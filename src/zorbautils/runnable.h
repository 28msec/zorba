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
#ifndef ZORBA_RUNNABLE_H
#define ZORBA_RUNNABLE_H

#include "common/common.h"

#include "zorbautils/mutex.h"
#include "zorbautils/condition.h"


#ifdef ZORBA_HAVE_PTHREAD_H
#    include <pthread.h>
#    define ZORBA_THREAD_RETURN void *
     typedef pthread_t ThreadId;
#else
     typedef DWORD ThreadId;
#    define ZORBA_THREAD_RETURN DWORD WINAPI
#endif


namespace zorba {

 /**
 * This class implements operating system independent
 * threads. Users of this class have to implement a child
 * of Runnable. The rules are as follows:
 *  - Runnable::start() will start the thread and run
 *    Runnable::run() inside that thread.
 *  - Runnable::finish() will be called by the implementation
 *    if the thread terminates or if Runnable::terminate() is
 *    called by the user.
 *  - A thread can only be suspended within the thread itself.
 *  - A thread can only be terminated by the user if the
 *    thread is suspended
 */
class ZORBA_DLL_PUBLIC Runnable
{
 public:
  enum ThreadState 
  {
    RUNNING,
    TERMINATED,
    SUSPENDED,
    IDLE
  };

private:
  volatile ThreadState theStatus;

  bool              theFinishCalled;

  Mutex             theMutex;

  /**
   * This mutex is only used to synchronize the join and finishImpl calls.
   */
  Mutex             theFinishMutex;
  /**
   * This condition is only used to synchronize the join and finishImpl calls.
   */
  Condition         theFinishCondition;

#ifdef ZORBA_HAVE_PTHREAD_H
  Condition         theCondition;
  bool              theCalledTerminate;
  pthread_t         theThread;
#else
  ThreadId          theThreadId;
  HANDLE            theThread;
#endif

public:
  static ThreadId self()
  {
#ifdef ZORBA_HAVE_PTHREAD_H
    return pthread_self();
#else
    return GetCurrentThreadId();
#endif
  }

public:
  virtual ~Runnable();

  void start();

  // can only be called if the thread is suspended
  void terminate();

  void suspend(unsigned long aTimeInMs = 0);

  void resume();

  void join();

  ThreadState status() const { return theStatus; }

  /**
   * Resets the Thread, so that it can be started again.
   *
   * @pre theStatus == TERMINATED || theStatus == IDLE
   * @post theStatus == IDLE
   */
  virtual void reset();
  
protected: 
    
  Runnable();

  virtual void run() = 0; // To be implemented by the user

  virtual void finish() = 0; // To be implemented by the user
  
  /**
   * Makes the current thread sleeping for a given
   * number of micro seconds.
   */
  void sleep_(unsigned long useconds);

private:
  static void mutexCleanupHandler(void *);

  static ZORBA_THREAD_RETURN startImpl(void* params);

  static void cleanupHandler(void *arg);

  void finishImpl();
};


} /* namespace zorba */

#endif // ZORBA_RUNNABLE_H

/* vim:set et sw=2 ts=2: */
