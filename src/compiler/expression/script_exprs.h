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

#include <vector>

#include "compiler/expression/expr_base.h"


namespace zorba
{

class expr_visitor;
class var_expr;
class exit_catcher_expr;


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
  std::vector<expr_t> theArgs;

public:
  block_expr(
      static_context* sctx,
      const QueryLoc& loc,
      bool allowLastUpdating,
      std::vector<expr_t>& seq,
      std::vector<var_expr*>* assignedVars);

  ~block_expr();

  void add_at(csize pos, const expr_t& arg);

  csize size() const { return theArgs.size(); }

  const expr* operator[](csize i) const { return theArgs[i]; }

  expr* operator[](csize i) { return theArgs[i]; }

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
  var_decl_expr(
      static_context* sctx,
      const QueryLoc& loc,
      const var_expr_t& varExpr,
      const expr_t& initExpr);

  ~var_decl_expr();

  var_expr* get_var_expr() const { return theVarExpr.getp(); }

  expr* get_init_expr() const { return theInitExpr.getp(); }

  void compute_scripting_kind();

  expr_t clone(substitution_t& s) const;

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;
};


/*******************************************************************************

  AssignStatement ::= "$" VarName ":=" ExprSingle ";"

  The RHS of the assignment must be a non-updating expr.

  var_set_expr is used to assign a value to a prolog or block-local var. During
  runtime, the function computes theExpr and stores the resulting value inside
  the appropriate dynamic ctx (global or local), at the location that is identified
  by the variable id.
********************************************************************************/
class var_set_expr : public expr
{
  friend class ExprIterator;
  friend class expr;

protected:
  var_expr_t theVarExpr;
  expr_t     theExpr;

public:
  var_set_expr(
      static_context* sctx,
      const QueryLoc& loc,
      const var_expr_t& varExpr,
      const expr_t& setExpr);

  ~var_set_expr();

  var_expr* get_var_expr() const { return theVarExpr.getp(); }

  expr* get_expr() const { return theExpr.getp(); }

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
  expr_t               theExpr;

  exit_catcher_expr  * theCatcherExpr;

public:
  exit_expr(static_context* sctx, const QueryLoc& loc, const expr_t& inExpr);

  ~exit_expr();

  expr* get_expr() const { return theExpr.getp(); }

  void setCatcherExpr(exit_catcher_expr* e) { theCatcherExpr = e; }

  void compute_scripting_kind();

  expr_t clone(substitution_t& s) const;

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;
};


/*******************************************************************************
  A "helper" expr to catch the exception thrown by an exit_expr that appears
  inside a UDF. It is placed between the return-type-checking expr(s) at the
  top of the UDF body and the effective UDF body.

  theExpr:
  --------
  The child expr of "this" exit_catcher_expr (i.e., the effective UDF body).

  theExitExprs:
  -------------
  All the exit_exprs that appear in the body of the udf.
********************************************************************************/
class exit_catcher_expr : public expr
{
  friend class ExprIterator;
  friend class expr;

private:
  expr_t             theExpr;

  std::vector<expr*> theExitExprs;

public:
  exit_catcher_expr(
      static_context* sctx,
      const QueryLoc& loc,
      const expr_t& inExpr,
      std::vector<expr*>& exitExprs);

  ~exit_catcher_expr();

  expr* get_expr() const { return theExpr.getp(); }

  std::vector<expr*>::const_iterator exitExprsBegin() const
  {
    return theExitExprs.begin();
  }

  std::vector<expr*>::const_iterator exitExprsEnd() const
  {
    return theExitExprs.end();
  }

  void removeExitExpr(const expr* exitExpr);

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
  flowctl_expr(static_context* sctx, const QueryLoc& loc, enum action action);

  enum action get_action() const { return theAction; }

  expr_t clone(substitution_t& s) const;

  void compute_scripting_kind();

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;
};


/*******************************************************************************
  WhileExpr ::= "while" "(" Expr ")" Statement

  theBody : It is a block_expr, whose 1st child is the following expr:
            if (cond_expr) then () else break
            The subsequent children are what it generated by the Statement.
********************************************************************************/
class while_expr : public expr
{
  friend class ExprIterator;
  friend class expr;

protected:
  expr_t theBody;

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
/* vim:set et sw=2 ts=2: */
