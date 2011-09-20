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
#include <cassert>
#include <map>
#include <cstdlib>
#include <time.h>
#include <limits.h>

#include <zorba/zorba.h>
#include <zorba/debugger_client.h>
#include <zorba/debugger_default_event_handler.h>
#include <zorba/store_manager.h>
#ifdef UNIX
#  include <sys/time.h>
#endif

#ifdef WIN32
#include <windows.h>
#define sleep(s) Sleep(s*1000)
#else
#include <limits.h>
#endif
#ifdef ZORBA_HAVE_PTHREAD_H
#include <pthread.h>
#define ZORBA_THREAD_RETURN void *
#else
#define ZORBA_THREAD_RETURN DWORD WINAPI
#endif

using namespace zorba;

unsigned int getSeed()
{
#ifdef WIN32
  return GetTickCount();
#else
  struct timeval tv;
  gettimeofday(&tv, NULL);
  unsigned long long sec = tv.tv_sec;
  unsigned long long usec = tv.tv_usec;
  unsigned long long value = 1000000*sec + usec;

  return (unsigned int)(value & UINT_MAX);
#endif
}

std::pair<short, short> getRandomPorts() 
{
  srand(getSeed());
  int lPort1 = rand();
  lPort1 = lPort1 < 1026 ? lPort1 + 1026 : lPort1;
  int lPort2 = rand();
  lPort2 = lPort2 < 1026 ? lPort2 + 1026 : lPort2;

  while (lPort1 > 65535) {
    lPort1 -= 1000;
  }
  while (lPort2 > 65535) {
    lPort2 -= 1000;
  }
  return std::pair<short, short>(static_cast<short>(lPort1), static_cast<short>(lPort2));
}

static std::pair<short, short> thePorts;

class MyDebuggerEventHandler: public DefaultDebuggerEventHandler
{
  public:
    virtual ~MyDebuggerEventHandler(){}

    void started()
    {
      std::cerr << "Query started" << std::endl;
    }

    void idle()
    {
      std::cerr << "Query idle" << std::endl;
    }

    void suspended( QueryLocation &aLocation, SuspendedBy aCause )
    {
      std::cerr << "Suspended at line: " << aLocation.getLineBegin(); 
    }

    void resumed()
    {
      std::cerr << "Query resumed" << std::endl; 
    }

    void terminated()
    {
      std::cerr << "Query terminated" << std::endl; 
    }

    void evaluated(String &anExpr, std::list< std::pair<String, String> > &aValuesAndTypes)
    {
      std::list<std::pair<String, String> >::iterator it;
      for(it=aValuesAndTypes.begin(); it!=aValuesAndTypes.end(); ++it)
      {
        std::cerr << it->first << " " << it->second << std::endl;
      }   
    }
  
    void evaluated(String &anExpr, String &anError)
    {
      std::cerr << "An error happened: " << anError << std::endl;
    }
};

ZORBA_THREAD_RETURN runClient(void*)
{
  sleep(1);
  MyDebuggerEventHandler lEventHandler;
  DebuggerClient* lClient = DebuggerClient::createClient(
    thePorts.first, thePorts.second);
  lClient->registerEventHandler( &lEventHandler );
  lClient->run();
  sleep(1); // make sure the query terminates
  delete lClient;
  return 0;
}

bool debugger_example_1(Zorba *aZorba)
{
  XQuery_t lQuery = aZorba->createQuery();
  lQuery->setDebugMode(true);
  lQuery->compile("for $i in ( 1 to 10 ) return $i");
  lQuery->debug(thePorts.second);
  lQuery->close();
  return true;
}

int debugger(int argc, char *argv[])
{
  thePorts = getRandomPorts();
  void* lStore = zorba::StoreManager::getStore();
  Zorba* lZorba = Zorba::getInstance(lStore);
  bool res = false;
  {
#ifdef ZORBA_HAVE_PTHREAD_H
    pthread_t lThread;
    if ( pthread_create( &lThread, 0, runClient, 0 ) != 0 ) 
#else
    HANDLE lThread;
    if ((lThread = CreateThread(0, 0, runClient, 0, 0, 0)) == 0)
#endif
    {
      std::cerr << "Couldn't start the thread" << std::endl;
      return 1;
    }
    std::cout << "executing example 1" << std::endl;
    res = debugger_example_1(lZorba);
#ifdef ZORBA_HAVE_PTHREAD_H
    pthread_join( lThread, 0 );
#else
    WaitForSingleObject( lThread, INFINITE );
#endif
    if ( !res ) return 1;
    std::cout << std::endl;
  }

  lZorba->shutdown();
  zorba::StoreManager::shutdownStore(lStore);
  return 0;
}

