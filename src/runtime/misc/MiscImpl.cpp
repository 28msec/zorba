/**
 * @copyright
 * ========================================================================
 *  Copyright FLWOR Foundation
 * ========================================================================
 *
 * @author Sorin Nasoi (sorin.nasoi@ipdevel.ro)
 * @file misc/MiscImpl.cpp
 *
 */

#include "runtime/misc/MiscImpl.h"
#include "errors/error_factory.h"

namespace zorba {

// 3 The Error Function
//---------------------
store::Item_t FnErrorIterator::nextImpl(PlanState& planState) const
{
  store::Item_t err_qname;
  xqp_string description;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  // TODO: better handling of 2nd and 3rd args
  err_qname = consumeNext(theChildren[0].getp(), planState);
  if( err_qname == NULL)
    /* err_qname = create_qname ("http://www.w3.org/2005/xqt-errors", "err:FOER0000") */;
  if (theChildren.size () >= 2)
    description = consumeNext(theChildren[1].getp(), planState)->getStringValue ();
  ZorbaAlertFactory::fn_user_error(err_qname, description, NULL);

  STACK_END();
}

} /* namespace zorba */
