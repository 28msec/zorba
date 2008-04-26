#ifndef ZORBA_DEFAULT_STORE_LOADER_H
#define ZORBA_DEFAULT_STORE_LOADER_H

#include <stack>
#include <libxml/parser.h>
#include <libxml/xmlstring.h>

#include "store/naive/ordpath.h"

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
  xmlSAXHandler                    theSaxHandler;

  xqpStringStore                 * theBaseUri;
  xqpStringStore                 * theDocUri;

  XmlTree                        * theTree;
  OrdPathStack                     theOrdPath;

  XmlNode                        * theRootNode;
  std::stack<XmlNode*>             theNodeStack;
  std::stack<NsBindingsContext*>   theBindingsStack;

  std::string                      theWarnings;

  char                             theBuffer[4096];

  error::ErrorManager            * theErrorManager;

public:
  XmlLoader(error::ErrorManager*);

  ~XmlLoader();

  XmlNode* loadXml(xqpStringStore* uri, std::istream& xmlStream);

protected:
  void abort();
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


