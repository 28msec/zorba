#ifndef XQP_SHARED_TYPES_H
#define XQP_SHARED_TYPES_H

#include "zorba/common/api_shared_types.h"
#include "zorba/util/rchandle.h"

namespace yy {

class location;

}

namespace xqp {

class XQType;
class namespace_context;
class user_function;
class PlanIterator;
class SimpleCollection;
class XmlTree;
class AnyUriItem;
class NodeItem;
class TempSeq;
class PUL;
class ItemFactory;
class Collection;
class StringPool;
class QNamePool;

typedef rchandle<XQType> xqtref_t;
typedef rchandle<namespace_context> NamespaceContext_t;
typedef rchandle<PlanIterator> PlanIter_t;
typedef rchandle<SimpleCollection> SimpleCollection_t;
typedef rchandle<XmlTree> XmlTree_t;
typedef rchandle<AnyUriItem> AnyUriItem_t;
typedef rchandle<NodeItem> NodeItem_t;
typedef rchandle<TempSeq> TempSeq_t;
typedef rchandle<PUL> PUL_t;
typedef rchandle<Collection> Collection_t;

}

#endif /* XQP_SHARED_TYPES_H */
/* vim:set ts=2 sw=2: */
