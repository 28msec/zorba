/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: mmfile.cpp,v 1.2 2006/10/22 01:32:22 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 *	Author: Paul Pedersen
 *
 */

#include "util/fx/mmfile.h"
#include "zorba/common/common.h"

#ifndef WIN32
	#include <sys/mman.h>
#elif _WIN32_WCE
	#include <winbase.h>
#else
	#include <io.h>
#endif

#ifndef _WIN32_WCE
	#include <sys/types.h>
	#include <sys/stat.h>
	#include <errno.h>
	#include <fcntl.h>
#else
	#include <types.h>
#endif
#include <string>
#include <sstream>
#include <iostream>

#include "errors/error_factory.h"

using namespace std;
namespace xqp {


#ifndef _WIN32_WCE
#define IOEXCEPTION(s) \
	{ \
		ostringstream oerr; \
		oerr << s << " [" << strerror(errno) << ']'; \
		ZORBA_ERROR_ALERT(ZorbaError::XQP0013_SYSTEM_MMFILE_IOEXCEPTION,\
													NULL,DONT_CONTINUE_EXECUTION,\
													oerr.str(), __FUNCTION__);\
	}
#else
#define IOEXCEPTION(s) \
	{ \
		ostringstream oerr; \
		oerr << s << " [" << GetLastError() << ']'; \
		ZORBA_ERROR_ALERT(ZorbaError::XQP0013_SYSTEM_MMFILE_IOEXCEPTION,\
													NULL,DONT_CONTINUE_EXECUTION,\
													oerr.str(), __FUNCTION__);\
	}
#endif

mmfile::mmfile(
	const string& _path,
	uint32_t initial_size)
:
	path(_path)
{
	data = NULL;
#ifndef WIN32
	fd = open(path.c_str(), O_RDWR|O_CREAT, S_IRUSR|S_IWUSR);
  if (fd < 0) {
		IOEXCEPTION("open failed on '"+path+"'");
	}

  // allocate entire file
  eofoff = lseek(fd, 0, SEEK_END);
	if (eofoff==-1) {
		IOEXCEPTION("lseek(EOF) failed on: '"+path+"'");
	}

  if (eofoff==0) {	// new, empty file

#ifdef DEBUG
cout << "mmfile::ctor: new, empty file: \"" << path << "\"\n";
#endif

		uint32_t m = (initial_size >> 12) << 12;	// multiple of 4096
		if (m<initial_size) m += (1<<12);			// round up

	  if (lseek(fd, m-1, SEEK_END)==-1) {
			IOEXCEPTION("lseek m-1 past EOF failed on: '"+path+"'");
	  }
	
	  // create a 'hole' of size m
	  char buf[1] = { '\0' };
	  if (write(fd, buf, 1) == -1) { 
			IOEXCEPTION("write to m-1 past EOF failed on: '"+path+"'");
	  }
	
	  if ((data = (char*)mmap(0, m, PROT_READ|PROT_WRITE,
	                           MAP_SHARED, fd, 0))==MAP_FAILED) {
			IOEXCEPTION("mmap failed on: '"+path+"'");
	  }
	
	  // initialize state
		eofoff = m;
	 	memset(data, 0, eofoff);
  }
	else {	// map an existing file

#ifdef DEBUG
cout << "mmfile::ctor: map existing file: \"" << path << "\"\n";
#endif

    if ((data = (char*)mmap(0, eofoff, PROT_READ|PROT_WRITE,
                             MAP_SHARED, fd, 0))==MAP_FAILED) {
      IOEXCEPTION("mmap failed on: '"+path+"'");
    }
  }
#else ///for Win32
	file_mapping = NULL;

#ifdef UNICODE
	TCHAR	path_str[1024];
	MultiByteToWideChar(CP_ACP,/// or CP_UTF8
											0, path.c_str(), -1,
											path_str, sizeof(path_str)/sizeof(TCHAR));
#else
	const char	*path_str = path.c_str();
#endif
	fd = CreateFile(path_str, GENERIC_READ | GENERIC_WRITE, 
									FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_ALWAYS,
									0, NULL);
	if(fd == INVALID_HANDLE_VALUE)
	{
		IOEXCEPTION("open failed on '"+path+"'");
	}

	eofoff = GetFileSize(fd, NULL);

	if (eofoff==-1) {
		CloseHandle(fd);
		fd = INVALID_HANDLE_VALUE;
		IOEXCEPTION("lseek(EOF) failed on: '"+path+"'");
	}

  if (eofoff==0) {	// new, empty file, extend it to initial size
#ifdef DEBUG
cout << "mmfile::ctor: new, empty file: \"" << path << "\"\n";
#endif

		uint32_t m = (initial_size >> 12) << 12;	// multiple of 4096
		if ((m < 0xfffff000) && (m<initial_size))
			m += (1<<12);			// round up

	  if (SetFilePointer(fd, m-1, NULL, FILE_END)==INVALID_SET_FILE_POINTER) 
		{
			CloseHandle(fd);
			fd = INVALID_HANDLE_VALUE;
			IOEXCEPTION("lseek m-1 past EOF failed on: '"+path+"'");
	  }

		if(!SetEndOfFile(fd))
		{
			CloseHandle(fd);
			fd = INVALID_HANDLE_VALUE;
			IOEXCEPTION("write to m-1 past EOF failed on: '"+path+"'");
	  }
	
	//  if ((data = (char*)mmap(0, m, PROT_READ|PROT_WRITE,
	//                           MAP_SHARED, fd, 0))==MAP_FAILED) {
	//		IOEXCEPTION("mmap failed on: '"+path+"'");
	//  }
  }
	else {	// map an existing file

#ifdef DEBUG
cout << "mmfile::ctor: map existing file: \"" << path << "\"\n";
#endif

  }
	file_mapping = CreateFileMapping(fd, NULL, PAGE_READWRITE, 0, 0, NULL);
	if(file_mapping == NULL)
	{
		CloseHandle(fd);
		fd = INVALID_HANDLE_VALUE;
		IOEXCEPTION("mmap failed on: '"+path+"'");
	}
	data = (char*)MapViewOfFile(file_mapping, FILE_MAP_WRITE, 0, 0, 0);
	if(data == NULL)
	{
		CloseHandle(file_mapping);
		file_mapping = NULL;
		CloseHandle(fd);
		fd = INVALID_HANDLE_VALUE;
		IOEXCEPTION("mmap failed on: '"+path+"'");
	}
	
	if(eofoff == 0)
	{
	  // file created new, initialize state
		eofoff = GetFileSize(fd, NULL);
	 	memset(data, 0, eofoff);
	}
#endif
}


mmfile::~mmfile()
{
	unmap();
#ifndef WIN32
	close(fd);
#else
	if(fd != INVALID_HANDLE_VALUE)
		CloseHandle(fd);
#endif
}


void mmfile::destroy()
{
	try {
    unmap();
#ifndef WIN32
		close(fd);
    remove(path.c_str());
#else
		if(fd != INVALID_HANDLE_VALUE)
			CloseHandle(fd);
#ifdef UNICODE
	TCHAR	path_str[1024];
	MultiByteToWideChar(CP_ACP,/// or CP_UTF8
											0, path.c_str(), -1,
											path_str, sizeof(path_str)/sizeof(TCHAR));
#else
	const char	*path_str = path.c_str();
#endif
		DeleteFile(path_str);
#endif
	} catch (xqp_exception& e) {
		IOEXCEPTION("remove on: '"+path+"' application exception: "+e.getError()->theDescription);
  } catch (exception& e) {
		IOEXCEPTION("remove on: '"+path+"' system exception: "+e.what());
  } catch (...) {
		IOEXCEPTION("remove on: '"+path+"' general exception");
  }
}


void mmfile::fill(char initval)
{
  memset(data, initval, eofoff);
}


void mmfile::expand(bool init)
{
	// release current map
  unmap();

#ifndef WIN32
  // double past the end
  if (lseek(fd, eofoff-1, SEEK_END)==-1) {
		IOEXCEPTION("lseek to 2*EOF failed on: '"+path+"'");
  }

  // write one byte: creates hole equal
  // in size to the original file
  char buf[1] = { '\0' };
  if (write(fd, buf, 1) == -1) {
		IOEXCEPTION("write to 2*EOF failed on: '"+path+"'");
  }

  // remap the file
  eofoff <<= 1;
  if ((data = (char*)mmap(0, eofoff, PROT_READ|PROT_WRITE,
                           MAP_SHARED, fd, 0))==MAP_FAILED) {
		IOEXCEPTION("mmap failed on: '"+path+"'");
  }
#else

	  if (SetFilePointer(fd, eofoff-1, NULL, FILE_END)==INVALID_SET_FILE_POINTER) 
		{
			CloseHandle(fd);
			fd = INVALID_HANDLE_VALUE;
			IOEXCEPTION("lseek m-1 past EOF failed on: '"+path+"'");
	  }

		if(!SetEndOfFile(fd))
		{
			CloseHandle(fd);
			fd = INVALID_HANDLE_VALUE;
			IOEXCEPTION("write to m-1 past EOF failed on: '"+path+"'");
	  }


		file_mapping = CreateFileMapping(fd, NULL, PAGE_READWRITE, 0, 0, NULL);
		if(file_mapping == NULL)
		{
			CloseHandle(fd);
			fd = INVALID_HANDLE_VALUE;
			IOEXCEPTION("mmap failed on: '"+path+"'");
		}
		data = (char*)MapViewOfFile(file_mapping, FILE_MAP_WRITE, 0, 0, 0);
		if(data == NULL)
		{
			CloseHandle(file_mapping);
			file_mapping = NULL;
			CloseHandle(fd);
			fd = INVALID_HANDLE_VALUE;
			IOEXCEPTION("mmap failed on: '"+path+"'");
		}
#endif

}


void mmfile::unmap()
{
#ifndef WIN32
  //if (msync(data, eofoff, 0)==-1) {
	//	IOEXCEPTION("msync failed on: '"+path+"'");
  //}
  if (munmap(data, eofoff)==-1) {
		IOEXCEPTION("munmap failed on: '"+path+"'");
  }
#else
	if(data)
	{
		if(!UnmapViewOfFile(data))
		{
			IOEXCEPTION("munmap failed on: '"+path+"'");
		}
	}
	data = NULL;
	if(file_mapping)
		CloseHandle(file_mapping);
	file_mapping = NULL;
#endif
}

void mmfile::rename_backing_file(const string& new_path)
{
#ifndef WIN32
	int res = rename(path.c_str(), new_path.c_str());
  if (res==-1) {
    IOEXCEPTION("rename failed on '"+path+"'");
  }
#else
#ifdef UNICODE
	TCHAR	path_str[1024];
	MultiByteToWideChar(CP_ACP,/// or CP_UTF8
											0, path.c_str(), -1,
											path_str, sizeof(path_str)/sizeof(TCHAR));
	TCHAR	newpath_str[1024];
	MultiByteToWideChar(CP_ACP,/// or CP_UTF8
											0, new_path.c_str(), -1,
											newpath_str, sizeof(newpath_str)/sizeof(TCHAR));
#else
	const char	*path_str = path.c_str();
	const char	*newpath_str = new_path.c_str();
#endif
	if(!MoveFile(path_str, newpath_str))
	{
    IOEXCEPTION("rename failed on '"+path+"'");
	}
#endif
	path = new_path;
}

}  /* namespace xqp */
