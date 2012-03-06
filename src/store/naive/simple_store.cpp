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

#include <iostream>
#include <climits>
#include <memory>

#include <libxml/parser.h>

#include "zorbautils/hashfun.h"
#include "zorbautils/fatal.h"
#include "zorbatypes/rchandle.h"
#include "diagnostics/xquery_diagnostics.h"
#include "diagnostics/assert.h"
#include "diagnostics/util_macros.h"

#include "store/api/pul.h"
#include "store/api/xs_type_codes.h"

#include "properties.h"
#include "string_pool.h"
#include "simple_store.h"
#include "simple_temp_seq.h"
#include "simple_lazy_temp_seq.h"
#include "simple_collection.h"
#include "simple_collection_set.h"
#include "simple_index.h"
#include "simple_index_value.h"
#include "simple_index_general.h"
#include "simple_ic.h"
#include "qname_pool.h"
#include "loader.h"
#include "store_defs.h"
#include "node_items.h"
#include "dataguide.h"
#include "node_iterators.h"
#include "simple_item_factory.h"
#include "simple_iterator_factory.h"
#include "query_context.h"
#include "item_iterator.h"
#include "node_factory.h"
#include "name_iterator.h"
#include "document_name_iterator.h"
#include "pul_primitive_factory.h"

#include "util/cxx_util.h"
#include "util/uuid/uuid.h"
#include "zorbautils/string_util.h"

#ifndef ZORBA_NO_FULL_TEXT
#include "runtime/full_text/default_tokenizer.h"
#include "runtime/full_text/stemmer.h"
#endif /* ZORBA_NO_FULL_TEXT */

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
}

/*******************************************************************************

*******************************************************************************/
PULPrimitiveFactory*
SimpleStore::createPULPrimitiveFactory() const
{
  return new PULPrimitiveFactory();
}


/*******************************************************************************

*******************************************************************************/
CollectionSet* SimpleStore::createCollectionSet() const
{
  return new SimpleCollectionSet();
}


/*******************************************************************************

*******************************************************************************/
NodeFactory* SimpleStore::createNodeFactory() const
{
  return new NodeFactory();
}


/*******************************************************************************

*******************************************************************************/
BasicItemFactory* SimpleStore::createItemFactory() const
{
  return new BasicItemFactory(theNamespacePool, theQNamePool);
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
  Refreshes an index with a given URI and return an rchandle to the index object.
  If an index with the given URI exists already and the index we want to create
  is not a temporary one, raise an error.
********************************************************************************/
store::Index_t SimpleStore::refreshIndex(
    const store::Item_t& qname,
    const store::IndexSpecification& spec,
    store::Iterator* sourceIter)
{
  store::Index_t index;
  store::Item* non_const_items = const_cast<store::Item*>(qname.getp());

  if (!theIndices.get(non_const_items, index))
  {
    throw ZORBA_EXCEPTION(
      zerr::ZSTR0002_INDEX_DOES_NOT_EXIST,
      ERROR_PARAMS( qname->getStringValue() )
    );
  }

  deleteIndex(qname);

  try
  {
    createIndex(qname, index->getSpecification(), sourceIter);
  }
  catch (...)
  {
    addIndex(index);
    throw;
  }

  return index;
}

/*******************************************************************************

********************************************************************************/
void SimpleStore::addIndex(store::Index_t& index)
{
  if (index == NULL)
    return;

  store::Item* qname = const_cast<store::Item*>(index->getName());

  theIndices.insert(qname, index);
}

/*******************************************************************************

********************************************************************************/
void SimpleStore::deleteIndex(const store::Item* qname)
{
  if (qname == NULL)
    return;

  store::Item* qname2 = const_cast<store::Item*>(qname);

  theIndices.erase(qname2);
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
