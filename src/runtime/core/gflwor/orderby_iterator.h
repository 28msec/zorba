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
#ifndef ZORBA_RUNTIME_GFLWOR_ORDERBY
#define ZORBA_RUNTIME_GFLWOR_ORDERBY

#include "zorbautils/checked_vector.h"

#include "common/shared_types.h"

#include "runtime/base/plan_iterator.h"
#include "runtime/core/gflwor/common.h"


namespace zorba 
{
namespace flwor 
{

class OrderByIterator;

class OrderValue;


/***************************************************************************//**
  Wrapper for a OrderSpec.

  - Syntax:

  OrderSpec ::= ExprSingle OrderModifier

  OrderModifier ::= ("ascending" | "descending")?
                    ("empty" ("greatest" | "least"))?
                    ("collation" URILiteral)?

  - Data Members:

  theInput         : The iterator computing the value of this orderby column for
                     each binding of the in-scope variables.
  theEmptyLeast    : Whether the empty seq should be considered the smallest or
                     the largest value.
  theDescending    : Whether to order in descending order or not.
  theNativeCompare : If true, then every pair of values in this orderby column
                     have data types such that the values can be compared using
                     the Item::equal() method (instead of the more expensive
                     CompareIterator::valueCompare() method).
  theCollation     : The collation to use when comparing values of this orderby
                     column (if the values are of type xs:string or subtype).
  theCollator      : Pointer to the collator obj corresponding to theCollation.
                     The pointer is assigned by the OrderByClause::open() method.
                     Note: no need to delete theCollator in ~OrderSpec() because
                     the obj is managed by the collation cache.
********************************************************************************/
class OrderSpec : public ::zorba::serialization::SerializeBaseClass
{
public:
  PlanIter_t             theDomainIter;

  bool                   theEmptyLeast;
  bool                   theDescending;
  bool                   theNativeCompare;
  std::string            theCollation;
  XQPCollator          * theCollator;

public:
  SERIALIZABLE_CLASS(OrderSpec)
  SERIALIZABLE_CLASS_CONSTRUCTOR(OrderSpec)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  OrderSpec() : theNativeCompare(false), theCollator(NULL) {}

  OrderSpec(
        PlanIter_t domainIter,
        bool emptyLeast,
        bool descending,
        bool nativeCompare,
        const std::string& collation);

  ~OrderSpec() {}

  void accept(PlanIterVisitor&) const;

  uint32_t getStateSizeOfSubtree() const;

  void open(PlanState& aPlanState, uint32_t& offset) const;
  void reset(PlanState& aPlanState) const;
  void close(PlanState& aPlanState) const;
};


/***************************************************************************//**
  A SortTuple ST stores the key values computed by the ordering exprs of an
  orderby clause for some input-stream tuple T. 

  For the generalized flwor, ST also stores the position of T in a data table
  that buffers the input tuple stream in inder to sort it.

  For a simple flwor, the T data is an iterator I over a temp sequence that
  stores the result of the return clause computed for the current input-
  stream tuple.
********************************************************************************/
class SortTuple
{
public:
  std::vector<store::Item*>   theKeyValues;
  ulong                       theDataPos;

public:
  SortTuple() { }

  ~SortTuple() { }

  void clear()
  {
    ulong numColumns = (ulong)theKeyValues.size();
    for (ulong i = 0; i < numColumns; ++i)
    {
      if (theKeyValues[i] != NULL)
      {
        theKeyValues[i]->removeReference();
        theKeyValues[i] = NULL;
      }
    }

    theKeyValues.clear();
  }
};


/*******************************************************************************
  theOderMap     : The table that materializes a flwor tuple stream in inder to
                   sort it. The entries of this table are instances of OrderByTuple.
  theNumTuples   : The number of tuples in theOrderMap.
  theCurTuplePos : A position inside theOrderMap. Used to return individual flwor
                   results after the full result set has been materialized and
                   sorted. 
********************************************************************************/
class OrderByState : public PlanIteratorState 
{
  friend class OrderByIterator;

public:
  typedef std::vector<SortTuple> SortTable;
  typedef std::vector<StreamTuple> DataTable;

protected:
  SortTable    theSortTable;
  DataTable    theDataTable;
  ulong        theNumTuples;
  ulong        theCurTuplePos;

public:
  OrderByState();

  ~OrderByState();

  void init(PlanState& planState, std::vector<OrderSpec>* orderSpecs);

  void reset(PlanState&);

private:
  void clearSortTable();
};


/*******************************************************************************

********************************************************************************/    
class OrderByIterator : public Batcher<OrderByIterator> 
{
private:
  bool                                  theStable;
  std::vector<OrderSpec>                theOrderSpecs;

  PlanIter_t                            theTupleIter;

  std::vector<ForVarIter_t>             theInputForVars;
  std::vector<LetVarIter_t>             theInputLetVars;
  std::vector<std::vector<PlanIter_t> > theOutputForVarsRefs;
  std::vector<std::vector<PlanIter_t> > theOutputLetVarsRefs;
  
public:
  SERIALIZABLE_CLASS(OrderByIterator)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(OrderByIterator, Batcher<OrderByIterator>)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  OrderByIterator(
        static_context* sctx,
        const QueryLoc& loc,
        bool stable,
        std::vector<OrderSpec>& orderSpecs,
        PlanIter_t tupleIterator,
        std::vector<ForVarIter_t>& inputForVars,
        std::vector<LetVarIter_t>& inputLetVars,
        std::vector<std::vector<PlanIter_t> >& outputForVarsRefs,
        std::vector<std::vector<PlanIter_t> >& outputLetVarsRefs);
  
  ~OrderByIterator();

  void openImpl(PlanState& planState, uint32_t& offset);
  bool nextImpl(store::Item_t& result, PlanState& planState) const;
  void resetImpl(PlanState& planState) const;
  void closeImpl(PlanState& planState);
  
  virtual uint32_t getStateSize() const;
  virtual uint32_t getStateSizeOfSubtree() const;

  virtual void accept(PlanIterVisitor&) const;

private:
  void materializeResultForSort(
        OrderByState* iterState,
        PlanState& planState) const;

  void bindOrderBy(
        OrderByState* iterState,
        PlanState& planState) const;
};


}//namespace gflwor
} //namespace zorba


#endif  /* ZORBA_RUNTIME_GFLWOR_ORDERBY */

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
