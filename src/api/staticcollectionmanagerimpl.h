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
#ifndef ZORBA_STATICCOLLECTIONMANAGER_IMPL_H
#define ZORBA_STATICCOLLECTIONMANAGER_IMPL_H

#include <string>
#include <vector>

#include <zorba/static_collection_manager.h>

namespace zorba {

  class CollectionManagerImpl;
  class StaticCollectionManagerImpl;
  class DiagnosticHandler;
  class StaticContextImpl;

  /** \brief 
   *
   */
  class StaticCollectionManagerImpl : public StaticCollectionManager
  {
  public:
    virtual ~StaticCollectionManagerImpl();

    virtual void
    createCollection(const Item& aQName);

    virtual void
    createCollection(
        const Item& aQName,
        const ItemSequence_t& aContents);

    virtual void
    deleteCollection(const Item& aQName);

    virtual Collection_t
    getCollection(const Item& aQName) const;

    virtual ItemSequence_t
    availableCollections() const;

    virtual bool
    isAvailableCollection(const Item& aQName) const;

    virtual ItemSequence_t
    declaredCollections() const;

    virtual bool
    isDeclaredCollection(const Item& aQName) const;

  protected:
    friend class StaticContextImpl;
    friend class StaticCollectionManagerSetImpl;
    friend class XQueryImpl;
    StaticCollectionManagerImpl(
      const StaticContextImpl* aModuleSctxSet,
      ItemFactory* aFactory);

    void
    initStaticContext(StaticContext_t& aCtx);

  protected:

    ItemFactory*             theFactory;
    std::string              theColDDLNamespace;
    std::string              theColDMLNamespace;

    StaticContext_t          theContext;
    CollectionManagerImpl*   theCollMgr;

    DiagnosticHandler      * theDiagnosticHandler;

    void
    registerDiagnosticHandler(DiagnosticHandler* aDiagnosticHandler);

  }; /* class StaticCollectionManagerImpl */

  /** \brief 
   *
   */
  class StaticCollectionManagerSetImpl : public StaticCollectionManager
  {
  protected:
    typedef std::vector<StaticCollectionManagerImpl*>  MgrSet;

  public:
    virtual ~StaticCollectionManagerSetImpl();

    virtual void
    createCollection(const Item& aQName);

    virtual void
    createCollection(
        const Item& aQName,
        const ItemSequence_t& aContents);

    virtual void
    deleteCollection(const Item& aQName);

    virtual Collection_t
    getCollection(const Item& aQName) const;

    virtual ItemSequence_t
    availableCollections() const;

    virtual bool
    isAvailableCollection(const Item& aQName) const;

    virtual ItemSequence_t
    declaredCollections() const;

    virtual bool
    isDeclaredCollection(const Item& aQName) const;

  protected:
    friend class XQueryImpl;
    StaticCollectionManagerSetImpl(MgrSet&);

    MgrSet  theMgrs;

    void
    registerDiagnosticHandler(DiagnosticHandler* aDiagnosticHandler);

  }; /* class StaticCollectionManagerSetImpl */

} /* namespace zorba */
#endif


/* vim:set et sw=2 ts=2: */
