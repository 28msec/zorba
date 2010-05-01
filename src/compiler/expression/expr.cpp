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

#include <typeinfo>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "zorbaerrors/Assert.h"
#include "zorbaerrors/error_manager.h"

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
#include "compiler/semantic_annotations/tsv_annotation.h"
#include "compiler/semantic_annotations/annotation_keys.h"
#include "compiler/parser/parse_constants.h"

#include "store/api/store.h"
#include "store/api/item_factory.h"

using namespace std;

namespace zorba 
{

SERIALIZABLE_CLASS_VERSIONS(global_binding)
END_SERIALIZABLE_CLASS_VERSIONS(global_binding)

SERIALIZABLE_CLASS_VERSIONS(AnnotationHolder)
END_SERIALIZABLE_CLASS_VERSIONS(AnnotationHolder)

SERIALIZABLE_CLASS_VERSIONS(expr)
END_SERIALIZABLE_CLASS_VERSIONS(expr)

SERIALIZABLE_CLASS_VERSIONS(sequential_expr)
END_SERIALIZABLE_CLASS_VERSIONS(sequential_expr)

SERIALIZABLE_CLASS_VERSIONS(catch_clause)
END_SERIALIZABLE_CLASS_VERSIONS(catch_clause)

SERIALIZABLE_CLASS_VERSIONS(trycatch_expr)
END_SERIALIZABLE_CLASS_VERSIONS(trycatch_expr)

SERIALIZABLE_CLASS_VERSIONS(eval_expr::eval_var)
END_SERIALIZABLE_CLASS_VERSIONS(eval_expr::eval_var)

SERIALIZABLE_CLASS_VERSIONS(eval_expr)
END_SERIALIZABLE_CLASS_VERSIONS(eval_expr)

SERIALIZABLE_CLASS_VERSIONS(wrapper_expr)
END_SERIALIZABLE_CLASS_VERSIONS(wrapper_expr)

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

SERIALIZABLE_CLASS_VERSIONS(exit_expr)
END_SERIALIZABLE_CLASS_VERSIONS(exit_expr)

SERIALIZABLE_CLASS_VERSIONS(flowctl_expr)
END_SERIALIZABLE_CLASS_VERSIONS(flowctl_expr)

SERIALIZABLE_CLASS_VERSIONS(while_expr)
END_SERIALIZABLE_CLASS_VERSIONS(while_expr)

SERIALIZABLE_CLASS_VERSIONS(OrderModifier)
END_SERIALIZABLE_CLASS_VERSIONS(OrderModifier)


/*******************************************************************************

********************************************************************************/

DEF_EXPR_ACCEPT (debugger_expr)
DEF_EXPR_ACCEPT (wrapper_expr)
DEF_EXPR_ACCEPT (sequential_expr)
DEF_EXPR_ACCEPT (promote_expr)
DEF_EXPR_ACCEPT (trycatch_expr)
DEF_EXPR_ACCEPT (eval_expr)
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
DEF_EXPR_ACCEPT (insert_expr)
DEF_EXPR_ACCEPT (delete_expr)
DEF_EXPR_ACCEPT (rename_expr)
DEF_EXPR_ACCEPT (replace_expr)
DEF_EXPR_ACCEPT (transform_expr)
DEF_EXPR_ACCEPT (exit_expr)
DEF_EXPR_ACCEPT (flowctl_expr)
DEF_EXPR_ACCEPT (while_expr)


static inline void checkNonUpdating(const expr* e)
{
  if (e != 0 && e->is_updating())
    ZORBA_ERROR_LOC(XUST0001, e->get_loc());
}


static inline void checkSimpleExpr(const expr* e)
{
  if (e != 0 && !e->is_simple() && !e->is_vacuous() && !e->is_sequential())
    ZORBA_ERROR_LOC(XUST0001, e->get_loc());
}


#define CLONE( e, s ) ((e) == NULL ? NULL : (e)->clone(s))



/*******************************************************************************
  Specific expr_iterator_data classes
********************************************************************************/

class sequential_expr_iterator_data : public expr_iterator_data 
{
public:
  checked_vector<expr_t>::iterator iter;

  sequential_expr_iterator_data(expr* e) : expr_iterator_data(e) {}
};


/*******************************************************************************

********************************************************************************/
sequential_expr::sequential_expr(static_context* sctx, const QueryLoc& loc)
  :
  expr(sctx, loc)
{
  compute_scripting_kind();
}


sequential_expr::sequential_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr_t first,
    expr_t second)
  :
  expr(sctx, loc)
{
  theArgs.push_back(first);
  theArgs.push_back(second);
  compute_scripting_kind();
}


sequential_expr::sequential_expr(
    static_context* sctx,
    const QueryLoc& loc,
    checked_vector<expr_t>& seq,
    expr_t result)
  :
  expr(sctx, loc),
  theArgs(seq)
{
  theArgs.push_back(result);
  compute_scripting_kind();
}


sequential_expr::sequential_expr(
    static_context* sctx,
    const QueryLoc& loc,
    checked_vector<expr_t>& seq)
  :
  expr(sctx, loc),
  theArgs(seq)
{
  compute_scripting_kind();
}


void sequential_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (expr*)this);
  ar & theArgs;
}


void sequential_expr::compute_scripting_kind() 
{
  theScriptingKind = SIMPLE_EXPR;
  bool vacuous = true;

  ulong numChildren = theArgs.size();

  for (ulong i = 0; i < numChildren; ++i)
  {
    expr_script_kind_t kind = theArgs[i]->get_scripting_kind();

    if (kind == SEQUENTIAL_EXPR || kind == UPDATE_EXPR)
    {
      theScriptingKind = SEQUENTIAL_EXPR;
      vacuous = false;
      break;
    }
    else if (kind == SIMPLE_EXPR)
    {
      vacuous = false;
    }
  }

  if (vacuous)
    theScriptingKind = VACUOUS_EXPR;
}


expr_iterator_data* sequential_expr::make_iter() 
{
  return new sequential_expr_iterator_data(this);
}


void sequential_expr::next_iter(expr_iterator_data& v) 
{
  BEGIN_EXPR_ITER2(sequential_expr);

  ITER_FOR_EACH(iter, theArgs.begin(), theArgs.end(), (*vv.iter));

  END_EXPR_ITER();
}


expr_t sequential_expr::clone(substitution_t& subst) const
{
  checked_vector<expr_t> seq2;
  for (unsigned i = 0; i < theArgs.size(); ++i)
    seq2.push_back(theArgs[i]->clone(subst));

  return new sequential_expr(theSctx, get_loc(), seq2);
}


/*******************************************************************************

********************************************************************************/
catch_clause::catch_clause()
{
}


void catch_clause::serialize(::zorba::serialization::Archiver& ar)
{
  //serialize_baseclass(ar, (SimpleRCObject*)this);
  ar & theNameTests;
  ar & theErrorCodeVar;
  ar & theErrorDescVar;
  ar & theErrorItemVar;
}


trycatch_expr::trycatch_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr_t tryExpr)
  :
  expr(sctx, loc),
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
  theScriptingKind = theTryExpr->get_scripting_kind();

  ulong numCatchClauses = theCatchClauses.size();

  for(ulong i = 0; i < numCatchClauses; ++i) 
  {
    const expr* catchExpr = theCatchExprs[i].getp();

    expr_script_kind_t catchKind = catchExpr->get_scripting_kind();

    if (theScriptingKind == UPDATE_EXPR)
    {
      if (catchKind == SEQUENTIAL_EXPR)
        ZORBA_ERROR_LOC(XUST0001, catchExpr->get_loc());
    }
    else if (theScriptingKind == SEQUENTIAL_EXPR)
    {
      if (catchKind == UPDATE_EXPR)
        ZORBA_ERROR_LOC(XUST0001, catchExpr->get_loc());
    }
    else if (theScriptingKind == VACUOUS_EXPR)
    {
      theScriptingKind = catchKind;
    }
  }
}


class trycatch_expr_iterator_data : public expr_iterator_data 
{
public:
  std::vector<expr_t>::iterator catch_iter;

  trycatch_expr_iterator_data(expr* e) : expr_iterator_data(e) {}
};


expr_iterator_data* trycatch_expr::make_iter() 
{
  return new trycatch_expr_iterator_data(this);
}


void trycatch_expr::next_iter(expr_iterator_data& v) 
{
  BEGIN_EXPR_ITER2(trycatch_expr);

  ITER(theTryExpr);

  for (vv.catch_iter = theCatchExprs.begin(); 
       vv.catch_iter != theCatchExprs.end();
       ++(vv.catch_iter))
  {
    ITER((*vv.catch_iter));
  }

  END_EXPR_ITER ();
}


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
  expr(sctx, loc),
  theThenExpr(thenExpr),
  theElseExpr(elseExpr)
{
  if (sctx != NULL &&
      !TypeOps::is_equal(*condExpr->get_return_type(),
                         *GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE))
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

  expr_script_kind_t thenKind = theThenExpr->get_scripting_kind();
  expr_script_kind_t elseKind = theElseExpr->get_scripting_kind();

  theScriptingKind = expr::scripting_kind_anding(thenKind, elseKind, theLoc);
}


expr_t if_expr::clone(substitution_t& subst) const 
{
  return new if_expr(theSctx,
                     get_loc(),
                     get_cond_expr()->clone(subst),
                     get_then_expr()->clone(subst),
                     get_else_expr()->clone(subst));
}


void if_expr::next_iter(expr_iterator_data& v) 
{
  BEGIN_EXPR_ITER();

  ITER(theCondExpr);
  ITER(theThenExpr);
  ITER(theElseExpr);

  END_EXPR_ITER();
}


/***************************************************************************//**

********************************************************************************/
order_expr::order_expr(
    static_context* sctx,
    const QueryLoc& loc,
    order_type_t type,
    expr_t inExpr)
  :
  expr(sctx, loc),
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
  theScriptingKind = theExpr->get_scripting_kind();
}


void order_expr::next_iter(expr_iterator_data& v) 
{
  BEGIN_EXPR_ITER();
  ITER(theExpr);
  END_EXPR_ITER();
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
    store::Item_t typeName,
    expr_t inExpr,
    rchandle<TypeManager> typemgr)
  :
  expr(sctx, loc),
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
  theScriptingKind = SIMPLE_EXPR;

  checkSimpleExpr(theExpr);
}


void validate_expr::next_iter(expr_iterator_data& v) 
{
  BEGIN_EXPR_ITER();
  ITER(theExpr);
  END_EXPR_ITER();
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



/*******************************************************************************
  Base for cast, treat, promote, castable, instanceof
********************************************************************************/
cast_or_castable_base_expr::cast_or_castable_base_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr_t input,
    xqtref_t type)
  :
  expr(sctx, loc),
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
  theScriptingKind = SIMPLE_EXPR;

  checkSimpleExpr(theInputExpr);
}


/***************************************************************************//**
  Base for cast, treat, promote
********************************************************************************/
cast_base_expr::cast_base_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr_t input,
    xqtref_t type)
  : 
  cast_or_castable_base_expr(sctx, loc, input, type)
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
  cast_base_expr(sctx, loc, inputExpr, type)
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


void cast_expr::next_iter(expr_iterator_data& v) 
{
  BEGIN_EXPR_ITER();
  ITER(theInputExpr);
  END_EXPR_ITER();
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
    XQUERY_ERROR err,
    bool check_prime)
  :
  cast_base_expr(sctx, loc, inputExpr, type),
  theError(err),
  theCheckPrime(check_prime)
{
}


void treat_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (cast_base_expr*)this);
  SERIALIZE_ENUM(XQUERY_ERROR, theError);
  ar & theCheckPrime;
}


void treat_expr::next_iter(expr_iterator_data& v) 
{
  BEGIN_EXPR_ITER();
  ITER(theInputExpr);
  END_EXPR_ITER();
}


expr_t treat_expr::clone(substitution_t& subst) const
{
  return new treat_expr(theSctx,
                        get_loc(),
                        get_input()->clone(subst), 
                        get_target_type(),
                        get_err(),
                        get_check_prime());
}


/***************************************************************************//**

********************************************************************************/
promote_expr::promote_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr_t input,
    xqtref_t type)
  :
  cast_base_expr(sctx, loc, input, type)
{
}


void promote_expr::next_iter(expr_iterator_data& v) 
{
  BEGIN_EXPR_ITER();
  ITER(theInputExpr);
  END_EXPR_ITER();
}


expr_t promote_expr::clone(substitution_t& subst) const
{
  return new promote_expr(theSctx, 
                          get_loc(),
                          get_input()->clone(subst),
                          get_target_type());
}


/***************************************************************************//**
  Base for castable, instanceof
********************************************************************************/
castable_base_expr::castable_base_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr_t input,
    xqtref_t type)
  :
  cast_or_castable_base_expr(sctx, loc, input, type)
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
  castable_base_expr (sctx, loc, inputExpr, type)
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


void castable_expr::next_iter(expr_iterator_data& v) 
{
  BEGIN_EXPR_ITER();
  ITER(theInputExpr);
  END_EXPR_ITER();
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
    xqtref_t type)
  :
  castable_base_expr(sctx, loc, inputExpr, type)
{
}


void instanceof_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (castable_base_expr*)this);
}


void instanceof_expr::next_iter(expr_iterator_data& v) 
{
  BEGIN_EXPR_ITER();
  ITER(theInputExpr);
  END_EXPR_ITER();  
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
    const namespace_context* aNCtx)
  :
  expr(sctx, loc),
  theInputExpr(inputExpr),
  theNCtx(const_cast<namespace_context*>(aNCtx)) 
{
  compute_scripting_kind();
}


void name_cast_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (expr*)this);
  ar & theInputExpr;
  ar & theNCtx;
}


void name_cast_expr::compute_scripting_kind()
{
  theScriptingKind = SIMPLE_EXPR;

  checkSimpleExpr(theInputExpr);
}


void name_cast_expr::next_iter(expr_iterator_data& v) 
{
  BEGIN_EXPR_ITER();
  ITER(theInputExpr);
  END_EXPR_ITER();
}


const namespace_context* name_cast_expr::get_namespace_context() const
{
  return theNCtx.getp();
}


expr_t name_cast_expr::clone(substitution_t& subst) const
{
  return new name_cast_expr(theSctx,
                            get_loc(),
                            get_input()->clone(subst),
                            get_namespace_context());
}


/***************************************************************************//**
  CompDocConstructor ::= "document" "{" Expr "}"
********************************************************************************/
doc_expr::doc_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr_t aContent)
  :
  expr(sctx, loc),
  theContent(aContent)
{
  compute_scripting_kind();
}


void doc_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (expr*)this);
  ar & theContent;
}


void doc_expr::compute_scripting_kind()
{
  theScriptingKind = SIMPLE_EXPR;

  checkSimpleExpr(theContent);
}


void doc_expr::next_iter(expr_iterator_data& v) 
{
  BEGIN_EXPR_ITER();
  ITER(theContent);
  END_EXPR_ITER();
}


expr_t doc_expr::clone(substitution_t& subst) const
{
  return new doc_expr(theSctx, get_loc(), CLONE(getContent(), subst));
}


/***************************************************************************//**

********************************************************************************/
elem_expr::elem_expr(
    static_context* sctx,
    const QueryLoc& aLoc,
    expr_t aQNameExpr,
    expr_t aAttrs,
    expr_t aContent,
    const namespace_context* aNSCtx)
  :
  expr(sctx, aLoc),
  theQNameExpr(aQNameExpr),
  theAttrs(aAttrs),
  theContent(aContent),
  theNSCtx(const_cast<namespace_context*>(aNSCtx))
{
  compute_scripting_kind();

  setUnfoldable(ANNOTATION_TRUE_FIXED);
}


elem_expr::elem_expr(
    static_context* sctx,
    const QueryLoc& aLoc,
    expr_t aQNameExpr,
    expr_t aContent,
    const namespace_context* aNSCtx)
  :
  expr(sctx, aLoc),
  theQNameExpr(aQNameExpr),
  theAttrs(0),
  theContent(aContent),
  theNSCtx(const_cast<namespace_context*>(aNSCtx))
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
}


const namespace_context* elem_expr::getNSCtx() const
{
  return theNSCtx.getp(); 
}


void elem_expr::compute_scripting_kind()
{
  theScriptingKind = SIMPLE_EXPR;

  checkSimpleExpr(theQNameExpr);
  checkSimpleExpr(theContent);
  checkSimpleExpr(theAttrs);
}


void elem_expr::next_iter(expr_iterator_data& v) 
{
  BEGIN_EXPR_ITER();
  ITER(theQNameExpr);
  ITER(theAttrs);
  ITER(theContent);
  END_EXPR_ITER();
}


expr_t elem_expr::clone(substitution_t& subst) const
{
  return new elem_expr(theSctx,
                       get_loc(),
                       CLONE(getQNameExpr(), subst),
                       CLONE(getAttrs(), subst),
                       CLONE(getContent(), subst),
                       getNSCtx());
}


/***************************************************************************//**

********************************************************************************/
attr_expr::attr_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr_t aQNameExpr,
    expr_t aValueExpr)
  :
  expr(sctx, loc),
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
  theScriptingKind = SIMPLE_EXPR;

  checkSimpleExpr(theQNameExpr);
  checkSimpleExpr(theValueExpr);
}


void attr_expr::next_iter(expr_iterator_data& v) 
{
  BEGIN_EXPR_ITER();
  ITER(theQNameExpr);
  ITER(theValueExpr);
  END_EXPR_ITER();
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
  expr(sctx, loc),
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
  theScriptingKind = SIMPLE_EXPR;

  checkSimpleExpr(theContentExpr);
}


void text_expr::next_iter(expr_iterator_data& v) 
{
  BEGIN_EXPR_ITER();
  ITER(theContentExpr);
  END_EXPR_ITER();
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
  expr(sctx, loc),
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
  theScriptingKind = SIMPLE_EXPR;

  checkSimpleExpr(theTargetExpr);
  checkSimpleExpr(theContentExpr);
}


void pi_expr::next_iter(expr_iterator_data& v) 
{
  BEGIN_EXPR_ITER();
  ITER(theTargetExpr);
  ITER(theContentExpr);
  END_EXPR_ITER();
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
  expr(sctx, loc),
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
  theScriptingKind = theWrappedExpr->get_scripting_kind();;
}


void wrapper_expr::next_iter(expr_iterator_data& v) 
{
  BEGIN_EXPR_ITER();
  ITER(theWrappedExpr);
  END_EXPR_ITER();
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
const_expr::const_expr(static_context* sctx, const QueryLoc& loc, xqpStringStore_t& v)
  :
  expr(sctx, loc)
{
  GENV_ITEMFACTORY->createString(theValue, v); 
  theScriptingKind = SIMPLE_EXPR;
}


const_expr::const_expr(static_context* sctx, const QueryLoc& loc, const std::string& v)
  :
  expr(sctx, loc)
{
  xqpStringStore_t tmp = new xqpStringStore(v);
  GENV_ITEMFACTORY->createString(theValue, tmp); 
  theScriptingKind = SIMPLE_EXPR;
}


const_expr::const_expr(static_context* sctx, const QueryLoc& loc, const char* v)
  :
  expr(sctx, loc)
{
  xqpStringStore_t tmp = new xqpStringStore(v);
  GENV_ITEMFACTORY->createString(theValue, tmp); 
  theScriptingKind = SIMPLE_EXPR;
}


const_expr::const_expr(static_context* sctx, const QueryLoc& loc, xqp_integer v)
  :
  expr(sctx, loc)
{
  GENV_ITEMFACTORY->createInteger(theValue, v);
  theScriptingKind = SIMPLE_EXPR;
}

const_expr::const_expr(
    static_context* sctx,
    const QueryLoc& loc,
    xqp_decimal v)
  :
  expr(sctx, loc)
{
  GENV_ITEMFACTORY->createDecimal(theValue, v);
  theScriptingKind = SIMPLE_EXPR;
}

const_expr::const_expr(
    static_context* sctx,
    const QueryLoc& loc,
    xqp_double v)
  :
  expr(sctx, loc)
{
  GENV_ITEMFACTORY->createDouble(theValue, v);
  theScriptingKind = SIMPLE_EXPR;
}


const_expr::const_expr(
    static_context* sctx,
    const QueryLoc& loc,
    xqp_boolean v)
  :
  expr(sctx, loc)
{
  GENV_ITEMFACTORY->createBoolean(theValue, v);
  theScriptingKind = SIMPLE_EXPR;
}


const_expr::const_expr(
    static_context* sctx,
    const QueryLoc& loc,
    store::Item_t v)
  :
  expr(sctx, loc),
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
  expr(sctx, aLoc)
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


void const_expr::next_iter(expr_iterator_data& v) 
{
  BEGIN_EXPR_ITER();
  END_EXPR_ITER();
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
  expr(sctx, loc)
{
  compute_scripting_kind();
}


extension_expr::extension_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr_t e)
  :
  expr(sctx, loc),
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


void extension_expr::next_iter(expr_iterator_data& v) 
{
  BEGIN_EXPR_ITER();
  ITER(theExpr);
  END_EXPR_ITER();
}


void extension_expr::compute_scripting_kind()
{
  theScriptingKind = SIMPLE_EXPR;

  checkSimpleExpr(theExpr);
}


/*******************************************************************************

********************************************************************************/
eval_expr::eval_var::eval_var(var_expr* ve)
  :
  varname(ve->get_name()),
  var_key(dynamic_context::var_key(ve)),
  type(ve->get_type())
{
}


void eval_expr::eval_var::serialize(::zorba::serialization::Archiver& ar)
{
  ar & varname;
  ar & var_key;
  ar & type;
}


void eval_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (expr*)this);
  ar & theExpr;
  ar & vars;
  ar & theArgs;
}


void eval_expr::compute_scripting_kind()
{
  theScriptingKind = theExpr->get_scripting_kind();
}


class eval_expr_iterator_data : public expr_iterator_data 
{
public:
  std::vector<expr_t>::iterator var_iter;

  eval_expr_iterator_data(expr* e) : expr_iterator_data(e) {}
};


expr_iterator_data* eval_expr::make_iter() 
{
  return new eval_expr_iterator_data(this);
}


void eval_expr::next_iter(expr_iterator_data& v) 
{
  BEGIN_EXPR_ITER2(eval_expr);
  ITER(theExpr);
  ITER_FOR_EACH(var_iter, theArgs.begin(), theArgs.end(), *vv.var_iter);
  END_EXPR_ITER();
}


/*******************************************************************************

********************************************************************************/
void debugger_expr::store_local_variables(checked_vector<varref_t>& aScopedVariables)
{
  std::set<const store::Item*> lQNames;
  checked_vector<varref_t>::reverse_iterator it;
  for ( it = aScopedVariables.rbegin(); it != aScopedVariables.rend(); ++it )
  {
    if ( lQNames.find((*it)->get_name()) == lQNames.end() )
    {
      lQNames.insert( (*it)->get_name() );
      varref_t lValue = (*it);
      varref_t lVariable(new var_expr(theSctx,
                                      theLoc,
                                      var_expr::eval_var,
                                      lValue->get_name() ) );
      lVariable->set_type( lValue->get_type() );
      add_var(eval_expr::eval_var(&*lVariable), lValue.getp());
    }
  }
}


class debugger_expr_iterator_data: public expr_iterator_data 
{
public:
  std::vector<expr_t>::iterator var_iter;
  
  debugger_expr_iterator_data(expr* e) : expr_iterator_data(e) {}
};


expr_iterator_data* debugger_expr::make_iter() 
{
  return new debugger_expr_iterator_data(this);
}


void debugger_expr::next_iter(expr_iterator_data& v) 
{
  BEGIN_EXPR_ITER2(debugger_expr);
  ITER(theExpr);
  ITER_FOR_EACH(var_iter, theArgs.begin(), theArgs.end(), *vv.var_iter);
  END_EXPR_ITER();
}  



/////////////////////////////////////////////////////////////////////////
//                                                                     //
//	Update expressions                                                 //
//  [http://www.w3.org/TR/xqupdate/]                                   //
//                                                                     //
/////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
insert_expr::insert_expr(
    static_context* sctx,
    const QueryLoc& loc,
    store::UpdateConsts::InsertType aType,
    expr_t aSourceExpr,
    expr_t aTargetExpr)
  :
	expr(sctx, loc),
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
  theScriptingKind = UPDATE_EXPR;

  checkNonUpdating(theSourceExpr);
  checkNonUpdating(theTargetExpr);
}


void insert_expr::next_iter(expr_iterator_data& v)
{
  BEGIN_EXPR_ITER();
  ITER(theSourceExpr);
  ITER(theTargetExpr);
  END_EXPR_ITER(); 
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
	expr(sctx, loc),
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
  theScriptingKind = UPDATE_EXPR;

  checkNonUpdating(theTargetExpr);
}


void delete_expr::next_iter(expr_iterator_data& v)
{
  BEGIN_EXPR_ITER();
  ITER(theTargetExpr);
  END_EXPR_ITER(); 
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
	expr(sctx, loc),
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
  theScriptingKind = UPDATE_EXPR;

  checkNonUpdating(theTargetExpr);
  checkNonUpdating(theReplaceExpr);
}


void replace_expr::next_iter(expr_iterator_data& v)
{
  BEGIN_EXPR_ITER();
  ITER(theTargetExpr);
  ITER(theReplaceExpr);
  END_EXPR_ITER();
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
	expr(sctx, loc),
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
  theScriptingKind = UPDATE_EXPR;

  checkNonUpdating(theTargetExpr);
  checkNonUpdating(theNameExpr);
}


void rename_expr::next_iter(expr_iterator_data& v)
{
  BEGIN_EXPR_ITER();
  ITER(theTargetExpr);
  ITER(theNameExpr);
  END_EXPR_ITER();
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


void copy_clause::serialize(::zorba::serialization::Archiver& ar)
{
  ar & theVar;
  ar & theExpr;
}


transform_expr::transform_expr(
    static_context* sctx,
	  const QueryLoc& loc,
    expr_t aModifyExpr,
    expr_t aReturnExpr)
  :
	expr(sctx, loc),
	theModifyExpr(aModifyExpr),
	theReturnExpr(aReturnExpr)
{
  compute_scripting_kind();
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
  compute_scripting_kind();
}


void transform_expr::setReturnExpr(expr* e)
{
  theReturnExpr = e;
  compute_scripting_kind();
}


void transform_expr::add_back(copy_clause_t c)
{
  theCopyClauses.push_back(c);
  compute_scripting_kind();
}


void transform_expr::compute_scripting_kind()
{
  theScriptingKind = SIMPLE_EXPR;

  ulong numCopyVars = theCopyClauses.size();

  for (ulong i = 0; i < numCopyVars; ++i)
  {
    checkNonUpdating(theCopyClauses[i]->getExpr());
  }

  if (theModifyExpr != NULL)
  {
    expr_script_kind_t modKind = theModifyExpr->get_scripting_kind();

    if (modKind != UPDATE_EXPR && modKind != VACUOUS_EXPR)
    {
      ZORBA_ERROR_LOC(XUST0002, theModifyExpr->get_loc());
    }
  }

  checkNonUpdating(theReturnExpr);
}


class transform_expr_iterator_data : public expr_iterator_data 
{
public:
  std::vector<rchandle<copy_clause> >::iterator clause_iter;
  transform_expr_iterator_data(expr* e) : expr_iterator_data(e) {}
};


expr_iterator_data* transform_expr::make_iter()
{
  return new transform_expr_iterator_data(this);
}


void transform_expr::next_iter(expr_iterator_data& v)
{
  BEGIN_EXPR_ITER2(transform_expr);

  ITER_FOR_EACH(clause_iter, theCopyClauses.begin(), theCopyClauses.end(),
                (*vv.clause_iter)->theExpr);

  ITER(theModifyExpr);
  ITER(theReturnExpr);

  END_EXPR_ITER();
} 


/////////////////////////////////////////////////////////////////////////
//                                                                     //
//	Scripting expressions                                              //
//  [http://www.w3.org/TR/xquery-sx-10/]                               //
//                                                                     //
/////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
exit_expr::exit_expr(static_context* sctx, const QueryLoc& loc, expr_t inExpr)
  :
  expr(sctx, loc),
  theExpr(inExpr)
{
  compute_scripting_kind();

  setUnfoldable(ANNOTATION_TRUE_FIXED);
}


void exit_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (expr*)this);
  ar & theExpr;
}


void exit_expr::compute_scripting_kind()
{
  if (theExpr->is_simple())
  {
    theScriptingKind = SIMPLE_EXPR;
  }
  if (theExpr->is_vacuous())
  {
    theScriptingKind = VACUOUS_EXPR;
  }
  else
  {
    theScriptingKind = SEQUENTIAL_EXPR;
  }
}


void exit_expr::next_iter(expr_iterator_data& v)
{
  BEGIN_EXPR_ITER();
  ITER(theExpr);
  END_EXPR_ITER();
}


expr_t exit_expr::clone(substitution_t& subst) const
{
  return new exit_expr(theSctx, get_loc(), get_value()->clone(subst));
}


/*******************************************************************************

********************************************************************************/
flowctl_expr::flowctl_expr(static_context* sctx, const QueryLoc& loc, enum action action)
  :
  expr(sctx, loc),
  theAction(action)
{
  compute_scripting_kind();

  setUnfoldable(ANNOTATION_TRUE_FIXED);
}


void flowctl_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (expr*)this);
  SERIALIZE_ENUM(enum action, theAction);
}


void flowctl_expr::compute_scripting_kind()
{
  theScriptingKind = SIMPLE_EXPR;
}


void flowctl_expr::next_iter(expr_iterator_data& v)
{
  BEGIN_EXPR_ITER();
  END_EXPR_ITER();
}


expr_t flowctl_expr::clone(substitution_t& subst) const
{
  return new flowctl_expr(theSctx, get_loc(), get_action());
}


/*******************************************************************************

********************************************************************************/
while_expr::while_expr(static_context* sctx, const QueryLoc& loc, expr_t body)
  : 
  expr(sctx, loc),
  theBody(body)
{
  compute_scripting_kind();
}


void while_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (expr*)this);
  ar & theBody;
}


void while_expr::compute_scripting_kind()
{
  sequential_expr* seq = static_cast<sequential_expr*>(theBody.getp());

  checkNonUpdating((*seq)[0]);

  theScriptingKind = theBody->get_scripting_kind();
}


void while_expr::next_iter(expr_iterator_data& v)
{
  BEGIN_EXPR_ITER();
  ITER(theBody);
  END_EXPR_ITER();
}


expr_t while_expr::clone(substitution_t& subst) const
{
  return new while_expr(theSctx, get_loc(), get_body()->clone(subst));
}


} /* namespace zorba */
/* vim:set ts=2 sw=2: */
