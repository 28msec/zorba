/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: parse_constants.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#ifndef XQP_PARSE_CONSTANTS_H
#define XQP_PARSE_CONSTANTS_H

namespace xqp {

enum default_namespace_mode_t {
	ns_element_default,
	ns_function_default
};

enum function_type_t {
	fn_extern,
	fn_read,
	fn_update,
	fn_extern_update,
};

enum dir_spec_t {
	dir_ascending,
	dir_descending
};

enum quantification_mode_t {
	quant_some,
	quant_every
};

enum add_op_t {
	op_plus,
	op_minus
};

enum mult_op_t {
	op_mul,
	op_div,
	op_idiv,
	op_mod
};

enum intex_op_t {
	op_intersect,
	op_except	
};

enum gencomp_t {
	op_eq,
	op_ne,
	op_lt,
	op_le,
	op_gt,
	op_ge
};

enum valcomp_t {
	op_val_eq,
	op_val_ne,
	op_val_lt,
	op_val_le,
	op_val_gt,
	op_val_ge
};

enum nodecomp_t {
	op_is,
	op_precedes,
	op_follows	
};

enum validation_mode_t {
	val_strict,
	val_lax
};

enum pathtype_t {
	path_leading_lone_slash,
	path_leading_slash,
	path_leading_slashslash,
	path_relative
};

enum steptype_t {
	st_step,
	st_slash,
	st_slashslash	
};

enum forward_axis_t {
	axis_child,
	axis_descendant,
	axis_attribute,
	axis_self,
	axis_descendant_or_self,
	axis_following_sibling,
	axis_following
};

enum reverse_axis_t {
	axis_parent,
	axis_ancestor,
	axis_preceding_sibling,
	axis_preceding,
	axis_ancestor_or_self
};

enum wildcard_t {
	wild_all,
	wild_elem,
	wild_prefix
};

enum numeric_type_t {
	num_integer,
	num_decimal,
	num_double
};

enum common_content_t {
	cont_entity,
	cont_charref,
	cont_escape_lbrace,
	cont_escape_rbrace,
	cont_expr
};

enum occurrence_t {
	occurs_never,
	occurs_exactly_one,
	occurs_optionally,
	occurs_zero_or_more,
	occurs_one_or_more
};

enum ft_case_mode_t {
	ft_case_lower,
	ft_case_upper,
	ft_case_sensitive,
	ft_case_insensitive
};

enum ft_diacritics_mode_t {
	ft_diacritics_with,
	ft_diacritics_without,
	ft_diacritics_senstive,
	ft_diacritics_insensitive
};

enum ft_stem_mode_t {
	ft_stemmode_with,
	ft_stemmode_without
};

enum stop_words_mode_t {
	ft_stopmode_with,
	ft_stopmode_with_default,
	ft_stopmode_without
};

enum ft_content_mode_t {
	ft_contentmode_at_start,
	ft_contentmode_at_end,
	ft_contentmode_entire
};

enum ft_anyall_option_t {
	ft_opt_any,
	ft_opt_any_word,
	ft_opt_all,
	ft_opt_all_words,
	ft_opt_phrase
};

enum ft_range_mode_t {
	ft_range_exactly,
	ft_range_at_least,
	ft_range_at_most,
	ft_range_from_to
};

enum ft_scope_t {
	ft_scope_same,
	ft_scope_different
};

enum ft_unit_t {
	ft_unit_word,
	ft_unit_sentence,
	ft_unit_paragraph
};

enum ft_big_unit_t {
	ft_bigunit_sentence,
	ft_bigunit_paragraph
};

  inline const char *decode_numeric_type (enum numeric_type_t t) {
    switch (t) {
    case num_integer: return "integer";
    case num_decimal: return "decimal";
    case num_double:  return "double";
    default: assert (false); return "?";
    }
  }


} /* namespace xqp */
#endif /* XQP_PARSE_CONSTANTS_H */

