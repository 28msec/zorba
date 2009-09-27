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
#ifndef ZORBA_RUNTIME_VALUE_INDEX_BUILDER
#define ZORBA_RUNTIME_VALUE_INDEX_BUILDER

#include "runtime/base/unarybase.h"
#include "runtime/base/narybase.h"


namespace zorba 
{

class ValueIndexInsertSession;

typedef rchandle<ValueIndexInsertSession> ValueIndexInsertSession_t;


/***************************************************************************//**
  Implements the "create index <uri>" expr. It creates the index in the store
  without populating. It returns the empty sequence.
********************************************************************************/
UNARY_ITER(CreateValueIndex);


/***************************************************************************//**
  Implements the "drop index <uri>" expr. It removes the index from the store.
  It returns the empty sequence.
********************************************************************************/
UNARY_ITER(DropValueIndex);


/***************************************************************************//**

********************************************************************************/
UNARY_ITER(ValueIndexInsertSessionOpener);


/***************************************************************************//**

********************************************************************************/
UNARY_ITER(ValueIndexInsertSessionCloser);


/***************************************************************************//**

********************************************************************************/
class ValueIndexBuilderState : public PlanIteratorState 
{
public:
  ValueIndexInsertSession_t theSession;
  store::Item_t             theIndexQname;

  void init(PlanState&);
  void reset(PlanState&);
};


NARY_ITER_STATE(ValueIndexBuilder, ValueIndexBuilderState);

}

#endif /* ZORBA_VALUE_INDEX_BUILDER_H */
/* vim:set ts=2 sw=2: */

/*
 * Local variables:
 * mode: c++
 * End:
 */
