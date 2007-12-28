/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: library.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *   Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan,Paul Pedersen
 */

#include <iostream>

#include "system/globalenv.h"
#include "functions/library.h"
#include "functions/function.h"
#include "functions/signature.h"

#include "functions/Accessors.h"
#include "functions/Numerics.h"
#include "functions/Sequences.h"
#include "functions/Strings.h"
#include "functions/Boolean.h"
#include "functions/Constructor.h"
#include "functions/DateTime.h"
#include "functions/FnContext.h"

#include "context/common.h"
#include "context/static_context.h"
#include "system/zorba.h"
#include "util/tracer.h"
#include "util/list.h"
#include "store/api/item.h"
#include "store/naive/atomic_items.h"
#include "store/naive/qname_pool.h"

using namespace std;
namespace xqp {

// clear static initializer state

// dummy function to tell the windows linker to keep the library.obj
// even though it contains no public objects or functions
// this is called at initializeZorba
void library_init()
{}

static string get_qname(const function &f)
{
  Item_t name = f.get_fname();
  return name->getPrefix() + ":" + name->getLocalName();
}


#define DECL( type, sig )                                               \
  type type##_obj (signature sig);                                      \
  class type##_init_class {                                             \
  public:                                                               \
    type##_init_class () {                                              \
      static_context::root_static_context ()->                          \
        bind_fn (get_qname (type##_obj), & type##_obj,                  \
                 type##_obj.get_signature ().arg_count ());             \
    }                                                                   \
  } type##_init_obj


#define ITEM_FACTORY (Store::getInstance().getItemFactory())

// Accessors
DECL(fn_data_func,
     (ITEM_FACTORY.createQName (XQUERY_FN_NS, "fn", "data"),
      GENV_TYPESYSTEM.ITEM_TYPE_STAR, GENV_TYPESYSTEM.ITEM_TYPE_STAR));

DECL(fn_root_func,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS, "fn", "root"),
      GENV_TYPESYSTEM.ITEM_TYPE_STAR, GENV_TYPESYSTEM.ITEM_TYPE_STAR));
// end Accessors

// Numerics
// TODO The parameter and return types of the numeric functions are not correct.
// e.g. it is possible to add two untyped atomics or the parameters can be element nodes
// which contain a number.
DECL(op_numeric_add,
     (ITEM_FACTORY.createQName (XQUERY_OP_NS,"fn", ":add"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE));

DECL(op_numeric_subtract,
     (ITEM_FACTORY.createQName (XQUERY_OP_NS,"fn", ":subtract"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE));

DECL(op_numeric_multiply,
     (ITEM_FACTORY.createQName (XQUERY_OP_NS,"fn", ":multiply"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE));

DECL(op_numeric_divide,
     (ITEM_FACTORY.createQName (XQUERY_OP_NS,"fn", ":divide"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE));

DECL(op_numeric_integer_divide,
     (ITEM_FACTORY.createQName (XQUERY_OP_NS,"fn", ":integer-divide"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE));

DECL(op_numeric_mod,
     (ITEM_FACTORY.createQName (XQUERY_OP_NS,"fn", ":mod"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE));

DECL(op_numeric_unary_minus,
     (ITEM_FACTORY.createQName (XQUERY_OP_NS,"fn", ":unary-minus"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE));

DECL(op_numeric_unary_plus,
     (ITEM_FACTORY.createQName (XQUERY_OP_NS,"fn", ":unary-plus"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE));

DECL(fn_abs,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS, "fn", "abs"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(fn_ceiling,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS, "fn", "ceiling"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(fn_floor,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS, "fn", "floor"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(fn_round,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS, "fn", "round"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(fn_round_half_to_even,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS, "fn", "round-half-to-even"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));
// end Numerics

// Sequences
DECL(fn_doc_func,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","doc"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));

DECL(op_concatenate,
       (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn",":concatenate"),
        GENV_TYPESYSTEM.ITEM_TYPE_STAR,
        true, GENV_TYPESYSTEM.ITEM_TYPE_STAR));

DECL(fn_exists,
    (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","exists"),
    GENV_TYPESYSTEM.ITEM_TYPE_ONE,
    GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(fn_empty,
    (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","empty"),
    GENV_TYPESYSTEM.ITEM_TYPE_ONE,
    GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

 // FIXME how to add the third optional string param
DECL(fn_index_of,
    (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","index-of"),
    GENV_TYPESYSTEM.ITEM_TYPE_STAR,
    GENV_TYPESYSTEM.ITEM_TYPE_ONE,
    GENV_TYPESYSTEM.INTEGER_TYPE_STAR));

DECL(fn_remove,
    (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","remove"),
    GENV_TYPESYSTEM.ITEM_TYPE_STAR,
    GENV_TYPESYSTEM.INTEGER_TYPE_ONE,
    GENV_TYPESYSTEM.ITEM_TYPE_STAR));

DECL(fn_distinct_values_1,
    (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","distinct-values"),
    GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR, 
    GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR));

DECL(fn_distinct_values_2,
    (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","distinct-values"),
    GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR, 
    GENV_TYPESYSTEM.STRING_TYPE_ONE,
    GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR));

DECL(fn_insert_before,
    (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","insert-before"),
    GENV_TYPESYSTEM.ITEM_TYPE_STAR,
    GENV_TYPESYSTEM.INTEGER_TYPE_ONE,    
    GENV_TYPESYSTEM.ITEM_TYPE_STAR,
    GENV_TYPESYSTEM.ITEM_TYPE_STAR));

DECL(fn_subsequence_2,
    (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","subsequence"),
    GENV_TYPESYSTEM.ITEM_TYPE_STAR,
    GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,    
    GENV_TYPESYSTEM.ITEM_TYPE_STAR));

DECL(fn_subsequence_3,
    (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","subsequence"),
    GENV_TYPESYSTEM.ITEM_TYPE_STAR,
    GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
    GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
    GENV_TYPESYSTEM.ITEM_TYPE_STAR));

DECL(fn_zero_or_one,
    (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","zero-or-one"),
    GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
    GENV_TYPESYSTEM.ITEM_TYPE_QUESTION));

DECL(fn_one_or_more,
    (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","one-or-more"),
    GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
    GENV_TYPESYSTEM.ITEM_TYPE_PLUS));

DECL(fn_exactly_one,
    (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","exactly-one"),
    GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
    GENV_TYPESYSTEM.ITEM_TYPE_ONE));

DECL(fn_count,
    (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","count"),
    GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
    GENV_TYPESYSTEM.INTEGER_TYPE_ONE));

DECL(fn_avg,
    (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","avg"),
    GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR, 
    GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(fn_max_1,
    (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","max"),
    GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR, 
    GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(fn_max_2,
    (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","max"),
    GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR, 
    GENV_TYPESYSTEM.STRING_TYPE_ONE, 
    GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(fn_min_1,
    (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","min"),
    GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR, 
    GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(fn_min_2,
    (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","min"),
    GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR, 
    GENV_TYPESYSTEM.STRING_TYPE_ONE, 
    GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(fn_sum_1,
    (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","sum"),
    GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR, 
    GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(fn_sum_2,
    (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","sum"),
    GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR, 
    GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION, 
    GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(op_to,
    (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn",":to"),
    GENV_TYPESYSTEM.INTEGER_TYPE_ONE, 
    GENV_TYPESYSTEM.INTEGER_TYPE_ONE, 
    GENV_TYPESYSTEM.INTEGER_TYPE_STAR));

DECL(op_distinct_nodes,
  (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn",":distinct-nodes"),
  GENV_TYPESYSTEM.ITEM_TYPE_STAR,
  GENV_TYPESYSTEM.ITEM_TYPE_STAR));

DECL(op_sort_nodes_ascending,
  (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn",":sort-nodes-ascending"),
  GENV_TYPESYSTEM.ITEM_TYPE_STAR,
  GENV_TYPESYSTEM.ITEM_TYPE_STAR));

DECL(op_sort_nodes_descending,
  (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn",":sort-nodes-descending"),
  GENV_TYPESYSTEM.ITEM_TYPE_STAR,
  GENV_TYPESYSTEM.ITEM_TYPE_STAR));

DECL(op_sort_distinct_nodes_ascending,
  (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn",":sort-distinct-nodes-ascending"),
  GENV_TYPESYSTEM.ITEM_TYPE_STAR,
  GENV_TYPESYSTEM.ITEM_TYPE_STAR));

DECL(op_sort_distinct_nodes_descending,
  (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn",":sort-distinct-nodes-descending"),
  GENV_TYPESYSTEM.ITEM_TYPE_STAR,
  GENV_TYPESYSTEM.ITEM_TYPE_STAR));

#if 0  // need node types
  DECL(op_union,
  (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn",":union"),
  GENV_TYPESYSTEM.,
  GENV_TYPESYSTEM.ITEM_TYPE_STAR));
#endif

// end Sequences

// Generic Comparison;
DECL(op_equal,
     (ITEM_FACTORY.createQName(XQUERY_OP_NS,"fn", ":equal"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(op_not_equal,
     (ITEM_FACTORY.createQName(XQUERY_OP_NS,"fn", ":not-equal"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(op_greater,
     (ITEM_FACTORY.createQName(XQUERY_OP_NS,"fn", ":greater"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(op_greater_equal,
     (ITEM_FACTORY.createQName(XQUERY_OP_NS,"fn", ":greater-equal"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(op_less,
     (ITEM_FACTORY.createQName(XQUERY_OP_NS,"fn", ":less"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(op_less_equal,
     (ITEM_FACTORY.createQName(XQUERY_OP_NS,"fn", ":less-equal"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));
// end Generic Comparison

// Value Comparison
DECL(op_value_equal,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn", ":value-equal"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_QUESTION));

DECL(op_value_not_equal,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn", ":value-not-equal"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_QUESTION));

DECL(op_value_greater,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn", ":value-greater"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_QUESTION));

DECL(op_value_greater_equal,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn", ":value-greater-equal"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_QUESTION));

DECL(op_value_less,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn", ":value-less"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_QUESTION));

DECL(op_value_less_equal,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn", ":value-less-equal"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_QUESTION));
// end Value Comparison

// Strings
DECL(fn_codepoints_to_string,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","codepoints-to-string"),
      GENV_TYPESYSTEM.INTEGER_TYPE_STAR,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(fn_string_to_codepoints,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","string-to-codepoints"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.INTEGER_TYPE_STAR));

DECL(fn_string_compare_2,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","compare"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION));

DECL(fn_string_compare_3,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","compare"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION));

DECL(fn_codepoint_equal,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","codepoint-equal"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_QUESTION));

DECL(fn_concat,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","concat"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      true, GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(fn_string_join,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","string-join"),
      GENV_TYPESYSTEM.STRING_TYPE_STAR,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(fn_substring_2,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","substring"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(fn_substring_3,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","substring"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(fn_string_length,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","string-length"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_ONE));

DECL(fn_normalize_space,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","normalize-space"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(fn_normalize_unicode_1,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","normalize-unicode"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(fn_normalize_unicode_2,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","normalize-unicode"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(fn_upper_case,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","upper-case"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(fn_lower_case,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","lower-case"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(fn_translate,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","translate"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(fn_encode_for_uri,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","encode-for-uri"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(fn_iri_to_uri,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","iri-to-uri"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(fn_escape_html_uri,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","escape-html-uri"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(fn_contains_2,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","contains"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));
      
DECL(fn_contains_3,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","contains"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(fn_starts_with_2,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","starts-with"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(fn_starts_with_3,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","starts-with"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(fn_ends_with_2,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","ends-with"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(fn_ends_with_3,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","ends-with"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(fn_substring_before_2,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","substring-before"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(fn_substring_before_3,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","substring-before"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(fn_substring_after_2,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","substring-after"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(fn_substring_after_3,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","substring-after"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));
// end Strings

// start Boolean
DECL(fn_true,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","true"),
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(fn_false,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","false"),
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(fn_boolean,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","boolean"),
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(fn_not,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","not"),
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));
// end Boolean

// start Logic
DECL(op_and,
     (ITEM_FACTORY.createQName(XQUERY_OP_NS,"fn", ":and"),
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      true, GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(op_or,
     (ITEM_FACTORY.createQName(XQUERY_OP_NS,"fn", ":or"),
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      true, GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));
// end Logic

// begin constructors
DECL(op_enclosed_expr,
     (ITEM_FACTORY.createQName(XQUERY_OP_NS,"fn", ":enclosed-expr"),
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));

DECL(op_docfilter_expr,
     (ITEM_FACTORY.createQName(XQUERY_OP_NS,"fn", ":doc-filter"),
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));
// end constructors

// begin date time
DECL(op_duration_equal,
     (ITEM_FACTORY.createQName(XQUERY_OP_NS,"fn", "duration-equal"),
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));


// end date time

// begin zorba functions
DECL(zor_numgen,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn", "zorba:numgen"),
      GENV_TYPESYSTEM.DECIMAL_TYPE_ONE));
// end zorba functions

// begin context functions
DECL(ctx_variable,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn", ":ctxvariable"),
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));
// end context functions

} /* namespace xqp */
