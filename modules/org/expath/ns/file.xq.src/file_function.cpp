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
#include <zorba/diagnostic_list.h>
#include <zorba/file.h>
#include <zorba/serializer.h>
#include <zorba/store_consts.h>
#include <zorba/user_exception.h>
#include <zorba/util/path.h>
#include <zorba/xquery_functions.h>
#include <zorba/zorba.h>

#include "file_module.h"

#include <cassert>

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

void
FileFunction::raiseFileError(
  const std::string& aQName,
  const std::string& aMessage,
  const std::string& aPath) const
{
  std::stringstream lErrorMessage;
  lErrorMessage << aMessage << ": " << aPath;
  Item lQName = theModule->getItemFactory()->createQName(getURI(), "file", aQName);
  throw USER_EXCEPTION(lQName, lErrorMessage.str());
}

String
FileFunction::getURI() const
{
  return theModule->getURI();
}

String
FileFunction::getFilePathString(
  const ExternalFunction::Arguments_t& aArgs,
  unsigned int aPos) const
{
  String lFileArg;

  Item lItem;
  Iterator_t args_iter = aArgs[aPos]->getIterator();
  args_iter->open();
  if (args_iter->next(lItem)) {
    lFileArg = lItem.getStringValue();
  }
  args_iter->close();

  return (filesystem_path::normalize_path
    (lFileArg.c_str(), getCurrentPath().c_str()));
}

String
FileFunction::directorySeparator() {
  return File::getDirectorySeparator();
}

String
FileFunction::pathSeparator() {
  return File::getPathSeparator();
}

String
FileFunction::pathToFullOSPath(const String& aPath) const {
  File_t lFile = File::createFile(aPath.c_str());
  std::string lPath = lFile->getFilePath();

  return String(lPath);
}

String
FileFunction::getEncodingArg(
  const ExternalFunction::Arguments_t& aArgs,
  unsigned int aPos) const
{
  // the default file encoding
  zorba::String lEncoding("UTF-8");
  if (aArgs.size() > aPos) {
    Item lEncodingItem;
    Iterator_t arg_iter = aArgs[aPos]->getIterator();
    arg_iter->open();
    if (arg_iter->next(lEncodingItem)) {
      lEncoding = fn::upper_case( lEncodingItem.getStringValue() );
    }
    arg_iter->close();
  }

  if (!(lEncoding == "UTF-8" || lEncoding == "UTF8")) {
    // the rest are not supported encodings
    raiseFileError("FOFL0006", "Unsupported encoding", lEncoding.c_str());
  }

  return lEncoding;
}

String
FileFunction::pathToOSPath(const String& aPath) const {
  File_t lFile = File::createFile(aPath.c_str());
  std::string lPath = lFile->getFilePath();

  return String(lPath);
}

String
FileFunction::pathToUriString(const String& aPath) const {
  std::stringstream lErrorMessage;

  if(fn::starts_with(aPath,"file://")) {
    lErrorMessage << "Please provide a path, not a URI";
    Item lQName = theModule->getItemFactory()->createQName(
        "http://www.w3.org/2005/xqt-errors",
        "err",
        "XPTY0004");
    throw USER_EXCEPTION(lQName, lErrorMessage.str() );
  }

  File_t lFile = File::createFile(aPath.c_str());

  std::string lPath = lFile->getFileUri();


  return String(lPath);
}

#ifdef WIN32
bool
FileFunction::isValidDriveSegment(
    String& aString)
{
  aString = fn::upper_case( aString );
  // the drive segment has one of the forms: "C:", "C%3A"
  if ((aString.length() != 2 && aString.length() != 4) ||
      (aString.length() == 2 && !fn::ends_with(aString,":")) ||
      (aString.length() == 4 && !fn::ends_with(aString,"%3A"))) {
    return false;
  }

  char lDrive = aString[0];
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
  assert(theIsOpen);

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
  const ExternalFunction::Arguments_t& aArgs,
  const StaticContext*                 aSctxCtx,
  const DynamicContext*                aDynCtx) const
{
  String lFileStr = getFilePathString(aArgs, 0);
  File_t lFile = File::createFile(lFileStr.c_str());

  // precondition
  if (lFile->isDirectory()) {
    raiseFileError("FOFL0004", "The given path points to a directory", lFile->getFilePath());
  }

  bool lBinary = isBinary();

  // actual write
  try {

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
          lOutStream.write(lString.data(), lString.size());
        }
      }
      lContentSeq->close();
    }

    // close the file stream
    lOutStream.close();

  } catch (ZorbaException& ze) {
    std::stringstream lSs;
    lSs << "An unknown error occured: " << ze.what() << "Can not read file";
    raiseFileError("FOFL9999", lSs.str(), lFile->getFilePath());
  } catch (...) {
    //assert(false); if this happens errors are not proprly thrown
    raiseFileError("FOFL9999", "Can not read file", lFile->getFilePath());
  }

  return ItemSequence_t(new EmptySequence());
}

} // namespace filemodule
} // namespace zorba
