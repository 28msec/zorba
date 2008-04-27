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
#ifndef ZORBA_ITERATOR_API_H
#define ZORBA_ITERATOR_API_H

#include <zorba/api_shared_types.h>
#include <zorba/item_sequence.h>

namespace zorba {

  class Iterator : public ItemSequence
  {
    public:

      virtual ~Iterator() {}

      virtual void 
      open() = 0;

      virtual bool
      next(Item&) = 0;

      virtual void 
      close() = 0;

  };

} /* namespace zorba */
#endif
