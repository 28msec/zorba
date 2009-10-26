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

void populateContext_Collections(static_context* sctx)
{

DECL(sctx, fn_collection,
     (createQName(XQUERY_FN_NS, "fn", "collection"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));

DECL(sctx, fn_collection,
     (createQName(XQUERY_FN_NS, "fn", "collection"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));
}

} /* namespace zorba */
