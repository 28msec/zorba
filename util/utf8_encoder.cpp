/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: utf8_encoder.cpp,v 1.1 2006/10/09 07:08:05 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#include "utf8_encoder.h"

#ifdef WIN32
	#include <windows.h>
#ifndef _WIN32_WCE
	#include <io.h>
#else
	#include <winbase.h>
#endif
	#include "win32/compatib_defs.h"
#endif

#ifndef _WIN32_WCE
	#include <sys/types.h>
	#include <sys/stat.h>
	#include <fcntl.h>
	#include <errno.h>
#else
	#include <types.h>
#endif

#include <iostream>

/*______________________________________________________________________________
| 
|  Standard Unicode to UTF-8 encoder: 
|                                    
|  U-00000000  U-0000007F: 0xxxxxxx 
|  U-00000080  U-000007FF: 110xxxxx 10xxxxxx 
|  U-00000800  U-0000FFFF: 1110xxxx 10xxxxxx 10xxxxxx
|  U-00010000  U-001FFFFF: 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx 
|  U-00200000  U-03FFFFFF: 111110xx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx  
|  U-04000000  U-7FFFFFFF: 1111110x 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx
|  Fill from right-to-left, least-significant-to-most-significant bits.          
|________________________________________________________________________________*/

using namespace std;
namespace xqp {

void utf8_encoder::encode(
	const char* path)
{
  char* ibuf;
  char* obuf;

#ifndef WIN32
  int  fd;
  struct stat statbuf;

	fd = open(path, O_RDONLY);
	if (fd < 0) {
		cerr<<"I/O error: open failed"<<endl;
		return;
	}
	if (fstat(fd, &statbuf)<0) {
		cerr<<"I/O error: fstat failed"<<endl;
		return;
	}
	off_t sz = statbuf.st_size;
#else
	HANDLE	fd;

#ifdef UNICODE
	TCHAR	path_str[1024];
	MultiByteToWideChar(CP_ACP,/// or CP_UTF8
											0, path, -1,
											path_str, sizeof(path_str)/sizeof(TCHAR));
#else
	const char	*path_str = path;
#endif
	fd = CreateFile(path_str, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE,
								NULL, OPEN_EXISTING, 0, NULL);
	if(fd == INVALID_HANDLE_VALUE)
	{
		cerr<<"I/O error: open failed"<<endl;
		return;
	}
	off_t sz = GetFileSize(fd, NULL);
#endif

	ibuf = new char[sz];
	obuf = new char[3*sz];
#ifndef WIN32
	ssize_t n = read(fd,&ibuf[0],sz);  
#else
	//int n = _read(fd,&ibuf[0],sz);  
	int n = -1;
	DWORD	nr_read;
	if(ReadFile(fd, &ibuf[0],sz, &nr_read, NULL))
		n = (int)nr_read;
#endif
	if (n<0) {
#ifndef _WIN32_WCE
		cerr<<"I/O error: read failed with error "<<errno<<endl;
#else
		cerr<<"I/O error: read failed " << endl;
#endif
		delete[] ibuf;
		delete[] obuf;
		return;
	} else {
		cerr<<"Reading "<<n<<" bytes\n";
	}

  uint32_t q = 0;
	for (int p=0; p<n; ++p) {
     char c = ibuf[p];
     int d = c&0xffff;
     if (d<=0x80) {
       obuf[q++] = c;
     } else if (d<=0x800) {
       obuf[q++] = (char)(((c&0x07c0) >> 6) | 0xc0);
       obuf[q++] = (char)((c&0x003f) | 0x80);
     } else {
       obuf[q++] = (char)(((c&0xf000) >> 12) | 0xe0);
       obuf[q++] = (char)(((c&0xfc0) >> 6) | 0x80);
       obuf[q++] = (char)((c&0x3f) | 0x80);
     }
	}
	string ostr = string(obuf, q);
	cout << ostr;

	delete[] ibuf;
	delete[] obuf;
#ifndef WIN32
	if (close(fd) < 0) {
		cerr<<"I/O error: close failed with error "<<errno<<endl;
	}
#else
//	if (_close(fd) < 0) {
//		cerr<<"I/O error: close failed with error "<<errno<<endl;
//	}
	CloseHandle(fd);
#endif
}


string utf8_encoder::encode(
	const string& s)
{
	const char* ibuf = s.c_str();
	uint32_t n = s.length();
	char *obuf;
	obuf = (char*)malloc(3*n);

  uint32_t q = 0;
	for (uint32_t p=0; p<n; ++p) {
     char c = ibuf[p];
     int d = c&0xffff;
     if (d<=0x80) {
       obuf[q++] = c;
     } else if (d<=0x800) {
       obuf[q++] = (char)(((c&0x07c0) >> 6) | 0xc0);
       obuf[q++] = (char)((c&0x003f) | 0x80);
     } else {
       obuf[q++] = (char)(((c&0xf000) >> 12) | 0xe0);
       obuf[q++] = (char)(((c&0xfc0) >> 6) | 0x80);
       obuf[q++] = (char)((c&0x3f) | 0x80);
     }
	}
	string retstr = string(obuf, q);
	free(obuf);
	return retstr;
}



string utf8_encoder::urlencode(
	const string& s)
{
	const char* ibuf = s.c_str();
	uint32_t n = s.length();
	char *obuf;
	obuf = (char*)malloc(3*n);

  uint32_t q = 0;
	for (uint32_t p=0; p<n; ++p) {
     char c = ibuf[p];
     int d = c&0xffff;
     if (d<=0x80) {
       obuf[q++] = c;
     } else if (d<=0x800) {
       obuf[q++] = (char)(((c&0x07c0) >> 6) | 0xc0);
       obuf[q++] = (char)((c&0x003f) | 0x80);
     } else {
       obuf[q++] = (char)(((c&0xf000) >> 12) | 0xe0);
       obuf[q++] = (char)(((c&0xfc0) >> 6) | 0x80);
       obuf[q++] = (char)((c&0x3f) | 0x80);
     }
	}
	string retstr = string(obuf, q);
	free(obuf);
	return retstr;
}


} /* namespace xqp */
