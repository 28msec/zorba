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
#include "stdafx.h"

#include "simple_store.h"
#include "store_defs.h"

#include "simple_collection.h"
#include "simple_collection_set.h"
#include "simple_item_factory.h"
#include "simple_iterator_factory.h"
#include "node_factory.h"
#include "pul_primitive_factory.h"

#include "diagnostics/zorba_exception.h"
#include "diagnostics/diagnostic.h"
#include <zorba/diagnostic_list.h>

namespace zorba
{

namespace simplestore
{

typedef rchandle<store::TempSeq> TempSeq_t;

/*******************************************************************************

********************************************************************************/
SimpleStore::SimpleStore()
{
}


/*******************************************************************************

********************************************************************************/
SimpleStore::~SimpleStore()
{
  shutdown(false);
}

/*******************************************************************************

*******************************************************************************/
PULPrimitiveFactory*
SimpleStore::createPULFactory() const
{
  return new PULPrimitiveFactory();
}

/*******************************************************************************

*******************************************************************************/
void
SimpleStore::destroyPULFactory(PULPrimitiveFactory* f) const
{
  delete f;
}

/*******************************************************************************

*******************************************************************************/
CollectionSet* SimpleStore::createCollectionSet() const
{
  return new SimpleCollectionSet();
}

/*******************************************************************************

*******************************************************************************/
void SimpleStore::destroyCollectionSet(CollectionSet* c) const
{
  delete c;
}

/*******************************************************************************

*******************************************************************************/
NodeFactory* SimpleStore::createNodeFactory() const
{
  return new NodeFactory();
}

/*******************************************************************************

*******************************************************************************/
void SimpleStore::destroyNodeFactory(NodeFactory* f) const
{
  delete f;
}

/*******************************************************************************

*******************************************************************************/
BasicItemFactory* SimpleStore::createItemFactory() const
{
  return new BasicItemFactory(theNamespacePool, theQNamePool);
}

/*******************************************************************************

*******************************************************************************/
void SimpleStore::destroyItemFactory(BasicItemFactory* f) const
{
  delete f;
}

/*******************************************************************************

*******************************************************************************/
store::IteratorFactory* SimpleStore::createIteratorFactory() const
{
  return new SimpleIteratorFactory();
}

/*******************************************************************************

*******************************************************************************/
void SimpleStore::destroyIteratorFactory(store::IteratorFactory* f) const
{
  delete f;
}

/*******************************************************************************
  create a tree id for a new tree that does not belong to any collection.
********************************************************************************/
ulong SimpleStore::createTreeId()
{
  SYNC_CODE(AutoMutex lock(&theTreeCounterMutex);)
  return theTreeCounter++;
}

/*******************************************************************************
  Create a collection with a given QName and return an rchandle to the new
  collection object. If a collection with the given QName exists already, raise
  an error.
********************************************************************************/
store::Collection_t SimpleStore::createCollection(
    const store::Item_t& aName,
    const std::vector<store::Annotation_t>& annotations,
    const store::Item_t& aNodeType,
    bool aDynamicCollection)
{
  if (aName == NULL)
    return NULL;

  store::Collection_t collection(
      new SimpleCollection(
        aName,
        annotations,
        aNodeType,
        aDynamicCollection));

  const store::Item* lName = collection->getName();

  bool inserted = theCollections->insert(lName, collection);

  if (!inserted)
  {
    throw ZORBA_EXCEPTION(zerr::ZSTR0008_COLLECTION_ALREADY_EXISTS,
    ERROR_PARAMS(lName->getStringValue()));
  }

  return collection;
}


} // namespace simplestore
} // namespace zorba
