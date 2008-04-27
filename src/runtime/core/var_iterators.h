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

  void init(PlanState& planState)  { PlanIteratorState::init(planState); }
  void reset(PlanState& planState) { PlanIteratorState::reset(planState); }
};


class ForVarIterator : public NoaryBaseIterator<ForVarIterator, ForVarState>
{
protected:
  xqpString     theVarName;
  const void  * theOrigin;  ///< origin expr, used as a kind of ID
  
public:
  ForVarIterator(xqpString vn,const QueryLoc& loc, const void* origin);

  ~ForVarIterator() { }
  
  store::Item_t nextImpl(PlanState& planState) const;

  void accept(PlanIterVisitor&) const;
  
public:
  xqpString getVarName() const { return theVarName; }

  void bind(store::Item_t value, PlanState& planState);
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
  xqpString     theVarName;
  const void  * theOrigin;  ///< like origin in var_iterator
  
public:
  LetVarIterator(xqpString vn,const QueryLoc& loc, const void *origin);

  ~LetVarIterator() {}
  
  store::Item_t nextImpl(PlanState& planState) const;

  void accept(PlanIterVisitor&) const;

  xqpString getVarName() const { return theVarName; }

  void bind(store::Iterator_t it, PlanState& planState);
};


} 
#endif

