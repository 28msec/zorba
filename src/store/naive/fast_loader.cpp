/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdio.h>
#include <memory.h>
#include <string>
#include <libxml/xmlmemory.h>

#include <zorba/store_consts.h>

#include "zorbamisc/config/platform.h"
#include "zorbatypes/datetime.h"
#include "zorbaerrors/error_manager.h"
#include "zorbaerrors/Assert.h"

#include "store/naive/store_defs.h"
#include "store/naive/string_pool.h"
#include "store/naive/qname_pool.h"
#include "store/naive/simple_store.h"
#include "store/naive/atomic_items.h"
#include "store/naive/node_items.h"
#include "store/naive/dataguide.h"
#include "store/naive/nsbindings.h"
#include "store/naive/sax_loader.h"


namespace zorba { namespace simplestore {

#ifndef NDEBUG

#define LOADER_TRACE(level, msg)             \
{                                            \
  if (level <= loader.theTraceLevel)         \
    std::cout << msg << std::endl;           \
}

#define LOADER_TRACE1(msg) LOADER_TRACE(1, msg);
#define LOADER_TRACE2(msg) LOADER_TRACE(2, msg);
#define LOADER_TRACE3(msg) LOADER_TRACE(3, msg);

#else
#define LOADER_TRACE(msg)
#define LOADER_TRACE1(msg)
#define LOADER_TRACE2(msg)
#define LOADER_TRACE3(msg)
#endif

#define ZORBA_LOADER_CHECK_ERROR(loader) \
  do { \
    if (loader.theErrorManager->hasErrors()) \
      return; \
  } while (0);


/*******************************************************************************

********************************************************************************/
FastXmlLoader::FastXmlLoader(
    store::ItemFactory* factory,
    error::ErrorManager* errorManager,
    bool dataguide)
  :
  XmlLoader(factory, errorManager, dataguide),
  theTree(NULL),
  theRootNode(NULL)
{
  theOrdPath.init();

  memset(&theSaxHandler, 0, sizeof(theSaxHandler) );
  theSaxHandler.initialized = XML_SAX2_MAGIC;
  theSaxHandler.startDocument = &FastXmlLoader::startDocument;
  theSaxHandler.endDocument = &FastXmlLoader::endDocument;
  theSaxHandler.startElementNs = &FastXmlLoader::startElement;
  theSaxHandler.endElementNs = &FastXmlLoader::endElement;
  theSaxHandler.characters = &FastXmlLoader::characters;
  theSaxHandler.cdataBlock = &FastXmlLoader::cdataBlock;
  theSaxHandler.comment = &FastXmlLoader::comment;
  theSaxHandler.processingInstruction = &FastXmlLoader::processingInstruction;
  theSaxHandler.warning = &FastXmlLoader::warning;
  theSaxHandler.error = &FastXmlLoader::error;
}


/*******************************************************************************

********************************************************************************/
FastXmlLoader::~FastXmlLoader()
{
}


/*******************************************************************************

********************************************************************************/
void FastXmlLoader::setRoot(XmlNode* root)
{
  theRootNode = root;
  theTree->setRoot(root);
}


/*******************************************************************************
  Method called to do cleanup in case of errors.
********************************************************************************/
void FastXmlLoader::abortload()
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

#ifdef DATAGUIDE
  if(!theGuideStack.empty())
  {
    GuideNode* node = theGuideStack[0];
    if (node != NULL)
      node->deleteTree();
  }

  theGuideStack.clear();
#endif

  while(!theBindingsStack.empty())
  {
    NsBindingsContext* ctx = theBindingsStack.top();
    theBindingsStack.pop();
    delete ctx;
  }
}


/*******************************************************************************
  Method used to reset the loader so it can be used to load another document.
********************************************************************************/
void FastXmlLoader::reset()
{
  theBaseUri = NULL;
  theDocUri = NULL;

  theTree = NULL;
  theOrdPath.init();
  theRootNode = NULL;

  theNodeStack.pop();

  ZORBA_ASSERT(theNodeStack.empty());
#ifdef DATAGUIDE
  ZORBA_ASSERT(theGuideStack.empty());
#endif
  ZORBA_ASSERT(theBindingsStack.empty());
}


/*******************************************************************************
  Read up to "size" bytes from the given input stream into the given buffer.
  Return the number of bytes actually read, throw an exception if any I/O
  error occured.
********************************************************************************/
long FastXmlLoader::readPacket(std::istream& stream, char* buf, long size)
{
  try
  {
    stream.read(buf, size);

    if (stream.bad())
    {
      ZORBA_ERROR_DESC_CONTINUE(theErrorManager,
                                XQP0016_LOADER_IO_ERROR,
                                "Input stream in bad state");
    }

    return stream.gcount();
  }
  catch (std::iostream::failure e)
  {
    ZORBA_ERROR_DESC_CONTINUE(theErrorManager,
                              XQP0016_LOADER_IO_ERROR, e.what());
  }
  catch (...)
  {
    ZORBA_ERROR_DESC_CONTINUE(theErrorManager, 
                              XQP0016_LOADER_IO_ERROR,
                              "Unknown exception");
  }

  return -1;
}


/*******************************************************************************

********************************************************************************/
store::Item_t FastXmlLoader::loadXml(
    const xqpStringStore_t& uri,
    std::istream& stream)
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
      ZORBA_ERROR_DESC_CONTINUE(theErrorManager, 
                                XQP0016_LOADER_IO_ERROR,
                                "Unknown I/O error");
      abortload();
      return NULL;
    }
    else if (numChars == 0)
    {
      ZORBA_ERROR_DESC_CONTINUE(theErrorManager, 
                                XQP0016_LOADER_IO_ERROR,
                                "No input data.");
      abortload();
      return NULL;
    }

    ctxt = xmlCreatePushParserCtxt(&theSaxHandler, this, theBuffer, numChars, NULL);

    if (ctxt == NULL)
    {
      ZORBA_ERROR_DESC_CONTINUE(theErrorManager,
                                XQP0017_LOADER_PARSING_ERROR, 
                                "Failed to initialize parser");
      abortload();
			return NULL;
    }

    while ((numChars = readPacket(stream, theBuffer, 4096)) > 0)
    {
      xmlParseChunk(ctxt, theBuffer, numChars, 0);
    }

    if (numChars < 0)
    {
      ZORBA_ERROR_DESC_CONTINUE(theErrorManager,
                                XQP0016_LOADER_IO_ERROR,
                                "Unknown I/O error");
      xmlFreeParserCtxt(ctxt);
      abortload();
      return NULL;
    }

    xmlParseChunk(ctxt, theBuffer, 0, 1);
  }
  catch(...)
  {
    xmlFreeParserCtxt(ctxt);
    abortload();
    return NULL;
  }

  bool ok = ctxt->wellFormed != 0;

  xmlFreeParserCtxt(ctxt);

  if (!ok)
  {
    if (theDocUri != NULL)
    {
      ZORBA_ERROR_PARAM_CONTINUE_OSS(theErrorManager,
                                     XQP0017_LOADER_PARSING_ERROR,
                                     "The document with URI " << *theDocUri
                                     <<" is not well formed", "");
    }
    else
    {
      ZORBA_ERROR_DESC_CONTINUE(theErrorManager,
                                XQP0017_LOADER_PARSING_ERROR,
                                "Not well formed XML");
    }

    abortload();
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
void FastXmlLoader::startDocument(void * ctx)
{
  FastXmlLoader& loader = *(static_cast<FastXmlLoader *>(ctx));
  ZORBA_LOADER_CHECK_ERROR(loader);

  xqpStringStore_t docUri = loader.theDocUri;
  xqpStringStore_t baseUri = loader.theBaseUri;
  if (docUri == NULL)
  {
    std::ostringstream uristream;
    uristream << "zorba://internalDocumentURI-" << loader.theTree->getId();

    docUri = new xqpStringStore(uristream.str().c_str());
  }

  XmlNode* docNode = new DocumentTreeNode(baseUri, docUri);

  loader.setRoot(docNode);
  loader.theNodeStack.push(docNode);
  loader.theNodeStack.push(NULL);

#ifdef DATAGUIDE
  if (loader.theBuildDataGuide)
  {
    assert(loader.theGuideStack.empty());
    store::Item_t nodeName;
    ElementGuideNode* gnode = new ElementGuideNode(NULL, nodeName);
    loader.theGuideStack.push(gnode);
  }
#endif

  SYNC_CODE(docNode->theRCLockPtr = &loader.theTree->getRCLock();)
  docNode->setId(loader.theTree, &loader.theOrdPath);
  loader.theOrdPath.pushChild();

  LOADER_TRACE1("Start Doc Node = " << docNode);
}


/*******************************************************************************
  SAX2 callback when the end of document has been detected by the parser.

  ctx: the user data (XML parser context)
********************************************************************************/
void FastXmlLoader::endDocument(void * ctx)
{
  FastXmlLoader& loader = *(static_cast<FastXmlLoader *>(ctx));
  ZORBA_LOADER_CHECK_ERROR(loader);

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

  DocumentTreeNode* docNode = dynamic_cast<DocumentTreeNode*>(loader.theNodeStack.top());
  ZORBA_ASSERT(docNode != NULL);

  NodeVector& children = docNode->children();
  children.resize(revChildNodes.size());

  std::vector<XmlNode*>::const_reverse_iterator it;
  ulong i = 0;
  for (it = revChildNodes.rbegin();
       it != (std::vector<XmlNode*>::const_reverse_iterator)revChildNodes.rend();
       it++, i++)
  {
    children.set(*it, i, false);
    (*it)->setParent(docNode);
  }

#ifdef DATAGUIDE
  if (loader.theBuildDataGuide)
  {
    // Remove from the dataguide stack
    ElementGuideNode* rootGNode = loader.theGuideStack.top();
    loader.theGuideStack.pop();
    assert(loader.theGuideStack.empty());

    loader.theTree->setDataGuide(rootGNode);

#ifndef NDEBUG
    std::cout << rootGNode->show(0) << std::endl;
#endif
  }
#endif


  LOADER_TRACE2("End Doc Node = " << docNode);
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
void FastXmlLoader::startElement(
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
  FastXmlLoader& loader = *(static_cast<FastXmlLoader *>(ctx));
  ZORBA_LOADER_CHECK_ERROR(loader);
  QNamePool& qnpool = store.getQNamePool();

  ulong numAttributes = (ulong)numAttrs;
  ulong numBindings = (ulong)numNamespaces;

  // Construct node name 
  store::Item_t nodeName = qnpool.insert(reinterpret_cast<const char*>(uri),
                                         reinterpret_cast<const char*>(prefix),
                                         reinterpret_cast<const char*>(lname));

  // Create the element node and push it to the node stack
  ElementTreeNode* elemNode = new ElementTreeNode(nodeName,
                                                  numBindings,
                                                  numAttributes);
  if (loader.theNodeStack.empty())
    loader.setRoot(elemNode);

#ifdef DATAGUIDE
  nodeName = elemNode->getNodeName();

  // Push new node to dataguide, if not there already
  if (loader.theBuildDataGuide && loader.theNodeStack.empty())
  {
    assert(loader.theGuideStack.empty());
    ElementGuideNode* gnode = new ElementGuideNode(NULL, nodeName);
    loader.theGuideStack.push(gnode);
  }
  else if (loader.theBuildDataGuide)
  {
    bool duplicate = false;

    assert(!loader.theGuideStack.empty());

    // See if we have seen an element with the same tag name among the left
    // siblings of this element node.
    for (long i = loader.theNodeStack.size() - 1; loader.theNodeStack[i] != NULL; i--)
    {
      XmlNode* sib = loader.theNodeStack[i];
      if (sib->getNodeKind() == store::StoreConsts::elementNode &&
          sib->getNodeName()->equals(nodeName))
      {
        duplicate = true;
        break;
      }
    }

    ElementGuideNode* parentGNode = loader.theGuideStack.top();
    ElementGuideNode* childGNode = parentGNode->findChild(nodeName);

    if (duplicate)
    {
      assert(childGNode != NULL);
      childGNode->setUnique(false);
    }
    else
    {
      if (childGNode == NULL)
        childGNode = new ElementGuideNode(parentGNode, nodeName);
    }

    loader.theGuideStack.push(childGNode);
  }
#endif

  loader.theNodeStack.push((XmlNode*)elemNode);
  loader.theNodeStack.push(NULL);

  // Assign the current node id to this node, and compute the next node id.
  elemNode->setId(loader.theTree, &loader.theOrdPath);
  loader.theOrdPath.pushChild();

  SYNC_CODE(elemNode->theRCLockPtr = &loader.theTree->getRCLock();)

  LOADER_TRACE1("Start Element: node = " << elemNode << " name = ["
                << (prefix != NULL ? prefix : (xmlChar*)"") << ":" << lname
                << " (" << (uri != NULL ? uri : (xmlChar*)"NULL") << ")]"
                << std::endl << " ordpath = " << elemNode->getOrdPath().show()
                << std::endl);

  // Process namespace bindings
  if (numBindings > 0)
  {
    store::NsBindings& bindings = elemNode->getNsContext()->getBindings();

    for (ulong i = 0; i < numBindings; ++i)
    {
      const char* prefix = reinterpret_cast<const char*>(namespaces[i * 2]);
      const char* nsuri = reinterpret_cast<const char*>(namespaces[i * 2 + 1]);

      if (prefix == NULL)
        prefix = "";

      xqpStringStore_t pooledNs;
      store.getNamespacePool().insertc(nsuri, pooledNs);

      bindings[i].first = prefix;
      bindings[i].second = pooledNs.getp();

      LOADER_TRACE1("namespace decl: [" << prefix  << ":" << nsuri << "]");
    }

    loader.theBindingsStack.push(elemNode->getNsContext());
  }

  // Process attributes
  if (numAttributes > 0)
  {
    NodeVector& attrNodes = elemNode->attributes();

    ulong index = 0;
    for (ulong i = 0; i < numAttributes; ++i, index += 5)
    {
      const char* lname = reinterpret_cast<const char*>(attributes[index]);
      const char* prefix = reinterpret_cast<const char*>(attributes[index+1]);
      const char* uri = reinterpret_cast<const char*>(attributes[index+2]);
      const char* valueBegin = reinterpret_cast<const char*>(attributes[index+3]);
      const char* valueEnd = reinterpret_cast<const char*>(attributes[index+4]);

      store::Item_t qname = qnpool.insert(uri, prefix, lname);
      xqpStringStore_t value = new xqpStringStore(valueBegin, valueEnd);

      store::Item_t typeName = store.theSchemaTypeNames[XS_UNTYPED_ATOMIC];
      store::Item_t typedValue = new UntypedAtomicItemImpl(value);

      AttributeNode* attrNode = new AttributeNode(qname, typeName);
      attrNode->theParent = elemNode;
      attrNode->setId(loader.theTree, &loader.theOrdPath);
      attrNode->theTypedValue = typedValue.transfer();

      attrNodes.set(attrNode, i, false);

      loader.theOrdPath.nextChild();

      SYNC_CODE(attrNode->theRCLockPtr = &loader.theTree->getRCLock();)

      LOADER_TRACE1("Attribute: node = " << attrNode
                    << " name [" << (prefix != NULL ? prefix : "") << ":"
                    << lname << " (" << (uri != NULL ? uri : "NULL") << ")]"
                    << " value = " << typedValue->getStringValue()->c_str() << std::endl
                    << " ordpath = " << attrNode->getOrdPath().show() << std::endl);
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
void  FastXmlLoader::endElement(
    void * ctx, 
    const xmlChar * localName, 
    const xmlChar * prefix, 
    const xmlChar * uri)
{
  FastXmlLoader& loader = *(static_cast<FastXmlLoader *>(ctx));
  ZORBA_LOADER_CHECK_ERROR(loader);

  // Collect the children of this element node from the node stack
  std::vector<XmlNode*> revChildNodes;

  XmlNode* prevChild = NULL;
  XmlNode* currChild = loader.theNodeStack.top();
  while (currChild != NULL)
  {
    if (currChild->getNodeKind() == store::StoreConsts::textNode &&
        prevChild != NULL &&
        prevChild->getNodeKind() == store::StoreConsts::textNode)
    {
      TextNode* textSibling = reinterpret_cast<TextNode*>(prevChild);
      TextNode* textChild = reinterpret_cast<TextNode*>(currChild);
      xqpStringStore_t content2 = textChild->getText()->append(textSibling->getText());
      textSibling->setText(content2);
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
  ElementTreeNode* elemNode = dynamic_cast<ElementTreeNode*>(loader.theNodeStack.top());
  ZORBA_ASSERT(elemNode != NULL);

  LOADER_TRACE2("End Element: node = " << elemNode << " name ["
                << (prefix != NULL ? prefix : (xmlChar*)"") << ":" << localName
                << " (" << (uri != NULL ? uri : (xmlChar*)"NULL") << ")]");

  // For each child, make this element node its parent and fix its namespace
  // bindings context. Note: the children were popped from the stack in reverse
  // order, so we copy them into the element node in the correct order.
  NodeVector& children = elemNode->children();
  children.resize(revChildNodes.size());

  std::vector<XmlNode*>::const_reverse_iterator it;
  ulong i = 0;
  for (it = revChildNodes.rbegin();
       it != (std::vector<XmlNode*>::const_reverse_iterator)revChildNodes.rend();
       it++, i++)
  {
    currChild = *it;

    children.set(currChild, i, false);
    currChild->setParent(elemNode);

    if (currChild->getNodeKind() == store::StoreConsts::elementNode)
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

#ifdef DATAGUIDE
  if (loader.theBuildDataGuide)
  {
    // Remove from the dataguide stack
    assert(loader.theGuideStack.top()->getName()->equals(elemNode->getNodeName()));
    loader.theGuideStack.pop();
  }
#endif
}


/*******************************************************************************
  SAX2 callback when xml text has been detected by the parser.

  ctx: the user data (XML parser context)
  ch:  a xmlChar string
  len: the number of xmlChar
********************************************************************************/
void FastXmlLoader::characters(void * ctx, const xmlChar * ch, int len)
{
  FastXmlLoader& loader = *(static_cast<FastXmlLoader *>( ctx ));
  ZORBA_LOADER_CHECK_ERROR(loader);

  const char* charp = reinterpret_cast<const char*>(ch);
  xqpStringStore_t content(new xqpStringStore(charp, len));

  XmlNode* textNode = new TextNode(content);

  if (loader.theNodeStack.empty())
    loader.setRoot(textNode);

  loader.theNodeStack.push(textNode);

  textNode->setId(loader.theTree, &loader.theOrdPath);
  loader.theOrdPath.nextChild();

  SYNC_CODE(textNode->theRCLockPtr = &loader.theTree->getRCLock();)

  LOADER_TRACE1("Text Node = " << textNode << " content = "
                << std::string(charp, len) << std::endl << " ordpath = "
                << textNode->getOrdPath().show() << std::endl);
}


/*******************************************************************************
  SAX2 callback when a CDATA block has been detected by the parser.

  ctx: the user data (XML parser context)
  ch:  a xmlChar string
  len: the number of xmlChar
********************************************************************************/
void FastXmlLoader::cdataBlock(void * ctx, const xmlChar * ch, int len)
{
  FastXmlLoader& loader = *(static_cast<FastXmlLoader *>( ctx ));
  ZORBA_LOADER_CHECK_ERROR(loader);

  const char* charp = reinterpret_cast<const char*>(ch);
  xqpStringStore_t content(new xqpStringStore(charp, len));

  XmlNode* textNode = new TextNode(content);

  if (loader.theNodeStack.empty())
    loader.setRoot(textNode);

  loader.theNodeStack.push(textNode);

  textNode->setId(loader.theTree, &loader.theOrdPath);
  loader.theOrdPath.nextChild();

  SYNC_CODE(textNode->theRCLockPtr = &loader.theTree->getRCLock();)
 
  LOADER_TRACE1("Text Node = " << textNode << " content = "
                << std::string(charp, len) << std::endl << " ordpath = "
                << textNode->getOrdPath().show() << std::endl);
}


/*******************************************************************************
  SAX2 callback when a processing instruction has been detected by the parser.

  ctx: the user data (XML parser context)

********************************************************************************/
void FastXmlLoader::processingInstruction(
    void * ctx, 
    const xmlChar * targetp, 
    const xmlChar * data)
{
  FastXmlLoader& loader = *(static_cast<FastXmlLoader *>( ctx ));
  ZORBA_LOADER_CHECK_ERROR(loader);

  xqpStringStore_t content = new xqpStringStore(reinterpret_cast<const char*>(data));
  xqpStringStore_t target = new xqpStringStore(reinterpret_cast<const char*>(targetp));

  XmlNode* piNode = new PiNode(target, content);

  if (loader.theNodeStack.empty())
    loader.setRoot(piNode);

  loader.theNodeStack.push(piNode);

  piNode->setId(loader.theTree, &loader.theOrdPath);
  loader.theOrdPath.nextChild();

  SYNC_CODE(piNode->theRCLockPtr = &loader.theTree->getRCLock();)

  LOADER_TRACE1("Pi Node = " << piNode << " target = "
                << targetp << std::endl << " ordpath = "
                << piNode->getOrdPath().show() << std::endl);
}


/*******************************************************************************
  SAX2 callback when a comment has been detected by the parser.

  ctx: the user data (XML parser context)
  content:  the comment content
********************************************************************************/
void FastXmlLoader::comment(void * ctx, const xmlChar * ch)
{
  FastXmlLoader& loader = *(static_cast<FastXmlLoader *>( ctx ));
  ZORBA_LOADER_CHECK_ERROR(loader);

  const char* charp = reinterpret_cast<const char*>(ch);
  xqpStringStore_t content(new xqpStringStore(charp));

  XmlNode* commentNode = new CommentNode(content);

  if (loader.theNodeStack.empty())
    loader.setRoot(commentNode);

  loader.theNodeStack.push(commentNode);

  commentNode->setId(loader.theTree, &loader.theOrdPath);
  loader.theOrdPath.nextChild();

  SYNC_CODE(commentNode->theRCLockPtr = &loader.theTree->getRCLock();)

  LOADER_TRACE1("Comment Node = " << commentNode << " content = "
                << charp << std::endl << " ordpath = "
                << commentNode->getOrdPath().show() << std::endl);
}


/*******************************************************************************
  Display and format an error messages, callback.
 
   ctx:  an XML parser context
   msg:  the message to display/transmit
   ...:  extra parameters for the message display
********************************************************************************/
void  FastXmlLoader::error(void * ctx, const char * msg, ... )
{
  FastXmlLoader* loader = (static_cast<FastXmlLoader *>(ctx));
  char buf[1024];
  va_list args;
  va_start(args, msg);
  vsprintf(buf, msg, args);
  va_end(args);
  ZORBA_ERROR_DESC_CONTINUE(loader->theErrorManager,
                            XQP0017_LOADER_PARSING_ERROR, buf);
}


/*******************************************************************************
   Display and format a warning messages, callback.
  
   ctx:  an XML parser context
   msg:  the message to display/transmit
   ...:  extra parameters for the message display
********************************************************************************/
void  FastXmlLoader::warning(void * ctx, const char * msg, ... )
{
  char buf[1024];
  va_list args;
  va_start(args, msg);
  vsprintf(buf, msg, args);
  va_end(args);

  std::cerr << buf << std::endl;
}

#undef ZORBA_ERROR_DESC_CONTINUE

} // namespace store
} // namespace zorba
