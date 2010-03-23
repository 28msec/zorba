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
#ifndef ZORBA_RUNTIME_GFLWOR_OUTER_FOR_ITERATOR
#define ZORBA_RUNTIME_GFLWOR_OUTER_FOR_ITERATOR

#include <vector>

#include "runtime/base/binarybase.h"


namespace zorba 
{

namespace flwor 
{

class OuterForIterator : public BinaryBaseIterator<OuterForIterator, PlanIteratorState> 
{
private:
  store::Item_t           theVarName;
  std::vector<PlanIter_t> theOuterForVars;

public:
  SERIALIZABLE_CLASS(OuterForIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  OuterForIterator, 
  BinaryBaseIterator<OuterForIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar);

public:
  OuterForIterator(
        static_context* sctx,
        const QueryLoc& aLoc,
        store::Item* aVarName,
        PlanIter_t aTupleIterator,
        PlanIter_t aInput,
        const std::vector<PlanIter_t>& aOuterForVars);
  
  ~OuterForIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
};

}
}


#endif  /* ZORBA_RUNTIME_GFLWOR_OUTER_FOR_ITERATOR */
/*
 * Local variables:
 * mode: c++
 * End:
 */
