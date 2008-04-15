#include <zorba/item.h>

#include "api/resultiteratorimpl.h"
#include "api/zorbaimpl.h"

#include "store/api/item.h"
#include "runtime/api/plan_wrapper.h"
#include "errors/error_manager.h"

namespace zorba {

  ResultIteratorImpl::ResultIteratorImpl(const PlanWrapper_t& aPlanWrapper,
                                         error::ErrorManager* aErrorManager,
                                         ErrorHandler* aErrorHandler)
    : thePlan(aPlanWrapper),
      theIsOpened(false),
      theErrorManager(aErrorManager),
      theErrorHandler(aErrorHandler) {}

  ResultIteratorImpl::~ResultIteratorImpl() 
  {
    if (theIsOpened)
      thePlan->close();
  }
 
  void 
  ResultIteratorImpl::open()
  {
    ZORBA_TRY
      if ( ! theIsOpened ) {
        thePlan->open();
        theIsOpened = true;
      } 
    ZORBA_CATCH
  }

  bool
  ResultIteratorImpl::next(Item& aItem)
  {
    ZORBA_TRY
      store::Item_t lItem;
      if (!theIsOpened) 
        return false; // todo throw error here

      lItem = thePlan->next();

      if (lItem == NULL)
        return false;
    
      if (lItem->isPul())
        ZORBA_ERROR(ZorbaError::API0024_CANNOT_ITERATE_OVER_UPDATE_QUERY);

      aItem = &*lItem;
      return true;
    ZORBA_CATCH
    return false;
  }

  void 
  ResultIteratorImpl::close()
  {
    ZORBA_TRY
      if (theIsOpened) {
        thePlan->reset();
      }
    ZORBA_CATCH
  }

} /* namespace zorba */
