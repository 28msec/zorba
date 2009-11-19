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
#include <algorithm>

#include "types/typeops.h"

#include "functions/function.h"

#include "compiler/indexing/value_index.h"
#include "compiler/api/compilercb.h"
#include "compiler/expression/flwor_expr.h"
#include "compiler/expression/fo_expr.h"
#include "compiler/expression/expr.h"
#include "compiler/codegen/plan_visitor.h"

#include "runtime/base/plan_iterator.h"
#include "runtime/indexing/doc_indexer.h"

#include "store/api/item_factory.h"


namespace zorba 
{

SERIALIZABLE_CLASS_VERSIONS(ValueIndex)
END_SERIALIZABLE_CLASS_VERSIONS(ValueIndex)


/*******************************************************************************

********************************************************************************/
ValueIndex::ValueIndex(
    static_context* sctx,
    const QueryLoc& loc,
    const store::Item_t& name)
  :
  theSctx(sctx),
  theName(name),
  theIsUnique(false),
  theIsTemp(false),
  theMaintenanceMode(MANUAL),
  theContainerKind(HASH)
{ 
}
  

/*******************************************************************************

********************************************************************************/
ValueIndex::ValueIndex(::zorba::serialization::Archiver& ar)
  :
  SimpleRCObject(ar)
{
}


/*******************************************************************************

********************************************************************************/
void ValueIndex::serialize(::zorba::serialization::Archiver& ar)
{
  ar & theSctx;
  ar & theName;
  ar & theIsUnique;
  ar & theIsTemp;
  SERIALIZE_ENUM(MaintenanceMode, theMaintenanceMode);
  SERIALIZE_ENUM(ContainerKind, theContainerKind);
  ar & theDomainClause;
  ar & theKeyExprs;
  ar & theKeyTypes;
  ar & theOrderModifiers;
}


/*******************************************************************************

********************************************************************************/
ValueIndex::~ValueIndex()
{
}


/*******************************************************************************

********************************************************************************/
store::Item* ValueIndex::getName() const
{
  return theName.getp();
}


expr* ValueIndex::getDomainExpr() const 
{
  return theDomainClause->get_expr();
}


void ValueIndex::setDomainExpr(expr_t domainExpr) 
{
  if (theDomainClause == NULL)
    theDomainClause = new for_clause(NULL,
                                     domainExpr->get_sctx_id(),
                                     domainExpr->get_loc(),
                                     NULL,
                                     NULL);

  theDomainClause->set_expr(domainExpr);
}


var_expr* ValueIndex::getDomainVariable() const 
{
  return theDomainClause->get_var();
}


void ValueIndex::setDomainVariable(var_expr_t domainVar)
{
  if (theDomainClause == NULL)
    theDomainClause = new for_clause(NULL,
                                     domainVar->get_sctx_id(),
                                     domainVar->get_loc(),
                                     NULL,
                                     NULL);

  theDomainClause->set_var(domainVar);
}


var_expr* ValueIndex::getDomainPositionVariable() const 
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


const std::vector<OrderModifier>& ValueIndex::getOrderModifiers() const
{
  return theOrderModifiers;
}


void ValueIndex::setOrderModifiers(const std::vector<OrderModifier>& modifiers)
{
  theOrderModifiers = modifiers;
}


/*******************************************************************************
  Check that the doman expr 
  (a) is deterministic,
  (b) does not have any free variables,
  (c) does not reference any input functions other than dc:collection()
  (d) the arg to each dc:collection is a const qname 
********************************************************************************/
void ValueIndex::analyze()
{
  std::vector<var_expr*> varExprs;

  analyzeExprInternal(getDomainExpr(),
                      theSourceNames,
                      theDomainSourceExprs,
                      varExprs);

  varExprs.clear();

  std::vector<expr*> keySources;

  ulong numKeys = theKeyExprs.size();

  for (ulong i = 0; i < numKeys; ++i)
  {
    analyzeExprInternal(theKeyExprs[i].getp(), theSourceNames, keySources, varExprs);
  }

  if (keySources.empty() &&
      theDomainSourceExprs.size() == 1 &&
      theMaintenanceMode != MANUAL)
  {
    theMaintenanceMode = DOC_MAP;
  }
}


void ValueIndex::analyzeExprInternal(
    expr* e,
    std::vector<store::Item*>& sourceNames,
    std::vector<expr*>& sourceExprs,
    std::vector<var_expr*>& varExprs)
{
  if (e->get_expr_kind() == fo_expr_kind)
  {
    fo_expr* foExpr = static_cast<fo_expr*>(e);
    const function* func = foExpr->get_func();

    if (!func->isDeterministic())
    {
      ZORBA_ERROR_LOC_PARAM(XQP0042_INDEX_NOT_DETERMINISTIC, e->get_loc(),
                            theName->getStringValue()->c_str(), "");
    }

    if (func->isSource())
    {
      bool valid = false;

      if (func->getKind() == FunctionConsts::FN_ZORBA_COLLECTION_1)
      {
        TypeManager* tm = theSctx->get_typemanager();

        const expr* argExpr = foExpr->get_arg(0);
        const const_expr* qnameExpr = dynamic_cast<const const_expr*>(argExpr);

        if (qnameExpr != NULL)
        {
          xqtref_t valueType = tm->create_value_type(qnameExpr->get_val());

          if (TypeOps::is_subtype(*valueType, *GENV_TYPESYSTEM.QNAME_TYPE_ONE) &&
              theSctx->lookup_collection(qnameExpr->get_val()))
          {
            sourceNames.push_back(qnameExpr->get_val());
            sourceExprs.push_back(foExpr);
            valid = true;
          }
        }
        else if (argExpr->get_expr_kind() == promote_expr_kind)
        {
          // We get here if the optimizer is turned off.

          const promote_expr* promoteExpr = static_cast<const promote_expr*>(argExpr);

          argExpr = promoteExpr->get_input();
          const fo_expr* dataExpr = dynamic_cast<const fo_expr*>(argExpr);

          if (dataExpr != NULL &&
              dataExpr->get_func()->getKind() == FunctionConsts::FN_DATA_1)
          {
            argExpr = dataExpr->get_arg(0);
            const const_expr* qnameExpr = dynamic_cast<const const_expr*>(argExpr);

            if (qnameExpr != NULL)
            {
              xqtref_t valueType = tm->create_value_type(qnameExpr->get_val());

              if (TypeOps::is_subtype(*valueType, *GENV_TYPESYSTEM.QNAME_TYPE_ONE) &&
                  theSctx->lookup_collection(qnameExpr->get_val()))
              {
                sourceNames.push_back(qnameExpr->get_val());
                sourceExprs.push_back(foExpr);
                valid = true;
              }
            }
          }
        }
      }

      if (!valid)
      {
        ZORBA_ERROR_LOC_PARAM(XQP0041_INDEX_HAS_INVALID_DATA_SOURCE, e->get_loc(),
                              theName->getStringValue()->c_str(), "");
      }
    }
    else if (func->getKind() == FunctionConsts::OP_VAR_DECLARE_1)
    {
      const const_expr* qnameExpr = dynamic_cast<const const_expr*>(foExpr->get_arg(0));
      ZORBA_ASSERT(qnameExpr != NULL);
      store::Item* qname = qnameExpr->get_val();

      var_expr* varExpr = static_cast<var_expr*>(theSctx->lookup_var(qname));
      ZORBA_ASSERT(varExpr->get_kind() == var_expr::local_var);

      varExprs.push_back(varExpr);
    }
  }
  else if (e->get_expr_kind() == flwor_expr_kind ||
           e->get_expr_kind() == gflwor_expr_kind)
  {
    static_cast<const flwor_expr*>(e)->get_vars_defined(varExprs);
  }
  else if (e->get_expr_kind() == var_expr_kind)
  {
    if (e != getDomainVariable() &&
        std::find(varExprs.begin(), varExprs.end(), e) == varExprs.end())
    {
      ZORBA_ERROR_LOC_PARAM(XQP0040_INDEX_HAS_FREE_VARS, e->get_loc(),
                            theName->getStringValue()->c_str(), "");
    }
  }

  for(expr_iterator i = e->expr_begin(); !i.done(); ++i) 
  {
    analyzeExprInternal((*i), sourceNames, sourceExprs, varExprs);
  }
}



/*******************************************************************************

********************************************************************************/
expr* ValueIndex::getBuildExpr(CompilerCB* ccb, const QueryLoc& loc)
{ 
  if (theBuildExpr != NULL)
    return theBuildExpr.getp();

  expr* domainExpr = getDomainExpr();
  const var_expr* dot = getDomainVariable();
  const var_expr* pos = getDomainPositionVariable();

  short sctxid = domainExpr->get_sctx_id();

  const QueryLoc& dotloc = dot->get_loc();

  ulong numKeys = theKeyExprs.size();
  std::vector<expr_t> clonedExprs(numKeys + 1);

  //
  // Clone the domain expr.
  //
  expr::substitution_t subst;
  
  expr_t newdom = domainExpr->clone(subst);
  
  //
  // Clone the domain variable and the domain pos variable. These vars are
  // referenced by the key exprs.
  //
  var_expr_t newdot = new var_expr(sctxid, dotloc, dot->get_kind(), dot->get_name());
  var_expr_t newpos = new var_expr(sctxid, dotloc, pos->get_kind(), pos->get_name());

  //
  // Clone the key exprs, replacing their references to the 2 domain variables
  // with the clones of these variables.
  //
  subst[dot] = newdot;
  subst[pos] = newpos;

  for(ulong i = 0; i < numKeys; ++i) 
  {
    clonedExprs[i+1] = theKeyExprs[i]->clone(subst);
  }

  //
  // Create flwor expr:
  //
  // for $newdot at $newpos in new_domain_expr
  // return index-entry-builder($$newdot, new_key1_expr, ..., new_keyN_expr) 
  //

  for_clause* fc = new for_clause(NULL, sctxid, dotloc, newdot, newdom, newpos);

  expr_t domainVarExpr(new wrapper_expr(sctxid, loc, newdot.getp()));

  clonedExprs[0] = domainVarExpr;
  
 function* f = theSctx->lookup_resolved_fn(ZORBA_DDL_FN_NS,
                                           "index-entry-builder",
                                           VARIADIC_SIG_SIZE);

  fo_expr_t returnExpr =  new fo_expr(sctxid, loc, f, clonedExprs);

  flwor_expr* flworExpr = new flwor_expr(sctxid, loc, false);
  flworExpr->set_return_expr(returnExpr.getp());
  flworExpr->add_clause(fc);

  theBuildExpr = flworExpr;

  std::string msg = "build expr for index " + theName->getStringValue()->str();

  if (ccb->theConfig.optimize_cb != NULL)
    ccb->theConfig.optimize_cb(theBuildExpr.getp(), msg);

  return theBuildExpr.getp();
}


/*******************************************************************************

********************************************************************************/
PlanIterator* ValueIndex::getBuildPlan(CompilerCB* ccb, const QueryLoc& loc)
{ 
  if (theBuildPlan != NULL)
    return theBuildPlan.getp();

  expr* buildExpr = getBuildExpr(ccb, loc);

  theBuildPlan = codegen("index", buildExpr, ccb);

  return theBuildPlan.getp();
}


/*******************************************************************************

********************************************************************************/
DocIndexer* ValueIndex::getDocIndexer(CompilerCB* ccb, const QueryLoc& loc)
{ 
  if (theDocIndexer != NULL)
    return theDocIndexer.getp();

  if (theMaintenanceMode != DOC_MAP)
    return NULL;

  expr* domainExpr = getDomainExpr();
  const var_expr* dot = getDomainVariable();
  const var_expr* pos = getDomainPositionVariable();

  short sctxid = domainExpr->get_sctx_id();

  const QueryLoc& dotloc = dot->get_loc();

  ulong numKeys = theKeyExprs.size();
  std::vector<expr_t> clonedExprs(numKeys + 1);

  //
  // Clone the domain expr and replace the reference to the collection with a
  // reference to a new temp variable that will be bound to a set of docs
  // during the apply-updates.
  //
  
  std::stringstream ss;
  ss << "$$idx_temp_" << this;
  std::string varname = ss.str();
  store::Item_t qname;
  GENV_ITEMFACTORY->createQName(qname, "", "", varname.c_str());
  var_expr_t tempVar = new var_expr(sctxid, dot->get_loc(), var_expr::prolog_var, qname);
  expr_t wrapperExpr = new wrapper_expr(sctxid, dot->get_loc(), tempVar.getp());

  expr::substitution_t subst;

  subst[theDomainSourceExprs[0]] = wrapperExpr;

  expr_t newdom = domainExpr->clone(subst);

  //
  // Clone the domain variable and the domain pos variable. These vars are
  // referenced by the key exprs.
  //
  var_expr_t newdot = new var_expr(sctxid, dotloc, dot->get_kind(), dot->get_name());
  var_expr_t newpos = new var_expr(sctxid, dotloc, pos->get_kind(), pos->get_name());

  //
  // Clone the key exprs, replacing their references to the 2 domain variables
  // with the clones of these variables.
  //
  for(ulong i = 0; i < numKeys; ++i) 
  {
    subst.clear();
    subst[dot] = newdot;
    subst[pos] = newpos;

    clonedExprs[i+1] = theKeyExprs[i]->clone(subst);
  }

  //
  // Create flwor expr:
  //
  // for $newdot at $newpos in new_domain_expr
  // return index-entry-builder($$newdot, new_key1_expr, ..., new_keyN_expr) 
  //

  for_clause* fc = new for_clause(NULL, sctxid, dotloc, newdot, newdom, newpos);

  expr_t domainVarExpr = new wrapper_expr(sctxid, loc, newdot.getp());

  clonedExprs[0] = domainVarExpr;

  function* f = theSctx->lookup_resolved_fn(ZORBA_DDL_FN_NS,
                                            "index-entry-builder",
                                            VARIADIC_SIG_SIZE);
  
  fo_expr_t returnExpr =  new fo_expr(sctxid, loc, f, clonedExprs);

  flwor_expr_t flworExpr = new flwor_expr(sctxid, loc, false);
  flworExpr->set_return_expr(returnExpr.getp());
  flworExpr->add_clause(fc);

  std::string msg = "entry-creator expr for index " + theName->getStringValue()->str();

  if (ccb->theConfig.optimize_cb != NULL)
    ccb->theConfig.optimize_cb(flworExpr.getp(), msg);

  theDocIndexerExpr = flworExpr;

  //
  // Generate the runtime plan for theDocIndexerExpr
  //
  theDocIndexerPlan = codegen("doc indexer", flworExpr, ccb);

  //
  // Create theDocIndexer obj
  //
  theDocIndexer = new DocIndexer(numKeys, theDocIndexerPlan, tempVar);

  return theDocIndexer.getp();
}


std::string ValueIndex::toString()
{
  std::ostringstream os;

  os << "Index : " << theName->getStringValue()->c_str() << std::endl;

  os << "Domain Expr : " << std::endl;

  theDomainClause->get_expr()->put(os) << std::endl;

  os << "Domain Variable : ";
  getDomainVariable()->put(os);

  ulong numColumns = theKeyExprs.size();

  for (ulong i = 0; i < numColumns; ++i)
  {
    os << std::endl << "Key Expr " << i << " : " << std::endl;
    theKeyExprs[i]->put(os);
  }

  return os.str();
}


}
/* vim:set ts=2 sw=2: */
