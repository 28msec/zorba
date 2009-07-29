#include "api/vectoriterator.h"

#include <zorba/item.h>

#include "system/globalenv.h"

#include "zorbaerrors/error_manager.h"
#include "store/api/item.h"
#include "store/api/iterator.h"
#include "store/api/store.h"

namespace zorba {

#define RESULT_ITERATOR_TRY try {
 
#define RESULT_ITERATOR_CATCH                                  \
} catch (error::ZorbaError& /*e*/)                             \
{                                                              \
}                                                              \
catch (std::exception& /*e*/)                                  \
{                                                              \
}                                                              \
catch (...)                                                    \
{                                                              \
} 

  VectorIterator::VectorIterator(const std::vector<store::Item_t>& aVector,
                                 ErrorHandler* aErrorHandler)
    : theVector(aVector),
      theErrorHandler(aErrorHandler),
      theIsOpened(false)
  {
  }

  VectorIterator::~VectorIterator()
  {
  }

  void 
  VectorIterator::open()
  {
    RESULT_ITERATOR_TRY
      if ( theIsOpened )
      {
        ZORBA_ERROR_DESC(API0010_XQUERY_EXECUTION_NOT_STARTED,
                         "Iterator has already been opened");
      }
      theIter = theVector.begin();
      theIsOpened = true;
    RESULT_ITERATOR_CATCH
  }

  bool
  VectorIterator::next(Item& aItem)
  {
    RESULT_ITERATOR_TRY
      if (!theIsOpened)  
      {
        ZORBA_ERROR_DESC(API0010_XQUERY_EXECUTION_NOT_STARTED,
                         "Iterator has not been opened");
      }

      if (theIter == theVector.end()) 
        return false;
      
      aItem = &**theIter;
      ++theIter;
      return true;
    RESULT_ITERATOR_CATCH
    return false;
  }

  void 
  VectorIterator::close()
  {
  }

} /* namespace zorba */
