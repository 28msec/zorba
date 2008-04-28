/**
 *
 */
#include <iostream>
#include <sstream>

#include <zorba/zorba.h>

using namespace zorba;

/**
 * Example to show the usage of the data manager in loading documents
 * for use in query exeution.
 */
bool
datamanager_example_1(Zorba* aZorba, XmlDataManager* aDataManager)
{
  try {
    std::stringstream lInStream("<books><book>Book 1</book><book>Book 2</book></books>");

    /* Load the document and call it books.xml */
    aDataManager->loadDocument("books.xml", lInStream);

    /* doc('books.xml') would find the document in the data manager. */
    XQuery_t lQuery = aZorba->compileQuery("doc('books.xml')//book"); 

    std::cout << lQuery << std::endl;
  } catch (ZorbaException& e) {
    std::cerr << e << std::endl;
    return false;
  }

	return true;
}

/**
 * Example to show the use of collections in query processing.
 */
bool
datamanager_example_2(Zorba* aZorba, XmlDataManager* aDataManager)
{
  try {
    /* Create a collection and give it a URI */
    Collection_t lCollection = 
      aDataManager->createCollection("http://www.flworfound.org/collections/mybooks");

    std::cout << "URI "  << lCollection->getUri().getStringValue() << std::endl;

    /* Populate the collection */
    for (int i = 0; i < 10; ++i) {
      std::stringstream lInStream;
      lInStream << "<book>Book " << i << "</book>";
      lCollection->addDocument(lInStream);
    }

    /* Compile the query */
    XQuery_t lQuery = aZorba->compileQuery("for $i in fn:collection()[3] return $i//book"); 

    /* Set the default collection to the one we created above */
    Item lDefaultCollection = aZorba->getItemFactory()
      ->createAnyURI("http://www.flworfound.org/collections/mybooks");
    lQuery->getDynamicContext()->setDefaultCollection(lDefaultCollection);

    std::cout << lQuery << std::endl;
  } catch (ZorbaException& e) {
    std::cerr << e << std::endl;
    return false;
  }

	return true;
}

/**
 * Example to show the use of erroneous documents in collections.
 */
bool
datamanager_example_3(Zorba* aZorba, XmlDataManager* aDataManager)
{
  try {
    Collection_t lCollection = 
      aDataManager->getCollection("http://www.flworfound.org/collections/mybooks");

    std::stringstream lInStream;
    lInStream << "<book>Book";
    /* We are trying to add a malformed document into the collection */
    lCollection->addDocument(lInStream);

  } catch (ZorbaException& e) {
    std::cerr << e << std::endl;
    return true;
  }

	return false;
}

/**
 * Example to show the definition of a new collection with a name, same as
 * a previously created collection. This is an error.
 */
bool
datamanager_example_4(Zorba* aZorba, XmlDataManager* aDataManager)
{
  try {
    // error if the collection already exists
    Collection_t lCollection = 
      aDataManager->createCollection("http://www.flworfound.org/collections/mybooks");

  } catch (ZorbaException& e) {
    std::cerr << e << std::endl;
    return true;
  }

	return false;
}

int 
datamanager(int argc, char* argv[])
{
#ifndef NDEBUG
  Zorba* lZorba = Zorba::getInstance();
  XmlDataManager* lDataManager = lZorba->getXmlDataManager();
  bool res = false;

  std::cout << "executing example 1" << std::endl;
  res = datamanager_example_1(lZorba, lDataManager);
  if (!res) return 1;
  std::cout << std::endl;

  std::cout << "executing example 2" << std::endl;
  res = datamanager_example_2(lZorba, lDataManager);
  if (!res) return 1;
  std::cout << std::endl;

  std::cout << "executing example 3" << std::endl;
  res = datamanager_example_3(lZorba, lDataManager);
  if (!res) return 1;
  std::cout << std::endl;

  std::cout << "executing example 4" << std::endl;
  res = datamanager_example_4(lZorba, lDataManager);
  if (!res) return 1;
  std::cout << std::endl;
#endif

    return 0;
}
