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
  friend class PrinterVisitor;

protected:
  enum ForLetType { FOR, LET };

  xqpStringStore_t           theVarName;

  ForLetType                 theType;
  std::vector<ForVarIter_t>  theForVarRefs;
  std::vector<ForVarIter_t>  thePosVarRefs;
  std::vector<LetVarIter_t>  theLetVarRefs;
  PlanIter_t                 theInput;
  bool                       theMaterialize;
    
public:
  SERIALIZABLE_CLASS(ForLetClause)
  SERIALIZABLE_CLASS_CONSTRUCTOR(ForLetClause)
  ForLetClause() {}
  void serialize(::zorba::serialization::Archiver &ar)
  {
    ar & theVarName;
    SERIALIZE_ENUM(ForLetType, theType)
    ar & theForVarRefs;
    ar & thePosVarRefs;
    ar & theLetVarRefs;
    ar & theInput;
    ar & theMaterialize;
  }
public:
  ForLetClause(
        const store::Item_t& varName,
        const std::vector<PlanIter_t>& forVars,
        PlanIter_t& input);

  ForLetClause(
        const store::Item_t& varName,
        const std::vector<PlanIter_t>& forVars,
        const std::vector<PlanIter_t>& posVars,
        PlanIter_t& input);

  ForLetClause(
        const store::Item_t& varName,
        const std::vector<PlanIter_t>& letVars,
        PlanIter_t& input,
        bool needsMaterialization);
  virtual ~ForLetClause() {}
          
  void accept (PlanIterVisitor&) const;

  xqpStringStore_t getVarName() const;
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
                  the the definition of class OrderSpec).
  theStable     : Whether the sorting must be stable or not.
********************************************************************************/
class OrderByClause : public ::zorba::serialization::SerializeBaseClass
{
  friend class FLWORIterator;
  
public:
  std::vector<OrderSpec> theOrderSpecs;
  bool                   theStable;
  
public:
  SERIALIZABLE_CLASS(OrderByClause)
  SERIALIZABLE_CLASS_CONSTRUCTOR(OrderByClause)
  OrderByClause() {}
  void serialize(::zorba::serialization::Archiver &ar)
  {
    ar & theOrderSpecs;
    ar & theStable;
  }

public:
  OrderByClause(const std::vector<OrderSpec>& orderSpecs, bool stable);

  ~OrderByClause() {}

  void accept(PlanIterVisitor& v) const;

  uint32_t getStateSizeOfSubtree() const;

  void open(static_context* sctx, PlanState& planState, uint32_t& offset);
  void reset(PlanState& planState);
  void close(PlanState& planState); 
};


/***************************************************************************//**
  Wrapper for a GroupByClause

  - Syntax:

  GroupByClause ::= "group" "by" GroupingSpecList

  GroupingSpecList ::= GroupingSpec ("," GroupingSpec)*

  GroupingSpec ::= "$" VarName ("collation" URILiteral)?

  - Data Members:

  theGroupingSpecs :
  theOuterVars     :
********************************************************************************/
class GroupByClause : public ::zorba::serialization::SerializeBaseClass
{
  friend class FLWORIterator;
  friend class PrinterVisitor;
  
private:
  std::vector<GroupingSpec>     theGroupingSpecs;
  std::vector<GroupingOuterVar> theOuterVars;
    
public:
  SERIALIZABLE_CLASS(GroupByClause)
  SERIALIZABLE_CLASS_CONSTRUCTOR(GroupByClause)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    ar & theGroupingSpecs;
    ar & theOuterVars;
  }

public:
  GroupByClause(
        std::vector<GroupingSpec> aGroupingSpecs, 
        std::vector<GroupingOuterVar> aOuterVars);

  ~GroupByClause() {}

  void accept(PlanIterVisitor& v) const;

  uint32_t getStateSizeOfSubtree() const;

  void open(static_context* sctx, PlanState& planState, uint32_t& offset);
  void reset(PlanState& planState);
  void close(PlanState& planState); 
};


/*******************************************************************************

  theVarBindingState : A vector that stores, for each LET var, if the var is
                       already bound or not, and for for each FOR var its
                       positional integer value.

  theSortTable       : The table that materializes a flwor tuple stream in inder
                       to sort it. The entries of this table are instances of
                       SortTuple (see gflwor/orderby_iterator.h).
  theNumTuples       : The number of tuples in theSort.
  theCurTuplePos     : A position inside theSortTable. Used, together with
                       theOrderResultIter, to return individual flwor results
                       after the full result set has been materialized and sorted. 
  theOrderResultIter : The iterator I over a temp sequence that stores the result
                       of return clause for the tuple pointed to by theCurTuplePos.

  theGroupMap        :

  theGroupMapIter    :
********************************************************************************/
class FlworState : public PlanIteratorState
{
  friend class FLWORIterator;

public:
  typedef std::vector<SortTuple> SortTable;
  typedef std::vector<store::Iterator_t> DataTable;

protected:
  checked_vector<uint32_t>      theVarBindingState;
          
  SortTable                     theSortTable;
  DataTable                     theDataTable;
  ulong                         theNumTuples;
  ulong                         theCurTuplePos;

  store::Iterator_t             theOrderResultIter; 

  GroupHashMap                * theGroupMap; 
  GroupHashMap::iterator        theGroupMapIter;

public:
  FlworState();

  ~FlworState();

  void init(PlanState& state, size_t numVars);
          
  void init(
        PlanState& state,
        TypeManager* tm,
        size_t numVars,
        std::vector<OrderSpec>* orderSpecs,
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
class FLWORIterator : public Batcher<FLWORIterator>
{
private:
  std::vector<ForLetClause> theForLetClauses;
  PlanIter_t                theWhereClause;
  GroupByClause           * theGroupByClause;
  OrderByClause           * theOrderByClause;
  bool                      doOrderBy; 
  bool                      doGroupBy;
  PlanIter_t                theReturnClause; 
  bool                      theIsUpdating;
  /*const */int             theNumBindings; //Number of FORs and LETs (overall) 
         
public:
  SERIALIZABLE_CLASS(FLWORIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2(FLWORIterator, Batcher<FLWORIterator>);

  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (Batcher<FLWORIterator>*)this);
    ar & theForLetClauses;
    ar & theWhereClause; //can be null
    ar & theGroupByClause;
    ar & theOrderByClause;  //can be null
    ar & doOrderBy; //just indicates if the FLWOR has an orderby
    ar & doGroupBy;
    ar & theReturnClause; 
    ar & theIsUpdating;
    ar & theNumBindings; //Number of FORs and LETs (overall) 
  }
public:
  FLWORIterator(
        static_context*             sctx,
        const QueryLoc&             loc,
        std::vector<ForLetClause>&  forLetClauses,
        PlanIter_t&                 whereClause,
        GroupByClause*              aGroupByClause,
        OrderByClause*              orderByClause,
        PlanIter_t&                 returnClause,
        bool                        aIsUpdating );
    
  ~FLWORIterator();

  virtual bool isUpdating() const { return theIsUpdating; }

  void openImpl(PlanState& planState, uint32_t& offset);
  bool nextImpl(store::Item_t& result, PlanState& planState) const;
  void resetImpl(PlanState& planState) const;
  void closeImpl(PlanState& planState);

  virtual uint32_t getStateSize() const;
  virtual uint32_t getStateSizeOfSubtree() const;
  
  void accept ( PlanIterVisitor& ) const;

private:
  bool bindVariable(int varNb, FlworState* flworState, PlanState& planState) const;

  void resetVariable(int varNb, FlworState* flworState, PlanState& planState) const;
    
  bool evalToBool(const PlanIter_t& checkIter, PlanState& planState) const;
    
  void materializeResultForSort(FlworState* flworState, PlanState& planState) const;
  
  void materializeGroupResultForSort(FlworState* flworState, PlanState& planStat) const;

  void matVarsAndGroupBy(FlworState* flworState, PlanState& planState) const;
      
  void bindGroupBy(
        GroupHashMap::iterator lGroupMapIter,
        FlworState* flworState,
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
