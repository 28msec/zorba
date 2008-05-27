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
#ifndef ZORBAC_ITEM_FACTORY_H
#define ZORBAC_ITEM_FACTORY_H

#include <zorba/zorbac.h>

namespace zorbac {

  class ItemFactory {
    public:
      static XQUERY_ERROR
      create_string(XQC_ItemFactory factory, XQC_String str, XQC_Item_Ref item); 

      static XQUERY_ERROR
      create_anyuri(XQC_ItemFactory factory, XQC_String str, XQC_Item_Ref item); 

      static XQUERY_ERROR
      create_qname2(XQC_ItemFactory factory, XQC_String uri, XQC_String localname, XQC_Item_Ref item); 
      
      static XQUERY_ERROR
      create_qname3(XQC_ItemFactory factory, 
                    XQC_String uri, XQC_String prefix,
                    XQC_String localname, XQC_Item_Ref item); 

      static XQUERY_ERROR
      create_boolean(XQC_ItemFactory factory, int boolean, XQC_Item_Ref item); 

      static void
      free(XQC_ItemFactory factory);

      static void
      assign_functions(XQC_ItemFactory factory);

  }; /* class ItemFactory */

} /* namespace zorbac */

#endif

