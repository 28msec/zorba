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
#ifndef ZORBA_XMLDATAMANAGER_IMPL_H
#define ZORBA_XMLDATAMANAGER_IMPL_H

#include <zorba/xmldatamanager.h>

#include <zorba/api_shared_types.h>

#include "zorbautils/latch.h"

#include "common/shared_types.h"


namespace zorba {

class ErrorHandler;

namespace store {
    class Store;
}
  

class XmlDataManagerImpl : public XmlDataManager
{
 public:
  virtual ~XmlDataManagerImpl();

  static XmlDataManagerImpl* 
  getInstance();

  void
  registerErrorHandler(ErrorHandler* aErrorHandler);

  Item 
  loadDocument(const String& uri, std::istream& stream);

  Item 
  loadDocument(const String& uri, std::istream& stream, ErrorHandler* aErrorHandler);

  Item
  loadDocument(const String& local_file_uri);

  Item
  loadDocument(const String& local_file_uri, ErrorHandler* aErrorHandler);

  Item
  loadDocumentFromUri(const String& aUri);

  Item
  getDocument(const String& uri);

  Item
  getDocument(const String& uri, ErrorHandler* aErrorHandler);

  bool
  deleteDocument(const String& uri);

  bool
  deleteDocument(const String& uri, ErrorHandler* aErrorHandler);

  Collection_t
  createCollection(const String& uri);

  Collection_t
  createCollection(const String& uri, ErrorHandler* aErrorHandler);

  Collection_t
  getCollection(const String& uri);

  Collection_t
  getCollection(const String& uri, ErrorHandler* aErrorHandler);

  bool
  deleteCollection(const String& uri);

  bool
  deleteCollection(const String& uri, ErrorHandler* aErrorHandler);

 protected:
  XmlDataManagerImpl();

  store::Store           * theStore;
  
  ErrorHandler           * theErrorHandler;
  
  bool                     theUserErrorHandler;

  SYNC_CODE(Latch          theLatch;)

}; /* class XmlDataManagerImpl */

} /* namespace zorba */
#endif
