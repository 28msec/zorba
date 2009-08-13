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
#ifndef RUNNABLE_H
#define RUNNABLE_H

#include "zorbautils/lock.h"

#ifndef ZORBA_FOR_ONE_THREAD_ONLY

#ifdef ZORBA_HAVE_PTHREAD_H
#include <pthread.h>
#define ZORBA_THREAD_RETURN void *
#else
typedef DWORD ThreadId;
#define ZORBA_THREAD_RETURN DWORD WINAPI
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
  */
  class Runnable {
  public:
    Runnable();
    virtual ~Runnable();
  public:
    enum ThreadState {
      RUNNING,
      TERMINATED,
      SUSPENDED,
      IDLE
    };
  public:
    void start();
    void terminate();
    void suspend();
    void resume();
    void join();
    ThreadState status();
  protected: // To be implemented by the user
    virtual void run() = 0;
    virtual void finish() = 0;
  private:
    static ZORBA_THREAD_RETURN startImpl(void* params);
    void finishImpl();
    ThreadState theStatus;
    bool finishCalled;
    Lock theThreadLock;
#ifdef ZORBA_HAVE_PTHREAD_H
    pthread_t theThread;
    pthread_mutex_t theMutex;
    pthread_cond_t theCV;
#else
    ThreadId theThreadId;
    HANDLE theThread;
#endif
  };
}
#endif//#ifndef ZORBA_FOR_ONE_THREAD_ONLY

#endif // RUNNABLE_H

