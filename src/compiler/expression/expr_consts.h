#ifndef ZORBA_EXPR_CONSTS_H
#define ZORBA_EXPR_CONSTS_H

namespace zorba {


enum axis_kind_t
{
  axis_kind_self,
  axis_kind_child,
  axis_kind_parent,
  axis_kind_descendant,
  axis_kind_descendant_or_self,
  axis_kind_ancestor,
  axis_kind_ancestor_or_self,
  axis_kind_following_sibling,
  axis_kind_following,
  axis_kind_preceding_sibling,
  axis_kind_preceding,
  axis_kind_attribute
};


enum match_test_t
{
  match_no_test,
  match_name_test,
  match_doc_test,
  match_elem_test,
  match_attr_test,
  match_xs_elem_test,
  match_xs_attr_test,
  match_pi_test,
  match_comment_test,
  match_text_test,
  match_anykind_test
};

std::string toString(match_test_t a);

enum match_wild_t
{
  match_no_wild,
  match_all_wild,
  match_prefix_wild,
  match_name_wild
};

enum expr_update_t
{
  UPDATE_EXPR,
  VACUOUS_EXPR,
  SIMPLE_EXPR
};


}; // namespace zorba


#endif /* ZORBA_EXPR_CONSTS_H */
