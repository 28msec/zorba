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
#include "runtime/api/runtimecb.h"
#include "context/static_context.h"
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

  STACK_END (state);
}

// 8.1 fn:resolve-uri
//---------------------
store::Item_t FnResolveUriIterator::nextImpl(PlanState& planState) const
{
  store::Item_t item;
  xqp_string strRelative;
  xqp_string strBase;
  xqp_string strResult;
  
  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  //TODO:check if both relative and base uri's are valid. If not raise err:FORG0002.
  item = consumeNext(theChildren[0].getp(), planState );
  if ( item != NULL ){
    strRelative = item->getStringValue();
    if( theChildren.size() == 2 ) {
      item = consumeNext(theChildren[1].getp(), planState );
      strBase = item->getStringValue();
      strResult = planState.theRuntimeCB->theStaticContext->resolve_relative_uri(strRelative, strBase);
    }
    else {
      if( planState.theRuntimeCB->theStaticContext->baseuri().empty() )
        ZORBA_ERROR_LOC_DESC( ZorbaError::FONS0005, loc, "Base-uri not defined in the static context.");
      else
        strResult = planState.theRuntimeCB->theStaticContext->resolve_relative_uri(strRelative);
    }
    STACK_PUSH(GENV_ITEMFACTORY->createString(strResult.getStore()), state);
  }

  //TODO fix the implementation
  
  STACK_END (state);
}

} /* namespace zorba */
