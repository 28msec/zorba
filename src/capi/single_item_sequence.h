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
#pragma once
#ifndef ZORBAC_SINGLE_ITEM_SEQUENCE_H
#define ZORBAC_SINGLE_ITEM_SEQUENCE_H

#include <zorba/zorba.h>
#include <zorba/iterator.h>
#include <zorba/item_sequence.h>
#include <zorba/zorbac.h>

using namespace zorba;

namespace zorbac {

  /**
   * Custom ItemSequence for a singleton Item. This is used for the
   * various parse_document() methods, not
   * create_singleton_seqeunce().
   */
  class SingleItemSequence : public ItemSequence {
    class InternalIterator : public Iterator
    {
    private:
      SingleItemSequence   *theItemSequence;
      bool is_open;
      bool theDone;
    public:
      InternalIterator(SingleItemSequence *item_sequence);

      virtual void open();
      virtual bool next(Item& aItem);
      virtual void close();
      virtual bool isOpen() const;
    };
    public:
      SingleItemSequence(Item aItem);

      virtual Iterator_t getIterator();

    private:
      Item theItem;
  };

} /* namespace zorbac */

#endif
/* vim:set et sw=2 ts=2: */
