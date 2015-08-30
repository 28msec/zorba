#include "zorba/xquery.h"

#include "exceptions/server-exceptions.h"
#include "io/response.h"
#include "response-iterator.h"

namespace zorba
{
namespace server
{
namespace io
{
  ResponseIterator::ResponseIterator(zorba::XQuery_t aQuery):
      theIsOpen(false),
      theWrappedIterator(aQuery->iterator()),
      theIsInitialized(false),
      theIsEmpty(false),
      theIsBinary(false)
  {
  }

  ResponseIterator::ResponseIterator(zorba::Iterator_t aIterator):
        theIsOpen(false),
        theWrappedIterator(aIterator),
        theIsInitialized(false),
        theIsEmpty(false),
        theIsBinary(false)
  {
  }

  void ResponseIterator::initialize()
  {
    theWrappedIterator->open();
    if (theWrappedIterator->next(theItem))
    {
      theIsEmpty = false;
      theContentType = ContentTypes::getContentTypeForItem(theItem);
      theIsBinary = false;
    }
    else
      theIsEmpty = true;

    theIsInitialized = true;
  }

  bool ResponseIterator::isEmpty()
  {
    if (!theIsInitialized)
      initialize();

    return theIsEmpty;
  }

  bool ResponseIterator::isBinary()
  {
    if (!theIsInitialized)
      initialize();

    return theIsBinary;
  }

  const std::string& ResponseIterator::getContentType()
  {
    if (!theIsInitialized)
      initialize();

    return theContentType;
  }

  void ResponseIterator::open()
  {
    theIsOpen = true;
  }

  bool ResponseIterator::next(Item& aItem)
  {
    if (!theIsInitialized)
      initialize();

    if (theItem.isNull())
      return false;

    aItem = theItem;
    if (!theWrappedIterator->next(theItem))
      theItem = zorba::Item();
    return true;
  }

  void ResponseIterator::close()
  {
    theIsOpen = false;

    if (theWrappedIterator->isOpen())
      theWrappedIterator->close();
  }

  bool ResponseIterator::isOpen() const
  {
    return theIsOpen;
  }

  int64_t ResponseIterator::count()
  {
    throw exceptions::ServerException("Response Iterator does not support <count>");
  }

  bool ResponseIterator::skip(int64_t count)
  {
    throw exceptions::ServerException("Response Iterator does not support <skip>");
  }

}
}
}
