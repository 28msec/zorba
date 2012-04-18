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


template<> const char* 
ZorbaCollectionIteratorHelper<ZorbaInsertNodesIterator, PlanIteratorState>::class_name_str =
"ZorbaCollectionIteratorHelper<ZorbaInsertNodesIterator, PlanIteratorState>";

template<> const char* 
ZorbaCollectionIteratorHelper<ZorbaApplyInsertNodesIterator, ZorbaApplyInsertNodesIteratorState>::class_name_str =
"ZorbaCollectionIteratorHelper<ZorbaApplyInsertNodesIterator, ZorbaApplyInsertNodesIteratorState>";

template<> const char* 
ZorbaCollectionIteratorHelper<ZorbaInsertNodesLastIterator, PlanIteratorState>::class_name_str =
"ZorbaCollectionIteratorHelper<ZorbaInsertNodesLastIterator, PlanIteratorState>";

template<> const char* 
ZorbaCollectionIteratorHelper<ZorbaApplyInsertNodesLastIterator, ZorbaApplyInsertNodesLastIteratorState>::class_name_str =
"ZorbaCollectionIteratorHelper<ZorbaApplyInsertNodesLastIterator, ZorbaApplyInsertNodesLastIteratorState>";

template<> const char* 
ZorbaCollectionIteratorHelper<ZorbaInsertNodesFirstIterator, PlanIteratorState>::class_name_str =
"ZorbaCollectionIteratorHelper<ZorbaInsertNodesFirstIterator, PlanIteratorState>";

template<> const char* 
ZorbaCollectionIteratorHelper<ZorbaApplyInsertNodesFirstIterator, ZorbaApplyInsertNodesFirstIteratorState>::class_name_str =
"ZorbaCollectionIteratorHelper<ZorbaApplyInsertNodesFirstIterator, ZorbaApplyInsertNodesFirstIteratorState>";

template<> const char* 
ZorbaCollectionIteratorHelper<ZorbaInsertNodesBeforeIterator, PlanIteratorState>::class_name_str =
"ZorbaCollectionIteratorHelper<ZorbaInsertNodesBeforeIterator, PlanIteratorState>";

template<> const char* 
ZorbaCollectionIteratorHelper<ZorbaApplyInsertNodesBeforeIterator, ZorbaApplyInsertNodesBeforeIteratorState>::class_name_str =
"ZorbaCollectionIteratorHelper<ZorbaApplyInsertNodesBeforeIterator, ZorbaApplyInsertNodesBeforeIteratorState>";

template<> const char* 
ZorbaCollectionIteratorHelper<ZorbaInsertNodesAfterIterator, PlanIteratorState>::class_name_str =
"ZorbaCollectionIteratorHelper<ZorbaInsertNodesAfterIterator, PlanIteratorState>";

template<> const char* 
ZorbaCollectionIteratorHelper<ZorbaApplyInsertNodesAfterIterator, ZorbaApplyInsertNodesAfterIteratorState>::class_name_str =
"ZorbaCollectionIteratorHelper<ZorbaApplyInsertNodesAfterIterator, ZorbaApplyInsertNodesAfterIteratorState>";


void checkNodeType(
    const static_context* sctx,
    const store::Item_t& node, 
    const StaticallyKnownCollection* collectionDecl,
    const QueryLoc& loc,
    bool dyn_coll)
{
  if (dyn_coll)
    return;

  const TypeManager* tm = sctx->get_typemanager();

  if (!TypeOps::is_treatable(tm, node, *(collectionDecl->getNodeType()), loc))
  {
    throw XQUERY_EXCEPTION(
      zerr::ZDTY0001_COLLECTION_INVALID_NODE_TYPE,
      ERROR_PARAMS(
        TypeOps::toString( *tm->create_value_type( node ) ),
        collectionDecl->getName()->getStringValue()
      ),
      ERROR_LOC( loc )
    );
  }
}

void
getCopyMode(
    store::CopyMode& aCopyMode,
    const static_context* aSctx)
{
  aCopyMode.set(true, 
    aSctx->construction_mode() == StaticContextConsts::cons_preserve,
    aSctx->preserve_mode() == StaticContextConsts::preserve_ns,
    aSctx->inherit_mode() == StaticContextConsts::inherit_ns);
}

} /* namespace zorba */
/* vim:set et sw=2 ts=2: */
