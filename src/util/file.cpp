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

#include <zorba/util/file.h>

#if ! defined (WIN32) && ! defined (APPLE) && ! defined (__FreeBSD__)
#define _XOPEN_SOURCE 600  // getcwd
#endif

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

#include <zorba/config.h>

#include <zorbautils/strutil.h>

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
  // GetCurrentDirectory sometimes misses drive letter
  resolve_relative ();
#endif
}

filesystem_path::filesystem_path (const string &path_, int flags)
  : path (path_)
{
  if ((flags & CONVERT_SLASHES) != 0)
    str_replace_all (path, "/", get_path_separator ());
  canonicalize ();
  if ((flags & RESOLVE) != 0)
    resolve_relative ();
}

bool filesystem_path::is_complete () const {
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
  if (! is_complete ()) {
#ifdef WIN32
    // call GetFullPathName as per
    // http://msdn.microsoft.com/en-us/library/aa364963(VS.85).aspx 
    
    char fullpath[1024];
    fullpath[0] = 0;
    GetFullPathName(path.c_str(), sizeof(fullpath), fullpath, NULL);
    *this = fullpath;
#else
    *this = filesystem_path (filesystem_path (), *this);
#endif
  }
}

bool filesystem_path::is_root () const {
  const string &sep = get_path_separator ();
#ifdef WIN32
  return path.size () == 3
    && isalpha (path [0]) && path [1] == ':'
    && path.compare (2, sep.size (), sep) == 0;
#else
  return path == sep;
#endif
}

void filesystem_path::canonicalize () {
  const string &sep = get_path_separator ();
  string::size_type pos, start;
  string pfx;
  bool last_seg;
  bool initial_dotdots = false, next_initial_dotdots;

#ifdef WIN32
  int rtsize = 2 + sep.size ();  // length of 'C:\'
  if (path.size () > rtsize && filesystem_path (path.substr (0, rtsize)).is_root ()) {
    pfx = path.substr (0, 2);
    path = path.substr (2);
  }
#endif
  for (pos = start = 0, last_seg = false;
       ! last_seg && pos != path.size ();
       pos += sep.size (), start = pos, initial_dotdots = next_initial_dotdots)
  {
    next_initial_dotdots = false;
    pos = path.find (sep, pos);
    if (pos == string::npos) {
      pos = path.size ();
      last_seg = true;
    }
    // cout << "path: " << path << " start: " << start << " pos: " << pos << endl;
    string seg = path.substr (start, pos - start);
    if ((seg.empty () && start != 0) || seg == ".") {
      path.erase (start, pos - start + sep.size ());
      pos = start - sep.size ();
    } else if (seg == "..") {
      string::size_type prev;
      if (start == 0 || initial_dotdots) {
        // cout << "initial or continued ..\n";
        next_initial_dotdots = true;
        continue;  // initial ..
      }
      if (start == sep.size ()) {
        // cout << "initial /..\n";
        prev = sep.size ();
      } else {
        prev = path.rfind (sep, start - sep.size () - 1);
        // cout << "prev @" << (int) (prev == string::npos ? -1 : prev) << endl;
        if (prev == string::npos)
          prev = 0;
        else
          prev += sep.size ();
      }
      path.erase (prev, pos - prev + sep.size ());
      pos = prev - sep.size ();
    }
  }
  if (! pfx.empty ())
    path = pfx + path;
  if (path.empty ())
      path = ".";
  else if (path.size () != sep.size () && path.compare (path.size () - sep.size (), sep.size (), sep) == 0)
    path.erase (path.size () - sep.size (), sep.size ());
}

filesystem_path filesystem_path::branch_path () const {
  if (is_root () && is_complete ())
    return *this;

  const string &sep = get_path_separator ();
  string::size_type pos = path.rfind (sep);
  if (pos == string::npos) {
    return filesystem_path (".");
  } else if (pos + sep.size () == path.size ()) {
    // Final separator -- eliminate.
    // Shouldn't happen, canonicalize() does this too
    filesystem_path other = path.substr (0, pos);
    return other.branch_path ();
  }
  else return filesystem_path (path.substr (0, pos + sep.size ()));
}

void file::do_stat () {
#if ! defined (WIN32) 
  struct stat st;
  if (::stat(c_str(), &st)) {
    if (errno!=ENOENT) file::error(__FUNCTION__,"stat failed on " +get_path ());
  } else {
    size  = st.st_size;
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
                      0, c_str(), -1,
                      path_str, sizeof(path_str)/sizeof(TCHAR));
#else
  const char  *path_str = c_str();
#endif

  hfind = FindFirstFile(path_str, &findData);
  if(hfind == INVALID_HANDLE_VALUE)
    error(__FUNCTION__,"file/dir not exist " + get_path ());
  else {
    size = findData.nFileSizeLow + (((int64_t)(findData.nFileSizeHigh))<<32);
    type  = (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)  ? type_directory :
            (findData.dwFileAttributes & FILE_ATTRIBUTE_ARCHIVE ) ? type_file :
            //(st.st_mode & S_IFLNK)  ? type_link : 
            type_invalid;
    FindClose(hfind);
  }
#endif
}

file::file(const filesystem_path &path_, int flags_)
:
  filesystem_path(path_, flags_),
  type(type_non_existent)
{
  do_stat ();
}


enum file::filetype file::get_filetype() {
  if (type!=type_non_existent) return type;

#if ! defined (WIN32) 
  // call native file system status
  struct stat st;
  if (::stat(c_str(), &st)) {
    if (errno==ENOENT) {
      errno = 0;
      return (type = type_non_existent);
    }
    error(__FUNCTION__,"stat failed on " +get_path ());
  } 
  size  = st.st_size;
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
                      0, c_str(), -1,
                      path_str, sizeof(path_str)/sizeof(TCHAR));
#else
  const char  *path_str = c_str();
#endif
  hfind = FindFirstFile(path_str, &findData);
  if(hfind == INVALID_HANDLE_VALUE)
  {
    error(__FUNCTION__,"file/dir not exist " + get_path ());
    return type_non_existent;
  }
  else
  {
    size = findData.nFileSizeLow + (((int64_t)(findData.nFileSizeHigh))<<32);
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
  int fd = ::creat(c_str(),0666);
  if (fd < 0) error(__FUNCTION__, "failed to create file " + get_path ());
  ::close(fd);
  set_filetype(type_file); 
#else
#ifdef UNICODE
  TCHAR path_str[1024];
  MultiByteToWideChar(CP_ACP,/// or CP_UTF8
                      0, c_str(), -1,
                      path_str, sizeof(path_str)/sizeof(TCHAR));
#else
  const char  *path_str = c_str();
#endif
  HANDLE fd = CreateFile(path_str,GENERIC_READ | GENERIC_WRITE, 
                      FILE_SHARE_READ | FILE_SHARE_WRITE, NULL,
                      CREATE_ALWAYS, 0, NULL);
  if (fd == INVALID_HANDLE_VALUE) 
    error(__FUNCTION__, "failed to create file " + get_path ());
  CloseHandle(fd);
  set_filetype(type_file); 
#endif
}


void file::mkdir() {
#if ! defined (WIN32) 
  if (::mkdir(c_str(),0777)) {
    ostringstream oss;
    oss<<"mkdir failed ["<<strerror(errno) << "]"<<"] for: " << get_path ();
    cout << oss.str() << endl;  //XXX DEBUG
    error(__FUNCTION__,oss.str());
  }
  set_filetype(file::type_directory);
#else
#ifdef UNICODE
  TCHAR path_str[1024];
  MultiByteToWideChar(CP_ACP,/// or CP_UTF8
                      0, c_str(), -1,
                      path_str, sizeof(path_str)/sizeof(TCHAR));
#else
  const char  *path_str = c_str();
#endif
  if (!CreateDirectory(path_str, NULL))
  {
    ostringstream oss;
    oss<<"mkdir failed ["<<GetLastError() << "]"<<"] for: "<<path_str;
    error(__FUNCTION__,oss.str());
  }
  set_filetype(file::type_directory);
#endif
}

void file::deep_mkdir () {
  vector<file> files;
  for (file f = *this; ! f.exists (); f = f.branch_path ())
    files.push_back (f);
  for (int i = files.size () - 1; i >= 0; i--) {
    // cout << "mkdir " << files [i] << endl;
    files [i].mkdir ();
  }
}

void file::remove(bool ignore) {
#if ! defined (WIN32) 
  if (::remove(c_str()) && !ignore) {
    error(__FUNCTION__, "failed to remove " + get_path ());
  }
#else
  BOOL  retval = TRUE;
#ifdef UNICODE
  TCHAR path_str[1024];
  MultiByteToWideChar(CP_ACP,/// or CP_UTF8
                      0, c_str(), -1,
                      path_str, sizeof(path_str)/sizeof(TCHAR));
#else
  const char  *path_str = c_str();
#endif
  if(this->type == type_file)
    retval = DeleteFile(path_str);
  else if(this->type == type_directory)
    retval = RemoveDirectory(path_str);
  if(!retval && !ignore)
    error(__FUNCTION__, "failed to remove " + get_path ());
#endif
  set_filetype(type_non_existent);
}


void file::rmdir(bool ignore) {
#if ! defined (WIN32) 
  if (::rmdir(c_str()) && !ignore) {
    error(__FUNCTION__, "rmdir failed on " + get_path ());
  }
#else
  BOOL  retval;
#ifdef UNICODE
  TCHAR path_str[1024];
  MultiByteToWideChar(CP_ACP,/// or CP_UTF8
                      0, c_str(), -1,
                      path_str, sizeof(path_str)/sizeof(TCHAR));
#else
  const char  *path_str = c_str();
#endif
  retval = RemoveDirectory(path_str);
  if(!retval)
    error(__FUNCTION__, "rmdir failed on " + get_path ());
#endif
  set_filetype(file::type_non_existent);
}

#ifndef _WIN32_WCE
void file::chdir() {
  if (!is_directory()) return;
#if ! defined (WIN32) 
  if (::chdir(c_str())) {
    error(__FUNCTION__, "chdir failed on " + get_path ());
  }
#else
  if (::_chdir(c_str())) {
    error(__FUNCTION__, "chdir failed on " + get_path ());
  }
#endif
}
#endif

void file::rename(std::string const& newpath) {
#if ! defined (WIN32) 
  if (::rename(c_str(), newpath.c_str())) {
    ostringstream oss;
    oss << get_path () << " to " << newpath;
    error(__FUNCTION__, "failed to rename: " +oss.str());
  }
  set_path(newpath);
#else
#ifdef UNICODE
  TCHAR path_str[1024];
  MultiByteToWideChar(CP_ACP,/// or CP_UTF8
                      0, c_str(), -1,
                      path_str, sizeof(path_str)/sizeof(TCHAR));
  TCHAR newpath_str[1024];
  MultiByteToWideChar(CP_ACP,/// or CP_UTF8
                      0, newpath.c_str(), -1,
                      newpath_str, sizeof(newpath_str)/sizeof(TCHAR));
#else
  const char  *path_str = c_str();
  const char  *newpath_str = newpath.c_str();
#endif
  if(!MoveFile(path_str, newpath_str))
  {
    ostringstream oss;
    oss << path_str << " to " << newpath;
    error(__FUNCTION__, "failed to rename: " +oss.str());
  }
#endif
}


} /* namespace zorba */

