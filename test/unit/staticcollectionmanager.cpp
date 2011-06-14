#include <cassert>
#include <fstream>

#include <zorba/store_manager.h>
#include <zorba/zorba.h>
#include <zorba/xquery.h>
#include <zorba/xquery_exception.h>
#include <zorba/serializer.h>
#include <zorba/item_sequence.h>
#include <zorba/singleton_item_sequence.h>
#include <zorba/staticcollectionmanager.h>

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

  if (!lColMgr->isDeclaredCollection(lCollName2) ||
      !lColMgr->isDeclaredCollection(lCollName3)) {
    return false;
  }

  lColMgr->createCollection(lCollName2);
  lColMgr->createCollection(lCollName3);

  if (!lColMgr->isAvailableCollection(lCollName2) ||
      !lColMgr->isAvailableCollection(lCollName3)) {
    return false;
  }

  lColMgr->deleteCollection(lCollName2);
  lColMgr->deleteCollection(lCollName3);

  if (lColMgr->isAvailableCollection(lCollName2) ||
      lColMgr->isAvailableCollection(lCollName3)) {
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
  Item lCollName2 = lFac->createQName("http://www.mod4.com/", "coll");

  lColMgr->createCollection(lCollName2);

  Collection_t lCollection = lColMgr->getCollection(lCollName2);

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

  if (num_nodes != 8) {
    return false;
  }


  return true;
}


int
staticcollectionmanager(int argc, char* argv[])
{
  void* store = zorba::StoreManager::getStore();
  zorba::Zorba* z = zorba::Zorba::getInstance(store);

  std::cout << "executing example 1" << std::endl;
  if (!staticcollectionamanger1(z))
    return 1;
  std::cout << std::endl;

  std::cout << "executing example 2" << std::endl;
  if (!staticcollectionamanger2(z))
    return 2;
  std::cout << std::endl;

  return 0;
}

/* vim:set et sw=2 ts=2: */
