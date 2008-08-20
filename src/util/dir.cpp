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

#include "util/dir.h"

#ifndef _WIN32_WCE
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#else
#include <types.h>
#endif
#include <stdio.h>

#if defined (WIN32) 
#include <tchar.h>
#ifndef _WIN32_WCE
#include <io.h>
#include <direct.h>
#endif
#else
#include <sys/param.h>
#include <unistd.h>
#endif

#ifndef _WIN32_WCE
#include <fcntl.h>
#endif
#include <sstream>

#include "zorbaerrors/error_manager.h"

using namespace std;

namespace zorba {

// dir_iterator

#define END true

directory::dir_iterator directory::begin()
{
  return directory::dir_iterator(path);
}

directory::dir_iterator directory::end()
{
  return directory::dir_iterator(path, END);
}

directory::dir_iterator::dir_iterator(
	string const& path,
	bool end_iterator)

:
	dirpath(path)
#if ! defined (WIN32) 
	,dirent(0)
#endif
{
#if ! defined (WIN32) 
	dir = opendir(path.c_str());
  if (dir==0) {
    error(__FUNCTION__, "opendir failed on "+dirpath);
	}
  if (!end_iterator) operator++();
#else
	if(!end_iterator)
	{
		if((*path.end() == '/') || (*path.end() == '\\'))
			win32_dir = FindFirstFile((LPCTSTR)(path+"\\*.*").c_str(), &win32_direntry);
		else
			win32_dir = FindFirstFile((LPCTSTR)(path+"*.*").c_str(), &win32_direntry);
		if(win32_dir == INVALID_HANDLE_VALUE)
			error(__FUNCTION__, "opendir failed on "+dirpath);
	}
	else
	{
		win32_dir = INVALID_HANDLE_VALUE;
#ifdef UNICODE
		_tcscpy(win32_direntry.cFileName, _T(""));
#else
		strcpy(win32_direntry.cFileName, "");
#endif
	}
#endif

}


directory::dir_iterator::~dir_iterator()
{
#if ! defined (WIN32) 
  if (dir!=0) closedir(dir);
#else
	if(win32_dir != INVALID_HANDLE_VALUE)
		FindClose(win32_dir);
#endif
}


void directory::dir_iterator::operator++()
{
#if ! defined (WIN32) 
  if (dir!=0) {
    while (true) {
      dirent = readdir(dir);
      if (dirent==0) { 
        closedir(dir); 
        dir = 0; 
        break; 
      }
      if (strcmp(dirent->d_name,".") &&
          strcmp(dirent->d_name,"..") &&
          strcmp(dirent->d_name,"lost+found")) {
        break;
			}
    }
  }
#else
	if(win32_dir != INVALID_HANDLE_VALUE)
	{
		while(true)
		{
			if(!FindNextFile(win32_dir, &win32_direntry))
			{				
        FindClose(win32_dir); 
        win32_dir = INVALID_HANDLE_VALUE; 
				_tcscpy(win32_direntry.cFileName, _T(""));
        break; 
      }
			if (_tcscmp(win32_direntry.cFileName,_T(".")) &&
          _tcscmp(win32_direntry.cFileName,_T("..")) &&
          _tcscmp(win32_direntry.cFileName,_T("lost+found"))) //daniel ??
			{
        break;
			}
		}
	}
#endif
}


bool operator!=(
	directory::dir_iterator const& x,
	directory::dir_iterator const& y)
{
#if ! defined (WIN32) 
	if (x.dirpath==y.dirpath) return false;
	if (x.dirent==y.dirent) return false;
	return true;
#else
	if (x.dirpath==y.dirpath) return false;
	if (!_tcscmp(x.win32_direntry.cFileName, y.win32_direntry.cFileName)) return false;
	return true;
#endif
}

}  // namespace
