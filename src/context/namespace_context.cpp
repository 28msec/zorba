#include <context/namespace_context.h>

namespace zorba {

void namespace_context::bind_ns(xqp_string prefix, xqp_string ns)
{
  m_bindings.push_back(std::pair<xqp_string, xqp_string>(prefix, ns));
}

}
/* vim:set ts=2 sw=2: */
