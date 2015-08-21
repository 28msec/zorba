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
#ifndef ZORBA_RUNTIME_FLWOR_ITERATOR
#define ZORBA_RUNTIME_FLWOR_ITERATOR

#include "zorbautils/checked_vector.h"

#include "common/shared_types.h"

#include "runtime/base/plan_iterator.h"
#include "runtime/core/gflwor/orderby_iterator.h"

namespace zorba
{

namespace store { class PUL; }

namespace flwor
{


/***************************************************************************//**
  Wraps a FOR or LET clause. There is one ForLetClause for each for/let variable.
  Note: we don't use separate ForClause and LetClause classes to avoid dynamic
  casts during the runtime.

  - Syntax:

  ForClause ::= "for" "$" VarName TypeDeclaration? PositionalVar? "in" ExprSingle

	LetClause ::= "let" "$" VarName TypeDeclaration? ":=" ExprSingle

  TypeDeclaration ::= "as" SequenceType

  PositionalVar ::= "at" "$" VarName

  - Data Members:

  theType       : Whether this is a FOR or a LET var.

  theForVarRefs : Vector of ForVarIters representing all references to this FOR
                  var. Each ForVarIter holds the current value of the var (as an
                  Item_t) and its next() method simply returns that value. The
                  value is computed and stored in the ForVarIter by the
                  bindValiable() method of the FLWORIterator.

  thePosVarRefs : Vector of ForVarIters representing all references to the positional
                  var (if any) associated with this FOR var.

  theLetVarRefs : Vector of LetVarIters representing all references to this LET
                  var. Each LetVarIter holds the current value of the var. The
                  "value" of a LET var is acually an iterator I; if the var is
                  materialized, I is an iterator over a temp sequence; otherwise,
                  I is an iterator wrapper over theInput iterator.

  theInput      : The iterator producing the domain (if FOR var) or the value (if
                  LET var) of this var.

  theMaterialize : Whether this LET var must be materialized or not. For example
                   "let $x := (1,2,3) return ($x, $x)" needs materialization, but
                   "let $x := (1,2,3) return if(test()) then $x else $x" doesn't.
********************************************************************************/
class ForLetClause : public ::zorba::serialization::SerializeBaseClass
{
  friend class FLWORIterator;
  friend class FlworState;
  friend class PrinterVisitor;

public:
  enum ForLetType { FOR, LET };

  zstring                    theVarName;

  ForLetType                 theType;

  PlanIter_t                 theInput;

  std::vector<PlanIter_t>    theVarRefs;

  std::vector<PlanIter_t>    thePosVarRefs;

  bool                       theSingleItemLETVar;

  bool                       theDoLazyEval;

public:
  SERIALIZABLE_CLASS(ForLetClause)
  SERIALIZABLE_CLASS_CONSTRUCTOR(ForLetClause)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  ForLetClause() {}

  ForLetClause(
        store::Item* varName,
        const std::vector<PlanIter_t>& forVars,
        PlanIter_t& input);

  ForLetClause(
        store::Item* varName,
        const std::vector<PlanIter_t>& forVars,
        const std::vector<PlanIter_t>& posVars,
        PlanIter_t& input);

  ForLetClause(
        store::Item* varName,
        const std::vector<PlanIter_t>& letVars,
        PlanIter_t& input,
        bool lazyEval,
        bool needsMaterialization);

  virtual ~ForLetClause() {}

  void accept (PlanIterVisitor&) const;

  zstring getVarName() const;

  void setSingleItem() { theSingleItemLETVar = true; }

  bool lazyEval() const { return theDoLazyEval; }
};


/***************************************************************************//**
 Wrapper for an OrderByClause

  Syntax:

	OrderByClause ::= (("order" "by") | ("stable" "order" "by")) OrderSpecList

	OrderSpecList ::= OrderSpec ("," OrderSpec)*

  OrderSpec ::= ExprSingle OrderModifier

  OrderModifier ::= ("ascending" | "descending")?
                    ("empty" ("greatest" | "least"))?
                    ("collation" URILiteral)?

  - Data Members:

  theOrderSpecs : The vector of OrderSpecs for this OrderByClause (see common.h
                  for the definition of class OrderSpec).
  theStable     : Whether the sorting must be stable or not.
********************************************************************************/
class OrderByClause : public ::zorba::serialization::SerializeBaseClass
{
  friend class FLWORIterator;

public:
  QueryLoc               theLocation;
  std::vector<OrderSpec> theOrderSpecs;
  bool                   theStable;

public:
  SERIALIZABLE_CLASS(OrderByClause)
  SERIALIZABLE_CLASS_CONSTRUCTOR(OrderByClause)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  OrderByClause() {}

  OrderByClause(
        const QueryLoc& loc,
        const std::vector<OrderSpec>& orderSpecs,
        bool stable);

  ~OrderByClause() {}

  void accept(PlanIterVisitor& v) const;

  uint32_t getStateSizeOfSubtree() const;

  void open(const static_context* sctx, PlanState& planState, uint32_t& offset);

  void close(PlanState& planState);

  void reset(PlanState& planState);
};


/***************************************************************************//**

********************************************************************************/
class MaterializeClause : public ::zorba::serialization::SerializeBaseClass
{
  friend class FLWORIterator;

protected:
  QueryLoc                              theLocation;

  std::vector<ForVarIter_t>             theInputForVars;
  std::vector<LetVarIter_t>             theInputLetVars;
  std::vector<std::vector<PlanIter_t> > theOutputForVarsRefs;
  std::vector<std::vector<PlanIter_t> > theOutputLetVarsRefs;

  std::vector<OrderSpec>                theOrderSpecs;
  bool                                  theStable;

public:
  SERIALIZABLE_CLASS(MaterializeClause)
  SERIALIZABLE_CLASS_CONSTRUCTOR(MaterializeClause)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  MaterializeClause(
      const QueryLoc& loc,
      std::vector<ForVarIter_t>& inputForVars,
      std::vector<LetVarIter_t>& inputLetVars,
      std::vector<std::vector<PlanIter_t> >& outputForVarsRefs,
      std::vector<std::vector<PlanIter_t> >& outputLetVarsRefs);

  ~MaterializeClause();

  void addSort(
      const QueryLoc& loc,
      std::vector<OrderSpec>& orderSpecs,
      bool stable);

  void accept(PlanIterVisitor& v) const;

  uint32_t getStateSizeOfSubtree() const;

  void open(const static_context* sctx, PlanState& planState, uint32_t& offset);

  void close(PlanState& planState);

  void reset(PlanState& planState);
};


/***************************************************************************//**
  Wrapper for a GroupByClause

  - Syntax:

  GroupByClause ::= "group" "by" GroupingSpecList

  GroupingSpecList ::= GroupingSpec ("," GroupingSpec)*

  GroupingSpec ::= "$" VarName ("collation" URILiteral)?

  - Data Members:

  theGroupingSpecs    :
  theNonGroupingSpecs :
********************************************************************************/
class GroupByClause : public ::zorba::serialization::SerializeBaseClass
{
  friend class FLWORIterator;
  friend class PrinterVisitor;

private:
  QueryLoc                     theLocation;
  std::vector<GroupingSpec>    theGroupingSpecs;
  std::vector<NonGroupingSpec> theNonGroupingSpecs;

public:
  SERIALIZABLE_CLASS(GroupByClause)
  SERIALIZABLE_CLASS_CONSTRUCTOR(GroupByClause)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  GroupByClause(
      const QueryLoc& loc,
      std::vector<GroupingSpec> aGroupingSpecs,
      std::vector<NonGroupingSpec> aNonGroupingSpecs);

  ~GroupByClause() {}

  void accept(PlanIterVisitor& v) const;

  uint32_t getStateSizeOfSubtree() const;

  void open(static_context* sctx, PlanState& planState, uint32_t& offset);
  void reset(PlanState& planState);
  void close(PlanState& planState);
};


/*******************************************************************************

  - theVarBindingState :
  ----------------------
  A vector that stores, for each LET var, if the var is already bound or not,
  and for for each FOR var its positional integer value.

  - theTempSeqs :
  ---------------
  For each LET var, this vector stores a handle to a temp seq that will store
  the "current" value of the LET var. Note: The size of the vector is equal to
  the total number of FOR/LET variables. The entry at position "pos" corresponds
  to the variable that, suntactically, appears at position "pos" within the
  flwor expr. The entries corresponding to FOR vars are left empty.

  - theTempSeqIters :
  -------------------
  For each LET var, this vector stores a handle to a PlanIteratorWrapper over
  the subplan that computes the domain expr of the LET var. This
  PlanIteratorWrapper is given as input to the init() method of the temp seq
  corresponding to the same LET var (and stored in theTempSeqs).

  - theTuplesTable :
  ------------------
  The table that materializes the tuple stream before computing the return
  clause. This is needed only if  the return expr is a sequential one.

  - theSortTable :
  ----------------
  The table that materializes the sort tuples in order to sort them. The entries
  of this table are instances of SortTuple (see gflwor/orderby_iterator.h).

  - theResultTable :
  ------------------
  If the flwor expr is non-sequential and contains orderby, then for each stream
  tuple, both the sort tuple and the return expr are evaluated and stored before
  the next stream tuple is evaluated. The sort tuple is stored in theSortTable,
  and the result of the return expr is stored in theResultTable. The result is
  stored in the form of an iterator over a temp seq that stores the actual result.

  - theNumTuples :
  ----------------
  The number of tuples in theTuplesTable or theSortTable.

  - theCurTuplePos :
  ----------------
  The "current" position inside theTuplesTable or theSortTable. It is used after
  theTuplesTable or theSortTable has been fully materialized, to iterate over
  the tuples and evaluate and return the results of the return clause for each
  tuple.

  - theOrderResultIter :
  ----------------------
  The iterator I over a temp sequence that stores the result of return clause
  for the tuple pointed to by theCurTuplePos.

  - theGroupMap :
  ---------------

  - theGroupMapIter :
  -------------------

  - thePUL :
  ----------

  - theFirstResult :
  ------------------

********************************************************************************/
class FlworState : public PlanIteratorState
{
  friend class FLWORIterator;

public:
  typedef std::vector<SortTuple> SortTable;

  typedef std::vector<store::Iterator_t> ResultTable;

  typedef std::vector<StreamTuple> TuplesTable;

protected:
  std::vector<long>              theVarBindingState;

  std::vector<store::TempSeq_t>  theTempSeqs;

  std::vector<store::Iterator_t> theTempSeqIters;

  TuplesTable                    theTuplesTable;

  SortTable                      theSortTable;

  ResultTable                    theResultTable;

  ulong                          theNumTuples;

  ulong                          theCurTuplePos;

  store::Iterator_t              theOrderResultIter;

  GroupHashMap                 * theGroupMap;

  GroupHashMap::iterator         theGroupMapIter;

  store::PUL_t                   thePUL;

  bool                           theFirstResult;

public:
  FlworState();

  ~FlworState();

  void init(PlanState& state, const std::vector<ForLetClause>& forletClauses);

  void init(
      PlanState& state,
      TypeManager* tm,
      const std::vector<ForLetClause>& forletClauses,
      std::vector<OrderSpec>* orderSpecs,
      const QueryLoc& groupbyLoc,
      std::vector<GroupingSpec>* groupingSpecs);

  void reset(PlanState&);

private:
  void clearSortTable();
  void clearGroupMap();
};


/***************************************************************************//**
  Main FLWOR class designed according to
  http://www.w3.org/TR/xquery/#id-flwor-expressions, extended to support one
  optional group-by clause.

  Syntax:

  FLWORExpr ::= (ForClause | LetClause)+
                WhereClause?
                GroupByClause ?
                OrderByClause?
                "return" ExprSingle

  - Data Members:

********************************************************************************/
class FLWORIterator : public PlanIterator
{
private:
  std::vector<ForLetClause> theForLetClauses;
  csize                     theNumBindings;
  PlanIter_t                theWhereClause;
  GroupByClause           * theGroupByClause;
  OrderByClause           * theOrderByClause;
  MaterializeClause       * theMaterializeClause;
  PlanIter_t                theReturnClause;

public:
  SERIALIZABLE_CLASS(FLWORIterator);
  SERIALIZABLE_CLASS_CONSTRUCTOR2(FLWORIterator, PlanIterator);
  void serialize(::zorba::serialization::Archiver& ar);

public:
  FLWORIterator(
      static_context*             sctx,
      const QueryLoc&             loc,
      std::vector<ForLetClause>&  forLetClauses,
      PlanIter_t&                 whereClause,
      GroupByClause*              aGroupByClause,
      OrderByClause*              orderByClause,
      MaterializeClause*          materializeClause,
      PlanIter_t&                 returnClause);

  ~FLWORIterator();

  void openImpl(PlanState& planState, uint32_t& offset);
  bool nextImpl(store::Item_t& result, PlanState& planState) const;
  void resetImpl(PlanState& planState) const;
  void closeImpl(PlanState& planState);

  zstring getNameAsString() const;

  uint32_t getStateSize() const;

  uint32_t getStateSizeOfSubtree() const;

  void accept(PlanIterVisitor&) const;

private:
  bool bindVariable(
      ulong varNo,
      FlworState* flworState,
      PlanState& planState) const;

  bool evalToBool(
      const PlanIter_t& checkIter,
      PlanState& planState) const;

  void materializeStreamTuple(
      FlworState* flworState,
      PlanState& planState) const;

  void materializeSortTupleAndResult(
      FlworState* flworState,
      PlanState& planState) const;

  void materializeGroupTuple(
      FlworState* flworState,
      PlanState& planState) const;

  void rebindStreamTuple(
      ulong tuplePos,
      FlworState* iterState,
      PlanState& planState) const;

  void rebindGroupTuple(
      GroupHashMap::iterator groupMapIter,
      FlworState* flworState,
      PlanState& planState) const;

  void rebindGroupTuplesForMaterialize(
      FlworState* iterState,
      PlanState& planState) const;

  void rebindGroupTuplesForSort(
      FlworState* iterState,
      PlanState& planState) const;
};


}
} /* namespace zorba */
#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
