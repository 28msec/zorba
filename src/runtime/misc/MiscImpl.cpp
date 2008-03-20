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
  store::Item_t description;
//   std::vector<class store::Item*>* items;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if(theChildren.size() > 2) {
    //TODO complete the implementation and also enhance fn_user_error
  }
  else {
    err_qname = consumeNext(theChildren[0].getp(), planState);
    if (theChildren.size() == 2) {
      if( err_qname != NULL) {
      description = consumeNext(theChildren[1].getp(), planState);
      ZorbaAlertFactory::fn_user_error(err_qname, description->getStringValue() , NULL);
      }
      else 
        ZorbaAlertFactory::fn_user_error(NULL, "", NULL);
    }
    else //theChildren.size() = 1
      ZorbaAlertFactory::fn_user_error(err_qname, "", NULL);
  }

  STACK_END();
}

} /* namespace zorba */
