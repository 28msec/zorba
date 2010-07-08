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
 * 
 *      dc:is-available-collection
 *    
 * Author: Zorba Team
 */
class IsAvailableCollectionIterator : public NaryBaseIterator<IsAvailableCollectionIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsAvailableCollectionIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsAvailableCollectionIterator,
    NaryBaseIterator<IsAvailableCollectionIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsAvailableCollectionIterator, PlanIteratorState>*)this);
  }

  IsAvailableCollectionIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsAvailableCollectionIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsAvailableCollectionIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      dc:available-collections
 *    
 * Author: Zorba Team
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

class AvailableCollectionsIterator : public NaryBaseIterator<AvailableCollectionsIterator, AvailableCollectionsIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(AvailableCollectionsIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(AvailableCollectionsIterator,
    NaryBaseIterator<AvailableCollectionsIterator, AvailableCollectionsIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<AvailableCollectionsIterator, AvailableCollectionsIteratorState>*)this);
  }

  AvailableCollectionsIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<AvailableCollectionsIterator, AvailableCollectionsIteratorState>(sctx, loc, children)
  {}

  virtual ~AvailableCollectionsIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      dc:is-available-index
 *    
 * Author: Zorba Team
 */
class IsAvailableIndexIterator : public NaryBaseIterator<IsAvailableIndexIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsAvailableIndexIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsAvailableIndexIterator,
    NaryBaseIterator<IsAvailableIndexIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsAvailableIndexIterator, PlanIteratorState>*)this);
  }

  IsAvailableIndexIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsAvailableIndexIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsAvailableIndexIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      dc:available-indexes
 *    
 * Author: Zorba Team
 */
class AvailableIndexesIteratorState : public PlanIteratorState
{
public:
  store::Iterator_t nameItState; //the current iterator

  AvailableIndexesIteratorState();

  ~AvailableIndexesIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class AvailableIndexesIterator : public NaryBaseIterator<AvailableIndexesIterator, AvailableIndexesIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(AvailableIndexesIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(AvailableIndexesIterator,
    NaryBaseIterator<AvailableIndexesIterator, AvailableIndexesIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<AvailableIndexesIterator, AvailableIndexesIteratorState>*)this);
  }

  AvailableIndexesIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<AvailableIndexesIterator, AvailableIndexesIteratorState>(sctx, loc, children)
  {}

  virtual ~AvailableIndexesIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      dc:is-activated-integrity-constraint
 *    
 * Author: Zorba Team
 */
class IsActivatedICIterator : public NaryBaseIterator<IsActivatedICIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsActivatedICIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsActivatedICIterator,
    NaryBaseIterator<IsActivatedICIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsActivatedICIterator, PlanIteratorState>*)this);
  }

  IsActivatedICIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsActivatedICIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsActivatedICIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      dc:activated-integrity-constraints
 *    
 * Author: Zorba Team
 */
class ActivatedICsIteratorState : public PlanIteratorState
{
public:
  store::Iterator_t nameItState; //the current iterator

  ActivatedICsIteratorState();

  ~ActivatedICsIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class ActivatedICsIterator : public NaryBaseIterator<ActivatedICsIterator, ActivatedICsIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ActivatedICsIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ActivatedICsIterator,
    NaryBaseIterator<ActivatedICsIterator, ActivatedICsIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<ActivatedICsIterator, ActivatedICsIteratorState>*)this);
  }

  ActivatedICsIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<ActivatedICsIterator, ActivatedICsIteratorState>(sctx, loc, children)
  {}

  virtual ~ActivatedICsIterator();

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
