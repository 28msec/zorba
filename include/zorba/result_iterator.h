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
#ifndef ZORBA_RESULT_ITERATOR_API_H
#define ZORBA_RESULT_ITERATOR_API_H

#include <zorba/api_shared_types.h>
#include <zorba/iterator.h>

namespace zorba {

  /** \brief A ResultIterator can be used to iterator over the result sequence of a query.
   *
   * A ResultIterator is created by calling XQuery::iterator() on a compiled XQuery.
   */
  class ResultIterator  : public Iterator
  {
    public:

      /** \brief Destructor
       */
      virtual ~ResultIterator() {}

      /** \brief Start iterating. 
       *
       * This function needs to be called before calling next.
       */
      virtual void 
      open() = 0;

      /** \brief Get the next Item of the result sequence.
       *
       * @param aItem the next Item of the result sequence if true is returned by the function.
       * @return true if the sequence is not exhausted, false otherwise.
       * @throw ZorbaException if an error occured during query execution or the ResultIterator has
       *        not been opened..
       */
      virtual bool
      next(Item& aItem) = 0;

      /** \brief Stop iterating.
       *
       * In order to call ResultIterator::next, open has to been called.
       */
      virtual void 
      close() = 0;

  };

} /* namespace zorba */
#endif
