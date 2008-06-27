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
#ifndef ZORBA_SIMPLE_STORE_FASTLOADER_H
#define ZORBA_SIMPLE_STORE_FASTLOADER_H

#include <stack>
#include <libxml/parser.h>
#include <libxml/xmlstring.h>

#include "zorbautils/stack.h"

#include "store/naive/ordpath.h"

namespace zorba 
{ 
  
namespace error 
{
  class ErrorManager;
}

namespace simplestore 
{

class XmlTree;
class XmlNode;
class ElementGuideNode;
class NsBindingsContext;


/*******************************************************************************

  theNodeStack : The startElement and startDocument methods create an element
                 or document XmlNode (say N) and push it in theNodeStack. If N 
                 has k children, then when the closing tag of N is reached,
                 the children of N will be at the k top positions of theNodeStack
                 and the endElement and endDocument methods will remove these
                 children from the stack and link them with N.

********************************************************************************/
class FastXmlLoader
{
protected:
  XmlTree                        * theTree;
  OrdPathStack                     theOrdPath;

  XmlNode                        * theRootNode;
  zorba::Stack<XmlNode*>           theNodeStack;
  std::stack<NsBindingsContext*>   theBindingsStack;

  zorba::Stack<ElementGuideNode*>  theGuideStack;

public:
  FastXmlLoader(store::ItemFactory* factory, error::ErrorManager*);

  ~FastXmlLoader();

  XmlNode* loadXml(xqpStringStore_t& uri, std::istream& xmlStream);

protected:
  void abortload();
  void reset();
  long readPacket(std::istream& stream, char* buf, long size);

  void setRoot(XmlNode* root);

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


