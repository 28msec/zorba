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
#include "functions/DynamicContext.h"

#include "runtime/collections/CollectionsImpl.h"

namespace zorba 
{

class dc_collection : public function 
{
public:
  dc_collection(const signature & sig): function(sig)
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

void populateContext_DynamicContext(static_context* sctx)
{
DECL(sctx, dc_collection,
     (createQName(ZORBA_DYNAMICCONTEXT_FN_NS, "fn-zorba-dynamiccontext", "collection"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));

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
}

} /* namespace zorba */
