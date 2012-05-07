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

#include <memory.h>
#include <string>
#include <iostream>
#include <vector>

#include <libxml/xmlmemory.h>
#include <libxml/parserInternals.h>
#include <libxml/uri.h>

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
    if (!loader.theXQueryDiagnostics->errors().empty()) \
      return; \
  } while (0);


/*******************************************************************************

********************************************************************************/
void XmlLoader::applyLoadOptions(const store::LoadProperties& props, xmlParserCtxtPtr ctxt)
{
  int options = 0;

  if (props.getStripWhitespace())
    options |= XML_PARSE_NOBLANKS;

  if (props.getDTDValidate())
    options |= XML_PARSE_DTDVALID;

  if (props.getDTDLoad())
    options |= XML_PARSE_DTDLOAD;

  if (props.getDefaultDTDAttributes())
    options |= XML_PARSE_DTDATTR;

  if (props.getSubstituteEntities())
    options |= XML_PARSE_NOENT;

  if (props.getXincludeSubstitutions())
    options |= XML_PARSE_XINCLUDE;

  if (props.getRemoveRedundantNS())
    options |= XML_PARSE_NSCLEAN;

  if (props.getNoCDATA())
    options |= XML_PARSE_NOCDATA;

  if (props.getNoXIncludeNodes())
    options |= XML_PARSE_NOXINCNODE;

  xmlCtxtUseOptions(ctxt, options);
}


/*******************************************************************************

********************************************************************************/
FragmentXmlLoader::FragmentXmlLoader(
    store::ItemFactory* factory,
    XQueryDiagnostics* xqueryDiagnostics,
    const store::LoadProperties& loadProperties,
    bool dataguide)
  :
  FastXmlLoader(factory, xqueryDiagnostics, loadProperties, dataguide)
{
  theOrdPath.init();

  theTraceLevel = GET_STORE().getTraceLevel();

  memset(&theSaxHandler, 0, sizeof(theSaxHandler) );
  theSaxHandler.initialized = XML_SAX2_MAGIC;
  theSaxHandler.startDocument = &FragmentXmlLoader::startDocument;
  theSaxHandler.endDocument = &FragmentXmlLoader::endDocument;
  theSaxHandler.startElementNs = &FragmentXmlLoader::startElement;
  theSaxHandler.endElementNs = &FragmentXmlLoader::endElement;
  theSaxHandler.characters = &FragmentXmlLoader::characters;
  theSaxHandler.cdataBlock = &FragmentXmlLoader::cdataBlock;
  theSaxHandler.comment = &FragmentXmlLoader::comment;
  theSaxHandler.processingInstruction = &FragmentXmlLoader::processingInstruction;
  theSaxHandler.warning = &FragmentXmlLoader::warning;
  theSaxHandler.error = &FragmentXmlLoader::error;
  theSaxHandler.getEntity = &FragmentXmlLoader::getEntity;
  theSaxHandler.getParameterEntity = &FragmentXmlLoader::getParameterEntity;
  theSaxHandler.entityDecl = &FragmentXmlLoader::entityDecl;
}


FragmentXmlLoader::~FragmentXmlLoader()
{
}

bool FragmentXmlLoader::fillBuffer(FragmentIStream* theFragmentStream)
{
  if (theFragmentStream->ctxt->input->length > 0 && theFragmentStream->current_offset < theFragmentStream->bytes_in_buffer)
  {
    memmove(theFragmentStream->theBuffer, theFragmentStream->theBuffer + theFragmentStream->current_offset,
            theFragmentStream->bytes_in_buffer - theFragmentStream->current_offset);
  }
  theFragmentStream->bytes_in_buffer -= theFragmentStream->current_offset;

  std::streamsize numChars = readPacket(*theFragmentStream->theStream, theFragmentStream->theBuffer + theFragmentStream->bytes_in_buffer,
                                         FragmentIStream::BUFFER_SIZE+FragmentIStream::LOOKAHEAD_BYTES - theFragmentStream->bytes_in_buffer);
  if (numChars < 0)
  {
    theXQueryDiagnostics->add_error(NEW_ZORBA_EXCEPTION(zerr::ZSTR0020_LOADER_IO_ERROR));
    throw 0; // the argument to throw is not used by the catch clause
  }

  if (theFragmentStream->theStream->eof())
    theFragmentStream->reached_eof = true;

  theFragmentStream->bytes_in_buffer += numChars;
  theFragmentStream->current_offset = 0;
  theFragmentStream->ctxt->input->base = (xmlChar*)(theFragmentStream->theBuffer);
  theFragmentStream->ctxt->input->length = (theFragmentStream->bytes_in_buffer < FragmentIStream::BUFFER_SIZE? theFragmentStream->bytes_in_buffer : FragmentIStream::BUFFER_SIZE);
  theFragmentStream->ctxt->input->cur = theFragmentStream->ctxt->input->base;
  theFragmentStream->ctxt->input->end = theFragmentStream->ctxt->input->base + theFragmentStream->ctxt->input->length;
  theFragmentStream->ctxt->checkIndex = 0;

  if (theFragmentStream->bytes_in_buffer < FragmentIStream::BUFFER_SIZE+FragmentIStream::LOOKAHEAD_BYTES)
    theFragmentStream->theBuffer[theFragmentStream->bytes_in_buffer] = 0;

  return !theFragmentStream->stream_is_consumed();
}

store::Item_t FragmentXmlLoader::loadXml(
    const zstring& baseUri,
    const zstring& docUri,
    std::istream& stream)
{
  theTree = GET_STORE().getNodeFactory().createXmlTree();

  xmlSubstituteEntitiesDefault(1);

  theBaseUri = baseUri;

  if (docUri.empty())
  {
    std::ostringstream uristream;
    uristream << "zorba://internalDocumentURI-" << theTree->getId();
    theDocUri = uristream.str();
  }
  else
  {
    theDocUri = docUri;
  }

  thePathStack.push(PathStepInfo(NULL, baseUri));

  try
  {
    theFragmentStream = static_cast<FragmentIStream*>(&stream);

    // Prepare the input buffer and the parser context
    if (theFragmentStream->theBuffer == NULL)
    {
      // Allocate input buffer
      theFragmentStream->theBuffer = new char[FragmentIStream::BUFFER_SIZE + FragmentIStream::LOOKAHEAD_BYTES+1];
      theFragmentStream->theBuffer[FragmentIStream::BUFFER_SIZE + FragmentIStream::LOOKAHEAD_BYTES] = 0;

      // Create the LibXml parser context
      theFragmentStream->ctxt = xmlCreatePushParserCtxt(&theSaxHandler, this, NULL, 0, 0);
      if (theFragmentStream->ctxt == NULL)
      {
        theXQueryDiagnostics->add_error(NEW_ZORBA_EXCEPTION(zerr::ZSTR0021_LOADER_PARSING_ERROR, ERROR_PARAMS( ZED( ParserInitFailed ) )));
        throw 0; // the argument to throw is not used by the catch clause
      }

      // Apply parser options
      applyLoadOptions(theLoadProperties, theFragmentStream->ctxt);

      // Delete the initial empty input stream
      xmlFreeInputStream(inputPop(theFragmentStream->ctxt));

      // Create the LibXml parser input
      xmlParserInputPtr input = xmlNewInputStream(theFragmentStream->ctxt);
      if (input == NULL)
      {
        theXQueryDiagnostics->add_error(NEW_ZORBA_EXCEPTION(zerr::ZSTR0021_LOADER_PARSING_ERROR, ERROR_PARAMS( ZED( ParserInitFailed ) )));
        throw 0; // the argument to throw is not used by the catch clause
      }

      // Initialize the parser input (only filename and the pointer to the current char)
      theFragmentStream->theBuffer[0] = ' '; // This assignment is needed for LibXml2-2.7.6, which tries to read the buffer when xmlPushInput() is called
      input->cur = (xmlChar*)(theFragmentStream->theBuffer);
      input->filename = (const char*)(xmlCanonicPath((const xmlChar*)theDocUri.c_str()));
      xmlPushInput(theFragmentStream->ctxt, input);
    }

    theFragmentStream->ctxt->userData = this;    // the loader has changed, update the address
    theFragmentStream->ctxt->disableSAX = false; // xmlStopParser() sets disableSAX to true
    theFragmentStream->parsed_nodes_count = 0;
    theFragmentStream->forced_parser_stop = false;

    if ( ! theFragmentStream->first_start_doc)
    {
      theFragmentStream->ctxt->instate = XML_PARSER_CONTENT;
      FragmentXmlLoader::startDocument(theFragmentStream->ctxt->userData);
    }

    while ( ! theFragmentStream->forced_parser_stop && fillBuffer(theFragmentStream))
    {
      // std::cerr << "\n==================\n--> skip_root: " << theFragmentStream->root_elements_to_skip << " current_depth: " << theFragmentStream->current_element_depth << " about to parse: [" << theFragmentStream->ctxt->input->cur << "] " << std::endl;
      
      if (theFragmentStream->only_one_doc_node && !theFragmentStream->first_start_doc)
      {
        theFragmentStream->ctxt->instate = XML_PARSER_CONTENT;
        theFragmentStream->ctxt->disableSAX = false; // xmlStopParser() sets disableSAX to true
      }

      // This case needs to be handled here, otherwise LibXml2 will segfault
      if (theFragmentStream->ctxt->input->cur[0] == '<' &&
          theFragmentStream->ctxt->input->cur[1] == '/' &&
          theFragmentStream->current_element_depth == 0)
      {
        theXQueryDiagnostics->add_error(theDocUri.empty() ?
              NEW_ZORBA_EXCEPTION(zerr::ZSTR0021_LOADER_PARSING_ERROR, ERROR_PARAMS( ZED( BadXMLNoOpeningTag ))) :
              NEW_ZORBA_EXCEPTION(zerr::ZSTR0021_LOADER_PARSING_ERROR, ERROR_PARAMS( ZED( BadXMLNoOpeningTag ), theDocUri))
            );
        throw 0; // the argument to throw is not used by the catch clause
      }

      xmlParseChunk(theFragmentStream->ctxt, (const char*)theFragmentStream->ctxt->input->cur,
                    theFragmentStream->ctxt->input->length, 0);

      if (theFragmentStream->ctxt->input->base == (xmlChar*)(theFragmentStream->theBuffer)
          &&
          theFragmentStream->current_offset < getCurrentInputOffset())
        theFragmentStream->current_offset = getCurrentInputOffset();

      // If we didn't get an error and we haven't moved, we might have some freestanding text. Parse it as element character data.
      if (theXQueryDiagnostics->errors().empty()
          &&
          theFragmentStream->current_offset == 0)
      {
        // The input has been reset by xmlStopParser()
        theFragmentStream->ctxt->input->base = (xmlChar*)(theFragmentStream->theBuffer);
        theFragmentStream->ctxt->input->cur = theFragmentStream->ctxt->input->base;
        xmlParseCharData(theFragmentStream->ctxt, 0);
      }

      if ( ! theXQueryDiagnostics->errors().empty())
        throw 0; // the argument to throw is not used by the catch clause
    }

    // this happens when there are tags that have not been closed
    if (theFragmentStream->stream_is_consumed()
        &&
        theFragmentStream->current_element_depth > 0)
    {
      theXQueryDiagnostics->add_error(theDocUri.empty() ?
          NEW_ZORBA_EXCEPTION(zerr::ZSTR0021_LOADER_PARSING_ERROR, ERROR_PARAMS( ZED( BadXMLDocument_2o ))) :
          NEW_ZORBA_EXCEPTION(zerr::ZSTR0021_LOADER_PARSING_ERROR, ERROR_PARAMS( ZED( BadXMLDocument_2o ), theDocUri))
        );
      throw 0;
    }

    FragmentXmlLoader::endDocument(theFragmentStream->ctxt->userData); // this would not be called otherwise
  }
  catch (...)
  {
    abortload();
    thePathStack.clear();
    return NULL;
  }

  // The doc may be well formed, but it may have other kinds of errors, e.g., unresolved ns prefixes.
  if (!theXQueryDiagnostics->errors().empty())
  {
    abortload();
    return NULL;
  }
  else if ( ! theFragmentStream->ctxt->wellFormed)
  {
    theXQueryDiagnostics->add_error(theDocUri.empty() ?
          NEW_ZORBA_EXCEPTION(zerr::ZSTR0021_LOADER_PARSING_ERROR, ERROR_PARAMS( ZED( BadXMLDocument_2o ))) :
          NEW_ZORBA_EXCEPTION(zerr::ZSTR0021_LOADER_PARSING_ERROR, ERROR_PARAMS( ZED( BadXMLDocument_2o ), theDocUri))
        );
    abortload();
    return NULL;
  }
  else if (theFragmentStream->ctxt->lastError.code != XML_ERR_OK)
  {
    if (theFragmentStream->ctxt->lastError.code == XML_NS_ERR_UNDEFINED_NAMESPACE
        ||
        theFragmentStream->ctxt->lastError.code != XML_ERR_NO_DTD )
    {
      theXQueryDiagnostics->add_error(theDocUri.empty() ?
          NEW_ZORBA_EXCEPTION(zerr::ZSTR0021_LOADER_PARSING_ERROR, ERROR_PARAMS( ZED( BadXMLDocument_2o ))) :
          NEW_ZORBA_EXCEPTION(zerr::ZSTR0021_LOADER_PARSING_ERROR, ERROR_PARAMS( ZED( BadXMLDocument_2o ), theDocUri))
        );
      abortload();
      return NULL;
    }
  }

  thePathStack.pop();
  assert(thePathStack.empty());

  XmlNode* resultNode;
  resultNode = theRootNode;
  reset();
  return resultNode;
}

unsigned long FragmentXmlLoader::getCurrentInputOffset() const
{
  unsigned long offset = theFragmentStream->ctxt->input->cur
      - theFragmentStream->ctxt->input->base
      + theFragmentStream->ctxt->input->consumed;

  return offset;
}

void FragmentXmlLoader::checkStopParsing(void* ctx, bool force)
{
  FragmentXmlLoader& loader = *(static_cast<FragmentXmlLoader*>(ctx));
  ZORBA_LOADER_CHECK_ERROR(loader);

  unsigned long offset = loader.getCurrentInputOffset();

  if (force
      ||
      loader.theFragmentStream->current_element_depth == 0
      ||
      (offset >= loader.theFragmentStream->bytes_in_buffer
          &&
          loader.theFragmentStream->reached_eof)
      ||
      (loader.theFragmentStream->current_element_depth <= loader.theFragmentStream->root_elements_to_skip
          &&
          loader.theFragmentStream->parsed_nodes_count >= loader.theFragmentStream->PARSED_NODES_BATCH_SIZE))
  {
    loader.theFragmentStream->current_offset = offset;
    xmlStopParser(loader.theFragmentStream->ctxt);
    loader.theFragmentStream->ctxt->errNo = XML_SCHEMAV_MISC; // fake error to force stopping      
    if (!loader.theFragmentStream->only_one_doc_node)
      loader.theFragmentStream->forced_parser_stop = true;
  }

  loader.theFragmentStream->parsed_nodes_count++;
}

void FragmentXmlLoader::startDocument(void * ctx)
{
  FragmentXmlLoader& loader = *(static_cast<FragmentXmlLoader*>(ctx));
  ZORBA_LOADER_CHECK_ERROR(loader);
  FastXmlLoader::startDocument(ctx);
  if (loader.theFragmentStream->first_start_doc)
  {
    loader.theFragmentStream->first_start_doc = false;
    FragmentXmlLoader::checkStopParsing(ctx, true);
  }
}

void FragmentXmlLoader::endDocument(void * ctx)
{
  FastXmlLoader::endDocument(ctx);
}

void FragmentXmlLoader::startElement(
    void * ctx,
    const xmlChar * localname,
    const xmlChar * prefix,
    const xmlChar * URI,
    int nb_namespaces,
    const xmlChar ** namespaces,
    int nb_attributes,
    int nb_defaulted,
    const xmlChar ** attributes)
{
  FragmentXmlLoader& loader = *(static_cast<FragmentXmlLoader*>(ctx));
  ZORBA_LOADER_CHECK_ERROR(loader);
  loader.theFragmentStream->current_element_depth++;
  if (loader.theFragmentStream->current_element_depth > loader.theFragmentStream->root_elements_to_skip)
  {
    const xmlChar** nsTab = namespaces;

    if (loader.theFragmentStream->current_element_depth == loader.theFragmentStream->root_elements_to_skip + 1)
    {
      nsTab = loader.theFragmentStream->ctxt->nsTab;
      nb_namespaces = loader.theFragmentStream->ctxt->nsNr/2;
    }

    FastXmlLoader::startElement(ctx, localname, prefix, URI, nb_namespaces, nsTab, nb_attributes, nb_defaulted, attributes);
  }
}

void FragmentXmlLoader::endElement(
    void * ctx,
    const xmlChar * localname,
    const xmlChar * prefix,
    const xmlChar * URI)
{
  FragmentXmlLoader& loader = *(static_cast<FragmentXmlLoader*>(ctx));
  ZORBA_LOADER_CHECK_ERROR(loader);
  if (loader.theFragmentStream->current_element_depth > loader.theFragmentStream->root_elements_to_skip)
    FastXmlLoader::endElement(ctx, localname, prefix, URI);
  loader.theFragmentStream->current_element_depth--;
  checkStopParsing(ctx);
}

void FragmentXmlLoader::characters(
    void * ctx,
    const xmlChar * ch,
    int len)
{
  FragmentXmlLoader& loader = *(static_cast<FragmentXmlLoader*>(ctx));
  ZORBA_LOADER_CHECK_ERROR(loader);
  if (loader.theFragmentStream->current_element_depth >= loader.theFragmentStream->root_elements_to_skip)
    FastXmlLoader::characters(ctx, ch, len);
  checkStopParsing(ctx);
}


void FragmentXmlLoader::comment(
    void * ctx,
    const xmlChar * value)
{
  FragmentXmlLoader& loader = *(static_cast<FragmentXmlLoader*>(ctx));
  ZORBA_LOADER_CHECK_ERROR(loader);
  if (loader.theFragmentStream->current_element_depth >= loader.theFragmentStream->root_elements_to_skip)
    FastXmlLoader::comment(ctx, value);
  checkStopParsing(ctx);
}


void FragmentXmlLoader::cdataBlock(
    void * ctx,
    const xmlChar * value,
    int len)
{
  FragmentXmlLoader& loader = *(static_cast<FragmentXmlLoader*>(ctx));
  ZORBA_LOADER_CHECK_ERROR(loader);
  if (loader.theFragmentStream->current_element_depth >= loader.theFragmentStream->root_elements_to_skip)
    FastXmlLoader::cdataBlock(ctx, value, len);
  checkStopParsing(ctx);
}


void FragmentXmlLoader::processingInstruction(
    void * ctx,
    const xmlChar * target,
    const xmlChar * data)
{
  FragmentXmlLoader& loader = *(static_cast<FragmentXmlLoader*>(ctx));
  ZORBA_LOADER_CHECK_ERROR(loader);
  if (loader.theFragmentStream->current_element_depth >= loader.theFragmentStream->root_elements_to_skip)
    FastXmlLoader::processingInstruction(ctx, target, data);
  checkStopParsing(ctx);
}


/*******************************************************************************

********************************************************************************/
DtdXmlLoader::DtdXmlLoader(
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
  theOrdPath.init();

  theTraceLevel = GET_STORE().getTraceLevel();

  memset(&theSaxHandler, 0, sizeof(theSaxHandler) );
  theSaxHandler.initialized = XML_SAX2_MAGIC;
  //theSaxHandler.startDocument = &DtdXmlLoader::startDocument;
  //theSaxHandler.endDocument = &DtdXmlLoader::endDocument;
  //theSaxHandler.startElementNs = &DtdXmlLoader::startElement;
  //theSaxHandler.endElementNs = &DtdXmlLoader::endElement;
  //theSaxHandler.characters = &DtdXmlLoader::characters;
  //theSaxHandler.cdataBlock = &DtdXmlLoader::cdataBlock;
  //theSaxHandler.comment = &DtdXmlLoader::comment;
  //theSaxHandler.processingInstruction = &DtdXmlLoader::processingInstruction;
  theSaxHandler.warning = &DtdXmlLoader::warning;
  theSaxHandler.error = &DtdXmlLoader::error;

  theSaxHandler.getEntity = &DtdXmlLoader::getEntity;
  theSaxHandler.getParameterEntity = &DtdXmlLoader::getParameterEntity;
  theSaxHandler.entityDecl = &DtdXmlLoader::entityDecl;
}


/*******************************************************************************

********************************************************************************/
DtdXmlLoader::~DtdXmlLoader()
{
}


/*******************************************************************************

********************************************************************************/
void DtdXmlLoader::setRoot(XmlNode* root)
{
  theRootNode = root;
  theTree->setRoot(root);
}


/*******************************************************************************
  Method called to do cleanup in case of errors.
********************************************************************************/
void DtdXmlLoader::abortload()
{
  theBaseUri.~zstring();
  theDocUri.~zstring();

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
      node->destroy(true);
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
  }

  ctxt = NULL;
}


/*******************************************************************************
  Method used to reset the loader so it can be used to load another document.
********************************************************************************/
void DtdXmlLoader::reset()
{
  theBaseUri.~zstring();
  theDocUri.~zstring();

  theTree = NULL;
  theOrdPath.init();
  theRootNode = NULL;

  if ( !theNodeStack.empty() )
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
std::streamsize DtdXmlLoader::readPacket(std::istream& stream, char* buf, std::streamoff size)
{
  try
  {
    stream.read(buf, size);

    if (stream.bad())
    {
      theXQueryDiagnostics->add_error(
      	NEW_ZORBA_EXCEPTION(
          zerr::ZSTR0020_LOADER_IO_ERROR, ERROR_PARAMS( ZED( BadStreamState ) )
        )
      );
    }

    return stream.gcount();
  }
  catch (std::iostream::failure const &e)
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
store::Item_t DtdXmlLoader::loadXml(
    const zstring& baseUri,
    const zstring& docUri,
    std::istream& stream)
{
  theTree = GET_STORE().getNodeFactory().createXmlTree();

  xmlSubstituteEntitiesDefault(1);

  theBaseUri = baseUri;

  if (docUri.empty())
  {
    std::ostringstream uristream;
    uristream << "zorba://internalDocumentURI-" << theTree->getId();

    theDocUri = uristream.str();
  }
  else
  {
    theDocUri = docUri;
  }

  thePathStack.push(PathStepInfo(NULL, baseUri));

  try
  {
    stream.seekg(0, std::ios::end);
    std::streamoff fileSize = stream.tellg();
    stream.seekg(0, std::ios::beg);

    theBuffer.resize(static_cast<unsigned int>(fileSize+1));
    theBuffer[fileSize] = 0;

    std::streamsize numChars = readPacket(stream,
                                          static_cast<char*>(&theBuffer[0]),
                                          fileSize);

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

    ctxt = xmlCreatePushParserCtxt(NULL, //&theSaxHandler,
                                   this,
                                   static_cast<char*>(&theBuffer[0]),
                                   static_cast<int>(numChars),
                                   theDocUri.c_str());

    if (ctxt == NULL)
    {
      theXQueryDiagnostics->add_error(
        NEW_ZORBA_EXCEPTION(
          zerr::ZSTR0021_LOADER_PARSING_ERROR,
          ERROR_PARAMS( ZED( ParserInitFailed ) )
        )
      );
      abortload();
      return NULL;
    }

    // Set the LibXml DTD validation options
    /*
    int options = XML_PARSE_COMPACT;
    options |= XML_PARSE_DTDVALID;
    options |= XML_PARSE_DTDLOAD;
    */
    //options |= XML_PARSE_SAX1;
    //xmlSAXDefaultVersion(1);

    // xmlCtxtUseOptions(ctxt, options);

    xmlLoadExtDtdDefaultValue |= XML_DETECT_IDS;
    xmlLoadExtDtdDefaultValue |= XML_COMPLETE_ATTRS;

    // Apply loader options
    applyLoadOptions(theLoadProperties, ctxt);

    if ( xmlParseDocument(ctxt)==-1 )
    {
      // std::cout << "  xmlParseDocument: Error: Unable to create tree: " << ctxt->lastError.message << std::endl;
      theXQueryDiagnostics->add_error(NEW_ZORBA_EXCEPTION(zerr::ZSTR0021_LOADER_PARSING_ERROR,ERROR_PARAMS( ZED( ParserNoCreateTree ) )));
      abortload();
      return NULL;
    }
  }
  catch(...)
  {
    abortload();
    thePathStack.clear();
    return NULL;
  }

  bool ok = ctxt->wellFormed != 0;

  // The doc may be well formed, but it may have other kinds of errors,
  // e.g., unresolved ns prefixes.
  if (!theXQueryDiagnostics->errors().empty())
  {
    abortload();
    return NULL;
  }
  else if (!ok )
  {
    if (!theDocUri.empty())
    {
      theXQueryDiagnostics->add_error(
        NEW_ZORBA_EXCEPTION(
          zerr::ZSTR0021_LOADER_PARSING_ERROR,
          ERROR_PARAMS( ZED( BadXMLDocument_2o ), theDocUri )
        )
      );
    }
    else
    {
      theXQueryDiagnostics->add_error(
        NEW_ZORBA_EXCEPTION(
          zerr::ZSTR0021_LOADER_PARSING_ERROR,
          ERROR_PARAMS( ZED( BadXMLDocument_2o ) )
        )
      );
    }

    abortload();
    return NULL;
  }
  else if ( ctxt->lastError.code != XML_ERR_OK )
  {
    /*
    std::cout << "-- LastErrorCode: " << ctxt->lastError.code << " " <<
        ctxt->lastError.message << " wellformed:" << ok << std::endl; std::cout.flush();
    */

    if ( ctxt->lastError.code == XML_NS_ERR_UNDEFINED_NAMESPACE ||
        ctxt->lastError.code != XML_ERR_NO_DTD )
    {
      theXQueryDiagnostics->add_error(
        NEW_ZORBA_EXCEPTION(
          zerr::ZSTR0021_LOADER_PARSING_ERROR,
          ERROR_PARAMS( ZED( BadXMLDocument_2o ) )
        )
      );
      abortload();
      return NULL;

    }
  }


  xmlDoc *doc = ctxt->myDoc;
  if (doc == NULL)
  {
    theXQueryDiagnostics->add_error(
      NEW_ZORBA_EXCEPTION(
        zerr::ZSTR0021_LOADER_PARSING_ERROR,
        ERROR_PARAMS( ZED( ParserNoCreateTree ) )
      )
    );
    abortload();
    return NULL;
  }

  loadDocument(doc);
  /* no need to free the document since is in ctxt */
  //xmlFreeDoc(doc);

  xmlCtxtReset(ctxt);
  xmlFreeParserCtxt(ctxt);
  ctxt = NULL;


  thePathStack.pop();
  assert(thePathStack.empty());

  XmlNode* resultNode;
  resultNode = theRootNode;
  reset();
  return resultNode;
}


void DtdXmlLoader::loadDocument(xmlDoc *doc)
{
  startDocument(this);

  /*Get the root element node */
  //xmlNode *root_element = xmlDocGetRootElement(doc);
  //print_element_names(root_element);
  loadNode(doc->children);

  endDocument(this);
}


void DtdXmlLoader::loadNode(xmlNode *a_node)
{
  xmlNode *cur_node = NULL;

  for (cur_node = a_node; cur_node; cur_node = cur_node->next)
  {
    switch( cur_node->type )
    {
      case XML_ELEMENT_NODE:
      {
        startElement(this, cur_node);
        loadNode(cur_node->children);
        endElement(this, cur_node);

        break;
      }
      case XML_TEXT_NODE:
      {
        xmlChar * content = xmlNodeGetContent(cur_node);
        characters(this, content, xmlStrlen(content));
        xmlFree(content);
        break;
      }
      case XML_CDATA_SECTION_NODE:
      {
        xmlChar * content = xmlNodeGetContent(cur_node);
        cdataBlock(this, content, xmlStrlen(content));
        xmlFree(content);
        break;
      }
      case XML_PI_NODE:
      {
        xmlChar * content = xmlNodeGetContent(cur_node);
        processingInstruction(this, cur_node->name, content);
        xmlFree(content);
        break;
      }
      case XML_COMMENT_NODE:
      {
        xmlChar * content = xmlNodeGetContent(cur_node);
        comment(this, content);
        xmlFree(content);
        break;
      }

      case XML_ATTRIBUTE_NODE:
      case XML_ENTITY_REF_NODE:
      case XML_ENTITY_NODE:
      case XML_DOCUMENT_NODE:
      case XML_DOCUMENT_TYPE_NODE:
      case XML_DOCUMENT_FRAG_NODE:
      case XML_NOTATION_NODE:
      case XML_HTML_DOCUMENT_NODE:
      case XML_DTD_NODE:
      case XML_ELEMENT_DECL:
      case XML_ATTRIBUTE_DECL:
      case XML_ENTITY_DECL:
      case XML_NAMESPACE_DECL:
      case XML_XINCLUDE_START:
      case XML_XINCLUDE_END:

#ifdef LIBXML_DOCB_ENABLED
      case XML_DOCB_DOCUMENT_NODE:
#endif //LIBXML_DOCB_ENABLED
        break;
      default:
        std::cout << "AssertError: Unknown libxml2 node type: " << (int)(cur_node->type)
          << std::endl; std::cout.flush();
        ZORBA_ASSERT(false);
    }
  }
}


/*******************************************************************************
  SAX2 callback when the start of document has been detected by the parser.

  ctx: the user data (XML parser context)
********************************************************************************/
void DtdXmlLoader::startDocument(void * ctx)
{
  DtdXmlLoader& loader = *(static_cast<DtdXmlLoader *>(ctx));
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
    loader.theXQueryDiagnostics->add_error(
      NEW_ZORBA_EXCEPTION( zerr::ZXQP0003_INTERNAL_ERROR )
    );
  }
}


/*******************************************************************************
  SAX2 callback when the end of document has been detected by the parser.

  ctx: the user data (XML parser context)
********************************************************************************/
void DtdXmlLoader::endDocument(void * ctx)
{
  DtdXmlLoader& loader = *(static_cast<DtdXmlLoader *>(ctx));
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
void DtdXmlLoader::startElement(
    void * ctx,
    xmlNode *node)
{
  //std::cout << "StartElement, name: " << node->name << std::endl; std::cout.flush();

  const xmlChar * lname =  node->name;
  const xmlChar * prefix = node->ns != NULL ? node->ns->prefix : NULL;
  const xmlChar * uri =    node->ns != NULL ? node->ns->href   : NULL;

  int numAttrs = 0;
  for (xmlAttrPtr attr = node->properties; attr != NULL; attr = attr->next )
    numAttrs++;

  int numNamespaces = 0;
  for (xmlNs  *ns = node->nsDef; ns != NULL; ns = ns->next)
    numNamespaces++;

  Store& store = GET_STORE();
  NodeFactory& nfactory = store.getNodeFactory();
  DtdXmlLoader& loader = *(static_cast<DtdXmlLoader *>(ctx));
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
    store::Item_t nodeName = qnpool.insert(reinterpret_cast<const char*>(uri),
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
    for (long j = pathStack.size() - 1; j >= 1; --j)
    {
      if (pathStack[j].theNode->theName->equals(elemNode->theName))
      {
        pathStack[j].theNode->setRecursive();
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
    store::NsBindings& bindings = elemNode->getNsContext()->getBindings();
    int i = 0;
    for (xmlNs *ns = node->nsDef; ns != NULL; ns = ns->next)
    {
      const char* prefix = reinterpret_cast<const char*>(ns->prefix);
      const char* nsuri = reinterpret_cast<const char*>(ns->href);

      if (prefix == NULL)
        prefix = "";

      zstring pooledNs;
      store.getNamespacePool().insertc(nsuri, pooledNs);

      bindings[i].first = prefix;
      bindings[i].second = pooledNs;

      LOADER_TRACE1("namespace decl: [" << prefix  << ":" << nsuri << "]");
      i++;
    }

    if ( i > 0 )
    {
      loader.theBindingsStack.push(elemNode->getNsContext());
    }
    else if (pathStack.size() == 1)
    {
      elemNode->theNsContext = new NsBindingsContext;
      elemNode->theFlags |= XmlNode::HaveLocalBindings;

      loader.theBindingsStack.push(elemNode->theNsContext);
    }

    // Process attributes
    i = 0;
    InternalNode::NodeVector& attrNodes = elemNode->nodes();

    for (xmlAttrPtr attr = node->properties; attr != NULL; attr = attr->next )
    {
      //std::cout << "  att: " << attr->name << std::endl; std::cout.flush();

      const char* lname = reinterpret_cast<const char*>(attr->name);
      const char* prefix = reinterpret_cast<const char*>( attr->ns != NULL ? attr->ns->prefix : NULL);
      const char* uri = reinterpret_cast<const char*>( attr->ns != NULL ? attr->ns->href : NULL);
      store::Item_t qname = qnpool.insert(uri, prefix, lname);
      AttributeNode* attrNode = nfactory.createAttributeNode(qname);

      xmlChar* val = xmlGetProp(node, attr->name);
      const char* valu = reinterpret_cast<const char*>(val);
      zstring value(valu);

      store::Item_t typeName;

      store::Item_t typedValue;
      switch (attr->atype)
      {
        case 0:                       // libxml2 bug
        case XML_ATTRIBUTE_CDATA:
          GET_STORE().getItemFactory()->createUntypedAtomic(typedValue, value);
          typeName = GET_STORE().theSchemaTypeNames[store::XS_UNTYPED_ATOMIC];
          break;
        case XML_ATTRIBUTE_ID:
          GET_STORE().getItemFactory()->createID(typedValue, value);
          typeName = GET_STORE().theSchemaTypeNames[store::XS_ID];
          break;
        case XML_ATTRIBUTE_IDREF:
          GET_STORE().getItemFactory()->createIDREF(typedValue, value);
          typeName = GET_STORE().theSchemaTypeNames[store::XS_IDREF];
          break;
        case XML_ATTRIBUTE_IDREFS:
          GET_STORE().getItemFactory()->createIDREFS(typedValue, value);
          GET_STORE().getItemFactory()->createQName(typeName, Store::XS_URI, "xs", "IDREFS");
          attrNode->setHaveListValue();
          break;
        case XML_ATTRIBUTE_ENTITY:
          GET_STORE().getItemFactory()->createENTITY(typedValue, value);
          typeName = GET_STORE().theSchemaTypeNames[store::XS_ENTITY];
          break;
        case XML_ATTRIBUTE_ENTITIES:
          GET_STORE().getItemFactory()->createENTITIES(typedValue, value);
          GET_STORE().getItemFactory()->createQName(typeName, Store::XS_URI, "xs", "ENTITIES");
          attrNode->setHaveListValue();
          break;
        case XML_ATTRIBUTE_NMTOKEN:
          GET_STORE().getItemFactory()->createNMTOKEN(typedValue, value);
          typeName = GET_STORE().theSchemaTypeNames[store::XS_NMTOKEN];
          break;
        case XML_ATTRIBUTE_NMTOKENS:
          GET_STORE().getItemFactory()->createNMTOKENS(typedValue, value);
          GET_STORE().getItemFactory()->createQName(typeName, Store::XS_URI, "xs", "NMTOKENS");
          attrNode->setHaveListValue();
          break;
        case XML_ATTRIBUTE_NOTATION:
          GET_STORE().getItemFactory()->createNOTATION(typedValue, value);
          GET_STORE().getItemFactory()->createQName(typeName, Store::XS_URI, "xs", "NOTATION");
          break;
        case XML_ATTRIBUTE_ENUMERATION:
          GET_STORE().getItemFactory()->createUntypedAtomic(typedValue, value);
          GET_STORE().getItemFactory()->createQName(typeName, Store::XS_URI, "xs", "anySimpleType");
          break;
        default:
          std::cout << "AssertError: unknown libxml2 attribute type: " <<
            (int)attr->atype << std::endl; std::cout.flush();
          ZORBA_ASSERT(false);
      }

      attrNode->theParent = elemNode;
      attrNode->setId(loader.theTree, &loader.theOrdPath);
      attrNode->theTypedValue.transfer(typedValue);
      attrNode->setType(typeName);

      attrNodes[i] = attrNode;

      if (attrNode->isBaseUri())
      {
        baseUri = pathStack.top().theBaseUri;
        zstring localUri;
        attrNode->theTypedValue->getStringValue2(localUri);
        if (baseUri == NULL)
        {
          elemNode->addBaseUriProperty(localUri, baseUri);
        }
        else
        {
          elemNode->addBaseUriProperty(baseUri, localUri);
        }

        elemNode->getBaseURI(baseUri);

        ++i;
      }

      loader.theOrdPath.nextChild();

      LOADER_TRACE2("Attribute: node = " << attrNode << " name ["
                    << (prefix != NULL ? prefix : "") << ":" << lname << " ("
                    << (uri != NULL ? uri : "NULL") << ")]" << " value = "
                    << attrNode->theTypedValue->getStringValue()
                    << std::endl << " ordpath = "
                    << attrNode->getOrdPath().show() << std::endl);


      xmlFree(val);
      i++;
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
    add_error(NEW_ZORBA_EXCEPTION( zerr::ZXQP0003_INTERNAL_ERROR));
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
void  DtdXmlLoader::endElement(
    void * ctx,
    xmlNode *node)
{
#ifndef NDEBUG
  const xmlChar * lname =  node->name;
  const xmlChar * prefix = node->ns!=NULL ? node->ns->prefix : NULL;
  const xmlChar * uri =    node->ns!=NULL ? node->ns->href   : NULL;
#endif

  DtdXmlLoader& loader = *(static_cast<DtdXmlLoader *>(ctx));
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
                  << (prefix != NULL ? prefix : (xmlChar*)"") << ":" << lname
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

    nodeStack.pop(numChildren+1);
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
void DtdXmlLoader::characters(void * ctx, const xmlChar * ch, int len)
{
  DtdXmlLoader& loader = *(static_cast<DtdXmlLoader *>( ctx ));
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
void DtdXmlLoader::cdataBlock(void * ctx, const xmlChar * ch, int len)
{
  DtdXmlLoader& loader = *(static_cast<DtdXmlLoader *>( ctx ));
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
void DtdXmlLoader::processingInstruction(
    void * ctx,
    const xmlChar * targetp,
    const xmlChar * data)
{
  DtdXmlLoader& loader = *(static_cast<DtdXmlLoader *>( ctx ));
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
void DtdXmlLoader::comment(void * ctx, const xmlChar * ch)
{
  DtdXmlLoader& loader = *(static_cast<DtdXmlLoader *>( ctx ));
  ZORBA_LOADER_CHECK_ERROR(loader);

  try
  {
    const char* charp = reinterpret_cast<const char*>(ch);
    zstring content(charp);

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
  Display and format an error messages, callback.

   ctx:  an XML parser context
   msg:  the message to display/transmit
   ...:  extra parameters for the message display
********************************************************************************/
void DtdXmlLoader::error(void * ctx, const char * msg, ... )
{
  DtdXmlLoader* loader = (static_cast<DtdXmlLoader *>(ctx));
  char buf[1024];
  va_list args;
  va_start(args, msg);
  vsprintf(buf, msg, args);
  va_end(args);
  loader->theXQueryDiagnostics->add_error(
    NEW_ZORBA_EXCEPTION(
      zerr::ZSTR0021_LOADER_PARSING_ERROR, ERROR_PARAMS( buf )
    )
  );
}


/*******************************************************************************
   Display and format a warning messages, callback.

   ctx:  an XML parser context
   msg:  the message to display/transmit
   ...:  extra parameters for the message display
********************************************************************************/
void DtdXmlLoader::warning(void * ctx, const char * msg, ... )
{
  char buf[1024];
  va_list args;
  va_start(args, msg);
  vsprintf(buf, msg, args);
  va_end(args);

  std::cerr << buf << std::endl;
}


/*******************************************************************************

********************************************************************************/
xmlEntityPtr  DtdXmlLoader::getEntity(
    void * ctx,
    const xmlChar * name)
{
  DtdXmlLoader& loader = *(static_cast<DtdXmlLoader *>( ctx ));
//  ZORBA_LOADER_CHECK_ERROR(loader);
/*
  xmlEntityPtr  parsed_entity = NULL;
  loader.entity_hash.get((const char*)name, parsed_entity);
  return parsed_entity;
*/
  return xmlGetDocEntity(loader.ctxt->myDoc, name);
}


xmlEntityPtr DtdXmlLoader::getParameterEntity(
    void *ctx,
    const xmlChar *name)
{
  DtdXmlLoader& loader = *(static_cast<DtdXmlLoader *>( ctx ));
  return xmlGetParameterEntity(loader.ctxt->myDoc, name);
}


void DtdXmlLoader::entityDecl(
    void *ctx,
    const xmlChar *name,
    int   type,
    const xmlChar *publicId,
    const xmlChar *systemId,
    xmlChar *content)
{
  DtdXmlLoader& loader = *(static_cast<DtdXmlLoader *>( ctx ));
  ZORBA_LOADER_CHECK_ERROR(loader);
}

} // namespace simplestore
} // namespace zorba
/* vim:set et sw=2 ts=2: */
