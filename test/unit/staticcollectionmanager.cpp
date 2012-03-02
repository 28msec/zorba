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
#include <cassert>
#include <fstream>

#include <zorba/store_manager.h>
#include <zorba/zorba.h>
#include <zorba/xquery.h>
#include <zorba/xquery_exception.h>
#include <zorba/serializer.h>
#include <zorba/item_sequence.h>
#include <zorba/singleton_item_sequence.h>
#include <zorba/static_collection_manager.h>

#include "system/properties.h"

using namespace zorba;

bool
staticcollectionamanger1(zorba::Zorba* z)
{
  std::ifstream lIn("module1.xq");

  zorba::XQuery_t lQuery = z->createQuery();
  Zorba_CompilerHints lHints;
  lQuery->compile(lIn, lHints);

  StaticCollectionManager* lColMgr = lQuery->getStaticCollectionManager();

  ItemFactory* lFac = z->getItemFactory();
  Item lCollName2 = lFac->createQName("http://www.mod2.com/", "coll");
  Item lIdxName   = lFac->createQName("http://www.mod2.com/", "index");
  Item lCollName3 = lFac->createQName("http://www.mod3.com/", "coll");

  ItemSequence_t lSeq = lColMgr->declaredCollections();
  Iterator_t lIter = lSeq->getIterator();
  lIter->open();
  Item lTmp;
  int num_colls = 0;
  while (lIter->next(lTmp)) {
    std::cout << "name " << lTmp.getStringValue() << std::endl;
    ++num_colls;
  }
  
  if (num_colls != 2) {
    return false;
  }

  int num_idxs = 0;
  lSeq = lColMgr->declaredIndexes();
  lIter = lSeq->getIterator();
  lIter->open();
  while (lIter->next(lTmp)) {
    std::cout << "name " << lTmp.getStringValue() << std::endl;
    ++num_idxs;
  }

  if (num_idxs != 1) {
    return false;
  }

  if (!lColMgr->isDeclaredCollection(lCollName2) ||
      !lColMgr->isDeclaredCollection(lCollName3)) {
    return false;
  }

  if (!lColMgr->isDeclaredIndex(lIdxName)) {
    return false;
  }

  lColMgr->createCollection(lCollName2);
  lColMgr->createCollection(lCollName3);
  lColMgr->createIndex(lIdxName);

  if (!lColMgr->isAvailableCollection(lCollName2) ||
      !lColMgr->isAvailableCollection(lCollName3) ||
      !lColMgr->isAvailableIndex(lIdxName)) {
    return false;
  }

  ItemSequence_t lAvailableColls = lColMgr->availableCollections();
  lIter = lAvailableColls->getIterator();
  lIter->open();
  num_colls = 0;
  while (lIter->next(lTmp)) {
    std::cout << "name " << lTmp.getStringValue() << std::endl;
    ++num_colls;
  }
  
  if (num_colls != 2) {
    return false;
  }

  lColMgr->deleteIndex(lIdxName);
  lColMgr->deleteCollection(lCollName2);
  lColMgr->deleteCollection(lCollName3);

  if (lColMgr->isAvailableCollection(lCollName2) ||
      lColMgr->isAvailableCollection(lCollName3) ||
      lColMgr->isAvailableIndex(lIdxName)) {
    return false;
  }

  return true;
}

bool
staticcollectionamanger2(zorba::Zorba* z)
{
  std::ifstream lIn("module1.xq");

  zorba::XQuery_t lQuery = z->createQuery();
  Zorba_CompilerHints lHints;
  lQuery->compile(lIn, lHints);

  StaticCollectionManager* lColMgr = lQuery->getStaticCollectionManager();

  ItemFactory* lFac = z->getItemFactory();
  Item lCollName2 = lFac->createQName("http://www.mod2.com/", "coll");

  lColMgr->createCollection(lCollName2);

  Collection_t lCollection = lColMgr->getCollection(lCollName2);

  std::vector<Annotation_t> lAnnotations;
  lCollection->getAnnotations(lAnnotations);
  size_t num_annotations = 0;
  for (std::vector<Annotation_t>::const_iterator lIter = lAnnotations.begin();
       lIter != lAnnotations.end(); ++lIter)
  {
    std::cout << "Annotation QName " << (*lIter)->getQName().getStringValue() << std::endl;
    ++num_annotations;
  }

  if (num_annotations != 3)
  {
    return false;
  }

  if (lCollection->getType()->getKind() != IdentTypes::ANY_NODE_TYPE)
  {
    return false;
  }

  std::stringstream lInStream;
  lInStream
    << "<books>" << std::endl
    << "  <book>Book 1</book>" << std::endl
    << "  <book>Book 2</book>" << std::endl
    << "</books>";

  Item lDoc = z->getXmlDataManager()->parseXML(lInStream);

  for (size_t i = 0; i < 10; ++i) {
    lCollection->insertNodesLast(new SingletonItemSequence(lDoc));
  }

  lCollection->deleteNodesLast(2);

  ItemSequence_t lContents = lCollection->contents();
  Iterator_t lIter = lContents->getIterator();
  size_t num_nodes = 0;
  lIter->open();
  while (lIter->next(lDoc)) {
    ++num_nodes;
  }
  lIter->close();

  if (num_nodes != 8) {
    return false;
  }

  lDoc = NULL;
  lColMgr->deleteCollection(lCollName2);

  return true;
}

bool
staticcollectionamanger3(zorba::Zorba* z)
{
  std::ifstream lIn("module1.xq");

  zorba::XQuery_t lQuery = z->createQuery();
  Zorba_CompilerHints lHints;
  lQuery->compile(lIn, lHints);

  const StaticContext* lSctx = lQuery->getStaticContext();

  StaticCollectionManager* lColMgr = lSctx->getStaticCollectionManager();

  ItemFactory* lFac = z->getItemFactory();
  Item lCollName2 = lFac->createQName("http://www.mod2.com/", "coll");
  
  lColMgr->createCollection(lCollName2);

  {
    Collection_t lColl = lColMgr->getCollection(lCollName2);
    std::vector<Annotation_t> lAnnotations;
    lColl->getAnnotations(lAnnotations);
    size_t num_annotations = 0;
    for (std::vector<Annotation_t>::const_iterator lIter = lAnnotations.begin();
         lIter != lAnnotations.end(); ++lIter)
    {
      std::cout << "Annotation QName " << (*lIter)->getQName().getStringValue() << std::endl;
      ++num_annotations;
    }

    if (num_annotations != 3)
    {
      return false;
    }
  }

  lColMgr->deleteCollection(lCollName2);

  return true;
}


bool
staticcollectionamanger4(zorba::Zorba* z)
{
  std::ifstream lIn("main_invoke.xq");
  assert(lIn.good());

  zorba::XQuery_t lQuery = z->createQuery();
  Zorba_CompilerHints lHints;
  lQuery->compile(lIn, lHints);

  size_t i = 0;

  StaticCollectionManager* lMgr = lQuery->getStaticCollectionManager();

  zorba::ItemSequence_t lSeq = lMgr->declaredCollections();
  zorba::Iterator_t lIter = lSeq->getIterator();
  lIter->open();
  zorba::Item lName;
  while (lIter->next(lName))
  {
    if (!lMgr->isAvailableCollection(lName))
    {
      lMgr->createCollection(lName);
      std::cout << "created collection " << lName.getStringValue() << std::endl;
      ++i;
    }
  }

  return i == 1;
}

(: test that declaredIndexes doesn't return temporary indexes and crashes
 : if one tries to create one :)
bool
staticcollectionamanger5(zorba::Zorba* z)
{
  std::ifstream lIn("module1.xq");

  zorba::XQuery_t lQuery = z->createQuery();
  Zorba_CompilerHints lHints;
  lQuery->compile(lIn, lHints);

  StaticCollectionManager* lColMgr = lQuery->getStaticCollectionManager();

  ItemFactory* lFac = z->getItemFactory();
  Item lCollName2 = lFac->createQName("http://www.mod2.com/", "coll");
  Item lIdxName   = lFac->createQName("http://www.mod2.com/", "index");
  Item lCollName3 = lFac->createQName("http://www.mod3.com/", "coll");

  ItemSequence_t lSeq = lColMgr->declaredCollections();
  Iterator_t lIter = lSeq->getIterator();
  lIter->open();
  Item lTmp;
  while (lIter->next(lTmp)) {
    std::cout << "name " << lTmp.getStringValue() << std::endl;
    lColMgr->createCollection(lTmp);
  }
  
  lSeq = lColMgr->declaredIndexes();
  lIter = lSeq->getIterator();
  lIter->open();
  while (lIter->next(lTmp)) {
    std::cout << "name " << lTmp.getStringValue() << std::endl;
    lColMgr->createIndex(lTmp);
  }

  return true;
}

int
staticcollectionmanager(int argc, char* argv[])
{
  void* store = zorba::StoreManager::getStore();
  zorba::Zorba* z = zorba::Zorba::getInstance(store);

  zorba::Properties::load(0, NULL);

  std::cout << "executing example 1" << std::endl;
  if (!staticcollectionamanger1(z))
    return 1;
  std::cout << std::endl;

  std::cout << "executing example 2" << std::endl;
  if (!staticcollectionamanger2(z))
    return 2;
  std::cout << std::endl;

  std::cout << "executing example 3" << std::endl;
  if (!staticcollectionamanger3(z))
    return 3;
  std::cout << std::endl;

  std::cout << "executing example 4" << std::endl;
  if (!staticcollectionamanger4(z))
    return 4;
  std::cout << std::endl;

  std::cout << "executing example 5" << std::endl;
  if (!staticcollectionamanger5(z))
    return 5;
  std::cout << std::endl;

  return 0;
}

/* vim:set et sw=2 ts=2: */
