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

#include "compiler/expression/expr_base.h"

#include "context/static_context.h"
#include "context/namespace_context.h"

#include "types/node_test.h"

#include "store/api/item.h"


namespace zorba
{

class ExprManager;
class expr_visitor;
class NodeNameTest;
class signature;
class pragma;


/*******************************************************************************
  [68] IfExpr ::= "if" "(" Expr ")" "then" ExprSingle "else" ExprSingle
********************************************************************************/
class if_expr : public expr
{
  friend class ExprManager;
  friend class ExprIterator;
  friend class expr;

protected:
  expr  * theCondExpr;
  expr  * theThenExpr;
  expr  * theElseExpr;

protected:
  if_expr(
        CompilerCB* ccb,
        static_context* sctx,
        user_function* udf,
        const QueryLoc& loc,
        expr* c,
        expr* t,
        expr* e);

public:
  expr* get_cond_expr() const { return theCondExpr; }

  expr* get_then_expr() const { return theThenExpr; }

  expr* get_else_expr() const { return theElseExpr; }

  void compute_scripting_kind();

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;
};


/***************************************************************************//**

********************************************************************************/
class order_expr : public expr
{
  friend class ExprManager;
  friend class ExprIterator;
  friend class expr;

protected:
  expr         * theInput;
  DocOrderMode   theType;

protected:
  order_expr(
      CompilerCB* ccb,
      static_context* sctx,
      user_function* udf,
      const QueryLoc&,
      DocOrderMode,
      expr*);

public:
  expr* get_input() const { return theInput; }

  DocOrderMode get_type() const { return theType; }

  void compute_scripting_kind();

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;
};


/***************************************************************************//**

********************************************************************************/
class validate_expr : public expr
{
  friend class ExprManager;
  friend class ExprIterator;
  friend class expr;

protected:
  expr                             * theInput;
  ParseConstants::validation_mode_t  theMode;
  store::Item_t                      theTypeName;
  rchandle<TypeManager>              theTypeMgr;

protected:
  validate_expr(
      CompilerCB* ccb,
      static_context* sctx,
      user_function* udf,
      const QueryLoc&,
      ParseConstants::validation_mode_t,
      const store::Item_t& aTypeName,
      expr*,
      rchandle<TypeManager>);

public:
  expr* get_input() const { return theInput; }

  const store::Item* get_type_name() const { return theTypeName; }

  TypeManager* get_typemgr() const { return theTypeMgr.getp(); }

  ParseConstants::validation_mode_t get_valmode() const { return theMode; }

  void compute_scripting_kind();

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
      CompilerCB* ccb,
      static_context* sctx,
      user_function* udf,
      const QueryLoc& loc,
      expr_kind_t kind,
      const namespace_context* aNSCtx);

public:
  const namespace_context* getNSCtx() const;
};


/*******************************************************************************
  Base for cast, treat, promote, castable, instanceof
********************************************************************************/
class cast_or_castable_base_expr : public expr
{
  friend class ExprIterator;
  friend class expr;

protected:
  expr     * theInput;
  xqtref_t   theTargetType;

protected:
  cast_or_castable_base_expr(
      CompilerCB* ccb,
      static_context* sctx,
      user_function* udf,
      const QueryLoc& loc,
      expr_kind_t kind,
      expr* input,
      const xqtref_t& type);

public:
  expr* get_input() const { return theInput; }

  xqtref_t get_target_type() const;

  void set_target_type(xqtref_t target);

  void compute_scripting_kind();
};


/*******************************************************************************
  Base for cast, promote, treat
********************************************************************************/
class cast_base_expr : public cast_or_castable_base_expr
{
  friend class ExprIterator;

protected:
  cast_base_expr(
      CompilerCB* ccb,
      static_context* sctx,
      user_function* udf,
      const QueryLoc& loc,
      expr_kind_t kind,
      expr* input,
      const xqtref_t& type);
};


/*******************************************************************************
  CastExpr ::= UnaryExpr ( "cast" "as" SingleType )?

  SingleType ::= AtomicType "?"?
********************************************************************************/
class cast_expr : public cast_base_expr
{
  friend class ExprManager;
  friend class ExprIterator;
  friend class expr;

protected:
  bool theAllowsEmtpyInput;

protected:
  cast_expr(
      CompilerCB* ccb,
      static_context* sctx,
      user_function* udf,
      const QueryLoc&,
      expr*,
      const xqtref_t&,
      bool allowsEmptyInput);

public:
  bool allows_empty_input() const { return theAllowsEmtpyInput; }

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;
};


/***************************************************************************//**
  This is an internal zorba expr. Its semantics are the following:

  1. Let "input sequence" be the result of theInputExpr, and "output sequence"
     be the result of the promote_expr.

  2. The input sequence is assumed to be empty or consist of atomic items only.

  4. theTargetType is always a subtype of xs:anyAtomicType*

  5. Raise error if the cardinality of the input sequence is not compatible with
     the quantifier of theTargetType.

  6. For each item I in the input sequence, let F(I) be the result of the
     function defined as follows:

     - Let "actual type" be the dynamic type of I, and "target type" be the prime
       type of theTargetType.
     - If the target type is the NONE type, F(I) = raise error, else
     - If the actual type is a subtype of the target type, F(I) = I, else
     - If the actual type is untypedAtomic and the target type is not QName,
       F(I) = cast(I, target type), else
     - If the actual type is (subtype of) decimal and the target type is float,
       F(I) = cast(I, float), else
     - If the actual type is (subtype of) decimal or float and the target type is double,
       F(I) = cast(I, double), else
     - If the actual type is anyURI and the target type is string,
       F(I) = cast(I, string), else
     - F(I) = raise error

  4. Put F(I) in the output sequence.

  theErrorKind :
  --------------

  theQName:
  ---------
  Stores the QName of the function, if the promote expr is used to cast the
  function's body to its result type

********************************************************************************/
class promote_expr : public cast_base_expr
{
  friend class ExprManager;
  friend class ExprIterator;
  friend class expr;

protected:
  PromoteErrorKind theErrorKind;
  store::Item_t    theQName;

protected:
  promote_expr(
      CompilerCB* ccb,
      static_context* sctx,
      user_function* udf,
      const QueryLoc& loc,
      expr* input,
      const xqtref_t& type,
      PromoteErrorKind err,
      store::Item* qname);

public:
  PromoteErrorKind get_err() const { return theErrorKind; }

  void set_qname(const store::Item_t& qname) { theQName = qname; }

  store::Item_t get_qname() const { return theQName; }

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;
};


/***************************************************************************//**
  TreatExpr ::= CastableExpr ( "treat" "as" SequenceType )?

  theCheckPrime :
  ---------------
  Normally, this is true. If false, then during runtime, only the cardinality of
  theInputExpr will be checked w.r.t. the quantifier of theTargetType. 
  theCheckPrime is set to false by the optimizer, if it discovers that the prime
  type of the static type of theInputExpr is a subtype of the prime type of 
  theTargetType.

  theQName :
  ------------
  Stores the QName of the function, if the treat expr is used to cast the
  function's body to its result type
********************************************************************************/
class treat_expr : public cast_base_expr
{
  friend class ExprManager;
  friend class ExprIterator;
  friend class expr;

protected:
  TreatErrorKind  theErrorKind;
  bool            theCheckPrime;
  store::Item_t   theQName;

protected:
  treat_expr(
      CompilerCB* ccb,
      static_context* sctx,
      user_function* udf,
      const QueryLoc&,
      expr*,
      const xqtref_t&,
      TreatErrorKind err,
      bool check_prime = true,
      store::Item* qname = NULL);

public:
  TreatErrorKind get_err() const { return theErrorKind; }

  bool get_check_prime() const { return theCheckPrime; }

  void set_check_prime(bool check_prime) { theCheckPrime = check_prime; }

  void set_qname(const store::Item_t& qname) { theQName = qname; }

  store::Item_t get_qname() const { return theQName; }

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;
};


/***************************************************************************//**
  Base for castable, instanceof
********************************************************************************/
class castable_base_expr : public cast_or_castable_base_expr
{
  friend class ExprIterator;

protected:
  castable_base_expr(
      CompilerCB* ccb,
      static_context* sctx,
      user_function* udf,
      const QueryLoc&,
      expr_kind_t kind,
      expr*,
      const xqtref_t&);
};


/***************************************************************************//**
  CastableExpr ::= CastExpr ( "castable" "as" SingleType )?

  SingleType ::= AtomicType "?"?
********************************************************************************/
class castable_expr : public castable_base_expr
{
  friend class ExprManager;
  friend class ExprIterator;
  friend class expr;

protected:
  bool theAllowsEmtpyInput;

protected:
  castable_expr(
      CompilerCB* ccb,
      static_context* sctx,
      user_function* udf,
      const QueryLoc&,
      expr*,
      const xqtref_t&,
      bool allowsEmtpyInput);

public:
  bool allows_empty_input() const { return theAllowsEmtpyInput; }

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;
};


/***************************************************************************//**
  InstanceofExpr ::= TreatExpr ( "instance" "of" SequenceType )?

  theCheckPrimeOnly :
  -------------------
  Normally, this is false. It is set to true only if this is an instanceof expr
  that is created during the translation of a PredicateList (see translator.cpp).
  This flag is used during the PartialEval rule.

********************************************************************************/
class instanceof_expr : public castable_base_expr
{
  friend class ExprManager;
  friend class ExprIterator;
  friend class expr;

protected:
  bool theCheckPrimeOnly;

protected:
  instanceof_expr(
      CompilerCB* ccb,
      static_context* sctx,
      user_function* udf,
      const QueryLoc&,
      expr*,
      const xqtref_t&,
      bool checkPrimeOnly = false);

public:
  bool getCheckPrimeOnly() const { return theCheckPrimeOnly; }

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
  friend class ExprManager;
  friend class ExprIterator;
  friend class expr;

private:
  expr  * theInputExpr;
  bool    theIsAttrName;

protected:
  name_cast_expr(
      CompilerCB* ccb,
      static_context* sctx,
      user_function* udf,
      const QueryLoc&,
      expr*,
      const namespace_context*,
      bool isAttr);

public:
  expr* get_input() const { return theInputExpr; }

  bool is_attr_name() const { return theIsAttrName; }

  void compute_scripting_kind();

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;
};


/***************************************************************************//**
  CompDocConstructor ::= "document" "{" Expr "}"
********************************************************************************/
class doc_expr : public expr
{
  friend class ExprManager;
  friend class ExprIterator;
  friend class expr;

protected:
  expr  * theContent;
  bool    theCopyInputNodes;

protected:
  doc_expr(
      CompilerCB* ccb,
      static_context* sctx,
      user_function* udf,
      const QueryLoc&,
      expr* content,
      bool copyNodes);

public:
  expr* getContent() const { return theContent; }

  bool copyInputNodes() const { return theCopyInputNodes; }

  void setCopyInputNodes() { theCopyInputNodes = true; }

  void compute_scripting_kind();

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
  friend class ExprManager;
  friend class ExprIterator;
  friend class expr;

protected:
  expr  * theQNameExpr;
  expr  * theAttrs;
  expr  * theContent;
  bool    theCopyInputNodes;

protected:
  elem_expr(
      CompilerCB* ccb,
      static_context* sctx,
      user_function* udf,
      const QueryLoc&,
      expr* qnameExpr,
      expr* attrs,
      expr* content,
      const namespace_context* nsCtx,
      bool copyNodes);

  elem_expr(
        CompilerCB* ccb,
        static_context* sctx,
        user_function* udf,
        const QueryLoc&,
        expr* qnameExpr,
        expr* content,
        const namespace_context* nsCtx,
        bool copyNodes);

public:
  expr* getQNameExpr() const { return theQNameExpr; }

  expr* getContent() const { return theContent; }

  expr* getAttrs() const { return theAttrs; }

  bool copyInputNodes() const { return theCopyInputNodes; }

  void setCopyInputNodes() { theCopyInputNodes = true; }

  void compute_scripting_kind();
  
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
  friend class ExprManager;
  friend class ExprIterator;
  friend class expr;

protected:
  expr  * theQNameExpr;
  expr  * theValueExpr;

protected:
  attr_expr(
      CompilerCB* ccb,
      static_context* sctx,
      user_function* udf,
      const QueryLoc& loc,
      expr* aQNameExpr,
      expr* aValueExpr);

public:
  expr* getQNameExpr() const { return theQNameExpr; }

  expr* getValueExpr() const { return theValueExpr; }

  const store::Item* getQName() const;

  void compute_scripting_kind();

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;
};


/***************************************************************************//**

********************************************************************************/
class text_expr : public expr
{
  friend class ExprManager;
  friend class ExprIterator;
  friend class expr;

protected:
  TextConstructorType   type;
  expr                * theContentExpr;

protected:
  text_expr(
      CompilerCB* ccb,
      static_context* sctx,
      user_function* udf,
      const QueryLoc&,
      TextConstructorType,
      expr*);

public:
  expr* get_text() const { return theContentExpr; }

  TextConstructorType get_type() const { return type; }

  void compute_scripting_kind();

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;
};


/***************************************************************************//**

********************************************************************************/
class pi_expr : public expr
{
  friend class ExprManager;
  friend class ExprIterator;
  friend class expr;

protected:
  expr * theTargetExpr;
  expr * theContentExpr;

protected:
  pi_expr(
      CompilerCB* ccb,
      static_context* sctx,
      user_function* udf,
      const QueryLoc&,
      expr*,
      expr*);

public:
  expr* get_target_expr() const { return theTargetExpr; }

  expr* get_content_expr() const { return theContentExpr; }

  void compute_scripting_kind();

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;
};


/***************************************************************************//**

********************************************************************************/
class const_expr : public expr
{
  friend class ExprManager;
  friend class ExprIterator;
  friend class expr;

protected:
  store::Item_t theValue;

protected:
  const_expr(
      CompilerCB*,
      static_context*,
      user_function* udf,
      const QueryLoc&,
      zstring& sval);

  const_expr(
      CompilerCB*,
      static_context*,
      user_function* udf,
      const QueryLoc&,
      const std::string& sval);

  const_expr(
      CompilerCB*,
      static_context*,
      user_function* udf,
      const QueryLoc&,
      const char* sval);

  const_expr(
      CompilerCB*,
      static_context*,
      user_function* udf,
      const QueryLoc&,
      xs_integer);

  const_expr(
      CompilerCB*,
      static_context*,
      user_function* udf,
      const QueryLoc&,
      xs_decimal);

  const_expr(
      CompilerCB*,
      static_context*,
      user_function* udf,
      const QueryLoc&,
      xs_double);

  const_expr(
      CompilerCB*,
      static_context*,
      user_function* udf,
      const QueryLoc&,
      xs_boolean);

  const_expr(
      CompilerCB*,
      static_context*,
      user_function* udf,
      const QueryLoc&,
      const store::Item_t&);

  const_expr(
      CompilerCB*,
      static_context*,
      user_function* udf,
      const QueryLoc&,
      const char* ns,
      const char* pre,
      const char* local);

public:
  store::Item* get_val() const { return theValue.getp(); }

  void compute_scripting_kind();

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;
};


/***************************************************************************//**

********************************************************************************/
class extension_expr : public expr
{
  friend class ExprManager;
  friend class ExprIterator;
  friend class expr;

protected:
  std::vector<pragma*>   thePragmas;
  expr                 * theExpr;

protected:
  extension_expr(
      CompilerCB* ccb,
      static_context* sctx,
      user_function* udf,
      const QueryLoc&);

  extension_expr(
      CompilerCB* ccb,
      static_context* sctx,
      user_function* udf,
      const QueryLoc&,
      expr*);

public:
  void add(pragma* p) { thePragmas.push_back(p); }

  expr* get_expr() const { return theExpr; }

  void compute_scripting_kind();

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;
};


/////////////////////////////////////////////////////////////////////////
//                                                                     //
//  XQuery 3.0 expressions                                             //
//  [http://www.w3.org/TR/xquery-3/]                                   //
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

class catch_clause
{
  friend class expr;
  friend class trycatch_expr;
  friend class ExprManager;

public:
  enum var_type
  {
    err_code = 0,
    err_desc,
    err_value,
    err_module,
    err_line_no,
    err_column_no,
    zerr_data_module,
    zerr_data_line_no,
    zerr_data_column_no,
    zerr_stack_trace
  };

public:
  typedef rchandle<NodeNameTest> nt_t;
  typedef std::vector<nt_t> nt_list_t;
  typedef std::map<int, var_expr*> var_map_t;

protected:
  nt_list_t         theNameTests;
  var_map_t         theVarMap;
  CompilerCB *const theCCB;

  catch_clause(CompilerCB* ccb);

public:
  void set_nametests(nt_list_t& a) { theNameTests = a; }

  nt_list_t& get_nametests() { return theNameTests; }

  void add_nametest_h(nt_t n) { theNameTests.push_back(n); }

  void set_vars(var_map_t& a) { theVarMap = a; }

  var_map_t& get_vars() { return theVarMap; }

  void add_var(var_type v, var_expr* n) { theVarMap[v] = n; }

  catch_clause* clone(expr::substitution_t& subst) const;
};


class trycatch_expr : public expr
{
  friend class ExprManager;
  friend class ExprIterator;
  friend class expr;

protected:
  expr*                      theTryExpr;
  std::vector<expr*>         theCatchExprs;
  std::vector<catch_clause*> theCatchClauses;

protected:
  trycatch_expr(
      CompilerCB* ccb,
      static_context* sctx,
      user_function* udf,
      const QueryLoc&,
      expr* tryExpr);

public:
  expr* get_try_expr() const { return theTryExpr; }

  void set_try_expr(expr* e) { theTryExpr = e; }

  expr* get_catch_expr(csize i) const { return theCatchExprs[i]; }

  void add_catch_expr(expr* e);

  void add_clause(catch_clause* cc);

  csize clause_count() const { return theCatchClauses.size(); }

  const catch_clause* operator[](csize i) const { return theCatchClauses[i]; }

  void compute_scripting_kind();

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;
};


/////////////////////////////////////////////////////////////////////////
//                                                                     //
//  Zorba expressions                                                  //
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
  friend class ExprManager;

protected:
  expr    * theInput;

protected:
  wrapper_expr(
      CompilerCB* ccb,
      static_context* sctx,
      user_function* udf,
      const QueryLoc& loc,
      expr* wrapped);

public:
  expr* get_input() const { return theInput; }

  void set_expr(expr* e) { theInput = e;}

  void compute_scripting_kind();

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;
};


/***************************************************************************//**
  dummy expression for call stack traces
********************************************************************************/
class function_trace_expr : public expr
{
  friend class ExprIterator;
  friend class expr;
  friend class ExprManager;

protected:
  expr         * theInput;
  store::Item_t  theFunctionName;
  QueryLoc       theFunctionLocation;
  QueryLoc       theFunctionCallLocation;
  unsigned int   theFunctionArity;

protected:
  function_trace_expr(
      CompilerCB* ccb,
      static_context* sctx,
      user_function* udf,
      const QueryLoc& loc,
      expr* aChild);

  function_trace_expr(
      user_function* udf,
      expr* aExpr);

public:
  virtual ~function_trace_expr();

  expr* get_input() const { return theInput; }

  void compute_scripting_kind();

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;

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

  theOuterVarNames:
  -----------------
  The names of all the in-scope variables at the place where the call to the
  eval function appears at.

  theOuterVarTypes:
  -----------------
  The types of all the in-scope variables at the place where the call to the
  eval function appears at.

  theArgs:
  --------
  For each in-scope var, the vector contains an expr that returns the value of
  the var. The expr is either a reference to the var itself, or the domain expr
  of that var, if that var was inlined.

  theInnerScriptingKind:
  ----------------------

  theDoNodeCopy:
  --------------

********************************************************************************/
class eval_expr : public namespace_context_base_expr
{
  friend class ExprIterator;
  friend class expr;
  friend class ExprManager;

protected:
  expr                      * theExpr;

  std::vector<store::Item_t>  theOuterVarNames;

  std::vector<xqtref_t>       theOuterVarTypes;

  std::vector<expr*>          theArgs;

  expr_script_kind_t          theInnerScriptingKind;

  bool                        theDoNodeCopy;

protected:
  eval_expr(
      CompilerCB* ccb,
      static_context* sctx,
      user_function* udf,
      const QueryLoc& loc,
      expr* e,
      expr_script_kind_t scriptingKind,
      namespace_context* nsCtx);

public:
  expr* get_expr() const { return theExpr; }

  expr* get_arg_expr(csize i) { return theArgs[i]; }

  csize num_vars() const { return theOuterVarNames.size(); }

  const std::vector<store::Item_t>& get_var_names() const { return theOuterVarNames; }

  const std::vector<xqtref_t>& get_var_types() const { return theOuterVarTypes; }

  void add_var(var_expr* var);

  expr_script_kind_t get_inner_scripting_kind() const;

  bool getNodeCopy() const { return theDoNodeCopy; }

  void setNodeCopy(bool v) { theDoNodeCopy = true; }

  void compute_scripting_kind();

  void accept(expr_visitor&);

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
  friend class ExprManager;

private:
  expr*                      theExpr;
  checked_vector<var_expr*>  theVars;
  std::vector<expr*>         theArgs;
  bool                       theIsVarDeclaration;

protected:
  debugger_expr(
      CompilerCB* ccb,
      static_context* sctx,
      user_function* udf,
      const QueryLoc& loc,
      expr* aChild,
      namespace_context* nsCtx,
      bool aIsVarDeclaration);

public:
  expr* get_expr() const { return theExpr; }

  bool isVarDeclaration() const { return theIsVarDeclaration; }

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;

  csize var_count() const { return theVars.size(); }

  const var_expr* get_var(csize i) const { return theVars[i]; }

  void add_var(var_expr* var, expr* arg);

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
