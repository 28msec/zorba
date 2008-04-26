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
