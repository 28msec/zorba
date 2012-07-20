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
#ifndef ZORBA_COMPILER_EXPRESSIONS_EXPR_ITER
#define ZORBA_COMPILER_EXPRESSIONS_EXPR_ITER

#include <zorba/config.h>

#include "common/shared_types.h"

#include "compiler/expression/flwor_expr.h"
#include "compiler/expression/update_exprs.h"

namespace zorba
{

/*******************************************************************************
  A class to iterate over the subexpressions of an expr.
********************************************************************************/
class ExprIterator
{
protected:
  expr                                 * theExpr;

  expr                                ** theCurrentChild;
  int                                    theState;

  std::vector<expr*>::iterator          theArgsIter;
  std::vector<expr*>::iterator          theArgsEnd;

  flwor_expr::clause_list_t::iterator    theClausesIter;
  flwor_expr::clause_list_t::iterator    theClausesBegin;
  flwor_expr::clause_list_t::iterator    theClausesEnd;
  flwor_clause::rebind_list_t::iterator  theGroupVarsIter;
  flwor_clause::rebind_list_t::iterator  theGroupVarsEnd;
  flwor_clause::rebind_list_t::iterator  theNonGroupVarsIter;
  flwor_clause::rebind_list_t::iterator  theNonGroupVarsEnd;
  int                                    theWincondIter;

  std::vector<copy_clause_t>::iterator   theCopyClauseIter;
  std::vector<copy_clause_t>::iterator   theCopyClauseEnd;

#ifndef ZORBA_NO_FULL_TEXT
  std::vector<expr**>                   theFTSelectionExprs;
  std::vector<expr**>::iterator         theFTSelectionExprsIter;
  std::vector<expr**>::iterator         theFTSelectionExprsEnd;
#endif /* ZORBA_NO_FULL_TEXT */

public:
  ExprIterator(expr* e);

  ~ExprIterator() {}

  void next();

  expr** operator*() const { return (theCurrentChild); }

  bool done() const { return theCurrentChild == expr::iter_done; }

private:
  // comparisson forbidden; use done()
  bool operator==(const ExprIterator& other) { return false; }
  ExprIterator& operator=(const ExprIterator& other);
  ExprIterator(const ExprIterator& other);
};


class ExprConstIterator : public ExprIterator
{
public:
  ExprConstIterator(const expr* e)
    :
    ExprIterator(const_cast<expr*>(e))
  {
  }

  expr* get_expr() const { return *theCurrentChild; }
};


}


#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
