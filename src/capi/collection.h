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
#ifndef ZORBAC_COLLECTION_H
#define ZORBAC_COLLECTION_H

#include <zorba/zorbac.h>

namespace zorbac {

  class Collection {

    public:
      static XQUERY_ERROR
      get_uri(XQC_Collection collection, XQC_Item_Ref uri_item);
  
      static XQUERY_ERROR
      add_node(XQC_Collection collection, XQC_Item node);
  
      static XQUERY_ERROR
      delete_node(XQC_Collection collection, XQC_Item node);
  
      static XQUERY_ERROR
      add_sequence(XQC_Collection collection, XQC_Sequence sequence);
  
      static XQUERY_ERROR
      add_document(XQC_Collection collection, FILE* doc);

      static XQUERY_ERROR
      add_document_char(XQC_Collection collection, const char* doc);

      static void
      free(XQC_Collection);

      static void
      assign_functions(XQC_Collection);

  }; /* class Collection */

} /* namespace zorbac */
#endif
