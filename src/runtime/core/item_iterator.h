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
#pragma once
#ifndef ZORBA_RUNTIME_ITEM_ITERATOR_H
#define ZORBA_RUNTIME_ITEM_ITERATOR_H

#include "common/shared_types.h"

#include "runtime/base/noarybase.h"

namespace zorba {

class SingletonIterator;

typedef rchandle<SingletonIterator> singleton_t;


/*******************************************************************************
   Class represents an empty sequence.
********************************************************************************/
NOARY_ITER(EmptyIterator); 


/*******************************************************************************
  Literals
********************************************************************************/
class SingletonIterator : public NoaryBaseIterator<SingletonIterator,
                                                   PlanIteratorState>
{
protected:
  store::Item_t theValue;

public:
  SERIALIZABLE_CLASS(SingletonIterator)
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(SingletonIterator,
                                   NoaryBaseIterator<SingletonIterator,
                                                     PlanIteratorState>)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  SingletonIterator(
      static_context* sctx,
      const QueryLoc& loc,
      const store::Item* value)
    :
    NoaryBaseIterator<SingletonIterator, PlanIteratorState>(sctx, loc),
    theValue(const_cast<store::Item*>(value))
  {
  }

  virtual ~SingletonIterator() {}
  
  const store::Item_t& getValue() const { return theValue; }

  void accept(PlanIterVisitor& v) const;
  
  void openImpl(PlanState& planState, uint32_t& offset);

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
  
  uint32_t getStateSizeOfSubtree() const;
};


/*******************************************************************************

  
********************************************************************************/
class IfThenElseIteratorState : public PlanIteratorState 
{
public:
  bool theThenUsed;
};


class IfThenElseIterator : public Batcher<IfThenElseIterator>
{
private:
  PlanIter_t theCondIter;
  PlanIter_t theThenIter;
  PlanIter_t theElseIter;
  bool theIsUpdating;
  bool theIsBooleanIter;
    
public:
  SERIALIZABLE_CLASS(IfThenElseIterator)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(IfThenElseIterator, Batcher<IfThenElseIterator>)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  /**
   * Constructor
   * @param loc location
   * @param iterCond_arg represents condition
   * @param iterThen_arg represents then expression
   * @param iterElse_arg represents else expression
   * @param condIsBooleanIter Optional flag. If true => condition is already an iterator 
   *                              which return true or false => the conditional value
   *                              does not have to be evaluated with the effective
   *                              boolean value function
   */
  IfThenElseIterator(
        static_context* sctx, 
        const QueryLoc& loc,
        PlanIter_t& aCondIter,
        PlanIter_t& aThenIter,
        PlanIter_t& aElseIter,
        bool aIsUpdating,
        bool aIsBooleanIter = false);

  virtual bool isUpdating() const { return theIsUpdating; }

  virtual uint32_t getStateSize() const { return sizeof(IfThenElseIteratorState); }

  virtual uint32_t getStateSizeOfSubtree() const;
      
  virtual void accept(PlanIterVisitor&) const;

  void openImpl(PlanState& planState, uint32_t& offset);

  bool nextImpl(store::Item_t& result, PlanState& planState) const;

  void resetImpl(PlanState& planState) const;

  void closeImpl(PlanState& planState) const;
};


} /* namespace zorba */
#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
