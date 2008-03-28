#include "context/namespace_context.h"
#include "context/static_context.h"

namespace zorba {

void namespace_context::bind_ns(xqp_string prefix, xqp_string ns)
{
  m_bindings.push_back(std::pair<xqp_string, xqp_string>(prefix, ns));
}

bool
namespace_context::findBinding(
    const xqp_string& aPrefix,
    xqp_string aNamespace)
{
  bindings_t::const_iterator lIter = m_bindings.begin();
  bindings_t::const_iterator lEnd = m_bindings.end();
  for (; lIter != lEnd ; ++lIter)
  {
    if ( (*lIter).first == aPrefix)
    {
      if ((*lIter).second == "")
      {
        // namespace is undeclared
        return false;
      }
      aNamespace = (*lIter).second;
      return true;
    }
  }
  if (m_parent != 0)
  {
    return m_parent->findBinding(aPrefix, aNamespace);
  } else {
    return m_sctx->lookup_elem_namespace(aPrefix, aNamespace);
  }
}

}
/* vim:set ts=2 sw=2: */
