#ifndef XQP_SHARED_TYPES_INCL_H
#define XQP_SHARED_TYPES_INCL_H

#include "zorba/util/rchandle.h"

namespace xqp {

class Item;
class Iterator;

typedef rchandle<Item> Item_t;
typedef rchandle<Iterator> Iterator_t;

}

#endif
