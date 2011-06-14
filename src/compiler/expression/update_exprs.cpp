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

#include "compiler/expression/update_exprs.h"
#include "compiler/expression/var_expr.h"
#include "compiler/expression/expr_visitor.h"

#include "diagnostics/assert.h"

namespace zorba 
{


SERIALIZABLE_CLASS_VERSIONS(insert_expr)
END_SERIALIZABLE_CLASS_VERSIONS(insert_expr)

SERIALIZABLE_CLASS_VERSIONS(delete_expr)
END_SERIALIZABLE_CLASS_VERSIONS(delete_expr)

SERIALIZABLE_CLASS_VERSIONS(replace_expr)
END_SERIALIZABLE_CLASS_VERSIONS(replace_expr)

SERIALIZABLE_CLASS_VERSIONS(rename_expr)
END_SERIALIZABLE_CLASS_VERSIONS(rename_expr)

SERIALIZABLE_CLASS_VERSIONS(copy_clause)
END_SERIALIZABLE_CLASS_VERSIONS(copy_clause)

SERIALIZABLE_CLASS_VERSIONS(transform_expr)
END_SERIALIZABLE_CLASS_VERSIONS(transform_expr)


DEF_EXPR_ACCEPT (insert_expr)
DEF_EXPR_ACCEPT (delete_expr)
DEF_EXPR_ACCEPT (rename_expr)
DEF_EXPR_ACCEPT (replace_expr)
DEF_EXPR_ACCEPT (transform_expr)


/*******************************************************************************

********************************************************************************/
insert_expr::insert_expr(
    static_context* sctx,
    const QueryLoc& loc,
    store::UpdateConsts::InsertType aType,
    expr_t aSourceExpr,
    expr_t aTargetExpr)
  :
	expr(sctx, loc, insert_expr_kind),
  theType(aType),
	theSourceExpr(aSourceExpr),
	theTargetExpr(aTargetExpr)
{
  compute_scripting_kind();
}


void insert_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (expr*)this);
  SERIALIZE_ENUM(store::UpdateConsts::InsertType, theType);
  ar & theSourceExpr;
  ar & theTargetExpr;
}


void insert_expr::compute_scripting_kind()
{
  theScriptingKind = UPDATING_EXPR;

  checkSimpleExpr(theSourceExpr);
  checkSimpleExpr(theTargetExpr);
}


expr_t insert_expr::clone(substitution_t& subst) const
{
  return new insert_expr(theSctx,
                         get_loc(),
                         getType(),
                         getSourceExpr()->clone(subst),
                         getTargetExpr()->clone(subst));
}


/*******************************************************************************

********************************************************************************/
delete_expr::delete_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr_t aTargetExpr)
  :
	expr(sctx, loc, delete_expr_kind),
	theTargetExpr(aTargetExpr)
{
  compute_scripting_kind();
}


void delete_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (expr*)this);
  ar & theTargetExpr;
}

void delete_expr::compute_scripting_kind()
{
  theScriptingKind = UPDATING_EXPR;

  checkSimpleExpr(theTargetExpr);
}


expr_t delete_expr::clone (substitution_t& subst) const
{
  return new delete_expr(theSctx, get_loc(), getTargetExpr()->clone(subst));
}


/*******************************************************************************

********************************************************************************/
replace_expr::replace_expr(
    static_context* sctx,
    const QueryLoc& loc,
    store::UpdateConsts::ReplaceType aType,
    expr_t aTargetExpr,
    expr_t aReplaceExpr)
  :
	expr(sctx, loc, replace_expr_kind),
  theType(aType),
	theTargetExpr(aTargetExpr),
	theReplaceExpr(aReplaceExpr)
{
  compute_scripting_kind();
}


void replace_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (expr*)this);
  SERIALIZE_ENUM(store::UpdateConsts::ReplaceType, theType);
  ar & theTargetExpr;
  ar & theReplaceExpr;
}


void replace_expr::compute_scripting_kind()
{
  theScriptingKind = UPDATING_EXPR;

  checkSimpleExpr(theTargetExpr);
  checkSimpleExpr(theReplaceExpr);
}


expr_t replace_expr::clone(substitution_t& subst) const
{
  return new replace_expr(theSctx,
                          get_loc(),
                          getType(),
                          getTargetExpr()->clone(subst),
                          getReplaceExpr()->clone(subst));
}


/*******************************************************************************

********************************************************************************/
rename_expr::rename_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr_t aTargetExpr,
    expr_t aNameExpr)
  :
	expr(sctx, loc, rename_expr_kind),
	theTargetExpr(aTargetExpr),
	theNameExpr(aNameExpr)
{
  compute_scripting_kind();
}


void rename_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (expr*)this);
  ar & theTargetExpr;
  ar & theNameExpr;
}


void rename_expr::compute_scripting_kind()
{
  theScriptingKind = UPDATING_EXPR;

  checkSimpleExpr(theTargetExpr);
  checkSimpleExpr(theNameExpr);
}


expr_t rename_expr::clone(substitution_t& subst) const
{
  return new rename_expr(theSctx,
                         get_loc(),
                         getTargetExpr()->clone(subst),
                         getNameExpr()->clone(subst));
}


/*******************************************************************************

********************************************************************************/
copy_clause::copy_clause(var_expr_t aVar, expr_t aExpr)
  :
  theVar(aVar),
  theExpr(aExpr)
{
  theVar->set_copy_clause(this);
}


copy_clause::~copy_clause()
{
  if(theVar)
    theVar->set_copy_clause(NULL);
}


void copy_clause::serialize(::zorba::serialization::Archiver& ar)
{
  ar & theVar;
  ar & theExpr;
}


copy_clause_t copy_clause::clone(expr::substitution_t& subst) const 
{
  ZORBA_ASSERT(theVar && theExpr);
  return new copy_clause(static_cast<var_expr*>(theVar->clone(subst).getp()), 
                         theExpr->clone(subst));   
}


transform_expr::transform_expr(
    static_context* sctx,
	  const QueryLoc& loc)
  :
	expr(sctx, loc, transform_expr_kind)
{
  theScriptingKind = SIMPLE_EXPR;
}


void transform_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (expr*)this);
  ar & theCopyClauses;
  ar & theModifyExpr;
  ar & theReturnExpr;
}


void transform_expr::setModifyExpr(expr* e) 
{
  theModifyExpr = e;

  if (! theModifyExpr->is_updating_or_vacuous())
  {
    throw XQUERY_EXCEPTION(err::XUST0002,
                           ERROR_PARAMS(ZED(XUST0002_Transform)),
                           ERROR_LOC(theModifyExpr->get_loc()));
  }
}


void transform_expr::setReturnExpr(expr* e)
{
  theReturnExpr = e;

  checkNonUpdating(theReturnExpr);

  theScriptingKind = theReturnExpr->get_scripting_detail();

  theScriptingKind &= ~VACUOUS_EXPR;
}


void transform_expr::add_back(copy_clause_t c)
{
  theCopyClauses.push_back(c);

  checkNonUpdating(c->getExpr());
}


void transform_expr::compute_scripting_kind()
{
  ZORBA_ASSERT(false);
}


expr_t transform_expr::clone(substitution_t& subst) const 
{
  ZORBA_ASSERT(theModifyExpr && theReturnExpr);

  rchandle<transform_expr> cloneExpr(new transform_expr(theSctx, get_loc()));

  cloneExpr->setModifyExpr(theModifyExpr->clone(subst));
  cloneExpr->setReturnExpr(theReturnExpr->clone(subst));

  for (std::vector<copy_clause_t>::const_iterator lIter = theCopyClauses.begin();
       lIter != theCopyClauses.end();
       ++lIter) 
  {
    cloneExpr->add_back((*lIter)->clone(subst));
  }

  return cloneExpr.getp();
}


} /* namespace zorba */
