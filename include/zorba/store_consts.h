#ifndef ZORBA_STORE_CONSTS_H
#define ZORBA_STORE_CONSTS_H

#include <string>

namespace zorba { namespace store {

class StoreConsts
{
 public:

  typedef enum
  {
    anyNode,
    documentNode,
    elementNode,
    attributeNode,
    textNode,
    piNode,
    commentNode
  }
  NodeKind;

  static std::string toString(NodeKind k);
};

} // namespace store
} // namespace zorba
#endif
