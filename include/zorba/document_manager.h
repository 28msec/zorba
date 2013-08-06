/*
 * Copyright 2006-2011 The FLWOR Foundation.
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
#ifndef ZORBA_DOCUMENTMANAGER_API_H
#define ZORBA_DOCUMENTMANAGER_API_H

#include <zorba/config.h>
#include <zorba/api_shared_types.h>

namespace zorba {

/**
 * \brief There is a single instance of DocumentManager, which provides methods
 * for adding, removing, or accessing XML documents in the Zorba store. This single
 * instance is accessible via the XmlDataManger::getDocumentManager() method.
 */
class ZORBA_DLL_PUBLIC DocumentManager
{
public:
  virtual ~DocumentManager() {}

  /**
   * Add a document to the store, associating it with the given URI.
   *
   * This method adds the document to the "available documents" component of
   * the dynamic context. This means that the document will remain in the
   * store and be accessible to queries via the associated URI (e.g., by using
   * the fn:doc() function) until it is explicitly removed via the
   * DocumentManager::remove() method.
   */
  virtual void
  put(const String& aURI, const Item& aDoc) = 0;

  /**
   * Remove the document with the given URI from the store.
   *
   * This method removes the document from the "available documents" component
   * of the dynamic context. This means that the document will no longer be
   * accessible to queries via the associated URI. However, the document is not
   * necessarily destroyed by this method. It will be destroyed if/when no more
   * references to it exist.
   */
  virtual void
  remove(const String& aURI) = 0;

  /**
   * Return a reference to the root node of the document with the given URI.
   */
  virtual Item
  document(const String& aURI) const = 0;

  /**
   * Returns an iterator over the root nodes of all the available documents
   * (i.e., all the documents that have been added to the store via the
   * DocumentManager::put() method).
   */
  virtual Iterator_t
  availableDocuments() const = 0;
  
  /**
   * Check if a document with a given URI is among the available documents
   * (i.e., the documents that have been added to the store via the
   * DocumentManager::put() method).
   */
  virtual bool
  isAvailableDocument(const String& aURI) const = 0;
};

} /* namespace zorba */
#endif
/* vim:set et sw=2 ts=2: */
