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

#include "store.h"
namespace zorba {
namespace simplestore {

class SimpleStore : public Store
{
public:
  ulong createTreeId();

  store::Collection_t createCollection(
      const store::Item_t& aName,
      const std::vector<store::Annotation_t>& annotations,
      const store::Item_t& aNodeType,
      bool aDynamicCollection = false);

  // needs to be virtual to allow implementation of additional stores
  virtual store::Index_t refreshIndex(
      const store::Item_t& qname,
      const store::IndexSpecification& spec,
      store::Iterator* sourceIter);

  void addIndex(store::Index_t& index);

  void deleteIndex(const store::Item* qname);

protected:
  virtual NodeFactory* createNodeFactory() const;

  virtual BasicItemFactory* createItemFactory() const;

  virtual PULPrimitiveFactory* createPULPrimitiveFactory() const;

  virtual CollectionSet* createCollectionSet() const;

protected:
  friend class zorba::StoreManager;
  SimpleStore();

  virtual ~SimpleStore();
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
