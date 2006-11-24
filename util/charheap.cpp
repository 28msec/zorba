/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: charheap.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *
 */

#include "charheap.h"

#include <sys/types.h>
#include <sys/mman.h>
#include <errno.h>
#include <unistd.h>
#include <string>
#include <sstream>
#include <iostream>

#include "xqpexception.h"

using namespace std;
namespace xqp {

#define ERROR(s) \
	ostringstream oerr; oerr << s; \
	cerr << __FUNCTION__ << oerr.str(); \
	throw xqpexception(__FUNCTION__, oerr.str());

// iterator implementations

charheap::charheap_iterator::charheap_iterator(
	charheap * ch,
	uint32_t initial_offset) 
:
	_begin(ch->data + initial_offset),
	_end(ch->data + ch->size()),
	current((char*)_begin),
	parent(ch)
{
}


charheap::charheap_iterator::~charheap_iterator()
{
}


char const* charheap::charheap_iterator::operator++()
{
	uint32_t len = strlen(current);
	char const* result = current;
	current += (len+1);
	return result;
}


char const* charheap::charheap_iterator::operator*() const
{
	return current;
}


bool operator!=(charheap::charheap_iterator const& x,
                charheap::charheap_iterator const& y)
{
	if (x.parent!=y.parent) return true;
	if (x.current!=y.current) return true;
	return false;
}



// charheap implementations

/*______________________________________________________________________

	The first sizeoff(off_t) bytes contain an offset to the first
	unused byte of the memory-mapped array.  The eofoff points to
	the end of the allocated array.  No need to store the eofoff
	since it can be computed from the backing file size.

        eofoff __________________________________________
                                                         |
        offset ______________________                    |
                                     v                   v
  heap: [s1,0,s2,0,...          sk,0| ..unused..        ]
         
	______________________________________________________________________*/

charheap::charheap(
	uint32_t initial_size)
:
	data(new char[initial_size]),
	eofoff(initial_size),
	offset(0)
{
}


charheap::~charheap()
{
	delete[] data;
}


/*
**
**  end _______________________________ 
**  begin __                           |
**          v                          v
**  heap: [s1,0,s2,0,...          sk,0| ..unused..        ]
**
*/
charheap::charheap_iterator charheap::begin()
{
	return charheap_iterator(this,0);
}


/*
**
**  end _______________________________ 
**  begin _____________________________|
**                                     v
**  heap: [s1,0,s2,0,...          sk,0| ..unused..        ]
**
*/
charheap::charheap_iterator charheap::end()
{
	return charheap_iterator(this,offset);
}



off_t charheap::put(			// return the target offset
  const char* buf,      	// buffer containing segment to put
  uint32_t seg_offset,  	// starting offset of segment in buffer
  uint32_t seg_len)      	// length of segment 
throw (xqp::xqpexception)
{
  try {
  	// check if we need to expand
  	while (offset+seg_len+1 > eofoff) expand();
    memcpy(&data[offset], &buf[seg_offset], seg_len);
    data[offset+seg_len] = 0;
  } catch (...) {
    ERROR("exception in memcpy");
  }
  off_t id = offset;
  offset += (seg_len+1);
  return id;
}


void charheap::replace(
	off_t id,							// offset replace location
  const char* buf,      // buffer containing segment to put
  uint32_t seg_offset,  // starting offset of segment in buffer
  uint32_t seg_len)     // length of segment 
throw (xqp::xqpexception)
{
  // check if we have enough room
	if (strlen(&data[id]) < seg_len) {
		ERROR("insufficient space for replace");
	}
  try {
    memcpy(&data[id], &buf[seg_offset], seg_len);
    data[id+seg_len] = 0;
  } catch (...) {
		ERROR("exception in memcpy");
  }
}


void charheap::get(
  off_t id,             // segment id
  char* seg_buf,        // buffer into which to place block
  uint32_t seg_offset,  // offset for block in buffer
  uint32_t seg_maxlen)  // maximum output size, truncate if larger
const
throw (xqp::xqpexception)
{
  try {
  	// transfer the data
    uint32_t len = strlen(&data[id]);
    if (seg_maxlen < len+1) len = seg_maxlen-1;
    memcpy(&seg_buf[seg_offset], &data[id], len+1);  // includes the trailing 0
  } catch (...) {
    ERROR("exception in memcpy"); 
  }
}


uint32_t charheap::get_length(off_t id) const
{
  return strlen(&data[id]);
}


void charheap::expand()
{
	uint32_t eofoff2 = eofoff<<1;
	char* data2 = new char[eofoff2];
	memset(data2, 0, eofoff2);
	memcpy(data2, data, offset);
	delete[] data;
	data = data2;
	eofoff = eofoff2;
}


}  /* namespace xqp */


