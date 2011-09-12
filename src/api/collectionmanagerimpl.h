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
#ifndef ZORBA_COLLECTIONMANAGER_IMPL_H
#define ZORBA_COLLECTIONMANAGER_IMPL_H

#include <zorba/collection_manager.h>
#include <string>

namespace zorba {

  class DiagnosticHandler;

  /** \brief 
   *
   */
  class CollectionManagerImpl : public virtual CollectionManager
  {
  protected:
    StaticContext_t          theContext;
    ItemFactory*             theFactory;
    std::string              theColDDLNamespace;
    std::string              theColDMLNamespace;

    DiagnosticHandler      * theDiagnosticHandler;

  public:
    virtual void
    createCollection(const Item& aName);

    virtual void
    createCollection(
        const Item& aName,
        const ItemSequence_t& aContents);

    virtual void
    deleteCollection(const Item& aName);

    virtual Collection_t
    getCollection(const Item& aName) const;

    virtual ItemSequence_t
    availableCollections() const;

    virtual bool
    isAvailableCollection(const Item& aName) const;

    virtual ~CollectionManagerImpl();

    virtual void
    registerDiagnosticHandler(DiagnosticHandler* aDiagnosticHandler);

  protected:
    friend class XmlDataManagerImpl;
    friend class StaticCollectionManagerImpl;
    CollectionManagerImpl(
      const StaticContext_t& aSctx,
      ItemFactory* aFactory,
      const std::string& aDDLNS = "http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl",
      const std::string& aDMLNS = "http://www.zorba-xquery.com/modules/store/dynamic/collections/dml");

    void
    initStaticContext(StaticContext_t& aSctx);


  }; /* class CollectionManagerImpl */

} /* namespace zorba */
#endif

/* vim:set et sw=2 ts=2: */
