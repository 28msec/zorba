/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef ZORBA_EXPR_ANNOTATIONS_H
#define ZORBA_EXPR_ANNOTATIONS_H

#include <set>
#include "compiler/expression/expr_base.h"

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
