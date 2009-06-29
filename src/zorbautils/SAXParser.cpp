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
#include "SAXParser.h"

#include <memory.h>
#include <string>


zorba::SAXParser::SAXParser( store::ItemFactory &factory, 
							xqpStringStore_t& baseUri, 
							xqpStringStore_t& docUri, 
							error::ErrorManager* errorManager )
:
theFactory(factory), theBaseUri(baseUri), theDocUri(docUri), theSucceeded(false), theErrorManager(errorManager)
{
  m_stream = new std::ostringstream();
}

zorba::SAXParser::~SAXParser()
{
  delete m_stream;
}

bool zorba::SAXParser::parseDocument( store::Item_t& result, std::istream& stream )
{
  std::string xmlText;
  std::string tmp;
  // ToDo: this is extremely nonperforming!
  std::ostringstream os;
  char buf[1024];
  while (!stream.eof()) {
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

	xmlSAXUserParseMemory(&theHandler, (void *) this, xmlText.c_str(), xmlText.size());
	result = theResult;
	return theSucceeded;
}

void zorba::SAXParser::startDocument( void * ctx )
{
	SAXParser &lParser = *(static_cast<SAXParser*>(ctx));
	lParser.theFactory.createDocumentNode(lParser.theResult, lParser.theBaseUri, lParser.theDocUri);
	lParser.theStack.push_back(lParser.theResult);
}

void zorba::SAXParser::endDocument( void * ctx )
{
	SAXParser& lParser = *(static_cast<SAXParser*>(ctx));
	lParser.theSucceeded = true;
}

void zorba::SAXParser::startElement( void * ctx, const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI, 
									int nb_namespaces, const xmlChar ** namespaces, int nb_attributes, int nb_defaulted, 
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
	for (int i = 0 ; i < nb_namespaces; i++) {
		xqpString pre(reinterpret_cast<const char*>(namespaces[i]));
		xqpString uri(reinterpret_cast<const char*>(namespaces[++i]));
		bindings.push_back(std::pair<xqpString, xqpString>(pre, uri));
	}
	store::Item_t typeName;
	factory.createElementNode(result, parent, -1, nodeName, typeName, false, false, false, false, bindings, lParser.theBaseUri);
	lParser.theStack.push_back(result);
}

void zorba::SAXParser::endElement( void * ctx, const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI )
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
  std::string s = os.str();
  xqpStringStore_t c = new xqpStringStore(s);
  lParser.theFactory.createTextNode(result, lParser.theStack.back().getp(), -1, c);
}

void zorba::SAXParser::comment( void * ctx, const xmlChar * ch )
{
	SAXParser& lParser = *(static_cast<SAXParser*>(ctx));
  lParser.createTextNodeFromBuffer();
	store::Item_t result;
	xqpStringStore_t data = new xqpStringStore(reinterpret_cast<const char*>(ch));
	lParser.theFactory.createCommentNode(result, lParser.theStack.back(), -1, data);
}

void zorba::SAXParser::processingInstruction( void * ctx, const xmlChar * target, const xmlChar * content )
{
	SAXParser& lParser = *(static_cast<SAXParser*>(ctx));
  lParser.createTextNodeFromBuffer();
	store::Item_t result;
	xqpStringStore_t data = new xqpStringStore(std::string(reinterpret_cast<const char*>(content)));
	xqpStringStore_t t = new xqpStringStore(reinterpret_cast<const char*>(target));
	lParser.theFactory.createPiNode(result, lParser.theStack.back(), -1, t, data, lParser.theBaseUri);
}

void zorba::SAXParser::error( void * ctx, const char * msg, ... )
{
	SAXParser& lParser = *(static_cast<SAXParser*>(ctx));
	char buf[1024];
	va_list args;
	va_start(args, msg);
	vsprintf(buf, msg, args);
	va_end(args);
	ZORBA_ERROR_DESC_CONTINUE(lParser.theErrorManager,
		STR0008_LOADER_PARSING_ERROR, buf);
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
  std::string s = m_stream->str();
  xqpStringStore_t c = new xqpStringStore(s);
  theFactory.createTextNode(result, theStack.back().getp(), -1, c);
  delete m_stream;
  m_stream = new std::ostringstream();
}
