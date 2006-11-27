/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: fxarray.h,v 1.2 2006/10/22 01:32:22 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR Foundation.  All Rights Reserved.
 *
 */

#ifndef XQP_FXARRAY_H
#define XQP_FXARRAY_H

#include <sys/mman.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <string>
#include <sstream>
#include <iostream>

#include "mmfile.h"
#include "xqpexception.h"

using namespace std;
namespace xqp {

#define IOEXCEPTION(s) \
	{ \
		ostringstream oerr; \
		oerr << s << " [" << strerror(errno) << ']'; \
		throw xqpxception(__FUNCTION__, oerr.str()); \
	}


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
public:		// state
	mmfile * mmf_p;		// memory-mapped case, may be NULL
	char * src;				// raw view: either mmf_p->data or heap pointer
	uint32_t eofoff;	// raw view: sentinel byte offset

  T * _begin;      	// element view: pointer to first
  T * _end;					// element view: pointer to sentinel

public:		// ctor,dtor
	/**
   ** Default construction: create no elements.
   */
  explicit fxarray() {}

	/**
   ** Create a memory-mapped fxarray with a given backing file.
	 **
   ** @param path - backing file pathname 
	 ** @param size - initial size
  */
  fxarray(string const& path, uint32_t size);

	/**
   ** Create a fxarray in memory.
	 **
	 ** @param size - initial size
   */
  fxarray(uint32_t size);

	/**
   ** Deallocate, possibly unmap and delete backing file.
   */
  ~fxarray();


	/**
   ** Destroy all the elements.
	 **	In the mm case, unmap and close backing file.
   */
	void destroy() throw (xqpexception);


public: 	// array interface
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
  void expand(bool init = false) throw (xqpexception);

	/**
	 ** Fill array with an initial byte value.
	 **
	 ** @param initval the initial value to fill with
	 */
  void fill(char initval);


public:		// iterator interface
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


public:		// memory-mapped only, nops in the non-mm case
	/**
	 ** Unmap the backing file.
	 */
	void unmap() throw (xqpexception);

	/**
	 ** Return the path of the backing file.
	 **
	 ** @return path of backing file
	 */
	string get_path() const { return mmf_p->get_path(); }

	/**
	 ** Rename the backing file.
	 */
  void rename_backing_file(string const& new_path) throw (xqpexception);

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
fxarray<T>::fxarray(string const& path, uint32_t size)
:
	mmf_p(new mmfile(path, size*sizeof(T)))
{
	eofoff = mmf_p->get_eofoff();
	src = mmf_p->get_data();
  _begin = reinterpret_cast<T*>(src);
  _end   = reinterpret_cast<T*>(src+eofoff);
}


template<typename T>
fxarray<T>::fxarray(uint32_t size)
:
	mmf_p(NULL)
{
	eofoff = size*sizeof(T);
	src = new char[eofoff];
  _begin = reinterpret_cast<T*>(src);
  _end   = reinterpret_cast<T*>(src+eofoff);
}


template<typename T>
fxarray<T>::~fxarray()
{
	if (mmf_p) {
		delete mmf_p;
	}
	else if (src) {
		delete[] src;
	}
}


template<typename T>
void fxarray<T>::fill(char initval)
{
  memset(src, initval, eofoff);
}


template<typename T>
void fxarray<T>::expand(bool init)
throw (xqpexception)
{
	if (mmf_p) {
		mmf_p->expand(init);
		src = mmf_p->get_data();
		eofoff = mmf_p->get_eofoff();
	}
	else {
		eofoff <<= 1;
		char * src0 = new char[eofoff];
		memcpy(src0, src, eofoff);
		delete[] src;
		src = src0;
	}

  _begin = reinterpret_cast<T*>(src);
  _end   = reinterpret_cast<T*>(src+eofoff);

}


template<typename T>
void fxarray<T>::unmap()
throw (xqpexception)
{
	if (mmf_p) mmf_p->unmap();
}


template<typename T>
void fxarray<T>::rename_backing_file(const string& new_path)
throw (xqpexception)
{
	if (mmf_p) mmf_p->rename_backing_file(new_path);
}


template<typename T>
void fxarray<T>::destroy()
throw (xqpexception)
{
	if (mmf_p) mmf_p->destroy();
}


}  /* namespace xqp */
#endif  /* XQP_FXARRAY_H */

