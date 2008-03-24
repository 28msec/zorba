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

} /* namespace zorba */
#endif /* ZORBA_NODES_IMPL_H */
