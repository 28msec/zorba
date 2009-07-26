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
#ifndef ZORBA_ACCESSORS_IMPL_H
#define ZORBA_ACCESSORS_IMPL_H

#include "common/shared_types.h"
#include "runtime/base/narybase.h"
#include "runtime/base/unarybase.h"

namespace zorba {

// 2.4 fn:data
class FnDataIteratorState : public PlanIteratorState 
{
public:
  store::Iterator_t theTypedValueIter;

  FnDataIteratorState();
  ~FnDataIteratorState();

  void init(PlanState& planState);
  void reset(PlanState& planState);
};


class FnDataIterator : public UnaryBaseIterator<FnDataIterator, FnDataIteratorState>
{
public:
  SERIALIZABLE_CLASS(FnDataIterator)
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnDataIterator, UnaryBaseIterator<FnDataIterator, FnDataIteratorState>)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (UnaryBaseIterator<FnDataIterator, FnDataIteratorState>*)this);
  }
public:
  FnDataIterator(short sctx, const QueryLoc& loc, PlanIter_t& aChild);

  virtual ~FnDataIterator() { }

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
  virtual void accept(PlanIterVisitor&) const;
};


// 14.9 fn:root
NARY_ITER(FnRootIterator);

// 2.1 fn:node-name
NARY_ITER(FnNodeNameIterator);

// 2.2 fn:nilled
NARY_ITER(FnNilledIterator);

// 2.5 fn:base-uri
NARY_ITER(FnBaseUriIterator);

// 2.6 fn:document-uri
NARY_ITER(FnDocumentUriIterator);

// 2.3 fn:string
class FnStringIteratorState : public PlanIteratorState {
  public:
    bool hasOutput;
    void init(PlanState& planState)
    {
      PlanIteratorState::init(planState);
      hasOutput = false;
    }

    void reset(PlanState& planState)
    {
      PlanIteratorState::reset(planState);
      hasOutput = false;
    }
};


class FnStringIterator : public NaryBaseIterator<FnStringIterator, FnStringIteratorState> {
  public:
  SERIALIZABLE_CLASS(FnStringIterator)
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnStringIterator, NaryBaseIterator<FnStringIterator, FnStringIteratorState>)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (NaryBaseIterator<FnStringIterator, FnStringIteratorState>*)this);
  }
  public:
    // TODO is the parameter theEmptyStringOnNULL needed?
    // otherwise we could replace this declaration with the macro
    FnStringIterator(short sctx, const QueryLoc& loc, std::vector<PlanIter_t>& aChildren)
      : NaryBaseIterator<FnStringIterator, FnStringIteratorState>(sctx, loc, aChildren), 
        theEmptyStringOnNULL(false) { }

    FnStringIterator(short sctx, const QueryLoc& loc, std::vector<PlanIter_t>& aChildren, bool emptyStringOnNULL)
      : NaryBaseIterator<FnStringIterator, FnStringIteratorState>(sctx, loc, aChildren), 
        theEmptyStringOnNULL(emptyStringOnNULL) { }

    virtual ~FnStringIterator() { }

    bool nextImpl(store::Item_t& result, PlanState& planState) const;

    virtual void accept(PlanIterVisitor& v) const;

  protected:
    bool theEmptyStringOnNULL;
};

} /* namespace zorba */
#endif /* ZORBA_ACCESSORS_IMPL_H */
/* vim:set ts=2 sw=2: */
