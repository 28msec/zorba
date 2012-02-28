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

#include "store/api/store.h"
#include "store/api/item_factory.h"

namespace zorba 
{

SERIALIZABLE_CLASS_VERSIONS(expr)
END_SERIALIZABLE_CLASS_VERSIONS(expr)

SERIALIZABLE_CLASS_VERSIONS(catch_clause)
END_SERIALIZABLE_CLASS_VERSIONS(catch_clause)

SERIALIZABLE_CLASS_VERSIONS(trycatch_expr)
END_SERIALIZABLE_CLASS_VERSIONS(trycatch_expr)

SERIALIZABLE_CLASS_VERSIONS(function_trace_expr)
END_SERIALIZABLE_CLASS_VERSIONS(function_trace_expr)

SERIALIZABLE_CLASS_VERSIONS(eval_expr)
END_SERIALIZABLE_CLASS_VERSIONS(eval_expr)

#ifdef ZORBA_WITH_DEBUGGER
SERIALIZABLE_CLASS_VERSIONS(debugger_expr)
END_SERIALIZABLE_CLASS_VERSIONS(debugger_expr)
#endif

SERIALIZABLE_CLASS_VERSIONS(wrapper_expr)
END_SERIALIZABLE_CLASS_VERSIONS(wrapper_expr)

SERIALIZABLE_CLASS_VERSIONS(namespace_context_base_expr)
END_SERIALIZABLE_CLASS_VERSIONS(namespace_context_base_expr)

SERIALIZABLE_CLASS_VERSIONS(cast_or_castable_base_expr)
END_SERIALIZABLE_CLASS_VERSIONS(cast_or_castable_base_expr)

SERIALIZABLE_CLASS_VERSIONS(cast_base_expr)
END_SERIALIZABLE_CLASS_VERSIONS(cast_base_expr)

SERIALIZABLE_CLASS_VERSIONS(promote_expr)
END_SERIALIZABLE_CLASS_VERSIONS(promote_expr)

SERIALIZABLE_CLASS_VERSIONS(castable_base_expr)
END_SERIALIZABLE_CLASS_VERSIONS(castable_base_expr)

SERIALIZABLE_CLASS_VERSIONS(instanceof_expr)
END_SERIALIZABLE_CLASS_VERSIONS(instanceof_expr)

SERIALIZABLE_CLASS_VERSIONS(treat_expr)
END_SERIALIZABLE_CLASS_VERSIONS(treat_expr)

SERIALIZABLE_CLASS_VERSIONS(castable_expr)
END_SERIALIZABLE_CLASS_VERSIONS(castable_expr)

SERIALIZABLE_CLASS_VERSIONS(cast_expr)
END_SERIALIZABLE_CLASS_VERSIONS(cast_expr)

SERIALIZABLE_CLASS_VERSIONS(name_cast_expr)
END_SERIALIZABLE_CLASS_VERSIONS(name_cast_expr)

SERIALIZABLE_CLASS_VERSIONS(if_expr)
END_SERIALIZABLE_CLASS_VERSIONS(if_expr)

SERIALIZABLE_CLASS_VERSIONS(validate_expr)
END_SERIALIZABLE_CLASS_VERSIONS(validate_expr)

SERIALIZABLE_CLASS_VERSIONS(pragma)
END_SERIALIZABLE_CLASS_VERSIONS(pragma)

SERIALIZABLE_CLASS_VERSIONS(extension_expr)
END_SERIALIZABLE_CLASS_VERSIONS(extension_expr)

SERIALIZABLE_CLASS_VERSIONS(const_expr)
END_SERIALIZABLE_CLASS_VERSIONS(const_expr)

SERIALIZABLE_CLASS_VERSIONS(order_expr)
END_SERIALIZABLE_CLASS_VERSIONS(order_expr)

SERIALIZABLE_CLASS_VERSIONS(elem_expr)
END_SERIALIZABLE_CLASS_VERSIONS(elem_expr)

SERIALIZABLE_CLASS_VERSIONS(doc_expr)
END_SERIALIZABLE_CLASS_VERSIONS(doc_expr)

SERIALIZABLE_CLASS_VERSIONS(attr_expr)
END_SERIALIZABLE_CLASS_VERSIONS(attr_expr)

SERIALIZABLE_CLASS_VERSIONS(text_expr)
END_SERIALIZABLE_CLASS_VERSIONS(text_expr)

SERIALIZABLE_CLASS_VERSIONS(pi_expr)
END_SERIALIZABLE_CLASS_VERSIONS(pi_expr)

SERIALIZABLE_CLASS_VERSIONS(OrderModifier)
END_SERIALIZABLE_CLASS_VERSIONS(OrderModifier)


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


#define CLONE( e, s ) ((e) == NULL ? NULL : (e)->clone(s))



/*******************************************************************************
  [68] IfExpr ::= "if" "(" Expr ")" "then" ExprSingle "else" ExprSingle
********************************************************************************/
if_expr::if_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr_t condExpr,
    expr_t thenExpr,
    expr_t elseExpr)
  :
  expr(sctx, loc, if_expr_kind),
  theThenExpr(thenExpr),
  theElseExpr(elseExpr)
{
  if (sctx != NULL &&
      !TypeOps::is_equal(sctx->get_typemanager(), 
                         *condExpr->get_return_type(),
                         *GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE,
                         loc))
  {
    fo_expr* boolExpr = new fo_expr(sctx,
                                    loc,
                                    GET_BUILTIN_FUNCTION(FN_BOOLEAN_1),
                                    condExpr);
    condExpr = boolExpr;
  }

  theCondExpr = condExpr;

  compute_scripting_kind();
}


void if_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (expr*)this);
  ar & theCondExpr;
  ar & theThenExpr;
  ar & theElseExpr;
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
      throw XQUERY_EXCEPTION(err::XUST0001, 
                             ERROR_PARAMS(ZED(XUST0001_IF)),
                             ERROR_LOC(get_loc()));
    }
    else if (theElseExpr->is_updating() && !theThenExpr->is_updating_or_vacuous())
    {
      throw XQUERY_EXCEPTION(err::XUST0001, 
                             ERROR_PARAMS(ZED(XUST0001_IF)),
                             ERROR_LOC(get_loc()));
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


expr_t if_expr::clone(substitution_t& subst) const 
{
  return new if_expr(theSctx,
                     get_loc(),
                     get_cond_expr()->clone(subst),
                     get_then_expr()->clone(subst),
                     get_else_expr()->clone(subst));
}


/***************************************************************************//**

********************************************************************************/
order_expr::order_expr(
    static_context* sctx,
    const QueryLoc& loc,
    order_type_t type,
    expr_t inExpr)
  :
  expr(sctx, loc, order_expr_kind),
  theType(type),
  theExpr(inExpr)
{
  compute_scripting_kind();
}


void order_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (expr*)this);
  SERIALIZE_ENUM(order_type_t, theType);
  ar & theExpr;
}


void order_expr::compute_scripting_kind()
{
  theScriptingKind = theExpr->get_scripting_detail();

  if (is_vacuous())
    theScriptingKind = SIMPLE_EXPR;
}


expr_t order_expr::clone(substitution_t& subst) const
{
  return new order_expr(theSctx, get_loc(), get_type(), get_expr()->clone(subst));
}


/***************************************************************************//**

********************************************************************************/
validate_expr::validate_expr(
    static_context* sctx,
    const QueryLoc& loc,
    enum ParseConstants::validation_mode_t mode,
    const store::Item_t& typeName,
    expr_t inExpr,
    rchandle<TypeManager> typemgr)
  :
  expr(sctx, loc, validate_expr_kind),
  theMode(mode),
  theTypeName(typeName),
  theTypeMgr(typemgr),
  theExpr(inExpr)
{
  compute_scripting_kind();
}


void validate_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (expr*)this);
  SERIALIZE_ENUM(ParseConstants::validation_mode_t, theMode);
  ar & theTypeName;
  SERIALIZE_TYPEMANAGER_RCHANDLE(TypeManager, theTypeMgr);
  ar & theExpr;
}


void validate_expr::compute_scripting_kind()
{
  checkNonUpdating(theExpr);

  theScriptingKind = theExpr->get_scripting_detail();

  if (is_vacuous())
    theScriptingKind = SIMPLE_EXPR;
}


expr_t validate_expr::clone(substitution_t& subst) const
{
  return new validate_expr(theSctx,
                           get_loc(),
                           get_valmode(),
                           const_cast<store::Item*>(get_type_name()),
                           get_expr()->clone(subst),
                           get_typemgr());
}


/***************************************************************************//**
  Base for expression classes that require a namespace context
********************************************************************************/
namespace_context_base_expr::namespace_context_base_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr_kind_t kind,
    const namespace_context* aNSCtx)
  :
  expr(sctx, loc, kind),
  theNSCtx(const_cast<namespace_context*>(aNSCtx))
{
}


const namespace_context* namespace_context_base_expr::getNSCtx() const
{
  return theNSCtx.getp(); 
}


void namespace_context_base_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (expr*)this);
  ar & theNSCtx;
}


/*******************************************************************************
  Base for cast, treat, promote, castable, instanceof
********************************************************************************/
cast_or_castable_base_expr::cast_or_castable_base_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr_kind_t kind,
    expr_t input,
    xqtref_t type)
  :
  expr(sctx, loc, kind),
  theInputExpr(input),
  theTargetType(type)
{
  assert(type != NULL);
  assert(input != NULL);

  compute_scripting_kind();
}


void cast_or_castable_base_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (expr*)this);
  ar & theInputExpr;
  ar & theTargetType;
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
  checkNonUpdating(theInputExpr);

  theScriptingKind = theInputExpr->get_scripting_detail();

  if (is_vacuous())
    theScriptingKind = SIMPLE_EXPR;
}


/***************************************************************************//**
  Base for cast, treat, promote
********************************************************************************/
cast_base_expr::cast_base_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr_kind_t kind,
    expr_t input,
    xqtref_t type)
  : 
  cast_or_castable_base_expr(sctx, loc, kind, input, type)
{
  setNonDiscardable(ANNOTATION_TRUE_FIXED);
}


void cast_base_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (cast_or_castable_base_expr*)this);
}


/***************************************************************************//**
  CastExpr ::= UnaryExpr ( "cast" "as" SingleType )?

  SingleType ::= AtomicType "?"?
********************************************************************************/
cast_expr::cast_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr_t inputExpr,
    xqtref_t type)
  :
  cast_base_expr(sctx, loc, cast_expr_kind, inputExpr, type)
{
  assert(type->get_quantifier() == TypeConstants::QUANT_ONE ||
         type->get_quantifier() == TypeConstants::QUANT_QUESTION);
}


void cast_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (cast_base_expr*)this);
}


bool cast_expr::is_optional() const 
{
  return TypeOps::quantifier(*theTargetType) == TypeConstants::QUANT_QUESTION; 
}


expr_t cast_expr::clone(substitution_t& subst) const
{
  return new cast_expr(theSctx,
                       get_loc(),
                       get_input()->clone(subst), 
                       get_target_type());
}


/***************************************************************************//**
	TreatExpr ::= CastableExpr ( "treat" "as" SequenceType )?
********************************************************************************/
treat_expr::treat_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr_t inputExpr,
    xqtref_t type,
    Error const &err,
    bool check_prime,
    store::Item_t fnQname)
  :
  cast_base_expr(sctx, loc, treat_expr_kind, inputExpr, type),
  theError(&err),
  theCheckPrime(check_prime),
  theFnQName(fnQname)
{
}


void treat_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (cast_base_expr*)this);
  ar & theCheckPrime;
  ar & theError;
  ar & theFnQName;
}


expr_t treat_expr::clone(substitution_t& subst) const
{
  return new treat_expr(theSctx,
                        get_loc(),
                        get_input()->clone(subst), 
                        get_target_type(),
                        get_err(),
                        get_check_prime(),
                        get_fn_qname());
}


/***************************************************************************//**

********************************************************************************/
promote_expr::promote_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr_t input,
    xqtref_t type,
    store::Item_t fnQName)
  :
  cast_base_expr(sctx, loc, promote_expr_kind, input, type),
  theFnQName(fnQName)
{
}


expr_t promote_expr::clone(substitution_t& subst) const
{
  return new promote_expr(theSctx, 
                          get_loc(),
                          get_input()->clone(subst),
                          get_target_type(),
                          theFnQName);
}


/***************************************************************************//**
  Base for castable, instanceof
********************************************************************************/
castable_base_expr::castable_base_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr_kind_t kind,
    expr_t input,
    xqtref_t type)
  :
  cast_or_castable_base_expr(sctx, loc, kind, input, type)
{
}


void castable_base_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (cast_or_castable_base_expr*)this);
}


/***************************************************************************//**
  CastableExpr ::= CastExpr ( "castable" "as" SingleType )?

  SingleType ::= AtomicType "?"?
********************************************************************************/
castable_expr::castable_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr_t inputExpr,
    xqtref_t type)
  :
  castable_base_expr (sctx, loc, castable_expr_kind, inputExpr, type)
{
}


void castable_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (castable_base_expr*)this);
}


bool castable_expr::is_optional() const 
{
  return TypeOps::quantifier(*theTargetType) == TypeConstants::QUANT_QUESTION; 
}


expr_t castable_expr::clone(substitution_t& subst) const
{
  return new castable_expr(theSctx, 
                           get_loc(),
                           get_input()->clone(subst),
                           get_target_type());
}


/***************************************************************************//**
	InstanceofExpr ::= TreatExpr ( "instance" "of" SequenceType )?
********************************************************************************/
instanceof_expr::instanceof_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr_t inputExpr,
    xqtref_t type,
    bool checkPrimeOnly)
  :
  castable_base_expr(sctx, loc, instanceof_expr_kind, inputExpr, type),
  theCheckPrimeOnly(checkPrimeOnly)
{
}


void instanceof_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (castable_base_expr*)this);
  ar & theCheckPrimeOnly;
}


expr_t instanceof_expr::clone(substitution_t& subst) const
{
  return new instanceof_expr(theSctx,
                             get_loc(),
                             get_input()->clone(subst),
                             get_target_type());
}


/***************************************************************************//**

********************************************************************************/
name_cast_expr::name_cast_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr_t inputExpr,
    const namespace_context* aNSCtx,
    bool isAttrName)
  :
  namespace_context_base_expr(sctx, loc, name_cast_expr_kind, aNSCtx),
  theInputExpr(inputExpr),
  theIsAttrName(isAttrName)
{
  compute_scripting_kind();
}


void name_cast_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (expr*)this);
  ar & theInputExpr;
  ar & theIsAttrName;
}


void name_cast_expr::compute_scripting_kind()
{
  checkNonUpdating(theInputExpr);

  theScriptingKind = theInputExpr->get_scripting_detail();

  if (is_vacuous())
    theScriptingKind = SIMPLE_EXPR;
}


expr_t name_cast_expr::clone(substitution_t& subst) const
{
  return new name_cast_expr(theSctx,
                            get_loc(),
                            get_input()->clone(subst),
                            getNSCtx(),
                            theIsAttrName);
}


/***************************************************************************//**
  CompDocConstructor ::= "document" "{" Expr "}"
********************************************************************************/
doc_expr::doc_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr* aContent,
    bool copyNodes)
  :
  expr(sctx, loc, doc_expr_kind),
  theContent(aContent),
  theCopyInputNodes(copyNodes)
{
  compute_scripting_kind();
}


void doc_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (expr*)this);
  ar & theContent;
  ar & theCopyInputNodes;
}


void doc_expr::compute_scripting_kind()
{
  checkNonUpdating(theContent);

  theScriptingKind = theContent->get_scripting_detail();

  if (is_vacuous())
    theScriptingKind = SIMPLE_EXPR;
}


expr_t doc_expr::clone(substitution_t& subst) const
{
  doc_expr* clone = new doc_expr(theSctx,
                                 get_loc(),
                                 CLONE(getContent(), subst),
                                 theCopyInputNodes);
  return clone;
}


/***************************************************************************//**

********************************************************************************/
elem_expr::elem_expr(
    static_context* sctx,
    const QueryLoc& aLoc,
    expr* aQNameExpr,
    expr* attrs,
    expr* content,
    const namespace_context* aNSCtx,
    bool copyNodes)
  :
  namespace_context_base_expr(sctx, aLoc, elem_expr_kind, aNSCtx),
  theQNameExpr(aQNameExpr),
  theAttrs(attrs),
  theContent(content),
  theCopyInputNodes(copyNodes)
{
  compute_scripting_kind();

  setUnfoldable(ANNOTATION_TRUE_FIXED);
}


elem_expr::elem_expr(
    static_context* sctx,
    const QueryLoc& aLoc,
    expr* aQNameExpr,
    expr* content,
    const namespace_context* aNSCtx,
    bool copyNodes)
  :
  namespace_context_base_expr(sctx, aLoc, elem_expr_kind, aNSCtx),
  theQNameExpr(aQNameExpr),
  theAttrs(0),
  theContent(content),
  theCopyInputNodes(copyNodes)
{
  compute_scripting_kind();

  setUnfoldable(ANNOTATION_TRUE_FIXED);
}
  

void elem_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (expr*)this);
  ar & theQNameExpr;
  ar & theAttrs;
  ar & theContent;
  ar & theNSCtx;
  ar & theCopyInputNodes;
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


expr_t elem_expr::clone(substitution_t& subst) const
{
  elem_expr* clone =  new elem_expr(theSctx,
                                    get_loc(),
                                    CLONE(getQNameExpr(), subst),
                                    CLONE(getAttrs(), subst),
                                    CLONE(getContent(), subst),
                                    getNSCtx(),
                                    theCopyInputNodes);
  return clone;
}


/***************************************************************************//**

********************************************************************************/
attr_expr::attr_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr_t aQNameExpr,
    expr_t aValueExpr)
  :
  expr(sctx, loc, attr_expr_kind),
  theQNameExpr(aQNameExpr),
  theValueExpr(aValueExpr)
{
  compute_scripting_kind();

  setUnfoldable(ANNOTATION_TRUE_FIXED);
}


void attr_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (expr*)this);
  ar & theQNameExpr;
  ar & theValueExpr;
}


const store::Item* attr_expr::getQName() const
{
  const_expr* qnExpr =  dynamic_cast<const_expr*>(theQNameExpr.getp());
  if (qnExpr != 0)
    return qnExpr->get_val();

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


expr_t attr_expr::clone(substitution_t& subst) const
{
  return new attr_expr(theSctx,
                       get_loc(),
                       CLONE(getQNameExpr(), subst),
                       CLONE(getValueExpr(), subst));
}


DEF_EXPR_ACCEPT(attr_expr)


/***************************************************************************//**

********************************************************************************/
text_expr::text_expr(
    static_context* sctx,
    const QueryLoc& loc,
    text_constructor_type type_arg,
    expr_t content)
  :
  expr(sctx, loc, text_expr_kind),
  type(type_arg),
  theContentExpr(content)
{
  compute_scripting_kind();

  setUnfoldable(ANNOTATION_TRUE_FIXED);
}


void text_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (expr*)this);
  SERIALIZE_ENUM(text_constructor_type, type);
  ar & theContentExpr;
}


void text_expr::compute_scripting_kind()
{
  checkNonUpdating(theContentExpr);

  theScriptingKind = theContentExpr->get_scripting_detail();

  if (is_vacuous())
    theScriptingKind = SIMPLE_EXPR;
}


expr_t text_expr::clone(substitution_t& subst) const
{
  return new text_expr(theSctx, get_loc(), get_type(), CLONE(get_text(), subst));
}


/***************************************************************************//**

********************************************************************************/
pi_expr::pi_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr_t targetExpr,
    expr_t contentExpr)
:
  expr(sctx, loc, pi_expr_kind),
  theTargetExpr(targetExpr),
  theContentExpr(contentExpr)
{
  compute_scripting_kind();

  setUnfoldable(ANNOTATION_TRUE_FIXED);
}


void pi_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (expr*)this);
  ar & theTargetExpr;
  ar & theContentExpr;
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


expr_t pi_expr::clone(substitution_t& subst) const
{
  return new pi_expr(theSctx,
                     get_loc(),
                     CLONE(get_target_expr(), subst),
                     CLONE(get_content_expr(), subst));
}



/*******************************************************************************
  Normally, it is used to wrap a var_expr in order to represent a var reference
  (see var_expr.h). But it may wrap any other kind of expr as well.
********************************************************************************/
wrapper_expr::wrapper_expr(static_context* sctx, const QueryLoc& loc, expr_t wrapped)
  :
  expr(sctx, loc, wrapper_expr_kind),
  theWrappedExpr(wrapped)
{
  compute_scripting_kind();
}


void wrapper_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (expr*)this);
  ar & theWrappedExpr;
}


void wrapper_expr::compute_scripting_kind()
{
  theScriptingKind = theWrappedExpr->get_scripting_detail();
}


expr_t wrapper_expr::clone(substitution_t& subst) const
{
  expr_t e = theWrappedExpr->clone(subst);

  if (theWrappedExpr->get_expr_kind() == var_expr_kind &&
      e->get_expr_kind() != var_expr_kind)
    return e;
  else
    return new wrapper_expr(theSctx, get_loc(), e);
}


/***************************************************************************//**

********************************************************************************/
const_expr::const_expr(static_context* sctx, const QueryLoc& loc, zstring& v)
  :
  expr(sctx, loc, const_expr_kind)
{
  GENV_ITEMFACTORY->createString(theValue, v); 
  theScriptingKind = SIMPLE_EXPR;
}


const_expr::const_expr(static_context* sctx, const QueryLoc& loc, const std::string& v)
  :
  expr(sctx, loc, const_expr_kind)
{
  zstring tmp(v);
  GENV_ITEMFACTORY->createString(theValue, tmp); 
  theScriptingKind = SIMPLE_EXPR;
}


const_expr::const_expr(static_context* sctx, const QueryLoc& loc, const char* v)
  :
  expr(sctx, loc, const_expr_kind)
{
  zstring tmp(v);
  GENV_ITEMFACTORY->createString(theValue, tmp); 
  theScriptingKind = SIMPLE_EXPR;
}


const_expr::const_expr(static_context* sctx, const QueryLoc& loc, xs_integer v)
  :
  expr(sctx, loc, const_expr_kind)
{
  GENV_ITEMFACTORY->createInteger(theValue, v);
  theScriptingKind = SIMPLE_EXPR;
}

const_expr::const_expr(
    static_context* sctx,
    const QueryLoc& loc,
    xs_decimal v)
  :
  expr(sctx, loc, const_expr_kind)
{
  GENV_ITEMFACTORY->createDecimal(theValue, v);
  theScriptingKind = SIMPLE_EXPR;
}

const_expr::const_expr(
    static_context* sctx,
    const QueryLoc& loc,
    xs_double v)
  :
  expr(sctx, loc, const_expr_kind)
{
  GENV_ITEMFACTORY->createDouble(theValue, v);
  theScriptingKind = SIMPLE_EXPR;
}


const_expr::const_expr(
    static_context* sctx,
    const QueryLoc& loc,
    xs_boolean v)
  :
  expr(sctx, loc, const_expr_kind)
{
  GENV_ITEMFACTORY->createBoolean(theValue, v);
  theScriptingKind = SIMPLE_EXPR;
}


const_expr::const_expr(
    static_context* sctx,
    const QueryLoc& loc,
    store::Item_t v)
  :
  expr(sctx, loc, const_expr_kind),
  theValue(v)
{
  theScriptingKind = SIMPLE_EXPR;
}


const_expr::const_expr(
    static_context* sctx,
    const QueryLoc& aLoc, 
    const char* aNamespace,
    const char* aPrefix, 
    const char* aLocal)
  :
  expr(sctx, aLoc, const_expr_kind)
{
  GENV_ITEMFACTORY->createQName(theValue, aNamespace, aPrefix, aLocal);
  theScriptingKind = SIMPLE_EXPR;
}


void const_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (expr*)this);
  ar & theValue;
}


void const_expr::compute_scripting_kind()
{
  theScriptingKind = SIMPLE_EXPR;
}


expr_t const_expr::clone(substitution_t&) const
{
  return new const_expr(theSctx, get_loc(), theValue);
}


/*******************************************************************************

********************************************************************************/
pragma::pragma(store::Item_t name, std::string const& content)
  :
  theQName(name),
  theContent(content)
{
}


void pragma::serialize(::zorba::serialization::Archiver& ar)
{
  ar & theQName;
  ar & theContent;
}


extension_expr::extension_expr(
    static_context* sctx,
    const QueryLoc& loc)
  :
  expr(sctx, loc, extension_expr_kind)
{
  compute_scripting_kind();
}


extension_expr::extension_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr_t e)
  :
  expr(sctx, loc, extension_expr_kind),
  theExpr(e)
{
  compute_scripting_kind();
}


void extension_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (expr*)this);
  ar & thePragmas;
  ar & theExpr;
}


void extension_expr::compute_scripting_kind()
{
  checkNonUpdating(theExpr);

  theScriptingKind = theExpr->get_scripting_detail();

  if (is_vacuous())
    theScriptingKind = SIMPLE_EXPR;
}


expr_t extension_expr::clone(substitution_t& subst) const 
{
  rchandle<extension_expr> lClone(0);
  lClone = (
    theExpr == 0 ? new extension_expr(theSctx, get_loc())
                 : new extension_expr(theSctx, get_loc(), theExpr->clone()) );
  // pragm doesn't contain expressions. Thus, it is not cloned.
  for ( std::vector<rchandle<pragma> >::const_iterator lIter = thePragmas.begin();
        lIter != thePragmas.end();
        ++lIter ) 
  {
    lClone->add(*lIter);
  }
  return lClone.getp();
}


/////////////////////////////////////////////////////////////////////////
//                                                                     //
//	XQuery 1.1 expressions                                             //
//  [http://www.w3.org/TR/xquery-1.1/]                                 //
//                                                                     //
/////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
catch_clause::catch_clause()
{
}


void catch_clause::serialize(::zorba::serialization::Archiver& ar)
{
  //serialize_baseclass(ar, (SimpleRCObject*)this);
  ar & theNameTests;
  ar & theVarMap;
}


trycatch_expr::trycatch_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr_t tryExpr)
  :
  expr(sctx, loc, trycatch_expr_kind),
  theTryExpr(tryExpr)
{
  compute_scripting_kind();
}


void trycatch_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (expr*)this);
  ar & theTryExpr;
  ar & theCatchExprs;
  ar & theCatchClauses;
}


void trycatch_expr::add_catch_expr(expr_t e)
{
  theCatchExprs.insert(theCatchExprs.begin(), e);

  compute_scripting_kind();
}


void trycatch_expr::add_clause(catch_clause_t cc)
{
  theCatchClauses.insert(theCatchClauses.begin(), cc);
}


void trycatch_expr::compute_scripting_kind()
{
  theScriptingKind = SIMPLE_EXPR;

  theScriptingKind |= theTryExpr->get_scripting_detail();

  ulong numCatchClauses = (ulong)theCatchClauses.size();

  for (ulong i = 0; i < numCatchClauses; ++i) 
  {
    const expr* catchExpr = theCatchExprs[i].getp();

    short catchKind = catchExpr->get_scripting_detail();

    theScriptingKind |= catchKind;
  }

  theScriptingKind &= ~VACUOUS_EXPR;

  if (theScriptingKind & UPDATING_EXPR)
    theScriptingKind &= ~SIMPLE_EXPR;

  if (is_sequential(theScriptingKind))
    theScriptingKind &= ~SIMPLE_EXPR;

  checkScriptingKind();
}


catch_clause_t catch_clause::clone(expr::substitution_t& subst) const
{
  catch_clause_t lClause(new catch_clause());

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
    lClause->add_var((catch_clause::var_type)lIter->first, lIter->second.getp());
  }

  return lClause.getp();
}


expr_t trycatch_expr::clone(substitution_t& subst) const
{
  std::auto_ptr<trycatch_expr> lTryCatch(
      new trycatch_expr(theSctx, get_loc(), theTryExpr->clone(subst)));

  for (std::vector<expr_t>::const_iterator lIter = theCatchExprs.begin();
       lIter != theCatchExprs.end();
       ++lIter) 
  {
    lTryCatch->add_catch_expr((*lIter)->clone(subst));
  }

  for (uint32_t i = 0; i < clause_count(); ++i) 
  {
    lTryCatch->add_clause(theCatchClauses[i]->clone(subst));
  }

  return lTryCatch.release();
}


/*******************************************************************************

********************************************************************************/
eval_expr::eval_expr(
    static_context* sctx,
    const QueryLoc& loc, 
    const expr_t& e,
    expr_script_kind_t scriptingKind,
    namespace_context* nsCtx)
  :
  namespace_context_base_expr(sctx, loc, eval_expr_kind, nsCtx),
  theExpr(e),
  theInnerScriptingKind(scriptingKind),
  theDoNodeCopy(false)
{
  compute_scripting_kind();
}


void eval_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (namespace_context_base_expr*)this);
  ar & theExpr;
  ar & theVars;
  ar & theArgs;
  SERIALIZE_ENUM(expr_script_kind_t, theInnerScriptingKind);
  ar & theDoNodeCopy;
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


expr_t eval_expr::clone(substitution_t& s) const
{
  rchandle<eval_expr> new_eval = new eval_expr(theSctx, 
                                               theLoc, 
                                               theExpr->clone(s),
                                               theInnerScriptingKind,
                                               theNSCtx.getp());
  new_eval->setNodeCopy(theDoNodeCopy);

  for (csize i = 0; i < theVars.size(); ++i)
  {
    var_expr_t cloneVar = dynamic_cast<var_expr*>(theVars[i]->clone(s).getp());
    assert(cloneVar != NULL);
    new_eval->add_var(cloneVar, theArgs[i]->clone(s));
  }

  return new_eval.getp();
}


#ifdef ZORBA_WITH_DEBUGGER
/*******************************************************************************

********************************************************************************/
debugger_expr::debugger_expr(
    static_context* sctx,
    const QueryLoc& loc,
    const expr_t& aChild,
    namespace_context* nsCtx,
    bool aIsVarDeclaration)
  :
  namespace_context_base_expr(sctx, loc, debugger_expr_kind, nsCtx),
  theExpr(aChild),
  theIsVarDeclaration(aIsVarDeclaration)
{
  compute_scripting_kind();
}

void debugger_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (expr*)this);
  ar & theExpr;
  ar & theVars;
  ar & theArgs;
  ar & theIsVarDeclaration;
}


void debugger_expr::compute_scripting_kind()
{
  theScriptingKind = theExpr->get_scripting_detail();
}

#endif


/*******************************************************************************

********************************************************************************/
function_trace_expr::function_trace_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr_t aChild)
  :
  expr(sctx, loc, aChild->get_expr_kind()),
  theExpr(aChild)
{
  theKind = function_trace_expr_kind;
  bool modified;
  compute_return_type(false, &modified);
  compute_scripting_kind();
}


function_trace_expr::function_trace_expr(expr_t aExpr)
  :
  expr(aExpr->get_sctx(), aExpr->get_loc(), aExpr->get_expr_kind()),
  theExpr(aExpr)
{
  theKind = function_trace_expr_kind;
  bool modified;
  compute_return_type(false, &modified);
  compute_scripting_kind();
}


function_trace_expr::~function_trace_expr() 
{
}


void function_trace_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (expr*)this);
  ar & theExpr;
  ar & theFunctionName;
  ar & theFunctionLocation;
  ar & theFunctionCallLocation;
  ar & theFunctionArity;
}


void function_trace_expr::compute_scripting_kind()
{
  theScriptingKind = theExpr->get_scripting_detail();
}


expr_t function_trace_expr::clone(substitution_t& s) const
{
  return new function_trace_expr(theExpr->clone(s));
}



} /* namespace zorba */
/* vim:set et sw=2 ts=2: */
