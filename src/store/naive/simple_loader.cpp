
#include <stdio.h>
#include <memory.h>
#include <string>
#include <libxml/xmlmemory.h>

#include "store/api/store_consts.h"
#include "store/naive/simple_store.h"
#include "store/naive/simple_loader.h"
#include "store/naive/atomic_items.h"
#include "store/naive/node_items.h"
#include "store/naive/store_defs.h"
#include "store/naive/qname_pool.h"
#include "store/naive/nsbindings.h"


namespace xqp
{

#ifndef NDEBUG

  //#define LOCAL_DEBUG

#ifdef LOCAL_DEBUG
#define LOADER_TRACE(msg)                                                     \
{                                                                             \
  std::cout << __FUNCTION__ << ": " << std::endl << "  " << msg << std::endl; \
}
#else
#define LOADER_TRACE(msg)
#endif

#else
#define LOADER_TRACE(msg)
#endif


/*******************************************************************************

********************************************************************************/
XmlLoader::XmlLoader()
:
  theBaseUri(NULL),
  theDocUri(NULL),
  theTree(NULL),
  theRootNode(NULL)
{
  theOrdPath.init();


  memset(&theSaxHandler, 0, sizeof(theSaxHandler) );
  theSaxHandler.initialized = XML_SAX2_MAGIC;
  theSaxHandler.startDocument = &XmlLoader::startDocument;
  theSaxHandler.endDocument = &XmlLoader::endDocument;
  theSaxHandler.startElementNs = &XmlLoader::startElement;
  theSaxHandler.endElementNs = &XmlLoader::endElement;
  theSaxHandler.characters = &XmlLoader::characters;
  theSaxHandler.cdataBlock = &XmlLoader::cdataBlock;
  theSaxHandler.comment = &XmlLoader::comment;
  theSaxHandler.processingInstruction = &XmlLoader::processingInstruction;
  theSaxHandler.warning = &XmlLoader::warning;
  theSaxHandler.error = &XmlLoader::error;
}


/*******************************************************************************

********************************************************************************/
XmlLoader::~XmlLoader()
{
}


/*******************************************************************************
  Method called to do cleanup in case of errors.
********************************************************************************/
void XmlLoader::abort()
{
  theBaseUri = NULL;
  theDocUri = NULL;

  if (theTree != NULL)
  {
    delete theTree;
    theTree = NULL;
  }

  theOrdPath.init();
  theRootNode = NULL;

  while(!theNodeStack.empty())
  {
    XmlNode* node = theNodeStack.top();
    theNodeStack.pop();
    if (node != NULL)
      node->deleteTree();
  }

  while(!theBindingsStack.empty())
  {
    NsBindingsContext* ctx = theBindingsStack.top();
    theBindingsStack.pop();
    delete ctx;
  }

  theWarnings.clear();
}


/*******************************************************************************
  Method used to reset the loader so it can be used to load another document.
********************************************************************************/
void XmlLoader::reset()
{
  theBaseUri = NULL;
  theDocUri = NULL;

  theTree = NULL;
  theOrdPath.init();
  theRootNode = NULL;

  theNodeStack.pop();

  ZORBA_ASSERT(theNodeStack.empty());
  ZORBA_ASSERT(theBindingsStack.empty());

  theWarnings.clear();
}


/*******************************************************************************

********************************************************************************/
void XmlLoader::setRoot(XmlNode* root)
{
  theRootNode = root;
  theTree->setRoot(root);
}


/*******************************************************************************
  Read up to "size" bytes from the given input stream into the given buffer.
  Return the number of bytes actually read, throw an exception if any I/O
  error occured.
********************************************************************************/
long XmlLoader::readPacket(std::istream& stream, char* buf, long size)
{
  try
  {
    stream.read(buf, size);

    if (stream.bad())
    {
      ZORBA_ERROR_ALERT(ZorbaError::XQP0016_LOADER_IO_ERROR,
                        NULL, DONT_CONTINUE_EXECUTION,
                        "Input stream in bad state");
    }

    return stream.gcount();
  }
  catch (std::iostream::failure e)
  {
    ZORBA_ERROR_ALERT(ZorbaError::XQP0016_LOADER_IO_ERROR,
                      NULL, DONT_CONTINUE_EXECUTION, e.what());
  }
  catch (...)
  {
    ZORBA_ERROR_ALERT(ZorbaError::XQP0016_LOADER_IO_ERROR,
                      NULL, DONT_CONTINUE_EXECUTION, "Unknown exception");
  }

  return -1;
}


/*******************************************************************************

********************************************************************************/
XmlNode* XmlLoader::loadXml(xqpStringStore* uri, std::istream& stream)
{
  xmlParserCtxtPtr ctxt = NULL;
  long numChars;

  theDocUri = uri;

  theTree = new XmlTree(NULL, GET_STORE().getTreeId());

  try
  {
    numChars = readPacket(stream, theBuffer, 4096);

    if (numChars < 0)
    {
      ZORBA_ERROR_ALERT(ZorbaError::XQP0016_LOADER_IO_ERROR,
                        NULL, CONTINUE_EXECUTION, "Unknown I/O error");
      abort();
      return NULL;
    }

    ctxt = xmlCreatePushParserCtxt(&theSaxHandler, this, theBuffer, numChars, NULL);

    if (ctxt == NULL)
    {
      ZORBA_ERROR_ALERT(ZorbaError::XQP0017_LOADER_PARSING_ERROR,
                        NULL, CONTINUE_EXECUTION,
                        "Failed to initialize parser");
      abort();
			return NULL;
    }

    while ((numChars = readPacket(stream, theBuffer, 4096)) > 0)
    {
      xmlParseChunk(ctxt, theBuffer, numChars, 0);
    }

    if (numChars < 0)
    {
      ZORBA_ERROR_ALERT(ZorbaError::XQP0016_LOADER_IO_ERROR,
                        NULL, CONTINUE_EXECUTION, "Unknown I/O error");
      xmlFreeParserCtxt(ctxt);
      abort();
      return NULL;
    }

    xmlParseChunk(ctxt, theBuffer, 0, 1);
  }
  catch(...)
  {
    xmlFreeParserCtxt(ctxt);
    abort();
    return NULL;
  }

  bool ok = ctxt->wellFormed != 0;

  xmlFreeParserCtxt(ctxt);

  if (!ok)
  {
    if (theDocUri != NULL)
    {
      ZORBA_ERROR_ALERT_OSS(ZorbaError::XQP0017_LOADER_PARSING_ERROR,
                            NULL, CONTINUE_EXECUTION,
                            "The document with URI " << *theDocUri
                            <<" is not well formed", "");
    }
    else
    {
      ZORBA_ERROR_ALERT(ZorbaError::XQP0017_LOADER_PARSING_ERROR,
                        NULL, CONTINUE_EXECUTION,
                        "Not well formed XML");
    }

    abort();
    return NULL;
  }

  XmlNode* resultNode = theRootNode;
  reset();
  return resultNode;
}


/*******************************************************************************
  SAX2 callback when the start of document has been detected by the parser.

  ctx: the user data (XML parser context)
********************************************************************************/
void XmlLoader::startDocument(void * ctx)
{
  XmlLoader& loader = *(static_cast<XmlLoader *>(ctx));

  LOADER_TRACE("");

  xqpStringStore* docUri = loader.theDocUri;
  xqpStringStore* baseUri = loader.theBaseUri;
  if (docUri == NULL)
  {
    std::ostringstream uristream;
    uristream << "zorba://internalDocumentURI-" << loader.theTree->getId();

    docUri = new xqpStringStore(uristream.str().c_str());
  }
  if (baseUri == NULL)
  {
    baseUri = new xqpStringStore("");
  }

  LoadedDocumentNode* docNode = new LoadedDocumentNode(baseUri, docUri);

  loader.setRoot(docNode);
  loader.theNodeStack.push(docNode);
  loader.theNodeStack.push(NULL);

  docNode->setId(loader.theTree, &loader.theOrdPath);
  loader.theOrdPath.pushChild();

  LOADER_TRACE("Doc Node = " << docNode);
}


/*******************************************************************************
  SAX2 callback when the end of document has been detected by the parser.

  ctx: the user data (XML parser context)
********************************************************************************/
void XmlLoader::endDocument(void * ctx)
{
  LOADER_TRACE("");

  XmlLoader& loader = *(static_cast<XmlLoader *>(ctx));

  // This check is required because it is possible (in case of mal-formed doc)
  // that libXml calls endDocument() without having called startDocument().
  if (loader.theNodeStack.size() == 0 )
    return;
  
  std::vector<XmlNode*> revChildNodes;

  XmlNode* childNode = loader.theNodeStack.top();

  while (childNode != NULL)
  {
    revChildNodes.push_back(childNode);
    loader.theNodeStack.pop();
    childNode = loader.theNodeStack.top();
  }
  loader.theNodeStack.pop();

  LoadedDocumentNode* docNode = dynamic_cast<LoadedDocumentNode*>(loader.theNodeStack.top());
  ZORBA_ASSERT(docNode != NULL);

  NodeVector& children = docNode->children();
  children.resize(revChildNodes.size());

  std::vector<XmlNode*>::const_reverse_iterator it;
  unsigned long i = 0;
  for (it = revChildNodes.rbegin();
       it != (std::vector<XmlNode*>::const_reverse_iterator)revChildNodes.rend();
       it++, i++)
  {
    children.set(i, *it, false);
    (*it)->setParent(docNode);
  }
}


/*******************************************************************************
  SAX2 callback when an element start has been detected by the parser. It
  provides the expanded qname of the element, as well as the new namespace
  declarations on the element (if any).

  ctx:           the user data (XML parser context)
  localname:     the local name of the element
  prefix:        the element namespace prefix if available
  URI:           the element namespace name if available
  nb_namespaces: number of namespace definitions on that node
  namespaces:    pointer to the array of prefix/URI pairs namespace definitions
  nb_attributes: the number of attributes on that node
  nb_defaulted:  the number of defaulted attributes. The defaulted ones are at
                 the end of the array
 attributes:     pointer to the array of (localname/prefix/URI/value/end)
                 attribute values.
********************************************************************************/
void XmlLoader::startElement(
    void * ctx, 
    const xmlChar * lname, 
    const xmlChar * prefix, 
    const xmlChar * uri,
    int numNamespaces,
    const xmlChar ** namespaces,
    int numAttrs, 
    int numDefaulted, 
    const xmlChar ** attributes)
{
  SimpleStore& store = GET_STORE();
  XmlLoader& loader = *(static_cast<XmlLoader *>(ctx));
  QNamePool& qnpool = store.getQNamePool();

  unsigned long numAttributes = (unsigned long)numAttrs;
  unsigned long numBindings = (unsigned long)numNamespaces;

  // Construct node name and type
  Item_t qname = qnpool.insert(reinterpret_cast<const char*>(uri),
                               reinterpret_cast<const char*>(prefix),
                               reinterpret_cast<const char*>(lname));
  Item_t tname = store.theAnyType.getp();

  // Create the element node and push it to the node stack
  LoadedElementNode* elemNode = new LoadedElementNode(qname.getp(),
                                                      tname.getp(),
                                                      numBindings,
                                                      numAttributes);
  if (loader.theNodeStack.empty())
    loader.setRoot(elemNode);

  loader.theNodeStack.push(elemNode);
  loader.theNodeStack.push(NULL);

  // Assign the current node id to this node, and compute the next node id.
  elemNode->setId(loader.theTree, &loader.theOrdPath);
  loader.theOrdPath.pushChild();

  LOADER_TRACE("Element name ["
               << (prefix != NULL ? prefix : (xmlChar*)"") << ":" << lname
               << " (" << (uri != NULL ? uri : (xmlChar*)"NULL") << ")]"
               << " Element Node = " << elemNode);

  // Process namespace bindings
  if (numBindings > 0)
  {
    NsBindings& bindings = elemNode->getNsContext()->getBindings();

    for (unsigned long i = 0; i < numBindings; ++i)
    {
      const char* prefix = reinterpret_cast<const char*>(namespaces[i * 2]);
      const char* nsuri = reinterpret_cast<const char*>(namespaces[i * 2 + 1]);

      if (prefix == NULL)
        prefix = "";

      xqpStringStore_t pooledNs;
      store.getNamespacePool().insert(nsuri, pooledNs);

      bindings[i].first = prefix;
      bindings[i].second = pooledNs.getp();

      LOADER_TRACE("namespace decl: [" << prefix  << ":" << nsuri << "]");
    }

    loader.theBindingsStack.push(elemNode->getNsContext());
  }

  // Process attributes
  if (numAttributes > 0)
  {
    NodeVector& attrNodes = elemNode->attributes();

    unsigned long index = 0;
    for (unsigned long i = 0; i < numAttributes; ++i, index += 5)
    {
      const char* lname = reinterpret_cast<const char*>(attributes[index]);
      const char* prefix = reinterpret_cast<const char*>(attributes[index+1]);
      const char* uri = reinterpret_cast<const char*>(attributes[index+2]);
      const char* valueBegin = reinterpret_cast<const char*>(attributes[index+3]);
      const char* valueEnd = reinterpret_cast<const char*>(attributes[index+4]);

      Item_t qname = qnpool.insert(uri, prefix, lname);
      Item_t tname = store.theUntypedAtomicType;

      xqpStringStore* value = new xqpStringStore(valueBegin, valueEnd);
      Item* typedVal = new UntypedAtomicItemImpl(value);

      AttributeNode* attrNode = new AttributeNode(NULL, NULL, 0,
                                                  qname, tname, 
                                                  false, false);
      attrNode->theParent = elemNode;
      attrNode->setId(loader.theTree, &loader.theOrdPath);
      attrNode->theTypedValue = typedVal;

      attrNodes.set(i, attrNode, false);

      loader.theOrdPath.nextChild();

      LOADER_TRACE("Attribute name [" << (prefix != NULL ? prefix : "")
                   << ":" << lname << " (" << (uri != NULL ? uri : "NULL")
                   << ")]" << std::endl << "  Attribute value: " << value->c_str());
    }
  }
}

  
/*******************************************************************************
  SAX2 callback when an element end has been detected by the parser. It
  provides the expanded qname of the element.

  ctx:       the user data (XML parser context)
  localname: the local name of the element
  prefix:    the element namespace prefix if available
  URI:       the element namespace name if available
********************************************************************************/
void  XmlLoader::endElement(
    void * ctx, 
    const xmlChar * localName, 
    const xmlChar * prefix, 
    const xmlChar * uri)
{
  XmlLoader& loader = *(static_cast<XmlLoader *>(ctx));

  // Collect the children of this element node from the node stack
  std::vector<XmlNode*> revChildNodes;

  XmlNode* prevChild = NULL;
  XmlNode* currChild = loader.theNodeStack.top();
  while (currChild != NULL)
  {
    if (currChild->getNodeKind() == StoreConsts::textNode &&
        prevChild != NULL &&
        prevChild->getNodeKind() == StoreConsts::textNode)
    {
      *(prevChild->getStringValueP()) = *(currChild->getStringValueP()) +
                                        *(prevChild->getStringValueP());
      delete currChild;
    }
    else
    {
      revChildNodes.push_back(currChild);
      prevChild = currChild;
    }

    loader.theNodeStack.pop();
    currChild = loader.theNodeStack.top();
  }
  loader.theNodeStack.pop();

  // The element node is now at the top of the stack
  LoadedElementNode* elemNode = dynamic_cast<LoadedElementNode*>(loader.theNodeStack.top());
  ZORBA_ASSERT(elemNode != NULL);

  LOADER_TRACE("Element name ["
               << (prefix != NULL ? prefix : (xmlChar*)"") << ":" << localName
               << " (" << (uri != NULL ? uri : (xmlChar*)"NULL") << ")]"
               << " Element Node = " << elemNode);

  // For each child, make this element node its parent and fix its namespace
  // bindings context. Note: the children were popped from the stack in reverse
  // order, so we copy them into the element node in the correct order.
  NodeVector& children = elemNode->children();
  children.resize(revChildNodes.size());

  std::vector<XmlNode*>::const_reverse_iterator it;
  unsigned long i = 0;
  for (it = revChildNodes.rbegin();
       it != (std::vector<XmlNode*>::const_reverse_iterator)revChildNodes.rend();
       it++, i++)
  {
    currChild = *it;

    children.set(i, currChild, false);
    currChild->setParent(elemNode);

    if (currChild->getNodeKind() == StoreConsts::elementNode)
    {
      if (!loader.theBindingsStack.empty())
        currChild->setNsContext(loader.theBindingsStack.top());
      else
        currChild->setNsContext(NULL);
    }
  }

  if (elemNode->getNsContext() != NULL)
  {
    loader.theBindingsStack.pop();
  }

  // Adjust the dewey id
  loader.theOrdPath.popChild();
}


/*******************************************************************************
  SAX2 callback when xml text has been detected by the parser.

  ctx: the user data (XML parser context)
  ch:  a xmlChar string
  len: the number of xmlChar
********************************************************************************/
void XmlLoader::characters(void * ctx, const xmlChar * ch, int len)
{
  XmlLoader& loader = *(static_cast<XmlLoader *>( ctx ));

  xqpStringStore* content = new xqpStringStore(reinterpret_cast<const char*>(ch), len);

  XmlNode* textNode = new TextNode(NULL, NULL, 0, content);

  if (loader.theNodeStack.empty())
    loader.setRoot(textNode);

  loader.theNodeStack.push(textNode);

  textNode->setId(loader.theTree, &loader.theOrdPath);
  loader.theOrdPath.nextChild();

  LOADER_TRACE("Text Node = " << textNode.getp() 
               << "content = " << content->c_str());
}


/*******************************************************************************
  SAX2 callback when a CDATA block has been detected by the parser.

  ctx: the user data (XML parser context)
  ch:  a xmlChar string
  len: the number of xmlChar
********************************************************************************/
void XmlLoader::cdataBlock(void * ctx, const xmlChar * ch, int len)
{
  XmlLoader& loader = *(static_cast<XmlLoader *>( ctx ));

  xqpStringStore* content = new xqpStringStore(reinterpret_cast<const char*>(ch), len);

  XmlNode* textNode = new TextNode(NULL, NULL, 0, content);

  if (loader.theNodeStack.empty())
    loader.setRoot(textNode);

  loader.theNodeStack.push(textNode);

  textNode->setId(loader.theTree, &loader.theOrdPath);
  loader.theOrdPath.nextChild();

  LOADER_TRACE("Text Node = " << textNode.getp() 
               << "content = " << content->c_str());
}


/*******************************************************************************
  SAX2 callback when a comment has been detected by the parser.

  ctx: the user data (XML parser context)
  content:  the comment content
********************************************************************************/
void XmlLoader::comment(
    void * ctx,
    const xmlChar * content)
{
  XmlLoader& loader = *(static_cast<XmlLoader *>( ctx ));

  LOADER_TRACE(content);

  xqpStringStore* contentp = new xqpStringStore(reinterpret_cast<const char*>(content));

  XmlNode* commentNode = new CommentNode(NULL, NULL, 0, contentp);

  if (loader.theNodeStack.empty())
    loader.setRoot(commentNode);

  loader.theNodeStack.push(commentNode);

  commentNode->setId(loader.theTree, &loader.theOrdPath);
  loader.theOrdPath.nextChild();
}


/*******************************************************************************
  SAX2 callback when a processing instruction has been detected by the parser.

  ctx: the user data (XML parser context)

********************************************************************************/
void XmlLoader::processingInstruction(
    void * ctx, 
    const xmlChar * target, 
    const xmlChar * data)
{
  XmlLoader& loader = *(static_cast<XmlLoader *>( ctx ));

  LOADER_TRACE("target : " << target << " data: " << data);

  xqpStringStore* datap = new xqpStringStore(reinterpret_cast<const char*>(data));
  xqpStringStore* targetp = new xqpStringStore(reinterpret_cast<const char*>(target));

  XmlNode* piNode = new PiNode(NULL, NULL, 0, targetp, datap);

  if (loader.theNodeStack.empty())
    loader.setRoot(piNode);

  loader.theNodeStack.push(piNode);

  piNode->setId(loader.theTree, &loader.theOrdPath);
  loader.theOrdPath.nextChild();
}


/*******************************************************************************
  Display and format an error messages, callback.
 
   ctx:  an XML parser context
   msg:  the message to display/transmit
   ...:  extra parameters for the message display
********************************************************************************/
void  XmlLoader::error(void * ctx, const char * msg, ... )
{
  XmlLoader& loader = *(static_cast<XmlLoader *>( ctx ));
  char buf[1024];
  va_list args;
  va_start(args, msg);
  vsprintf(buf, msg, args);
  va_end(args);
  ZORBA_ERROR_ALERT(ZorbaError::XQP0017_LOADER_PARSING_ERROR,
                    NULL, CONTINUE_EXECUTION, buf);
}


/*******************************************************************************
   Display and format a warning messages, callback.
  
   ctx:  an XML parser context
   msg:  the message to display/transmit
   ...:  extra parameters for the message display
********************************************************************************/
void  XmlLoader::warning(void * ctx, const char * msg, ... )
{
  XmlLoader& loader = *(static_cast<XmlLoader *>( ctx ));
  char buf[1024];
  va_list args;
  va_start(args, msg);
  vsprintf(buf, msg, args);
  va_end(args);
  if (loader.theWarnings.size() > 0)
    loader.theWarnings += "+ ";
  loader.theWarnings += buf;
}

}
