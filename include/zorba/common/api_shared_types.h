#ifndef XQP_SHARED_TYPES_INCL_H
#define XQP_SHARED_TYPES_INCL_H

#include "zorba/util/rchandle.h"

namespace xqp {

class Item;
class Iterator;

/* stuff needed for the external functions */
class StatelessExternalFunction;
class ItemSequence;


typedef rchandle<Item> Item_t;
typedef rchandle<Iterator> Iterator_t;

/* stuff needed for the external functions */
typedef rchandle<StatelessExternalFunction> StatelessExternalFunction_t;
typedef rchandle<ItemSequence>              ItemSequence_t;

}

#endif
