/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: persistent_charheap.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *
 */

#ifndef XQP_PERSISTENT_CHARHEAP_H
#define XQP_PERSISTENT_CHARHEAP_H

#include <string>

/*______________________________________________________________________

	Implementation of a persistent character heap using
	memory-mapped files.
	______________________________________________________________________*/

namespace xqp {

class persistent_charheap
{

public:  // iterator 

	typedef class persistent_charheap_iterator
	{
		char const* _begin;
		char const* _end;
		char * current;
		persistent_charheap const* parent;

	public:	// ctor,dtor
		persistent_charheap_iterator(persistent_charheap const* pch, uint32_t offset);
		~persistent_charheap_iterator();

	public:	// iterator interface
		const char* operator++();
		const char* operator*() const;

		friend bool operator!=(persistent_charheap_iterator const& x,
		                       persistent_charheap_iterator const& y);

	} const_iterator;

	const_iterator begin();
	const_iterator end();


public:	// state
	std::string path;    // path name of backing file
	int fd;              // backing file id
	off_t eofoff;        // offset to eof
	off_t offset;        // offset to first free byte
	off_t * offset_p;    // &offset
	char * data;         // memory view of the data

public:	// ctor,dtor
	persistent_charheap(const std::string& path);
	~persistent_charheap();

public:	// heap interface
 /**
	*   
	*		Get a block of characters, placing into a given array.
 	*/
	void get(
		off_t id,               // byte id
		char* seg_buf,          // buffer into which to place block
		uint32_t seg_offset,    // offset for segment into buffer
		uint32_t seg_maxlen)    // maximum output size, truncate if larger
	const;

 /**
	*		Insert a new block of characters.
	*
	*		@returns byte offset of the entry.
	*		@comment occasionally expensive, doubling the charheap if needed.
	*/
	off_t put(
		char const* buf,        // buffer containing segment to put
		uint32_t seg_offset,    // starting offset of segment in buffer
		uint32_t seg_len);      // length of segment

 /**
	* 	Replace a block of characters in place.
	*/
	void put(
		off_t id,								// offset to charheap (replace location)
		char const* buf,       // buffer containing segment to put
		uint32_t seg_offset,    // starting offset of segment in buffer
		uint32_t seg_len);      // length of segment

 /**
	*		Return the length of the string at offset 'id'
	*
	*		@return length of char string at offset id
	*/
	uint32_t get_length(off_t id) const;


protected:
	/**
	*		Intialize charheap.
	*/
	void initialize();

	/**
	*		Double the charheap.
	*/
	void expand();

	/**
	*		Unmap the underlying file.
	*/
	void unmap();

public:
	/**
	*		Return heap allocated capacity.
	*
	*		@return	current allocated size
	*/
	uint64_t capacity() const { return eofoff - sizeof(off_t); }

	/**
	*		Return heap size.
	*
	*		@return	current size in bytes
	*/
	uint64_t size() const { return *offset_p - sizeof(off_t); }

};

}  /* namespace xqp */
#endif  /* XQP_PERSISTENT_CHARHEAP_H */
