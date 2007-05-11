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

// Numeric functions
op_numeric_add  op_add(
	signature(
		new zorba_qname(XQUERY_FN_NS,XQUERY_PRE,"op_add"),
		xs_decimal,					// arg[1] type
		xs_decimal,					// arg[2] type
		xs_decimal					// return type
	)
);

op_numeric_subtract  op_subtract(
	signature(
		new zorba_qname(XQUERY_FN_NS,XQUERY_PRE,"op_subtract"),
		xs_decimal,					// arg[1] type
		xs_decimal,					// arg[2] type
		xs_decimal					// return type
	)
);


qnamekey_t library::op_add_key;
qnamekey_t library::op_subtract_key;


void library::init(
	value_factory* vf_p)
{
	if (!library::static_init) {
		// Numeric functions
		put(&op_add);
		put(&op_subtract);

		op_add_key = op_add.get_fname()->qnamekey();
		op_subtract_key = op_subtract.get_fname()->qnamekey();

	}
}


library::library(zorba* _zorp) : zorp(_zorp)
{
	init(&*zorp->get_value_factory());
}

library::~library()
{
}

void library::put(const function* funp)
{
	qnamekey_t fun_key = funp->get_fname()->qnamekey();
	funtab.put(fun_key, funp);
}

const function* library::get(qnamekey_t fun_key)
{
	const function* funp = NULL;
	uint64_t key = fun_key;
	funtab.get(key, funp);
	return funp;
}

} /* namespace xqp */

