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
#include "runtime/util/handle_hashmap_item_value.h"

namespace zorba
{

  namespace store 
  {
    class PUL;
    //template<class V>
    //class ItemValuesCollHandleHashMap;
    //class ValueCollCompareParam;
    //class GroupCompareParam;
  }

  class FlworState;

/***************************************************************************//**
  Main FLWOR class designed according to
  http://www.w3.org/TR/xquery/#id-flwor-expressions. 

  The complete tuple-stream handling is done in this class. 
********************************************************************************/
class FLWORIterator : public Batcher<FLWORIterator>
{
public:
  class OrderKeyCmp;
  
  typedef std::multimap<std::vector<store::Item_t>,
                        store::Iterator_t,
                        OrderKeyCmp> order_map_t;

  typedef ItemValuesCollHandleHashMap<std::vector<store::TempSeq_t>* > group_map_t;

  /**
   * Wrappes a FOR or LET clause. There is one ForLetClause for each for/let
   * variable. Note: we don't use separate ForClause and LetClause classes to
   * avoid dynamic casts during the runtime.
   */
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
    std::vector<ForVarIter_t>  theForVars;
    std::vector<ForVarIter_t>  thePosVars;
    std::vector<LetVarIter_t>  theLetVars;
    PlanIter_t                 theInput;
    bool                       theNeedsMaterialization;
    
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

  
  /**
   *
   */
  class GroupingSpec
  {
    friend class FLWORIterator;
    friend class PrinterVisitor;
    friend class GroupByClause;//Just for older gcc's
  
  protected:
    PlanIter_t                theInput;
    std::vector<ForVarIter_t> theInnerVars;
    xqpString                 theCollation;
  
  public:
    GroupingSpec(
        PlanIter_t aInput,
        std::vector<ForVarIter_t> aInnerVars,
        xqpString aCollation );

    void accept ( PlanIterVisitor& ) const;

    void open ( PlanState& planState, uint32_t& offset );
    void close ( PlanState& planState );

    uint32_t getStateSizeOfSubtree() const; 
  };
  

  /**
   *
   */
  class GroupingOuterVar
  {
    friend class FLWORIterator;
    friend class PrinterVisitor;
    friend class GroupByClause; //Just for older gcc's
  
  protected:
    PlanIter_t                theInput;
    std::vector<LetVarIter_t> theOuterVars;
  
  public:
    GroupingOuterVar(PlanIter_t aInput, std::vector<LetVarIter_t> aOuterVars);

    void accept ( PlanIterVisitor& ) const;

    void open ( PlanState& planState, uint32_t& offset );
    void close ( PlanState& planState );

    uint32_t getStateSizeOfSubtree() const; 
  };
  

  /**
   *
   */
  class GroupByClause
  {
    friend class FLWORIterator;
    friend class PrinterVisitor;
  
  private:
    std::vector<GroupingSpec> theGroupingSpecs;
    std::vector<GroupingOuterVar> theOuterVars;
    PlanIter_t theWhere;
    
  public:
    GroupByClause(std::vector<GroupingSpec> aGroupingSpecs, 
                  std::vector<GroupingOuterVar> aOuterVars,
                  PlanIter_t aWhere);
    void accept ( PlanIterVisitor& ) const;
    void open ( PlanState& planState, uint32_t& offset );
    void close( PlanState& planState);
    uint32_t getStateSizeOfSubtree() const; 
  };


  /**
   * Wrapper for a OrderSpec
   * http://www.w3.org/TR/xquery/#id-orderby-return
   */
  class OrderSpec
  {
    friend class FLWORIterator;
    friend class OrderKeyCmp;

  protected:
    PlanIter_t             theOrderByIter;
    bool                   theEmptyLeast;
    bool                   theDescending;
    mutable RuntimeCB    * theRuntimeCB; // TODO hack
    xqpString              theCollation;
    mutable XQPCollator  * theCollator; // TODO hack

  public:
    OrderSpec ( PlanIter_t orderByIter, bool empty_least, bool descending );
    OrderSpec ( PlanIter_t orderByIter, bool empty_least, bool descending, const xqpString& collation );

    void accept ( PlanIterVisitor& ) const;
  };
  

  /**
   * Wrapper for a orderByClause
   * See http://www.w3.org/TR/xquery/#id-orderby-return
   */
  class OrderByClause
  {
    friend class FLWORIterator;
  
  public:
    std::vector<OrderSpec> orderSpecs;
    bool                   stable;

  public:
    OrderByClause ( std::vector<OrderSpec> orderSpecs, bool stable );

    void accept ( PlanIterVisitor& ) const;
  };


  /**
   * Class to pass to the MultiMap to do the comparison according to the OrderByClause. 
   * Luckily the MultiMap is stable already :-)
   */
  class OrderKeyCmp
  {
  private:
    std::vector<OrderSpec> * mOrderSpecs;
    TypeManager            * theTypeManager;
    long                     theTimezone;

  public:
    OrderKeyCmp() : mOrderSpecs(0), theTypeManager(0), theTimezone(0) {}

    OrderKeyCmp(RuntimeCB* rcb, std::vector<OrderSpec>* aOrderSpecs) 
      :
      mOrderSpecs ( aOrderSpecs ) 
    {
      theTypeManager = rcb->theStaticContext->get_typemanager();
      theTimezone = rcb->theDynamicContext->get_implicit_timezone();
    }

    bool operator() (
        const std::vector<store::Item_t>& s1,
        const std::vector<store::Item_t>& s2 ) const;
          
    /**
     * Does the actual comparision
     * @return   -1, if item0 &lt; item1
     *            0, if item0 == item1
     *            1, if item0 &gt; item1
     */
    inline long compare(
        const store::Item_t& s1,
        const store::Item_t& s2,
        bool asc,
        bool emptyLeast,
        XQPCollator* collator) const;
    
    /**
     * Helper functions to switch the ordering between ascending and descending
     */
    inline long descAsc(long result, bool asc) const;
  };
       
  
  /* ####################################################
   * Here we have the actual FLWOR class
   * #################################################### 
   */
    
public:
  /**
   * Constructor
   * @param loc location
   * @param forLetClauses For and Lets: Attention the order matters!
   * @param whereClause The where-clause iterator. Can be null
   * @param orderByClause The order by expressions. Can be null
   * @param returnClause The return expressions
   * @param whereClauseReturnsBooleanPlus Optional flag.
   *  If true => The iterator has to return xs:boolean+
   */
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
  void openImpl ( PlanState& planState, uint32_t& offset );
  bool nextImpl(store::Item_t& result, PlanState& planState) const;
  void resetImpl(PlanState& planState) const;
  void closeImpl(PlanState& planState);

  virtual uint32_t getStateSize() const;
  virtual uint32_t getStateSizeOfSubtree() const;
  
  void accept ( PlanIterVisitor& ) const;

private:
  /**
   * Resets a input of a FOR or LET
   */
  void resetInput(const int& varNb, FlworState* flworState, PlanState& planState) const;
      
  /**
   * Binds the variable to all its places
   */
  bool bindVariable ( int varNb, FlworState* flworState, PlanState& planState ) const;
    
  /**
   * Evaluates the checkItere to the EBV. If the checkIter = NULL true is returned
   */
  bool evalToBool(const PlanIter_t& checkIter, PlanState& planState ) const;
    
  /**
   * Materialized the result after binding the variables (needed for OrderBy)
   */
  void matResultAndOrder (FlworState* flworState, PlanState& planState) const;
  
  /**
   * Materialized the result after binding the variables and do the grouping
   */
  void matVarsAndGroupBy(FlworState* flworState, PlanState& planState) const;
      
  void groupAndOrder(FlworState* flworState, PlanState& planStat) const;
      
  void bindGroupBy(FLWORIterator::group_map_t::iterator lGroupMapIter,
                       FlworState* flworState,
                       PlanState& planState) const;
      
private:
  std::vector<ForLetClause> forLetClauses;
  PlanIter_t                whereClause; //can be null
  GroupByClause           * theGroupByClause;
  OrderByClause           * orderByClause;  //can be null
  bool                      doOrderBy; //just indicates if the FLWOR has an orderby
  bool                      doGroupBy;
  PlanIter_t                returnClause; 
  //bool                      whereClauseReturnsBooleanPlus;
  bool                      theIsUpdating;
  const int                 theNumBindings; //Number of FORs and LETs (overall)  
};



/*******************************************************************************

  varBindingState : A vector that stores, for each LET, if the LET is already
                    bound or not, and for for each FOR its positional integer
                    value.

  orderMap        : An std::multimap used to implement the order-by clause.
                    For each binding V of the for/let variables, the order-by
                    tuple T is evaluated and stored in this multimap. The value
                    associated with T is an iterator over a temp sequence that
                    computes the return clause for the V binding.

********************************************************************************/
class FlworState : public PlanIteratorState
{
public:
  checked_vector<uint32_t>                    varBindingState;
          
  //When returning the result, this indicates, which return sequence we are
  // touching at the moment and the curOrderPos indicates 
  FLWORIterator::order_map_t                * orderMap; 
  FLWORIterator::group_map_t                * groupMap; 
  GroupCompareParam                         * valueCompareParam;
  store::Iterator_t                           curOrderResultSeq; 
  FLWORIterator::order_map_t::const_iterator  curOrderPos; 
  FLWORIterator::group_map_t::iterator        curGroupPos;

public:
  FlworState();

  ~FlworState();

  /**
   * Init the state for a certain nb of variables but not the ordering
   * @nb_variables  Number of FOR and LET clauses
   */
  void init(PlanState& state, size_t numVars);
          
  /**
   * Init the state for a certain nb of variables, ordering and goruping
   * @nb_variables  Number of FOR and LET clauses
   * @orderSpecs    The OrderSpec which defines how to compare during ordering
   * @groupingCollation    The GoupingColaltion which defines how to compare during grouping
   */
  void init(
        PlanState& state,
        size_t numVars,
        std::vector<FLWORIterator::OrderSpec>* orderSpecs,
        std::vector<XQPCollator*>* groupingCollation );
  
  /**
   * Resets the state
   */
  void reset(PlanState&);
};  


} /* namespace zorba */
#endif  /* ZORBA_ITEM_ITERATOR_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
