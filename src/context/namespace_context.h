#ifndef ZORBA_NAMESPACE_CONTEXT_H
#define ZORBA_NAMESPACE_CONTEXT_H

#include <string>
#include <vector>

#include "zorbatypes/representations.h"

#include "util/rchandle.h"

namespace zorba {

class static_context;
class namespace_context;

typedef rchandle<namespace_context> NamespaceContext_t;

class namespace_context : public SimpleRCObject {
  public:
    typedef std::vector<std::pair<xqp_string, xqp_string> > bindings_t;

    namespace_context(static_context *sctx)
      : m_sctx(sctx) { }
    namespace_context(rchandle<namespace_context> parent)
      : m_parent(parent) { }

    rchandle<namespace_context> get_parent() const { return m_parent; }
    static_context *get_context() const { return m_sctx; }

    void bind_ns(xqp_string prefix, xqp_string ns);
    const bindings_t& get_bindings() const { return m_bindings; }
    bool findBinding(xqp_string aPrefix, xqp_string &aNamespace);

  private:
    static_context *m_sctx;
    rchandle<namespace_context> m_parent;
    bindings_t m_bindings;
};

}

#endif /* ZORBA_NAMESPACE_CONTEXT_H */
/* vim:set ts=2 sw=2: */
