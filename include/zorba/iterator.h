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

// standard
#include <cassert>

// Zorba
#include <zorba/api_shared_types.h>
#include <zorba/internal/type_traits.h>

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

/**
 * \brief Interface for an Iterator over a sequence of items.
 *
 * An iterator can be in one of the following two states: open or not-open.
 * When in open state, only methods isOpen(), next() and close() may be called.
 * When in not-open state, only isOpen() and open() may be called. The open()
 * method changes the state from non-open to open, and the close() method
 * changes the state from open to not-open.
 */
class ZORBA_DLL_PUBLIC Iterator : virtual public SmartObject
{
 public:
  /** \brief Start iterating.
   *
   * This function needs to be called before calling next(), count(), skip() or
   * close().
   * Its purpose is to create and initialize any resources that may be 
   * needed during the iteration. It should not be called again until
   * after close() has been called.
   *
   * @throw ZorbaException if an error occurs, or the iterator is open already.
   */
  virtual void 
  open() = 0;

  /** \brief Get the next Item of the sequence.
   *
   * @param  aItem the next Item of the sequence, unless all the items of the
   *         sequence have been returned already by previous invocations of next().
   * @return false if all the items of the sequence have been returned already
   *         by previous invocations of next(); true otherwise.
   * @throw  ZorbaException if an error occurs, or the Iterator has not been opened.
   */
  virtual bool
  next(Item& aItem) = 0;
  
  /** \brief Stop iterating.
   *
   * The purpose of this method is to release resources that were allocated
   * during open. After calling close(), neither close() nor next() may be
   * called again. However, the iterator may be re-opened (by calling open()).
   *
   * @throw  ZorbaException if an error occurs, or the Iterator has not been opened.
   */
  virtual void 
  close() = 0;

  /**
   * \brief Check whether the iterator is open or not
   */
  virtual bool
  isOpen() const = 0;

  /**
   * Counts the number of items this iterator would have returned.
   *
   * @throw ZorbaException if an error occurs or the iterator has not been
   * opened.
   */
  virtual int64_t
  count();

  /**
   * Skips a number of items.
   *
   * @param count The number of items to skip.
   * @return \c true only if there are more items.
   * @throw ZorbaException if an error occurs or the iterator has not been
   * opened.
   */
  virtual bool
  skip(int64_t count);
};

///////////////////////////////////////////////////////////////////////////////

/**
 * Creates an \c Iterator over some container type of \c Item, e.g.,
 * <code>vector&lt;Item&gt;</code>.
 *
 * @param container The container to create the \c Iterator over.
 * @param copy If \c false, \a container is swapped with an internal one thus
 * clearing \a container; if \c true, a copy of \a container is made instead.
 * @return Returns a new \c Iterator over \a container.
 */
template<class ContainerType>
typename std::enable_if<
  std::is_same<typename ContainerType::value_type,Item>::value,Iterator_t>::type
make_iterator( ContainerType &container, bool copy = false ) {

  struct iterator_impl : Iterator {
    iterator_impl( ContainerType &container, bool copy ) : open_( false ) {
      if ( copy )
        container_ = container;
      else
        container_.swap( container );
    }

    void close() {
      assert( open_ );
      open_ = false;
    }

    bool isOpen() const {
      return open_;
    }

    bool next( Item &result ) {
      assert( open_ );
      if ( pos_ == container_.end() )
        return false;
      result = *pos_;
      ++pos_;
      return true;
    }

    void open() {
      assert( !open_ );
      pos_ = container_.begin();
      open_ = true;
    }

    ContainerType container_;
    bool open_;
    typename ContainerType::const_iterator pos_;
  };

  return Iterator_t( new iterator_impl( container, copy ) );
};

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
#endif
/* vim:set et sw=2 ts=2: */
