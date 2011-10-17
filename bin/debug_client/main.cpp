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
#include <zorba/config.h>
#include "debug_command.h"
#include "command_line_handler.h"

using namespace zorba;
using namespace zorba::debugclient;

#ifndef _WIN32_WCE
int
main(int argc, char* argv[])
#else
int
_tmain(int argc, _TCHAR* argv[])
#endif
{
  int lPort = 28028;
  if (argv[1]) {
    std::stringstream lStream(argv[1]);
    lStream >> lPort;
    if (lStream.fail() || argv[2]) {
      std::cerr << "Unknown argument. USAGE: " << argv[0] << " [PORT]" << std::endl;
      return 2;
    }
  }
  try {
    LockFreeQueue<std::size_t> lQueue;
    LockFreeQueue<bool> lContEvent;
    EventHandler lEventHandler(lQueue, lContEvent);
    lEventHandler.init();

    CommandLine lCommandLine;
    CommandLineHandler lCommandLineHandler(lPort, lQueue, lContEvent, lEventHandler, lCommandLine);
    lCommandLineHandler.execute();
  } catch (...) {
    return 4;
  }
  return 0;
}
