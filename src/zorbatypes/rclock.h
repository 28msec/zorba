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
#pragma once
#ifndef ZORBA_RCLOCK_H
#define ZORBA_RCLOCK_H

#include <iostream>
#include <cstdlib>


namespace zorba 
{


#ifndef ZORBA_FOR_ONE_THREAD_ONLY

/*******************************************************************************

********************************************************************************/

#if defined ZORBA_HAVE_PTHREAD_SPINLOCK

class RCLock 
{
  pthread_spinlock_t theLock;

public:
  RCLock()
  {
    if (0 != pthread_spin_init(&theLock, PTHREAD_PROCESS_PRIVATE))
    {
      std::cerr << "Failed to initialize spinlock" << std::endl; 
      abort();
    }
  } 

  RCLock(const RCLock&)
  {
    if (0 != pthread_spin_init(&theLock, PTHREAD_PROCESS_PRIVATE))
    {
      std::cerr << "Failed to initialize spinlock" << std::endl; 
      abort();
    }
  }

  ~RCLock()
  {
    if (0 != pthread_spin_destroy(&theLock))
    {
      std::cerr << "Failed to destroy spinlock" << std::endl; 
      abort();
    }
  } 

  void acquire()
  {
    if (0 != pthread_spin_lock(&theLock))
    {
      std::cerr << "Failed to acquire spinlock" << std::endl; 
      abort();
    }
  }
  
  void release()
  {
    if (0 != pthread_spin_unlock(&theLock))
    {
      std::cerr << "Failed to release spinlock" << std::endl; 
      abort();
    }
  }
};
  

#elif defined ZORBA_HAVE_PTHREAD_MUTEX

class RCLock 
{
  mutable pthread_mutex_t  theLock;

public:

RCLock()
{
  pthread_mutexattr_t attr;
  pthread_mutexattr_init(&attr);
  pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_ERRORCHECK | PTHREAD_PROCESS_PRIVATE);
  if (0 != pthread_mutex_init(&theLock, &attr))
  {
    std::cerr << "Failed to initialize RCLock" << std::endl; 
    abort();
  }
  pthread_mutexattr_destroy(&attr);
} 


RCLock(const RCLock&)
{
  pthread_mutexattr_t attr;
  pthread_mutexattr_init(&attr);
  pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_ERRORCHECK | PTHREAD_PROCESS_PRIVATE);
  if (0 != pthread_mutex_init(&theLock, &attr))
  {
    std::cerr << "Failed to initialize RCLock" << std::endl; 
    abort();
  }
  pthread_mutexattr_destroy(&attr);
} 


~RCLock()
{
  if (0 != pthread_mutex_destroy(&theLock))
  {
    std::cerr << "Failed to destroy RCLock" << std::endl; 
    abort();
  }
} 

void acquire()
{
  if (0 != pthread_mutex_lock(&theLock))
  {
    std::cerr << "Failed to acquire RCLock" << std::endl; 
    abort();
  }

}

void release()
{
  if (0 != pthread_mutex_unlock(&theLock))
  {
    std::cerr << "Failed to release RCLock" << std::endl; 
    abort();
  }
}
};


#elif defined WIN32 || defined WINCE

class RCLock 
{
public:
  RCLock() { }
  
  RCLock(const RCLock& ) { }

  ~RCLock() { } 

  void acquire() { }

  void release() { }
};

#else

#error must have pthread mutex or phread spinlock, or windows OS

#endif // ZORBA_HAVE_PTHREAD or WIN32

#endif // ZORBA_FOR_ONE_THREAD_ONLY

} // namespace zorba

#endif // ZORBA_RCLOCK

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
