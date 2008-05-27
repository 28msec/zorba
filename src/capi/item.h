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

namespace zorbac {

  class Item {
    public:
      static XQUERY_ERROR
      create(XQC_Item_Ref item);

      static XQUERY_ERROR
      string_value(XQC_Item item, XQC_String);

      static XQUERY_ERROR
      prefix(XQC_Item item, XQC_String);

      static XQUERY_ERROR
      ns(XQC_Item item, XQC_String);

      static XQUERY_ERROR
      localname(XQC_Item item, XQC_String);

      static XQUERY_ERROR
      boolean_value(XQC_Item item, int*);

      static XQUERY_ERROR
      nan(XQC_Item item, int*);

      static XQUERY_ERROR
      pos_or_neg_inf(XQC_Item item, int*);

      static void
      free(XQC_Item item);

      static void
      assign_functions(XQC_Item item);

  }; /* class Item */

} /* namespace zorbac */

#endif
