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
#ifndef ZORBA_RUNTIME_INTROSPECTION_SCTX_H
#define ZORBA_RUNTIME_INTROSPECTION_SCTX_H


#include "common/shared_types.h"



#include "runtime/base/narybase.h"


namespace zorba {

/**
 * 
 *      sc:is-declared-collection
 *    
 * Author: Zorba Team
 */
class IsDeclaredCollectionIteratorState : public PlanIteratorState
{
public:
  store::Iterator_t nameItState; //the current iterator

  IsDeclaredCollectionIteratorState();

  ~IsDeclaredCollectionIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class IsDeclaredCollectionIterator : public NaryBaseIterator<IsDeclaredCollectionIterator, IsDeclaredCollectionIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsDeclaredCollectionIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsDeclaredCollectionIterator,
    NaryBaseIterator<IsDeclaredCollectionIterator, IsDeclaredCollectionIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsDeclaredCollectionIterator, IsDeclaredCollectionIteratorState>*)this);
  }

  IsDeclaredCollectionIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsDeclaredCollectionIterator, IsDeclaredCollectionIteratorState>(sctx, loc, children)
  {}

  virtual ~IsDeclaredCollectionIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      sc:declared-collections
 *    
 * Author: Zorba Team
 */
class DeclaredCollectionsIteratorState : public PlanIteratorState
{
public:
  store::Iterator_t nameItState; //the current iterator

  DeclaredCollectionsIteratorState();

  ~DeclaredCollectionsIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class DeclaredCollectionsIterator : public NaryBaseIterator<DeclaredCollectionsIterator, DeclaredCollectionsIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(DeclaredCollectionsIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(DeclaredCollectionsIterator,
    NaryBaseIterator<DeclaredCollectionsIterator, DeclaredCollectionsIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<DeclaredCollectionsIterator, DeclaredCollectionsIteratorState>*)this);
  }

  DeclaredCollectionsIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<DeclaredCollectionsIterator, DeclaredCollectionsIteratorState>(sctx, loc, children)
  {}

  virtual ~DeclaredCollectionsIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      sc:is-declared-index
 *    
 * Author: Zorba Team
 */
class IsDeclaredIndexIteratorState : public PlanIteratorState
{
public:
  store::Iterator_t nameItState; //the current iterator

  IsDeclaredIndexIteratorState();

  ~IsDeclaredIndexIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class IsDeclaredIndexIterator : public NaryBaseIterator<IsDeclaredIndexIterator, IsDeclaredIndexIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsDeclaredIndexIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsDeclaredIndexIterator,
    NaryBaseIterator<IsDeclaredIndexIterator, IsDeclaredIndexIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsDeclaredIndexIterator, IsDeclaredIndexIteratorState>*)this);
  }

  IsDeclaredIndexIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsDeclaredIndexIterator, IsDeclaredIndexIteratorState>(sctx, loc, children)
  {}

  virtual ~IsDeclaredIndexIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      sc:declared-indexes
 *    
 * Author: Zorba Team
 */
class DeclaredIndexesIteratorState : public PlanIteratorState
{
public:
  store::Iterator_t nameItState; //the current iterator

  DeclaredIndexesIteratorState();

  ~DeclaredIndexesIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class DeclaredIndexesIterator : public NaryBaseIterator<DeclaredIndexesIterator, DeclaredIndexesIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(DeclaredIndexesIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(DeclaredIndexesIterator,
    NaryBaseIterator<DeclaredIndexesIterator, DeclaredIndexesIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<DeclaredIndexesIterator, DeclaredIndexesIteratorState>*)this);
  }

  DeclaredIndexesIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<DeclaredIndexesIterator, DeclaredIndexesIteratorState>(sctx, loc, children)
  {}

  virtual ~DeclaredIndexesIterator();

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
