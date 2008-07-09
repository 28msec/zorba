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
#ifndef ZORBA_SIMPLE_STORE_LOADER_H
#define ZORBA_SIMPLE_STORE_LOADER_H

#include <stack>
#include <libxml/parser.h>
#include <libxml/xmlstring.h>

#include "zorbautils/stack.h"

#include "store/api/item.h"

#include "store/naive/ordpath.h"


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

  theSaxHandler   : The struct containing the callback functions defined by the
                    XmlLoader and given as input to the libxml SAX parser.
 
  theBuffer       : A buffer to read chunks of the source stream in.

  theFactory      : The item factory of the store.
  theErrorManager : 

  theTraceLevel   :

  theBaseUri      : The loader does not not own the string memory
  theDocUri       : The loader does not not own the string memory

********************************************************************************/
class XmlLoader
{
protected:
  xmlSAXHandler                    theSaxHandler;

  char                             theBuffer[4096];

  store::ItemFactory             * theFactory;

  error::ErrorManager            * theErrorManager;

  long                             theTraceLevel;

  xqpStringStore_t                 theBaseUri;
  xqpStringStore_t                 theDocUri;

  bool                             theBuildDataGuide;

public:
  XmlLoader(
        store::ItemFactory* factory,
        error::ErrorManager* errorManager,
        bool dataguide)
    :
    theFactory(factory),
    theErrorManager(errorManager),
    theTraceLevel(0),
    theBuildDataGuide(dataguide)
  {
  }

  virtual ~XmlLoader() {}

  virtual store::Item_t loadXml(
        const xqpStringStore_t& docuri,
        std::istream& xmlStream) = 0;
};


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
class SimpleXmlLoader : public XmlLoader
{
protected:
  store::Item_t                    theRootNode;
  std::stack<store::Item*>         theNodeStack;

public:
  SimpleXmlLoader(
        store::ItemFactory* factory,
        error::ErrorManager* errorManager,
        bool dataguide);

  ~SimpleXmlLoader();

  store::Item_t loadXml(const xqpStringStore_t& docuri, std::istream& xmlStream);

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
class FastXmlLoader : public XmlLoader
{
protected:
  static const ulong               theElementChunckSize = 200;
      
protected:
  XmlTree                        * theTree;
  OrdPathStack                     theOrdPath;

  XmlNode                        * theRootNode;
  zorba::Stack<XmlNode*>           theNodeStack;
  std::stack<NsBindingsContext*>   theBindingsStack;

#ifdef DATAGUIDE
  zorba::Stack<ElementGuideNode*>  theGuideStack;
#endif

public:
  FastXmlLoader(
        store::ItemFactory* factory,
        error::ErrorManager* errorManager,
        bool dataguide);

  ~FastXmlLoader();

  store::Item_t loadXml(const xqpStringStore_t& uri, std::istream& xmlStream);

protected:
  void abortload();
  void reset();
  long readPacket(std::istream& stream, char* buf, long size);

  void setRoot(XmlNode* root);

  void* getElementNode();

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


