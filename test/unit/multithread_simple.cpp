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
#include <stdio.h>
#include <stdlib.h>

#include <zorba/zorba.h>
#include <zorba/store_manager.h>

using namespace zorba;

void* query_thread_1(void *param);
void* query_thread_2(void *param);
void* query_thread_3(void *param);
void* query_thread_4(void *param);

#define NR_THREADS  20

struct data {
  Zorba*  lZorba;
  Item    lItem;
  int     index;
};

typedef struct {
  Zorba*  lZorba;
  int     index;
} data_2;


#ifdef ZORBA_HAVE_PTHREAD_H

static  XQuery_t    lQuery;
std::string make_absolute_file_name(const char *target_file_name, const char *this_file_name);

/*
Simple cloning test
*/
bool
multithread_example_1(Zorba* aZorba)
{
  unsigned int  i;
  pthread_t     pt[NR_THREADS];

  try {
    lQuery = aZorba->compileQuery("1+1");

    for(i=0; i<NR_THREADS; i++)
      pthread_create(&pt[i], NULL, query_thread_1, (void*)i);

    //wait for threads to finish
    for(i=0;i<NR_THREADS;i++)
      pthread_join(pt[i], NULL);

    lQuery->close();

    return true;
  }
  catch (ZorbaException &e) {
    std::cerr << "some exception " << e << std::endl;
    return false;
  }
}


/*
Create multiple threads that compile and execute a query
*/
bool
multithread_example_2(Zorba* aZorba)
{
  unsigned int    i;
  pthread_t*      pthreads;
  data_2*         pdata;

  try {
    pthreads=(pthread_t *)malloc(NR_THREADS*sizeof(*pthreads));
    pdata=(data_2 *)malloc(NR_THREADS*sizeof(data_2));

    for(i=0; i<NR_THREADS; i++)
    {
      pdata[i].lZorba = aZorba;
      pdata[i].index = i;
      pthread_create(&pthreads[i], NULL, query_thread_2, (void*)(pdata+i));
    }

    //wait for threads to finish
    for(i=0; i<NR_THREADS; i++)
      pthread_join(pthreads[i], NULL);

    free(pthreads);
    free(pdata);

    return true;
  }
  catch (ZorbaException &e) {
    std::cerr << "some exception " << e << std::endl;
    return false;
  }
}


/*
Create separate queries that are working with the same document loaded in store.
*/
bool
multithread_example_3(Zorba* aZorba)
{
  unsigned int  i;
  pthread_t     pt[NR_THREADS];
  data*         test;

  try {
    std::stringstream lInStream("<books><book>Book 1</book><book>Book 2</book><book>Book 3</book></books>");

    Item aItem = aZorba->getXmlDataManager()->loadDocument("books.xml", lInStream);

    for(i=0; i<NR_THREADS; i++)
    {
      test = new data ();
      test->lZorba = aZorba;
      test->lItem = aItem;
      test->index = i+1;
      pthread_create(&pt[i], NULL, query_thread_3, (void*)test);
    }

    for(i=0;i<NR_THREADS;i++)
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

/*
Load a document in store and query it from diffrent threads.
*/
bool
multithread_example_4(Zorba* aZorba)
{
  unsigned int  i;
  pthread_t     pt[NR_THREADS];
  data*         test;

  try {
    Item aItem = aZorba->getXmlDataManager()->loadDocument(make_absolute_file_name("book.xml", __FILE__));

    for(i=0; i<NR_THREADS; i++)
    {
      test = new data ();
      test->lZorba = aZorba;
      test->lItem = aItem;
      test->index = i+1;
      pthread_create(&pt[i], NULL, query_thread_4, (void*)test);
    }

    for(i=0;i<NR_THREADS;i++)
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
multithread_simple(int argc, char* argv[])
{
  simplestore::SimpleStore* lStore = StoreManager::getStore();
  Zorba*                    lZorba = Zorba::getInstance(StoreManager::getStore());
  bool                      res = false;

//   std::cout << std::endl  << "executing multithread test 1 : ";
//   res = multithread_example_1(lZorba);
//   if (!res) {
//     std::cout << "Failed" << std::endl;
//     lZorba->shutdown();
//     StoreManager::shutdownStore(lStore);
//     return 1;
//   }
//   else std::cout << "Passed" << std::endl;

  std::cout << std::endl  << "executing multithread test 2 : ";
  res = multithread_example_2(lZorba);
  if (!res) {
    std::cout << "Failed" << std::endl;
    lZorba->shutdown();
    StoreManager::shutdownStore(lStore);
    return 1;
  }
  else std::cout << "Passed" << std::endl;

//   std::cout << std::endl  << "executing multithread test 3 : ";
//   res = multithread_example_3(lZorba);
//   if (!res) {
//     std::cout << "Failed" << std::endl;
//     lZorba->shutdown();
//     StoreManager::shutdownStore(lStore);
//     return 1;
//   }
//   else std::cout << "Passed" << std::endl;

//   std::cout << std::endl  << "executing multithread test 4 : ";
//   res = multithread_example_4(lZorba);
//   if (!res) {
//     std::cout << "Failed" << std::endl;
//     lZorba->shutdown();
//     StoreManager::shutdownStore(lStore);
//     return 1;
//   }
//   else std::cout << "Passed" << std::endl;
  
  lZorba->shutdown();
  StoreManager::shutdownStore(lStore);
  return 0;
}


void* query_thread_1(void *param)
{
  XQuery_t xquery_clone = lQuery->clone();
  if(xquery_clone == NULL)
  {
    std::cout << "cannot clone xquery object" << std::endl;
    return (void*)1;
  }

  std::ostringstream os;
  os << xquery_clone << std::endl;

  return (void*)0;
}


void* query_thread_2(void *param)
{
  data_2* var = (data_2*)param;

  try
  {
    XQuery_t query = var->lZorba->compileQuery("1+1");

    std::ostringstream os;
    os << query << std::endl;

    query->close();
  } catch (ZorbaException &e) {
    std::cerr << "filename: " << e.getFileName() << ", ";
    std::cerr << "line NO: " << e.getFileLineNumber() << ", ";
    std::cerr << e.getDescription() << std::endl;
    return NULL;
  }

//   std::cout << "1 ";
  return (0);
}


void* query_thread_3(void *param)
{
  data* var = (data*)param;

  XQuery_t lQuery = var->lZorba->compileQuery("declare variable $var external; doc('books.xml')//book");

  DynamicContext* lCtx = lQuery->getDynamicContext();

  lCtx->setVariable("var", var->lItem);

  std::ostringstream os;
  os << lQuery << std::endl;

  var->lItem = NULL;
  lQuery->close();

  return (void*)0;
}

void* query_thread_4(void *param)
{
  data* var = (data*)param;
  char buff [3];
  int n;

  int i = var->index % 10;
  n=sprintf (buff, "%d", i);

  XQuery_t aQuery = var->lZorba->compileQuery("declare variable $var external; doc('books.xml')//chapter[@id=1]");

  DynamicContext* lCtx = aQuery->getDynamicContext();

  lCtx->setVariable("var", var->lItem);

  std::ostringstream os;
  os << aQuery << std::endl;

  var->lItem = NULL;
  aQuery->close();

  return (void*)0;
}

std::string make_absolute_file_name(const char *target_file_name, const char *this_file_name)
{
  std::string             str_result;
  std::string::size_type  pos;

  str_result = this_file_name;
  pos = str_result.rfind('/');
  if(pos == std::string::npos)
    pos = str_result.rfind('\\');
  if(pos == std::string::npos)
    return target_file_name;
  str_result.erase(pos+1);
  str_result += target_file_name;
//   std::cout << "make_absolute_file_name -> " << str_result << std::endl;
  return str_result;
}
#endif
/* vim:set et sw=2 ts=2: */
