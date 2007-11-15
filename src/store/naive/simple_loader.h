
#ifndef XQP_SIMPLE_LOADER_H
#define XQP_SIMPLE_LOADER_H

#include <stack>
#include <libxml/parser.h>
#include <libxml/xmlstring.h>

#include "store/api/item.h"

namespace xqp
{

template <class Object> class rchandle;

class Item;
class NodeItem;
typedef rchandle<Item> Item_t;
typedef rchandle<class NodeItem> NodeItem_t;


class XmlLoader
{
protected:
  xmlSAXHandler           theSaxHandler;
 
  NodeItem_t              theRootNode;
  std::stack<NodeItem_t>  thePath;

public:
  static void startElementNs(
        void * ctx, 
        const xmlChar * localname, 
        const xmlChar * prefix, 
        const xmlChar * URI, 
        int nb_namespaces, 
        const xmlChar ** namespaces, 
        int nb_attributes, 
        int nb_defaulted, 
        const xmlChar ** attributes);
  
  static void endElementNs(
        void * ctx, 
        const xmlChar * localname, 
        const xmlChar * prefix, 
        const xmlChar * URI);

  static void error(void * ctx, const char * msg, ... );

  static void warning(void * ctx, const char * msg, ... );

public:
  XmlLoader();

  ~XmlLoader();

  NodeItem_t getRootNode() const { return theRootNode; }
  
  NodeItem_t loadXml(std::iostream& xmlStream);

protected:
  long readPacket(std::iostream& stream, char* buf, long size);
};

} /* namespace xqp */

#endif /* XQP_SIMPLE_LOADER_H */


