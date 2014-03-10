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

#include <typeinfo>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "diagnostics/assert.h"
#include "diagnostics/util_macros.h"
#include "diagnostics/xquery_diagnostics.h"

#include "system/globalenv.h"

#include "context/static_context_consts.h"
#include "context/namespace_context.h"
#include "context/dynamic_context.h"

#include "types/root_typemanager.h"
#include "types/typeops.h"

#include "functions/library.h"

#include "compiler/expression/expr.h"
#include "compiler/expression/fo_expr.h"
#include "compiler/expression/var_expr.h"
#include "compiler/expression/expr_utils.h"
#include "compiler/expression/expr_visitor.h"
#include "compiler/parser/parse_constants.h"
#include "compiler/expression/expr_manager.h"

#include "compiler/api/compilercb.h"

#include "store/api/store.h"
#include "store/api/item_factory.h"
#include "zorbatypes/decimal.h"
#include "zorbatypes/float.h"
#include "zorbatypes/integer.h"


namespace zorba
{


/*******************************************************************************

********************************************************************************/

#ifdef ZORBA_WITH_DEBUGGER
DEF_EXPR_ACCEPT (debugger_expr)
#endif
DEF_EXPR_ACCEPT (wrapper_expr)
DEF_EXPR_ACCEPT (promote_expr)
DEF_EXPR_ACCEPT (trycatch_expr)
DEF_EXPR_ACCEPT (eval_expr)
DEF_EXPR_ACCEPT (function_trace_expr)
DEF_EXPR_ACCEPT (if_expr)
DEF_EXPR_ACCEPT (instanceof_expr)
DEF_EXPR_ACCEPT (treat_expr)
DEF_EXPR_ACCEPT (castable_expr)
DEF_EXPR_ACCEPT (cast_expr)
DEF_EXPR_ACCEPT (name_cast_expr)
DEF_EXPR_ACCEPT (validate_expr)
DEF_EXPR_ACCEPT (extension_expr)
DEF_EXPR_ACCEPT (const_expr)
DEF_EXPR_ACCEPT (order_expr)
DEF_EXPR_ACCEPT (elem_expr)
DEF_EXPR_ACCEPT (doc_expr)
DEF_EXPR_ACCEPT (text_expr)
DEF_EXPR_ACCEPT (pi_expr)


/*******************************************************************************
  [68] IfExpr ::= "if" "(" Expr ")" "then" ExprSingle "else" ExprSingle
********************************************************************************/
if_expr::if_expr(
    CompilerCB* ccb,
    static_context* sctx,
    user_function* udf,
    const QueryLoc& loc,
    expr* condExpr,
    expr* thenExpr,
    expr* elseExpr)
  :
  expr(ccb, sctx, udf, loc, if_expr_kind),
  theThenExpr(thenExpr),
  theElseExpr(elseExpr)
{
  if (sctx != NULL &&
      !TypeOps::is_equal(sctx->get_typemanager(),
                         *condExpr->get_return_type(),
                         *GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE,
                         loc))
  {
    fo_expr* boolExpr = theCCB->theEM->
    create_fo_expr(sctx,
                   udf,
                   loc,
                   BUILTIN_FUNC(FN_BOOLEAN_1),
                   condExpr);

    condExpr = boolExpr;
  }

  theCondExpr = condExpr;

  compute_scripting_kind();
}


void if_expr::compute_scripting_kind()
{
  checkNonUpdating(theCondExpr);

  theScriptingKind = UNKNOWN_SCRIPTING_KIND;

  short thenKind = theThenExpr->get_scripting_detail();
  short elseKind = theElseExpr->get_scripting_detail();

  if (theThenExpr->is_updating() || theElseExpr->is_updating())
  {
    if (theThenExpr->is_updating() && !theElseExpr->is_updating_or_vacuous())
    {
      RAISE_ERROR(err::XUST0001, get_loc(), ERROR_PARAMS(ZED(XUST0001_IF)));
    }
    else if (theElseExpr->is_updating() && !theThenExpr->is_updating_or_vacuous())
    {
      RAISE_ERROR(err::XUST0001, get_loc(), ERROR_PARAMS(ZED(XUST0001_IF)));
    }
    else
    {
      theScriptingKind = (thenKind | elseKind);
      theScriptingKind &= ~VACUOUS_EXPR;
    }
  }
  else if (theThenExpr->is_sequential() || theElseExpr->is_sequential())
  {
    theScriptingKind = (thenKind | elseKind);

    theScriptingKind &= ~SIMPLE_EXPR;
    theScriptingKind &= ~VACUOUS_EXPR;
  }
  else if (theThenExpr->is_vacuous() && theElseExpr->is_vacuous())
  {
    theScriptingKind = VACUOUS_EXPR;
  }
  else
  {
    theScriptingKind = SIMPLE_EXPR;
  }

  checkScriptingKind();
}


/***************************************************************************//**

********************************************************************************/
order_expr::order_expr(
    CompilerCB* ccb,
    static_context* sctx,
    user_function* udf,
    const QueryLoc& loc,
    DocOrderMode type,
    expr* input)
  :
  expr(ccb, sctx, udf, loc, order_expr_kind),
  theInput(input),
  theType(type)
{
  compute_scripting_kind();
}


void order_expr::compute_scripting_kind()
{
  theScriptingKind = theInput->get_scripting_detail();

  if (is_vacuous())
    theScriptingKind = SIMPLE_EXPR;
}


/***************************************************************************//**

********************************************************************************/
validate_expr::validate_expr(
    CompilerCB* ccb,
    static_context* sctx,
    user_function* udf,
    const QueryLoc& loc,
    enum ParseConstants::validation_mode_t mode,
    const store::Item_t& typeName,
    expr* input,
    rchandle<TypeManager> typemgr)
  :
  expr(ccb, sctx, udf, loc, validate_expr_kind),
  theInput(input),
  theMode(mode),
  theTypeName(typeName),
  theTypeMgr(typemgr)
{
  compute_scripting_kind();
}


void validate_expr::compute_scripting_kind()
{
  checkNonUpdating(theInput);

  theScriptingKind = theInput->get_scripting_detail();

  if (is_vacuous())
    theScriptingKind = SIMPLE_EXPR;
}



/***************************************************************************//**
  Base for expression classes that require a namespace context
********************************************************************************/
namespace_context_base_expr::namespace_context_base_expr(
    CompilerCB* ccb,
    static_context* sctx,
    user_function* udf,
    const QueryLoc& loc,
    expr_kind_t kind,
    const namespace_context* aNSCtx)
  :
  expr(ccb, sctx, udf, loc, kind),
  theNSCtx(const_cast<namespace_context*>(aNSCtx))
{
}


const namespace_context* namespace_context_base_expr::getNSCtx() const
{
  return theNSCtx.getp();
}



/*******************************************************************************
  Base for cast, treat, promote, castable, instanceof
********************************************************************************/
cast_or_castable_base_expr::cast_or_castable_base_expr(
    CompilerCB* ccb,
    static_context* sctx,
    user_function* udf,
    const QueryLoc& loc,
    expr_kind_t kind,
    expr* input,
    const xqtref_t& type)
  :
  expr(ccb, sctx, udf, loc, kind),
  theInput(input),
  theTargetType(type)
{
  assert(type != NULL);
  assert(input != NULL);

  compute_scripting_kind();
}


xqtref_t cast_or_castable_base_expr::get_target_type() const
{
  return theTargetType;
}


void cast_or_castable_base_expr::set_target_type(xqtref_t target)
{
  theTargetType = target;
}


void cast_or_castable_base_expr::compute_scripting_kind()
{
  checkNonUpdating(theInput);

  theScriptingKind = theInput->get_scripting_detail();

  if (is_vacuous())
    theScriptingKind = SIMPLE_EXPR;
}


/***************************************************************************//**
  Base for cast, treat, promote
********************************************************************************/
cast_base_expr::cast_base_expr(
    CompilerCB* ccb,
    static_context* sctx,
    user_function* udf,
    const QueryLoc& loc,
    expr_kind_t kind,
    expr* input,
    const xqtref_t& type)
  :
  cast_or_castable_base_expr(ccb, sctx, udf, loc, kind, input, type)
{
  setNonDiscardable(ANNOTATION_TRUE_FIXED);
}


/***************************************************************************//**
  CastExpr ::= UnaryExpr ( "cast" "as" SingleType )?

  SingleType ::= AtomicType "?"?
********************************************************************************/
cast_expr::cast_expr(
    CompilerCB* ccb,
    static_context* sctx,
    user_function* udf,
    const QueryLoc& loc,
    expr* inputExpr,
    const xqtref_t& type,
    bool allowsEmptyInput)
  :
  cast_base_expr(ccb, sctx, udf, loc, cast_expr_kind, inputExpr, type),
  theAllowsEmtpyInput(allowsEmptyInput)
{
  assert(type->get_quantifier() == SequenceType::QUANT_ONE ||
         type->get_quantifier() == SequenceType::QUANT_QUESTION ||
         type->get_quantifier() == SequenceType::QUANT_STAR);

  setNonDiscardable(ANNOTATION_TRUE_FIXED);
}


/***************************************************************************//**
  TreatExpr ::= CastableExpr ( "treat" "as" SequenceType )?
********************************************************************************/
treat_expr::treat_expr(
    CompilerCB* ccb,
    static_context* sctx,
    user_function* udf,
    const QueryLoc& loc,
    expr* inputExpr,
    const xqtref_t& type,
    TreatErrorKind err,
    bool check_prime,
    store::Item* qname)
  :
  cast_base_expr(ccb, sctx, udf, loc, treat_expr_kind, inputExpr, type),
  theErrorKind(err),
  theCheckPrime(check_prime),
  theQName(qname)
{
  setNonDiscardable(ANNOTATION_TRUE_FIXED);
}


/***************************************************************************//**

********************************************************************************/
promote_expr::promote_expr(
    CompilerCB* ccb,
    static_context* sctx,
    user_function* udf,
    const QueryLoc& loc,
    expr* input,
    const xqtref_t& type,
    PromoteErrorKind err,
    store::Item* qname)
  :
  cast_base_expr(ccb, sctx, udf, loc, promote_expr_kind, input, type),
  theErrorKind(err),
  theQName(qname)
{
  assert(TypeOps::is_subtype(sctx->get_typemanager(),
                             *type,
                             *GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR));

  setNonDiscardable(ANNOTATION_TRUE_FIXED);
}


/***************************************************************************//**
  Base for castable, instanceof
********************************************************************************/
castable_base_expr::castable_base_expr(
    CompilerCB* ccb,
    static_context* sctx,
    user_function* udf,
    const QueryLoc& loc,
    expr_kind_t kind,
    expr* input,
    const xqtref_t& type)
  :
  cast_or_castable_base_expr(ccb, sctx, udf, loc, kind, input, type)
{
}


/***************************************************************************//**
  CastableExpr ::= CastExpr ( "castable" "as" SingleType )?

  SingleType ::= AtomicType "?"?
********************************************************************************/
castable_expr::castable_expr(
    CompilerCB* ccb,
    static_context* sctx,
    user_function* udf,
    const QueryLoc& loc,
    expr* inputExpr,
    const xqtref_t& type,
    bool allowsEmtpyInput)
  :
  castable_base_expr(ccb, sctx, udf, loc, castable_expr_kind, inputExpr, type),
  theAllowsEmtpyInput(allowsEmtpyInput)
{
}


/***************************************************************************//**
  InstanceofExpr ::= TreatExpr ( "instance" "of" SequenceType )?
********************************************************************************/
instanceof_expr::instanceof_expr(
    CompilerCB* ccb,
    static_context* sctx,
    user_function* udf,
    const QueryLoc& loc,
    expr* inputExpr,
    const xqtref_t& type,
    bool checkPrimeOnly)
  :
  castable_base_expr(ccb, sctx, udf, loc, instanceof_expr_kind, inputExpr, type),
  theCheckPrimeOnly(checkPrimeOnly)
{
}


/***************************************************************************//**

********************************************************************************/
name_cast_expr::name_cast_expr(
    CompilerCB* ccb,
    static_context* sctx,
    user_function* udf,
    const QueryLoc& loc,
    expr* inputExpr,
    const namespace_context* aNSCtx,
    bool isAttrName)
  :
  namespace_context_base_expr(ccb, sctx, udf, loc, name_cast_expr_kind, aNSCtx),
  theInputExpr(inputExpr),
  theIsAttrName(isAttrName)
{
  compute_scripting_kind();
}


void name_cast_expr::compute_scripting_kind()
{
  checkNonUpdating(theInputExpr);

  theScriptingKind = theInputExpr->get_scripting_detail();

  if (is_vacuous())
    theScriptingKind = SIMPLE_EXPR;
}


/***************************************************************************//**
  CompDocConstructor ::= "document" "{" Expr "}"
********************************************************************************/
doc_expr::doc_expr(
    CompilerCB* ccb,
    static_context* sctx,
    user_function* udf,
    const QueryLoc& loc,
    expr* aContent,
    bool copyNodes)
  :
  expr(ccb, sctx, udf, loc, doc_expr_kind),
  theContent(aContent),
  theCopyInputNodes(copyNodes)
{
  compute_scripting_kind();

  setUnfoldable(ANNOTATION_TRUE_FIXED);
  setConstructsNodes(ANNOTATION_TRUE_FIXED);
}


void doc_expr::compute_scripting_kind()
{
  checkNonUpdating(theContent);

  theScriptingKind = theContent->get_scripting_detail();

  if (is_vacuous())
    theScriptingKind = SIMPLE_EXPR;
}


/***************************************************************************//**

********************************************************************************/
elem_expr::elem_expr(
    CompilerCB* ccb,
    static_context* sctx,
    user_function* udf,
    const QueryLoc& aLoc,
    expr* aQNameExpr,
    expr* attrs,
    expr* content,
    const namespace_context* aNSCtx,
    bool copyNodes)
  :
  namespace_context_base_expr(ccb, sctx, udf, aLoc, elem_expr_kind, aNSCtx),
  theQNameExpr(aQNameExpr),
  theAttrs(attrs),
  theContent(content),
  theCopyInputNodes(copyNodes)
{
  compute_scripting_kind();

  // Node constructors are unfoldable because if a node constructor is inside
  // a loop, then it will create a different xml tree every time it is invoked,
  // even if the constructor itself is "constant" (i.e. does not reference any
  // varialbes)
  setUnfoldable(ANNOTATION_TRUE_FIXED);
  setConstructsNodes(ANNOTATION_TRUE_FIXED);
}


elem_expr::elem_expr(
    CompilerCB* ccb,
    static_context* sctx,
    user_function* udf,
    const QueryLoc& aLoc,
    expr* aQNameExpr,
    expr* content,
    const namespace_context* aNSCtx,
    bool copyNodes)
  :
  namespace_context_base_expr(ccb, sctx, udf, aLoc, elem_expr_kind, aNSCtx),
  theQNameExpr(aQNameExpr),
  theAttrs(0),
  theContent(content),
  theCopyInputNodes(copyNodes)
{
  compute_scripting_kind();

  setUnfoldable(ANNOTATION_TRUE_FIXED);
  setConstructsNodes(ANNOTATION_TRUE_FIXED);
}


void elem_expr::compute_scripting_kind()
{
  checkNonUpdating(theQNameExpr);
  checkNonUpdating(theContent);
  checkNonUpdating(theAttrs);

  short nameExprKind = theQNameExpr->get_scripting_detail();
  short contentExprKind = (theContent ? theContent->get_scripting_detail() : 0);
  short attrsExprKind = (theAttrs ? theAttrs->get_scripting_detail() : 0);

  theScriptingKind |= (nameExprKind | contentExprKind | attrsExprKind);

  if (is_vacuous())
  {
    theScriptingKind = SIMPLE_EXPR;
  }
  else
  {
    theScriptingKind &= ~VACUOUS_EXPR;

    if (is_sequential())
      theScriptingKind &= ~SIMPLE_EXPR;
  }
}


/***************************************************************************//**

********************************************************************************/
attr_expr::attr_expr(
    CompilerCB* ccb,
    static_context* sctx,
    user_function* udf,
    const QueryLoc& loc,
    expr* aQNameExpr,
    expr* aValueExpr)
  :
  expr(ccb, sctx, udf, loc, attr_expr_kind),
  theQNameExpr(aQNameExpr),
  theValueExpr(aValueExpr)
{
  compute_scripting_kind();

  setUnfoldable(ANNOTATION_TRUE_FIXED);
  setConstructsNodes(ANNOTATION_TRUE_FIXED);
}


const store::Item* attr_expr::getQName() const
{
  if (theQNameExpr->get_expr_kind() == const_expr_kind)
  {
    return static_cast<const_expr*>(theQNameExpr)->get_val();
  }

  return 0;
}


void attr_expr::compute_scripting_kind()
{
  checkNonUpdating(theQNameExpr);
  checkNonUpdating(theValueExpr);

  short nameExprKind = theQNameExpr->get_scripting_detail();
  short valueExprKind = (theValueExpr ? theValueExpr->get_scripting_detail() : 0);

  theScriptingKind |= (nameExprKind | valueExprKind);

  if (is_vacuous())
  {
    theScriptingKind = SIMPLE_EXPR;
  }
  else
  {
    theScriptingKind &= ~VACUOUS_EXPR;

    if (is_sequential())
      theScriptingKind &= ~SIMPLE_EXPR;
  }
}


DEF_EXPR_ACCEPT(attr_expr)


/***************************************************************************//**

********************************************************************************/
namespace_expr::namespace_expr(
    CompilerCB* ccb,
    static_context* sctx,
    user_function* udf,
    const QueryLoc& loc,
    expr* preExpr,
    expr* uriExpr)
  :
  expr(ccb, sctx, udf, loc, namespace_expr_kind),
  thePrefixExpr(preExpr),
  theUriExpr(uriExpr)
{
  compute_scripting_kind();

  setUnfoldable(ANNOTATION_TRUE_FIXED);
  setConstructsNodes(ANNOTATION_TRUE_FIXED);
}


const store::Item* namespace_expr::getPrefix() const
{
  if (thePrefixExpr->get_expr_kind() == const_expr_kind)
  {
    return static_cast<const_expr*>(thePrefixExpr)->get_val();
  }

  return NULL;
}


void namespace_expr::compute_scripting_kind()
{
  checkNonUpdating(thePrefixExpr);
  checkNonUpdating(theUriExpr);

  short nameExprKind = thePrefixExpr->get_scripting_detail();
  short valueExprKind = theUriExpr->get_scripting_detail();

  theScriptingKind |= (nameExprKind | valueExprKind);

  if (is_vacuous())
  {
    theScriptingKind = SIMPLE_EXPR;
  }
  else
  {
    theScriptingKind &= ~VACUOUS_EXPR;

    if (is_sequential())
      theScriptingKind &= ~SIMPLE_EXPR;
  }
}


DEF_EXPR_ACCEPT(namespace_expr)


/***************************************************************************//**

********************************************************************************/
text_expr::text_expr(
    CompilerCB* ccb,
    static_context* sctx,
    user_function* udf,
    const QueryLoc& loc,
    TextConstructorType type_arg,
    expr* content)
  :
  expr(ccb, sctx, udf, loc, text_expr_kind),
  type(type_arg),
  theContentExpr(content)
{
  compute_scripting_kind();

  setUnfoldable(ANNOTATION_TRUE_FIXED);
  setConstructsNodes(ANNOTATION_TRUE_FIXED);
}


void text_expr::compute_scripting_kind()
{
  checkNonUpdating(theContentExpr);

  theScriptingKind = theContentExpr->get_scripting_detail();

  if (is_vacuous())
    theScriptingKind = SIMPLE_EXPR;
}


/***************************************************************************//**

********************************************************************************/
pi_expr::pi_expr(
    CompilerCB* ccb,
    static_context* sctx,
    user_function* udf,
    const QueryLoc& loc,
    expr* targetExpr,
    expr* contentExpr)
:
  expr(ccb, sctx, udf, loc, pi_expr_kind),
  theTargetExpr(targetExpr),
  theContentExpr(contentExpr)
{
  compute_scripting_kind();

  setUnfoldable(ANNOTATION_TRUE_FIXED);
  setConstructsNodes(ANNOTATION_TRUE_FIXED);
}


void pi_expr::compute_scripting_kind()
{
  checkNonUpdating(theTargetExpr);
  checkNonUpdating(theContentExpr);

  short targetExprKind = theTargetExpr->get_scripting_detail();
  short contentExprKind = theContentExpr->get_scripting_detail();

  theScriptingKind |= (targetExprKind | contentExprKind);

  if (is_vacuous())
  {
    theScriptingKind = SIMPLE_EXPR;
  }
  else
  {
    theScriptingKind &= ~VACUOUS_EXPR;

    if (is_sequential())
      theScriptingKind &= ~SIMPLE_EXPR;
  }
}


/*******************************************************************************
  Normally, it is used to wrap a var_expr in order to represent a var reference
  (see var_expr.h). But it may wrap any other kind of expr as well.
********************************************************************************/
wrapper_expr::wrapper_expr(
    CompilerCB* ccb,
    static_context* sctx,
    user_function* udf,
    const QueryLoc& loc,
    expr* input)
  :
  expr(ccb, sctx, udf, loc, wrapper_expr_kind),
  theInput(input)
{
  compute_scripting_kind();

  if (theInput->get_expr_kind() == var_expr_kind)
    static_cast<var_expr*>(theInput)->add_ref();
}


void wrapper_expr::compute_scripting_kind()
{
  theScriptingKind = theInput->get_scripting_detail();
}


/***************************************************************************//**

********************************************************************************/
const_expr::const_expr(
    CompilerCB* ccb,
    static_context* sctx,
    user_function* udf,
    const QueryLoc& loc,
    zstring& v)
  :
  expr(ccb, sctx, udf, loc, const_expr_kind)
{
  GENV_ITEMFACTORY->createString(theValue, v);
  theScriptingKind = SIMPLE_EXPR;
}


const_expr::const_expr(
    CompilerCB* ccb,
    static_context* sctx,
    user_function* udf,
    const QueryLoc& loc,
    const std::string& v)
  :
  expr(ccb, sctx, udf, loc, const_expr_kind)
{
  zstring tmp(v);
  GENV_ITEMFACTORY->createString(theValue, tmp);
  theScriptingKind = SIMPLE_EXPR;
}


const_expr::const_expr(
    CompilerCB* ccb,
    static_context* sctx,
    user_function* udf,
    const QueryLoc& loc,
    const char* v)
  :
  expr(ccb, sctx, udf, loc, const_expr_kind)
{
  zstring tmp(v);
  GENV_ITEMFACTORY->createString(theValue, tmp);
  theScriptingKind = SIMPLE_EXPR;
}


const_expr::const_expr(
    CompilerCB* ccb,
    static_context* sctx,
    user_function* udf,
    const QueryLoc& loc,
    xs_integer v)
  :
  expr(ccb, sctx, udf, loc, const_expr_kind)
{
  GENV_ITEMFACTORY->createInteger(theValue, v);
  theScriptingKind = SIMPLE_EXPR;
}


const_expr::const_expr(
    CompilerCB* ccb,
    static_context* sctx,
    user_function* udf,
    const QueryLoc& loc,
    xs_decimal v)
  :
  expr(ccb, sctx, udf, loc, const_expr_kind)
{
  GENV_ITEMFACTORY->createDecimal(theValue, v);
  theScriptingKind = SIMPLE_EXPR;
}


const_expr::const_expr(
    CompilerCB* ccb,
    static_context* sctx,
    user_function* udf,
    const QueryLoc& loc,
    xs_double v)
  :
  expr(ccb, sctx, udf, loc, const_expr_kind)
{
  GENV_ITEMFACTORY->createDouble(theValue, v);
  theScriptingKind = SIMPLE_EXPR;
}


const_expr::const_expr(
    CompilerCB* ccb,
    static_context* sctx,
    user_function* udf,
    const QueryLoc& loc,
    xs_boolean v)
  :
  expr(ccb, sctx, udf, loc, const_expr_kind)
{
  GENV_ITEMFACTORY->createBoolean(theValue, v);
  theScriptingKind = SIMPLE_EXPR;
}


const_expr::const_expr(
    CompilerCB* ccb,
    static_context* sctx,
    user_function* udf,
    const QueryLoc& loc,
    const store::Item_t& v)
  :
  expr(ccb, sctx, udf, loc, const_expr_kind),
  theValue(v)
{
  theScriptingKind = SIMPLE_EXPR;
}


const_expr::const_expr(
    CompilerCB* ccb,
    static_context* sctx,
    user_function* udf,
    const QueryLoc& aLoc,
    const char* aNamespace,
    const char* aPrefix,
    const char* aLocal)
  :
  expr(ccb, sctx, udf, aLoc, const_expr_kind)
{
  GENV_ITEMFACTORY->createQName(theValue, aNamespace, aPrefix, aLocal);
  theScriptingKind = SIMPLE_EXPR;
}


void const_expr::compute_scripting_kind()
{
  theScriptingKind = SIMPLE_EXPR;
}


/*******************************************************************************

********************************************************************************/
extension_expr::extension_expr(
    CompilerCB* ccb,
    static_context* sctx,
    user_function* udf,
    const QueryLoc& loc)
  :
  expr(ccb, sctx, udf, loc, extension_expr_kind)
{
  compute_scripting_kind();
}


extension_expr::extension_expr(
    CompilerCB* ccb,
    static_context* sctx,
    user_function* udf,
    const QueryLoc& loc,
    expr* e)
  :
  expr(ccb, sctx, udf, loc, extension_expr_kind),
  theExpr(e)
{
  compute_scripting_kind();
}


void extension_expr::compute_scripting_kind()
{
  checkNonUpdating(theExpr);

  theScriptingKind = theExpr->get_scripting_detail();

  if (is_vacuous())
    theScriptingKind = SIMPLE_EXPR;
}


/////////////////////////////////////////////////////////////////////////
//                                                                     //
//  XQuery 3.0 expressions                                             //
//  [http://www.w3.org/TR/xquery-3/]                                   //
//                                                                     //
/////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
catch_clause::catch_clause(CompilerCB* ccb)
  :
  theCCB(ccb)
{
}


trycatch_expr::trycatch_expr(
    CompilerCB* ccb,
    static_context* sctx,
    user_function* udf,
    const QueryLoc& loc,
    expr* tryExpr)
  :
  expr(ccb, sctx, udf, loc, trycatch_expr_kind),
  theTryExpr(tryExpr)
{
  compute_scripting_kind();
}


void trycatch_expr::add_catch_expr(expr* e)
{
  theCatchExprs.insert(theCatchExprs.begin(), e);

  compute_scripting_kind();
}


void trycatch_expr::add_clause(catch_clause* cc)
{
  theCatchClauses.insert(theCatchClauses.begin(), cc);
}


void trycatch_expr::compute_scripting_kind()
{
  bool vacuous = true;

  theScriptingKind = VACUOUS_EXPR;

  theScriptingKind |= theTryExpr->get_scripting_detail();

  if (theScriptingKind != VACUOUS_EXPR)
    vacuous = false;

  csize numCatchClauses = theCatchClauses.size();

  for (csize i = 0; i < numCatchClauses; ++i)
  {
    const expr* catchExpr = theCatchExprs[i];
    short catchKind = catchExpr->get_scripting_detail();

    if (catchKind == VACUOUS_EXPR)
      continue;

    vacuous = false;

    if (!theSctx->is_feature_set(feature::scripting))
    {
      if (is_updating() && !(catchKind & UPDATING_EXPR) && catchKind != VACUOUS_EXPR)
      {
        RAISE_ERROR(err::XUST0001, catchExpr->get_loc(),
        ERROR_PARAMS(ZED(XUST0001_TRYCATCH)));
      }

      if (!is_updating() && !is_vacuous() && (catchKind & UPDATING_EXPR))
      {
        RAISE_ERROR(err::XUST0001, catchExpr->get_loc(),
        ERROR_PARAMS(ZED(XUST0001_TRYCATCH)));
      }
    }

    theScriptingKind |= catchKind;
  }

  if (!vacuous)
    theScriptingKind &= ~VACUOUS_EXPR;

  if (theScriptingKind & UPDATING_EXPR)
    theScriptingKind &= ~SIMPLE_EXPR;

  if (is_sequential(theScriptingKind))
    theScriptingKind &= ~SIMPLE_EXPR;

  checkScriptingKind();
}


catch_clause* catch_clause::clone(expr::substitution_t& subst) const
{
  catch_clause* lClause = theCCB->theEM->create_catch_clause();

  for (nt_list_t::const_iterator lIter = theNameTests.begin();
       lIter != theNameTests.end();
       ++lIter)
  {
    lClause->add_nametest_h(lIter->getp());
  }

  for (var_map_t::const_iterator lIter = theVarMap.begin();
       lIter != theVarMap.end();
       ++lIter)
  {
    lClause->add_var((catch_clause::var_type)lIter->first, lIter->second);
  }

  return lClause;
}


/*******************************************************************************

********************************************************************************/
eval_expr::eval_expr(
    CompilerCB* ccb,
    static_context* sctx,
    user_function* udf,
    const QueryLoc& loc,
    expr* e,
    expr_script_kind_t scriptingKind,
    namespace_context* nsCtx)
  :
  namespace_context_base_expr(ccb, sctx, udf, loc, eval_expr_kind, nsCtx),
  theExpr(e),
  theInnerScriptingKind(scriptingKind),
  theDoNodeCopy(false)
{
  if (ccb)
    ccb->theHasEval = true;

  compute_scripting_kind();
}


expr_script_kind_t eval_expr::get_inner_scripting_kind() const
{
  return theInnerScriptingKind;
}


void eval_expr::compute_scripting_kind()
{
  checkNonUpdating(theExpr);

  theScriptingKind = theInnerScriptingKind;

  if (theExpr->is_sequential())
  {
    theScriptingKind |= theExpr->get_scripting_detail();
    theScriptingKind &= ~SIMPLE_EXPR;
  }

  checkScriptingKind();
}


void eval_expr::add_var(var_expr* var)
{
  theOuterVarNames.push_back(var->get_name());
  theOuterVarTypes.push_back(var->get_return_type());
  theArgs.push_back(var);
}


#ifdef ZORBA_WITH_DEBUGGER
/*******************************************************************************

********************************************************************************/
debugger_expr::debugger_expr(
    CompilerCB* ccb,
    static_context* sctx,
    user_function* udf,
    const QueryLoc& loc,
    expr* aChild,
    namespace_context* nsCtx,
    bool aIsVarDeclaration)
  :
  namespace_context_base_expr(ccb, sctx, udf, loc, debugger_expr_kind, nsCtx),
  theExpr(aChild),
  theIsVarDeclaration(aIsVarDeclaration)
{
  compute_scripting_kind();
}


void debugger_expr::compute_scripting_kind()
{
  theScriptingKind = theExpr->get_scripting_detail();
}


void debugger_expr::add_var(var_expr* var, expr* arg)
{
  theVars.push_back(var);
  theArgs.push_back(arg);
}

#endif


/*******************************************************************************

********************************************************************************/
function_trace_expr::function_trace_expr(
    CompilerCB* ccb,
    static_context* sctx,
    user_function* udf,
    const QueryLoc& loc,
    expr* input)
  :
  expr(ccb, sctx, udf, loc, function_trace_expr_kind),
  theInput(input),
  theFunctionArity(0)
{
  bool modified;
  compute_return_type(false, &modified);
  compute_scripting_kind();
}


function_trace_expr::function_trace_expr(user_function* udf, expr* input)
  :
  expr(input->get_ccb(),
       input->get_sctx(),
       udf,
       input->get_loc(),
       function_trace_expr_kind),
  theInput(input),
  theFunctionArity(0)
{
  bool modified;
  compute_return_type(false, &modified);
  compute_scripting_kind();
}


function_trace_expr::~function_trace_expr()
{
}


void function_trace_expr::compute_scripting_kind()
{
  theScriptingKind = theInput->get_scripting_detail();
}


} /* namespace zorba */
/* vim:set et sw=2 ts=2: */
