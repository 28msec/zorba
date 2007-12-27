/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *  Authors: Tim Kraska, David Graf
 */


#include "runtime/fncontext/FnContextImpl.h"
#include "api/external/xquery.h"
#include "context/dynamic_context.h"
#include "runtime/core/item_iterator.h"

namespace xqp
{

  /* start class CtxVariableIterator */
  CtxVariableIterator::CtxVariableIterator ( const yy::location& loc, PlanIter_t& aIter )
      :
      UnaryBaseIterator<CtxVariableIterator> ( loc, aIter ) {}

  CtxVariableIterator::CtxVariableIterator ( const yy::location& loc, PlanIter_t& aIter, xqp_string aVarname )
    : 
    UnaryBaseIterator<CtxVariableIterator> ( loc, aIter ), theVarname (aVarname)
  {}

  CtxVariableIterator::~CtxVariableIterator() {}

  Item_t CtxVariableIterator::nextImpl ( PlanState& planState )
  {
    Item_t item;
    Iterator_t iter;
    PlanIterator::PlanIteratorState* aState;
    GET_STATE ( PlanIteratorState, aState, planState );
    MANUAL_STACK_INIT ( aState );
//     if(varName == NULL){
//        item = consumeNext(theChild, planState);
//        varName = item->getStringValue();
//     }
    FINISHED_ALLOCATING_RESOURCES();

     // TODO get varname from child iterator
    iter = ZORBA_FOR_CURRENT_THREAD()->current_xqueryresult->internal_dyn_context->get_variable(theVarname);
    if (iter == NULL)
       ZORBA_ERROR_ALERT (AlertCodes::XPDY0002, &loc);

    do{
      item = iter->next();
      STACK_PUSH (item , aState);
    }while(item != NULL);
    while(true){
      STACK_PUSH (NULL , aState);
    }
    STACK_END();
  }

  /* end class CtxVariableIterator */

}
