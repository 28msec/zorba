
#include <fstream>

#include "timer.h"

#include "errors/error_factory.h"
#include "store/naive/atomic_items.h"
#include "store/naive/simple_store.h"
#include "store/naive/simple_collection.h"
#include "store/naive/qname_pool.h"
#include "store/naive/simple_loader.h"

#include "zorba_api.h"
#include "store/naive/basic_item_factory.h"

using namespace xqp;

#ifdef _DEBUG
extern const char*		xqp::g_error_in_file;
extern int						xqp::g_error_at_line;
#endif


void readXmlFile(const char* fileName, std::string& xmlString)
{
  std::ifstream xmlFile(fileName);
  if(!xmlFile)
  {
    std::cerr << "Error while opening: " << fileName << std::endl;
    abort();
  }

  xmlString.clear();

  char delim = '\n';

  while (xmlFile)
  {
    std::string tmp;
    getline(xmlFile, tmp, delim);
    xmlString += tmp;
    xmlString += delim;
  }
  xmlFile.close();
}


int main(int argc, const char * argv[])
{
	// xqp::LoggerManager::logmanager()->setLoggerConfig("#1#logging.log");

  if (argc < 2)
  {
    std::cerr << "usage: test_store <input file name>" << std::endl;
  }

  std::string fileName(argv[1]);

  //
  // Store initialization
  //
  xqp::SimpleStore* store = static_cast<xqp::SimpleStore*>(&xqp::Store::getInstance());

  //
  // Zorba initialization
  // 
  ZorbaEngine_t zorba_factory = ZorbaEngine::getInstance();

	zorba_factory->initThread();

	ZorbaAlertsManager_t errmanager = zorba_factory->getAlertsManagerForCurrentThread();

  //
  // Create collections
  //
  xqp::Collection_t coll1;
  xqp::Collection_t coll2;

  try
  {
    coll1 = store->createCollection("http://MyCollection1");

    std::cout << coll1->getUri()->show() << std::endl;

    coll2 = store->createCollection("http://MyCollection1");
  }
  catch (xqp_exception& e)
  {
    std::cerr << e;
    abort();
  }

	errmanager->dumpAlerts(std::cerr);

  //
  // Load an xml doc from a file to a collection
  //

  std::ifstream xmlFile(fileName.c_str());
  if(!xmlFile)
  {
    std::cerr << "Error while opening: " << fileName << std::endl;
    abort();
  }

  std::iostream xmlStream(xmlFile.rdbuf());
  Item_t doc;

#ifndef WIN32
	Timer timer;
	timer.start();
#endif

  try
  {
    doc = coll1->addToCollection(xmlStream);
  }
  catch (xqp_exception& e)
  {
    std::cerr << e;
    abort();
  }

#ifndef WIN32
  timer.suspend();
  std::cout << "Loading time : " << timer.getTime() << std::endl;
  timer.resume();
#endif

  xmlFile.close();

  store->deleteCollection(coll1->getUri()->getStringValue());

  fileName += ".res";
  std::ofstream outXmlFile(fileName.c_str());
  if(!outXmlFile)
  {
    std::cerr << "Error while opening: " << fileName << std::endl;
    abort();
  }

  if (doc != NULL)
    outXmlFile << doc->show() << std::endl;
  else
    errmanager->dumpAlerts(outXmlFile);

  errmanager->dumpAlerts(std::cerr);

  zorba_factory->uninitThread();
  zorba_factory->shutdown();

  return 0;
}

