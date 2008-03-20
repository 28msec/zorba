#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "context/static_context_consts.h"

#include "compiler/expression/expr.h"
#include "system/globalenv.h"
#include "functions/function.h"
#include "compiler/parser/parse_constants.h"
#include "compiler/parsetree/parsenodes.h"
#include "util/Assert.h"
#include "util/tracer.h"
//#include "system/zorba.h"


using namespace std;
namespace zorba {
  
  static inline ostream &put_qname (store::Item_t qname, ostream &os) {
    xqp_string pfx = qname->getPrefix ();
    if (! pfx.empty ())
      os << pfx << "[=" << qname->getNamespace () << "]:";
    os << qname->getLocalName ();
    return os;
  }

int printdepth0 = -2;

#define DENT      string(printdepth0, ' ')
#define INDENT    (printdepth0 += 2, string(printdepth0, ' '))
#define OUTDENT   (printdepth0 -= 2, string(printdepth0, ' '))
#define UNDENT    printdepth0 -= 2;

ostream& expr::put( ostream& os) const
{
  return os;
}

ostream& var_expr::put(ostream& os) const
{
  os << INDENT << "var_expr " << decode_var_kind(get_kind()) << " (" << this << ") [\n";
  if (varname_h != NULL)
  {
    os << DENT << " name=";
    put_qname (get_varname(), os);
  }
  os << endl;
  if (type != NULL) {
    os << DENT << " type=";
    GENV_TYPESYSTEM.serialize (os, *type);
    os << endl;
  }
  os << DENT << "]\n";
  UNDENT;
  return os;
}

ostream & forlet_clause::put( ostream& os) const
{
  os << INDENT << "forlet (" << this << ") [\n";

  ZORBA_ASSERT(var_h != NULL);
  var_h->put(os);
  if (pos_var_h!=NULL) 
  {
    os << DENT << "AT \n";
    pos_var_h->put(os);
  }
  if (score_var_h!=NULL) 
  {
    os << DENT << "SCORE \n";
    score_var_h->put(os);
  }

  ZORBA_ASSERT(expr_h != NULL);
  os << DENT << (var_h->get_kind() == var_expr::for_var ? "IN" : ":=") << " \n";
  expr_h->put(os);

  os << DENT << "]\n"; UNDENT;
  return os;
}

ostream& flwor_expr::put( ostream& os) const
{
  os << INDENT << "flwor_expr (" << this << ") [\n";

  vector<forletref_t>::const_iterator it = clause_begin();
  for (; it!=clause_end(); ++it)
  {
    forletref_t fl_h = *it;
    ZORBA_ASSERT(fl_h != NULL);
    fl_h->put(os);
  }

  if (where_h!=NULL) {
    os << DENT << "WHERE\n";
    where_h->put(os);
  }

  
  for (vector<orderspec_t>::const_iterator ord_it = orderspec_begin();
       ord_it!=orderspec_end(); ++ord_it) 
  {
    orderspec_t spec = *ord_it;
    expr_t e_h = spec.first;
    ZORBA_ASSERT(e_h != NULL);
    orderref_t ord_h = spec.second;
    ZORBA_ASSERT(ord_h != NULL);

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

  os << DENT << "]\n"; UNDENT;
  return os;
}

ostream& promote_expr::put(ostream& os) const
{
  os << INDENT << "promote_expr (" << this << ") [\n";
  os << DENT; GENV_TYPESYSTEM.serialize(os, *target_type); os << "\n";
  ZORBA_ASSERT(input_expr_h!=NULL);
  input_expr_h->put(os);
  os << DENT << "]\n"; UNDENT;
  return os;
}

ostream& trycatch_expr::put( ostream& os) const
{
  os << INDENT << "trycatch_expr (" << this << ") [\n";

  //d Assert<null_pointer>(switch_expr_h!=NULL);
  ZORBA_ASSERT(try_expr_h!=NULL);
  try_expr_h->put(os);

  for (vector<clauseref_t>::const_iterator it = catch_clause_hv.begin();
       it!=catch_clause_hv.end(); ++it)
  {
    clauseref_t cc_h = *it;
    os << INDENT << "catch: ";
    if (cc_h->var_h!=NULL) cc_h->var_h->put(os);
        os << " return ";
    //d Assert<null_pointer>(cc_h->case_expr_h!=NULL);
    ZORBA_ASSERT(cc_h->catch_expr_h!=NULL);
    cc_h->catch_expr_h->put(os) << endl;
    UNDENT;
  }
  os << DENT << "]\n"; UNDENT;
  return os;
}

ostream& typeswitch_expr::put( ostream& os) const
{
  os << INDENT << "typeswitch_expr (" << this << ") [\n";

  //d Assert<null_pointer>(switch_expr_h!=NULL);
  ZORBA_ASSERT(switch_expr_h!=NULL);
  switch_expr_h->put(os);

  for (vector<clauseref_t>::const_iterator it = case_clause_hv.begin();
       it!=case_clause_hv.end(); ++it)
  {
    clauseref_t cc_h = *it;
    os << INDENT << "case: ";
    if (cc_h->var_h!=NULL) cc_h->var_h->put(os) << " as ";
    // TODO(VRB) os << sequence_type::describe(cc_h->type);
        os << " return ";
    //d Assert<null_pointer>(cc_h->case_expr_h!=NULL);
    ZORBA_ASSERT(cc_h->case_expr_h!=NULL);
    cc_h->case_expr_h->put(os) << endl;
    UNDENT;
  }
  os << DENT << "]\n"; UNDENT;
  return os;
}

ostream& if_expr::put( ostream& os) const
{
  os << INDENT << "if_expr (" << this << ") [\n";
  ZORBA_ASSERT(cond_expr_h!=NULL);
  cond_expr_h->put(os);
  ZORBA_ASSERT(then_expr_h!=NULL);
  os << DENT << "THEN\n";
  then_expr_h->put(os);
  ZORBA_ASSERT(else_expr_h!=NULL);
  os << DENT << "ELSE\n";
  else_expr_h->put(os);
  os << DENT << "]\n"; UNDENT;
  return os;
}

ostream& fo_expr::put( ostream& os) const
{
  store::Item_t qname = func->get_fname ();
  os << INDENT << qname->getStringValue() << "/" << size () << " (" << this << ") [\n";
  
  for (vector<rchandle<expr> >::const_iterator it = begin();
       it != end(); ++it)
  {
    rchandle<expr> e_h = *it;
    ZORBA_ASSERT(e_h!=NULL);
    e_h->put(os);
  }
  os << DENT << "]\n"; UNDENT;
  return os;
}

ostream& ft_contains_expr::put( ostream& os) const
{
  os << INDENT << "ft_contains_expr (" << this << ") [\n";
  //d Assert<null_pointer>(range_h!=NULL);
  ZORBA_ASSERT(range_h!=NULL);
  range_h->put(os) << endl;
  //d Assert<null_pointer>(ft_select_h!=NULL);
  ZORBA_ASSERT(ft_select_h!=NULL);
  os << "ft_contains\n";
  ft_select_h->put(os) << endl;
  if (ft_ignore_h!=NULL) ft_ignore_h->put(os);
  os << DENT << "]\n"; UNDENT;
  return os;
}

ostream& instanceof_expr::put( ostream& os) const
{
  os << INDENT << "instanceof_expr "; GENV_TYPESYSTEM.serialize (os, *type);
  os << " (" << this << ") [\n";
  ZORBA_ASSERT(expr_h!=NULL);
  expr_h->put(os);
  os << DENT << "]\n"; UNDENT;
  return os;
}

ostream& treat_expr::put( ostream& os) const
{
  os << INDENT << "treat_expr "; GENV_TYPESYSTEM.serialize (os, *target_type);
  os << " (" << this << ") [\n";
  ZORBA_ASSERT(input_expr_h!=NULL);
  input_expr_h->put(os);
  os << DENT << "]\n"; UNDENT;
  return os;
}

ostream& castable_expr::put( ostream& os) const
{
  os << INDENT << "castable_expr ";
  GENV_TYPESYSTEM.serialize (os, *type);
  os << " (" << this << ") [\n";
  ZORBA_ASSERT(expr_h!=NULL);
  expr_h->put(os);
  os << DENT << "]\n"; UNDENT;
  return os;
}

ostream& cast_expr::put( ostream& os) const
{
  os << INDENT << "cast_expr ";
  GENV_TYPESYSTEM.serialize (os, *target_type);
  os << " (" << this << ") [\n";
  ZORBA_ASSERT(input_expr_h!=NULL);
  input_expr_h->put(os);
  os << DENT << "]\n"; UNDENT;
  return os;
}

ostream& validate_expr::put( ostream& os) const
{
  os << INDENT << "validate_expr (" << this << ") [\n";

  switch (valmode) {
  case ParseConstants::val_strict: os << "strict\n"; break;
  case ParseConstants::val_lax: os << "lax\n"; break;
  default: os << "??\n";
  }
  //d Assert<null_pointer>(expr_h!=NULL);
  ZORBA_ASSERT(expr_h!=NULL);
  expr_h->put(os) << endl;
  os << DENT << "]\n"; UNDENT;
  return os;
}

ostream& extension_expr::put( ostream& os) const
{
  os << INDENT << "extension_expr (" << this << ") [\n";

  /*
  vector<rchandle<pragma> >::const_iterator it = begin();
  for (; it!=end(); ++it) {
    os << INDENT;
    rchandle<pragma> p_h = *it;
    ZORBA_ASSERT<null_pointer>(p_h!=NULL);
    ZORBA_ASSERT<null_pointer>(p_h->name_h!=NULL);
    os << "?"; p_h->name_h->put(zorp,os);
    os << " " << p_h->content << endl;
    UNDENT;
  }
  */

  os << INDENT;
  //d Assert<null_pointer>(pragma_h!=NULL);
  ZORBA_ASSERT(pragma_h!=NULL);
  //d Assert<null_pointer>(pragma_h->name_h!=NULL);
  ZORBA_ASSERT(pragma_h->name_h!=NULL);
  os << "?"; put_qname (pragma_h->name_h, os);
  os << " " << pragma_h->content << endl;
  UNDENT;

  //d Assert<null_pointer>(expr_h!=NULL);
  ZORBA_ASSERT(expr_h!=NULL);
  expr_h->put(os) << endl;
  os << DENT << "]\n"; UNDENT;
  return os;
}

ostream& relpath_expr::put( ostream& os) const
{
  os << INDENT << "relpath_expr (" << this << ") [\n";

  for (std::vector<expr_t>::const_iterator it = begin(); it != end(); ++it)
  {
    expr_t expr = *it;
    ZORBA_ASSERT(expr != NULL);
    if (it != begin ())
      os << DENT << "REL STEP\n";
    expr->put(os);
  }
  os << DENT << "]\n"; UNDENT;
  return os;
}

ostream& axis_step_expr::put(ostream& os) const
{
  os << INDENT << "axis_step_expr (" << this << ") [\n";

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

  int saveIndent = printdepth0;
  printdepth0 = 0;

  if (theNodeTest != NULL)
    theNodeTest->put(os);

  printdepth0 = saveIndent;
  
  for (vector<rchandle<expr> >::const_iterator it = thePreds.begin();
       it != thePreds.end(); ++it)
  {
    rchandle<expr> e = *it;
    //d Assert<null_pointer>(e_h!=NULL);
    ZORBA_ASSERT(e != NULL);
    e->put(os);
  }

  os << DENT << "]\n"; UNDENT;
  return os;
}

ostream& match_expr::put(ostream& os) const
{
  os << INDENT << "match_expr[";
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

  os << ")";
  return os << "]\n";
}

ostream& const_expr::put( ostream& os) const
{
  os << INDENT << "const_expr (" << this << ")[ ";
  //os << val->getStringValue();
  os << " ]\n"; UNDENT;
  return os;
}

ostream& order_expr::put( ostream& os) const
{
  os << INDENT << "order_expr (" << this << ")\n";
  os << DENT << "[ ";

  switch (type) 
  {
  case ordered: os << "ordered\n"; break;
  case unordered: os << "unordered\n"; break;
  default: os << "??\n";
  }
  //d Assert<null_pointer>(expr_h!=NULL);
  ZORBA_ASSERT(expr_h!=NULL);
  expr_h->put(os) << endl;
  os << DENT << "]\n"; UNDENT;
  return os;
}

ostream& elem_expr::put(ostream& os) const
{
  os << INDENT << "elem_expr (" << this << ") [\n";

  if (theQNameExpr != NULL)
    theQNameExpr->put(os);
  if (theAttrs != NULL)
    theAttrs->put(os);
  if (theContent != NULL)
    theContent->put(os);
  os << DENT << "]\n"; UNDENT;
  return os;
}

ostream& doc_expr::put( ostream& os) const
{
  os << INDENT << "doc_expr (" << this << ") [\n";

  ZORBA_ASSERT(theContent != NULL);
  theContent->put(os);
  os << DENT << "]\n"; UNDENT;
  return os;
}

ostream& attr_expr::put( ostream& os) const
{
  os << INDENT << "attr_expr (" << this << ") [\n";

  theQNameExpr->put (os);
  
  if (theValueExpr != NULL)
  {
    os << "=";
    theValueExpr->put(os);
  }
  os << DENT << "]\n"; UNDENT;
  return os;
}

ostream& text_expr::put(ostream& os) const
{
  os << INDENT << "text_expr (" << this << ") [\n";

  text->put(os);

  os << DENT << "]\n"; UNDENT;
  return os;
}

ostream& pi_expr::put( ostream& os) const
{
  os << INDENT << "pi_expr (" << this << ") [\n";

  os << DENT << "TARGET\n";
  ZORBA_ASSERT(target_expr_h != NULL);
  target_expr_h->put(os);

  os << DENT << "CONTENT\n";
  ZORBA_ASSERT(get_text () != NULL);
  get_text ()->put(os);

  os << DENT << "]\n"; UNDENT;
  return os;
}

  ostream& function_def_expr::put (ostream &os) const {
    os << INDENT << "fn_def_expr (" << this << ") [\n";
    os << DENT << "]\n"; UNDENT;
    return os;
  }

ostream& insert_expr::put( ostream& os) const
{
  os << INDENT << "insert_expr (" << this << ") [\n";
  ZORBA_ASSERT(theSourceExpr!=NULL);
  theSourceExpr->put(os);
  os << DENT << ",\n";
  ZORBA_ASSERT(theTargetExpr!=NULL);
  theTargetExpr->put(os);
  os << DENT << "]\n"; UNDENT;
  return os;
}

ostream& delete_expr::put( ostream& os) const
{
  os << INDENT << "delete_expr (" << this << ") [\n";
  ZORBA_ASSERT(theTargetExpr!=NULL);
  theTargetExpr->put(os);
  os << DENT << "]\n"; UNDENT;
  return os;
}

ostream& replace_expr::put( ostream& os) const
{
  os << INDENT << "replace_expr (" << this << ") [\n";
  ZORBA_ASSERT(theTargetExpr!=NULL);
  theTargetExpr->put(os);
  os << DENT << ",\n";
  ZORBA_ASSERT(theReplaceExpr!=NULL);
  theReplaceExpr->put(os);
  os << DENT << "]\n"; UNDENT;
  return os;
}

ostream& rename_expr::put( ostream& os) const
{
  os << INDENT << "rename_expr (" << this << ") [\n";
  ZORBA_ASSERT(theTargetExpr!=NULL);
  theTargetExpr->put(os);
  os << DENT << ",\n";
  ZORBA_ASSERT(theNameExpr!=NULL);
  theNameExpr->put(os);
  os << DENT << "]\n"; UNDENT;
  return os;
}

ostream& transform_expr::put( ostream& os) const
{
  os << INDENT << "transform_expr (" << this << ") [\n";
  for (vector<rchandle<var_expr> >::const_iterator it = theAssigns.begin();
       it != theAssigns.end(); ++it)
  {
    rchandle<expr> e = *it;
    ZORBA_ASSERT(e != NULL);
    e->put(os);
  }
  ZORBA_ASSERT(theModifyExpr!=NULL);
  theModifyExpr->put(os);
  os << DENT << ",\n";
  ZORBA_ASSERT(theReturnExpr!=NULL);
  theReturnExpr->put(os);
  os << DENT << "]\n"; UNDENT;
  return os;
}

}
