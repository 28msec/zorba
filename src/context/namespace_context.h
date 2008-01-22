#ifndef XQP_NAMESPACE_CONTEXT_H
#define XQP_NAMESPACE_CONTEXT_H

#include <string>
#include "util/rchandle.h"
#include "util/hashmap.h"
#include "types/representations.h"

namespace xqp {

class static_context;

class namespace_context : public rcobject {
  public:
    namespace_context(static_context *sctx)
      : m_sctx(sctx) { }
    namespace_context(rchandle<namespace_context> parent)
      : m_parent(parent) { }

    rchandle<namespace_context> get_parent() { return m_parent; }

    xqp_string lookup_ns(const std::string& prefix) const;
    void bind_ns(const std::string& prefix, xqp_string ns);

  private:
    static_context *m_sctx;
    rchandle<namespace_context> m_parent;
    hashmap<xqp_string> m_namespace_map;
};

}

#endif /* XQP_NAMESPACE_CONTEXT_H */
/* vim:set ts=2 sw=2: */
