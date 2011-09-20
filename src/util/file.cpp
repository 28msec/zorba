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

#ifdef WIN32
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

#include <zorba/config.h>

#include "ascii_util.h"
#include "fs_util.h"
#include "regex.h"
#include "uri_util.h"
#include "utf8_util.h"
#include "diagnostics/xquery_diagnostics.h"
#include "diagnostics/xquery_exception.h"


using namespace std;
namespace zorba {

std::string filesystem_path::normalize_path( std::string const &aIn,
                                             std::string const &aBase ) {
  return fs::get_normalized_path( aIn, aBase ).str();
}

const char* filesystem_path::get_directory_separator() {
#ifdef WIN32
  return "\\";
#else
  return "/";
#endif
}

const char* filesystem_path::get_path_separator() {
#ifdef WIN32
  return ";";
#else
  return ":";
#endif
}

filesystem_path::filesystem_path() {
  path = fs::curdir().c_str();
}

filesystem_path::filesystem_path (const string &path_, int flags)
  : path (path_)
{
  if ((flags & CONVERT_SLASHES) != 0)
    ascii::replace_all (path, "/", get_directory_separator ());
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
  const std::string &sep = get_directory_separator ();
  if (path.compare (0, sep.size (), sep) == 0)
    return true;
  return false;
}

void
filesystem_path::resolve_relative ()
{
  fs::make_absolute( path );
}

bool
filesystem_path::is_root () const
{
  const string &sep = get_directory_separator ();
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
  const string &sep = get_directory_separator ();
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

  const string &sep = get_directory_separator ();
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

std::string filesystem_path::getPathString() const {
  return path;
}

void file::do_stat() {
#ifdef ZORBA_WITH_FILE_ACCESS
  fs::size_type fs_size;
  switch ( fs::get_type( c_str(), &fs_size ) ) {
    case fs::non_existent: type = type_non_existent; break;
    case fs::directory   : type = type_directory;    break;
    case fs::file        : type = type_file;         break;
    case fs::link        : type = type_link;         break;
    case fs::volume      : type = type_volume;       break;
    case fs::other       : type = type_other;        break;
  }
  size = fs_size;
#else
  type = type_non_existent;
  size = 0;
#endif
}

file::file( const filesystem_path &path_, int flags_ ) :
  filesystem_path( path_, flags_ )
{
  do_stat();
}

file::filetype file::get_filetype() {
  if ( type == type_non_existent )
    do_stat();
  return type;
}

time_t file::lastModified() {
#ifdef ZORBA_WITH_FILE_ACCESS
  struct stat s;
  if ( ::stat( get_path().c_str(), &s ) == 0 )
    return s.st_mtime;
#endif
  return -1;
}

void file::create() {
#ifdef ZORBA_WITH_FILE_ACCESS
  try {
    fs::create( c_str() );
    set_filetype( type_file );
  }
  catch ( fs::exception const &e ) {
    throw ZORBA_IO_EXCEPTION( e.function(), e.path() );
  }
#endif
}

void file::mkdir() {
#ifdef ZORBA_WITH_FILE_ACCESS
  try {
    fs::mkdir( c_str() );
    set_filetype( type_directory );
  }
  catch ( fs::exception const &e ) {
    throw ZORBA_IO_EXCEPTION( e.function(), e.path() );
  }
#endif
}

void file::deep_mkdir() {
#ifdef ZORBA_WITH_FILE_ACCESS
  vector<file> files;
  for ( file f = *this; !f.exists(); f = f.branch_path() )
    files.push_back( f );
  for ( int i = files.size() - 1; i >= 0; --i )
    files[i].mkdir();
  set_filetype( type_directory );
#endif
}

void file::remove( bool ignore ) {
#ifdef ZORBA_WITH_FILE_ACCESS
  if ( !fs::remove( c_str() ) ) {
    if ( !ignore )
      throw ZORBA_IO_EXCEPTION( "remove()", get_path() );
    return;
  }
  set_filetype( type_non_existent );
#endif
}

void file::rmdir( bool ignore ) {
  remove( ignore );
}

#ifndef _WIN32_WCE
void file::chdir() {
  if ( is_directory() ) {
    try {
      fs::chdir( c_str() );
    }
    catch ( fs::exception const &e ) {
      throw ZORBA_IO_EXCEPTION( e.function(), e.path() );
    }
  }
}
#endif

void file::rename( std::string const& newpath ) {
#ifdef ZORBA_WITH_FILE_ACCESS
  try {
    fs::rename( c_str(), newpath );
  }
  catch ( fs::exception const &e ) {
    throw ZORBA_IO_EXCEPTION( e.function(), e.path() );
  }
  set_path( newpath );
#endif
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
