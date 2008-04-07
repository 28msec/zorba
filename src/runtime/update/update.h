#ifndef ZORBA_RUNTIME_UPDATE_H
#define ZORBA_RUNTIME_UPDATE_H

#include <vector>
#include "runtime/base/binarybase.h"
#include "runtime/base/unarybase.h"
#include "store/api/update_consts.h"
#include "store/api/copymode.h"


namespace zorba {

/*******************************************************************************

********************************************************************************/
class InsertIterator : public BinaryBaseIterator<InsertIterator, PlanIteratorState>
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

  bool isUpdateIterator() const { return true; }

  store::Item_t nextImpl(PlanState&) const;

  virtual void accept(PlanIterVisitor&) const;
};


/*******************************************************************************

********************************************************************************/
class DeleteIterator : public UnaryBaseIterator<DeleteIterator, PlanIteratorState>
{
 public:
  DeleteIterator(const QueryLoc& aLoc, PlanIter_t target);

  virtual ~DeleteIterator() {}

  bool isUpdateIterator() const { return true; }

  store::Item_t nextImpl(PlanState&) const;
  virtual void accept(PlanIterVisitor&) const;
};


/*******************************************************************************

********************************************************************************/
class ReplaceIterator : public BinaryBaseIterator<ReplaceIterator, PlanIteratorState>
{
private:
  store::UpdateConsts::ReplaceType theType;
  bool                             theDoCopy;

public:
  ReplaceIterator (
    const QueryLoc& aLoc,
    store::UpdateConsts::ReplaceType aType,
    PlanIter_t target,
    PlanIter_t source);

  virtual ~ReplaceIterator() {}

  bool isUpdateIterator() const { return true; }

  store::Item_t nextImpl(PlanState&) const;
  virtual void accept(PlanIterVisitor&) const;
};


/*******************************************************************************

********************************************************************************/
class RenameIterator : public BinaryBaseIterator<RenameIterator, PlanIteratorState>
{
public:
  RenameIterator (
    const QueryLoc& aLoc,
    PlanIter_t target,
    PlanIter_t name);

  virtual ~RenameIterator() {}

  bool isUpdateIterator() const { return true; }

  store::Item_t nextImpl(PlanState&) const;
  virtual void accept(PlanIterVisitor&) const;
};


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
