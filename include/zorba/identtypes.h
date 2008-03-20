#ifndef ZORBA_TYPEIDENT_TYPES_API_H
#define ZORBA_TYPEIDENT_TYPES_API_H

namespace zorba {
class IdentTypes {
public:
  typedef enum {
    NAMED_TYPE,
    ELEMENT_TYPE,
    ATTRIBUTE_TYPE,
    DOCUMENT_TYPE,
    PI_TYPE,
    TEXT_TYPE,
    COMMENT_TYPE,
    ANY_NODE_TYPE,
    ITEM_TYPE,
    EMPTY_TYPE,
    INVALID_TYPE,
  } kind_t;

  typedef enum {
    QUANT_ONE,
    QUANT_QUESTION,
    QUANT_PLUS,
    QUANT_STAR,
  } quantifier_t;
};
}

#endif
