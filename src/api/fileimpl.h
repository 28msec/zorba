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
#ifndef XQP_FILE_IMPL_H
#define XQP_FILE_IMPL_H

#include <iostream>
#include <zorba/file.h>

namespace zorba {

  class file;
  class dir_iterator;
  class DefaultErrorHandler;


  class DirectoryIteratorImpl : public DirectoryIterator
  {
    private:

      dir_iterator*     theInternalDirIter;

    public:

      DirectoryIteratorImpl(std::string const& aPath);

      ~DirectoryIteratorImpl() {}

      bool next(std::string& aPathStr) const;

  };

  class FileImpl : public File
  {
    private:

      zorba::file*          theInternalFile;

      DefaultErrorHandler*  theErrorHandler; 
    
    public:

      FileImpl(std::string const& _path);

      ~FileImpl();


    public: // public methods

      bool isDirectory() const;
      bool isFile() const;
      bool isLink() const;
      bool isVolume() const;
      bool isInvalid() const;
      bool exists() const;

      bool remove();
      bool create();
      bool rename(std::string const& newpath);

      FileSize_t getSize() const;

      bool mkdir();
      bool mkdirs();

      DirectoryIterator_t files() const;

      void read(std::ifstream& aInStream) const;

      time_t lastModified() const;

  };

} /* namespace zorba */

#endif
