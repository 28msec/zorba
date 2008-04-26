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
