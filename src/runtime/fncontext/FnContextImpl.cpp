/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *  Authors: Tim Kraska, David Graf
 */


#include "runtime/fncontext/FnContextImpl.h"
#include "api/external/xquerybinary.h"
#include "context/dynamic_context.h"

namespace xqp
{
  /* start class CtxVariableIterator */
  CtxVariableIterator::CtxVariableIterator ( const yy::location& loc, PlanIter_t& aIter )
      :
      UnaryBaseIterator<CtxVariableIterator> ( loc, aIter ) {}

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
    iter = zorba::getZorbaForCurrentThread()->current_xqueryresult->internal_dyn_context->get_variable("test"); //TODO place varname instead of "test"
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
