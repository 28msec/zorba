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
#include <zorba/zorba.h>
#include <zorba/debugger_client.h>
#include <zorba/debugger_default_event_handler.h>
#include <simplestore/simplestore.h>
#include <zorbaerrors/errors.h>
#ifdef WIN32
#include <windows.h>
#define sleep(s) Sleep(s*1000)
#endif
#ifdef ZORBA_HAVE_PTHREAD_H
#include <pthread.h>
#define ZORBA_THREAD_RETURN void *
#else
#define ZORBA_THREAD_RETURN DWORD WINAPI
#endif

using namespace zorba;

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

    void evaluated(String &anExpr, std::map<String, String> &aValuesAndTypes)
    {
      std::map<String, String>::iterator it;
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

ZORBA_THREAD_RETURN runClient( void* )
{
  sleep(3);
  MyDebuggerEventHandler lEventHandler;
  ZorbaDebuggerClient * lClient = ZorbaDebuggerClient::createClient( 8000, 9000 );
  lClient->registerEventHandler( &lEventHandler );
  lClient->run();
  sleep(1);
  lClient->terminate();
  delete lClient;
  return 0;
}

bool debugger_example_1(Zorba *aZorba)
{
  XQuery_t lQuery = aZorba->createQuery();
  lQuery->setDebugMode(true);
  lQuery->compile("for $i in ( 1 to 10 ) return $i");
  lQuery->debug();
  lQuery->close();
  return true;
}

bool debugger_example_2(Zorba *aZorba)
{
  XQuery_t lQuery = aZorba->createQuery();
  lQuery->setFileName("foo.xq");
  lQuery->setDebugMode(true);
  assert(lQuery->getDebugMode());
  lQuery->compile("1+2");
  lQuery->debug( 8000, 9000 );
  lQuery->close();
  return true;
}

bool debugger_example_3(Zorba *aZorba)
{
  try
  {
    XQuery_t lQuery = aZorba->createQuery();
    lQuery->compile("1+2");
    lQuery->debug();
    lQuery->close();
  } catch( error::ZorbaError &e ) {
    return true;
  }
  return false;
}

int debugger( int argc, char *argv[] )
{
  simplestore::SimpleStore *lStore = simplestore::SimpleStoreManager::getStore();
  Zorba *lZorba = Zorba::getInstance( lStore );
  bool res = false;
  {
#ifdef ZORBA_HAVE_PTHREAD_H
    pthread_t lThread;
    if ( pthread_create( &lThread, 0, runClient, 0 ) != 0 ) 
#else
    HANDLE lThread;
    if ( ( lThread = CreateThread(0, 0, runClient, 0, 0, 0) ) == 0 )
#endif
    {
      std::cerr << "Couldn't start the thread" << std::endl;
      return 1;
    }
    std::cout << "executing example 1" << std::endl;
    res = debugger_example_1(lZorba);
#ifdef ZORBA_HAVE_PTHREAD_H
    pthread_join( lThread, 0 );
    pthread_cancel( lThread );
    pthread_detach( lThread );
#else
    WaitForSingleObject( lThread, INFINITE );
    CloseHandle( lThread );;
#endif
    if ( !res ) return 1;
    std::cout << std::endl;
  }

  {
    std::cout << "executing example 2" << std::endl;
#ifdef ZORBA_HAVE_PTHREAD_H
    pthread_t lThread;
    if ( pthread_create( &lThread, 0, runClient, 0 ) != 0 ) 
#else
    HANDLE lThread;
    if ( ( lThread = CreateThread(0, 0, runClient, 0, 0, 0) ) == 0 )
#endif
    {
      std::cerr << "Couldn't start the thread" << std::endl;
      return 1;
    }
    res = debugger_example_2(lZorba);
#ifdef ZORBA_HAVE_PTHREAD_H
    pthread_join( lThread, 0 );
    pthread_cancel( lThread );
    pthread_detach( lThread );
#else
    WaitForSingleObject( lThread, INFINITE );
    CloseHandle( lThread );;
#endif
    if ( !res ) return 1;
    std::cout << std::endl;
  }
 
  {
    std::cout << "executing example 3" << std::endl;
    res = debugger_example_3(lZorba);
    if ( !res ) return 1;
    std::cout << std::endl;
  }

  lZorba->shutdown();
  simplestore::SimpleStoreManager::shutdownStore(lStore);
  return 0;
}

