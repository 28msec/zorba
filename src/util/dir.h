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

#include "zorba/util/file.h"
#include "zorbatypes/rchandle.h"

#ifdef UNIX
#include <dirent.h>
#endif

namespace zorba {

  class dir_iterator : public SimpleRCObject
  {

    public:

      std::string dirpath;
      std::string path;
#ifndef WIN32
      DIR *dir;
      struct dirent *dirent;
#else
      HANDLE          win32_dir;
      WIN32_FIND_DATA win32_direntry;
#endif

    public:

      dir_iterator(const std::string& path, bool end_iterator = false);
      ~dir_iterator();

    public:	// iterator interface

      void operator++();

      bool end() const {
#ifndef WIN32
        return dir == 0;
#else
        return win32_dir == INVALID_HANDLE_VALUE;
#endif
      }

#ifndef WIN32
  		const char* operator*() { 
	      return dirent->d_name; 
      }
#else
      const TCHAR* operator*() { 
	      return win32_direntry.cFileName;
      }
#endif

    public:	
#ifndef WIN32
      const char* get_name() const { 
	      return dirent?dirent->d_name:0;
      }
#else
      const TCHAR* get_name() const { 
	      return (win32_dir != INVALID_HANDLE_VALUE) ? win32_direntry.cFileName : NULL;
      }
#endif
	};

  class directory : public file {
  
    public:
      dir_iterator begin();
      dir_iterator end();

	    friend bool operator!=(dir_iterator const& x, dir_iterator const& y);
  
  };

}
