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
    const store::Item_t& name)
  :
  theName(name),
  theIsUnique(false),
  theIsTemp(false),
  theMethod(HASH),
  theDomainClause(new for_clause(sctx, loc, NULL, NULL))
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
  ar & theName;
  ar & theIsUnique;
  ar & theIsTemp;
  SERIALIZE_ENUM(index_method_t, theMethod);
  ar & theDomainClause;
  ar & theKeyExprs;
  ar & theKeyTypes;
  ar & theKeyCollations;
  ar & m_creatorPatterns;
}


ValueIndex::~ValueIndex()
{
}


const store::Item* ValueIndex::getName() const
{
  return theName.getp();
}


expr_t ValueIndex::getDomainExpression() const 
{
  return theDomainClause->get_expr();
}


void ValueIndex::setDomainExpression(expr_t domainExpr) 
{
  theDomainClause->set_expr(domainExpr);
}


var_expr_t ValueIndex::getDomainVariable() const 
{
  return theDomainClause->get_var();
}


void ValueIndex::setDomainVariable(var_expr_t domainVar)
{
  theDomainClause->set_var(domainVar);
}


var_expr_t ValueIndex::getDomainPositionVariable() const 
{
  return theDomainClause->get_pos_var();
}


void ValueIndex::setDomainPositionVariable(var_expr_t domainPosVar) 
{
  theDomainClause->set_pos_var(domainPosVar);
}


const std::vector<expr_t>& ValueIndex::getKeyExpressions() const 
{
  return theKeyExprs; 
}


void ValueIndex::setKeyExpressions(const std::vector<expr_t>& keyExprs) 
{
  theKeyExprs = keyExprs;
}


const std::vector<xqtref_t>& ValueIndex::getKeyTypes() const 
{
  return theKeyTypes; 
}


void ValueIndex::setKeyTypes(const std::vector<xqtref_t>& keyTypes) 
{
  theKeyTypes = keyTypes;
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
