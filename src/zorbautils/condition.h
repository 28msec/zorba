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
#ifndef ZORBA_UTIL_CONDITION_H
#define ZORBA_UTIL_CONDITION_H

#ifndef ZORBA_FOR_ONE_THREAD_ONLY

#include "zorbamisc/config/platform.h"

#ifdef ZORBA_HAVE_PTHREAD_H
#include <pthread.h>
#endif

namespace zorba { 

/*******************************************************************************

********************************************************************************/

#ifdef ZORBA_HAVE_PTHREAD_H

class Condition
{
 protected:
  pthread_cond_t   theCondition;

  Mutex          & theMutex;

 public:
  Condition(Mutex& m);

  ~Condition();

  void wait();
  void signal();
  void broadcast();
};

#elif WIN32 

class Condition
{
protected:
  HANDLE           cond_event[2];
  Mutex          & theMutex;
  int              waiters;
  HANDLE           cond_door;
  HANDLE           cond_broadcast;
  CRITICAL_SECTION  cond_cs;
public:
  Condition(Mutex& m);

  ~Condition();

  void wait();
  void signal();
  void broadcast();
};

#else

class Condition
{
 protected:
  Mutex          & theMutex;

 public:
  Condition(Mutex& m) : theMutex(m) {}

  ~Condition() {}

  void wait() {}
  void signal() {}
  void broadcast() {}
};

#endif // ZORBA_HAVE_PTHREAD_H

}

#endif // ZORBA_FOR_ONE_THREAD_ONLY

#endif


