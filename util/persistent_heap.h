/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: persistent_heap.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *
 */

#ifndef XQP_PHEAP_H
#define XQP_PHEAP_H

#include <string>
#include "Exception.h"

/*
**	implementation of a persistent string heap using
**	memory-mapped files.
**
*/

namespace xqp {

class persistent_heap
{
public:  // types
	typedef class persistent_heap_iterator
	{
		const char* _begin;
		const char* _end;
		char* current;
		persistent_heap* parent;

	public:
		persistent_heap_iterator(persistent_heap* ph) 
		:
			_begin(&ph->data[8]),
			_end(&ph->data[ph->size()]),
			current((char*)_begin),
			parent(ph)
		{
		}

		~persistent_heap_iterator()
		{
		}

		const char* operator++()
		{
			uint32_t len = strlen(current);
			const char* result = current;
			current += (len+1);
			return result;
		}

		const char* operator*() const
		{
			return current;
		}

		bool done() const
		{
			return current >= _end;
		}
	} const_iterator;


	typedef class bounded_persistent_heap_iterator
	{
		const char* _begin;
		const char* _end;
		char* current;
		persistent_heap* parent;
		uint32_t cursor;
		uint32_t cursor_limit;

	public:
		bounded_persistent_heap_iterator(
			persistent_heap* ph,
			uint32_t start,
			uint32_t count) 
		:
			_begin(&ph->data[8]),
			_end(&ph->data[ph->size()]),
			current((char*)_begin),
			parent(ph),
			cursor(0),
			cursor_limit(start+count)
		{
			for (uint32_t n=0; n<start && !done(); ++n) ++(*this);
		}

		~bounded_persistent_heap_iterator()
		{
		}

		const char* operator++()
		{
			uint32_t len = strlen(current);
			const char* result = current;
			current += (len+1);
			cursor++;
			return result;
		}

		const char* operator*() const
		{
			return current;
		}

		bool done() const
		{
			return (cursor>=cursor_limit || current>=_end);
		}
	} const_bounded_iterator;
	

public:  // state
	std::string path;    // path name of backing file
	int fd;              // backing file id
	off_t eofoff;        // offset to eof
	off_t offset;        // offset to first free byte
	off_t* offsetp;      // offset to first free byte
	char* data;          // memory view of the data

	persistent_heap(const std::string& path);
	~persistent_heap();

public:  // heap interface
 /*
	**  
	**  Get a block of characters, placing into an array of given size.
 	*/
	void get(
		off_t id,               // byte id
		char* seg_buf,          // buffer into which to place block
		uint32_t seg_offset,    // offset for segment into buffer
		uint32_t seg_maxlen)    // maximum output size, truncate if larger
	const;

 /*
	**
	**	Insert a new block of characters.
	**	@returns byte offset of the entry.
	**	@comment Occasionally expensive: doubling the heap if needed.
	*/
	off_t put(
		const char* buf,        // buffer containing segment to put
		uint32_t seg_offset,    // starting offset of segment in buffer
		uint32_t seg_len);      // length of segment

 /*
	**
	**	Replace a block
	*/
	void put(
		off_t id,								// offset to heap (replace location)
		const char* buf,        // buffer containing segment to put
		uint32_t seg_offset,    // starting offset of segment in buffer
		uint32_t seg_len);      // length of segment

 /*
	**
	**	Return the length of the string at offset 'id'
	*/
	uint32_t getLength(off_t id) const;
	uint32_t get_length(off_t id) const;


protected:
	/*
	**	intialize the heap
	*/
	void initialize();

	/*
	**	double the heap
	*/
	void expand();

	/*
	**	unmap the underlying file
	*/
	void unmap();

public:
	/*
	**	@return	current allocated size
	*/
	uint64_t capacity() const { return eofoff; }

	/*
	**	@return	current size in bytes
	*/
	uint64_t size() const { return *offsetp - 8; }

	/*
	**	@return persistent_heap_iterator for this heap
	*/
	const_iterator iterator() { return persistent_heap_iterator(this); }

	/*
	**	@return bounded_persistent_heap_iterator for this heap
	*/
	const_bounded_iterator bounded_iterator(uint32_t start, uint32_t count)
	{
		return bounded_persistent_heap_iterator(this, start, count);
	}

};

}  /* namespace xqp */
#endif  /* XQP_PERSISTENT_HEAP_H */
