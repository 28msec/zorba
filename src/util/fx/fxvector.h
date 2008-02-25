/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: fxvector.h,v 1.3 2006/11/01 17:56:20 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR Foundation.  All Rights Reserved.
 *	Author: Paul Pedersen
 *
 */

#ifndef XQP_FXVECTOR_H
#define XQP_FXVECTOR_H

#include <zorba/rchandle.h>
#include <zorba/common/common.h>

#include "util/fx/mmfile.h"
#include "util/tracer.h"
#include "errors/error_factory.h"

#ifndef WIN32
	#include <sys/mman.h>
	#include <unistd.h>
#endif

#ifndef _WIN32_WCE
	#include <sys/types.h>
	#include <sys/stat.h>
	#include <errno.h>
	#include <fcntl.h>
#else
	#include <types.h>
#endif
#include <string.h>

#include <memory>
#include <string>
#include <sstream>
#include <iostream>

namespace xqp {

#define DEFAULT_SIZE		4096		// default initial vector size

template<typename T>
class fxvector
{
public:
	typedef fxvector<T> vector_type;
	typedef T           value_type;
	typedef T*          pointer;
	typedef T const*    const_pointer;
	typedef T&          reference;
	typedef T const&    const_reference;
	typedef size_t      size_type;
	typedef ptrdiff_t   difference_type;
	typedef __gnu_cxx::__normal_iterator<pointer,vector_type>				iterator;
	typedef __gnu_cxx::__normal_iterator<const_pointer,vector_type>	const_iterator;
	typedef std::reverse_iterator<iterator>													reverse_iterator;
	typedef std::reverse_iterator<const_iterator>										const_reverse_iterator;

public:  
	mmfile* mmf_p;			// memory-mapped file, may be NULL
	char* src;					// raw view of data
	                    //   the first 8 bytes stores end-of-storage offset
	T* start;						// pointer to first element
	T* finish;					// pointer to first free element 
	T* end_of_storage;	// pointer one past end of storage

public:		// ctor,dtor
	/**
	 **  Create in-memory fxvector 
	 */
	fxvector(uint32_t initial_size=DEFAULT_SIZE);

	/**
	 **  Create a fxvector with a given backing file
	 **  @param  path    The pathname of the backing file
	 */
	fxvector(string const& path, uint32_t initial_size=DEFAULT_SIZE);

	/**
	 **  dtor erases all elements.
	 **  Note: if the elements themselves are pointers, the
	 **  pointed-to memory is not touched in any way.  Managing
	 **  the pointers is the user's responsibilty.
	 */
	~fxvector();

public:
	T* get_start() const { return start; }
	T* get_finish() const { return finish; }
	void incr_finish(uint32_t n) { finish += n; }
	T* get_end_of_storage() const { return end_of_storage; }
	char* get_src() const { return src; }
	char* raw_copy(char const* data, uint32_t length);
	char* raw_copy(std::string const&);

private:
	/**
	 **  lock out fxvector copy constructor. 
	 */
	fxvector(fxvector const& x) { }

public:		// iterator interface
	/**
	 *  Returns a read/write iterator that points to the first
	 *  element in the vector.  Iteration is done in ordinary
	 *  element order.
	 */
	iterator begin()
	{
		return iterator(start);
	}

	/**
	 *  Returns a read-only (constant) iterator that points to the
	 *  first element in the vector.  Iteration is done in ordinary
	 *  element order.
	 */
	const_iterator cbegin() const
	{
		return const_iterator(start);
	}

	/**
	 *  Returns a read/write iterator that points one past the last
	 *  element in the vector.  Iteration is done in ordinary
	 *  element order.
	 */
	iterator end()
	{
		return iterator(finish);
	}

	/**
	 *  Returns a read-only (constant) iterator that points one past
	 *  the last element in the vector.  Iteration is done in
	 *  ordinary element order.
	 */
	const_iterator cend() const
	{
		return const_iterator(finish);
	}

	/**
	 *  Returns a read/write reverse iterator that points to the
	 *  last element in the vector.  Iteration is done in reverse
	 *  element order.
	 */
	reverse_iterator rbegin()
	{
		return reverse_iterator(end());
	}

	/**
	 *  Returns a read-only (constant) reverse iterator that points
	 *  to the last element in the vector.  Iteration is done in
	 *  reverse element order.
	 */
	const_reverse_iterator rbegin() const
	{
		return const_reverse_iterator(end());
	}

	/**
	 *  Return a read/write reverse iterator that points to one
	 *  before the first element in the vector.  Iteration is done
	 *  in reverse element order.
	 */
	reverse_iterator rend()
	{
		return reverse_iterator(begin());
	}

	/**
	 *  Return a read-only (constant) reverse iterator that points
	 *  to one before the first element in the vector.  Iteration
	 *  is done in reverse element order.
	 */
	const_reverse_iterator rend() const
	{
		return const_reverse_iterator(begin());
	}

public:		// vector interface
	/**
	 *  Return the number of elements in the vector. 
	 */
	size_type size() const
	{
		return size_type(cend() - cbegin());
	}

	/**
	 *  Return the size() of the largest possible vector. 
	 */
	size_type max_size() const
	{
		return size_type(-1) / sizeof(value_type);
	}

	/**
	 *  Returns the total number of elements that the vector can
	 *  hold before needing to allocate more memory.
	 */
	size_type capacity() const
	{
		return size_type(const_iterator(end_of_storage) - cbegin()); 
	}

	/**
	 *  Returns true if the vector is empty.  (Thus begin() would
	 *  equal end().)
	 */
	bool empty() const
	{
		return begin() == end();
	}

	/**
	 *  Subscript access to the data contained in the vector.
	 *  @param n index of the element for which data should be accessed.
	 *  @return  Read/write reference to data.
	 *
	 *  This operator allows for easy, array-style, data access.
	 *  Note that data access with this operator is unchecked and
	 *  out_of_range lookups are not defined. (For checked lookups
	 *  see at().)
	 */
	reference operator[](size_type n)
	{
		return *(begin() + n);
	}

	/**
	 *  Subscript access to the data contained in the vector.
	 *  @param n index of the element for which data should be accessed.
 	 *  @return  Read-only (constant) reference to data.
	 *
	 *  This operator allows for easy, array-style, data access.
	 *  Note that data access with this operator is unchecked and
	 *  out_of_range lookups are not defined. (For checked lookups
	 *  see at().)
	 */
	const_reference operator[](size_type n) const
	{
		return *(begin() + n);
	}

protected:
	void range_check(size_type n) const
	{
		if (n >= size())
		{
		//	throw xqp_exception(__FUNCTION__, "fxvector::range_check");
			ostringstream	ostr1;
			ostringstream	ostr2;

			ostr1 << n;
			ostr2 << size();
			ZORBA_ERROR_ALERT(ZorbaError::XQP0007_SYSTEM_VECTOR_OUT_OF_RANGE,
                        NULL, DONT_CONTINUE_EXECUTION,///dont continue execution, stop here
                        ostr1.str(), ostr2.str()///param1 and param2 for error message
                        );
		}
	}

public:
	/**
	 *  Provides access to the data contained in the vector.
	 *  @param n index of the element for which data should be accessed.
	 *  @return  Read/write reference to data.
	 *  @throw  std::out_of_range  If n is an invalid index.
	 *
	 *  This function provides for safer data access.  The parameter
	 *  is first checked that it is in the range of the vector.  The
	 *  function throws out_of_range if the check fails.
	 */
	reference at(size_type n)
	{
		range_check(n);
		return (*this)[n];
	}

	/**
	 *  Provides access to the data contained in the vector.
	 *  @param n index of the element for which data should be accessed.
	 *  @return  Read-only (constant) reference to data.
	 *  @throw  std::out_of_range  If n is an invalid index.
	 *
	 *  This function provides for safer data access.  The parameter
	 *  is first checked that it is in the range of the vector.  The
	 *  function throws out_of_range if the check fails.
	 */
	const_reference at(size_type n) const
	{
		range_check(n);
		return (*this)[n];
	}

	/**
	 *  Returns a read/write reference to the data at the first
	 *  element of the vector.
	 */
	reference front() { return *begin(); }

	/**
	 *  Returns a read-only (constant) reference to the data at the first
	 *  element of the vector.
	 */
	const_reference front() const { return *begin(); }

	/**
	 *  Returns a read/write reference to the data at the last
	 *  element of the vector.
	 */
	reference back() { return *(end() - 1); }

	/**
	 *  Returns a read-only (constant) reference to the data at the
 	 *  last element of the vector.
	 */
	const_reference back() const { return *(end() - 1); }

	/**
	 *  Add data to the end of the vector.
 	 *  @param  x  data to be added.
	 */
	void push_back(const value_type& x)
	{
		//if (finish+sizeof(value_type) >= end_of_storage) expand();
		if (&finish[1] > end_of_storage) expand();
		std::_Construct(finish, x);
		++finish;
		if (mmf_p) {	// update offset_p
			off_t* offset_p = reinterpret_cast<off_t*>(src);
			*offset_p += sizeof(value_type);
		}
		//msync(src, mmf_p->get_eofoff(), MS_SYNC);
	}

	void* alloc(size_t n);

	/**
	 *  Remove last element.  It shrinks the vector by one.
	 *
	 *  No data is returned, and if the last element's data is
	 *  needed, it should be retrieved before pop_back() is called.
	 */
	void pop_back()
	{
		--finish;
		std::_Destroy(finish);
	}

	/**
	 *  Clear the vector.                     
	 *  Set the size to zero.         
	 */
	void clear();


// INTERNAL

public:
	void expand();

public:
	void unmap();

};



// IMPLEMENTATIONS 

template<typename T>
fxvector<T>::fxvector(
	const string& _path,
	uint32_t initial_size) 
:
	mmf_p(new mmfile(_path, initial_size))
{
	src = mmf_p->get_data();

	// the first sizeof(off_t) bytes stores offset to free storage
	off_t* offset_p = reinterpret_cast<off_t*>(src);
	if (*offset_p == 0) {
		*offset_p = sizeof(off_t);
	}

#ifdef DEBUG
	cout << "fxvector::ctor: offset = " << *offset_p << endl; 
#endif

	start  = reinterpret_cast<T*>(src + sizeof(off_t));
	finish = reinterpret_cast<T*>(&src[*offset_p]);
	end_of_storage = reinterpret_cast<T*>(src + mmf_p->get_eofoff());

#ifdef DEBUG
	cout << "fxvector::ctor: start="<<(uint32_t)(start)
			 <<", finish="<<(uint32_t)(finish)
			 <<", end_of_storage="<<(uint32_t)(end_of_storage)<<endl;
#endif
}

template<typename T>
fxvector<T>::fxvector(
	uint32_t initial_size)
:
	mmf_p(NULL),
	src(new char[initial_size]),
	start(reinterpret_cast<T*>(src)),
	finish(reinterpret_cast<T*>(src)),
	end_of_storage(reinterpret_cast<T*>(src+initial_size))
{

#ifdef DEBUG
	cout << "fxvector::ctor: start="<<(uint32_t)(start)
			 <<", finish="<<(uint32_t)(finish)
			 <<", end_of_storage="<<(uint32_t)(end_of_storage)<<endl;
#endif

}

template<typename T>
fxvector<T>::~fxvector()
{
#ifndef WIN32
	std::_Destroy(start, finish);
#else
	T*	_First = start;
	T*	_Last = finish;
	for (; _First != _Last; ++_First)
		_First->~T();
#endif

	if (mmf_p) {

#ifdef DEBUG
	cout << "fxvector::dtor: offset = "
			 << *reinterpret_cast<off_t*>(src) << endl;
#endif

		unmap();
		delete mmf_p;
	}
	else delete [] src;
}

template<typename T>
char * fxvector<T>::raw_copy(
	string const& s)
{
	return raw_copy(s.c_str (), s.length () + 1);
}

template<typename T>
char * fxvector<T>::raw_copy(
	char const* data,
	uint32_t length)
{
	// insure capacity
	uint32_t n = sizeof(T);
	uint32_t T_count = (length/n + (length%n?1:0));
	uint32_t aligned_length = n * T_count;
	//std::cout << TRACE<<" : [1] T_count = "<<T_count<<std::endl;
	//std::cout << TRACE<<" :     length = "<<length<<std::endl;
	//std::cout << TRACE<<" :     aligned_length = "<<aligned_length<<std::endl;
	//std::cout << TRACE<<" :     size = "<<size()<<std::endl;
	while (capacity()-size() < T_count) expand();

	// copy
	char* p = reinterpret_cast<char*>(finish);
	strncpy(p, data, length);
	memset(p+length, 0, aligned_length - length);

	//std::cout << TRACE<<" : [2] stored>> "<<string(p,0,length)<<endl;
	//std::cout << TRACE<<" :     finish = "<<finish<<std::endl;
	finish += T_count;
	//std::cout << TRACE<<" :     finish = "<<finish<<std::endl;

	// update mmfile
	if (mmf_p) {
		off_t* offset_p = reinterpret_cast<off_t*>(src);
		*offset_p += aligned_length;
		//std::cout << TRACE<<" : [3] *offset_p = "<<*offset_p<<std::endl;
	}
	return p;
}


template<typename T>
void * fxvector<T>::alloc(
	size_t length)
{
	// insure capacity
	uint32_t n = sizeof(T);
	size_t T_count = (length/n + (length%n?1:0));
	uint32_t aligned_length = n * T_count;
	while (capacity()-size() < T_count) expand();

	// alloc
	void* v = reinterpret_cast<void*>(finish);
	//finish += aligned_length;
	finish += T_count;

	// update mmfile
	if (mmf_p) {
		off_t* offset_p = reinterpret_cast<off_t*>(src);
		*offset_p += aligned_length;
	}
	return v;
}


/*___________________________________________________________________
|                                                                    |
|  fxvector equality comparison.
|    @param  x  A fxvector.
|    @param  y  A fxvector of the same type as x.
|    @return true iff the size and elements are equal.
|  This is an equivalence relation.  It is linear in the size of
|  the vectors.  fxvectors are considered equivalent if their sizes
|  are equal and if corresponding elements compare equal.
|____________________________________________________________________|*/

template<typename T>
inline bool operator==(fxvector<T> const& x, fxvector<T> const& y)
{
	return  x.size() == y.size() 
					&& std::equal(x.begin(), x.end(), y.begin());
}


template<typename T>
void fxvector<T>::clear()
{
	uint32_t n = size() * sizeof(value_type);
	uint32_t m = capacity() * sizeof(value_type);

	memset(src,0,n);

	if (mmf_p) {
		off_t* offset_p  = reinterpret_cast<off_t*>(src);
		*offset_p = sizeof(off_t);  
		start = reinterpret_cast<T*>(&src[sizeof(off_t)]);
	}
	else {
		start = reinterpret_cast<T*>(src);
	}

	finish = start;
	end_of_storage = reinterpret_cast<T*>(&src[m]);
}


// double the vector capacity
template<typename T>
void fxvector<T>::expand()
{
	uint32_t n = size() * sizeof(value_type);
	uint32_t m = capacity() * sizeof(value_type);

#ifdef DEBUG
	cout << "fxvector::expand: n="<<n<<", m="<<m<<endl;
	cout << "fxvector::expand: start="<<(uint32_t)(start)
			 <<", finish="<<(uint32_t)(finish)
			 <<", end_of_storage="<<(uint32_t)(end_of_storage)<<endl;
#endif

	if (mmf_p) {
		off_t offset = *reinterpret_cast<off_t*>(src);
		mmf_p->expand();
		src = mmf_p->get_data();
		off_t* offset_p = reinterpret_cast<off_t*>(src);
		*offset_p = offset;

#ifdef DEBUG
	cout << "fxvector::expand: offset = "
			 << *reinterpret_cast<off_t*>(src) << endl;
#endif

		// update vector state
		start = reinterpret_cast<T*>(src + sizeof(off_t));
		finish = reinterpret_cast<T*>(&src[*offset_p]);
		end_of_storage = reinterpret_cast<T*>(src + mmf_p->get_eofoff());
	}
	else {
		char* src0 = new char[m<<1];
		memcpy(src0,src,n);
		delete[] src;
		src = src0;

		// update vector state
		start = reinterpret_cast<T*>(src);
		finish = reinterpret_cast<T*>(&src[n]);
		end_of_storage = reinterpret_cast<T*>(&src[m<<1]);
	}

#ifdef DEBUG
	cout << "fxvector::expand: start="<<(uint32_t)(start)
			 <<", finish="<<(uint32_t)(finish)
			 <<", end_of_storage="<<(uint32_t)(end_of_storage)<<endl;
#endif

}


template<typename T>
void fxvector<T>::unmap()
{
	if (mmf_p) mmf_p->unmap();
}


} // namespace xqp
#endif /* XQP_FXVECTOR_H */
