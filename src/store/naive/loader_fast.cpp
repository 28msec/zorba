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
#include "stdafx.h"

#include <cstdio>
#include <memory.h>
#include <string>
#include <iostream>

#include <libxml/xmlmemory.h>

#include <zorba/store_consts.h>

#include "store_defs.h"
#include "string_pool.h"
#include "qname_pool.h"
#include "simple_store.h"
#include "atomic_items.h"
#include "node_items.h"
#include "dataguide.h"
#include "nsbindings.h"
#include "loader.h"
#include "simple_item_factory.h"
#include "node_factory.h"

#include "zorbatypes/datetime.h"
#include "zorbatypes/URI.h"

#include "diagnostics/xquery_diagnostics.h"
#include "diagnostics/assert.h"
#include "util/ascii_util.h"
#include "util/stream_util.h"

namespace zorba {
namespace simplestore {

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
    if (!loader.theXQueryDiagnostics->errors().empty()) \
      return; \
  } while (0);


/*******************************************************************************

********************************************************************************/
XmlLoader::XmlLoader(
    store::ItemFactory* factory,
    XQueryDiagnostics* xqueryDiagnostics,
    const store::LoadProperties& loadProperties,
    bool dataguide)
  :
  theLoadProperties(loadProperties),
  ctxt(NULL),
  theFactory(static_cast<BasicItemFactory*>(factory)),
  theXQueryDiagnostics(xqueryDiagnostics),
  theTraceLevel(0),
  theBuildDataGuide(dataguide)
{
}


XmlLoader::~XmlLoader() 
{
}


/*******************************************************************************

********************************************************************************/
void XmlLoader::error(void* ctx, xmlErrorPtr error)
{
  if ( error->level == XML_ERR_NONE )
    return;

  ascii::itoa_buf_type itoa_buf;

  zstring libxml_dict_key_4( ZED_PREFIX "libxml_" );
  libxml_dict_key_4 += ascii::itoa( error->code, itoa_buf );

  char const *const error_str1_5 = error->str1 ? error->str1 : "";
  char const *const error_str2_6 = error->str2 ? error->str2 : "";
  char const *const error_str3_7 = error->str3 ? error->str3 : "";
  zstring error_int1_8;
  char const *const error_message_9 = error->message ? error->message : "";

  if ( error->int1 ) 
  {
    // assume valid only if > 0
    switch ( error->code )
    {
      case XML_ERR_ENTITY_CHAR_ERROR:
      case XML_ERR_INVALID_CHAR:
      case XML_ERR_SEPARATOR_REQUIRED:
        // For these error codes, int1 is a char.
        error_int1_8 = static_cast<char>( error->int1 );
        break;
      case XML_DTD_ID_SUBSET:
      case XML_DTD_UNKNOWN_ID:
      case XML_ERR_ELEMCONTENT_NOT_FINISHED:
      case XML_ERR_INTERNAL_ERROR:
      case XML_ERR_TAG_NOT_FINISHED:
        // For these error codes, int1 is an int.
        error_int1_8 = ascii::itoa( error->int1, itoa_buf );
        break;
      default:
        // For an unaccounted-for error code, use a heuristic to guess whether
        // int1 is a char or an int.
        if ( ascii::is_print( error->int1 ) )
          error_int1_8 = static_cast<char>( error->int1 );
        else
          error_int1_8 = ascii::itoa( error->int1, itoa_buf );
    } // switch
  } // if

  XmlLoader *const loader = static_cast<XmlLoader*>( ctx );

  xmlErrorLevel errorLevel = error->level;

  //This is a dirty hack to consider a recoverable error a warning
  if (error->code == XML_WAR_NS_URI)
  {
    errorLevel = XML_ERR_WARNING;
  }

  switch (errorLevel)
  {
    case XML_ERR_ERROR:
    case XML_ERR_FATAL:
    {
      XQueryException *const xe =
      NEW_XQUERY_EXCEPTION(zerr::ZSTR0021_LOADER_PARSING_ERROR,
      ERROR_PARAMS(error->file, error->line, error->int2 /* column */,
                   libxml_dict_key_4, error_str1_5, error_str2_6, error_str3_7,
                   error_int1_8, error_message_9));

      xe->set_data( error->file, error->line, error->int2 /* column */ );
      loader->theXQueryDiagnostics->add_error( xe );
      break;
    }
    case XML_ERR_WARNING:
    {
      XQueryWarning *const xw =
      NEW_XQUERY_WARNING(zwarn::ZWST0007_LOADER_PARSING_WARNING,
      WARN_PARAMS(error->file, error->line, error->int2 /* column */,
                  libxml_dict_key_4, error_str1_5, error_str2_6, error_str3_7,
                  error_int1_8, error_message_9));
      xw->set_data( error->file, error->line, error->int2 /* column */ );
      loader->theXQueryDiagnostics->add_warning( xw );
      break;
    }
    default:
      ZORBA_ASSERT( false );
  } // switch
}


/*******************************************************************************

********************************************************************************/
FastXmlLoader::FastXmlLoader(
    store::ItemFactory* factory,
    XQueryDiagnostics* xqueryDiagnostics,
    const store::LoadProperties& loadProperties,
    bool dataguide)
  :
  XmlLoader(factory, xqueryDiagnostics, loadProperties, dataguide),
  theTree(NULL),
  theRootNode(NULL),
  theNodeStack(2048)
{
  theBuffer = new char[INPUT_CHUNK_SIZE];
  theOrdPath.init();

  theTraceLevel = GET_STORE().getTraceLevel();

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
  theSaxHandler.serror = &XmlLoader::error;
  theSaxHandler.getEntity = &FastXmlLoader::getEntity;
  theSaxHandler.getParameterEntity = &FastXmlLoader::getParameterEntity;
  theSaxHandler.entityDecl = &FastXmlLoader::entityDecl;
}


/*******************************************************************************

********************************************************************************/
FastXmlLoader::~FastXmlLoader()
{
  delete[] theBuffer;
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
  theBaseUri.clear();
  theDocUri.clear();

  theOrdPath.init();
  theRootNode = NULL;

  while(!theNodeStack.empty())
  {
    XmlNode* node = theNodeStack.top();
    theNodeStack.pop();
    if (node != NULL)
      node->destroy(true);
  }

  if (theTree != NULL)
  {
    delete theTree;
    theTree = NULL;
  }

  thePathStack.clear();

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
    //NsBindingsContext* ctx = theBindingsStack.top();
    theBindingsStack.pop();
    //delete ctx;
  }

  if(ctxt)
  {
    xmlCtxtReset(ctxt);
    xmlFreeParserCtxt(ctxt);
    ctxt = NULL;
  }
}


/*******************************************************************************
  Method used to reset the loader so it can be used to load another document.
********************************************************************************/
void FastXmlLoader::reset()
{
  theBaseUri.clear();
  theDocUri.clear();

  theTree = NULL;
  theOrdPath.init();
  theRootNode = NULL;

  if (!theNodeStack.empty())
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
std::streamsize FastXmlLoader::readPacket(std::istream& stream, char* buf, long size)
{
  try
  {
    stream.read(buf, size);

    if (stream.bad())
    {
      theXQueryDiagnostics->
      add_error(NEW_ZORBA_EXCEPTION(zerr::ZSTR0020_LOADER_IO_ERROR,
                                    ERROR_PARAMS(ZED(BadStreamState))));
    }

    return stream.gcount();
  }
  catch (std::iostream::failure e)
  {
    theXQueryDiagnostics->add_error(
      NEW_ZORBA_EXCEPTION(
        zerr::ZSTR0020_LOADER_IO_ERROR, ERROR_PARAMS( e.what() )
      )
    );
  }
  catch (...)
  {
    theXQueryDiagnostics->add_error(
      NEW_ZORBA_EXCEPTION( zerr::ZSTR0020_LOADER_IO_ERROR )
    );
  }

  return -1;
}


/*******************************************************************************

********************************************************************************/
store::Item_t FastXmlLoader::loadXml(
    const zstring& baseUri,
    const zstring& docUri,
    std::istream& stream)
{
  //  xmlParserCtxtPtr ctxt = NULL;
  theTree = GET_STORE().getNodeFactory().createXmlTree();

  xmlSubstituteEntitiesDefault(1);

  theBaseUri = baseUri;

  char const *doc_uri;
  if ( char const *const stream_uri = get_uri( stream ) )
    doc_uri = stream_uri;
  else
    doc_uri = docUri.c_str();

  if (docUri.empty())
  {
    std::ostringstream uristream;
    uristream << "zorba://internalDocumentURI-" << theTree->getTreeId();

    theDocUri = uristream.str();
  }
  else
  {
    theDocUri = docUri;
  }

  thePathStack.push(PathStepInfo(NULL, baseUri));

  try
  {
    std::streamsize numChars = readPacket(stream, theBuffer, INPUT_CHUNK_SIZE);

    if (numChars < 0)
    {
      theXQueryDiagnostics->
      add_error(NEW_ZORBA_EXCEPTION(zerr::ZSTR0020_LOADER_IO_ERROR));

      abortload();
      return NULL;
    }
    else if (numChars == 0)
    {
      theXQueryDiagnostics->
      add_error(NEW_ZORBA_EXCEPTION(zerr::ZSTR0020_LOADER_IO_ERROR,
                                    ERROR_PARAMS(ZED(NoInputData))));
      abortload();
      return NULL;
    }

    ctxt = xmlCreatePushParserCtxt(&theSaxHandler,
                                   this,
                                   theBuffer,
                                   static_cast<int>(numChars),
                                   doc_uri);

    // Apply loader options
    store::LoadProperties new_props = theLoadProperties;
    new_props.setSubstituteEntities(true); // This is required for some Zorba tests,
                                           // e.g. rbkt/Queries/zorba/entity/entity.xq
                                           // It should probably be handled in a different way
    applyLoadOptions(new_props, ctxt);

    if (ctxt == NULL)
    {
      theXQueryDiagnostics->
      add_error(NEW_ZORBA_EXCEPTION(zerr::ZSTR0021_LOADER_PARSING_ERROR,
                                    ERROR_PARAMS(ZED(XMLParserInitFailed))));
      abortload();
			return NULL;
    }

    while ((numChars = readPacket(stream, theBuffer, INPUT_CHUNK_SIZE)) > 0)
    {
      xmlParseChunk(ctxt, theBuffer, static_cast<int>(numChars), 0);

      if (!theXQueryDiagnostics->errors().empty())
      {
        abortload();
        return NULL;
      }
    }

    if (numChars < 0)
    {
      theXQueryDiagnostics->
      add_error(NEW_ZORBA_EXCEPTION(zerr::ZSTR0020_LOADER_IO_ERROR));

      abortload();
      return NULL;
    }

    xmlParseChunk(ctxt, theBuffer, 0, 1);
  }
  catch(...)
  {
    abortload();
    return NULL;
  }

  bool ok = ctxt->wellFormed != 0;

  // Free parser resources
  xmlCtxtReset(ctxt);
  xmlFreeParserCtxt(ctxt);
  ctxt = NULL;

  // The doc may be well formed, but it may have other kinds of errors,
  // e.g., unresolved ns prefixes.
  if (!theXQueryDiagnostics->errors().empty())
  {
    abortload();
    return NULL;
  }
  else if (!ok)
  {
    theXQueryDiagnostics->add_error(
      NEW_ZORBA_EXCEPTION(
        zerr::ZSTR0021_LOADER_PARSING_ERROR,
        ERROR_PARAMS( ZED( BadXMLDocument_2o ), theDocUri )
      )
    );
    abortload();
    return NULL;
  }

  thePathStack.pop();
  assert(thePathStack.empty());

  XmlNode* resultNode;
  resultNode = theRootNode;
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
  
  try
  {
    DocumentNode* docNode = GET_STORE().getNodeFactory().createDocumentNode();

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

    docNode->setBaseUri(loader.theBaseUri);
    docNode->setDocUri(loader.theDocUri);
    docNode->setId(loader.theTree, &loader.theOrdPath);
    loader.theOrdPath.pushChild();

    LOADER_TRACE1("Start Doc Node = " << docNode);
  }
  catch (ZorbaException const& e)
  {
    loader.theXQueryDiagnostics->add_error( e );
  }
  catch (...)
  {
    loader.theXQueryDiagnostics->
    add_error(NEW_ZORBA_EXCEPTION(zerr::ZXQP0003_INTERNAL_ERROR));
  }
}


/*******************************************************************************
  SAX2 callback when the end of document has been detected by the parser.

  ctx: the user data (XML parser context)
********************************************************************************/
void FastXmlLoader::endDocument(void * ctx)
{
  FastXmlLoader& loader = *(static_cast<FastXmlLoader *>(ctx));
  ZORBA_LOADER_CHECK_ERROR(loader);

  zorba::Stack<XmlNode*>& nodeStack = loader.theNodeStack;
  ulong stackSize = nodeStack.size();
  ulong firstChildPos;
  ulong numChildren;
  ulong numActualChildren;
  ulong i;
  DocumentNode* docNode;
  XmlNode* currChild;
  
  try
  {
    // This check is required because it is possible (in case of mal-formed doc)
    // that libXml calls endDocument() without having called startDocument().
    if (stackSize == 0)
      return;

    // Find the position of the 1st child of this doc node in the node stack
    firstChildPos = stackSize - 1;
    while (nodeStack[firstChildPos] != NULL)
      --firstChildPos;

    // Find the doc node in the stack
    docNode = dynamic_cast<DocumentNode*>(nodeStack[firstChildPos-1]);
    ZORBA_ASSERT(docNode != NULL);

    // For each child, make this doc node its parent.
    InternalNode::NodeVector& children = docNode->nodes();

    numChildren = nodeStack.size() - firstChildPos - 1;

    children.resize(numChildren);

    numActualChildren = 0;

    for (i = firstChildPos + 1; i < stackSize; ++i)
    {
      currChild = nodeStack[i];
      children[numActualChildren] = currChild;
      if (loader.theLoadProperties.getCreateDocParentLink())
        currChild->setParent(docNode);
      ++numActualChildren;
    }

    nodeStack.pop(numChildren+1);

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
  catch (ZorbaException const& e)
  {
    loader.theXQueryDiagnostics->add_error( e );
  }
  catch (...)
  {
    loader.theXQueryDiagnostics->add_error(
      NEW_ZORBA_EXCEPTION( zerr::ZXQP0003_INTERNAL_ERROR )
    );
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
  Store& store = GET_STORE();
  NodeFactory& nfactory = store.getNodeFactory();
  FastXmlLoader& loader = *(static_cast<FastXmlLoader *>(ctx));
  ZORBA_LOADER_CHECK_ERROR(loader);
  QNamePool& qnpool = store.getQNamePool();
  zorba::Stack<XmlNode*>& nodeStack = loader.theNodeStack;
  zorba::Stack<PathStepInfo>& pathStack = loader.thePathStack;
  zstring baseUri;

  try
  {
    csize numAttributes = static_cast<csize>(numAttrs);
    csize numBindings = static_cast<csize>(numNamespaces);

    // Construct node name
    store::Item_t nodeName;
    qnpool.insert(nodeName,
                  reinterpret_cast<const char*>(uri),
                  reinterpret_cast<const char*>(prefix),
                  reinterpret_cast<const char*>(lname));
    
    // Create the element node and push it to the node stack
    ElementNode* elemNode = nfactory.createElementNode(nodeName,
                                                       numBindings,
                                                       numAttributes);
    if (nodeStack.empty())
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
      for (long i = loader.theNodeStack.size() - 1;
           loader.theNodeStack[i] != NULL;
           --i)
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

    // Check for recursiveness, i.e., whether this node is a descendant of
    // another noide with the same name
    for (long i = pathStack.size() - 1; i >= 1; --i)
    {
      if (pathStack[i].theNode->theName->equals(elemNode->theName))
      {
        pathStack[i].theNode->setRecursive();
        break;
      }
    }

    // Assign the current node id to this node, and compute the next node id.
    elemNode->setId(loader.theTree, &loader.theOrdPath);
    loader.theOrdPath.pushChild();

    LOADER_TRACE1("Start Element: node = " << elemNode << " name = ["
                  << (prefix != NULL ? prefix : (xmlChar*)"") << ":" << lname
                  << " (" << (uri != NULL ? uri : (xmlChar*)"NULL") << ")]"
                  << std::endl << " ordpath = " << elemNode->getOrdPath().show()
                  << std::endl);
    
    // Process namespace bindings
    if (numBindings > 0)
    {
      store::NsBindings& bindings = elemNode->getNsContext()->getBindings();

      for (csize i = 0; i < numBindings; ++i)
      {
        const char* prefix = reinterpret_cast<const char*>(namespaces[i * 2]);
        const char* nsuri = reinterpret_cast<const char*>(namespaces[i * 2 + 1]);

        if (prefix == NULL)
          prefix = "";

        zstring pooledNs;
        store.getNamespacePool().insertc(nsuri, pooledNs);

        bindings[i].first = prefix;
        bindings[i].second = pooledNs;

        LOADER_TRACE1("namespace decl: [" << prefix  << ":" << nsuri << "]");
      }

      loader.theBindingsStack.push(elemNode->getNsContext());
    }
    else if (pathStack.size() == 1)
    {
      elemNode->theNsContext = new NsBindingsContext;
      elemNode->theFlags |= XmlNode::HaveLocalBindings;

      loader.theBindingsStack.push(elemNode->theNsContext);
    }

    // Process attributes
    if (numAttributes > 0)
    {
      InternalNode::NodeVector& attrNodes = elemNode->nodes();

      csize index = 0;
      for (csize i = 0; i < numAttributes; ++i, index += 5)
      {
        const char* lname = reinterpret_cast<const char*>(attributes[index]);
        const char* prefix = reinterpret_cast<const char*>(attributes[index+1]);
        const char* uri = reinterpret_cast<const char*>(attributes[index+2]);
        const char* valueBegin = reinterpret_cast<const char*>(attributes[index+3]);
        const char* valueEnd = reinterpret_cast<const char*>(attributes[index+4]);

        store::Item_t qname;
        qnpool.insert(qname, uri, prefix, lname);

        zstring value(valueBegin, valueEnd);
        store::Item_t typedValue;
        GET_STORE().getItemFactory()->createUntypedAtomic(typedValue, value);

        AttributeNode* attrNode = nfactory.createAttributeNode(qname);
        attrNode->theParent = elemNode;
        attrNode->setId(loader.theTree, &loader.theOrdPath);
        attrNode->theTypedValue.transfer(typedValue);

        attrNodes[i] = attrNode;

        if (attrNode->isBaseUri())
        {
          baseUri = pathStack.top().theBaseUri;
          zstring localUri;
          attrNode->theTypedValue->getStringValue2(localUri);
          if (baseUri.empty())
          {
            elemNode->addBaseUriProperty(localUri, baseUri);
          }
          else
          {
            elemNode->addBaseUriProperty(baseUri, localUri);
          }

          elemNode->getBaseURI(baseUri);

          ++i;
          ++numAttributes;
        }

        loader.theOrdPath.nextChild();

        LOADER_TRACE2("Attribute: node = " << attrNode << " name ["
                      << (prefix != NULL ? prefix : "") << ":" << lname << " ("
                      << (uri != NULL ? uri : "NULL") << ")]" << " value = "
                      << attrNode->theTypedValue->getStringValue()
                      << std::endl << " ordpath = "
                      << attrNode->getOrdPath().show() << std::endl);
      }
    }
    
    // Add the base-uri if the parent document node is not being created, which happens when xml fragments are parsed
    FragmentXmlLoader* fragmentLoader = dynamic_cast<FragmentXmlLoader*>(&loader);
    if (fragmentLoader != NULL && 
        fragmentLoader->theLoadProperties.getCreateDocParentLink() == false &&
        fragmentLoader->getFragmentStream()->current_element_depth == 1)
    {
      zstring emptyStr;
      elemNode->addBaseUriProperty(loader.theBaseUri, emptyStr);
    }

    nodeStack.push((XmlNode*)elemNode);
    nodeStack.push(NULL);
    pathStack.push(PathStepInfo(elemNode, baseUri));
  }
  catch (ZorbaException const& e)
  {
    loader.theXQueryDiagnostics->add_error( e );
  }
  catch (...)
  {
    loader.theXQueryDiagnostics->
    add_error(NEW_ZORBA_EXCEPTION(zerr::ZXQP0003_INTERNAL_ERROR));
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

  zorba::Stack<PathStepInfo>& pathStack = loader.thePathStack;
  zorba::Stack<XmlNode*>& nodeStack = loader.theNodeStack;
  csize stackSize = nodeStack.size();
  csize firstChildPos;
  csize numChildren;
  csize numActualNodes;
  csize i;
  ElementNode* elemNode;
  XmlNode* prevChild = NULL;
  XmlNode* currChild;

  try
  {
    // Find the position of the 1st child of this element node in the node stack
    firstChildPos = stackSize - 1;
    while (nodeStack[firstChildPos] != NULL)
      --firstChildPos;

    // Find the element node in the stack
#ifndef NDEBUG
    elemNode = dynamic_cast<ElementNode*>(nodeStack[firstChildPos-1]);
    ZORBA_ASSERT(elemNode != NULL);
#else
    elemNode = static_cast<ElementNode*>(nodeStack[firstChildPos-1]);
#endif

    LOADER_TRACE2("End Element: node = " << elemNode << " name ["
                  << (prefix != NULL ? prefix : (xmlChar*)"") << ":" << localName
                  << " (" << (uri != NULL ? uri : (xmlChar*)"NULL") << ")]");

    // For each child, make this element node its parent and fix its namespace
    // bindings context.
    InternalNode::NodeVector& nodes = elemNode->nodes();

    numChildren = nodeStack.size() - firstChildPos - 1;

    numActualNodes = nodes.size();

    nodes.resize(numActualNodes + numChildren);

    for (i = firstChildPos + 1; i < stackSize; ++i)
    {
      currChild = nodeStack[i];

      if (currChild->getNodeKind() == store::StoreConsts::textNode &&
          prevChild != NULL &&
          prevChild->getNodeKind() == store::StoreConsts::textNode)
      {
        TextNode* textSibling = reinterpret_cast<TextNode*>(prevChild);
        TextNode* textChild = reinterpret_cast<TextNode*>(currChild);

        zstring content2;
        content2.reserve(textSibling->getText().size() + textChild->getText().size());
        content2 = textSibling->getText();
        content2 += textChild->getText();

        textSibling->setText(content2);
        delete currChild;
      }
      else
      {
        nodes[numActualNodes] = currChild;
        currChild->setParent(elemNode);

        if (currChild->getNodeKind() == store::StoreConsts::elementNode &&
            !loader.theBindingsStack.empty())
        {
          reinterpret_cast<ElementNode*>(currChild)->
          setNsContext(loader.theBindingsStack.top());
        }

        prevChild = currChild;
        ++numActualNodes;
      }
    }

    nodes.resize(numActualNodes);

    nodeStack.pop(numChildren + 1);
    pathStack.pop();

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
  catch (ZorbaException const& e)
  {
    loader.theXQueryDiagnostics->add_error( e );
  }
  catch (...)
  {
    loader.theXQueryDiagnostics->add_error(
      NEW_ZORBA_EXCEPTION( zerr::ZXQP0003_INTERNAL_ERROR )
    );
  }
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

  try
  {
    const char* charp = reinterpret_cast<const char*>(ch);
    zstring content(charp, len);

    TextNode* textNode = GET_STORE().getNodeFactory().createTextNode(content);

    if (loader.theNodeStack.empty())
      loader.setRoot(textNode);

    loader.theNodeStack.push(textNode);

    textNode->setId(loader.theTree, &loader.theOrdPath);
    loader.theOrdPath.nextChild();

#ifndef NDEBUG
    std::stringstream lSs;
    lSs << "Text Node = " << textNode << " content = "
        << std::string(charp, len) << std::endl
#ifdef TEXT_ORDPATH
        << " ordpath = " << textNode->getOrdPath().show()
#endif
        << std::endl;
    LOADER_TRACE2(lSs.str());
#endif
  }
  catch (ZorbaException const& e)
  {
    loader.theXQueryDiagnostics->add_error( e );
  }
  catch (...)
  {
    loader.theXQueryDiagnostics->add_error(
      NEW_ZORBA_EXCEPTION( zerr::ZXQP0003_INTERNAL_ERROR )
    );
  }
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

  try
  {
    // If a doc contains an element like <cdata><![CDATA[ <> ]]></cdata>,
    // libxml returns the string " <> ".
    const char* charp = reinterpret_cast<const char*>(ch);
    zstring content(charp, len);

    TextNode* cdataNode = GET_STORE().getNodeFactory().createTextNode(content);

    if (loader.theNodeStack.empty())
      loader.setRoot(cdataNode);

    loader.theNodeStack.push(cdataNode);

    cdataNode->setId(loader.theTree, &loader.theOrdPath);
    loader.theOrdPath.nextChild();

#ifndef NDEBUG
    std::stringstream lSs;
    lSs << "CDATA Node = " << cdataNode << " content = "
        << std::string(charp, len) << std::endl
#ifdef TEXT_ORDPATH
        << " ordpath = " << cdataNode->getOrdPath().show()
#endif
        << std::endl;
    LOADER_TRACE2(lSs.str());
#endif
  }
  catch (ZorbaException const& e)
  {
    loader.theXQueryDiagnostics->add_error( e );
  }
  catch (...)
  {
    loader.theXQueryDiagnostics->add_error(
      NEW_ZORBA_EXCEPTION( zerr::ZXQP0003_INTERNAL_ERROR )
    );
  }
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

  try
  {
    // bugfix: handling PIs with no data (i.e. data being NULL)
    zstring content;
    if (data)
      content = reinterpret_cast<const char*>(data);

    zstring target = reinterpret_cast<const char*>(targetp);

    PiNode* piNode = GET_STORE().getNodeFactory().createPiNode(target, content);

    if (loader.theNodeStack.empty())
      loader.setRoot(piNode);

    loader.theNodeStack.push(piNode);

    piNode->setId(loader.theTree, &loader.theOrdPath);
    loader.theOrdPath.nextChild();

    LOADER_TRACE2("Pi Node = " << piNode << " target = "
                  << targetp << std::endl << " ordpath = "
                  << piNode->getOrdPath().show() << std::endl);
  }
  catch (ZorbaException const& e)
  {
    loader.theXQueryDiagnostics->add_error( e );
  }
  catch (...)
  {
    loader.theXQueryDiagnostics->add_error(
      NEW_ZORBA_EXCEPTION( zerr::ZXQP0003_INTERNAL_ERROR )
    );
  }
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

  try
  {
    const char* charp = reinterpret_cast<const char*>(ch);
    zstring content;
    if (charp)
      content = charp;

    CommentNode* commentNode = GET_STORE().getNodeFactory().createCommentNode(content);

    if (loader.theNodeStack.empty())
      loader.setRoot(commentNode);

    loader.theNodeStack.push(commentNode);

    commentNode->setId(loader.theTree, &loader.theOrdPath);
    loader.theOrdPath.nextChild();

    LOADER_TRACE2("Comment Node = " << commentNode << " content = "
                  << charp << std::endl << " ordpath = "
                  << commentNode->getOrdPath().show() << std::endl);
  }
  catch (ZorbaException const& e)
  {
    loader.theXQueryDiagnostics->add_error( e );
  }
  catch (...)
  {
    loader.theXQueryDiagnostics->add_error(
      NEW_ZORBA_EXCEPTION( zerr::ZXQP0003_INTERNAL_ERROR )
    );
  }
}


/*******************************************************************************

********************************************************************************/
xmlEntityPtr	FastXmlLoader::getEntity(
    void * ctx,
    const xmlChar * name)
{
  FastXmlLoader& loader = *(static_cast<FastXmlLoader *>( ctx ));
//  ZORBA_LOADER_CHECK_ERROR(loader);
/*
  xmlEntityPtr  parsed_entity = NULL;
  loader.entity_hash.get((const char*)name, parsed_entity);
  return parsed_entity;
*/
  return xmlGetDocEntity(loader.ctxt->myDoc, name);
}


xmlEntityPtr FastXmlLoader::getParameterEntity(
    void *ctx,
    const xmlChar *name)
{
  FastXmlLoader& loader = *(static_cast<FastXmlLoader *>( ctx ));
  return xmlGetParameterEntity(loader.ctxt->myDoc, name);
}


void FastXmlLoader::entityDecl(
    void *ctx,
    const xmlChar *name,
    int   type,
    const xmlChar *publicId,
    const xmlChar *systemId,
    xmlChar *content)
{
  FastXmlLoader& loader = *(static_cast<FastXmlLoader *>( ctx ));
  ZORBA_LOADER_CHECK_ERROR(loader);
}


} // namespace simplestore
} // namespace zorba
/* vim:set et sw=2 ts=2: */
