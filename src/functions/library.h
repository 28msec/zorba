/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
*
 *  $Id: function_library.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Authors: John Cowan,Paul Pedersen
 *
 */

#ifndef XQP_LIBRARY_H
#define XQP_LIBRARY_H

#include <string>

#include "context/common.h"
#include "store/api/item_factory.h"
#include "util/fx/fxhashmap.h"

namespace xqp {

class function;
class zorba;

// template<typename FuncIter>
// class LibraryFunction {
// 	PlanIter_t operator() {
// 		
// 	}
// };

class library : public rcobject
{
protected:
	fxhash64map<const function*> funtab;

public:
	// Accessor functions
	static std::string fn_data_key;
  static std::string fn_root_key;

	// Numeric functions
	//daniel: these serve as constant global keys
	static std::string op_add_key;
	static std::string op_subtract_key;
  static std::string op_mul_key;
  static std::string op_div_key;
  static std::string op_idiv_key;
  static std::string op_mod_key;
  static std::string op_unary_minus_key;
  static std::string op_unary_plus_key;

	static std::string fn_abs_key;

	// comparison operators
	static std::string op_eq_key;
	static std::string op_ne_key;
	static std::string op_lt_key;
	static std::string op_le_key;
	static std::string op_gt_key;
	static std::string op_ge_key;
	static std::string op_val_eq_key;
	static std::string op_val_ne_key;
	static std::string op_val_lt_key;
	static std::string op_val_le_key;
	static std::string op_val_gt_key;
	static std::string op_val_ge_key;
	static std::string op_is_key;
	static std::string op_precedes_key;
	static std::string op_follows_key;

	// Sequence functions
	static std::string op_concatenate_key;
	static std::string op_union_key;
	static std::string op_intersect_key;
	static std::string op_except_key;
	static std::string fn_doc_key;

	// String functions
	static std::string fn_codepoints_to_string_key;
	static std::string fn_string_to_codepoints_key;
	static std::string fn_codepoint_equal_key;
	static std::string fn_concat_key;
	static std::string fn_string_join_key;
	static std::string fn_string_compare_key;
	static std::string fn_substring_key;
	static std::string fn_normalize_space_key;
	static std::string fn_normalize_unicode_key;
	static std::string fn_upper_case_key;
	static std::string fn_lower_case_key;
	static std::string fn_translate_key;
	static std::string fn_string_length_key;
	static std::string fn_contains_key;
	static std::string fn_starts_with_key;
	static std::string fn_ends_with_key;
	static std::string fn_substring_before_key;
	static std::string fn_substring_after_key;

	// Boolean functions
	static std::string fn_true_key;
	static std::string fn_false_key;
	static std::string fn_boolean_key;
	static std::string fn_not_key;
	
	// Logic operators
	static std::string op_and_key;
	static std::string op_or_key;
	
	// Zorba Function
	static std::string zor_numgen_key;
	
public:
	library( );
	~library();
	static bool static_init;
	void init(ItemFactory*);
};

} /* namespace xqp */
#endif /* XQP_LIBRARY_H */

