/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: persistent_charheap.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *
 */

#include "persistent_charheap.h"

#include <sys/types.h>
#include <sys/mman.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <string>
#include <sstream>
#include <iostream>

#include "xqpexception.h"

using namespace std;
namespace xqp {


// iterator implementations

persistent_charheap::persistent_charheap_iterator::persistent_charheap_iterator(
	persistent_charheap const* pch,
	uint32_t initial_offset) 
:
	_begin(initial_offset ? (pch->data+initial_offset) : (pch->data + sizeof(off_t))),
	_end(pch->data + sizeof(off_t) + pch->size()),
	current((char *)_begin),
	parent(pch)
{
}


persistent_charheap::persistent_charheap_iterator::~persistent_charheap_iterator()
{
}


char const* persistent_charheap::persistent_charheap_iterator::operator++()
{
	uint32_t len = strlen(current);
	const char * result = current;
	current += (len+1);
	return result;
}


char const* persistent_charheap::persistent_charheap_iterator::operator*() const
{
	return current;
}


bool operator!=(persistent_charheap::persistent_charheap_iterator const& x,
                persistent_charheap::persistent_charheap_iterator const& y)
{
	if (x.parent!=y.parent) return true;
	if (x.current!=y.current) return true;
	return false;
}


// heap implementations


/*______________________________________________________________________

	The first sizeoff(off_t) bytes contain an offset to the first
	unused byte of the memory-mapped array.  The eofoff points to
	the end of the allocated array.  No need to store the eofoff
	since it can be computed from the backing file size.


        eoffoff ________________________________________________
                                                                v
  heap: [offset|s1,0,s2,0,...          sk,0| ..unused..        ]
           |________________________________^

	______________________________________________________________________*/

persistent_charheap::persistent_charheap(
	const string& _path)
:
	path(_path)
{
  fd = open(path.c_str(), O_RDWR|O_CREAT, S_IRUSR|S_IWUSR);
  if (fd < 0 ) {
    ostringstream oerr;
    oerr << "open failed on '" << path << "' with error: " << strerror(errno);
    throw xqpexception("persistent_charheap::ctor", oerr.str());
  }
  if ((eofoff = lseek(fd, 0, SEEK_END)) == -1) {
    ostringstream oerr;
    oerr << "lseek to EOF failed on '" << path << "' with error: " << strerror(errno);
    throw xqpexception("persistent_charheap::ctor", oerr.str());
  }
  if (eofoff==0) { initialize(); }
  if ((data = (char*)mmap(0, eofoff, PROT_READ|PROT_WRITE,
                           MAP_FILE|MAP_SHARED, fd, 0))==MAP_FAILED)
  {
    ostringstream oerr;
    oerr << "mmap failed on '" << path << "' with error: " << strerror(errno);
    throw xqpexception("persistent_charheap::ctor", oerr.str());
  }
  offset_p = reinterpret_cast<off_t*>(data);
}


persistent_charheap::~persistent_charheap()
{
  unmap();
  if (close(fd) == -1) {
    ostringstream oerr;
    oerr << "close failed on '" << path << "' with error: " << strerror(errno);
    throw xqpexception("persistent_charheap::dtor", oerr.str());
  }
}



/*
**
**  end ______________________________________ 
**  begin ________                            |
**                v                           v
**  heap: [offset|s1,0,s2,0,...          sk,0| ..unused..        ]
**           |________________________________^
**
*/
persistent_charheap::persistent_charheap_iterator persistent_charheap::begin()
{
	return persistent_charheap_iterator(this,0);
}


/*
**
**  end ______________________________________ 
**  begin ____________________________________|
**                                            v
**  heap: [offset|s1,0,s2,0,...          sk,0| ..unused..        ]
**           |________________________________^
**
*/
persistent_charheap::persistent_charheap_iterator persistent_charheap::end()
{
	return persistent_charheap_iterator(this,*offset_p);
}


off_t persistent_charheap::put(
  const char* buf,				// buffer containing segment to put
  uint32_t seg_offset,		// starting offset of segment in buffer
  uint32_t seg_len)				// length of segment 
{
  // check if we need to expand
  while (*offset_p+seg_len+1 > eofoff) expand();

  try {
    memcpy(&data[*offset_p], &buf[seg_offset], seg_len);
    data[*offset_p+seg_len] = 0;
  } catch (...) {
    throw xqpexception("persistent_charheap::put", "exception in memcpy");
  }
  off_t id = *offset_p;
  *offset_p += (seg_len+1);
  return id;
}


void persistent_charheap::put(
	off_t id,								// offset replace location
  const char* buf,				// buffer containing segment to put
  uint32_t seg_offset,		// starting offset of segment in buffer
  uint32_t seg_len)				// length of segment 
{
  // check if we have enough room
	if (strlen(&data[id]) < seg_len) {
		cout << "strlen(&data[id]) = " << strlen(&data[id]) << endl;
		cout << "seg_len = " << seg_len << endl;
    throw xqpexception("persistent_charheap::put", "insufficient space for put/replace");
	}
  try {
    memcpy(&data[id], &buf[seg_offset], seg_len);
    data[id+seg_len] = 0;
  } catch (...) {
    throw xqpexception("persistent_charheap::put", "exception in memcpy");
  }
}


void persistent_charheap::get(
  off_t id,								// segment id
  char* seg_buf,					// buffer into which to place block
  uint32_t seg_offset,		// offset for block in buffer
  uint32_t seg_maxlen)		// maximum output size, truncate if larger
const
{
  // transfer the data
  try {
    uint32_t len = strlen(&data[id]);
    if (seg_maxlen < len+1) len = seg_maxlen-1;
    memcpy(&seg_buf[seg_offset], &data[id], len+1);  // includes the trailing 0
  } catch (...) {
    ostringstream oerr;
    oerr << "persistent_charheap::get() : exception in memcpy"; 
    cerr << oerr.str() << endl;
  }
}


uint32_t persistent_charheap::get_length(off_t id) const
{
  return strlen(&data[id]);
}


void persistent_charheap::initialize()
{
  if (lseek(fd, 4095, SEEK_END)==-1) {  // Note 4096-1
    ostringstream oerr;
    oerr << "lseek to 4095 failed with error: " << strerror(errno);
    throw xqpexception("persistent_charheap::initialize", oerr.str());
  }

  // write one byte to create the new allocation
  char buf[1] = { '\0' };
  if (write(fd, buf, 1) == -1) {				// Get 4095+1
    ostringstream oerr;
    oerr << "write to 4095 failed with error: " << strerror(errno);
    throw xqpexception("persistent_charheap::expand", oerr.str());
  }

  if ((data = (char*)mmap(0, 4096, PROT_READ|PROT_WRITE,
                           MAP_FILE|MAP_SHARED, fd, 0))==MAP_FAILED)
  {
    ostringstream oerr;
    oerr << "mmap failed with error: " << strerror(errno);
    throw xqpexception("persistent_charheap::initialize", oerr.str());
  }
  offset_p = reinterpret_cast<off_t*>(data);
  *offset_p = sizeof(off_t);      // reserve for size
  eofoff = 4096;
}


void persistent_charheap::expand()
{
  unmap();

  // find the end
  if ( (eofoff = lseek(fd, 0, SEEK_END)) == -1) {
    ostringstream oerr;
    oerr << "lseek to EOF failed with error: " << strerror(errno);
    throw xqpexception("persistent_charheap::expand", oerr.str());
  }

  // double past the end
  if (lseek(fd, eofoff-1, SEEK_END)==-1) {  // Note the -1
    ostringstream oerr;
    oerr << "lseek to 2*EOF failed with error: " << strerror(errno);
    throw xqpexception("persistent_charheap::expand", oerr.str());
  }

  // write one byte to create the hole equal 
  // in size to the original file
  char buf[1] = { '\0' };
  if (write(fd, buf, 1) == -1) {            // Get back the -1
    ostringstream oerr;
    oerr << "write to 2*EOF failed with error: " << strerror(errno);
    throw xqpexception("persistent_charheap::expand", oerr.str());
  }

  // remap the file
  eofoff <<= 1;
  if ((data = (char*)mmap(0, eofoff, PROT_READ|PROT_WRITE,
                           MAP_FILE|MAP_SHARED, fd, 0))==MAP_FAILED)
  {
    ostringstream oerr;
    oerr << "mmap failed with error: " << strerror(errno);
    throw xqpexception("persistent_charheap::expand", oerr.str());
  }
  offset_p = reinterpret_cast<off_t*>(data);
}


void persistent_charheap::unmap()
{
  if (munmap(data, eofoff)==-1) {
    ostringstream oerr;
    oerr << "munmap failed with error: " << strerror(errno);
    throw xqpexception("persistent_charheap:unmap", oerr.str());
  }
}

}  /* namespace xqp */
