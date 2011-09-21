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
#include "stdafx.h"

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

#include "diagnostics/xquery_diagnostics.h"

using namespace std;

namespace zorba {

// dir_iterator

#define END true

dir_iterator
directory::begin()
{
  return dir_iterator(getPathString());
}

dir_iterator
directory::end()
{
  return dir_iterator(getPathString(), END);
}

dir_iterator::dir_iterator(
    string const& path,
    bool end_iterator)
:
    dirpath(path)
#ifndef WIN32
    ,dirent(0)
#endif
{
#ifndef WIN32
  dir = opendir(path.c_str());
  if (dir==0) {
    throw ZORBA_IO_EXCEPTION( "opendir()", path );
  }
  if (!end_iterator) operator++();
#else
  if(!end_iterator) {
    std::string path_star = path + "\\*.*";
    WCHAR wpath_str[1024];
    wpath_str[0] = 0;
    if(MultiByteToWideChar(CP_UTF8,
                        0, path_star.c_str(), -1,
                        wpath_str, sizeof(wpath_str)/sizeof(WCHAR)) == 0)
    {//probably there is some invalid utf8 char, try the Windows ACP
      MultiByteToWideChar(CP_ACP,
                        0, path_star.c_str(), -1,
                        wpath_str, sizeof(wpath_str)/sizeof(WCHAR));
    }
    win32_dir = FindFirstFileW(wpath_str, &win32_direntry);
    if(win32_dir == INVALID_HANDLE_VALUE) {
      throw ZORBA_IO_EXCEPTION( "FindFirstFile()", path );
    }
    if (wcscmp(win32_direntry.cFileName, L".") == 0 ||
      wcscmp(win32_direntry.cFileName, L"..") == 0) {
        operator ++();
    }
  } else {
    win32_dir = INVALID_HANDLE_VALUE;
    wcscpy(win32_direntry.cFileName, L"");
  }
#endif

}

dir_iterator::~dir_iterator()
{
#if ! defined (WIN32) 
  if (dir!=0) closedir(dir);
#else
  if(win32_dir != INVALID_HANDLE_VALUE) {
    FindClose(win32_dir);
  }
#endif
}


void
dir_iterator::operator++()
{
#ifndef WIN32
  if (dir!=0) {
    while (true) {
      dirent = readdir(dir);
      if (dirent==0) { 
        closedir(dir); 
        dir = 0; 
        break; 
      }
      if (strcmp(dirent->d_name,".") &&
          strcmp(dirent->d_name,"..")) {
        break;
      }
    }
  }
#else
  if(win32_dir != INVALID_HANDLE_VALUE) {
    while(true) {
      if(!FindNextFileW(win32_dir, &win32_direntry)) {        
        FindClose(win32_dir); 
        win32_dir = INVALID_HANDLE_VALUE; 
        wcscpy(win32_direntry.cFileName, L"");
        break; 
      }
      if (wcscmp(win32_direntry.cFileName, L".") &&
          wcscmp(win32_direntry.cFileName, L"..")) {
        break;
      }
    }
  }
#endif
}

bool operator!=(
    dir_iterator const& x,
    dir_iterator const& y)
{
#ifndef WIN32
  if (x.dirpath==y.dirpath) return false;
  if (x.dirent==y.dirent) return false;
  return true;
#else
  if (x.dirpath==y.dirpath) return false;
  if (!wcscmp(x.win32_direntry.cFileName, y.win32_direntry.cFileName)) return false;
  return true;
#endif
}

}  // namespace
/* vim:set et sw=2 ts=2: */
