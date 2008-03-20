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
#include "store/api/item_factory.h"
#include "store/api/store.h"
#include "system/globalenv.h"

namespace zorba {

// 3 The Error Function
//---------------------
store::Item_t FnErrorIterator::nextImpl(PlanState& planState) const
{
  static const char *err_ns = "http://www.w3.org/2005/xqt-errors";
  store::Item_t err_qname = GENV_ITEMFACTORY->createQName (err_ns, "err", "FOER0000");
  xqp_string ns;
  xqp_string description;
  std::vector<store::Item_t> aErrorObject; // TODO


  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (theChildren.size () >= 1)
    err_qname = consumeNext(theChildren[0].getp(), planState);
  if (theChildren.size () >= 2)
    description = consumeNext(theChildren[1].getp(), planState)->getStringValue ();

  ns = err_qname->getNamespace ();
  if (ns == err_ns)
    ZORBA_ERROR (error::ZorbaError::err_name_to_code (err_qname->getLocalName()));
  else {
    ZORBA_USER_ERROR(ns, err_qname->getLocalName(), description,
                     loc, aErrorObject);
  }

  STACK_END();
}

} /* namespace zorba */
