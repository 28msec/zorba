
#include <fstream>

#include "timer.h"

#include "errors/Error.h"
#include "store/naive/atomic_items.h"
#include "store/naive/simple_store.h"
#include "store/naive/simple_collection.h"
#include "store/naive/qname_pool.h"
#include "store/naive/simple_loader.h"

#include "zorba_api.h"
#include "store/naive/basic_item_factory.h"
#include "error_display.h"

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
	Timer timer;
	timer.start();

	// xqp::LoggerManager::logmanager()->setLoggerConfig("#1#logging.log");

  //
  // Store initialization
  //
  xqp::SimpleStore* store = static_cast<xqp::SimpleStore*>(&xqp::Store::getInstance());

  timer.end();
  std::cout << "construction time : " << timer.getTime() << std::endl;
  //timer.resume();

  //
  // Zorba initialization
  // 
  ZorbaFactory& zorba_factory = ZorbaFactory::getInstance();

	zorba_factory.InitThread();

	Zorba_AlertsManager& errmanager = zorba_factory.getAlertsManagerForCurrentThread();

  //
  // Collections
  //
  xqp::Collection_t coll1 = store->createCollection("http://MyCollection1");

  std::cout << coll1->getURI()->show() << std::endl;

  xqp::Collection_t coll2 = store->createCollection("http://MyCollection1");

  DisplayErrorListForCurrentThread();

  xqp::QNamePool& pool = store->getQNamePool();

  rchandle<xqp::QNameItemImpl> qn = NULL;

  qn = pool.insert("ns1", "pre1", "loc1");

  qn = NULL;

  //
  // Load an xml file
  //
  std::string fileName("test1.xml");
  std::string xmlString;

  readXmlFile(fileName.c_str(), xmlString);

  XmlLoader& loader = store->getXmlLoader();
 
  NodeItem_t root = loader.loadXml(xmlString);

  std::cout << std::endl << root->show() << std::endl;

  root = NULL;
  coll1 = NULL;
  coll2 = NULL;

  return 0;
}

