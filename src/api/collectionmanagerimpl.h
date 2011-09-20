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


/*******************************************************************************
  There are 3 kinds of CollectionManager instsances, depending on the kind of
  collections they are created to manage: static, dynamic, or w3c collections.

  There is only one instance of a dynamic CollectionManager, and only one
  instance of a w3c CollectionManager. These are obtainable via the 
  XmlDataManager::getCollectionManagerand and XmlDataManager::getW3CCollectionManager
  methods respectively, and are owned by the (singleton) XmlDataManager obj. 

  There is one instance of a static CollectionManager per instance of
  StaticCollectionManager. Such a CollectionManager obj is created internally
  when the associated StaticCollectionManager obj is created, and it is owned
  by the associated StaticCollectionManager obj.

  theContext:
  -----------
  A StaticContext obj that is created during construction of this CollectionManager
  and is owned by it. The obj is created as the child of the StaticContext obj
  owned by the associated XmlDataManager or StaticCollectionManager.  A child 
  context is required because the CollectionManagerImpl constructor will do a 
  loadProlog on this child in order to import either one of the following 3 
  modules, depending on whether "this" is supposed to manage dynamic collections,
  or w3c collections, or static collections respectively:
  http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl, or
  http://www.zorba-xquery.com/modules/store/dynamic/collections/w3c/ddl, or
  http://www.zorba-xquery.com/modules/store/static/collections/ddl

  theFactory:
  -----------
  The singleton ItemFactory obj.

  theDiagnosticHandler:
  ---------------------
  The DiagnosticHandler to use for handling errors raised during the execution of
  the methods of this CollectionManager. It is the same as the DiagnosticHandler 
  used by the associated XmlDataManager or StaticCollectionManager.

  theColDDLNamespace:
  -------------------
  http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl, or
  http://www.zorba-xquery.com/modules/store/dynamic/collections/w3c/ddl, or
  http://www.zorba-xquery.com/modules/store/static/collections/ddl

  theColDMLNamespace:
  -------------------
  http://www.zorba-xquery.com/modules/store/dynamic/collections/dml, or
  http://www.zorba-xquery.com/modules/store/dynamic/collections/w3c/dml, or
  http://www.zorba-xquery.com/modules/store/static/collections/dml

********************************************************************************/
class CollectionManagerImpl : public virtual CollectionManager
{
protected:
  friend class XmlDataManagerImpl;
  friend class StaticCollectionManagerImpl;

protected:
  StaticContext_t          theContext;
  ItemFactory*             theFactory;
  std::string              theColDDLNamespace;
  std::string              theColDMLNamespace;

  DiagnosticHandler      * theDiagnosticHandler;

protected:
  CollectionManagerImpl(
      const StaticContext_t& aSctx,
      ItemFactory* aFactory,
      DiagnosticHandler* aDiagnosticHandler,
      const std::string& aDDLNS,
      const std::string& aDMLNS);

  void
  initStaticContext(StaticContext_t& aSctx);

  virtual void
  registerDiagnosticHandler(DiagnosticHandler* aDiagnosticHandler);

public:
  virtual void
  createCollection(const Item& aName);

  virtual void
  createCollection(const Item& aName, const ItemSequence_t& aContents);

  virtual void
  deleteCollection(const Item& aName);

  virtual Collection_t
  getCollection(const Item& aName) const;

  virtual ItemSequence_t
  availableCollections() const;

  virtual bool
  isAvailableCollection(const Item& aName) const;

  virtual ~CollectionManagerImpl();

}; /* class CollectionManagerImpl */

} /* namespace zorba */
#endif

/* vim:set et sw=2 ts=2: */
