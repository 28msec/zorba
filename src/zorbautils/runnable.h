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

public:
    enum ThreadState {
      RUNNING,
      TERMINATED,
      SUSPENDED,
      IDLE
    };

public:
  virtual ~Runnable();

public:
    void
    start();

    // can only be called if the thread is suspended
    void
    terminate();

    void
    suspend(unsigned long aTimeInMs = 0);

    void
    resume();

    void
    join();

    ThreadState status() const { return theStatus; }

    /**
    * Resets the Thread, so that it can be started again.
    *
    * @pre theStatus == TERMINATED || theStatus == IDLE
    * @post theStatus == IDLE
    */
    virtual void reset();

    /**
    * @brief Indicates if the object should be deleted after run.
    *
    * When the run methods finished, it checks if it has to delete
    * the object. With this method, this deletion status can be set.
    *
    * @post theDeleteAfterRun == aDeleteAfterRun
    */
    void setDeleteAfterRun(bool aDeleteAfterRun);

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

    bool theDeleteAfterRun;

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

