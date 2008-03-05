
#include <fstream>

#include "timer.h"

#include <zorba/zorba_api.h>

#include "errors/error_factory.h"
#include "system/globalenv.h"
#include "store/naive/atomic_items.h"
#include "store/naive/simple_store.h"
#include "store/naive/simple_collection.h"
#include "store/naive/qname_pool.h"
#include "store/naive/simple_loader.h"
#include "store/naive/basic_item_factory.h"


using namespace zorba;

#ifdef _DEBUG
extern const char*		zorba::g_error_in_file;
extern int				zorba::g_error_at_line;
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
  zorba::store::SimpleStore* store = static_cast<zorba::store::SimpleStore*>(&zorba::GENV.getStore());

  //
  // Zorba initialization
  // 
  ZorbaEngine_t zorba_factory = ZorbaEngine::getInstance();

	zorba_factory->initThread();

	ZorbaAlertsManager_t errmanager = zorba_factory->getAlertsManagerForCurrentThread();

  //
  // Create collections
  //
  zorba::store::Collection_t coll1;
  zorba::store::Collection_t coll2;

  try
  {
    xqpStringStore_t uri(new xqpStringStore("http://MyCollection1"));
    coll1 = store->createCollection(uri);

    std::cout << coll1->getUri()->show() << std::endl;

    coll2 = store->createCollection(uri);
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
  store::Item_t doc;

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

  store->deleteCollection(coll1->getUri()->getStringValue().getStore());
  coll1 = 0;

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

  doc = 0;

  zorba_factory->uninitThread();
  zorba_factory->shutdown();

  return 0;
}

