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
#ifndef ZORBA_RUNTIME_FNCALL_ITERATOR
#define ZORBA_RUNTIME_FNCALL_ITERATOR

#include <zorba/api_shared_types.h>

#include "common/shared_types.h"

// TODO remove the next three includes
#include "api/unmarshaller.h"
#include "context/static_context.h"
#include <zorba/stateless_function.h>

#include "runtime/base/narybase.h"


namespace zorba {

class StaticContextImpl;

class UDFunctionCallIteratorState : public PlanIteratorState 
{
 public:
  PlanState                     * theFnBodyStateBlock;
  PlanIterator                  * thePlan;
  uint32_t                        thePlanStateSize;
  std::vector<store::Iterator_t>  theChildIterators;
  bool                            thePlanOpen;
  store::Iterator_t               exitValue;

  UDFunctionCallIteratorState();

  ~UDFunctionCallIteratorState();

  void openPlan();

  void closePlan();

  void resetPlan();

  void resetChildIters();
};


class UDFunctionCallIterator : public NaryBaseIterator<UDFunctionCallIterator, 
                                                       UDFunctionCallIteratorState> 
{
protected:
  user_function* theUDF;

public:
  SERIALIZABLE_CLASS(UDFunctionCallIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  UDFunctionCallIterator,
  NaryBaseIterator<UDFunctionCallIterator, UDFunctionCallIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar);

public:
  UDFunctionCallIterator(
        static_context* sctx,
        const QueryLoc& loc, 
        std::vector<PlanIter_t>& args, 
        const user_function* aUDF)
    :
    NaryBaseIterator<UDFunctionCallIterator, UDFunctionCallIteratorState>(sctx, loc, args), 
    theUDF((user_function*)aUDF)
  {}

  ~UDFunctionCallIterator() {}
    
  bool isUpdating() const;

  void accept(PlanIterVisitor& v) const;

  void openImpl(PlanState& planState, uint32_t& offset);

  bool nextImpl(store::Item_t& result, PlanState& planState) const;

  void resetImpl(PlanState& planState) const;

  void closeImpl(PlanState& planState);
};


class StatelessExtFunctionCallIteratorState : public PlanIteratorState 
{
 public:
  std::vector<ItemSequence*> m_extArgs;
  ItemSequence_t             m_result;

  StatelessExtFunctionCallIteratorState();
  ~StatelessExtFunctionCallIteratorState();

  void reset(PlanState&);
};


class StatelessExtFunctionCallIterator : 
                   public NaryBaseIterator<StatelessExtFunctionCallIterator,
                                           StatelessExtFunctionCallIteratorState>
{
protected:
  const StatelessExternalFunction *m_function;
  bool theIsUpdating;
  xqp_string thePrefix;

public:
  SERIALIZABLE_CLASS(StatelessExtFunctionCallIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  StatelessExtFunctionCallIterator, 
  NaryBaseIterator<StatelessExtFunctionCallIterator,
                   StatelessExtFunctionCallIteratorState>);

  void serialize(serialization::Archiver& ar);

public:
  StatelessExtFunctionCallIterator(
        static_context* sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& args,
        const StatelessExternalFunction *function,
        bool aIsUpdating,
        const xqp_string& aPrefix);

  virtual ~StatelessExtFunctionCallIterator();

  virtual bool isUpdating() const { return theIsUpdating; }

  void accept(PlanIterVisitor& v) const;

  void openImpl(PlanState& planState, uint32_t& offset);

  bool nextImpl(store::Item_t& result, PlanState& planState) const;

  void closeImpl(PlanState& planState);
};

}

#endif /* ZORBA_FNCALL_ITERATOR_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set ts=2 sw=2: */
