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
#include "indexing/value_index.h"

#include "compiler/expression/flwor_expr.h"

namespace zorba 
{

SERIALIZABLE_CLASS_VERSIONS(ValueIndex)
END_SERIALIZABLE_CLASS_VERSIONS(ValueIndex)


ValueIndex::ValueIndex(
    short sctx,
    const QueryLoc& loc,
    const xqpStringStore_t& indexUri)
  :
  m_index_uri(indexUri),
  m_unique(false),
  m_temp(false),
  m_method(HASH),
  m_domain_clause(new for_clause(sctx, loc, NULL, NULL))
{ 
}
  

ValueIndex::ValueIndex(::zorba::serialization::Archiver& ar)
  :
  SimpleRCObject(ar)
{
}


void ValueIndex::serialize(::zorba::serialization::Archiver &ar)
{
  //serialize_baseclass(ar, (SimpleRCObject*)this);
  ar & m_index_uri;
  ar & m_unique;
  ar & m_temp;
  SERIALIZE_ENUM(index_method_t, m_method);
  ar & m_domain_clause;
  ar & m_index_field_exprs;
  ar & m_index_field_types;
  ar & m_index_field_collations;
  ar & m_creatorPatterns;
}


ValueIndex::~ValueIndex()
{
}


expr_t ValueIndex::getDomainExpression() const 
{
  return m_domain_clause->get_expr();
}


void ValueIndex::setDomainExpression(expr_t domainExpr) 
{
  m_domain_clause->set_expr(domainExpr);
}


var_expr_t ValueIndex::getDomainVariable() const 
{
  return m_domain_clause->get_var();
}


void ValueIndex::setDomainVariable(var_expr_t domainVar)
{
  m_domain_clause->set_var(domainVar);
}


var_expr_t ValueIndex::getDomainPositionVariable() const 
{
  return m_domain_clause->get_pos_var();
}


void ValueIndex::setDomainPositionVariable(var_expr_t domainPosVar) 
{
  m_domain_clause->set_pos_var(domainPosVar);
}


const std::vector<expr_t>& ValueIndex::getIndexFieldExpressions() const 
{
  return m_index_field_exprs; 
}


void ValueIndex::setIndexFieldExpressions(const std::vector<expr_t>& indexFieldExprs) 
{
  m_index_field_exprs = indexFieldExprs;
}


const std::vector<xqtref_t>& ValueIndex::getIndexFieldTypes() const 
{
  return m_index_field_types; 
}


void ValueIndex::setIndexFieldTypes(const std::vector<xqtref_t>& indexFieldTypes) 
{
  m_index_field_types = indexFieldTypes;
}


void ValueIndexInsertSession::commitBulkInsertSession()
{
  m_bulkInsertSession->commit();
  m_bulkInsertSession = NULL;
}


void ValueIndexInsertSession::abortBulkInsertSession()
{
  m_bulkInsertSession->abort();
  m_bulkInsertSession = NULL;
}

}
/* vim:set ts=2 sw=2: */
