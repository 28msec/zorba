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

#include "file_module.h"

namespace zorba { namespace filemodule {

const std::string
FileFunction::FILE_SCHEMA("file://");

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
  if (!aArgs[aPos]->next(lItem)) {
    std::stringstream lErrorMessage;
    lErrorMessage << "An empty-sequence is not allowed as " 
                  << aPos << ". parameter.";
    throwError(lErrorMessage.str(), XPTY0004);
  }
  zorba::String lTmpString = lItem.getStringValue();
  if (aArgs[aPos]->next(lItem)) {
    std::stringstream lErrorMessage;
    lErrorMessage << "A sequence of more then one item is not allowed as "
                  << aPos << ". parameter.";
    throwError(lErrorMessage.str(), XPTY0004);
  }
  return lTmpString;
}

String
FileFunction::getFilePathString(
    const StaticContext* aSctxCtx,
    const StatelessExternalFunction::Arguments_t& aArgs,
    int aPos)
{
  std::stringstream lErrorMessage;
  String lFileArg = getOneStringArg(aArgs, aPos);

  // ****************************************************
  // if we have an absolute file URI
  // e.g.: file://localhost/C:/my%20file.txt
  if(lFileArg.startsWith(FILE_SCHEMA.c_str())) {
    // make sure the URI is a valid one
    aSctxCtx->resolve("", lFileArg);

    // test if we have a valid URI
    lFileArg = lFileArg.substring(FILE_SCHEMA.length());
    int lIndex = lFileArg.indexOf("/");

    if (lIndex > 0) { // if the file URI has a host
                      // e.g.: file://localhost/C:/my%20file.txt
      String lAuthorityString = lFileArg.substring(0, lIndex);
      // only allow "localhost" as the authoriry
      // This makes this implementation the same with the Zorba URI type.
      // If this functionality is changed, please make the same changes
      // in the Zorba URI type.
      if (!lAuthorityString.compare("localhost") == 0 ) {
        lErrorMessage << "Invalid host: \"" << lAuthorityString
            << "\". Only \"localhost\" is allowed as host in a file URI.";
        throwError(lErrorMessage.str(), XPTY0004);
      }
    } else if (lIndex < 0) { // if the file URI doesn't have a path: file://abc
        throwError("The file URI contains no path.", XPTY0004);
    }

#ifdef WIN32
    // remove the first '/' from path: /C:/my%20file.txt
    ++lIndex;
#endif

    // remove the host from the URI
    lFileArg = lFileArg.substring(lIndex);

#ifdef WIN32
    // test for a valid drive segment
    String lDriveString;
    int lNext = lFileArg.indexOf("/");
    if (lNext >= 0) {
      lDriveString = lFileArg.substring(0, lNext);
    } else {
      lDriveString = lFileArg.substring(0);
    }
    if(!isValidDriveSegment(lDriveString)) {
      lErrorMessage << "Invalid drive specification: \""
          << lDriveString << "\".";
      throwError(lErrorMessage.str(), XPTY0004);
    }
#endif

    // decode the resulting URL encoded path
    // e.g.: C%3A/my%20file.txt, C:/my%20file.txt, /usr/my%20file.xml

    lFileArg = lFileArg.decodeFromUri();
  }
  
  // ****************************************************
  // if we have a relative file URI
  // e.g.: "/blub 1/file", "myfile"
  else {

    bool lAbsolutePath = false;

    // check if we have an absolute path: /users, C:\test
#ifdef WIN32
    // the underlying Zorba implementation accepts both separators for WIN32
    // so detect the first occurence of any of them
    int lIndex = lFileArg.indexOf("\\");
    int lIndexS = lFileArg.indexOf("/");
    if (lIndex < 0) {
      lIndex = lIndexS;
    } else if (lIndexS >=0 ) {
      lIndex = std::min(lIndex, lIndexS);
    }

    // test for a valid drive segment
    String lDriveString;
    if (lIndex >= 0) {
      lDriveString = lFileArg.substring(0, lIndex);
    } else {
      lDriveString = lFileArg.substring(0);
    }
    lAbsolutePath = isValidDriveSegment(lDriveString);
#else
    // only check if the path starts with "/"
    lAbsolutePath = (lFileArg.indexOf("/") == 0);
#endif

    // if a relative path, we have to resolve it against the base URI
    if (!lAbsolutePath) {
      // first encode the user input
      // NOTE: this encodes also the allowed characters like '/', '&' but
      //       we are only interested in resolving and obtaining a file
      //       system path. The user input is NOT considered an URI!
      //       The file system behave accordingly if wrong signs are used.
      lFileArg = lFileArg.encodeForUri();

      // resolve the relative path against the base URI
      lFileArg = aSctxCtx->resolve(aSctxCtx->getBaseURI(), lFileArg);
      
      // remove the file scheme (Zorba returns no host)
      int lIndex = FILE_SCHEMA.length();
#ifdef WIN32
      ++lIndex;
#endif
      lFileArg = lFileArg.substring(lIndex);
      
      // decode the path
      lFileArg = lFileArg.decodeFromUri();
    }

    // no other encoding or decoding if already an absolute path
    // simply pass it further

  }
  return lFileArg;
}

String
FileFunction::pathToUriString(const String& aPath) {
  std::stringstream lErrorMessage;

  if(aPath.startsWith(FILE_SCHEMA.c_str())) {
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
