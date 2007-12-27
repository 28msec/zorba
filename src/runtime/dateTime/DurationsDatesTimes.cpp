/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *  Authors: Nicolae Brinza
 */

#include "runtime/dateTime/DurationsDatesTimes.h"
#include "runtime/base/iterator.h"

namespace xqp
{

Item_t 
OpDurationEqualIterator::nextImpl(PlanState& planState)
{
  Item_t item0;
  Item_t item1;

  PlanIterator::PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIterator::PlanIteratorState, state, planState);

  // TODO: arguments should be of type xs:duration

  item0 = consumeNext(theChild0, planState);
  item1 = consumeNext(theChild1, planState);
  

  // theChild0 theChild1
  // if(theChildren.size() == 2 || theChildren.size()==3)
  {
    /*
    item0 = consumeNext ( theChildren[0], planState );
    if ( item0 != NULL )
    {
      item0 = item0->getAtomizationValue();
      if(item0->getStringValue().length() == 0)
      {
        STACK_PUSH( Zorba::getItemFactory()->createString(resStr), state );
      }
      else{
        item1 = consumeNext( theChildren[1], planState );
        if( item1 != NULL )
        {//note: The first character of a string is located at position 1, not position 0.
          item1 = item1->getAtomizationValue();
          if( theChildren.size() == 2 )
          {
            resStr = item0->getStringValue().substr((int32_t)round(item1->getDecimalValue())-1);
          }
          else{ //theChildren.size() ==3
            item2 = consumeNext ( theChildren[2], planState );
            if ( item2 != NULL )
            {
              item2 = item2->getAtomizationValue();
              resStr = item0->getStringValue().substr((int32_t)round(item1->getDecimalValue())-1,
                                             (int32_t)round(item2->getDecimalValue()));
            }
          }
          STACK_PUSH( Zorba::getItemFactory()->createString(resStr), state );
        }
      }
    }
    */
  }
  STACK_END();
}

}
