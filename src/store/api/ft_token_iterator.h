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

#ifndef ZORBA_FT_TOKEN_ITERATOR_H
#define ZORBA_FT_TOKEN_ITERATOR_H

#include "zorbatypes/ft_token.h"
#include "zorbatypes/rchandle.h"

namespace zorba {

/**
 * An %FTTokenIterator iterates over a sequence of full-text tokens.
 */
class ZORBA_DLL_PUBLIC FTTokenIterator : public SimpleRCObject {
public:
  typedef unsigned index_t;

  /**
   * A %Mark holds the position state of an iterator.
   */
  class Mark : public SimpleRCObject {
  protected:
    Mark() { }
  };
  typedef rchandle<Mark> Mark_t;

  /**
   * Destroys this iterator.
   */
  virtual ~FTTokenIterator() { }

  /**
   * The index of the beginning token.
   *
   * @return Returns said index.
   */
  virtual index_t begin() const = 0;

  /**
   * One greater than the index of the ending token.
   *
   * @return Returns said index.
   */
  virtual index_t end() const = 0;

  /**
   * Checks whether there is a next token.
   *
   * @return Returns \c true only if there is a next token.
   */
  virtual bool hasNext() const = 0;

  /**
   * Obtains the next token and advances the iterator.
   *
   * @return Returns the next token or \c nullptr if there is no next token.
   */
  virtual FTToken const* next() = 0;

  /**
   * Gets the current position.
   *
   * @return Returns said position.
   */
  virtual Mark_t pos() const = 0;

  /**
   * Sets the current position.
   *
   * @param mark The position to set this iterator to.
   */
  virtual void pos( Mark_t const &mark ) = 0;

  /**
   * Resets this iterator to the beginning.
   */
  virtual void reset() = 0;

};

typedef rchandle<FTTokenIterator> FTTokenIterator_t;

} // namespace zorba
#endif  /* ZORBA_FT_TOKEN_ITERATOR_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
