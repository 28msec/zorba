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

#ifndef ZORBA_FILE_H
#define ZORBA_FILE_H

#ifndef WIN32
#include <stdint.h>
#endif

#include <cstdio>
#include <string>
#include <time.h>
#include <vector>

#include <zorba/config.h>
#include <zorba/file.h>
#include <zorba/util/path.h>

namespace zorba {

class ZORBA_DLL_PUBLIC file : public filesystem_path
{
public:

  enum filetype {
    type_invalid,
    type_non_existent,
    type_directory,
    type_link,
    type_file,
    type_volume,
    type_other
  };

  typedef zorba::File::FileSize_t file_size_t;

protected:
  filetype type; 

// file attributes
  file_size_t size;          // size in bytes

  void do_stat();

public:
  file(const filesystem_path &path, int flags = 0);

public: // common methods
  void set_path(std::string const& _path ) { *((filesystem_path *) this) = _path; }
  void set_filetype(enum filetype _type ) { type = _type ; }
  enum filetype get_filetype();

  bool is_directory() const { return (type==type_directory); }  
  bool is_file() const { return (type==type_file); }  
  bool is_link() const { return (type==type_link); }  
  bool is_volume() const { return (type==type_volume); }  

  bool is_invalid() const { return (type==type_invalid); }  
  bool exists() const { return (type!=type_non_existent && type!=type_invalid); }  

  time_t lastModified();

public: // file methods
  void create();
  void remove(bool ignore = true);
  void rename(std::string const& newpath);

  file_size_t get_size() const        { return size; }

public: // directory methods
  void mkdir();
  void deep_mkdir();
  void rmdir(bool ignore = true);
#ifndef _WIN32_WCE
  void chdir();
#endif

  bool is_empty() const { return (size == (file_size_t)0); }
};


} // namespace zorba
#endif /* ZORBA_FILE_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
