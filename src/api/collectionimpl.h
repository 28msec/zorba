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

class CollectionImpl : public Collection
{
 protected:
  friend class Unmarshaller;

  StaticContext_t theContext;
  ItemFactory*    theFactory;
  Item            theQName;
  DiagnosticHandler   * theDiagnosticHandler;
  std::string     theNS;

 protected:
  void
  initStaticContext();

  void
  invoke(
      const char* aLocalName,
      const std::vector<ItemSequence_t>& aArgs) const;

  friend class CollectionManagerImpl;
  CollectionImpl(
      const StaticContext_t& aSctx,
      ItemFactory* aFactory,
      const Item& aQName,
      DiagnosticHandler* aDiagnosticHandler,
      const std::string& aDMLNamespace);

 public:
  virtual ~CollectionImpl();

  virtual void
  insertNodesFirst(const ItemSequence_t& aNodes);
  
  virtual void
  insertNodesLast(const ItemSequence_t& aNodes);
  
  virtual void
  insertNodesBefore(
      const Item& aTarget,
      const ItemSequence_t& aNodes);
  
  virtual void
  insertNodesAfter(
      const Item& aTarget,
      const ItemSequence_t& aNodes);
  
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

  virtual void
  registerDiagnosticHandler(DiagnosticHandler* aDiagnosticHandler);
  
}; /* class CollectionImpl */


} /* namespace zorba */

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
