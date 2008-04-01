#ifndef ZORBA_RUNTIME_UPDATE_H
#define ZORBA_RUNTIME_UPDATE_H

#include <vector>
#include "runtime/base/binarybase.h"
#include "runtime/base/narybase.h"
#include "store/api/update_consts.h"
#include "store/api/copymode.h"


namespace zorba {

/*******************************************************************************

********************************************************************************/
class InsertIteratorState : public PlanIteratorState
{
public:
  store::CopyMode theCopyMode;

  void init(PlanState&);
  void reset(PlanState&);
};


class InsertIterator : public BinaryBaseIterator<InsertIterator, InsertIteratorState>
{
private:
  store::UpdateConsts::InsertType theType;
  bool                            theDoCopy;

public:
  InsertIterator ( 
    const QueryLoc& loc, 
    store::UpdateConsts::InsertType aType,
    PlanIter_t source, 
    PlanIter_t target); 

  virtual ~InsertIterator() {}

  store::Item_t nextImpl(PlanState&) const;

  virtual void accept(PlanIterVisitor&) const;
};


/*******************************************************************************

********************************************************************************/
NARY_ITER(DeleteIterator);


/*******************************************************************************

********************************************************************************/
class ReplaceIterator : public BinaryBaseIterator<ReplaceIterator, PlanIteratorState>
{
private:
  store::UpdateConsts::ReplaceType theType;

public:
  ReplaceIterator (
    const QueryLoc& aLoc,
    store::UpdateConsts::ReplaceType aType,
    PlanIter_t aChild0,
    PlanIter_t aChild1);
  virtual ~ReplaceIterator() {}

  store::Item_t nextImpl(PlanState&) const;
  virtual void accept(PlanIterVisitor&) const;
};


/*******************************************************************************

********************************************************************************/
NARY_ITER(RenameIterator);


/*******************************************************************************

********************************************************************************/
class TransformIterator : public Batcher<TransformIterator>
{
private:
  std::vector<PlanIter_t> theAssignIters;
  PlanIter_t theModifyIter;
  PlanIter_t theReturnIter;

public:
  TransformIterator (
    const QueryLoc& aLoc,
    PlanIter_t aModifyIter,
    PlanIter_t aReturnIter);

  void addAssign(PlanIter_t anIter);

  void openImpl(PlanState& planState, uint32_t& offset);
  store::Item_t nextImpl(PlanState& planState) const;
  void resetImpl(PlanState& planState) const;
  void closeImpl(PlanState& planState) const;
      
  virtual uint32_t getStateSize() const { return sizeof(PlanIteratorState); }
  virtual uint32_t getStateSizeOfSubtree() const;
      
  virtual void accept(PlanIterVisitor&) const;
};

} // namespace zorba

#endif
