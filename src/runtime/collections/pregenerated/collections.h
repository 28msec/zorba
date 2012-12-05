/*
 * Copyright 2006-2012 The FLWOR Foundation.
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
#include "runtime/collections/collections_base.h"


namespace zorba {
class StaticallyKnownCollection;
/**
 * 
 *      zorba:create
 *    
 * Author: Zorba Team
 */
class ZorbaCreateCollectionIterator : public NaryBaseIterator<ZorbaCreateCollectionIterator, PlanIteratorState>
{ 
protected:
  bool theIsDynamic; //
public:
  SERIALIZABLE_CLASS(ZorbaCreateCollectionIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaCreateCollectionIterator,
    NaryBaseIterator<ZorbaCreateCollectionIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  ZorbaCreateCollectionIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children,
    bool isDynamic)
    : 
    NaryBaseIterator<ZorbaCreateCollectionIterator, PlanIteratorState>(sctx, loc, children),
    theIsDynamic(isDynamic)
  {}

  virtual ~ZorbaCreateCollectionIterator();

public:
  const StaticallyKnownCollection* getCollection(const store::Item_t& name, store::Collection_t& coll) const;
  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      zorba:delete
 *    
 * Author: Zorba Team
 */
class ZorbaDeleteCollectionIterator : public NaryBaseIterator<ZorbaDeleteCollectionIterator, PlanIteratorState>
{ 
protected:
  bool theIsDynamic; //
public:
  SERIALIZABLE_CLASS(ZorbaDeleteCollectionIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaDeleteCollectionIterator,
    NaryBaseIterator<ZorbaDeleteCollectionIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  ZorbaDeleteCollectionIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children,
    bool isDynamic)
    : 
    NaryBaseIterator<ZorbaDeleteCollectionIterator, PlanIteratorState>(sctx, loc, children),
    theIsDynamic(isDynamic)
  {}

  virtual ~ZorbaDeleteCollectionIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      dc:is-available-collection
 *    
 * Author: Zorba Team
 */
class IsAvailableCollectionIterator : public NaryBaseIterator<IsAvailableCollectionIterator, PlanIteratorState>
{ 
protected:
  bool theIsDynamic; //
public:
  SERIALIZABLE_CLASS(IsAvailableCollectionIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsAvailableCollectionIterator,
    NaryBaseIterator<IsAvailableCollectionIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  IsAvailableCollectionIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children,
    bool isDynamic)
    : 
    NaryBaseIterator<IsAvailableCollectionIterator, PlanIteratorState>(sctx, loc, children),
    theIsDynamic(isDynamic)
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
  store::Iterator_t nameItState; //

  AvailableCollectionsIteratorState();

  ~AvailableCollectionsIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class AvailableCollectionsIterator : public NaryBaseIterator<AvailableCollectionsIterator, AvailableCollectionsIteratorState>
{ 
protected:
  bool theIsDynamic; //
public:
  SERIALIZABLE_CLASS(AvailableCollectionsIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(AvailableCollectionsIterator,
    NaryBaseIterator<AvailableCollectionsIterator, AvailableCollectionsIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  AvailableCollectionsIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children,
    bool isDynamic)
    : 
    NaryBaseIterator<AvailableCollectionsIterator, AvailableCollectionsIteratorState>(sctx, loc, children),
    theIsDynamic(isDynamic)
  {}

  virtual ~AvailableCollectionsIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      fn:collection
 *    
 * Author: Zorba Team
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

class FnCollectionIterator : public NaryBaseIterator<FnCollectionIterator, FnCollectionIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FnCollectionIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnCollectionIterator,
    NaryBaseIterator<FnCollectionIterator, FnCollectionIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  FnCollectionIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FnCollectionIterator, FnCollectionIteratorState>(sctx, loc, children)
  {}

  virtual ~FnCollectionIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      zorba:collection
 *    
 * Author: Zorba Team
 */
class ZorbaCollectionIteratorState : public PlanIteratorState
{
public:
  store::Iterator_t theIterator; //
  bool theIteratorOpened; //

  ZorbaCollectionIteratorState();

  ~ZorbaCollectionIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class ZorbaCollectionIterator : public NaryBaseIterator<ZorbaCollectionIterator, ZorbaCollectionIteratorState>
{ 
protected:
  bool theIsDynamic; //
public:
  SERIALIZABLE_CLASS(ZorbaCollectionIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaCollectionIterator,
    NaryBaseIterator<ZorbaCollectionIterator, ZorbaCollectionIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  ZorbaCollectionIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children,
    bool isDynamic)
    : 
    NaryBaseIterator<ZorbaCollectionIterator, ZorbaCollectionIteratorState>(sctx, loc, children),
    theIsDynamic(isDynamic)
  {}

  virtual ~ZorbaCollectionIterator();

  bool isDynamic() const { return theIsDynamic; }

public:
  bool isCountOptimizable() const;
  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      zorba:collection-name
 *    
 * Author: Zorba Team
 */
class ZorbaCollectionNameIterator : public NaryBaseIterator<ZorbaCollectionNameIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ZorbaCollectionNameIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaCollectionNameIterator,
    NaryBaseIterator<ZorbaCollectionNameIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  ZorbaCollectionNameIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<ZorbaCollectionNameIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~ZorbaCollectionNameIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      zorba:index-of
 *    
 * Author: Zorba Team
 */
class ZorbaIndexOfIterator : public NaryBaseIterator<ZorbaIndexOfIterator, PlanIteratorState>
{ 
protected:
  bool theIsDynamic; //
public:
  SERIALIZABLE_CLASS(ZorbaIndexOfIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaIndexOfIterator,
    NaryBaseIterator<ZorbaIndexOfIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  ZorbaIndexOfIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children,
    bool isDynamic)
    : 
    NaryBaseIterator<ZorbaIndexOfIterator, PlanIteratorState>(sctx, loc, children),
    theIsDynamic(isDynamic)
  {}

  virtual ~ZorbaIndexOfIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      zorba:insert-nodes
 *    
 * Author: Zorba Team
 */
class ZorbaInsertNodesIterator : public ZorbaCollectionIteratorHelper<ZorbaInsertNodesIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ZorbaInsertNodesIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaInsertNodesIterator,
    ZorbaCollectionIteratorHelper<ZorbaInsertNodesIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  ZorbaInsertNodesIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children,
    bool isDynamic,
    bool needToCopy)
    : 
    ZorbaCollectionIteratorHelper<ZorbaInsertNodesIterator, PlanIteratorState>(sctx, loc, children, isDynamic, needToCopy)
  {}

  virtual ~ZorbaInsertNodesIterator();

public:
  const StaticallyKnownCollection* getCollection(const store::Item_t& name, store::Collection_t& coll) const;
  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      zorba:insert-nodes-first
 *    
 * Author: Zorba Team
 */
class ZorbaInsertNodesFirstIterator : public ZorbaCollectionIteratorHelper<ZorbaInsertNodesFirstIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ZorbaInsertNodesFirstIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaInsertNodesFirstIterator,
    ZorbaCollectionIteratorHelper<ZorbaInsertNodesFirstIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  ZorbaInsertNodesFirstIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children,
    bool isDynamic,
    bool needToCopy)
    : 
    ZorbaCollectionIteratorHelper<ZorbaInsertNodesFirstIterator, PlanIteratorState>(sctx, loc, children, isDynamic, needToCopy)
  {}

  virtual ~ZorbaInsertNodesFirstIterator();

public:
  const StaticallyKnownCollection* getCollection(const store::Item_t& name, store::Collection_t& coll) const;
  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      zorba:insert-nodes-last
 *    
 * Author: Zorba Team
 */
class ZorbaInsertNodesLastIterator : public ZorbaCollectionIteratorHelper<ZorbaInsertNodesLastIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ZorbaInsertNodesLastIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaInsertNodesLastIterator,
    ZorbaCollectionIteratorHelper<ZorbaInsertNodesLastIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  ZorbaInsertNodesLastIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children,
    bool isDynamic,
    bool needToCopy)
    : 
    ZorbaCollectionIteratorHelper<ZorbaInsertNodesLastIterator, PlanIteratorState>(sctx, loc, children, isDynamic, needToCopy)
  {}

  virtual ~ZorbaInsertNodesLastIterator();

public:
  const StaticallyKnownCollection* getCollection(const store::Item_t& name, store::Collection_t& coll) const;
  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      zorba:insert-nodes-before
 *    
 * Author: Zorba Team
 */
class ZorbaInsertNodesBeforeIterator : public ZorbaCollectionIteratorHelper<ZorbaInsertNodesBeforeIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ZorbaInsertNodesBeforeIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaInsertNodesBeforeIterator,
    ZorbaCollectionIteratorHelper<ZorbaInsertNodesBeforeIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  ZorbaInsertNodesBeforeIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children,
    bool isDynamic,
    bool needToCopy)
    : 
    ZorbaCollectionIteratorHelper<ZorbaInsertNodesBeforeIterator, PlanIteratorState>(sctx, loc, children, isDynamic, needToCopy)
  {}

  virtual ~ZorbaInsertNodesBeforeIterator();

public:
  const StaticallyKnownCollection* getCollection(const store::Item_t& name, store::Collection_t& coll) const;
  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      zorba:insert-nodes-after
 *    
 * Author: Zorba Team
 */
class ZorbaInsertNodesAfterIterator : public ZorbaCollectionIteratorHelper<ZorbaInsertNodesAfterIterator, PlanIteratorState>
{ 
protected:
  bool theIsDynamic; //
public:
  SERIALIZABLE_CLASS(ZorbaInsertNodesAfterIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaInsertNodesAfterIterator,
    ZorbaCollectionIteratorHelper<ZorbaInsertNodesAfterIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  ZorbaInsertNodesAfterIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children,
    bool isDynamic,
    bool needToCopy)
    : 
    ZorbaCollectionIteratorHelper<ZorbaInsertNodesAfterIterator, PlanIteratorState>(sctx, loc, children, isDynamic, needToCopy),
    theIsDynamic(isDynamic)
  {}

  virtual ~ZorbaInsertNodesAfterIterator();

public:
  const StaticallyKnownCollection* getCollection(const store::Item_t& name, store::Collection_t& coll) const;
  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      zorba:apply-insert-nodes
 *    
 * Author: Zorba Team
 */
class ZorbaApplyInsertNodesIteratorState : public PlanIteratorState
{
public:
  std::vector<store::Item_t> nodes; //the nodes that have been inserted
  std::vector<store::Item_t>::const_iterator iterator; //iterator over the nodes

  ZorbaApplyInsertNodesIteratorState();

  ~ZorbaApplyInsertNodesIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class ZorbaApplyInsertNodesIterator : public ZorbaCollectionIteratorHelper<ZorbaApplyInsertNodesIterator, ZorbaApplyInsertNodesIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ZorbaApplyInsertNodesIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaApplyInsertNodesIterator,
    ZorbaCollectionIteratorHelper<ZorbaApplyInsertNodesIterator, ZorbaApplyInsertNodesIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  ZorbaApplyInsertNodesIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children,
    bool isDynamic,
    bool needToCopy)
    : 
    ZorbaCollectionIteratorHelper<ZorbaApplyInsertNodesIterator, ZorbaApplyInsertNodesIteratorState>(sctx, loc, children, isDynamic, needToCopy)
  {}

  virtual ~ZorbaApplyInsertNodesIterator();

public:
  const StaticallyKnownCollection* getCollection(const store::Item_t& name, store::Collection_t& coll) const;
  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      zorba:apply-insertnodes-first
 *    
 * Author: Zorba Team
 */
class ZorbaApplyInsertNodesFirstIteratorState : public PlanIteratorState
{
public:
  std::vector<store::Item_t> nodes; //the nodes that have been inserted
  std::vector<store::Item_t>::const_iterator iterator; //iterator over the nodes

  ZorbaApplyInsertNodesFirstIteratorState();

  ~ZorbaApplyInsertNodesFirstIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class ZorbaApplyInsertNodesFirstIterator : public ZorbaCollectionIteratorHelper<ZorbaApplyInsertNodesFirstIterator, ZorbaApplyInsertNodesFirstIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ZorbaApplyInsertNodesFirstIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaApplyInsertNodesFirstIterator,
    ZorbaCollectionIteratorHelper<ZorbaApplyInsertNodesFirstIterator, ZorbaApplyInsertNodesFirstIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  ZorbaApplyInsertNodesFirstIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children,
    bool isDynamic,
    bool needToCopy)
    : 
    ZorbaCollectionIteratorHelper<ZorbaApplyInsertNodesFirstIterator, ZorbaApplyInsertNodesFirstIteratorState>(sctx, loc, children, isDynamic, needToCopy)
  {}

  virtual ~ZorbaApplyInsertNodesFirstIterator();

public:
  const StaticallyKnownCollection* getCollection(const store::Item_t& name, store::Collection_t& coll) const;
  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      zorba:apply-insertnodes-last
 *    
 * Author: Zorba Team
 */
class ZorbaApplyInsertNodesLastIteratorState : public PlanIteratorState
{
public:
  std::vector<store::Item_t> nodes; //the nodes that have been inserted
  std::vector<store::Item_t>::const_iterator iterator; //iterator over the nodes

  ZorbaApplyInsertNodesLastIteratorState();

  ~ZorbaApplyInsertNodesLastIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class ZorbaApplyInsertNodesLastIterator : public ZorbaCollectionIteratorHelper<ZorbaApplyInsertNodesLastIterator, ZorbaApplyInsertNodesLastIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ZorbaApplyInsertNodesLastIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaApplyInsertNodesLastIterator,
    ZorbaCollectionIteratorHelper<ZorbaApplyInsertNodesLastIterator, ZorbaApplyInsertNodesLastIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  ZorbaApplyInsertNodesLastIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children,
    bool isDynamic,
    bool needToCopy)
    : 
    ZorbaCollectionIteratorHelper<ZorbaApplyInsertNodesLastIterator, ZorbaApplyInsertNodesLastIteratorState>(sctx, loc, children, isDynamic, needToCopy)
  {}

  virtual ~ZorbaApplyInsertNodesLastIterator();

public:
  const StaticallyKnownCollection* getCollection(const store::Item_t& name, store::Collection_t& coll) const;
  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      zorba:apply-insert-nodes-before
 *    
 * Author: Zorba Team
 */
class ZorbaApplyInsertNodesBeforeIteratorState : public PlanIteratorState
{
public:
  std::vector<store::Item_t> nodes; //the nodes that have been inserted
  std::vector<store::Item_t>::const_iterator iterator; //iterator over the nodes

  ZorbaApplyInsertNodesBeforeIteratorState();

  ~ZorbaApplyInsertNodesBeforeIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class ZorbaApplyInsertNodesBeforeIterator : public ZorbaCollectionIteratorHelper<ZorbaApplyInsertNodesBeforeIterator, ZorbaApplyInsertNodesBeforeIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ZorbaApplyInsertNodesBeforeIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaApplyInsertNodesBeforeIterator,
    ZorbaCollectionIteratorHelper<ZorbaApplyInsertNodesBeforeIterator, ZorbaApplyInsertNodesBeforeIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  ZorbaApplyInsertNodesBeforeIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children,
    bool isDynamic,
    bool needToCopy)
    : 
    ZorbaCollectionIteratorHelper<ZorbaApplyInsertNodesBeforeIterator, ZorbaApplyInsertNodesBeforeIteratorState>(sctx, loc, children, isDynamic, needToCopy)
  {}

  virtual ~ZorbaApplyInsertNodesBeforeIterator();

public:
  const StaticallyKnownCollection* getCollection(const store::Item_t& name, store::Collection_t& coll) const;
  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      zorba:apply-insertnodes-after
 *    
 * Author: Zorba Team
 */
class ZorbaApplyInsertNodesAfterIteratorState : public PlanIteratorState
{
public:
  std::vector<store::Item_t> nodes; //the nodes that have been inserted
  std::vector<store::Item_t>::const_iterator iterator; //iterator over the nodes

  ZorbaApplyInsertNodesAfterIteratorState();

  ~ZorbaApplyInsertNodesAfterIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class ZorbaApplyInsertNodesAfterIterator : public ZorbaCollectionIteratorHelper<ZorbaApplyInsertNodesAfterIterator, ZorbaApplyInsertNodesAfterIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ZorbaApplyInsertNodesAfterIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaApplyInsertNodesAfterIterator,
    ZorbaCollectionIteratorHelper<ZorbaApplyInsertNodesAfterIterator, ZorbaApplyInsertNodesAfterIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  ZorbaApplyInsertNodesAfterIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children,
    bool isDynamic,
    bool needToCopy)
    : 
    ZorbaCollectionIteratorHelper<ZorbaApplyInsertNodesAfterIterator, ZorbaApplyInsertNodesAfterIteratorState>(sctx, loc, children, isDynamic, needToCopy)
  {}

  virtual ~ZorbaApplyInsertNodesAfterIterator();

public:
  const StaticallyKnownCollection* getCollection(const store::Item_t& name, store::Collection_t& coll) const;
  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      zorba:delete-nodes
 *    
 * Author: Zorba Team
 */
class ZorbaDeleteNodesIterator : public NaryBaseIterator<ZorbaDeleteNodesIterator, PlanIteratorState>
{ 
protected:
  bool theIsDynamic; //
public:
  SERIALIZABLE_CLASS(ZorbaDeleteNodesIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaDeleteNodesIterator,
    NaryBaseIterator<ZorbaDeleteNodesIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  ZorbaDeleteNodesIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children,
    bool isDynamic)
    : 
    NaryBaseIterator<ZorbaDeleteNodesIterator, PlanIteratorState>(sctx, loc, children),
    theIsDynamic(isDynamic)
  {}

  virtual ~ZorbaDeleteNodesIterator();

public:
  const StaticallyKnownCollection* getCollection(const store::Item_t& name, store::Collection_t& coll) const;
  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      zorba:delete-node-first
 *    
 * Author: Zorba Team
 */
class ZorbaDeleteNodesFirstIterator : public NaryBaseIterator<ZorbaDeleteNodesFirstIterator, PlanIteratorState>
{ 
protected:
  bool theIsDynamic; //
public:
  SERIALIZABLE_CLASS(ZorbaDeleteNodesFirstIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaDeleteNodesFirstIterator,
    NaryBaseIterator<ZorbaDeleteNodesFirstIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  ZorbaDeleteNodesFirstIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children,
    bool isDynamic)
    : 
    NaryBaseIterator<ZorbaDeleteNodesFirstIterator, PlanIteratorState>(sctx, loc, children),
    theIsDynamic(isDynamic)
  {}

  virtual ~ZorbaDeleteNodesFirstIterator();

public:
  const StaticallyKnownCollection* getCollection(const store::Item_t& name, store::Collection_t& coll) const;
  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      zorba:delete-node-last
 *    
 * Author: Zorba Team
 */
class ZorbaDeleteNodesLastIterator : public NaryBaseIterator<ZorbaDeleteNodesLastIterator, PlanIteratorState>
{ 
protected:
  bool theIsDynamic; //
public:
  SERIALIZABLE_CLASS(ZorbaDeleteNodesLastIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaDeleteNodesLastIterator,
    NaryBaseIterator<ZorbaDeleteNodesLastIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  ZorbaDeleteNodesLastIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children,
    bool isDynamic)
    : 
    NaryBaseIterator<ZorbaDeleteNodesLastIterator, PlanIteratorState>(sctx, loc, children),
    theIsDynamic(isDynamic)
  {}

  virtual ~ZorbaDeleteNodesLastIterator();

public:
  const StaticallyKnownCollection* getCollection(const store::Item_t& name, store::Collection_t& coll) const;
  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      zorba:replace
 *    
 * Author: Zorba Team
 */
class ZorbaReplaceNodesIterator : public NaryBaseIterator<ZorbaReplaceNodesIterator, PlanIteratorState>
{ 
protected:
  bool theIsDynamic; //
public:
  SERIALIZABLE_CLASS(ZorbaReplaceNodesIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaReplaceNodesIterator,
    NaryBaseIterator<ZorbaReplaceNodesIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  ZorbaReplaceNodesIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children,
    bool isDynamic)
    : 
    NaryBaseIterator<ZorbaReplaceNodesIterator, PlanIteratorState>(sctx, loc, children),
    theIsDynamic(isDynamic)
  {}

  virtual ~ZorbaReplaceNodesIterator();

public:
  const StaticallyKnownCollection* getCollection(const store::Item_t& name, store::Collection_t& coll) const;
  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      zorba:truncate
 *    
 * Author: Zorba Team
 */
class ZorbaTruncateCollectionIterator : public NaryBaseIterator<ZorbaTruncateCollectionIterator, PlanIteratorState>
{ 
protected:
  bool theIsDynamic; //
public:
  SERIALIZABLE_CLASS(ZorbaTruncateCollectionIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaTruncateCollectionIterator,
    NaryBaseIterator<ZorbaTruncateCollectionIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  ZorbaTruncateCollectionIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children,
    bool isDynamic)
    : 
    NaryBaseIterator<ZorbaTruncateCollectionIterator, PlanIteratorState>(sctx, loc, children),
    theIsDynamic(isDynamic)
  {}

  virtual ~ZorbaTruncateCollectionIterator();

public:
  const StaticallyKnownCollection* getCollection(const store::Item_t& name, store::Collection_t& coll) const;
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

  void serialize( ::zorba::serialization::Archiver& ar);

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

  void serialize( ::zorba::serialization::Archiver& ar);

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

  void serialize( ::zorba::serialization::Archiver& ar);

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
  store::Iterator_t nameItState; //

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

  void serialize( ::zorba::serialization::Archiver& ar);

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


/**
 * 
 *      sc:is-declared-collection
 *    
 * Author: Zorba Team
 */
class IsDeclaredCollectionIterator : public NaryBaseIterator<IsDeclaredCollectionIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsDeclaredCollectionIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsDeclaredCollectionIterator,
    NaryBaseIterator<IsDeclaredCollectionIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  IsDeclaredCollectionIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsDeclaredCollectionIterator, PlanIteratorState>(sctx, loc, children)
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
  store::Iterator_t nameItState; //

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

  void serialize( ::zorba::serialization::Archiver& ar);

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
class IsDeclaredIndexIterator : public NaryBaseIterator<IsDeclaredIndexIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsDeclaredIndexIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsDeclaredIndexIterator,
    NaryBaseIterator<IsDeclaredIndexIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  IsDeclaredIndexIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsDeclaredIndexIterator, PlanIteratorState>(sctx, loc, children)
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

  void serialize( ::zorba::serialization::Archiver& ar);

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


/**
 * 
 *      sc:is-declared-integrity-constraint
 *    
 * Author: Zorba Team
 */
class IsDeclaredICIterator : public NaryBaseIterator<IsDeclaredICIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsDeclaredICIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsDeclaredICIterator,
    NaryBaseIterator<IsDeclaredICIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  IsDeclaredICIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsDeclaredICIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsDeclaredICIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      sc:declared-integrity-constrints
 *    
 * Author: Zorba Team
 */
class DeclaredICsIteratorState : public PlanIteratorState
{
public:
  store::Iterator_t nameItState; //

  DeclaredICsIteratorState();

  ~DeclaredICsIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class DeclaredICsIterator : public NaryBaseIterator<DeclaredICsIterator, DeclaredICsIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(DeclaredICsIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(DeclaredICsIterator,
    NaryBaseIterator<DeclaredICsIterator, DeclaredICsIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  DeclaredICsIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<DeclaredICsIterator, DeclaredICsIteratorState>(sctx, loc, children)
  {}

  virtual ~DeclaredICsIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *    Returns a sequence of xs:anyURI values representing the document URIs of the 
 *    documents in a collection.
 *  
 * Author: Zorba Team
 */
class FnURICollectionIteratorState : public PlanIteratorState
{
public:
  store::Iterator_t theIterator; //the current iterator
  bool theIteratorOpened; //flag indicating whether theIterator was opened

  FnURICollectionIteratorState();

  ~FnURICollectionIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class FnURICollectionIterator : public NaryBaseIterator<FnURICollectionIterator, FnURICollectionIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FnURICollectionIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnURICollectionIterator,
    NaryBaseIterator<FnURICollectionIterator, FnURICollectionIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  FnURICollectionIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FnURICollectionIterator, FnURICollectionIteratorState>(sctx, loc, children)
  {}

  virtual ~FnURICollectionIterator();

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
