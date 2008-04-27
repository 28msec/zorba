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

  virtual bool isUpdating() const { return true; }
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

  virtual bool isUpdating() const { return true; }
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

  virtual bool isUpdating() const { return true; }
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

  virtual bool isUpdating() const { return true; }
  store::Item_t nextImpl(PlanState&) const;
  virtual void accept(PlanIterVisitor&) const;
};


/*******************************************************************************

********************************************************************************/
class CopyClause
{
  friend class TransformIterator;

  typedef std::vector<CopyClause>::const_iterator const_iter_t;
  typedef std::vector<CopyClause>::iterator       iter_t;

  std::vector<ForVarIter_t> theCopyVars;
  PlanIter_t                theInput;

public:
  CopyClause(
    std::vector<ForVarIter_t>& aCopyVars,
    PlanIter_t                 aInput)
  :
    theCopyVars(aCopyVars),
    theInput(aInput)
  {}
};


class TransformIterator : public Batcher<TransformIterator>
{
private:
  std::vector<CopyClause> theCopyClauses;
  PlanIter_t              theModifyIter;
  PlanIter_t              theReturnIter;

public:
  TransformIterator (
    const QueryLoc& aLoc,
    std::vector<CopyClause>& aCopyClauses,
    PlanIter_t aModifyIter,
    PlanIter_t aReturnIter);

  virtual ~TransformIterator();

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
