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
#ifndef ZORBAC_DATA_MANAGER_H
#define ZORBAC_DATA_MANAGER_H

#include <zorba/zorbac.h>

namespace zorbac {

  class DataManager {
    public:
      static XQC_Error
      load_document(XQC_DataManager data_manager, const char* doc_uri, FILE* document);

      static XQC_Error
      load_document_uri(XQC_DataManager data_manager, const char* location);

      static XQC_Error
      get_document(XQC_DataManager data_manager, const char* document_uri, XQC_Item_Ref doc);

      static XQC_Error
      delete_document(XQC_DataManager data_manager, const char* document_uri);

      static XQC_Error
      create_collection(XQC_DataManager data_manager, const char* collection_uri, 
                        XQC_Collection_Ref col);

      static XQC_Error
      get_collection(XQC_DataManager data_manager, const char* collection_uri, XQC_Collection_Ref collection);

      static XQC_Error
      delete_collection(XQC_DataManager data_manager, const char* collection_uri);

      static void
      free(XQC_DataManager data_manager);

      static void
      assign_functions(XQC_DataManager data_manager);

  }; /* class DataManager */

} /* namespace zorbac */
#endif

