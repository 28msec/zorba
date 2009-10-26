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
#include "functions/StaticContext.h"

#include "runtime/collections/CollectionsImpl.h"

namespace zorba 
{

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

void populateContext_StaticContext(static_context* sctx)
{
DECL(sctx, sc_is_declared_collection,
     (createQName(ZORBA_STATICCONTEXT_FN_NS, "fn-zorba-staticcontext", "is-declared-collection"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));
DECL(sctx, sc_declared_collections,
     (createQName(ZORBA_STATICCONTEXT_FN_NS, "fn-zorba-staticcontext", "declared-collections"),
      GENV_TYPESYSTEM.QNAME_TYPE_STAR));
}

} /* namespace zorba */
