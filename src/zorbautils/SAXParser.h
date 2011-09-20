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
#pragma once
#ifndef SAX_PARSER_H
#define SAX_PARSER_H

#include "store/api/item.h"
#include "store/api/item_factory.h"
#include "diagnostics/xquery_diagnostics.h"

#include <libxml/parser.h>
#include <libxml/xmlstring.h>

#include <istream>
#include <vector>

namespace zorba {


class ZORBA_DLL_PUBLIC SAXParser 
{
 public:
  SAXParser(store::ItemFactory &factory, 
            const zstring& baseUri, 
            const zstring& docUri, 
            XQueryDiagnostics* xqueryDiagnostics);

  virtual ~SAXParser();

 public:
  bool parseDocument(store::Item_t& result, std::istream& stream);
 public:
  static void	startDocument(void * ctx);

  static void endDocument(void * ctx);

  static void startElement(
			void * ctx, 
			const xmlChar * localname, 
			const xmlChar * prefix, 
			const xmlChar * URI, 
			int nb_namespaces, 
			const xmlChar ** namespaces, 
			int nb_attributes, 
			int nb_defaulted, 
			const xmlChar ** attributes);

  static void endElement(
			void * ctx, 
			const xmlChar * localname, 
			const xmlChar * prefix, 
			const xmlChar * URI);

  static void characters(
			void * ctx,
			const xmlChar * ch,
			int len);

  static void	cdataBlock(
			void * ctx, 
			const xmlChar * ch, 
			int len);

  static void comment(
			void * ctx, 
			const xmlChar * ch);

  static void	processingInstruction(
			void * ctx, 
			const xmlChar * target, 
			const xmlChar * data);

  static void error(void * ctx, const char * msg, ... );

  static void warning(void * ctx, const char * msg, ... );

 protected:
  void createTextNodeFromBuffer();

  xmlSAXHandler theHandler;
  store::Item_t theResult;
  store::ItemFactory& theFactory;
  const zstring& theBaseUri;
  const zstring& theDocUri;
  bool theSucceeded;
  std::vector<store::Item_t> theStack;
  XQueryDiagnostics* theXQueryDiagnostics;
  std::ostringstream* m_stream;
};


}

#endif
/* vim:set et sw=2 ts=2: */
