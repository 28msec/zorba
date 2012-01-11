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
#include "stdafx.h"

#include "zorbautils/fatal.h"
#include "zorbautils/mutex.h"

namespace zorba { 


Mutex::Mutex()
{
#ifdef ZORBA_HAVE_PTHREAD_H
  pthread_mutexattr_t attr;
  pthread_mutexattr_init(&attr);
  pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_ERRORCHECK);

#ifndef NDEBUG
  int pshared;
  pthread_mutexattr_getpshared(&attr, &pshared);
  ZORBA_FATAL(pshared == PTHREAD_PROCESS_PRIVATE, "mutex pshared = " << pshared);
#endif

  pthread_mutex_init(&theMutex, &attr);

  pthread_mutexattr_destroy(&attr);

#elif defined WIN32
  //threads can acquire same mutex multiple times
  theMutex = CreateMutex(NULL, FALSE, _T(""));
#endif
}



Mutex::~Mutex()
{
#ifdef ZORBA_HAVE_PTHREAD_H
  pthread_mutex_destroy(&theMutex);
#elif defined WIN32
  CloseHandle(theMutex);
#endif
}


void Mutex::lock()
{ 
#ifdef ZORBA_HAVE_PTHREAD_H
  int ret= pthread_mutex_lock(&theMutex);
  ZORBA_FATAL(!ret, "Failed to acquire mutex. Error code = " << ret << " message = " << strerror(ret));
#elif defined WIN32
  WaitForSingleObject(theMutex, INFINITE);
#endif
}


void Mutex::unlock()
{ 
#ifdef ZORBA_HAVE_PTHREAD_H
  int ret= pthread_mutex_unlock(&theMutex);
  ZORBA_FATAL(!ret, "Failed to release mutex. Error code = " << ret);
#elif defined WIN32
  ReleaseMutex(theMutex);
#endif
}


} // namespace zorba
/* vim:set et sw=2 ts=2: */
