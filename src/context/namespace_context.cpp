#include <context/namespace_context.h>
#include <context/static_context.h>

namespace xqp {

xqp_string namespace_context::lookup_ns(const std::string& prefix) const
{
  xqp_string ns;
  const namespace_context *nsctx = this;
  do {
    if (nsctx->m_namespace_map.get(prefix, ns)) {
      return ns;
    }
    if (m_parent == NULL) {
      return nsctx->m_sctx->lookup_ns(prefix);
    }
    nsctx = m_parent.get_ptr();
  } while(true);
}

void namespace_context::bind_ns(const std::string& prefix, xqp_string ns)
{
  m_namespace_map.put(prefix, ns);
}

}
/* vim:set ts=2 sw=2: */
