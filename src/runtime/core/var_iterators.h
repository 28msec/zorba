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

#include "common/shared_types.h"

#include "runtime/base/noarybase.h" 
#include "runtime/base/narybase.h"

#include "zorbatypes/representations.h"


namespace zorba
{

/*******************************************************************************
  This iterator implements the ctxvar-declare(varName) function. Its purpose is
  to declare all block-local and prolog vars (including the context item, if it
  is declared in the prolog), except for external vars without an initalizing
  expr. Specifically, the iterator registers the varName into the dynamic context.
********************************************************************************/
NARY_ITER(CtxVarDeclIterator);


/*******************************************************************************
  This iterator implements the ctxvar-assign(varName, initExpr) function. Its
  purpose is to initialize prolog vars that do have an initializing expr, or
  in xquery-scripting, to assign a value to a prolog or block-local variable.

  For the context item var, the iterator creates a binding in the dynamic ctx
  between the varName (".") and the actual context item returned by the initExpr.
  For a regular prolog var, the iterator creates a binding in the dynamic ctx
  between the varName and an iterator plan that computes the initExpr. 
********************************************************************************/
class CtxVarAssignIterator : public NaryBaseIterator<CtxVarAssignIterator,
                                                     PlanIteratorState>
{
private:
  bool theSingleItem;

public:
  SERIALIZABLE_CLASS(CtxVarAssignIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  CtxVarAssignIterator,
  NaryBaseIterator<CtxVarAssignIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar, 
    (NaryBaseIterator<CtxVarAssignIterator, PlanIteratorState>*)this);

    ar & theSingleItem;
  }

public:
  CtxVarAssignIterator(
        static_context* sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& args) 
    :
    NaryBaseIterator<CtxVarAssignIterator, PlanIteratorState>(sctx, loc, args),
    theSingleItem(false)
  {
  }

  void setSingleItem() { theSingleItem = true; }

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
};


/*******************************************************************************
  This iterator implements the ctxvar-exists(varName) function. Its purpose is
  to check if a prolog or block-local variable has been declared. It does so
  by checking whether an entry exists for variable in the dynamic ctx.
********************************************************************************/
NARY_ITER(CtxVarExistsIterator);


/*******************************************************************************
  This iterator implements the ctxvariable(varName) function, which represents
  references to prolog or block-local variables.

  For each prolog variable, the dynamic context maps the name of the variable
  to an iterator that computes the variable's value. CtxVariableIterator has
  one child only, which produces the name of a prolog variabe. Using this name,
  CtxVariableIterator extracts the associated iterator from the dynamic context
  and just returns the items that it produces, one-at-a-time.

  The global context item is also considered a prolog variable whose name is
  ".". Since the value of the context item is always a single item (or the empty
  seq), the dynamic context maps "." to an Item (instead of an Iterator). So,
  a CtxVariableIterator that represents the context item, returns just the item
  associated with "." in the dynamic context.

  Note: the binding in the dynamic context between a var name and an iterator
  plan (or single item) can be created in one of the following ways:
  (a) The CtxVarAssignIterator described above, or
  (b) Through the user API provided by DynamicContextImpl class (see methods
      setVariable, setContextItem, etc).
********************************************************************************/
class CtxVariableIteratorState : public  PlanIteratorState 
{
public:
  CtxVariableIteratorState();
  
  ~CtxVariableIteratorState();

  store::Iterator_t theIter;
};


NARY_ITER_STATE(CtxVariableIterator, CtxVariableIteratorState);


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
  SERIALIZABLE_CLASS(ForVarIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  ForVarIterator, 
  NoaryBaseIterator<ForVarIterator, ForVarState>);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar, (NoaryBaseIterator<ForVarIterator, ForVarState>*)this);
    ar & theVarName;
  }

public:
  ForVarIterator(
        static_context* sctx,
        const QueryLoc& loc,
        store::Item* name);

  ~ForVarIterator() { }
  
  store::Item* getVarName() const { return theVarName.getp(); }

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& planState) const;

  void bind(store::Item* value, PlanState& planState);
};


/*******************************************************************************

  LET variables. A LetVarIterator represents a reference to a let variable V.
  
  theSourceIter stores the current "value" of V: it is a PlanIteratorWraper
  that may wrap the actual domain expression that defines the var, or an
  iterator over a temp sequence, if the result of the domain expression is
  materialized.

********************************************************************************/
class LetVarState : public PlanIteratorState 
{
public:
  store::TempSeq_t  theTempSeq;

  store::Iterator_t theSourceIter;
  store::Item_t     theItem;

  ulong             thePos;
  ulong             theLastPos;

  LetVarState();

  ~LetVarState();

  void init(PlanState& planState)  { PlanIteratorState::init(planState); }

  void reset(PlanState& planState);
};


class LetVarIterator : public NoaryBaseIterator<LetVarIterator, LetVarState>
{
private:
  store::Item_t  theVarName;
  xqp_long       theTargetPos;
  PlanIter_t     theTargetPosIter;
  PlanIter_t     theTargetLenIter;

public:
  SERIALIZABLE_CLASS(LetVarIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  LetVarIterator, 
  NoaryBaseIterator<LetVarIterator, LetVarState>);

  void serialize(::zorba::serialization::Archiver& ar);

public:
  LetVarIterator(
        static_context* sctx,
        const QueryLoc& loc, 
        store::Item* name);

  ~LetVarIterator() {}

  bool setTargetPos(xqp_long v);

  bool setTargetPosIter(const PlanIter_t& v);

  bool setTargetLenIter(const PlanIter_t& v);

  xqp_long getTargetPos() const { return theTargetPos; }

  PlanIterator* getTargetPosIter() const { return theTargetPosIter.getp(); }

  PlanIterator* getTargetLenIter() const { return theTargetLenIter.getp(); }

  store::Item* getVarName() const { return theVarName.getp(); }

  void bind(store::TempSeq_t& value, PlanState& planState);

  void bind(store::TempSeq_t& value, PlanState& planState, ulong startPos, ulong endPos);

  void bind(store::Iterator_t& it, PlanState& planState);

  void accept(PlanIterVisitor& v) const;

  uint32_t getStateSizeOfSubtree() const;

  void openImpl(PlanState& planState, uint32_t& offset);

  void resetImpl(PlanState& planState) const;

  void closeImpl(PlanState& planState);

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
};


} 
#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
