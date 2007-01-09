/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: spectrum.cpp,v 1.5 2006/11/01 17:56:20 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 Paul Pedersen.  All Rights Reserved.
 *
 *	Author:  Paul Pedersen
 *
 */

#include "spectrum.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string>
#include <sstream>
#include <iostream>

#include "../../util/Assert.h"
#include "../../util/coder.h"
#include "../../util/xqpexception.h"

using namespace std;
namespace xqp {


#define UINT_LEN				sizeof(uint32_t)
#define HIGHBIT					((unsigned char)0x80)
#define SYSBLOCK				4096
#define PAGE_SZ					4096
#define PAGE_LGSZ				12


#define BAD_BLOCK throw xqpexception(__FUNCTION__, "Bad block");


// return: ceil(log_2(len)), (i.e.) lg(2)=1, lg(3)=2, etc.
static inline uint32_t lg(uint32_t len)
{
	uint32_t l = 0;
	uint32_t n = len;
	while ( n>>=1 ) { ++l; }
	int c = (len & (1<<l)-1) ? 1 : 0;
	return l+c;
}

// only use this with powers of 2
static inline uint32_t lg0(uint32_t len)
{
	uint32_t l = 0;
	uint32_t n = len;
	while ( n>>=1 ) { ++l; }
	return l;
}



////////////////////////////////
//	block implementations 
////////////////////////////////

/*______________________________________________________________________
|  
|  o a block has a size, some power of 2,
|  o sizes 2^9-2^31 (512B-2GB), 31-9+1=23 'buckets'
|  o a block is 'active' or 'free'
|  o each active block contains a 'segment' of active data
|  o the segment is defined by (offset,length)
|		 _________________________    ___
|   |      32bit offset      -|-.  |  
|		|-------------------------| |  |
|		|      in-use area        | |  |
|		|_ _ _ _ _ _ _ _ _ _ _ _ _| |  |k
|		|                         <-'  2
|		|       free area         |    |
|		|                         |    |
|		|                         |    |
|		|_________________________|   ___
|		
|  o there is a FREE header = offset to first free block
|  o initialize the buckets with at least one empty block
|  o blockid layout:
|  
|		 63:59 58								   :									     0
|		 ___________________________________________________ 
|		| lgsz |                offset		                  | 
|		|______|____________________________________________| 
|  
|_______________________________________________________________________*/


// create a new block at end of file
// ---------------------------------
block::block(int fd, uint32_t sz, bool init) throw (xqpexception)
:
	id(xqp::lg(sz),0)
{
	char buf[1] = { '\0' };
	off_t eofoff;

	// create a hole in the file, which reads as 0's.
	if ((eofoff = lseek(fd, 0, SEEK_END)) == -1) {
		ostringstream oss;
		oss << "lseek to EOF ["<<fd<<"] failed with error: " << strerror(errno);
		throw xqpexception("block::ctor[01]", oss.str());
	}

	uint32_t sz0 = (sz < PAGE_SZ) ? PAGE_SZ : sz;
	if (lseek(fd, sz0-1, SEEK_END) == -1) {  // -1 here
		ostringstream oss;
		oss << "lseek to EOF+" << sz0
				<< " failed with error: " << strerror(errno);
		throw xqpexception("block::ctor[01]", oss.str());
	}
	if (write(fd, buf, 1) == -1) {					// +1 here
		ostringstream oss;
		oss << "write to EOF+" << sz0
				<< " failed with error: " << strerror(errno);
		throw xqpexception("block::ctor[01]", oss.str());
	}
	
	int prot = PROT_READ|PROT_WRITE;
	int flags = MAP_FILE|MAP_SHARED;
	if ((data = (char*)mmap(0,sz0,prot,flags,fd,eofoff))==MAP_FAILED)
	{
		ostringstream oss;
		oss << "mmap failed with error: " << strerror(errno);
		throw xqpexception("block::ctor[01]", oss.str());
	}
	if (init) { memset(data, 0, sz0); } 
	id.offset = eofoff;
}


// map a block at a given file offset
// ----------------------------------
block::block(int fd, off_t offset, uint32_t sz) throw (xqpexception)
:
	id(xqp::lg0(sz),offset)
{
	off_t off0  = offset;
	off_t off1  = offset;
	off_t delta = 0;

	if (sz<PAGE_SZ) {												// round up to page size
		off0  = off1&0xfffffffffffff000LL;		// (parametrize this!!)	
		delta = (off1 - off0);								// offset within page
	}

	int prot  = PROT_READ|PROT_WRITE;
	int flags = MAP_FILE|MAP_SHARED;
	if ((data = (char*)mmap(0,sz,prot,flags,fd,off0))==MAP_FAILED) {
		ostringstream oss;
		oss << "mmap failed with error: " << strerror(errno);
		throw xqpexception("block:ctor[02]", oss.str());
	}

	data += delta;
}


// map a block at a given file offset
// ----------------------------------
block::block(char* data0, off_t offset, uint32_t sz) throw (xqpexception)
:
	id(xqp::lg0(sz),offset)
{
	data = data0+offset;
}


// create an empty block
// ---------------------
block::block() : id(), data(0)
{
}


// deallocate the block
// --------------------
block::~block()
{
}


// unmap the block
// ---------------
void block::unmap(uint32_t sz)
{
	uint32_t sz0 = (sz < PAGE_SZ) ? PAGE_SZ : sz;
	char* data0 = (char*)(((uint32_t)data)&0xfffff000);

/*
	if (msync(data0, sz0, MS_SYNC)==-1) {
		ostringstream oss;
		oss << "msync failed with error: " << strerror(errno);
		throw xqpexception("block:unmap", oss.str());
	}
*/
	if (munmap(data0, sz0)==-1) {
		ostringstream oss;
		oss << "munmap failed with error: " << strerror(errno);
		throw xqpexception("block:unmap", oss.str());
	}
}


void block::unmap()
{
	unmap(1<<id.lgsz);
}


ostream& operator<<(ostream& os, const blockid& id)
{
	return os << id.lgsz << "." << id.offset;
}


bool operator==(const blockid& id1, const blockid& id2)
{
	return (id1.lgsz==id2.lgsz && id1.offset==id2.offset);
}


bool operator!=(const blockid& id1, const blockid& id2)
{
	return (id1.lgsz!=id2.lgsz || id1.offset!=id2.offset);
}



////////////////////////////////
//	bucket implementations 
////////////////////////////////

// create bucket from file
//------------------------
bucket::bucket(
	const string& _path,
	uint32_t _lgsz,
	off_t    _end,
	off_t*   _end_p)
:
	path(_path),
	lgsz(_lgsz),
	sz(1<<_lgsz),
	freelist(_path+".fl"),
	end_p(_end_p),
	end(_end)
{
}


bucket::~bucket()
{
}


void bucket::displayFreelist()
{
	uint32_t top = (uint32_t)freelist[0];
	for (uint32_t a=1; a<top; a++) {
		off_t offset = freelist[a];
		cout << "(" << a << ") " << lgsz << '.' << offset << endl;
	}
}


void bucket::expand_freelist()
{
	for (uint32_t n=0; n<4096; ++n) {
		freelist.push_back(0);
	}
}




////////////////////////////////
//	file-mapped bucket 
////////////////////////////////

// create file_mapped_bucket from file
//------------------------------------
file_mapped_bucket::file_mapped_bucket(
	const string& _path,
	uint32_t  _lgsz,
	off_t  _end,
	off_t* _end_p)
:
	bucket(_path,_lgsz,_end,_end_p)
{
  // open the backing file
  fd = open(path.c_str(), O_RDWR|O_CREAT, S_IRUSR|S_IWUSR);
  if (fd < 0 ) {
    ostringstream oerr;
    oerr<<"open failed on '"<<path<<"' with error: "<<strerror(errno);
    throw xqpexception("file_mapped_bucket::ctor", oerr.str());
  }

  // allocate the entire file
  if ((eofoff = lseek(fd, 0, SEEK_END))==-1) {
    ostringstream oerr;
    oerr<<"lseek to EOF failed on '"<<path<<"' with error: "<<strerror(errno);
    throw xqpexception("file_mapped_bucket::ctor", oerr.str());
  }

  if (eofoff==0) {
		// initialize empty bucket
	  if (lseek(fd, sz-1, SEEK_END)==-1) { // Note: sz-1
	    ostringstream oerr;
	    oerr << "lseek to "<<(sz-1)<< " failed with error: " << strerror(errno);
	    throw xqpexception("file_mapped_bucket::ctor", oerr.str());
	  }
	
	  // write one byte to create the new allocation
	  char buf[1] = { '\0' };
	  if (write(fd, buf, 1) == -1) {       // Get back the -1
	    ostringstream oerr;
	    oerr << "write to "<<(sz-1)<<" failed with error: " << strerror(errno);
	    throw xqpexception("file_mapped_bucket::ctor", oerr.str());
	  }
		eofoff = sz;
		end = 0;
		*end_p = end;
	}
	
  // map the existing file
	int prot  = PROT_READ|PROT_WRITE;
	int flags = MAP_FILE|MAP_SHARED;
	if ((data = (char*)mmap(0,eofoff,prot,flags,fd,0))==MAP_FAILED) {
		ostringstream oerr;
		oerr<<"mmap failed on '"<<path<<"' with error: "<<strerror(errno);
		throw xqpexception("file_mapped_bucket::ctor", oerr.str());
	}

	if (freelist.size()==0) freelist.push_back(1);

}


file_mapped_bucket::~file_mapped_bucket()
{
}


/*________________________________________
|
|  freelist structure:
|
|  [0] [1] [2] [3] [4] ...[top-1]  [top] [top+1] ..
|  top  x0  x2  x2  x3    x(top-2) empty  empty  ..
|
|__________________________________________*/

inline block file_mapped_bucket::front()
{
	uint32_t top = (uint32_t)freelist[0];

	if (top > 1) {		// freelist non-empty
		off_t offset = freelist[top-1];
		block blk(data, offset, sz);
		memset(blk.data,0,sz);
		freelist[0] = top-1;
		return blk;
	}
	else {								// allocate new free block
		if (end+sz >= eofoff) expand(false);
		block blk(data, end, sz);
		memset(blk.data,0,sz);
		end += sz;
		*end_p = end;
		return blk;
	}
}


inline block file_mapped_bucket::get(blockid id)
{
	return block(data, id.offset, sz);
}


inline block file_mapped_bucket::get(blockid id) const
{
	return block(data, id.offset, sz);
}


void file_mapped_bucket::pushfree(struct blockid id)
{
	uint32_t top = (uint32_t)freelist[0];
	if (top>=freelist.size()) expand_freelist();
	freelist[top] = id.offset;
	freelist[0] = top+1;
}


void file_mapped_bucket::free(struct blockid id)
{
	pushfree(id);
}



// double the backing file and remap
void file_mapped_bucket::expand(bool init)
{
	// release current map
  unmap();

  // double past the end
  if (lseek(fd, eofoff-1, SEEK_END)==-1) {  // Note the -1
    ostringstream oerr;
    oerr << "lseek to 2*EOF failed with error: " << strerror(errno);
    throw xqpexception("file_mapped_bucket::expand", oerr.str());
  }

  // write one byte: creates hole equal in size to original file
  char buf[1] = { '\0' };
  if (write(fd, buf, 1) == -1) {            // Get back +1
    ostringstream oerr;
    oerr << "write to 2*EOF failed with error: " << strerror(errno);
    throw xqpexception("file_mapped_bucket::expand", oerr.str());
  }

  // remap the file
  eofoff <<= 1;
	int prot = PROT_READ|PROT_WRITE;
	int flags = MAP_FILE|MAP_SHARED;
  if ((data = (char*)mmap(0,eofoff,prot,flags,fd,0))==MAP_FAILED) {
    ostringstream oerr;
    oerr << "mmap failed with error: " << strerror(errno);
    throw xqpexception("file_mapped_bucket::expand", oerr.str());
  }

	// 'end' is a zero-based offset and doesn't change.

}


void file_mapped_bucket::unmap()
{
  if (msync(data, eofoff, MS_ASYNC)==-1) {
    ostringstream oerr;
    oerr << "msync failed with error: " << strerror(errno) << endl;
    throw xqpexception("file_mapped_bucket::unmap", oerr.str());
  }
  if (munmap(data, eofoff)==-1) {
    ostringstream oerr;
    oerr << "munmap failed with error: " << strerror(errno) << endl;
    throw xqpexception("file_mapped_bucket::unmap", oerr.str());
  }
}



////////////////////////////////
//	block_mapped bucket 
////////////////////////////////

// create bucket from file
//------------------------

block_mapped_bucket::block_mapped_bucket(
	const string& _path,
	uint32_t  _lgsz,
	off_t  _end,
	off_t* _end_p)
:
	bucket(_path,_lgsz,_end,_end_p)
{
	// open file for blocks of size 2^n
	if ((fd = open(_path.c_str(), O_RDWR|O_CREAT, S_IRUSR|S_IWUSR))<0) {
		ostringstream oss;
		oss <<"open("<<_path<<") failed: "<<strerror(errno)
				<<" >>check security,create directory";
		throw xqpexception(__FUNCTION__, oss.str());
	} 
	if (freelist.size()==0) freelist.push_back(1);
}


block_mapped_bucket::~block_mapped_bucket()
{
}


void block_mapped_bucket::free(struct blockid id)
{
	uint32_t sz = (1<<id.lgsz);
	block blk0 = get(id);
	memset(blk0.data, 0, sz);
	uint32_t top = (uint32_t)freelist[0];
	if (top>=freelist.size()) expand_freelist();
	freelist[top] = id.offset;
	freelist[0] = top+1;
	blk0.unmap(sz);
}


void block_mapped_bucket::pushfree(struct blockid id)
{
	uint32_t top = (uint32_t)freelist[0];
	if (top>=freelist.size()) expand_freelist();
	freelist[top] = id.offset;
	freelist[0] = top+1;
}


/*________________________________________
|
|  freelist structure:
|
|  [0] [1] [2] [3] [4] ...[top-1]  [top] [top+1] ..
|  top  x0  x2  x2  x3    x(top-2) empty  empty  ..
|
|__________________________________________*/


inline block block_mapped_bucket::front()
{
	uint32_t top = (uint32_t)freelist[0];

	if (end%PAGE_SZ!=0) {	// more small blocks in last page
		//cout << "block_mapped_bucket::"<<__FUNCTION__<<": small blocks in page: end = "<<end<<endl;
		block blk(fd, end, sz);
		memset(blk.data,0,sz);
		end += sz;
		*end_p = end;
		//cout << "block_mapped_bucket::"<<__FUNCTION__<<": small blocks in page: end = "<<end<<endl;
		return blk;
	}
	else if (top > 1) {		// freelist non-empty
		//cout << "block_mapped_bucket::"<<__FUNCTION__<<": freelist non-empty: offset = "<<offset<<endl;
		off_t offset = freelist[top-1];
		block blk(fd, offset, sz);
		memset(blk.data,0,sz);
		freelist[0] = top-1;
		return blk;
	}
	else {								// allocate new free block
		//cout << "block_mapped_bucket::"<<__FUNCTION__<<": allocate new block: end = "<<end<<endl;
		block blk(fd, sz, true);
		end += sz;
		*end_p = end;
		//cout << "block_mapped_bucket::"<<__FUNCTION__<<": allocate new block: end = "<<end<<endl;
		return blk;
	}
}


inline block block_mapped_bucket::get(blockid id)
{
	return block(fd, id.offset, sz);
}

inline block block_mapped_bucket::get(blockid id) const
{
	return block(fd, id.offset, sz);
}



////////////////////////////////
//	spectrum 
////////////////////////////////

spectrum::spectrum(
	const string& _path,
	uint32_t _lgmin,
	uint32_t _lgmax,
	uint32_t _lgbreak)
:
	path(	_path),
	lgmin( _lgmin),
	lgmax( _lgmax),
	lgbreak(_lgbreak),
	endv(	_path+"/endv")		// endv[n] = offset to first unused byte
{
	for (uint32_t lgsz=0; lgsz<lgmin; ++lgsz) {
		buckv.push_back((bucket*)NULL);
	}
	for (uint32_t lgsz=lgmin; lgsz<lgmax; ++lgsz) {
		ostringstream oss;
		string pad(lgsz<10 ? "00" : lgsz<100 ? "0" : "");
		oss<<path<<"/"<<pad<<lgsz<<".rep";
		string fname = oss.str(); // "009.rep", "010.rep", "011.rep", etc..

		while (lgsz >= endv.size()) endv.push_back(0);// includes endv[n] = 0, uninitialized

		bucket* buck_p;
		if (lgsz<lgbreak) {
			buck_p = new file_mapped_bucket(fname,lgsz,endv[lgsz],&endv[lgsz]);
		} else {
			buck_p = new block_mapped_bucket(fname,lgsz,endv[lgsz],&endv[lgsz]);
		}
		buckv.push_back(buck_p);
	}
}


spectrum::~spectrum()
{
	vector<bucket*>::const_iterator it = buckv.begin();
	for (; it!=buckv.end(); ++it) {
		bucket* buck_p = *it;
		if (buck_p != NULL) delete buck_p;
	}
	endv.unmap();
}


// insert a new block of bytes
// ---------------------------
blockid spectrum::put(
	char const*	input_buffer,	
	uint32_t		input_offset,
	uint32_t		input_length)
{
	uint32_t lgsz = lg(input_length+UINT_LEN);
	if (lgsz < lgmin) lgsz = lgmin;
	Assert<bad_arg>(lgmin<=lgsz && lgsz<=lgmax, "spectrum::put(char*) [lgsz]");
	bucket* buck_p = buckv[lgsz];

	// transfer data to next available free block
	block blk = buck_p->front();
	uint32_t* len_p = reinterpret_cast<uint32_t*>(blk.data);
	*len_p = input_length;
	memcpy(&blk.data[UINT_LEN], &input_buffer[input_offset], input_length);
	if (blk.id.lgsz>=lgbreak) blk.unmap();
	return blk.id;
}



// update block with new byte array
// --------------------------------
blockid	spectrum::update(
	blockid			input_id,
	const char*	input_buffer,
	uint32_t		input_offset,
	uint32_t		input_length)
{
	blockid id = input_id;
	Assert<bad_arg>(lgmin<=id.lgsz && id.lgsz<=lgmax,
									"spectrum::update(char*) [lgsz]");

	uint32_t lgsz = lg(input_length+UINT_LEN);
	if (id.lgsz==lgsz) { // rewrite block
		// fetch the bucket
		bucket* buck_p = buckv[lgsz];
		uint32_t sz = buck_p->sz;
		uint32_t available_size = (sz - UINT_LEN);

		if (input_length > available_size) BAD_BLOCK;

		// fetch the block, plug len
		block blk = buck_p->get(id);
		uint32_t* len_p = reinterpret_cast<uint32_t*>(blk.data);
		*len_p = input_length;

		// and overwrite
		memcpy(&blk.data[UINT_LEN], &input_buffer[input_offset], input_length);
		if (blk.id.lgsz>=lgbreak) blk.unmap();
		return id;
	}
	else {  // insert new block, free old block
		blockid new_id = put(input_buffer, input_offset, input_length);
		bucket* buck_p = buckv[id.lgsz];
		buck_p->free(id);
		return new_id;
	}
}



inline void spectrum::poke(uint32_t val, unsigned char* p0)
{
	unsigned char ca = (val>>24) & (uint32_t)0xff;
	unsigned char cb = (val>>16) & (uint32_t)0xff;
	unsigned char cc = (val>>8 ) & (uint32_t)0xff;
	unsigned char cd = (val		 ) & (uint32_t)0xff;
	*p0++ = ca;
	*p0++ = cb;
	*p0++ = cc;
	*p0++ = cd;
}



// return front block
// ------------------
blockid spectrum::get_front(
	uint32_t lgsz)
{
	return buckv[lgsz]->front().id;
}



// get block to char buffer
// ------------------------
int spectrum::get(
	blockid input_id,
	char*			output_buffer,	
	uint32_t	output_offset,
	uint32_t	output_maxlen)
{
	blockid id = input_id;
	Assert<bad_arg>(lgmin<=id.lgsz && id.lgsz<=lgmax,
									"spectrum::get(char*): [id.lgsz]");

	// find the bucket for this id
	bucket* buck_p = buckv[id.lgsz];
	uint32_t sz = buck_p->sz;

	// find the block within the bucket
	block blk = buck_p->get(id);
	uint32_t len = *reinterpret_cast<uint32_t*>(blk.data);
	if (len > sz) {
		if (blk.id.lgsz>=lgbreak) blk.unmap();
		BAD_BLOCK;
	}

	// transfer the data
	if (output_maxlen < len) len = output_maxlen;
	memcpy(&output_buffer[output_offset], &blk.data[UINT_LEN], len);
	if (blk.id.lgsz>=lgbreak) blk.unmap();
	return len;
}



int spectrum::get(
	blockid 		input_id,
	char*				output_buffer,
	uint32_t		output_offset,
	uint32_t		output_maxlen)
const
{
	blockid id = input_id;
	Assert<bad_arg>(lgmin<=input_id.lgsz && id.lgsz<=lgmax,
									"spectrum::get(char*): [id.lgsz]");

	// find the bucket for this id
	bucket* buck_p = buckv[id.lgsz];
	uint32_t sz = buck_p->sz;

	// find the block within the bucket
	block blk = buck_p->get(id);
	uint32_t len = *reinterpret_cast<uint32_t*>(blk.data);
	if (len > sz) {
		if (blk.id.lgsz>=lgbreak) blk.unmap();
		BAD_BLOCK;
	}

	// transfer the data
	if (output_maxlen < len) len = output_maxlen;
	memcpy(&output_buffer[output_offset], &blk.data[UINT_LEN], len);
	if (blk.id.lgsz>=lgbreak) blk.unmap();
	return len;
}


// free a block
// ------------
void spectrum::free(blockid id)
{
	Assert<bad_arg>(lgmin<=id.lgsz && id.lgsz<=lgmax,
									"spectrum::free(blockid): [id.lgsz]");
	bucket* buck_p = buckv[id.lgsz];
	buck_p->free(id);
}


}	/* namespace xqp */
