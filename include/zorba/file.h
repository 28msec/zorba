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
#ifndef ZORBA_FILE_API_H
#define ZORBA_FILE_API_H

#include <string>

#include <zorba/config.h>
#include <zorba/api_shared_types.h>

namespace zorba {

  /** \brief This class is the representation of file system file.
   *
   * ...
   */
  class ZORBA_DLL_PUBLIC DirectoryIterator : public SmartObject
  {
    public:

      virtual ~DirectoryIterator() {}

      virtual bool next(std::string& aPathStr) const = 0;
      /** \brief Rewind the file find iterator
      */
      virtual void reset() = 0;
  };


  /** \brief This class is the representation of file system file.
   *
   * ...
   */
  class ZORBA_DLL_PUBLIC File : public SmartObject
  {
    public: // constructors

      virtual ~File() {}

      static File_t createFile(const std::string& path);

      static const char* getDirectorySeparator();

      static const char* getPathSeparator();

    public: // type, enums

#ifdef WIN32
      typedef __int64 FileSize_t;
#else
      typedef int64_t FileSize_t;
#endif


    public: // public methods

      virtual const std::string getFilePath() const = 0;
      virtual const std::string getFileUri() const = 0;

      virtual bool isDirectory() const = 0;
      virtual bool isFile() const = 0;
      virtual bool isLink() const = 0;
      virtual bool isVolume() const = 0;
      virtual bool isInvalid() const = 0;
      virtual bool exists() const = 0;

      virtual void remove() = 0;
      virtual bool create() = 0;
      virtual bool rename(std::string const& newpath) = 0;

      virtual FileSize_t getSize() const = 0;

      virtual void mkdir(bool recursive) = 0;

      virtual DirectoryIterator_t files() const = 0;

      virtual void openInputStream(std::ifstream& aInStream, bool binary, bool trimByteOrderMark) const = 0;
      virtual void openOutputStream(std::ofstream& aOutStream, bool binary, bool append) const = 0;

      virtual time_t lastModified() const = 0;

  };

} /* namespace zorba */

#endif
/* vim:set et sw=2 ts=2: */
