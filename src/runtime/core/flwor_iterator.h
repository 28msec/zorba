/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *  Author: Tim Kraska
 *
 */


#ifndef XQP_FLWOR_ITERATOR_H
#define XQP_FLWOR_ITERATOR_H

#include "context/common.h"
#include "util/rchandle.h"
#include "util/tracer.h"
#include "compiler/parser/location.hh"
#include "runtime/base/iterator.h"
#include "runtime/base/unarybase.h"

#include <assert.h>
#include <iostream>
#include <vector>

namespace xqp
{

  class var_iterator;
  typedef rchandle<var_iterator> var_iter_t;

  class RefIterator;
  typedef rchandle<RefIterator> ref_iter_t;

  class FLWORIterator : public Batcher<FLWORIterator>
  {

    public:
      class ForLetClause  //Combines FOR and LET to avoid dynamic casts
      {
          friend class FLWORIterator;

        protected:
          enum ForLetType {FOR, LET};
          ForLetType type;
          std::vector<var_iter_t> forVars;
          std::vector<var_iter_t> posVars;
          std::vector<ref_iter_t> letVars;
          PlanIter_t input;
          bool needsMaterialization;

        public:
          /**
          * Creates a new ForClause
          *
          */
          ForLetClause ( std::vector<var_iter_t> forVars, PlanIter_t& input );
          ForLetClause ( std::vector<var_iter_t> forVars, std::vector<var_iter_t> posVars, PlanIter_t& input );

        public:

          std::ostream& show ( std::ostream& os ) const;

          /**
           * Creates a new LetClause
           * needsMaterialization indicates if it is necassary to materialize the LET-Binding:
           * E.g. "let $x := (1,2,3) return ($x, $x)" needs materialization.
           * but "let $x := (1,2,3) return if(test()) then $x else $x" doesn't
          */
          ForLetClause ( std::vector<ref_iter_t> letVars, PlanIter_t& input,bool needsMaterialization );
      };

      /**
       * See http://www.w3.org/TR/xquery/#id-orderby-return
       * Collation are skipped so far! We do that later...
       */
      class OrderSpec
      {
        friend class FLWORIterator;
        friend class OrderKeyCmp;
        protected:
          PlanIter_t orderByIter;
          bool empty_least;
          bool descending;
        public:
          OrderSpec ( PlanIter_t orderByIter, bool empty_least, bool descending );
      };

      /**
       * See http://www.w3.org/TR/xquery/#id-orderby-return
       */
      class OrderByClause
      {
        friend class FLWORIterator;
        protected:
          vector<OrderSpec> orderSpecs;
          bool stable;
        public:
          OrderByClause ( std::vector<OrderSpec> orderSpecs, bool stable );
      };


      /** The key comparison function, a Strict Weak Ordering whose argument type is key_type;
      it returns true if its first argument is less than its second argument, and false otherwise.
      This is also defined as multimap::key_compare.*/
      class OrderKeyCmp
      {
        public:
          OrderKeyCmp() : mOrderSpecs ( 0 ) {}
          OrderKeyCmp ( vector<OrderSpec>* aOrderSpecs ) : mOrderSpecs ( aOrderSpecs ) {}

          
          bool operator() ( const std::vector<Item_t>& s1, const std::vector<Item_t>& s2 ) const;
          
          /**
            @return   -1, if item0 &lt; item1
                      0, if item0 == item1
                      1, if item0 &gt; item1
          */
          inline int8_t compare(const Item_t& s1, const Item_t& s2, bool asc, bool emptyLeast) const;
          
          inline int8_t descAsc(int8_t result, bool asc) const;
          
          private:
          vector<OrderSpec>* mOrderSpecs;         
         
      };

    private:
      std::vector<FLWORIterator::ForLetClause> forLetClauses; //
      PlanIter_t whereClause; //can be null
      FLWORIterator::OrderByClause* orderByClause;  //can be null
      PlanIter_t returnClause;
      bool whereClauseReturnsBooleanPlus;
      const int bindingsNb;
      //State
      int* varBindingState;
      Store* store;

      std::multimap<std::vector<Item_t>, TempSeq_t, OrderKeyCmp>* orderMap;

    protected:
    class ElementContentState : public PlanIteratorState
      {
        public:
          xqp_string theString;
          Item_t     theContextItem;

          void init();
      };

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
      FLWORIterator ( const yy::location& loc,
                      std::vector<FLWORIterator::ForLetClause> &forLetClauses,
                      PlanIter_t& whereClause,
                      FLWORIterator::OrderByClause* orderByClause,
                      PlanIter_t& returnClause,
                      bool whereClauseReturnsBooleanPlus = false );

      ~FLWORIterator();

      Item_t nextImpl ( PlanState& planState );
      void resetImpl ( PlanState& planState );
      void releaseResourcesImpl ( PlanState& planState );
      virtual int32_t getStateSize();
      virtual int32_t getStateSizeOfSubtree();
      virtual void setOffset ( PlanState& planState, int32_t& offset );
      std::ostream& _show ( std::ostream& os ) const;

    private:
      void resetInput ( int varNb, PlanState& planState );
      bool bindVariable ( int varNb, PlanState& planState );
      bool evalWhereClause( PlanState& planState );
      void matResultAndOrder (PlanState& planState);
      
  };

} /* namespace xqp */
#endif  /* XQP_ITEM_ITERATOR_H */
