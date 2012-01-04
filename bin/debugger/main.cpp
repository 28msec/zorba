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

#ifdef WIN32
# include <windows.h>
# include <string.h>
# include <strsafe.h>
#endif

#include <vector>

#include <zorba/config.h>

#include "command_prompt.h"
#include "command_line_handler.h"
#include "process_listener.h"

using namespace zorba;
using namespace zorba::debugger;

class XqdbClient {

  public:

    XqdbClient(unsigned int aPort)
    {
      theIdQueue = new LockFreeQueue<std::size_t>();
      theQuitQueue = new LockFreeQueue<bool>();
      theEventHandler = new EventHandler(*theIdQueue, *theQuitQueue);
      theEventHandler->init();

      theCommandPrompt = new CommandPrompt();
      theCommandLineHandler = new CommandLineHandler(aPort, *theIdQueue, *theQuitQueue, theEventHandler, theCommandPrompt);
    }

    ~XqdbClient()
    {
      if (theCommandLineHandler) {
        delete theCommandLineHandler;
      }
      if (theCommandPrompt) {
        delete theCommandPrompt;
      }
      if (theEventHandler) {
        delete theEventHandler;
      }

      delete theIdQueue;
      delete theQuitQueue;
    }

    void start()
    {
      theCommandLineHandler->execute();
    }

  private:

    LockFreeQueue<std::size_t>* theIdQueue;
    LockFreeQueue<bool>*        theQuitQueue;

    EventHandler*       theEventHandler;
    CommandPrompt*      theCommandPrompt;
    CommandLineHandler* theCommandLineHandler;
};


XqdbClient* theClient;


void
onExitProcess(ExitCode aExitCode) {
  //if (aExitCode != -1) {
  //  std::cout << "Zorba has exited with code: " << aExitCode << std::endl;
  //}
  std::cout << "Terminating debugger client."<< std::endl;
  // TODO: and the memory?

  delete theClient;
  exit(aExitCode);
}

int
startZorba(std::string& aExec, std::vector<std::string>& aArgs) 
{
#ifdef WIN32
  // **************************
  // start a process on Windows

  DWORD iReturnVal = 0;

  std::wstring lExec;
  std::wstring lArgs;

  lExec.assign(aExec.begin(), aExec.end());

  // the executable must be the first in the list of arguments
  lArgs.append(L"\"");
  lArgs.append(lExec);
  lArgs.append(L"\"");

  for (std::vector<std::string>::size_type j = 0; j < aArgs.size(); j++) {
    std::string lArg(aArgs.at(j));
    std::wstring lArgW;
    lArgW.assign(lArg.begin(), lArg.end());
    lArgs.append(L" ");
    lArgs.append(lArgW);
  }

  // CreateProcessW can modify Parameters thus we allocate needed memory
  wchar_t * pwszParam = new wchar_t[lArgs.size() + 1];
  if (pwszParam == 0) {
    return 1;
  }
  const wchar_t* pchrTemp = lArgs.c_str();
  wcscpy_s(pwszParam, lArgs.size() + 1, pchrTemp); 

  // CreateProcess API initialization
  STARTUPINFOW siStartupInfo;
  PROCESS_INFORMATION piProcessInfo;
  memset(&siStartupInfo, 0, sizeof(siStartupInfo));
  memset(&piProcessInfo, 0, sizeof(piProcessInfo));
  siStartupInfo.cb = sizeof(siStartupInfo);

  BOOL lResult = CreateProcessW(
    const_cast<LPCWSTR>(lExec.c_str()),
    pwszParam, 0, 0, false,
    CREATE_DEFAULT_ERROR_MODE, 0, 0,
    &siStartupInfo, &piProcessInfo);

  if (lResult) {
    // Watch the process
    ProcessListener* lPl = new ProcessListener(piProcessInfo.hProcess, &onExitProcess);
  }
  else {
    // CreateProcess failed
    iReturnVal = GetLastError();
    LPVOID lpMsgBuf;
    LPVOID lpDisplayBuf;

    FormatMessage(
      FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
      NULL,
      iReturnVal,
      MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
      (LPTSTR) &lpMsgBuf,
      0, NULL);

    // Display the error message and exit the process

    lpDisplayBuf = (LPVOID)LocalAlloc(
      LMEM_ZEROINIT,
      (lstrlen((LPCTSTR)lpMsgBuf) + 40) * sizeof(TCHAR));

    StringCchPrintf(
      (LPTSTR)lpDisplayBuf,
      LocalSize(lpDisplayBuf) / sizeof(TCHAR),
      TEXT("Error (%d) when starting zorba: %s"),
      iReturnVal,
      lpMsgBuf);

    std::wstring lErrorW((wchar_t*)lpDisplayBuf);
    std::string lError;
    lError.assign(lErrorW.begin(), lErrorW.end());
    std::cout << lError << std::endl;

    LocalFree(lpMsgBuf);
    LocalFree(lpDisplayBuf);
  }

  // Free memory
  delete[]pwszParam;
  pwszParam = 0;

  // Release handles
  CloseHandle(piProcessInfo.hProcess);
  CloseHandle(piProcessInfo.hThread);

  return iReturnVal; 

#else
  // ************************
  // start a process on Linux

  pid_t pID = fork();
  if (pID == 0) {
    // Code only executed by child process
    std::stringstream lCommand;
    lCommand << aExec;
    for (std::vector<std::string>::size_type j = 0; j < aArgs.size(); j++) {
      lCommand << " " << aArgs.at(j);
    }

    int lRes = system(lCommand.str().c_str());
    exit(lRes);
  }
  else {
    // Code only executed by parent process
    if (pID < 0) {
      std::cerr << "Failed to fork Zorba" << std::endl;
      return pID;
    }
    
    // pID > 0

    // Watch the process
    //ProcessListener* lPl =
    new ProcessListener(pID, &onExitProcess);

    return 0;
  }
#endif
}

void printUsage(std::string& aProgram)
{
  std::cerr << "Usage:" << std::endl
    << "    " << aProgram << " <zorba_arguments>" << std::endl
    << "        this will start a debugger command line and a zorba process with the given arguments" << std::endl;
}

bool
processArguments(
  int argc,
  char* argv[],
  std::string& aProgram,
  bool& aStandalone,
  std::string& aZorba,
  unsigned int& aPort,
  std::vector<std::string>& aZorbaArgs)
{
  aPort = 28028;

  // find the path to Zorba and this executable name
  aProgram = argv[0];

#ifdef WIN32
  char lSep = '\\';
#else
  char lSep = '/';
#endif
  std::string::size_type lPos = aProgram.find_last_of(lSep);

  std::stringstream lZs;

  if (lPos == aProgram.npos) {
    lZs << "." << lSep;
  } else {
    lZs << aProgram.substr(0, lPos + 1);
    aProgram = aProgram.substr(lPos + 1);
  }
  lZs << "zorba";
#ifdef WIN32
  lZs << ".exe";
#endif
  aZorba = lZs.str();


  bool lHasFileArg = false;
  bool lHasQueryArg = false;
  bool lHasQueryVal = false;

  // find if the user asked for help or specified a specific port
  for (int i = 1; i < argc; i++) {
    std::string lArg = argv[i];
    if (lArg == "-h" || lArg == "--help") {
      return false;
    }
    else if (lArg == "-p" || lArg == "--debug-port") {
      // if there is one more argument
      if (i < argc - 1) {
        // get the port value
        int lPort;
        std::stringstream lStream(argv[i + 1]);
        lStream >> lPort;
        if (!lStream.fail()) {
          aPort = lPort;
        }
      }
    }
    else if (lArg == "-f") {
      lHasFileArg = true;
    }
    else if (lArg == "-q") {
      lHasQueryArg = true;
      if (++i < argc) {
        lHasQueryVal = true;
      }
    }
  }

  if (!lHasFileArg || !lHasQueryArg || !lHasQueryVal) {
    std::cout << "Not enough arguments to start Zorba." << std::endl;
    std::cout << "Running the standalone XQuery debugger client on port: " << aPort << std::endl;
    return true;
  }

  // zorba will need the -d flag
  aZorbaArgs.push_back("-d");

  // gather all arguments (excepting the program name)
  for (int i = 1; i < argc; i++) {
    aZorbaArgs.push_back(argv[i]);
  }

  aStandalone = false;
  return true;
}

#ifndef _WIN32_WCE
int
main(int argc, char* argv[])
#else
int
_tmain(int argc, _TCHAR* argv[])
#endif
{
  // **************************************************************************
  // processing arguments

  std::string lProgram, lZorbaExec;
  unsigned int lPort = 28028;
  std::vector<std::string> lZorbaArgs;

  bool lStandalone = true;
  if (!processArguments(argc, argv, lProgram, lStandalone, lZorbaExec, lPort, lZorbaArgs)) {
    printUsage(lProgram);
    return 1;
  }

#ifndef NDEBUG
  // **************************************************************************
  // debug reporting

  if (!lStandalone) {
    std::cout << "Communication port: " << lPort << std::endl;
    std::cout << "Zorba executable:   " << lZorbaExec << std::endl;
    std::cout << "Zorba arguments:    ";
    for (std::vector<std::string>::size_type j = 0; j < lZorbaArgs.size(); j++) {
      std::cout << lZorbaArgs.at(j) << " ";
    }
    std::cout << std::endl;
  }
#endif

  try {
    // **************************************************************************
    // start a zorba

    if (!lStandalone) {
      int lResult = startZorba(lZorbaExec, lZorbaArgs);
      if (lResult) {
        return lResult;
      }
    } else {
      std::cout << "Listening for an incomming Zorba connection on port " << lPort << "..." << std::endl;
    }

    // **************************************************************************
    // start the debugger command line

    theClient =  new XqdbClient(lPort);
    theClient->start();

    //tCommandLineHandler.execute();

#ifndef WIN32
    int lStatus;
    wait(&lStatus);
#endif

    delete theClient;

  } catch (...) {
    delete theClient;
    return -1;
  }

  return 0;
}
