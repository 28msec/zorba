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

#include "process_listener.h"

#include <iostream>

#ifdef ZORBA_HAVE_PTHREAD_H
# include <cassert>
#endif


namespace zorba { namespace debugger {
  
ProcessListener::ProcessListener(ProcessId aProcessID, ExitCallbackType aCallback)
  : theProcessID(aProcessID), theCallback(aCallback)
{
#ifdef WIN32
  theThread = CreateThread(NULL, 0, &run, (void*) this, 0, &theThreadId);
#else
  if (pthread_create(&theThread, NULL, &run, (void*) this)) {
    assert(false);
  }
#endif
}

ProcessListener::~ProcessListener()
{
}

ProcessId
ProcessListener::getProcessID()
{
  return theProcessID;
}

ExitCallbackType
ProcessListener::getCallback()
{
  return theCallback;
}


ZORBA_THREAD_RETURN
ProcessListener::run(void* params)
{
  ProcessListener* lThis = static_cast<ProcessListener*>(params);
  ExitCode lExitCode = -1;
  ProcessId lPid = lThis->getProcessID();

#ifdef WIN32
  // wait for the process to exit
  WaitForSingleObject(lPid, INFINITE);

  // find out the process exit code if possible
  if (!GetExitCodeProcess(lThis->getProcessID(), &lExitCode)) {
    lExitCode = -1;
  }

  // wait a little for zorba to dump the garbage
  Sleep(1000);
#else
  int lChildExitStatus;

  // wait for the process to exit
  waitpid(lPid, &lChildExitStatus, 0);

  // find out the process exit code if possible
  if (WIFEXITED(lChildExitStatus)) {
    lExitCode = WEXITSTATUS(lChildExitStatus);
  }

  // wait a little for zorba to dump the garbage
  sleep(1);
#endif

  // and call the callback when this happened
  ExitCallbackType lCallback = lThis->getCallback();
  lCallback(lExitCode);

  for (int i = 0; i < 10; i++) {
    std::cout << i << std::endl;
  }
  return NULL;
}

} // namespace zorba
} // namespace debugger
