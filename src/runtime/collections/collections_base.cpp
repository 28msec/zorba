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


#include "stdafx.h"

#include "runtime/collections/collections_base.h"
#include "runtime/collections/collections.h"

namespace zorba {




void checkNodeType(
    const static_context* sctx,
    const store::Item_t& node, 
    const StaticallyKnownCollection* collectionDecl,
    const QueryLoc& loc,
    bool isDynamic)
{
  if (isDynamic)
  {
    return;
  }

  const TypeManager* tm = sctx->get_typemanager();

  if (!TypeOps::is_subtype(tm, node, *(collectionDecl->getNodeType()), loc))
  {
    RAISE_ERROR(zerr::ZDTY0001_COLLECTION_INVALID_NODE_TYPE, loc,
    ERROR_PARAMS(tm->create_value_type(node)->toSchemaString(),
                 collectionDecl->getName()->getStringValue()));
  }
}


void getCopyMode(store::CopyMode& copyMode, const static_context* sctx)
{
  copyMode.set(true, 
               sctx->construction_mode() == StaticContextConsts::cons_preserve,
               sctx->preserve_ns(),
               sctx->inherit_ns());
}

} /* namespace zorba */
/* vim:set et sw=2 ts=2: */
