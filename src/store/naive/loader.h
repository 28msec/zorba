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
#ifndef ZORBA_SIMPLE_STORE_LOADER
#define ZORBA_SIMPLE_STORE_LOADER

#include <stack>
#include <libxml/parser.h>
#include <libxml/xmlstring.h>

#include "store/api/item.h"

#include "store/naive/ordpath.h"

#include "zorbautils/stack.h"


namespace zorba 
{ 
  
namespace error
{
  class ErrorManager; 
}

namespace store 
{
  class Item;
}


namespace simplestore 
{

class BasicItemFactory;
class ElementNode;


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
  static const ulong INPUT_CHUNK_SIZE = 8192;

protected:
  xmlParserCtxtPtr                 ctxt;

  xmlSAXHandler                    theSaxHandler;

  char                             theBuffer[INPUT_CHUNK_SIZE];

  BasicItemFactory               * theFactory;

  error::ErrorManager            * theErrorManager;

  long                             theTraceLevel;

  xqpStringStore_t                 theBaseUri;
  xqpStringStore_t                 theDocUri;

  bool                             theBuildDataGuide;

public:
  XmlLoader(
        BasicItemFactory* factory,
        error::ErrorManager* errorManager,
        bool dataguide)
    :
    ctxt(NULL),
    theFactory(factory),
    theErrorManager(errorManager),
    theTraceLevel(0),
    theBuildDataGuide(dataguide)
  {
  }

  virtual ~XmlLoader() {}

  virtual store::Item_t loadXml(
        const xqpStringStore_t& baseUri,
        const xqpStringStore_t& docUri,
        std::istream& xmlStream) = 0;
};


#ifdef SIMPLE_LOADER

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

#endif // SIMPLE_LOADER


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
  struct PathStepInfo
  {
    ElementNode    * theNode;
    xqpStringStore * theBaseUri;

    PathStepInfo(ElementNode* node, xqpStringStore* uri)
      :
      theNode(node),
      theBaseUri(uri) 
    {
    }
  };

protected:
  XmlTree                        * theTree;
  OrdPathStack                     theOrdPath;

  XmlNode                        * theRootNode;
  zorba::Stack<XmlNode*>           theNodeStack;
  zorba::Stack<PathStepInfo>       thePathStack;
  std::stack<NsBindingsContext*>   theBindingsStack;

#ifdef DATAGUIDE
  zorba::Stack<ElementGuideNode*>  theGuideStack;
#endif

public:
  FastXmlLoader(
        BasicItemFactory* factory,
        error::ErrorManager* errorManager,
        bool dataguide);

  ~FastXmlLoader();

  store::Item_t loadXml(
        const xqpStringStore_t& baseUri,
        const xqpStringStore_t& uri,
        std::istream& xmlStream);

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

  static xmlEntityPtr	getEntity(
        void * ctx, 					 
        const xmlChar * name);

  static xmlEntityPtr getParameterEntity(
        void *ctx,
        const xmlChar *name);

  static void entityDecl(
        void *ctx,
        const xmlChar *name,
        int type,
        const xmlChar *publicId,
        const xmlChar *systemId,
        xmlChar *content);
};

/*******************************************************************************

  DtdXmlLoader - implements XmlLoader interface as FastXmlLoader but it uses 
                 libxml2's tree parser to be able identify ID, IDREF and IDREFS
               - has more functionality but uses more memory - potentialy slower
                 for big documents 

*******************************************************************************/
class DtdXmlLoader : public XmlLoader
{
  struct PathStepInfo
  {
    ElementNode    * theNode;
    xqpStringStore * theBaseUri;

    PathStepInfo(ElementNode* node, xqpStringStore* uri)
      :
      theNode(node),
      theBaseUri(uri) 
    {
    }
  };

protected:
  XmlTree                        * theTree;
  OrdPathStack                     theOrdPath;

  XmlNode                        * theRootNode;
  zorba::Stack<XmlNode*>           theNodeStack;
  zorba::Stack<PathStepInfo>       thePathStack;
  std::stack<NsBindingsContext*>   theBindingsStack;

#ifdef DATAGUIDE
  zorba::Stack<ElementGuideNode*>  theGuideStack;
#endif

public:
  DtdXmlLoader(
        BasicItemFactory* factory,
        error::ErrorManager* errorManager,
        bool dataguide);

  ~DtdXmlLoader();

  store::Item_t loadXml(
        const xqpStringStore_t& baseUri,
        const xqpStringStore_t& uri,
        std::istream& xmlStream);

protected:
  void abortload();
  void reset();
  long readPacket(std::istream& stream, char* buf, long size);

  void setRoot(XmlNode* root);

  void* getElementNode();

  void loadDocument(xmlDoc *doc);
  void loadNode(xmlNode *node);

public:
  static void	startDocument(void * ctx);

  static void endDocument(void * ctx);

  static void startElement(
        void * ctx, 
        xmlNode *node);
  
  static void endElement(
        void * ctx, 
        xmlNode *node);

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

  static xmlEntityPtr	getEntity(
        void * ctx, 					 
        const xmlChar * name);

  static xmlEntityPtr getParameterEntity(
        void *ctx,
        const xmlChar *name);

  static void entityDecl(
        void *ctx,
        const xmlChar *name,
        int type,
        const xmlChar *publicId,
        const xmlChar *systemId,
        xmlChar *content);
};


} // namespace store
} // namespace zorba

#endif /* ZORBA_SIMPLE_STORE_LOADER */


/*
 * Local variables:
 * mode: c++
 * End:
 */
