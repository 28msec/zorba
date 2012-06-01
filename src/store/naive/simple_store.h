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
#ifndef ZORBA_SIMPLE_STORE
#define ZORBA_SIMPLE_STORE

#include "store/naive/store.h"

#include "store/naive/node_factory.h"
#include "store/naive/pul_primitive_factory.h"
#include "store/naive/tree_id_generator.h"

namespace zorba {
namespace simplestore {


/*******************************************************************************

  theCollectionCounter:
  ---------------------
  Incremented every time a new collection is created. The current value of the  
  counter is then assigned as the id of the new collection.

  theReferencesToNodeMap:
  -----------------------
  A hashmap that maps node references to the referenced nodes

  theNodeToReferencesMap:
  -----------------------
  A hashmap that maps nodes into their references
  
********************************************************************************/
class SimpleStore : public Store
{
  friend class zorba::StoreManager;

  typedef std::map<const zstring, const store::Item*> RefNodeMap;
  typedef NodePointerHashMap<zstring> NodeRefMap;

private:
  ulong                         theCollectionCounter;
  SYNC_CODE(Mutex               theCollectionCounterMutex;)

  RefNodeMap                    theReferencesToNodeMap;
  NodeRefMap                    theNodeToReferencesMap;

public:
  ulong createCollectionId();

  store::Collection_t createCollection(
      const store::Item_t& aName,
      const std::vector<store::Annotation_t>& annotations,
      const store::Item_t& aNodeType,
      bool aDynamicCollection = false);

protected:
  SimpleStore();

  virtual ~SimpleStore();
  
  void init();
  
  void shutdown(bool soft);

  NodeFactory* createNodeFactory() const;

  void destroyNodeFactory(zorba::simplestore::NodeFactory*) const;

  store::ItemFactory* createItemFactory() const;

  void destroyItemFactory(store::ItemFactory*) const;

  store::IteratorFactory* createIteratorFactory() const;

  void destroyIteratorFactory(store::IteratorFactory*) const;

  PULPrimitiveFactory* createPULFactory() const;

  void destroyPULFactory(zorba::simplestore::PULPrimitiveFactory*) const;

  CollectionSet* createCollectionSet() const;

  void destroyCollectionSet(CollectionSet*) const;
      
  TreeIdGeneratorFactory* createTreeIdGeneratorFactory() const;

  void destroyTreeIdGeneratorFactory(TreeIdGeneratorFactory* g) const;

  bool unregisterNode(XmlNode* node);

  //
  // Store api methods
  //

  bool getNodeReference(store::Item_t& result, const store::Item* node);

  bool hasReference(const store::Item* node);

  bool getNodeByReference(
      store::Item_t& result,
      const zstring& reference);
};

} // namespace store
} // namespace zorba

#endif /* ZORBA_STORE_SIMPLE_STORE_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
