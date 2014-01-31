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
 * Author: 
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
 * Author: 
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
 * Author: 
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
 * Author: 
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
 * Author: 
 */
class FnCollectionIteratorState : public PlanIteratorState
{
public:
  store::Iterator_t theIterator; //
  bool theIteratorOpened; //

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

public:
  bool count(store::Item_t& result, PlanState& planState) const;
  store::Collection_t getCollection(PlanState& planState) const;
  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
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
  bool count(store::Item_t& result, PlanState& planState) const;
  bool skip(int64_t count, PlanState& planState) const;
  void initCollection(PlanState& planState, int64_t skipCount) const;
  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
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
 * Author: 
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
 * Author: 
 */
class ZorbaApplyInsertIteratorState : public PlanIteratorState
{
public:
  std::vector<store::Item_t> nodes; //the nodes that have been inserted
  std::vector<store::Item_t>::const_iterator iterator; //iterator over the nodes

  ZorbaApplyInsertIteratorState();

  ~ZorbaApplyInsertIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class ZorbaApplyInsertIterator : public ZorbaCollectionIteratorHelper<ZorbaApplyInsertIterator, ZorbaApplyInsertIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ZorbaApplyInsertIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaApplyInsertIterator,
    ZorbaCollectionIteratorHelper<ZorbaApplyInsertIterator, ZorbaApplyInsertIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  ZorbaApplyInsertIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children,
    bool isDynamic,
    bool needToCopy)
    : 
    ZorbaCollectionIteratorHelper<ZorbaApplyInsertIterator, ZorbaApplyInsertIteratorState>(sctx, loc, children, isDynamic, needToCopy)
  {}

  virtual ~ZorbaApplyInsertIterator();

public:
  const StaticallyKnownCollection* getCollection(const store::Item_t& name, store::Collection_t& coll) const;
  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
 */
class ZorbaInsertAfterIterator : public ZorbaCollectionIteratorHelper<ZorbaInsertAfterIterator, PlanIteratorState>
{ 
protected:
  bool theIsDynamic; //
public:
  SERIALIZABLE_CLASS(ZorbaInsertAfterIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaInsertAfterIterator,
    ZorbaCollectionIteratorHelper<ZorbaInsertAfterIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  ZorbaInsertAfterIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children,
    bool isDynamic,
    bool needToCopy)
    : 
    ZorbaCollectionIteratorHelper<ZorbaInsertAfterIterator, PlanIteratorState>(sctx, loc, children, isDynamic, needToCopy),
    theIsDynamic(isDynamic)
  {}

  virtual ~ZorbaInsertAfterIterator();

public:
  const StaticallyKnownCollection* getCollection(const store::Item_t& name, store::Collection_t& coll) const;
  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
 */
class ZorbaInsertBeforeIterator : public ZorbaCollectionIteratorHelper<ZorbaInsertBeforeIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ZorbaInsertBeforeIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaInsertBeforeIterator,
    ZorbaCollectionIteratorHelper<ZorbaInsertBeforeIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  ZorbaInsertBeforeIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children,
    bool isDynamic,
    bool needToCopy)
    : 
    ZorbaCollectionIteratorHelper<ZorbaInsertBeforeIterator, PlanIteratorState>(sctx, loc, children, isDynamic, needToCopy)
  {}

  virtual ~ZorbaInsertBeforeIterator();

public:
  const StaticallyKnownCollection* getCollection(const store::Item_t& name, store::Collection_t& coll) const;
  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
 */
class ZorbaInsertFirstIterator : public ZorbaCollectionIteratorHelper<ZorbaInsertFirstIterator,PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ZorbaInsertFirstIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaInsertFirstIterator,
    ZorbaCollectionIteratorHelper<ZorbaInsertFirstIterator,PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  ZorbaInsertFirstIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children,
    bool isDynamic,
    bool needToCopy)
    : 
    ZorbaCollectionIteratorHelper<ZorbaInsertFirstIterator,PlanIteratorState>(sctx, loc, children, isDynamic, needToCopy)
  {}

  virtual ~ZorbaInsertFirstIterator();

public:
  const StaticallyKnownCollection* getCollection(const store::Item_t& name, store::Collection_t& coll) const;
  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
 */
class ZorbaInsertLastIterator : public ZorbaCollectionIteratorHelper<ZorbaInsertLastIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ZorbaInsertLastIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaInsertLastIterator,
    ZorbaCollectionIteratorHelper<ZorbaInsertLastIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  ZorbaInsertLastIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children,
    bool isDynamic,
    bool needToCopy)
    : 
    ZorbaCollectionIteratorHelper<ZorbaInsertLastIterator, PlanIteratorState>(sctx, loc, children, isDynamic, needToCopy)
  {}

  virtual ~ZorbaInsertLastIterator();

public:
  const StaticallyKnownCollection* getCollection(const store::Item_t& name, store::Collection_t& coll) const;
  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
 */
class ZorbaApplyInsertFirstIteratorState : public PlanIteratorState
{
public:
  std::vector<store::Item_t> nodes; //the nodes that have been inserted
  std::vector<store::Item_t>::const_iterator iterator; //iterator over the nodes

  ZorbaApplyInsertFirstIteratorState();

  ~ZorbaApplyInsertFirstIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class ZorbaApplyInsertFirstIterator : public ZorbaCollectionIteratorHelper<ZorbaApplyInsertFirstIterator, ZorbaApplyInsertFirstIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ZorbaApplyInsertFirstIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaApplyInsertFirstIterator,
    ZorbaCollectionIteratorHelper<ZorbaApplyInsertFirstIterator, ZorbaApplyInsertFirstIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  ZorbaApplyInsertFirstIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children,
    bool isDynamic,
    bool needToCopy)
    : 
    ZorbaCollectionIteratorHelper<ZorbaApplyInsertFirstIterator, ZorbaApplyInsertFirstIteratorState>(sctx, loc, children, isDynamic, needToCopy)
  {}

  virtual ~ZorbaApplyInsertFirstIterator();

public:
  const StaticallyKnownCollection* getCollection(const store::Item_t& name, store::Collection_t& coll) const;
  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
 */
class ZorbaApplyInsertLastIteratorState : public PlanIteratorState
{
public:
  std::vector<store::Item_t> nodes; //the nodes that have been inserted
  std::vector<store::Item_t>::const_iterator iterator; //iterator over the nodes

  ZorbaApplyInsertLastIteratorState();

  ~ZorbaApplyInsertLastIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class ZorbaApplyInsertLastIterator : public ZorbaCollectionIteratorHelper<ZorbaApplyInsertLastIterator, ZorbaApplyInsertLastIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ZorbaApplyInsertLastIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaApplyInsertLastIterator,
    ZorbaCollectionIteratorHelper<ZorbaApplyInsertLastIterator, ZorbaApplyInsertLastIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  ZorbaApplyInsertLastIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children,
    bool isDynamic,
    bool needToCopy)
    : 
    ZorbaCollectionIteratorHelper<ZorbaApplyInsertLastIterator, ZorbaApplyInsertLastIteratorState>(sctx, loc, children, isDynamic, needToCopy)
  {}

  virtual ~ZorbaApplyInsertLastIterator();

public:
  const StaticallyKnownCollection* getCollection(const store::Item_t& name, store::Collection_t& coll) const;
  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
 */
class ZorbaApplyInsertBeforeIteratorState : public PlanIteratorState
{
public:
  std::vector<store::Item_t> nodes; //the nodes that have been inserted
  std::vector<store::Item_t>::const_iterator iterator; //iterator over the nodes

  ZorbaApplyInsertBeforeIteratorState();

  ~ZorbaApplyInsertBeforeIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class ZorbaApplyInsertBeforeIterator : public ZorbaCollectionIteratorHelper<ZorbaApplyInsertBeforeIterator, ZorbaApplyInsertBeforeIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ZorbaApplyInsertBeforeIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaApplyInsertBeforeIterator,
    ZorbaCollectionIteratorHelper<ZorbaApplyInsertBeforeIterator, ZorbaApplyInsertBeforeIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  ZorbaApplyInsertBeforeIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children,
    bool isDynamic,
    bool needToCopy)
    : 
    ZorbaCollectionIteratorHelper<ZorbaApplyInsertBeforeIterator, ZorbaApplyInsertBeforeIteratorState>(sctx, loc, children, isDynamic, needToCopy)
  {}

  virtual ~ZorbaApplyInsertBeforeIterator();

public:
  const StaticallyKnownCollection* getCollection(const store::Item_t& name, store::Collection_t& coll) const;
  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
 */
class ZorbaApplyInsertAfterIteratorState : public PlanIteratorState
{
public:
  std::vector<store::Item_t> nodes; //the nodes that have been inserted
  std::vector<store::Item_t>::const_iterator iterator; //iterator over the nodes

  ZorbaApplyInsertAfterIteratorState();

  ~ZorbaApplyInsertAfterIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class ZorbaApplyInsertAfterIterator : public ZorbaCollectionIteratorHelper<ZorbaApplyInsertAfterIterator, ZorbaApplyInsertAfterIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ZorbaApplyInsertAfterIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaApplyInsertAfterIterator,
    ZorbaCollectionIteratorHelper<ZorbaApplyInsertAfterIterator, ZorbaApplyInsertAfterIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  ZorbaApplyInsertAfterIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children,
    bool isDynamic,
    bool needToCopy)
    : 
    ZorbaCollectionIteratorHelper<ZorbaApplyInsertAfterIterator, ZorbaApplyInsertAfterIteratorState>(sctx, loc, children, isDynamic, needToCopy)
  {}

  virtual ~ZorbaApplyInsertAfterIterator();

public:
  const StaticallyKnownCollection* getCollection(const store::Item_t& name, store::Collection_t& coll) const;
  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
 */
class ZorbaDeleteIterator : public NaryBaseIterator<ZorbaDeleteIterator, PlanIteratorState>
{ 
protected:
  bool theIsDynamic; //
public:
  SERIALIZABLE_CLASS(ZorbaDeleteIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaDeleteIterator,
    NaryBaseIterator<ZorbaDeleteIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  ZorbaDeleteIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children,
    bool isDynamic)
    : 
    NaryBaseIterator<ZorbaDeleteIterator, PlanIteratorState>(sctx, loc, children),
    theIsDynamic(isDynamic)
  {}

  virtual ~ZorbaDeleteIterator();

public:
  const StaticallyKnownCollection* getCollection(const store::Item_t& name, store::Collection_t& coll) const;
  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
 */
class ZorbaDeleteFirstIterator : public NaryBaseIterator<ZorbaDeleteFirstIterator, PlanIteratorState>
{ 
protected:
  bool theIsDynamic; //
public:
  SERIALIZABLE_CLASS(ZorbaDeleteFirstIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaDeleteFirstIterator,
    NaryBaseIterator<ZorbaDeleteFirstIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  ZorbaDeleteFirstIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children,
    bool isDynamic)
    : 
    NaryBaseIterator<ZorbaDeleteFirstIterator, PlanIteratorState>(sctx, loc, children),
    theIsDynamic(isDynamic)
  {}

  virtual ~ZorbaDeleteFirstIterator();

public:
  const StaticallyKnownCollection* getCollection(const store::Item_t& name, store::Collection_t& coll) const;
  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
 */
class ZorbaDeleteLastIterator : public NaryBaseIterator<ZorbaDeleteLastIterator, PlanIteratorState>
{ 
protected:
  bool theIsDynamic; //
public:
  SERIALIZABLE_CLASS(ZorbaDeleteLastIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaDeleteLastIterator,
    NaryBaseIterator<ZorbaDeleteLastIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  ZorbaDeleteLastIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children,
    bool isDynamic)
    : 
    NaryBaseIterator<ZorbaDeleteLastIterator, PlanIteratorState>(sctx, loc, children),
    theIsDynamic(isDynamic)
  {}

  virtual ~ZorbaDeleteLastIterator();

public:
  const StaticallyKnownCollection* getCollection(const store::Item_t& name, store::Collection_t& coll) const;
  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
 */
class ZorbaEditIterator : public NaryBaseIterator<ZorbaEditIterator, PlanIteratorState>
{ 
protected:
  bool theIsDynamic; //
  bool theNeedToCopy; //
public:
  SERIALIZABLE_CLASS(ZorbaEditIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaEditIterator,
    NaryBaseIterator<ZorbaEditIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  ZorbaEditIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children,
    bool isDynamic,
    bool needToCopy)
    : 
    NaryBaseIterator<ZorbaEditIterator, PlanIteratorState>(sctx, loc, children),
    theIsDynamic(isDynamic),
    theNeedToCopy(needToCopy)
  {}

  virtual ~ZorbaEditIterator();

public:
  const StaticallyKnownCollection* getCollection(const store::Item_t& name, store::Collection_t& coll) const;
  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
 */
class ZorbaInsertIterator : public ZorbaCollectionIteratorHelper<ZorbaInsertIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ZorbaInsertIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaInsertIterator,
    ZorbaCollectionIteratorHelper<ZorbaInsertIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  ZorbaInsertIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children,
    bool isDynamic,
    bool needToCopy)
    : 
    ZorbaCollectionIteratorHelper<ZorbaInsertIterator, PlanIteratorState>(sctx, loc, children, isDynamic, needToCopy)
  {}

  virtual ~ZorbaInsertIterator();

public:
  const StaticallyKnownCollection* getCollection(const store::Item_t& name, store::Collection_t& coll) const;
  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
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
 * Author: 
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
 * Author: 
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
 * Author: 
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
 * Author: 
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
 * Author: 
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
 * Author: 
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
 * Author: 
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
 * Author: 
 */
class DeclaredIndexesIteratorState : public PlanIteratorState
{
public:
  store::Iterator_t nameItState; //

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
 * Author: 
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
 * Author: 
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
 * Author: 
 */
class FnURICollectionIteratorState : public PlanIteratorState
{
public:
  store::Iterator_t theIterator; //
  bool theIteratorOpened; //

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
