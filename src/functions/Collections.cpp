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
  fn_collection(const signature& sig) 
    :
    function(sig, FunctionConsts::FN_COLLECTION)
  {
  }

  bool isSource() const { return true; }

  bool requires_dyn_ctx() const { return true; }

  DEFAULT_NARY_CODEGEN(FnCollectionIterator);
};


class dc_collection : public function 
{
public:
  dc_collection(const signature& sig): function(sig, FunctionConsts::FN_ZORBA_COLLECTION)
  {}

  bool requires_dyn_ctx() const { return true; }

  DEFAULT_NARY_CODEGEN(ZorbaCollectionIterator);
};


class dc_is_available_collections : public function
{
public:
  dc_is_available_collections(const signature& sig): function(sig){}

  bool requires_dyn_ctx() const { return true; }

  DEFAULT_NARY_CODEGEN(DcIsAvailableCollectionIterator);
};


class dc_available_collections : public function
{
public:
  dc_available_collections(const signature& sig): function(sig){}

  bool requires_dyn_ctx () const { return true; }

  DEFAULT_NARY_CODEGEN(DcAvailableCollectionsIterator);
};


class dc_index_of : public function
{
public:
  dc_index_of(const signature& sig): function(sig){}

  bool requires_dyn_ctx () const { return true; }

  DEFAULT_NARY_CODEGEN(ZorbaIndexOfIterator);
};

class sc_is_declared_collection : public function
{
public:
  sc_is_declared_collection(const signature& sig): function(sig){}

  bool requires_dyn_ctx () const { return false; }

  DEFAULT_NARY_CODEGEN(ScIsDeclaredCollectionIterator);
};

class sc_declared_collections : public function
{
public:
  sc_declared_collections(const signature& sig): function(sig){}

  bool requires_dyn_ctx () const { return false; }

  DEFAULT_NARY_CODEGEN(ScDeclaredCollectionsIterator);
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

DECL(sctx, dc_collection,
     (createQName(ZORBA_DYNAMICCONTEXT_FN_NS, "fn-zorba-dynamiccontext", "collection"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.DOCUMENT_UNTYPED_TYPE_STAR));

DECL(sctx, dc_is_available_collections,
     (createQName(ZORBA_DYNAMICCONTEXT_FN_NS, "fn-zorba-dynamiccontext", "is-available-collection"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(sctx, dc_available_collections,
     (createQName(ZORBA_DYNAMICCONTEXT_FN_NS, "fn-zorba-dynamiccontext", "available-collections"),
      GENV_TYPESYSTEM.QNAME_TYPE_STAR));

DECL(sctx, dc_index_of,
     (createQName(ZORBA_DYNAMICCONTEXT_FN_NS, "fn-zorba-dynamiccontext", "index-of"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE,
      GENV_TYPESYSTEM.INTEGER_TYPE_ONE));

DECL(sctx, sc_is_declared_collection,
     (createQName(ZORBA_STATICCONTEXT_FN_NS, "fn-zorba-staticcontext", "is-declared-collection"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(sctx, sc_declared_collections,
     (createQName(ZORBA_STATICCONTEXT_FN_NS, "fn-zorba-staticcontext", "declared-collections"),
      GENV_TYPESYSTEM.QNAME_TYPE_STAR));
}

} /* namespace zorba */
