/**
 * @copyright
 * ========================================================================
 *  Copyright FLWOR Foundation
 * ========================================================================
 *
 * @author Sorin Nasoi (sorin.nasoi@ipdevel.ro)
 * @file runtime/context/ContextImpl.cpp
 *
 */
 
#include "system/globalenv.h"
#include "runtime/context/ContextImpl.h"
#include "store/api/item_factory.h"
#include "runtime/api/runtimecb.h"
#include "context/dynamic_context.h"
#include "context/static_context.h"
#include "zorbatypes/datetime.h"

namespace zorba
{
/**
 *______________________________________________________________________
 *
 * 16.3 fn:current-dateTime
 *
 * fn:current-dateTime() as xs:dateTime
 *_______________________________________________________________________*/

/*begin class FnCurrentDateTimeIterator */
store::Item_t
FnCurrentDateTimeIterator::nextImpl(PlanState& planState) const
{
  store::Item_t itemRes;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemRes = planState.theRuntimeCB->theDynamicContext->get_current_date_time();
  if( NULL != itemRes )
    STACK_PUSH( itemRes, state );

  STACK_END (state);
}
/*end class FnCurrentDateTimeIterator */

/**
 *______________________________________________________________________
 *
 * 16.4 fn:current-date
 *
 * fn:current-date() as xs:date
 *_______________________________________________________________________*/

/*begin class FnCurrentDateIterator */
store::Item_t
FnCurrentDateIterator::nextImpl(PlanState& planState) const
{
  store::Item_t itemRes;
  xqp_date d;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemRes = planState.theRuntimeCB->theDynamicContext->get_current_date_time();
  if( NULL != itemRes )
  {
    d = itemRes->getDateTimeValue()->getDate();
    STACK_PUSH( GENV_ITEMFACTORY->createDate(d), state );
  }

  STACK_END (state);
}
/*end class FnCurrentDateIterator */

/**
 *______________________________________________________________________
 *
 * 16.5 fn:current-time
 *
 * fn:current-time() as xs:time
 *_______________________________________________________________________*/

/*begin class FnCurrentTimeIterator */
store::Item_t
FnCurrentTimeIterator::nextImpl(PlanState& planState) const
{
  store::Item_t itemRes;
  xqp_time t;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemRes = planState.theRuntimeCB->theDynamicContext->get_current_date_time();
  if( NULL != itemRes )
  {
    t = itemRes->getDateTimeValue()->getTime();
    STACK_PUSH( GENV_ITEMFACTORY->createTime(t), state );
  }

  STACK_END (state);
}
/*end class FnCurrentTimeIterator */

/**
 *______________________________________________________________________
 *
 * 16.6 fn:implicit-timezone
 *
 * fn:implicit-timezone() as xs:dayTimeDuration
 *_______________________________________________________________________*/

/*begin class FnImplicitTimezoneIterator */
store::Item_t
FnImplicitTimezoneIterator::nextImpl(PlanState& planState) const
{
  long tz;
  xqp_dayTimeDuration dtd;
  DurationBase_t db;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  tz = planState.theRuntimeCB->theDynamicContext->get_implicit_timezone();
  db = new DayTimeDuration( tz < 0, 0, tz<0?-tz:tz, 0 , 0, 0);
  
  STACK_PUSH( GENV_ITEMFACTORY->createDuration(db), state );

  STACK_END (state);
}
/*end class FnImplicitTimezoneIterator */

/**
 *______________________________________________________________________
 *
 * 16.7 fn:default-collation
 *
 * fn:default-collation() as xs:string
 *_______________________________________________________________________*/

/*begin class FnDefaultCollationIterator */
store::Item_t
FnDefaultCollationIterator::nextImpl(PlanState& planState) const
{
  xqp_string strColUri;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  strColUri = planState.theRuntimeCB->theStaticContext->default_collation_uri();
  STACK_PUSH( GENV_ITEMFACTORY->createString(strColUri.getStore()), state );

  STACK_END (state);
}
/*end class FnDefaultCollationIterator */
}/* namespace zorba */
