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

#include "SAXParser.h"

#include <memory.h>
#include <string>


zorba::SAXParser::SAXParser(
    store::ItemFactory &factory, 
    const zstring& baseUri, 
    const zstring& docUri, 
    XQueryDiagnostics* xqueryDiagnostics)
  :
  theFactory(factory),
  theBaseUri(baseUri),
  theDocUri(docUri),
  theSucceeded(false),
  theXQueryDiagnostics(xqueryDiagnostics)
{
  m_stream = new std::ostringstream();
}


zorba::SAXParser::~SAXParser()
{
  delete m_stream;
}


bool zorba::SAXParser::parseDocument(store::Item_t& result, std::istream& stream)
{
  std::string xmlText;
  std::string tmp;
  // ToDo: this is extremely nonperforming!
  std::ostringstream os;
  char buf[1024];
  while (!stream.eof()) 
  {
    stream.read(buf, 1024);
    os.write(buf, stream.gcount());
  }
  xmlText = os.str();

  memset(&theHandler, 0, sizeof(theHandler) );
  theHandler.initialized = XML_SAX2_MAGIC;
  theHandler.startDocument = &SAXParser::startDocument;
  theHandler.endDocument = &SAXParser::endDocument;
  theHandler.startElementNs = &SAXParser::startElement;
  theHandler.endElementNs = &SAXParser::endElement;
  theHandler.characters = &SAXParser::characters;
  theHandler.cdataBlock = &SAXParser::cdataBlock;
  theHandler.comment = &SAXParser::comment;
  theHandler.processingInstruction = &SAXParser::processingInstruction;
  theHandler.error = &SAXParser::error;
  theHandler.warning = &SAXParser::warning;

  xmlSAXUserParseMemory(&theHandler, (void *) this, xmlText.c_str(), (int)xmlText.size());
  result = theResult;
  return theSucceeded;
}


void zorba::SAXParser::startDocument( void * ctx )
{
  SAXParser &lParser = *(static_cast<SAXParser*>(ctx));

  zstring baseuri = lParser.theBaseUri;
  zstring docuri = lParser.theDocUri;

  lParser.theFactory.createDocumentNode(lParser.theResult, baseuri, docuri);
  lParser.theStack.push_back(lParser.theResult);
}


void zorba::SAXParser::endDocument( void * ctx )
{
  SAXParser& lParser = *(static_cast<SAXParser*>(ctx));
  lParser.theSucceeded = true;
}


void zorba::SAXParser::startElement(
    void * ctx,
    const xmlChar * localname,
    const xmlChar * prefix,
    const xmlChar * URI, 
    int nb_namespaces,
    const xmlChar ** namespaces,
    int nb_attributes,
    int nb_defaulted, 
    const xmlChar ** attributes )
{
  SAXParser& lParser = *(static_cast<SAXParser*>(ctx));
  if (lParser.theStack.size() > 1) {
    lParser.createTextNodeFromBuffer();
  }
  store::ItemFactory& factory = lParser.theFactory;
  store::Item_t parent = lParser.theStack.back();
  store::Item_t result;
  store::Item_t nodeName;

  factory.createQName(nodeName, reinterpret_cast<const char*>(URI), reinterpret_cast<const char*>(prefix), 
    reinterpret_cast<const char*>(localname));
  store::NsBindings bindings;
  for (int i = 0 ; i < nb_namespaces; i++) 
  {
    zstring pre(reinterpret_cast<const char*>(namespaces[i]));

    zstring uri(reinterpret_cast<const char*>(namespaces[++i]));

    bindings.push_back(std::pair<zstring, zstring>(pre, uri));
  }
  store::Item_t typeName;
  zstring baseuri = lParser.theBaseUri;

  factory.createElementNode(result, parent, nodeName, typeName, false, false, bindings, baseuri);
  unsigned int index = 0;
  for (int indexAttribute = 0;
       indexAttribute < nb_attributes;
       ++indexAttribute, index += 5) 
  {
      store::Item_t res;
      store::Item_t anAttrName;
      store::Item_t aTypedValue;
      factory.createQName(
        anAttrName,
        reinterpret_cast<const char*>(attributes[index+2]),
        reinterpret_cast<const char*>(attributes[index+1]),
        reinterpret_cast<const char*>(attributes[index]));

      zstring aValue(reinterpret_cast<const char*>(attributes[index+3]), reinterpret_cast<const char*>(attributes[index+4]));

      factory.createUntypedAtomic(aTypedValue, aValue);

      factory.createAttributeNode(res, result.getp(), anAttrName, typeName, aTypedValue);
  }
  lParser.theStack.push_back(result);
}


void zorba::SAXParser::endElement(
     void * ctx,
     const xmlChar * localname,
     const xmlChar * prefix,
     const xmlChar * URI)
{
  SAXParser& lParser = *(static_cast<SAXParser*>(ctx));
  if (lParser.theStack.size() > 2) {
    lParser.createTextNodeFromBuffer();
  }
  lParser.theStack.pop_back();
}


void zorba::SAXParser::characters( void * ctx, const xmlChar * ch, int len )
{
  SAXParser& lParser = *(static_cast<SAXParser*>(ctx));
  lParser.m_stream->write(reinterpret_cast<const char*>(ch), len);
}


void zorba::SAXParser::cdataBlock( void * ctx, const xmlChar * ch, int len )
{
  SAXParser& lParser = *(static_cast<SAXParser*>(ctx));
  lParser.createTextNodeFromBuffer();
  store::Item_t result;
  std::ostringstream os;
  os.write(reinterpret_cast<const char*>(ch), len);
  zstring s(os.str());
  lParser.theFactory.createTextNode(result, lParser.theStack.back().getp(), s);
}


void zorba::SAXParser::comment( void * ctx, const xmlChar * ch )
{
  SAXParser& lParser = *(static_cast<SAXParser*>(ctx));
  lParser.createTextNodeFromBuffer();
  store::Item_t result;
  zstring data(reinterpret_cast<const char*>(ch));
  lParser.theFactory.createCommentNode(result, lParser.theStack.back(), data);
}


void zorba::SAXParser::processingInstruction( 
    void * ctx, 
    const xmlChar * target,
    const xmlChar * content )
{
  SAXParser& lParser = *(static_cast<SAXParser*>(ctx));
  lParser.createTextNodeFromBuffer();
  store::Item_t result;
  zstring data(reinterpret_cast<const char*>(content));
  zstring t = reinterpret_cast<const char*>(target);
  zstring baseuri = lParser.theBaseUri;
  lParser.theFactory.createPiNode(result, lParser.theStack.back(), t, data, baseuri);
}


void zorba::SAXParser::error( void * ctx, const char * msg, ... )
{
  SAXParser& lParser = *(static_cast<SAXParser*>(ctx));
  char buf[1024];
  va_list args;
  va_start(args, msg);
  vsprintf(buf, msg, args);
  va_end(args);
  lParser.theXQueryDiagnostics->add_error(
    NEW_ZORBA_EXCEPTION(
      zerr::ZSTR0021_LOADER_PARSING_ERROR, ERROR_PARAMS( buf )
    )
  );
}


void zorba::SAXParser::warning( void * ctx, const char * msg, ... )
{
  char buf[1024];
  va_list args;
  va_start(args, msg);
  vsprintf(buf, msg, args);
  va_end(args);

  std::cerr << buf << std::endl;
}


void zorba::SAXParser::createTextNodeFromBuffer()
{
  store::Item_t result;
  zstring s(m_stream->str());
  theFactory.createTextNode(result, theStack.back().getp(), s);
  delete m_stream;
  m_stream = new std::ostringstream();
}
/* vim:set et sw=2 ts=2: */
