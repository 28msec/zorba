/*
 * Copyright 2006-2008 The FLWOR Foundation.
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
#ifndef ZORBA_RUNTIME_UTIL_SINGLE_ITEM_ITERATOR
#define ZORBA_RUNTIME_UTIL_SINGLE_ITEM_ITERATOR

#include <vector>

#include "store/api/iterator.h"

#include "common/shared_types.h"

namespace zorba
{ 

class SingleItemIterator : public store::Iterator
{
private:
  store::Item_t theItem;
  bool          theIsDone;

public:
  SingleItemIterator() : theIsDone(true) {}

  SingleItemIterator(store::Item_t& item)
  {
    theIsDone = false;
    theItem.transfer(item);
  } 

  virtual ~SingleItemIterator() {}

  void init(store::Item_t& item)
  {
    theIsDone = false;
    theItem.transfer(item);
  }

  void open() {}

  bool next(store::Item_t& res) 
  {
    if (theIsDone)
      return false;

    res = theItem;
    theIsDone = true;
    return true;
  }

  void reset() { theIsDone = (theItem == NULL); }

  void close() { theItem = NULL; theIsDone = true; }

#ifndef NDEBUG
  // toString() debugging method.
  virtual std::string toString() const { return ""; };
#endif      
};


typedef rchandle<SingleItemIterator> SingleItemIterator_t;


} // namespace zorba

#endif
/* vim:set et sw=2 ts=2: */
