/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *  Author: Tim Kraska
 *
 */


#ifndef ZORBA_RUNTIME_FLWOR_ITERATOR
#define ZORBA_RUNTIME_FLWOR_ITERATOR

#include "common/shared_types.h"
#include "util/checked_vector.h"
#include "runtime/base/plan_iterator.h"

namespace zorba
{

namespace store 
{
  class PUL;
}

class FlworState;

 
 /**
  Main FLWOR class designed according to http://www.w3.org/TR/xquery/#id-flwor-expressions. 
  The complete tuple-stream handling is done in this class. 
 */
class FLWORIterator : public Batcher<FLWORIterator>
{
public:
  class OrderKeyCmp;
  
  typedef std::multimap<std::vector<store::Item_t>, store::Iterator_t, OrderKeyCmp> order_map_t;
      
  /**
     Wrappes a FOR or LET clause. 
     It is combined to avoid dynamic casts during the runtime
  */
  class ForLetClause 
  {
    friend class FLWORIterator;
    friend class PrinterVisitor;

  protected:
    enum ForLetType {FOR, LET};

#ifndef NDEBUG
    xqpStringStore           theVarName;
#endif
    ForLetType               theType;
    std::vector<var_iter_t>  theForVars;
    std::vector<var_iter_t>  thePosVars;
    std::vector<ref_iter_t>  theLetVars;
    PlanIter_t               theInput;
    bool                     theNeedsMaterialization;

  public:
    /**
     * Creates a new ForClause
     */
    ForLetClause(
        const var_expr* var,
        std::vector<var_iter_t> forVars,
        PlanIter_t& input);
          
    /**
     * Creates a new ForClause including positional variable bindings 
     */
    ForLetClause(
        const var_expr* var,
        std::vector<var_iter_t> forVars,
        std::vector<var_iter_t> posVars,
        PlanIter_t& input);

    /**
     * Creates a new LetClause
     * needsMaterialization indicates if it is necassary to materialize the LET-Binding:
     * E.g. "let $x := (1,2,3) return ($x, $x)" needs materialization.
     * but "let $x := (1,2,3) return if(test()) then $x else $x" doesn't
     */
    ForLetClause(
        const var_expr* var,
        std::vector<ref_iter_t> letVars,
        PlanIter_t& input,
        bool needsMaterialization);
          
    void accept (PlanIterVisitor&) const;

    xqpStringStore getVarName() const;
  };

  class GroupClause
  {
    friend class FLWORIterator;
    friend class PrinterVisitor;
  private:
    PlanIter_t              theInput;
    std::vector<ref_iter_t> theInnerVars;
    xqpString               theCollation;

  public:
    GroupClause(PlanIter_t aInput, std::vector<ref_iter_t> aInnerVars);
    GroupClause(PlanIter_t aInput, std::vector<ref_iter_t> aInnerVars, xqpString& aCollation);

    void accept ( PlanIterVisitor& ) const;
  };

  /**
   *  Wrapper for a OrderSpec
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
    void accept ( PlanIterVisitor& ) const;
    OrderSpec ( PlanIter_t orderByIter, bool empty_least, bool descending );
    OrderSpec ( PlanIter_t orderByIter, bool empty_least, bool descending, const xqpString& collation );
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
    void accept ( PlanIterVisitor& ) const;
    OrderByClause ( std::vector<OrderSpec> orderSpecs, bool stable );
  };


  /**
   * Class to pass to the MultiMap to do the comparison according to the OrderByClause. 
   * Luckily the MultiMap is stable already :-)
   */
  class OrderKeyCmp
  {
  public:
    OrderKeyCmp() : mOrderSpecs ( 0 ) {}
    OrderKeyCmp ( std::vector<OrderSpec>* aOrderSpecs ) 
      : mOrderSpecs ( aOrderSpecs ) {}

    /**
     * The key comparison function, a Strict Weak Ordering whose argument type is key_type;
     * it returns true if its first argument is less than its second argument, and false otherwise.
     * This is also defined as multimap::key_compare.
     */
    bool operator() ( const std::vector<store::Item_t>& s1, const std::vector<store::Item_t>& s2 ) const;
          
    /**
     * Does the actual comparision
     * @return    -1, if item0 &lt; item1
     *            0, if item0 == item1
     *            1, if item0 &gt; item1
     */
    inline int8_t compare(
        RuntimeCB* aRuntimeCB,
        const store::Item_t& s1,
        const store::Item_t& s2,
        bool asc,
        bool emptyLeast,
        XQPCollator* collator = 0) const;
          
    /**
     * Helper functions to switch the ordering between ascending and descending
     */
    inline int8_t descAsc(int8_t result, bool asc) const;
    
  private:
    std::vector<OrderSpec>* mOrderSpecs; //Pointer to the OrderSpec to do the comparison accordingly  
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
        std::vector<GroupClause>&   aGroupByClauses,
        OrderByClause*              orderByClause,
        PlanIter_t&                 returnClause,
        bool                        aIsUpdating,
        bool                        whereClauseReturnsBooleanPlus = false );
    
  ~FLWORIterator();

  virtual bool isUpdating() const { return theIsUpdating; }
  void openImpl ( PlanState& planState, uint32_t& offset );
  store::Item_t nextImpl(PlanState& planState) const;
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
   * Evaluates the where clause. If there doesn't exist a where clause it returns always true
   */
  bool evalWhereClause( PlanState& planState ) const;
    
  /**
   * Materialized the result after binding the variables (needed for OrderBy)
   */
  void matResultAndOrder (FlworState* flworState, PlanState& planState) const;
      
 private:
  std::vector<ForLetClause> forLetClauses;
  PlanIter_t                whereClause; //can be null
  std::vector<GroupClause>  theGroupByClauses;
  OrderByClause           * orderByClause;  //can be null
  bool                      doOrderBy; //just indicates if the FLWOR has an orderby
  PlanIter_t                returnClause; 
  bool                      whereClauseReturnsBooleanPlus;
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
  store::Iterator_t                                  curOrderResultSeq; 
  FLWORIterator::order_map_t::const_iterator  curOrderPos; 

  /**
   * Init the state for a certain nb of variables but not the ordering
   * @nb_variables  Number of FOR and LET clauses
   */
  void init(PlanState& state, size_t numVars);
          
  /**
   * Init the state for a certain nb of variables and ordering
   * @nb_variables  Number of FOR and LET clauses
   * @orderSpecs    The OrderSpec which defines how to compare during ordering
   */
  void init(
        PlanState& state,
        size_t numVars,
        std::vector<FLWORIterator::OrderSpec>* orderSpecs);

  /**
   * Resets the state
   */
  void reset(PlanState&);
          
  ~FlworState();
  FlworState();
};  


} /* namespace zorba */
#endif  /* ZORBA_ITEM_ITERATOR_H */
