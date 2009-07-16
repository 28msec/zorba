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
#include "functions/tuple_functions.h"
#include "functions/InternalOperators.h"
#include "functions/Index.h"
#include "functions/Alexis.h"
#include "functions/Convertors.h"

#ifdef ZORBA_WITH_REST
#include "functions/Rest.h"
#endif

#ifdef ZORBA_WITH_EMAIL
#include "functions/Email.h"
#endif

#ifdef ZORBA_WITH_FOP
#include "functions/Fop.h"
#endif // ZORBA_WITH_FOP

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
  populateContext_ZorbaExtensions(sctx);
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

DECL(sctx, fn_string_func,
     (createQName(XQUERY_FN_NS, "fn", "string"),
      GENV_TYPESYSTEM.ITEM_TYPE_QUESTION, GENV_TYPESYSTEM.STRING_TYPE_ONE));
// end Accessors
}


void BuiltinFunctionLibrary::populateContext_Error(static_context *sctx)
{
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

#ifdef ZORBA_WITH_TIDY
// zorba-rest:get with an URI
DECL(sctx, rest_get_tidy,
      (createQName(ZORBA_REST_FN_NS, "fn-zorba-rest", "getTidy"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE, //$tidyOptions
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));

// zorba-rest:get with an URI and a payload
DECL(sctx, rest_get_tidy,
     (createQName(ZORBA_REST_FN_NS, "fn-zorba-rest", "getTidy"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE, //$tidyOptions
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));

// zorba-rest:get with an URI, a payload and custom headers
DECL(sctx, rest_get_tidy,
     (createQName(ZORBA_REST_FN_NS, "fn-zorba-rest", "getTidy"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE, //$tidyOptions
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));
#endif

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


// zorba-rest:put with an URI
DECL(sctx, rest_put,
     (createQName(ZORBA_REST_FN_NS, "fn-zorba-rest", "put"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));

// zorba-rest:put with an URI and a payload
DECL(sctx, rest_put,
     (createQName(ZORBA_REST_FN_NS, "fn-zorba-rest", "put"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));

// zorba-rest:put with an URI, a payload and custom headers
DECL(sctx, rest_put,
     (createQName(ZORBA_REST_FN_NS, "fn-zorba-rest", "put"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));
      
      
// zorba-rest:delete with an URI
DECL(sctx, rest_delete,
     (createQName(ZORBA_REST_FN_NS, "fn-zorba-rest", "delete"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));

// zorba-rest:delete with an URI and a payload
DECL(sctx, rest_delete,
     (createQName(ZORBA_REST_FN_NS, "fn-zorba-rest", "delete"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));

// zorba-rest:delete with an URI, a payload and custom headers
DECL(sctx, rest_delete,
     (createQName(ZORBA_REST_FN_NS, "fn-zorba-rest", "delete"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));


// zorba-rest:head with an URI
DECL(sctx, rest_head,
     (createQName(ZORBA_REST_FN_NS, "fn-zorba-rest", "head"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));

// zorba-rest:head with an URI and a payload
DECL(sctx, rest_head,
     (createQName(ZORBA_REST_FN_NS, "fn-zorba-rest", "head"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));

// zorba-rest:head with an URI, a payload and custom headers
DECL(sctx, rest_head,
     (createQName(ZORBA_REST_FN_NS, "fn-zorba-rest", "head"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));

#endif // ZORBA_WITH_REST

//begin fop functions
#ifdef ZORBA_WITH_FOP
DECL(sctx, zorba_fop,
	 (createQName(ZORBA_FOP_FN_NS, "fn-zorba-fop", "zorba-fop"),
	 GENV_TYPESYSTEM.ITEM_TYPE_ONE,
	 GENV_TYPESYSTEM.ITEM_TYPE_ONE));
#endif

//begin collection functions
DECL(sctx, zorba_collection_exists,
     (createQName(ZORBA_COLLECTION_FN_NS, "fn-zorba-collection", "collection-exists"),
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(sctx, zorba_collection_exists,
     (createQName(ZORBA_COLLECTION_FN_NS, "fn-zorba-collection", "collection-exists"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(sctx, zorba_import_xml,
     (createQName(ZORBA_COLLECTION_FN_NS, "fn-zorba-collection", "import-xml"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.NONE_TYPE));

DECL(sctx, zorba_import_catalog,
     (createQName(ZORBA_COLLECTION_FN_NS, "fn-zorba-collection", "import-catalog"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.NONE_TYPE));

DECL(sctx, zorba_import_folder,
     (createQName(ZORBA_COLLECTION_FN_NS, "fn-zorba-collection", "import-folder"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.NONE_TYPE));

DECL(sctx, zorba_list_collections,
     (createQName(ZORBA_COLLECTION_FN_NS, "fn-zorba-collection", "list-collections"),
      GENV_TYPESYSTEM.ANY_URI_TYPE_STAR));

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
      GENV_TYPESYSTEM.NONE_TYPE));

DECL(sctx, zorba_delete_collection,
     (createQName(ZORBA_COLLECTION_FN_NS, "fn-zorba-collection", "delete-collection"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.NONE_TYPE));

DECL(sctx, zorba_delete_all_collections,
     (createQName(ZORBA_COLLECTION_FN_NS, "fn-zorba-collection", "delete-all-collections"),
      GENV_TYPESYSTEM.NONE_TYPE));

DECL(sctx, zorba_insert_nodes_first,
     (createQName(ZORBA_COLLECTION_FN_NS, "fn-zorba-collection", "insert-nodes-first"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
      GENV_TYPESYSTEM.NONE_TYPE));

DECL(sctx, zorba_insert_nodes_first,
     (createQName(ZORBA_COLLECTION_FN_NS, "fn-zorba-collection", "insert-nodes-first"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
      GENV_TYPESYSTEM.NONE_TYPE));

DECL(sctx, zorba_insert_nodes_last,
     (createQName(ZORBA_COLLECTION_FN_NS, "fn-zorba-collection", "insert-nodes-last"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
      GENV_TYPESYSTEM.NONE_TYPE));

DECL(sctx, zorba_insert_nodes_last,
     (createQName(ZORBA_COLLECTION_FN_NS, "fn-zorba-collection", "insert-nodes-last"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
      GENV_TYPESYSTEM.NONE_TYPE));

DECL(sctx, zorba_insert_nodes_before,
     (createQName(ZORBA_COLLECTION_FN_NS, "fn-zorba-collection", "insert-nodes-before"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_PLUS,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
      GENV_TYPESYSTEM.NONE_TYPE));

DECL(sctx, zorba_insert_nodes_before,
     (createQName(ZORBA_COLLECTION_FN_NS, "fn-zorba-collection", "insert-nodes-before"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_PLUS,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
      GENV_TYPESYSTEM.NONE_TYPE));

DECL(sctx, zorba_insert_nodes_after,
     (createQName(ZORBA_COLLECTION_FN_NS, "fn-zorba-collection", "insert-nodes-after"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_PLUS,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
      GENV_TYPESYSTEM.NONE_TYPE));

DECL(sctx, zorba_insert_nodes_after,
     (createQName(ZORBA_COLLECTION_FN_NS, "fn-zorba-collection", "insert-nodes-after"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_PLUS,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
      GENV_TYPESYSTEM.NONE_TYPE));

DECL(sctx, zorba_insert_nodes_at,
     (createQName(ZORBA_COLLECTION_FN_NS, "fn-zorba-collection", "insert-nodes-at"),
      GENV_TYPESYSTEM.INTEGER_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
      GENV_TYPESYSTEM.NONE_TYPE));

DECL(sctx, zorba_insert_nodes_at,
     (createQName(ZORBA_COLLECTION_FN_NS, "fn-zorba-collection", "insert-nodes-at"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
      GENV_TYPESYSTEM.NONE_TYPE));

DECL(sctx, zorba_remove_nodes,
     (createQName(ZORBA_COLLECTION_FN_NS, "fn-zorba-collection", "remove-nodes"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_PLUS,
      GENV_TYPESYSTEM.NONE_TYPE));

DECL(sctx, zorba_remove_nodes,
     (createQName(ZORBA_COLLECTION_FN_NS, "fn-zorba-collection", "remove-nodes"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_PLUS,
      GENV_TYPESYSTEM.NONE_TYPE));

DECL(sctx, zorba_remove_node_at,
     (createQName(ZORBA_COLLECTION_FN_NS, "fn-zorba-collection", "remove-node-at"),
      GENV_TYPESYSTEM.INTEGER_TYPE_ONE,
      GENV_TYPESYSTEM.NONE_TYPE));

DECL(sctx, zorba_remove_node_at,
     (createQName(ZORBA_COLLECTION_FN_NS, "fn-zorba-collection", "remove-node-at"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_ONE,
      GENV_TYPESYSTEM.NONE_TYPE));

DECL(sctx, zorba_nodes_count,
     (createQName(ZORBA_COLLECTION_FN_NS, "fn-zorba-collection", "nodes-count"),
      GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION));

DECL(sctx, zorba_nodes_count,
     (createQName(ZORBA_COLLECTION_FN_NS, "fn-zorba-collection", "nodes-count"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION));

DECL(sctx, zorba_node_at,
     (createQName(ZORBA_COLLECTION_FN_NS, "fn-zorba-collection", "node-at"),
      GENV_TYPESYSTEM.INTEGER_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION));

DECL(sctx, zorba_node_at,
     (createQName(ZORBA_COLLECTION_FN_NS, "fn-zorba-collection", "node-at"),
     GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
     GENV_TYPESYSTEM.INTEGER_TYPE_ONE,
     GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION));

DECL(sctx, zorba_index_of,
     (createQName(ZORBA_COLLECTION_FN_NS, "fn-zorba-collection", "index-of"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE,
      GENV_TYPESYSTEM.INTEGER_TYPE_ONE));

DECL(sctx, zorba_index_of,
     (createQName(ZORBA_COLLECTION_FN_NS, "fn-zorba-collection", "index-of"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE,
      GENV_TYPESYSTEM.INTEGER_TYPE_ONE));

DECL(sctx, zorba_export_xml,
     (createQName(ZORBA_COLLECTION_FN_NS, "fn-zorba-collection", "export-xml"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.NONE_TYPE));

DECL(sctx, zorba_export_xml,
     (createQName(ZORBA_COLLECTION_FN_NS, "fn-zorba-collection", "export-xml"),
     GENV_TYPESYSTEM.STRING_TYPE_ONE,
     GENV_TYPESYSTEM.STRING_TYPE_ONE,
     GENV_TYPESYSTEM.NONE_TYPE));

//end collection functions


// begin index functions
#if 0
DECL(sctx, zorba_create_index,
     (createQName(ZORBA_INDEX_FN_NS, "fn-zorba-index", "create-index"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION
      true,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));
#endif


// begin util functions
DECL(sctx, zorba_schema_type,
     (createQName(ZORBA_ALEXIS_FN_NS, "fn-zorba-util", "schema-type"),
      GENV_TYPESYSTEM.ITEM_TYPE_ONE,
      GENV_TYPESYSTEM.QNAME_TYPE_ONE));

DECL(sctx, zorba_decode_base64,
     (createQName(ZORBA_ALEXIS_FN_NS, "fn-zorba-util", "base64Decode"),
      GENV_TYPESYSTEM.BASE64BINARY_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(sctx, zorba_encode_base64,
     (createQName(ZORBA_ALEXIS_FN_NS, "fn-zorba-util", "base64Encode"),
      GENV_TYPESYSTEM.ITEM_TYPE_ONE,
      GENV_TYPESYSTEM.BASE64BINARY_TYPE_ONE));

#ifdef ZORBA_WITH_TIDY
  DECL(sctx, zorba_tidy,
       (createQName(ZORBA_ALEXIS_FN_NS, "fn-zorba-util", "tidy"),
        GENV_TYPESYSTEM.STRING_TYPE_ONE,
        GENV_TYPESYSTEM.ITEM_TYPE_ONE));

  DECL(sctx, zorba_tidy,
       (createQName(ZORBA_ALEXIS_FN_NS, "fn-zorba-util", "tidy"),
        GENV_TYPESYSTEM.STRING_TYPE_ONE,
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
        GENV_TYPESYSTEM.ITEM_TYPE_ONE));

  DECL(sctx, zorba_tdoc,
       (createQName(ZORBA_ALEXIS_FN_NS, "fn-zorba-util", "tdoc"),
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
        GENV_TYPESYSTEM.DOCUMENT_TYPE_QUESTION));

  DECL(sctx, zorba_tdoc,
       (createQName(ZORBA_ALEXIS_FN_NS, "fn-zorba-util", "tdoc"),
        GENV_TYPESYSTEM.STRING_TYPE_ONE,
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
        GENV_TYPESYSTEM.DOCUMENT_TYPE_QUESTION));
#endif

  DECL (sctx, zorba_serialize_to_string,
        (createQName(ZORBA_ALEXIS_FN_NS, "fn-zorba-util", "serialize-to-string"),
         GENV_TYPESYSTEM.ITEM_TYPE_STAR,
         GENV_TYPESYSTEM.STRING_TYPE_ONE));


  DECL(sctx, zorba_random,
       (createQName(ZORBA_ALEXIS_FN_NS, "fn-zorba-util", "random"),
        GENV_TYPESYSTEM.INTEGER_TYPE_ONE));

  DECL(sctx, zorba_random,
       (createQName(ZORBA_ALEXIS_FN_NS, "fn-zorba-util", "random"),
        GENV_TYPESYSTEM.INTEGER_TYPE_ONE,
        GENV_TYPESYSTEM.INTEGER_TYPE_ONE));

  DECL(sctx, zorba_uuid,
       (createQName(ZORBA_ALEXIS_FN_NS, "fn-zorba-util", "uuid"),
        GENV_TYPESYSTEM.STRING_TYPE_ONE));

  DECL(sctx, zorba_timestamp,
       (createQName(ZORBA_ALEXIS_FN_NS, "fn-zorba-util", "timestamp"),
        GENV_TYPESYSTEM.LONG_TYPE_ONE));

  DECL(sctx, zorba_json_parse,
       (createQName(ZORBA_JSON_FN_NS, "fn-zorba-json", "parse"),
        GENV_TYPESYSTEM.STRING_TYPE_STAR,
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));

  DECL(sctx, zorba_json_serialize,
       (createQName(ZORBA_JSON_FN_NS, "fn-zorba-json", "serialize"),
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
        GENV_TYPESYSTEM.STRING_TYPE_STAR));

  DECL(sctx, zorba_json_ml_parse,
       (createQName(ZORBA_JSON_ML_FN_NS, "fn-zorba-json-ml", "parse"),
        GENV_TYPESYSTEM.STRING_TYPE_STAR,
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));

  DECL(sctx, zorba_json_ml_serialize,
       (createQName(ZORBA_JSON_ML_FN_NS, "fn-zorba-json-ml", "serialize"),
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
        GENV_TYPESYSTEM.STRING_TYPE_STAR));
#ifdef ZORBA_WITH_EMAIL
  DECL(sctx, zorba_mail,
       (createQName(ZORBA_EMAIL_FN_NS, "fn-zorba-email", "mail"),
        GENV_TYPESYSTEM.STRING_TYPE_ONE,
        GENV_TYPESYSTEM.STRING_TYPE_ONE,
        GENV_TYPESYSTEM.STRING_TYPE_ONE,
        GENV_TYPESYSTEM.NONE_TYPE));
#endif

// end util functions

// begin context functions
DECL(sctx, ctx_variable,
     (createQName(XQUERY_FN_NS,"fn", ":ctxvariable"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));
DECL(sctx, ctx_var_declare,
     (createQName(XQUERY_FN_NS,"fn", ":ctxvar-declare"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.EMPTY_TYPE));
DECL(sctx, ctx_var_assign,
     (createQName(XQUERY_FN_NS,"fn", ":ctxvar-assign"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.EMPTY_TYPE));
DECL(sctx, ctx_var_exists,
     (createQName(XQUERY_FN_NS,"fn", ":ctxvar-exists"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));
// end context functions

  populateContext_Math (sctx);
}

void BuiltinFunctionLibrary::populateContext_ZorbaExtensions(static_context *sctx)
{
DECL(sctx, zop_createtuple,
     (createQName(ZORBA_OPEXTENSIONS_NS,"op-extensions", "create-tuple"),
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      true,
      GENV_TYPESYSTEM.ITEM_TYPE_ONE));
DECL(sctx, zop_gettuplefield,
     (createQName(ZORBA_OPEXTENSIONS_NS,"op-extensions", "get-tuple-field"),
      GENV_TYPESYSTEM.INTEGER_TYPE_ONE,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));
DECL(sctx, zop_hoist,
     (createQName(XQUERY_FN_NS,"fn", ":hoist"),
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));
DECL(sctx, zop_unhoist,
     (createQName(XQUERY_FN_NS,"fn", ":unhoist"),
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));
DECL(sctx, zop_createindex,
     (createQName(ZORBA_OPEXTENSIONS_NS,"op-extensions", "create-index"),
      GENV_TYPESYSTEM.ANY_URI_TYPE_ONE,
      GENV_TYPESYSTEM.ITEM_TYPE_ONE));
DECL(sctx, zop_dropindex,
     (createQName(ZORBA_OPEXTENSIONS_NS,"op-extensions", "drop-index"),
      GENV_TYPESYSTEM.ANY_URI_TYPE_ONE,
      GENV_TYPESYSTEM.ITEM_TYPE_ONE));
DECL(sctx, zop_buildindex,
     (createQName(ZORBA_OPEXTENSIONS_NS,"op-extensions", "build-index"),
      GENV_TYPESYSTEM.ANY_URI_TYPE_ONE,
      GENV_TYPESYSTEM.ITEM_TYPE_ONE));
DECL(sctx, zop_probeindexpoint,
     (createQName(ZORBA_OPEXTENSIONS_NS,"op-extensions", "probe-index-point"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      true,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));
DECL(sctx, zop_probeindexrange,
     (createQName(ZORBA_OPEXTENSIONS_NS,"op-extensions", "probe-index-range"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      true,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));
DECL(sctx, zop_index_session_opener,
     (createQName(XQUERY_FN_NS,"fn", ":index-session-opener"),
      GENV_TYPESYSTEM.ANY_URI_TYPE_ONE,
      GENV_TYPESYSTEM.ITEM_TYPE_ONE));
DECL(sctx, zop_index_session_closer,
     (createQName(XQUERY_FN_NS,"fn", ":index-session-closer"),
      GENV_TYPESYSTEM.ANY_URI_TYPE_ONE,
      GENV_TYPESYSTEM.ITEM_TYPE_QUESTION));
DECL(sctx, zop_index_builder,
     (createQName(XQUERY_FN_NS,"fn", ":index-builder"),
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      true,
      GENV_TYPESYSTEM.ITEM_TYPE_QUESTION));
}

} /* namespace zorba */
