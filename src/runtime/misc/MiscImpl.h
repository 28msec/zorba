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
#ifndef ZORBA_MISC_IMPL_H
#define ZORBA_MISC_IMPL_H
 
#include "common/shared_types.h"

#include "runtime/base/narybase.h"
#include "runtime/api/plan_iterator_wrapper.h"

#include "zorbaerrors/errors.h"

namespace zorba {

// 3 The Error Function
NARY_ITER(FnErrorIterator);

// 8.1 fn:resolve-uri
NARY_ITER(FnResolveUriIterator);

class SequentialIterator : public NaryBaseIterator<SequentialIterator, PlanIteratorState >
{
private:
  bool theUpdating;
public:
  SERIALIZABLE_CLASS(SequentialIterator)
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(SequentialIterator, NaryBaseIterator<SequentialIterator, PlanIteratorState >)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (NaryBaseIterator<SequentialIterator, PlanIteratorState >*)this);
    ar & theUpdating;
  }
public:
  SequentialIterator(short sctx, const QueryLoc& loc, std::vector<PlanIter_t>& aChildren, bool aUpdating) 
  : NaryBaseIterator<SequentialIterator, PlanIteratorState>(sctx, loc, aChildren), theUpdating(aUpdating)
  {}

public:
  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const; 
  bool isUpdating() const { return theUpdating; }
};


class FlowCtlIterator : public NaryBaseIterator<FlowCtlIterator, PlanIteratorState>
{
public:
  enum action {
    BREAK, CONTINUE, EXIT
  };

  class FlowCtlException : public error::ZorbaInternalException {
  public:
  enum action act;
    
    FlowCtlException (enum action act_)
      : act (act_) 
    {}
  };

  class ExitException : public FlowCtlException {
  public:
    store::Iterator_t val;
    ExitException (store::Iterator_t val_)
      : FlowCtlException (EXIT),
        val (val_)
    {}
  };

private:
  enum action act;

public:
  SERIALIZABLE_CLASS(FlowCtlIterator)
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FlowCtlIterator, NaryBaseIterator<FlowCtlIterator, PlanIteratorState >)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (NaryBaseIterator<FlowCtlIterator, PlanIteratorState >*)this);
    SERIALIZE_ENUM(enum action, act);
  }
public:
  FlowCtlIterator(short sctx, const QueryLoc& loc, std::vector<PlanIter_t>& aChildren, enum action act_)
    : NaryBaseIterator<FlowCtlIterator, PlanIteratorState>(sctx, loc, aChildren), act (act_)
  {}
  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const; 
};


NARY_ITER (LoopIterator);

NARY_ITER (FnReadStringIterator);

class FnPrintIterator : public NaryBaseIterator<FnPrintIterator, PlanIteratorState>
{
public:
	FnPrintIterator(short sctx, const QueryLoc& loc, std::vector<PlanIter_t>& aChildren, bool printToConsole = true) :
	  NaryBaseIterator<FnPrintIterator, PlanIteratorState >(sctx, loc, aChildren), m_printToConsole(printToConsole)
	  {
	  }

public:
	bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;

private:
	bool m_printToConsole;
public:
  SERIALIZABLE_CLASS(FnPrintIterator)
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnPrintIterator, NaryBaseIterator<FnPrintIterator, PlanIteratorState >)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (NaryBaseIterator<FnPrintIterator, PlanIteratorState >*)this);
    ar & m_printToConsole;
  }
};

} /* namespace zorba */

#endif /* ZORBA_MISC_IMPL_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
