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
#ifndef ZORBA_RUNTIME_GFLWOR_WINDOW
#define ZORBA_RUNTIME_GFLWOR_WINDOW

#include "zorbautils/checked_vector.h"
#include "common/shared_types.h"
#include "runtime/base/plan_iterator.h"

namespace zorba
{
namespace flwor
{
class WindowIterator;


/***************************************************************************//**
  Class WindowVars stores the ForVarIterators that represent the references to
  the "start" or the "end" variables of a window clause (there are 2 instances
  of WindowVars per window clause: one for the "start" vars and another for the
  "end" vars).

  theCurVars       : References to the variable storing the current item. The
                     scope is only the WindowClause.
  thePrevVars      : References to the variable storing the item before the
                     current item. The scope is only the WindowClause.
  theNextVars      : References to the variable storing the item after the
                     current item. The scope is only the WindowClause.
  thePosVars       : References to the variable storing the position of the
                     current item within the domain sequence. The scope is
                     only the WindowClause.

  theCurOuterVars  : References to the variable storing the current item. The
                     scope is everything after the WindowClause.
  thePrevOuterVars : References to the variable storing the item before the
                     current item. The scope is everything after the
                     WindowClause.
  theNextOuterVars : References to the variable storing the item after the
                     current item. The scope is everything after the
                     WindowClause.
  thePosOuterVars  : References to the variable storing the position of the
                     current item within the domain sequence. The scope is
                     everything after the WindowClause.
********************************************************************************/
class WindowVars : public ::zorba::serialization::SerializeBaseClass
{
  friend class WindowIterator;
  friend class StartClause;
  friend class EndClause;

protected:
  std::vector<PlanIter_t> theCurVars;
  std::vector<PlanIter_t> thePrevVars;
  std::vector<PlanIter_t> theNextVars;
  std::vector<PlanIter_t> thePosVars;

  std::vector<PlanIter_t> theCurOuterVars;
  std::vector<PlanIter_t> thePrevOuterVars;
  std::vector<PlanIter_t> theNextOuterVars;
  std::vector<PlanIter_t> thePosOuterVars;

public:
  SERIALIZABLE_CLASS(WindowVars)
  SERIALIZABLE_CLASS_CONSTRUCTOR(WindowVars)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  WindowVars();

  WindowVars(
        const std::vector<PlanIter_t >& aCurVars,
        const std::vector<PlanIter_t >& aPrevVars,
        const std::vector<PlanIter_t >& aNextVars,
        const std::vector<PlanIter_t >& aPosVars,

        const std::vector<PlanIter_t >& aCurOuterVars,
        const std::vector<PlanIter_t >& aPrevOuterVars,
        const std::vector<PlanIter_t >& aNextOuterVars,
        const std::vector<PlanIter_t >& aPosOuterVars);

  virtual ~WindowVars();

  void accept(PlanIterVisitor&) const;

  void bindIntern(
        PlanState& aPlanState,
        const store::TempSeq_t& aInputSeq,
        const ulong aPosition) const;

  void bindExtern(
        PlanState& aPlanState,
        const store::TempSeq_t& aInputSeq,
        const ulong aPosition) const;
};


/***************************************************************************//**
  Represents the start condition of a window clause.

  theStartClauseIter : The iterator evaluating the condition expression of "this"
  theWindowVars      : Stores the iterators representing the references to the
                       "start" variables of this window clause, both inside the
                       condition expression of "this" and outside the window 
                       clause.
********************************************************************************/
class StartClause : public ::zorba::serialization::SerializeBaseClass
{
  friend class WindowIterator;

protected:
  PlanIter_t theStartClauseIter;
  WindowVars theWindowVars;

public:
  SERIALIZABLE_CLASS(StartClause)
  SERIALIZABLE_CLASS_CONSTRUCTOR(StartClause)
  void serialize(::zorba::serialization::Archiver& ar)
  {
    ar & theStartClauseIter;
    ar & theWindowVars;
  }

public:
  StartClause(PlanIter_t aStartClauseIter, WindowVars& aWindowVars);

  virtual ~StartClause();

protected:
  uint32_t getStateSizeOfSubtree() const;

  void accept(PlanIterVisitor&) const;

  void open(PlanState& aPlanState, uint32_t& offset) const;
  void reset(PlanState& aPlanState) const;
  void close(PlanState& aPlanState) const;

  bool evaluate(
        PlanState& aPlanState,
        const store::TempSeq_t& aInputSeq,
        const ulong aPosition) const;

  void bindIntern(
        PlanState& aPlanState,
        const store::TempSeq_t& aInputSeq,
        const ulong aPosition) const;

  void bindExtern(
        PlanState& aPlanState,
        const store::TempSeq_t& aInputSeq,
        const ulong aPosition) const;
};


/***************************************************************************//**
  Represents the end condition of a window clause.

  theEndClauseIter : The iterator evaluating the condition expression of "this"
  theWindowVars    : Stores the iterators representing the references to the
                     "end" variables of this window clause, both inside the
                     condition expression of "this" and outside the window clause.
  theOnlyEnd       : Whether the end condition contains the "only" keyword or not.
  theHasEndClause  : An EndClause instance is created even if the window clause
                     has no end condition. For thie "dummy" EndClause obj, 
                     theHasEndClause will be false; otherwise it will be true.
********************************************************************************/
class EndClause : public ::zorba::serialization::SerializeBaseClass
{
  friend class WindowIterator;

protected:
  PlanIter_t  theEndClauseIter;
  WindowVars  theWindowVars;
  bool        theOnlyEnd;
  bool        theHasEndClause;

public:
  SERIALIZABLE_CLASS(EndClause)
  SERIALIZABLE_CLASS_CONSTRUCTOR(EndClause)
  void serialize(::zorba::serialization::Archiver& ar)
  {
    ar & theEndClauseIter;
    ar & theWindowVars;
    ar & theOnlyEnd;
    ar & theHasEndClause;
  }

public:
  EndClause();

  EndClause(
        PlanIter_t aEndClauseIter,
        WindowVars& theWindowVars,
        bool aOnlyEnd);

  virtual ~EndClause();

protected:
  uint32_t getStateSizeOfSubtree() const;

  void accept(PlanIterVisitor&) const;

  void open(PlanState& aPlanState, uint32_t& offset) const;
  void reset(PlanState& aPlanState) const;
  void close(PlanState& aPlanState) const;

  bool evaluate(
        PlanState& aPlanState,
        const store::TempSeq_t& aInputSeq,
        const ulong aPosition) const;

  void bindIntern(
        PlanState& aPlanState,
        const store::TempSeq_t& aInputSeq,
        const ulong aPosition ) const;

  void bindExtern(
        PlanState& aPlanState,
        const store::TempSeq_t& aInputSeq,
        const ulong aPosition) const;
};


/***************************************************************************//**
  A simple class to store info about a "candidate" window. A candidate window
  is one for which a quailifying starting item has been found within the domain
  sequence, but no quailifying end item has been found yet. Instances of this class
  are stored inside the WindowState::theOpenWindows vector until an item is found
  that satisfies the end condition.

  theStartPos : The position within the domain sequence of the item that marks
                the start of the window.
  theEndPos   : The position within the domain sequence of the item that marks
                the end of the window. Once this is set, the window is not a
                candidate anymore (it becomes a real window), and the WindowDef
                obj is removed from the WindowState::theOpenWindows vector.
********************************************************************************/
class WindowDef
{
public:
	ulong theStartPos;
	ulong theEndPos;

public:
	WindowDef(ulong aStartPos);

	~WindowDef();
};


/***************************************************************************//**
  theDomainSeq   : A temp sequence where the result of the domain exspression is
                   materialized into (lazily, if the WindowIterator was created
                   with the lazy flag on).
  theCurInputPos : 
  theOpenWindows : A vector storing "candidate" windows, i.e., windows for which
                   a quailifying starting item has been found within the domain
                   sequence, but no quailifying end item has been found yet.
  theCurWindow   : Iterator over theOpenWindows vector
********************************************************************************/
class WindowState : public PlanIteratorState
{
  friend class WindowIterator;

protected:
  store::TempSeq_t                 theDomainSeq;
  ulong                            theCurInputPos;
  std::vector<WindowDef>           theOpenWindows;
  std::vector<WindowDef>::iterator theCurWindow;

public:
  WindowState();

  ~WindowState();

  void init(PlanState& aState);

  void reset(PlanState& aState);
};


/***************************************************************************//**
  theWindowType       : The kind of this window clause (tumbling or sliding)
  theTupleIter        : The iterator producing the input tuple stream. In fact 
                        it is the iterator representing the flwor clause that
                        precedes this window clause in the flwor expression.
  theInputIter        : The iterator producing the domain sequence for this
                        window clause.
  theVarName          : The name of the window var.
  theVarRefs          : The LetVarIterators representing the references to the
                        window var.
  theStartClause      : Object representing the start cond of this window clause
  theEndClause        : Object representing the end cond of this window clause
  theLazyEval         : Whether to use an eager or a lazy temp sequence to
                        buffer the domain sequence.
  theMaxNeededHistory : This is relevant only if a lazy temp sequence is used.
********************************************************************************/
class WindowIterator : public Batcher<WindowIterator>
{
public:
  static const ulong MAX_HISTORY;

  enum WindowType
  {
    TUMBLING,
    SLIDING
  };

private:
  WindowType                 theWindowType;

  PlanIter_t                 theTupleIter;
  PlanIter_t                 theInputIter;

  store::Item_t              theVarName;
  std::vector<LetVarIter_t>  theVarRefs;

  StartClause                theStartClause;
  EndClause                  theEndClause;

  bool                       theLazyEval;
  ulong                      theMaxNeededHistory;

public:
  SERIALIZABLE_CLASS(WindowIterator);

  WindowIterator(::zorba::serialization::Archiver& ar) 
    :
    Batcher<WindowIterator>(ar), theStartClause(ar) 
  {}

  void serialize(::zorba::serialization::Archiver& ar);

public:
  WindowIterator(
        static_context* sctx,
        const QueryLoc& loc,
        WindowType windowType,
        PlanIter_t tupleIter,
        PlanIter_t domainIterator,
        store::Item* varName,
        const std::vector<PlanIter_t >& varRefs,
        StartClause& startClause,
        EndClause& endClause,
        bool lazyEval,
        ulong maxNeededHistory = MAX_HISTORY);

  ~WindowIterator();

  uint32_t getStateSize() const;

  uint32_t getStateSizeOfSubtree() const;

  void accept(PlanIterVisitor&) const;

  void openImpl(PlanState& aPlanState, uint32_t& aOffset);
  bool nextImpl(store::Item_t& aResult, PlanState& aPlanState) const;
  void resetImpl(PlanState& aPlanState) const;
  void closeImpl(PlanState& aPlanState);

private:
  void bindVariable(
        PlanState& aPlanState,
        store::TempSeq_t& aInputSeq,
        ulong aStartPos,
        ulong aEndPos) const;

  void doGarbageCollection(WindowState* lState) const;
};


}//namespace gflwor
} //namespace zorba
#endif  /* ZORBA_RUNTIME_GFLWOR_WINDOW */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
