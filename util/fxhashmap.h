/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: fxhashmap.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#ifndef XQP_FXHASHMAP_H
#define XQP_FXHASHMAP_H

#include "Assert.h"
#include "fxcharheap.h"
#include "fxarray.h"
#include "fxvector.h"
#include "hashfun.h"
#include "rchandle.h"

#include <stddef.h>
#include <stdlib.h>
#ifndef WIN32
	#include <strings.h>
#else
	#include "win32/compatib_defs.h"
#endif

#include <iostream>
#include <string>


using namespace std;
namespace xqp {

#define MAX_KEYLEN 65535
#define DEFAULT_DIR_SIZE 65536

/*_____________________________________________________________
|
|  hash map: string -> V
|______________________________________________________________*/

template<class V>
class fxhashmap
{
public:
	struct entry
	{
		off_t key;							// fxcharheap offset
		V val;									
		entry() {}
		entry(off_t k, V v) : key(k), val(v) {}
		entry(entry const& e) : key(e.key), val(e.val) {}
		entry& operator=(entry const& e) { key = e.key; val = e.val; return *this; }
		~entry() {}
	};

private:
	const string datapath;		// data files directory
	fxvector<entry>* vp;			// memory-mapped hash entry vector
	fxcharheap* hp;						// memory-mapped string heap
	fxarray<int>* dir;				// hash directory, indexes into v, -1 = empty
	uint32_t dsz;							// directory size
	uint32_t sz;							// count of hashed entries
	float ld;									// load factor, default = .6
	bool persistent;					// true <-> persistent map

public:
	// transient map
	fxhashmap(
		float ld = .6,							// default load factor
		uint32_t initial_size = DEFAULT_DIR_SIZE);

	// persistent map
	fxhashmap(
		const string& datapath,	// data files directrory
		float ld = .6,					// default load factor
		uint32_t initial_size = DEFAULT_DIR_SIZE);

	~fxhashmap();

public:
	uint32_t size() const { return sz; }			// return the number of hashed entries
	float load() const { return ld; }					// return the load factor
	uint32_t dirSize() const { return dsz; }	// return the current hash directory size
	void resize();														// double the hash directory

	V getentryVal(uint32_t n) const { return (*vp)[n].val; }
	void displayentry(uint32_t n) const;
	void displayEntries() const;
	void getentryKey(const entry&, char* buf, unsigned maxlen) const;
	void getentryKey(off_t entry_offset, char* buf, unsigned maxlen) const;
	typename fxvector<entry>::const_iterator begin() { return vp->begin(); }
	typename fxvector<entry>::const_iterator end() { return vp->end(); }

public:
	// find: true on match, (index = hash index)
	bool find(const string& key, uint32_t& index) const;
	bool find(const string& key) const;
	bool find(const char* key, uint32_t& index) const;

	// find key heap offset, true on match
	bool find_heap(const string& key, off_t& heap_offset) const;

	// copy hash entry to result, true on match
	bool get(const string& key, V& result) const;

	// copy hash entry to result, true on match
	bool get(const char* key, V& result) const;

	// add (key,val) entry to map, true on match
	bool put(const string& key, V val)
	throw (bad_arg);

	// add (key,val) entry to map, true on match
	bool put(const char* key, V val)
	throw (bad_arg);

	// add (key,val) entry to map, return offset
	off_t put0(const char* key, V val)
	throw (bad_arg);

	// the hash functions
	uint32_t h(const char*) const;
	uint32_t h(const string&) const;

public:
	class fxhashmap_iterator : public rcobject
	{
	public:
		fxhashmap_iterator(fxhashmap<V>* map) : m(map), i(m->begin()) {}
		~fxhashmap_iterator() {}
		bool done() const  { return i==m->end(); }
		void operator++()  { i++; }
		const entry* operator*() { return &*i; }
	private:
		fxhashmap<V>* m;
		typename fxvector<entry>::const_iterator i;
	};

	fxhashmap_iterator iterator() { return fxhashmap_iterator(this); }

};



// display one entry
template<class V>
inline void fxhashmap<V>::displayentry(uint32_t n) const
{
	char buf[MAX_KEYLEN+1];
	hp->get((*vp)[n].key,buf,0,MAX_KEYLEN);
	cout << "table["<<n<<"] = ("<<buf<<','<<(*vp)[n].val<<")\n";
}
	

// display all the entries
template<class V>
inline void fxhashmap<V>::displayEntries() const
{
	typename fxvector<entry>::const_iterator it;
	char buf[MAX_KEYLEN+1];
	for (it = vp->begin(); it!=vp->end(); it++) {
		const entry& e = *it;
		hp->get(e.key,buf,0,MAX_KEYLEN);
		cout << e.key << " -> " << string(buf,0,strlen(buf)) << ',' << e.val << endl;
	}
}


template<class V>
inline void fxhashmap<V>::getentryKey(
	const entry& e,
	char* buf,
	unsigned maxlen) const
{
	hp->get(e.key,buf,0,maxlen);
}


template<class V>
inline void fxhashmap<V>::getentryKey(
	off_t key,
	char* buf,
	unsigned maxlen) const
{
	hp->get(key,buf,0,maxlen);
}


// ctor creates and initializes all the memory mapped objects
template<class V>
fxhashmap<V>::fxhashmap(
	float    _factor,
	uint32_t _initial_size)
:
	vp(  new fxvector<entry> ),
	hp(  new fxcharheap( _initial_size )),
	dir( new fxarray<int>( _initial_size )),
	ld(_factor ),
	persistent(false)
{
	dsz = dir->size();
	sz  = vp->size();
	if (sz==0) dir->fill(-1);
}


template<class V>
fxhashmap<V>::fxhashmap(
	std::string const& _datapath,
	float    _factor,
	uint32_t _initial_size)
:
	datapath( _datapath ),
	vp(  new fxvector<entry>(_datapath+"keys" )),
	hp(  new fxcharheap( 		 _datapath+"heap", _initial_size )),
	dir( new fxarray<int>(	 _datapath+"dir", _initial_size )),
	ld(_factor ),
	persistent(true)
{
	dsz = dir->size();
	sz  = vp->size();
	if (sz==0) dir->fill(-1);
}


// dtor unmaps all the backing files
template<class V>
fxhashmap<V>::~fxhashmap()
{
	delete dir;
	delete vp;
	delete hp;
}


// double the hash directory, remap hash entry offsets
template<class V>
inline void fxhashmap<V>::resize()
{
	uint32_t dsz0;
	fxarray<int>* dir0;
	int oldindex;

	// create and initialize new table
	dsz0 = dsz;
	dsz <<= 1;

	dir0 = dir;
	if (persistent) {
		dir0->rename_backing_file(datapath+"dir0");
		dir = new fxarray<int>(datapath+"dir", dsz);
	}
	else {
		dir = new fxarray<int>(dsz);
	}
	dir->fill(-1);

	// rehash: place old entry offset in new hash location
	for (unsigned k = 0; k<dsz0; ++k) {
		oldindex = (*dir0)[k];
		if (oldindex>=0) {
			char buf[MAX_KEYLEN+1];
			hp->get((*vp)[oldindex].key,buf,0,MAX_KEYLEN);
			uint32_t h0 = h(buf);
			while (true) {
				if ((*dir)[h0]==-1) break;
				h0 = (h0 + 1) % dsz;
			}
			(*dir)[h0] = oldindex;
		}
	}

	// cleanup
	dir0->destroy();
}


// Store the hash location for a given key (or next available slot) 
// in 'h'.  Return true <=> key matched.
template<class V>
inline bool fxhashmap<V>::find(
	const string& key,
	uint32_t& hval) const
{
	char keybuf[key.length()+1];
	strcpy(keybuf,key.c_str());
	uint32_t h0 = h(key);
	bool result = false;
	while (true) {
		int x = (*dir)[h0];
		if (x==-1) { hval = h0; break; }	// -1 => empty
		entry& e = (*vp)[x];							// (id,val)
		char buf[MAX_KEYLEN+1];
		hp->get(e.key,buf,0,MAX_KEYLEN);	// string(id)
		if (strcasecmp(buf,keybuf)==0) {
			result = true;
			break;
		}
		h0 = (h0 + 1) % dir->size();			// collision
	}
	hval = h0;
	return result;
}

template<class V>
inline bool fxhashmap<V>::find(
	const string& key) const
{
	uint32_t index;
	return find(key,index);
}


// Store the hash location for a given key (or next available slot) 
// in 'index'.  Return true <=> key matched.   
template<class V>
inline bool fxhashmap<V>::find(
	const char* key,
	uint32_t& hval) const
{
	uint32_t h0 = h(key);
	bool result = false;
	while (true) {
		int x = (*dir)[h0];
		if (x==-1) { hval = h0; break; }	// -1 => empty
		entry& e = (*vp)[x];							// (id,val) 
		char buf[MAX_KEYLEN+1];
		hp->get(e.key,buf,0,MAX_KEYLEN);	// string(id)
		if (strcasecmp(buf,key)==0) {
			result = true;
			break;
		}
		h0 = (h0 + 1) % dir->size();			// collision
	}
	hval = h0;
	return result;
}


// Store the key heap offset for a given key in 'index'.
// Return true <=> key matched. 
template<class V>
inline bool fxhashmap<V>::find_heap(const string& key, off_t& heap_offset) const
{
	char keybuf[key.length()+1];
	strcpy(keybuf,key.c_str());
	uint32_t h0 = h(key);
	bool result = false;
	off_t offset = 0;
	while (true) {
		int x = (*dir)[h0];
		if (x==-1) break;							// -1 => empty
		entry& e = (*vp)[x];					// (id,val)
		char buf[MAX_KEYLEN+1];
		offset = e.key;
		hp->get(offset,buf,0,MAX_KEYLEN);		// string(id)
		if (strcasecmp(buf,keybuf)==0) { result = true; break; }
		h0 = (h0 + 1) % dir->size();	// collision
	}
	heap_offset = offset;
	return result;
}


// Copy hash value for a given key, return false if not found. 
template<class V>
inline bool fxhashmap<V>::get(const string& key, V& result) const
{
	uint32_t h0;
	if (find(key,h0)) {
		result = (*vp)[(*dir)[h0]].val;
		return true;
	}
	return false;
}


// Copy hash value for a given key, return false if not found. 
template<class V>
inline bool fxhashmap<V>::get(const char* key, V& result) const
{
	uint32_t h0;
	if (find(key,h0)) {
		result = (*vp)[(*dir)[h0]].val;
		return true;
	}
	return false;
}


// Store a new (key.val) pair in the map.
// Return true <=> key matched.
template<class V>
inline bool fxhashmap<V>::put(const string& key, V val)
throw (bad_arg)
{
	uint32_t n = key.length();
	if (n > MAX_KEYLEN) {
		throw bad_arg(__FUNCTION__, "key exceeds MAX_KEYLEN");
	}
	if (sz > dsz*ld) resize();
	uint32_t h0;
	if (find(key,h0)) {
		entry* e = &((*vp)[(*dir)[h0]]); 
		e->val = val;
		return true;
	} else {
		off_t id = hp->put(key.c_str(), 0, n);
		vp->push_back(entry(id,val));
		(*dir)[h0] = sz++;
		return false;
	}
}


// Store a new (key.val) pair in the map.
// Return true <=> key matched.
template<class V>
inline bool fxhashmap<V>::put(const char* key, V val) 
throw (bad_arg)
{
	uint32_t n = strlen(key);
	if (n > MAX_KEYLEN) {
		throw bad_arg(__FUNCTION__, "key exceeds MAX_KEYLEN");
	}
	if (sz > dsz*ld) resize();
	uint32_t h0;
	if (find(key,h0)) {
		entry* e = &((*vp)[(*dir)[h0]]); 
		e->val = val;
		return true;
	} else {
		off_t id = hp->put(key, 0, n);
		vp->push_back(entry(id,val));
		(*dir)[h0] = sz++;
		return false;
	}
}


// Store a new (key.val) pair in the map.
// Return key heap offset.
template<class V>
inline off_t fxhashmap<V>::put0(const char* key, V val) 
throw (bad_arg)
{
	uint32_t n = strlen(key);
	if (n > MAX_KEYLEN) {
		throw bad_arg(__FUNCTION__, "key exceeds MAX_KEYLEN");
	}
	if (sz > dsz*ld) resize();
	uint32_t h0;
	if (find(key,h0)) {
		entry* e = &((*vp)[(*dir)[h0]]); 
		e->val = val;
		return e->key;
	} else {
		off_t id = hp->put(key, 0, n);
		vp->push_back(entry(id,val));
		(*dir)[h0] = sz++;
		return id;
	}
}


// The hash functions
template<class V>
inline uint32_t fxhashmap<V>::h(const string& key) const
{
	return hashfun::h32(key) % dsz;
}


template<class V>
inline uint32_t fxhashmap<V>::h(const char* key) const
{
	return hashfun::h32(key, strlen(key), FNV_32_INIT) % dsz;
}



/*_____________________________________________________________
|                                
|  hash map: 32 bits -> V
|______________________________________________________________*/

template<class V>
class fxhash32map
{
public:
	struct entry
	{
		uint32_t key;
		V val;
		entry() {}
		entry(uint32_t k, V v) : key(k), val(v) {}
		entry(entry const& e) : key(e.key), val(e.val) {}
		entry& operator=(entry const& e) { key =  e.key; val = e.val; return *this; }
		~entry() {}
	};

private:
	const string datapath;		// data directory path
	fxvector<entry>* vp;			// memory-mapped hash entry vector
	fxarray<int>* dir;				// hash directory, indexes into v, -1 = empty
	unsigned dsz;							// directory size
	unsigned sz;							// count of hashed entries
	float ld;									// load factor, default = .6
	bool persistent;					// true <-> persistent map

public:
	// transient map
	fxhash32map(
		float ld = .6,					// default load factor
		unsigned depth = 10);		// initial depth of hash directory 10 => 1M

	// persistent map
	fxhash32map(
		const string& datapath,	// data directory path
		float ld = .6,					// default load factor
		unsigned depth = 10);		// initial depth of hash directory 10 => 1M

	~fxhash32map();

public:
	unsigned size() const     { return sz; }		// return the number of hashed entries
	float load() const        { return ld; }		// return the load factor
	unsigned dirSize() const { return dsz; }		// return the current hash directory size
	void resize();															// double the hash directory
	void displayEntries() const;
	typename fxvector<entry>::const_iterator begin() { return vp->begin(); }
	typename fxvector<entry>::const_iterator end() { return vp->end(); }
	typename fxvector<entry>::const_iterator begin() const { return vp->begin(); }
	typename fxvector<entry>::const_iterator end() const { return vp->end(); }

public:
	// find hash position(key), true on match
	bool find(uint32_t key, uint32_t& index) const;
	bool find(uint32_t key) const;	

	// copy hash entry to result, true on match
	bool get(uint32_t key, V& result) const;

	// add (key,val) entry to map, true on match
	bool put(uint32_t key, V val);

public:
	class fxhash32map_iterator : public rcobject
	{
	public:
		fxhash32map_iterator(fxhash32map<V>* map) : m(map), i(m->begin()) {}
		~fxhash32map_iterator() {}
		bool done() const  { return i==m->end(); }
		void operator++()  { i++; }
		const entry* operator*() { return &*i; }
	private:
		fxhash32map<V>* m;
		typename fxvector<entry>::const_iterator i;
	};

	class fxhash32map_const_iterator : public rcobject
	{
	public:
		fxhash32map_const_iterator(const fxhash32map<V>* map) : m(map), i(m->begin()) {}
		~fxhash32map_const_iterator() {}
		bool done() const  { return i==m->end(); }
		void operator++()  { i++; }
		const entry* operator*() { return &*i; }
	private:
		const fxhash32map<V>* m;
		typename fxvector<entry>::const_iterator i;
	};

	fxhash32map_iterator iterator() 
		{ return fxhash32map_iterator(this); }
	fxhash32map_const_iterator const_iterator() const
		{ return fxhash32map_const_iterator(this); }

};


// display all the entries
template<class V>
void fxhash32map<V>::displayEntries() const
{
	typename fxvector<entry>::const_iterator it;
	for (it = vp->begin(); it!=vp->end(); it++) {
		const entry& e = *it;
		cout <<e.key<<" -> "<<e.val<<endl;
	}
}


// construct transient map
template<class V>
fxhash32map<V>::fxhash32map(
	float    _factor,
	unsigned _depth)
:
	vp(  new fxvector<entry> ),
	dir( new fxarray<int>( _depth )),
	ld(_factor ),
	persistent(false)
{
	dsz = dir->size();
	sz  = vp->size();
	if (sz==0) dir->fill(-1);
} 


// construct persistent map
template<class V>
fxhash32map<V>::fxhash32map(
	const std::string& _datapath,
	float    _factor,
	unsigned _depth)
:
	datapath( _datapath ),
	vp(  new fxvector<entry>( _datapath+"keys" )),
	dir( new fxarray<int>( 		_datapath+"dir", _depth )),
	ld(_factor ),
	persistent(true)
{
	dsz = dir->size();
	sz  = vp->size();
	if (sz==0) dir->fill(-1);
} 

// dtor unmaps all the backing files
template<class V>
fxhash32map<V>::~fxhash32map()
{
	delete dir;
	delete vp;
}


// double the hash directory, remap hash entry offsets
template<class V>
inline void fxhash32map<V>::resize()
{
	fxarray<int>* dir0;
	int oldindex;

	// create and initialize new table
	dir0 = dir;
	if (persistent) {
		dir0->rename_backing_file(datapath+"dir0");
		dir = new fxarray<int>(datapath+"dir", dir0->size()<<1);
	}
	else {
		dir = new fxarray<int>(dir0->size()<<1);
	}
	dir->fill(-1);
	unsigned dsz0 = dir0->size();
	dsz  = dir->size();

	Assert<invariant>(dsz==dsz0*2, "fxhash32map::resize[01]");

	// rehash: place old entry offset in new hash location
	for (unsigned k = 0; k<dsz0; ++k) {
		oldindex = (*dir0)[k];
		if (oldindex>=0) {
			uint32_t h0 = (*vp)[oldindex].key % dsz0;
			while (true) {
				if ((*dir)[h0]==-1) break;
				h0 = (h0 + 1) % dsz;
			}
			(*dir)[h0] = oldindex;
		}
	}

	// cleanup
	dir0->destroy();
	//delete dir0;
}


// Store the hash location for a given key (or next available slot) 
// in 'index'.  Return true <=> key matched.
template<class V>
inline bool fxhash32map<V>::find(
	uint32_t key,
	uint32_t& hval) const
{
	uint32_t h0 = key % dsz;
	bool result = false;
	while (true) {
		int x = (*dir)[h0];
		if (x==-1) { hval = h0; break; }	// -1 => empty
		entry& e = (*vp)[x];							// (id,val)
		if (key==e.key) {
			result = true;
			break;
		}
		h0 = (h0 + 1) % dir->size();			// collision
	}
	hval = h0;
	return result;
}

template<class V>
inline bool fxhash32map<V>::find(uint32_t key) const
{
	uint32_t index;
	return find(key,index);
}


// Copy hash value for a given key, return false if not found. 
template<class V>
inline bool fxhash32map<V>::get(uint32_t key, V& result) const
{
	uint32_t h0;
	if (find(key,h0)) {
		result = (*vp)[(*dir)[h0]].val;
		return true;
	}
	return false;
}


// Store a new (key.val) pair in the map.
// Return true <=> key matched.
template<class V>
inline bool fxhash32map<V>::put(uint32_t key, V val)
{
	if (sz > dsz*ld) resize();
	uint32_t h0;
	if (find(key,h0)) {
		entry* e = &((*vp)[(*dir)[h0]]); 
		e->val = val;
		return true;
	} else {
		vp->push_back(entry(key,val));
		(*dir)[h0] = sz++;
		return false;
	}
}




/*_____________________________________________________________
|
|  hash map: 64 bits -> V
|______________________________________________________________*/

template<class V>
class fxhash64map
{
public:
	struct entry
	{
		uint64_t key;
		V val;
		entry() {}
		entry(uint64_t k, V v) : key(k), val(v) {}
		entry(entry const& e) : key(e.key), val(e.val) {}
		entry& operator=(entry const& e) { key = e.key; val = e.val; return *this; }
		~entry() {}
	};

private:
	const string datapath;		// data directory path
	fxvector<entry>* vp;			// memory-mapped hash entry vector
	fxarray<int>* dir;				// hash directory, indexes into v, -1 = empty
	unsigned dsz;							// directory size
	unsigned sz;							// count of hashed entries
	float ld;									// load factor, default = .6
	bool persistent;					// true <-> persistent map

public:
	// transient map
	fxhash64map(
		float ld = .6,					// default load factor
		unsigned depth = 6);		// initial depth of hash directory 6 => 64K

	// persistent map
	fxhash64map(
		const string& datapath,	// data directory path
		float ld = .6,					// default load factor
		unsigned depth = 6);		// initial depth of hash directory 6 => 64K

	~fxhash64map();

public:
	unsigned size() const     { return sz; }		// return the number of hashed entries
	float load() const        { return ld; }		// return the load factor
	unsigned dirSize() const { return dsz; }		// return the current hash directory size
	void resize();															// double the hash directory
	void displayEntries() const;
	typename fxvector<entry>::const_iterator begin() { return vp->begin(); }
	typename fxvector<entry>::const_iterator end() { return vp->end(); }
	typename fxvector<entry>::const_iterator begin() const { return vp->begin(); }
	typename fxvector<entry>::const_iterator end() const { return vp->end(); }

public:
	// find hash position(key), true on match
	bool find(uint64_t key, uint32_t& index) const;
	bool find(uint64_t key) const;						

	// copy hash entry to result, true on match
	bool get(uint64_t key, V& result) const;	

	// add (key,val) entry to map, true on match
	bool put(uint64_t key, V val);			

public:
	class fxhash64map_iterator : public rcobject
	{
	public:
		fxhash64map_iterator(fxhash64map<V>* map) : m(map), i(m->begin()) {}
		~fxhash64map_iterator() {}
		bool done() const  { return i==m->end(); }
		void operator++()  { i++; }
		const entry* operator*() { return &*i; }
	private:
		fxhash64map<V>* m;
		typename fxvector<entry>::const_iterator i;
	};

	class fxhash64map_const_iterator : public rcobject
	{
	public:
		fxhash64map_const_iterator(const fxhash64map<V>* map) : m(map), i(m->begin()) {}
		~fxhash64map_const_iterator() {}
		bool done() const  { return i==m->end(); }
		void operator++()  { i++; }
		const entry* operator*() { return &*i; }
	private:
		const fxhash64map<V>* m;
		typename fxvector<entry>::const_iterator i;
	};

	fxhash64map_iterator iterator()
		{ return fxhash64map_iterator(this); }
	fxhash64map_const_iterator const_iterator() const
		{ return fxhash64map_const_iterator(this); }

};


// display all the entries
template<class V>
void fxhash64map<V>::displayEntries() const
{
	typename fxvector<entry>::const_iterator it;
	for (it = vp->begin(); it!=vp->end(); it++) {
		const entry& e = *it;
		cout <<e.key<<" -> "<<e.val<<endl;
	}
}


// allocate transient hash64map
template<class V>
fxhash64map<V>::fxhash64map(
	float    _factor,
	unsigned _depth)
:
	vp(  new fxvector<entry> ),
	dir( new fxarray<int>( _depth )),
	ld(_factor),
	persistent(false)
{
	dsz = dir->size();
	sz  = vp->size();
	if (sz==0) dir->fill(-1);
} 


// allocate persistent hash64map
template<class V>
fxhash64map<V>::fxhash64map(
	const std::string& _datapath,
	float    _factor,
	unsigned _depth)
:
	datapath( _datapath ),
	vp(  new fxvector<entry>( _datapath+"keys" )),
	dir( new fxarray<int>(		_datapath+"dir", _depth )),
	ld(_factor),
	persistent(true)
{
	dsz = dir->size();
	sz  = vp->size();
	if (sz==0) dir->fill(-1);
} 


// dtor unmaps all the backing files
template<class V>
fxhash64map<V>::~fxhash64map()
{
	delete dir;
	delete vp;
}


// double the hash directory, remap hash entry offsets
template<class V>
inline void fxhash64map<V>::resize()
{
	fxarray<int>* dir0;
	int oldindex;

	// create and initialize new table
	dir0 = dir;
	if (persistent) {
		dir0->rename_backing_file(datapath+"dir0");
		dir = new fxarray<int>(datapath+"dir", dir0->size()<<1);
	}
	else {
		dir = new fxarray<int>(dir0->size()<<1);
	}
	dir->fill(-1);
	unsigned dsz0 = dir0->size();
	dsz  = dir->size();

	Assert<invariant>(dsz==dsz0*2, "fxhash64map::resize[01]");

	// rehash: place old entry offset in new hash location
	for (unsigned k = 0; k<dsz0; ++k) {
		oldindex = (*dir0)[k];
		if (oldindex>=0) {
			uint32_t h0 = (uint32_t)((*vp)[oldindex].key % dsz0);
			while (true) {
				if ((*dir)[h0]==-1) break;
				h0 = (h0 + 1) % dsz;
			}
			(*dir)[h0] = oldindex;
		}
	}

	// cleanup
	dir0->destroy();
	//delete dir0;
}


// Store the hash location for a given key (or next available slot) 
// in 'index'.  Return true <=> key matched.
template<class V>
inline bool fxhash64map<V>::find(
	uint64_t key,
	uint32_t& hval) const
{
	uint32_t h0 = (uint32_t)(key % dsz);
	bool result = false;
	while (true) {
		int x = (*dir)[h0];
		if (x==-1) { hval = h0; break; }		// -1 => empty
		entry& e = (*vp)[x];								// (id,val)
		if (key==e.key) {
			result = true;
			break;
		}
		h0 = (h0 + 1) % dir->size();				// collision
	}
	hval = h0;
	return result;
}

template<class V>
inline bool fxhash64map<V>::find(uint64_t key) const
{
	uint32_t index;
	return find(key,index);
}


// Copy hash value for a given key, return false if not found. 
template<class V>
inline bool fxhash64map<V>::get(uint64_t key, V& result) const
{
	uint32_t h0;
	if (find(key,h0)) {
		result = (*vp)[(*dir)[h0]].val;
		return true;
	}
	return false;
}


// Store a new (key.val) pair in the map.
// Return true <=> key matched.
template<class V>
inline bool fxhash64map<V>::put(uint64_t key, V val)
{
	if (sz > dsz*ld) resize();
	uint32_t h0;
	if (find(key,h0)) {
		entry* e = &((*vp)[(*dir)[h0]]); 
		e->val = val;
		return true;
	} else {
		vp->push_back(entry(key,val));
		(*dir)[h0] = sz++;
		return false;
	}
}


}  /* namespace xqp  */
#endif  /* XQP_FXHASHMAP_H */

