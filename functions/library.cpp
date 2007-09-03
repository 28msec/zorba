/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: library.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan,Paul Pedersen
 */

#include "library.h"
#include "function.h"
#include "signature.h"

#include "Numerics.h"
#include "Sequences.h"
#include "Strings.h"
#include "Boolean.h"

#include "context/common.h"
#include "runtime/zorba.h"
#include "types/sequence_type.h"
#include "util/tracer.h"
// #include "zorba/zorba_qname.h"
#include "../store/api/item.h"
#include "../store/native/atomic_items.h"

#include <iostream>

using namespace std;
namespace xqp {


// TODO FIXME This library must be changed!! Somehow!!

// clear static initializer state
bool library::static_init = false;

// TODO adapt to new store

// Numerics
op_numeric_add  op_add(
	signature(
		new QNameItem(XQUERY_FN_NS,"op","add"),
		xs_decimal,					// arg[1] type
		xs_decimal,					// arg[2] type
		xs_decimal					// return type
	)
);

op_numeric_subtract  op_subtract(
	signature(
		new QNameItem(XQUERY_FN_NS,"op","subtract"),
		xs_decimal,					// arg[1] type
		xs_decimal,					// arg[2] type
		xs_decimal					// return type
	)
);

op_numeric_multiply op_multiply(
	signature(
		new QNameItem(XQUERY_FN_NS,"op","multiply"),
		xs_decimal,
		xs_decimal,
		xs_decimal
	)
);
 
op_numeric_divide op_divide(
	signature(
		new QNameItem(XQUERY_FN_NS,"op","divide"),
		xs_decimal,
		xs_decimal,
		xs_decimal
	)
);
 
// op_numeric_integer_divide
// 
op_numeric_mod op_mod(
	signature(
		new QNameItem(XQUERY_FN_NS,"op","mod"),
		xs_decimal,
		xs_decimal,
		xs_decimal
	)
);
 
// op_numeric_unary_plus
// 
// op_numeric_unary_minus

op_numeric_equal op_equal(
	signature(
		new QNameItem(XQUERY_FN_NS,"op","equal"),
		xs_decimal,
		xs_decimal,
		xs_boolean
	)
);


fn_abs fn_abs_sig(
	signature(
		new QNameItem(XQUERY_FN_NS, "fn", "abs"),
		xs_decimal,
		xs_decimal
	)
);

// Sequences
fn_doc_func fn_doc(
	signature(
		new QNameItem(XQUERY_FN_NS,"fn","doc"),
		xs_string,					// arg[1] type
		documentNode				// return type
	)
);


// Strings

fn_codepoints_to_string fn_codepoints_to_string_func(
	signature(
		new QNameItem(XQUERY_FN_NS,"fn","codepoints-to-string"),
		xs_integer,					// arg[0] type
		xs_string						// return type
	)
); 

fn_string_to_codepoints fn_string_to_codepoints_func(
	signature(
		new QNameItem(XQUERY_FN_NS,"fn","string-to-codepoints"),
		xs_string,					// arg[0] type
		xs_long							// return type
	)
);

fn_codepoint_equal fn_codepoint_equal_func(
	signature(
		new QNameItem(XQUERY_FN_NS,"fn","codepoint-equal"),
		xs_string,					// arg[0] type
		xs_string,					// arg[1] type
		xs_boolean					// return type
	)
);

fn_concat fn_concat_func(
	signature(
		new QNameItem(XQUERY_FN_NS,"fn","concat"),
		xs_anyType,					// args type
		xs_boolean					// return type
	)
);

fn_string_join fn_string_join_func(
	signature(
		new QNameItem(XQUERY_FN_NS,"fn","string-join"),
		xs_string,					// arg[0] type
		xs_string,					// arg[1] type
		xs_string						// return type
	)
);

fn_boolean fn_boolean_func(
	signature(
		new QNameItem(XQUERY_FN_NS,"fn","boolean"),
		xs_anyType,
		xs_boolean
	)
);

qnamekey_t library::op_add_key;
qnamekey_t library::op_subtract_key;
qnamekey_t library::op_mul_key;
qnamekey_t library::op_div_key;
qnamekey_t library::op_idiv_key;
qnamekey_t library::op_mod_key;

qnamekey_t library::fn_abs_key;


// Comparison operators
qnamekey_t library::op_eq_key;
qnamekey_t library::op_ne_key;
qnamekey_t library::op_lt_key;
qnamekey_t library::op_le_key;
qnamekey_t library::op_gt_key;
qnamekey_t library::op_ge_key;
qnamekey_t library::op_val_eq_key;
qnamekey_t library::op_val_ne_key;
qnamekey_t library::op_val_lt_key;
qnamekey_t library::op_val_le_key;
qnamekey_t library::op_val_gt_key;
qnamekey_t library::op_val_ge_key;
qnamekey_t library::op_is_key;
qnamekey_t library::op_precedes_key;
qnamekey_t library::op_follows_key;


// Sequences
qnamekey_t library::op_concatenate_key;
qnamekey_t library::op_union_key;
qnamekey_t library::op_intersect_key;
qnamekey_t library::op_except_key;
qnamekey_t library::fn_doc_key;

// Strings
qnamekey_t library::fn_codepoints_to_string_key;
qnamekey_t library::fn_string_to_codepoints_key;
qnamekey_t library::fn_codepoint_equal_key;
qnamekey_t library::fn_concat_key;
qnamekey_t library::fn_string_join_key;

qnamekey_t library::fn_boolean_key;

// initializer

void library::init(
	ItemFactory* vf_p)
{
	if (!library::static_init) {
  	
		// Numeric functions
		put(&op_add);
		put(&op_subtract);
		put(&op_multiply);
		put(&op_divide);
		put(&op_mod);
		put(&op_equal);
		put(&fn_abs_sig);

		op_add_key = op_add.get_fname()->getQNameKey();
		op_subtract_key = op_subtract.get_fname()->getQNameKey();
		op_mul_key = op_multiply.get_fname()->getQNameKey();
		op_div_key = op_divide.get_fname()->getQNameKey();
		op_mod_key = op_mod.get_fname()->getQNameKey();
		op_val_eq_key = op_equal.get_fname()->getQNameKey();

		fn_abs_key = fn_abs_sig.get_fname()->getQNameKey();

		
		// Sequences functions
		put(&fn_doc);

		
		fn_doc_key = fn_doc.get_fname()->getQNameKey();
		cout << TRACE << " : fn_doc_key = " << fn_doc_key << endl;
		

		// String functions
		put(&fn_codepoints_to_string_func);
		put(&fn_string_to_codepoints_func);
		put(&fn_codepoint_equal_func);
		put(&fn_concat_func);
		put(&fn_string_join_func);
		
		fn_codepoints_to_string_key = fn_codepoints_to_string_func.get_fname()->getQNameKey();
		fn_string_to_codepoints_key = fn_string_to_codepoints_func.get_fname()->getQNameKey();
		fn_codepoint_equal_key = fn_codepoint_equal_func.get_fname()->getQNameKey();
		fn_concat_key = fn_concat_func.get_fname()->getQNameKey();
		fn_string_join_key = fn_string_join_func.get_fname()->getQNameKey();

		// Boolean functions
		put(&fn_boolean_func);
		fn_boolean_key = fn_boolean_func.get_fname()->getQNameKey();

		library::static_init = true;///don't initialize again
	}
}


// ctor, dtor

library::library()
:
	funtab((float)0.6, 1024)
{
	init(&*zorba::getZorbaForCurrentThread()->getItemFactory());
}

library::~library()
{
}


// map interface

void library::put(const function* funp)
{
	qnamekey_t fun_key = funp->get_fname()->getQNameKey();
	funtab.put(fun_key, funp);
}

const function* library::get(qnamekey_t fun_key)
{
//#ifdef DEBUG
//	cout << TRACE << " : fun_key = " << fun_key->qnamekey() << endl;
//#endif

	const function* fun_p = NULL;
	uint64_t key = fun_key;
	if (!funtab.get(key, fun_p)) {
		cout << TRACE << "function not found!\n";
		return NULL;
	}
	return fun_p;
}

} /* namespace xqp */

