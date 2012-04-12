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
#pragma once
#ifndef ZORBA_COMPILER_EXPR
#define ZORBA_COMPILER_EXPR

#include <string>
#include <vector>

#include <zorba/store_consts.h>

#include "zorbautils/checked_vector.h"

#include "zorbatypes/schema_types.h"

#include "functions/signature.h"

#include "compiler/expression/var_expr.h"

#include "context/static_context.h"
#include "context/namespace_context.h"

#include "types/node_test.h"

#include "zorbaserialization/class_serializer.h"

#include "store/api/item.h"

namespace zorba 
{

class expr_visitor;
class NodeNameTest;
class signature;



/*******************************************************************************
  [68] IfExpr ::= "if" "(" Expr ")" "then" ExprSingle "else" ExprSingle
********************************************************************************/
class if_expr : public expr 
{
  friend class ExprIterator;
  friend class expr;

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
        static_context* sctx,
        const QueryLoc& loc,
        expr_t c,
        expr_t t,
        expr_t e);

  expr* get_cond_expr() const { return theCondExpr.getp(); }

  expr* get_then_expr() const { return theThenExpr.getp(); }

  expr* get_else_expr() const { return theElseExpr.getp(); }

  void compute_scripting_kind();

  expr_t clone(substitution_t& s) const;

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;
};


/***************************************************************************//**

********************************************************************************/
class order_expr : public expr 
{
  friend class ExprIterator;
  friend class expr;

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
  order_expr(static_context* sctx, const QueryLoc&, order_type_t, expr_t);

  order_type_t get_type() const { return theType; }

  expr* get_expr() const { return theExpr.getp(); }

  void compute_scripting_kind();

  expr_t clone(substitution_t& s) const;

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;
};


/***************************************************************************//**

********************************************************************************/
class validate_expr : public expr 
{
  friend class ExprIterator;
  friend class expr;

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
        static_context* sctx,
        const QueryLoc&,
        ParseConstants::validation_mode_t,
        const store::Item_t& aTypeName,
        expr_t,
        rchandle<TypeManager>);

  expr* get_expr() const { return theExpr.getp(); }

  const store::Item* get_type_name() const { return theTypeName; }

  TypeManager* get_typemgr() const { return theTypeMgr.getp(); }

  ParseConstants::validation_mode_t get_valmode() const { return theMode; }

  void compute_scripting_kind();

  expr_t clone(substitution_t& s) const;

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;
};


/***************************************************************************//**
  Base for expression classes that require a namespace context
********************************************************************************/
class namespace_context_base_expr : public expr
{
  friend class expr;

protected:
  NamespaceContext_t theNSCtx;

protected:
  namespace_context_base_expr(
      static_context* sctx,
      const QueryLoc& loc,
      expr_kind_t kind,
      const namespace_context* aNSCtx);

public:
  SERIALIZABLE_ABSTRACT_CLASS(namespace_context_base_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(namespace_context_base_expr, expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  const namespace_context* getNSCtx() const;
};


/***************************************************************************//**
  Base for cast, treat, promote, castable, instanceof
********************************************************************************/
class cast_or_castable_base_expr : public expr 
{
  friend class ExprIterator;
  friend class expr;

protected:
  expr_t   theInputExpr;
  xqtref_t theTargetType;

protected:
  cast_or_castable_base_expr(
        static_context* sctx,
        const QueryLoc& loc,
        expr_kind_t kind,
        expr_t input,
        xqtref_t type);
  
public:
  SERIALIZABLE_ABSTRACT_CLASS(cast_or_castable_base_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(cast_or_castable_base_expr, expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  expr* get_input() const { return theInputExpr.getp(); }

  xqtref_t get_target_type() const;

  void set_target_type(xqtref_t target);

  void compute_scripting_kind();
};


/***************************************************************************//**
  Base for cast, treat, promote
********************************************************************************/
class cast_base_expr : public cast_or_castable_base_expr
{
  friend class ExprIterator;

public:
  SERIALIZABLE_ABSTRACT_CLASS(cast_base_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(cast_base_expr, cast_or_castable_base_expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  cast_base_expr(
      static_context* sctx, 
      const QueryLoc& loc,
      expr_kind_t kind,
      expr_t input,
      xqtref_t type);
};


/***************************************************************************//**
  CastExpr ::= UnaryExpr ( "cast" "as" SingleType )?

  SingleType ::= AtomicType "?"?
********************************************************************************/
class cast_expr : public cast_base_expr
{
  friend class ExprIterator;
  friend class expr;

public:
  SERIALIZABLE_CLASS(cast_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(cast_expr, cast_base_expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  cast_expr(static_context* sctx, const QueryLoc&, expr_t, xqtref_t);

  bool is_optional() const;

  expr_t clone(substitution_t& s) const;

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

  theFnQName    : Stores the QName of the function, if the treat expr is used 
                  to cast the function's body to its result type
********************************************************************************/
class treat_expr : public cast_base_expr 
{
  friend class ExprIterator;
  friend class expr;

protected:
  const Error  * theError;
  bool           theCheckPrime;
  store::Item_t  theFnQName;

public:
  SERIALIZABLE_CLASS(treat_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(treat_expr, cast_base_expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  treat_expr(
        static_context* sctx, 
        const QueryLoc&,
        expr_t,
        xqtref_t,
        Error const&,
        bool check_prime = true,
        store::Item_t fnQname = NULL);

  Error const& get_err() const { return *theError; }

  bool get_check_prime() const { return theCheckPrime; }

  void set_check_prime(bool check_prime) { theCheckPrime = check_prime; }

  void set_fn_qname(store::Item_t fnQName) { theFnQName = fnQName; }

  store::Item_t get_fn_qname() const { return theFnQName; }

  expr_t clone(substitution_t& s) const;

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

  theFnQName:
  -----------
  Stores the QName of the function, if the promote expr is used to cast the
  function's body to its result type
  
********************************************************************************/
class promote_expr : public cast_base_expr
{
  friend class ExprIterator;
  friend class expr;

protected:
  store::Item_t theFnQName;
  
public:
  SERIALIZABLE_CLASS(promote_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(promote_expr, cast_base_expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  promote_expr(
      static_context* sctx, 
      const QueryLoc& loc, 
      expr_t input, 
      xqtref_t type, 
      store::Item_t fnQname = NULL);

  expr_t clone(substitution_t& s) const;

  void set_fn_qname(store::Item_t fnQName) { theFnQName = fnQName; }

  store::Item_t get_fn_qname() const { return theFnQName; }

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;
};


/***************************************************************************//**
  Base for castable, instanceof
********************************************************************************/
class castable_base_expr : public cast_or_castable_base_expr 
{
  friend class ExprIterator;

public:
  SERIALIZABLE_ABSTRACT_CLASS(castable_base_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(castable_base_expr, cast_or_castable_base_expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  castable_base_expr(
        static_context* sctx,
        const QueryLoc&,
        expr_kind_t kind,
        expr_t,
        xqtref_t);
};


/***************************************************************************//**
  CastableExpr ::= CastExpr ( "castable" "as" SingleType )?

  SingleType ::= AtomicType "?"?
********************************************************************************/
class castable_expr : public castable_base_expr 
{
  friend class ExprIterator;
  friend class expr;

public:
  SERIALIZABLE_CLASS(castable_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(castable_expr, castable_base_expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  castable_expr(static_context* sctx, const QueryLoc&, expr_t, xqtref_t);
  
  bool is_optional() const;

  expr_t clone(substitution_t& s) const;

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;
};


/***************************************************************************//**
	InstanceofExpr ::= TreatExpr ( "instance" "of" SequenceType )?

  theCheckPrimeOnly : 
  Normally, this is false. It is set to true only if this is an instanceof expr
  that is created during the translation of a PredicateList (see translator.cpp).
  This flag is used during the PartialEval rule.

********************************************************************************/
class instanceof_expr : public castable_base_expr 
{
  friend class ExprIterator;
  friend class expr;

protected:
  bool theCheckPrimeOnly;

public:
  SERIALIZABLE_CLASS(instanceof_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(instanceof_expr, castable_base_expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  instanceof_expr(
      static_context* sctx,
      const QueryLoc&, 
      expr_t, 
      xqtref_t,
      bool checkPrimeOnly = false);

  bool getCheckPrimeOnly() const { return theCheckPrimeOnly; }

  expr_t clone(substitution_t& s) const;

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
class name_cast_expr : public namespace_context_base_expr
{
  friend class ExprIterator;
  friend class expr;

private:
  expr_t             theInputExpr;
  bool               theIsAttrName;

public:
  SERIALIZABLE_CLASS(name_cast_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(name_cast_expr, namespace_context_base_expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  name_cast_expr(
        static_context* sctx,
        const QueryLoc&,
        expr_t,
        const namespace_context*,
        bool isAttr);

  expr* get_input() const { return theInputExpr.getp(); }

  bool is_attr_name() const { return theIsAttrName; }

  void compute_scripting_kind();

  expr_t clone(substitution_t& s) const;

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;
};


/***************************************************************************//**
  CompDocConstructor ::= "document" "{" Expr "}"
********************************************************************************/
class doc_expr : public expr 
{
  friend class ExprIterator;
  friend class expr;

protected:
  expr_t theContent;
  bool   theCopyInputNodes;

public:
  SERIALIZABLE_CLASS(doc_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(doc_expr, expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  doc_expr(static_context* sctx, const QueryLoc&, expr* content, bool copyNodes);

  expr* getContent() const { return theContent.getp(); }

  bool copyInputNodes() const { return theCopyInputNodes; }

  void setCopyInputNodes() { theCopyInputNodes = true; }

  void compute_scripting_kind();

  expr_t clone(substitution_t& s) const;

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
class elem_expr : public namespace_context_base_expr
{
  friend class ExprIterator;
  friend class expr;

protected:
  expr_t theQNameExpr;
  expr_t theAttrs;
  expr_t theContent;
  bool   theCopyInputNodes;

public:
  SERIALIZABLE_CLASS(elem_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(elem_expr, namespace_context_base_expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  elem_expr(
        static_context* sctx,
        const QueryLoc&,
        expr* qnameExpr,
        expr* attrs,
        expr* content,
        const namespace_context* nsCtx,
        bool copyNodes);
  
  elem_expr(
        static_context* sctx,
        const QueryLoc&,
        expr* qnameExpr,
        expr* content,
        const namespace_context* nsCtx,
        bool copyNodes);
  
  expr* getQNameExpr() const { return theQNameExpr.getp(); }

  expr* getContent() const { return theContent.getp(); }

  expr* getAttrs() const { return theAttrs.getp(); }

  bool copyInputNodes() const { return theCopyInputNodes; }

  void setCopyInputNodes() { theCopyInputNodes = true; }

  void compute_scripting_kind();
  
  expr_t clone(substitution_t& s) const;  

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
  friend class ExprIterator;
  friend class expr;

protected:
  expr_t theQNameExpr;
  expr_t theValueExpr;

public:
  SERIALIZABLE_CLASS(attr_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(attr_expr, expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  attr_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr_t aQNameExpr,
    expr_t aValueExpr);

  expr* getQNameExpr() const { return theQNameExpr.getp(); }

  expr* getValueExpr() const { return theValueExpr.getp(); }

  const store::Item* getQName() const;

  void compute_scripting_kind();

  expr_t clone(substitution_t& s) const;

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;
};


/***************************************************************************//**

********************************************************************************/
class text_expr : public expr 
{
  friend class ExprIterator;
  friend class expr;

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
      static_context* sctx,
      const QueryLoc&,
      text_constructor_type,
      expr_t);

  expr* get_text() const { return theContentExpr.getp(); }

  text_constructor_type get_type() const { return type; }

  void compute_scripting_kind();

  expr_t clone(substitution_t& s) const;  

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;
};


/***************************************************************************//**

********************************************************************************/
class pi_expr : public expr 
{
  friend class ExprIterator;
  friend class expr;

protected:
  expr_t theTargetExpr;
  expr_t theContentExpr;

public:
  SERIALIZABLE_CLASS(pi_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(pi_expr, expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  pi_expr(static_context* sctx, const QueryLoc&, expr_t, expr_t);
 
  expr* get_target_expr() const { return theTargetExpr.getp(); }

  expr* get_content_expr() const { return theContentExpr.getp(); }

  void compute_scripting_kind();
  
  expr_t clone(substitution_t& s) const;  

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;
};


/***************************************************************************//**

********************************************************************************/
class const_expr : public expr 
{
  friend class ExprIterator;
  friend class expr;

protected:
  store::Item_t theValue;

public:
  SERIALIZABLE_CLASS(const_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(const_expr, expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  const_expr(static_context* sctx, const QueryLoc&, zstring& sval);

  const_expr(static_context* sctx, const QueryLoc&, const std::string& sval);

  const_expr(static_context* sctx, const QueryLoc&, const char* sval);

  const_expr(static_context* sctx, const QueryLoc&, xs_integer);

  const_expr(static_context* sctx, const QueryLoc&, xs_decimal);

  const_expr(static_context* sctx, const QueryLoc&, xs_double);

  const_expr(static_context* sctx, const QueryLoc&, xs_boolean);

  const_expr(static_context* sctx, const QueryLoc&, store::Item_t);  

  const_expr(static_context* sctx, const QueryLoc&, const char* ns, const char* pre, const char* local);

  store::Item* get_val() const { return theValue.getp(); }

  void compute_scripting_kind();

  expr_t clone(substitution_t& s) const;

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;
};


/***************************************************************************//**

********************************************************************************/
class pragma : public SimpleRCObject
{
  friend class expr;

public:
  store::Item_t theQName;
  std::string theContent;

public:
  SERIALIZABLE_CLASS(pragma)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(pragma, SimpleRCObject)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  pragma(store::Item_t name, std::string const& content);
};


/***************************************************************************//**

********************************************************************************/
class extension_expr : public expr 
{
  friend class ExprIterator;
  friend class expr;

protected:
  std::vector<rchandle<pragma> > thePragmas;
  expr_t                         theExpr;

public:
  SERIALIZABLE_CLASS(extension_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(extension_expr, expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  extension_expr(static_context* sctx, const QueryLoc&);

  extension_expr(static_context* sctx, const QueryLoc&, expr_t);

  void add(rchandle<pragma> p) { thePragmas.push_back(p); }

  expr* get_expr() const { return theExpr.getp(); }

  void compute_scripting_kind();

  expr_t clone(substitution_t& subst) const;

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;
};


/////////////////////////////////////////////////////////////////////////
//                                                                     //
//	XQuery 1.1 expressions                                             //
//  [http://www.w3.org/TR/xquery-1.1/]                                 //
//                                                                     //
/////////////////////////////////////////////////////////////////////////


/***************************************************************************//**
  [169] TryCatchExpr ::= TryClause CatchClauseList

  [170] TryClause ::= "try" "{" TryTargetExpr "}"

  [171] TryTargetExpr ::= Expr

        CatchClauseList := CatchClause+

  [172] CatchClause ::= "catch" CatchErrorList "{" Expr "}"

  [173] CatchErrorList ::= NameTest ("|" NameTest)*

********************************************************************************/
class catch_clause;

typedef rchandle<catch_clause> catch_clause_t;


class catch_clause : public SimpleRCObject 
{
  friend class expr;
  friend class trycatch_expr;

public:
  enum var_type
  {
    err_code = 0,
    err_desc,
    err_value,
    err_module,
    err_line_no,
    err_column_no,
    zerr_stack_trace
  };

public:
  typedef rchandle<NodeNameTest> nt_t;
  typedef std::vector<nt_t> nt_list_t;
  typedef std::map<int, var_expr_t> var_map_t;

protected:
  nt_list_t  theNameTests;
  var_map_t  theVarMap;
  
public:
  SERIALIZABLE_CLASS(catch_clause)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(catch_clause, SimpleRCObject)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  catch_clause();
  
  void set_nametests(nt_list_t& a) { theNameTests = a; }

  nt_list_t& get_nametests() { return theNameTests; }
  
  void add_nametest_h(nt_t n) { theNameTests.push_back(n); }

  void set_vars(var_map_t& a) { theVarMap = a; }

  var_map_t& get_vars() { return theVarMap; }
  
  void add_var(var_type v, var_expr_t n) { theVarMap[v] = n; }
  
  catch_clause_t clone(expr::substitution_t& subst) const;
};


class trycatch_expr : public expr 
{
  friend class ExprIterator;
  friend class expr;

protected:
  expr_t                      theTryExpr;
  std::vector<expr_t>         theCatchExprs;
  std::vector<catch_clause_t> theCatchClauses;

public:
  SERIALIZABLE_CLASS(trycatch_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(trycatch_expr, expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  trycatch_expr(static_context* sctx, const QueryLoc&, expr_t tryExpr);

  expr* get_try_expr() const { return theTryExpr.getp(); }

  expr* get_catch_expr(csize i) const { return theCatchExprs[i].getp(); }

  void add_catch_expr(expr_t e);

  void add_clause(catch_clause_t cc);
  
  csize clause_count() const { return theCatchClauses.size(); }
  
  catch_clause_t const& operator[](csize i) const { return theCatchClauses[i]; }

  void compute_scripting_kind();

  expr_t clone(substitution_t& subst) const;

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;
};


/////////////////////////////////////////////////////////////////////////
//                                                                     //
//	Zorba expressions                                                  //
//                                                                     //
/////////////////////////////////////////////////////////////////////////


/*******************************************************************************
  Normally, it is used to wrap a var_expr in order to represent a var reference
  (see var_expr.h). But it may wrap any other kind of expr as well.
********************************************************************************/
class wrapper_expr : public expr 
{
  friend class ExprIterator;
  friend class expr;

protected:
  expr_t theWrappedExpr;

public:
  SERIALIZABLE_CLASS(wrapper_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(wrapper_expr, expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  wrapper_expr(static_context* sctx, const QueryLoc& loc, expr_t wrapped);

  expr* get_expr() const { return theWrappedExpr.getp(); }

  void set_expr(const expr* e) { theWrappedExpr = e; }

  void compute_scripting_kind();

  void accept(expr_visitor&);

  expr_t clone(substitution_t& s) const;

  std::ostream& put(std::ostream&) const;
};


/***************************************************************************//**
  dummy expression for call stack traces
********************************************************************************/
class function_trace_expr : public expr
{
  friend class ExprIterator;
  friend class expr;
protected:
  expr_t theExpr;
  store::Item_t theFunctionName;
  QueryLoc theFunctionLocation;
  QueryLoc theFunctionCallLocation;
  unsigned int theFunctionArity;

public:
  SERIALIZABLE_CLASS(function_trace_expr);
  SERIALIZABLE_CLASS_CONSTRUCTOR2(function_trace_expr, expr)
  void serialize(::zorba::serialization::Archiver& ar);
public:
  function_trace_expr(
      static_context* sctx,
      const QueryLoc& loc,
      expr_t aChild);

  function_trace_expr(expr_t aExpr);

  virtual ~function_trace_expr();

  void compute_scripting_kind();

  void accept(expr_visitor&);

  expr_t clone(substitution_t& s) const;

  std::ostream& put(std::ostream&) const;

  expr* get_expr() const { return theExpr.getp(); }

  void setFunctionName(store::Item_t aFunctionName)
  {
    theFunctionName = aFunctionName;
  }

  store::Item_t getFunctionName() const
  {
    return theFunctionName;
  }

  void setFunctionLocation(const QueryLoc& loc)
  {
    theFunctionLocation = loc;
  }

  const QueryLoc& getFunctionLocation() const
  {
    return theFunctionLocation;
  }

  void setFunctionCallLocation(const QueryLoc& loc)
  {
    theFunctionCallLocation = loc;
  }

  const QueryLoc& getFunctionCallLocation() const
  {
    return theFunctionCallLocation;
  }
  
  void setFunctionArity(unsigned int arity)
  {
    theFunctionArity = arity;
  }

  unsigned int getFunctionArity() const
  {
    return theFunctionArity;
  }
};


/***************************************************************************//**
  There is no syntax corresponding to the eval_expr. Instead, an eval_expr is
  created by the translator whenever a call to the eval() function is reached.

  theExpr:
  --------
  The expr that computes the query string to be evaluated by eval.

  theVars:
  --------
  There is one "eval" var for each non-global var that is in scope where the call
  to the eval function appears at.

  theArgs:
  --------
  The domain expr of each eval var. Initially, the domain expr of an eval var
  is always another var. However, that other var may be later inlined, so in
  general, the domain expr of an eval var may be any expr.

  theInnerScriptingKind:
  ----------------------

  theDoNodeCopy:
  --------------

********************************************************************************/
class eval_expr : public namespace_context_base_expr
{
  friend class ExprIterator;
  friend class expr;

protected:
  expr_t                      theExpr;

  std::vector<var_expr_t>     theVars;
  std::vector<expr_t>         theArgs;

  expr_script_kind_t          theInnerScriptingKind;
  bool                        theDoNodeCopy;

public:
  SERIALIZABLE_CLASS(eval_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(eval_expr, namespace_context_base_expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  eval_expr(
      static_context* sctx,
      const QueryLoc& loc, 
      const expr_t& e,
      expr_script_kind_t scriptingKind,
      namespace_context* nsCtx);

  expr* get_expr() const { return theExpr.getp(); }

  expr* get_arg_expr(csize i) { return theArgs[i].getp(); }

  csize var_count() const { return theVars.size(); }

  const var_expr* get_var(csize i) const { return theVars[i]; }

  void add_var(const var_expr_t& var, const expr_t& arg) 
  {
    theVars.push_back(var);
    theArgs.push_back(arg);
  }

  expr_script_kind_t get_inner_scripting_kind() const;

  bool getNodeCopy() const { return theDoNodeCopy; }

  void setNodeCopy(bool v) { theDoNodeCopy = true; }

  void compute_scripting_kind();

  void accept(expr_visitor&);

  expr_t clone(substitution_t& s) const;

  std::ostream& put(std::ostream&) const;
};


#ifdef ZORBA_WITH_DEBUGGER
/***************************************************************************//**
  debugger expression

  theExpr:
  --------
  The wrapped expr

  theVars:
  --------

  theArgs:
  --------

  theIsVarDeclaration:
  --------------------
********************************************************************************/
class debugger_expr : public namespace_context_base_expr
{
  friend class ExprIterator;
  friend class expr;

private:
  expr_t                      theExpr;
  checked_vector<var_expr_t>  theVars;
  std::vector<expr_t>         theArgs;
  bool                        theIsVarDeclaration;

public:
  SERIALIZABLE_CLASS(debugger_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(debugger_expr, namespace_context_base_expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  debugger_expr(
      static_context* sctx,
      const QueryLoc& loc,
      const expr_t& aChild,
      namespace_context* nsCtx,
      bool aIsVarDeclaration);

  expr* get_expr() const { return theExpr.getp(); }

  bool isVarDeclaration() const { return theIsVarDeclaration; }

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;

  csize var_count() const { return theVars.size(); }

  const var_expr* get_var(csize i) const { return theVars[i]; }

  void add_var(const var_expr_t& var, const expr_t& arg) 
  {
    theVars.push_back(var);
    theArgs.push_back(arg);
  }

  void compute_scripting_kind();
};
#endif


}
#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
