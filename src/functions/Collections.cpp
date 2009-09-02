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

#include "system/globalenv.h"

#include "functions/function_impl.h"
#include "functions/Collections.h"

#include "runtime/collections/CollectionsImpl.h"


namespace zorba 
{


class fn_collection : public function 
{
public:
  fn_collection(const signature & sig) : function (sig) {}

  bool requires_dyn_ctx() const { return true; }

  DEFAULT_NARY_CODEGEN(FnCollectionIterator);
};


class zorba_collection_exists : public function
{
public:
  zorba_collection_exists(const signature& sig): function(sig){}

  bool requires_dyn_ctx() const { return true; }

  DEFAULT_NARY_CODEGEN(ZorbaCollectionExistsIterator);
};


class zorba_import_xml : public function
{
public:
  zorba_import_xml(const signature& sig): function(sig){}
  
  bool requires_dyn_ctx () const { return true; }

  DEFAULT_NARY_CODEGEN(ZorbaImportXmlIterator);
};


class zorba_import_catalog : public function
{
public:
  zorba_import_catalog(const signature& sig): function(sig){}

  bool requires_dyn_ctx () const { return true; }

  DEFAULT_NARY_CODEGEN(ZorbaImportCatalogIterator);
};


class zorba_import_folder : public function
{
public:
  zorba_import_folder(const signature& sig): function(sig){}

  bool requires_dyn_ctx () const { return true; }

  DEFAULT_NARY_CODEGEN(ZorbaImportFolderIterator);
};


class zorba_list_collections : public function
{
public:
  zorba_list_collections(const signature& sig): function(sig){}

  bool requires_dyn_ctx () const { return true; }

  DEFAULT_NARY_CODEGEN(ZorbaListCollectionsIterator);
};


class zorba_create_collection : public function
{
public:
  zorba_create_collection(const signature& sig): function(sig){}

  bool requires_dyn_ctx () const { return true; }

  expr_update_t getUpdateType() const { return UPDATE_EXPR; }

  DEFAULT_NARY_CODEGEN(ZorbaCreateCollectionIterator);
};


class zorba_delete_collection : public function
{
public:
  zorba_delete_collection(const signature& sig): function(sig){}

  bool requires_dyn_ctx () const { return true; }

  expr_update_t getUpdateType() const { return UPDATE_EXPR; }

  DEFAULT_NARY_CODEGEN(ZorbaDeleteCollectionIterator);
};


class zorba_delete_all_collections : public function
{
public:
  zorba_delete_all_collections(const signature& sig): function(sig){}

  bool requires_dyn_ctx () const { return true; }

  expr_update_t getUpdateType() const { return UPDATE_EXPR; }

  DEFAULT_NARY_CODEGEN(ZorbaDeleteAllCollectionsIterator);
};


class zorba_insert_nodes_first : public function
{
public:
  zorba_insert_nodes_first(const signature& sig): function(sig){}

  bool requires_dyn_ctx () const { return true; }

  expr_update_t getUpdateType() const { return UPDATE_EXPR; }

  DEFAULT_NARY_CODEGEN(ZorbaInsertNodeFirstIterator);
};


class zorba_insert_nodes_last : public function
{
public:
  zorba_insert_nodes_last(const signature& sig): function(sig){}

  bool requires_dyn_ctx () const { return true; }

  expr_update_t getUpdateType() const { return UPDATE_EXPR; }

  DEFAULT_NARY_CODEGEN(ZorbaInsertNodeLastIterator);
};


class zorba_insert_nodes_before : public function
{
public:
  zorba_insert_nodes_before(const signature& sig): function(sig){}

  bool requires_dyn_ctx () const { return true; }

  expr_update_t getUpdateType() const { return UPDATE_EXPR; }

  DEFAULT_NARY_CODEGEN(ZorbaInsertNodeBeforeIterator);
};


class zorba_insert_nodes_after : public function
{
public:
  zorba_insert_nodes_after(const signature& sig): function(sig){}

  bool requires_dyn_ctx () const { return true; }

  expr_update_t getUpdateType() const { return UPDATE_EXPR; }

  DEFAULT_NARY_CODEGEN(ZorbaInsertNodeAfterIterator);
};


class zorba_insert_nodes_at : public function
{
public:
  zorba_insert_nodes_at(const signature& sig): function(sig){}

  bool requires_dyn_ctx () const { return true; }

  expr_update_t getUpdateType() const { return UPDATE_EXPR; }

  DEFAULT_NARY_CODEGEN(ZorbaInsertNodeAtIterator);
};


class zorba_remove_nodes : public function
{
public:
  zorba_remove_nodes(const signature& sig): function(sig){}

  bool requires_dyn_ctx () const { return true; }

  expr_update_t getUpdateType() const { return UPDATE_EXPR; }

  DEFAULT_NARY_CODEGEN(ZorbaRemoveNodeIterator);
};


class zorba_remove_node_at : public function
{
public:
  zorba_remove_node_at(const signature& sig): function(sig){}

  bool requires_dyn_ctx () const { return true; }

  expr_update_t getUpdateType() const { return UPDATE_EXPR; }

  DEFAULT_NARY_CODEGEN(ZorbaRemoveNodeAtIterator);
};


class zorba_nodes_count : public function
{
public:
  zorba_nodes_count(const signature& sig): function(sig){}

  bool requires_dyn_ctx () const { return true; }

  DEFAULT_NARY_CODEGEN(ZorbaNodeCountIterator);
};


class zorba_node_at : public function
{
public:
  zorba_node_at(const signature& sig): function(sig){}

  bool requires_dyn_ctx() const { return true; }

  DEFAULT_NARY_CODEGEN(ZorbaNodeAtIterator);
};


class zorba_index_of : public function
{
public:
  zorba_index_of(const signature& sig): function(sig){}

  bool requires_dyn_ctx () const { return true; }

  DEFAULT_NARY_CODEGEN(ZorbaIndexOfIterator);
};


class zorba_export_xml : public function
{
public:
  zorba_export_xml(const signature& sig): function(sig){}

  bool requires_dyn_ctx () const { return true; }

  DEFAULT_NARY_CODEGEN(ZorbaExportXmlIterator);
};


void populateContext_Collections(static_context* sctx)
{

DECL(sctx, fn_collection,
     (createQName(XQUERY_FN_NS, "fn", "collection"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));

DECL(sctx, fn_collection,
     (createQName(XQUERY_FN_NS, "fn", "collection"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));

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
}

} /* namespace zorba */
