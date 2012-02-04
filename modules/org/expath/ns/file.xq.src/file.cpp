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

#include "file.h"

#include <memory>
#include <fstream>
#include <sstream>

#include <zorba/base64.h>
#include <zorba/empty_sequence.h>
#include <zorba/diagnostic_list.h>
#include <zorba/file.h>
#include <zorba/serializer.h>
#include <zorba/singleton_item_sequence.h>
#include <zorba/util/path.h>
#include <zorba/user_exception.h>
#include <zorba/transcode_stream.h>

#include "file_module.h"


namespace zorba { namespace filemodule {

//*****************************************************************************

CreateDirectoryFunction::CreateDirectoryFunction(const FileModule* aModule)
  : FileFunction(aModule)
{
}

ItemSequence_t
CreateDirectoryFunction::evaluate(
  const ExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  String lFileStr = getFilePathString(aArgs, 0);
  File_t lFile = File::createFile(lFileStr.c_str());

  // precondition
  if (lFile->isFile()) {
    raiseFileError("FOFL0002", "A file already exists at this path", lFile->getFilePath());
  }

  // actual mkdir
  try {
    lFile->mkdir(true);
  } catch (ZorbaException& ze) {
    std::stringstream lSs;
    lSs << "An unknown error occured: " << ze.what() << "Can not create directory";
    raiseFileError("FOFL9999", lSs.str(), lFile->getFilePath());
  } catch (...) {
    //assert(false); if this happens errors are not proprly thrown
    raiseFileError("FOFL9999", "Can not create directory", lFile->getFilePath());
  }

  // postcondition
  if (!(lFile->isDirectory())) {
    raiseFileError("FOFL9999", "Can not create directory", lFile->getFilePath());
  }

  return ItemSequence_t(new EmptySequence());
}

//*****************************************************************************

DeleteFileImplFunction::DeleteFileImplFunction(const FileModule* aModule)
  : FileFunction(aModule)
{
}

ItemSequence_t
DeleteFileImplFunction::evaluate(
  const ExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  String lFileStr = getFilePathString(aArgs, 0);
  File_t lFile = File::createFile(lFileStr.c_str());

  // precondition
  if (!lFile->exists()) {
    raiseFileError("FOFL0001", "A file or directory does not exist at this path", lFile->getFilePath());
  }

  // actual remove
  try {
    lFile->remove();
  } catch (ZorbaException& ze) {
    std::stringstream lSs;
    lSs << "An unknown error occured: " << ze.what() << "Can not delete file";
    raiseFileError("FOFL9999", lSs.str(), lFile->getFilePath());
  } catch (...) {
    //assert(false); if this happens errors are not proprly thrown
    raiseFileError("FOFL9999", "Can not delete directory", lFile->getFilePath());
  }

  // postcondition
  if (lFile->exists()) {
    raiseFileError("FOFL9999", "The file at this path could not be deleted", lFile->getFilePath());
  }

  return ItemSequence_t(new EmptySequence());
}

//*****************************************************************************

ReadBinaryFunction::ReadBinaryFunction(const FileModule* aModule)
  : FileFunction(aModule)
{
}

ItemSequence_t
ReadBinaryFunction::evaluate(
  const ExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  String lFileStr = getFilePathString(aArgs, 0);
  File_t lFile = File::createFile(lFileStr.c_str());

  // preconditions
  if (!lFile->exists()) {
    raiseFileError("FOFL0001", "A file does not exist at this path", lFile->getFilePath());
  }
  if (lFile->isDirectory()) {
    raiseFileError("FOFL0004", "The given path points to a directory", lFile->getFilePath());
  }

  // actual read
  Item lItem;
  try {
    std::ifstream lInStream;
    lFile->openInputStream(lInStream, true, false);

    std::stringstream lStrStream;
    char lBuf[1024];
    while (!lInStream.eof()) {
      lInStream.read(lBuf, 1024);
      lStrStream.write(lBuf, lInStream.gcount());
    }  

    String lContent(lStrStream.str());
    String lEncodedContent = encoding::Base64::encode(lContent);
    lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.data(), lEncodedContent.size());
  } catch (ZorbaException& ze) {
    std::stringstream lSs;
    lSs << "An unknown error occured: " << ze.what() << "Can not read file";
    raiseFileError("FOFL9999", lSs.str(), lFile->getFilePath());
  } catch (...) {
    //assert(false); if this happens errors are not proprly thrown
    raiseFileError("FOFL9999", "Can not read file", lFile->getFilePath());
  }

  if (lItem.isNull()) {
    Item lQName = theModule->getItemFactory()->createQName("http://www.w3.org/2005/xqt-errors", "err", "XPTY0004");
    throw USER_EXCEPTION(lQName, "Error while building the base64binary item." );
  }

  return ItemSequence_t(new SingletonItemSequence(lItem));
}

//*****************************************************************************

ReadTextFunction::ReadTextFunction(const FileModule* aModule)
  : StreamableFileFunction(aModule)
{
}

ItemSequence_t
ReadTextFunction::evaluate(
  const ExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  String lFileStr = getFilePathString(aArgs, 0);
  File_t lFile = File::createFile(lFileStr.c_str());
  String lEncoding("UTF-8");

  // preconditions
  if (!lFile->exists()) {
    raiseFileError("FOFL0001", "A file does not exist at this path", lFile->getFilePath());
  }
  if (lFile->isDirectory()) {
    raiseFileError("FOFL0004", "The given path points to a directory", lFile->getFilePath());
  }

  if (aArgs.size() == 2) {
    lEncoding = getEncodingArg(aArgs, 1);
  }
  
  zorba::Item lResult;
  std::unique_ptr<std::ifstream> lInStream;
  if ( transcode::is_necessary( lEncoding.c_str() ) )
  {
    try {
      lInStream.reset( new transcode::stream<std::ifstream>(lEncoding.c_str()) );
    } catch (std::invalid_argument const& e)
    {
      raiseFileError("FOFL0006", "Unsupported encoding", lEncoding.c_str());
    }
  }
  else
  {
    lInStream.reset( new std::ifstream() );
  }
  lFile->openInputStream(*lInStream.get(), false, true);
  lResult = theModule->getItemFactory()->createStreamableString(
      *lInStream.release(), &FileModule::streamReleaser
    );
  return ItemSequence_t(new SingletonItemSequence(lResult));

}

//*****************************************************************************

ExistsFunction::ExistsFunction(const FileModule* aModule)
  : FileFunction(aModule)
{
}

ItemSequence_t
ExistsFunction::evaluate(
  const ExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  bool   lFileExists = false;
  String lFileStr = getFilePathString(aArgs, 0);

  File_t lFile = File::createFile(lFileStr.c_str());
  if (lFile->exists()) {
    lFileExists = true;
  }

  return ItemSequence_t(new SingletonItemSequence(
      theModule->getItemFactory()->createBoolean(lFileExists)));
}

//*****************************************************************************

IsDirectoryFunction::IsDirectoryFunction(const FileModule* aModule)
  : FileFunction(aModule)
{
}

ItemSequence_t
IsDirectoryFunction::evaluate(
  const ExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  bool   lResult = false;
  String lFileStr = getFilePathString(aArgs, 0);

  File_t lFile = File::createFile(lFileStr.c_str());
  if (lFile->isDirectory()) {
    lResult = true;
  }
  return ItemSequence_t(new SingletonItemSequence(
      theModule->getItemFactory()->createBoolean(lResult)));
}

//*****************************************************************************

IsFileFunction::IsFileFunction(const FileModule* aModule)
  : FileFunction(aModule)
{
}

ItemSequence_t
IsFileFunction::evaluate(
  const ExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  bool   lResult = false;
  String lFileStr = getFilePathString(aArgs, 0);

  File_t lFile = File::createFile(lFileStr.c_str());
  if (lFile->isFile()) {
    lResult = true;
  }
  return ItemSequence_t(new SingletonItemSequence(
      theModule->getItemFactory()->createBoolean(lResult)));
}

//*****************************************************************************

CopyFileImplFunction::CopyFileImplFunction(const FileModule* aModule)
  : FileFunction(aModule)
{
}

ItemSequence_t
CopyFileImplFunction::evaluate(
  const ExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  String lSrcFileStr = getFilePathString(aArgs, 0);
  File_t lSrcFile = File::createFile(lSrcFileStr.c_str());
  String lDstStr = getFilePathString(aArgs, 1);
  File_t lDst = File::createFile(lDstStr.c_str());

  // preconditions
  if (!lSrcFile->exists()) {
    raiseFileError("FOFL0001", "A file does not exist at this path", lSrcFile->getFilePath());
  }
  // is this a file? (the recursive version is implemented in XQuery)
  if (lSrcFile->isDirectory()) {
    raiseFileError("FOFL0004", "This operation is non-recursive. The source path points to a directory", lSrcFile->getFilePath());
  }

  // do we copy into a directory?
  if (lDst->isDirectory()) {
    lDstStr = lDst->getFilePath();
    String lSrcPath = lSrcFile->getFilePath();
    int lLastSep = lSrcPath.rfind(File::getDirectorySeparator());
    String lName = lSrcPath.substr(lLastSep);
    lDstStr = lDstStr.append(lName.c_str());
    lDst = File::createFile(lDstStr.c_str());
  }

  // is the destination still is a directory?
  if (lDst->isDirectory()) {
    raiseFileError("FOFL0002", "The destination path already exists", lSrcFile->getFilePath());
  }

  // do we copy a file to its own location?
  if (lSrcFile->getFilePath() == lDst->getFilePath()) {
    raiseFileError("FOFL9999", "The source and destination paths can not point to the same file", lSrcFile->getFilePath());
  }

  // actual copy
  try {

    // open the output stream in the desired write mode
    std::ifstream lInStream;
    std::ofstream lOutStream;
    lSrcFile->openInputStream(lInStream, true, false);
    lDst->openOutputStream(lOutStream, true, false);

    // copy the data
    char lBuf[1024];
    while (!lInStream.eof()) {
      lInStream.read(lBuf, 1024);
      lOutStream.write(lBuf, lInStream.gcount());
    }  

    // close the streams
    lInStream.close();
    lOutStream.close();

  } catch (ZorbaException& ze) {
    std::stringstream lSs;
    lSs << "An unknown error occured: " << ze.what() << "Can not copy file";
    raiseFileError("FOFL9999", lSs.str(), lSrcFile->getFilePath());
  } catch (...) {
    //assert(false); if this happens errors are not proprly thrown
    raiseFileError("FOFL9999", "Can not copy file", lSrcFile->getFilePath());
  }

  return ItemSequence_t(new EmptySequence());
}

//*****************************************************************************

ListFunction::ListFunction(const FileModule* aModule)
  : FileFunction(aModule)
{
}

ItemSequence_t
ListFunction::evaluate(
  const ExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  String lFileStr = getFilePathString(aArgs, 0);
  File_t lFile = File::createFile(lFileStr.c_str());

  // precondition
  if (!lFile->isDirectory()) {
    raiseFileError("FOFL0003", "The specified path does not point to a directory", lFile->getFilePath());
  }

  // actual list
  try {
    DirectoryIterator_t lIter = lFile->files();
    return ItemSequence_t(new IteratorBackedItemSequence(lIter, theModule->getItemFactory()));
  } catch (ZorbaException& ze) {
    std::stringstream lSs;
    lSs << "An unknown error occured: " << ze.what() << "Can not list directory";
    raiseFileError("FOFL9999", lSs.str(), lFile->getFilePath());
  } catch (...) {
    //assert(false); if this happens errors are not proprly thrown
    raiseFileError("FOFL9999", "Can not list directory", lFile->getFilePath());
  }

  // dummy, this will never be called
  return ItemSequence_t(new EmptySequence());
}

ListFunction::IteratorBackedItemSequence::IteratorBackedItemSequence(
    DirectoryIterator_t& aIter,
    ItemFactory* aFactory)
  : theIterator(aIter), theItemFactory(aFactory)
{
  is_open = false;
  open_count = 0;
}

ListFunction::IteratorBackedItemSequence::~IteratorBackedItemSequence()
{
}

Iterator_t ListFunction::IteratorBackedItemSequence::getIterator()
{
  return this;
}

void ListFunction::IteratorBackedItemSequence::open()
{
  if (open_count) {
    theIterator->reset();
  }
  open_count++;
  is_open = true;
}

void ListFunction::IteratorBackedItemSequence::close()
{
  is_open = false;
}

bool ListFunction::IteratorBackedItemSequence::isOpen() const
{
  return is_open;
}

bool
ListFunction::IteratorBackedItemSequence::next(Item& lItem)
{
  std::string lPath;
  if (!theIterator->next(lPath)) {
    return false;
  }

  String lUriStr(lPath.c_str());
  lItem = theItemFactory->createString(lUriStr);
  return true;
}

//*****************************************************************************

LastModifiedFunction::LastModifiedFunction(const FileModule* aModule)
  : FileFunction(aModule)
{
}

ItemSequence_t
LastModifiedFunction::evaluate(
  const ExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  String lFileStr = getFilePathString(aArgs, 0);
  File_t lFile = File::createFile(lFileStr.c_str());

  // precondition
  if (!lFile->exists()) {
    raiseFileError("FOFL0001", "A file or directory does not exist at this path", lFile->getFilePath());
  }

  // actual last modified
  try {
    time_t lTime = lFile->lastModified();
    struct tm *lT = localtime(&lTime);
    int gmtOffset = LastModifiedFunction::getGmtOffset();

    return ItemSequence_t(new SingletonItemSequence(
      theModule->getItemFactory()->createDateTime(1900 + lT->tm_year, lT->tm_mon, lT->tm_mday, lT->tm_hour, lT->tm_min, lT->tm_sec, gmtOffset)));
  } catch (ZorbaException& ze) {
    std::stringstream lSs;
    lSs << "An unknown error occured: " << ze.what() << "Can not retrieve the last modification timestamp of";
    raiseFileError("FOFL9999", lSs.str(), lFile->getFilePath());
  } catch (...) {
    //assert(false); if this happens errors are not proprly thrown
    raiseFileError("FOFL9999", "Can not retrieve the last modification timestamp of", lFile->getFilePath());
  }

  // dummy, this will never be called
  return ItemSequence_t(new EmptySequence());
}

int
LastModifiedFunction::getGmtOffset()
{
  time_t t = time(0);
  struct tm* data;
  data = localtime(&t);
  data->tm_isdst = 0;
  time_t a = mktime(data);
  data = gmtime(&t);
  data->tm_isdst = 0;
  time_t b = mktime(data);
  return (int)(a - b)/3600; 
}

//*****************************************************************************

SizeFunction::SizeFunction(const FileModule* aModule)
  : FileFunction(aModule)
{
}

ItemSequence_t
SizeFunction::evaluate(
  const ExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  String lFileStr = getFilePathString(aArgs, 0);
  File_t lFile = File::createFile(lFileStr.c_str());

  // preconditions
  if (!lFile->exists()) {
    raiseFileError("FOFL0001", "A file does not exist at this path", lFile->getFilePath());
  }
  if (lFile->isDirectory()) {
    raiseFileError("FOFL0004", "The given path points to a directory", lFile->getFilePath());
  }

  // actual size
  File::FileSize_t lFs = -1;
  try {
    lFs = lFile->getSize();
  } catch (ZorbaException& ze) {
    std::stringstream lSs;
    lSs << "An unknown error occured: " << ze.what() << "Can not retrieve the file size of";
    raiseFileError("FOFL9999", lSs.str(), lFile->getFilePath());
  } catch (...) {
    //assert(false); if this happens errors are not proprly thrown
    raiseFileError("FOFL9999", "Can not retrieve the file size of", lFile->getFilePath());
  }

  return ItemSequence_t(new SingletonItemSequence(
    theModule->getItemFactory()->createInteger(lFs)));
}

//*****************************************************************************

PathSeparator::PathSeparator(const FileModule* aModule)
  : FileFunction(aModule)
{
}

ItemSequence_t
PathSeparator::evaluate(
  const ExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  return ItemSequence_t(new SingletonItemSequence(theModule->getItemFactory()->createString(FileFunction::pathSeparator())));
}

//*****************************************************************************

DirectorySeparator::DirectorySeparator(const FileModule* aModule)
  : FileFunction(aModule)
{
}

ItemSequence_t
DirectorySeparator::evaluate(
  const ExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  return ItemSequence_t(new SingletonItemSequence(theModule->getItemFactory()->createString(FileFunction::directorySeparator())));
}

//*****************************************************************************

ResolvePathFunction::ResolvePathFunction(const FileModule* aModule)
  : FileFunction(aModule)
{
}

ItemSequence_t
ResolvePathFunction::evaluate(
  const ExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  String lPathStr = getFilePathString(aArgs, 0);
  String lResult = pathToOSPath(lPathStr);

  return ItemSequence_t(new SingletonItemSequence(theModule->getItemFactory()->createString(lResult)));
}

//*****************************************************************************

PathToNativeFunction::PathToNativeFunction(const FileModule* aModule)
  : FileFunction(aModule)
{
}

ItemSequence_t
PathToNativeFunction::evaluate(const ExternalFunction::Arguments_t& args,
                                const StaticContext* aSctxCtx,
                                const DynamicContext* aDynCtx) const
{
  Item pathItem;
  Iterator_t arg0_iter = args[0]->getIterator();
  arg0_iter->open();
  arg0_iter->next(pathItem);
  arg0_iter->close();
  String osPath = filesystem_path::normalize_path(pathItem.getStringValue().c_str());
  return ItemSequence_t(new SingletonItemSequence(theModule->getItemFactory()->createString(osPath)));
}

//*****************************************************************************

PathToUriFunction::PathToUriFunction(const FileModule* aModule)
  : FileFunction(aModule)
{
}

ItemSequence_t
PathToUriFunction::evaluate(
  const ExternalFunction::Arguments_t& aArgs,
  const StaticContext*                 aSctxCtx,
  const DynamicContext*                aDynCtx) const
{
  String lPathStr = getFilePathString(aArgs, 0);
  String lResult = pathToUriString(lPathStr);

  return ItemSequence_t(new SingletonItemSequence(theModule->getItemFactory()->createAnyURI(lResult)));
}

//*****************************************************************************

WriteTextFunction::WriteTextFunction(const FileModule* aModule)
  : WriterFileFunction(aModule)
{
}

bool
WriteTextFunction::isAppend() const {
  return false;
}

bool
WriteTextFunction::isBinary() const {
  return false;
}

//*****************************************************************************

WriteBinaryFunction::WriteBinaryFunction(const FileModule* aModule)
  : WriterFileFunction(aModule)
{
}

bool
WriteBinaryFunction::isAppend() const {
  return false;
}

bool
WriteBinaryFunction::isBinary() const {
  return true;
}

//*****************************************************************************

AppendTextFunction::AppendTextFunction(const FileModule* aModule)
  : WriterFileFunction(aModule)
{
}

bool
AppendTextFunction::isAppend() const {
  return true;
}

bool
AppendTextFunction::isBinary() const {
  return false;
}

//*****************************************************************************

AppendBinaryFunction::AppendBinaryFunction(const FileModule* aModule)
  : WriterFileFunction(aModule)
{
}

bool
AppendBinaryFunction::isAppend() const {
  return true;
}

bool
AppendBinaryFunction::isBinary() const {
  return true;
}

//*****************************************************************************


} /* namespace filemodule */ } /* namespace zorba */

#ifdef WIN32
#  define DLL_EXPORT __declspec(dllexport)
#else
#  define DLL_EXPORT __attribute__ ((visibility("default")))
#endif

extern "C" DLL_EXPORT zorba::ExternalModule* createModule() {
  return new zorba::filemodule::FileModule();
}
/* vim:set et sw=2 ts=2: */
