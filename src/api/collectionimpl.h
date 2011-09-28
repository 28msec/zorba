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
#pragma once
#ifndef ZORBA_API_COLLECTIONIMPL
#define ZORBA_API_COLLECTIONIMPL

#include "common/shared_types.h"
#include <zorba/collection.h>

namespace zorba {


/*******************************************************************************

  A CollectionImpl obj can be used to do dml kind of operations on an underlying
  store collection, which may be a zorba static collection, a zorba dynamic 
  collection, or a w3c collection. Instances of CollectionImpl are obtained via
  the CollectionManagerImpl::getCollection method. However, the instances are
  NOT owned by the CollectionManager who created them.

  theContext:
  -----------
  A StaticContext obj that is created as a child of the StaticContext obj owned
  by the CollectionManagerImpl that created "this". A child context is required
  because the CollectionImpl constructor will do a loadProlog on this child in
  order to import the module identified by theNS.

  theFactory:
  -----------
  The singleton ItemFactory obj.

  theQName:
  ---------
  The QName of the collection.

  theNS:
  ------
  One of the following:
  http://www.zorba-xquery.com/modules/store/dynamic/collections/dml, or
  http://www.zorba-xquery.com/modules/store/dynamic/collections/w3c/dml, or
  http://www.zorba-xquery.com/modules/store/static/collections/dml

  theDiagnosticHandler:
  ---------------------
  Initialized (during construction) to the same as theDiagnosticHandler of 
  the CollectionManagerImpl obj from which "this" is being created.
********************************************************************************/
class CollectionImpl : public Collection
{
 protected:
  friend class Unmarshaller;
  friend class CollectionManagerImpl;

protected:
  StaticContext_t      theContext;
  ItemFactory        * theFactory;
  Item                 theQName;
  DiagnosticHandler  * theDiagnosticHandler;
  std::string          theNS;

protected:
  CollectionImpl(
      const StaticContext_t& aSctx,
      ItemFactory* aFactory,
      const Item& aQName,
      DiagnosticHandler* aDiagnosticHandler,
      const std::string& aDMLNamespace);

  void
  initStaticContext();

  void
  invoke(
      const char* aLocalName,
      const std::vector<ItemSequence_t>& aArgs) const;

 public:
  virtual ~CollectionImpl();

  virtual void
  registerDiagnosticHandler(DiagnosticHandler* aDiagnosticHandler);

  virtual void
  insertNodesFirst(const ItemSequence_t& aNodes);
  
  virtual void
  insertNodesLast(const ItemSequence_t& aNodes);
  
  virtual void
  insertNodesBefore(const Item& aTarget, const ItemSequence_t& aNodes);
  
  virtual void
  insertNodesAfter(const Item& aTarget, const ItemSequence_t& aNodes);
  
  virtual void
  deleteNodes(const ItemSequence_t& aNodes);
  
  virtual void
  deleteNodeFirst();
  
  virtual void
  deleteNodesFirst(unsigned long aNumNodes);
  
  virtual void
  deleteNodeLast();
  
  virtual void
  deleteNodesLast(unsigned long aNumNodes);
  
  virtual long long
  indexOf(const Item& aNode);
  
  virtual ItemSequence_t
  contents();

  virtual const Item
  getName() const;

  virtual void
  getAnnotations(std::vector<Annotation_t>& aAnnotations) const;

  virtual bool
  isStatic() const;

  virtual TypeIdentifier_t
  getType() const;
  
}; /* class CollectionImpl */


} /* namespace zorba */

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
