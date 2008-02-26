#include "functions/external_function_adapters.h"
#include "runtime/core/fncall_iterator.h"

namespace xqp {

stateless_external_function_adapter::stateless_external_function_adapter(const signature& sig, StatelessExternalFunction *function)
    : external_function(sig),
    m_function(function)
{
}

stateless_external_function_adapter::~stateless_external_function_adapter()
{
}

PlanIter_t stateless_external_function_adapter::operator()(const QueryLoc& loc, std::vector<PlanIter_t>& argv) const
{
    return new StatelessExtFunctionCallIterator(loc, argv, m_function);
}

xqtref_t stateless_external_function_adapter::type_check(signature& s) const
{
    return sig.return_type();
}

bool stateless_external_function_adapter::validate_args(std::vector<PlanIter_t>& argv) const
{
    return argv.size() == sig.arg_count();
}

}
