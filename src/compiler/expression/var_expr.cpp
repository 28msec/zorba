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
#include "stdafx.h"

#include "functions/udf.h"

#include "compiler/expression/var_expr.h"
#include "compiler/expression/update_exprs.h"
#include "compiler/expression/flwor_expr.h"
#include "compiler/expression/expr_visitor.h"
#include "compiler/api/compilercb.h"

#include "types/typeops.h"

#include "context/static_context.h"

#include "diagnostics/assert.h"


namespace zorba
{


/*******************************************************************************

********************************************************************************/
std::string var_expr::decode_var_kind(enum var_kind k)
{
  switch (k)
  {
  case for_var: return "FOR"; break;
  case let_var: return "LET"; break;
  case win_var: return "WIN"; break;
  case pos_var: return "POS"; break;
  case wincond_out_var: return "WINCOND"; break;
  case wincond_in_var: return "WINCOND IN"; break;
  case wincond_out_pos_var: return "WINCOND POS"; break;
  case wincond_in_pos_var: return "WINCOND IN POS"; break;
  case count_var: return "CNT"; break;
  case score_var: return "SCORE"; break;
  case prolog_var: return "PROLOG"; break;
  case local_var: return "LOCAL"; break;
  case catch_var: return "CATCH"; break;
  case copy_var: return "COPY"; break;
  case groupby_var: return "GROUPBY"; break;
  case non_groupby_var: return "NON-GROUPBY"; break;
  case arg_var: return "ARG"; break;
  case eval_var: return "EVAL"; break;
  default: return "???";
  }
}


/*******************************************************************************

********************************************************************************/
var_expr::var_expr(
    CompilerCB* ccb,
    static_context* sctx,
    const QueryLoc& loc,
    var_kind k,
    store::Item* name)
  :
  expr(ccb, sctx, loc, var_expr_kind),
  theUniqueId(0),
  theVarKind(k),
  theName(name),
  theDeclaredType(NULL),
  theFlworClause(NULL),
  theCopyClause(NULL),
  theParamPos(0),
  theUDF(NULL),
  theVarInfo(NULL),
  theIsExternal(false),
  theIsPrivate(false),
  theIsMutable(true),
  theHasInitializer(false)
{
  compute_scripting_kind();

  setUnfoldable(ANNOTATION_TRUE_FIXED);
}


/*******************************************************************************

********************************************************************************/
var_expr::var_expr(const var_expr& source)
  :
  expr(source),
  theUniqueId(0),
  theVarKind(source.theVarKind),
  theName(source.theName),
  theDeclaredType(source.theDeclaredType),
  theFlworClause(NULL),
  theCopyClause(NULL),
  theParamPos(source.theParamPos),
  theUDF(source.theUDF),
  theVarInfo(NULL),
  theIsExternal(source.theIsExternal),
  theIsPrivate(source.theIsPrivate),
  theIsMutable(source.theIsMutable),
  theHasInitializer(source.theHasInitializer)
{
}


/*******************************************************************************

********************************************************************************/
var_expr::~var_expr()
{
  if (theVarInfo)
  {
    assert(theVarKind == prolog_var);
    theVarInfo->clearVar();
  }
}


/*******************************************************************************

********************************************************************************/
void var_expr::set_var_info(VarInfo* v)
{
  assert(theVarInfo == NULL);
  theVarInfo = v;
}


/*******************************************************************************

********************************************************************************/
store::Item* var_expr::get_name() const
{
  return theName.getp();
}


/*******************************************************************************

********************************************************************************/
void var_expr::set_unique_id(ulong v)
{
  assert(theUniqueId == 0);

  theUniqueId = v;

  if (theVarInfo)
  {
    assert(theVarKind == prolog_var);
    theVarInfo->setId(v);
  }
}


/*******************************************************************************

********************************************************************************/
void var_expr::set_external(bool v)
{
  assert(theVarKind == prolog_var);
  theIsExternal = v;

  if (theVarInfo)
  {
    assert(theVarKind == prolog_var);
    theVarInfo->setIsExternal(v);
  }
}


/*******************************************************************************

********************************************************************************/
void var_expr::set_has_initializer(bool v)
{
  theHasInitializer = v;

  if (theVarInfo)
  {
    assert(theVarKind == prolog_var);
    theVarInfo->setHasInitializer(v);
  }
}


/*******************************************************************************

********************************************************************************/
void var_expr::set_type(xqtref_t t)
{
  theDeclaredType = t;

  if (theVarInfo)
  {
    assert(theVarKind == prolog_var);
    theVarInfo->setType(t);
  }
}


/*******************************************************************************

********************************************************************************/
xqtref_t var_expr::get_type() const
{
  return theDeclaredType;
}


/*******************************************************************************

********************************************************************************/
const var_expr* var_expr::get_pos_var() const
{
  if (theVarKind == for_var)
  {
    return reinterpret_cast<for_clause*>(theFlworClause)->get_pos_var();
  }
  else
  {
    return NULL;
  }
}


/*******************************************************************************

********************************************************************************/
expr* var_expr::get_domain_expr() const
{
  if (theFlworClause)
  {
    if (theVarKind == for_var ||
        theVarKind == let_var ||
        theVarKind == win_var ||
        theVarKind == wincond_in_var ||
        theVarKind == wincond_out_var)
    {
      return reinterpret_cast<forletwin_clause*>(theFlworClause)->get_expr();
    }
    else if (theVarKind == groupby_var)
    {
      return reinterpret_cast<group_clause*>(theFlworClause)->
             get_input_for_group_var(this);
    }
    else if (theVarKind == non_groupby_var)
    {
      return reinterpret_cast<group_clause*>(theFlworClause)->
             get_input_for_nongroup_var(this);
    }
  }
  else if (theCopyClause)
  {
    return theCopyClause->getExpr();
  }

  return NULL;
}


/*******************************************************************************

********************************************************************************/
forletwin_clause* var_expr::get_forletwin_clause() const
{
  return dynamic_cast<forletwin_clause*>(theFlworClause);
}


/*******************************************************************************

********************************************************************************/
for_clause* var_expr::get_for_clause() const
{
  return dynamic_cast<for_clause*>(theFlworClause);
}


/*******************************************************************************

********************************************************************************/
void var_expr::remove_set_expr(expr* e)
{
  assert(theVarKind == local_var || theVarKind == prolog_var);

  bool found = false;
  std::vector<expr*>::iterator ite = theSetExprs.begin();
  std::vector<expr*>::iterator end = theSetExprs.end();
  for (; ite != end; ++ite)
  {
    if (*ite == e)
    {
      theSetExprs.erase(ite);
      found = true;
      break;
    }
  }

  ZORBA_ASSERT(found);
}


/*******************************************************************************

********************************************************************************/
bool var_expr::is_context_item() const
{
  return theName->getLocalName() == ".";
}


/*******************************************************************************

********************************************************************************/
void var_expr::compute_scripting_kind()
{
  theScriptingKind = SIMPLE_EXPR;
}


/*******************************************************************************

********************************************************************************/
expr* var_expr::clone(expr::substitution_t& subst) const
{
  expr::subst_iter_t i = subst.find(this);

  if (i == subst.end())
    return const_cast<var_expr*>(this);

  return i->second;
}


/*******************************************************************************

********************************************************************************/
void var_expr::accept(expr_visitor& v)
{
  if (v.begin_visit(*this))
    accept_children(v);

  v.end_visit(*this);
}


}

/* vim:set et sw=2 ts=2: */
