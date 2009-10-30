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
#ifndef ZORBA_SINGLETON_ITEM_SEQUENCE_API_H
#define ZORBA_SINGLETON_ITEM_SEQUENCE_API_H

#include <zorba/config.h>
#include <zorba/item_sequence.h>
#include <zorba/serializable.h>

namespace zorba { 

  /** \brief This class is an implementation of the ItemSequence.
   *         Objects of this class return, on the first next call, the
   *         Item that is passed to this object.
   *
   * See ItemSequence
   */
  class ZORBA_DLL_PUBLIC SingletonItemSequence : public ItemSequence
  {
    public:
      /** \brief Constructor
       * 
       * @param aItem the single item in this sequence
       */
      SingletonItemSequence(const Item& aItem);

      /** \brief Destructor
       */
      virtual ~SingletonItemSequence() { }

      /** \brief Get the Item that was passed in the constructor.
       *
       * @param aItem the Item if true is returned by the function.
       * @return true if the sequence is not exhausted, false otherwise.
       * @throw ZorbaException if an error occured.
       */
      virtual bool
      next(Item& aItem);

    protected:

      Item theItem;
      bool theFirstCall;

  }; /* class SingletonItemSequence */

} // namespace zorba
#endif


