/*
 * Copyright 2015 Federico Cavalieri.
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
#include "zorba/xquery.h"

#include "exceptions/server_exceptions.h"
#include "io/response.h"

#include "response_iterator.h"

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
