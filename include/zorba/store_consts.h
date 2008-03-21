#ifndef ZORBA_STORE_STORE_CONSTS_H
#define ZORBA_STORE_STORE_CONSTS_H

#include <string>

namespace zorba { namespace store {

class StoreConsts
{
 public:

  enum NodeKind
  {
    anyNode,
    documentNode,
    elementNode,
    attributeNode,
    textNode,
    piNode,
    commentNode
  };

  enum NsScoping 
  {
    ALL_NAMESPACES,
    ONLY_LOCAL_NAMESPACES,
    ONLY_PARENT_NAMESPACES
  };

  static std::string toString(NodeKind k);
};

} // namespace store
} // namespace zorba
#endif
