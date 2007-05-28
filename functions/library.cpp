/* -*- mode: c++; indent-tabs-mode: nil -*-
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

#include "context/common.h"
#include "runtime/zorba.h"
#include "types/sequence_type.h"
#include "util/tracer.h"
#include "zorba/zorba_qname.h"

#include <iostream>

using namespace std;
namespace xqp {

// clear static initializer state
bool library::static_init = false;

// Numerics
op_numeric_add  op_add(
	signature(
		new zorba_qname(XQUERY_FN_NS,"op","op_add"),
		xs_decimal,					// arg[1] type
		xs_decimal,					// arg[2] type
		xs_decimal					// return type
	)
);

op_numeric_subtract  op_subtract(
	signature(
		new zorba_qname(XQUERY_FN_NS,"op","op_subtract"),
		xs_decimal,					// arg[1] type
		xs_decimal,					// arg[2] type
		xs_decimal					// return type
	)
);


// Sequences
fn_doc_func fn_doc(
	signature(
		new zorba_qname(XQUERY_FN_NS,"fn","fn_doc"),
		xs_string,					// arg[1] type
		documentNode				// return type
	)
);


qnamekey_t library::op_add_key;
qnamekey_t library::op_subtract_key;
qnamekey_t library::op_mul_key;
qnamekey_t library::op_div_key;
qnamekey_t library::op_idiv_key;
qnamekey_t library::op_mod_key;



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



// static initializer

void library::init(
	value_factory* vf_p)
{
	if (!library::static_init) {
  	
		// Numeric functions
		put(&op_add);
		put(&op_subtract);

		op_add_key = op_add.get_fname()->qnamekey();
		op_subtract_key = op_subtract.get_fname()->qnamekey();
		
		// Sequences functions
		put(&fn_doc);
		
		fn_doc_key = fn_doc.get_fname()->qnamekey();
cout << TRACE << " : fn_doc_key = " << fn_doc_key << endl;

	}
}


// ctor, dtor

library::library(
	zorba* _zorp)
:
	zorp(_zorp),
	funtab(0.6, 1024)
{
	init(&*zorp->get_value_factory());
}

library::~library()
{
}


// map interface

void library::put(const function* funp)
{
	qnamekey_t fun_key = funp->get_fname()->qnamekey();
	funtab.put(fun_key, funp);
}

const function* library::get(qnamekey_t fun_key)
{
#ifdef DEBUG
cout << TRACE << " : fun_key = " << fun_key << endl;
#endif

	const function* fun_p = NULL;
	uint64_t key = fun_key;
	if (!funtab.get(key, fun_p)) {
		cout << TRACE << "function not found!\n";
		return NULL;
	}
	return fun_p;
}

} /* namespace xqp */

