/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: mmfile.cpp,v 1.2 2006/10/22 01:32:22 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR Foundation.  All Rights Reserved.
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

#define IOERROR(s) \
	ostringstream oerr; \
	oerr << s << " [" << strerror(errno) << ']'; \
	throw xqpexception(__FUNCTION__, oerr.str());


mmfile::mmfile(
	const string& _path,
	uint32_t _depth)
:
	path( _path),
	depth(_depth)
{
	reopen();
}


mmfile::~mmfile()
{
	unmap();
	close(fd);
}


void mmfile::reopen()
{
  // open the backing file
  fd = open(path.c_str(), O_RDWR|O_CREAT, S_IRUSR|S_IWUSR);
  if (fd < 0 ) {
    IOERROR("open failed on '"+path+"'");
  }

  // allocate entire file
  if ((eofoff = lseek(fd, 0, SEEK_END)) == -1) {
  	IOERROR("lseek to 2*EOF failed on '"+path+"'");
  }

  if (eofoff==0) {
    initialize(depth);
  } else {
    // map the existing file
    if ((data = (char*)mmap(0, eofoff, PROT_READ|PROT_WRITE,
                            MAP_FILE|MAP_SHARED, fd, 0))==MAP_FAILED) {
      IOERROR("mmap failed on '"<<path<<"'");
    }

    // recompute depth
    uint32_t l = 0;
    uint32_t n = eofoff;
    while ( n>>=1 ) { ++l; }
    while (l<12) {
      double_array(true);
      n = eofoff;
      while ( n>>=1 ) { ++l; }
    }
    depth = (l-12);  // base 4K
  }
}


void mmfile::initialize(uint32_t depth)
{
	// position to eof
  if (lseek(fd, 4095, SEEK_END)==-1) { // 4096 - 1
		IOERROR("lseek to EOF failed");
  }

  // writing one byte creates the new allocation
  char buf[1] = { '\0' };
  if (write(fd, buf, 1) == -1) {       // 4095 + 1
		IOERROR("write to EOF failed");
  }

	// return the mem-map buffer pointer
  if ((data = (char*)mmap(0,4096,PROT_READ|PROT_WRITE,
                           MAP_FILE|MAP_SHARED,fd,0))==MAP_FAILED) {
		IOERROR("mmap failed");
  }

  // initialize state
 	memset(data, 0, 4096);
 	eofoff = 4096;
 	for (uint32_t n=0; n<depth; ++n) { double_array(true); }
}


void mmfile::fill(char initval)
{
#ifdef DEBUG
  cout << "mmfile::fill(eofoff=" << eofoff <<" )\n";
#endif
  memset(data, initval, eofoff);
}


void mmfile::double_array(bool init)
{
#ifdef DEBUG
  cout << "mmfile::double_array\n";
  cout << "eofoff = " << eofoff << endl;
#endif

	// release current map
  unmap();

  // double past the end
  if (lseek(fd, eofoff-1, SEEK_END)==-1) {  // Note the -1
		IOERROR("lseek to 2*EOF failed");
  }

  // write one byte: creates hole equal
  // in size to the original file
  char buf[1] = { '\0' };
  if (write(fd, buf, 1) == -1) {            // Get back +1
		IOERROR("write to 2*EOF failed");
  }

#ifdef DEBUG
struct stat statbuf; fstat(fd, &statbuf);
cout << "  eof => " << statbuf.st_size << endl;
#endif

  if (!init) depth++;

  // remap the file
  eofoff <<= 1;
  if ((data = (char*)mmap(0, eofoff, PROT_READ|PROT_WRITE,
                           MAP_SHARED, fd, 0))==MAP_FAILED) {
		IOERROR("mmap failed");
  }

#ifdef DEBUG
  cout << "eofoff = " << eofoff << endl;
#endif
}


void mmfile::unmap()
{
  if (msync(data, eofoff, 0)==-1) {
		IOERROR("msync failed");
  }
  if (munmap(data, eofoff)==-1) {
		IOERROR("munmap failed");
  }
}


void mmfile::renam(const string& new_path)
{
  int res = rename(path.c_str(), new_path.c_str());
  if (res==-1) {
    IOERROR("renaming error on '"+path+"'");
  }
  path = new_path;
}


}  /* namespace xqp */
