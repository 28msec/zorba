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

#if !defined (WIN32) && !defined (APPLE) && !defined (__FreeBSD__) && !defined(_XOPEN_SOURCE)
#define _XOPEN_SOURCE 600  // getcwd
#endif

#ifndef _WIN32_WCE
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#else
#include <types.h>
#endif
#include <stdio.h>

#if defined (WIN32)
#include <tchar.h>
#ifndef _WIN32_WCE
#include <io.h>
#include <direct.h>
#else
#include <sys/types.h>
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

#include "util/ascii_util.h"
#include "zorbaerrors/error_manager.h"


using namespace std;
namespace zorba {


String
filesystem_path::normalize_path
(String aIn, String aBase)
  throw (ZorbaException)
{
  static const std::string FILE_SCHEMA("file://");

  String lFileArg = aIn;
  std::stringstream lErrorMessage;

  // ****************************************************
  // if we have an absolute file URI
  // e.g.: file://localhost/C:/my%20file.txt
  if(lFileArg.startsWith(FILE_SCHEMA.c_str())) {
    // make sure the URI is a valid one
    // QQQ not sure how to replicate this without a static context
    //aSctxCtx->resolve("", lFileArg);

    // test if we have a valid URI
    lFileArg = lFileArg.substring(FILE_SCHEMA.length());
    int lIndex = lFileArg.indexOf("/");

    if (lIndex > 0) { // if the file URI has a host
                      // e.g.: file://localhost/C:/my%20file.txt
      String lAuthorityString = lFileArg.substring(0, lIndex);
      // only allow "localhost" as the authoriry
      // This makes this implementation the same with the Zorba URI type.
      // If this functionality is changed, please make the same changes
      // in the Zorba URI type.
      if (!lAuthorityString.compare("localhost") == 0 ) {
        lErrorMessage << "Invalid host: \"" << lAuthorityString
            << "\". Only \"localhost\" is allowed as host in a file URI.";
        // QQQ I think it's weird that I need to include
        // ExternalFunctionData to do this, but couldn't find an
        // alternative.
        throw ExternalFunctionData::createZorbaException
          (XPTY0004, lErrorMessage.str(), __FILE__, __LINE__);
      }
    } else if (lIndex < 0) { // if the file URI doesn't have a path: file://abc
      throw ExternalFunctionData::createZorbaException
        (XPTY0004, "The file URI contains no path.", __FILE__, __LINE__);
    }

#ifdef WIN32
    // remove the first '/' from path: /C:/my%20file.txt
    ++lIndex;
#endif

    // remove the host from the URI
    lFileArg = lFileArg.substring(lIndex);

#ifdef WIN32
    // test for a valid drive segment
    String lDriveString;
    int lNext = lFileArg.indexOf("/");
    if (lNext >= 0) {
      lDriveString = lFileArg.substring(0, lNext);
    } else {
      lDriveString = lFileArg.substring(0);
    }
    if(!isValidDriveSegment(lDriveString)) {
      lErrorMessage << "Invalid drive specification: \""
          << lDriveString << "\".";
      throw ExternalFunctionData::createZorbaException
        (XPTY0004, lErrorMessage.str(), __FILE__, __LINE__);
    }
#endif

    // decode the resulting URL encoded path
    // e.g.: C%3A/my%20file.txt, C:/my%20file.txt, /usr/my%20file.xml

    lFileArg = lFileArg.decodeFromUri();
  }
  
  // ****************************************************
  // if we have a relative file URI
  // e.g.: "/blub 1/file", "myfile"
  else {

    bool lAbsolutePath = false;

    // check if we have an absolute path: /users, C:\test
#ifdef WIN32
    // the underlying Zorba implementation accepts both separators for WIN32
    // so detect the first occurence of any of them
    int lIndex = lFileArg.indexOf("\\");
    int lIndexS = lFileArg.indexOf("/");
    if (lIndex < 0) {
      lIndex = lIndexS;
    } else if (lIndexS >=0 ) {
      lIndex = std::min(lIndex, lIndexS);
    }

    // test for a valid drive segment
    String lDriveString;
    if (lIndex >= 0) {
      lDriveString = lFileArg.substring(0, lIndex);
    } else {
      lDriveString = lFileArg.substring(0);
    }
    lAbsolutePath = isValidDriveSegment(lDriveString);
#else
    // only check if the path starts with "/"
    lAbsolutePath = (lFileArg.indexOf("/") == 0);
#endif
    // if a relative path, we have to resolve it against the base URI
    if (!lAbsolutePath && aBase != "") {
      // resolve the relative path against the current working directory
      //lFileArg = aSctxCtx->resolve(aSctxCtx->getBaseURI(), lFileArg);
      lFileArg = aBase + File::getPathSeparator() + lFileArg;
    }

    // no other encoding or decoding if already an absolute path
    // simply return it
  }

  // Replace all occurences of the path-separator with the system specific one
  {
#ifdef WIN32
    String separator = "\\";
    String non_system_separator = "/";
    String pattern = "/+";
#else
    String separator = "/";
    String non_system_separator = "\\";
    String pattern = "\\\\+";
#endif
    String flags = "";
    int32_t startPos = 0;
    bool has_matched = false;
    String lResult;
    lResult = lFileArg.tokenize(pattern, flags, &startPos, &has_matched);
    if (!has_matched)
      return lFileArg;
    while (has_matched) {
      String token = lFileArg.tokenize(pattern, flags, &startPos, &has_matched);
      if (token != "")
        lResult += separator + token;
    }
    if (lResult == "") // if lResult is empty, then there was a path separator
      lResult = separator;
    lFileArg = lResult;
  }

  return lFileArg;
}

const char *
filesystem_path::get_path_separator () {
#ifdef WIN32
  return "\\";
#else
  return "/";
#endif
}

filesystem_path::filesystem_path () {
#ifdef WIN32
  char buf [MAX_PATH];
  WCHAR wbuf[MAX_PATH];
  
  GetCurrentDirectoryW (sizeof (wbuf)/sizeof(WCHAR), wbuf);
  WideCharToMultiByte(CP_UTF8, 0, wbuf, -1, buf, sizeof(buf), NULL, NULL);

  path = buf;
 // GetCurrentDirectory sometimes misses drive letter
  resolve_relative ();
#else
  char buf[1024];
  if (getcwd (buf, sizeof (buf)) == NULL) {
    file::error (__FUNCTION__, "current directory path too long");
  }
  else path = buf;
#endif
}

filesystem_path::filesystem_path (const string &path_, int flags)
  : path (path_)
{
  if ((flags & CONVERT_SLASHES) != 0)
    ascii::replace_all (path, "/", get_path_separator ());
  canonicalize ();
  if ((flags & RESOLVE) != 0)
    resolve_relative ();
}

bool
filesystem_path::is_complete () const
{
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

void
filesystem_path::resolve_relative ()
{
  if (! is_complete ()) {
#ifdef WIN32
    // call GetFullPathName as per
    // http://msdn.microsoft.com/en-us/library/aa364963(VS.85).aspx

#ifndef WINCE//for win ce don't bother with relative paths
  char fullpath[1024];
  fullpath[0] = 0;
  wchar_t *wfullpath;
	wfullpath = new wchar_t[1024];
	wchar_t *wpath;
	int wpath_len = path.length() + 10;
	wpath = new wchar_t[wpath_len];
  wpath[0] = 0;
	if(MultiByteToWideChar(CP_UTF8, 0, path.c_str(), -1, wpath, wpath_len) == 0)
	{//error case, maybe there is an invalid utf-8 char, try windows ACP
    MultiByteToWideChar(CP_ACP, 0, path.c_str(), -1, wpath, wpath_len);
  }
  GetFullPathNameW(wpath, 1024, wfullpath, NULL);
	delete[] wpath;
	WideCharToMultiByte(CP_UTF8, 0, wfullpath, -1, fullpath, sizeof(fullpath), NULL, NULL);
	delete[] wfullpath;
  *this = fullpath;
#endif
#else
    *this = filesystem_path (filesystem_path (), *this);
#endif
  }
}

bool
filesystem_path::is_root () const
{
  const string &sep = get_path_separator ();
#ifdef WIN32
  return path.size () == 3
    && isalpha (path [0]) && path [1] == ':'
    && path.compare (2, sep.size (), sep) == 0;
#else
  return path == sep;
#endif
}

void filesystem_path::canonicalize ()
{
  const string &sep = get_path_separator ();
  string::size_type pos, start;
  string pfx;
  bool last_seg;
  bool initial_dotdots = false, next_initial_dotdots;

#ifdef WIN32
  size_t rtsize = 2 + sep.size ();  // length of 'C:\'
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
#ifdef WIN32
      if(0 == prev)
        path = path.substr(0, rtsize);
      else
        path.erase (prev, pos - prev + sep.size ());
#else
      path.erase (prev, pos - prev + sep.size ());
#endif
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

filesystem_path
filesystem_path::branch_path () const
{
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

std::string
filesystem_path::getPathString() const
{
  return path;
}

void file::do_stat () {
#ifndef WIN32
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

  WCHAR wpath_str[1024];
  wpath_str[0] = 0;
  if(MultiByteToWideChar(CP_UTF8,
                      0, c_str(), -1,
                      wpath_str, sizeof(wpath_str)/sizeof(WCHAR)) == 0)
  {//probably there is some invalid utf8 char, try the Windows ACP
    MultiByteToWideChar(CP_ACP,
                      0, c_str(), -1,
                      wpath_str, sizeof(wpath_str)/sizeof(WCHAR));
  }

  DWORD lFileAttributes;
  lFileAttributes = GetFileAttributesW(wpath_str);
  if(lFileAttributes == INVALID_FILE_ATTRIBUTES) {
    type = type_invalid;
  } else {
    HANDLE hFile = CreateFileW(wpath_str, GENERIC_READ, FILE_SHARE_READ |
        FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE) {
      size = -1;
    } else {
      LARGE_INTEGER lLi;
      if (GetFileSizeEx(hFile, &lLi)) {
        size = lLi.QuadPart;
      }
    }
    type  = (lFileAttributes & FILE_ATTRIBUTE_DIRECTORY) ? type_directory :
        ((lFileAttributes & FILE_ATTRIBUTE_REPARSE_POINT) ? type_link :
        type_file);
    CloseHandle(hFile);
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

#ifndef WIN32
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

  WCHAR wpath_str[1024];
  wpath_str[0] = 0;
  if(MultiByteToWideChar(CP_UTF8,
                      0, c_str(), -1,
                      wpath_str, sizeof(wpath_str)/sizeof(WCHAR)) == 0)
  {//probably there is some invalid utf8 char, try the Windows ACP
    MultiByteToWideChar(CP_ACP,
                      0, c_str(), -1,
                      wpath_str, sizeof(wpath_str)/sizeof(WCHAR));
  }

  DWORD lFileAttributes;
  lFileAttributes = GetFileAttributesW(wpath_str);
  if(lFileAttributes == INVALID_FILE_ATTRIBUTES) {
    error(__FUNCTION__,"file/dir not exist " + get_path ());
    return type_non_existent;
  } else {
    HANDLE hFile = CreateFileW(wpath_str, GENERIC_READ, FILE_SHARE_READ |
        FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE) {
      size = -1;
    } else {
      LARGE_INTEGER lLi;
      if (GetFileSizeEx(hFile, &lLi)) {
        size = lLi.QuadPart;
      }
    }
    type  = (lFileAttributes & FILE_ATTRIBUTE_DIRECTORY) ? type_directory :
        ((lFileAttributes & FILE_ATTRIBUTE_REPARSE_POINT) ? type_link :
        type_file);
    CloseHandle(hFile);
    return type;
  }
#endif
}

time_t
file::lastModified()
{
  struct stat s;
  int i = stat(get_path().c_str(), &s);
  if (i == 0) {
    return s.st_mtime;
  }
  return -1;
}


void file::error(
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
  WCHAR wpath_str[1024];
  wpath_str[0] = 0;
  if(MultiByteToWideChar(CP_UTF8,
                      0, c_str(), -1,
                      wpath_str, sizeof(wpath_str)/sizeof(WCHAR)) == 0)
  {//probably there is some invalid utf8 char, try the Windows ACP
    MultiByteToWideChar(CP_ACP,
                      0, c_str(), -1,
                      wpath_str, sizeof(wpath_str)/sizeof(WCHAR));
  }
  HANDLE fd = CreateFileW(wpath_str,GENERIC_READ | GENERIC_WRITE,
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
  WCHAR wpath_str[1024];
  wpath_str[0] = 0;
  if(MultiByteToWideChar(CP_UTF8,
                      0, c_str(), -1,
                      wpath_str, sizeof(wpath_str)/sizeof(WCHAR)) == 0)
  {//probably there is some invalid utf8 char, try the Windows ACP
    MultiByteToWideChar(CP_ACP,
                      0, c_str(), -1,
                      wpath_str, sizeof(wpath_str)/sizeof(WCHAR));
  }
  if (!CreateDirectoryW(wpath_str, NULL))
  {
    ostringstream oss;
    oss<<"mkdir failed ["<<GetLastError() << "]"<<"] for: "<<wpath_str;
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
  if (::remove(c_str())) {
    if (!ignore) {
      error(__FUNCTION__, "failed to remove " + get_path ());
    }
    return;
  }
#else
  BOOL  retval = TRUE;
  WCHAR wpath_str[1024];
  wpath_str[0] = 0;
  if(MultiByteToWideChar(CP_UTF8,
                      0, c_str(), -1,
                      wpath_str, sizeof(wpath_str)/sizeof(WCHAR)) == 0)
  {//probably there is some invalid utf8 char, try the Windows ACP
    MultiByteToWideChar(CP_ACP,
                      0, c_str(), -1,
                      wpath_str, sizeof(wpath_str)/sizeof(WCHAR));
  }
  if(this->type == type_file)
    retval = DeleteFileW(wpath_str);
  else if(this->type == type_directory)
    retval = RemoveDirectoryW(wpath_str);
  if(!retval && !ignore)
    error(__FUNCTION__, "failed to remove " + get_path ());
#endif
  set_filetype(type_non_existent);
}


void file::rmdir(bool ignore) {
#if ! defined (WIN32)
  if (::rmdir(c_str())) {
    if (!ignore) {
      error(__FUNCTION__, "rmdir failed on " + get_path ());
    }
    return;
  }
#else
  BOOL  retval;
  WCHAR wpath_str[1024];
  wpath_str[0] = 0;
  if(MultiByteToWideChar(CP_UTF8,
                      0, c_str(), -1,
                      wpath_str, sizeof(wpath_str)/sizeof(WCHAR)) == 0)
  {//probably there is some invalid utf8 char, try the Windows ACP
    MultiByteToWideChar(CP_ACP,
                      0, c_str(), -1,
                      wpath_str, sizeof(wpath_str)/sizeof(WCHAR));
  }
  retval = RemoveDirectoryW(wpath_str);
  if(!retval && !ignore)
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
  WCHAR wpath_str[1024];
  wpath_str[0] = 0;
  if(MultiByteToWideChar(CP_UTF8,
                      0, c_str(), -1,
                      wpath_str, sizeof(wpath_str)/sizeof(WCHAR)) == 0)
  {//probably there is some invalid utf8 char, try the Windows ACP
    MultiByteToWideChar(CP_ACP,
                      0, c_str(), -1,
                      wpath_str, sizeof(wpath_str)/sizeof(WCHAR));
  }
  if (::_wchdir(wpath_str)) {
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
  WCHAR wpath_str[1024];
  wpath_str[0] = 0;
  if(MultiByteToWideChar(CP_UTF8,
                      0, c_str(), -1,
                      wpath_str, sizeof(wpath_str)/sizeof(WCHAR)) == 0)
  {//probably there is some invalid utf8 char, try the Windows ACP
    MultiByteToWideChar(CP_ACP,
                      0, c_str(), -1,
                      wpath_str, sizeof(wpath_str)/sizeof(WCHAR));
  }
  WCHAR wnewpath_str[1024];
  wnewpath_str[0] = 0;
  if(MultiByteToWideChar(CP_UTF8,
                      0, c_str(), -1,
                      wnewpath_str, sizeof(wnewpath_str)/sizeof(WCHAR)) == 0)
  {//probably there is some invalid utf8 char, try the Windows ACP
    MultiByteToWideChar(CP_ACP,
                      0, c_str(), -1,
                      wnewpath_str, sizeof(wnewpath_str)/sizeof(WCHAR));
  }
  if(!MoveFileW(wpath_str, wnewpath_str))
  {
    ostringstream oss;
    oss << wpath_str << " to " << newpath;
    error(__FUNCTION__, "failed to rename: " +oss.str());
  }
#endif
}

#ifdef WIN32
bool
filesystem_path::isValidDriveSegment(
    String& aString)
{
  aString = aString.uppercase();
  // the drive segment has one of the forms: "C:", "C%3A"
  if ((aString.length() != 2 && aString.length() != 4) ||
      (aString.length() == 2 && !aString.endsWith(":")) ||
      (aString.length() == 4 && !aString.endsWith("%3A"))) {
    return false;
  }

  char lDrive = aString.charAt(0);
  // the string is already upper case
  if (lDrive < 65 || lDrive > 90) {
    return false;
  }
  return true;
}
#endif

} /* namespace zorba */

