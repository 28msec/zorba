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

#include "util/file.h"

namespace zorba {

class directory : public file {
public:
	class dir_iterator : public SimpleRCObject
	{
	public:
  	std::string dirpath;
  	std::string path;
#if ! defined (WIN32) 
  	DIR *dir;
  	struct dirent *dirent;
#else
		HANDLE						win32_dir;
		WIN32_FIND_DATA		win32_direntry;
#endif
	public:
  	dir_iterator(const std::string& path, bool end_iterator = false);
  	~dir_iterator();
	public:	// iterator interface
		void operator++();
#if ! defined (WIN32) 
		const char* operator*() { 
			return dirent->d_name; 
		}
#else
		const TCHAR* operator*() { 
			return win32_direntry.cFileName;
		}
#endif
	public:	
#if ! defined (WIN32) 
		const char* get_name() const { 
			return dirent?dirent->d_name:0;
		}
#else
		const TCHAR* get_name() const { 
			return (win32_dir != INVALID_HANDLE_VALUE) ? win32_direntry.cFileName : NULL;
		}
#endif
	};

  dir_iterator begin();
  dir_iterator end();

	friend bool operator!=(dir_iterator const& x, dir_iterator const& y);
  
};

}
