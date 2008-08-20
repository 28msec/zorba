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
#include "util/fx/fxcharheap.h"

#ifndef _WIN32_WCE
  #include <sys/types.h>
  #include <errno.h>
#else
  #include <windows.h>
  #include <types.h>
#endif

#ifdef WIN32
  
#else
  #include <sys/mman.h>
  #include <unistd.h>
#endif

#include <string>
#include <sstream>
#include <iostream>

#include <zorba/util/file.h>

#include "zorbaerrors/error_manager.h"

using namespace std;
namespace zorba {

#define _SOURCE  __FUNCTION__

void fxcharheap::ioexception(
  string const& location,
  string const& msg) const
{
  ostringstream oss;
#ifndef _WIN32_WCE
  oss << msg << " [" << strerror(errno) << ']';
#else
  oss << msg;
#endif
  //throw xqp_exception(location, oss.str());
  ZORBA_ERROR_DESC(  XQP0012_SYSTEM_FXCHARHEAP_IOEXCEPTION, oss.str());
}


/*______________________________________________________________________

  The initial sizeoff(off_t) bytes contain an offset to the first
  unused byte of the memory-mapped array.  Eofoff indexes to
  the end+1 of the allocated array. 

        eofoff__________________________________________________
   data__                                                       |
         v                                                      v
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
  bool init_offset = file(path).get_size()>0;
  init(init_offset);
}


// in-memory heap
fxcharheap::fxcharheap(
  uint32_t initial_size)
:
  fxary_p(new fxarray<char>(initial_size+sizeof(off_t)))
{
  init(true);
}


// common initialization
void fxcharheap::init(bool init_offset)
{
  data = fxary_p->get_data();
  offset_p = reinterpret_cast<off_t*>(data);
  if (init_offset) *offset_p = sizeof(off_t);
}


fxcharheap::~fxcharheap()
{
  if (fxary_p) delete fxary_p;
}


#define END true


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
  return fxcharheap_iterator(this);
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
  return fxcharheap_iterator(this,END);
}


void fxcharheap::dump_heap() const
{
  char * tmp = new char[(uint32_t)size()];
  memcpy(tmp, &data[sizeof(off_t)], (size_t)size());
  for (uint32_t i=0; i<size(); ++i) {
    if (tmp[i]==0) tmp[i] = '#';
  }
  tmp[size()] = 0;
  cout << "heap[" << size() <<"] = \n" << tmp << endl;
}


off_t fxcharheap::put(    // return the target offset
  const char* buf,        // input: string
  uint32_t start_offset,  // input: starting offset
  uint32_t len)           // input: length 
{
  off_t id  = *offset_p;

  try {
    while (id+len+1 > fxary_p->get_eofoff()) expand();
    memcpy(&data[id], &buf[start_offset], len);
    data[id+len] = 0;
  } catch (...) {
    ioexception(_SOURCE,"exception in expanding before put()");
  }

  *offset_p += (len+1);
  return id;
}


off_t fxcharheap::put(char const* buf)
{
  uint32_t n = strlen(buf);
  return put(buf, 0, n);
}


off_t fxcharheap::put(const string& s)
{
  return put(s.c_str());
}


void fxcharheap::replace(
  off_t id,               // input: heap offset
  const char* buf,        // input: string
  uint32_t start_offset,  // input: starting offset
  uint32_t len)           // input: length
{
  // check if we have enough room
  if (strlen(&data[id]) < len) {
    ioexception(_SOURCE,"insufficient space for replace");
  }
  try {
    memcpy(&data[id], &buf[start_offset], len);
    data[id+len] = 0;
  } catch (...) {
    ioexception(_SOURCE,"exception in memcpy");
  }
}


void fxcharheap::get(
  off_t id,               // input: heap offset
  char* buf,              // output: buffer
  uint32_t output_offset, // input: output buffer offset
  uint32_t maxlen) const  // input: maximum output size, truncate 
{
  try {
    uint32_t len = strlen(&data[id]);
    if (maxlen < len+1) len = maxlen-1;
    memcpy(&buf[output_offset], &data[id], len+1);  // include the trailing 0
  } catch (...) {
    ioexception(_SOURCE,"exception in memcpy"); 
  }
}


void fxcharheap::get0(
  long  id,               // input: heap offset
  char* buf,              // output: buffer
  uint32_t output_offset, // input: output buffer offset
  uint32_t maxlen) const  // input: maximum output size, truncate 
{
  try {
    uint32_t len = strlen(&data[id]);
    if (len > (maxlen - 1)) len = maxlen-1;
    memcpy(&buf[output_offset], &data[id], len);
    buf [output_offset + len] = 0;
  } catch (...) {
    ioexception(_SOURCE,"exception in memcpy"); 
  }
}


string fxcharheap::gets(off_t id)
{
  uint32_t n = get_length(id);
  char * buf = new char[n+1];
  get(id, buf, 0, n);
  return string(buf,0,n);
}


char * fxcharheap::get(off_t id) const
{
  return &data[id];
}


uint32_t fxcharheap::get_length(off_t id) const
{
  return strlen(&data[id]);
}


uint32_t fxcharheap::get_length0(long id) const
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
  bool end) 
:
  _begin(end ? &ch_p->data[sizeof(off_t)] + ch_p->size() : &ch_p->data[sizeof(off_t)]),
  _end(&ch_p->data[sizeof(off_t)] + ch_p->size()),
  parent(ch_p)
{
  current = (char*)_begin;
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


}  /* namespace zorba */
