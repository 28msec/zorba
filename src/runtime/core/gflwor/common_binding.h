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
#ifndef ZORBA_RUNTIME_GFLWOR_COMMON_BINDING
#define ZORBA_RUNTIME_GFLWOR_COMMON_BINDING

#include "zorba/api_shared_types.h"
#include "zorbautils/checked_vector.h"
#include "runtime/core/var_iterators.h"
#include "system/globalenv.h"
#include "store/api/store.h"
#include "runtime/api/plan_iterator_wrapper.h"
#include "store/api/temp_seq.h"

//using namespace zorba;

namespace zorba 
{

namespace flwor 
{

/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Static Binding Functions                                                   //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

inline void bindVariables(
    store::TempSeq_t& aTmpSeq,
    const std::vector<LetVarIter_t>& aLetVariables,
    PlanState& aPlanState) 
{
  std::vector<LetVarIter_t>::const_iterator letIter;

  for (letIter = aLetVariables.begin();
       letIter != aLetVariables.end();
       ++letIter) 
  {
    store::Iterator_t iter = aTmpSeq->getIterator();
    iter->open();
    (*letIter)->bind(iter, aPlanState);
  }
}


}/* namespace gflwor */
} /* namespace zorba */
#endif  /* ZORBA_RUNTIME_GFLWOR_COMMON_BINDING */

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
