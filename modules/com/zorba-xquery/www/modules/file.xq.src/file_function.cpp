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

#include "file_function.h"

#include <sstream>

#include <zorba/zorba.h>
#include <zorba/file.h>
#include <zorba/util/path.h>

#include "file_module.h"

#include <stdlib.h>
#include <stdio.h>
#ifdef WIN32
#include <Windows.h>
#include <direct.h>
#else
#include <unistd.h>
#endif

static zorba::String getCurrentPath()
{
#ifdef WIN32
  wchar_t* wbuffer = _wgetcwd(NULL, 0);
  char *buffer = (char*)malloc(1024);
  WideCharToMultiByte(CP_UTF8, 0, wbuffer, -1, buffer, 1024, NULL, NULL);
#else
  char buffer[2048];
  getcwd(buffer, 2048);
#endif
  zorba::String result(buffer);
#ifdef WIN32
  free(buffer);
#endif
  return result;
}

namespace zorba { namespace filemodule {

FileFunction::FileFunction(const FileModule* aModule)
        : theModule(aModule)
{
}

FileFunction::~FileFunction()
{
}

String
FileFunction::getURI() const
{
  return theModule->getURI();
}

String
FileFunction::getOneStringArg(
  const StatelessExternalFunction::Arguments_t& aArgs,
  int aPos)
{
  Item lItem;
  Iterator_t args_iter = aArgs[aPos]->getIterator();
  args_iter->open();
  if (!args_iter->next(lItem)) {
    std::stringstream lErrorMessage;
    lErrorMessage << "An empty-sequence is not allowed as " 
                  << aPos << ". parameter.";
    throwError(lErrorMessage.str(), XPTY0004);
  }
  zorba::String lTmpString = lItem.getStringValue();
  if (args_iter->next(lItem)) {
    std::stringstream lErrorMessage;
    lErrorMessage << "A sequence of more then one item is not allowed as "
                  << aPos << ". parameter.";
    throwError(lErrorMessage.str(), XPTY0004);
  }
  args_iter->close();
  return lTmpString;
}

bool
FileFunction::getOneBooleanArg(
  const StatelessExternalFunction::Arguments_t& aArgs,
  int aPos)
{
  bool lResult = false;

  Item lCreateItem;
  Iterator_t arg1_iter = aArgs[aPos]->getIterator();
  arg1_iter->open();
  if (arg1_iter->next(lCreateItem)) {
    lResult = lCreateItem.getBooleanValue();
  }
  arg1_iter->close();

  return lResult;
}


String
FileFunction::getFilePathString(
    const StaticContext* aSctxCtx,
    const StatelessExternalFunction::Arguments_t& aArgs,
    int aPos)
{
  String lFileArg = getOneStringArg(aArgs, aPos);

  return (filesystem_path::normalize_path
    (lFileArg.c_str(), getCurrentPath().c_str()));
}

String
FileFunction::pathSeparator() {
  return File::getPathSeparator();
}

String
FileFunction::pathToFullOSPath(const String& aPath) {
  File_t lFile = File::createFile(aPath.c_str());
  std::string lPath = lFile->getFilePath();

  return String(lPath);
}

String
FileFunction::pathToOSPath(const String& aPath) {
  File_t lFile = File::createFile(aPath.c_str());
  std::string lPath = lFile->getFilePath();

  return String(lPath);
}

String
FileFunction::pathToUriString(const String& aPath) {
  std::stringstream lErrorMessage;

  if(aPath.startsWith("file://")) {
    lErrorMessage << "Please provide a path, not a URI";
    throwError(lErrorMessage.str(), XPTY0004);
  }

  File_t lFile = File::createFile(aPath.c_str());

  std::string lPath = lFile->getFileUri();


  return String(lPath);
}

void
FileFunction::throwError(
    const std::string aErrorMessage,
    const XQUERY_ERROR& aErrorType)
{
  throw zorba::ExternalFunctionData::createZorbaException(aErrorType,
      aErrorMessage.c_str(), __FILE__, __LINE__);
}

#ifdef WIN32
bool
FileFunction::isValidDriveSegment(
    String& aString)
{
  aString = aString.uppercase();
  // the drive segment has one of the forms: "C:", "C%3A"
  if ((aString.length() != 2 && aString.length() != 4) ||
      (aString.length() == 2 && !aString.endsWith(":")) ||
      (aString.length() == 4 && !aString.endsWith("%3A"))) {
    return false;
  }

  char lDrive = aString.charAt(0);
  // the string is already upper case
  if (lDrive < 65 || lDrive > 90) {
    return false;
  }
  return true;
}
#endif

} /* namespace filemodule */ } /* namespace zorba */
