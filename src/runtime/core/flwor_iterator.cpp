/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *  Author: Tim Kraska
 *
 */
#include "compiler/expression/expr.h"
#include "runtime/core/flwor_iterator.h"
#include "runtime/core/var_iterators.h"
#include "system/zorba.h"
#include "errors/error_factory.h"
#include "store/api/item.h"
#include "store/api/temp_seq.h"
#include "runtime/booleans/BooleanImpl.h"
#include "runtime/visitors/planitervisitor.h"
#include "util/Assert.h"
#include "system/globalenv.h"

namespace xqp
{

  // Utility function -- is this item null or a NaN?
static bool empty_item (Item_t s)
{
  return (s == 0) ||
         (GENV_TYPESYSTEM.is_numeric(*GENV_TYPESYSTEM.create_type(s->getType(), TypeSystem::QUANT_ONE)) &&
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
  theVarName(var->get_varname()->getStringProperty().c_str()),
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
  theVarName(var->get_varname()->getStringProperty().c_str()),
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
  theVarName(var->get_varname()->getStringProperty().c_str()),
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
    assert ( false );
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
    const Item_t& s1,
    const Item_t& s2,
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
      ZORBA_ERROR_ALERT(AlertCodes::XPTY0004,
                        NULL, false, "Non-comparable types found while sorting" );
      
    }
    return descAsc (result , desc );
  }
}


int8_t FLWORIterator::OrderKeyCmp::descAsc ( int8_t result, bool desc ) const
{
  assert (result <= 1 && result >= -1);
  return desc ? -result : result;
}


bool FLWORIterator::OrderKeyCmp::operator() (
    const std::vector<Item_t>& s1,
    const std::vector<Item_t>& s2 ) const
{
  assert ( s1.size() == s2.size() );
  assert ( s1.size() == mOrderSpecs->size() );

  std::vector<Item_t>::const_iterator s1iter = s1.begin();
  std::vector<Item_t>::const_iterator s2iter = s2.begin();
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
//  FlworState                                                                 //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

void FLWORIterator::FlworState::init(size_t nb_variables)
{
  PlanIterator::PlanIteratorState::init();
  std::vector<uint32_t> v( nb_variables, 0 );
  varBindingState.swap (v);
}


void FLWORIterator::FlworState::init(
    size_t nb_variables,
    vector<OrderSpec>* orderSpecs)
{
  init (nb_variables);
  orderMap = new order_map_t(orderSpecs);
}


void FLWORIterator::FlworState::reset()
{
  PlanIteratorState::reset();
  size_t size = varBindingState.size();
  varBindingState.clear();
  varBindingState.insert(varBindingState.begin(), size, 0);
  curOrderResultSeq = 0;
  if ( orderMap != 0 )
  {
    orderMap->clear();
  }
}


void FLWORIterator::FlworState::releaseResources()
{
  reset();
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  FLWORIterator                                                              //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

FLWORIterator::FLWORIterator(
    const yy::location& loc,
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



Item_t FLWORIterator::nextImpl ( PlanState& planState )
{
  //Needed variables
  int curVar = 0;
  FlworState* flworState;
  Item_t curItem;

  GET_STATE(FlworState, flworState, planState);
  MANUAL_STACK_INIT(flworState);

  //we allocate resources
  if ( doOrderBy )
  {
    flworState->init(bindingsNb, &orderByClause->orderSpecs);
  }
  else
  {
    flworState->init ( bindingsNb );
  }
  FINISHED_ALLOCATING_RESOURCES();

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
        curVar++;
      }
      else
      {
        flworState->varBindingState[curVar] = 0;
        resetInput ( curVar, flworState, planState );
        curVar--;

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
              curItem = flworState->curOrderResultSeq->next();

              while ( curItem != 0 )
              {
                STACK_PUSH ( curItem, flworState );
                curItem = flworState->curOrderResultSeq->next();
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
        while ( true )
        {
          curItem = this->consumeNext ( returnClause, planState );
          if ( curItem == NULL )
          {
            curVar = bindingsNb - 1;
            this->resetChild ( returnClause, planState );
            break;
          }
          else
          {
            STACK_PUSH ( curItem, flworState );
          }
        }
        //In the case we have to order we are materializing the result
      }
      else
      {
        matResultAndOrder ( flworState, planState );
        curVar = bindingsNb - 1;
      }
    }
    else
    {
      curVar = bindingsNb - 1;
    }
  }

 stop:
  STACK_PUSH ( NULL, flworState );
  STACK_END();
}


void FLWORIterator::matResultAndOrder(
    FlworState* flworState,
    PlanState& planState)
{
  assert ( doOrderBy );

  vector<OrderSpec> lOrderSpecs = orderByClause->orderSpecs;
  //FIXME hould be a const iterator after the change of Plan_Iter
  std::vector<OrderSpec>::iterator lSpecIter = lOrderSpecs.begin();
  std::vector<Item_t> orderKey;

  while ( lSpecIter != lOrderSpecs.end() )
  {
    Item_t lItem = consumeNext ( lSpecIter->orderByIter, planState );
    orderKey.push_back ( lItem );
    //Test for singleton
    if ( lItem != 0 )
    {
      lItem = consumeNext ( lSpecIter->orderByIter, planState );
      if ( lItem != 0 )
      {
        ZORBA_ERROR_ALERT(AlertCodes::XPTY0004,
                          NULL, false, "Expected a singleton" );
      }
    }
    resetChild ( lSpecIter->orderByIter, planState );
    ++lSpecIter;
  }

  Iterator_t iterWrapper = new PlanIteratorWrapper(returnClause, planState);
  TempSeq_t result = Zorba::getStore()->createTempSeq(iterWrapper, false);
  flworState->orderMap->insert(std::pair<std::vector<Item_t>, Iterator_t>(orderKey, result->getIterator()));
  this->resetChild(returnClause, planState);
}


bool FLWORIterator::evalWhereClause ( PlanState& planState )
{
  if ( whereClause == NULL )
    return true;

  if ( whereClauseReturnsBooleanPlus )
  {
    Item_t boolValue = this->consumeNext ( whereClause, planState );
    if ( boolValue == NULL )
      return false;

    bool value = boolValue->getBooleanValue();
    resetChild(whereClause, planState);
    return value;
  }

  Item_t item = FnBooleanIterator::effectiveBooleanValue(loc,
                                                         planState,
                                                         whereClause);
  resetChild(whereClause, planState);
  return item->getBooleanValue();
}


void FLWORIterator::resetInput(
    const int& varNb,
    FlworState* flworState,
    PlanState& planState)
{
  FLWORIterator::ForLetClause lForLetClause = forLetClauses[varNb];
  this->resetChild(lForLetClause.input, planState);
  flworState->varBindingState[varNb] = 0;
}


bool FLWORIterator::bindVariable(
    int varNb,
    FlworState* flworState,
    PlanState& planState )
{
  FLWORIterator::ForLetClause lForLetClause = forLetClauses[varNb];

  switch (lForLetClause.type)
  {
  //In the case of a FOR we try to get the next item of the input and bind
  // it to all the variable references
  case ForLetClause::FOR :
  {
    Item_t lItem = this->consumeNext ( lForLetClause.input, planState );
    if ( lItem == NULL )
    {
      return false;
    }

    //We increase the position counter
    ++ ( flworState->varBindingState[varNb] );

    std::vector<var_iter_t>::iterator forIter;
    for (forIter = lForLetClause.forVars.begin();
         forIter != lForLetClause.forVars.end();
         forIter++)
    {
      var_iter_t variable = (*forIter);
      variable->bind(lItem, planState);
    }

    if ( !lForLetClause.posVars.empty() )
    {
      Item_t posItem = Zorba::getItemFactory()->
                       createInteger(flworState->varBindingState[varNb]);

      std::vector<var_iter_t>::iterator posIter;
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
      TempSeq_t tmpSeq = Zorba::getStore()->createTempSeq(iterWrapper, true);
      std::vector<ref_iter_t>::iterator letIter;
      for (letIter = lForLetClause.letVars.begin();
           letIter != lForLetClause.letVars.end();
           letIter++ )
      {
        (*letIter)->bind(tmpSeq->getIterator(), planState);
      }
    }
    else
    {
      std::vector<ref_iter_t>::iterator letIter;
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
    assert ( false );
  }

  return false;
}


void FLWORIterator::resetImpl ( PlanState& planState )
{
  resetChild(returnClause, planState);

  if (whereClause != NULL)
    resetChild(whereClause, planState);

  FlworState* flworState;
  GET_STATE ( FlworState, flworState, planState );
  flworState->reset();
}


void FLWORIterator::releaseResourcesImpl ( PlanState& planState )
{
  returnClause->releaseResources(planState);

  if (whereClause != NULL)
    whereClause->releaseResources(planState);

  std::vector<FLWORIterator::ForLetClause>::iterator iter;
  for (iter = forLetClauses.begin(); iter != forLetClauses.end(); iter++)
  {
    iter->input->releaseResources(planState);
  }

  FlworState* flworState;
  GET_STATE ( FlworState, flworState, planState );
  flworState->releaseResources();
}


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


void FLWORIterator::setOffset(PlanState& planState, uint32_t& offset)
{
  this->stateOffset = offset;
  offset += this->getStateSize();

  std::vector<FLWORIterator::ForLetClause>::const_iterator iter;
  for (iter = forLetClauses.begin(); iter != forLetClauses.end(); iter++)
  {
    iter->input->setOffset ( planState, offset );
  }

  returnClause->setOffset ( planState, offset );

  if ( whereClause != NULL )
    whereClause->setOffset ( planState, offset );

  if ( doOrderBy )
  {
    std::vector<OrderSpec>::const_iterator iter;
    for (iter = orderByClause->orderSpecs.begin();
         iter != orderByClause->orderSpecs.end();
         iter++ )
    {
      iter->orderByIter->setOffset ( planState, offset );
    }
  }
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


}
