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
#ifndef ZORBA_STORE_ITERATOR_FACTORY_H
#define ZORBA_STORE_ITERATOR_FACTORY_H


#include "store/api/iterator.h"


namespace zorba { namespace store {


class IteratorFactory
{
public:
  virtual ~IteratorFactory() {}

  /**
   * Create an iterator to iterate over the children of a document or element
   * node.
   */
  virtual ChildrenIterator* createChildrenIterator() = 0;

  /**
   * Create an iterator to iterate over the attributes of an element node.
   */
  virtual AttributesIterator* createAttributesIterator() = 0;

  /**
   * Create an iterator to iterate over the items of a temp sequence.
   */
  virtual TempSeqIterator* createTempSeqIterator() = 0;
};


}
}

#endif
