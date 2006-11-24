/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: charheap.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *
 */

#ifndef XQP_CHARHEAP_H
#define XQP_CHARHEAP_H

#include "xqpexception.h"


namespace xqp {


/*______________________________________________________________________

	______________________________________________________________________*/

class charheap
{

public:  // iterator 

  typedef class charheap_iterator
  {
    char const* _begin;
    char const* _end;
    char * current;
    charheap const* parent;

  public:	// ctor,dtor
    charheap_iterator(charheap * ch, uint32_t initial_offset);
    ~charheap_iterator();

	public:	// iterator interface
    char const* operator++();
    char const* operator*() const;

		friend bool operator!=(charheap_iterator const&, charheap_iterator const&);

  } const_iterator;

	const_iterator begin();
	const_iterator end();


public:	// state
	char * data;
  off_t eofoff;        // offset to eof = data array sentinel
  off_t offset;        // offset to first free byte

public:	// ctor,dtor
  charheap(uint32_t initial_size);
  ~charheap();

public:  // heap interface
	/**
	 *	Get a block of bytes, placing into given output array.
	 */
  void get(
    off_t id,								// byte id
    char * seg_buf,					// buffer into which to place block
    uint32_t seg_offset,		// offset for segment into buffer
    uint32_t seg_maxlen)		// maximum output size, truncate if larger
  const
	throw (xqp::xqpexception);

	/**
   *	Insert a new block of characters.
	 *
   *	@returns the byte offset of the entry.
   *	@note occasionally expensive, doubling the heap if needed.
	 */
  off_t put(
    char const* buf,				// buffer containing segment to put
    uint32_t seg_offset,		// starting offset of segment in buffer
    uint32_t seg_len)				// length of segment
	throw (xqp::xqpexception);

	/**
   *	Replace a block of characters in place.
	 */
  void replace(
		off_t id,								// offset to heap (replace location)
    char const* buf,        // buffer containing segment to put
    uint32_t seg_offset,    // starting offset of segment in buffer
    uint32_t seg_len)       // length of segment
	throw (xqp::xqpexception);

	/**
   *	Return the length of the string at offset 'id'.
	 *
	 *	@return length
	 */
  uint32_t get_length(off_t id) const;

protected:
	/**
   *	Intialize the heap.
	 */
  void initialize();

	/**
   *	double the heap
	 */
  void expand();

public:
	/**
   *	Return the heap capacity.
	 *
	 *	@return currently allocated capacity
	 */
  uint64_t capacity() const { return eofoff; }

	/**
	 *	Return the heap size.
	 *
   *	@return current heap size in bytes
	 */
  uint64_t size() const { return offset; }

};

}  /* namespace xqp */
#endif  /* XQP_CHARHEAP_H */
