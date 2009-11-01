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

#include "api/fileimpl.h"
#include "api/zorbaimpl.h"
#include "zorba/default_error_handler.h"
#include "runtime/util/flowctl_exception.h"

#include "zorbaerrors/errors.h"
#include "zorbaerrors/error_manager.h"

#include <zorba/util/file.h>
#include "util/dir.h"

#include <fstream>

namespace zorba {

DirectoryIteratorImpl::DirectoryIteratorImpl(std::string const& aPath)
{
  theInternalDirIter = new dir_iterator(aPath);
}

DirectoryIteratorImpl::~DirectoryIteratorImpl()
{
  delete theInternalDirIter;
}

bool
DirectoryIteratorImpl::next(std::string& aPathStr) const
{
  if (theInternalDirIter->end()) {
    return false;
  }

  // get the current pointed entry
  aPathStr = *(*theInternalDirIter);

  // advance to the next entry
  ++(*theInternalDirIter);

  return true;
}

FileImpl::FileImpl(std::string const& path)
  : theErrorHandler(new DefaultErrorHandler())
{
  theInternalFile = new file(path
#ifdef WIN32
      , filesystem_path::CONVERT_SLASHES
#endif
    );
}

FileImpl::~FileImpl()
{
  delete theInternalFile;
  delete theErrorHandler;
}

File_t
File::createFile(const std::string& path) {
  return new FileImpl(path);
}


bool
FileImpl::isDirectory() const {
  bool lResult = false;

  ZORBA_TRY
    lResult = theInternalFile->is_directory() || theInternalFile->is_volume() || theInternalFile->is_root() ;
  ZORBA_CATCH

  return lResult;
};

bool
FileImpl::isFile() const
{
  bool lResult = false;

  ZORBA_TRY
    lResult = theInternalFile->is_file() || theInternalFile->is_link();
  ZORBA_CATCH

  return lResult;
}

bool
FileImpl::isLink() const
{
  bool lResult = false;

  ZORBA_TRY
    lResult = theInternalFile->is_link();
  ZORBA_CATCH

  return lResult;
}

bool
FileImpl::isVolume() const
{
  bool lResult = false;

  ZORBA_TRY
    lResult = theInternalFile->is_volume();
  ZORBA_CATCH

  return lResult;
}

bool
FileImpl::isInvalid() const
{
  bool lResult = false;

  ZORBA_TRY
    lResult = theInternalFile->is_invalid();
  ZORBA_CATCH

  return lResult;
}

bool
FileImpl::exists() const
{
  bool lResult = false;

  ZORBA_TRY
    lResult = theInternalFile->exists();
  ZORBA_CATCH

  return lResult;
}

bool
FileImpl::remove()
{
  bool lResult = false;

  ZORBA_TRY
    // if the file/dir does not exist, return false
    if (!theInternalFile->exists()) {
      return false;
    }

    if (theInternalFile->is_directory()) {
      theInternalFile->rmdir();
    } else {
      theInternalFile->remove();
    }

    // if the file/dir still exist, return false
    if (theInternalFile->exists()) {
      return false;
    }

    lResult = true;
  ZORBA_CATCH

  return lResult;
}

bool
FileImpl::create()
{
  bool lResult = false;

  ZORBA_TRY
    // if the file/dir exist, return false
    if (theInternalFile->exists()) {
      return false;
    }

    theInternalFile->create();

    // if the file does not exist, return false
    if (!theInternalFile->exists() || !theInternalFile->is_file()) {
      return false;
    }

    lResult = true;
  ZORBA_CATCH

  return lResult;
}

bool
FileImpl::rename(std::string const& newpath)
{
  bool lResult = false;

  ZORBA_TRY
    // if the file/dir does not exist, return false
    if (!theInternalFile->exists()) {
      return false;
    }
    // if the new path is already used, return false
    file lNewFile(newpath);
    if (lNewFile.exists()) {
      return false;
    }

    theInternalFile->rename(newpath);

    // if the file does not exist, return false
    if (!lNewFile.exists()) {
      return false;
    }

    lResult = true;
  ZORBA_CATCH

  return lResult;
}

File::FileSize_t
FileImpl::getSize() const
{
  ZORBA_TRY
    return theInternalFile->get_size();
  ZORBA_CATCH
  assert(false);
  return -1;
}

bool
FileImpl::mkdir()
{
  bool lResult = false;

  ZORBA_TRY
    // if the dir/file already exists, return false
    if (theInternalFile->exists()) {
      return false;
    }

    theInternalFile->mkdir();

    lResult = true;
  ZORBA_CATCH

  return lResult;
}

bool
FileImpl::mkdirs()
{
  bool lResult = false;

  ZORBA_TRY
    // if the dir/file already exists, return false
    if (theInternalFile->exists()) {
      return false;
    }

    theInternalFile->deep_mkdir();
    lResult = true;
  ZORBA_CATCH

  return lResult;
}

DirectoryIterator_t
FileImpl::files() const
{
  return new DirectoryIteratorImpl(theInternalFile->get_path());
}

void
FileImpl::openInputStream(std::ifstream& aInStream) const
{
  ZORBA_TRY
    std::string lPath(theInternalFile->get_path());

    if (!theInternalFile->exists()) {
      ZORBA_ERROR_DESC_OSS(FODC0002, "File not found: " << lPath);
    }
    if (!theInternalFile->is_file()) {
      ZORBA_ERROR_DESC_OSS(FODC0002, "\"" << lPath << "\" is not a file");
    }
    aInStream.open(lPath.c_str(), std::ifstream::in);
    if (aInStream.is_open() == false) {
      ZORBA_ERROR_DESC_OSS(FODC0002, "File not accessible: " << lPath);
    }
  ZORBA_CATCH
}

void
FileImpl::openOutputStream(std::ofstream& aOutStream, bool append) const
{
  ZORBA_TRY
    std::string lPath(theInternalFile->get_path());

    if (theInternalFile->exists() && !theInternalFile->is_file()) {
      ZORBA_ERROR_DESC_OSS(FODC0002, "\"" << lPath << "\" is not a file");
    }

    std::_Ios_Openmode lMode = (append ?
                                std::ofstream::app :
                                (std::ofstream::out | std::ofstream::trunc));

    aOutStream.open(lPath.c_str(), lMode);
    if (aOutStream.is_open() == false) 
    {
      ZORBA_ERROR_DESC_OSS(FODC0002, "File not accessible: " << lPath);
    }
  ZORBA_CATCH
}

time_t
FileImpl::lastModified() const
{
  return theInternalFile->lastModified();
}

} /* namespace zorba */
