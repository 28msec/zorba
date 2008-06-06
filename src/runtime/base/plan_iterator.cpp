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
#include "runtime/base/plan_iterator.h"
#include "runtime/api/runtimecb.h"
#include "compiler/api/compilercb.h"
#include "context/static_context.h"

namespace zorba
{
/*******************************************************************************
  class PlanState
********************************************************************************/
PlanState::PlanState(uint32_t blockSize, uint32_t aStackDepth)
  :
  theBlockSize (blockSize),
  theStackDepth (aStackDepth),
  theRuntimeCB(0)
{
  theBlock = new int8_t[theBlockSize];
}


static_context*
PlanState::sctx() { return theCompilerCB->m_sctx; }


dynamic_context*
PlanState::dctx() 
{
  return theRuntimeCB->theDynamicContext; 
}


CollationCache*
PlanState::collationCache() 
{
  return sctx()->get_collation_cache(); 
}


void PlanState::checkDepth (const QueryLoc &loc) 
{
  if (theStackDepth > 256)
    ZORBA_ERROR_LOC_PARAM (XQP0019_INTERNAL_ERROR, loc, "stack overflow", "");
}


PlanState::~PlanState()
{
  delete[] theBlock; theBlock = 0;
}

}
