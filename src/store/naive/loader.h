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
#include "runtime/parsing_and_serializing/fragment_istream.h"


namespace zorba
{

class XQueryDiagnostics;

namespace store
{
  class Item;
}


namespace simplestore
{

class BasicItemFactory;
class ElementNode;

class XmlTree;
class XmlNode;
class ElementGuideNode;
class NsBindingsContext;


/*******************************************************************************

  theSaxHandler   : The struct containing the callback functions defined by the
                    XmlLoader and given as input to the libxml SAX parser.

  theBuffer       : A buffer to read chunks of the source stream in -- declared
                    in the derived classes.

  theFactory      : The item factory of the store.
  theXQueryDiagnostics :

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

  BasicItemFactory               * theFactory;

  XQueryDiagnostics              * theXQueryDiagnostics;

  long                             theTraceLevel;

  zstring                          theBaseUri;
  zstring                          theDocUri;

  bool                             theBuildDataGuide;

public:
  XmlLoader(
        BasicItemFactory* factory,
        XQueryDiagnostics* xqueryDiagnostics,
        bool dataguide)
    :
    ctxt(NULL),
    theFactory(factory),
    theXQueryDiagnostics(xqueryDiagnostics),
    theTraceLevel(0),
    theBuildDataGuide(dataguide)
  {
  }

  virtual ~XmlLoader() {}

  virtual store::Item_t loadXml(
        const zstring& baseUri,
        const zstring& docUri,
        std::istream& xmlStream) = 0;
};


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
  struct PathStepInfo
  {
    ElementNode    * theNode;
    zstring          theBaseUri;

    PathStepInfo(ElementNode* node, const zstring& uri)
      :
      theNode(node),
      theBaseUri(uri)
    {
    }
  };

protected:
  char                           * theBuffer;
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
        XQueryDiagnostics* xqueryDiagnostics,
        bool dataguide);

  ~FastXmlLoader();

  store::Item_t loadXml(
        const zstring& baseUri,
        const zstring& uri,
        std::istream& xmlStream);

protected:
  void abortload();
  void reset();
  std::streamsize readPacket(std::istream& stream, char* buf, long size);

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
  FragmentXmlLoader
*******************************************************************************/
class FragmentXmlLoader : public FastXmlLoader
{
public:
  FragmentXmlLoader(
        BasicItemFactory* factory,
        XQueryDiagnostics* xqueryDiagnostics,
        bool dataguide);

  ~FragmentXmlLoader();

  store::Item_t loadXml(
        const zstring& baseUri,
        const zstring& uri,
        std::istream& xmlStream);

protected:
  unsigned long getCurrentInputOffset() const;

  static void checkStopParsing(void* ctx, bool force = false);

  static void startDocument(void * ctx);

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

  static void comment(
        void * ctx,
        const xmlChar * value);

  static void cdataBlock(
        void * ctx,
        const xmlChar * value,
        int len);

  static void processingInstruction(
        void * ctx,
        const xmlChar * target,
        const xmlChar * data);

protected:
  FragmentIStream* theFragmentStream;
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
    zstring          theBaseUri;

    PathStepInfo(ElementNode* node, const zstring& uri)
      :
      theNode(node),
      theBaseUri(uri)
    {
    }
  };

protected:
  std::vector<char>                theBuffer;
  XmlTree                        * theTree;
  OrdPathStack                     theOrdPath;

  XmlNode                        * theRootNode;
  zorba::Stack<XmlNode*>           theNodeStack;
  zorba::Stack<PathStepInfo>       thePathStack;
  std::stack<NsBindingsContext*>   theBindingsStack;

  bool                             theParseExtParsedEntity;

#ifdef DATAGUIDE
  zorba::Stack<ElementGuideNode*>  theGuideStack;
#endif

public:
  DtdXmlLoader(
        BasicItemFactory* factory,
        XQueryDiagnostics* xqueryDiagnostics,
        bool dataguide,
        bool parseExtParsedEntity);

  ~DtdXmlLoader();

  store::Item_t loadXml(
        const zstring& baseUri,
        const zstring& uri,
        std::istream& xmlStream);

protected:
  void abortload();
  void reset();
  std::streamsize readPacket(std::istream& stream, char* buf, std::streamoff size);

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
/* vim:set et sw=2 ts=2: */
