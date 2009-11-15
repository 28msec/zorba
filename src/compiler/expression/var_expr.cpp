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

#include "types/typeops.h"

#include "compiler/expression/expr.h"
#include "compiler/expression/var_expr.h"
#include "compiler/expression/flwor_expr.h"
#include "compiler/expression/expr_visitor.h"

#include "zorbaserialization/serialization_engine.h"


namespace zorba 
{

SERIALIZABLE_CLASS_VERSIONS(var_expr)
END_SERIALIZABLE_CLASS_VERSIONS(var_expr)


ulong var_expr::theVarCounter = 0; //used for giving var_exprs unique ids


/*******************************************************************************

********************************************************************************/
std::string var_expr::decode_var_kind(enum var_kind k)
{
  switch (k) 
  {
  case for_var: return "FOR"; break;
  case let_var: return "LET"; break;
  case win_var: return "WIN"; break;
  case pos_var: return "POS"; break;
  case wincond_out_var: return "WINCOND"; break;
  case wincond_in_var: return "WINCOND IN"; break;
  case wincond_out_pos_var: return "WINCOND POS"; break;
  case wincond_in_pos_var: return "WINCOND IN POS"; break;
  case count_var: return "CNT"; break;
  case score_var: return "SCORE"; break;
  case prolog_var: return "PROLOG"; break;
  case local_var: return "LOCAL"; break;
  case catch_var: return "CATCH"; break;
  case copy_var: return "COPY"; break;
  case groupby_var: return "GROUPBY"; break;
  case non_groupby_var: return "NON-GROUPBY"; break;
  case arg_var: return "ARG"; break;
  default: return "???";
  }
}


/*******************************************************************************

********************************************************************************/
var_expr::var_expr(
    short sctx,
    const QueryLoc& loc,
    var_kind k,
    store::Item* name)
  :
  expr(sctx, loc),
  theKind(k),
  theName(name),
  theDeclaredType(NULL),
  theFlworClause(NULL),
  theCopyClause(NULL)
{
  theUniqueId = theVarCounter++;
}


/*******************************************************************************

********************************************************************************/
void var_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (expr*)this);
  SERIALIZE_ENUM(var_kind, theKind);
  ar & theName;
  ar & theDeclaredType;
  //+ar & theFlworClause;
  //+ar & theCopyClause;
  if(!ar.is_serializing_out())
  {
    theFlworClause = NULL;
    theCopyClause = NULL;
  }
  ar & theUniqueId;
}


/*******************************************************************************

********************************************************************************/
store::Item* var_expr::get_name() const 
{
  return theName.getp();
}


/*******************************************************************************

********************************************************************************/
xqtref_t var_expr::get_type() const 
{
  return theDeclaredType;
}


/*******************************************************************************

********************************************************************************/
void var_expr::set_type(xqtref_t t) 
{
  theDeclaredType = t;
}


/*******************************************************************************

********************************************************************************/
const var_expr* var_expr::get_pos_var() const 
{
  if (theKind == for_var) 
  {
    return reinterpret_cast<for_clause*>(theFlworClause)->get_pos_var();
  }
  else
  {
    return NULL;
  }
}


/*******************************************************************************

********************************************************************************/
expr* var_expr::get_domain_expr() const
{
  if (theFlworClause)
  {
    if (theKind == for_var ||
        theKind == let_var ||
        theKind == win_var ||
        theKind == wincond_in_var ||
        theKind == wincond_out_var)
    {
      return reinterpret_cast<forletwin_clause*>(theFlworClause)->get_expr();
    }
    else if (theKind == groupby_var)
    {
      return reinterpret_cast<group_clause*>(theFlworClause)->
             get_input_for_group_var(this);
    }
    else if (theKind == non_groupby_var)
    {
      return reinterpret_cast<group_clause*>(theFlworClause)->
             get_input_for_nongroup_var(this);
    }
  }
  else if (theCopyClause)
  {
    return theCopyClause->getExpr();
  }

  return NULL;
}


/*******************************************************************************

********************************************************************************/
forletwin_clause* var_expr::get_forletwin_clause() const 
{
  return dynamic_cast<forletwin_clause*>(theFlworClause);
}


/*******************************************************************************

********************************************************************************/
for_clause* var_expr::get_for_clause() const 
{
  return dynamic_cast<for_clause*>(theFlworClause);
}


/*******************************************************************************

********************************************************************************/
void var_expr::compute_scripting_kind() const
{
  theCache.scripting_kind.kind = SIMPLE_EXPR;
  theCache.scripting_kind.valid = true;  
}


/*******************************************************************************

********************************************************************************/
xqtref_t var_expr::return_type_impl(static_context* sctx) const 
{
  RootTypeManager& rtm = GENV_TYPESYSTEM;

  xqtref_t derivedType;
  expr* domainExpr;

  // The translator has already set theDeclaredType of pos_vars, count_vars,
  // wincond_out_pos_vars, and wincond_in_pos_vars to xs:positiveInteger.
  if (theKind == pos_var ||
      theKind == wincond_out_pos_var ||
      theKind == wincond_in_pos_var)
  {
    return theDeclaredType;
  }
  else if (theKind == for_var ||
           theKind == let_var ||
           theKind == win_var || 
           theKind == wincond_in_var ||
           theKind == wincond_out_var ||
           theKind == groupby_var ||
           theKind == non_groupby_var ||
           theKind == copy_var) 
  {
    domainExpr = get_domain_expr();
    ZORBA_ASSERT(domainExpr != NULL);

    xqtref_t domainType = domainExpr->return_type(sctx);

    if (theKind == for_var) 
    {
      derivedType = TypeOps::prime_type(*domainType);
    }
    else if (theKind == wincond_in_var || theKind == wincond_out_var)
    {
      // TODO: we can be a little more specific here: if the quantifier of the
      // domain type is PLUS or ONE, then the quantifier of the "current" cond
      // var is ONE.
      derivedType = rtm.create_type(*domainType, TypeConstants::QUANT_QUESTION);
    }
    else if (theKind == non_groupby_var)
    {
      derivedType = rtm.create_type(*domainType, TypeConstants::QUANT_STAR);
    }
    else
    {
      derivedType = domainType;
    }
  }

  if (derivedType == NULL) 
  {
    return (theDeclaredType == NULL ? rtm.ITEM_TYPE_STAR : theDeclaredType);
  }

  return (theDeclaredType == NULL ?
          derivedType :
          TypeOps::intersect_type(*derivedType, *theDeclaredType));
}


/*******************************************************************************

********************************************************************************/
void var_expr::next_iter(expr_iterator_data& v) 
{
  BEGIN_EXPR_ITER();
  END_EXPR_ITER();
}


/*******************************************************************************

********************************************************************************/
expr::expr_t var_expr::clone(expr::substitution_t& subst) const
{
  expr::subst_iter_t i = subst.find(this);

  if (i == subst.end()) 
    return const_cast<var_expr*>(this);

  return i->second;
}


/*******************************************************************************

********************************************************************************/
void var_expr::accept(expr_visitor& v)
{
  if (v.begin_visit(*this))
    accept_children(v);

  v.end_visit(*this); 
}


/*******************************************************************************

********************************************************************************/
void global_binding::serialize(::zorba::serialization::Archiver& ar)
{
  ar & ext;
}


}

