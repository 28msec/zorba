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
 
#ifndef ZORBA_RUNTIME_EVAL_EVAL_H
#define ZORBA_RUNTIME_EVAL_EVAL_H

#include "common/shared_types.h"

#include "runtime/base/narybase.h"

namespace zorba {


class EvalIteratorState : public PlanIteratorState
{
public:
  PlanIter_t                     thePlan;
  PlanWrapper_t                  thePlanWrapper;
  std::auto_ptr<CompilerCB>      ccb;
  std::auto_ptr<dynamic_context> dctx;

  EvalIteratorState();

  ~EvalIteratorState();
};


class EvalIterator : public NaryBaseIterator<EvalIterator, EvalIteratorState>
{ 
protected:
  checked_vector<store::Item_t>  theVarNames;
  checked_vector<xqtref_t>       theVarTypes;

public:
  SERIALIZABLE_CLASS(EvalIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(EvalIterator,
  NaryBaseIterator<EvalIterator, EvalIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  EvalIterator(
        static_context* sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& children,
        const checked_vector<store::Item_t>& aVarNames,
        const checked_vector<xqtref_t>& aVarTypes);

  ~EvalIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


}
#endif
/*
 * Local variables:
 * mode: c++
 * End:
 */ 
