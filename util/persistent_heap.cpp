/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: persistent_heap.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *
 */

#include "persistent_heap.h"

#include <sys/types.h>
#include <sys/mman.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <string>
#include <sstream>
#include <iostream>

#include "Exception.h"

using namespace std;
namespace xqp {

// Memory-mapped heap implementations

persistent_heap::persistent_heap(
	const string& _path)
:
	path(_path)
{
  fd = open(path.c_str(), O_RDWR|O_CREAT, S_IRUSR|S_IWUSR);
  if (fd < 0 ) {
    ostringstream oerr;
    oerr << "open failed on '" << path << "' with error: " << strerror(errno);
    throw Exception("persistent_heap::ctor", oerr.str());
  }
  if ((eofoff = lseek(fd, 0, SEEK_END)) == -1) {
    ostringstream oerr;
    oerr << "lseek to EOF failed on '" << path << "' with error: " << strerror(errno);
    throw Exception("persistent_heap::ctor", oerr.str());
  }
  if (eofoff==0) { initialize(); }
  if ((data = (char*)mmap(0, eofoff, PROT_READ|PROT_WRITE,
                           MAP_FILE|MAP_SHARED, fd, 0))==MAP_FAILED)
  {
    ostringstream oerr;
    oerr << "mmap failed on '" << path << "' with error: " << strerror(errno);
    throw Exception("persistent_heap::ctor", oerr.str());
  }
  offsetp = reinterpret_cast<off_t*>(data);
}


persistent_heap::~persistent_heap()
{
  unmap();
  if (close(fd) == -1) {
    ostringstream oerr;
    oerr << "close failed on '" << path << "' with error: " << strerror(errno);
    throw Exception("persistent_heap::dtor", oerr.str());
  }
}


off_t persistent_heap::put(
  const char* buf,      // buffer containing segment to put
  uint32_t seg_offset,  // starting offset of segment in buffer
  uint32_t seg_len)      // length of segment 
{
  // check if we need to expand
  while (*offsetp+seg_len+1 > eofoff) expand();

  try {
    memcpy(&data[*offsetp], &buf[seg_offset], seg_len);
    data[*offsetp+seg_len] = 0;
  } catch (...) {
    throw Exception("persistent_heap::put", "exception in memcpy");
  }
  off_t id = *offsetp;
  *offsetp += (seg_len+1);
  return id;
}


void persistent_heap::put(
	off_t id,							// offset replace location
  const char* buf,      // buffer containing segment to put
  uint32_t seg_offset,  // starting offset of segment in buffer
  uint32_t seg_len)     // length of segment 
{
  // check if we have enough room
	if (strlen(&data[id]) < seg_len) {
		cout << "strlen(&data[id]) = " << strlen(&data[id]) << endl;
		cout << "seg_len = " << seg_len << endl;
    throw Exception("persistent_heap::put", "insufficient space for put/replace");
	}
  try {
    memcpy(&data[id], &buf[seg_offset], seg_len);
    data[id+seg_len] = 0;
  } catch (...) {
    throw Exception("persistent_heap::put", "exception in memcpy");
  }
}


void persistent_heap::get(
  off_t id,             // segment id
  char* seg_buf,        // buffer into which to place block
  uint32_t seg_offset,  // offset for block in buffer
  uint32_t seg_maxlen)  // maximum output size, truncate if larger
const
{
  // transfer the data
  try {
    uint32_t len = strlen(&data[id]);
    if (seg_maxlen < len+1) len = seg_maxlen-1;
    memcpy(&seg_buf[seg_offset], &data[id], len+1);  // includes the trailing 0
  } catch (...) {
    ostringstream oerr;
    oerr << "persistent_heap::get() : exception in memcpy"; 
    cerr << oerr.str() << endl;
  }
}


uint32_t persistent_heap::getLength(off_t id) const
{
  return strlen(&data[id]);
}

uint32_t persistent_heap::get_length(off_t id) const
{
  return strlen(&data[id]);
}


void persistent_heap::initialize()
{
  if (lseek(fd, 4095, SEEK_END)==-1) {  // Note the -1
    ostringstream oerr;
    oerr << "lseek to 4095 failed with error: " << strerror(errno);
    throw Exception("persistent_heap::initialize", oerr.str());
  }

  // write one byte to create the new allocation
  char buf[1] = { '\0' };
  if (write(fd, buf, 1) == -1) {            // Get back the -1
    ostringstream oerr;
    oerr << "write to 4095 failed with error: " << strerror(errno);
    throw Exception("persistent_heap::expand", oerr.str());
  }

  if ((data = (char*)mmap(0, 4096, PROT_READ|PROT_WRITE,
                           MAP_FILE|MAP_SHARED, fd, 0))==MAP_FAILED)
  {
    ostringstream oerr;
    oerr << "mmap failed with error: " << strerror(errno);
    throw Exception("persistent_heap::initialize", oerr.str());
  }
  offsetp  = reinterpret_cast<off_t*>(data);
  *offsetp = 8;      // reserve 8 bytes for size
  eofoff = 4096;
}


void persistent_heap::expand()
{
  unmap();

  // find the end
  if ( (eofoff = lseek(fd, 0, SEEK_END)) == -1) {
    ostringstream oerr;
    oerr << "lseek to EOF failed with error: " << strerror(errno);
    throw Exception("persistent_heap::expand", oerr.str());
  }

  // double past the end
  if (lseek(fd, eofoff-1, SEEK_END)==-1) {  // Note the -1
    ostringstream oerr;
    oerr << "lseek to 2*EOF failed with error: " << strerror(errno);
    throw Exception("persistent_heap::expand", oerr.str());
  }

  // write one byte to create the hole equal 
  // in size to the original file
  char buf[1] = { '\0' };
  if (write(fd, buf, 1) == -1) {            // Get back the -1
    ostringstream oerr;
    oerr << "write to 2*EOF failed with error: " << strerror(errno);
    throw Exception("persistent_heap::expand", oerr.str());
  }

  // remap the file
  eofoff <<= 1;
  if ((data = (char*)mmap(0, eofoff, PROT_READ|PROT_WRITE,
                           MAP_FILE|MAP_SHARED, fd, 0))==MAP_FAILED)
  {
    ostringstream oerr;
    oerr << "mmap failed with error: " << strerror(errno);
    throw Exception("persistent_heap::expand", oerr.str());
  }
  offsetp = reinterpret_cast<off_t*>(data);
}


void persistent_heap::unmap()
{
  if (munmap(data, eofoff)==-1) {
    ostringstream oerr;
    oerr << "munmap failed with error: " << strerror(errno);
    throw Exception("persistent_heap:unmap", oerr.str());
  }
}

}  /* namespace xqp */


