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

#include <vector>
#include <iostream>
#include <sstream>

#include <zorba/zorba.h>
#include <zorba/store_manager.h>

using namespace zorba;

void* query_stress_test_1(void *param);

#define THREADS  5

struct argv {
  Zorba*  lZorba;
  Item    lItem;
  int     index;
};

#ifdef ZORBA_HAVE_PTHREAD_H

std::string make_absolute_file_name(const char *target_file_name, const char *this_file_name);

/*
Load a document in store and query it from diffrent threads.
*/
bool
multithread_stress_example_1(Zorba* aZorba)
{
  unsigned int  i;
  pthread_t     pt[THREADS];
  argv*         test;

  try {
    Item aItem = aZorba->getXmlDataManager()->loadDocument(make_absolute_file_name("XQTSCatalog.xml", __FILE__));

    for(i=0; i<THREADS; i++)
    {
      test = new argv ();
      test->lZorba = aZorba;
      test->lItem = aItem;
      test->index = i+1;
      pthread_create(&pt[i], NULL, query_stress_test_1, (void*)test);
    }

    for(i=0;i<THREADS;i++)
    {
      void  *thread_result;
      pthread_join(pt[i], &thread_result);
    }

    aItem = NULL;
    delete test;

    return true;
  }
  catch (ZorbaException &e) {
    std::cerr << "some exception " << e << std::endl;
    return false;
  }
}

int
multithread_stress_test(int argc, char* argv[])
{
  simplestore::SimpleStore* lStore = StoreManager::getStore();
  Zorba*                    lZorba = Zorba::getInstance(StoreManager::getStore());
  bool                      res = false;

  std::cout << std::endl  << "executing multithread test 1 : ";
  res = multithread_stress_example_1(lZorba);
  if (!res) {
    std::cout << "Failed" << std::endl;
    lZorba->shutdown();
    StoreManager::shutdownStore(lStore);
    return 1;
  }
  else std::cout << "Passed" << std::endl;

  lZorba->shutdown();
  StoreManager::shutdownStore(lStore);
  return 0;
}

void* query_stress_test_1(void *param)
{
  argv* var = (argv*)param;

  std::ostringstream os;
  os << var->index;

  XQuery_t aQuery = var->lZorba->compileQuery(".//chapter[@id=" + os.str() + "]");

  DynamicContext* lCtx = aQuery->getDynamicContext();

  lCtx->setContextItem(var->lItem);

  os.clear();
  os << aQuery << std::endl;

  var->lItem = NULL;
  aQuery->close();

  return (void*)0;
}

// std::string make_absolute_file_name(const char *target_file_name, const char *this_file_name)
// {
//   std::string             str_result;
//   std::string::size_type  pos;
// 
//   str_result = this_file_name;
//   pos = str_result.rfind('/');
//   if(pos == std::string::npos)
//     pos = str_result.rfind('\\');
//   if(pos == std::string::npos)
//     return target_file_name;
//   str_result.erase(pos+1);
//   str_result += target_file_name;
// //   std::cout << "make_absolute_file_name -> " << str_result << std::endl;
//   return str_result;
// }
#endif
/* vim:set et sw=2 ts=2: */
