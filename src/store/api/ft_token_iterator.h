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

#include <vector>

#include "store/api/ft_token.h"
#include "zorbatypes/rchandle.h"
#include "zorbaerrors/Assert.h"

namespace zorba {

/**
 * An <code>FTTokenIterator</code> iterates over a sequence of full-text
 * tokens.
 */
class ZORBA_DLL_PUBLIC FTTokenIterator : public SimpleRCObject {
public:
  typedef unsigned index_t;

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
   * Gets the current token.
   *
   * @return Returns said token.
   */
  virtual FTToken const& current() const = 0;

  /**
   * Checks whether there are any tokens to iterate over.
   *
   * @return Returns <code>true</code> only if there are no tokens to iterate
   * over.
   */
  virtual bool empty() const = 0;

  /**
   * One greater than the index of the ending token.
   *
   * @return Returns said index.
   */
  virtual index_t end() const = 0;

  /**
   * Checks whether there is a next token.
   *
   * @return Returns <code>true</code> only if there is a next token.
   */
  virtual bool hasNext() const = 0;

  /**
   * Marks the iterator's position so that it can be returned to later.
   *
   * @param set If true, sets a mark; if false, returns to the previous mark.
   */
  virtual void mark( bool set ) = 0;

  /**
   * Obtains the next token and advances the iterator.
   *
   * @param ppToken A pointer to the next token is put here; may be null to
   * advance the iterator only.
   * @return Returns <code>true</code> only if there is a next token.
   */
  virtual bool next( FTToken const **ppToken = 0 ) = 0;

  /**
   * Resets this iterator and the mark to the beginning.
   */
  virtual void reset() = 0;

};

typedef rchandle<FTTokenIterator> FTTokenIterator_t;

} // namespace zorba
#endif  /* ZORBA_FT_TOKEN_ITERATOR_H */
/* vim:set et sw=2 ts=2: */
