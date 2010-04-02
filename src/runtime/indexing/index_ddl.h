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
 
#ifndef ZORBA_RUNTIME_INDEXING_INDEX_DDL_H
#define ZORBA_RUNTIME_INDEXING_INDEX_DDL_H


#include "common/shared_types.h"
#include "runtime/base/unarybase.h"


#include "runtime/base/narybase.h"


namespace zorba 
{

class ValueIndex;


/**
 * 
 *  create-internal-index($indexName as xs:QName) as ()
 *
 *  This is an intenal function that is used by the hashjoins rule to create and
 *  populate a temp index. There are 3 reasons why we need a different function
 *  than the regular create-index, which is defined below:
 *
 *  1. create-index assumes that the domain and key expressions do not reference
 *     any free variables. This is not true for the temp index created by the
 *     hashjoin rule.
 *  2. The argument to create-index can be any arbitrary expression that returns
 *     a QName. In the case of create-internal-index we know that the arg is a
 *     const expr holding a qname item.
 *  3. create-internal-index is a "simple" function, whereas create-index is an
 *     updating function.
 */
class CreateInternalIndexIterator : public UnaryBaseIterator<CreateInternalIndexIterator,
                                                             PlanIteratorState>
{ 
protected:
  store::Item_t theQName; //the name of the index to create

public:
  SERIALIZABLE_CLASS(CreateInternalIndexIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(CreateInternalIndexIterator,
  UnaryBaseIterator<CreateInternalIndexIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (UnaryBaseIterator<CreateInternalIndexIterator, PlanIteratorState>*)this);

    ar & theQName;
  }

  CreateInternalIndexIterator(
        static_context* sctx,
        const QueryLoc& loc,
        PlanIter_t& child,
        const store::Item_t aName)
    :
    UnaryBaseIterator<CreateInternalIndexIterator, PlanIteratorState>(sctx, loc, child),
    theQName(aName)
  {}

  virtual ~CreateInternalIndexIterator();

  store::Item_t getName() const { return theQName; }

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 *  create-index($indexName as xs:QName) as pul()
 *
 *  This is an updating function. During normal runtime (see CreateIndexIterator),
 *  it checks that index does not exist already (in the store) and generates an
 *  update primitive. During applyUpdates(), it creates the index container in
 *  the store and populates it according to the index definition.
 *
 *  The specification for the index to create is taken from the static context,
 *  which stores a mapping from the index uri to ValueIndex obj (defined in
 *  indexing/value_index.h).
 *
 *  The population of the index is done by a runtime plan that implements
 *  the following flwor expr:
 *
 *    for $$dot at $$pos in domainExpr
 *    return index-entry-builder($$dot, fieldExpr1, ..., fieldExprN);
 *
 *  This plan is generated "on-the-fly" by the CreateIndexIterator. The generated
 *  plan is stored in the update primitive, and during applyUpdates(), it is given
 *  as an arg to the SimpleStore::createIndex() method. 
 *    
 */
class CreateIndexIterator : public UnaryBaseIterator<CreateIndexIterator, 
                                                     PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(CreateIndexIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(CreateIndexIterator,
  UnaryBaseIterator<CreateIndexIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (UnaryBaseIterator<CreateIndexIterator, PlanIteratorState>*)this);
  }

  CreateIndexIterator(
        static_context* sctx,
        const QueryLoc& loc,
        PlanIter_t& child)
    :
    UnaryBaseIterator<CreateIndexIterator, PlanIteratorState>(sctx, loc, child)
  {
  }

  virtual ~CreateIndexIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *  drop-index($indexName as xs:QName) as ()
 *
 *  This is an updating function. During normal runtime (see DropIndexIterator),
 *  it checks that index exists (in the dynamic context) and generates an update
 *  primitive. During applyUpdates(), it destroys the index container in the store
 *  and removes the index entry from the dynamic context. 
 *    
 */
class DeleteIndexIterator : public UnaryBaseIterator<DeleteIndexIterator,
                                                     PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(DeleteIndexIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(DeleteIndexIterator,
  UnaryBaseIterator<DeleteIndexIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (UnaryBaseIterator<DeleteIndexIterator, PlanIteratorState>*)this);
  }

  DeleteIndexIterator(
        static_context* sctx,
        const QueryLoc& loc,
        PlanIter_t& child)
    :
    UnaryBaseIterator<DeleteIndexIterator, PlanIteratorState>(sctx, loc, child)
  {}

  virtual ~DeleteIndexIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *  refresh-index($indexName as xs:QName) as pul()
 *
 *  This is an updating function. During normal runtime (see RefreshIndexIterator),
 *  it checks that index exists (in the dynamic context) and generates an update
 *  primitive. During applyUpdates(), it clears the index of its contents and then
 *  rebuilds the index the same way as the create-index() function.
 *    
 * Author: Zorba Team
 */
class RefreshIndexIterator : public UnaryBaseIterator<RefreshIndexIterator, 
                                                      PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(RefreshIndexIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(RefreshIndexIterator,
  UnaryBaseIterator<RefreshIndexIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (UnaryBaseIterator<RefreshIndexIterator, PlanIteratorState>*)this);
  }

  RefreshIndexIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& child)
    : 
    UnaryBaseIterator<RefreshIndexIterator, PlanIteratorState>(sctx, loc, child)
  {}

  virtual ~RefreshIndexIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *    
 * Author: Zorba Team
 */
class IndexEntryBuilderIteratorState : public PlanIteratorState
{
public:
  uint32_t theCurChild; //the current child

  IndexEntryBuilderIteratorState();

  ~IndexEntryBuilderIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class IndexEntryBuilderIterator : public NaryBaseIterator<IndexEntryBuilderIterator, 
                                                          IndexEntryBuilderIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IndexEntryBuilderIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IndexEntryBuilderIterator,
    NaryBaseIterator<IndexEntryBuilderIterator, IndexEntryBuilderIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IndexEntryBuilderIterator, IndexEntryBuilderIteratorState>*)this);
  }

  IndexEntryBuilderIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IndexEntryBuilderIterator, IndexEntryBuilderIteratorState>(sctx, loc, children)
  {}

  virtual ~IndexEntryBuilderIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *  probe-index-point($indexName as xs:QName,
 *                    $key1      as anyAtomic?,
 *                    ...,
 *                    $keyN      as anyAtomic?) as node()*
 *    
 * Author: Zorba Team
 */
class IndexPointProbeIteratorState : public PlanIteratorState
{
public:
  const store::Item            * theQname; 
  const ValueIndex             * theIndexDecl;
  store::Index                 * theIndex; 
  store::IndexProbeIterator_t    theIterator;

  IndexPointProbeIteratorState();

  ~IndexPointProbeIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class IndexPointProbeIterator : public NaryBaseIterator<IndexPointProbeIterator, 
                                                        IndexPointProbeIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IndexPointProbeIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IndexPointProbeIterator,
  NaryBaseIterator<IndexPointProbeIterator, IndexPointProbeIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IndexPointProbeIterator, IndexPointProbeIteratorState>*)this);
  }

  IndexPointProbeIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IndexPointProbeIterator, IndexPointProbeIteratorState>(sctx, loc, children)
  {}

  virtual ~IndexPointProbeIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/*******************************************************************************
   probe-index-range($indexName               as xs:QName,
                     $range1LowerBound         as anyAtomic?,
                     $range1UpperBound         as anyAtomic?,
                     $range1HaveLowerBound     as boolean?,
                     $range1HaveupperBound     as boolean?,
                     $range1LowerBoundIncluded as boolean?,
                     $range1upperBoundIncluded as boolean?,
                     ....,
                     $rangeNLowerBound         as anyAtomic?,
                     $rangeNUpperBound         as anyAtomic?,
                     $rangeNHaveLowerBound     as boolean?,
                     $rangeNHaveupperBound     as boolean?,
                     $rangeNLowerBoundIncluded as boolean?,
                     $rangeNupperBoundIncluded as boolean?) as node()*

  theQname    : the name of the index
  theIndex    : the index to probe
  theIterator : the index probe iterator
********************************************************************************/
class IndexRangeProbeIteratorState : public PlanIteratorState
{
public:
  const store::Item           * theQname;
  store::Index                * theIndex;
  store::IndexProbeIterator_t   theIterator;

  IndexRangeProbeIteratorState();

  ~IndexRangeProbeIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};


class IndexRangeProbeIterator : public NaryBaseIterator<IndexRangeProbeIterator,
                                                        IndexRangeProbeIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IndexRangeProbeIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IndexRangeProbeIterator,
  NaryBaseIterator<IndexRangeProbeIterator, IndexRangeProbeIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IndexRangeProbeIterator, IndexRangeProbeIteratorState>*)this);
  }

  IndexRangeProbeIterator(
        static_context* sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IndexRangeProbeIterator, IndexRangeProbeIteratorState>(sctx, loc, children)
  {}

  virtual ~IndexRangeProbeIterator();

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
