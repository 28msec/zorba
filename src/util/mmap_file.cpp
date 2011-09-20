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

#ifndef WIN32
# include <fcntl.h>                     /* for open(2) */
# include <sys/mman.h>                  /* for mmap(2) */
# include <sys/stat.h>                  /* for stat(2) */
# include <unistd.h>                    /* for close(2) */
#endif /* WIN32 */

#include "cxx_util.h"
#include "error_util.h"
#include "diagnostics/xquery_diagnostics.h"

#include "mmap_file.h"

using namespace std;

namespace zorba {

void mmap_file::close() {
#ifndef WIN32
  if ( addr_ && ::munmap( static_cast<char*>( addr_ ), size_ ) == -1 )
    throw ZORBA_IO_EXCEPTION( "munmap()", path_ );
  if ( fd_ != -1 )
    ::close( fd_ );
#else /* WIN32 */
  if ( addr_ && !::UnmapViewOfFile( addr_ ) )
    throw ZORBA_IO_EXCEPTION( "UnmapViewOfFile()", path_ );
  if ( mapping_ )
    ::CloseHandle( mapping_ );
  if ( fd_ != INVALID_HANDLE_VALUE )
    ::CloseHandle( fd_ );
#endif /* WIN32 */
  init();
}

void mmap_file::init() {
#ifndef WIN32
  fd_ = -1;
#else
  fd_ = INVALID_HANDLE_VALUE;
#endif /* WIN32 */
  size_ = 0;
  addr_ = nullptr;
}

void mmap_file::open( char const *path, ios::openmode mode ) {
  close();
  path_ = path;

#ifndef WIN32

  struct stat stat_buf;
  if ( ::stat( path, &stat_buf ) == -1 )
    throw ZORBA_IO_EXCEPTION( "stat()", path_ );
  size_ = stat_buf.st_size;

  int flags = 0;
  int prot  = PROT_NONE;

  if ( mode & ios::in ) {
    flags |= O_RDONLY;
    prot  |= PROT_READ;
  }
  if ( mode & ios::out ) {
    flags |= O_WRONLY;
    prot  |= PROT_WRITE;
  }

  if ( (fd_ = ::open( path, flags )) == -1 )
    throw ZORBA_IO_EXCEPTION( "open()", path_ );

  addr_ = ::mmap( nullptr, size_, prot, MAP_SHARED, fd_, 0 );
  if ( addr_ == MAP_FAILED ) {
    addr_ = nullptr;
    throw ZORBA_IO_EXCEPTION( "mmap()", path_ );
  }

#else /* WIN32 */

#ifdef UNICODE
  TCHAR wPath[ 1024 ];
  MultiByteToWideChar(
    CP_ACP /* or CP_UTF8 */, 0, path, -1, wPath,
    sizeof( wPath ) / sizeof( wPath[0] )
  );
#else
  char const *const wPath = path;
#endif /* UNICODE */

  DWORD createAccess = 0;
  DWORD protect      = 0;
  DWORD shareMode    = 0;
  DWORD mapAccess    = 0;

  if ( mode & ios::in ) {
    createAccess |= GENERIC_READ;
    shareMode    |= FILE_SHARE_READ;
    mapAccess    |= FILE_MAP_READ;
    protect       = PAGE_READONLY;
  }
  if ( mode & ios::out ) {
    createAccess |= GENERIC_WRITE;
    shareMode    |= FILE_SHARE_WRITE;
    mapAccess    |= FILE_MAP_WRITE;
    protect       = PAGE_READWRITE;
  }

  fd_ = ::CreateFile(
    wPath, createAccess, shareMode, NULL, OPEN_EXISTING, 0, NULL
  );
  if ( fd_ == INVALID_HANDLE_VALUE )
    throw ZORBA_IO_EXCEPTION( "CreateFile()", path_ );

  if ( (size_ = ::GetFileSize( fd_, NULL )) == -1 )
    throw ZORBA_IO_EXCEPTION( "GetFileSize()", path_ );

  if ( !(mapping_ = ::CreateFileMapping( fd_, NULL, protect, 0, 0, NULL )) )
    throw ZORBA_IO_EXCEPTION( "CreateFileMapping()", path_ );

  if ( !(addr_ = ::MapViewOfFile( mapping_, mapAccess, 0, 0, 0 )) )
    throw ZORBA_IO_EXCEPTION( "MapViewOfFile()", path_ );
#endif /* WIN32 */
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
