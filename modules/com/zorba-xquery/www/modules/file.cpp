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

#include <zorba/file.h>
#include <zorba/empty_sequence.h>
#include <zorba/singleton_item_sequence.h>

//#include <zorba/error.h>
//#include "zorbaerrors/errors.h"

#include "file.h"
#include "file_module.h"

#include <fstream>
#include <sstream>

namespace zorba { namespace filemodule {

//*****************************************************************************

ExistsFunction::ExistsFunction(const FileModule* aModule)
  : FileFunction(aModule)
{
}
  
ItemSequence_t
ExistsFunction::evaluate(const StatelessExternalFunction::Arguments_t& args,
                         const StaticContext* aSctxCtx,
                         const DynamicContext* aDynCtx) const
{
  bool   lFileExists = false;
  String lFileStr = FileFunction::getFilePathString(aSctxCtx, args, 0);

  File_t lFile = File::createFile(lFileStr.c_str());
  if (lFile->exists()) {
    lFileExists = true;
  }

  return ItemSequence_t(new SingletonItemSequence(
      theModule->getItemFactory()->createBoolean(lFileExists)));
}

//*****************************************************************************

FilesFunction::FilesFunction(const FileModule* aModule)
  : FileFunction(aModule)
{
}
  
ItemSequence_t
FilesFunction::evaluate(const StatelessExternalFunction::Arguments_t& args,
                         const StaticContext* aSctxCtx,
                         const DynamicContext* aDynCtx) const
{
  String lFileStr = FileFunction::getFilePathString(aSctxCtx, args, 0);
  File_t lFile = File::createFile(lFileStr.c_str());

  if (!lFile->isDirectory()) {
      return ItemSequence_t(new EmptySequence());
  }

  DirectoryIterator_t lIter = lFile->files();
  return ItemSequence_t(new IteratorBackedItemSequence(lIter, theModule->getItemFactory()));
}

FilesFunction::IteratorBackedItemSequence::IteratorBackedItemSequence(
    DirectoryIterator_t& aIter,
    ItemFactory* aFactory)
  : theIterator(aIter), theItemFactory(aFactory)
{
}

FilesFunction::IteratorBackedItemSequence::~IteratorBackedItemSequence()
{
}

bool
FilesFunction::IteratorBackedItemSequence::next(Item& lItem)
{
  std::string lPath;
  if (!theIterator->next(lPath)) {
    return false;
  }
  
  String lUriStr(lPath.c_str());
  lItem = theItemFactory->createAnyURI(lUriStr);
  return true;
}

//*****************************************************************************

IsDirectoryFunction::IsDirectoryFunction(const FileModule* aModule)
  : FileFunction(aModule)
{
}
  
ItemSequence_t
IsDirectoryFunction::evaluate(const StatelessExternalFunction::Arguments_t& args,
                              const StaticContext* aSctxCtx,
                              const DynamicContext* aDynCtx) const
{
  bool   lResult = false;
  String lFileStr = FileFunction::getFilePathString(aSctxCtx, args, 0);

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
IsFileFunction::evaluate(const StatelessExternalFunction::Arguments_t& args,
                         const StaticContext* aSctxCtx,
                         const DynamicContext* aDynCtx) const
{
  bool   lResult = false;
  String lFileStr = FileFunction::getFilePathString(aSctxCtx, args, 0);

  File_t lFile = File::createFile(lFileStr.c_str());
  if (lFile->isFile()) {
    lResult = true;
  }
  return ItemSequence_t(new SingletonItemSequence(
      theModule->getItemFactory()->createBoolean(lResult)));
}

//*****************************************************************************

LastModifiedFunction::LastModifiedFunction(const FileModule* aModule)
  : FileFunction(aModule)
{
}
  
ItemSequence_t
LastModifiedFunction::evaluate(const StatelessExternalFunction::Arguments_t& args,
                        const StaticContext* aSctxCtx,
                        const DynamicContext* aDynCtx) const
{
  String lFileStr = FileFunction::getFilePathString(aSctxCtx, args, 0);
  File_t lFile = File::createFile(lFileStr.c_str());

  time_t lTime = lFile->lastModified();
  struct tm *lT = localtime(&lTime);

  short gmtOffset = LastModifiedFunction::getGmtOffset();

  return ItemSequence_t(new SingletonItemSequence(
    theModule->getItemFactory()->createDateTime(1900 + lT->tm_year, lT->tm_mon, lT->tm_mday, lT->tm_hour, lT->tm_min, lT->tm_sec, gmtOffset)));
}

short
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
  return (a - b)/3600; 
}

//*****************************************************************************

MkdirFunction::MkdirFunction(const FileModule* aModule)
  : FileFunction(aModule)
{
}
  
ItemSequence_t
MkdirFunction::evaluate(const StatelessExternalFunction::Arguments_t& args,
                        const StaticContext* aSctxCtx,
                        const DynamicContext* aDynCtx) const
{
  String lFileStr = FileFunction::getFilePathString(aSctxCtx, args, 0);
  File_t lFile = File::createFile(lFileStr.c_str());

  bool lStatus = lFile->mkdir();

  return ItemSequence_t(new SingletonItemSequence(
      theModule->getItemFactory()->createBoolean(lStatus)));
}

//*****************************************************************************

MkdirsFunction::MkdirsFunction(const FileModule* aModule)
  : FileFunction(aModule)
{
}

ItemSequence_t
MkdirsFunction::evaluate(const StatelessExternalFunction::Arguments_t& args,
                         const StaticContext* aSctxCtx,
                         const DynamicContext* aDynCtx) const
{
  String lFileStr = FileFunction::getFilePathString(aSctxCtx, args, 0);
  File_t lFile = File::createFile(lFileStr.c_str());

  bool lStatus = lFile->mkdirs();

  return ItemSequence_t(new SingletonItemSequence(
    theModule->getItemFactory()->createBoolean(lStatus)));
}

//*****************************************************************************

ReadFunction::ReadFunction(const FileModule* aModule)
  : FileFunction(aModule)
{
}
  
ItemSequence_t
ReadFunction::evaluate(const StatelessExternalFunction::Arguments_t& args,
                       const StaticContext* aSctxCtx,
                       const DynamicContext* aDynCtx) const
{
  String lFileStr = FileFunction::getFilePathString(aSctxCtx, args, 0);
  File_t lFile = File::createFile(lFileStr.c_str());

  std::ifstream lInStream;
  lFile->read(lInStream);

  std::stringstream lStrStream;
  char lBuf[1024];
  while (!lInStream.eof()) {
    lInStream.read(lBuf, 1024);
    lStrStream.write(lBuf, lInStream.gcount());
  }  

  XmlDataManager* lDataManager = Zorba::getInstance(0)->getXmlDataManager();

  std::string lResult = lStrStream.str();
  Item lItem = theModule->getItemFactory()->createBase64Binary(lResult.c_str(), lResult.size());

  if (lItem.isNull()) {
    throw ExternalFunctionData::createZorbaException(XPTY0004, "Invalid Binary64 file.", __FILE__, __LINE__);
  }

  return ItemSequence_t(new SingletonItemSequence(lItem));
}

//*****************************************************************************

ReadXmlFunction::ReadXmlFunction(const FileModule* aModule)
  : FileFunction(aModule)
{
}
  
ItemSequence_t
ReadXmlFunction::evaluate(const StatelessExternalFunction::Arguments_t& args,
                          const StaticContext* aSctxCtx,
                          const DynamicContext* aDynCtx) const
{
  String lFileStr = FileFunction::getFilePathString(aSctxCtx, args, 0);
  File_t lFile = File::createFile(lFileStr.c_str());

  std::ifstream lInStream;
  lFile->read(lInStream);

  XmlDataManager* lDataManager = Zorba::getInstance(0)->getXmlDataManager();
  Item lItem = lDataManager->parseDocument(lInStream);

  return ItemSequence_t(new SingletonItemSequence(lItem));
}

//*****************************************************************************

ReadTextFunction::ReadTextFunction(const FileModule* aModule)
  : FileFunction(aModule)
{
}
  
ItemSequence_t
ReadTextFunction::evaluate(const StatelessExternalFunction::Arguments_t& args,
                           const StaticContext* aSctxCtx,
                           const DynamicContext* aDynCtx) const
{
  String lFileStr = FileFunction::getFilePathString(aSctxCtx, args, 0);
  File_t lFile = File::createFile(lFileStr.c_str());

  std::ifstream lInStream;
  lFile->read(lInStream);

  std::stringstream lStrStream;
  char lBuf[1024];
  while (!lInStream.eof()) {
    lInStream.read(lBuf, 1024);
    lStrStream.write(lBuf, lInStream.gcount());
  }  

  XmlDataManager* lDataManager = Zorba::getInstance(0)->getXmlDataManager();

  std::string lResult = lStrStream.str();
  Item lItem = theModule->getItemFactory()->createString(lResult.c_str());

  return ItemSequence_t(new SingletonItemSequence(lItem));
}

//*****************************************************************************

RemoveFunction::RemoveFunction(const FileModule* aModule)
  : FileFunction(aModule)
{
}
  
ItemSequence_t
RemoveFunction::evaluate(const StatelessExternalFunction::Arguments_t& args,
                         const StaticContext* aSctxCtx,
                         const DynamicContext* aDynCtx) const
{
  String lFileStr = FileFunction::getFilePathString(aSctxCtx, args, 0);
  File_t lFile = File::createFile(lFileStr.c_str());

  bool lStatus = lFile->remove();

  return ItemSequence_t(new SingletonItemSequence(
      theModule->getItemFactory()->createBoolean(lStatus)));
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
