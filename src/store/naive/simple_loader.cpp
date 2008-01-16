
#include <stdio.h>
#include <memory.h>
#include <string>
#include <libxml/xmlmemory.h>

#include "errors/error_factory.h"
#include "store/api/store_consts.h"
#include "store/naive/simple_store.h"
#include "store/naive/simple_loader.h"
#include "store/naive/simple_temp_seq.h"
#include "store/naive/node_items.h"
#include "store/naive/store_defs.h"
#include "store/naive/qname_pool.h"
#include "store/naive/nsbindings.h"

using namespace std;

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
{
  // This initializes the library and checks potential ABI mismatches between
  // the version it was compiled for and the actual shared library used.
  LIBXML_TEST_VERSION

  // See http://xmlsoft.org/html/libxml-tree.html#xmlSAXHandler
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

********************************************************************************/
void XmlLoader::reset()
{
  while(!theNodeStack.empty())
    theNodeStack.pop();

  while(!theBindingsStack.empty())
    theBindingsStack.pop();

  theErrors.clear();

  theRootNode = NULL;
}


/*******************************************************************************

********************************************************************************/
long XmlLoader::readPacket(std::istream& stream, char* buf, long size)
{
  try
  {
    stream.read(buf, size);

    if (stream.bad())
    {
      ZORBA_ERROR_ALERT(ZorbaError::XQP0016_LOADER_IO_ERROR,
                        NULL,
                        true,
                        "Input stream in bad state");
      return -1;
    }

    return stream.gcount();
  }
  catch (iostream::failure e)
  {
    ZORBA_ERROR_ALERT(ZorbaError::XQP0016_LOADER_IO_ERROR,
                      NULL,
                      true,
                      e.what());
  }
  return -1;
}


/*******************************************************************************

********************************************************************************/
Item_t XmlLoader::loadXml(const xqpStringStore* uri, std::istream& stream)
{
  xmlParserCtxtPtr ctxt = NULL;
  char *buf = NULL;//[4096];
  long numChars;

  theBaseUri = new xqpStringStore("");
  theDocUri = const_cast<xqpStringStore*>(uri);

  theNodeId.init(GET_STORE().getTreeId());

	buf = new char[4096];
  numChars = readPacket(stream, buf, 4096);
  if (numChars < 0)
  {
		delete[] buf;
    return NULL;
  }

  try
  {
    ctxt = xmlCreatePushParserCtxt(&theSaxHandler, this, buf, numChars, NULL);
    if (ctxt == NULL)
		{
			delete[] buf;
			return NULL;
		}

    while ((numChars = readPacket(stream, buf, 4096)) > 0)
    {
      xmlParseChunk(ctxt, buf, numChars, 0);
    }

    xmlParseChunk(ctxt, buf, 0, 1);
  }
  catch(std::runtime_error& e)
  {
    xmlFreeParserCtxt(ctxt);
    reset();
		delete[] buf;
    throw e;
  }

  Item_t resultNode = theRootNode;

  bool ok = ctxt->wellFormed;

  xmlFreeParserCtxt(ctxt);

  if (!ok)
  {
		delete[] buf;
    ZORBA_ERROR_ALERT(ZorbaError::XQP0017_LOADER_NOT_WELL_FORMED_XML,
                      NULL,
                      true,
                      theErrors.c_str());
    reset();
    return NULL;
  }

  reset();
	delete[] buf;
  return resultNode;
}


/*******************************************************************************
  SAX2 callback when the start of document has been detected by the parser.

  ctx: the user data (XML parser context)
********************************************************************************/
void XmlLoader::startDocument(void * ctx)
{
  SimpleStore& store = GET_STORE();
  XmlLoader& loader = *(static_cast<XmlLoader *>(ctx));

  LOADER_TRACE("");

  if (loader.theDocUri == NULL)
  {
    std::ostringstream uristream;
    uristream << "zorba://internalDocumentURI-"
              << loader.theNodeId.getTreeId();

    loader.theDocUri = new xqpStringStore(uristream.str().c_str());
  }

  Item_t docNode = new DocumentNodeImpl(loader.theBaseUri, loader.theDocUri);

  DOC_NODE(docNode)->setId(loader.theNodeId);
  loader.theNodeId.pushChild();

  LOADER_TRACE("Doc Node = " << docNode.get_ptr());

  loader.theRootNode = docNode;
  loader.theNodeStack.push(docNode);
  loader.theNodeStack.push(NULL);
}


/*******************************************************************************
  SAX2 callback when the end of document has been detected by the parser.

  ctx: the user data (XML parser context)
********************************************************************************/
void XmlLoader::endDocument(void * ctx)
{
  LOADER_TRACE("");

  XmlLoader& loader = *(static_cast<XmlLoader *>(ctx));

  if (loader.theNodeStack.size() == 0 )
    return;
  
  std::vector<Item_t> revChildNodes;

  Item_t childNode = loader.theNodeStack.top();

  while (childNode != NULL)
  {
    revChildNodes.push_back(childNode);
    loader.theNodeStack.pop();
    childNode = loader.theNodeStack.top();
  }
  loader.theNodeStack.pop();

  DocumentNodeImpl* docNode = DOC_NODE(loader.theNodeStack.top());

  NodeVector& children = docNode->children();
  children.resize(revChildNodes.size());

  std::vector<Item_t>::const_reverse_iterator it;
  unsigned long i = 0;
  for (it = revChildNodes.rbegin();
       it != (std::vector<Item_t>::const_reverse_iterator)revChildNodes.rend();
       it++, i++)
  {
    children[i] = *it;
    BASE_NODE(*it)->setParent(docNode);
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
  BasicItemFactory& factory = GET_FACTORY();
  XmlLoader& loader = *(static_cast<XmlLoader *>(ctx));
  QNamePool& qnpool = store.getQNamePool();

  unsigned long numAttributes = (unsigned long)numAttrs;
  unsigned long numBindings = (unsigned long)numNamespaces;

  // Name and type
  Item_t qname = qnpool.insert(reinterpret_cast<const char*>(uri),
                               reinterpret_cast<const char*>(prefix),
                               reinterpret_cast<const char*>(lname));
  Item_t tname = store.theAnyType;

  // Create the element node and assign it an id.
  Item_t elemItem(new ElementNodeImpl(qname.get_ptr(),
                                      tname.get_ptr(),
                                      numBindings,
                                      numAttributes));

  ElementNodeImpl* elemNode = ELEM_NODE(elemItem);

  elemNode->setId(loader.theNodeId);
  loader.theNodeId.pushChild();

  LOADER_TRACE("Element name ["
               << (prefix != NULL ? prefix : (xmlChar*)"") << ":" << lname
               << " (" << (uri != NULL ? uri : (xmlChar*)"NULL") << ")]"
               << " Element Node = " << elemNode);

  // Push element node to the node stack
  if (loader.theNodeStack.empty())
    loader.theRootNode = elemItem;

  loader.theNodeStack.push(elemItem);
  loader.theNodeStack.push(NULL);

  // Process namespace bindings
  if (numBindings > 0)
  {
    NamespaceBindings& bindings = elemNode->getNsContext()->getBindings();

    for (unsigned long i = 0; i < numBindings; ++i)
    {
      const char* prefix = reinterpret_cast<const char*>(namespaces[i * 2]);
      const char* nsuri = reinterpret_cast<const char*>(namespaces[i * 2 + 1]);

      if (prefix == NULL)
        prefix = "";

      xqpStringStore_t pooledNs;
      store.getNamespacePool().insert(nsuri, pooledNs);

      bindings[i].first = prefix;
      bindings[i].second = pooledNs;

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

      xqpStringStore_t value(new xqpStringStore(valueBegin, valueEnd));
      Item_t lexVal = factory.createString(value);
      Item_t typedVal = factory.createUntypedAtomic(value);

      Item_t attrItem(new AttributeNodeImpl(qname, tname, lexVal, typedVal,
                                            false, false, false));
      NodeImpl* attrNode = BASE_NODE(attrItem);

      attrNodes[i] = attrItem;

      attrNode->setParent(elemNode);
      attrNode->setId(loader.theNodeId);
      loader.theNodeId.nextChild();

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
  std::vector<Item_t> revChildNodes;
  Item_t childNode = loader.theNodeStack.top();
  while (childNode != NULL)
  {
    revChildNodes.push_back(childNode);
    loader.theNodeStack.pop();
    childNode = loader.theNodeStack.top();
  }
  loader.theNodeStack.pop();

  // The element node is now at the top of the stack
  ElementNodeImpl* elemNode = ELEM_NODE(loader.theNodeStack.top());

  LOADER_TRACE("Element name ["
               << (prefix != NULL ? prefix : (xmlChar*)"") << ":" << localName
               << " (" << (uri != NULL ? uri : (xmlChar*)"NULL") << ")]"
               << " Element Node = " << elemNode);

  // For each child, make this element node its parent and fix its namespace
  // bindings context. Note: the children were popped from the stack in reverse
  // order, so we copy them into the element node in the correct order.
  NodeVector& children = elemNode->children();
  children.resize(revChildNodes.size());
  std::vector<Item_t>::const_reverse_iterator it;
  unsigned long i = 0;
  for (it = revChildNodes.rbegin();
       it != (std::vector<Item_t>::const_reverse_iterator)revChildNodes.rend();
       it++, i++)
  {
    children[i] = *it;
    BASE_NODE(*it)->setParent(elemNode);

    if ((*it)->getNodeKind() == StoreConsts::elementNode)
    {
      if (!loader.theBindingsStack.empty())
        ELEM_NODE(*it)->setNsContext(loader.theBindingsStack.top());
      else
        ELEM_NODE(*it)->setNsContext(NULL);
    }
  }

  if (elemNode->getNsContext() != NULL)
  {
    loader.theBindingsStack.pop();
  }

  // Adjust the dewey id
  loader.theNodeId.popChild();
}


/*******************************************************************************
  SAX2 callback when xml text has been detected by the parser.

  ctx: the user data (XML parser context)
  ch:  a xmlChar string
  len: the number of xmlChar
********************************************************************************/
void XmlLoader::characters(void * ctx, const xmlChar * ch, int len)
{
  SimpleStore& store = GET_STORE();
  XmlLoader& loader = *(static_cast<XmlLoader *>( ctx ));

  xqpStringStore_t content(new xqpStringStore(reinterpret_cast<const char*>(ch), len));

  Item_t textNode(new TextNodeImpl(content, false));

  BASE_NODE(textNode)->setId(loader.theNodeId);
  loader.theNodeId.nextChild();

  LOADER_TRACE("Text Node = " << textNode.get_ptr() 
               << "content = " << content->c_str());

  if (loader.theNodeStack.empty())
    loader.theRootNode = textNode;

  loader.theNodeStack.push(textNode);
}


/*******************************************************************************
  SAX2 callback when a CDATA block has been detected by the parser.

  ctx: the user data (XML parser context)
  ch:  a xmlChar string
  len: the number of xmlChar
********************************************************************************/
void XmlLoader::cdataBlock(void * ctx, const xmlChar * ch, int len)
{
  SimpleStore& store = GET_STORE();
  XmlLoader& loader = *(static_cast<XmlLoader *>( ctx ));

  xqpStringStore_t content(new xqpStringStore(reinterpret_cast<const char*>(ch), len));

  Item_t textNode(new TextNodeImpl(content, false));

  BASE_NODE(textNode)->setId(loader.theNodeId);
  loader.theNodeId.nextChild();

  LOADER_TRACE("Text Node = " << textNode.get_ptr() 
               << "content = " << content->c_str());

  if (loader.theNodeStack.empty())
    loader.theRootNode = textNode;

  loader.theNodeStack.push(textNode);
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
  SimpleStore& store = GET_STORE();
  XmlLoader& loader = *(static_cast<XmlLoader *>( ctx ));

  LOADER_TRACE(content);

  xqpStringStore_t contentp(new xqpStringStore(reinterpret_cast<const char*>(content)));

  Item_t commentNode(new CommentNodeImpl(contentp, false));

  BASE_NODE(commentNode)->setId(loader.theNodeId);
  loader.theNodeId.nextChild();

  if (loader.theNodeStack.empty())
    loader.theRootNode = commentNode;

  loader.theNodeStack.push(commentNode);
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
  SimpleStore& store = GET_STORE();
  XmlLoader& loader = *(static_cast<XmlLoader *>( ctx ));

  LOADER_TRACE("target : " << target << " data: " << data);

  xqpStringStore_t datap(new xqpStringStore(reinterpret_cast<const char*>(data)));
  xqpStringStore_t targetp(new xqpStringStore(reinterpret_cast<const char*>(target)));

  Item_t piNode(new PiNodeImpl(targetp, datap, false));

  BASE_NODE(piNode)->setId(loader.theNodeId);
  loader.theNodeId.nextChild();

  if (loader.theNodeStack.empty())
    loader.theRootNode = piNode;

  loader.theNodeStack.push(piNode);
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
  if (loader.theErrors.size() > 0)
    loader.theErrors += "+ ";
  loader.theErrors += buf;
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
  va_list args;
  va_start(args, msg);
  vprintf(msg, args);
  va_end(args);
}

}
