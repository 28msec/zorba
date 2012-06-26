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
#ifndef ZORBA_RUNTIME_VAR_ITERATORS
#define ZORBA_RUNTIME_VAR_ITERATORS

#include "common/shared_types.h"

#include "runtime/base/noarybase.h" 
#include "runtime/base/unarybase.h"
#include "runtime/base/narybase.h"

#include "zorbatypes/schema_types.h"


namespace zorba
{

/*******************************************************************************
  This iterator implements the var_decl expression. Its purpose is to "declare"
  a block-local or prolog var (including the context item, if it is declared in
  the prolog) and to initialize its value, if an init expr is provided.

  Specifically, for each prolog and block-local variable, the dynamic context 
  maps a numeric variable id (assigned to the varExpr during codegen) to an 
  entry that stores the current value of the variable, either as a single item
  or as an iterator that produces an item sequence. Each such entry has a
  state as well, which can be one of undeclared, declared, having a single-item
  value, or having an iterator value. 

  The iterator adds such an entry for the variable in the dynamic context and
  initializes its state to "declared". It is possible that an entry for the
  variable exists already (and the entry may even have a value already), in
  which case, the iterator will set its state to "declared" only if it was
  previously "undeclared". Then, if an init expr is porvided, the init subplan
  will be evaluated, the resulting value will be stored in the dctx entry,
  and the state of the entry will be set to single-item or iterator value.

  The iterator has 0 or 1 children. It has a single child if there is an
  init expr, in which case, the child is the root of the subplan that computes
  the init value.

  Note: this iterator is a NOOP if the variable being declared is an external
  one, which has been set already, either during a previous execution of the
  same XQuery obj, or via the c++ API.
********************************************************************************/
class CtxVarDeclareIterator : public NaryBaseIterator<CtxVarDeclareIterator,
                                                      PlanIteratorState>
{
private:
  ulong         theVarId;
  store::Item_t theVarName;
  bool          theIsExternal;
  bool          theSingleItem;

public:
  SERIALIZABLE_CLASS(CtxVarDeclareIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  CtxVarDeclareIterator,
  NaryBaseIterator<CtxVarDeclareIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar);

public:
  CtxVarDeclareIterator(
        static_context* sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& args,
        ulong varid,
        const store::Item_t& varName,
        bool isExtern,
        bool singleItem);

  ulong getVarId() const { return theVarId; }

  const store::Item* getVarName() const { return theVarName.getp(); }

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
};


/*******************************************************************************
  This iterator implements the ctxvar-assign(varName, initExpr) function. Its
  purpose is to initialize prolog vars that do have an initializing expr, or
  in xquery-scripting, to assign a value to a prolog or block-local variable.

  For the context item var, the iterator creates a binding in the dynamic ctx
  between the varName (".") and the actual context item returned by the initExpr.
  For a regular prolog var, the iterator creates a binding in the dynamic ctx
  between the varName and an iterator plan that computes the initExpr. 
********************************************************************************/
class CtxVarAssignIterator : public UnaryBaseIterator<CtxVarAssignIterator,
                                                      PlanIteratorState>
{
private:
  ulong         theVarId;
  store::Item_t theVarName;
  bool          theIsLocal;
  bool          theSingleItem;

public:
  SERIALIZABLE_CLASS(CtxVarAssignIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  CtxVarAssignIterator,
  UnaryBaseIterator<CtxVarAssignIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar);

public:
  CtxVarAssignIterator(
        static_context* sctx,
        const QueryLoc& loc,
        ulong varid,
        const store::Item_t& varName,
        bool isLocal,
        PlanIter_t& arg) 
    :
    UnaryBaseIterator<CtxVarAssignIterator, PlanIteratorState>(sctx, loc, arg),
    theVarId(varid),
    theVarName(varName),
    theIsLocal(isLocal),
    theSingleItem(false)
  {
  }

  ulong getVarId() const { return theVarId; }

  const store::Item* getVarName() const { return theVarName.getp(); }

  bool isLocal() const { return theIsLocal; }

  void setSingleItem() { theSingleItem = true; }

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
};


/*******************************************************************************
  This iterator implements the ctxvar-is-set(varName) function. Its purpose is
  to check if an external prolog variable has been set. It does so by checking
  whether an entry exists for variable in the global dynamic ctx.
********************************************************************************/
class CtxVarIsSetIterator : public NoaryBaseIterator<CtxVarIsSetIterator,
                                                       PlanIteratorState>
{
private:
  ulong         theVarId;
  store::Item_t theVarName;

public:
  SERIALIZABLE_CLASS(CtxVarIsSetIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  CtxVarIsSetIterator,
  NoaryBaseIterator<CtxVarIsSetIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar);

public:
  CtxVarIsSetIterator(
        static_context* sctx,
        const QueryLoc& loc,
        ulong varid,
        const store::Item_t& varName) 
    :
    NoaryBaseIterator<CtxVarIsSetIterator, PlanIteratorState>(sctx, loc),
    theVarId(varid),
    theVarName(varName)
  {
  }

  ulong getVarId() const { return theVarId; }

  const store::Item* getVarName() const { return theVarName.getp(); }

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
};



/*******************************************************************************
  This iterator implements a reference to a prolog or block-local variable.

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
class CtxVarState : public  PlanIteratorState 
{
public:
  store::TempSeq_t         theTempSeq;

  store::TempSeqIterator_t theSourceIter;
  store::Item_t            theItem;

  xs_integer               thePos;
  xs_integer               theLastPos;

public:
  CtxVarState();
  
  ~CtxVarState();

  void reset(PlanState& planState);
};


class CtxVarIterator : public NoaryBaseIterator<CtxVarIterator, CtxVarState>
{
protected:
  ulong          theVarId;
  store::Item_t  theVarName;
  bool           theIsLocal;

  xs_integer     theTargetPos;
  PlanIter_t     theTargetPosIter;
  PlanIter_t     theTargetLenIter;
  bool           theInfLen;

public:
  SERIALIZABLE_CLASS(CtxVarIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  CtxVarIterator, 
  NoaryBaseIterator<CtxVarIterator, CtxVarState>);

  void serialize(::zorba::serialization::Archiver& ar);

public:
  CtxVarIterator(
      static_context* sctx,
      const QueryLoc& loc,
      ulong varid,
      const store::Item_t& varName,
      bool local);

  virtual ~CtxVarIterator() {}

  ulong getVarId() const { return theVarId; }

  const store::Item* getVarName() const { return theVarName.getp(); }

  bool isLocal() const { return theIsLocal; }

  bool setTargetPos(xs_integer v);

  bool setTargetPosIter(const PlanIter_t& v);

  bool setTargetLenIter(const PlanIter_t& v);

  xs_integer getTargetPos() const { return theTargetPos; }

  PlanIterator* getTargetPosIter() const { return theTargetPosIter.getp(); }

  PlanIterator* getTargetLenIter() const { return theTargetLenIter.getp(); }

  uint32_t getStateSizeOfSubtree() const;

  void accept(PlanIterVisitor& v) const;

  void openImpl(PlanState& planState, uint32_t& offset);

  void resetImpl(PlanState& planState) const;

  void closeImpl(PlanState& planState);

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
};


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

  void serialize(::zorba::serialization::Archiver& ar);

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
  
  If the var is materialized, then its value is stored in a temp sequence, and a
  (smart) pointer to that temp seq is stored in the state of the LetVarIterator.
  Otherwise, it's value is a PlanIteratorWraper that may wrap the actual domain 
  expression that defines the var.

  theSourceIter:
  --------------
  Stores the current "value" of V, if the variable is not materialized.

  theTempSeq:
  -----------
  The temp seq storing the value of tha variable.
 
  theTempSeqIter:
  ---------------
  A pre-allocated iterator over the temp seq.

********************************************************************************/
class LetVarState : public PlanIteratorState 
{
public:
  store::Iterator_t        theSourceIter;

  store::TempSeq_t         theTempSeq;
  store::TempSeqIterator_t theTempSeqIter;
  store::Item_t            theItem;
  xs_integer               thePos;
  xs_integer               theLastPos;

public:
  LetVarState();

  ~LetVarState();

  void reset(PlanState& planState);
};


class LetVarIterator : public NoaryBaseIterator<LetVarIterator, LetVarState>
{
private:
  store::Item_t  theVarName;
  xs_integer     theTargetPos;
  PlanIter_t     theTargetPosIter;
  PlanIter_t     theTargetLenIter;
  bool           theInfLen;

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

  bool setTargetPos(xs_integer v);

  bool setTargetPosIter(const PlanIter_t& v);

  bool setTargetLenIter(const PlanIter_t& v);

  xs_integer getTargetPos() const { return theTargetPos; }

  PlanIterator* getTargetPosIter() const { return theTargetPosIter.getp(); }

  PlanIterator* getTargetLenIter() const { return theTargetLenIter.getp(); }

  store::Item* getVarName() const { return theVarName.getp(); }

  void bind(const store::TempSeq_t& value, PlanState& planState);

  void bind(
      store::TempSeq_t& value,
      PlanState& planState,
      xs_integer startPos,
      xs_integer endPos);

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
/* vim:set et sw=2 ts=2: */
