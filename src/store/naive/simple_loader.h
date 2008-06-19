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
#ifndef ZORBA_DEFAULT_STORE_LOADER_H
#define ZORBA_DEFAULT_STORE_LOADER_H

#include <stack>
#include <libxml/parser.h>
#include <libxml/xmlstring.h>

#include "store/api/item.h"

namespace zorba { 
  
namespace error
{
  class ErrorManager; 
}

namespace store 
{
  class Item;
  class ItemFactory;
}

 
namespace simplestore 
{


/*******************************************************************************

  theBaseUri   : The loader does not not own the string memory
  theDocUri    : The loader does not not own the string memory

  theNodeStack : The startElement and startDocument events create an element or
                 document XmlNode (say N) and push it in theNodeStack. N will
                 at the top of the stack during the "start" event on each of N's
                 children. N is removed from the stack during the corresponding
                 endElement or endDocument events.

  theBuffer    : A buffer to read chunks of the source stream in.

********************************************************************************/
class XmlLoader
{
protected:
  xmlSAXHandler                    theSaxHandler;

  store::ItemFactory             * theFactory;

  xqpStringStore_t                 theBaseUri;
  xqpStringStore_t                 theDocUri;

  store::Item_t                    theRootNode;
  std::stack<store::Item*>         theNodeStack;

  char                             theBuffer[4096];

  error::ErrorManager            * theErrorManager;

public:
  XmlLoader(store::ItemFactory* factory, error::ErrorManager*);

  ~XmlLoader();

  store::Item_t loadXml(xqpStringStore_t& docuri, std::istream& xmlStream);

protected:
  void abortload();

  long readPacket(std::istream& stream, char* buf, long size);

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
        const xmlChar * value, 
        int len);

  static void comment(
        void * ctx, 
        const xmlChar * value);

  static void	processingInstruction(
        void * ctx, 
        const xmlChar * target, 
        const xmlChar * data);

  static void error(void * ctx, const char * msg, ... );

  static void warning(void * ctx, const char * msg, ... );
};

} // namespace store
} // namespace zorba

#endif /* ZORBA_SIMPLE_LOADER_H */


