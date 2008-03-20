/**
 *
 * @copyright
 * ========================================================================
 *  Copyright 2007 FLWOR Foundation
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *  
 *    http://www.apache.org/licenses/LICENSE-2.0
 *  
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 * ========================================================================
 *
 * @author Tim Kraska (tim.kraska@inf.ethz.ch), David Graf (dagraf@inf.ethz.ch)
 * @file runtime/core/batching.h
 *
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
PlanState::PlanState(uint32_t blockSize)
  : theRuntimeCB(0)
{
  theBlockSize = blockSize;
  theBlock = new int8_t[theBlockSize];
}

static_context*
PlanState::sctx() { return theCompilerCB->m_sctx; }

dynamic_context*
PlanState::dctx() { return theRuntimeCB->theDynamicContext; }

CollationCache*
PlanState::collationCache() { return sctx()->get_collation_cache(); }

PlanState::~PlanState()
{
  delete[] theBlock; theBlock = 0;
}

}
