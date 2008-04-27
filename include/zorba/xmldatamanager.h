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
#ifndef ZORBA_XMLDATAMANAGER_API_H
#define ZORBA_XMLDATAMANAGER_API_H

#include <istream>
#include <zorba/api_shared_types.h>

namespace zorba {
  
  class XmlDataManager 
  {
    public:
      virtual ~XmlDataManager() {}

      virtual Item 
      loadDocument(const String& uri, std::istream& stream, ErrorHandler* aErrorHandler = 0) = 0;

      virtual Item
      loadDocument(const String& local_file_uri, ErrorHandler* aErrorHandler = 0) = 0;

      virtual Item
      getDocument(const String& uri, ErrorHandler* aErrorHandler = 0) = 0;

      virtual bool
      deleteDocument(const String& uri, ErrorHandler* aErrorHandler = 0) = 0;

      virtual Collection_t
      createCollection(const String& uri, ErrorHandler* aErrorHandler = 0) = 0;

      virtual Collection_t
      getCollection(const String& uri, ErrorHandler* aErrorHandler = 0) = 0;

      virtual bool
      deleteCollection(const String& uri, ErrorHandler* aErrorHandler = 0) = 0;

  }; /* class XmlDataManager */

} /* namespace zorba */
#endif
