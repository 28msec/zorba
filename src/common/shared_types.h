#ifndef XQP_SHARED_TYPES_H
#define XQP_SHARED_TYPES_H

#include "util/rchandle.h"

namespace xqp {

class XQType;
class Item;

typedef rchandle<XQType> xqtref_t;
typedef rchandle<Item> Item_t;

}

#endif /* XQP_SHARED_TYPES_H */
/* vim:set ts=2 sw=2: */
