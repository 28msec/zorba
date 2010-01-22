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

class WindowVars : public ::zorba::serialization::SerializeBaseClass
{
  friend class WindowIterator;
  friend class StartClause;
  friend class EndClause;

protected:
  std::vector<ForVarIter_t > theCurVars;
  std::vector<ForVarIter_t > thePrevVars;
  std::vector<ForVarIter_t > theNextVars;
  std::vector<ForVarIter_t > thePosVars;

  std::vector<ForVarIter_t > theCurOuterVars;
  std::vector<ForVarIter_t > thePrevOuterVars;
  std::vector<ForVarIter_t > theNextOuterVars;
  std::vector<ForVarIter_t > thePosOuterVars;

public:
  SERIALIZABLE_CLASS(WindowVars)
  SERIALIZABLE_CLASS_CONSTRUCTOR(WindowVars)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    ar & theCurVars;
    ar & thePrevVars;
    ar & theNextVars;
    ar & thePosVars;

    ar & theCurOuterVars;
    ar & thePrevOuterVars;
    ar & theNextOuterVars;
    ar & thePosOuterVars;
  }
public:
  WindowVars();
  /**
  * Method to construct the WindowVars.
  *
   * @param aCurVars Variables which refer the current item. The scope is only
   *        the WindowClause.
    * @param aPrevVars Previous item variables. The scope is only the WindowClause.
    * @param aNextVars Next item variables. The scope is only the WindowClause.
    * @param aPosVars  Position variables. The scope is only the WindowClause.
   * @param aCurOuterVars Variables which refer the current item. The scope is
   *        everything after the WindowClause.
   * @param aPrevOuterVars Previous item variables. The scope is everything after
   *        the WindowClause.
   * @param aNextOuterVars Next item variables. The scope is everything after
   *        the WindowClause.
   * @param aPosOuterVars  Position variables. The scope is everything after
   *        the WindowClause.
         */
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

  void accept ( PlanIterVisitor& ) const;

  /**
   * Binds the variables inside the window clause.
   *
   * @param aPlanState The PlanState
   * @param aInputSeq The underlying input sequence
   * @param aPosition The relative position for all variables. Starts counting
   *        with 0 (although the XQuery counting starts with 1).
   */
  void bindIntern(
        PlanState& aPlanState,
        const store::TempSeq_t& aInputSeq,
        const uint32_t aPosition ) const;

        /**
        * Binds the variables outside the window clause.
        *
        * @param aPlanState The PlanState
        * @param aInputSeq The underlying input sequence
   * @param aPosition The relative position for all variables. Starts counting
   *        with 0 (although the XQuery counting starts with 1).
        */
  void bindExtern(
        PlanState& aPlanState,
        const store::TempSeq_t& aInputSeq,
        const uint32_t aPosition ) const;
};


class StartClause : public ::zorba::serialization::SerializeBaseClass
{
  friend class WindowIterator;

protected:
  PlanIter_t theStartClauseIter;
  WindowVars theWindowVars;

public:
  SERIALIZABLE_CLASS(StartClause)
  SERIALIZABLE_CLASS_CONSTRUCTOR(StartClause)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    ar & theStartClauseIter;
    ar & theWindowVars;
  }

public:
  StartClause(PlanIter_t aStartClauseIter, WindowVars& aWindowVars);

  virtual ~StartClause();

protected:

  void accept ( PlanIterVisitor& ) const;
  void open ( PlanState& aPlanState, uint32_t& offset ) const;
  void reset ( PlanState& aPlanState ) const;
  void close ( PlanState& aPlanState ) const;
  uint32_t getStateSizeOfSubtree() const;
  bool evaluate(PlanState& aPlanState, const store::TempSeq_t& aInputSeq, const uint32_t aPosition) const;
  void bindIntern ( PlanState& aPlanState, const store::TempSeq_t& aInputSeq, const uint32_t aPosition ) const;
  void bindExtern(PlanState& aPlanState, const store::TempSeq_t& aInputSeq, const uint32_t aPosition) const;
};


class EndClause : public ::zorba::serialization::SerializeBaseClass
{
  friend class WindowIterator;
protected:
  PlanIter_t theEndClauseIter;
  WindowVars theWindowVars;
  bool theOnlyEnd;
  bool theHasEndClause;

public:
  SERIALIZABLE_CLASS(EndClause)
  SERIALIZABLE_CLASS_CONSTRUCTOR(EndClause)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    ar & theEndClauseIter;
    ar & theWindowVars;
    ar & theOnlyEnd;
    ar & theHasEndClause;
  }

public:
  /**
   * If the EndClause is missing in the case of a tumbling window, this constructor should be used
   */
  EndClause ();
  EndClause ( PlanIter_t aEndClauseIter,
              WindowVars& theWindowVars,
              bool aOnlyEnd
            );
  virtual ~EndClause();

protected:
  void accept ( PlanIterVisitor& ) const;
  void open ( PlanState& aPlanState, uint32_t& offset ) const;
  void reset ( PlanState& aPlanState ) const;
  void close ( PlanState& aPlanState ) const;
  uint32_t getStateSizeOfSubtree() const;
  bool evaluate(PlanState& aPlanState, const store::TempSeq_t& aInputSeq, const uint32_t aPosition) const;
  void bindIntern ( PlanState& aPlanState, const store::TempSeq_t& aInputSeq, const uint32_t aPosition ) const;
  void bindExtern(PlanState& aPlanState, const store::TempSeq_t& aInputSeq, const uint32_t aPosition) const;
};


class WindowDef{
public:
	~WindowDef();
	WindowDef(uint32_t aStartPos);
	uint32_t theStartPos;
	uint32_t theEndPos;
};


class WindowState : public PlanIteratorState
{
  friend class WindowIterator;
protected:
  store::TempSeq_t theInputSeq;
  ulong theCurInputPos;
  std::vector<WindowDef> theOpenWindows;
  std::vector<WindowDef>::iterator theCurWindow;

public:
  ~WindowState();
  WindowState();
  void init ( PlanState& aState );
  void reset ( PlanState& aState );
  void tupleReset();
};


class WindowIterator :public Batcher<WindowIterator>
{
public:
  static const uint32_t MAX_HISTORY; //TODO should be set platform dependent, but somebody hat comment out everything in platform.h!

  enum WindowType
  {
    TUMBLING,
    SLIDING
  };

private:
  WindowType                 theWindowType;

  PlanIter_t theTupleIter;
  PlanIter_t theInputIter;

  store::Item_t              theVarName;
  std::vector<LetVarIter_t > theVarRefs;

  StartClause theStartClause;
  EndClause theEndClause;

  bool theLazyEval;
  uint32_t theMaxNeededHistory;

public:
  SERIALIZABLE_CLASS(WindowIterator);

  WindowIterator(::zorba::serialization::Archiver& ar) 
    :
    Batcher<WindowIterator>(ar), theStartClause(ar) 
  {}

  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (Batcher<WindowIterator>*)this);
    SERIALIZE_ENUM(WindowType, theWindowType);
    ar & theTupleIter;
    ar & theInputIter;
    ar & theVarName;
    ar & theVarRefs;
    ar & theStartClause;
    ar & theEndClause;
    ar & theLazyEval;
    ar & theMaxNeededHistory;
  }

public:

  /**
   * Method to construct a WindowIterator.
   *
   * @param aTupleIterator The tuple triggering the window
   * @param aInputIterator The window input
   * @param aWindowType The window Type
   * @param aStartclause The start clause. The iterator has to return a Boolean
   *        Value or Null.
   * @param aEndClause The end clause. The iterator has to return a Boolean
   *        Value or Null.
   * @param aLazyEval For Windowing the input sequence needs to be materialized.
   *        Is it allowed to do this lazy?
   * @param aMaxNeededHistory To allow Continous Queries we need to garbage
   *        collect a possible infinite input sequence. But the Start, End and
   *        other Clauses might require to look back from the start position of
   *        a window. The MaxNeededHistory specifies how much it is required to
   *        look back. If the value is MAX_HISTORY no Garbage Colleciton is performed.
   *
         */
  WindowIterator (
        static_context* sctx,
        const QueryLoc& loc,
        WindowType windowType,
        PlanIter_t tupleIter,
        PlanIter_t domainIterator,
        store::Item* varName,
        const std::vector<PlanIter_t >& varRefs,
        StartClause& startClause,
        EndClause& endClause,
        bool lazyEval = true,
        uint32_t maxNeededHistory = MAX_HISTORY);

  ~WindowIterator();

  void openImpl ( PlanState& aPlanState, uint32_t& aOffset );
  bool nextImpl ( store::Item_t& aResult, PlanState& aPlanState ) const;
  void resetImpl ( PlanState& aPlanState ) const;
  void closeImpl ( PlanState& aPlanState );

  virtual uint32_t getStateSize() const;
  virtual uint32_t getStateSizeOfSubtree() const;

  virtual void accept ( PlanIterVisitor& ) const;

private:
  void bindVariable(
        PlanState& aPlanState,
        const store::TempSeq_t& aInputSeq,
        const uint32_t aStartPos,
        const uint32_t aEndPos ) const;

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
