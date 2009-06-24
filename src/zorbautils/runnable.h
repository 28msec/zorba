#ifndef RUNNABLE_H
#define RUNNABLE_H

#include "lock.h"

#ifdef ZORBA_HAVE_PTHREAD_H
#include <pthread.h>
typedef pthread_t ThreadId;
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
    ThreadId theThreadId;
    bool finishCalled;
    Lock theThreadLock;
#ifdef ZORBA_HAVE_PTHREAD_H
    pthread_t theThread;
    pthread_mutex_t theMutex;
    pthread_cond_t theCV;
#else
    HANDLE theThread;
#endif
  };
}

#endif // RUNNABLE_H

