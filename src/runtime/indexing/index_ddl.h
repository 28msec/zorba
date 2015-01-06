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
#include "runtime/base/binarybase.h"
#include "runtime/base/narybase.h"


namespace zorba 
{

class IndexDecl;
class StructuredItemHandleHashSet;


/*******************************************************************************
  create-internal-index($indexName as xs:QName) as ()

  This is an intenal function that is used by the hashjoins rule to create and
  populate a temp index. There are 3 reasons why we need a different function
  than the regular create, which is defined below:

  1. create assumes that the domain and key expressions do not reference
     any free variables. This is not true for the temp index created by the
     hashjoin rule.
  2. The argument to create can be any arbitrary expression that returns
     a QName. In the case of create-internal-index we know that the arg is a
     const expr holding a qname item.
  3. create-internal-index is a "simple" function, whereas create is an
     updating function.
********************************************************************************/
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
  {
  }

  ~CreateInternalIndexIterator();

  store::Item_t getName() const { return theQName; }

  void accept(PlanIterVisitor& v) const;

  zstring getNameAsString() const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/*******************************************************************************
  create($indexName as xs:QName) as pul()
 
  This is an updating function. During normal runtime (see CreateIndexIterator),
  it checks that index does not exist already (in the store) and generates an
  update primitive. During applyUpdates(), it creates the index container in
  the store and populates it according to the index definition.
 
  The specification for the index to create is taken from the static context,
  which stores a mapping from the index uri to IndexDecl obj (defined in
  indexing/value_index.h).
 
  The population of the index is done by a runtime plan that implements
  the following flwor expr:
 
    for $$dot at $$pos in domainExpr
    return value-index-entry-builder($$dot, fieldExpr1, ..., fieldExprN);
 
  for value indexes, or

    for $$dot at $$pos in domainExpr
    return general-index-entry-builder($$dot, fieldExpr);

  for general indexes.

  This plan is generated "on-the-fly" by the CreateIndexIterator. The generated
  plan is stored in the update primitive, and during applyUpdates(), it is given
  as an arg to the SimpleStore::createIndex() method. 
********************************************************************************/
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

  ~CreateIndexIterator();

  void accept(PlanIterVisitor& v) const;

  zstring getNameAsString() const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
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
  {
  }

  virtual ~DeleteIndexIterator();

  void accept(PlanIterVisitor& v) const;

  zstring getNameAsString() const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/******************************************************************************
   refresh-index($indexName as xs:QName) as pul()
 
   This is an updating function. During normal runtime (see RefreshIndexIterator),
   it checks that index exists (in the dynamic context) and generates an update
   primitive. During applyUpdates(), it clears the index of its contents and then
   rebuilds the index the same way as the create() function.
*******************************************************************************/
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

  zstring getNameAsString() const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/******************************************************************************
  zorba-op:value-index-entry-builder(node(), xs:anyAtomic)
*******************************************************************************/
class ValueIndexEntryBuilderIteratorState : public PlanIteratorState
{
public:
  csize theCurChild;

public:
  ValueIndexEntryBuilderIteratorState();

  ~ValueIndexEntryBuilderIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};


class ValueIndexEntryBuilderIterator : 
public NaryBaseIterator<ValueIndexEntryBuilderIterator, 
                        ValueIndexEntryBuilderIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ValueIndexEntryBuilderIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ValueIndexEntryBuilderIterator,
  NaryBaseIterator<ValueIndexEntryBuilderIterator, ValueIndexEntryBuilderIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<ValueIndexEntryBuilderIterator,
                      ValueIndexEntryBuilderIteratorState>*)this);
  }

  ValueIndexEntryBuilderIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<ValueIndexEntryBuilderIterator,
                     ValueIndexEntryBuilderIteratorState>(sctx, loc, children)
  {}

  virtual ~ValueIndexEntryBuilderIterator();

  void accept(PlanIterVisitor& v) const;

  zstring getNameAsString() const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/******************************************************************************
  zorba-op:general-index-entry-builder(node(), xs:anyAtomic*)
*******************************************************************************/
class GeneralIndexEntryBuilderIterator :
public BinaryBaseIterator<GeneralIndexEntryBuilderIterator, 
                          PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(GeneralIndexEntryBuilderIterator);
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(GeneralIndexEntryBuilderIterator,
  BinaryBaseIterator<GeneralIndexEntryBuilderIterator,
                     PlanIteratorState>);
  void serialize(::zorba::serialization::Archiver& ar);

public:
  GeneralIndexEntryBuilderIterator(
      static_context* sctx,
      const QueryLoc& loc,
      PlanIter_t& child0,
      PlanIter_t& child1);

  virtual ~GeneralIndexEntryBuilderIterator();

  void accept(PlanIterVisitor& v) const;

  zstring getNameAsString() const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/******************************************************************************
   probe-index-point-value($indexName as xs:QName,
                           $key1      as anyAtomic?,
                           ...,
                           $keyN      as anyAtomic?) as node()*

  Note: the translator wraps calls to this function with an OP_NODE_SORT_ASC
  function.
********************************************************************************/
class ProbeIndexPointValueIteratorState : public PlanIteratorState
{
public:
  const store::Item            * theQname; 
  const IndexDecl              * theIndexDecl;
  store::Index                 * theIndex; 
  store::IndexProbeIterator_t    theIterator;

public:
  ProbeIndexPointValueIteratorState();

  ~ProbeIndexPointValueIteratorState();

  void init(PlanState&);

  void reset(PlanState&);
};


class ProbeIndexPointValueIterator 
  :
  public NaryBaseIterator<ProbeIndexPointValueIterator,
                          ProbeIndexPointValueIteratorState>
{
protected:
  bool theCheckKeyType;
  bool theSkip;

public:
  SERIALIZABLE_CLASS(ProbeIndexPointValueIterator);
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ProbeIndexPointValueIterator,
  NaryBaseIterator<ProbeIndexPointValueIterator, ProbeIndexPointValueIteratorState>);
  void serialize(::zorba::serialization::Archiver& ar);

public:
  ProbeIndexPointValueIterator(
      static_context* sctx,
      const QueryLoc& loc,
      std::vector<PlanIter_t>& children,
      bool skip);

  ~ProbeIndexPointValueIterator();

  bool hasSkip() const { return theSkip; }

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& planState) const;

  zstring getNameAsString() const;

  bool countImpl(store::Item_t& result, PlanState& planState) const;

protected:
  void getIndex(
      ProbeIndexPointValueIteratorState* state,
      PlanState& planState) const;

  store::IndexCondition_t createCondition(
      ProbeIndexPointValueIteratorState* state,
      PlanState& planState) const;
};


/******************************************************************************
   probe-index-point-general($indexName as xs:QName,
                             $key1      as anyAtomic*,
                              ...,
                             $keyN      as anyAtomic*) as node()*

  Note: the translator wraps calls to this function with an OP_NODE_SORT_DISTINCT_ASC
  function.
********************************************************************************/
class ProbeIndexPointGeneralIteratorState : public ProbeIndexPointValueIteratorState
{
public:
  store::IndexCondition_t theCondition;

public:
  ProbeIndexPointGeneralIteratorState();

  ~ProbeIndexPointGeneralIteratorState();
};


class ProbeIndexPointGeneralIterator : 
public NaryBaseIterator<ProbeIndexPointGeneralIterator, 
                        ProbeIndexPointGeneralIteratorState>
{
protected:
  bool theCheckKeyType;

public:
  SERIALIZABLE_CLASS(ProbeIndexPointGeneralIterator);
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ProbeIndexPointGeneralIterator,
  NaryBaseIterator<ProbeIndexPointGeneralIterator, ProbeIndexPointGeneralIteratorState>);
  void serialize(::zorba::serialization::Archiver& ar);

public:
  ProbeIndexPointGeneralIterator(
      static_context* sctx,
      const QueryLoc& loc,
      std::vector<PlanIter_t>& children);
  
  ~ProbeIndexPointGeneralIterator();

  void accept(PlanIterVisitor& v) const;

  zstring getNameAsString() const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;

protected:
  void getIndex(
      ProbeIndexPointGeneralIteratorState* state,
      PlanState& planState) const;

  void createCondition(
      ProbeIndexPointGeneralIteratorState* state) const;
};


/*******************************************************************************
   probe-index-range-value($indexName               as xs:QName,
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

  Note: the translator wraps calls to this function with an OP_NODE_SORT_ASC
  function.

  theQname    : the name of the index
  theIndex    : the index to probe
  theIterator : the index probe iterator
********************************************************************************/
class ProbeIndexRangeValueIteratorState : public PlanIteratorState
{
public:
  const store::Item           * theQname;
  const IndexDecl             * theIndexDecl;
  store::Index                * theIndex;
  store::IndexProbeIterator_t   theIterator;

public:
  ProbeIndexRangeValueIteratorState();

  ~ProbeIndexRangeValueIteratorState();

  void init(PlanState&);

  void reset(PlanState&);
};


class ProbeIndexRangeValueIterator :
public NaryBaseIterator<ProbeIndexRangeValueIterator,
                        ProbeIndexRangeValueIteratorState>
{
protected:
  bool theCheckKeyType;
  bool theSkip;

public:
  SERIALIZABLE_CLASS(ProbeIndexRangeValueIterator);
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ProbeIndexRangeValueIterator,
  NaryBaseIterator<ProbeIndexRangeValueIterator, ProbeIndexRangeValueIteratorState>);
  void serialize(::zorba::serialization::Archiver& ar);

public:
  ProbeIndexRangeValueIterator(
      static_context* sctx,
      const QueryLoc& loc,
      std::vector<PlanIter_t>& children,
      bool skip);

  ~ProbeIndexRangeValueIterator();

  bool hasSkip() const { return theSkip; }

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& planState) const;

  zstring getNameAsString() const;

  bool countImpl(store::Item_t& result, PlanState& planState) const;

protected:
  void getIndex(
      ProbeIndexRangeValueIteratorState* state,
      PlanState& planState) const;

  store::IndexCondition_t createCondition(
      ProbeIndexRangeValueIteratorState* state,
      PlanState& planState) const;
};


/*******************************************************************************
  fn-zorba-ddl:probe-index-range-general(
      $indexName           as xs:QName, 
      $lowerBoundKeys      as xs:anyAtomicType*,
      $upperBoundKeys      as xs:anyAtomicType*,
      $haveLowerBound      as xs:boolean,
      $haveUpperBound      as xs:boolean,
      $lowerBoundIncluded  as xs:boolean,
      $upperBoundIncluded  as xs:boolean) as node()*

  Note: the translator wraps calls to this function with an OP_NODE_SORT_DISTINCT_ASC
  function.
********************************************************************************/
class ProbeIndexRangeGeneralIteratorState : public PlanIteratorState
{
public:
  const store::Item                  * theQname;
  store::Index                       * theIndex;

  long                                 theTimezone;
  const XQPCollator                  * theCollator;
  xqtref_t                             theKeyType;

  std::vector<store::Item_t>           theSearchItems;
  std::vector<store::Item_t>::iterator theSearchItemsIte;
  std::vector<store::Item_t>::iterator theSearchItemsEnd;

  store::IndexProbeIterator_t          theIterator;

  StructuredItemHandleHashSet                  * theNodeHashSet;

public:
  ProbeIndexRangeGeneralIteratorState();

  ~ProbeIndexRangeGeneralIteratorState();

  void init(PlanState&);

  void reset(PlanState&);
};


class ProbeIndexRangeGeneralIterator : 
public NaryBaseIterator<ProbeIndexRangeGeneralIterator, 
                        ProbeIndexRangeGeneralIteratorState>
{
protected:
  bool theCheckKeyType;

public:
  SERIALIZABLE_CLASS(ProbeIndexRangeGeneralIterator);
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ProbeIndexRangeGeneralIterator,
  NaryBaseIterator<ProbeIndexRangeGeneralIterator, ProbeIndexRangeGeneralIteratorState>);
  void serialize(::zorba::serialization::Archiver& ar);

public:
  ProbeIndexRangeGeneralIterator(
      static_context* sctx,
      const QueryLoc& loc,
      std::vector<PlanIter_t>& children);
  
  ~ProbeIndexRangeGeneralIterator();

  void accept(PlanIterVisitor& v) const;

  zstring getNameAsString() const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;

private:
  bool getSearchItems(
      PlanState& planState,
      ProbeIndexRangeGeneralIteratorState* state,
      bool haveLower,
      bool haveUpper,
      bool inclLower,
      bool inclUpper) const;

  void getIndex(
      ProbeIndexRangeGeneralIteratorState* state,
      PlanState& planState) const;
};



}
#endif
/*
 * Local variables:
 * mode: c++
 * End:
 */ 
/* vim:set et sw=2 ts=2: */
