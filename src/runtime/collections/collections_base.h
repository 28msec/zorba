/*
 * Copyright 2006-2008 The FLWOR Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once
#ifndef ZORBA_RUNTIME_COLLECTIONS_COLLECTIONS_BASE_H
#define ZORBA_RUNTIME_COLLECTIONS_COLLECTIONS_BASE_H

#include "runtime/base/narybase.h"

#include "compiler/xqddf/collection_decl.h"

#include "context/static_context.h"

#include "store/api/collection.h"
#include "store/api/copymode.h"
#include "store/api/store.h"

#include "types/typeops.h"
#include "types/typeimpl.h"

#include "diagnostics/util_macros.h"


namespace zorba {


/*******************************************************************************
  Check that the type of a node to be inserted into a collection matches with
  the statically declared type of the collection nodes. If not, raise an error.
********************************************************************************/
void checkNodeType(
    const static_context* sctx,
    const store::Item_t& node,
    const StaticallyKnownCollection* collectionDecl,
    const QueryLoc& loc,
    bool isDynamic);


void getCopyMode(store::CopyMode& copyMode, const static_context* sctx);


/*******************************************************************************

********************************************************************************/
template <class Iter, class State>
class ZorbaCollectionIteratorHelper : public NaryBaseIterator<Iter, State>
{
protected:
  bool theIsDynamic;
  bool theNeedToCopy;

protected:

  virtual const StaticallyKnownCollection*
  getCollection(const store::Item_t& name, store::Collection_t& coll) const = 0;

  virtual void
  checkCollectionAndCopyNodes(
      PlanState& planState,
      store::Item_t& collName,
      std::vector<store::Item_t>& nodes,
      store::Item_t& targetNode,
      bool beforeOrAfter) const
  {
    store::Collection_t              collection;
    const StaticallyKnownCollection* collectionDecl;
    store::Item_t                    node;
    store::Item_t                    copyNode;
    xs_integer                       targetPos;

    this->consumeNext(collName, this->theChildren[0].getp(), planState);

    collectionDecl = getCollection(collName, collection);

    if (beforeOrAfter) 
    {
      if (!this->consumeNext(targetNode,
                             this->theChildren[this->theChildren.size()-2].getp(),
                             planState))
      {
        ZORBA_ASSERT(false);
      }

      if (!collection->findNode(targetNode.getp(), targetPos))
      {
        RAISE_ERROR(zerr::ZDDY0011_COLLECTION_NODE_NOT_FOUND, this->loc,
        ERROR_PARAMS(collName->getStringValue()));
      }
    }

    store::CopyMode lCopyMode;
    getCopyMode(lCopyMode, this->theSctx);

    lCopyMode.theDoCopy =
     !(this->theChildren[this->theChildren.size()-1]->isConstructor() ||
      !theNeedToCopy);

    while (this->consumeNext(node,
                             this->theChildren[this->theChildren.size()-1].getp(),
                             planState))
    {
      checkNodeType(this->theSctx,
                    node,
                    collectionDecl,
                    this->loc,
                    theIsDynamic);

      copyNode = node->copy(NULL, lCopyMode);
      nodes.push_back(copyNode);
    }
  }

  virtual void
  checkCollectionAndCopyNodes(
      PlanState& planState,
      store::Item_t& collName,
      std::vector<store::Item_t>& nodes) const
  {
    store::Item_t targetNode;
    checkCollectionAndCopyNodes(planState, collName, nodes, targetNode, false);
  }

public:
  SERIALIZABLE_TEMPLATE_ABSTRACT_CLASS(ZorbaCollectionIteratorHelper)

  ZorbaCollectionIteratorHelper(::zorba::serialization::Archiver& ar)
    :
    NaryBaseIterator<Iter, State>(ar)
  {
  }

  ZorbaCollectionIteratorHelper(
      static_context* sctx,
      const QueryLoc& loc,
      std::vector<PlanIter_t>& children,
      bool isDynamic,
      bool needToCopy)
    :
    NaryBaseIterator<Iter, State>(sctx, loc, children),
    theIsDynamic(isDynamic),
    theNeedToCopy(needToCopy)
  {
  }

  virtual ~ZorbaCollectionIteratorHelper() {}

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar, (NaryBaseIterator<Iter, State>*)this);
    ar & theIsDynamic;
    ar & theNeedToCopy;
  }
};

} // namespace zorba
#endif /* ZORBA_RUNTIME_COLLECTIONS_COLLECTIONS_BASE_H */
/* vim:set et sw=2 ts=2: */
