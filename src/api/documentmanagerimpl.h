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
#ifndef ZORBA_DOCUMENTMANAGER_IMPL_H
#define ZORBA_DOCUMENTMANAGER_IMPL_H

#include <zorba/document_manager.h>
#include <string>

namespace zorba {

  class DiagnosticHandler;

  /** \brief 
   *
   */
  class DocumentManagerImpl : public DocumentManager
  {
  protected:
    StaticContext_t          theContext;
    ItemFactory*             theFactory;
    static std::string       theDocNamespace;

    DiagnosticHandler      * theDiagnosticHandler;

  public:
    void
    put(const String& aURI, const Item& aDoc);

    void
    remove(const String& aURI);

    Item
    document(const String& aURI) const;

    ItemSequence_t
    availableDocuments() const;

    bool
    isAvailableDocument(const String& aURI) const;

    virtual ~DocumentManagerImpl();

  protected:
    friend class XmlDataManagerImpl;
    DocumentManagerImpl(
      const StaticContext_t& aSctx,
      ItemFactory* aFactory);

    void
    initStaticContext();

    void
    registerDiagnosticHandler(DiagnosticHandler* aDiagnosticHandler);

  }; /* class DocumentManagerImpl */

} /* namespace zorba */
#endif
/* vim:set et sw=2 ts=2: */
