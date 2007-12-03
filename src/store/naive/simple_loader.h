
#ifndef XQP_SIMPLE_LOADER_H
#define XQP_SIMPLE_LOADER_H

#include <stack>
#include <libxml/parser.h>
#include <libxml/xmlstring.h>

#include "store/api/item.h"
#include "store/naive/ordpath.h"

namespace xqp
{

template <class Object> class rchandle;

class Item;
class NodeItem;
class NsBindingsContext;

typedef rchandle<Item> Item_t;
typedef rchandle<class NodeItem> NodeItem_t;

typedef rchandle<class NsBindingsContext> NsBindingsContext_t;


/*******************************************************************************

********************************************************************************/
class XmlLoader
{
protected:
  xmlSAXHandler                   theSaxHandler;
 
  Item_t                          theRootNode;
  std::stack<Item_t>              theNodeStack;
  std::stack<NsBindingsContext_t> theBindingsStack;

  OrdPathStack                    theNodeId;

  xqpStringStore                  theErrors;

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

public:
  XmlLoader();

  ~XmlLoader();

  Item_t getRootNode() const { return theRootNode; }
  
  Item_t loadXml(std::istream& xmlStream);

protected:
  void reset();
  long readPacket(std::istream& stream, char* buf, long size);
};

} /* namespace xqp */

#endif /* XQP_SIMPLE_LOADER_H */


