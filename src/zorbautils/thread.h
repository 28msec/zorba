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
#ifndef ZORBA_UTIL_THREAD
#define ZORBA_UTIL_THREAD

#include <zorba/config.h>
#include "zorbamisc/config/platform.h"

#ifdef ZORBA_HAVE_PTHREAD_H
#include <pthread.h>
#define ZORBA_THREAD_RETURN void *
#else
#define ZORBA_THREAD_RETURN DWORD WINAPI
#endif

namespace zorba {

#ifdef ZORBA_HAVE_PTHREAD_H
typedef pthread_t ThreadId;
#else
typedef DWORD ThreadId;
#endif

class  Thread
{
 private:
#ifdef ZORBA_HAVE_PTHREAD_H
  pthread_t theThread;
  pthread_mutex_t theMutex;
  pthread_cond_t theCV;
#else
  HANDLE theThread;
#endif

private:
	bool m_isSuspended;

 public:
  static ThreadId self()
  {
#ifdef ZORBA_HAVE_PTHREAD_H
    return pthread_self();
#else
    return GetCurrentThreadId();
#endif
  }

#ifdef ZORBA_HAVE_PTHREAD_H
  Thread( void *aFunction(void *anArgs), void *anArg );
#else
  Thread( DWORD ( WINAPI *aFunction ) ( void *anArg ), void *anArg );
#endif
    
  ~Thread();
  
  void suspend();

  void resume();

  void join();
};
}//end of namespace
#endif
