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
#ifndef ZORBA_RUNTIME_NODEID_ITERATORS
#define ZORBA_RUNTIME_NODEID_ITERATORS

#include "common/shared_types.h"

#include "runtime/base/unarybase.h"

namespace zorba 
{

/*******************************************************************************
  Preserves the order of input nodes
********************************************************************************/
class NodeDistinctState : public PlanIteratorState
{
public:
  store::Iterator_t  theStoreIterator;

  void init(PlanState&);
  void reset(PlanState&);
};


class NodeDistinctIterator : public UnaryBaseIterator<NodeDistinctIterator,
                                                      NodeDistinctState>
{
private:
  bool theAcceptAtomics;

public:
  SERIALIZABLE_CLASS(NodeDistinctIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  NodeDistinctIterator,
  UnaryBaseIterator<NodeDistinctIterator, NodeDistinctState>);

  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar,
    (UnaryBaseIterator<NodeDistinctIterator, NodeDistinctState>*)this);

    ar & theAcceptAtomics;
  }

public:
  NodeDistinctIterator(
        static_context* sctx,
        const QueryLoc& loc,
        PlanIter_t input,
        bool aAcceptAtomics = false)
    :
    UnaryBaseIterator<NodeDistinctIterator, NodeDistinctState>(sctx, loc, input), 
    theAcceptAtomics(aAcceptAtomics)
  {
  }

  ~NodeDistinctIterator() { }

  void accept(PlanIterVisitor& v) const;

  void openImpl(PlanState& planState, uint32_t& offset);

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
};


/*******************************************************************************

********************************************************************************/
class NodeSortState : public PlanIteratorState
{
public:
  store::Iterator_t  theStoreIterator;
  void init(PlanState&);
  void reset(PlanState&);
};


class NodeSortIterator : public UnaryBaseIterator<NodeSortIterator, NodeSortState>
{
protected:
  bool  theAscendant;
  bool  theDistinct;
  bool  theAcceptAtomics;

public:
  SERIALIZABLE_CLASS(NodeSortIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  NodeSortIterator,
  UnaryBaseIterator<NodeSortIterator, NodeSortState>);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar, (UnaryBaseIterator<NodeSortIterator, NodeSortState>*)this);
    ar & theAscendant;
    ar & theDistinct;
    ar & theAcceptAtomics;
  }

public:
  NodeSortIterator(
        static_context* sctx,
        const QueryLoc& loc,
        PlanIter_t input,
        bool ascendant,
        bool distinct,
        bool aAcceptAtomics = false)
    :
    UnaryBaseIterator<NodeSortIterator, NodeSortState>(sctx, loc, input),
    theAscendant(ascendant),
    theDistinct(distinct),
    theAcceptAtomics(aAcceptAtomics)
  {
  }

  ~NodeSortIterator() { }

  bool getDistinct() const { return theDistinct; }

  bool getAscending() const { return theAscendant; }

  void accept(PlanIterVisitor& v) const;

  void openImpl(PlanState& planState, uint32_t& offset);

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
};

}

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
