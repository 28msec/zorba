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

/** \brief Interface for an Iterator over an instance of the XML Data Model
 *  (i.e., a sequence of items).
 *
 * An iterator can be in one of the following two states: open or not-open.
 * When in open state, only methods isOpen(), next() and close() may be called.
 * When in not-open state, only isOpen and open() may be called. The open()
 * method changes the state from non-open to open, and the close() method
 * changes the state from open to not-open.
 *
 * Iterator is not a thread-safe class, i.e., none of its methods should ever
 * be called by two or more threads in parallel.
 *
 * Note: This class is reference counted. When writing multi-threaded clients,
 * it is the responibility of the client code to synchronize assignments to the
 * SmartPtr holding this object.
 */
class ZORBA_DLL_PUBLIC Iterator : virtual public SmartObject
{
 public:
  /** \brief Destructor
   */
  virtual ~Iterator() {}

  /** \brief Start iterating.
   *
   * This function needs to be called before calling next() or close().
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
   * @param  aItem the next Item of the result sequence, if true is returned
   *         by the function.
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
   */
  virtual void 
  close() = 0;

  /**
   * brief Check whether the iterator is open or not
   */
  virtual bool
  isOpen() const = 0;
};


} /* namespace zorba */
#endif
/* vim:set et sw=2 ts=2: */
