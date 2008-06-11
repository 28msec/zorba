/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
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

#ifdef ZORBA_WITH_REST
#include "functions/Rest.h"
#endif

#include "context/static_context.h"
#include "context/namespace_context.h"

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

#define DECL(type, sig)                                        \
do                                                             \
{                                                              \
  std::auto_ptr<function> type##_ptr(new type(signature sig)); \
                                                               \
  sctx->bind_fn(type##_ptr->get_fname (),                      \
                type##_ptr.get(),                              \
                type##_ptr->get_signature().arg_count());      \
  type##_ptr.release();                                        \
} while(0)

#define ITEM_FACTORY (*(GENV.getStore().getItemFactory()))

static store::Item_t createQName(const char *ns, const char *pre, const char *local)
{
  store::Item_t res;
  ITEM_FACTORY.createQName(res, ns, pre, local);
  return res;
}

void BuiltinFunctionLibrary::populateContext(static_context *sctx)
{
  populateContext_Accesors(sctx);
  populateContext_Error(sctx);
  populateContext_Nodes(sctx);
  populateContext_AnyURI(sctx);
  populateContext_Arithmetics(sctx);
  populateContext_Context(sctx);
  populateContext_QNames(sctx);
  populateContext_Sequences(sctx);
  populateContext_Comparison(sctx);
  populateContext_Strings(sctx);
  populateContext_Boolean(sctx);
  populateContext_Constructors(sctx);
  populateContext_Datetime(sctx);
  populateContext_Debug(sctx);
  populateContext_Zorba(sctx);
}

void BuiltinFunctionLibrary::populateContext_Accesors(static_context *sctx)
{
// Accessors
DECL(fn_data_func,
     (createQName (XQUERY_FN_NS, "fn", "data"),
      GENV_TYPESYSTEM.ITEM_TYPE_STAR, GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR));

DECL(fn_root_func,
     (createQName(XQUERY_FN_NS, "fn", "root"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION, GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION));

DECL(fn_nodename_func,
     (createQName(XQUERY_FN_NS, "fn", "node-name"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION, GENV_TYPESYSTEM.QNAME_TYPE_QUESTION));

DECL(fn_nilled_func,
     (createQName(XQUERY_FN_NS, "fn", "nilled"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION, GENV_TYPESYSTEM.BOOLEAN_TYPE_QUESTION));

DECL(fn_base_uri_func,
     (createQName(XQUERY_FN_NS, "fn", "base-uri"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION, GENV_TYPESYSTEM.ANY_URI_TYPE_QUESTION));

DECL(fn_document_uri_func,
     (createQName(XQUERY_FN_NS, "fn", "document-uri"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION, GENV_TYPESYSTEM.ANY_URI_TYPE_QUESTION));

DECL(fn_name_func,
     (createQName(XQUERY_FN_NS, "fn", "name"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION, GENV_TYPESYSTEM.STRING_TYPE_ONE));
// end Accessors

}
void BuiltinFunctionLibrary::populateContext_Error(static_context *sctx)
{
//begin Error function
DECL(fn_error,
     (createQName(XQUERY_FN_NS, "fn", "error"),
      GENV_TYPESYSTEM.NONE_TYPE));

DECL(fn_error,
     (createQName(XQUERY_FN_NS, "fn", "error"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.NONE_TYPE));

DECL(fn_error,
     (createQName(XQUERY_FN_NS, "fn", "error"),
      GENV_TYPESYSTEM.QNAME_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.NONE_TYPE));

DECL(fn_error,
     (createQName(XQUERY_FN_NS, "fn", "error"),
      GENV_TYPESYSTEM.QNAME_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR ,
      GENV_TYPESYSTEM.NONE_TYPE));
//end Errror function

}
void BuiltinFunctionLibrary::populateContext_Nodes(static_context *sctx)
{
//begin functions on nodes
DECL(fn_local_name,
     (createQName(XQUERY_FN_NS, "fn", "local-name"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(fn_namespace_uri,
     (createQName(XQUERY_FN_NS, "fn", "namespace-uri"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_URI_TYPE_ONE));

DECL(fn_lang,
     (createQName(XQUERY_FN_NS, "fn", "lang"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(fn_collection,
     (createQName(XQUERY_FN_NS, "fn", "collection"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));

DECL(fn_collection,
     (createQName(XQUERY_FN_NS, "fn", "collection"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));
//end functions on nodes


}
void BuiltinFunctionLibrary::populateContext_AnyURI(static_context *sctx)
{
//begin functions on AnyURI

// resolve-uri / 1 handled by translator

 DECL(fn_resolve_uri,
     (createQName(XQUERY_FN_NS, "fn", "resolve-uri"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_URI_TYPE_QUESTION));
//end functions on Any URI


}
void BuiltinFunctionLibrary::populateContext_Arithmetics(static_context *sctx)
{
// Generic Arithmetics
DECL(op_add,
     (createQName (XQUERY_OP_NS,"fn", ":add"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(op_subtract,
     (createQName (XQUERY_OP_NS,"fn", ":subtract"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(op_multiply,
     (createQName (XQUERY_OP_NS,"fn", ":multiply"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(op_divide,
     (createQName (XQUERY_OP_NS,"fn", ":divide"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(op_integer_divide,
     (createQName (XQUERY_OP_NS,"fn", ":integer-divide"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(op_mod,
     (createQName (XQUERY_OP_NS,"fn", ":mod"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

// Numerics
DECL(op_numeric_add,
     (createQName (XQUERY_OP_NS,"fn", ":numeric-add"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(op_numeric_subtract,
     (createQName (XQUERY_OP_NS,"fn", ":numeric-subtract"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(op_numeric_multiply,
     (createQName (XQUERY_OP_NS,"fn", ":numeric-multiply"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(op_numeric_divide,
     (createQName (XQUERY_OP_NS,"fn", ":numeric-divide"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(op_numeric_integer_divide,
     (createQName (XQUERY_OP_NS,"fn", ":numeric-integer-divide"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(op_numeric_mod,
     (createQName (XQUERY_OP_NS,"fn", ":numeric-mod"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(op_numeric_unary_minus,
     (createQName (XQUERY_OP_NS,"fn", ":unary-minus"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE));

DECL(op_numeric_unary_plus,
     (createQName (XQUERY_OP_NS,"fn", ":unary-plus"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE));

DECL(fn_abs,
     (createQName(XQUERY_FN_NS, "fn", "abs"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(fn_ceiling,
     (createQName(XQUERY_FN_NS, "fn", "ceiling"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(fn_floor,
     (createQName(XQUERY_FN_NS, "fn", "floor"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(fn_round,
     (createQName(XQUERY_FN_NS, "fn", "round"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(fn_round_half_to_even,
     (createQName(XQUERY_FN_NS, "fn", "round-half-to-even"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(fn_round_half_to_even,
     (createQName(XQUERY_FN_NS, "fn", "round-half-to-even"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));
// end Numerics


}
void BuiltinFunctionLibrary::populateContext_Context(static_context *sctx)
{
// begin context functions
//position(), last() and static-base-uri() are implemented in the context
DECL(fn_current_dateTime,
     (createQName(XQUERY_FN_NS,"fn","current-dateTime"),
      GENV_TYPESYSTEM.DATETIME_TYPE_ONE));

DECL(fn_current_date,
     (createQName(XQUERY_FN_NS,"fn","current-date"),
      GENV_TYPESYSTEM.DATE_TYPE_ONE));

DECL(fn_current_time,
     (createQName(XQUERY_FN_NS,"fn","current-time"),
      GENV_TYPESYSTEM.TIME_TYPE_ONE));

DECL(fn_implicit_timezone,
     (createQName(XQUERY_FN_NS,"fn","implicit-timezone"),
      GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE));

DECL(fn_default_collation,
     (createQName(XQUERY_FN_NS,"fn","default-collation"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE));
// end context functions


}
void BuiltinFunctionLibrary::populateContext_QNames(static_context *sctx)
{
//QNames
// rchandle<NodeTest> nodeTest;
// nodeTest = new NodeTest(store::StoreConsts::elementNode);

DECL(fn_resolve_qname,
     (createQName(XQUERY_FN_NS, "fn",  "resolve-QName"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE,
      GENV_TYPESYSTEM.QNAME_TYPE_QUESTION));
      
DECL(fn_qname,
     (createQName(XQUERY_FN_NS, "fn", "QName"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.QNAME_TYPE_ONE));

DECL(op_qname_equal,
     (createQName(XQUERY_FN_NS,"fn","QName-equal"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(fn_prefix_from_qname,
     (createQName(XQUERY_FN_NS,"fn","prefix-from-QName"),
      GENV_TYPESYSTEM.QNAME_TYPE_QUESTION,
      GENV_TYPESYSTEM.NCNAME_TYPE_QUESTION));

DECL(fn_local_name_from_qname,
     (createQName(XQUERY_FN_NS,"fn","local-name-from-QName"),
      GENV_TYPESYSTEM.QNAME_TYPE_QUESTION,
      GENV_TYPESYSTEM.NCNAME_TYPE_QUESTION));

DECL(fn_namespace_uri_from_qname,
     (createQName(XQUERY_FN_NS,"fn","namespace-uri-from-QName"),
      GENV_TYPESYSTEM.QNAME_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_URI_TYPE_QUESTION));

DECL(fn_namespace_uri_for_prefix,
     (createQName(XQUERY_FN_NS,"fn","namespace-uri-for-prefix"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_URI_TYPE_QUESTION));

DECL(fn_in_scope_prefixes,
     (createQName(XQUERY_FN_NS,"fn","in-scope-prefixes"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_STAR));
// end QNames

}
void BuiltinFunctionLibrary::populateContext_Sequences(static_context *sctx)
{
// Sequences
DECL(fn_doc_func,
     (createQName(XQUERY_FN_NS,"fn","doc"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.DOCUMENT_TYPE_QUESTION));

DECL(fn_doc_available_func,
     (createQName(XQUERY_FN_NS,"fn","doc-available"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(op_concatenate,
     (createQName(XQUERY_FN_NS,"fn",":concatenate"),
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      true, GENV_TYPESYSTEM.ITEM_TYPE_STAR));

DECL(fn_exists,
    (createQName(XQUERY_FN_NS,"fn","exists"),
    GENV_TYPESYSTEM.ITEM_TYPE_STAR,
    GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(fn_empty,
    (createQName(XQUERY_FN_NS,"fn","empty"),
    GENV_TYPESYSTEM.ITEM_TYPE_STAR,
    GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(fn_index_of,
    (createQName(XQUERY_FN_NS,"fn","index-of"),
    GENV_TYPESYSTEM.ITEM_TYPE_STAR,
    GENV_TYPESYSTEM.ITEM_TYPE_ONE,
    GENV_TYPESYSTEM.INTEGER_TYPE_STAR));

DECL(fn_index_of,
    (createQName(XQUERY_FN_NS,"fn","index-of"),
    GENV_TYPESYSTEM.ITEM_TYPE_STAR,
    GENV_TYPESYSTEM.ITEM_TYPE_ONE,
    GENV_TYPESYSTEM.STRING_TYPE_ONE,
    GENV_TYPESYSTEM.INTEGER_TYPE_STAR));

DECL(fn_remove,
    (createQName(XQUERY_FN_NS,"fn","remove"),
    GENV_TYPESYSTEM.ITEM_TYPE_STAR,
    GENV_TYPESYSTEM.INTEGER_TYPE_ONE,
    GENV_TYPESYSTEM.ITEM_TYPE_STAR));

DECL(fn_reverse,
    (createQName(XQUERY_FN_NS,"fn","reverse"),
    GENV_TYPESYSTEM.ITEM_TYPE_STAR,
    GENV_TYPESYSTEM.ITEM_TYPE_STAR));

DECL(fn_distinct_values,
    (createQName(XQUERY_FN_NS,"fn","distinct-values"),
    GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR, 
    GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR));

DECL(fn_distinct_values,
    (createQName(XQUERY_FN_NS,"fn","distinct-values"),
    GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR, 
    GENV_TYPESYSTEM.STRING_TYPE_ONE,
    GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR));

DECL(fn_insert_before,
    (createQName(XQUERY_FN_NS,"fn","insert-before"),
    GENV_TYPESYSTEM.ITEM_TYPE_STAR,
    GENV_TYPESYSTEM.INTEGER_TYPE_ONE,    
    GENV_TYPESYSTEM.ITEM_TYPE_STAR,
    GENV_TYPESYSTEM.ITEM_TYPE_STAR));

DECL(fn_subsequence,
    (createQName(XQUERY_FN_NS,"fn","subsequence"),
    GENV_TYPESYSTEM.ITEM_TYPE_STAR,
    GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,    
    GENV_TYPESYSTEM.ITEM_TYPE_STAR));

DECL(fn_subsequence,
    (createQName(XQUERY_FN_NS,"fn","subsequence"),
    GENV_TYPESYSTEM.ITEM_TYPE_STAR,
    GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
    GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
    GENV_TYPESYSTEM.ITEM_TYPE_STAR));

DECL(fn_zero_or_one,
    (createQName(XQUERY_FN_NS,"fn","zero-or-one"),
    GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
    GENV_TYPESYSTEM.ITEM_TYPE_QUESTION));

DECL(fn_one_or_more,
    (createQName(XQUERY_FN_NS,"fn","one-or-more"),
    GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
    GENV_TYPESYSTEM.ITEM_TYPE_PLUS));

DECL(fn_exactly_one,
    (createQName(XQUERY_FN_NS,"fn","exactly-one"),
    GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
    GENV_TYPESYSTEM.ITEM_TYPE_ONE));

DECL(fn_exactly_one_noraise,
    (createQName(XQUERY_FN_NS,"fn",":exactly-one-noraise"),
    GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
    GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(fn_count,
    (createQName(XQUERY_FN_NS,"fn","count"),
    GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
    GENV_TYPESYSTEM.INTEGER_TYPE_ONE));

DECL(fn_avg,
    (createQName(XQUERY_FN_NS,"fn","avg"),
    GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR, 
    GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(fn_max_1,
    (createQName(XQUERY_FN_NS,"fn","max"),
    GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR, 
    GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(fn_max_2,
    (createQName(XQUERY_FN_NS,"fn","max"),
    GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR, 
    GENV_TYPESYSTEM.STRING_TYPE_ONE, 
    GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(fn_min_1,
    (createQName(XQUERY_FN_NS,"fn","min"),
    GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR, 
    GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(fn_min_2,
    (createQName(XQUERY_FN_NS,"fn","min"),
    GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR, 
    GENV_TYPESYSTEM.STRING_TYPE_ONE, 
    GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(fn_sum,
    (createQName(XQUERY_FN_NS,"fn","sum"),
    GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR, 
    GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(fn_sum,
    (createQName(XQUERY_FN_NS,"fn","sum"),
    GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR, 
    GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION, 
    GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(op_to,
    (createQName(XQUERY_FN_NS,"fn",":to"),
    GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION, 
    GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION, 
    GENV_TYPESYSTEM.INTEGER_TYPE_STAR));

DECL(fn_id,
     (createQName(XQUERY_FN_NS,"fn","id"),
      GENV_TYPESYSTEM.STRING_TYPE_STAR,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR)
    );

DECL(fn_id_ref,
     (createQName(XQUERY_FN_NS,"fn","idref"),
      GENV_TYPESYSTEM.STRING_TYPE_STAR,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));

DECL(fn_unordered,
  (createQName(XQUERY_FN_NS,"fn","unordered"),
  GENV_TYPESYSTEM.ITEM_TYPE_STAR,
  GENV_TYPESYSTEM.ITEM_TYPE_STAR));

DECL(op_either_nodes_or_atomics,
  (createQName(XQUERY_FN_NS,"fn",":either-nodes-or-atomics"),
  GENV_TYPESYSTEM.ITEM_TYPE_STAR,
  GENV_TYPESYSTEM.ITEM_TYPE_STAR));

DECL(op_distinct_nodes,
  (createQName(XQUERY_FN_NS,"fn",":distinct-nodes"),
  GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
  GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));

DECL(op_distinct_nodes_or_atomics,
  (createQName(XQUERY_FN_NS,"fn",":distinct-nodes-or-atomics"),
  GENV_TYPESYSTEM.ITEM_TYPE_STAR,
  GENV_TYPESYSTEM.ITEM_TYPE_STAR));

DECL(op_sort_nodes_ascending,
  (createQName(XQUERY_FN_NS,"fn",":sort-nodes-ascending"),
  GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
  GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));

DECL(op_sort_nodes_asc_or_atomics,
  (createQName(XQUERY_FN_NS,"fn",":sort-nodes-asc-or-atomics"),
  GENV_TYPESYSTEM.ITEM_TYPE_STAR,
  GENV_TYPESYSTEM.ITEM_TYPE_STAR));

DECL(op_sort_nodes_descending,
  (createQName(XQUERY_FN_NS,"fn",":sort-nodes-descending"),
  GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
  GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));

DECL(op_sort_nodes_desc_or_atomics,
  (createQName(XQUERY_FN_NS,"fn",":sort-nodes-desc-or-atomics"),
  GENV_TYPESYSTEM.ITEM_TYPE_STAR,
  GENV_TYPESYSTEM.ITEM_TYPE_STAR));

DECL(op_sort_distinct_nodes_ascending,
  (createQName(XQUERY_FN_NS,"fn",":sort-distinct-nodes-ascending"),
  GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
  GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));

DECL(op_sort_distinct_nodes_asc_or_atomics,
  (createQName(XQUERY_FN_NS,"fn",":sort-distinct-nodes-asc-or-atomics"),
  GENV_TYPESYSTEM.ITEM_TYPE_STAR,
  GENV_TYPESYSTEM.ITEM_TYPE_STAR));

DECL(op_sort_distinct_nodes_descending,
  (createQName(XQUERY_FN_NS,"fn",":sort-distinct-nodes-descending"),
  GENV_TYPESYSTEM.ITEM_TYPE_STAR,
  GENV_TYPESYSTEM.ITEM_TYPE_STAR));

// TODO: separate function
DECL(op_sort_distinct_nodes_descending,
  (createQName(XQUERY_FN_NS,"fn",":sort-distinct-nodes-desc-or-atomics"),
  GENV_TYPESYSTEM.ITEM_TYPE_STAR,
  GENV_TYPESYSTEM.ITEM_TYPE_STAR));

  DECL(fn_union,
  (createQName(XQUERY_FN_NS,"fn",":union"),
   GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR, GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
   GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));

  DECL(fn_intersect,
  (createQName(XQUERY_FN_NS,"fn",":intersect"),
   GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR, GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
   GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));

  DECL(fn_except,
  (createQName(XQUERY_FN_NS,"fn",":except"),
   GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR, GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
   GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));
  
DECL(fn_deep_equal,
  (createQName(XQUERY_FN_NS, "fn", "deep-equal"),
  GENV_TYPESYSTEM.ITEM_TYPE_STAR,
  GENV_TYPESYSTEM.ITEM_TYPE_STAR,
  GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(fn_deep_equal,
  (createQName(XQUERY_FN_NS, "fn", "deep-equal"),
  GENV_TYPESYSTEM.ITEM_TYPE_STAR,
  GENV_TYPESYSTEM.ITEM_TYPE_STAR,
  GENV_TYPESYSTEM.STRING_TYPE_ONE,
  GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));


// end Sequences

}
void BuiltinFunctionLibrary::populateContext_Comparison(static_context *sctx)
{
// Generic Comparison;
DECL(op_equal,
     (createQName(XQUERY_OP_NS,"fn", ":equal"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(op_not_equal,
     (createQName(XQUERY_OP_NS,"fn", ":not-equal"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(op_greater,
     (createQName(XQUERY_OP_NS,"fn", ":greater"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(op_greater_equal,
     (createQName(XQUERY_OP_NS,"fn", ":greater-equal"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(op_less,
     (createQName(XQUERY_OP_NS,"fn", ":less"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(op_less_equal,
     (createQName(XQUERY_OP_NS,"fn", ":less-equal"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));
// end Generic Comparison

// Value Comparison
DECL(op_value_equal,
     (createQName(XQUERY_FN_NS,"fn", ":value-equal"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_QUESTION));

DECL(op_value_not_equal,
     (createQName(XQUERY_FN_NS,"fn", ":value-not-equal"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_QUESTION));

DECL(op_value_greater,
     (createQName(XQUERY_FN_NS,"fn", ":value-greater"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_QUESTION));

DECL(op_value_greater_equal,
     (createQName(XQUERY_FN_NS,"fn", ":value-greater-equal"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_QUESTION));

DECL(op_value_less,
     (createQName(XQUERY_FN_NS,"fn", ":value-less"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_QUESTION));

DECL(op_value_less_equal,
     (createQName(XQUERY_FN_NS,"fn", ":value-less-equal"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_QUESTION));
// end Value Comparison

// Node Comparison
DECL(op_is_same_node,
     (createQName(XQUERY_FN_NS,"fn", ":is-same-node"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_QUESTION));

DECL(op_node_before,
     (createQName(XQUERY_FN_NS,"fn", ":node-before"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_QUESTION));

DECL(op_node_after,
     (createQName(XQUERY_FN_NS,"fn", ":node-after"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_QUESTION));

// end Node Comparson

}
void BuiltinFunctionLibrary::populateContext_Strings(static_context *sctx)
{
// Strings
DECL(fn_codepoints_to_string,
     (createQName(XQUERY_FN_NS,"fn","codepoints-to-string"),
      GENV_TYPESYSTEM.INTEGER_TYPE_STAR,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(fn_string_to_codepoints,
     (createQName(XQUERY_FN_NS,"fn","string-to-codepoints"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_STAR));

DECL(fn_string_compare,
     (createQName(XQUERY_FN_NS,"fn","compare"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION));

DECL(fn_string_compare,
     (createQName(XQUERY_FN_NS,"fn","compare"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION));

DECL(fn_codepoint_equal,
     (createQName(XQUERY_FN_NS,"fn","codepoint-equal"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_QUESTION));

// the string concat function, not the sequence op:concat
DECL(fn_concat,
     (createQName(XQUERY_FN_NS,"fn","concat"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      true, GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(fn_string_join,
     (createQName(XQUERY_FN_NS,"fn","string-join"),
      GENV_TYPESYSTEM.STRING_TYPE_STAR,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(fn_substring,
     (createQName(XQUERY_FN_NS,"fn","substring"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(fn_substring,
     (createQName(XQUERY_FN_NS,"fn","substring"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(fn_string_length,
     (createQName(XQUERY_FN_NS,"fn","string-length"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_ONE));

DECL(fn_normalize_space,
     (createQName(XQUERY_FN_NS,"fn","normalize-space"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(fn_normalize_unicode,
     (createQName(XQUERY_FN_NS,"fn","normalize-unicode"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(fn_normalize_unicode,
     (createQName(XQUERY_FN_NS,"fn","normalize-unicode"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(fn_upper_case,
     (createQName(XQUERY_FN_NS,"fn","upper-case"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(fn_lower_case,
     (createQName(XQUERY_FN_NS,"fn","lower-case"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(fn_translate,
     (createQName(XQUERY_FN_NS,"fn","translate"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(fn_encode_for_uri,
     (createQName(XQUERY_FN_NS,"fn","encode-for-uri"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(fn_iri_to_uri,
     (createQName(XQUERY_FN_NS,"fn","iri-to-uri"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(fn_escape_html_uri,
     (createQName(XQUERY_FN_NS,"fn","escape-html-uri"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(fn_contains,
     (createQName(XQUERY_FN_NS,"fn","contains"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));
      
DECL(fn_contains,
     (createQName(XQUERY_FN_NS,"fn","contains"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(fn_starts_with,
     (createQName(XQUERY_FN_NS,"fn","starts-with"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(fn_starts_with,
     (createQName(XQUERY_FN_NS,"fn","starts-with"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(fn_ends_with,
     (createQName(XQUERY_FN_NS,"fn","ends-with"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(fn_ends_with,
     (createQName(XQUERY_FN_NS,"fn","ends-with"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(fn_substring_before,
     (createQName(XQUERY_FN_NS,"fn","substring-before"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(fn_substring_before,
     (createQName(XQUERY_FN_NS,"fn","substring-before"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(fn_substring_after,
     (createQName(XQUERY_FN_NS,"fn","substring-after"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(fn_substring_after,
     (createQName(XQUERY_FN_NS,"fn","substring-after"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(fn_matches,
     (createQName(XQUERY_FN_NS,"fn","matches"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(fn_matches,
     (createQName(XQUERY_FN_NS,"fn","matches"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(fn_replace,
     (createQName(XQUERY_FN_NS,"fn","replace"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(fn_replace,
     (createQName(XQUERY_FN_NS,"fn","replace"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(fn_tokenize,
     (createQName(XQUERY_FN_NS,"fn","tokenize"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_STAR));

DECL(fn_tokenize,
     (createQName(XQUERY_FN_NS,"fn","tokenize"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_STAR));
// end Strings

}
void BuiltinFunctionLibrary::populateContext_Boolean(static_context *sctx)
{
// start Boolean
DECL(fn_true,
     (createQName(XQUERY_FN_NS,"fn","true"),
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(fn_false,
     (createQName(XQUERY_FN_NS,"fn","false"),
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(fn_boolean,
     (createQName(XQUERY_FN_NS,"fn","boolean"),
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(fn_not,
     (createQName(XQUERY_FN_NS,"fn","not"),
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));
// end Boolean

// start Logic
DECL(op_and,
     (createQName(XQUERY_OP_NS,"fn", ":and"),
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      true, GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(op_or,
     (createQName(XQUERY_OP_NS,"fn", ":or"),
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      true, GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));
// end Logic

}
void BuiltinFunctionLibrary::populateContext_Constructors(static_context *sctx)
{
// begin constructors
DECL(op_enclosed_expr,
     (createQName(XQUERY_OP_NS,"fn", ":enclosed-expr"),
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));
// end constructors

}
void BuiltinFunctionLibrary::populateContext_Datetime(static_context *sctx)
{
// begin date time
DECL(fn_datetime_ctor,
     (createQName(XQUERY_OP_NS,"fn", "dateTime"),
      GENV_TYPESYSTEM.DATE_TYPE_QUESTION,
      GENV_TYPESYSTEM.TIME_TYPE_QUESTION,
      GENV_TYPESYSTEM.DATETIME_TYPE_QUESTION));

DECL(fn_years_from_duration,
     (createQName(XQUERY_FN_NS,"fn", "years-from-duration"),
      GENV_TYPESYSTEM.DURATION_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION));

DECL(fn_months_from_duration,
     (createQName(XQUERY_FN_NS,"fn", "months-from-duration"),
      GENV_TYPESYSTEM.DURATION_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION));

DECL(fn_days_from_duration,
     (createQName(XQUERY_FN_NS,"fn", "days-from-duration"),
      GENV_TYPESYSTEM.DURATION_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION));

DECL(fn_hours_from_duration,
     (createQName(XQUERY_FN_NS,"fn", "hours-from-duration"),
      GENV_TYPESYSTEM.DURATION_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION));

DECL(fn_minutes_from_duration,
     (createQName(XQUERY_FN_NS,"fn", "minutes-from-duration"),
      GENV_TYPESYSTEM.DURATION_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION));

DECL(fn_seconds_from_duration,
     (createQName(XQUERY_FN_NS,"fn", "seconds-from-duration"),
      GENV_TYPESYSTEM.DURATION_TYPE_QUESTION,
      GENV_TYPESYSTEM.DECIMAL_TYPE_QUESTION));

DECL(fn_year_from_datetime,
     (createQName(XQUERY_FN_NS,"fn", "year-from-dateTime"),
      GENV_TYPESYSTEM.DATETIME_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION));

DECL(fn_month_from_datetime,
     (createQName(XQUERY_FN_NS,"fn", "month-from-dateTime"),
      GENV_TYPESYSTEM.DATETIME_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION));

DECL(fn_day_from_datetime,
     (createQName(XQUERY_FN_NS,"fn", "day-from-dateTime"),
      GENV_TYPESYSTEM.DATETIME_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION));

DECL(fn_hours_from_datetime,
     (createQName(XQUERY_FN_NS,"fn", "hours-from-dateTime"),
      GENV_TYPESYSTEM.DATETIME_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION));

DECL(fn_minutes_from_datetime,
     (createQName(XQUERY_FN_NS,"fn", "minutes-from-dateTime"),
      GENV_TYPESYSTEM.DATETIME_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION));

DECL(fn_seconds_from_datetime,
     (createQName(XQUERY_FN_NS,"fn", "seconds-from-dateTime"),
      GENV_TYPESYSTEM.DATETIME_TYPE_QUESTION,
      GENV_TYPESYSTEM.DECIMAL_TYPE_QUESTION));

DECL(fn_timezone_from_datetime,
     (createQName(XQUERY_FN_NS,"fn", "timezone-from-dateTime"),
      GENV_TYPESYSTEM.DATETIME_TYPE_QUESTION,
      GENV_TYPESYSTEM.DURATION_TYPE_QUESTION));

DECL(fn_year_from_date,
     (createQName(XQUERY_FN_NS,"fn", "year-from-date"),
      GENV_TYPESYSTEM.DATE_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION));

DECL(fn_month_from_date,
     (createQName(XQUERY_FN_NS,"fn", "month-from-date"),
      GENV_TYPESYSTEM.DATE_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION));

DECL(fn_day_from_date,
     (createQName(XQUERY_FN_NS,"fn", "day-from-date"),
      GENV_TYPESYSTEM.DATE_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION));

DECL(fn_timezone_from_date,
     (createQName(XQUERY_FN_NS,"fn", "timezone-from-date"),
      GENV_TYPESYSTEM.DATE_TYPE_QUESTION,
      GENV_TYPESYSTEM.DURATION_TYPE_QUESTION));

DECL(fn_hours_from_time,
     (createQName(XQUERY_FN_NS,"fn", "hours-from-time"),
      GENV_TYPESYSTEM.TIME_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION));

DECL(fn_minutes_from_time,
     (createQName(XQUERY_FN_NS,"fn", "minutes-from-time"),
      GENV_TYPESYSTEM.TIME_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION));

DECL(fn_seconds_from_time,
     (createQName(XQUERY_FN_NS,"fn", "seconds-from-time"),
      GENV_TYPESYSTEM.TIME_TYPE_QUESTION,
      GENV_TYPESYSTEM.DECIMAL_TYPE_QUESTION));

DECL(fn_timezone_from_time,
     (createQName(XQUERY_FN_NS,"fn", "timezone-from-time"),
      GENV_TYPESYSTEM.TIME_TYPE_QUESTION,
      GENV_TYPESYSTEM.DURATION_TYPE_QUESTION));

DECL(op_ym_durations_add,
     (createQName (XQUERY_FN_NS,"fn", "add-yearMonthDurations"),
      GENV_TYPESYSTEM.YM_DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.YM_DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.YM_DURATION_TYPE_ONE));

DECL(op_dt_durations_add,
     (createQName (XQUERY_FN_NS,"fn", "add-dayTimeDurations"),
      GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE));

DECL(op_ym_durations_subtract,
     (createQName (XQUERY_FN_NS,"fn", "subtract-yearMonthDurations"),
      GENV_TYPESYSTEM.YM_DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.YM_DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.YM_DURATION_TYPE_ONE));

DECL(op_dt_durations_subtract,
     (createQName (XQUERY_FN_NS,"fn", "subtract-dayTimeDurations"),
      GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE));

DECL(op_ym_durations_multiply,
     (createQName (XQUERY_FN_NS,"fn", "multiply-yearMonthDuration"),
      GENV_TYPESYSTEM.YM_DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
      GENV_TYPESYSTEM.YM_DURATION_TYPE_ONE));

DECL(op_dt_durations_multiply,
     (createQName (XQUERY_FN_NS,"fn", "multiply-dayTimeDuration"),
      GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
      GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE));

DECL(op_ym_durations_divide,
     (createQName (XQUERY_FN_NS,"fn", "divide-yearMonthDuration"),
      GENV_TYPESYSTEM.YM_DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
      GENV_TYPESYSTEM.YM_DURATION_TYPE_ONE));

DECL(op_dt_durations_divide,
     (createQName (XQUERY_FN_NS,"fn", "divide-dayTimeDuration"),
      GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
      GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE));

DECL(op_divide_ymd_by_ymd,
     (createQName (XQUERY_FN_NS,"fn", "divide-yearMonthDuration-by-yearMonthDuration"),
      GENV_TYPESYSTEM.YM_DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.YM_DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DECIMAL_TYPE_ONE));

DECL(op_divide_dtd_by_dtd,
     (createQName (XQUERY_FN_NS,"fn", "divide-dayTimeDuration-by-dayTimeDuration"),
      GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DECIMAL_TYPE_ONE));

 //TODO change the returned type to DT_DURATION_TYPE_QUESTION
DECL(op_sub_dt,
     (createQName (XQUERY_FN_NS,"fn", "subtract-dateTimes"),
      GENV_TYPESYSTEM.DATETIME_TYPE_ONE,
      GENV_TYPESYSTEM.DATETIME_TYPE_ONE,
      GENV_TYPESYSTEM.DURATION_TYPE_QUESTION));

 //TODO change the returned type to DT_DURATION_TYPE_QUESTION
DECL(op_sub_d,
     (createQName (XQUERY_FN_NS,"fn", "subtract-dates"),
      GENV_TYPESYSTEM.DATE_TYPE_ONE,
      GENV_TYPESYSTEM.DATE_TYPE_ONE,
      GENV_TYPESYSTEM.DURATION_TYPE_QUESTION));

 //TODO change the returned type to DT_DURATION_TYPE_QUESTION
DECL(op_sub_t,
     (createQName (XQUERY_FN_NS,"fn", "subtract-times"),
      GENV_TYPESYSTEM.TIME_TYPE_ONE,
      GENV_TYPESYSTEM.TIME_TYPE_ONE,
      GENV_TYPESYSTEM.DURATION_TYPE_QUESTION));

 //TODO change the type of the second arg to YM_DURATION_TYPE_ONE
DECL(op_add_ymd_to_dt,
     (createQName (XQUERY_FN_NS,"fn", "add-yearMonthDuration-to-dateTime"),
      GENV_TYPESYSTEM.DATETIME_TYPE_ONE,
      GENV_TYPESYSTEM.DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DATETIME_TYPE_ONE));

 //TODO change the type of the second arg to DT_DURATION_TYPE_ONE
DECL(op_add_dtd_to_dt,
     (createQName (XQUERY_FN_NS,"fn", "add-dayTimeDuration-to-dateTime"),
      GENV_TYPESYSTEM.DATETIME_TYPE_ONE,
      GENV_TYPESYSTEM.DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DATETIME_TYPE_ONE));

 //TODO change the type of the second arg to YM_DURATION_TYPE_ONE
DECL(op_sub_ymd_from_dt,
     (createQName (XQUERY_FN_NS,"fn", "subtract-yearMonthDuration-from-dateTime"),
      GENV_TYPESYSTEM.DATETIME_TYPE_ONE,
      GENV_TYPESYSTEM.DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DATETIME_TYPE_ONE));

 //TODO change the type of the second arg to DT_DURATION_TYPE_ONE
DECL(op_sub_dtd_from_dt,
     (createQName (XQUERY_FN_NS,"fn", "subtract-dayTimeDuration-from-dateTime"),
      GENV_TYPESYSTEM.DATETIME_TYPE_ONE,
      GENV_TYPESYSTEM.DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DATETIME_TYPE_ONE));

 //TODO change the type of the second arg to YM_DURATION_TYPE_ONE
DECL(op_add_ymd_to_d,
     (createQName (XQUERY_FN_NS,"fn", "add-yearMonthDuration-to-date"),
      GENV_TYPESYSTEM.DATE_TYPE_ONE,
      GENV_TYPESYSTEM.DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DATE_TYPE_ONE));

 //TODO change the type of the second arg to DT_DURATION_TYPE_ONE
DECL(op_add_dtd_to_d,
     (createQName (XQUERY_FN_NS,"fn", "add-dayTimeDuration-to-date"),
      GENV_TYPESYSTEM.DATE_TYPE_ONE,
      GENV_TYPESYSTEM.DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DATE_TYPE_ONE));

 //TODO change the type of the second arg to YM_DURATION_TYPE_ONE
DECL(op_sub_ymd_from_d,
     (createQName (XQUERY_FN_NS,"fn", "subtract-yearMonthDuration-from-date"),
      GENV_TYPESYSTEM.DATE_TYPE_ONE,
      GENV_TYPESYSTEM.DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DATE_TYPE_ONE));

 //TODO change the type of the second arg to DT_DURATION_TYPE_ONE
DECL(op_sub_dtd_from_d,
     (createQName (XQUERY_FN_NS,"fn", "subtract-dayTimeDuration-from-date"),
      GENV_TYPESYSTEM.DATE_TYPE_ONE,
      GENV_TYPESYSTEM.DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DATE_TYPE_ONE));

 //TODO change the type of the second arg to DT_DURATION_TYPE_ONE
DECL(op_add_dtd_to_t,
     (createQName (XQUERY_FN_NS,"fn", "add-dayTimeDuration-to-time"),
      GENV_TYPESYSTEM.TIME_TYPE_ONE,
      GENV_TYPESYSTEM.DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.TIME_TYPE_ONE));

 //TODO change the type of the second arg to DT_DURATION_TYPE_ONE
DECL(op_sub_dtd_from_t,
     (createQName (XQUERY_FN_NS,"fn", "subtract-dayTimeDuration-from-time"),
      GENV_TYPESYSTEM.TIME_TYPE_ONE,
      GENV_TYPESYSTEM.DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.TIME_TYPE_ONE));

DECL(fn_adjust_dt_to_tz_1,
     (createQName (XQUERY_FN_NS,"fn", "adjust-dateTime-to-timezone"),
      GENV_TYPESYSTEM.DATETIME_TYPE_QUESTION,
      GENV_TYPESYSTEM.DATETIME_TYPE_QUESTION));

DECL(fn_adjust_dt_to_tz_2,
     (createQName (XQUERY_FN_NS,"fn", "adjust-dateTime-to-timezone"),
      GENV_TYPESYSTEM.DATETIME_TYPE_QUESTION,
      GENV_TYPESYSTEM.DT_DURATION_TYPE_QUESTION,
      GENV_TYPESYSTEM.DATETIME_TYPE_QUESTION));

DECL(fn_adjust_d_to_tz_1,
     (createQName (XQUERY_FN_NS,"fn", "adjust-date-to-timezone"),
      GENV_TYPESYSTEM.DATE_TYPE_QUESTION,
      GENV_TYPESYSTEM.DATE_TYPE_QUESTION));

DECL(fn_adjust_d_to_tz_2,
     (createQName (XQUERY_FN_NS,"fn", "adjust-date-to-timezone"),
      GENV_TYPESYSTEM.DATE_TYPE_QUESTION,
      GENV_TYPESYSTEM.DT_DURATION_TYPE_QUESTION,
      GENV_TYPESYSTEM.DATE_TYPE_QUESTION));

DECL(fn_adjust_t_to_tz_1,
     (createQName (XQUERY_FN_NS,"fn", "adjust-time-to-timezone"),
      GENV_TYPESYSTEM.TIME_TYPE_QUESTION,
      GENV_TYPESYSTEM.TIME_TYPE_QUESTION));

DECL(fn_adjust_t_to_tz_2,
     (createQName (XQUERY_FN_NS,"fn", "adjust-time-to-timezone"),
      GENV_TYPESYSTEM.TIME_TYPE_QUESTION,
      GENV_TYPESYSTEM.DT_DURATION_TYPE_QUESTION,
      GENV_TYPESYSTEM.TIME_TYPE_QUESTION));
  
// end date time

}
void BuiltinFunctionLibrary::populateContext_Debug(static_context *sctx)
{
// begin debug functions
DECL(fn_trace_func,
     (createQName(XQUERY_FN_NS,"fn","trace"),
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));
// end debug functions


}
void BuiltinFunctionLibrary::populateContext_Zorba(static_context *sctx)
{
// begin zorba functions

DECL(zor_numgen,
     (createQName(XQUERY_FN_NS,"fn", "zorba:numgen"),
      GENV_TYPESYSTEM.DECIMAL_TYPE_ONE));

DECL(node_reference,
     (createQName(ZORBA_FN_NS, "fn-zorba", "node-reference"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_URI_TYPE_ONE));

DECL(node_by_reference,
     (createQName(ZORBA_FN_NS, "fn-zorba", "node-by-reference"),
      GENV_TYPESYSTEM.ANY_URI_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION));

// end zorba functions

#ifdef ZORBA_WITH_REST
// zorba-rest functions
DECL(rest_get_1,
     (createQName(ZORBA_REST_FN_NS, "fn-zorba-rest", "get"),
     GENV_TYPESYSTEM.STRING_TYPE_ONE, // need to make this an ANY_URI_TYPE_ONE
     GENV_TYPESYSTEM.ITEM_TYPE_STAR));

// DECL(rest_get_2,
//      (createQName("http://www.flworfound.org/", "zorba-rest", "get"),
//      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));
#endif

// begin context functions
DECL(ctx_variable,
     (createQName(XQUERY_FN_NS,"fn", ":ctxvariable"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));
DECL(ctx_var_assign,
     (createQName(XQUERY_FN_NS,"fn", ":ctxvar-assign"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.EMPTY_TYPE));
// end context functions

DECL(fn_sqrt,
     (createQName(ZORBA_MATH_FN_NS,"fn-zorba-math", "sqrt"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));
}

} /* namespace zorba */
