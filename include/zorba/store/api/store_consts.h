#ifndef XQP_STORE_CONSTS_H
#define XQP_STORE_CONSTS_H

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
  NodeKind_t;

};

}
#endif
