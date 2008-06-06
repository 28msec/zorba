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
#ifndef ZORBA_STORE_UTIL_MUTEX
#define ZORBA_STORE_UTIL_MUTEX

#include "zorbamisc/config/platform.h"

#ifdef ZORBA_HAVE_PTHREAD_H
#  include <pthread.h>
#endif

namespace zorba { 

#ifndef ZORBA_FOR_ONE_THREAD_ONLY


/*******************************************************************************

********************************************************************************/
class Mutex
{
protected:

#ifdef ZORBA_HAVE_PTHREAD_H
  pthread_mutex_t  theMutex;
#elif defined WIN32
  HANDLE           theMutex;
#endif

public:
  Mutex();

  ~Mutex();
    
  void lock();
    
  void unlock();

 private:
  Mutex(const Mutex &);
  void operator=(const Mutex &);
};


/*******************************************************************************

********************************************************************************/
class AutoMutex
{
private:
  Mutex * theMutex;

public:
  AutoMutex(Mutex* mutex) : theMutex(mutex)
  { 
    if (theMutex)
      theMutex->lock();   
  }
    
  ~AutoMutex()
  {
    if (theMutex)
      theMutex->unlock();
  }
};

#endif // ZORBA_FOR_ONE_THREAD_ONLY


} // namespace zorba


#endif
