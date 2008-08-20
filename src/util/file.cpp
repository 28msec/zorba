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

#include <zorba/config.h>
#if ! defined (WIN32) && ! defined (APPLE)
#define _XOPEN_SOURCE 600  // getcwd
#endif

#include "util/file.h"

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

const char *filesystem_path::get_path_separator () {
#ifdef WIN32
  return "\\";
#else
  return "/";
#endif
}

filesystem_path::filesystem_path () {
  char buf [512];
#ifdef WIN32
  GetCurrentDirectory (sizeof (buf), buf);
#else
  if (getcwd (buf, sizeof (buf)) == NULL) {
    file::error (__FUNCTION__, "current directory path too long");
  }
  else path = buf;
#endif
#ifdef WIN32
  resolve_relative ();
#endif
}

bool filesystem_path::is_absolute () const {
#ifdef WIN32
  // c:dir1\file is NOT absolute! Only c:\dir\file is
  if (path.size () >= 3 && isalpha (path [0]) && path [1] == ':' && path [2] == '\\')
    return true;
#endif
  const std::string &sep = get_path_separator ();
  if (path.compare (0, sep.size (), sep) == 0)
    return true;
  return false;
}

void filesystem_path::resolve_relative () {
  if (! is_absolute ()) {
#ifdef WIN32
    // call GetFullPathName as per
    // http://msdn.microsoft.com/en-us/library/aa364963(VS.85).aspx 
    
    char fullpath[1024];
    fullpath[0] = 0;
    GetFullPathName(path.c_str(), sizeof(fullpath), fullpath, NULL);
    path = fullpath;
#else
    *this = filesystem_path (filesystem_path (), *this);
#endif
  }
}


void file::do_stat () {
#if ! defined (WIN32) 
  struct stat st;
  if (::stat(path.c_str(), &st)) {
    if (errno!=ENOENT) file::error(__FUNCTION__,"stat failed on "+path.get_path ());
  } 
  else {
    size  = st.st_size;
    atime = st.st_atime;
    mtime = st.st_mtime;
    type  = (st.st_mode & S_IFDIR)  ? type_directory :
            (st.st_mode & S_IFREG ) ? type_file :
            (st.st_mode & S_IFLNK)  ? type_link : type_invalid;
  }
#else
  WIN32_FIND_DATA   findData;
  HANDLE            hfind;
#ifdef UNICODE
  TCHAR path_str[1024];
  MultiByteToWideChar(CP_ACP,/// or CP_UTF8
                      0, path.c_str(), -1,
                      path_str, sizeof(path_str)/sizeof(TCHAR));
#else
  const char  *path_str = path.c_str();
#endif

  hfind = FindFirstFile(path_str, &findData);
  if(hfind == INVALID_HANDLE_VALUE)
  {
    error(__FUNCTION__,"file/dir not exist "+path);
  }
  else
  {
    size = findData.nFileSizeLow + (((int64_t)(findData.nFileSizeHigh))<<32);
    atime = findData.ftLastAccessTime;
    mtime = findData.ftLastWriteTime;
    type  = (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)  ? type_directory :
            (findData.dwFileAttributes & FILE_ATTRIBUTE_ARCHIVE ) ? type_file :
            //(st.st_mode & S_IFLNK)  ? type_link : 
            type_invalid;
    FindClose(hfind);
  }
#endif
}

file::file(const std::string& _path)
:
  path(_path),
  type(type_non_existent)
{
  do_stat ();
}


file::file(
  std::string const& base,
  std::string const& name)
:
  path (base+ filesystem_path::get_path_separator () +name),
  type (type_non_existent)
{
  do_stat ();
}


enum file::filetype file::get_filetype() {
  if (type!=type_non_existent) return type;

#if ! defined (WIN32) 
  // call native file system status
  struct stat st;
  if (::stat(path.c_str(), &st)) {
    if (errno==ENOENT) {
      errno = 0;
      return (type = type_non_existent);
    }
    error(__FUNCTION__,"stat failed on "+path);
  } 
  size  = st.st_size;
  atime = st.st_atime;
  mtime = st.st_mtime;
  return (type  = (st.st_mode & S_IFDIR)  ? type_directory :
                  (st.st_mode & S_IFREG ) ? type_file :
                  //(st.st_mode & S_IFLNK)  ? type_link : 
                  type_invalid );

#else

  WIN32_FIND_DATA   findData;
  HANDLE            hfind;
#ifdef UNICODE
  TCHAR path_str[1024];
  MultiByteToWideChar(CP_ACP,/// or CP_UTF8
                      0, path.c_str(), -1,
                      path_str, sizeof(path_str)/sizeof(TCHAR));
#else
  const char  *path_str = path.c_str();
#endif
  hfind = FindFirstFile(path_str, &findData);
  if(hfind == INVALID_HANDLE_VALUE)
  {
    error(__FUNCTION__,"file/dir not exist "+path);
    return type_non_existent;
  }
  else
  {
    size = findData.nFileSizeLow + (((int64_t)(findData.nFileSizeHigh))<<32);
    atime = findData.ftLastAccessTime;
    mtime = findData.ftLastWriteTime;
    type  = (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)  ? type_directory :
            (findData.dwFileAttributes & FILE_ATTRIBUTE_ARCHIVE ) ? type_file :
            //(st.st_mode & S_IFLNK)  ? type_link : 
            type_invalid;
    FindClose(hfind);
    return type;
  }
#endif  
}



volatile void file::error(
  string const& location,
  string const& msg)
{
  ZORBA_ERROR_DESC( XQP0011_SYSTEM_FILE_ERROR_IN_FUNCTION, msg);
}


void file::create() {
#ifndef WIN32
  int fd = ::creat(path.c_str(),0666);
  if (fd < 0) error(__FUNCTION__, "failed to create file "+path);
  ::close(fd);
  set_filetype(type_file); 
#else
#ifdef UNICODE
  TCHAR path_str[1024];
  MultiByteToWideChar(CP_ACP,/// or CP_UTF8
                      0, path.c_str(), -1,
                      path_str, sizeof(path_str)/sizeof(TCHAR));
#else
  const char  *path_str = path.c_str();
#endif
  HANDLE fd = CreateFile(path_str,GENERIC_READ | GENERIC_WRITE, 
                      FILE_SHARE_READ | FILE_SHARE_WRITE, NULL,
                      CREATE_ALWAYS, 0, NULL);
  if (fd == INVALID_HANDLE_VALUE) 
    error(__FUNCTION__, "failed to create file "+path);
  CloseHandle(fd);
  set_filetype(type_file); 
#endif
}


void file::mkdir() {
#if ! defined (WIN32) 
  if (::mkdir(path.c_str(),0777)) {
    ostringstream oss;
    oss<<"mkdir failed ["<<strerror(errno) << "]"<<"] for: "<<path;
    cout << oss.str() << endl;  //XXX DEBUG
    error(__FUNCTION__,oss.str());
  }
  set_filetype(file::type_directory);
#else
#ifdef UNICODE
  TCHAR path_str[1024];
  MultiByteToWideChar(CP_ACP,/// or CP_UTF8
                      0, path.c_str(), -1,
                      path_str, sizeof(path_str)/sizeof(TCHAR));
#else
  const char  *path_str = path.c_str();
#endif
  if (!CreateDirectory(path_str, NULL))
  {
    ostringstream oss;
    oss<<"mkdir failed ["<<GetLastError() << "]"<<"] for: "<<path;
    cout << oss.str() << endl;  //DEBUG
    error(__FUNCTION__,oss.str());
  }
  set_filetype(file::type_directory);
#endif
}


void file::remove(bool ignore) {
#if ! defined (WIN32) 
  if (::remove(path.c_str()) && !ignore) {
    error(__FUNCTION__, "failed to remove "+path);
  }
#else
  BOOL  retval = TRUE;
#ifdef UNICODE
  TCHAR path_str[1024];
  MultiByteToWideChar(CP_ACP,/// or CP_UTF8
                      0, path.c_str(), -1,
                      path_str, sizeof(path_str)/sizeof(TCHAR));
#else
  const char  *path_str = path.c_str();
#endif
  if(this->type == type_file)
    retval = DeleteFile(path_str);
  else if(this->type == type_directory)
    retval = RemoveDirectory(path_str);
  if(!retval)
    error(__FUNCTION__, "failed to remove "+path);
#endif
  set_filetype(type_non_existent);
}


void file::rmdir(bool ignore) {
#if ! defined (WIN32) 
  if (::rmdir(path.c_str()) && !ignore) {
    error(__FUNCTION__, "rmdir failed on "+path);
  }
#else
  BOOL  retval;
#ifdef UNICODE
  TCHAR path_str[1024];
  MultiByteToWideChar(CP_ACP,/// or CP_UTF8
                      0, path.c_str(), -1,
                      path_str, sizeof(path_str)/sizeof(TCHAR));
#else
  const char  *path_str = path.c_str();
#endif
  retval = RemoveDirectory(path_str);
  if(!retval)
    error(__FUNCTION__, "rmdir failed on "+path);
#endif
  set_filetype(file::type_non_existent);
}

#ifndef _WIN32_WCE
void file::chdir() {
  if (!is_directory()) return;
#if ! defined (WIN32) 
  if (::chdir(path.c_str())) {
    error(__FUNCTION__, "chdir failed on "+path);
  }
#else
  if (::_chdir(path.c_str())) {
    error(__FUNCTION__, "chdir failed on "+path);
  }
#endif
}
#endif

void file::rename(std::string const& newpath) {
#if ! defined (WIN32) 
  if (::rename(path.c_str(), newpath.c_str())) {
    ostringstream oss;
    oss << path << " to " << newpath;
    error(__FUNCTION__, "failed to rename: "+oss.str());
  }
  set_path(newpath);
#else
#ifdef UNICODE
  TCHAR path_str[1024];
  MultiByteToWideChar(CP_ACP,/// or CP_UTF8
                      0, path.c_str(), -1,
                      path_str, sizeof(path_str)/sizeof(TCHAR));
  TCHAR newpath_str[1024];
  MultiByteToWideChar(CP_ACP,/// or CP_UTF8
                      0, newpath.c_str(), -1,
                      newpath_str, sizeof(newpath_str)/sizeof(TCHAR));
#else
  const char  *path_str = path.c_str();
  const char  *newpath_str = newpath.c_str();
#endif
  if(!MoveFile(path_str, newpath_str))
  {
    ostringstream oss;
    oss << path << " to " << newpath;
    error(__FUNCTION__, "failed to rename: "+oss.str());
  }
#endif
}


} /* namespace zorba */

