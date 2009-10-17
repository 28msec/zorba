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
#ifndef ZORBA_RUNTIME_ACCESSORS
#define ZORBA_RUNTIME_ACCESSORS

#include "common/shared_types.h"

#include "runtime/base/unarybase.h"

namespace zorba 
{


/*******************************************************************************
  2.4 fn:data
********************************************************************************/
class FnDataIteratorState : public PlanIteratorState 
{
public:
  store::Iterator_t theTypedValueIter;

public:
  FnDataIteratorState() {}

  ~FnDataIteratorState() {}

  void init(PlanState& planState);

  void reset(PlanState& planState);
};


UNARY_ITER_STATE(FnDataIterator, FnDataIteratorState);


} /* namespace zorba */

#endif 

/* vim:set ts=2 sw=2: */

/*
 * Local variables:
 * mode: c++
 * End:
 */

