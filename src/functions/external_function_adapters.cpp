#include "functions/external_function_adapters.h"
#include "runtime/core/fncall_iterator.h"

namespace zorba {

stateless_external_function_adapter::stateless_external_function_adapter(const signature& sig, StatelessExternalFunction *function)
    : external_function(sig),
    m_function(function)
{
}

stateless_external_function_adapter::~stateless_external_function_adapter()
{
}

PlanIter_t stateless_external_function_adapter::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
    return new StatelessExtFunctionCallIterator(loc, argv, m_function);
}

}
