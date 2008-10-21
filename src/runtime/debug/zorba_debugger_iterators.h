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

#ifndef ZORBA_DEBUGGER_ITERATORS_H
#define ZORBA_DEBUGGER_ITERATORS_H

#include <vector>

#include "common/shared_types.h"
#include "runtime/base/narybase.h"
#include "types/typeimpl.h"
#include "compiler/expression/expr.h"

namespace zorba {

typedef rchandle<var_expr> var_expr_t;
class ZorbaDebugger;

class FnDebugIterator : public NaryBaseIterator<FnDebugIterator, PlanIteratorState>
{
  private:
    ZorbaDebugger *theDebugger;
    checked_vector<store::Item_t> varnames;
    checked_vector<std::string> var_keys;  
    checked_vector<xqtref_t> vartypes;
    checked_vector<global_binding> globals;
    bool for_expr;

  public:
    FnDebugIterator(const QueryLoc& loc,
                 checked_vector<store::Item_t> varnames_,
                 checked_vector<std::string> var_keys_,
                 checked_vector<xqtref_t> vartypes_,
                 checked_vector<global_binding> globals_,
                 std::vector<PlanIter_t>& aChildren,
                 bool for_expr = false);

    virtual ~FnDebugIterator();

    bool nextImpl( store::Item_t& result, PlanState& planState ) const;

    void accept(PlanIterVisitor& v) const;

    void openImpl(PlanState& planState, uint32_t& offset );

  private:
    void updateInfos(const QueryLoc& loc, PlanState& planState, checked_vector<store::Item_t> varnames,
                     checked_vector<std::string> var_keys, checked_vector<xqtref_t> vartypes,
                     checked_vector<global_binding> globals) const;

   
};
} /* namespace zorba */

#endif /* XQP_DEBUG_ITERATORS_H */
/* vim:set ts=2 sw=2: */
