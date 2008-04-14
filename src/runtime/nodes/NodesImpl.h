/**
 * @copyright
 * ========================================================================
 *  Copyright FLWOR Foundation
 * ========================================================================
 *
 * @author Sorin Nasoi (sorin.nasoi@ipdevel.ro)
 * @file misc/MiscImpl.cpp
 *
 */

#ifndef ZORBA_NODES_IMPL_H
#define ZORBA_NODES_IMPL_H

#include "common/shared_types.h"
#include "runtime/base/narybase.h"

namespace zorba {

// 14.2 fn:local-name
NARY_ITER(FnLocalNameIterator);

// 14.3 fn:namespace-uri
NARY_ITER(FnNamespaceUriIterator);

// 14.5 fn:lang
NARY_ITER(FnLangIterator);

// 15.5.6 fn:collection
class FnCollectionIteratorState : public PlanIteratorState {
public:
  store::Iterator_t theIterator;

  void init(PlanState&);
  void reset(PlanState&);
};

NARY_ITER_STATE(FnCollectionIterator, FnCollectionIteratorState);

// NARY_ITER(FnCollectionIterator);
} /* namespace zorba */
#endif /* ZORBA_NODES_IMPL_H */
