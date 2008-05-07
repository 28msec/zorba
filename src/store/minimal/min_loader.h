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
#ifndef ZORBA_MINIMAL_STORE_LOADER_H
#define ZORBA_MINIMAL_STORE_LOADER_H

#include <stack>
#include "util/rchandle.h"
//#include <libxml/parser.h>
//#include <libxml/xmlstring.h>

#include "store/minimal/min_ordpath.h"
#include <list>
#include "store/api/item.h"

namespace zorba { 
  
  namespace error {
    class ErrorManager;
  }

  namespace store {

class XmlTree;
class XmlNode;
class NsBindingsContext;

typedef char    xmlChar;

/*******************************************************************************

  theBaseUri   : The loader does not not own the string memory
  theDocUri    : The loader does not not own the string memory

  theNodeStack : The startElement and startDocument methods create an element
                 or document XmlNode (say N) and push it in theNodeStack. If N 
                 has k children, then when the closing tag of N is reached,
                 the children of N will be at the k top positions of theNodeStack
                 and the endElement and endDocument methods will remove these
                 children from the stack and link them with N.

  theBuffer    : A buffer to read chunks of the source stream in.

  For lazy loading, the XmlLoader is specific for each document

********************************************************************************/
class XmlLoader : public SimpleRCObject
{
protected:
//  xmlSAXHandler                    theSaxHandler;

  xqpStringStore_t                 theBaseUri;
  xqpStringStore_t                 theDocUri;

  XmlTree                        * theTree;
  OrdPathStack                     theOrdPath;

  XmlNode                        * theRootNode;
  //std::stack<XmlNode*>             theNodeStack;
  //std::stack<NsBindingsContext*>   theBindingsStack;

  std::string                   theWarnings;

  char                             theBuffer[4096];
  int  buff_size;
  int  buff_pos;

  int  current_c;
  int  prev_c;

  typedef struct
  {
    std::string   localname;
    std::string   prefix;
    std::string   uri;
  }QNAME_ELEM;

  typedef struct
  {
    QNAME_ELEM    name;
    NsBindings    ns_bindings;

    XmlNode       *elem;
  }TAG_ELEM;
  std::list<TAG_ELEM*>      tag_stack;

  typedef struct
  {
    QNAME_ELEM    name;

    std::string   attr_value;
  }ATTR_ELEM;
  typedef std::list<ATTR_ELEM>    attr_list_t;


  error::ErrorManager            * theErrorManager;
  bool  end_document;
  int   is_end_tag;
  std::istream *stream;

  int        reading_prolog;
  std::string   xml_version;
  std::string   xml_encoding;

public:
  enum lazyloadType_t 
  {
    UNTIL_START_ELEMENT,
    UNTIL_END_ELEMENT
  };

public:
  XmlLoader(error::ErrorManager*);

  ~XmlLoader();

  //load all doc
  XmlNode* loadXml(xqpStringStore_t& uri, 
                   std::istream& stream);
  //or start lazy load
  XmlNode* startloadXml(
                   xqpStringStore_t& uri, 
                   std::istream* xmlStream);
  bool continueloadXml(
                   enum lazyloadType_t,//for lazy loading, UNTIL_START_ELEMENT or UNTIL_END_ELEMENT
                   unsigned int   depth);//for lazy loading, 1 based, when to stop loading;
protected:
  int  read_char();
  void unread_char();
  bool isWhitespace(int c);
  bool isNameChar(int c);
  void skip_whitespaces();
  bool read_qname(QNAME_ELEM &qname, bool read_attr);
  bool read_attributes( attr_list_t &all_attributes);
  bool fill_in_uri(std::string &prefix, std::string &result_uri);
  bool compareQNames(QNAME_ELEM &name1, QNAME_ELEM &name2);
  bool read_tag();
  bool read_characters();
  bool read_comment();
  bool read_pi();
  bool read_xmlprolog();
protected:
  void abort();
  void reset();
  void clear_tag_stack();
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

typedef rchandle<XmlLoader>   XmlLoader_t;

} // namespace store
} // namespace zorba

#endif /* ZORBA_SIMPLE_LOADER_H */


