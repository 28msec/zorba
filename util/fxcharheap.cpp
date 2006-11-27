/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: charheap.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *
 */

#include "fxcharheap.h"

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

void fxcharheap::ioexception(
	string const& location,
	string const& msg) const
{
	ostringstream oss;
	oss << msg << " [" << strerror(errno) << ']';
	throw xqpexception(location, oss.str());
}


/*______________________________________________________________________

  The initial sizeoff(off_t) bytes contain an offset to the first
  unused byte of the memory-mapped array.  Eofoff indexes to
  the end of the allocated array. 

        eofoff__________________________________________________
        data____                                                |
                v                                               v
  heap: [offset|s1,0,s2,0,...          sk,0| ..unused..        ]
           |                                ^
           |________________________________|

  ______________________________________________________________________*/

// memory-mapped heap
fxcharheap::fxcharheap(
	string const& path,
	uint32_t initial_size)
:
	fxary_p(new fxarray<char>(path, initial_size+sizeof(off_t)))
{
	init();
}


// in-memory heap
fxcharheap::fxcharheap(
	uint32_t initial_size)
:
	fxary_p(new fxarray<char>(initial_size+sizeof(off_t)))
{
	init();
}


// common initialization
void fxcharheap::init()
{
	data = fxary_p->get_data();
	offset_p = reinterpret_cast<off_t*>(data);
	data += sizeof(off_t);
}


fxcharheap::~fxcharheap()
{
	delete fxary_p;
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
fxcharheap::fxcharheap_iterator fxcharheap::begin()
{
	return fxcharheap_iterator(this,0);
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
fxcharheap::fxcharheap_iterator fxcharheap::end()
{
	return fxcharheap_iterator(this,*offset_p);
}


off_t fxcharheap::put(		// return the target offset
  const char* buf,				// input: string
  uint32_t start_offset,	// input: starting offset
  uint32_t len)						// input: length 
throw (xqp::xqpexception)
{
  try {
  	while (*offset_p+len+1 > fxary_p->get_eofoff()) expand();
    memcpy(&data[*offset_p], &buf[start_offset], len);
    offset_p[len] = 0;
  } catch (...) {
    ioexception(__FUNCTION__,"exception in expanding before put()");
  }
  off_t id = *offset_p;
  *offset_p += (len+1);
  return id;
}


void fxcharheap::replace(
	off_t id,								// input: heap offset
  const char* buf,				// input: string
  uint32_t start_offset,	// input: starting offset
  uint32_t len)						// input: length
throw (xqp::xqpexception)
{
  // check if we have enough room
	if (strlen(&data[id]) < len) {
		ioexception(__FUNCTION__,"insufficient space for replace");
	}
  try {
    memcpy(&data[id], &buf[start_offset], len);
    data[id+start_offset] = 0;
  } catch (...) {
		ioexception(__FUNCTION__,"exception in memcpy");
  }
}


void fxcharheap::get(
  off_t id,             	// input: heap offset
  char* buf,		        	// output: buffer
  uint32_t output_offset, // input: output buffer offset
  uint32_t maxlen) const	// input: maximum output size, truncate 
throw (xqp::xqpexception)
{
  try {
    uint32_t len = strlen(&data[id]);
    if (maxlen < len+1) len = maxlen-1;
    memcpy(&buf[output_offset], &data[id], len+1);  // include the trailing 0
  } catch (...) {
    ioexception(__FUNCTION__,"exception in memcpy"); 
  }
}


uint32_t fxcharheap::get_length(off_t id) const
{
  return strlen(&data[id]);
}


void fxcharheap::expand()
{
	fxary_p->expand();
	init();
}



// iterator implementations

fxcharheap::fxcharheap_iterator::fxcharheap_iterator(
	fxcharheap * ch_p,
	uint32_t initial_offset) 
:
	_begin(initial_offset ? ch_p->data + initial_offset - sizeof(off_t) : ch_p->data),
	_end(ch_p->data + ch_p->size()),
	current((char*)_begin),
	parent(ch_p)
{
}


fxcharheap::fxcharheap_iterator::~fxcharheap_iterator()
{
}


char const* fxcharheap::fxcharheap_iterator::operator++()
{
	uint32_t len = strlen(current);
	char const* result = current;
	current += (len+1);
	return result;
}


char const* fxcharheap::fxcharheap_iterator::operator*() const
{
	return current;
}


bool operator!=(fxcharheap::fxcharheap_iterator const& x,
                fxcharheap::fxcharheap_iterator const& y)
{
	if (x.parent!=y.parent) return true;
	if (x.current!=y.current) return true;
	return false;
}


}  /* namespace xqp */

