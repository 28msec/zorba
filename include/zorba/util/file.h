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
#include <stdio.h>

#if ! defined (WIN32) 
#include <dirent.h>
#endif
#include <time.h>
#include <string>

#include <zorba/config.h>

#include <zorba/util/path.h>

namespace zorba {

class file : public filesystem_path
{
public:
  enum filetype {
    type_invalid,
    type_non_existent,
    type_directory,
    type_link,
    type_file,
    type_volume
  };

public:
  enum rwaccess {
    ro = 1, // Read-Only
    wo = 2, // WriteOnly
    rw = 3  // Read and Write
  };

protected:
  enum filetype type; 

// file attributes
  int64_t  size;          // size in bytes
#if ! defined (WIN32) 
  time_t   atime;         // most recent access time
  time_t   mtime;         // most recent mod time
#else
  FILETIME  atime;
  FILETIME  mtime;
#endif

  void do_stat ();

public:
  file(const filesystem_path &path, int flags = 0);

public: // common methods
  void set_path(std::string const& _path ) { path = filesystem_path (_path); }
  void set_filetype(enum filetype _type ) { type = _type ; }
  enum filetype get_filetype();

  bool is_directory() const { return (type==type_directory); }  
  bool is_file() const { return (type==type_file); }  
  bool is_link() const { return (type==type_link); }  
  bool is_volume() const { return (type==type_volume); }  

  bool is_invalid() const { return (type==type_invalid); }  
  bool exists() const { return (type!=type_non_existent && type!=type_invalid); }  
  static volatile void error(std::string const& location, std::string const& msg);
  static void sync() { 
#if defined (UNIX)
  ::sync(); 
#else
  _flushall();
#endif
  }


public: // file methods
  void create();
  void remove(bool ignore = true);
  void rename(std::string const& newpath);

  int64_t get_size() const        { return size; }
#if ! defined (WIN32) 
  time_t  get_acctime() const     { return atime; }
  time_t  get_modtime() const     { return mtime; }
#else
  FILETIME  get_acctime() const     { return atime; }
  FILETIME  get_modtime() const     { return mtime; }

#endif

public: // directory methods
  void mkdir();
  void deep_mkdir();
  void rmdir(bool ignore);
#ifndef _WIN32_WCE
  void chdir();
#endif

  bool is_empty() const { return (size == (int64_t)0); }
};


} /* namespace zorba */
#endif /* ZORBA_FILE_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
