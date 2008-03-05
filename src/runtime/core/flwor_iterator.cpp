/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *  Author: Tim Kraska
 *
 */
#include <zorba/item.h>

#include "compiler/expression/expr.h"
#include "runtime/core/flwor_iterator.h"
#include "types/root_typemanager.h"
#include "runtime/core/var_iterators.h"
#include "system/zorba.h"
#include "errors/error_factory.h"
#include "store/api/temp_seq.h"
#include "runtime/booleans/BooleanImpl.h"
#include "runtime/visitors/planitervisitor.h"
#include "runtime/base/plan_iterator_wrapper.h"
#include "util/Assert.h"
#include "system/globalenv.h"
#include "store/api/store.h"
#include "store/api/item_factory.h"

namespace zorba
{

  // Utility function -- is this item null or a NaN?
static bool empty_item (store::Item_t s)
{
  return (s == 0) ||
         (GENV_TYPESYSTEM.is_numeric(*GENV_TYPESYSTEM.create_type(s->getType(), TypeConstants::QUANT_ONE)) &&
          s->isNaN());
  }


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  ForLetClause                                                               //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


FLWORIterator::ForLetClause::ForLetClause(
    const var_expr* var,
    std::vector<var_iter_t> aForVars,
    PlanIter_t& aInput)
  :
#ifndef NDEBUG
  theVarName(var->get_varname()->getStringValue().c_str()),
#endif
  type ( FOR ),
  forVars ( aForVars ),
  input ( aInput )
{
}


FLWORIterator::ForLetClause::ForLetClause (
    const var_expr* var,
    std::vector<var_iter_t> aForVars,
    std::vector<var_iter_t> aPosVars,
    PlanIter_t& aInput )
  :
#ifndef NDEBUG
  theVarName(var->get_varname()->getStringValue().c_str()),
#endif
  type ( FOR ),
  forVars ( aForVars ),
  posVars ( aPosVars ),
  input ( aInput )
{
}


FLWORIterator::ForLetClause::ForLetClause (
    const var_expr* var,
    std::vector<ref_iter_t> aLetVars,
    PlanIter_t& aInput,
    bool aNeedsMaterialization )
  :
#ifndef NDEBUG
  theVarName(var->get_varname()->getStringValue().c_str()),
#endif
  type(LET),
  letVars(aLetVars),
  input(aInput),
  needsMaterialization(aNeedsMaterialization)
{
}


void FLWORIterator::ForLetClause::accept ( PlanIterVisitor& v ) const
{
  // TODO correct for visitor
  switch ( type )
  {
  case FOR:
    v.beginVisitFlworForVariable(*input, getVarName());
    v.endVisitFlworForVariable(*input);
    break;
  case LET:
    v.beginVisitFlworLetVariable(*input, needsMaterialization, getVarName());
    v.endVisitFlworLetVariable(*input);
    break;
  default:
    ZORBA_ASSERT ( false );
  }
}


xqpStringStore FLWORIterator::ForLetClause::getVarName() const
{
#ifndef NDEBUG
  return theVarName;
#else
  return std::string("");
#endif
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  OrderSpec                                                                  //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

FLWORIterator::OrderSpec::OrderSpec (
    PlanIter_t aOrderByIter,
    bool aEmpty_least,
    bool aDescending )
  :
  orderByIter ( aOrderByIter ),
  empty_least ( aEmpty_least ),
  descending ( aDescending )
{
}


void FLWORIterator::OrderSpec::accept ( PlanIterVisitor& v ) const
{
  v.beginVisitFlworOrderBy(*orderByIter);
  v.endVisitFlworOrderBy(*orderByIter);
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  OrderByClause                                                              //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


FLWORIterator::OrderByClause::OrderByClause (
    std::vector<FLWORIterator::OrderSpec> aOrderSpecs,
    bool aStable )
  :
  orderSpecs ( aOrderSpecs ),
  stable ( aStable )
{
}
  

void FLWORIterator::OrderByClause::accept ( PlanIterVisitor& v ) const
{
  // TODO
  std::vector<OrderSpec>::const_iterator iter;
  for ( iter = orderSpecs.begin() ; iter != orderSpecs.end(); iter++ )
  {
    iter->accept ( v );
  }
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  OrderKeyCmp                                                                //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


int8_t FLWORIterator::OrderKeyCmp::compare(
    const store::Item_t& s1,
    const store::Item_t& s2,
    bool desc,
    bool emptyLeast ) const
{
  if ( empty_item (s1) )
  {
    if ( empty_item (s2) )
      return descAsc ( 0, desc );
    else
      return descAsc (emptyLeast ? -1 : 1, desc);
  }
  else if ( empty_item (s2) )
  {
    return descAsc (emptyLeast ? 1 : -1, desc);
  }
  else
  {
    // danm: both valueCompare (x, NaN) and valueCompare (NaN, x) return 2.
    // That's why empty_item is needed.
    int8_t result = CompareIterator::valueCompare ( s1 , s2 );
    if (result > 1 || result < -1) {
      ZORBA_ERROR_ALERT(ZorbaError::XPTY0004,
                        NULL, DONT_CONTINUE_EXECUTION, "Non-comparable types found while sorting" );
      
    }
    return descAsc (result , desc );
  }
}


int8_t FLWORIterator::OrderKeyCmp::descAsc ( int8_t result, bool desc ) const
{
  ZORBA_ASSERT (result <= 1 && result >= -1);
  return desc ? -result : result;
}


bool FLWORIterator::OrderKeyCmp::operator() (
    const std::vector<store::Item_t>& s1,
    const std::vector<store::Item_t>& s2 ) const
{
  ZORBA_ASSERT ( s1.size() == s2.size() );
  ZORBA_ASSERT ( s1.size() == mOrderSpecs->size() );

  std::vector<store::Item_t>::const_iterator s1iter = s1.begin();
  std::vector<store::Item_t>::const_iterator s2iter = s2.begin();
  std::vector<OrderSpec>::const_iterator orderSpecIter = mOrderSpecs->begin();

  while ( s1iter != s1.end() )
  {
    int8_t cmp = compare(*s1iter,
                         *s2iter,
                         orderSpecIter->descending,
                         orderSpecIter->empty_least);
    if ( cmp == 1 )
    {
      return false;
    }
    else if ( cmp == -1 )
    {
      return true;
    }
    ++s1iter;
    ++s2iter;
    ++orderSpecIter;
  }
  return false;
}



/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  FLWORIterator                                                              //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

FLWORIterator::FLWORIterator(
    const QueryLoc& loc,
    std::vector<FLWORIterator::ForLetClause> &aForLetClauses,
    PlanIter_t& aWhereClause,
    FLWORIterator::OrderByClause* aOrderByClause,
    PlanIter_t& aReturnClause,
    bool aWhereClauseReturnsBooleanPlus)
  :
  Batcher<FLWORIterator>(loc),
  forLetClauses(aForLetClauses),
  whereClause(aWhereClause),
  orderByClause(aOrderByClause),
  returnClause(aReturnClause),
  whereClauseReturnsBooleanPlus(aWhereClauseReturnsBooleanPlus),
  bindingsNb(aForLetClauses.size())
{
  if ( orderByClause == 0 || orderByClause->orderSpecs.size() == 0 )
  {
    orderByClause = 0;
    doOrderBy = false;
  }
  else
  {
    doOrderBy = true;
  }
}


FLWORIterator::~FLWORIterator()
{
  if ( doOrderBy )
  {
    delete orderByClause;
  }
}



store::Item_t FLWORIterator::nextImpl ( PlanState& planState ) const
{
  //Needed variables
  int curVar = 0;
  store::Item_t curItem;

  FlworState* flworState;
  DEFAULT_STACK_INIT(FlworState, flworState, planState);

  assert(flworState->varBindingState.size() > 0);

  while ( true )
  {
    //Here we do the variable bindings from the outer most to the inner most
    while ( curVar != bindingsNb )
    {
      // Try to bind the current variable. If the binding of the variable is
      // successfull, we procede with the next binding level. Else, we go a
      // level back and try the previous level
      if ( bindVariable ( curVar, flworState, planState ) )
      {
        ++curVar;
      }
      else
      {
        flworState->varBindingState[curVar] = 0;
        resetInput ( curVar, flworState, planState );
        --curVar;

        //If we finished the last binding (curVar == -1) and we had to Orde
        //r we need to return the results, otherwise we just need to indicate
        // that we finished by returning NULL
        if ( curVar == -1 )
        {
          if ( doOrderBy )
          {
            flworState->curOrderPos = flworState->orderMap->begin();

            while ( flworState->curOrderPos != flworState->orderMap->end() )
            {
              flworState->curOrderResultSeq = flworState->curOrderPos->second;

              while ( ( curItem = flworState->curOrderResultSeq->next() ) != 0 )
              {
                STACK_PUSH ( curItem, flworState );
              }
              ++ ( flworState->curOrderPos );
            }
          }

          STACK_PUSH ( NULL, flworState );
          goto stop;
        }
      }
    }

    //After binding all variables, we check first the where clause
    //curVar = bindingsNb - 1 indicates that we have to do the next binding level
    if ( evalWhereClause ( planState ) )
    {
      //In the case we not need to do ordering, we now returning the items produced
      //by the ReturnClause
      if ( !doOrderBy )
      {
        while ( ( curItem = consumeNext ( returnClause.getp(), planState )) != 0  )
        {
          STACK_PUSH ( curItem, flworState );
        }
        returnClause->reset(planState);
        //In the case we have to order we are materializing the result
      }
      else
      {
        matResultAndOrder ( flworState, planState );
      }
    }
    curVar = bindingsNb - 1;
  }

 stop:
  STACK_PUSH ( NULL, flworState );
  STACK_END();
}


void FLWORIterator::matResultAndOrder(
    FlworState* flworState,
    PlanState& planState) const
{
  ZORBA_ASSERT ( doOrderBy );

  std::vector<OrderSpec>& lOrderSpecs = orderByClause->orderSpecs;
  //FIXME hould be a const iterator after the change of Plan_Iter
  std::vector<OrderSpec>::iterator lSpecIter = lOrderSpecs.begin();
  std::vector<store::Item_t> orderKey;

  while ( lSpecIter != lOrderSpecs.end() )
  {
    store::Item_t lItem = consumeNext ( lSpecIter->orderByIter.getp(), planState );
    orderKey.push_back ( lItem );
    //Test for singleton
    if ( lItem != 0 )
    {
      lItem = consumeNext ( lSpecIter->orderByIter.getp(), planState );
      if ( lItem != 0 )
      {
        ZORBA_ERROR_ALERT(ZorbaError::XPTY0004,
                          NULL, DONT_CONTINUE_EXECUTION, "Expected a singleton" );
      }
    }
    lSpecIter->orderByIter->reset(planState);
    ++lSpecIter;
  }

  Iterator_t iterWrapper = new PlanIteratorWrapper(returnClause, planState);
  store::TempSeq_t result = Zorba::getStore()->createTempSeq(iterWrapper, false);
  Iterator_t iter = result->getIterator();
  iter->open();
  flworState->orderMap->insert(std::pair<std::vector<store::Item_t>, Iterator_t>(orderKey, iter));
  returnClause->reset(planState);

}


bool FLWORIterator::evalWhereClause ( PlanState& planState ) const
{
  if ( whereClause == NULL )
    return true;

  if ( whereClauseReturnsBooleanPlus )
  {
    store::Item_t boolValue = consumeNext ( whereClause.getp(), planState );
    if ( boolValue == NULL )
      return false;

    bool value = boolValue->getBooleanValue();
    whereClause->reset(planState);
    return value;
  }

  store::Item_t item = FnBooleanIterator::effectiveBooleanValue(loc,
                                                         planState,
                                                         whereClause);
  whereClause->reset(planState);
  return item->getBooleanValue();
}


void FLWORIterator::resetInput(
    const int& varNb,
    FlworState* flworState,
    PlanState& planState) const
{
  FLWORIterator::ForLetClause lForLetClause = forLetClauses[varNb];
  lForLetClause.input->reset( planState );
  flworState->varBindingState[varNb] = 0;
}


bool FLWORIterator::bindVariable (
    int varNb,
    FlworState* flworState,
    PlanState& planState ) const
{
  const FLWORIterator::ForLetClause& lForLetClause = forLetClauses[varNb];

  switch (lForLetClause.type)
  {
  //In the case of a FOR we try to get the next item of the input and bind
  // it to all the variable references
  case ForLetClause::FOR :
  {
    store::Item_t lItem = consumeNext ( lForLetClause.input.getp(), planState );
    if ( lItem == NULL )
    {
      return false;
    }

    //We increase the position counter
    ++ ( flworState->varBindingState[varNb] );

    std::vector<var_iter_t>::const_iterator forIter;
    for (forIter = lForLetClause.forVars.begin();
         forIter != lForLetClause.forVars.end();
         forIter++)
    {
      var_iter_t variable = (*forIter);
      variable->bind(lItem, planState);
    }

    if ( !lForLetClause.posVars.empty() )
    {
      store::Item_t posItem = Zorba::getItemFactory()->
                       createInteger(Integer::parseInt(flworState->varBindingState[varNb]));

      std::vector<var_iter_t>::const_iterator posIter;
      for (posIter = lForLetClause.posVars.begin();
           posIter != lForLetClause.posVars.end();
           posIter++)
      {
        var_iter_t variable = (*posIter);
        variable->bind(posItem, planState);
      }
    }
    //TODO Pos Bindings
    return true;
  }
  case ForLetClause::LET :
  {      
    //return false if the Var-Variable was already bound
    if ( flworState->varBindingState[varNb] == 1 )
    {
      return false;
    }

    Iterator_t iterWrapper = new PlanIteratorWrapper(lForLetClause.input, planState);
    //Depending on the query, we might need to materialize the LET-Binding
    if ( lForLetClause.needsMaterialization )
    {
      store::TempSeq_t tmpSeq = Zorba::getStore()->createTempSeq(iterWrapper, true);
      std::vector<ref_iter_t>::const_iterator letIter;
      for (letIter = lForLetClause.letVars.begin();
           letIter != lForLetClause.letVars.end();
           letIter++ )
      {
        Iterator_t iter = tmpSeq->getIterator();
        iter->open();
        (*letIter)->bind(iter, planState);
      }
    }
    else
    {
      std::vector<ref_iter_t>::const_iterator letIter;
      for (letIter = lForLetClause.letVars.begin();
           letIter != lForLetClause.letVars.end();
           letIter++)
      {
        (*letIter)->bind(iterWrapper, planState);
      }
    }
    ++ ( flworState->varBindingState[varNb] );
    return true;
  }
  default:
    //That should never happen
    ZORBA_ASSERT ( false );
  }

  return false;
}

void FLWORIterator::openImpl(PlanState& planState, uint32_t& offset)
{
  StateTraitsImpl<FlworState>::createState(planState, this->stateOffset, offset);
  FlworState* flworState = StateTraitsImpl<FlworState>::getState(planState, this->stateOffset);

  //we allocate resources
  if ( doOrderBy )
  {
    flworState->init(planState, bindingsNb, &orderByClause->orderSpecs);
  }
  else
  {
    flworState->init ( planState, bindingsNb );
  }

#ifndef NDEBUG
  assert(flworState->varBindingState.size() > 0); // some variables must have been bound
#endif

  std::vector<FLWORIterator::ForLetClause>::const_iterator iter;
  for (iter = forLetClauses.begin(); iter != forLetClauses.end(); iter++)
  {
    iter->input->open ( planState, offset );
  }

  returnClause->open ( planState, offset );

  if ( whereClause != NULL )
    whereClause->open ( planState, offset );

  if ( doOrderBy )
  {
    std::vector<OrderSpec>::const_iterator iter;
    for (iter = orderByClause->orderSpecs.begin();
         iter != orderByClause->orderSpecs.end();
         iter++ )
    {
      iter->orderByIter->open ( planState, offset );
    }
  }
  
}

void FLWORIterator::resetImpl ( PlanState& planState ) const
{
  returnClause->reset(planState);

  if (whereClause != NULL)
    whereClause->reset(planState);

  if (orderByClause != NULL)
  {
    std::vector<FLWORIterator::OrderSpec>::iterator iter;
    for (iter = orderByClause->orderSpecs.begin();
         iter != orderByClause->orderSpecs.end();
         iter++)
    {
      iter->orderByIter->reset(planState);
    }
  }

  std::vector<FLWORIterator::ForLetClause>::const_iterator iter;
  for (iter = forLetClauses.begin(); iter != forLetClauses.end(); iter++)
  {
    iter->input->reset(planState);
  }

  StateTraitsImpl<FlworState>::reset(planState, this->stateOffset);
}


void FLWORIterator::closeImpl ( PlanState& planState )
{
  returnClause->close(planState);

  if (whereClause != NULL)
    whereClause->close(planState);

  if (orderByClause != NULL)
  {
    std::vector<FLWORIterator::OrderSpec>::iterator iter;
    for (iter = orderByClause->orderSpecs.begin();
         iter != orderByClause->orderSpecs.end();
         iter++)
    {
      iter->orderByIter->close(planState);
    }
  }

  std::vector<FLWORIterator::ForLetClause>::iterator iter;
  for (iter = forLetClauses.begin(); iter != forLetClauses.end(); iter++)
  {
    iter->input->close(planState);
  }
  
  StateTraitsImpl<FlworState>::destroyState(planState, this->stateOffset);
}


uint32_t FLWORIterator::getStateSize() const  { return sizeof ( FlworState); }

uint32_t FLWORIterator::getStateSizeOfSubtree() const
{
  int32_t size = this->getStateSize();
  std::vector<FLWORIterator::ForLetClause>::const_iterator iter;
  for ( iter = forLetClauses.begin() ; iter != forLetClauses.end(); iter++ )
  {
    size += iter->input->getStateSizeOfSubtree();
  }

  size += returnClause->getStateSizeOfSubtree();

  if ( whereClause != NULL )
    size += whereClause->getStateSizeOfSubtree();

  if ( doOrderBy )
  {
    std::vector<OrderSpec>::const_iterator iter;
    for (iter = orderByClause->orderSpecs.begin();
         iter != orderByClause->orderSpecs.end();
         iter++ )
    {
      size += iter->orderByIter->getStateSizeOfSubtree();
    }
  }

  return size;
}




void FLWORIterator::accept ( PlanIterVisitor& v ) const
{
  // TODO
  v.beginVisit ( *this );
  std::vector<FLWORIterator::ForLetClause>::const_iterator iter;
  for ( iter = forLetClauses.begin() ; iter != forLetClauses.end(); iter++ )
  {
    iter->accept ( v );
  }
  if ( whereClause != NULL )
  {
    v.beginVisitFlworWhereClause(*whereClause);
    v.endVisitFlworWhereClause(*whereClause);
  }
  if ( doOrderBy )
  {
    orderByClause->accept ( v );
  }
  v.beginVisitFlworReturn(*returnClause);
  v.endVisitFlworReturn(*returnClause);

  v.endVisit(*this);
}

/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  FlworState                                                                 //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

void FlworState::init(PlanState& planState, size_t nb_variables)
{
  PlanIteratorState::init(planState);
  std::vector<uint32_t> v( nb_variables, 0 );
  varBindingState.swap (v);
  assert(varBindingState.size() > 0);
}


void FlworState::init(
                      PlanState& planState,
                      size_t nb_variables,
                      std::vector<FLWORIterator::OrderSpec>* orderSpecs)
{
  init (planState, nb_variables);
  orderMap = new FLWORIterator::order_map_t(orderSpecs);
}


void FlworState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  assert(varBindingState.size() > 0);
  size_t size = varBindingState.size();
  varBindingState.clear();
  varBindingState.insert(varBindingState.begin(), size, 0);
  curOrderResultSeq = 0;
  if ( orderMap != 0 )
  {
    orderMap->clear();
  }
}

FlworState::FlworState()
  : orderMap(0)
{}


FlworState::~FlworState()
{
  if ( orderMap )
  {
    orderMap->clear(); // TODO is this needed
    delete orderMap; orderMap = 0;
  }
}

}
