#ifndef ZORBA_RUNNABLE_H
#define ZORBA_RUNNABLE_H

#include "common/common.h"

#include "zorbautils/mutex.h"
#include "zorbautils/condition.h"


#ifdef ZORBA_HAVE_PTHREAD_H
#    include <pthread.h>
#    define ZORBA_THREAD_RETURN void *
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

protected:
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
    void
    start();

    // can only be called if the thread is suspended
    void
    terminate();

    void
    suspend();

    void
    resume();

    void
    join();

    ThreadState status() const { return theStatus; }

protected: // To be implemented by the user
    
    virtual void run() = 0;

    virtual void finish() = 0;

private:
    volatile ThreadState theStatus;
    static ZORBA_THREAD_RETURN startImpl(void* params);
    static void cleanupHandler(void *arg);

    void finishImpl();

    bool theFinishCalled;

    Mutex             theMutex;

    Condition         theCondition;

#ifdef ZORBA_HAVE_PTHREAD_H
    pthread_t         theThread;

    static void
    mutexCleanupHandler(void *);

#else
    ThreadId theThreadId;
    HANDLE theThread;
#endif
};
} /* namespace zorba */

#endif // ZORBA_RUNNABLE_H

