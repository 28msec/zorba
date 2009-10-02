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

#include "compiler/api/compilercb.h"
#include "compiler/expression/flwor_expr.h"
#include "compiler/expression/expr.h"
#include "compiler/codegen/plan_visitor.h"

#include "runtime/base/plan_iterator.h"

namespace zorba 
{

#define LOOKUP_OPN( local ) \
(GENV.getRootStaticContext ().lookup_builtin_fn (":" local, VARIADIC_SIG_SIZE))


SERIALIZABLE_CLASS_VERSIONS(ValueIndex)
END_SERIALIZABLE_CLASS_VERSIONS(ValueIndex)


ValueIndex::ValueIndex(
    CompilerCB* ccb,
    const QueryLoc& loc,
    const store::Item_t& name)
  :
  theSctx(ccb->m_sctx),
  theName(name),
  theIsUnique(false),
  theIsTemp(false),
  theMethod(HASH),
  theDomainClause(new for_clause(ccb->m_cur_sctx, loc, NULL, NULL))
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
  ar & theSctx;
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


store::Item* ValueIndex::getName() const
{
  return theName.getp();
}


expr_t ValueIndex::getDomainExpr() const 
{
  return theDomainClause->get_expr();
}


void ValueIndex::setDomainExpr(expr_t domainExpr) 
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


expr* ValueIndex::getBuildExpr(CompilerCB* topCCB, const QueryLoc& loc)
{ 
  if (theBuildExpr != NULL)
    return theBuildExpr.getp();

  expr* domainExpr = getDomainExpr();
  var_expr_t dot = getDomainVariable();
  var_expr_t pos = getDomainPositionVariable();

  short sctxid = domainExpr->get_cur_sctx();

  flwor_expr::clause_list_t clauses;

  //
  // Create FOR clause:
  // for $$dot at $$pos in domain_expr
  //
  expr::substitution_t subst;
  
  expr_t newdom = domainExpr->clone(subst);
  
  var_expr_t newdot = new var_expr(sctxid,
                                   dot->get_loc(),
                                   dot->get_kind(),
                                   dot->get_varname());
  var_expr_t newpos = new var_expr(sctxid,
                                   pos->get_loc(),
                                   pos->get_kind(),
                                   pos->get_varname());
  subst[dot] = newdot;
  subst[pos] = newpos;

  for_clause* fc = new for_clause(sctxid,
                                  dot->get_loc(),
                                  newdot,
                                  newdom,
                                  newpos);
  newdot->set_flwor_clause(fc);
  newpos->set_flwor_clause(fc);
  
  clauses.push_back(fc);

  //
  // Create RETURN clause:
  // return concat($$dot, field1_expr, ..., fieldN_expr)
  //
  rchandle<fo_expr> returnExpr = fo_expr::create_seq(sctxid, loc);

  expr_t domainVarExpr(new wrapper_expr(sctxid, loc, newdot.getp()));
  returnExpr->add(domainVarExpr);
  
  ulong n = theKeyExprs.size();
  for(ulong i = 0; i < n; ++i) 
  {
    returnExpr->add(theKeyExprs[i]->clone(subst));
  }
  
  //
  // Create flwor_expr with the above FOR and RETURN clauses.
  //
  flwor_expr* flworExpr = new flwor_expr(sctxid, loc, false);
  theBuildExpr = flworExpr;
  flworExpr->set_return_expr(returnExpr);
  for (unsigned i = 0; i < clauses.size(); ++i)
  {
    flworExpr->add_clause(clauses[i]);
  }

  std::string msg = "build expr for index " + theName->getStringValue()->str();

  if (topCCB->m_config.optimize_cb != NULL)
    topCCB->m_config.optimize_cb(theBuildExpr.getp(), msg);

  return theBuildExpr.getp();
}


PlanIterator* ValueIndex::getBuildPlan(CompilerCB* topCCB, const QueryLoc& loc)
{ 
  if (theBuildPlan != NULL)
    return theBuildPlan.getp();

  expr* buildExpr = getBuildExpr(topCCB, loc);

  theBuildPlan = codegen("index", buildExpr, topCCB);

  return theBuildPlan.getp();
}


}
/* vim:set ts=2 sw=2: */
