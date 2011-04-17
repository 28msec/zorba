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

#ifndef XQP_FXCHARHEAP_H
#define XQP_FXCHARHEAP_H

#include <string>

#include "zorbatypes/rchandle.h"
#include "common/common.h"
#include "util/fx/fxarray.h"


namespace zorba {

#define DEFAULT_SIZE 4096

class fxcharheap : public SimpleRCObject
{
public:  //iterator 

  typedef class fxcharheap_iterator
  {
    char const* _begin;
    char const* _end;
    char * current;
    fxcharheap const* parent;

  public:  //ctor,dtor
    fxcharheap_iterator(fxcharheap * ch, bool end = false);
    ~fxcharheap_iterator();

  public:  //iterator interface
    char const* operator++();
    char const* operator*() const;

    friend bool operator!=(fxcharheap_iterator const&, fxcharheap_iterator const&);

  } const_iterator;


  const_iterator begin();
  const_iterator end();

public:  //state
  fxarray<char> * fxary_p;  // flex-array, either in-memory or memory-mapped
  char * data;              // heap data
  off_t * offset_p;         // pointer to offset to first unused char 


public:  //ctor,dtor

  /**
   **  Create in-memory char heap.
   */
  fxcharheap(uint32_t initial_size=DEFAULT_SIZE);

  /**
   **  Destroy char heap.
   */
  ~fxcharheap();


public:  //heap interface
  /**
   ** Get a block of characters, placing into given output array.
   */
  void get(
    off_t id,               // input: heap offset
    char * buf,             // output: output buffer
    uint32_t offset,        // input: buffer starting offset
    uint32_t maxlen) const;  // input: maximum output size, truncate

  void get0(
    long id,                // input: heap offset
    char * buf,             // output: output buffer
    uint32_t offset,        // input: buffer starting offset
    uint32_t maxlen) const;  // input: maximum output size, truncate

  // convenience method: return a string 
  std::string gets(
    off_t id);

  /**
   ** Return a pointer to the NULL-delimited string at a given offset
   */
  char * get(               // return: heap char pointer
    off_t id)  const;       // input:  the string offset

  /**
   ** Insert a new block of characters.
   **
   **  @return byte offset of the new string entry
   **  @note occasionally expensive, doubling the heap if needed.
   */
  off_t put(
    char const* buf,        // input: string
    uint32_t offset,        // input: starting offset
    uint32_t len);           // input: string length

  // convenience methods
  off_t put(char const*) ;
  off_t put(const std::string &) ;

  /**
   **  Replace a block of characters in place.
   */
  void replace(
    off_t id,               // input: heap offset
    char const* buf,        // input: string
    uint32_t offset,        // input: starting offset
    uint32_t len);           // input: string length

  /**
   **  Return the length of the string at offset 'id'.
   **
   **  @return length
   */
  uint32_t get_length(off_t id) const;
  uint32_t get_length0(long id) const;

  /**
   **  Return the heap capacity.
   **
   **  @return currently allocated capacity
   */
  uint64_t capacity() const { return fxary_p->size() - sizeof(off_t); }

  /**
   **  Return the heap size.
   **
   **  @return current heap size in bytes
   */
  uint64_t size() const { return *offset_p - sizeof(off_t); }


protected:  //internals
  /**
   ** common initialization
   */
  void init(bool init_offset = false);

  /**
   **  double the heap
   */
  void expand();

  /**
   **  parametrized io exception
   */
  void ioexception(std::string const& msg) const; 

  void dump_heap() const;
};


}  /* namespace zorba */
#endif  /* XQP_FXCHARHEAP_H */

