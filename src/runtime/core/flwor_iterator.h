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
#include "runtime/core/gflwor/common.h"

namespace zorba
{

namespace store { class PUL; }

namespace flwor
{

class FlworState;


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
class ForLetClause 
{
  friend class FLWORIterator;
  friend class PrinterVisitor;

protected:
  enum ForLetType { FOR, LET };

#ifndef NDEBUG
  xqpStringStore             theVarName;
#endif
  ForLetType                 theType;
  std::vector<ForVarIter_t>  theForVarRefs;
  std::vector<ForVarIter_t>  thePosVarRefs;
  std::vector<LetVarIter_t>  theLetVarRefs;
  PlanIter_t                 theInput;
  bool                       theMaterialize;
    
public:
  ForLetClause(
        const var_expr* var,
        std::vector<ForVarIter_t> forVars,
        PlanIter_t& input);
          
  ForLetClause(
        const var_expr* var,
        std::vector<ForVarIter_t> forVars,
        std::vector<ForVarIter_t> posVars,
        PlanIter_t& input);
    
  ForLetClause(
        const var_expr* var,
        std::vector<LetVarIter_t> letVars,
        PlanIter_t& input,
        bool needsMaterialization);
          
  void accept (PlanIterVisitor&) const;

  xqpStringStore getVarName() const;
};


/***************************************************************************//**
 Wrapper for an OrderByClause
 See http://www.w3.org/TR/xquery/#id-orderby-return

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
class OrderByClause
{
  friend class FLWORIterator;
  
public:
  std::vector<OrderSpec> theOrderSpecs;
  bool                   theStable;
  
public:
  OrderByClause(std::vector<OrderSpec> orderSpecs, bool stable);

  void accept(PlanIterVisitor& v) const;

  uint32_t getStateSizeOfSubtree() const;

  void open(PlanState& planState, uint32_t& offset);
  void reset(PlanState& planState);
  void close(PlanState& planState); 
};


/***************************************************************************//**
  Wrapper for a GroupByClause
  See http://www.w3.org/TR/xquery-11/#id-group-by

  Syntax:

  GroupByClause ::= "group" "by" GroupingSpecList

  GroupingSpecList ::= GroupingSpec ("," GroupingSpec)*

  GroupingSpec ::= "$" VarName ("collation" URILiteral)?

  - Data Members:

  theGroupingSpecs :
  theOuterVars     :
  theWhere         :
********************************************************************************/
class GroupByClause
{
  friend class FLWORIterator;
  friend class PrinterVisitor;
  
private:
  std::vector<GroupingSpec>     theGroupingSpecs;
  std::vector<GroupingOuterVar> theOuterVars;
  PlanIter_t                    theWhere;
    
public:
  GroupByClause(
        std::vector<GroupingSpec> aGroupingSpecs, 
        std::vector<GroupingOuterVar> aOuterVars,
        PlanIter_t aWhere);

  void accept(PlanIterVisitor& v) const;

  uint32_t getStateSizeOfSubtree() const;

  void open(PlanState& planState, uint32_t& offset);
  void reset(PlanState& planState);
  void close(PlanState& planState); 
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
public:
  typedef std::multimap<std::vector<store::Item_t>,
                        store::Iterator_t,
                        OrderTupleCmp> order_map_t;

private:
  std::vector<ForLetClause> theForLetClauses;
  PlanIter_t                theWhereClause; //can be null
  GroupByClause           * theGroupByClause;
  OrderByClause           * theOrderByClause;  //can be null
  bool                      doOrderBy; //just indicates if the FLWOR has an orderby
  bool                      doGroupBy;
  PlanIter_t                theReturnClause; 
  bool                      theIsUpdating;
  const int                 theNumBindings; //Number of FORs and LETs (overall) 
         
public:
  FLWORIterator(
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
    
  void matResultAndOrder(FlworState* flworState, PlanState& planState) const;
  
  void matVarsAndGroupBy(FlworState* flworState, PlanState& planState) const;
      
  void groupAndOrder(FlworState* flworState, PlanState& planStat) const;
      
  void bindGroupBy(
        GroupHashMap::iterator lGroupMapIter,
        FlworState* flworState,
        PlanState& planState) const; 
};



/*******************************************************************************

  theVarBindingState : A vector that stores, for each LET var, if the var is
                       already bound or not, and for for each FOR var its
                       positional integer value.

  theOderMap         : An std::multimap used to implement the order-by clause.
                       For each full binding V of the for/let variables, the 
                       order-by tuple T is evaluated and stored in this multimap.
                       The value associated with T is an iterator I over a temp
                       sequence that stores the return-clause sequence R for the
                       V binding.
  theOrderMapIter    : Iterator over theOrderMap. Used, together with theOrderResultIter,
                       to return individual flwor results after the full result set
                       has been materialized and ordered. 
  theOrderResultIter : The iterator I associated with the tuple T that is pointed
                       to by theOrderMapIter.

  theGroupMap        :

  theGroupMapIter    :
********************************************************************************/
class FlworState : public PlanIteratorState
{
public:
  checked_vector<uint32_t>                    theVarBindingState;
          
  FLWORIterator::order_map_t                * theOrderMap; 
  FLWORIterator::order_map_t::const_iterator  theOrderMapIter;
  store::Iterator_t                           theOrderResultIter; 

  GroupHashMap                              * theGroupMap; 
  GroupHashMap::iterator                      theGroupMapIter;

public:
  FlworState();

  ~FlworState();

  void init(PlanState& state, size_t numVars);
          
  void init(
        PlanState& state,
        size_t numVars,
        std::vector<OrderSpec>* orderSpecs,
        std::vector<GroupingSpec>* groupingSpecs);
  
  void reset(PlanState&);
};  


}
} /* namespace zorba */
#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
