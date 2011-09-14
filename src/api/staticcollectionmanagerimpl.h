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

/*******************************************************************************

  A StaticCollectionManager is used to manage the static collections whose
  declaration is reachable from a particular static_context obj S. 

  Instances of StaticCollectionManager are obtained via :

  (a) the StaticContext::getStaticCollectionManager() method. In this case,
  "this" is owned by the StaticContext obj SW on which getStaticCollectionManager
  was invoked, and it manages the static collections of the static_context 
  obj S that is wrapped by SW.

  (b) the XqueryImpl::getStaticCollectionManager() method. This method creates 
  one StaticCollectionManagerImpl for each static_context obj S found in 
  theSctMap of the Xquery obj. Each of these StaticCollectionManagerImpl objs
  is owned by the StaticCollectionManagerSetImpl that is also created by the
  same method and it manages the static collections of the associated S obj.

  theFactory:
  -----------
  The singleton ItemFactory obj.

  theContext:
  -----------
  A StaticContext obj that wraps a child of the static_context obj S whose 
  static collections are managed by "this". A child of S is created because
  a loadProlog is performed on the child to import theColDMLNamespace module.

  theCollMgr:
  -----------
  A CollectionManager obj that is owned by "this" and to which many of the 
  methods of "this" are propagated to. The CollectionManager obj is created 
  during the construction of "this".

  theDiagnosticHandler:
  ---------------------
  The DiagnosticHandler to use for handling errors raised during the execution
  of the methods of this StaticCollectionManager. It is the same as the one used
  by the owner of "this", i.e. the StaticContext obj SW in case (a) above, or
  the XQuery obj in case (b).
********************************************************************************/
class StaticCollectionManagerImpl : public StaticCollectionManager
{
protected:
  friend class StaticContextImpl;
  friend class StaticCollectionManagerSetImpl;
  friend class XQueryImpl;

protected:
  ItemFactory            * theFactory;
  std::string              theColDDLNamespace;
  std::string              theColDMLNamespace;
  
  StaticContext_t          theContext;
  CollectionManagerImpl*   theCollMgr;
  
  DiagnosticHandler      * theDiagnosticHandler;

protected:
  StaticCollectionManagerImpl(
      const StaticContextImpl* aModuleSctxSet,
      ItemFactory* aFactory,
      DiagnosticHandler* aDiagnosticHandler);

  void
  initStaticContext(StaticContext_t& aCtx);
  
  void
  registerDiagnosticHandler(DiagnosticHandler* aDiagnosticHandler);

public:
  virtual ~StaticCollectionManagerImpl();

  virtual void
  createCollection(const Item& aQName);

  virtual void
  createCollection(const Item& aQName, const ItemSequence_t& aContents);

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

}; /* class StaticCollectionManagerImpl */


/*******************************************************************************
  A StaticCollectionManagerSet is used to manage the static collections whose
  declaration is reachable by the static_context objs associated with the any
  of the modules that participate in a query. Let SS be the set of these
  static_context objs.

  Instances of StaticCollectionManager are obtained via the 
  XqueryImpl::getStaticCollectionManager() method.

  theMgrs:
  --------
  For each static_context obj S in SS, a StaticCollectionManager obj is created
  to manage the static collections of S. theMgrs is a vector the stores all these 
  StaticCollectionManager objs.

********************************************************************************/
class StaticCollectionManagerSetImpl : public StaticCollectionManager
{
protected:
  friend class XQueryImpl;

  typedef std::vector<StaticCollectionManagerImpl*>  MgrSet;

protected:
  MgrSet  theMgrs;

protected:
  StaticCollectionManagerSetImpl(MgrSet&);

  void
  registerDiagnosticHandler(DiagnosticHandler* aDiagnosticHandler);

public:
  virtual ~StaticCollectionManagerSetImpl();

  virtual void
  createCollection(const Item& aQName);

  virtual void
  createCollection(const Item& aQName, const ItemSequence_t& aContents);

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

}; /* class StaticCollectionManagerSetImpl */


} /* namespace zorba */
#endif


/* vim:set et sw=2 ts=2: */
