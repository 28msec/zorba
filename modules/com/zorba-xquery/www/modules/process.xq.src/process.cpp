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
#include "process.h"
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <vector>
#include <iostream>
#include <limits.h>

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
#include <zorba/empty_sequence.h>
#include <zorba/file.h>

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

#ifndef WIN32

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
    while (aArgs[1]->next(lArg))
    {
      lArgs.push_back(lArg.getStringValue().c_str());
    }
  }

  std::ostringstream lTmp;

  lTmp << lCommand;
  for (std::vector<std::string>::const_iterator lIter = lArgs.begin();
       lIter != lArgs.end(); ++lIter)
  {
    lTmp << " " << *lIter;
  }

  std::ostringstream lStdout;
  std::ostringstream lStderr;

#ifdef WIN32
  int status = system(lTmp.str().c_str());
  if (status != 0)
  {
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
    char outbuf[PATH_MAX];
    int length = 0;
    while ( (length=read(outfp, outbuf, PATH_MAX)) > 0 )
    {
      outbuf[length] = '\0';
      lStdout << outbuf;
    }

    status = close(outfp);

    char errbuf[PATH_MAX];
    while ( (length=read(errfp, errbuf, PATH_MAX)) > 0 )
    {
      errbuf[length] = '\0';
      lStderr << errbuf;
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
  if (!aArgs[aPos]->next(lItem))
  {
    std::stringstream lErrorMessage;
    lErrorMessage << "An empty-sequence is not allowed as "
                  << aPos << ". parameter.";
    throwError(lErrorMessage.str(), XPTY0004);
  }

  zorba::String lTmpString = lItem.getStringValue();
  if (aArgs[aPos]->next(lItem))
  {
    std::stringstream lErrorMessage;
    lErrorMessage << "A sequence of more then one item is not allowed as "
                  << aPos << ". parameter.";
    throwError(lErrorMessage.str(), XPTY0004);
  }
  return lTmpString;
}

void ExecFunction::throwError(
    const std::string aErrorMessage,
    const XQUERY_ERROR& aErrorType)
{
  throw zorba::ExternalFunctionData::createZorbaException(aErrorType,
      aErrorMessage.c_str(), __FILE__, __LINE__);
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
