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
#ifndef ZORBA_RUNTIME_UPDATE
#define ZORBA_RUNTIME_UPDATE

#include <vector>

#include "runtime/base/binarybase.h"
#include "runtime/base/unarybase.h"

#include "store/api/update_consts.h"


namespace zorba {


/*******************************************************************************

********************************************************************************/
class InsertIterator : public BinaryBaseIterator<InsertIterator, PlanIteratorState>
{
private:
  store::UpdateConsts::InsertType theType;
  bool                            theDoCopy;

public:
  SERIALIZABLE_CLASS(InsertIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  InsertIterator, 
  BinaryBaseIterator<InsertIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (BinaryBaseIterator<InsertIterator, PlanIteratorState>*)this);

    SERIALIZE_ENUM(store::UpdateConsts::InsertType, theType);
    ar & theDoCopy;
  }

public:
  InsertIterator ( 
    static_context* sctx,
    const QueryLoc& loc, 
    store::UpdateConsts::InsertType aType,
    PlanIter_t source, 
    PlanIter_t target); 

  ~InsertIterator() {}

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t&, PlanState&) const;
};


/*******************************************************************************

********************************************************************************/
UNARY_ITER(DeleteIterator);


/*******************************************************************************

********************************************************************************/
class ReplaceIterator : public BinaryBaseIterator<ReplaceIterator,
                                                  PlanIteratorState>
{
private:
  store::UpdateConsts::ReplaceType theType;
  bool                             theDoCopy;

public:
  SERIALIZABLE_CLASS(ReplaceIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  ReplaceIterator,
  BinaryBaseIterator<ReplaceIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar);

public:
  ReplaceIterator(
    static_context* sctx,
    const QueryLoc& aLoc,
    store::UpdateConsts::ReplaceType aType,
    PlanIter_t target,
    PlanIter_t source);

  ~ReplaceIterator() {}

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t&, PlanState&) const;
};


/*******************************************************************************

********************************************************************************/
class RenameIterator : public BinaryBaseIterator<RenameIterator,
                                                 PlanIteratorState>
{
private:
  NamespaceContext_t theNsCtx;

public:
  SERIALIZABLE_CLASS(RenameIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  RenameIterator,
  BinaryBaseIterator<RenameIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar);

public:
  RenameIterator(
    static_context* sctx,
    const QueryLoc& aLoc,
    PlanIter_t target,
    PlanIter_t source,
    const namespace_context* nsctx);

  ~RenameIterator() {}

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t&, PlanState&) const;
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
  SERIALIZABLE_CLASS(CopyClause);

  SERIALIZABLE_CLASS_CONSTRUCTOR(CopyClause);

  void serialize(::zorba::serialization::Archiver &ar)
  {
    ar & theCopyVars;
    ar & theInput;
  }

public:
  CopyClause() {}

  CopyClause(
        std::vector<ForVarIter_t>& aCopyVars,
        PlanIter_t                 aInput)
    :
    theCopyVars(aCopyVars),
    theInput(aInput)
  {}

  ~CopyClause() {}
};


class TransformIterator : public Batcher<TransformIterator>
{
private:
  std::vector<CopyClause> theCopyClauses;
  PlanIter_t              theModifyIter;
  PlanIter_t              thePulHolderIter;
  PlanIter_t              theApplyIter;
  PlanIter_t              theReturnIter;

public:
  SERIALIZABLE_CLASS(TransformIterator)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(TransformIterator, Batcher<TransformIterator>)
  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar, (Batcher<TransformIterator>*)this);
    ar & theCopyClauses;
    ar & theModifyIter;
    ar & thePulHolderIter;
    ar & theApplyIter;
    ar & theReturnIter;
  }

public:
  TransformIterator (
    static_context* sctx,
    const QueryLoc& aLoc,
    std::vector<CopyClause>& aCopyClauses,
    PlanIter_t aModifyIter,
    PlanIter_t aPulHolderIter,
    PlanIter_t aApplyIter,
    PlanIter_t aReturnIter);

  ~TransformIterator();

  uint32_t getStateSize() const { return sizeof(PlanIteratorState); }

  uint32_t getStateSizeOfSubtree() const;
      
  void accept(PlanIterVisitor&) const;

  void openImpl(PlanState& planState, uint32_t& offset);

  bool nextImpl(store::Item_t&, PlanState& planState) const;

  void resetImpl(PlanState& planState) const;

  void closeImpl(PlanState& planState) const;
};


} // namespace zorba

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
