/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *	$Id: spectrum.h,v 1.3 2006/10/13 06:53:30 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#ifndef _XQP_SPECTRUM_H_
#define _XQP_SPECTRUM_H_

#include <string>
#include <utility>
#include <vector>

#include "../util/hashmap.h"
#include "../util/fxarray.h"
#include "../util/fxvector.h"


namespace xqp {


struct blockid
{
	uint32_t lgsz : 5;
	off_t offset : 59;
	blockid() : lgsz(0), offset(0) {}
	blockid(uint32_t z, off_t o) : lgsz(z), offset(o) {}
	~blockid() {}
	friend std::ostream& operator<<(std::ostream&, const blockid&);
	friend bool operator==(const blockid&, const blockid&);
	friend bool operator!=(const blockid&, const blockid&);
};



struct block
{
	blockid id;
	char* data;

	// empty block
	block();

	// new block at file eofoff
	block(int fd, uint32_t sz, bool initp) throw (xqp_exception);

	// new block at offset in file
	block(int fd, off_t offset, uint32_t sz) throw (xqp_exception);

	// new block at offset in (mapped) array
	block(char* data, off_t offset, uint32_t sz) throw (xqp_exception);

	~block();

	void unmap(uint32_t sz);
	void unmap();

	block& operator=(const block& b)
	{
		id = b.id;
		data = b.data;
		return *this;
	}

	// return: ceil(log_2(len)), (i.e.) lg(2)=1, lg(3)=2, etc.
	static uint32_t lg(uint32_t n);

	// use this only with powers of 2
	static uint32_t lg0(uint32_t n);

};



class bucket
{
public:
	std::string path;			// underlying file name
	uint32_t lgsz;				// lg(block size)
	uint32_t sz;					// 2^(lgsz)

	// freelist[0] = top = next empty slot
	fxvector<off_t> freelist;
	off_t* end_p;					// pointer to parent copy of:
	off_t  end;						// (local) offset to first unused block
	uint32_t free_count;  // count of free blocks

public:
	bucket(
		const string& path,
		uint32_t lgsz,
		off_t end,
		off_t* end_p);
	virtual ~bucket();

public:	// manipulators
	virtual block front() = 0; 						// unlink front of free list
	virtual block get(blockid id) = 0;		// return the block at given id 
	virtual block get(blockid id) const = 0;		// return the block at given id 
	virtual void free(blockid)  = 0;			// unmap block and push block id on free list
	virtual void pushfree(blockid)  = 0;	// push block id free list

public: // free list housekeeping
	void displayFreelist();
	void expand_freelist();

};



// memory-map entire file (small blocks)
class file_mapped_bucket : public bucket
{
public:
	int fd;						// mapped file descriptor
	char* data;				// pointer to first byte
	off_t eofoff;			// end of allocated storage


public:	// bucket base interface
	file_mapped_bucket(
		const string& path,
		uint32_t lgsz,
		off_t end,
		off_t* end_p);

	~file_mapped_bucket();

public: // manipulators
	// unmap block and push to free list
	void free(blockid);

	// push block on free list
	void pushfree(blockid);

	// unlink and return front of free list
	block front();

	// return the block at given offset,
	block get(blockid id);
	block get(blockid id) const;


protected:	// implementation methods
	// double backing file
	void expand(bool init);

	// release file map
	void unmap();

};



// memory-map/unmap each block (big blocks)
class block_mapped_bucket : public bucket
{
public:
	int fd;			// underlying file descriptor

public:
	// construct bucket from non-empty file
	block_mapped_bucket(
		const std::string& path,
		uint32_t lgsz,
		off_t end,
		off_t* end_p);

	~block_mapped_bucket();

public: // manipulators
	// unmap block and push block id on free list
	void free(blockid);

	// push block id on free list
	void pushfree(blockid);

	// unlink and return front of free list
	block front();

	// return the block at given offset,
	block get(blockid id);
	block get(blockid id) const;

};



// multi-bucket mmap-based block file system
class spectrum
{
protected:	// state

	std::string path;
	uint32_t lgmin;								// minimum lg(block size)
	uint32_t lgmax;								// maximum lg(block size)
	uint32_t lgbreak;							// bucket_index < lgbreak => file mapped
	std::vector<bucket*> buckv;		// blocks by lg size
	fxvector<off_t> endv;					// bucket end offset vector

public:	// ctor,dtor

	spectrum(const std::string& path,  
		uint32_t lgmin,			// initial min block size = 2^min
		uint32_t lgmax, 		// initial max block size = 2^max
		uint32_t lgbreak);	// bucket_index < lgbreak => file mapped

	~spectrum();

public:	// manipulators

	uint32_t get_lgbreak() const { return lgbreak; }
	uint32_t get_lgmin() const { return lgmin; }
	uint32_t get_lgmax() const { return lgmax; }
	bucket* get_bucket(uint32_t lgsz) { return buckv[lgsz]; }


public:	// store interface

	int get(
		blockid			input_id,
		char*				output_buf,
		uint32_t		output_offset,
		uint32_t		output_maxlen);

	int get(
		blockid			input_id,
		char*				output_buffer,
		uint32_t		output_offset,
		uint32_t		output_maxlen) const;

	blockid put(
		const char* input_buffer,
		uint32_t 		input_offset,
		uint32_t		input_length);

	blockid update(
		blockid 		input_id,
		char const*	input_buf,
		uint32_t		input_offset,
		uint32_t		input_length);


private:

	// poke value, (e.g.) length, to index block
	void poke(uint32_t val, unsigned char* p);

	// Return front of a given free list
	blockid get_front(uint32_t lgsz);

	// Return a block to the free list.
	void free(blockid);

};

}	/* namespace xqp */
#endif	/* _PV_SPECTRUM_H_ */
