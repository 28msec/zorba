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
#include "functions/DataDefinitionLanguage.h"

#include "runtime/collections/CollectionsImpl.h"

namespace zorba 
{

class ddl_create_collection : public function
{
public:
  ddl_create_collection(const signature& sig): function(sig){}

  bool requires_dyn_ctx () const { return true; }

 expr_script_kind_t getUpdateType() const { return UPDATE_EXPR; }

  DEFAULT_NARY_CODEGEN(ZorbaCreateCollectionIterator);
};

class ddl_drop_collection : public function
{
public:
  ddl_drop_collection(const signature& sig): function(sig){}

  bool requires_dyn_ctx () const { return true; }

 expr_script_kind_t getUpdateType() const { return UPDATE_EXPR; }

  DEFAULT_NARY_CODEGEN(ZorbaDropCollectionIterator);
};

class ddl_drop_all_collections : public function
{
public:
  ddl_drop_all_collections(const signature& sig): function(sig){}

  bool requires_dyn_ctx () const { return true; }

 expr_script_kind_t getUpdateType() const { return UPDATE_EXPR; }

  DEFAULT_NARY_CODEGEN(ZorbaDropAllCollectionsIterator);
};


class ddl_insert_nodes_first : public function
{
public:
  ddl_insert_nodes_first(const signature& sig): function(sig){}

  bool requires_dyn_ctx () const { return true; }

 expr_script_kind_t getUpdateType() const { return UPDATE_EXPR; }

  DEFAULT_NARY_CODEGEN(ZorbaInsertNodesFirstIterator);
};

class ddl_insert_nodes_last : public function
{
public:
  ddl_insert_nodes_last(const signature& sig): function(sig){}

  bool requires_dyn_ctx () const { return true; }

 expr_script_kind_t getUpdateType() const { return UPDATE_EXPR; }

  DEFAULT_NARY_CODEGEN(ZorbaInsertNodesLastIterator);
};

class ddl_insert_nodes_before : public function
{
public:
  ddl_insert_nodes_before(const signature& sig): function(sig){}

  bool requires_dyn_ctx () const { return true; }

 expr_script_kind_t getUpdateType() const { return UPDATE_EXPR; }

  DEFAULT_NARY_CODEGEN(ZorbaInsertNodesBeforeIterator);
};

class ddl_insert_nodes_after : public function
{
public:
  ddl_insert_nodes_after(const signature& sig): function(sig){}

  bool requires_dyn_ctx () const { return true; }

 expr_script_kind_t getUpdateType() const { return UPDATE_EXPR; }

  DEFAULT_NARY_CODEGEN(ZorbaInsertNodesAfterIterator);
};

class ddl_insert_nodes_at : public function
{
public:
  ddl_insert_nodes_at(const signature& sig): function(sig){}

  bool requires_dyn_ctx () const { return true; }

 expr_script_kind_t getUpdateType() const { return UPDATE_EXPR; }

  DEFAULT_NARY_CODEGEN(ZorbaInsertNodesAtIterator);
};

class ddl_remove_nodes : public function
{
public:
  ddl_remove_nodes(const signature& sig): function(sig){}

  bool requires_dyn_ctx () const { return true; }

 expr_script_kind_t getUpdateType() const { return UPDATE_EXPR; }

  DEFAULT_NARY_CODEGEN(ZorbaRemoveNodesIterator);
};

class ddl_remove_node_at : public function
{
public:
  ddl_remove_node_at(const signature& sig): function(sig){}

  bool requires_dyn_ctx () const { return true; }

 expr_script_kind_t getUpdateType() const { return UPDATE_EXPR; }

  DEFAULT_NARY_CODEGEN(ZorbaRemoveNodeAtIterator);
};

void populateContext_DataDefinitionLanguage(static_context* sctx)
{
DECL(sctx, ddl_create_collection,
     (createQName(ZORBA_DDL_FN_NS, "fn-zorba-ddl", "create-collection"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.NONE_TYPE));

DECL(sctx, ddl_create_collection,
     (createQName(ZORBA_DDL_FN_NS, "fn-zorba-ddl", "create-collection"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.NONE_TYPE));

DECL(sctx, ddl_create_collection,
     (createQName(ZORBA_DDL_FN_NS, "fn-zorba-ddl", "create-collection"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
      GENV_TYPESYSTEM.NONE_TYPE));

DECL(sctx, ddl_drop_collection,
     (createQName(ZORBA_DDL_FN_NS, "fn-zorba-ddl", "drop-collection"),
      GENV_TYPESYSTEM.QNAME_TYPE_QUESTION,
      GENV_TYPESYSTEM.NONE_TYPE));

DECL(sctx, ddl_drop_all_collections,
     (createQName(ZORBA_DDL_FN_NS, "fn-zorba-ddl", "drop-all-collections"),
      GENV_TYPESYSTEM.NONE_TYPE));

DECL(sctx, ddl_insert_nodes_first,
     (createQName(ZORBA_DDL_FN_NS, "fn-zorba-ddl", "insert-nodes-first"),
      GENV_TYPESYSTEM.QNAME_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
      GENV_TYPESYSTEM.NONE_TYPE));

DECL(sctx, ddl_insert_nodes_last,
     (createQName(ZORBA_DDL_FN_NS, "fn-zorba-ddl", "insert-nodes-last"),
      GENV_TYPESYSTEM.QNAME_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
      GENV_TYPESYSTEM.NONE_TYPE));

DECL(sctx, ddl_insert_nodes_before,
     (createQName(ZORBA_DDL_FN_NS, "fn-zorba-ddl", "insert-nodes-before"),
      GENV_TYPESYSTEM.QNAME_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_PLUS,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
      GENV_TYPESYSTEM.NONE_TYPE));

DECL(sctx, ddl_insert_nodes_after,
     (createQName(ZORBA_DDL_FN_NS, "fn-zorba-ddl", "insert-nodes-after"),
      GENV_TYPESYSTEM.QNAME_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_PLUS,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
      GENV_TYPESYSTEM.NONE_TYPE));

DECL(sctx, ddl_insert_nodes_at,
     (createQName(ZORBA_DDL_FN_NS, "fn-zorba-ddl", "insert-nodes-at"),
      GENV_TYPESYSTEM.QNAME_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
      GENV_TYPESYSTEM.NONE_TYPE));

DECL(sctx, ddl_remove_nodes,
     (createQName(ZORBA_DDL_FN_NS, "fn-zorba-ddl", "remove-nodes"),
      GENV_TYPESYSTEM.QNAME_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_PLUS,
      GENV_TYPESYSTEM.NONE_TYPE));

DECL(sctx, ddl_remove_node_at,
     (createQName(ZORBA_DDL_FN_NS, "fn-zorba-ddl", "remove-node-at"),
      GENV_TYPESYSTEM.QNAME_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_ONE,
      GENV_TYPESYSTEM.NONE_TYPE));
}

} /* namespace zorba */
