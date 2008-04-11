#include "functions/external_function_adapters.h"
#include "runtime/core/fncall_iterator.h"

namespace zorba {

stateless_external_function_adapter::stateless_external_function_adapter
(const signature& sig, StatelessExternalFunction *function, bool aIsUpdating)
: external_function(sig),
  m_function(function),
  theUpdateType((aIsUpdating ? UPDATE_EXPR : SIMPLE_EXPR))
{
}

stateless_external_function_adapter::~stateless_external_function_adapter()
{
}

PlanIter_t stateless_external_function_adapter::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
    return new StatelessExtFunctionCallIterator(loc, argv, m_function, isUpdating());
}

}
