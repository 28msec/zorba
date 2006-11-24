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


charheap::charheap(uint32_t initial_size)
: data(new char[initial_size]),
	eofoff(initial_size),
	offset(0)
{
}


charheap::~charheap()
{
	delete[] data;
}


off_t charheap::put(
// return the target offset
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


