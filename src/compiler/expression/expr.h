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
#ifndef ZORBA_COMPILER_EXPR
#define ZORBA_COMPILER_EXPR

#include <string>
#include <vector>
#include <set>
#include <map>

#include "zorbautils/checked_vector.h"

#include "zorbatypes/xqpstring.h"
#include "zorbatypes/representations.h"

#include "zorbaerrors/errors.h"

#include "functions/signature.h"

#include "compiler/expression/var_expr.h"
#include "compiler/expression/flwor_expr.h"

#include "context/static_context.h"
#include "context/namespace_context.h"
#include "types/node_test.h"
#include "types/typeimpl.h"

#include <zorba/store_consts.h>
#include "store/api/fullText/ft_options.h"
#include "store/api/update_consts.h"
#include "store/api/item.h"

namespace zorba 
{

class expr_visitor;
class NodeNameTest;
class match_expr;
class signature;


/***************************************************************************//**
  imperative construct: do this, then that
********************************************************************************/
class sequential_expr : public expr
{
  checked_vector<expr_t> sequence;

public:
  SERIALIZABLE_CLASS(sequential_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(sequential_expr, expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  sequential_expr(short, const QueryLoc&);

  sequential_expr(short, const QueryLoc&, expr_t first, expr_t second);

  sequential_expr(short, const QueryLoc&, checked_vector<expr_t> seq, expr_t result);

  sequential_expr(short, const QueryLoc&, checked_vector<expr_t> seq);

  expr_kind_t get_expr_kind() const { return sequential_expr_kind; }

  bool cache_compliant() { return true; }

  unsigned size() const { return sequence.size (); }

  const expr_t& operator[](int i) const { return sequence [i]; }

  expr_t& operator[](int i) { invalidate(); return sequence [i]; }

  void push_back(expr_t expr) 
  {
    invalidate();
    sequence.push_back(expr);
    compute_upd_seq_kind();
  }

  void push_front(expr_t front) 
  {
    invalidate();
    sequence.insert(sequence.begin(), front);
    compute_upd_seq_kind();
  }

  void compute_upd_seq_kind() const;

  xqtref_t return_type_impl(static_context *);

  expr_iterator_data *make_iter();

  void next_iter(expr_iterator_data&);

  virtual expr_t clone(substitution_t& s);

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;
};


/*******************************************************************************
  [68] IfExpr ::= "if" "(" Expr ")" "then" ExprSingle "else" ExprSingle
********************************************************************************/
class if_expr : public expr 
{
protected:
  expr_t theCondExpr;
  expr_t theThenExpr;
  expr_t theElseExpr;

public:
  SERIALIZABLE_CLASS(if_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(if_expr, expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  if_expr(
        short sctxid,
        const QueryLoc& loc,
        static_context* sctx,
        expr_t c,
        expr_t t,
        expr_t e);

  expr_kind_t get_expr_kind() const { return if_expr_kind; }

  bool cache_compliant() { return true; }
  
  expr* get_cond_expr() { invalidate(); return theCondExpr; }

  expr* get_then_expr() { invalidate(); return theThenExpr; }

  expr* get_else_expr() { invalidate(); return theElseExpr; }

  const expr* get_cond_expr() const { return theCondExpr; }

  const expr* get_then_expr() const { return theThenExpr; }

  const expr* get_else_expr() const { return theElseExpr; }

  xqtref_t return_type_impl(static_context* sctx);

  void compute_upd_seq_kind() const;

  virtual expr_t clone(substitution_t& s);

  void next_iter(expr_iterator_data&);

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;
};


/***************************************************************************//**

********************************************************************************/
class order_expr : public expr 
{
public:
  enum order_type_t 
  {
    ordered,
    unordered
  };

protected:
  order_type_t theType;
  expr_t       theExpr;

public:
  SERIALIZABLE_CLASS(order_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(order_expr, expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  order_expr(short sctx, const QueryLoc&, order_type_t, expr_t);

  expr_kind_t get_expr_kind() const { return order_expr_kind; }

  order_type_t get_type() const { return theType; }
  expr_t get_expr() const { return theExpr; }

  xqtref_t return_type_impl(static_context* sctx);

  expr_t clone(substitution_t& s);

  void next_iter(expr_iterator_data&);

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;
};


/***************************************************************************//**

********************************************************************************/
class validate_expr : public expr 
{
protected:
  ParseConstants::validation_mode_t theMode;
  store::Item_t                     theTypeName;
  rchandle<TypeManager>             theTypeMgr;
  expr_t                            theExpr;

public:
  SERIALIZABLE_CLASS(validate_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(validate_expr, expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  validate_expr(
        short sctx,
        const QueryLoc&,
        ParseConstants::validation_mode_t,
        store::Item_t aTypeName,
        expr_t,
        rchandle<TypeManager>);

  expr_kind_t get_expr_kind() const { return validate_expr_kind; }

  expr_t get_expr() const { return theExpr; }

  store::Item_t get_type_name() { return theTypeName; }

  TypeManager* get_typemgr() const { return theTypeMgr.getp(); }

  ParseConstants::validation_mode_t get_valmode() const { return theMode; }

  xqtref_t return_type_impl(static_context* sctx);

  void next_iter(expr_iterator_data&);

  expr_t clone(substitution_t& s);

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;
};


/***************************************************************************//**
  Base for cast, treat, promote, castable, instanceof
********************************************************************************/
class cast_or_castable_base_expr : public expr 
{
protected:
  expr_t   theInputExpr;
  xqtref_t theTargetType;

protected:
  cast_or_castable_base_expr(
        short sctx,
        const QueryLoc& loc,
        expr_t input,
        xqtref_t type);
  
public:
  SERIALIZABLE_ABSTRACT_CLASS(cast_or_castable_base_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(cast_or_castable_base_expr, expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  bool cache_compliant() { return true; }

  expr_t get_input() { invalidate(); return theInputExpr; }

  void set_input(expr_t input) { invalidate(); theInputExpr = input; }
  
  xqtref_t get_target_type() const;

  void set_target_type(xqtref_t target);

  void compute_upd_seq_kind() const;
};


/***************************************************************************//**
  Base for cast, treat, promote
********************************************************************************/
class cast_base_expr : public cast_or_castable_base_expr 
{
public:
  SERIALIZABLE_ABSTRACT_CLASS(cast_base_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(cast_base_expr, cast_or_castable_base_expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  cast_base_expr(short sctx, const QueryLoc& loc, expr_t input, xqtref_t type);

  xqtref_t return_type_impl(static_context* sctx);
};


/***************************************************************************//**
  CastExpr ::= UnaryExpr ( "cast" "as" SingleType )?

  SingleType ::= AtomicType "?"?
********************************************************************************/
class cast_expr : public cast_base_expr 
{
public:
  SERIALIZABLE_CLASS(cast_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(cast_expr, cast_base_expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  cast_expr(short sctx, const QueryLoc&, expr_t, xqtref_t);

  expr_kind_t get_expr_kind() const { return cast_expr_kind; }

  bool is_optional() const;

  void next_iter(expr_iterator_data&);

  expr_t clone(substitution_t& s);

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;
};


/***************************************************************************//**
	TreatExpr ::= CastableExpr ( "treat" "as" SequenceType )?

  theCheckPrime : Normally, this is true. If false, then during runtime, only
                  the cardinality of theInputExpr will be checked w.r.t. the
                  quantifier of theTargetType. theCheckPrime is set to false
                  by the optimizer, if it discovers that the prime type of the
                  static type of theInputExpr is a subtype of the prime type of
                  theTargetType.
********************************************************************************/
class treat_expr : public cast_base_expr 
{
protected:
  XQUERY_ERROR theError;
  bool check_prime;

public:
  SERIALIZABLE_CLASS(treat_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(treat_expr, cast_base_expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  treat_expr(
        short sctx, 
        const QueryLoc&,
        expr_t,
        xqtref_t,
        XQUERY_ERROR,
        bool check_prime = true);

  expr_kind_t get_expr_kind() const { return treat_expr_kind; }

  XQUERY_ERROR get_err() { return theError; }

  bool get_check_prime() { return check_prime; }

  void set_check_prime(bool check_prime_) { check_prime = check_prime_; }

  xqtref_t return_type_impl(static_context* sctx);  

  void next_iter(expr_iterator_data&);

  expr_t clone(substitution_t& s);

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;
};


/***************************************************************************//**
  This is an internal zorba expr. Its semantics are the following:

  1. Let "input sequence" be the result of theInputExpr, and "output sequence"
     be the result of the promote_expr.

  2. Raise error if the cardinality of the input sequence is not compatible with
     the quantifier of theTargetType.

  3. For each item I in the input sequence, let F(I) be the result of the
     function defined as follows:

     - Let "actual type" be the dynamic type of I, and "target type" be the prime
       type of theTargetType.
     - If the target type is the NONE type, F(I) = error, else
     - If the actual type is a subtype of the target type, F(I) = I, else
     - If the target type is not an atomic type, F(I) = error, else
     - If the actual type is untypedAtomic and the target type is not QName, 
       F(I) = cast(I, target type), else
     - If the actual type is (subtype of) decimal and the target type is float,
       F(I) = cast(I, target type), else
     - If the actual type is (subtype of) decimal or float and the target type is double,
       F(I) = cast(I, target type), else
     - If the actual type is anyURI and the target type is string,
       F(I) = cast(I, string), else
     - F(I) = error

  4. Put F(I) in the output sequence.
********************************************************************************/
class promote_expr : public cast_base_expr
{
public:
  SERIALIZABLE_CLASS(promote_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(promote_expr, cast_base_expr)
  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar, (cast_base_expr*)this);
  }

public:
  promote_expr(short sctx, const QueryLoc& loc, expr_t input, xqtref_t type);

  expr_kind_t get_expr_kind() const { return promote_expr_kind; }

  xqtref_t return_type_impl(static_context* sctx);

  void next_iter(expr_iterator_data&);

  expr_t clone(substitution_t& s);

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;
};


/***************************************************************************//**
  Base for castable, instanceof
********************************************************************************/
class castable_base_expr : public cast_or_castable_base_expr 
{
public:
  SERIALIZABLE_ABSTRACT_CLASS(castable_base_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(castable_base_expr, cast_or_castable_base_expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  castable_base_expr(short sctx, const QueryLoc&, expr_t, xqtref_t);

  xqtref_t return_type_impl(static_context* sctx);
};


/***************************************************************************//**
  CastableExpr ::= CastExpr ( "castable" "as" SingleType )?

  SingleType ::= AtomicType "?"?
********************************************************************************/
class castable_expr : public castable_base_expr 
{
public:
  SERIALIZABLE_CLASS(castable_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(castable_expr, castable_base_expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  castable_expr(short sctx, const QueryLoc&, expr_t, xqtref_t);
  
  expr_kind_t get_expr_kind() const { return castable_expr_kind; }

  bool is_optional() const;

  void next_iter(expr_iterator_data&);

  expr_t clone(substitution_t& s);

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;
};


/***************************************************************************//**
	InstanceofExpr ::= TreatExpr ( "instance" "of" SequenceType )?
********************************************************************************/
class instanceof_expr : public castable_base_expr 
{
public:
  SERIALIZABLE_CLASS(instanceof_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(instanceof_expr, castable_base_expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  instanceof_expr(short sctx, const QueryLoc&, expr_t, xqtref_t);

  expr_kind_t get_expr_kind() const { return instanceof_expr_kind; }

  void next_iter(expr_iterator_data&);

  expr_t clone(substitution_t& s);

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;
};


/***************************************************************************//**
  Casts the result of theInputExpr to a qname item. theInputExpr must return
  exactly one item. If that item is a qname, it is simply returned to the
  consumer iterator. If the input item is a string or an untyped item, it is
  cast, if possible, to qname using the prefix-to-ns bindings in theNCtx.

  This is an internal zorba expr. It is used in the case of computed element or
  attribute constructors when the name of the element/attribute is not a const
  expr.
********************************************************************************/
class name_cast_expr : public expr 
{
private:
  expr_t             theInputExpr;
  NamespaceContext_t theNCtx;

public:
  SERIALIZABLE_CLASS(name_cast_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(name_cast_expr, expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  name_cast_expr(short sctx, const QueryLoc&, expr_t, NamespaceContext_t);

  expr_kind_t get_expr_kind() const { return name_cast_expr_kind; }

  expr_t get_input() { return theInputExpr; }

  NamespaceContext_t getNamespaceContext();

  void next_iter(expr_iterator_data&);

  expr_t clone(substitution_t& s);

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;
};


/***************************************************************************//**
  CompDocConstructor ::= "document" "{" Expr "}"
********************************************************************************/
class doc_expr : public expr 
{
protected:
  expr_t theContent;

public:
  SERIALIZABLE_CLASS(doc_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(doc_expr, expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  doc_expr(short sctx, const QueryLoc&, expr_t aContent);

  expr_kind_t get_expr_kind() const { return doc_expr_kind; }

  expr_t getContent() const { return theContent; }

  xqtref_t return_type_impl(static_context* sctx);

  void next_iter(expr_iterator_data&);

  expr_t clone(substitution_t& s);

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;
};



/***************************************************************************//**

  CompElemConstructor ::= "element" (QName | ("{" Expr "}")) "{" Expr? "}"


  DirElemConstructor ::= "<" QName DirAttributeList?
                         ("/>" |
                          (">" DirElemContentList? "</" QName S? ">"))

  DirElemContentList ::= DirElemContent+

  DirElemContent ::= DirectConstructor |
                     CDataSection |
                     CommonContent |
                     ElementContentChar

  CDataSection ::= "<![CDATA[" CDataSectionContents "]]>"

  CDataSectionContents ::= (Char* - (Char* ']]>' Char*))

  ElementContentChar ::= Char - [{}<&]

  CommonContent ::= PredefinedEntityRef | CharRef | "{{" | "}}" | EnclosedExpr

********************************************************************************/
class elem_expr : public expr 
{
protected:
  expr_t theQNameExpr;
  expr_t theAttrs;
  expr_t theContent;
  rchandle<namespace_context> theNSCtx;
  
public:
  SERIALIZABLE_CLASS(elem_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(elem_expr, expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  elem_expr(
        short sctx,
        const QueryLoc&,
        expr_t aQNameExpr,
        expr_t aAttrs,
        expr_t aContent,
        rchandle<namespace_context> aNSCtx);
  
  elem_expr(
        short sctx,
        const QueryLoc&,
        expr_t aQNameExpr,
        expr_t aContent,
        rchandle<namespace_context> aNSCtx);
  
  expr_kind_t get_expr_kind() const { return elem_expr_kind; }
  
  expr_t getQNameExpr() const { return theQNameExpr; }

  void setQNameExpr(expr_t aQNameExpr) { theQNameExpr = aQNameExpr; }

  expr_t getContent() const { return theContent; }

  expr_t getAttrs() const { return theAttrs; }

  namespace_context* getNSCtx() const;
  
  xqtref_t return_type_impl(static_context *);

  void next_iter(expr_iterator_data&);

  expr_t clone(substitution_t& s);  

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;
};


/******************************************************************************

  CompAttrConstructor ::= "attribute" (QName | ("{" Expr "}")) "{" Expr? "}"

  DirAttr ::= (S (QName S? "=" S? DirAttributeValue)

  DirAttributeValue ::= '"' QuoteAttrContentList? '"' |
                        "'" AposAttrContentList? "'"

  QuoteAttrContentList ::= QuotAttrValueContent+

  AposAttrContentList ::= AposAttrValueContent+

  QuotAttrValueContent ::= EscapeQuot | QuotAttrContentChar | CommonContent

  AposAttrValueContent ::= EscapeApos | AposAttrContentChar | CommonContent

  QuotAttrContentChar ::= Char - ["{}<&]

  AposAttrContentChar ::= Char - ['{}<&]

  CommonContent ::= PredefinedEntityRef | CharRef | "{{" | "}}" | EnclosedExpr

********************************************************************************/
class attr_expr : public expr 
{
protected:
  expr_t theQNameExpr;
  expr_t theValueExpr;

public:
  SERIALIZABLE_CLASS(attr_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(attr_expr, expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  attr_expr(
    short sctx,
    const QueryLoc& loc,
    expr_t aQNameExpr,
    expr_t aValueExpr);

  expr_kind_t get_expr_kind() const { return attr_expr_kind; }

  expr_t getQNameExpr() const { return theQNameExpr; }

  void setQNameExpr(expr_t aQNameExpr) { theQNameExpr = aQNameExpr; }

  expr_t getValueExpr() const { return theValueExpr; }

  void setValueExpr(expr_t aValueExpr) { theValueExpr = aValueExpr; }

  store::Item* getQName() const;

  xqtref_t return_type_impl(static_context* sctx);

  void next_iter(expr_iterator_data&);

  expr_t clone(substitution_t& s);

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;
};


/***************************************************************************//**

********************************************************************************/
class text_expr : public expr 
{
public:
  typedef enum 
  {
    text_constructor,
    comment_constructor
  } text_constructor_type;

protected:
  text_constructor_type type;
  expr_t                theContentExpr;

public:
  SERIALIZABLE_CLASS(text_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(text_expr, expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  text_expr(
        short sctx,
        const QueryLoc&,
        text_constructor_type,
        expr_t);

  expr_kind_t get_expr_kind() const { return text_expr_kind; }

  expr_t get_text() const { return theContentExpr; }

  text_constructor_type get_type() const { return type; }

  xqtref_t return_type_impl(static_context* sctx);

  void next_iter(expr_iterator_data&);

  expr_t clone(substitution_t& s);  

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;
};


/***************************************************************************//**

********************************************************************************/
class pi_expr : public expr 
{
protected:
  expr_t theTargetExpr;
  expr_t theContentExpr;

public:
  SERIALIZABLE_CLASS(pi_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(pi_expr, expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  pi_expr(short sctx, const QueryLoc&, expr_t, expr_t);
 
  expr_kind_t get_expr_kind() const { return pi_expr_kind; }
 
  expr_t get_target_expr() const { return theTargetExpr; }

  expr_t get_content_expr() const { return theContentExpr; }
  
  xqtref_t return_type_impl(static_context* sctx);

  void next_iter(expr_iterator_data&);

  expr_t clone(substitution_t& s);  

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;
};


/*******************************************************************************
  first-order expressions
********************************************************************************/
class fo_expr : public expr 
{
protected:
  checked_vector<expr_t>   theArgs;
  function               * theFunction;

public:
  SERIALIZABLE_CLASS(fo_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(fo_expr, expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  static fo_expr* create_seq(short sctx, const QueryLoc &);

public:
  fo_expr(short sctx, const QueryLoc& loc, function* f);

  fo_expr(short sctx, const QueryLoc& loc, function* f, expr_t arg);

  fo_expr(short sctx, const QueryLoc& loc, function* f, expr_t arg1, expr_t arg2);

  fo_expr(short sctx, const QueryLoc& loc, function* f, const std::vector<expr_t>& args);

  expr_kind_t get_expr_kind() const { return fo_expr_kind; }

  bool cache_compliant() { return true; }

  const function* get_func() const { return theFunction; }

  function* get_func() { invalidate(); return theFunction; }

  void set_func(function* f) { invalidate(); theFunction = f; }

  const signature& get_signature() const;

  store::Item_t get_fname() const;

  uint32_t size() const { return theArgs.size(); }

  expr_t& operator[](int i) { invalidate(); return theArgs[i]; }

  const expr_t& operator[](int i) const { return theArgs[i]; }

  std::vector<expr_t>::const_iterator begin() const { return theArgs.begin(); }

  std::vector<expr_t>::const_iterator end() const { return theArgs.end(); }

  std::vector<expr_t>::iterator begin() { invalidate(); return theArgs.begin(); }

  std::vector<expr_t>::iterator end() { invalidate(); return theArgs.end(); }

  expr_iterator_data* make_iter();

  void next_iter(expr_iterator_data&);

  xqtref_t return_type_impl(static_context* sctx);

  void compute_upd_seq_kind() const;

  expr_t clone(substitution_t& s);

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;
};


/*******************************************************************************
  Normally, it is used to wrap a var_expr in order to represent a var reference
  (see var_expr.h). But it may wrap any other kind of expr as well.
********************************************************************************/
class wrapper_expr : public expr 
{
  expr_t theWrappedExpr;

public:
  SERIALIZABLE_CLASS(wrapper_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(wrapper_expr, expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  wrapper_expr(short sctx, const QueryLoc& loc, expr_t wrapped);

  expr_kind_t get_expr_kind() const { return wrapper_expr_kind; }

  expr_t get_expr() const { return theWrappedExpr; }

  void set_expr(expr* e) { theWrappedExpr = e; }

  void compute_upd_seq_kind() const;

  void next_iter(expr_iterator_data&);

  void accept(expr_visitor&);

  xqtref_t return_type_impl(static_context* sctx);

  expr_t clone(substitution_t& s);

  std::ostream& put(std::ostream&) const;
};


/***************************************************************************//**

********************************************************************************/
class const_expr : public expr 
{
protected:
  store::Item_t theValue;

public:
  SERIALIZABLE_CLASS(const_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(const_expr, expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  const_expr(short sctx, const QueryLoc&, xqpString sval);

  const_expr(short sctx, const QueryLoc&, xqp_integer);

  const_expr(short sctx, const QueryLoc&, xqp_decimal);

  const_expr(short sctx, const QueryLoc&, xqp_double);

  const_expr(short sctx, const QueryLoc&, xqp_boolean);

  const_expr(short sctx, const QueryLoc&, store::Item_t);  

  const_expr(short sctx, const QueryLoc&, const char* ns, const char* pre, const char* local);

  expr_kind_t get_expr_kind() const { return const_expr_kind; }

  store::Item_t get_val() const { return theValue; }

  xqtref_t return_type_impl(static_context* sctx);

  void next_iter(expr_iterator_data&);

  expr_t clone(substitution_t& s);

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;
};


/***************************************************************************//**

********************************************************************************/
class catch_clause : public SimpleRCObject 
{
  friend class trycatch_expr;
  public:
    typedef rchandle<NodeNameTest> nt_t;
    typedef std::vector<nt_t> nt_list_t;
  protected:
    nt_list_t nametests_h;
    varref_t errorcode_var_h;
    varref_t errordesc_var_h;
    varref_t errorobj_var_h;
    expr_t catch_expr_h;

  public:
    SERIALIZABLE_CLASS(catch_clause)
    SERIALIZABLE_CLASS_CONSTRUCTOR2(catch_clause, SimpleRCObject)
    void serialize(::zorba::serialization::Archiver &ar)
    {
      //serialize_baseclass(ar, (SimpleRCObject*)this);
      ar & nametests_h;
      ar & errorcode_var_h;
      ar & errordesc_var_h;
      ar & errorobj_var_h;
      ar & catch_expr_h;
    }
  public:
    catch_clause();

    void set_nametests(nt_list_t& a) { nametests_h = a; }
    nt_list_t& get_nametests() { return nametests_h; }

    void add_nametest_h(nt_t n) { nametests_h.push_back(n); }

    void set_errorcode_var_h(varref_t a) { errorcode_var_h = a; }
    varref_t get_errorcode_var_h() const { return errorcode_var_h; }

    void set_errordesc_var_h(varref_t a) { errordesc_var_h = a; }
    varref_t get_errordesc_var_h() const { return errordesc_var_h; }

    void set_errorobj_var_h(varref_t a) { errorobj_var_h = a; }
    varref_t get_errorobj_var_h() const { return errorobj_var_h; }

    void set_catch_expr_h(expr_t a) { catch_expr_h = a; }
    expr_t get_catch_expr_h() const { return catch_expr_h; }
};


class trycatch_expr : public expr 
{
public:
  expr_kind_t get_expr_kind () const { return trycatch_expr_kind; }

public:
    typedef rchandle<catch_clause> clauseref_t;

protected:
    expr_t try_expr_h;
    std::vector<clauseref_t> catch_clause_hv;

public:
  SERIALIZABLE_CLASS(trycatch_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(trycatch_expr, expr)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (expr*)this);
    ar & try_expr_h;
    ar & catch_clause_hv;
  }
public:
    trycatch_expr(short sctx, const QueryLoc&);

    expr_t get_try_expr() const
    { return try_expr_h; }
    void set_try_expr(expr_t e_h)
    { try_expr_h = e_h; }

    void add_clause(clauseref_t cc_h)
    { catch_clause_hv.push_back(cc_h); }

    void add_clause_in_front(clauseref_t cc_h)
    { catch_clause_hv.insert(catch_clause_hv.begin(), cc_h); }

    std::vector<clauseref_t>::const_iterator begin() const
    { return catch_clause_hv.begin(); }
    std::vector<clauseref_t>::const_iterator end() const
    { return catch_clause_hv.end(); }
    std::vector<clauseref_t>::iterator begin()
    { return catch_clause_hv.begin(); }
    std::vector<clauseref_t>::iterator end()
    { return catch_clause_hv.end(); }

    uint32_t clause_count() const
    { return catch_clause_hv.size(); }

    clauseref_t & operator[](int i)
    { return catch_clause_hv[i]; }
    clauseref_t const& operator[](int i) const
    { return catch_clause_hv[i]; }

    expr_iterator_data *make_iter ();

    void next_iter (expr_iterator_data&);
    void accept (expr_visitor&);
    std::ostream& put(std::ostream&) const;
};


/***************************************************************************//**

********************************************************************************/
class eval_expr : public expr 
{
public:
  class eval_var : public ::zorba::serialization::SerializeBaseClass
  {
  public:
    store::Item_t varname;
    std::string var_key;
    xqtref_t type;
    expr_t val;
  public:
    SERIALIZABLE_CLASS(eval_var)
    SERIALIZABLE_CLASS_CONSTRUCTOR(eval_var)
    void serialize(::zorba::serialization::Archiver &ar)
    {
      ar & varname;
      ar & var_key;
      ar & type;
      ar & val;
    }

    eval_var() {}
    eval_var (var_expr *ve, expr_t val);
    virtual ~eval_var() {}
  };

protected:
  expr_t expr_h;
  checked_vector<eval_var> vars;

public:
  SERIALIZABLE_CLASS(eval_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(eval_expr, expr)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (expr*)this);
    ar & expr_h;
    ar & vars;
  }
public:
  expr_kind_t get_expr_kind () const { return eval_expr_kind; }

  eval_expr (short sctx, const QueryLoc &loc, expr_t expr_)
    : expr (sctx, loc), expr_h (expr_)
  {}

  checked_vector<eval_var> &get_vars () { return vars; }

  const expr_t &get_expr () const { return expr_h; }
  expr_t get_expr () { return expr_h; }

  unsigned var_count () const { return vars.size (); }
  eval_var &var_at (unsigned i) { return vars [i]; }

  void add_var (eval_var var) { vars.push_back (var); }

  expr_iterator_data *make_iter ();
  void next_iter (expr_iterator_data&);
  void accept (expr_visitor&);
  std::ostream& put(std::ostream&) const;
};


//debugger expression
class debugger_expr: public eval_expr
{
public:
  expr_kind_t get_expr_kind () const { return debugger_expr_kind; }

private:
  std::list<global_binding> theGlobals;
  bool theForExpr;

public:
  debugger_expr(short sctx, const QueryLoc& loc, expr_t aChild, std::list<global_binding> aGlobals )
    : eval_expr(sctx, loc, aChild ), theGlobals( aGlobals ){}

  debugger_expr( short sctx, const QueryLoc& loc, expr_t aChild,
    checked_vector<varref_t> aScopedVariables,
    std::list<global_binding> aGlobals,
    bool aForExpr = false):
  eval_expr(sctx, loc, aChild ), theGlobals( aGlobals ), theForExpr(aForExpr)
  {
    store_local_variables( aScopedVariables );
  }

  expr_iterator_data *make_iter();
  void next_iter (expr_iterator_data&);
  void accept (expr_visitor&);
  std::ostream& put(std::ostream&) const;

  std::list<global_binding> getGlobals() const
  {
    return theGlobals;
  }

  bool isForExpr() const { return theForExpr; }

private:
  void store_local_variables(checked_vector<varref_t> &aScopedVariables)
  {
    std::set<store::Item_t> lQNames;
    checked_vector<varref_t>::reverse_iterator it;
    for ( it = aScopedVariables.rbegin(); it != aScopedVariables.rend(); ++it )
    {
      if ( lQNames.find( (*it)->get_varname() ) == lQNames.end() )
      {
        lQNames.insert( (*it)->get_varname() );
        varref_t lValue = (*it);
        varref_t lVariable(new var_expr(theSctxId, loc, var_expr::eval_var, lValue->get_varname() ) );
        lVariable->set_type( lValue->get_type() );
        add_var(eval_expr::eval_var(&*lVariable, lValue.getp()));
      }
    }
  }
};



/***************************************************************************//**

********************************************************************************/
class pragma : public SimpleRCObject
{
public:
  store::Item_t name_h;
  std::string content;

public:
  SERIALIZABLE_CLASS(pragma)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(pragma, SimpleRCObject)
  void serialize(::zorba::serialization::Archiver& ar)
  {
    ar & name_h;
    ar & content;
  }

public:
  pragma(store::Item_t _name_h, std::string const& _content)
    :
    name_h(_name_h),
    content(_content)
  {
  }
};


/***************************************************************************//**

********************************************************************************/
class extension_expr : public expr 
{
protected:
  rchandle<pragma> pragma_h;
  expr_t expr_h;

public:
  SERIALIZABLE_CLASS(extension_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(extension_expr, expr)
  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar, (expr*)this);
    ar & pragma_h;
    ar & expr_h;
  }

public:
  extension_expr(short sctx, const QueryLoc&);

  extension_expr(short sctx, const QueryLoc&, expr_t);

  expr_kind_t get_expr_kind () const { return extension_expr_kind; }

  void add(rchandle<pragma> _pragma_h) { pragma_h = _pragma_h; }

  void add(expr_t _expr_h) { expr_h = _expr_h; }

  expr_t get_expr() const { return expr_h; }

  void next_iter (expr_iterator_data&);

  // TODO clone ????

  void accept (expr_visitor&);

  std::ostream& put(std::ostream&) const;
};



/*******************************************************************************

  PathExpr ::= 	("/" RelativePathExpr?) |
                ("//" RelativePathExpr) |
                RelativePathExpr

  RelativePathExpr ::= StepExpr (("/" | "//") StepExpr)*


  Formal Semantics [http://www.w3.org/TR/xquery-semantics]:
    /    == fn:root(self::node())
    /A   == fn:root(self::node())/A
    //A  == fn:root(self::node())/descendant-or-self::node()/A
    A//B == A/descendant-or-self::node()/B
  This implies that all path expressions are relative path expressions. So a
  relative path is defined as follows:

 RelativPathExpr ::= "/" | ("/" | "//")?  StepExpr (("/" | "//") StepExpr)*

********************************************************************************/
class relpath_expr : public expr 
{
protected:
  std::vector<expr_t> theSteps;
  long                theTargetPos;

public:
  SERIALIZABLE_CLASS(relpath_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(relpath_expr, expr)
  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar, (expr*)this);
    ar & theSteps;
    ar & theTargetPos;
  }
public:
  relpath_expr(short sctx, const QueryLoc& loc);

  expr_kind_t get_expr_kind () const { return relpath_expr_kind; }

	size_t size() const          { return theSteps.size(); }
	void add_back(expr_t step)   { theSteps.push_back(step); }
  void erase(ulong i)          { theSteps.erase(theSteps.begin() + i); }

  ulong numSteps() const       { return theSteps.size(); }

	expr_t& operator[](int n)    { return theSteps[n]; }

  std::vector<expr_t>::const_iterator begin() const { return theSteps.begin(); }
  std::vector<expr_t>::const_iterator end()   const { return theSteps.end(); }
  std::vector<expr_t>::iterator begin() { return theSteps.begin(); }
  std::vector<expr_t>::iterator end()   { return theSteps.end(); }

  void setTargetPosition(long pos) { theTargetPos = pos; }

  long getTargetPosition() const { return theTargetPos; }

  expr_iterator_data *make_iter ();
  void next_iter (expr_iterator_data&);
  void accept (expr_visitor&);
  std::ostream& put(std::ostream&) const;

  xqtref_t return_type_impl(static_context *sctx);
  expr_t clone (substitution_t &);
};


/*******************************************************************************

  StepExpr ::= AxisStep  |  FilterExpr

********************************************************************************/


/*******************************************************************************

  AxisStep ::= Axis NodeTest Predicate*

********************************************************************************/
class axis_step_expr : public expr 
{
protected:
  axis_kind_t             theAxis;
  expr_t                  theNodeTest;

public:
  SERIALIZABLE_CLASS(axis_step_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(axis_step_expr, expr)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (expr*)this);
    SERIALIZE_ENUM(axis_kind_t, theAxis);
    ar & theNodeTest;
  }
public:
  axis_step_expr(short sctx, const QueryLoc&);

  expr_kind_t get_expr_kind () const { return axis_step_expr_kind; }

  axis_kind_t getAxis() const          { return theAxis; }
  void setAxis(axis_kind_t v)          { theAxis = v; }
  bool is_reverse_axis () const        { return is_reverse_axis (getAxis ()); }

  rchandle<match_expr> getTest() const 
  {
    return reinterpret_cast<match_expr*>(theNodeTest.getp());
  }

  void setTest(rchandle<match_expr> v) { theNodeTest = v.getp(); }

  expr_iterator_data *make_iter ();
  void next_iter (expr_iterator_data&);
  void accept (expr_visitor&);
  std::ostream& put(std::ostream&) const;

  xqtref_t return_type_impl(static_context *sctx);
  expr_t clone (substitution_t &);

public:
  static bool is_reverse_axis (axis_kind_t kind);
};


/*******************************************************************************

  [78] NodeTest ::= KindTest | NameTest

  [79] NameTest ::= QName | Wildcard
  [80] Wildcard ::= "*" | (NCName ":" "*") | ("*" ":" NCName)

  [123] KindTest ::= DocumentTest | ElementTest | AttributeTest |
                     SchemaElementTest | SchemaAttributeTest |
                     PITest | CommentTest | TextTest | AnyKindTest

  If a match_expr represents a KindTest, then theWildKind and theWildName data
  members are not used. If a match_expr represents a NameTest, then theTypeName
  and theNilledAllowed data members are not used.

********************************************************************************/
class match_expr : public expr 
{
protected:
  match_test_t  theTestKind;
  match_test_t  theDocTestKind;

  match_wild_t  theWildKind;
  xqp_string    theWildName;

  store::Item_t theQName;
  store::Item_t theTypeName;
  bool          theNilledAllowed;

public:
  SERIALIZABLE_CLASS(match_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(match_expr, expr)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (expr*)this);
    SERIALIZE_ENUM(match_test_t, theTestKind);
    SERIALIZE_ENUM(match_test_t, theDocTestKind);
    SERIALIZE_ENUM(match_wild_t, theWildKind);
    ar & theWildName;
    ar & theQName;
    ar & theTypeName;
    ar & theNilledAllowed;
  }
public:
  match_expr(short sctx, const QueryLoc&);

  expr_kind_t get_expr_kind () const       { return match_expr_kind; }

  match_test_t getTestKind() const         { return theTestKind; }
  void setTestKind(enum match_test_t v)    { theTestKind = v; }

  match_test_t getDocTestKind() const      { return theDocTestKind; }
  void setDocTestKind(enum match_test_t v) { theDocTestKind = v; }

  match_wild_t getWildKind() const         { return theWildKind; }
  void setWildKind(enum match_wild_t v)    { theWildKind = v; }

  const xqp_string& getWildName() const    { return theWildName; }
  void setWildName(const xqp_string& v)    { theWildName = v; } 

  store::Item* getQName() const            { return theQName.getp(); }
  void setQName(const store::Item_t& v)    { theQName = v; }

  store::Item* getTypeName() const         { return theTypeName.getp(); }
  void setTypeName(const store::Item_t& v) { theTypeName = v; }

  bool getNilledAllowed() const            { return theNilledAllowed; }
  void setNilledAllowed(bool v)            { theNilledAllowed = v; }

  store::StoreConsts::NodeKind getNodeKind() const;

  xqtref_t return_type_impl(static_context *sctx);

  expr_t clone (substitution_t &);

  void next_iter (expr_iterator_data&);

  void accept (expr_visitor&);

  std::ostream& put(std::ostream&) const;
};


/////////////////////////////////////////////////////////////////////////
//                                                                     //
//	Update expressions                                                 //
//  [http://www.w3.org/TR/xqupdate/]                                   //
//                                                                     //
/////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
class insert_expr : public expr
{
protected:
  store::UpdateConsts::InsertType theType;
	expr_t                          theSourceExpr;
	expr_t                          theTargetExpr;

public:
  SERIALIZABLE_CLASS(insert_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(insert_expr, expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
	insert_expr(
    short sctx,
		const QueryLoc&,
    store::UpdateConsts::InsertType,
		expr_t aSourceExpr,
		expr_t aTargetExpr);

  expr_kind_t get_expr_kind() const { return insert_expr_kind; }

  store::UpdateConsts::InsertType getType() const { return theType; }

	expr_t getSourceExpr() const { return theSourceExpr; }

	expr_t getTargetExpr() const { return theTargetExpr; }
  
  void compute_upd_seq_kind() const;

  xqtref_t return_type_impl(static_context* sctx);

  void next_iter(expr_iterator_data&);

  expr_t clone(substitution_t& s);

  void accept(expr_visitor&);

	std::ostream& put(std::ostream&) const;
};


/*******************************************************************************

********************************************************************************/
class delete_expr : public expr
{
protected:
	expr_t theTargetExpr;

public:
  SERIALIZABLE_CLASS(delete_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(delete_expr, expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
	delete_expr(short sctx, const QueryLoc&, expr_t);

  expr_kind_t get_expr_kind() const { return delete_expr_kind; }

	expr_t getTargetExpr() const { return theTargetExpr; }

  void next_iter(expr_iterator_data&);

  void compute_upd_seq_kind() const;

  xqtref_t return_type_impl(static_context* sctx);

  expr_t clone(substitution_t& s);

  void accept(expr_visitor&);

	std::ostream& put(std::ostream&) const;
};


/*******************************************************************************

********************************************************************************/
class replace_expr : public expr
{
protected:
  store::UpdateConsts::ReplaceType theType;
	expr_t                           theTargetExpr;
	expr_t                           theReplaceExpr;

public:
  SERIALIZABLE_CLASS(replace_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(replace_expr, expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
	replace_expr(
    short sctx,
		const QueryLoc&,
    store::UpdateConsts::ReplaceType aType,
		expr_t,
		expr_t);

  expr_kind_t get_expr_kind() const { return replace_expr_kind; }

  store::UpdateConsts::ReplaceType getType() const { return theType; }

	expr_t getTargetExpr() const { return theTargetExpr; }

	expr_t getReplaceExpr() const { return theReplaceExpr; }

  void compute_upd_seq_kind() const;

  xqtref_t return_type_impl(static_context* sctx);

  void next_iter(expr_iterator_data&);

  expr_t clone(substitution_t& s);

  void accept(expr_visitor&);

	std::ostream& put(std::ostream&) const;
};


/*******************************************************************************

********************************************************************************/
class rename_expr : public expr
{
protected:
	expr_t theTargetExpr;
	expr_t theNameExpr;

public:
  SERIALIZABLE_CLASS(rename_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(rename_expr, expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
	rename_expr(short sctx,	const QueryLoc&, expr_t, expr_t);

  expr_kind_t get_expr_kind() const { return rename_expr_kind; }

	expr_t getTargetExpr() const { return theTargetExpr; }

	expr_t getNameExpr() const { return theNameExpr; }

  void compute_upd_seq_kind() const;

  xqtref_t return_type_impl(static_context* sctx);

  void next_iter(expr_iterator_data&);

  expr_t clone(substitution_t& s);

  void accept(expr_visitor&);

	std::ostream& put(std::ostream&) const;
};


/*******************************************************************************
  TransformExpr ::= "copy" "$" VarName ":=" ExprSingle
                    ("," "$" VarName ":=" ExprSingle)*
                    "modify"  ExprSingle "return" ExprSingle
********************************************************************************/
class copy_clause : public SimpleRCObject
{
  friend class transform_expr;

private:
  var_expr_t theVar;
  expr_t     theExpr;

public:
  SERIALIZABLE_CLASS(copy_clause)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(copy_clause, SimpleRCObject)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  copy_clause(var_expr_t aVar, expr_t aExpr);

  var_expr* getVar()  const { return theVar.getp(); }

  expr* getExpr() const { return theExpr.getp(); }

  std::ostream& put(std::ostream&) const;
};


typedef rchandle<copy_clause> copy_clause_t;



class transform_expr : public expr
{
protected:
	std::vector<copy_clause_t> theCopyClauses;
	expr_t                     theModifyExpr;
	expr_t                     theReturnExpr;

public:
  SERIALIZABLE_CLASS(transform_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(transform_expr, expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
	transform_expr(
    short sctx,
		const QueryLoc&,
		expr_t aModifyExpr,
		expr_t aReturnExpr);

  expr_kind_t get_expr_kind () const { return transform_expr_kind; }

	expr_t getModifyExpr() const { return theModifyExpr; }

	expr_t getReturnExpr() const { return theReturnExpr; }

  void setModifyExpr(expr* e);

  void setReturnExpr(expr* e);

	void add_back(copy_clause_t c);

	copy_clause_t const& operator[](int i) const { return theCopyClauses[i]; }

	std::vector<copy_clause_t>::const_iterator begin() const
  { return theCopyClauses.begin(); }

	std::vector<copy_clause_t>::const_iterator end() const
  { return theCopyClauses.end(); }

	size_t size() const { return theCopyClauses.size(); }

  void compute_upd_seq_kind() const;

  xqtref_t return_type_impl(static_context* sctx);

  expr_iterator_data* make_iter();

  void next_iter(expr_iterator_data&);

  // TODO : clone()

  void accept(expr_visitor&);

	std::ostream& put(std::ostream&) const;
};


/////////////////////////////////////////////////////////////////////////
//                                                                     //
//	Scripting expressions                                              //
//  [http://www.w3.org/TR/xquery-sx-10/]                               //
//                                                                     //
/////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
class exit_expr : public expr 
{
private:
  expr_t theExpr;

public:
  SERIALIZABLE_CLASS(exit_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(exit_expr, expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  exit_expr(short sctx, const QueryLoc& loc, expr_t inExpr);

  expr_kind_t get_expr_kind() const { return exit_expr_kind; }

  expr* get_value() const { return theExpr.getp(); }

  expr_t clone(substitution_t& s);

  void next_iter(expr_iterator_data&);

  void accept(expr_visitor&);

	std::ostream& put(std::ostream&) const;
};


/*******************************************************************************

********************************************************************************/
class flowctl_expr : public expr 
{
public:
  enum action { BREAK, CONTINUE };

protected:
  enum action theAction;

public:
  SERIALIZABLE_CLASS(flowctl_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(flowctl_expr, expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  flowctl_expr(short sctx, const QueryLoc& loc, enum action action);

  expr_kind_t get_expr_kind() const { return flowctl_expr_kind; }

  enum action get_action() const { return theAction; }

  expr_t clone(substitution_t& s);

  void next_iter(expr_iterator_data&);

  void accept(expr_visitor&);

	std::ostream& put(std::ostream&) const;
};


/*******************************************************************************

********************************************************************************/
class while_expr : public expr 
{
  expr_t theBody;

public:
  SERIALIZABLE_CLASS(while_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(while_expr, expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  while_expr(short sctx, const QueryLoc &loc, expr_t body);

  expr_kind_t get_expr_kind() const { return while_expr_kind; }

  expr* get_body() const { return theBody.getp(); }

  void next_iter(expr_iterator_data&);

  expr_t clone(substitution_t& s);

  void accept(expr_visitor&);

	std::ostream& put(std::ostream&) const;
};



/////////////////////////////////////////////////////////////////////////
//                                                                     //
//	Full-Text expressions                                              //
//  [http://www.w3.org/TR/????/]                                       //
//                                                                     //
/////////////////////////////////////////////////////////////////////////

class ft_select_expr : public expr 
{
public:
  ft_select_expr (short sctx, const QueryLoc &loc) : expr (sctx, loc) {}
public:
  SERIALIZABLE_ABSTRACT_CLASS(ft_select_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ft_select_expr, expr)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (expr*)this);
  }
};


class ft_contains_expr : public expr 
{
protected:
  expr_t range_h;
  expr_t ft_select_h;
  expr_t ft_ignore_h;

public:
  SERIALIZABLE_ABSTRACT_CLASS(ft_contains_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ft_contains_expr, expr)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (expr*)this);
    ar & range_h;
    ar & ft_select_h;
    ar & ft_ignore_h;
  }

public:
  ft_contains_expr(
        short sctx,
        const QueryLoc&,
        expr_t,
        expr_t,
        expr_t);

  expr_t get_range() const { return range_h; }
  expr_t get_ft_select() const { return ft_select_h; }
  expr_t get_ignore() const { return ft_ignore_h; }

  void next_iter (expr_iterator_data&);
  void accept (expr_visitor&);
  std::ostream& put(std::ostream&) const;
};


}
#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set ts=2 sw=2: */
