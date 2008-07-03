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
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "context/static_context_consts.h"

#include "compiler/expression/expr.h"
#include "compiler/parser/parse_constants.h"
#include "compiler/parsetree/parsenodes.h"

#include "functions/function.h"

#include "types/typeops.h"

#include "zorbaerrors/Assert.h"
#include "util/tracer.h"
#include "util/properties.h"

#include "system/globalenv.h"

using namespace std;
namespace zorba {
  
  static inline ostream &put_qname (store::Item_t qname, ostream &os) {
    xqp_string pfx = qname->getPrefix (), ns = qname->getNamespace();
    if (! ns.empty ())
      os << pfx << "[=" << qname->getNamespace()->str() << "]:";
    os << qname->getLocalName()->str();
    return os;
  }

static int printdepth0 = -2;

#define DENT      string(printdepth0, ' ')
#define UNDENT    printdepth0 -= 2;
#define INDENT    (printdepth0 += 2, DENT)

#define BEGIN_EXPR( descr) os << INDENT << #descr << expr_addr (this) << " [\n"
#define CLOSE_EXPR os << DENT << "]\n"; UNDENT; return os;
#define PUT_SUB( descr, sub ) do { if ((sub) != NULL) { os << DENT << (descr) << "\n"; (sub)->put (os); } } while (0)

static inline string expr_addr (const void *e) {
  if (Properties::instance ()->noTreeIds ())
    return "";
  else {
    ostringstream os;
    os << " (" << e << ")";
    return os.str ();
  }
}

ostream& sequential_expr::put( ostream& os) const
{
  BEGIN_EXPR (sequential_expr);
  for (checked_vector<expr_t>::const_iterator i = this->sequence.begin ();
       i != sequence.end (); i++)
    (*i)->put (os);
  CLOSE_EXPR;
}

ostream& var_expr::put(ostream& os) const
{
  os << INDENT << "var kind=" << decode_var_kind(get_kind()) << expr_addr (this);
  if (varname_h != NULL)
  {
    os << " name=";
    put_qname (get_varname(), os);
  }
  if (type != NULL) {
    os << " type=" << type->toString ();
  }
  os << endl;
  UNDENT;
  return os;
}

ostream & forlet_clause::put( ostream& os) const
{
  BEGIN_EXPR (forlet);

  var_h->put(os);
  PUT_SUB ("AT", pos_var_h);
  PUT_SUB ("SCORE", score_var_h);

  PUT_SUB (var_h->get_kind() == var_expr::for_var ? "IN" : ":=", expr_h);

  CLOSE_EXPR;
}

ostream& flwor_expr::put( ostream& os) const
{
  BEGIN_EXPR (flwor_expr);

  vector<forletref_t>::const_iterator it = clause_begin();
  for (; it!=clause_end(); ++it)
  {
    forletref_t fl_h = *it;
    fl_h->put(os);
  }

  PUT_SUB ("WHERE", where_h);

  for (flwor_expr::group_list_t::const_iterator lIter = group_begin();
       lIter != group_end();
       ++lIter)
  {
    groupref_t lGroup = *lIter;
    os << INDENT << "GROUP BY [\n";
    os << INDENT << "Outer:\n";
    lGroup->getOuterVar()->put(os);
    PUT_SUB ("Inner:", lGroup->getInnerVar());
    UNDENT;
    os << DENT << "]\n"; UNDENT;
  }
  
  for (vector<orderspec_t>::const_iterator ord_it = orderspec_begin();
       ord_it!=orderspec_end(); ++ord_it) 
  {
    orderspec_t spec = *ord_it;
    expr_t e_h = spec.first;
    orderref_t ord_h = spec.second;

    os << DENT << "ORDER BY ";
    switch (ord_h->dir) 
    {
    case ParseConstants::dir_ascending: os << "ASCENDING "; break;
    case ParseConstants::dir_descending: os << "DESCENDING "; break;
    default: os << "?? ";
    }
    switch (ord_h->empty_mode) 
    {
    case StaticContextConsts::empty_greatest: os << "EMPTY GREATEST "; break;
    case StaticContextConsts::empty_least: os << "EMPTY LEAST "; break;
    default: os << "?? ";
    }
    os << ord_h->collation << endl;
    os << DENT; e_h->put(os);
  }

  os << DENT << "RETURN\n";
  if (retval_h == NULL) {
    os << "$NULL$";
  } else {
    retval_h->put(os);
  }

  CLOSE_EXPR;
}

ostream& promote_expr::put(ostream& os) const
{
  os << INDENT << "promote_expr " << target_type->toString () << expr_addr (this) << " [\n";
  input_expr_h->put(os);
  CLOSE_EXPR;
}

ostream& trycatch_expr::put( ostream& os) const
{
  BEGIN_EXPR (trycatch_expr);

  try_expr_h->put(os);

  for (vector<clauseref_t>::const_iterator it = catch_clause_hv.begin();
       it!=catch_clause_hv.end(); ++it)
  {
    clauseref_t cc_h = *it;
    os << DENT << "CATCH ";
    if (cc_h->var_h!=NULL) cc_h->var_h->put(os);
    os << "\n";
    cc_h->catch_expr_h->put(os);
  }
  os << DENT << "]\n";
  return os;
}

ostream& eval_expr::put( ostream& os) const
{
  BEGIN_EXPR (eval_expr);
  expr_h->put (os);
  CLOSE_EXPR;
}

ostream& typeswitch_expr::put( ostream& os) const
{
  BEGIN_EXPR (typeswitch_expr);

  switch_expr_h->put(os);

  for (vector<clauseref_t>::const_iterator it = case_clause_hv.begin();
       it!=case_clause_hv.end(); ++it)
  {
    clauseref_t cc_h = *it;
    os << INDENT << "case: ";
    if (cc_h->var_h!=NULL) cc_h->var_h->put(os) << " as ";
    // TODO(VRB) os << sequence_type::describe(cc_h->type);
    os << " return ";
    cc_h->case_expr_h->put(os) << endl;
    UNDENT;
  }
  CLOSE_EXPR;
}

ostream& if_expr::put( ostream& os) const
{
  BEGIN_EXPR (if_expr);
  cond_expr_h->put(os);
  PUT_SUB ("THEN", then_expr_h);
  PUT_SUB ("ELSE", else_expr_h);
  CLOSE_EXPR;
}

ostream& fo_expr::put( ostream& os) const
{
  store::Item_t qname = func->get_fname ();
  os << INDENT << qname->getStringValue() << "/" << size () << expr_addr (this) << " [\n";
  
  for (vector<rchandle<expr> >::const_iterator it = begin();
       it != end(); ++it)
  {
    rchandle<expr> e_h = *it;
    e_h->put(os);
  }
  CLOSE_EXPR;
}

ostream& ft_contains_expr::put( ostream& os) const
{
  BEGIN_EXPR (ft_contains_expr);
  range_h->put(os) << endl;
  os << "ft_contains\n";
  ft_select_h->put(os) << endl;
  if (ft_ignore_h!=NULL) ft_ignore_h->put(os);
  CLOSE_EXPR;
}

ostream& instanceof_expr::put( ostream& os) const
{
  os << INDENT << "instanceof_expr " << target_type->toString () << expr_addr (this) << " [\n";
  input_expr_h->put(os);
  CLOSE_EXPR;
}

ostream& treat_expr::put( ostream& os) const
{
  os << INDENT << "treat_expr " << target_type->toString () << expr_addr (this) << " [\n";
  input_expr_h->put(os);
  CLOSE_EXPR;
}

ostream& castable_expr::put( ostream& os) const
{
  os << INDENT << "castable_expr " << target_type->toString () << expr_addr (this) << " [\n";
  input_expr_h->put(os);
  CLOSE_EXPR;
}

ostream& cast_expr::put( ostream& os) const
{
  os << INDENT << "cast_expr " << target_type->toString () << expr_addr (this) << " [\n";
  input_expr_h->put(os);
  CLOSE_EXPR;
}

ostream& name_cast_expr::put( ostream& os) const
{
  BEGIN_EXPR (name_cast_expr);
  input_expr_h->put(os);
  CLOSE_EXPR;
}

ostream& validate_expr::put( ostream& os) const
{
  BEGIN_EXPR (validate_expr);

  switch (valmode) {
  case ParseConstants::val_strict: os << "strict\n"; break;
  case ParseConstants::val_lax: os << "lax\n"; break;
  default: os << "??\n";
  }
  expr_h->put(os) << endl;
  CLOSE_EXPR;
}

ostream& extension_expr::put( ostream& os) const
{
  BEGIN_EXPR (extension_expr);

  os << INDENT;
  os << "?"; put_qname (pragma_h->name_h, os);
  os << " " << pragma_h->content << endl;
  UNDENT;

  expr_h->put(os) << endl;
  CLOSE_EXPR;
}

ostream& relpath_expr::put( ostream& os) const
{
  BEGIN_EXPR (relpath_expr);
  
  for (std::vector<expr_t>::const_iterator it = begin(); it != end(); ++it)
  {
    expr_t expr = *it;
    if (it == begin ())
      expr->put (os);
    else
      PUT_SUB ("REL STEP", expr);
  }
  CLOSE_EXPR;
}

ostream& axis_step_expr::put(ostream& os) const
{
  BEGIN_EXPR (axis_step_expr);

  os << INDENT;
  switch (theAxis)
  {
  case axis_kind_self:                os << "self::"; break;
  case axis_kind_child:               os << "child::"; break;
  case axis_kind_parent:              os << "parent::"; break;
  case axis_kind_descendant:          os << "descendant::"; break;
  case axis_kind_descendant_or_self:  os << "descendant-or-self::"; break;
  case axis_kind_ancestor:            os << "ancestor::"; break;
  case axis_kind_ancestor_or_self:    os << "ancestor-or-self::"; break;
  case axis_kind_following_sibling:   os << "following-sibling::"; break;
  case axis_kind_following:           os << "following::"; break;
  case axis_kind_preceding_sibling:   os << "preceding-sibling::"; break;
  case axis_kind_preceding:           os << "preceding::"; break;
  case axis_kind_attribute:           os << "attribute::"; break;
  default: os << "??";
  }
  UNDENT;

  if (theNodeTest != NULL) {
    int saveIndent = printdepth0;
    printdepth0 = -2;
    theNodeTest->put(os);
    printdepth0 = saveIndent;
  }
  
  CLOSE_EXPR;
}

ostream& match_expr::put(ostream& os) const
{
  os << INDENT << "match_expr [";
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

  os << ")" << "]\n"; UNDENT;
  return os;
}

ostream& const_expr::put( ostream& os) const
{
  os << INDENT << "const_expr" << expr_addr (this) << " " << GENV_TYPESYSTEM.create_value_type (get_val ())->toString () << " [ ";
  os << val->getStringValue();
  os << " ]\n"; UNDENT;
  return os;
}

ostream& order_expr::put( ostream& os) const
{
  os << INDENT << "order_expr" << expr_addr (this) << "\n";
  os << DENT << "[ ";

  switch (type) 
  {
  case ordered: os << "ordered\n"; break;
  case unordered: os << "unordered\n"; break;
  default: os << "??\n";
  }
  expr_h->put(os) << endl;
  CLOSE_EXPR;
}

ostream& elem_expr::put(ostream& os) const
{
  BEGIN_EXPR (elem_expr);

  if (theQNameExpr != NULL)
    theQNameExpr->put(os);
  if (theAttrs != NULL)
    theAttrs->put(os);
  if (theContent != NULL)
    theContent->put(os);
  CLOSE_EXPR;
}

ostream& doc_expr::put( ostream& os) const
{
  BEGIN_EXPR (doc_expr);

  theContent->put(os);
  CLOSE_EXPR;
}

ostream& attr_expr::put( ostream& os) const
{
  BEGIN_EXPR (attr_expr);

  theQNameExpr->put (os);
  PUT_SUB ("=", theValueExpr);
  CLOSE_EXPR;
}

ostream& text_expr::put(ostream& os) const
{
  BEGIN_EXPR (text_expr);

  text->put(os);

  CLOSE_EXPR;
}

ostream& pi_expr::put( ostream& os) const
{
  BEGIN_EXPR (pi_expr);

  PUT_SUB ("TARGET", target_expr_h);

  PUT_SUB ("CONTENT", get_text ());

  CLOSE_EXPR;
}

ostream& function_def_expr::put (ostream &os) const {
  BEGIN_EXPR (fn_def_expr);
  CLOSE_EXPR;
}

ostream& insert_expr::put( ostream& os) const
{
  BEGIN_EXPR (insert_expr);
  theSourceExpr->put(os);
  PUT_SUB (",", theTargetExpr);
  CLOSE_EXPR;
}

ostream& delete_expr::put( ostream& os) const
{
  BEGIN_EXPR (delete_expr);
  theTargetExpr->put(os);
  CLOSE_EXPR;
}

ostream& replace_expr::put( ostream& os) const
{
  BEGIN_EXPR (replace_expr);
  theTargetExpr->put(os);
  PUT_SUB (",", theReplaceExpr);
  CLOSE_EXPR;
}

ostream& rename_expr::put( ostream& os) const
{
  BEGIN_EXPR (rename_expr);
  theTargetExpr->put(os);
  PUT_SUB (",", theNameExpr);
  CLOSE_EXPR;
}

ostream& copy_clause::put( ostream& os) const
{
  BEGIN_EXPR (copy);
  theVar->put(os);
  theExpr->put(os);
  CLOSE_EXPR;
}

ostream& transform_expr::put( ostream& os) const
{
  BEGIN_EXPR (transform_expr);
  for (vector<rchandle<copy_clause> >::const_iterator it = theCopyClauses.begin();
       it != theCopyClauses.end(); ++it)
  {
    rchandle<copy_clause> e = *it;
    e->put(os);
  }
  theModifyExpr->put(os);
  PUT_SUB (",", theReturnExpr);
  CLOSE_EXPR;
}

ostream& exit_expr::put( ostream& os) const
{
  BEGIN_EXPR (exit_expr);
  val->put (os);
  CLOSE_EXPR;
}

ostream& flowctl_expr::put( ostream& os) const
{
  BEGIN_EXPR (flowctl_expr);
  CLOSE_EXPR;
}

ostream& while_expr::put( ostream& os) const
{
  BEGIN_EXPR (while_expr);
  body->put (os);
  CLOSE_EXPR;
}

}  // namespace zorba
