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
#ifndef ZORBA_VALUE_INDEX_H
#define ZORBA_VALUE_INDEX_H

#include "common/shared_types.h"
#include "zorbatypes/rchandle.h"
#include "compiler/expression/expr.h"
#include "compiler/expression/var_expr.h"
#include "store/api/index.h"

namespace zorba {

typedef rchandle<var_expr> var_expr_t;

class ValueIndex : public RCObject {
  public:
    ValueIndex(static_context *sCtx, xqpStringStore_t indexUri)
      : m_static_context(sCtx),
      m_index_uri(indexUri) { }
    ~ValueIndex();

    static_context *getStaticContext() const { return m_static_context; }
    xqpStringStore_t getIndexUri() const { return m_index_uri; }

    store::Index_t getStoreIndex() const { return m_store_index; }
    void setStoreIndex(store::Index_t storeIndex) { m_store_index = storeIndex; }

    expr_t getDomainExpression() const { return m_domain_expr; }
    void setDomainExpression(expr_t domainExpr) { m_domain_expr = domainExpr; }

    var_expr_t getDomainVariable() const { return m_domain_var; }
    void setDomainVariable(var_expr_t domainVar) { m_domain_var = domainVar; }

    const std::vector<expr_t>& getIndexFieldExpressions() const { return m_index_field_exprs; }
    void setIndexFieldExpressions(const std::vector<expr_t>& indexFieldExprs) { m_index_field_exprs = indexFieldExprs; }

    const std::vector<xqtref_t>& getIndexFieldTypes() const { return m_index_field_types; }
    void setIndexFieldTypes(const std::vector<xqtref_t>& indexFieldTypes) { m_index_field_types = indexFieldTypes; }

    void startBulkInsertSession();

    void commitBulkInsertSession();

    void abortBulkInsertSession();

    store::IndexEntryReceiver_t& getBulkInsertSession() { return m_bulkInsertSession; }

  private:
    static_context *m_static_context;
    xqpStringStore_t m_index_uri;
    store::Index_t m_store_index;
    expr_t m_domain_expr;
    var_expr_t m_domain_var;
    std::vector<expr_t> m_index_field_exprs;
    std::vector<xqtref_t> m_index_field_types;
    store::IndexEntryReceiver_t m_bulkInsertSession;
};

typedef rchandle<ValueIndex> ValueIndex_t;

}

#endif /* ZORBA_VALUE_INDEX_H */
/* vim:set ts=2 sw=2: */
