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
#include <zorba/error_list.h>
#include <zorba/file.h>
#include <zorba/serializer.h>
#include <zorba/singleton_item_sequence.h>
#include <zorba/util/path.h>
#include <zorba/xquery_exception.h>

#include "file_module.h"


namespace zorba { namespace filemodule {

//*****************************************************************************

CreateDirectoryFunction::CreateDirectoryFunction(const FileModule* aModule)
  : FileFunction(aModule)
{
}

ItemSequence_t
CreateDirectoryFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  String lFileStr = FileFunction::getFilePathString(aArgs, 0);
  File_t lFile = File::createFile(lFileStr.c_str());

  lFile->mkdir(true);

  return ItemSequence_t(new EmptySequence());
}

//*****************************************************************************

DeleteFileImplFunction::DeleteFileImplFunction(const FileModule* aModule)
  : FileFunction(aModule)
{
}

ItemSequence_t
DeleteFileImplFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  String lFileStr = FileFunction::getFilePathString(aArgs, 0);
  File_t lFile = File::createFile(lFileStr.c_str());

  lFile->remove();

  return ItemSequence_t(new EmptySequence());
}

//*****************************************************************************

ReadBinaryFunction::ReadBinaryFunction(const FileModule* aModule)
  : FileFunction(aModule)
{
}

ItemSequence_t
ReadBinaryFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  String lFileStr = FileFunction::getFilePathString(aArgs, 0);
  File_t lFile = File::createFile(lFileStr.c_str());

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
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());

  if (lItem.isNull()) {
    throw XQUERY_EXCEPTION(err::XPTY0004, ERROR_PARAMS( "Error while building the base64binary item." ) );
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
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  String lFileStr = FileFunction::getFilePathString(aArgs, 0);
  File_t lFile = File::createFile(lFileStr.c_str());

  if (aArgs.size() == 2) {
    // since Zorba currently only supports UTF-8 we only call this function
    // to reject any other encoding requested bu the user
    getEncodingArg(aArgs, 1);
  }
  
  std::auto_ptr<StreamableItemSequence> lSeq(new StreamableItemSequence());
  lFile->openInputStream(*lSeq->theStream, false, true);

  lSeq->theItem = theModule->getItemFactory()->createStreamableString(
      *lSeq->theStream, &StreamableItemSequence::streamDestroyer);

  return ItemSequence_t(lSeq.release());
}

//*****************************************************************************

ExistsFunction::ExistsFunction(const FileModule* aModule)
  : FileFunction(aModule)
{
}

ItemSequence_t
ExistsFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  bool   lFileExists = false;
  String lFileStr = FileFunction::getFilePathString(aArgs, 0);

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
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  bool   lResult = false;
  String lFileStr = FileFunction::getFilePathString(aArgs, 0);

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
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  bool   lResult = false;
  String lFileStr = FileFunction::getFilePathString(aArgs, 0);

  File_t lFile = File::createFile(lFileStr.c_str());
  if (lFile->isFile()) {
    lResult = true;
  }
  return ItemSequence_t(new SingletonItemSequence(
      theModule->getItemFactory()->createBoolean(lResult)));
}

//*****************************************************************************

CopyFunction::CopyFunction(const FileModule* aModule)
  : FileFunction(aModule)
{
}

ItemSequence_t
CopyFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  bool lResult = false;

  String lSrcFileStr = FileFunction::getFilePathString(aArgs, 0);
  File_t lSrcFile = File::createFile(lSrcFileStr.c_str());
  String lDstStr = FileFunction::getFilePathString(aArgs, 1);
  File_t lDst = File::createFile(lDstStr.c_str());

  // do we have something to copy?
  if (!(lSrcFile->exists())) {
    std::stringstream lSs;
    lSs << "The source path does not exist: " << lSrcFile->getFilePath();
    error(/*FOFL0001, lSs.str()*/);
  }

  // is this a file (the recursive version is implemented in XQuery)
  if (!(lSrcFile->isFile())) {
    std::stringstream lSs;
    lSs << "The source of a non-recursive copy cannot be a directory: " << lSrcFile->getFilePath();
    error(/*FOFL0004, lSs.str()*/);
  }

  // do we have to overwrite an existing file?
  bool lOverwrite = false;
  if (aArgs.size() == 3) {
    lOverwrite = getOneBooleanArg(aArgs, 2);
  }

  // stop if not overwriting and the destination file exists
  if (!lOverwrite && lDst->isFile()) {
    std::stringstream lSs;
    lSs << "The destination path already exists: " << lDst->getFilePath();
    error(/*FOFL0002, lSs.str()*/);
  }

  if (lDst->isDirectory()) {
    lDstStr = lDst->getFilePath();
    String lSrcPath = lSrcFile->getFilePath();
    int lLastSep = lSrcPath.lastIndexOf(File::getDirectorySeparator());
    String lName = lSrcPath.substring(lLastSep);
    lDstStr = lDstStr.append(lName.c_str());
    lDst = File::createFile(lDstStr.c_str());
  }

  if (lDst->isDirectory()) {
    std::stringstream lSs;
    lSs << "The destination path already exists: : " << lDst->getFilePath();
    error(/*FOFL0002, lSs.str()*/);
  } else if (lDst->isFile() && !lOverwrite) {
    std::stringstream lSs;
    lSs << "The destination path already exists: " << lDst->getFilePath();
    error(/*FOFL0002, lSs.str()*/);
  }

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

  lResult = true;

  return ItemSequence_t(new EmptySequence());
}

//*****************************************************************************

ListFunction::ListFunction(const FileModule* aModule)
  : FileFunction(aModule)
{
}

ItemSequence_t
ListFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  String lFileStr = FileFunction::getFilePathString(aArgs, 0);
  File_t lFile = File::createFile(lFileStr.c_str());

  if (!lFile->isDirectory()) {
    return ItemSequence_t(new EmptySequence());
  }

  DirectoryIterator_t lIter = lFile->files();
  return ItemSequence_t(new IteratorBackedItemSequence(lIter, theModule->getItemFactory()));
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
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  String lFileStr = FileFunction::getFilePathString(aArgs, 0);
  File_t lFile = File::createFile(lFileStr.c_str());

  if(!lFile->exists()) {
    std::stringstream lErrorMessage;
    lErrorMessage << "The provided path/URI does not exist: " << lFile->getFilePath();
    error(/*FOFL0001, lErrorMessage.str()*/);
  }

  time_t lTime = lFile->lastModified();
  struct tm *lT = localtime(&lTime);

  int gmtOffset = LastModifiedFunction::getGmtOffset();

  return ItemSequence_t(new SingletonItemSequence(
    theModule->getItemFactory()->createDateTime(1900 + lT->tm_year, lT->tm_mon, lT->tm_mday, lT->tm_hour, lT->tm_min, lT->tm_sec, gmtOffset)));
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
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  String lFileStr = FileFunction::getFilePathString(aArgs, 0);
  File_t lFile = File::createFile(lFileStr.c_str());

  if(!lFile->exists()) {
    std::stringstream lErrorMessage;
    lErrorMessage << "The provided path/URI does not exist: " << lFile->getFilePath();
    error(/*FOFL0001, lErrorMessage.str()*/);
  }

  if(lFile->isDirectory()) {
    std::stringstream lErrorMessage;
    lErrorMessage << "The provided path/URI must not point to a directory: " << lFile->getFilePath();
    error(/*FOFL0004, lErrorMessage.str()*/);
  }

  return ItemSequence_t(new SingletonItemSequence(
    theModule->getItemFactory()->createInteger(lFile->getSize())));
}

//*****************************************************************************

PathSeparator::PathSeparator(const FileModule* aModule)
  : FileFunction(aModule)
{
}

ItemSequence_t
PathSeparator::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
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
  const StatelessExternalFunction::Arguments_t& aArgs,
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
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  String lPathStr = FileFunction::getFilePathString(aArgs, 0);
  String lResult = FileFunction::pathToOSPath(lPathStr);

  return ItemSequence_t(new SingletonItemSequence(theModule->getItemFactory()->createString(lResult)));
}

//*****************************************************************************

PathToUriFunction::PathToUriFunction(const FileModule* aModule)
  : FileFunction(aModule)
{
}

ItemSequence_t
PathToUriFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  String lPathStr = FileFunction::getFilePathString(aArgs, 0);
  String lResult = FileFunction::pathToUriString(lPathStr);

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


//*****************************************************************************
//*****************************************************************************
// the functions above have been updated to the new file API spec
//*****************************************************************************
//*****************************************************************************

PathToNativeFunction::PathToNativeFunction(const FileModule* aModule)
  : FileFunction(aModule)
{
}

ItemSequence_t
PathToNativeFunction::evaluate(const StatelessExternalFunction::Arguments_t& args,
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
