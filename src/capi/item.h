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
#ifndef ZORBAC_ITEM_H
#define ZORBAC_ITEM_H

#include <zorba/zorbac.h>
#include <zorba/zorbastring.h>
#include <zorba/item.h>
#include <vector>

namespace zorbac {

  class Item {
    public:
      static XQC_Error
      create(XQC_Item_Ref item);

      static XQC_Error
      string_value(XQC_Item item, const char** str);

      static XQC_Error
      prefix(XQC_Item item, const char** prefix);

      static XQC_Error
      ns(XQC_Item item, const char** ns);

      static XQC_Error
      localname(XQC_Item item, const char** localname);

      static XQC_Error
      boolean_value(XQC_Item item, int*);

      static XQC_Error
      nan(XQC_Item item, int*);

      static XQC_Error
      pos_or_neg_inf(XQC_Item item, int*);

      static void
      free(XQC_Item item);

      static void
      assign_functions(XQC_Item item);

      // buffer to store strings that we return
      // they are valid until the item is destroyed
      std::vector<zorba::String> theStrings;
      zorba::Item                theItem;

  }; /* class Item */

} /* namespace zorbac */

#endif
