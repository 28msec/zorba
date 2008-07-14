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
//#include <libxml/parser.h>
//#include <libxml/xmlstring.h>

#include "store/minimal/min_ordpath.h"
#include <list>
#include "store/api/item.h"
#include "store/minimal/qname_pool.h"
#include "store/minimal/string_pool.h"

namespace zorba { 
  
  namespace error {
    class ErrorManager;
  }

  namespace store
  {
    class Item;
    class ItemFactory;
  }
  namespace storeminimal 
  {

class XmlTree;
class XmlNode;
class NsBindingsContext;
class ElementTreeNode;
class NodeVector;
class SimpleStore;
class DocumentTreeNode;

typedef char    xmlChar;

typedef rchandle<DocumentTreeNode>    DocumentTreeNode_t;


class mystring
{
  char  prealloc_buff[100];
  char  *buff;
  int   buff_total;
  int   buff_written;
  int   grow_by;
public:
  mystring(int grow_by);
  ~mystring();

  void clear();
  void append(char c);
  int   length();
  const char *c_str();
  bool empty();
  bool byteEqual(const char *str, int str_len);

};


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

  DocumentTreeNode_t                      theRootNode;

  std::string                    theWarnings;

  char                             theBuffer[4096];
  mystring                         temp_buff;
  int  buff_size;
  int  buff_pos;

  int  current_c;
  int  prev_c;
  SimpleStore& store;
  StringPool& namespacePool;

  typedef struct
  {
  //  xqpStringStore_t   localname;
  //  xqpStringStore_t   prefix;
  //  xqpStringStore_t   uri;
    char    localname[100];
    int     localname_len;
    char    prefix[100];
    int     prefix_len;
    xqpStringStore_t   uri;
  }QNAME_ELEM;

  typedef struct
  {
    QNAME_ELEM    name;
    //NsBindingsContext_t    ns_bindings_context;

    ElementTreeNode       *elemNode;
  }TAG_ELEM;
  std::list<TAG_ELEM*>      tag_stack;

  struct ATTR_ELEM
  {
    //ATTR_ELEM() : value(20) {}

    QNAME_ELEM    name;

    xqpStringStore_t   value;
    //mystring    value;
  };
  typedef std::vector<ATTR_ELEM>    attr_list_t;
  attr_list_t elem_attrs;


  store::ItemFactory                    * theFactory;
  error::ErrorManager            * theErrorManager;
  bool  end_document;
  int   is_end_tag;
  std::istream *stream;

  int        reading_prolog;
  xqpStringStore_t   xml_version;
  xqpStringStore_t   xml_encoding;

public:
  enum lazyloadType_t 
  {
    UNTIL_START_ELEMENT,
    UNTIL_END_ELEMENT
  };

public:
  XmlLoader(store::ItemFactory* factory, error::ErrorManager*);

  ~XmlLoader();

  //load all doc
  XmlNode* loadXml(const xqpStringStore_t& uri, 
                   std::istream& stream);
  //or start lazy load
  XmlNode* startloadXml(
                   const xqpStringStore_t& uri, 
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
  bool read_attributes(store::NsBindings *nsbindings, attr_list_t& attrs);
  bool fill_in_uri(store::NsBindings *nsbindings, char* prefix, int prefix_len, xqpStringStore_t &result_uri);
  bool compareQNames(QNAME_ELEM &name1, QNAME_ELEM &name2);
  bool read_tag();
  bool read_characters();
  bool read_comment();
  bool read_cdata();
  bool read_pi();
  bool read_xmlprolog();
protected:
  void abortload();
  void clear_tag_stack();
  long readPacket(std::istream& stream, char* buf, long size);

public:
  static void	startDocument(void * ctx);

  static void endDocument(void * ctx);

  void startElement(
         TAG_ELEM *tag_elem,
         store::NsBindings &nsbindings,
         attr_list_t  &elem_attrs
    );
  
  void endElement();
//        void * ctx, 
//        const xmlChar * localname, 
//        const xmlChar * prefix, 
//        const xmlChar * URI);

  static void characters(
        void * ctx,
        xqpStringStore_t content);
        //const xmlChar * ch,
        //int len);

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

} // namespace storeminimal
} // namespace zorba

#endif /* ZORBA_SIMPLE_LOADER_H */


