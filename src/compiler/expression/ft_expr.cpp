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

#include "compiler/expression/expr_visitor.h"
#include "compiler/expression/ft_expr.h"
#include "compiler/expression/ftnode.h"
#include "compiler/expression/ftnode_visitor.h"

#include "compiler/api/compilercb.h"

using namespace std;

namespace zorba {


#define EV_ACCEPT( EXPR, V )                  \
    if ( !(EXPR) ) ; else (EXPR)->accept( V )

///////////////////////////////////////////////////////////////////////////////

ftcontains_expr::ftcontains_expr(
  CompilerCB* ccb,
  static_context* sctx,
  user_function* udf,
  QueryLoc const &loc,
  expr* range,
  ftnode *ftselection,
  expr* ftignore
) :
  expr(ccb, sctx, udf, loc, ft_expr_kind ),
  range_( range ),
  ftselection_( ftselection ),
  ftignore_( ftignore )
{
  ZORBA_ASSERT( range );
  ZORBA_ASSERT( ftselection );
  compute_scripting_kind();
}


void ftcontains_expr::accept( expr_visitor &v ) {
  if ( v.begin_visit( *this ) ) {
    EV_ACCEPT( range_, v );
    ftselection_->accept( *v.get_ftnode_visitor() );
    EV_ACCEPT( ftignore_, v );
  }
  v.end_visit( *this );
}


void ftcontains_expr::compute_scripting_kind() 
{
  checkSimpleExpr(range_);

  theScriptingKind = SIMPLE_EXPR;
  // TODO: checkIsSimple for all sub-expr
}


} // namespace zorba
/* vim:set et sw=2 ts=2: */
