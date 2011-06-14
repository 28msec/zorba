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
#pragma once
#ifndef ZORBA_RUNTIME_NODEID_ITERATORS
#define ZORBA_RUNTIME_NODEID_ITERATORS

#include "common/shared_types.h"

#include "runtime/base/unarybase.h"

namespace zorba 
{

/*******************************************************************************
  The behaviour of this iterator depends on the values of its 2 data members:
  theAcceptAtomics and theCheckDistinct.

  If theAcceptAtomics is true, then the iterator checks that its input sequence
  contains atomic values only or nodes only. If it contains atomic values, the
  iterator just passes on these values to its parent. If it contains nodes, the
  iterator will either perform duplicate node elimination (if theCheckDistinct
  is false), or check that there are no duplicate nodes (if theCheckDistinct is
  true) and return an error if duplicates are found.
********************************************************************************/
class NodeDistinctState : public PlanIteratorState
{
public:
  store::Iterator_t  theStoreIterator;

  ~NodeDistinctState();

  void init(PlanState&);
  void reset(PlanState&);
};


class NodeDistinctIterator : public UnaryBaseIterator<NodeDistinctIterator,
                                                      NodeDistinctState>
{
private:
  bool theAcceptAtomics;
  bool theCheckDistinct;

public:
  SERIALIZABLE_CLASS(NodeDistinctIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  NodeDistinctIterator,
  UnaryBaseIterator<NodeDistinctIterator, NodeDistinctState>);

  void serialize(::zorba::serialization::Archiver& ar);

public:
  NodeDistinctIterator(
        static_context* sctx,
        const QueryLoc& loc,
        PlanIter_t input,
        bool acceptAtomics,
        bool checkDistinct);

  ~NodeDistinctIterator() { }

  bool getAtomics() const { return theAcceptAtomics; }

  bool getCheckDistinct() const { return theCheckDistinct; }

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

  ~NodeSortState();

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

  void serialize(::zorba::serialization::Archiver& ar);

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
/* vim:set et sw=2 ts=2: */
