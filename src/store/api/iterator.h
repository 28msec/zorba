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
#ifndef ZORBA_ITERATOR_H
#define ZORBA_ITERATOR_H

#include "common/shared_types.h"

namespace zorba { namespace store {

  /**
   * General iterator interface. Used to program iterators which return a
   * sequence of items, wrapped into a rchandle object for garbage collection
   */
  class Iterator : virtual public SimpleRCObject
  {
    public:
      virtual ~Iterator() {}

      Iterator() {}

      Iterator(const Iterator&) 
        : SimpleRCObject() {}

      virtual void
      open() = 0;

      virtual store::Item_t
      next() = 0;

      virtual void
      reset() = 0;

      virtual void
      close() = 0;

  };
} /* namespace store */
} /* namespace zorba */
#endif
