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
#ifndef ZORBA_FXARRAY_H
#define ZORBA_FXARRAY_H
#include "common/common.h"

#ifndef WIN32
#include <sys/mman.h>
#endif

#ifndef _WIN32_WCE
  #include <sys/types.h>
  #include <errno.h>
  #include <fcntl.h>
#else
  #include <types.h>
#endif


#include <string>
#include <sstream>
#include <iostream>

#include "zorbaerrors/error_manager.h"

namespace zorba {

#define DEFAULT_SIZE 4096


/*_____________________________________________________________
|
|  Flex-array.
|
|  Given a path name, this will create a memory-mapped
|  array of type T.
|
|  With no path name given, this will create a simple
|  in-memory array of type T.
|______________________________________________________________*/

template<typename T>
class fxarray
{
public:   // state
  char * src;       // raw view: heap pointer
  uint32_t eofoff;  // raw view: sentinel byte offset

  T * _begin;       // element view: pointer to first
  T * _end;         // element view: pointer to sentinel

public:   // ctor,dtor

  /**
   ** Create a fxarray in memory.
   **
   ** @param size - initial size
   */
  fxarray(uint32_t initial_size=DEFAULT_SIZE);

  /**
   ** Deallocate, possibly unmap and delete backing file.
   */
  ~fxarray();

public:   // array interface
  /**
   ** Subscript access to the data contained in the fxarray.
   **
   ** @param n - index of the element for which data should be accessed.
   ** @return  Read/write reference to data.
   ** @note data access with this operator is unchecked and
   **       out-of-range lookups are not defined.
   */
  T& operator[](size_t n) { return *(_begin + n); }

  /**
   ** Return the size of this array.
   ** @return array size
   */
  uint32_t size() const { return (eofoff / sizeof(T)); }

  /**
   ** Double the array (and its file).
   **
   ** @param init - if true then initialize the new entries to 0
   */
  void expand(bool init = false);

  /**
   ** Fill array with an initial byte value.
   **
   ** @param initval the initial value to fill with
   */
  void fill(char initval);

public:   // iterator interface
  /**
   ** Return the first element.
   **
   ** @return first element
   */
  T * begin() { return _begin; }

  /**
   ** Return the sentinel element.
   **
   ** @return sentinel element
   */
  T * end() { return _end; }


public:   // memory-mapped only, nops in the non-mm case

  /**
   ** Return data array pointer.
   **
   ** @return data array pointer
   */
  char * get_data() const { return src; }

  /**
   ** Return the data array sentinel.
   **
   ** @return data array sentinel
   */
  uint32_t get_eofoff() const { return eofoff; }

};


template<typename T>
fxarray<T>::fxarray(uint32_t size)
{
  eofoff = size*sizeof(T);
  src = new char[eofoff];
  _begin = reinterpret_cast<T*>(src);
  _end   = reinterpret_cast<T*>(src+eofoff);
}


template<typename T>
fxarray<T>::~fxarray()
{
  delete[] src;
}


template<typename T>
void fxarray<T>::fill(char initval)
{
  memset(src, initval, eofoff);
}


template<typename T>
void fxarray<T>::expand(bool init)
{
  char * src0 = new char[eofoff<<1];
  memcpy(src0, src, eofoff);
  eofoff <<= 1;
  delete[] src;
  src = src0;

  _begin = reinterpret_cast<T*>(src);
  _end   = reinterpret_cast<T*>(src+eofoff);

}


}  /* namespace zorba */
#endif  /* ZORBA_FXARRAY_H */
/* vim:set et sw=2 ts=2: */
