/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: library.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan,Paul Pedersen
 */

#include <iostream>

#include "functions/library.h"
#include "functions/function.h"
#include "functions/signature.h"

#include "functions/Accessors.h"
#include "functions/Numerics.h"
#include "functions/Sequences.h"
#include "functions/Strings.h"
#include "functions/Boolean.h"

#include "context/common.h"
#include "context/static_context.h"
#include "util/zorba.h"
#include "types/sequence_type.h"
#include "util/tracer.h"
#include "util/list.h"
#include "store/api/item.h"
#include "store/naive/atomic_items.h"

using namespace std;
namespace xqp {

// clear static initializer state

  static string get_qname (const function &f) {
    const QNameItem *name = static_cast<const QNameItem *> (f.get_fname ());
    return name->getPrefix () + ":" + name->getLocalName ();
  }
  
#define DECL( type, sig )                                               \
  type type##_obj (signature sig);                                      \
  class type##_init_class {                                             \
  public:                                                               \
    type##_init_class () {                                              \
      static_context::root_static_context ()->                          \
        bind_fn (get_qname (type##_obj), & type##_obj);                 \
    }                                                                   \
  } type##_init_obj
  
  
  // Accessors
  DECL (fn_data_func,
  			(new QNameItem (XQUERY_FN_NS, "fn", "data"),
  			 xs_anyTypeSeq, xs_anyTypeSeq/*, xs_anySimpleTypeSeq*/));

  DECL (fn_root_func,
  			(new QNameItem(XQUERY_FN_NS, "fn", "root"), anyNodeOpt, anyNodeOpt));
  // end Accessors
  
  // Numerics
 	// TODO The parameter and return types of the numeric functions are not correct.
 	// e.g. it is possible to add two untyped atomics or the parameters can be element nodes
 	// which contain a number.
  DECL (op_numeric_add,
        (new QNameItem (XQUERY_OP_NS,"fn", ":add"),
         xs_decimal, xs_decimal, xs_decimal));
  DECL (op_numeric_subtract,
        (new QNameItem (XQUERY_OP_NS,"fn", ":subtract"),
         xs_decimal, xs_decimal, xs_decimal));
  DECL (op_numeric_multiply,
        (new QNameItem (XQUERY_OP_NS,"fn", ":multiply"),
         xs_decimal, xs_decimal, xs_decimal));
  DECL (op_numeric_divide,
        (new QNameItem (XQUERY_OP_NS,"fn", ":divide"),
         xs_decimal, xs_decimal, xs_decimal));
  DECL (op_numeric_integer_divide,
        (new QNameItem (XQUERY_OP_NS,"fn", ":integer-divide"),
         xs_decimal, xs_decimal, xs_decimal));
  DECL (op_numeric_mod,
        (new QNameItem (XQUERY_OP_NS,"fn", ":mod"),
         xs_decimal, xs_decimal, xs_decimal));
  DECL (op_numeric_unary_minus, 
  			(new QNameItem (XQUERY_OP_NS,"fn", ":unary-minus"),
  			xs_decimal, xs_decimal));
  DECL (op_numeric_unary_plus, 
  			(new QNameItem (XQUERY_OP_NS,"fn", ":unary-plus"),
  			xs_decimal, xs_decimal));

  DECL (fn_abs,
        (new QNameItem(XQUERY_FN_NS, "fn", "abs"),
         xs_decimal,
         xs_decimal));
  // end Numerics

  // Sequences
  DECL (fn_doc_func,
        (new QNameItem(XQUERY_FN_NS,"fn","doc"),
         xs_string,
         documentNode));
  // end Sequences

  // Generic Comparison;
  DECL (op_equal,
        (new QNameItem(XQUERY_OP_NS,"fn", ":equal"),
         xs_anyType, xs_anyType,
         xs_boolean));
         
  DECL (op_not_equal,
        (new QNameItem(XQUERY_OP_NS,"fn", ":not-equal"),
         xs_anyType, xs_anyType,
         xs_boolean));
  
  DECL (op_greater,
        (new QNameItem(XQUERY_OP_NS,"fn", ":greater"),
         xs_anyType, xs_anyType,
         xs_boolean));
         
  DECL (op_greater_equal,
        (new QNameItem(XQUERY_OP_NS,"fn", ":greater-equal"),
         xs_anyType, xs_anyType,
         xs_boolean));

   DECL (op_less,
        (new QNameItem(XQUERY_OP_NS,"fn", ":less"),
         xs_anyType, xs_anyType,
         xs_boolean));
         
   DECL (op_less_equal,
        (new QNameItem(XQUERY_OP_NS,"fn", ":less-equal"),
         xs_anyType, xs_anyType,
         xs_boolean));
   // end Generic Comparison
   
  // Value Comparison
	DECL (op_value_equal,
        (new QNameItem(XQUERY_FN_NS,"fn", ":value-equal"),
         xs_anyType, xs_anyType,
         xs_boolean));
      
	DECL (op_value_not_equal,
				(new QNameItem(XQUERY_FN_NS,"fn", ":value-not-equal"),
				xs_anyType, xs_anyType,
				xs_boolean));
				
	DECL (op_value_greater,
				(new QNameItem(XQUERY_FN_NS,"fn", ":value-greater"),
				xs_anyType, xs_anyType,
				xs_boolean));
				
	DECL (op_value_greater_equal,
				(new QNameItem(XQUERY_FN_NS,"fn", ":value-greater-equal"),
				xs_anyType, xs_anyType,
				xs_boolean));
				
	DECL (op_value_less,
				(new QNameItem(XQUERY_FN_NS,"fn", ":value-less"),
				xs_anyType, xs_anyType,
				xs_boolean));
				
	DECL (op_value_less_equal,
				(new QNameItem(XQUERY_FN_NS,"fn", ":value-less-equal"),
				xs_anyType, xs_anyType,
				xs_boolean));
  // end Value Comparison

  // Strings
  DECL (fn_codepoints_to_string,
        (new QNameItem(XQUERY_FN_NS,"fn","codepoints-to-string"),
         xs_integer,
         xs_string));

  DECL (fn_string_to_codepoints,
        (new QNameItem(XQUERY_FN_NS,"fn","string-to-codepoints"),
         xs_string,
         xs_integer));

  DECL (fn_codepoint_equal,
        (new QNameItem(XQUERY_FN_NS,"fn","codepoint-equal"),
         xs_string, xs_string,
         xs_boolean));

  DECL (fn_concat,
        (new QNameItem(XQUERY_FN_NS,"fn","concat"),
         xs_anyType,
         xs_boolean));

  DECL (fn_string_join,
        (new QNameItem(XQUERY_FN_NS,"fn","string-join"),
         xs_string, xs_string,
         xs_string));

  DECL (fn_substring,
        (new QNameItem(XQUERY_FN_NS,"fn","substring"),
         xs_string, xs_double, xs_double,
         xs_string));

  DECL (fn_normalize_space,
        (new QNameItem(XQUERY_FN_NS,"fn","normalize-space"),
         xs_string,
         xs_string));

  DECL (fn_normalize_unicode,
        (new QNameItem(XQUERY_FN_NS,"fn","normalize-unicode"),
         xs_string, xs_string,
         xs_string));

  DECL (fn_upper_case,
        (new QNameItem(XQUERY_FN_NS,"fn","upper-case"),
         xs_string,
         xs_string));

  DECL (fn_lower_case,
        (new QNameItem(XQUERY_FN_NS,"fn","lower-case"),
         xs_string,
         xs_string));

  DECL (fn_translate,
        (new QNameItem(XQUERY_FN_NS,"fn","translate"),
         xs_string, xs_string, xs_string,
         xs_string));

  DECL (fn_string_compare,
        (new QNameItem(XQUERY_FN_NS,"fn","compare"),
         xs_string, xs_string, xs_string,
         xs_integer));

  DECL (fn_string_length,
        (new QNameItem(XQUERY_FN_NS,"fn","string-length"),
         xs_string,
         xs_integer));

  DECL (fn_contains,
        (new QNameItem(XQUERY_FN_NS,"fn","contains"),
          xs_string, xs_string, xs_string,
          xs_boolean));

  DECL (fn_starts_with,
        (new QNameItem(XQUERY_FN_NS,"fn","starts-with"),
          xs_string, xs_string, xs_string,
          xs_boolean));

  DECL (fn_ends_with,
        (new QNameItem(XQUERY_FN_NS,"fn","ends-with"),
          xs_string, xs_string, xs_string,
          xs_boolean));

  DECL (fn_substring_before,
        (new QNameItem(XQUERY_FN_NS,"fn","substring-before"),
          xs_string, xs_string, xs_string,
          xs_string));

  DECL (fn_substring_after,
        (new QNameItem(XQUERY_FN_NS,"fn","substring-after"),
          xs_string, xs_string, xs_string,
          xs_string));
  // end Strings

	// start Boolean
	DECL (fn_true,
        (new QNameItem(XQUERY_FN_NS,"fn","true"),
         xs_boolean));
  
  DECL (fn_false,
        (new QNameItem(XQUERY_FN_NS,"fn","false"),
         xs_boolean));
  
  DECL (fn_boolean,
        (new QNameItem(XQUERY_FN_NS,"fn","boolean"),
         xs_anyType,
         xs_boolean));
  
  DECL (fn_not,
  			(new QNameItem(XQUERY_FN_NS,"fn","not"),
  			xs_anyType,
  			xs_boolean));
	// end Boolean
	
	// start Logic
	DECL (op_and,
			(new QNameItem(XQUERY_OP_NS,"fn", ":and"),
			xs_anyType,
			xs_boolean));
			
	DECL (op_or,
			(new QNameItem(XQUERY_OP_NS,"fn", ":or"),
			xs_anyType,
			xs_boolean));
	// end Logic
	
	// begin zorba functions
	DECL (zor_numgen,
			(new QNameItem(XQUERY_FN_NS,"fn", "zorba:numgen"),
			xs_decimal));
	// end zorba functions
	
} /* namespace xqp */
