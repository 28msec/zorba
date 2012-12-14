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
#ifndef API_ITERATOR_H
#define API_ITERATOR_H

/** \brief Interface for an Iterator over an instance of the XML Data Model
 *  (i.e., a sequence of items).
 *
 * An iterator can be in one of the following two states: open or not-open.
 * When in open state, only methods isOpen(), next() and close() may be called.
 * When in not-open state, only isOpen and open() may be called. The open()
 * method changes the state from non-open to open, and the close() method
 * changes the state from open to not-open.
 *
 * Note: Iterator is not a thread-safe class, i.e., none of its methods should
 * ever be called by two or more threads in parallel.
 *
 */
class Iterator 
{
protected:
  friend class DynamicContext;
  friend class DocumentManager;
  friend class CollectionManager;
  friend class Collection;
  friend class StaticContext;
  friend class XQuery;
  friend class ItemSequence;
  zorba::Iterator_t theIterator;
  zorba::Item theItem;
  bool theConsumed;
public:
  // constructors
  Iterator() {}
  Iterator(const Iterator& anIterator)
    : theIterator(anIterator.theIterator),
      theItem(anIterator.theItem),
      theConsumed(false)
  {}
  Iterator(zorba::Iterator_t anIterator)
    : theIterator(anIterator),
      theConsumed(false)
  {}
  Iterator(zorba::Item& aItem)
    : theIterator(0),
      theItem(aItem),
      theConsumed(false)
  {}

  /** \brief Start iterating.
   *
   * This function needs to be called before calling next() or close().
   * Its purpose is to create and initialize any resources that may be 
   * needed during the iteration. It should not be called again until
   * after close() has been called.
   *
   * @throw ZorbaException if an error occurs, or the iterator is open already.
   */
  void open();

  /**
   * brief Check whether the iterator is open or not
   */
  bool isOpen();

  /** \brief Get the next Item of the sequence.
   *
   * @param  aItem the next Item of the result sequence, if true is returned
   *         by the function.
   * @return false if all the items of the sequence have been returned already
   *         by previous invocations of next(); true otherwise.
   * @throw  ZorbaException if an error occurs, or the Iterator has not been opened.
   */
  bool next(Item& aItem);

  /** \brief Stop iterating.
   *
   * The purpose of this method is to release resources that were allocated
   * during open. After calling close(), neither close() nor next() may be
   * called again. However, the iterator may be re-opened (by calling open()).
   *
   * @throw  ZorbaException if an error occurs, or the Iterator has not been opened.
   */
  void close();

  /**
   * brief Destroy this iterator from memory
   */
  void destroy();
}; // class Iterator

#endif