#ifndef ZORBA_STORE_CONSTS_H
#define ZORBA_STORE_CONSTS_H

#include <string>

namespace xqp
{

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

}
#endif
