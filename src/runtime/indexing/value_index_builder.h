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
#ifndef ZORBA_VALUE_INDEX_BUILDER_H
#define ZORBA_VALUE_INDEX_BUILDER_H

#include "runtime/base/unarybase.h"
#include "runtime/base/narybase.h"
#include "indexing/value_index.h"

namespace zorba 
{

/***************************************************************************//**
  Implements the "create index <uri>" expr. It creates the index in the store
  without populating. It returns the empty sequence.
********************************************************************************/
class CreateValueIndex : public UnaryBaseIterator<CreateValueIndex, PlanIteratorState> 
{
public:
  CreateValueIndex( short sctx, const QueryLoc& loc, PlanIter_t aChild)
    :
    UnaryBaseIterator<CreateValueIndex, PlanIteratorState>(sctx, loc, aChild) { }

  virtual ~CreateValueIndex() { }

  bool nextImpl(store::Item_t& result, PlanState& planState) const;

  virtual void accept(PlanIterVisitor& v) const;
public:
  SERIALIZABLE_CLASS(CreateValueIndex)
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(CreateValueIndex, UnaryBaseIterator<CreateValueIndex, PlanIteratorState> )
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (UnaryBaseIterator<CreateValueIndex, PlanIteratorState> *)this);
  }
};


/***************************************************************************//**
  Implements the "drop index <uri>" expr. It removes the index from the store.
  It returns the empty sequence.
********************************************************************************/
class DropValueIndex : public UnaryBaseIterator<DropValueIndex, PlanIteratorState> 
{
public:
  DropValueIndex( short sctx,const QueryLoc& loc, PlanIter_t aChild)
    :
    UnaryBaseIterator<DropValueIndex, PlanIteratorState>(sctx, loc, aChild) { }

  virtual ~DropValueIndex() { }

  bool nextImpl(store::Item_t& result, PlanState& planState) const;

  virtual void accept(PlanIterVisitor& v) const;
public:
  SERIALIZABLE_CLASS(DropValueIndex)
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(DropValueIndex, UnaryBaseIterator<DropValueIndex, PlanIteratorState> )
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (UnaryBaseIterator<DropValueIndex, PlanIteratorState> *)this);
  }
};


/***************************************************************************//**

********************************************************************************/
class ValueIndexInsertSessionOpener : public UnaryBaseIterator<ValueIndexInsertSessionOpener, PlanIteratorState> 
{
public:
  ValueIndexInsertSessionOpener( short sctx,const QueryLoc& loc, PlanIter_t aChild)
    :
    UnaryBaseIterator<ValueIndexInsertSessionOpener, PlanIteratorState>(sctx, loc, aChild) { }

  virtual ~ValueIndexInsertSessionOpener() { }

  bool nextImpl(store::Item_t& result, PlanState& planState) const;

  virtual void accept(PlanIterVisitor& v) const;
public:
  SERIALIZABLE_CLASS(ValueIndexInsertSessionOpener)
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ValueIndexInsertSessionOpener, UnaryBaseIterator<ValueIndexInsertSessionOpener, PlanIteratorState> )
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (UnaryBaseIterator<ValueIndexInsertSessionOpener, PlanIteratorState> *)this);
  }
};


/***************************************************************************//**

********************************************************************************/
class ValueIndexInsertSessionCloser : public UnaryBaseIterator<ValueIndexInsertSessionCloser, PlanIteratorState> 
{
public:
  ValueIndexInsertSessionCloser( short sctx,const QueryLoc& loc, PlanIter_t aChild)
    :
    UnaryBaseIterator<ValueIndexInsertSessionCloser, PlanIteratorState>(sctx, loc, aChild) { }

  virtual ~ValueIndexInsertSessionCloser() { }

  bool nextImpl(store::Item_t& result, PlanState& planState) const;

  virtual void accept(PlanIterVisitor& v) const;
public:
  SERIALIZABLE_CLASS(ValueIndexInsertSessionCloser)
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ValueIndexInsertSessionCloser, UnaryBaseIterator<ValueIndexInsertSessionCloser, PlanIteratorState> )
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (UnaryBaseIterator<ValueIndexInsertSessionCloser, PlanIteratorState> *)this);
  }
};


/***************************************************************************//**

********************************************************************************/
class ValueIndexBuilderState : public PlanIteratorState 
{
public:
  ValueIndexInsertSession_t theSession;

  void init(PlanState&);
  void reset(PlanState&);
};


class ValueIndexBuilder : public NaryBaseIterator<ValueIndexBuilder, ValueIndexBuilderState> 
{
public:
  ValueIndexBuilder( short sctx,const QueryLoc& loc, std::vector<PlanIter_t>& aChildren)
    :
    NaryBaseIterator<ValueIndexBuilder, ValueIndexBuilderState>(sctx, loc, aChildren) { }

  virtual ~ValueIndexBuilder() { }

  bool nextImpl(store::Item_t& result, PlanState& planState) const;

  virtual void accept(PlanIterVisitor& v) const;
public:
  SERIALIZABLE_CLASS(ValueIndexBuilder)
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ValueIndexBuilder, NaryBaseIterator<ValueIndexBuilder, ValueIndexBuilderState> )
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (NaryBaseIterator<ValueIndexBuilder, ValueIndexBuilderState> *)this);
  }
};

}

#endif /* ZORBA_VALUE_INDEX_BUILDER_H */
/* vim:set ts=2 sw=2: */

/*
 * Local variables:
 * mode: c++
 * End:
 */
