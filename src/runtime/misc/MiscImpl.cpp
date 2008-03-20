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
#include "errors/error_manager.h"

namespace zorba {

// 3 The Error Function
//---------------------
store::Item_t FnErrorIterator::nextImpl(PlanState& planState) const
{
  store::Item_t err_qname;
  xqp_string description;
  std::vector<store::Item_t> aErrorObject; // TODO

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  // TODO: better handling of 2nd and 3rd args
  err_qname = consumeNext(theChildren[0].getp(), planState);
  if( err_qname == NULL)
    /* err_qname = create_qname ("http://www.w3.org/2005/xqt-errors", "err:FOER0000") */;
  if (theChildren.size () >= 2)
    description = consumeNext(theChildren[1].getp(), planState)->getStringValue ();

  ZORBA_USER_ERROR(err_qname->getNamespace(), err_qname->getLocalName(), description, 
                   loc, aErrorObject);

  STACK_END();
}

} /* namespace zorba */
