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
#include "utils/debug.h"

#include "response_iterator.h"

namespace zorba
{
namespace server
{
namespace io
{
  ResponseIterator::ResponseIterator(zorba::Iterator_t aIterator, bool aMaterialize):
        theIsOpen(false),
        theIsInitialized(false),
        theIsEmpty(false)
  {
    if (aMaterialize)
    {
      zorba::Item lItem;
      aIterator->open();
      while (aIterator->next(lItem))
        theItemVector.push_back(lItem);
      aIterator->close();

      theItemSequence = std::auto_ptr<VectorItemSequence>(new VectorItemSequence(theItemVector));
      theWrappedIterator = theItemSequence->getIterator();
    }
    else
    {
      theWrappedIterator = aIterator;
    }
  }

  void ResponseIterator::initialize()
  {
    theWrappedIterator->open();
    if (theWrappedIterator->next(theItem))
    {
      theIsEmpty = false;
      DEBUG_SS("First item is json: " << theItem.isJSONItem());
      theContentType = ContentTypes::getContentTypeForItem(theItem);
      DEBUG_SS("Response Iterator want to send " << theContentType);
      if (theItem.isAtomic())
      {
        theOptions.omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_YES;
      }
      theSerializer = zorba::Serializer::createSerializer(theOptions);
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

  const zorba::Serializer_t ResponseIterator::getSerializer()
  {
    if (!theIsInitialized)
      initialize();

    return theSerializer;
  }

  const std::string& ResponseIterator::getContentType()
  {
    if (!theIsInitialized)
      initialize();

    DEBUG_SS("Response Iterator thinks it is: " << theContentType);
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
