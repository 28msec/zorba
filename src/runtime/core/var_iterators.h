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
#ifndef ZORBA_RUNTIME_VAR_ITERATORS
#define ZORBA_RUNTIME_VAR_ITERATORS

#include "zorbatypes/xqpstring.h"

#include "common/shared_types.h"
#include "runtime/base/noarybase.h" // TODO remove after iterator refactoring

namespace zorba
{

class Item;


/*******************************************************************************

  FOR variables. A ForVarIterator represents a reference to a for variable V.

  theValue stores the current value of V.

********************************************************************************/
class ForVarState : public PlanIteratorState 
{
public:
  store::Item_t theValue;

  void init(PlanState& planState)  
  {
    PlanIteratorState::init(planState); 
  }

  void reset(PlanState& planState) 
  {
    PlanIteratorState::reset(planState); 
  }
};


class ForVarIterator : public NoaryBaseIterator<ForVarIterator, ForVarState>
{
protected:
  store::Item_t  theVarName;
  
public:
  ForVarIterator(short sctx, const QueryLoc& loc, const store::Item_t& name);

  ~ForVarIterator() { }
  
  store::Item* getVarName() const { return theVarName.getp(); }

  void accept(PlanIterVisitor&) const;

  bool nextImpl(store::Item_t& result, PlanState& planState) const;

  void bind(store::Item *value, PlanState& planState);

  void foo();
};


/*******************************************************************************

  LET variables. A LetVarIterator represents a reference to a let variable V.
  
  theSourceIter stores the current "value" of V: it is a PlanIteratorWraper
  that may wrap the actual expression that defines the var, or an iterator
  over a temp sequence, if the result of the defining expression needs
  materialization.

********************************************************************************/
class LetVarState : public PlanIteratorState 
{
public:
  store::Iterator_t theSourceIter;

  LetVarState();

  ~LetVarState();

  void init(PlanState& planState)  { PlanIteratorState::init(planState); }
  void reset(PlanState& planState);
};


class LetVarIterator : public NoaryBaseIterator<LetVarIterator, LetVarState>
{
private:
  store::Item_t  theVarName;
  
public:
  LetVarIterator(short sctx, const QueryLoc& loc, const store::Item_t& name);

  ~LetVarIterator() {}
  
  store::Item* getVarName() const { return theVarName.getp(); }

  void accept(PlanIterVisitor&) const;

  bool nextImpl(store::Item_t& result, PlanState& planState) const;

  void bind(store::Iterator_t it, PlanState& planState);
};


} 
#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
