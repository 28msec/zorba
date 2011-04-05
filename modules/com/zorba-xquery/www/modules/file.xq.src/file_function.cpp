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

#include <zorba/empty_sequence.h>
#include <zorba/error_list.h>
#include <zorba/file.h>
#include <zorba/serializer.h>
#include <zorba/store_consts.h>
#include <zorba/util/path.h>
#include <zorba/xquery_exception.h>
#include <zorba/zorba.h>

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
    throwError(lErrorMessage.str(), err::XPTY0004);
  }
  zorba::String lTmpString = lItem.getStringValue();
  if (args_iter->next(lItem)) {
    std::stringstream lErrorMessage;
    lErrorMessage << "A sequence of more then one item is not allowed as "
                  << aPos << ". parameter.";
    throwError(lErrorMessage.str(), err::XPTY0004);
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
    const StatelessExternalFunction::Arguments_t& aArgs,
    int aPos)
{
  String lFileArg = getOneStringArg(aArgs, aPos);

  return (filesystem_path::normalize_path
    (lFileArg.c_str(), getCurrentPath().c_str()));
}

String
FileFunction::directorySeparator() {
  return File::getDirectorySeparator();
}

String
FileFunction::pathSeparator1() {
  return File::getPathSeparator1();
}

String
FileFunction::pathToFullOSPath(const String& aPath) {
  File_t lFile = File::createFile(aPath.c_str());
  std::string lPath = lFile->getFilePath();

  return String(lPath);
}

String
FileFunction::getEncodingArg(
    const StatelessExternalFunction::Arguments_t& aArgs,
    unsigned int aPos)
{
  // the default file encoding
  zorba::String lEncoding("UTF-8");
  if (aArgs.size() > aPos) {
    Item lEncodingItem;
    Iterator_t arg_iter = aArgs[aPos]->getIterator();
    arg_iter->open();
    if (arg_iter->next(lEncodingItem)) {
      lEncoding = lEncodingItem.getStringValue().uppercase();
    }
    arg_iter->close();
  }

  if (!(lEncoding == "UTF-8" || lEncoding == "UTF8")) {
    // the rest are not supported encodings
    std::stringstream lErrorMessage;
    lErrorMessage << "Unsupported encoding: " << lEncoding;
    throwError(lErrorMessage.str(), err::XQP0019_INTERNAL_ERROR);
  }

  return lEncoding;
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
    throwError(lErrorMessage.str(), err::XPTY0004);
  }

  File_t lFile = File::createFile(aPath.c_str());

  std::string lPath = lFile->getFileUri();


  return String(lPath);
}

void
FileFunction::throwError(
    const std::string aErrorMessage,
    const Error& aErrorType)
{
  throw XQUERY_EXCEPTION_VAR(aErrorType, ERROR_PARAMS( aErrorMessage.c_str() ));
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

//*****************************************************************************

StreamableFileFunction::StreamableFileFunction(const FileModule* aModule)
  : FileFunction(aModule)
{
}

StreamableFileFunction::~StreamableFileFunction()
{
}

bool
StreamableFileFunction::StreamableItemSequence::InternalIterator::next(Item& aResult)
{
  if(!theIsOpen) {
    throw XQUERY_EXCEPTION(XQP0019_INTERNAL_ERROR, ERROR_PARAMS(
      "StreamableItemSequence Iterator consumed without open" ) );  
  }
  if (theHasNext) {
    aResult = theItemSequence->theItem;
    theHasNext = false;
    return !aResult.isNull();
  }
  return false;
}

//*****************************************************************************

WriterFileFunction::WriterFileFunction(const FileModule* aModule)
  : FileFunction(aModule)
{
}

WriterFileFunction::~WriterFileFunction()
{
}

ItemSequence_t
WriterFileFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  String lFileStr = getFilePathString(aArgs, 0);
  File_t lFile = File::createFile(lFileStr.c_str());

  if (lFile->isDirectory()) {
    error(/* FOFL0004, "The path denotes an existing directory: " + lFile->getFilePath() */);
  }

  bool lBinary = isBinary();
  bool lAppend = isAppend();

  // throw an error if the file exists and we don't want to overwrite,
  // but if we append, we don't care because we always write
  if (!lAppend && lFile->exists() && aArgs.size() == 3 && !getOneBooleanArg(aArgs, 2)) {
    error(/* FOFL0002, "The file already exists: " + lFile->getFilePath() */);
  }

  // open the output stream in the desired write mode
  std::ofstream lOutStream;
  lFile->openOutputStream(lOutStream, lBinary, isAppend());

  // if this is a binary write
  if (lBinary) {
    Zorba_SerializerOptions lOptions;
    lOptions.ser_method = ZORBA_SERIALIZATION_METHOD_BINARY;
    Serializer_t lSerializer = Serializer::createSerializer(lOptions);
    lSerializer->serialize(aArgs[1], lOutStream);
  }
  // if we only write text
  else {
    Item lStringItem;
    Iterator_t lContentSeq = aArgs[1]->getIterator();
    lContentSeq->open();
    // for each item (string or base64Binary) in the content sequence
    while (lContentSeq->next(lStringItem)) {
      // if the item is streamable make use of the stream
      if (lStringItem.isStreamable()) {
        std::istream& lInStream = lStringItem.getStream();
        char lBuf[1024];
        while (!lInStream.eof()) {
          lInStream.read(lBuf, 1024);
          lOutStream.write(lBuf, lInStream.gcount());
        }
      }
      // else write the string value
      else {
        zorba::String lString = lStringItem.getStringValue();
        lOutStream.write(lString.c_str(), lString.bytes());
      }
    }
    lContentSeq->close();
  }

  // close the file stream
  lOutStream.close();

  return ItemSequence_t(new EmptySequence());
}

} /* namespace filemodule */ } /* namespace zorba */
