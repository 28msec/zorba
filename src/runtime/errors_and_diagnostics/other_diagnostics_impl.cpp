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
#include "stdafx.h"

#include "runtime/errors_and_diagnostics/other_diagnostics.h"

#include <iostream>

#include "api/serialization/serializer.h"
#include "context/static_context.h"
#include "compiler/api/compilercb.h"
#include "runtime/util/iterator_impl.h"
#include "store/api/item.h"
#include "store/api/item_factory.h"
#include "system/globalenv.h"

#include "diagnostics/xquery_diagnostics.h"
#include "diagnostics/xquery_stack_trace.h"

namespace zorba {

/*******************************************************************************
  Diagnostics iterators: a dummy iterator for dynamic exception stack traces
********************************************************************************/
bool FunctionTraceIterator::nextImpl(store::Item_t &result, PlanState &aPlanState) const
{
  try {
    PlanIteratorState* lState = 0;
    DEFAULT_STACK_INIT(PlanIteratorState, lState, aPlanState);
    while (consumeNext(result, theChildren[0], aPlanState)) {
      STACK_PUSH(true, lState);
    }
    STACK_END(lState);
  } catch (ZorbaException& err) {
    recordStackTrace(
        theFunctionLocation,
        theFunctionCallLocation,
        theFunctionName,
        theFunctionArity,
        err);
    throw;
  }
  // never reached because either STACK_PUSH or STACK_END return a bool
  // or record_stack_trace raises an error
  return false;
}

void FunctionTraceIterator::setFunctionName(const store::Item_t& aFunctionName)
{
  theFunctionName = aFunctionName;
}

void FunctionTraceIterator::setFunctionLocation(const QueryLoc &aFunctionLocation)
{
  theFunctionLocation = aFunctionLocation;
}

void FunctionTraceIterator::setFunctionCallLocation(const QueryLoc &aFunctionLocation)
{
  theFunctionCallLocation = aFunctionLocation;
}

void FunctionTraceIterator::setFunctionArity(unsigned int arity)
{
  theFunctionArity = arity;
}

/*******************************************************************************
  Diagnostics iterators: read-line
********************************************************************************/
bool
ReadLineIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState *state;
  zstring zstr;
  char str [512];
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  std::cin.getline (str, sizeof (str));

  zstr = str;
  GENV_ITEMFACTORY->createString(result, zstr);

  STACK_PUSH(true, state);
  STACK_END(state);
}

/*******************************************************************************
  Diagnostics iterators: print
********************************************************************************/
// TODO: This print iterator has to be removed and the classes that need
// to be serialized have to implement the zorba:intern::Serializable
// interface.
bool PrintIterator::nextImpl (store::Item_t& result, PlanState& planState) const
{
  std::ostringstream os;
  serializer* lSerializer = NULL;
  store::Item_t item;
  zstring resString;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  while (CONSUME (item, theChildren.size () - 1))
  {
    if (item->isNode())
    {
      if (lSerializer == NULL)
      {
        lSerializer = new serializer(planState.theCompilerCB->theXQueryDiagnostics);
        lSerializer->setParameter("omit-xml-declaration", "yes");
      }

      // TODO: This print iterator has to be removed and the classes that need
      // to be serialized have to implement the zorba:intern::Serializable
      // interface.
      if (thePrintToConsole) {
        // lSerializer->serialize(item.getp(), std::cout);
      } else {
        // lSerializer->serialize(item.getp(), os);
      }
    }
    else
    {
      if (thePrintToConsole) {
          std::cout << item->getStringValue ();
      } else {
        os << item->getStringValue();
      }
    }
  }

  if (!thePrintToConsole) 
  {
    resString = os.str();
    STACK_PUSH(GENV_ITEMFACTORY->createString(result, resString) , state);
  }
  STACK_END (state);
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
