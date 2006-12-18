/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: mmfile.cpp,v 1.2 2006/10/22 01:32:22 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 */

#include "mmfile.h"

#include <sys/mman.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <string>
#include <sstream>
#include <iostream>

#include "xqpexception.h"

using namespace std;
namespace xqp {


#define IOEXCEPTION(s) \
	{ \
		ostringstream oerr; \
		oerr << s << " [" << strerror(errno) << ']'; \
		throw xqpexception(__FUNCTION__, oerr.str()); \
	}


mmfile::mmfile(
	const string& _path,
	uint32_t initial_size)
:
	path(_path)
{
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
		cout << "mmfile::ctor: new, empty file\n";
		off_t m = (initial_size >> 12) << 12;	// multiple of 4096
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
	                           MAP_FILE|MAP_SHARED, fd, 0))==MAP_FAILED) {
			IOEXCEPTION("mmap failed on: '"+path+"'");
	  }
	
	  // initialize state
		eofoff = m;
	 	memset(data, 0, eofoff);
  }
	else {	// map an existing file
		cout << "mmfile::ctor: map existing file\n";
    if ((data = (char*)mmap(0, eofoff, PROT_READ|PROT_WRITE,
                            MAP_FILE|MAP_SHARED, fd, 0))==MAP_FAILED) {
      IOEXCEPTION("mmap failed on: '"+path+"'");
    }
  }
}


mmfile::~mmfile()
{
	unmap();
	close(fd);
}


void mmfile::destroy()
throw (xqpexception)
{
	try {
    unmap();
    close(fd);
    remove(path.c_str());
	} catch (xqpexception& e) {
		IOEXCEPTION("remove on: '"+path+"' application exception: "+e.what()+", "+e.get_msg());
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
throw (xqpexception)
{
	// release current map
  unmap();

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
}


void mmfile::unmap()
throw (xqpexception)
{
  if (msync(data, eofoff, 0)==-1) {
		IOEXCEPTION("msync failed on: '"+path+"'");
  }
  if (munmap(data, eofoff)==-1) {
		IOEXCEPTION("munmap failed on: '"+path+"'");
  }
}


void mmfile::rename_backing_file(const string& new_path)
throw (xqpexception)
{
  int res = rename(path.c_str(), new_path.c_str());
  if (res==-1) {
    IOEXCEPTION("rename failed on '"+path+"'");
  }
  path = new_path;
}


}  /* namespace xqp */
