/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: library.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *   Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan,Paul Pedersen
 */

#include <iostream>
#include <memory>


#include "system/globalenv.h"
#include "functions/library.h"
#include "functions/function.h"
#include "functions/signature.h"
#include "types/node_test.h"

#include "functions/Accessors.h"
#include "functions/Numerics.h"
#include "functions/QNames.h"
#include "functions/Sequences.h"
#include "functions/Strings.h"
#include "functions/Boolean.h"
#include "functions/Constructor.h"
#include "functions/ContextFunctions.h"
#include "functions/DateTime.h"
#include "functions/FnContext.h"
#include "functions/Misc.h"
#include "functions/arithmetic.h"
#include "functions/Nodes.h"

#include "context/static_context.h"
//#include "system/zorba.h"
#include "store/api/store.h"
#include "store/api/item_factory.h"

using namespace std;
namespace zorba {

// clear static initializer state

// dummy function to tell the windows linker to keep the library.obj
// even though it contains no public objects or functions
// this is called at initializeZorba
void library_init()
{}

static string get_qname(const function &f)
{
  store::Item_t name = f.get_fname();
  return name->getPrefix() + ":" + name->getLocalName();
}

#define DECL(type, sig)                                        \
do                                                             \
{                                                              \
  std::auto_ptr<function> type##_ptr(new type(signature sig)); \
                                                               \
  sctx->bind_fn(get_qname(*type##_ptr),                        \
                type##_ptr.get(),                              \
                type##_ptr->get_signature().arg_count());      \
  type##_ptr.release();                                        \
} while(0)


#define ITEM_FACTORY (*(GENV.getStore().getItemFactory()))

void BuiltinFunctionLibrary::populateContext(static_context *sctx)
{

// Accessors
DECL(fn_data_func,
     (ITEM_FACTORY.createQName (XQUERY_FN_NS, "fn", "data"),
      GENV_TYPESYSTEM.ITEM_TYPE_STAR, GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR));

DECL(fn_root_func,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS, "fn", "root"),
      GENV_TYPESYSTEM.ITEM_TYPE_STAR, GENV_TYPESYSTEM.ITEM_TYPE_STAR));

DECL(fn_nodename_func,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS, "fn", "node-name"),
      GENV_TYPESYSTEM.ITEM_TYPE_QUESTION, GENV_TYPESYSTEM.QNAME_TYPE_QUESTION));

DECL(fn_nilled_func,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS, "fn", "nilled"),
      GENV_TYPESYSTEM.ITEM_TYPE_QUESTION, GENV_TYPESYSTEM.BOOLEAN_TYPE_QUESTION));

DECL(fn_base_uri_func,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS, "fn", "base-uri"),
      GENV_TYPESYSTEM.ITEM_TYPE_QUESTION, GENV_TYPESYSTEM.ANY_URI_TYPE_QUESTION));

DECL(fn_document_uri_func,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS, "fn", "document-uri"),
      GENV_TYPESYSTEM.ITEM_TYPE_QUESTION, GENV_TYPESYSTEM.ANY_URI_TYPE_QUESTION));

DECL(fn_name_func,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS, "fn", "name"),
      GENV_TYPESYSTEM.ITEM_TYPE_QUESTION, GENV_TYPESYSTEM.STRING_TYPE_ONE));
// end Accessors

//begin Error function
DECL(fn_error,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS, "fn", "error"),
      GENV_TYPESYSTEM.NONE_TYPE));

DECL(fn_error,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS, "fn", "error"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.NONE_TYPE));

DECL(fn_error,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS, "fn", "error"),
      GENV_TYPESYSTEM.QNAME_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.NONE_TYPE));

DECL(fn_error,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS, "fn", "error"),
      GENV_TYPESYSTEM.QNAME_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR ,
      GENV_TYPESYSTEM.NONE_TYPE));
//end Errror function

//begin functions on nodes
DECL(fn_local_name,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS, "fn", "local-name"),
      GENV_TYPESYSTEM.ITEM_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(fn_namespace_uri,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS, "fn", "namespace-uri"),
      GENV_TYPESYSTEM.ITEM_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_URI_TYPE_ONE));

DECL(fn_lang,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS, "fn", "lang"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));
 
DECL(fn_lang,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS, "fn", "lang"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.ITEM_TYPE_ONE,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(fn_collection,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS, "fn", "collection"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));
//end functions on nodes


//begin functions on AnyURI
DECL(fn_resolve_uri,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS, "fn", "resolve-uri"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_URI_TYPE_QUESTION));

 DECL(fn_resolve_uri,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS, "fn", "resolve-uri"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_URI_TYPE_QUESTION));
//end functions on Any URI


// Generic Arithmetics
DECL(op_add,
     (ITEM_FACTORY.createQName (XQUERY_OP_NS,"fn", ":add"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(op_subtract,
     (ITEM_FACTORY.createQName (XQUERY_OP_NS,"fn", ":subtract"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(op_multiply,
     (ITEM_FACTORY.createQName (XQUERY_OP_NS,"fn", ":multiply"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(op_divide,
     (ITEM_FACTORY.createQName (XQUERY_OP_NS,"fn", ":divide"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(op_integer_divide,
     (ITEM_FACTORY.createQName (XQUERY_OP_NS,"fn", ":integer-divide"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(op_mod,
     (ITEM_FACTORY.createQName (XQUERY_OP_NS,"fn", ":mod"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

// Numerics
DECL(op_numeric_add,
     (ITEM_FACTORY.createQName (XQUERY_OP_NS,"fn", ":numeric-add"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(op_numeric_subtract,
     (ITEM_FACTORY.createQName (XQUERY_OP_NS,"fn", ":numeric-subtract"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(op_numeric_multiply,
     (ITEM_FACTORY.createQName (XQUERY_OP_NS,"fn", ":numeric-multiply"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(op_numeric_divide,
     (ITEM_FACTORY.createQName (XQUERY_OP_NS,"fn", ":numeric-divide"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(op_numeric_integer_divide,
     (ITEM_FACTORY.createQName (XQUERY_OP_NS,"fn", ":numeric-integer-divide"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(op_numeric_mod,
     (ITEM_FACTORY.createQName (XQUERY_OP_NS,"fn", ":numeric-mod"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

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


// begin context functions
//position(), last() and static-base-uri() are implemented in the context
DECL(fn_current_dateTime,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","current-dateTime"),
      GENV_TYPESYSTEM.DATETIME_TYPE_ONE));

DECL(fn_current_date,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","current-date"),
      GENV_TYPESYSTEM.DATE_TYPE_ONE));

DECL(fn_current_time,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","current-time"),
      GENV_TYPESYSTEM.TIME_TYPE_ONE));

DECL(fn_implicit_timezone,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","implicit-timezone"),
      GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE));

DECL(fn_default_collation,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","default-collation"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE));
// end context functions


//QNames
// rchandle<NodeTest> nodeTest;
// nodeTest = new NodeTest(store::StoreConsts::elementNode);

DECL(fn_resolve_qname,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS, "fn",  "resolve-QName"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      sctx->get_typemanager()->create_node_type(new NodeTest(store::StoreConsts::elementNode), NULL, TypeConstants::QUANT_ONE),
      GENV_TYPESYSTEM.QNAME_TYPE_QUESTION));
      
DECL(fn_qname,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS, "fn", "QName"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.QNAME_TYPE_ONE));

DECL(op_qname_equal,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","QName-equal"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(fn_prefix_from_qname,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","prefix-from-QName"),
      GENV_TYPESYSTEM.QNAME_TYPE_QUESTION,
      GENV_TYPESYSTEM.NCNAME_TYPE_QUESTION));

DECL(fn_local_name_from_qname,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","local-name-from-QName"),
      GENV_TYPESYSTEM.QNAME_TYPE_QUESTION,
      GENV_TYPESYSTEM.NCNAME_TYPE_QUESTION));

DECL(fn_namespace_uri_from_qname,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","namespace-uri-from-QName"),
      GENV_TYPESYSTEM.QNAME_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_URI_TYPE_QUESTION));

DECL(fn_namespace_uri_for_prefix,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","namespace-uri-for-prefix"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      sctx->get_typemanager()->create_node_type(new NodeTest(store::StoreConsts::elementNode), NULL, TypeConstants::QUANT_ONE),
      GENV_TYPESYSTEM.ANY_URI_TYPE_QUESTION));

DECL(fn_in_scope_prefixes,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","in-scope-prefixes"),
      sctx->get_typemanager()->create_node_type(new NodeTest(store::StoreConsts::elementNode), NULL, TypeConstants::QUANT_ONE),
      GENV_TYPESYSTEM.STRING_TYPE_STAR));
// end QNames

// Sequences
DECL(fn_doc_func,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","doc"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.DOCUMENT_TYPE_QUESTION));

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

DECL(fn_index_of,
    (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","index-of"),
    GENV_TYPESYSTEM.ITEM_TYPE_STAR,
    GENV_TYPESYSTEM.ITEM_TYPE_ONE,
    GENV_TYPESYSTEM.INTEGER_TYPE_STAR));

DECL(fn_index_of,
    (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","index-of"),
    GENV_TYPESYSTEM.ITEM_TYPE_STAR,
    GENV_TYPESYSTEM.ITEM_TYPE_ONE,
    GENV_TYPESYSTEM.STRING_TYPE_ONE,
    GENV_TYPESYSTEM.INTEGER_TYPE_STAR));

DECL(fn_remove,
    (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","remove"),
    GENV_TYPESYSTEM.ITEM_TYPE_STAR,
    GENV_TYPESYSTEM.INTEGER_TYPE_ONE,
    GENV_TYPESYSTEM.ITEM_TYPE_STAR));

DECL(fn_reverse,
    (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","reverse"),
    GENV_TYPESYSTEM.ITEM_TYPE_STAR,
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

DECL(fn_exactly_one_noraise,
    (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn",":exactly-one-noraise"),
    GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
    GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

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
    GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION, 
    GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION, 
    GENV_TYPESYSTEM.INTEGER_TYPE_STAR));

DECL(fn_unordered,
  (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","unordered"),
  GENV_TYPESYSTEM.ITEM_TYPE_STAR,
  GENV_TYPESYSTEM.ITEM_TYPE_STAR));

DECL(op_distinct_nodes,
  (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn",":distinct-nodes"),
  GENV_TYPESYSTEM.ITEM_TYPE_STAR,
  GENV_TYPESYSTEM.ITEM_TYPE_STAR));

DECL(op_distinct_nodes_or_atomics,
  (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn",":distinct-nodes-or-atomics"),
  GENV_TYPESYSTEM.ITEM_TYPE_STAR,
  GENV_TYPESYSTEM.ITEM_TYPE_STAR));

DECL(op_sort_nodes_ascending,
  (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn",":sort-nodes-ascending"),
  GENV_TYPESYSTEM.ITEM_TYPE_STAR,
  GENV_TYPESYSTEM.ITEM_TYPE_STAR));

DECL(op_sort_nodes_asc_or_atomics,
  (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn",":sort-nodes-asc-or-atomics"),
  GENV_TYPESYSTEM.ITEM_TYPE_STAR,
  GENV_TYPESYSTEM.ITEM_TYPE_STAR));

DECL(op_sort_nodes_descending,
  (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn",":sort-nodes-descending"),
  GENV_TYPESYSTEM.ITEM_TYPE_STAR,
  GENV_TYPESYSTEM.ITEM_TYPE_STAR));

DECL(op_sort_nodes_desc_or_atomics,
  (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn",":sort-nodes-desc-or-atomics"),
  GENV_TYPESYSTEM.ITEM_TYPE_STAR,
  GENV_TYPESYSTEM.ITEM_TYPE_STAR));

DECL(op_sort_distinct_nodes_ascending,
  (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn",":sort-distinct-nodes-ascending"),
  GENV_TYPESYSTEM.ITEM_TYPE_STAR,
  GENV_TYPESYSTEM.ITEM_TYPE_STAR));

DECL(op_sort_distinct_nodes_asc_or_atomics,
  (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn",":sort-distinct-nodes-asc-or-atomics"),
  GENV_TYPESYSTEM.ITEM_TYPE_STAR,
  GENV_TYPESYSTEM.ITEM_TYPE_STAR));

DECL(op_sort_distinct_nodes_descending,
  (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn",":sort-distinct-nodes-descending"),
  GENV_TYPESYSTEM.ITEM_TYPE_STAR,
  GENV_TYPESYSTEM.ITEM_TYPE_STAR));

// TODO: separate function
DECL(op_sort_distinct_nodes_descending,
  (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn",":sort-distinct-nodes-desc-or-atomics"),
  GENV_TYPESYSTEM.ITEM_TYPE_STAR,
  GENV_TYPESYSTEM.ITEM_TYPE_STAR));

  DECL(fn_union,
  (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn",":union"),
   GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR, GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
   GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));

  DECL(fn_intersect,
  (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn",":intersect"),
   GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR, GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
   GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));

  DECL(fn_except,
  (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn",":except"),
   GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR, GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
   GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));

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

// Node Comparison
DECL(op_is_same_node,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn", ":is-same-node"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_QUESTION));

DECL(op_node_before,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn", ":node-before"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_QUESTION));

DECL(op_node_after,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn", ":node-after"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_QUESTION));
// end Node Comparson

// Strings
DECL(fn_codepoints_to_string,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","codepoints-to-string"),
      GENV_TYPESYSTEM.INTEGER_TYPE_STAR,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(fn_string_to_codepoints,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","string-to-codepoints"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
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

DECL(fn_matches,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","matches"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(fn_matches,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","matches"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(fn_replace,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","replace"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(fn_replace,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","replace"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(fn_tokenize,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","tokenize"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_STAR));

DECL(fn_tokenize,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","tokenize"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_STAR));
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
DECL(fn_datetime_ctor,
     (ITEM_FACTORY.createQName(XQUERY_OP_NS,"fn", "dateTime"),
      GENV_TYPESYSTEM.DATE_TYPE_QUESTION,
      GENV_TYPESYSTEM.TIME_TYPE_QUESTION,
      GENV_TYPESYSTEM.DATETIME_TYPE_QUESTION));

DECL(fn_years_from_duration,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn", "years-from-duration"),
      GENV_TYPESYSTEM.DURATION_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION));

DECL(fn_months_from_duration,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn", "months-from-duration"),
      GENV_TYPESYSTEM.DURATION_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION));

DECL(fn_days_from_duration,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn", "days-from-duration"),
      GENV_TYPESYSTEM.DURATION_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION));

DECL(fn_hours_from_duration,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn", "hours-from-duration"),
      GENV_TYPESYSTEM.DURATION_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION));

DECL(fn_minutes_from_duration,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn", "minutes-from-duration"),
      GENV_TYPESYSTEM.DURATION_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION));

DECL(fn_seconds_from_duration,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn", "seconds-from-duration"),
      GENV_TYPESYSTEM.DURATION_TYPE_QUESTION,
      GENV_TYPESYSTEM.DECIMAL_TYPE_QUESTION));

DECL(fn_year_from_datetime,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn", "year-from-dateTime"),
      GENV_TYPESYSTEM.DATETIME_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION));

DECL(fn_month_from_datetime,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn", "month-from-dateTime"),
      GENV_TYPESYSTEM.DATETIME_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION));

DECL(fn_day_from_datetime,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn", "day-from-dateTime"),
      GENV_TYPESYSTEM.DATETIME_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION));

DECL(fn_hours_from_datetime,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn", "hours-from-dateTime"),
      GENV_TYPESYSTEM.DATETIME_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION));

DECL(fn_minutes_from_datetime,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn", "minutes-from-dateTime"),
      GENV_TYPESYSTEM.DATETIME_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION));

DECL(fn_seconds_from_datetime,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn", "seconds-from-dateTime"),
      GENV_TYPESYSTEM.DATETIME_TYPE_QUESTION,
      GENV_TYPESYSTEM.DECIMAL_TYPE_QUESTION));

DECL(fn_timezone_from_datetime,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn", "timezone-from-dateTime"),
      GENV_TYPESYSTEM.DATETIME_TYPE_QUESTION,
      GENV_TYPESYSTEM.DURATION_TYPE_QUESTION));

DECL(fn_year_from_date,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn", "year-from-date"),
      GENV_TYPESYSTEM.DATE_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION));

DECL(fn_month_from_date,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn", "month-from-date"),
      GENV_TYPESYSTEM.DATE_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION));

DECL(fn_day_from_date,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn", "day-from-date"),
      GENV_TYPESYSTEM.DATE_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION));

DECL(fn_timezone_from_date,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn", "timezone-from-date"),
      GENV_TYPESYSTEM.DATE_TYPE_QUESTION,
      GENV_TYPESYSTEM.DURATION_TYPE_QUESTION));

DECL(fn_hours_from_time,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn", "hours-from-time"),
      GENV_TYPESYSTEM.TIME_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION));

DECL(fn_minutes_from_time,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn", "minutes-from-time"),
      GENV_TYPESYSTEM.TIME_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION));

DECL(fn_seconds_from_time,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn", "seconds-from-time"),
      GENV_TYPESYSTEM.TIME_TYPE_QUESTION,
      GENV_TYPESYSTEM.DECIMAL_TYPE_QUESTION));

DECL(fn_timezone_from_time,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn", "timezone-from-time"),
      GENV_TYPESYSTEM.TIME_TYPE_QUESTION,
      GENV_TYPESYSTEM.DURATION_TYPE_QUESTION));

DECL(op_ym_durations_add,
     (ITEM_FACTORY.createQName (XQUERY_FN_NS,"fn", "add-yearMonthDurations"),
      GENV_TYPESYSTEM.YM_DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.YM_DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.YM_DURATION_TYPE_ONE));

DECL(op_dt_durations_add,
     (ITEM_FACTORY.createQName (XQUERY_FN_NS,"fn", "add-dayTimeDurations"),
      GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE));

DECL(op_ym_durations_subtract,
     (ITEM_FACTORY.createQName (XQUERY_FN_NS,"fn", "subtract-yearMonthDurations"),
      GENV_TYPESYSTEM.YM_DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.YM_DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.YM_DURATION_TYPE_ONE));

DECL(op_dt_durations_subtract,
     (ITEM_FACTORY.createQName (XQUERY_FN_NS,"fn", "subtract-dayTimeDurations"),
      GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE));

DECL(op_ym_durations_multiply,
     (ITEM_FACTORY.createQName (XQUERY_FN_NS,"fn", "multiply-yearMonthDuration"),
      GENV_TYPESYSTEM.YM_DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
      GENV_TYPESYSTEM.YM_DURATION_TYPE_ONE));

DECL(op_dt_durations_multiply,
     (ITEM_FACTORY.createQName (XQUERY_FN_NS,"fn", "multiply-dayTimeDuration"),
      GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
      GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE));

DECL(op_ym_durations_divide,
     (ITEM_FACTORY.createQName (XQUERY_FN_NS,"fn", "divide-yearMonthDuration"),
      GENV_TYPESYSTEM.YM_DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
      GENV_TYPESYSTEM.YM_DURATION_TYPE_ONE));

DECL(op_dt_durations_divide,
     (ITEM_FACTORY.createQName (XQUERY_FN_NS,"fn", "divide-dayTimeDuration"),
      GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
      GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE));

DECL(op_divide_ymd_by_ymd,
     (ITEM_FACTORY.createQName (XQUERY_FN_NS,"fn", "divide-yearMonthDuration-by-yearMonthDuration"),
      GENV_TYPESYSTEM.YM_DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.YM_DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DECIMAL_TYPE_ONE));

DECL(op_divide_dtd_by_dtd,
     (ITEM_FACTORY.createQName (XQUERY_FN_NS,"fn", "divide-dayTimeDuration-by-dayTimeDuration"),
      GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DECIMAL_TYPE_ONE));

 //TODO change the returned type to DT_DURATION_TYPE_QUESTION
DECL(op_sub_dt,
     (ITEM_FACTORY.createQName (XQUERY_FN_NS,"fn", "subtract-dateTimes"),
      GENV_TYPESYSTEM.DATETIME_TYPE_ONE,
      GENV_TYPESYSTEM.DATETIME_TYPE_ONE,
      GENV_TYPESYSTEM.DURATION_TYPE_QUESTION));

 //TODO change the returned type to DT_DURATION_TYPE_QUESTION
DECL(op_sub_d,
     (ITEM_FACTORY.createQName (XQUERY_FN_NS,"fn", "subtract-dates"),
      GENV_TYPESYSTEM.DATE_TYPE_ONE,
      GENV_TYPESYSTEM.DATE_TYPE_ONE,
      GENV_TYPESYSTEM.DURATION_TYPE_QUESTION));

 //TODO change the returned type to DT_DURATION_TYPE_QUESTION
DECL(op_sub_t,
     (ITEM_FACTORY.createQName (XQUERY_FN_NS,"fn", "subtract-times"),
      GENV_TYPESYSTEM.TIME_TYPE_ONE,
      GENV_TYPESYSTEM.TIME_TYPE_ONE,
      GENV_TYPESYSTEM.DURATION_TYPE_QUESTION));

 //TODO change the type of the second arg to YM_DURATION_TYPE_ONE
DECL(op_add_ymd_to_dt,
     (ITEM_FACTORY.createQName (XQUERY_FN_NS,"fn", "add-yearMonthDuration-to-dateTime"),
      GENV_TYPESYSTEM.DATETIME_TYPE_ONE,
      GENV_TYPESYSTEM.DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DATETIME_TYPE_ONE));

 //TODO change the type of the second arg to DT_DURATION_TYPE_ONE
DECL(op_add_dtd_to_dt,
     (ITEM_FACTORY.createQName (XQUERY_FN_NS,"fn", "add-dayTimeDuration-to-dateTime"),
      GENV_TYPESYSTEM.DATETIME_TYPE_ONE,
      GENV_TYPESYSTEM.DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DATETIME_TYPE_ONE));

 //TODO change the type of the second arg to YM_DURATION_TYPE_ONE
DECL(op_sub_ymd_from_dt,
     (ITEM_FACTORY.createQName (XQUERY_FN_NS,"fn", "subtract-yearMonthDuration-from-dateTime"),
      GENV_TYPESYSTEM.DATETIME_TYPE_ONE,
      GENV_TYPESYSTEM.DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DATETIME_TYPE_ONE));

 //TODO change the type of the second arg to DT_DURATION_TYPE_ONE
DECL(op_sub_dtd_from_dt,
     (ITEM_FACTORY.createQName (XQUERY_FN_NS,"fn", "subtract-dayTimeDuration-from-dateTime"),
      GENV_TYPESYSTEM.DATETIME_TYPE_ONE,
      GENV_TYPESYSTEM.DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DATETIME_TYPE_ONE));

 //TODO change the type of the second arg to YM_DURATION_TYPE_ONE
DECL(op_add_ymd_to_d,
     (ITEM_FACTORY.createQName (XQUERY_FN_NS,"fn", "add-yearMonthDuration-to-date"),
      GENV_TYPESYSTEM.DATE_TYPE_ONE,
      GENV_TYPESYSTEM.DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DATE_TYPE_ONE));

 //TODO change the type of the second arg to DT_DURATION_TYPE_ONE
DECL(op_add_dtd_to_d,
     (ITEM_FACTORY.createQName (XQUERY_FN_NS,"fn", "add-dayTimeDuration-to-date"),
      GENV_TYPESYSTEM.DATE_TYPE_ONE,
      GENV_TYPESYSTEM.DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DATE_TYPE_ONE));

 //TODO change the type of the second arg to YM_DURATION_TYPE_ONE
DECL(op_sub_ymd_from_d,
     (ITEM_FACTORY.createQName (XQUERY_FN_NS,"fn", "subtract-yearMonthDuration-from-date"),
      GENV_TYPESYSTEM.DATE_TYPE_ONE,
      GENV_TYPESYSTEM.DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DATE_TYPE_ONE));

 //TODO change the type of the second arg to DT_DURATION_TYPE_ONE
DECL(op_sub_dtd_from_d,
     (ITEM_FACTORY.createQName (XQUERY_FN_NS,"fn", "subtract-dayTimeDuration-from-date"),
      GENV_TYPESYSTEM.DATE_TYPE_ONE,
      GENV_TYPESYSTEM.DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DATE_TYPE_ONE));

 //TODO change the type of the second arg to DT_DURATION_TYPE_ONE
DECL(op_add_dtd_to_t,
     (ITEM_FACTORY.createQName (XQUERY_FN_NS,"fn", "add-dayTimeDuration-to-time"),
      GENV_TYPESYSTEM.TIME_TYPE_ONE,
      GENV_TYPESYSTEM.DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.TIME_TYPE_ONE));

 //TODO change the type of the second arg to DT_DURATION_TYPE_ONE
DECL(op_sub_dtd_from_t,
     (ITEM_FACTORY.createQName (XQUERY_FN_NS,"fn", "subtract-dayTimeDuration-from-time"),
      GENV_TYPESYSTEM.TIME_TYPE_ONE,
      GENV_TYPESYSTEM.DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.TIME_TYPE_ONE));

DECL(fn_adjust_dt_to_tz_1,
     (ITEM_FACTORY.createQName (XQUERY_FN_NS,"fn", "adjust-dateTime-to-timezone"),
      GENV_TYPESYSTEM.DATETIME_TYPE_QUESTION,
      GENV_TYPESYSTEM.DATETIME_TYPE_QUESTION));

DECL(fn_adjust_dt_to_tz_2,
     (ITEM_FACTORY.createQName (XQUERY_FN_NS,"fn", "adjust-dateTime-to-timezone"),
      GENV_TYPESYSTEM.DATETIME_TYPE_QUESTION,
      GENV_TYPESYSTEM.DT_DURATION_TYPE_QUESTION,
      GENV_TYPESYSTEM.DATETIME_TYPE_QUESTION));

DECL(fn_adjust_d_to_tz_1,
     (ITEM_FACTORY.createQName (XQUERY_FN_NS,"fn", "adjust-date-to-timezone"),
      GENV_TYPESYSTEM.DATE_TYPE_QUESTION,
      GENV_TYPESYSTEM.DATE_TYPE_QUESTION));

DECL(fn_adjust_d_to_tz_2,
     (ITEM_FACTORY.createQName (XQUERY_FN_NS,"fn", "adjust-date-to-timezone"),
      GENV_TYPESYSTEM.DATE_TYPE_QUESTION,
      GENV_TYPESYSTEM.DT_DURATION_TYPE_QUESTION,
      GENV_TYPESYSTEM.DATE_TYPE_QUESTION));

DECL(fn_adjust_t_to_tz_1,
     (ITEM_FACTORY.createQName (XQUERY_FN_NS,"fn", "adjust-time-to-timezone"),
      GENV_TYPESYSTEM.TIME_TYPE_QUESTION,
      GENV_TYPESYSTEM.TIME_TYPE_QUESTION));

DECL(fn_adjust_t_to_tz_2,
     (ITEM_FACTORY.createQName (XQUERY_FN_NS,"fn", "adjust-time-to-timezone"),
      GENV_TYPESYSTEM.TIME_TYPE_QUESTION,
      GENV_TYPESYSTEM.DT_DURATION_TYPE_QUESTION,
      GENV_TYPESYSTEM.TIME_TYPE_QUESTION));
  
// end date time

// begin debug functions
DECL(fn_trace_func,
     (ITEM_FACTORY.createQName(XQUERY_FN_NS,"fn","trace"),
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));
// end debug functions


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
}

} /* namespace zorba */
