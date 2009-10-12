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
#include <memory>

#include "system/globalenv.h"

#include "compiler/api/compilercb.h"

#include "runtime/context/ContextImpl.h"
#include "runtime/api/runtimecb.h"
#include "runtime/visitors/planiter_visitor.h"

#include "context/dynamic_context.h"
#include "context/static_context.h"

#include "zorbatypes/datetime.h"

#include "store/api/item_factory.h"


namespace zorba
{
SERIALIZABLE_CLASS_VERSIONS(FnCurrentDateTimeIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnCurrentDateTimeIterator)

SERIALIZABLE_CLASS_VERSIONS(FnCurrentDateIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnCurrentDateIterator)

SERIALIZABLE_CLASS_VERSIONS(FnCurrentTimeIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnCurrentTimeIterator)

SERIALIZABLE_CLASS_VERSIONS(FnImplicitTimezoneIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnImplicitTimezoneIterator)

SERIALIZABLE_CLASS_VERSIONS(FnDefaultCollationIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnDefaultCollationIterator)


NARY_ACCEPT(FnCurrentDateTimeIterator);

NARY_ACCEPT(FnCurrentDateIterator);

NARY_ACCEPT(FnCurrentTimeIterator);

NARY_ACCEPT(FnImplicitTimezoneIterator);

NARY_ACCEPT(FnDefaultCollationIterator);


/**
 *______________________________________________________________________
 *
 * 16.3 fn:current-dateTime
 *
 * fn:current-dateTime() as xs:dateTime
 *_______________________________________________________________________*/

/*begin class FnCurrentDateTimeIterator */
bool
FnCurrentDateTimeIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  result = planState.theRuntimeCB->theDynamicContext->get_current_date_time();
  if (result != NULL)
    STACK_PUSH(true, state );

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
bool
FnCurrentDateIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t itemRes;
  std::auto_ptr<xqp_date> d;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemRes = planState.theRuntimeCB->theDynamicContext->get_current_date_time();
  if( NULL != itemRes )
  {
    d.reset (itemRes->getDateTimeValue().getDate());
    STACK_PUSH( GENV_ITEMFACTORY->createDate(result, d.get ()), state );
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
bool
FnCurrentTimeIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t itemRes;
  std::auto_ptr<xqp_time> t;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemRes = planState.theRuntimeCB->theDynamicContext->get_current_date_time();
  if( NULL != itemRes )
  {
    t.reset (itemRes->getDateTimeValue().getTime());
    STACK_PUSH( GENV_ITEMFACTORY->createTime(result, t.get ()), state );
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
bool
FnImplicitTimezoneIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  long secs;
  bool neg;
  xqp_dayTimeDuration dtd;
  std::auto_ptr<Duration> dur;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  secs = planState.theRuntimeCB->theDynamicContext->get_implicit_timezone();
  neg = secs < 0;
  if (neg)
    secs = -secs;
  dur = std::auto_ptr<Duration>(new Duration(Duration::DAYTIMEDURATION_FACET, neg, 0, 0, 0, 0, 0 , secs));
                                                                                                    
  STACK_PUSH( GENV_ITEMFACTORY->createDayTimeDuration(result, dur.get()), state );

  STACK_END (state);
}


/**
 *______________________________________________________________________
 *
 * 16.7 fn:default-collation
 *
 * fn:default-collation() as xs:string
 *_______________________________________________________________________*/

bool
FnDefaultCollationIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  xqpStringStore_t strColUri;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  strColUri = theSctx->default_collation_uri().getStore();

  STACK_PUSH(GENV_ITEMFACTORY->createString(result, strColUri), state );

  STACK_END (state);
}


}/* namespace zorba */
