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

#include <iostream>
#include <sstream>

#include <zorba/zorba.h>
#include <zorba/store_manager.h>
#include <zorba/zorba_exception.h>
#include <zorba/iterator.h>
#include <zorba/singleton_item_sequence.h>
#include <zorba/serializer.h>

using namespace zorba;

/**
 * Example to show the usage of the data manager to
 * (1) parse a document,
 * (2) bind it in the store,
 * (3) access it using XQuer's doc() function,
 * (4) remove it afterwards, and
 * (5) make sure the document is removed.
 */
bool
xmldatamanager_example_1(Zorba* aZorba, XmlDataManager* aDataManager)
{
  try {

    // create a document in a temporary stream
    std::stringstream lInStream;
    lInStream
    << "<books>" << std::endl
    << "  <book>Book 1</book>" << std::endl
    << "  <book>Book 2</book>" << std::endl
    << "</books>";

    // (1) parse the document and return a item
    Item lDoc = aDataManager->parseXML(lInStream);

    // (2) bind the document in the store using the DocumentManager
    DocumentManager* lDocMgr = aDataManager->getDocumentManager();
    lDocMgr->put("books.xml", lDoc);

    // (3) doc('books.xml') accesses the previously found document
    XQuery_t lQuery = aZorba->compileQuery("doc('books.xml')//book"); 
    std::cout << lQuery << std::endl;

    // (4) remove the document binding from the store
    lDocMgr->remove("books.xml");

    // (5) verify that the document binding was actually removed 
    bool lAvailable = lDocMgr->isAvailableDocument("books.xml");
    if (lAvailable)
      return false;

  } catch (ZorbaException& e) {
    std::cerr << e << std::endl;
    return false;
  }

  return true;
}

/*
 * Example to show the usage of the collection manager to
 * (1) create a collection
 * (2) list available collections,
 * (3) delete a collection, and
 * (4) make sure the collection was removed.
 */
bool
xmldatamanager_example_2(Zorba* aZorba, XmlDataManager* aDataManager)
{
  try {
    CollectionManager* lColMgr = aDataManager->getCollectionManager();

    // name of the collection
    Item lColName = aZorba->getItemFactory()->createQName(
        "http://zorba.io/collections", "mybooks");

    // (1) create the collection
    lColMgr->createCollection(lColName);

    // (2) list available collections
    ItemSequence_t lSeq = lColMgr->availableCollections();
    Iterator_t lIter = lSeq->getIterator();
    lIter->open();
    while (lIter->next(lColName)) {
      std::cout << "collection " << lColName.getStringValue() << std::endl;
    }

    // (3) delete collection
    lColMgr->deleteCollection(lColName);

    // (4) make sure the collection was removed
    bool lAvailable = lColMgr->isAvailableCollection(lColName);
    if (lAvailable)
      return false;

  } catch (ZorbaException& e) {
    std::cerr << e << std::endl;
    return false;
  }

  return true;
}

/*
 * Example to show the usage of the collection manager to
 * (1) create a collection
 * (2) insert a node at the end of the collection,
 * (3) retrieve the annotations of a collection
 * (4) iterate over the contents of the collection,
 * (5) delete the node, and
 * (6) make sure the node was deleted.
 */
bool
xmldatamanager_example_3(Zorba* aZorba, XmlDataManager* aDataManager)
{
  try {
    CollectionManager* lColMgr = aDataManager->getCollectionManager();

    // name of the collection
    Item lColName = aZorba->getItemFactory()->createQName(
        "http://zorba.io/collections", "mybooks");

    // (1) create the collection
    lColMgr->createCollection(lColName);

    // create a document in a temporary stream
    std::stringstream lInStream;
    lInStream
    << "<books>" << std::endl
    << "  <book>Book 1</book>" << std::endl
    << "  <book>Book 2</book>" << std::endl
    << "</books>";

    Item lDoc = aDataManager->parseXML(lInStream);

    Collection_t lColl = lColMgr->getCollection(lColName);

    if (!lColl) {
      return false;
    }

    // (2) get the annotations of a collections
    std::vector<Annotation_t> lAnnotations;
    lColl->getAnnotations(lAnnotations);
    size_t num_annotations = 0;
    for (std::vector<Annotation_t>::const_iterator lIter = lAnnotations.begin();
        lIter != lAnnotations.end(); ++lIter)
    {
      std::cout << "Annotation QName "
          << (*lIter)->getQName().getStringValue() << std::endl;
      ++num_annotations;
    }

    if (num_annotations != 3)
    {
      return false;
    }


    // (3) insert a node at the end of the collection
    lColl->insertNodesLast(new SingletonItemSequence(lDoc));

    // (4) iterate over the contents of the collection 
    ItemSequence_t lContents = lColl->contents();
    Iterator_t lIter = lContents->getIterator();

    lIter->open();

    while (lIter->next(lDoc)) {
      std::cout << "node found at position "
          << lColl->indexOf(lDoc) << std::endl;
    }

    // (5) delete the node
    lColl->deleteNodeLast();

    // (6) make sure the node was deleted
    lIter->close();
    lIter->open();
    while (lIter->next(lDoc)) {
      return false;
    }

    lColMgr->deleteCollection(lColName);

  } catch (ZorbaException& e) {
    std::cerr << e << std::endl;
    return false;
  }

  return true;
}

/*
 * Example to show the usage of the collection manager for w3c-style collections to
 * (1) create a collection
 * (2) list available collections,
 * (3) delete a collection, and
 * (4) make sure the collection was removed.
 */
bool
xmldatamanager_example_4(Zorba* aZorba, XmlDataManager* aDataManager)
{
  try {
    CollectionManager* lColMgr = aDataManager->getW3CCollectionManager();

    // name of the collection
    Item lColName = aZorba->getItemFactory()->createString(
        "http://www.blub.com/");

    // (1) create the collection
    lColMgr->createCollection(lColName);

    // (2) list available collections
    ItemSequence_t lSeq = lColMgr->availableCollections();
    Iterator_t lIter = lSeq->getIterator();
    lIter->open();
    while (lIter->next(lColName)) {
      std::cout << "collection " << lColName.getStringValue() << std::endl;
    }

    // (3) delete collection
    lColMgr->deleteCollection(lColName);

    // (4) make sure the collection was removed
    bool lAvailable = lColMgr->isAvailableCollection(lColName);
    if (lAvailable)
      return false;

  } catch (ZorbaException& e) {
    std::cerr << e << std::endl;
    return false;
  }

  return true;
}

/*
 */
bool
xmldatamanager_example_5(Zorba* aZorba, XmlDataManager* aDataManager)
{
  try {
    std::stringstream lStream;
    lStream
    << "<book><title>XQuery From The Experts</title></book>"
    << "<book><title>XQuery Kick Start</title></book>"
    << "<book><title>Querying XML</title></book>";

    XmlDataManager::ParseOptions lOptions;
    lOptions.setExternalEntityProcessing(true);

    ItemSequence_t lSeq = aDataManager->parseXML(lStream, lOptions);
    Iterator_t lIter = lSeq->getIterator();
    lIter->open();
    Item lItem;
    while (lIter->next(lItem)) {
      std::cout << "element " << lItem.getStringValue() << std::endl;
    }

  } catch (ZorbaException& e) {
    std::cerr << e << std::endl;
    return false;
  }
  return true;
}

int 
xmldatamanager(int argc, char* argv[])
{
  void* lStore = zorba::StoreManager::getStore();
  Zorba* lZorba = Zorba::getInstance(lStore);
  XmlDataManager_t lDataManager = lZorba->getXmlDataManager();
  bool res = false;

  std::cout << "executing example 1" << std::endl;
  res = xmldatamanager_example_1(lZorba, lDataManager);
  if (!res) return 1;
  std::cout << std::endl;

  std::cout << "executing example 2" << std::endl;
  res = xmldatamanager_example_2(lZorba, lDataManager);
  if (!res) return 2;
  std::cout << std::endl;

  std::cout << "executing example 3" << std::endl;
  res = xmldatamanager_example_3(lZorba, lDataManager);
  if (!res) return 3;
  std::cout << std::endl;

  std::cout << "executing example 4" << std::endl;
  res = xmldatamanager_example_4(lZorba, lDataManager);
  if (!res) return 4;
  std::cout << std::endl;

  std::cout << "executing example 5" << std::endl;
  res = xmldatamanager_example_5(lZorba, lDataManager);
  if (!res) return 5;
  std::cout << std::endl;

  lZorba->shutdown();
  zorba::StoreManager::shutdownStore(lStore);
  return 0;
}
