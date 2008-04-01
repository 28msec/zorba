/**
 *
 */
#include <iostream>
#include <sstream>

#include <zorba/zorba.h>

using namespace zorba;

bool
datamanager_example_1(Zorba* aZorba, XmlDataManager* aDataManager)
{

  std::stringstream lInStream("<books><book>Book 1</book><book>Book 2</book></books>");

  aDataManager->loadDocument("books.xml", lInStream);

	XQuery_t lQuery = aZorba->compileQuery("doc('books.xml')//book"); 

  std::cout << lQuery << std::endl;

	return true;
}


int 
datamanager(int argc, char* argv[])
{
  Zorba* lZorba = Zorba::getInstance();
  XmlDataManager* lDataManager = lZorba->getXmlDataManager();

  std::cout << "executing example 1" << std::endl;
	assert(datamanager_example_1(lZorba, lDataManager)); 
  std::cout << std::endl;

  
  return 0;
}
