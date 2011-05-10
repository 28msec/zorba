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

#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <vector>
#include <iostream>
#include <limits.h>
#include <algorithm>

#ifdef WIN32
#  include <windows.h>

#  ifndef NDEBUG
#    define _CRTDBG_MAP_ALLOC
#    include <stdlib.h>
#    include <crtdbg.h>
#   endif
#else
#  include <unistd.h>
#endif

#include <zorba/item_factory.h>
#include <zorba/singleton_item_sequence.h>
#include <zorba/error_list.h>
#include <zorba/user_exception.h>
#include <zorba/empty_sequence.h>
#include <zorba/file.h>

#include "process.h"

namespace zorba {
namespace processmodule {

/******************************************************************************
 *****************************************************************************/
void create_result_node(
    zorba::Item&        aResult,
    const std::string&  aStandardOut,
    const std::string&  aErrorOut,
    int                 aExitCode,
    zorba::ItemFactory* aFactory)
{
  zorba::Item lResultQName = aFactory->createQName("", "result");
  zorba::Item lExitCodeQName = aFactory->createQName("", "exit-code");
  zorba::Item lOutputQName = aFactory->createQName("", "stdout");
  zorba::Item lErrorQName = aFactory->createQName("", "stderr");
  zorba::Item lNullItem;
  zorba::Item lTypeName = aFactory->createQName("http://www.w3.org/2001/XMLSchema", "untyped");

  std::vector<std::pair<zorba::String, zorba::String> > lNSBindings;

  // root node called result
  aResult = aFactory->createElementNode(
      lNullItem, lResultQName, lTypeName, false, false, lNSBindings);

  // <result><output> aStandardOut </output></result>
  zorba::Item lOutput;
  lOutput = aFactory->createElementNode(
      aResult, lOutputQName, lTypeName, true, false, lNSBindings);
  aFactory->createTextNode(lOutput, aStandardOut);

  // <result><error> aErrorOut </error></result>
  zorba::Item lError;
  lError = aFactory->createElementNode(
      aResult, lErrorQName, lTypeName, true, false, lNSBindings);
  aFactory->createTextNode(lError, aErrorOut);

  // <result><exit-code> aExitCode </exit-code></result>
  zorba::Item lExitCode;
  lExitCode = aFactory->createElementNode(
      aResult, lExitCodeQName, lTypeName, true, false, lNSBindings);
  std::ostringstream lExitCodeString;
  lExitCodeString << aExitCode;
  aFactory->createTextNode(lExitCode, lExitCodeString.str());
}

#ifdef WIN32

/***********************************************
*  throw a descriptive message of the last error
*  accessible with GetLastError() on windows
*/
void throw_last_error(const zorba::String& aFilename, unsigned int aLineNumber){
  LPVOID lpvMessageBuffer;
  TCHAR lErrorBuffer[512];
  FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER|FORMAT_MESSAGE_FROM_SYSTEM,
          NULL, GetLastError(),
          MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
          (LPTSTR)&lpvMessageBuffer, 0, NULL);
  wsprintf(lErrorBuffer,TEXT("Process Error Code: %d - Message= %s"),GetLastError(), (TCHAR *)lpvMessageBuffer);
  LocalFree(lpvMessageBuffer);
  Item lQName = theModule->getItemFactory()->createQName("http://www.zorba-xquery.com/modules/process",
      "XPTY0004");
#ifdef UNICODE
  char error_str[1024];
  WideCharToMultiByte(CP_UTF8, 0, lErrorBuffer, -1, error_str, sizeof(error_str), NULL, NULL);
  throw USER_EXCEPTION(lQName, error_str);
#else
  throw USER_EXCEPTION(lQName, lErrorBuffer);
#endif
}

/******************************************
*  read output from child process on windows
*/
void read_child_output(HANDLE aOutputPipe, std::ostringstream& aTargetStream)
{
  CHAR lBuffer[256];
  DWORD lBytesRead;
  
  while(TRUE)
  {
    if (
      !ReadFile(aOutputPipe,lBuffer,sizeof(lBuffer),&lBytesRead,NULL) 
      || !lBytesRead
    )
    {
      if (GetLastError() == ERROR_BROKEN_PIPE)
        break; // finished
      else{
      
         // couldn't read from pipe
         throw_last_error(__FILE__, __LINE__);
      }
    }
    
    // remove the windows specific carriage return outputs
   // std::stringstream lTmp;
   // lTmp.write(lBuffer,lBytesRead);
   // std::string lRawString=lTmp.str();
   // std::replace( lRawString.begin(), lRawString.end(), '\r', ' ' );
   // aTargetStream.write(lRawString.c_str(),static_cast<std::streamsize>(lRawString.length()));
    for(DWORD i=0;i<lBytesRead;i++)
    {
      if(lBuffer[i] != '\r')
        aTargetStream << lBuffer[i];
    }
    lBytesRead = 0;
  }
}

/******************************************
*  Create a child process on windows with
*  redirected output
*/
BOOL create_child_process(HANDLE aStdOutputPipe,HANDLE aStdErrorPipe,const std::string& aCommand,PROCESS_INFORMATION& aProcessInformation){
  STARTUPINFO lChildStartupInfo;
  BOOL result=FALSE;
  
  // set the output handles
  FillMemory(&lChildStartupInfo,sizeof(lChildStartupInfo),0);
  lChildStartupInfo.cb = sizeof(lChildStartupInfo);
  GetStartupInfo(&lChildStartupInfo);
  lChildStartupInfo.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;
  lChildStartupInfo.wShowWindow = SW_HIDE; // don't show the command window
  lChildStartupInfo.hStdOutput = aStdOutputPipe;
  lChildStartupInfo.hStdError  = aStdErrorPipe;

  // convert from const char* to char*
  size_t length = strlen(aCommand.c_str());
#ifdef UNICODE
  WCHAR *tmpCommand = new WCHAR[length+1];
  MultiByteToWideChar(CP_UTF8, 0, aCommand.c_str(), -1, tmpCommand, length+1);
#else
  char *tmpCommand=new char[length+1];
  strcpy (tmpCommand,aCommand.c_str());
  tmpCommand[length]='\0';
#endif

  try{
  
    // settings for the child process      
    LPCTSTR lApplicationName=NULL;
    LPTSTR lCommandLine=tmpCommand;
    LPSECURITY_ATTRIBUTES lProcessAttributes=NULL;
    LPSECURITY_ATTRIBUTES lThreadAttributes=NULL;
    BOOL lInheritHandles=TRUE; // that's what we want
    DWORD lCreationFlags=CREATE_NEW_CONSOLE;
    LPVOID lEnvironment=NULL;
    LPCTSTR lCurrentDirectory=NULL; // same as main process
    
    // start child
    result=CreateProcess(
          lApplicationName,lCommandLine,lProcessAttributes,
          lThreadAttributes,lInheritHandles,lCreationFlags,
          lEnvironment,lCurrentDirectory,&lChildStartupInfo,
          &aProcessInformation);
          
  }catch(...){
    delete[] tmpCommand;
    tmpCommand=0;
    throw;  
  }
        
  delete[] tmpCommand;
  tmpCommand=0;
        
  return result;
}

/******************************************
*  run a process that executes the aCommand
*  in a new console and reads the output
*/
int run_process(const std::string& aCommand,std::ostringstream& aTargetOutStream,std::ostringstream& aTargetErrStream)
{
  HANDLE lOutRead, lErrRead, lStdOut, lStdErr;
  SECURITY_ATTRIBUTES lSecurityAttributes;
  PROCESS_INFORMATION lChildProcessInfo;
  DWORD exitCode=0;
    
  // prepare security attributes
  lSecurityAttributes.nLength= sizeof(lSecurityAttributes);
  lSecurityAttributes.lpSecurityDescriptor = NULL;
  lSecurityAttributes.bInheritHandle = TRUE;

  // create output pipes
  if(
      !CreatePipe(&lOutRead,&lStdOut,&lSecurityAttributes,1024*1024) // std::cout >> lOutRead
      || !CreatePipe(&lErrRead,&lStdErr,&lSecurityAttributes,1024*1024) // std::cerr >> lErrRead
    ){
    throw USER_EXCEPTION(
        err::XPTY0004, "Couldn't create one of std::cout/std::cerr pipe for child process execution."
    );
  };
  
  //start child process
  BOOL ok=create_child_process(lStdOut,lStdErr,aCommand,lChildProcessInfo);
  if(ok==TRUE)
  {

    // close unneeded handle  
    CloseHandle(lChildProcessInfo.hThread);
    
    // wait for the process to finish
    WaitForSingleObject(lChildProcessInfo.hProcess,INFINITE);
    if (!GetExitCodeProcess(lChildProcessInfo.hProcess, &exitCode))
    {
      std::stringstream lErrorMsg;
      lErrorMsg 
        << "Couldn't get exit code from child process. Executed command: '" << aCommand << "'.";
      throw USER_EXCEPTION(
        err::XPTY0004, lErrorMsg.str().c_str()
      );
    }
  
    CloseHandle(lChildProcessInfo.hProcess);
    CloseHandle(lStdOut);
    CloseHandle(lStdErr);

    // read child's output
    read_child_output(lOutRead,aTargetOutStream);
    read_child_output(lErrRead,aTargetErrStream);

    // close 
    CloseHandle(lOutRead);
    CloseHandle(lErrRead);

 }else{
    CloseHandle(lStdOut);
    CloseHandle(lStdErr);
    CloseHandle(lOutRead);
    CloseHandle(lErrRead);
  
     // couldn't launch process
     throw_last_error(__FILE__, __LINE__);
  };
  
  
  return exitCode;
}

#else

#define READ  0
#define WRITE 1

pid_t zorba_popen(const char *command, int *infp, int *outfp, int *errfp)
{
    int p_stdin[2];
    int p_stdout[2];
    int p_stderr[2];
    pid_t pid;

    if (pipe(p_stdin) != 0 || pipe(p_stdout) != 0 || pipe(p_stderr) != 0)
        return -1;

    pid = fork();

    if (pid < 0)
        return pid;
    else if (pid == 0)
    {
        close(p_stdin[WRITE]);
        dup2(p_stdin[READ], 0);   // duplicate stdin

        close(p_stdout[READ]);
        dup2(p_stdout[WRITE], 1); // duplicate stdout

        close(p_stderr[READ]);
        dup2(p_stderr[WRITE], 2); // duplicate stderr

        execl("/bin/sh", "sh", "-c", command, NULL);
        perror("execl");
        exit(1);
    }

    if (infp == NULL)
        close(p_stdin[WRITE]);
    else
        *infp = p_stdin[WRITE];

    if (outfp == NULL)
        close(p_stdout[READ]);
    else
        *outfp = p_stdout[READ];

    if (errfp == NULL)
        close(p_stderr[READ]);
    else
        *errfp = p_stderr[READ];

    close(p_stdin[READ]);   // We only write to the forks stdin anyway
    close(p_stdout[WRITE]); // and we only read from its stdout
    close(p_stderr[WRITE]); // and we only read from its stderr

    return pid;
}
#endif

/******************************************************************************
 *****************************************************************************/
zorba::ItemSequence_t
ExecFunction::evaluate(
  const Arguments_t& aArgs,
  const zorba::StaticContext* aSctx,
  const zorba::DynamicContext* aDctx) const
{
  std::string lCommand;
  std::vector<std::string> lArgs;

  lCommand = getOneStringArgument(aArgs, 0).c_str();

  if (aArgs.size() > 1)
  {
    zorba::Item lArg;
    Iterator_t arg1_iter = aArgs[1]->getIterator();
    arg1_iter->open();
    while (arg1_iter->next(lArg))
    {
      lArgs.push_back(lArg.getStringValue().c_str());
    }
    arg1_iter->close();
  }

  std::ostringstream lTmp;

#ifdef WIN32
  // execute process command in a new commandline
  // with quotes at the beggining and at the end
  lTmp << "cmd /C \"";
#endif
 
  lTmp << "\"" << lCommand << "\""; //quoted for spaced paths/filenames
  size_t pos=0;
  for (std::vector<std::string>::const_iterator lIter = lArgs.begin();
       lIter != lArgs.end(); ++lIter)
  {
    pos = (*lIter).rfind('\\')+(*lIter).rfind('/');
    if (int(pos)>=0)
      lTmp << " \"" << *lIter << "\"";
    else
      lTmp << " " << *lIter;
  }
#ifdef WIN32
  lTmp << "\"";   // with quotes at the end for commandline
#endif
  
  std::ostringstream lStdout;
  std::ostringstream lStderr;

#ifdef WIN32
  std::string lCommandLineString=lTmp.str();
  int status = run_process(lCommandLineString,lStdout,lStderr);
  
  if (status != 0)
  {
    
  //  std::stringstream lErrorMsg;
  //  lErrorMsg <<
  //      "[FAILURE] command execution failed. Exit code: " << status << "." ;
  //  throw zorba::ExternalFunctionData::createZorbaException(
  //        XPTY0004,lErrorMsg.str().c_str(), __FILE__, __LINE__);
    std::cerr << "[FAILURE] command execution failed. Exit code: " << status
      << std::endl;
  }

#else //not WIN32

  int outfp;
  int errfp;
  int status;

  status=zorba_popen(lTmp.str().c_str(), NULL, &outfp, &errfp);
  if ( status<=0 )
  {
    std::cerr << "[FAILURE] command execution failed. Exit code: " << status
      << std::endl;
  }
  else
  {
    char lBuf[PATH_MAX];
    ssize_t length = 0;
    while ( (length=read(outfp, lBuf, PATH_MAX)) > 0 )
    {
      lStdout.write(lBuf, length);
    }

    status = close(outfp);

    while ( (length=read(errfp, lBuf, PATH_MAX)) > 0 )
    {
      lStderr.write(lBuf, length);
    }

    status = close(errfp);

    if ( status < 0 )
    {
      std::cerr << "[FAILURE] command execution failed. Exit code: " << errno
        << std::endl;
    }
  }
#endif // WIN32

  zorba::Item lResult;
  create_result_node(lResult, lStdout.str(), lStderr.str(), status,
                     theModule->getItemFactory());

  return zorba::ItemSequence_t(new zorba::SingletonItemSequence(lResult));
}

String ExecFunction::getOneStringArgument (const Arguments_t& aArgs, int aPos)
  const
{
  Item lItem;
  Iterator_t  args_iter = aArgs[aPos]->getIterator();
  args_iter->open();
  if (!args_iter->next(lItem))
  {
    std::stringstream lErrorMessage;
    lErrorMessage << "An empty-sequence is not allowed as "
                  << aPos << ". parameter.";
    Item lQName = theModule->getItemFactory()->createQName("http://www.zorba-xquery.com/modules/process", "XPTY0004");
    USER_EXCEPTION(lQName, lErrorMessage.str());
  }

  zorba::String lTmpString = lItem.getStringValue();
  if (args_iter->next(lItem))
  {
    std::stringstream lErrorMessage;
    lErrorMessage << "A sequence of more then one item is not allowed as "
                  << aPos << ". parameter.";
    Item lQName = theModule->getItemFactory()->createQName("http://www.zorba-xquery.com/modules/process", "XPTY0004");
    USER_EXCEPTION(lQName, lErrorMessage.str());
  }
  args_iter->close();
  return lTmpString;
}

/******************************************************************************
 *****************************************************************************/
zorba::StatelessExternalFunction*
ProcessModule::getExternalFunction(const zorba::String& aLocalname)
{
  FuncMap_t::const_iterator lFind = theFunctions.find(aLocalname);
  zorba::StatelessExternalFunction*& lFunc = theFunctions[aLocalname];
  if (lFind == theFunctions.end())
  {
    if (aLocalname.equals("exec"))
    {
      lFunc = new ExecFunction(this);
    }
  }
  return lFunc;
}

void ProcessModule::destroy()
{
  if (!dynamic_cast<ProcessModule*>(this)) {
    return;
  }
  delete this;
}

/*
ProcessModule::~ProcessModule()
{
}
*/
ItemFactory* ProcessModule::theFactory = 0;


} /* namespace processmodule */
} /* namespace zorba */

/*
extern "C" ZORBA_MODULES_DLL_EXPORT zorba::ExternalModule* createModule()
{
  return new zorba::processmodule::ProcessModule();
}*/

#ifdef WIN32
#  define DLL_EXPORT __declspec(dllexport)
#else
#  define DLL_EXPORT __attribute__ ((visibility("default")))
#endif

extern "C" DLL_EXPORT zorba::ExternalModule* createModule() {
  return new zorba::processmodule::ProcessModule();
}
/* vim:set et sw=2 ts=2: */
