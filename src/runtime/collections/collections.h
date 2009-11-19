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
#ifndef ZORBA_RUNTIME_COLLECTIONS_COLLECTIONS_H
#define ZORBA_RUNTIME_COLLECTIONS_COLLECTIONS_H


#include "common/shared_types.h"



#include "runtime/base/narybase.h"


namespace zorba {

/**
 * fn:collection
 * 
 * Author: Zorba Team * 
 */
class FnCollectionIteratorState : public PlanIteratorState
{
public:
  store::Iterator_t theIterator; //the current iterator
  bool theIteratorOpened; //flag indicating whether theIterator was opened

  FnCollectionIteratorState();

  ~FnCollectionIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class FnCollectionIterator : public NaryBaseIterator <FnCollectionIterator, FnCollectionIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FnCollectionIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnCollectionIterator,
    NaryBaseIterator <FnCollectionIterator, FnCollectionIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator <FnCollectionIterator, FnCollectionIteratorState>*)this);
  }

  FnCollectionIterator(
    static_context* sctx,
    const QueryLoc& loc
    , std::vector<PlanIter_t>& aChildren)
    : NaryBaseIterator <FnCollectionIterator, FnCollectionIteratorState>
    (sctx, loc, aChildren) {}

  virtual ~FnCollectionIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * zorba:collection
 * 
 * Author: Zorba Team * 
 */
class ZorbaCollectionIteratorState : public PlanIteratorState
{
public:
  store::Iterator_t theIterator; //the current iterator
  bool theIteratorOpened; //flag indicating whether theIterator was opened

  ZorbaCollectionIteratorState();

  ~ZorbaCollectionIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class ZorbaCollectionIterator : public NaryBaseIterator <ZorbaCollectionIterator, ZorbaCollectionIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ZorbaCollectionIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaCollectionIterator,
    NaryBaseIterator <ZorbaCollectionIterator, ZorbaCollectionIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator <ZorbaCollectionIterator, ZorbaCollectionIteratorState>*)this);
  }

  ZorbaCollectionIterator(
    static_context* sctx,
    const QueryLoc& loc
    , std::vector<PlanIter_t>& aChildren)
    : NaryBaseIterator <ZorbaCollectionIterator, ZorbaCollectionIteratorState>
    (sctx, loc, aChildren) {}

  virtual ~ZorbaCollectionIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * zorba:index-of
 * 
 * Author: Zorba Team * 
 */
class ZorbaIndexOfIterator : public NaryBaseIterator <ZorbaIndexOfIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ZorbaIndexOfIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaIndexOfIterator,
    NaryBaseIterator <ZorbaIndexOfIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator <ZorbaIndexOfIterator, PlanIteratorState>*)this);
  }

  ZorbaIndexOfIterator(
    static_context* sctx,
    const QueryLoc& loc
    , std::vector<PlanIter_t>& aChildren)
    : NaryBaseIterator <ZorbaIndexOfIterator, PlanIteratorState>
    (sctx, loc, aChildren) {}

  virtual ~ZorbaIndexOfIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * zorba:create-collection
 * 
 * Author: Zorba Team * 
 */
class ZorbaCreateCollectionIterator : public NaryBaseIterator <ZorbaCreateCollectionIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ZorbaCreateCollectionIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaCreateCollectionIterator,
    NaryBaseIterator <ZorbaCreateCollectionIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator <ZorbaCreateCollectionIterator, PlanIteratorState>*)this);
  }

  ZorbaCreateCollectionIterator(
    static_context* sctx,
    const QueryLoc& loc
    , std::vector<PlanIter_t>& aChildren)
    : NaryBaseIterator <ZorbaCreateCollectionIterator, PlanIteratorState>
    (sctx, loc, aChildren) {}

  virtual ~ZorbaCreateCollectionIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * zorba:drop-collection
 * 
 * Author: Zorba Team * 
 */
class ZorbaDropCollectionIterator : public NaryBaseIterator <ZorbaDropCollectionIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ZorbaDropCollectionIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaDropCollectionIterator,
    NaryBaseIterator <ZorbaDropCollectionIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator <ZorbaDropCollectionIterator, PlanIteratorState>*)this);
  }

  ZorbaDropCollectionIterator(
    static_context* sctx,
    const QueryLoc& loc
    , std::vector<PlanIter_t>& aChildren)
    : NaryBaseIterator <ZorbaDropCollectionIterator, PlanIteratorState>
    (sctx, loc, aChildren) {}

  virtual ~ZorbaDropCollectionIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * zorba:drop-all-collections
 * 
 * Author: Zorba Team * 
 */
class ZorbaDropAllCollectionsIterator : public NaryBaseIterator <ZorbaDropAllCollectionsIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ZorbaDropAllCollectionsIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaDropAllCollectionsIterator,
    NaryBaseIterator <ZorbaDropAllCollectionsIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator <ZorbaDropAllCollectionsIterator, PlanIteratorState>*)this);
  }

  ZorbaDropAllCollectionsIterator(
    static_context* sctx,
    const QueryLoc& loc
    , std::vector<PlanIter_t>& aChildren)
    : NaryBaseIterator <ZorbaDropAllCollectionsIterator, PlanIteratorState>
    (sctx, loc, aChildren) {}

  virtual ~ZorbaDropAllCollectionsIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * zorba:insert-nodes-first
 * 
 * Author: Zorba Team * 
 */
class ZorbaInsertNodesFirstIterator : public NaryBaseIterator <ZorbaInsertNodesFirstIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ZorbaInsertNodesFirstIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaInsertNodesFirstIterator,
    NaryBaseIterator <ZorbaInsertNodesFirstIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator <ZorbaInsertNodesFirstIterator, PlanIteratorState>*)this);
  }

  ZorbaInsertNodesFirstIterator(
    static_context* sctx,
    const QueryLoc& loc
    , std::vector<PlanIter_t>& aChildren)
    : NaryBaseIterator <ZorbaInsertNodesFirstIterator, PlanIteratorState>
    (sctx, loc, aChildren) {}

  virtual ~ZorbaInsertNodesFirstIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * zorba:insert-nodes-last
 * 
 * Author: Zorba Team * 
 */
class ZorbaInsertNodesLastIterator : public NaryBaseIterator <ZorbaInsertNodesLastIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ZorbaInsertNodesLastIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaInsertNodesLastIterator,
    NaryBaseIterator <ZorbaInsertNodesLastIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator <ZorbaInsertNodesLastIterator, PlanIteratorState>*)this);
  }

  ZorbaInsertNodesLastIterator(
    static_context* sctx,
    const QueryLoc& loc
    , std::vector<PlanIter_t>& aChildren)
    : NaryBaseIterator <ZorbaInsertNodesLastIterator, PlanIteratorState>
    (sctx, loc, aChildren) {}

  virtual ~ZorbaInsertNodesLastIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * zorba:insert-nodes-at
 * 
 * Author: Zorba Team * 
 */
class ZorbaInsertNodesAtIterator : public NaryBaseIterator <ZorbaInsertNodesAtIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ZorbaInsertNodesAtIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaInsertNodesAtIterator,
    NaryBaseIterator <ZorbaInsertNodesAtIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator <ZorbaInsertNodesAtIterator, PlanIteratorState>*)this);
  }

  ZorbaInsertNodesAtIterator(
    static_context* sctx,
    const QueryLoc& loc
    , std::vector<PlanIter_t>& aChildren)
    : NaryBaseIterator <ZorbaInsertNodesAtIterator, PlanIteratorState>
    (sctx, loc, aChildren) {}

  virtual ~ZorbaInsertNodesAtIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * zorba:insert-nodes-before
 * 
 * Author: Zorba Team * 
 */
class ZorbaInsertNodesBeforeIterator : public NaryBaseIterator <ZorbaInsertNodesBeforeIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ZorbaInsertNodesBeforeIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaInsertNodesBeforeIterator,
    NaryBaseIterator <ZorbaInsertNodesBeforeIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator <ZorbaInsertNodesBeforeIterator, PlanIteratorState>*)this);
  }

  ZorbaInsertNodesBeforeIterator(
    static_context* sctx,
    const QueryLoc& loc
    , std::vector<PlanIter_t>& aChildren)
    : NaryBaseIterator <ZorbaInsertNodesBeforeIterator, PlanIteratorState>
    (sctx, loc, aChildren) {}

  virtual ~ZorbaInsertNodesBeforeIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * zorba:insert-nodes-after
 * 
 * Author: Zorba Team * 
 */
class ZorbaInsertNodesAfterIterator : public NaryBaseIterator <ZorbaInsertNodesAfterIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ZorbaInsertNodesAfterIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaInsertNodesAfterIterator,
    NaryBaseIterator <ZorbaInsertNodesAfterIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator <ZorbaInsertNodesAfterIterator, PlanIteratorState>*)this);
  }

  ZorbaInsertNodesAfterIterator(
    static_context* sctx,
    const QueryLoc& loc
    , std::vector<PlanIter_t>& aChildren)
    : NaryBaseIterator <ZorbaInsertNodesAfterIterator, PlanIteratorState>
    (sctx, loc, aChildren) {}

  virtual ~ZorbaInsertNodesAfterIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * zorba:remove-nodes
 * 
 * Author: Zorba Team * 
 */
class ZorbaRemoveNodesIterator : public NaryBaseIterator <ZorbaRemoveNodesIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ZorbaRemoveNodesIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaRemoveNodesIterator,
    NaryBaseIterator <ZorbaRemoveNodesIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator <ZorbaRemoveNodesIterator, PlanIteratorState>*)this);
  }

  ZorbaRemoveNodesIterator(
    static_context* sctx,
    const QueryLoc& loc
    , std::vector<PlanIter_t>& aChildren)
    : NaryBaseIterator <ZorbaRemoveNodesIterator, PlanIteratorState>
    (sctx, loc, aChildren) {}

  virtual ~ZorbaRemoveNodesIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * zorba:remove-node-at TODO: deprecate
 * 
 * Author: Zorba Team * 
 */
class ZorbaRemoveNodeAtIterator : public NaryBaseIterator <ZorbaRemoveNodeAtIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ZorbaRemoveNodeAtIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaRemoveNodeAtIterator,
    NaryBaseIterator <ZorbaRemoveNodeAtIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator <ZorbaRemoveNodeAtIterator, PlanIteratorState>*)this);
  }

  ZorbaRemoveNodeAtIterator(
    static_context* sctx,
    const QueryLoc& loc
    , std::vector<PlanIter_t>& aChildren)
    : NaryBaseIterator <ZorbaRemoveNodeAtIterator, PlanIteratorState>
    (sctx, loc, aChildren) {}

  virtual ~ZorbaRemoveNodeAtIterator();

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
