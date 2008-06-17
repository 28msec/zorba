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

#include <zorba/config.h>
#include <zorba/api_shared_types.h>
#include <zorba/item_sequence.h>

namespace zorba {

  /** \brief Interface for an Iterator over an instance of the XML Data Model.
    *
    * Note: This class is reference counted. When writing multi-threaded clients,
    * it is the responibility of the client code to synchronize assignments to the
    * SmartPtr holding this object.
    */
  class ZORBA_EXTERN_DECL Iterator : public ItemSequence, public SmartObject
  {
    public:
      /** \brief Destructor
       */
      virtual ~Iterator() {}

      /** \brief Start iterating
       *
       * This function needs to be called before calling next.
       * @throw ZorbaException if an error occurs.
       */
      virtual void 
      open() = 0;

      /** \brief Get the next Item of the sequence.
       * @param aItem the next Item of the result sequence if true is returned by the function.
       * @return true if the sequence is not exhausted, false otherwise.
       * @throw ZorbaException if an error occurs during query execution or the Iterator has
       *        not been opened.
       */
      virtual bool
      next(Item& aItem) = 0;

      /** \brief Stop iterating.
       *
       * In order to call Iterator::next, open has to been called.
       */
      virtual void 
      close() = 0;

  };

} /* namespace zorba */
#endif
