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

#include "functions/library.h"
#include "functions/function.h"
#include "functions/signature.h"

#include "functions/Accessors.h"
#include "functions/Collections.h"
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

#include "types/node_test.h"

using namespace std;
namespace zorba {

// clear static initializer state

// dummy function to tell the windows linker to keep the library.obj
// even though it contains no public objects or functions
// this is called at initializeZorba
void library_init()
{}

void BuiltinFunctionLibrary::populateContext(static_context *sctx)
{
  populateContext_Accesors(sctx);
  populateContext_Error(sctx);
  populateContext_Nodes(sctx);
  populateContext_AnyURI(sctx);
  populateContext_Arithmetics(sctx);
  populateContext_Numerics(sctx);
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
DECL(sctx, fn_data_func,
     (createQName (XQUERY_FN_NS, "fn", "data"),
      GENV_TYPESYSTEM.ITEM_TYPE_STAR, GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR));

DECL(sctx, fn_root_func,
     (createQName(XQUERY_FN_NS, "fn", "root"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION, GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION));

DECL(sctx, fn_nodename_func,
     (createQName(XQUERY_FN_NS, "fn", "node-name"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION, GENV_TYPESYSTEM.QNAME_TYPE_QUESTION));

DECL(sctx, fn_nilled_func,
     (createQName(XQUERY_FN_NS, "fn", "nilled"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION, GENV_TYPESYSTEM.BOOLEAN_TYPE_QUESTION));

DECL(sctx, fn_base_uri_func,
     (createQName(XQUERY_FN_NS, "fn", "base-uri"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION, GENV_TYPESYSTEM.ANY_URI_TYPE_QUESTION));

DECL(sctx, fn_document_uri_func,
     (createQName(XQUERY_FN_NS, "fn", "document-uri"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION, GENV_TYPESYSTEM.ANY_URI_TYPE_QUESTION));

DECL(sctx, fn_name_func,
     (createQName(XQUERY_FN_NS, "fn", "name"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION, GENV_TYPESYSTEM.STRING_TYPE_ONE));
// end Accessors

}
void BuiltinFunctionLibrary::populateContext_Error(static_context *sctx)
{
//begin Error function
DECL(sctx, fn_error,
     (createQName(XQUERY_FN_NS, "fn", "error"),
      GENV_TYPESYSTEM.NONE_TYPE));

DECL(sctx, fn_error,
     (createQName(XQUERY_FN_NS, "fn", "error"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.NONE_TYPE));

DECL(sctx, fn_error,
     (createQName(XQUERY_FN_NS, "fn", "error"),
      GENV_TYPESYSTEM.QNAME_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.NONE_TYPE));

DECL(sctx, fn_error,
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
DECL(sctx, fn_local_name,
     (createQName(XQUERY_FN_NS, "fn", "local-name"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(sctx, fn_namespace_uri,
     (createQName(XQUERY_FN_NS, "fn", "namespace-uri"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_URI_TYPE_ONE));

DECL(sctx, fn_lang,
     (createQName(XQUERY_FN_NS, "fn", "lang"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(sctx, fn_collection,
     (createQName(XQUERY_FN_NS, "fn", "collection"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));

DECL(sctx, fn_collection,
     (createQName(XQUERY_FN_NS, "fn", "collection"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));
//end functions on nodes


}
void BuiltinFunctionLibrary::populateContext_AnyURI(static_context *sctx)
{
//begin functions on AnyURI

// resolve-uri / 1 handled by translator

 DECL(sctx, fn_resolve_uri,
     (createQName(XQUERY_FN_NS, "fn", "resolve-uri"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_URI_TYPE_QUESTION));
//end functions on Any URI


}
void BuiltinFunctionLibrary::populateContext_Context(static_context *sctx)
{
// begin context functions
//position(), last() and static-base-uri() are implemented in the context
DECL(sctx, fn_current_dateTime,
     (createQName(XQUERY_FN_NS,"fn","current-dateTime"),
      GENV_TYPESYSTEM.DATETIME_TYPE_ONE));

DECL(sctx, fn_current_date,
     (createQName(XQUERY_FN_NS,"fn","current-date"),
      GENV_TYPESYSTEM.DATE_TYPE_ONE));

DECL(sctx, fn_current_time,
     (createQName(XQUERY_FN_NS,"fn","current-time"),
      GENV_TYPESYSTEM.TIME_TYPE_ONE));

DECL(sctx, fn_implicit_timezone,
     (createQName(XQUERY_FN_NS,"fn","implicit-timezone"),
      GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE));

DECL(sctx, fn_default_collation,
     (createQName(XQUERY_FN_NS,"fn","default-collation"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE));
// end context functions


}
void BuiltinFunctionLibrary::populateContext_QNames(static_context *sctx)
{
//QNames
// rchandle<NodeTest> nodeTest;
// nodeTest = new NodeTest(store::StoreConsts::elementNode);

DECL(sctx, fn_resolve_qname,
     (createQName(XQUERY_FN_NS, "fn",  "resolve-QName"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE,
      GENV_TYPESYSTEM.QNAME_TYPE_QUESTION));
      
DECL(sctx, fn_qname,
     (createQName(XQUERY_FN_NS, "fn", "QName"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.QNAME_TYPE_ONE));

DECL(sctx, op_qname_equal,
     (createQName(XQUERY_FN_NS,"fn","QName-equal"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(sctx, fn_prefix_from_qname,
     (createQName(XQUERY_FN_NS,"fn","prefix-from-QName"),
      GENV_TYPESYSTEM.QNAME_TYPE_QUESTION,
      GENV_TYPESYSTEM.NCNAME_TYPE_QUESTION));

DECL(sctx, fn_local_name_from_qname,
     (createQName(XQUERY_FN_NS,"fn","local-name-from-QName"),
      GENV_TYPESYSTEM.QNAME_TYPE_QUESTION,
      GENV_TYPESYSTEM.NCNAME_TYPE_QUESTION));

DECL(sctx, fn_namespace_uri_from_qname,
     (createQName(XQUERY_FN_NS,"fn","namespace-uri-from-QName"),
      GENV_TYPESYSTEM.QNAME_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_URI_TYPE_QUESTION));

DECL(sctx, fn_namespace_uri_for_prefix,
     (createQName(XQUERY_FN_NS,"fn","namespace-uri-for-prefix"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_URI_TYPE_QUESTION));

DECL(sctx, fn_in_scope_prefixes,
     (createQName(XQUERY_FN_NS,"fn","in-scope-prefixes"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_STAR));
// end QNames

}
void BuiltinFunctionLibrary::populateContext_Sequences(static_context *sctx)
{
// Sequences
DECL(sctx, fn_doc_func,
     (createQName(XQUERY_FN_NS,"fn","doc"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.DOCUMENT_TYPE_QUESTION));

DECL(sctx, fn_doc_available_func,
     (createQName(XQUERY_FN_NS,"fn","doc-available"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(sctx, op_concatenate,
     (createQName(XQUERY_FN_NS,"fn",":concatenate"),
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      true, GENV_TYPESYSTEM.ITEM_TYPE_STAR));

DECL(sctx, fn_exists,
    (createQName(XQUERY_FN_NS,"fn","exists"),
    GENV_TYPESYSTEM.ITEM_TYPE_STAR,
    GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(sctx, fn_empty,
    (createQName(XQUERY_FN_NS,"fn","empty"),
    GENV_TYPESYSTEM.ITEM_TYPE_STAR,
    GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(sctx, fn_index_of,
    (createQName(XQUERY_FN_NS,"fn","index-of"),
    GENV_TYPESYSTEM.ITEM_TYPE_STAR,
    GENV_TYPESYSTEM.ITEM_TYPE_ONE,
    GENV_TYPESYSTEM.INTEGER_TYPE_STAR));

DECL(sctx, fn_index_of,
    (createQName(XQUERY_FN_NS,"fn","index-of"),
    GENV_TYPESYSTEM.ITEM_TYPE_STAR,
    GENV_TYPESYSTEM.ITEM_TYPE_ONE,
    GENV_TYPESYSTEM.STRING_TYPE_ONE,
    GENV_TYPESYSTEM.INTEGER_TYPE_STAR));

DECL(sctx, fn_remove,
    (createQName(XQUERY_FN_NS,"fn","remove"),
    GENV_TYPESYSTEM.ITEM_TYPE_STAR,
    GENV_TYPESYSTEM.INTEGER_TYPE_ONE,
    GENV_TYPESYSTEM.ITEM_TYPE_STAR));

DECL(sctx, fn_reverse,
    (createQName(XQUERY_FN_NS,"fn","reverse"),
    GENV_TYPESYSTEM.ITEM_TYPE_STAR,
    GENV_TYPESYSTEM.ITEM_TYPE_STAR));

DECL(sctx, fn_distinct_values,
    (createQName(XQUERY_FN_NS,"fn","distinct-values"),
    GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR, 
    GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR));

DECL(sctx, fn_distinct_values,
    (createQName(XQUERY_FN_NS,"fn","distinct-values"),
    GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR, 
    GENV_TYPESYSTEM.STRING_TYPE_ONE,
    GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR));

DECL(sctx, fn_insert_before,
    (createQName(XQUERY_FN_NS,"fn","insert-before"),
    GENV_TYPESYSTEM.ITEM_TYPE_STAR,
    GENV_TYPESYSTEM.INTEGER_TYPE_ONE,    
    GENV_TYPESYSTEM.ITEM_TYPE_STAR,
    GENV_TYPESYSTEM.ITEM_TYPE_STAR));

DECL(sctx, fn_subsequence,
    (createQName(XQUERY_FN_NS,"fn","subsequence"),
    GENV_TYPESYSTEM.ITEM_TYPE_STAR,
    GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,    
    GENV_TYPESYSTEM.ITEM_TYPE_STAR));

DECL(sctx, fn_subsequence,
    (createQName(XQUERY_FN_NS,"fn","subsequence"),
    GENV_TYPESYSTEM.ITEM_TYPE_STAR,
    GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
    GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
    GENV_TYPESYSTEM.ITEM_TYPE_STAR));

DECL(sctx, fn_zero_or_one,
    (createQName(XQUERY_FN_NS,"fn","zero-or-one"),
    GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
    GENV_TYPESYSTEM.ITEM_TYPE_QUESTION));

DECL(sctx, fn_one_or_more,
    (createQName(XQUERY_FN_NS,"fn","one-or-more"),
    GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
    GENV_TYPESYSTEM.ITEM_TYPE_PLUS));

DECL(sctx, fn_exactly_one,
    (createQName(XQUERY_FN_NS,"fn","exactly-one"),
    GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
    GENV_TYPESYSTEM.ITEM_TYPE_ONE));

DECL(sctx, fn_exactly_one_noraise,
    (createQName(XQUERY_FN_NS,"fn",":exactly-one-noraise"),
    GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
    GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(sctx, fn_count,
    (createQName(XQUERY_FN_NS,"fn","count"),
    GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
    GENV_TYPESYSTEM.INTEGER_TYPE_ONE));

DECL(sctx, fn_avg,
    (createQName(XQUERY_FN_NS,"fn","avg"),
    GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR, 
    GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(sctx, fn_max_1,
    (createQName(XQUERY_FN_NS,"fn","max"),
    GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR, 
    GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(sctx, fn_max_2,
    (createQName(XQUERY_FN_NS,"fn","max"),
    GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR, 
    GENV_TYPESYSTEM.STRING_TYPE_ONE, 
    GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(sctx, fn_min_1,
    (createQName(XQUERY_FN_NS,"fn","min"),
    GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR, 
    GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(sctx, fn_min_2,
    (createQName(XQUERY_FN_NS,"fn","min"),
    GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR, 
    GENV_TYPESYSTEM.STRING_TYPE_ONE, 
    GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(sctx, fn_sum,
    (createQName(XQUERY_FN_NS,"fn","sum"),
    GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR, 
    GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(sctx, fn_sum,
    (createQName(XQUERY_FN_NS,"fn","sum"),
    GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR, 
    GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION, 
    GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(sctx, op_to,
    (createQName(XQUERY_FN_NS,"fn",":to"),
    GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION, 
    GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION, 
    GENV_TYPESYSTEM.INTEGER_TYPE_STAR));

DECL(sctx, fn_id,
     (createQName(XQUERY_FN_NS,"fn","id"),
      GENV_TYPESYSTEM.STRING_TYPE_STAR,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR)
    );

DECL(sctx, fn_id_ref,
     (createQName(XQUERY_FN_NS,"fn","idref"),
      GENV_TYPESYSTEM.STRING_TYPE_STAR,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));

DECL(sctx, fn_unordered,
  (createQName(XQUERY_FN_NS,"fn","unordered"),
  GENV_TYPESYSTEM.ITEM_TYPE_STAR,
  GENV_TYPESYSTEM.ITEM_TYPE_STAR));

DECL(sctx, op_either_nodes_or_atomics,
  (createQName(XQUERY_FN_NS,"fn",":either-nodes-or-atomics"),
  GENV_TYPESYSTEM.ITEM_TYPE_STAR,
  GENV_TYPESYSTEM.ITEM_TYPE_STAR));

DECL(sctx, op_distinct_nodes,
  (createQName(XQUERY_FN_NS,"fn",":distinct-nodes"),
  GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
  GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));

DECL(sctx, op_distinct_nodes_or_atomics,
  (createQName(XQUERY_FN_NS,"fn",":distinct-nodes-or-atomics"),
  GENV_TYPESYSTEM.ITEM_TYPE_STAR,
  GENV_TYPESYSTEM.ITEM_TYPE_STAR));

DECL(sctx, op_sort_nodes_ascending,
  (createQName(XQUERY_FN_NS,"fn",":sort-nodes-ascending"),
  GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
  GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));

DECL(sctx, op_sort_nodes_asc_or_atomics,
  (createQName(XQUERY_FN_NS,"fn",":sort-nodes-asc-or-atomics"),
  GENV_TYPESYSTEM.ITEM_TYPE_STAR,
  GENV_TYPESYSTEM.ITEM_TYPE_STAR));

DECL(sctx, op_sort_nodes_descending,
  (createQName(XQUERY_FN_NS,"fn",":sort-nodes-descending"),
  GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
  GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));

DECL(sctx, op_sort_nodes_desc_or_atomics,
  (createQName(XQUERY_FN_NS,"fn",":sort-nodes-desc-or-atomics"),
  GENV_TYPESYSTEM.ITEM_TYPE_STAR,
  GENV_TYPESYSTEM.ITEM_TYPE_STAR));

DECL(sctx, op_sort_distinct_nodes_ascending,
  (createQName(XQUERY_FN_NS,"fn",":sort-distinct-nodes-ascending"),
  GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
  GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));

DECL(sctx, op_sort_distinct_nodes_asc_or_atomics,
  (createQName(XQUERY_FN_NS,"fn",":sort-distinct-nodes-asc-or-atomics"),
  GENV_TYPESYSTEM.ITEM_TYPE_STAR,
  GENV_TYPESYSTEM.ITEM_TYPE_STAR));

DECL(sctx, op_sort_distinct_nodes_descending,
  (createQName(XQUERY_FN_NS,"fn",":sort-distinct-nodes-descending"),
  GENV_TYPESYSTEM.ITEM_TYPE_STAR,
  GENV_TYPESYSTEM.ITEM_TYPE_STAR));

// TODO: separate function
DECL(sctx, op_sort_distinct_nodes_descending,
  (createQName(XQUERY_FN_NS,"fn",":sort-distinct-nodes-desc-or-atomics"),
  GENV_TYPESYSTEM.ITEM_TYPE_STAR,
  GENV_TYPESYSTEM.ITEM_TYPE_STAR));

  DECL(sctx, fn_union,
  (createQName(XQUERY_FN_NS,"fn",":union"),
   GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR, GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
   GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));

  DECL(sctx, fn_intersect,
  (createQName(XQUERY_FN_NS,"fn",":intersect"),
   GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR, GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
   GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));

  DECL(sctx, fn_except,
  (createQName(XQUERY_FN_NS,"fn",":except"),
   GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR, GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
   GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));
  
DECL(sctx, fn_deep_equal,
  (createQName(XQUERY_FN_NS, "fn", "deep-equal"),
  GENV_TYPESYSTEM.ITEM_TYPE_STAR,
  GENV_TYPESYSTEM.ITEM_TYPE_STAR,
  GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(sctx, fn_deep_equal,
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
DECL(sctx, op_equal,
     (createQName(XQUERY_OP_NS,"fn", ":equal"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(sctx, op_not_equal,
     (createQName(XQUERY_OP_NS,"fn", ":not-equal"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(sctx, op_greater,
     (createQName(XQUERY_OP_NS,"fn", ":greater"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(sctx, op_greater_equal,
     (createQName(XQUERY_OP_NS,"fn", ":greater-equal"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(sctx, op_less,
     (createQName(XQUERY_OP_NS,"fn", ":less"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(sctx, op_less_equal,
     (createQName(XQUERY_OP_NS,"fn", ":less-equal"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));
// end Generic Comparison

// Value Comparison
DECL(sctx, op_value_equal,
     (createQName(XQUERY_FN_NS,"fn", ":value-equal"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_QUESTION));

DECL(sctx, op_value_not_equal,
     (createQName(XQUERY_FN_NS,"fn", ":value-not-equal"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_QUESTION));

DECL(sctx, op_value_greater,
     (createQName(XQUERY_FN_NS,"fn", ":value-greater"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_QUESTION));

DECL(sctx, op_value_greater_equal,
     (createQName(XQUERY_FN_NS,"fn", ":value-greater-equal"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_QUESTION));

DECL(sctx, op_value_less,
     (createQName(XQUERY_FN_NS,"fn", ":value-less"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_QUESTION));

DECL(sctx, op_value_less_equal,
     (createQName(XQUERY_FN_NS,"fn", ":value-less-equal"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_QUESTION));
// end Value Comparison

// Node Comparison
DECL(sctx, op_is_same_node,
     (createQName(XQUERY_FN_NS,"fn", ":is-same-node"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_QUESTION));

DECL(sctx, op_node_before,
     (createQName(XQUERY_FN_NS,"fn", ":node-before"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_QUESTION));

DECL(sctx, op_node_after,
     (createQName(XQUERY_FN_NS,"fn", ":node-after"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_QUESTION));

// end Node Comparson

}

void BuiltinFunctionLibrary::populateContext_Boolean(static_context *sctx)
{
// start Boolean
DECL(sctx, fn_true,
     (createQName(XQUERY_FN_NS,"fn","true"),
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(sctx, fn_false,
     (createQName(XQUERY_FN_NS,"fn","false"),
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(sctx, fn_boolean,
     (createQName(XQUERY_FN_NS,"fn","boolean"),
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(sctx, fn_not,
     (createQName(XQUERY_FN_NS,"fn","not"),
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));
// end Boolean

// start Logic
DECL(sctx, op_and,
     (createQName(XQUERY_OP_NS,"fn", ":and"),
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      true, GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(sctx, op_or,
     (createQName(XQUERY_OP_NS,"fn", ":or"),
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      true, GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));
// end Logic

}
void BuiltinFunctionLibrary::populateContext_Constructors(static_context *sctx)
{
// begin constructors
DECL(sctx, op_enclosed_expr,
     (createQName(XQUERY_OP_NS,"fn", ":enclosed-expr"),
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));
// end constructors

}

void BuiltinFunctionLibrary::populateContext_Debug(static_context *sctx)
{
// begin debug functions
DECL(sctx, fn_trace_func,
     (createQName(XQUERY_FN_NS,"fn","trace"),
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));

DECL (sctx, fn_read_string,
      (createQName (ZORBA_FN_NS, "fn-zorba", "read-line"),
       GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL (sctx, fn_print,
      (createQName (ZORBA_FN_NS, "fn-zorba", "print"),
       GENV_TYPESYSTEM.ITEM_TYPE_STAR,
       GENV_TYPESYSTEM.NONE_TYPE));

// end debug functions


}
void BuiltinFunctionLibrary::populateContext_Zorba(static_context *sctx)
{
// begin zorba functions

DECL(sctx, zor_numgen,
     (createQName(XQUERY_FN_NS,"fn", "zorba:numgen"),
      GENV_TYPESYSTEM.DECIMAL_TYPE_ONE));

DECL(sctx, node_reference,
     (createQName(ZORBA_NODEREF_FN_NS, "fn-zorba", "node-reference"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_URI_TYPE_ONE));

DECL(sctx, node_by_reference,
     (createQName(ZORBA_NODEREF_FN_NS, "fn-zorba", "node-by-reference"),
      GENV_TYPESYSTEM.ANY_URI_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION));

// end zorba functions

#ifdef ZORBA_WITH_REST

// zorba-rest functions

// zorba-rest:get with an URI
DECL(sctx, rest_get,
     (createQName(ZORBA_REST_FN_NS, "fn-zorba-rest", "get"),
     GENV_TYPESYSTEM.STRING_TYPE_ONE,
     GENV_TYPESYSTEM.ITEM_TYPE_STAR));

// zorba-rest:get with an URI and a payload
DECL(sctx, rest_get,
     (createQName(ZORBA_REST_FN_NS, "fn-zorba-rest", "get"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));

// zorba-rest:get with an URI, a payload and custom headers
DECL(sctx, rest_get,
     (createQName(ZORBA_REST_FN_NS, "fn-zorba-rest", "get"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));


// zorba-rest:post with an URI
DECL(sctx, rest_post,
     (createQName(ZORBA_REST_FN_NS, "fn-zorba-rest", "post"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));

// zorba-rest:post with an URI and a payload
DECL(sctx, rest_post,
     (createQName(ZORBA_REST_FN_NS, "fn-zorba-rest", "post"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));

// zorba-rest:post with an URI, a payload and custom headers
DECL(sctx, rest_post,
     (createQName(ZORBA_REST_FN_NS, "fn-zorba-rest", "post"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));

#endif

//begin collection functions
DECL(sctx, zorba_collection,
     (createQName(ZORBA_COLLECTION_FN_NS, "fn-zorba-collection", "collection"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));

DECL(sctx, zorba_list_collections,
     (createQName(ZORBA_COLLECTION_FN_NS, "fn-zorba-collection", "list-collections"),
      GENV_TYPESYSTEM.STRING_TYPE_STAR));

DECL(sctx, zorba_create_collection,
     (createQName(ZORBA_COLLECTION_FN_NS, "fn-zorba-collection", "create-collection"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.NONE_TYPE));

DECL(sctx, zorba_create_collection,
     (createQName(ZORBA_COLLECTION_FN_NS, "fn-zorba-collection", "create-collection"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
      GENV_TYPESYSTEM.NONE_TYPE));

DECL(sctx, zorba_delete_collection,
     (createQName(ZORBA_COLLECTION_FN_NS, "fn-zorba-collection", "delete-collection"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.NONE_TYPE));

DECL(sctx, zorba_delete_all_collections,
     (createQName(ZORBA_COLLECTION_FN_NS, "fn-zorba-collection", "delete-all-collections"),
      GENV_TYPESYSTEM.NONE_TYPE));

DECL(sctx, zorba_insert_node_first,
     (createQName(ZORBA_COLLECTION_FN_NS, "fn-zorba-collection", "insert-node-first"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
      GENV_TYPESYSTEM.NONE_TYPE));

DECL(sctx, zorba_insert_node_last,
     (createQName(ZORBA_COLLECTION_FN_NS, "fn-zorba-collection", "insert-node-last"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
      GENV_TYPESYSTEM.NONE_TYPE));

DECL(sctx, zorba_insert_node_before,
     (createQName(ZORBA_COLLECTION_FN_NS, "fn-zorba-collection", "insert-node-before"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_PLUS,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
      GENV_TYPESYSTEM.NONE_TYPE));

DECL(sctx, zorba_insert_node_after,
     (createQName(ZORBA_COLLECTION_FN_NS, "fn-zorba-collection", "insert-node-after"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_PLUS,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
      GENV_TYPESYSTEM.NONE_TYPE));

DECL(sctx, zorba_insert_node_at,
     (createQName(ZORBA_COLLECTION_FN_NS, "fn-zorba-collection", "insert-node-at"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.INTEGER_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
      GENV_TYPESYSTEM.NONE_TYPE));

DECL(sctx, zorba_remove_node,
     (createQName(ZORBA_COLLECTION_FN_NS, "fn-zorba-collection", "remove-node"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_PLUS,
      GENV_TYPESYSTEM.NONE_TYPE));

DECL(sctx, zorba_remove_node_at,
     (createQName(ZORBA_COLLECTION_FN_NS, "fn-zorba-collection", "remove-node-at"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.INTEGER_TYPE_ONE,
      GENV_TYPESYSTEM.NONE_TYPE));

DECL(sctx, zorba_node_count,
     (createQName(ZORBA_COLLECTION_FN_NS, "fn-zorba-collection", "node-count"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION));

DECL(sctx, zorba_node_at,
     (createQName(ZORBA_COLLECTION_FN_NS, "fn-zorba-collection", "node-at"),
     GENV_TYPESYSTEM.STRING_TYPE_ONE,
     GENV_TYPESYSTEM.INTEGER_TYPE_ONE,
     GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION));

DECL(sctx, zorba_export_collection,
     (createQName(ZORBA_COLLECTION_FN_NS, "fn-zorba-collection", "export-collection"),
     GENV_TYPESYSTEM.STRING_TYPE_ONE,
     GENV_TYPESYSTEM.STRING_TYPE_ONE,
     GENV_TYPESYSTEM.NONE_TYPE));

//end collection functions

// begin context functions
DECL(sctx, ctx_variable,
     (createQName(XQUERY_FN_NS,"fn", ":ctxvariable"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));
DECL(sctx, ctx_var_assign,
     (createQName(XQUERY_FN_NS,"fn", ":ctxvar-assign"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.EMPTY_TYPE));
// end context functions

  populateContext_Math (sctx);
}

} /* namespace zorba */
