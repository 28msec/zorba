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

#include <fstream>

#include "timer.h"

#include <zorba/zorba.h>

#include "errors/errors.h"
#include "system/globalenv.h"
#include "store/naive/atomic_items.h"
#include "store/naive/simple_store.h"
#include "store/naive/simple_collection.h"
#include "store/naive/qname_pool.h"
#include "store/naive/simple_loader.h"
#include "store/naive/basic_item_factory.h"
#include "zorbatypes/datetime.h"
#include "zorbatypes/duration.h"


using namespace zorba;


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

  if (argc < 2)
  {
    std::cerr << "usage: test_store <input file name>" << std::endl;
  }

  std::string fileName(argv[1]);

  //
  // Zorba initialization
  //
  Zorba* lZorba = Zorba::getInstance();

  //
  // Store initialization
  //
  zorba::store::SimpleStore* store = static_cast<zorba::store::SimpleStore*>(&zorba::GENV.getStore());

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
  catch (zorba::error::ZorbaError& e)
  {
    std::cout << e.theDescription << std::endl;
  }

  //
  // Test boost::shared_ptr
  //
#if 0
  zorba::store::OrdPath* ordp = new zorba::store::OrdPath();

  boost::shared_ptr<zorba::store::OrdPath> p1(ordp);
  boost::shared_ptr<zorba::store::OrdPath> p2(ordp);

  std::cout << "p1 count = " << p1.use_count()
            << " p2 count = " << p2.use_count() << std::endl;

  p2 = p1;
#endif

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

#define RC_TIMMING

#ifdef RC_TIMMING

  ulong loop = 1000000;
  const char* data = "aaaaaaa0000000";
  ulong datalen = strlen(data);

#ifndef WIN32
	Timer timer;
#endif

  for (ulong i = 0; i < loop; i++)
  {
    char* tmp = new char[datalen + 1];
    memcpy(tmp, data, datalen);
    delete [] tmp;
  }

#ifndef WIN32
  timer.suspend();
  std::cout << "char-pointer alloc time : " << timer.getTime() << std::endl;
  timer.resume();
#endif

  for (ulong i = 0; i < loop; i++)
  {
    xqpStringStore* tmp = new xqpStringStore(data);
    delete tmp;
  }

#ifndef WIN32
  timer.suspend();
  std::cout << "String-pointer alloc time : " << timer.getTime() << std::endl;
  timer.resume();
#endif

  for (ulong i = 0; i < loop; i++)
  {
    xqpStringStore_t tmp = new xqpStringStore(data);
  }

#ifndef WIN32
  timer.suspend();
  std::cout << "String-handle alloc time : " << timer.getTime() << std::endl;
  timer.resume();
#endif

#else

#ifndef WIN32
	Timer timer;
#endif

#endif // RC_TIMMING

  try
  {
    doc = coll1->addToCollection(xmlStream);
  }
  catch (zorba::error::ZorbaError& e)
  {
    std::cout << e.theDescription << std::endl;
    return 1;
  }

#ifndef WIN32
  timer.suspend();
  std::cout << "Loading time : " << timer.getTime() << std::endl;
  timer.resume();
#endif

  xmlFile.close();

  store->deleteCollection(coll1->getUri()->getStringValue());
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
    return 1;


  doc = 0;

  return 0;
}

