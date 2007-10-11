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
// 	Iterator_t operator() {
// 		
// 	}
// };

class library : public rcobject
{
protected:
	fxhash64map<const function*> funtab;

public:
	// Accessor functions
	static qnamekey_t fn_data_key;
  static qnamekey_t fn_root_key;

	// Numeric functions
	//daniel: these serve as constant global keys
	static qnamekey_t op_add_key;
	static qnamekey_t op_subtract_key;
  static qnamekey_t op_mul_key;
  static qnamekey_t op_div_key;
  static qnamekey_t op_idiv_key;
  static qnamekey_t op_mod_key;
  static qnamekey_t op_unary_minus_key;
  static qnamekey_t op_unary_plus_key;

	static qnamekey_t fn_abs_key;

	// comparison operators
	static qnamekey_t op_eq_key;
	static qnamekey_t op_ne_key;
	static qnamekey_t op_lt_key;
	static qnamekey_t op_le_key;
	static qnamekey_t op_gt_key;
	static qnamekey_t op_ge_key;
	static qnamekey_t op_val_eq_key;
	static qnamekey_t op_val_ne_key;
	static qnamekey_t op_val_lt_key;
	static qnamekey_t op_val_le_key;
	static qnamekey_t op_val_gt_key;
	static qnamekey_t op_val_ge_key;
	static qnamekey_t op_is_key;
	static qnamekey_t op_precedes_key;
	static qnamekey_t op_follows_key;

	// Sequence functions
	static qnamekey_t op_concatenate_key;
	static qnamekey_t op_union_key;
	static qnamekey_t op_intersect_key;
	static qnamekey_t op_except_key;
	static qnamekey_t fn_doc_key;

	// String functions
	static qnamekey_t fn_codepoints_to_string_key;
	static qnamekey_t fn_string_to_codepoints_key;
	static qnamekey_t fn_codepoint_equal_key;
	static qnamekey_t fn_concat_key;
	static qnamekey_t fn_string_join_key;
	static qnamekey_t fn_string_compare_key;

	// Boolean functions
	static qnamekey_t fn_true_key;
	static qnamekey_t fn_false_key;
	static qnamekey_t fn_boolean_key;
	static qnamekey_t fn_not_key;
	
	// Logic operators
	static qnamekey_t op_and_key;
	static qnamekey_t op_or_key;
	
	// Zorba Function
	static qnamekey_t zor_numgen_key;
	
public:
	library( );
	~library();
	static bool static_init;
	void init(ItemFactory*);

public:
	void put(const function*);
	const function* get(qnamekey_t);

};

} /* namespace xqp */
#endif /* XQP_LIBRARY_H */

