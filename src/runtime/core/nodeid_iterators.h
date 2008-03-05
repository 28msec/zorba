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
  Iterator_t  theStoreIterator;

  void init(PlanState&);
  void reset(PlanState&);
};

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
  Item_t nextImpl(PlanState& planState) const;
  void resetImpl(PlanState& planState) const;
  void closeImpl(PlanState& planState);

  virtual void accept(PlanIterVisitor&) const;
};

/*******************************************************************************


********************************************************************************/
class NodeSortState : public PlanIteratorState
{
public:
  Iterator_t  theStoreIterator;
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
  Item_t nextImpl(PlanState& planState) const;
  void resetImpl(PlanState& planState) const;
  void closeImpl(PlanState& planState);


  virtual void accept(PlanIterVisitor&) const;
};

}

#endif
