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
#ifndef ZORBAC_USER_ITEM_SEQUENCE_H
#define ZORBAC_USER_ITEM_SEQUENCE_H

#include <zorba/zorba.h>
#include <zorba/iterator.h>
#include <zorba/zorbac.h>

using namespace zorba;

namespace zorbac {

  /**
   * A class which implements ItemSequence by getting item data from
   * the end-user (via Zorba_ItemSetter) and creating Items.
   */
  class UserItemSequence : public ItemSequence {
    class InternalIterator : public Iterator
    {
    private:
      UserItemSequence      *theItemSequence;
      bool is_open;
    public:
      InternalIterator(UserItemSequence  *item_sequence);

      virtual void open();
      virtual bool next(Item& aItem);
      virtual void close();
      virtual bool isOpen() const;
    };
    public:
      UserItemSequence
      (XQC_Sequence** args, unsigned int argc,
        external_function_init init_fn, external_function_next next_fn,
        external_function_free free_fn, void* sequence_data,
        ItemFactory* factory, XQC_ErrorHandler* handler);

      virtual ~UserItemSequence();

      static UserItemSequence*
      get(Zorba_ItemSetter* setter);

      virtual Iterator_t  getIterator();

      // Zorba_ItemSetter methods

      static XQC_Error
      set_string(Zorba_ItemSetter* setter, const char* value);

      static XQC_Error
      set_integer(Zorba_ItemSetter* setter, int value);

      static XQC_Error
      set_double(Zorba_ItemSetter* setter, double value);

      static XQC_Error
      set_typed_value(Zorba_ItemSetter* setter, XQC_ItemType type,
        const char* value);

    private:
      Zorba_ItemSetter                       theItemSetter;
      void*                                  theUserData;
      XQC_Sequence_s**                       theArgs;
      unsigned int                           theArgc;
      external_function_init                 theInitFunction;
      external_function_next                 theNextFunction;
      external_function_free                 theFreeFunction;
      void*                                  theSequenceData;
      ItemFactory*                           theFactory;
      XQC_ErrorHandler*                      theErrorHandler;
      Item                                   theItem;

  }; /* class UserItemSequence */

} /* namespace zorbac */

#endif
/* vim:set et sw=2 ts=2: */
