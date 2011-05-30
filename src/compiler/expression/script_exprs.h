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
#ifndef ZORBA_COMPILER_SCRIPT_EXPRS
#define ZORBA_COMPILER_SCRIPT_EXPRS

#include <string>
#include <vector>

#include <zorba/store_consts.h>

#include "compiler/expression/expr_base.h"

#include "zorbautils/checked_vector.h"

#include "zorbatypes/representations.h"

#include "diagnostics/xquery_diagnostics.h"

#include "context/static_context.h"

#include "types/typeimpl.h"

#include "store/api/item.h"

namespace zorba 
{

class expr_visitor;
class var_expr;


/***************************************************************************//**

  MainModule := Prolog Program

  Program := StatementsAndOptionalExpr

  StatementsAndOptionalExpr := Statements Expr?

  StatementsAndExpr := Statements Expr

  Statements := Statement*

  Statement := ApplyStatement      |
               VarDeclStatement    |
               AssignStatement     |
               WhileStatement      |
               BreakStatement      |
               ContinueStatement   |
               ExitStatement       |

               BlockStatement      |
               FLWORStatement      |
               IfStatement         |
               SwitchStatement     |
               TypeSwitchStatement |
               TryCatchStatement

  Expr := ExprSingle ("," ExprSingle)*

  ExprSingle := FLWORExpr      |
                IfExpr         |
                SwitchExpr     |
                TypeSwitchExpr |
                TryCatchExpr   |

                ExprSimple

  ExprSimple := QuantifiedExpr |
                OrExpr         |   <-- this may end up being a BlockExpr
                InsertExpr     |
                DeleteExpr     |
                ReplaceExpr    |
                RenameExpr     |
                TransformExpr

  BlockStatement := "{" Statements "}"

  BlockExpr := "{" StatementsAndExpr "}"

  Semantics:

  The runtime implementation of block expr is very permissive: it evaluates each
  operand from left to right and returns its result (if any). The implementation
  does not care if the result of an operand is XDM or PUL or both; it simply
  propagates the result to the consumer iterator.

  However, the translator makes sure that a block expr does not mix updating
  and sequential expressions. (there is one exception to this rule; see below.)

  The translator is still more permissive than the grammar. It allows a block
  expr to mix simple and sequential exprs, or simple and updating exprs. In
  contrast, the grammar allows only the last operand to be simple; all the other
  operands must be sequential or vacuous.

  EXCEPTION: At the top level, a Program consists of 0 or more statements 
  followed by an expr, which may be updating. In the case of a "normal" program,
  we can wrap this expr with an apply_expr and model the Program as a block
  expr. However, this does not work in the case of eval-updating. The solution
  is to pass a special flag to the constructor of block expr to allow the last
  operand to be an updating expr.
********************************************************************************/
class block_expr : public expr
{
  friend class ExprIterator;
  friend class expr;

protected:
  checked_vector<expr_t> theArgs;

public:
  SERIALIZABLE_CLASS(block_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(block_expr, expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  block_expr(
      static_context* sctx,
      const QueryLoc& loc,
      bool allowLastUpdating,
      std::vector<expr_t>& seq,
      std::vector<var_expr*>* assignedVars);

  void add_at(ulong pos, const expr_t& arg);

  ulong size() const { return (ulong)theArgs.size(); }

  const expr_t& operator[](ulong i) const { return theArgs[i]; }

  expr_t& operator[](ulong i) { return theArgs[i]; }

  expr_t clone(substitution_t& s) const;

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;

private:
  void compute_scripting_kind();

  void compute_scripting_kind2(    
      std::vector<var_expr*>* assignedVars,
      bool allowLastUpdating) ;
};


/*******************************************************************************
  ApplyStatement ::= ExprSimple ";"
********************************************************************************/
class apply_expr : public expr 
{
  friend class ExprIterator;
  friend class expr;

private:
  expr_t theExpr;
  bool   theDiscardXDM;

public:
  SERIALIZABLE_CLASS(apply_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(apply_expr, expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  apply_expr(
      static_context* sctx,
      const QueryLoc& loc,
      const expr_t& inExpr,
      bool discardXDM);

  expr* get_expr() const { return theExpr.getp(); }

  bool discardsXDM() const { return theDiscardXDM; }

  void compute_scripting_kind();

  expr_t clone(substitution_t& s) const;

  void accept(expr_visitor&);

	std::ostream& put(std::ostream&) const;
};


/*******************************************************************************

  For Global Var:
  ----------------

  AnnotatedDecl ::= "declare" Annotation* (VarDecl | FunctionDecl)

  Annotation ::= "%" EQName ("(" Literal ("," Literal)* ")")?

  VarDecl ::= "variable" "$" VarName TypeDeclaration? 
              ((":=" VarValue) | ("external" (":=" VarDefaultValue)?))

  For Local Var:
  --------------

  VarDeclExpr ::= ("local" Annotation*)? "variable" "$" VarName TypeDeclaration?
                  (":=" ExprSingle)?

  var_decl_expr is used to declare block-local and prolog variables (including 
  the context item, if it is declared in the prolog). During runtime, the
  associated iterator creates in the local dynamic context a binding between 
  the variable id and the variable value. If the declaration includes an
  initializing expr, the iterator computes the initExpr and stores the resulting
  value inside this binding.

  Note: the init expr must be non-updating. For global vars, it must also be
  non-sequential.
********************************************************************************/
class var_decl_expr : public expr 
{
  friend class ExprIterator;
  friend class expr;

protected:
  var_expr_t theVarExpr;
  expr_t     theInitExpr;

public:
  SERIALIZABLE_CLASS(var_decl_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(var_decl_expr, expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  var_decl_expr(
      static_context* sctx,
      const QueryLoc& loc,
      const var_expr_t& varExpr,
      const expr_t& initExpr);

  var_expr* get_var_expr() const { return theVarExpr.getp(); }

  expr* get_init_expr() const { return theInitExpr.getp(); }

  void compute_scripting_kind();

  expr_t clone(substitution_t& s) const;

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;
};


/*******************************************************************************
  ExitExpr ::= "exit" "with" ExprSingle
********************************************************************************/
class exit_expr : public expr 
{
  friend class ExprIterator;
  friend class expr;

private:
  expr_t theExpr;

public:
  SERIALIZABLE_CLASS(exit_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(exit_expr, expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  exit_expr(static_context* sctx, const QueryLoc& loc, const expr_t& inExpr);

  expr* get_value() const { return theExpr.getp(); }

  void compute_scripting_kind();

  expr_t clone(substitution_t& s) const;

  void accept(expr_visitor&);

	std::ostream& put(std::ostream&) const;
};


/*******************************************************************************
  A "helper" expr to catch the ExitExpr thrown by an exit_expr.
********************************************************************************/
class exit_catcher_expr : public expr 
{
  friend class ExprIterator;
  friend class expr;

private:
  expr_t theExpr;

public:
  SERIALIZABLE_CLASS(exit_catcher_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(exit_catcher_expr, expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  exit_catcher_expr(static_context* sctx, const QueryLoc& loc, const expr_t& inExpr);

  expr* get_expr() const { return theExpr.getp(); }

  void compute_scripting_kind();

  expr_t clone(substitution_t& s) const;

  void accept(expr_visitor&);

	std::ostream& put(std::ostream&) const;
};


/*******************************************************************************

********************************************************************************/
class flowctl_expr : public expr 
{
  friend class ExprIterator;
  friend class expr;

public:
  enum action { BREAK, CONTINUE };

protected:
  enum action theAction;

public:
  SERIALIZABLE_CLASS(flowctl_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(flowctl_expr, expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  flowctl_expr(static_context* sctx, const QueryLoc& loc, enum action action);

  enum action get_action() const { return theAction; }

  expr_t clone(substitution_t& s) const;

  void compute_scripting_kind();

  void accept(expr_visitor&);

	std::ostream& put(std::ostream&) const;
};


/*******************************************************************************
	WhileExpr ::= "while" "(" ExprSingle ")" WhileBody

  WhileBody ::= Block
********************************************************************************/
class while_expr : public expr 
{
  friend class ExprIterator;
  friend class expr;

protected:
  expr_t theBody;

public:
  SERIALIZABLE_CLASS(while_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(while_expr, expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  while_expr(static_context* sctx, const QueryLoc& loc, expr_t body);

  expr* get_body() const { return theBody.getp(); }

  void compute_scripting_kind();

  expr_t clone(substitution_t& s) const;

  void accept(expr_visitor&);

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
