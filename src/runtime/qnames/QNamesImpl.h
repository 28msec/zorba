/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef ZORBA_RUNTIME_QNAMES
#define ZORBA_RUNTIME_QNAMES

#include <vector>

#include "common/shared_types.h"

#include "runtime/base/unarybase.h" // remove after iterator refactoring
#include "runtime/base/binarybase.h" // remove after iterator refactoring
#include "runtime/base/narybase.h"

namespace zorba {

/*
 * 11.1.1 fn:resolve-QName
 * --------------------*/
 
BINARY_ITER(ResolveQNameIterator);


/*
 * 11.1.2 fn:QName
 * --------------------*/
 
BINARY_ITER(QNameIterator);


/*
 * 11.2.1 op:QName-equal
 * --------------------*/

BINARY_ITER(QNameEqualIterator)


/*
 * 11.2.2 fn:prefix-from-QName
 * -------------------- */

UNARY_ITER(PrefixFromQNameIterator);


/*
 * 11.2.3 fn:local-name-from-QName
 * -------------------- */

UNARY_ITER(LocalNameFromQNameIterator);


/*
 * 11.2.4 fn:namespace-uri-from-QName
 * -------------------- */

UNARY_ITER(NamespaceUriFromQNameIterator);


/*
 * 11.2.5 fn:namespace-uri-for-prefix
 * --------------------*/
NARY_ITER(NamespaceUriForPrefixIterator);


/*
 * 11.2.6 fn:in-scope-prefixes
 * -------------------- */

class InScopePrefixesState : public PlanIteratorState
{
  friend class InScopePrefixesIterator;

private:
  std::vector<std::pair<xqpStringStore_t, xqpStringStore_t> > theBindings;
  unsigned long theCurrentPos;

public:
  void init(PlanState&);
  void reset(PlanState&);
};


UNARY_ITER_STATE(InScopePrefixesIterator, InScopePrefixesState);


}/*namespace zorba*/

#endif /* ZORBA_QNAMES_IMPL_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
