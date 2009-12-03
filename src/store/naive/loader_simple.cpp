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

#include "common/common.h"
#include "zorbautils/fatal.h"
#include "zorbaerrors/error_manager.h"
#include "zorbaerrors/Assert.h"

#include "store/api/item_factory.h"
#include "store/api/item.h"
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
SimpleXmlLoader::SimpleXmlLoader(
    store::ItemFactory* factory,
    error::ErrorManager* errorManager,
    bool dataguide)
  :
  XmlLoader(factory, errorManager, dataguide),
  theRootNode(NULL)
{
  memset(&theSaxHandler, 0, sizeof(theSaxHandler) );
  theSaxHandler.initialized = XML_SAX2_MAGIC;
  theSaxHandler.startDocument = &SimpleXmlLoader::startDocument;
  theSaxHandler.endDocument = &SimpleXmlLoader::endDocument;
  theSaxHandler.startElementNs = &SimpleXmlLoader::startElement;
  theSaxHandler.endElementNs = &SimpleXmlLoader::endElement;
  theSaxHandler.characters = &SimpleXmlLoader::characters;
  theSaxHandler.cdataBlock = &SimpleXmlLoader::cdataBlock;
  theSaxHandler.comment = &SimpleXmlLoader::comment;
  theSaxHandler.processingInstruction = &SimpleXmlLoader::processingInstruction;
  theSaxHandler.warning = &SimpleXmlLoader::warning;
  theSaxHandler.error = &SimpleXmlLoader::error;
}


/*******************************************************************************

********************************************************************************/
SimpleXmlLoader::~SimpleXmlLoader()
{
}


/*******************************************************************************
  Method called to do cleanup in case of errors.
********************************************************************************/
void SimpleXmlLoader::abortload()
{
  theBaseUri = NULL;
  theDocUri = NULL;

  theRootNode = NULL;

  while (!theNodeStack.empty())
  {
    theNodeStack.pop();
  }
}


/*******************************************************************************

********************************************************************************/
store::Item_t SimpleXmlLoader::loadXml(
    const xqpStringStore_t& docuri,
    std::istream& stream)
{
  xmlParserCtxtPtr ctxt = NULL;

  theDocUri = docuri;

  try
  {
    long numChars = readPacket(stream, theBuffer, 4096);

    if (numChars < 0)
    {
      ZORBA_ERROR_DESC_CONTINUE(theErrorManager, STR0007_LOADER_IO_ERROR,
                                "Unknown I/O error");
      abortload();
      return NULL;
    }
    else if (numChars == 0)
    {
      ZORBA_ERROR_DESC_CONTINUE(theErrorManager, STR0007_LOADER_IO_ERROR,
                                "No input data.");
      abortload();
      return NULL;
    }

    ctxt = xmlCreatePushParserCtxt(&theSaxHandler, this, theBuffer, numChars, NULL);

    if (ctxt == NULL)
    {
      ZORBA_ERROR_DESC_CONTINUE(theErrorManager, STR0008_LOADER_PARSING_ERROR, 
                                "Failed to initialize parser");
      abortload();
			return NULL;
    }

    while ((numChars = readPacket(stream, theBuffer, 4096)) > 0)
    {
      xmlParseChunk(ctxt, theBuffer, numChars, 0);

      if (theErrorManager->hasErrors())
      {
        xmlFreeParserCtxt(ctxt);
        abortload();
        return NULL;
      }
    }

    if (numChars < 0)
    {
      ZORBA_ERROR_DESC_CONTINUE(theErrorManager, STR0007_LOADER_IO_ERROR,
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
                                     STR0008_LOADER_PARSING_ERROR,
                                     "The document with URI " << *theDocUri
                                     <<" is not well formed", "");
    }
    else
    {
      ZORBA_ERROR_DESC_CONTINUE(theErrorManager,
                                STR0008_LOADER_PARSING_ERROR,
                                "Not well formed XML");
    }

    abortload();
    return NULL;
  }

  ZORBA_FATAL(theNodeStack.empty(), "");

  store::Item_t result;
  result.transfer(theRootNode);
  return result;
}


/*******************************************************************************
  Read up to "size" bytes from the given input stream into the given buffer.
  Return the number of bytes actually read, throw an exception if any I/O
  error occured.
********************************************************************************/
long SimpleXmlLoader::readPacket(std::istream& stream, char* buf, long size)
{
  try
  {
    stream.read(buf, size);

    if (stream.bad())
    {
      ZORBA_ERROR_DESC_CONTINUE(theErrorManager,
                                STR0007_LOADER_IO_ERROR,
                                "Input stream in bad state");
    }

    return stream.gcount();
  }
  catch (std::iostream::failure e)
  {
    ZORBA_ERROR_DESC_CONTINUE(theErrorManager,
                              STR0007_LOADER_IO_ERROR, e.what());
  }
  catch (...)
  {
    ZORBA_ERROR_DESC_CONTINUE(theErrorManager, 
                              STR0007_LOADER_IO_ERROR,
                              "Unknown exception");
  }

  return -1;
}


/*******************************************************************************
  SAX2 callback when the start of document has been detected by the parser.

  ctx: the user data (XML parser context)
********************************************************************************/
void SimpleXmlLoader::startDocument(void * ctx)
{
  SimpleXmlLoader& loader = *(static_cast<SimpleXmlLoader *>(ctx));
  ZORBA_LOADER_CHECK_ERROR(loader);

  try
  {
    xqpStringStore_t docUri = loader.theDocUri;
    xqpStringStore_t baseUri = loader.theBaseUri;
    store::Item_t docNode;

    loader.theFactory->createDocumentNode(docNode, baseUri, docUri);

    loader.theRootNode = docNode;
    loader.theNodeStack.push(docNode.getp());

    LOADER_TRACE1("Start Doc Node = " << docNode.getp());
  }
  catch (error::ZorbaError& e)
  {
    ZORBA_ERROR_DESC_CONTINUE(loader.theErrorManager,
                              e.theErrorCode, e.theDescription);
  }
  catch (...)
  {
    ZORBA_ERROR_DESC_CONTINUE(loader.theErrorManager,
                              XQP0019_INTERNAL_ERROR, "Unknown exception");
  }
}


/*******************************************************************************
  SAX2 callback when the end of document has been detected by the parser.

  ctx: the user data (XML parser context)
********************************************************************************/
void SimpleXmlLoader::endDocument(void * ctx)
{
  SimpleXmlLoader& loader = *(static_cast<SimpleXmlLoader *>(ctx));
  ZORBA_LOADER_CHECK_ERROR(loader);

  try
  {
    // This check is required because it is possible (in case of mal-formed doc)
    // that libXml calls endDocument() without having called startDocument().
    if (loader.theNodeStack.size() == 0 )
      return;
  
    store::Item* docNode = loader.theNodeStack.top();
    loader.theNodeStack.pop();

    ZORBA_ASSERT(docNode != NULL);

    docNode->finalizeNode();

    LOADER_TRACE2("End Doc Node = " << docNode);
  }
  catch (error::ZorbaError& e)
  {
    ZORBA_ERROR_DESC_CONTINUE(loader.theErrorManager,
                              e.theErrorCode, e.theDescription);
  }
  catch (...)
  {
    ZORBA_ERROR_DESC_CONTINUE(loader.theErrorManager,
                              XQP0019_INTERNAL_ERROR, "Unknown exception");
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
  attributes:    pointer to the array of (localname/prefix/URI/value/end)
                 attribute values.
********************************************************************************/
void SimpleXmlLoader::startElement(
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
  SimpleXmlLoader& loader = *(static_cast<SimpleXmlLoader *>(ctx));
  ZORBA_LOADER_CHECK_ERROR(loader);

  try
  {
    ulong numAttributes = (ulong)numAttrs;
    ulong numBindings = (ulong)numNamespaces;

    store::Item* parent = NULL;
    store::Item_t qname;
    store::Item_t tname;
    store::Item_t nullValue;
    xqpStringStore_t baseUri;

    // Get the parent node from the node stack
    if (!loader.theNodeStack.empty())
      parent = loader.theNodeStack.top();

    // Construct node name and type
    loader.theFactory->createQName(qname,
                                   reinterpret_cast<const char*>(uri),
                                   reinterpret_cast<const char*>(prefix),
                                   reinterpret_cast<const char*>(lname));
    loader.theFactory->createQName(tname,
                                   "http://www.w3.org/2001/XMLSchema",
                                   "xs",
                                   "untyped");

    // If this is going to be the root of the xml tree, give it the input base uri
    if (parent == NULL)
      baseUri = loader.theBaseUri;

    // Process namespace bindings
    store::NsBindings bindings(numBindings);
    for (ulong i = 0; i < numBindings; ++i)
    {
      const char* prefix = reinterpret_cast<const char*>(namespaces[i * 2]);
      const char* nsuri = reinterpret_cast<const char*>(namespaces[i * 2 + 1]);

      if (prefix == NULL)
        prefix = "";

      bindings[i].first = new xqpStringStore(prefix);
      bindings[i].second = new xqpStringStore(nsuri);
    
      LOADER_TRACE1("namespace decl: [" << prefix  << ":" << nsuri << "]");
    }

    // Create the element node and push it to the node stack
    store::Item_t node;
    loader.theFactory->createElementNode(node, parent, -1, qname,
                                         tname, true, false,
                                         bindings, baseUri);

    if (loader.theNodeStack.empty())
      loader.theRootNode = node;

    loader.theNodeStack.push(node.getp());

    LOADER_TRACE1("Start Element: node = " << node.getp() << std::endl
                  << node->show() << std::endl);

    // Process attributes

    loader.theFactory->createQName(tname,
                                   "http://www.w3.org/2001/XMLSchema",
                                   "xs",
                                   "untypedAtomic");
    ulong index = 0;
    for (ulong i = 0; i < numAttributes; ++i, index += 5)
    {
      const char* lname = reinterpret_cast<const char*>(attributes[index]);
      const char* prefix = reinterpret_cast<const char*>(attributes[index+1]);
      const char* uri = reinterpret_cast<const char*>(attributes[index+2]);
      const char* valueBegin = reinterpret_cast<const char*>(attributes[index+3]);
      const char* valueEnd = reinterpret_cast<const char*>(attributes[index+4]);

      loader.theFactory->createQName(qname, uri, prefix, lname);

      xqpStringStore_t stringValue = new xqpStringStore(valueBegin, valueEnd);
      store::Item_t typedValue;
      loader.theFactory->createUntypedAtomic(typedValue, stringValue);

      store::Item_t tnameCopy = tname;
      store::Item_t attr;
      loader.theFactory->createAttributeNode(attr,
                                             node,
                                             -1,
                                             qname,
                                             tnameCopy,
                                             typedValue);

      LOADER_TRACE1("Attribute: node = " << attr.getp() << std::endl
                    << attr->show() << std::endl);
    }
  }
  catch (error::ZorbaError& e)
  {
    ZORBA_ERROR_DESC_CONTINUE(loader.theErrorManager,
                              e.theErrorCode, e.theDescription);
  }
  catch (...)
  {
    ZORBA_ERROR_DESC_CONTINUE(loader.theErrorManager,
                              XQP0019_INTERNAL_ERROR, "Unknown exception");
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
void SimpleXmlLoader::endElement(
    void * ctx, 
    const xmlChar * localName, 
    const xmlChar * prefix, 
    const xmlChar * uri)
{
  SimpleXmlLoader& loader = *(static_cast<SimpleXmlLoader *>(ctx));
  ZORBA_LOADER_CHECK_ERROR(loader);

  try
  {
    store::Item* node = loader.theNodeStack.top();
    ZORBA_ASSERT(node != NULL);
    loader.theNodeStack.pop();

    node->finalizeNode();

    LOADER_TRACE2("End Element: node = " << node << " name = "
                  << node->getNodeName()->show() << std::endl);
  }
  catch (error::ZorbaError& e)
  {
    ZORBA_ERROR_DESC_CONTINUE(loader.theErrorManager,
                              e.theErrorCode, e.theDescription);
  }
  catch (...)
  {
    ZORBA_ERROR_DESC_CONTINUE(loader.theErrorManager,
                              XQP0019_INTERNAL_ERROR, "Unknown exception");
  }
}


/*******************************************************************************
  SAX2 callback when xml text has been detected by the parser.

  ctx: the user data (XML parser context)
  ch:  a xmlChar string
  len: the number of xmlChar
********************************************************************************/
void SimpleXmlLoader::characters(void * ctx, const xmlChar * ch, int len)
{
  SimpleXmlLoader& loader = *(static_cast<SimpleXmlLoader *>( ctx ));
  ZORBA_LOADER_CHECK_ERROR(loader);

  try
  {
    store::Item* parent = NULL;

    // Get the parent node from the node stack
    if (!loader.theNodeStack.empty())
      parent = loader.theNodeStack.top();

    // Get the text content
    const char* charp = reinterpret_cast<const char*>(ch);
    xqpStringStore_t content(new xqpStringStore(charp, len));

    // Create the text node
    store::Item_t node;
    loader.theFactory->createTextNode(node, parent, -1, content);

    if (loader.theNodeStack.empty())
      loader.theRootNode = node;

    LOADER_TRACE1("Text Node = " << node.getp() << std::endl
                  << node->show() << std::endl);
  }
  catch (error::ZorbaError& e)
  {
    ZORBA_ERROR_DESC_CONTINUE(loader.theErrorManager,
                              e.theErrorCode, e.theDescription);
  }
  catch (...)
  {
    ZORBA_ERROR_DESC_CONTINUE(loader.theErrorManager,
                              XQP0019_INTERNAL_ERROR, "Unknown exception");
  }
}


/*******************************************************************************
  SAX2 callback when a CDATA block has been detected by the parser.

  ctx: the user data (XML parser context)
  ch:  a xmlChar string
  len: the number of xmlChar
********************************************************************************/
void SimpleXmlLoader::cdataBlock(void * ctx, const xmlChar * ch, int len)
{
  SimpleXmlLoader& loader = *(static_cast<SimpleXmlLoader *>( ctx ));
  ZORBA_LOADER_CHECK_ERROR(loader);

  try
  {
    store::Item* parent = NULL;

    // Get the parent node from the node stack
    if (!loader.theNodeStack.empty())
      parent = loader.theNodeStack.top();

    // Get the text content
    const char* charp = reinterpret_cast<const char*>(ch);
    xqpStringStore_t content(new xqpStringStore(charp, len));

    // Create the text node
    store::Item_t node;
    loader.theFactory->createTextNode(node, parent, -1, content);

    if (loader.theNodeStack.empty())
      loader.theRootNode = node;

    LOADER_TRACE1("CDATA Node = " << node.getp() << std::endl
                  << node->show() << std::endl);
  }
  catch (error::ZorbaError& e)
  {
    ZORBA_ERROR_DESC_CONTINUE(loader.theErrorManager,
                              e.theErrorCode, e.theDescription);
  }
  catch (...)
  {
    ZORBA_ERROR_DESC_CONTINUE(loader.theErrorManager,
                              XQP0019_INTERNAL_ERROR, "Unknown exception");
  }
}


/*******************************************************************************
  SAX2 callback when a processing instruction has been detected by the parser.

  ctx: the user data (XML parser context)

********************************************************************************/
void SimpleXmlLoader::processingInstruction(
    void * ctx, 
    const xmlChar * targetp, 
    const xmlChar * data)
{
  SimpleXmlLoader& loader = *(static_cast<SimpleXmlLoader *>( ctx ));
  ZORBA_LOADER_CHECK_ERROR(loader);

  try
  {
    store::Item* parent = NULL;

    // Get the parent node from the node stack
    if (!loader.theNodeStack.empty())
      parent = loader.theNodeStack.top();

    xqpStringStore_t content = new xqpStringStore(reinterpret_cast<const char*>(data));
    xqpStringStore_t target = new xqpStringStore(reinterpret_cast<const char*>(targetp));
    xqpStringStore_t baseUri;

    store::Item_t node;
    loader.theFactory->createPiNode(node, parent, -1, target, content, baseUri);

    if (loader.theNodeStack.empty())
      loader.theRootNode = node;

    LOADER_TRACE1("Pi Node = " << node.getp() << std::endl
                  << node->show() << std::endl);
  }
  catch (error::ZorbaError& e)
  {
    ZORBA_ERROR_DESC_CONTINUE(loader.theErrorManager,
                              e.theErrorCode, e.theDescription);
  }
  catch (...)
  {
    ZORBA_ERROR_DESC_CONTINUE(loader.theErrorManager,
                              XQP0019_INTERNAL_ERROR, "Unknown exception");
  }
}


/*******************************************************************************
  SAX2 callback when a comment has been detected by the parser.

  ctx: the user data (XML parser context)
  content:  the comment content
********************************************************************************/
void SimpleXmlLoader::comment(void * ctx, const xmlChar * ch)
{
  SimpleXmlLoader& loader = *(static_cast<SimpleXmlLoader *>( ctx ));
  ZORBA_LOADER_CHECK_ERROR(loader);

  try
  {
    store::Item* parent = NULL;

    // Get the parent node from the node stack
    if (!loader.theNodeStack.empty())
      parent = loader.theNodeStack.top();

    const char* charp = reinterpret_cast<const char*>(ch);
    xqpStringStore_t content(new xqpStringStore(charp));

    store::Item_t node;
    loader.theFactory->createCommentNode(node, parent, -1, content);

    if (loader.theNodeStack.empty())
      loader.theRootNode = node;

    LOADER_TRACE1("Comment Node = " << node.getp() << std::endl
                  << node->show() << std::endl);
  }
  catch (error::ZorbaError& e)
  {
    ZORBA_ERROR_DESC_CONTINUE(loader.theErrorManager,
                              e.theErrorCode, e.theDescription);
  }
  catch (...)
  {
    ZORBA_ERROR_DESC_CONTINUE(loader.theErrorManager,
                              XQP0019_INTERNAL_ERROR, "Unknown exception");
  }
}


/*******************************************************************************
  Display and format an error messages, callback.
 
   ctx:  an XML parser context
   msg:  the message to display/transmit
   ...:  extra parameters for the message display
********************************************************************************/
void  SimpleXmlLoader::error(void * ctx, const char * msg, ... )
{
  SimpleXmlLoader* loader = (static_cast<SimpleXmlLoader *>(ctx));
  char buf[1024];
  va_list args;
  va_start(args, msg);
  vsprintf(buf, msg, args);
  va_end(args);
  ZORBA_ERROR_DESC_CONTINUE(loader->theErrorManager,
                            STR0008_LOADER_PARSING_ERROR, buf);
}


/*******************************************************************************
   Display and format a warning messages, callback.
  
   ctx:  an XML parser context
   msg:  the message to display/transmit
   ...:  extra parameters for the message display
********************************************************************************/
void  SimpleXmlLoader::warning(void * ctx, const char * msg, ... )
{
  char buf[1024];
  va_list args;
  va_start(args, msg);
  vsprintf(buf, msg, args);
  va_end(args);

  std::cerr << buf << std::endl;
}

#undef ZORBA_ERROR_DESC_CONTINUE

} // namespace simplestore
} // namespace zorba
