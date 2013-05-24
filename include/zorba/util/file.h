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
  filetype do_stat( bool follow_symlinks = true, file_size_t *size = 0 ) const;

public:
  file(const filesystem_path &path, int flags = 0);

public: // common methods
  void set_path(std::string const& _path ) { *((filesystem_path *) this) = _path; }
  void set_filetype(filetype)   { /* do nothing */ }  // deprecated

  filetype get_filetype( bool follow_symlinks = true ) const {
    return do_stat( follow_symlinks );
  }

  bool is_directory( bool follow_symlinks = true ) const {
    return do_stat( follow_symlinks ) == type_directory;
  }

  bool is_file( bool follow_symlinks = true ) const {
    return do_stat( follow_symlinks ) == type_file;
  }

  bool is_link() const {
    return do_stat( false ) == type_link;
  }

  bool is_volume( bool follow_symlinks = true ) const {
    return do_stat( follow_symlinks ) == type_volume;
  }

  bool exists( bool follow_symlinks = true ) const {
    return do_stat( follow_symlinks ) != type_non_existent;
  }

  time_t lastModified() const;

public: // file methods
  void create();
  void remove(bool ignore = true);
  void rename(std::string const& newpath);

  file_size_t get_size() const {
    file_size_t size;
    do_stat( true, &size );
    return size;
  }

public: // directory methods
  void mkdir();
  void deep_mkdir();
  void rmdir(bool ignore = true);
  void lsdir(std::vector<std::string> &list);
#ifndef _WIN32_WCE
  void chdir();
#endif

  bool is_empty() const { return get_size() == 0; }
};


} // namespace zorba
#endif /* ZORBA_FILE_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
