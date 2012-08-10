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
#include <vector>
#include <utility>


#include "functions/function.h"

#include "compiler/indexing/index_tools.h"
#include "compiler/expression/flwor_expr.h"
#include "compiler/expression/path_expr.h"
#include "compiler/expression/fo_expr.h"
#include "compiler/expression/expr.h"

#include "system/globalenv.h"

#include "store/api/item_factory.h"

namespace zorba {


/*******************************************************************************
  Return true if the given expr is of the form "fn:collection(arg_expr)" where
  arg_expr is a constant.
********************************************************************************/
static bool isHoistableCollection(expr* e)
{
  if (e->get_expr_kind() != fo_expr_kind)
    return false;

  fo_expr* fo = static_cast<fo_expr *>(e);

  if (fo->get_func()->getKind() != FunctionConsts::FN_COLLECTION_1 ||
      fo->num_args() != 1)
    return false;

  const expr* arg = fo->get_arg(0);
  return arg->is_constant();
}


/*******************************************************************************
  Assuming that the given expr is of the form "fn:collection(arg_expr)" where
  arg_expr is a constant, return the URI of the collection (i.e., the string
  value of the const arg).
********************************************************************************/
static zstring* getCollectionName(const expr* e)
{
  const fo_expr* fo = static_cast<const fo_expr *>(e);
  const const_expr* arg = static_cast<const const_expr *>(fo->get_arg(0));
  const store::Item* val = arg->get_val();
  return val->getStringValueP();
}


typedef std::vector<std::pair<expr_t, expr_t> > hoisted_collections_t;


/*******************************************************************************

********************************************************************************/
static var_expr* createTempLetVar(short sctx, const QueryLoc& loc, int counter)
{
  std::stringstream ss;
  ss << "$$opt_temp_" << (counter);
  std::string varname = ss.str();
  store::Item_t qname;
  GENV_ITEMFACTORY->createQName(qname, "", "", varname.c_str());
  var_expr* var = new var_expr(sctx, loc, var_expr::let_var, qname);

  return var;
}


/*******************************************************************************

********************************************************************************/
static expr_t hoistCollectionSources(
    expr_t e,
    hoisted_collections_t& h,
    int& count)
{
  if (isHoistableCollection(e.getp()))
  {
    var_expr* var = createTempLetVar(e->get_sctx_id(), e->get_loc(), count);
    std::pair<expr_t, expr_t> p(var.getp(), e);
    h.push_back(p);
    return new wrapper_expr(e->get_sctx_id(), e->get_loc(), var.getp());
  }

  expr_iterator i = e->expr_begin();
  while(!i.done())
  {
    *i = hoistCollectionSources(*i, h, count);
    ++i;
  }

  return e;
}


/*******************************************************************************
  This function tries to see if the given expression is a map in the given var.
  If this returns true, then it is guaranteed to be a map. If it returns false,
  it may still be a map, but this algorithm could not determine that.
  It assumes that the variable occurs at most once.
********************************************************************************/
static bool isMapInVar(const expr* e, const var_expr* var)
{
  if (e == var)
  {
    return true;
  }

  switch(e->get_expr_kind())
  {
    case wrapper_expr_kind:
      return isMapInVar(static_cast<const wrapper_expr *>(e)->get_expr(), var);

    case flwor_expr_kind:
    {
      const flwor_expr* flwor = static_cast<const flwor_expr *>(e);

      for(int i = static_cast<int>(flwor->num_clauses()) - 1; i >= 0; --i)
      {
        const flwor_clause* clause = (*flwor)[i];
        bool isMap = false;

        switch(clause->get_kind())
        {
          case flwor_clause::for_clause:
            isMap = (isMap ||
                     isMapInVar(static_cast<const for_clause *>(clause)->get_expr(), var));

          case flwor_clause::let_clause:
          case flwor_clause::where_clause:
          case flwor_clause::order_clause:
            continue;

          default:
            return false;
        }

        return isMap;
      }
    }

    case relpath_expr_kind:
    {
      const relpath_expr* re = static_cast<const relpath_expr *>(e);
      return isMapInVar((*re)[0], var);
    }

    default:
      break;
  }

  return false;
}


/*******************************************************************************

********************************************************************************/
void IndexTools::inferIndexCreators(ValueIndex *vi)
{
  expr *de = vi->getDomainExpr();
  expr_t ne = de->clone();
  hoisted_collections_t h;
  int count = 0;
  expr_t he = hoistCollectionSources(ne, h, count);
  if (h.size() > 1) {
    return;
  }
  /*

    Commenting out for now. But these are the things that need to happen here:

      0. Create an expression that is of the following form:

        let $t := $externalVar
        for $de in $t
        let $k1 := key1($de)
        let $k2 := key1($de)
        .
        .
        .
        return createTuple($k1, $k2, ... $de)

      1. For each substituted variable that the DE is a map in, replace it
      with an external variable

      2. Create an IndexCreator that is capable of evaluating this expression
      with the external variable set to the given item in the appendIndexEntries() call.

      3. For each tuple that is returned by this plan, create an IndexEntry containing
      the contents of the tuple.



  expr_t e = new flwor_expr(de->get_loc(), true);
  flwor_expr *f = static_cast<flwor_expr *>(e.getp());
  for(hoisted_collections_t::iterator i = h.begin(); i != h.end(); ++i) {
    var_expr *var = static_cast<var_expr *>(i->first.getp());
    expr *ce = i->second.getp();
    xpqStringStore *cName = getCollectionName(ce);

    let_clause_t lc = new let_clause(i->first->get_loc(), var, i->second.getp());
    var->set_flwor_clause(lc.getp());

    f->add_clause(lc.getp());
  }
  f->set_return_expr(he.getp());
  */
}

}
/* vim:set et sw=2 ts=2: */
