/**
 * @copyright
 * ========================================================================
 *  Copyright FLWOR Foundation
 * ========================================================================
 *
 * @author Sorin Nasoi (sorin.nasoi@ipdevel.ro)
 * @file misc/MiscImpl.h
 *
 */

#ifndef ZORBA_MISC_IMPL_H
#define ZORBA_MISC_IMPL_H
 
#include "common/shared_types.h"
#include "runtime/base/narybase.h"

namespace zorba {

// 3 The Error Function
NARY_ITER(FnErrorIterator);

// 8.1 fn:resolve-uri
NARY_ITER(FnResolveUriIterator);

NARY_ITER(SequentialIterator);

} /* namespace zorba */

#endif /* ZORBA_MISC_IMPL_H */

