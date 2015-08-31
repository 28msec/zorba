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
#ifndef ZORBA_SERVER_IO_RESPONSE_ITERATOR_H_
#define ZORBA_SERVER_IO_RESPONSE_ITERATOR_H_

#include <string>

#include "zorba/item.h"
#include "zorba/iterator.h"

namespace zorba
{
namespace server
{
namespace io
{
  class ResponseIterator : public zorba::Iterator
  {
  public:
    ResponseIterator(zorba::XQuery_t aQuery);
    ResponseIterator(zorba::Iterator_t aIterator);

    bool isEmpty();
    bool isBinary();
    const std::string& getContentType();

    /*
     * zorba::Iterator functions
     */
    void open();
    bool next(Item& aItem);
    void close();
    bool isOpen() const;
    virtual int64_t count();
    bool skip(int64_t count);

  private:
    void initialize();

    bool theIsOpen;
    zorba::Iterator_t theWrappedIterator;

    bool theIsInitialized;
    zorba::Item theItem;
    bool theIsEmpty;
    bool theIsBinary;
    std::string theContentType;
  };
}
}
}

#endif

