#ifndef XQP_SHARED_TYPES_H
#define XQP_SHARED_TYPES_H

#include "util/rchandle.h"

namespace yy {

class location;

}

namespace xqp {

class XQType;
class Item;
class namespace_context;
class user_function;
class PlanIterator;
class Iterator;

typedef rchandle<XQType> xqtref_t;
typedef rchandle<Item> Item_t;
typedef rchandle<namespace_context> NamespaceContext_t;
typedef rchandle<PlanIterator> PlanIter_t;
typedef rchandle<Iterator> Iterator_t;

}

#endif /* XQP_SHARED_TYPES_H */
/* vim:set ts=2 sw=2: */
