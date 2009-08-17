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
  SERIALIZABLE_CLASS(InsertIterator)
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(InsertIterator, BinaryBaseIterator<InsertIterator, PlanIteratorState>)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (BinaryBaseIterator<InsertIterator, PlanIteratorState>*)this);
    SERIALIZE_ENUM(store::UpdateConsts::InsertType, theType);
    ar & theDoCopy;
  }

public:
  InsertIterator ( 
    short sctx,
    const QueryLoc& loc, 
    store::UpdateConsts::InsertType aType,
    PlanIter_t source, 
    PlanIter_t target); 

  virtual ~InsertIterator() {}

  virtual bool isUpdating() const { return true; }

  void openImpl(PlanState& planState, uint32_t& offset)
  {
    BinaryBaseIterator<InsertIterator, PlanIteratorState>::openImpl(planState, offset); 
    theSctx = planState.theCompilerCB->getStaticContext(sctx);
  }

  bool nextImpl(store::Item_t&, PlanState&) const;

  virtual void accept(PlanIterVisitor&) const;
};


/*******************************************************************************

********************************************************************************/
class DeleteIterator : public UnaryBaseIterator<DeleteIterator, PlanIteratorState>
{
 public:
  DeleteIterator(short sctx, const QueryLoc& aLoc, PlanIter_t target);

  virtual ~DeleteIterator() {}

  virtual bool isUpdating() const { return true; }

  bool nextImpl(store::Item_t&, PlanState&) const;

  virtual void accept(PlanIterVisitor&) const;

public:
  SERIALIZABLE_CLASS(DeleteIterator)
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(DeleteIterator, UnaryBaseIterator<DeleteIterator, PlanIteratorState>)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (UnaryBaseIterator<DeleteIterator, PlanIteratorState>*)this);
  }
};


/*******************************************************************************

********************************************************************************/
class ReplaceIterator : public BinaryBaseIterator<ReplaceIterator, PlanIteratorState>
{
private:
  store::UpdateConsts::ReplaceType theType;
  bool                             theDoCopy;

public:
  SERIALIZABLE_CLASS(ReplaceIterator)
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ReplaceIterator, BinaryBaseIterator<ReplaceIterator, PlanIteratorState>)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (BinaryBaseIterator<ReplaceIterator, PlanIteratorState>*)this);
    SERIALIZE_ENUM(store::UpdateConsts::ReplaceType, theType);
    ar & theDoCopy;
  }

public:
  ReplaceIterator (
    short sctx,
    const QueryLoc& aLoc,
    store::UpdateConsts::ReplaceType aType,
    PlanIter_t target,
    PlanIter_t source);

  virtual ~ReplaceIterator() {}

  virtual bool isUpdating() const { return true; }

  void openImpl(PlanState& planState, uint32_t& offset)
  {
    BinaryBaseIterator<ReplaceIterator, PlanIteratorState>::
    openImpl(planState, offset); 

    theSctx = planState.theCompilerCB->getStaticContext(sctx);
  }

  bool nextImpl(store::Item_t&, PlanState&) const;

  virtual void accept(PlanIterVisitor&) const;
};


/*******************************************************************************

********************************************************************************/
class RenameIterator : public BinaryBaseIterator<RenameIterator, PlanIteratorState>
{
public:
  RenameIterator (
    short sctx,
    const QueryLoc& aLoc,
    PlanIter_t target,
    PlanIter_t name);

  virtual ~RenameIterator() {}

  virtual bool isUpdating() const { return true; }

  bool nextImpl(store::Item_t&, PlanState&) const;

  virtual void accept(PlanIterVisitor&) const;

public:
  SERIALIZABLE_CLASS(RenameIterator)
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(RenameIterator, BinaryBaseIterator<RenameIterator, PlanIteratorState>)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (BinaryBaseIterator<RenameIterator, PlanIteratorState>*)this);
  }
};


/*******************************************************************************

********************************************************************************/
class CopyClause : public ::zorba::serialization::SerializeBaseClass
{
  friend class TransformIterator;

  typedef std::vector<CopyClause>::const_iterator const_iter_t;
  typedef std::vector<CopyClause>::iterator       iter_t;

  std::vector<ForVarIter_t> theCopyVars;
  PlanIter_t                theInput;

public:
  SERIALIZABLE_CLASS(CopyClause)
  SERIALIZABLE_CLASS_CONSTRUCTOR(CopyClause)
  CopyClause() {}
  void serialize(::zorba::serialization::Archiver &ar)
  {
    ar & theCopyVars;
    ar & theInput;
  }
  virtual ~CopyClause() {}
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
  SERIALIZABLE_CLASS(TransformIterator)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(TransformIterator, Batcher<TransformIterator>)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (Batcher<TransformIterator>*)this);
    ar & theCopyClauses;
    ar & theModifyIter;
    ar & theReturnIter;
  }
public:
  TransformIterator (
    short sctx,
    const QueryLoc& aLoc,
    std::vector<CopyClause>& aCopyClauses,
    PlanIter_t aModifyIter,
    PlanIter_t aReturnIter);

  virtual ~TransformIterator();

  void openImpl(PlanState& planState, uint32_t& offset);
  bool nextImpl(store::Item_t&, PlanState& planState) const;
  void resetImpl(PlanState& planState) const;
  void closeImpl(PlanState& planState) const;
      
  virtual uint32_t getStateSize() const { return sizeof(PlanIteratorState); }
  virtual uint32_t getStateSizeOfSubtree() const;
      
  virtual void accept(PlanIterVisitor&) const;
};

} // namespace zorba

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
