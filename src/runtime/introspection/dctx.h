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
 
// ******************************************
// *                                        *
// * THIS IS A GENERATED FILE. DO NOT EDIT! *
// * SEE .xml FILE WITH SAME NAME           *
// *                                        *
// ******************************************
#ifndef ZORBA_RUNTIME_INTROSPECTION_DCTX_H
#define ZORBA_RUNTIME_INTROSPECTION_DCTX_H


#include "common/shared_types.h"



#include "runtime/base/narybase.h"


namespace zorba {

/**
 * dc:is-available-collection
 * 
 * Author: Zorba Team * 
 */
class IsAvailableCollectionIterator : public NaryBaseIterator <IsAvailableCollectionIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsAvailableCollectionIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsAvailableCollectionIterator,
    NaryBaseIterator <IsAvailableCollectionIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator <IsAvailableCollectionIterator, PlanIteratorState>*)this);
  }

  IsAvailableCollectionIterator(
    static_context* sctx,
    const QueryLoc& loc
    , std::vector<PlanIter_t>& aChildren)
    : NaryBaseIterator <IsAvailableCollectionIterator, PlanIteratorState>
    (sctx, loc, aChildren) {}

  virtual ~IsAvailableCollectionIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * dc:available-collections
 * 
 * Author: Zorba Team * 
 */
class AvailableCollectionsIteratorState : public PlanIteratorState
{
public:
  store::Iterator_t nameItState; //the current iterator

  AvailableCollectionsIteratorState();

  ~AvailableCollectionsIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class AvailableCollectionsIterator : public NaryBaseIterator <AvailableCollectionsIterator, AvailableCollectionsIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(AvailableCollectionsIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(AvailableCollectionsIterator,
    NaryBaseIterator <AvailableCollectionsIterator, AvailableCollectionsIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator <AvailableCollectionsIterator, AvailableCollectionsIteratorState>*)this);
  }

  AvailableCollectionsIterator(
    static_context* sctx,
    const QueryLoc& loc
    , std::vector<PlanIter_t>& aChildren)
    : NaryBaseIterator <AvailableCollectionsIterator, AvailableCollectionsIteratorState>
    (sctx, loc, aChildren) {}

  virtual ~AvailableCollectionsIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


}
#endif
/*
 * Local variables:
 * mode: c++
 * End:
 */ 
