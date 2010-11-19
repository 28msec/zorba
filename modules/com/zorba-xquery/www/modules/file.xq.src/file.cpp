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

#include <fstream>
#include <sstream>

#include <zorba/file.h>
#include <zorba/empty_sequence.h>
#include <zorba/singleton_item_sequence.h>
#include <zorba/serializer.h>
#include <zorba/store_consts.h>
#include <zorba/base64.h>
#include <zorba/util/path.h>

#include "file_module.h"


namespace zorba { namespace filemodule {

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

  String lSrcFileStr = FileFunction::getFilePathString(aSctxCtx, aArgs, 0);
  File_t lSrcFile = File::createFile(lSrcFileStr.c_str());
  String lDstFileStr = FileFunction::getFilePathString(aSctxCtx, aArgs, 1);
  File_t lDstFile = File::createFile(lDstFileStr.c_str());

  // do we have overwrite existing files?
  bool lOverwrite = false;
  if (aArgs.size() == 3) {
    Item lOverwriteItem;
    aArgs[2]->next(lOverwriteItem);
    lOverwrite = lOverwriteItem.getBooleanValue();
  }

  // only continue if we have a file to copy
  // AND (
  //  if the destination is not present
  //    OR
  //  if the overwrite flag, but, in this case, the desfination must be a file
  // )
  if (lSrcFile->isFile() && (!lDstFile->exists() || (lOverwrite && lDstFile->isFile()))) {

    // open the output stream in the desired write mode
    std::ifstream lInStream;
    std::ofstream lOutStream;
    lSrcFile->openInputStream(lInStream);
    lDstFile->openOutputStream(lOutStream);

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
  }

  return ItemSequence_t(new SingletonItemSequence(
      theModule->getItemFactory()->createBoolean(lResult)));
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
  String lFileStr = FileFunction::getFilePathString(aSctxCtx, aArgs, 0);

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
FilesFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  String lFileStr = FileFunction::getFilePathString(aSctxCtx, aArgs, 0);
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
  lItem = theItemFactory->createString(lUriStr);
  return true;
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
  String lFileStr = FileFunction::getFilePathString(aSctxCtx, aArgs, 0);

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
  String lFileStr = FileFunction::getFilePathString(aSctxCtx, aArgs, 0);

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
LastModifiedFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  String lFileStr = FileFunction::getFilePathString(aSctxCtx, aArgs, 0);
  File_t lFile = File::createFile(lFileStr.c_str());

  if(!lFile->exists()) {
    std::stringstream lErrorMessage;
    lErrorMessage << "The provided path/URI does not point to a file system item.";
    throwError(lErrorMessage.str(), XPTY0004);
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

MkdirFunction::MkdirFunction(const FileModule* aModule)
  : FileFunction(aModule)
{
}
  
ItemSequence_t
MkdirFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  String lFileStr = FileFunction::getFilePathString(aSctxCtx, aArgs, 0);
  File_t lFile = File::createFile(lFileStr.c_str());

  bool lCreate = true;
  if (aArgs.size() == 2) {
    Item lCreateItem;
    if (aArgs[1]->next(lCreateItem)) {
      lCreate = lCreateItem.getBooleanValue();
    }
  }

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
MkdirsFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  String lFileStr = FileFunction::getFilePathString(aSctxCtx, aArgs, 0);
  File_t lFile = File::createFile(lFileStr.c_str());

  bool lCreate = true;
  if (aArgs.size() == 2) {
    Item lCreateItem;
    if (aArgs[1]->next(lCreateItem)) {
      lCreate = lCreateItem.getBooleanValue();
    }
  }

  bool lStatus = lFile->mkdirs(lCreate);

  return ItemSequence_t(new SingletonItemSequence(
    theModule->getItemFactory()->createBoolean(lStatus)));
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

PathToFullPathFunction::PathToFullPathFunction(const FileModule* aModule)
  : FileFunction(aModule)
{
}
  
ItemSequence_t
PathToFullPathFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  String lPathStr = FileFunction::getFilePathString(aSctxCtx, aArgs, 0);
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
  String lPathStr = FileFunction::getFilePathString(aSctxCtx, aArgs, 0);
  String lResult = FileFunction::pathToUriString(lPathStr);

  return ItemSequence_t(new SingletonItemSequence(theModule->getItemFactory()->createAnyURI(lResult)));
}

//*****************************************************************************

ReadFunction::ReadFunction(const FileModule* aModule)
  : FileFunction(aModule)
{
}
  
ItemSequence_t
ReadFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  String lFileStr = FileFunction::getFilePathString(aSctxCtx, aArgs, 0);
  File_t lFile = File::createFile(lFileStr.c_str());

  std::ifstream lInStream;
  lFile->openInputStream(lInStream, true);

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
    throw ExternalFunctionData::createZorbaException(XPTY0004, "Error while building the base64binaty item.", __FILE__, __LINE__);
  }

  return ItemSequence_t(new SingletonItemSequence(lItem));
}

//*****************************************************************************

ReadTextFunction::ReadTextFunction(const FileModule* aModule)
  : FileFunction(aModule)
{
}
  
ItemSequence_t
ReadTextFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  String lFileStr = FileFunction::getFilePathString(aSctxCtx, aArgs, 0);
  File_t lFile = File::createFile(lFileStr.c_str());

  std::ifstream lInStream;
  lFile->openInputStream(lInStream);

  std::stringstream lStrStream;
  char lBuf[1024];
  while (!lInStream.eof()) {
    lInStream.read(lBuf, 1024);
    lStrStream.write(lBuf, lInStream.gcount());
  }  

  std::string lResult = lStrStream.str();
  Item lItem = theModule->getItemFactory()->createString(lResult.c_str());

  return ItemSequence_t(new SingletonItemSequence(lItem));
}

//*****************************************************************************

ReadXmlFunction::ReadXmlFunction(const FileModule* aModule)
  : FileFunction(aModule)
{
}
  
ItemSequence_t
ReadXmlFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  String lFileStr = FileFunction::getFilePathString(aSctxCtx, aArgs, 0);
  File_t lFile = File::createFile(lFileStr.c_str());

  std::ifstream lInStream;
  lFile->openInputStream(lInStream);

  XmlDataManager* lDataManager = Zorba::getInstance(0)->getXmlDataManager();
  Item lItem = lDataManager->parseDocument(lInStream);

  return ItemSequence_t(new SingletonItemSequence(lItem));
}

//*****************************************************************************

RemoveFunction::RemoveFunction(const FileModule* aModule)
  : FileFunction(aModule)
{
}
  
ItemSequence_t
RemoveFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  String lFileStr = FileFunction::getFilePathString(aSctxCtx, aArgs, 0);
  File_t lFile = File::createFile(lFileStr.c_str());

  bool lStatus = lFile->remove();

  return ItemSequence_t(new SingletonItemSequence(
      theModule->getItemFactory()->createBoolean(lStatus)));
}

//*****************************************************************************

WriteFunction::WriteFunction(const FileModule* aModule)
  : FileFunction(aModule)
{
}
  
ItemSequence_t
WriteFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  String lFileStr = FileFunction::getFilePathString(aSctxCtx, aArgs, 0);
  File_t lFile = File::createFile(lFileStr.c_str());

  // do we have an "append" or a "write new" operation?
  bool lAppend = false;
  if (aArgs.size() == 4) {
    Item lAppendItem;
    aArgs[3]->next(lAppendItem);
    lAppend = lAppendItem.getBooleanValue();
  }
  
  Serializer_t lSerializer = Serializer::createSerializer(aArgs.at(2));

  bool lBinary = false;
  if (lSerializer->getSerializationMethod() == ZORBA_SERIALIZATION_METHOD_BINARY) {
    lBinary = true;
  }

  // open the output stream in the desired write mode
  std::ofstream lOutStream;
  lFile->openOutputStream(lOutStream, lAppend, lBinary);

  // serialize the content
  lSerializer->serialize((Serializable*)aArgs[1], lOutStream);

  lOutStream.close();

  return ItemSequence_t(new EmptySequence());
}

const Zorba_SerializerOptions_t
WriteFunction::createSerializerOptions(const Item& aItem) const
{
  Zorba_SerializerOptions_t lOptions;
  
  // in case the parameter is a string
  if (aItem.isAtomic()) {
    zorba::String lMethod = aItem.getStringValue();
    if (lMethod == "xml") {
      lOptions.ser_method = ZORBA_SERIALIZATION_METHOD_XML;
    } else if (lMethod == "html") {
      lOptions.ser_method = ZORBA_SERIALIZATION_METHOD_HTML;
    } else if (lMethod == "xhtml") {
      lOptions.ser_method = ZORBA_SERIALIZATION_METHOD_XHTML;
    } else if (lMethod == "text") {
      lOptions.ser_method = ZORBA_SERIALIZATION_METHOD_TEXT;
    } else if (lMethod == "json") {
      lOptions.ser_method = ZORBA_SERIALIZATION_METHOD_JSON;
    } else if (lMethod == "jsonml") {
      lOptions.ser_method = ZORBA_SERIALIZATION_METHOD_JSONML;
    } else {
      throwInvalidSerializationOptionValue();
    }
  // if we have an element node
  } else if (aItem.isNode() && aItem.getNodeKind() == store::StoreConsts::elementNode) {
    // and must have "output" as local name
    Item lQName;
    aItem.getNodeName(lQName);
    zorba::String lLocalName = lQName.getLocalName();
    if(lLocalName != "output") {
      throwInvalidSerializationOptionValue();
    }
    // iterate all the atributes and set the serialization options accordingly
    // NOTE: Extra attributes and invalid values for attributes are ignored.
    Iterator_t lIter = aItem.getAttributes();
    lIter->open();
    Item lAttribute;
    while (lIter->next(lAttribute)) {
      Item lAttributeQName;
      lAttribute.getNodeName(lAttributeQName);
      lOptions.SetSerializerOption(lAttributeQName.getLocalName().c_str(), lAttribute.getStringValue().c_str());
    }
    lIter->close();
  } else {
    throwInvalidSerializationOptionValue();
  }

  return lOptions;
}

void
WriteFunction::throwInvalidSerializationOptionValue() const
{
  std::stringstream lErrorMessage;
  lErrorMessage << "Invalid serialization options parameter. "
      << "Please see the documentation for valid values.";
  throwError(lErrorMessage.str(), XPTY0004);
}


//*****************************************************************************
NormalizePathFunction::NormalizePathFunction(const FileModule* aModule)
  : FileFunction(aModule)
{
}

ItemSequence_t NormalizePathFunction::evaluate(const StatelessExternalFunction::Arguments_t& args,
                                const StaticContext* aSctxCtx,
                                const DynamicContext* aDynCtx) const
{
  Item pathItem;
  args[0]->next(pathItem);
  String osPath = filesystem_path::resolve_path(pathItem.getStringValue().c_str());
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
