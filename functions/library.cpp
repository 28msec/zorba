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
#include "util/list.h"
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

  class initializer;
  static list<const initializer *> initializers;

  class initializer {
    const function &f;
    qnamekey_t &k;

  public:
    initializer (const function &f_, qnamekey_t &k_) : f (f_), k (k_)
    { initializers.push_front (this); }
    const function &run () const {
      k = f.get_fname()->getQNameKey();
      return f;
    }
  };

#define DECL( key, type, sig )                                          \
  qnamekey_t library::key##_key;                                        \
  type key##_tmp_obj (signature sig);                                   \
  initializer key##_tmp_init (key##_tmp_obj, library::key##_key)
  
  // Numerics
    
  // op_numeric_unary_plus
  // 
  // op_numeric_unary_minus
    
  DECL (op_add, op_numeric_add,
        (new QNameItem (XQUERY_FN_NS,"op","add"),
         xs_decimal, xs_decimal, xs_decimal));
  DECL (op_subtract, op_numeric_subtract,
        (new QNameItem (XQUERY_FN_NS,"op","subtract"),
         xs_decimal, xs_decimal, xs_decimal));
  DECL (op_mul, op_numeric_multiply,
        (new QNameItem (XQUERY_FN_NS,"op","multiply"),
         xs_decimal, xs_decimal, xs_decimal));
  DECL (op_div, op_numeric_divide,
        (new QNameItem (XQUERY_FN_NS,"op","divide"),
         xs_decimal, xs_decimal, xs_decimal));
  DECL (op_mod, op_numeric_mod,
        (new QNameItem (XQUERY_FN_NS,"op","mod"),
         xs_decimal, xs_decimal, xs_decimal));

  DECL (op_val_eq, op_numeric_equal,
        (new QNameItem(XQUERY_FN_NS,"op","equal"),
         xs_decimal, xs_decimal,
         xs_boolean));

  DECL (fn_abs, fn_abs,
        (new QNameItem(XQUERY_FN_NS, "fn", "abs"),
         xs_decimal,
         xs_decimal));

  // Sequences
  DECL (fn_doc, fn_doc_func,
        (new QNameItem(XQUERY_FN_NS,"fn","doc"),
         xs_string,
         documentNode));

  // Comparisons
  DECL (op_gt, op_greater,
        (new QNameItem(XQUERY_OP_NS,"op","greater"),
         xs_anyType, xs_anyType,
         xs_boolean));

  // Strings

  DECL (fn_codepoints_to_string, fn_codepoints_to_string,
        (new QNameItem(XQUERY_FN_NS,"fn","codepoints-to-string"),
         xs_integer,
         xs_string));

  DECL (fn_string_to_codepoints, fn_string_to_codepoints,
        (new QNameItem(XQUERY_FN_NS,"fn","string-to-codepoints"),
         xs_string,
         xs_long));

  DECL (fn_codepoint_equal, fn_codepoint_equal,
        (new QNameItem(XQUERY_FN_NS,"fn","codepoint-equal"),
         xs_string, xs_string,
         xs_boolean));

  DECL (fn_concat, fn_concat,
        (new QNameItem(XQUERY_FN_NS,"fn","concat"),
         xs_anyType,
         xs_boolean));

  DECL (fn_string_join, fn_string_join,
        (new QNameItem(XQUERY_FN_NS,"fn","string-join"),
         xs_string, xs_string,
         xs_string));

  DECL (fn_boolean, fn_boolean,
        (new QNameItem(XQUERY_FN_NS,"fn","boolean"),
         xs_anyType,
         xs_boolean));

// TODO

qnamekey_t library::op_idiv_key;

// Comparison operators
qnamekey_t library::op_eq_key;
qnamekey_t library::op_ne_key;
qnamekey_t library::op_lt_key;
qnamekey_t library::op_le_key;
qnamekey_t library::op_ge_key;
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

// initializer

void library::init(
	ItemFactory* vf_p)
{
  
	if (!library::static_init) {
    while (initializers.size () > 0) {
      const function &f = initializers.pop_front ()->run ();
      put (& f);
    }
    static_init = true; //don't initialize again
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
