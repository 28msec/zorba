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
#ifndef ZORBA_DEBUGGER_PROCESS_LISTENER_H
#define ZORBA_DEBUGGER_PROCESS_LISTENER_H

#include <zorba/config.h>

#ifdef ZORBA_HAVE_PTHREAD_H
# include <pthread.h>
# include <sys/wait.h>
  typedef pthread_t ThreadId;
  typedef pid_t ProcessId;
  typedef int ExitCode;
# define ZORBA_THREAD_RETURN void *
#else
# include <windows.h>
  typedef DWORD ThreadId;
  typedef DWORD ProcessId;
  typedef DWORD ExitCode;
# define ZORBA_THREAD_RETURN DWORD WINAPI
#endif

typedef void (*ExitCallbackType)(ExitCode);


namespace zorba { namespace debugger {

class ProcessListener
{
  public:
    ProcessListener(ProcessId processID, ExitCallbackType callback);

    ~ProcessListener();

    ProcessId
    getProcessID();

    ExitCallbackType
    getCallback();

  private:

    static ZORBA_THREAD_RETURN run(void* params);

  private:

#ifdef ZORBA_HAVE_PTHREAD_H
    pthread_t         theThread;
#else
    ThreadId          theThreadId;
    HANDLE            theThread;
#endif

    ProcessId         theProcessID;
    ExitCallbackType  theCallback;
};
  
} // namespace zorba
} // namespace debugger

#endif // ZORBA_DEBUGGER_PROCESS_LISTENER_H
