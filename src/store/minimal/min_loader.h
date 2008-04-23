#ifndef ZORBA_MINIMAL_STORE_LOADER_H
#define ZORBA_MINIMAL_STORE_LOADER_H

#include <stack>
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

********************************************************************************/
class XmlLoader
{
protected:
//  xmlSAXHandler                    theSaxHandler;

  xqpStringStore                 * theBaseUri;
  xqpStringStore                 * theDocUri;

  XmlTree                        * theTree;
  OrdPathStack                     theOrdPath;

  XmlNode                        * theRootNode;
  std::stack<XmlNode*>             theNodeStack;
  std::stack<NsBindingsContext*>   theBindingsStack;

  xqpStringStore                   theWarnings;

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
  }TAG_ELEM;
  std::list<TAG_ELEM*>      tag_stack;

  typedef struct
  {
    QNAME_ELEM    name;

    std::string   attr_value;
  }ATTR_ELEM;
  typedef std::list<ATTR_ELEM>    attr_list_t;


  error::ErrorManager            * theErrorManager;

public:
  XmlLoader(error::ErrorManager*);

  ~XmlLoader();

  XmlNode* loadXml(xqpStringStore* uri, std::istream& xmlStream);
protected:
  int  read_char(std::istream &stream);
  void unread_char();
  bool isWhitespace(int c);
  bool isNameChar(int c);
  void skip_whitespaces(std::istream &stream);
  bool read_qname(std::istream &stream, QNAME_ELEM &qname, bool read_attr);
  bool read_attributes(std::istream &stream, attr_list_t &all_attributes);
  bool fill_in_uri(std::string &prefix, std::string &result_uri);
  bool compareQNames(QNAME_ELEM &name1, QNAME_ELEM &name2);
  bool read_tag(std::istream& stream);
  bool read_characters(std::istream &stream, bool *end_document);
  bool read_comment(std::istream &stream);
  bool read_pi(std::istream &stream);
protected:
  void abort();
  void reset();
  void clear_tag_stack();
  long readPacket(std::istream& stream, char* buf, long size);

  void setRoot(XmlNode* root);

public:
  void	startDocument();

  void endDocument();

  void startElement(
        const char * localname, 
        const char * prefix, 
        const char * URI, 
        int nb_namespaces, 
        const char ** namespaces, 
        int nb_attributes, 
        int nb_defaulted, 
        const char ** attributes);
  
  void endElement(
        const char * localname, 
        const char * prefix, 
        const char * URI);

  void characters(
        const char * ch,
        int len);

  void	cdataBlock(
        const char * value, 
        int len);

  void comment(
        const char * value);

  void	processingInstruction(
        const char * target, 
        const char * data);

  void error(const char * msg, ... );

  void warning(const char * msg, ... );
};

} // namespace store
} // namespace zorba

#endif /* ZORBA_SIMPLE_LOADER_H */


