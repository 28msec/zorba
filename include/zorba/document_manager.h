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

  /** \brief 
   *
   */
  class ZORBA_DLL_PUBLIC DocumentManager
  {
  public:
    virtual void
    put(const String& aURI, const Item& aDoc) = 0;

    virtual void
    remove(const String& aURI) = 0;

    virtual Item
    document(const String& aURI) const = 0;

    virtual ItemSequence_t
    availableDocuments() const = 0;

    virtual bool
    isAvailableDocument(const String& aURI) const = 0;

    virtual ~DocumentManager() {}

  }; /* class DocumentManager */

} /* namespace zorba */
#endif
/* vim:set et sw=2 ts=2: */
