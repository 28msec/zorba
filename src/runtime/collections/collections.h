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
 * 
 *      zorba:collection
 *    
 * Author: Zorba Team
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
 * 
 *      zorba:index-of
 *    
 * Author: Zorba Team
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
 * 
 *      zorba:create-collection
 *    
 * Author: Zorba Team
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
 * 
 *      zorba:delete-collection
 *    
 * Author: Zorba Team
 */
class ZorbaDeleteCollectionIterator : public NaryBaseIterator <ZorbaDeleteCollectionIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ZorbaDeleteCollectionIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaDeleteCollectionIterator,
    NaryBaseIterator <ZorbaDeleteCollectionIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator <ZorbaDeleteCollectionIterator, PlanIteratorState>*)this);
  }

  ZorbaDeleteCollectionIterator(
    static_context* sctx,
    const QueryLoc& loc
    , std::vector<PlanIter_t>& aChildren)
    : NaryBaseIterator <ZorbaDeleteCollectionIterator, PlanIteratorState>
    (sctx, loc, aChildren) {}

  virtual ~ZorbaDeleteCollectionIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      zorba:insert-nodes
 *    
 * Author: Zorba Team
 */
class ZorbaInsertNodesIterator : public NaryBaseIterator <ZorbaInsertNodesIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ZorbaInsertNodesIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaInsertNodesIterator,
    NaryBaseIterator <ZorbaInsertNodesIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator <ZorbaInsertNodesIterator, PlanIteratorState>*)this);
  }

  ZorbaInsertNodesIterator(
    static_context* sctx,
    const QueryLoc& loc
    , std::vector<PlanIter_t>& aChildren)
    : NaryBaseIterator <ZorbaInsertNodesIterator, PlanIteratorState>
    (sctx, loc, aChildren) {}

  virtual ~ZorbaInsertNodesIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      zorba:insert-nodes-first
 *    
 * Author: Zorba Team
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
 * 
 *      zorba:insert-nodes-last
 *    
 * Author: Zorba Team
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
 * 
 *      zorba:insert-nodes-before
 *    
 * Author: Zorba Team
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
 * 
 *      zorba:insert-nodes-after
 *    
 * Author: Zorba Team
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
 * 
 *      zorba:delete-nodes
 *    
 * Author: Zorba Team
 */
class ZorbaDeleteNodesIterator : public NaryBaseIterator <ZorbaDeleteNodesIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ZorbaDeleteNodesIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaDeleteNodesIterator,
    NaryBaseIterator <ZorbaDeleteNodesIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator <ZorbaDeleteNodesIterator, PlanIteratorState>*)this);
  }

  ZorbaDeleteNodesIterator(
    static_context* sctx,
    const QueryLoc& loc
    , std::vector<PlanIter_t>& aChildren)
    : NaryBaseIterator <ZorbaDeleteNodesIterator, PlanIteratorState>
    (sctx, loc, aChildren) {}

  virtual ~ZorbaDeleteNodesIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      zorba:delete-node-first
 *    
 * Author: Zorba Team
 */
class ZorbaDeleteNodeFirstIterator : public NaryBaseIterator <ZorbaDeleteNodeFirstIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ZorbaDeleteNodeFirstIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaDeleteNodeFirstIterator,
    NaryBaseIterator <ZorbaDeleteNodeFirstIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator <ZorbaDeleteNodeFirstIterator, PlanIteratorState>*)this);
  }

  ZorbaDeleteNodeFirstIterator(
    static_context* sctx,
    const QueryLoc& loc
    , std::vector<PlanIter_t>& aChildren)
    : NaryBaseIterator <ZorbaDeleteNodeFirstIterator, PlanIteratorState>
    (sctx, loc, aChildren) {}

  virtual ~ZorbaDeleteNodeFirstIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      zorba:delete-node-last
 *    
 * Author: Zorba Team
 */
class ZorbaDeleteNodeLastIterator : public NaryBaseIterator <ZorbaDeleteNodeLastIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ZorbaDeleteNodeLastIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaDeleteNodeLastIterator,
    NaryBaseIterator <ZorbaDeleteNodeLastIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator <ZorbaDeleteNodeLastIterator, PlanIteratorState>*)this);
  }

  ZorbaDeleteNodeLastIterator(
    static_context* sctx,
    const QueryLoc& loc
    , std::vector<PlanIter_t>& aChildren)
    : NaryBaseIterator <ZorbaDeleteNodeLastIterator, PlanIteratorState>
    (sctx, loc, aChildren) {}

  virtual ~ZorbaDeleteNodeLastIterator();

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
