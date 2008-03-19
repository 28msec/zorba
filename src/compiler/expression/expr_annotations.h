#ifndef ZORBA_EXPR_ANNOTATIONS_H
#define ZORBA_EXPR_ANNOTATIONS_H

#include <set>
#include "compiler/expression/expr.h"

namespace zorba {

class ExpressionPropertyComputer {
  public:
    bool returnsDuplicateNodes(expr *e);
    bool returnsAncestorNodes(expr *e);
    bool returnsDescendantNodes(expr *e);
};

class SourceFinder {
  public:
    typedef std::set<expr *> sources_t;

    SourceFinder() { }
    ~SourceFinder() { }

    void reset() { m_sources.clear(); }
    void findSources(expr *e);
    const sources_t& getSources() const;

  private:
    sources_t m_sources;

    void findSourcesInChildren(expr *e);
};

}

#endif /* ZORBA_EXPR_ANNOTATIONS_H */
/* vim:set ts=2 sw=2: */
