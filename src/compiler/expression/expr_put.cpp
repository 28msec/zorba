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

#include <typeinfo>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include <zorba/config.h>

#include "system/properties.h"

#include "context/static_context_consts.h"

#include "compiler/expression/expr.h"
#include "compiler/expression/fo_expr.h"
#include "compiler/expression/script_exprs.h"
#include "compiler/expression/json_exprs.h"
#include "compiler/expression/update_exprs.h"
#ifndef ZORBA_NO_FULL_TEXT
#include "compiler/expression/ft_expr.h"
#include "compiler/expression/ftnode.h"
#endif /* ZORBA_NO_FULL_TEXT */
#include "compiler/expression/path_expr.h"
#include "compiler/expression/var_expr.h"
#include "compiler/expression/flwor_expr.h"
#include "compiler/expression/function_item_expr.h"
#include "compiler/parser/parse_constants.h"

#include "diagnostics/assert.h"
#include "functions/function.h"
#include "functions/udf.h"

#include "util/indent.h"

using namespace std;

namespace zorba
{

#define BEGIN_PUT_NO_LOCATION(LABEL) \
  os << indent << #LABEL << expr_addr(this) << " [\n" << inc_indent

#define BEGIN_PUT(LABEL) \
  os << indent << #LABEL << expr_addr(this) \
     << expr_loc(dynamic_cast<const expr*>(this)) << " [\n" << inc_indent

#define BEGIN_PUT2(STRING) \
  os << indent << STRING << expr_addr(this) \
     << expr_loc(dynamic_cast<const expr*>(this)) << " [\n" << inc_indent

#define BEGIN_PUT_NO_EOL(LABEL) \
  os << indent << #LABEL << expr_addr(this) \
     << expr_loc(dynamic_cast<const expr*>(this)) << " [ "

#define BEGIN_PUT1(LABEL,S1) \
  os << indent << #LABEL << ' ' << (S1) << expr_addr(this) \
     << expr_loc(dynamic_cast<const expr*>(this)) << " [\n" << inc_indent

#define END_PUT() \
  os << dec_indent << indent << "]\n"; return os;

#define PUT_SUB( LABEL, EXPR ) \
  if ( !(EXPR) ) ; else { os << indent << (LABEL) << "\n" << inc_indent; (EXPR)->put(os); os << dec_indent; }


static inline zstring qname_to_string(store::Item_t qname)
{
  zstring result;
  zstring pfx = qname->getPrefix();
  zstring ns = qname->getNamespace();
  if (! ns.empty())
    result += pfx.str() + "[=" + ns.str() + "]:";
  result += qname->getLocalName().str();
  return result;
}


static inline ostream& put_qname(store::Item_t qname, ostream& os)
{
  zstring pfx = qname->getPrefix();
  zstring ns = qname->getNamespace();
  if (! ns.empty())
    os << pfx << "[=" << qname->getNamespace() << "]:";
  os << qname->getLocalName();
  return os;
}


static inline string expr_addr(const void* e)
{
  if (Properties::instance()->noTreeIds ())
  {
    return "";
  }
  else
  {
    ostringstream os;
    os << " (" << e << ")";
    return os.str ();
  }
}


static inline string expr_loc(const expr* e)
{
  if (e == NULL)
    return "";

  if (Properties::instance()->printLocations())
  {
    ostringstream os;
    os << " (loc: " << e->get_loc().getLineBegin() << ", " << e->get_loc().getColumnBegin() << ")";
    return os.str ();
  }
  else
  {
    return "";
  }
}


#ifdef ZORBA_WITH_DEBUGGER
std::ostream&
debugger_expr::put(std::ostream& os) const
{
  BEGIN_PUT( debugger_expr );
  theExpr->put(os);
  END_PUT();
}
#endif

std::ostream&
wrapper_expr::put(std::ostream& os) const
{
#ifdef VERBOSE
  get_expr()->put(os);
  return os;
#else
  if (get_expr()->get_expr_kind() == var_expr_kind)
  {
    const var_expr* varExpr = static_cast<const var_expr*>(get_expr());

    BEGIN_PUT_NO_EOL(var_ref) ;
    put_qname(varExpr->get_name(), os);
    os << expr_addr(varExpr) << " ]" << endl;
    return os;
  }
  else
  {
    BEGIN_PUT( wrapper_expr );
    get_expr()->put(os);
    END_PUT();
  }
#endif
}

ostream& block_expr::put( ostream& os) const
{
  BEGIN_PUT( block_expr );
  for (checked_vector<expr*>::const_iterator i = this->theArgs.begin ();
       i != theArgs.end (); i++)
    (*i)->put (os);
  END_PUT();
}

ostream& var_expr::put(ostream& os) const
{
  os << indent << "var kind=" << decode_var_kind(get_kind()) << expr_addr(this);
  if (theName != NULL)
  {
    os << " name=";
    put_qname(get_name(), os);
  }

#if VERBOSE
  if (theDeclaredType != NULL)
  {
    os << " type=" << theDeclaredType->toString();
  }
#endif

  os << endl;
  return os;
}


ostream& for_clause::put(ostream& os) const
{
#if VERBOSE
  BEGIN_PUT( FOR );

  theVarExpr->put(os);
  PUT_SUB( "AT", thePosVarExpr );
  PUT_SUB( "SCORE", theScoreVarExpr );

  PUT_SUB("IN", theDomainExpr);

#else
  os << indent << "FOR" << expr_addr(this) << " ";

  put_qname(theVarExpr->get_name(), os);

  os << expr_addr(theVarExpr);

  if (thePosVarExpr != NULL)
  {
    os << " AT ";
    put_qname(thePosVarExpr->get_name(), os);
    os << expr_addr(thePosVarExpr);
  }
  os << endl << indent << "[\n" << inc_indent;

  theDomainExpr->put(os);
#endif

  END_PUT();
}


ostream& let_clause::put(ostream& os) const
{
#if VERBOSE
  BEGIN_PUT(LET);

  theVarExpr->put(os);
  PUT_SUB("SCORE", theScoreVarExpr);

  PUT_SUB(":=", theDomainExpr);

#else
  os << indent << "LET" << expr_addr(this) << " ";

  put_qname(theVarExpr->get_name(), os);

  os << expr_addr(theVarExpr);

  os << endl << indent << "[\n" << inc_indent;

  theDomainExpr->put(os);
#endif

  END_PUT();
}

ostream& window_clause::put(ostream& os) const
{
  BEGIN_PUT(WINDOW);
  theVarExpr->put(os);
  PUT_SUB("IN", theDomainExpr);
  PUT_SUB("START", theWinStartCond);
  PUT_SUB("STOP", theWinStopCond);
  END_PUT();
}


ostream& flwor_wincond::vars::put(ostream& os) const
{
  BEGIN_PUT_NO_LOCATION( flwor_wincond::vars );
  PUT_SUB( "AT", posvar );
  PUT_SUB( "CURR", curr );
  PUT_SUB( "NEXT", next );
  PUT_SUB( "PREV", prev );
  END_PUT();
}

ostream& flwor_wincond::put(ostream& os) const
{
  BEGIN_PUT_NO_LOCATION(flwor_wincond);
  PUT_SUB("IN-VARS", &get_in_vars());
  PUT_SUB("OUT-VARS", &get_out_vars());
  PUT_SUB("WHEN", theCondExpr);
  END_PUT();
}


ostream& group_clause::put(ostream& os) const
{
  BEGIN_PUT(group_clause);

  os << indent << "GROUP BY EXPRS";

  for (unsigned i = 0; i < theGroupVars.size(); i++)
  {
    PUT_SUB("", theGroupVars[i].first);
    os << inc_indent << indent << "-->" << dec_indent;
    theGroupVars[i].second->put(os) << endl;
  }

  os << indent << "NON GROUP BY VARS ";

  for (unsigned i = 0; i < theNonGroupVars.size(); i++)
  {
    PUT_SUB("", theNonGroupVars[i].first);
    os << inc_indent << indent << "-->" << dec_indent;
    theNonGroupVars[i].second->put(os) << endl;
  }

  END_PUT();
}


ostream& orderby_clause::put(ostream& os) const
{
  BEGIN_PUT(orderby_clause);

  //os << indent << "ORDER BY ";

  csize numColumns = num_columns();

  for (csize i = 0; i < numColumns; i++)
  {
    theOrderingExprs[i]->put(os);
  }
#if 0
  os << endl;

  os << indent << "VAR REBINDS ";
  for (unsigned i = 0; i < theRebindList.size (); i++)
  {
    os << "$";
    put_qname(theRebindList[i].first->get_varname(), os);
    os << " (" << theRebindList[i].first << " -> "
       << theRebindList[i].second << ") ";
  }
  os << endl;
#endif
  END_PUT();
}


ostream& materialize_clause::put(ostream& os) const
{
  BEGIN_PUT(materialize_clause);

  END_PUT();
}


ostream& flwor_expr::put(ostream& os) const
{
  BEGIN_PUT(flwor_expr);

  for (csize i = 0; i < num_clauses(); i++)
  {
    const flwor_clause& c = *(get_clause(i));

    switch (c.get_kind())
    {
    case flwor_clause::where_clause:
    {
      PUT_SUB( "WHERE", static_cast<const where_clause *>(&c)->get_expr() );
      break;
    }
    case flwor_clause::count_clause:
    {
      os << indent << "COUNT $";
      put_qname(static_cast<const count_clause *>(&c)->get_var()->get_name(), os);
      os << endl;
      break;
    }
    case flwor_clause::for_clause:
    {
      static_cast<const for_clause *>(&c)->put(os);
      break;
    }
    case flwor_clause::let_clause:
    {
      static_cast<const let_clause *>(&c)->put(os);
      break;
    }
    case flwor_clause::window_clause:
    {
      static_cast<const window_clause *>(&c)->put(os);
      break;
    }
    case flwor_clause::group_clause:
    {
      static_cast<const group_clause *>(&c)->put(os);
      break;
    }
    case flwor_clause::order_clause:
    {
      static_cast<const orderby_clause *>(&c)->put(os);
      break;
    }
    case flwor_clause::materialize_clause:
    {
      static_cast<const materialize_clause *>(&c)->put(os);
      break;
    }
    default:
    {
      ZORBA_ASSERT(false);
    }
    }
  }

  os << indent << "RETURN\n" << inc_indent;
  if (theReturnExpr == NULL)
  {
    os << indent << "NULL";
  }
  else
  {
    theReturnExpr->put(os);
  }
  os << dec_indent;
  END_PUT();
}

ostream& promote_expr::put(ostream& os) const
{
  os << indent << "promote_expr " << theTargetType->toString()
     << expr_addr (this) << " [\n" << inc_indent;
  theInputExpr->put(os);
  END_PUT();
}

ostream& trycatch_expr::put( ostream& os) const
{
  BEGIN_PUT( trycatch_expr );

  theTryExpr->put(os);

  ulong numClauses = (ulong)theCatchClauses.size();

  for (ulong i = 0; i < numClauses; ++i)
  {
    catch_clause* cc = theCatchClauses[i];
    os << indent << "CATCH ";
    os << "\n";
    theCatchExprs[i]->put(os);
  }
  os << dec_indent << indent << "]\n";
  return os;
}

ostream& eval_expr::put(ostream& os) const
{
  BEGIN_PUT( eval_expr );
  for (ulong i = 0; i < theArgs.size(); i++)
  {
    os << indent << "using $" << theVars[i]->get_name()->getStringValue() << " := [";
    os << endl << inc_indent;
    if (theArgs[i])
      theArgs[i]->put(os);
    os << dec_indent << indent << "]" << endl;
  }
  theExpr->put (os);
  END_PUT();
}

ostream& function_trace_expr::put(ostream& os) const
{
  BEGIN_PUT(function_trace_expr);
  theExpr->put(os);
  END_PUT();
}


ostream& apply_expr::put(ostream& os) const
{
  BEGIN_PUT(apply_expr);
  theExpr->put(os);
  END_PUT();
}


ostream& var_decl_expr::put(ostream& os) const
{
  BEGIN_PUT(var_decl_expr);

  theVarExpr->put(os);
  if (theInitExpr)
    theInitExpr->put(os);

  END_PUT();
}


ostream& var_set_expr::put(ostream& os) const
{
  BEGIN_PUT(var_set_expr);

  theVarExpr->put(os);
  theExpr->put(os);

  END_PUT();
}


ostream& if_expr::put(ostream& os) const
{
  BEGIN_PUT(if_expr);
  theCondExpr->put(os);
  PUT_SUB("THEN", theThenExpr);
  PUT_SUB("ELSE", theElseExpr);
  END_PUT();
}


ostream& fo_expr::put(ostream& os) const
{
  const store::Item* qname = theFunction->getName();
  BEGIN_PUT2( qname->getStringValue() << "/" << num_args() );
  csize numArgs = theArgs.size();

  for (csize i = 0; i < numArgs; ++i)
  {
    theArgs[i]->put(os);
  }

  END_PUT();
}


#ifndef ZORBA_NO_FULL_TEXT
ostream& ftcontains_expr::put( ostream &os ) const
{
  BEGIN_PUT( ftcontains_expr );
  PUT_SUB( "RANGE", range_ );
  ftselection_->put( os );
  PUT_SUB( "IGNORE", ftignore_ );
  END_PUT();
}
#endif /* ZORBA_NO_FULL_TEXT */


std::ostream& function_item_expr::put(std::ostream& os) const
{
  os << indent << "funtion_item_expr " << expr_addr(this) << inc_indent;

  if (theQName != NULL)
  {
    os << " " << theQName->getStringValue() << "/" << theArity;
    os << dec_indent << endl;
    return os;
  }
  else
  {
    os << " inline udf (" << theFunction.getp() << ") [\n";
    reinterpret_cast<const user_function*>(theFunction.getp())->getBody()->put(os);
    END_PUT();
  }
}


ostream& dynamic_function_invocation_expr::put(ostream& os) const
{
  BEGIN_PUT( dynamic_function_invocation_expr );

  theExpr->put(os);

  for (ulong i = 0; i < theArgs.size(); ++i)
    theArgs[i]->put(os);

  END_PUT();
}


ostream& instanceof_expr::put( ostream& os) const
{
  BEGIN_PUT1( instanceof_expr, theTargetType->toString() );
  theInputExpr->put(os);
  END_PUT();
}

ostream& treat_expr::put( ostream& os) const
{
  BEGIN_PUT1( treat_expr, theTargetType->toString() );
  theInputExpr->put(os);
  END_PUT();
}

ostream& castable_expr::put( ostream& os) const
{
  BEGIN_PUT1( castable_expr, theTargetType->toString() );
  theInputExpr->put(os);
  END_PUT();
}

ostream& cast_expr::put( ostream& os) const
{
  BEGIN_PUT1( cast_expr, theTargetType->toString() );
  theInputExpr->put(os);
  END_PUT();
}

ostream& name_cast_expr::put( ostream& os) const
{
  BEGIN_PUT( name_cast_expr );
  theInputExpr->put(os);
  END_PUT();
}


ostream& validate_expr::put(ostream& os) const
{
  BEGIN_PUT( validate_expr );

  switch (theMode)
  {
  case ParseConstants::val_strict: os << "strict\n"; break;
  case ParseConstants::val_lax: os << "lax\n"; break;
  case ParseConstants::val_typename: os << "typename\n"; break;
  default: os << "??\n";
  }
  theExpr->put(os) << endl;
  END_PUT();
}


ostream& extension_expr::put( ostream& os) const
{
  BEGIN_PUT( extension_expr );

  os << inc_indent << indent;
  os << '?'; put_qname (thePragmas[0]->theQName, os);
  os << ' ' << thePragmas[0]->theContent << endl << dec_indent;

  theExpr->put(os) << endl;
  END_PUT();
}

ostream& relpath_expr::put( ostream& os) const
{
  BEGIN_PUT( relpath_expr );

  for (std::vector<expr*>::const_iterator it = begin(); it != end(); ++it)
  {
    expr* expr = *it;
    if (it == begin ())
    {
      expr->put (os);
    }
    else
    {
      os << inc_indent << indent << "REL STEP " ;
      expr->put(os);
      os << endl << dec_indent;
    }
  }
  END_PUT();
}

ostream& axis_step_expr::put(ostream& os) const
{
  switch (theAxis)
  {
  case axis_kind_self:                os << "self"; break;
  case axis_kind_child:               os << "child"; break;
  case axis_kind_parent:              os << "parent"; break;
  case axis_kind_descendant:          os << "descendant"; break;
  case axis_kind_descendant_or_self:  os << "descendant-or-self"; break;
  case axis_kind_ancestor:            os << "ancestor"; break;
  case axis_kind_ancestor_or_self:    os << "ancestor-or-self"; break;
  case axis_kind_following_sibling:   os << "following-sibling"; break;
  case axis_kind_following:           os << "following"; break;
  case axis_kind_preceding_sibling:   os << "preceding-sibling"; break;
  case axis_kind_preceding:           os << "preceding"; break;
  case axis_kind_attribute:           os << "attribute"; break;
  default: os << "??";
  }

  if (theReverseOrder)
    os << "_reverse";

  os << "::";

  if (theNodeTest != NULL)
  {
    theNodeTest->put(os);
  }
  else
  {
    os << endl;
  }

  return os;
}


ostream& match_expr::put(ostream& os) const
{
  os << "match_expr [";
  switch (theTestKind)
  {
  case match_no_test:   os << "no_test("; break;
  case match_name_test: os << "name_test("; break;
  case match_doc_test:
  {
    os << "doc_test(";
    switch (theDocTestKind)
    {
    case match_no_test:   os << "no_test("; break;
    case match_elem_test: os << "element("; break;
    case match_attr_test: os << "attribute("; break;
    default: os << "(??";
    }
    break;
  }
  case match_elem_test:     os << "element("; break;
  case match_attr_test:     os << "attribute("; break;
  case match_xs_elem_test:  os << "schema-element("; break;
  case match_xs_attr_test:  os << "schema-element("; break;
  case match_pi_test:       os << "pi("; break;
  case match_comment_test:  os << "comment("; break;
  case match_text_test:     os << "text("; break;
  case match_anykind_test:  os << "node("; break;
  default: os << "(??";
  }

  switch (theWildKind)
  {
    case match_no_wild:
      if (theQName != NULL)
        put_qname (theQName, os);
      break;
    case match_all_wild:
      os << "*";
      break;
    case match_prefix_wild:
      os << "*:" << theWildName;
      break;
    case match_name_wild:
      os << theWildName << ":*";
      break;
    default:
      os << "??";
  }

  if (theTypeName != NULL)
  {
    put_qname (theTypeName, os) << endl;
  }

  os << ")]";
  return os;
}


ostream& const_expr::put(ostream& os) const
{
  BEGIN_PUT_NO_EOL( const_expr );
  if (theValue->isFunction())
  {
    os << "functrion item [ " << theValue->show() << " ]";
  }
  else
  {
    os << get_val()->getType()->getStringValue()
       << " [ " << theValue->show() << " ]";
  }
  os << " ]\n";
  return os;
}


ostream& order_expr::put(ostream& os) const
{
  os << indent << "order_expr" << expr_addr (this) << "\n" << inc_indent
     << indent << "[ ";

  switch (theType)
  {
  case ordered: os << "ordered\n"; break;
  case unordered: os << "unordered\n"; break;
  default: os << "??\n";
  }
  theExpr->put(os) << endl;
  END_PUT();
}


ostream& elem_expr::put(ostream& os) const
{
  BEGIN_PUT(elem_expr);

  os << indent << "copy nodes = " << theCopyInputNodes << std::endl;

  if (theQNameExpr != NULL)
    theQNameExpr->put(os);

  if (theAttrs != NULL)
    theAttrs->put(os);

  if (theContent != NULL)
    theContent->put(os);

  END_PUT();
}


ostream& doc_expr::put(ostream& os) const
{
  BEGIN_PUT(doc_expr);

  os << indent << "copy nodes = " << theCopyInputNodes << std::endl;

  theContent->put(os);

  END_PUT();
}


ostream& attr_expr::put(ostream& os) const
{
  BEGIN_PUT(attr_expr);

  theQNameExpr->put(os);
  PUT_SUB("=", theValueExpr);

  END_PUT();
}


ostream& text_expr::put(ostream& os) const
{
  BEGIN_PUT(text_expr);
  theContentExpr->put(os);
  END_PUT();
}

ostream& pi_expr::put(ostream& os) const
{
  BEGIN_PUT(pi_expr);
  PUT_SUB("TARGET", theTargetExpr);
  PUT_SUB("CONTENT", theContentExpr);
  END_PUT();
}


#ifdef ZORBA_WITH_JSON
ostream& json_array_expr::put(ostream& os) const
{
  BEGIN_PUT(json_array_expr);
  if (theContentExpr)
    theContentExpr->put(os);
  END_PUT();
}


ostream& json_object_expr::put(ostream& os) const
{
  BEGIN_PUT(json_object_expr);
  if (theContentExpr)
    theContentExpr->put(os);
  END_PUT();
}


ostream& json_direct_object_expr::put(ostream& os) const
{
  BEGIN_PUT(json_direct_object_expr);

  std::vector<expr*>::const_iterator ite1 = theNames.begin();
  std::vector<expr*>::const_iterator end1 = theNames.end();
  std::vector<expr*>::const_iterator ite2 = theValues.begin();
  for (; ite1 != end1; ++ite1, ++ite2)
  {
    (*ite1)->put(os);
    (*ite2)->put(os);
  }

  END_PUT();
}
#endif


ostream& insert_expr::put(ostream& os) const
{
  BEGIN_PUT( insert_expr );
  theSourceExpr->put(os);
  PUT_SUB( ",", theTargetExpr );
  END_PUT();
}

ostream& delete_expr::put(ostream& os) const
{
  BEGIN_PUT( delete_expr );
  theTargetExpr->put(os);
  END_PUT();
}

ostream& replace_expr::put(ostream& os) const
{
  BEGIN_PUT( replace_expr );
  theTargetExpr->put(os);
  PUT_SUB( ",", theSourceExpr );
  END_PUT();
}

ostream& rename_expr::put(ostream& os) const
{
  BEGIN_PUT(rename_expr);
  theTargetExpr->put(os);
  PUT_SUB(",", theSourceExpr);
  END_PUT();
}


ostream& copy_clause::put(ostream& os) const
{
  BEGIN_PUT_NO_LOCATION(copy);
  theVar->put(os);
  theExpr->put(os);
  END_PUT();
}


ostream& transform_expr::put(ostream& os) const
{
  BEGIN_PUT(transform_expr);

  for (vector<copy_clause*>::const_iterator it = theCopyClauses.begin();
       it != theCopyClauses.end(); ++it)
  {
    copy_clause* e = *it;
    e->put(os);
  }
  theModifyExpr->put(os);
  PUT_SUB(",", theReturnExpr);
  END_PUT();
}


ostream& exit_expr::put(ostream& os) const
{
  BEGIN_PUT(exit_expr);
  theExpr->put(os);
  END_PUT();
}


ostream& exit_catcher_expr::put(ostream& os) const
{
  BEGIN_PUT(exit_catcher_expr);
  theExpr->put(os);
  END_PUT();
}


ostream& flowctl_expr::put(ostream& os) const
{
  BEGIN_PUT(flowctl_expr);
  END_PUT();
}

ostream& while_expr::put(ostream& os) const
{
  BEGIN_PUT(while_expr);
  theBody->put(os);
  END_PUT();
}


}  // namespace zorba
/* vim:set et sw=2 ts=2: */
