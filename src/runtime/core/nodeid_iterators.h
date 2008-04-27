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
#ifndef ZORBA_NODEID_ITERATORS_H
#define ZORBA_NODEID_ITERATORS_H

#include "common/shared_types.h"
#include "runtime/base/unarybase.h"

namespace zorba 
{

/*******************************************************************************

********************************************************************************/
class NodeDistinctState : public PlanIteratorState
{
public:
  store::Iterator_t  theStoreIterator;

  void init(PlanState&);
  void reset(PlanState&);
};

// Preserves the order of input nodes
class NodeDistinctIterator : public UnaryBaseIterator<NodeDistinctIterator, NodeDistinctState>
{
private:
  bool theAcceptAtomics;

protected:

public:
  NodeDistinctIterator(
        const QueryLoc& loc,
        PlanIter_t input,
        bool aAcceptAtomics = false)
    :
    UnaryBaseIterator<NodeDistinctIterator, NodeDistinctState>(loc, input), theAcceptAtomics(aAcceptAtomics)
  {
  }

  ~NodeDistinctIterator() { }

  void openImpl(PlanState& planState, uint32_t& offset);
  store::Item_t nextImpl(PlanState& planState) const;
  void resetImpl(PlanState& planState) const;
  void closeImpl(PlanState& planState);

  virtual void accept(PlanIterVisitor&) const;
};

/*******************************************************************************

********************************************************************************/
#if 0
NARY_ITER_STATE (NodeUniqIterator, NodeUniqIteratorState);
#endif

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
  NodeSortIterator(
        const QueryLoc& loc,
        PlanIter_t input,
        bool ascendant,
        bool distinct,
        bool aAcceptAtomics = false)
    :
    UnaryBaseIterator<NodeSortIterator, NodeSortState>(loc, input),
    theAscendant(ascendant),
    theDistinct(distinct),
    theAcceptAtomics(aAcceptAtomics)
  {
  }

  ~NodeSortIterator() { }

  void openImpl(PlanState& planState, uint32_t& offset);
  store::Item_t nextImpl(PlanState& planState) const;
  void resetImpl(PlanState& planState) const;
  void closeImpl(PlanState& planState);


  virtual void accept(PlanIterVisitor&) const;
};

}

#endif
