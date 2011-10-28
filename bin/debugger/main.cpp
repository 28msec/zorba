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

#include <zorba/config.h>

#include "command_prompt.h"
#include "command_line_handler.h"

using namespace zorba;
using namespace zorba::debugger;

#ifdef WIN32
size_t ExecuteProcess(std::wstring aPathToExe, std::wstring aParameters, size_t SecondsToWait) 
{ 
    DWORD iReturnVal = 0;
    DWORD dwExitCode = 0;
    std::wstring lTempStr = L"";

    // Add a space to the beginning of the Parameters
    if (aParameters.size() != 0) {
      if (aParameters[0] != L' ') {
        aParameters.insert(0, L" ");
      }
    }

    // The first parameter needs to be the exe itself
    lTempStr = aPathToExe;
    std::wstring::size_type iPos = lTempStr.find_last_of(L"\\");
    lTempStr.erase(0, iPos + 1);
    aParameters = lTempStr.append(aParameters);

    // CreateProcessW can modify Parameters thus we allocate needed memory
    wchar_t * pwszParam = new wchar_t[aParameters.size() + 1];
    if (pwszParam == 0) {
      return 1;
    }
    const wchar_t* pchrTemp = aParameters.c_str();
    wcscpy_s(pwszParam, aParameters.size() + 1, pchrTemp); 

    // CreateProcess API initialization
    STARTUPINFOW siStartupInfo;
    PROCESS_INFORMATION piProcessInfo;
    memset(&siStartupInfo, 0, sizeof(siStartupInfo));
    memset(&piProcessInfo, 0, sizeof(piProcessInfo));
    siStartupInfo.cb = sizeof(siStartupInfo);

    BOOL lResult = CreateProcessW(
      const_cast<LPCWSTR>(aPathToExe.c_str()),
      pwszParam, 0, 0, false,
      CREATE_DEFAULT_ERROR_MODE, 0, 0,
      &siStartupInfo, &piProcessInfo);

    if (lResult) {
      // Watch the process
      dwExitCode = WaitForSingleObject(piProcessInfo.hProcess, (SecondsToWait * 1000));
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
}
#else

// add execute process in Linux

#endif


void printUsage(std::string& aProgram)
{
  std::cerr << "Usage:" << std::endl
    << "\t" << aProgram << " [-p PORT] <zorba_executable> <zorba_arguments>" << std::endl;
}

#ifndef _WIN32_WCE
int
main(int argc, char* argv[])
#else
int
_tmain(int argc, _TCHAR* argv[])
#endif
{
  std::string lProgram(argv[0]);
  std::string::size_type lPos = lProgram.find_last_of('\\');
  lProgram = lProgram.substr(lPos + 1);

  if (argc < 2 || (argv[1] == "-p" && argc < 3)) {
    printUsage(lProgram);
    return 1;
  }

  int lPort = 28028;
  if (argv[1] == "-p") {
    std::stringstream lStream(argv[2]);
    lStream >> lPort;
    if (lStream.fail() || argv[2]) {
      std::cerr << "Invalid port: " << argv[2] << std::endl;
      printUsage(lProgram);
      return 2;
    }
  }
#ifndef NDEBUG
  std::cout << "Communicating on port: " << lPort << std::endl;
#endif

  try {
    LockFreeQueue<std::size_t> lQueue;
    LockFreeQueue<bool> lContEvent;
    EventHandler lEventHandler(lQueue, lContEvent);
    lEventHandler.init();

    CommandPrompt lCommandPrompt;
    CommandLineHandler lCommandLineHandler(lPort, lQueue, lContEvent, lEventHandler, lCommandPrompt);

    // now fork to start a zorba

    std::string lExec(argv[1]);
    std::wstring lExecW, lParamsW;
    lExecW.assign(lExec.begin(), lExec.end());

#ifndef NDEBUG
    std::cout << "Zorba arguments:" << std::endl;
#endif
    lParamsW.append(L"-d ");
#ifndef NDEBUG
    std::cout << "\tArgument 1: -d" << std::endl;
#endif

    int offset = argv[1] == "-p" ? 4 : 2;
    for (int j = 0; j + offset < argc; j++) {
#ifndef NDEBUG
      std::cout << "\tArgument " << j + 2 << ": " << argv[j + offset] << std::endl;
#endif
      std::string lArg(argv[j + offset]);
      std::wstring lArgW;
      lArgW.assign(lArg.begin(), lArg.end());
      lParamsW.append(lArgW);
      lParamsW.append(L" ");
    }

#ifdef WIN32
    int lResult = ExecuteProcess(lExecW, lParamsW, 0);
    if (lResult) {
      return lResult;
    }
#else
    std::cout << "On Linux, Zorba is not started by the debugger. Start it manually!"
#endif

    lCommandLineHandler.execute();
  } catch (...) {
    return 4;
  }
  return 0;
}
