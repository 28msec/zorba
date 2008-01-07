#ifndef XQP_NODEID_ITERATORS_H
#define XQP_NODEID_ITERATORS_H


#include "util/rchandle.h"
#include "util/logging/logging.hh"
#include "compiler/expression/expr_consts.h"
#include "runtime/base/iterator.h"
#include "runtime/base/unarybase.h"

namespace xqp 
{

/*******************************************************************************

********************************************************************************/
class NodeDistinctIterator : public UnaryBaseIterator<NodeDistinctIterator>
{
private:
  bool theAcceptAtomics;

protected:
  class NodeDistinctState : public PlanIterator::PlanIteratorState
  {
  public:
    Iterator_t  theStoreIterator;
  };

public:
  NodeDistinctIterator(
        const yy::location& loc,
        PlanIter_t input,
        bool aAcceptAtomics = false)
    :
    UnaryBaseIterator<NodeDistinctIterator>(loc, input), theAcceptAtomics(aAcceptAtomics)
  {
  }

  ~NodeDistinctIterator() { }

  Item_t nextImpl(PlanState& planState);
  void resetImpl(PlanState& planState);
  void releaseResourcesImpl(PlanState& planState);

  virtual uint32_t getStateSize() const { return sizeof(NodeDistinctState); }

  virtual void setOffset(PlanState& planState, uint32_t& offset);

  virtual void accept(PlanIterVisitor&) const;
};

/*******************************************************************************


********************************************************************************/
class NodeSortIterator : public UnaryBaseIterator<NodeSortIterator>
{
protected:
  class NodeSortState : public PlanIterator::PlanIteratorState
  {
  public:
    Iterator_t  theStoreIterator;
  };

protected:
  bool  theAscendant;
  bool  theDistinct;
  bool  theAcceptAtomics;

public:
  NodeSortIterator(
        const yy::location& loc,
        PlanIter_t input,
        bool ascendant,
        bool distinct,
        bool aAcceptAtomics = false)
    :
    UnaryBaseIterator<NodeSortIterator>(loc, input),
    theAscendant(ascendant),
    theDistinct(distinct),
    theAcceptAtomics(aAcceptAtomics)
  {
  }

  ~NodeSortIterator() { }

  Item_t nextImpl(PlanState& planState);
  void resetImpl(PlanState& planState);
  void releaseResourcesImpl(PlanState& planState);

  virtual uint32_t getStateSize() const { return sizeof(NodeSortState); }

  virtual void setOffset(PlanState& planState, uint32_t& offset);

  virtual void accept(PlanIterVisitor&) const;
};

}

#endif
