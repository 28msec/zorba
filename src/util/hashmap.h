/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: hashmap.h,v 1.2 2006/10/11 00:13:43 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR Foundation.
 *	Author: Paul Pedersen
 *
 */

#ifndef XQP_HASHMAP_H
#define XQP_HASHMAP_H

#ifndef WIN32
#include <pthread.h>
#else
#include "util/win32/pthread.h"
#endif

#include <stddef.h>
#include <stdlib.h>
#ifndef WIN32
	#include <strings.h>
#else
	#include <string.h>
#endif
#include <string>
#include <vector>
#include <iostream>

#include "util/hashfun.h"
#include "util/rchandle.h"
#include "util/rwlock.h"
#include "errors/error_factory.h"


using namespace std;
namespace xqp {

/*___________________________________________________________
|
|  Hash map: string -> <class V>
|____________________________________________________________*/

template<class V>		// V = value type
class hashmap 			// key type = string
{
public:
	struct entry
	{
		string key;
		V val;

		entry() {}
		entry(string const& k, V v) : key(k), val(v) {}
		entry(char const* k, uint32_t l, V v) : key(string(k,0,l)), val(v) {}
		entry(entry const& e) : key(e.key), val(e.val) {}
		entry& operator=(entry const& e) { key = e.key; val = e.val; return *this; }
		~entry() {}
	};

private:
	uint32_t sz;					// entry count 
	uint32_t tsz;					// allocated size
	float ld;							// maximum load factor, default = .6
	float minsz;					// minimum size, default = .2*tsz
	vector<entry> v;			// hash entries
	int * tab;						// hash table, indexes into 'v', -1 = empty
	uint32_t dp;					// depth = lg(tsz)

public:	// ctor,dtor
	hashmap(uint32_t sz = 1024, float ld = .6);
	//daniel hashmap(hashmap&);
	hashmap(hashmap const&);
	~hashmap();

public:	// housekeeping
	void clear();
	uint32_t size() const		 { return sz; }		// return the number of hashed entries
	float load() const 			 { return ld; }		// return the load factor
	uint32_t tabSize() const { return tsz; }	// return the current hash table size
	void resize();														// double the hash table

	V getentryVal(uint32_t n) const { return v[n].val; }
	const string& getentryKey(uint32_t n) const { return v[n].key; }
	void displayentry(uint32_t n) const;
	void displayEntries() const;

public:	// iterator interface
	typename vector<entry>::const_iterator begin() { return v.begin(); }
	typename vector<entry>::const_iterator end() { return v.end(); }
	typename vector<entry>::const_iterator begin() const { return v.begin(); }
	typename vector<entry>::const_iterator end() const { return v.end(); }

public:	// map interface
	bool find(string const& key, uint32_t& index) const;		// find hash position(key), true on match
	bool find(char const* key, uint32_t& index) const;			// find hash position(key), true on match
	bool find(char const* key, uint32_t, uint32_t&) const;	// find hash position(key,len), true on match

	bool get(string const& key, V& result) const;	// copy hash entry at key to result, true on match
	bool get(char const* key, V& result) const;	  // copy hash entry at key to result, true on match
	bool get(char const* key, uint32_t, V&) const;// copy hash entry at key,len to result, true on match

	bool put(string const& key, V val);						// add (key,val) entry to map, true on match
	bool put(char const* key, V val);							// add (key,val) entry to map, true on match
	bool put(char const* key, uint32_t, V val);		// add (key,len,val) entry to map, true on match
	uint64_t put0(char const* key, V val);				// add (key,val) entry to map, return key heap offset

public: // the hash functions
	uint32_t h(string const& key) const;
	uint32_t h(char const*) const;
	uint32_t h(char const*, uint32_t len) const;

};



/*_____________________________________________________________
|
|  Hash map: 32 bits -> <class V>
|______________________________________________________________*/

#define EMPTY	-1

template<class V>
class hash32map
{
public:
  struct entry
  {
    uint32_t key;
    V val;
    entry() {}
    entry(uint32_t k, V v) : key(k), val(v) {}
    ~entry() {}
  };

private:
	uint32_t sz;								// count of hashed entries
	uint32_t dsz;								// tab (directory) allocated size
	float ld;										// maximum load factor, default = .6
	std::vector<entry> v;				// hash entries
	int* tab;										// hash directory, indexes 'v', -1 = EMPTY
	uint32_t depth;							// = lg(sz)
	rwlock rwl;									// readers-writers synchronization

public:	// ctor,dtor
	hash32map(uint32_t sz, float ld);
	hash32map();
	~hash32map();

public:	// housekeeping
	uint32_t size();														// the number of hashed entries
	uint32_t size_unsync();
	uint32_t alloc_size() const { return dsz; }	// size of underlying array
	float load() const { return ld; }						// return the load factor
	void resize();	// double the array
	void resize_unsync();

public:	// iterator interface
	typename vector<entry>::const_iterator begin() { return v.begin(); }
	typename vector<entry>::const_iterator end() { return v.end(); }

public:	// map interface
  bool find(uint32_t key, uint32_t& index);			// find hash index(key), true on match
  bool find_unsync(uint32_t key, uint32_t& index);	// find hash index(key), true on match
  bool get(uint32_t key, V& result);						// copy hash entry to result, true on match
  bool get_unsync(uint32_t key, V& result);			// copy hash entry to result, true on match
  bool put(uint32_t key, V val);								// add (key,val) entry to map, true on match
  bool put_unsync(uint32_t key, V val);					// add (key,val) entry to map, true on match
	uint32_t h(uint32_t key) const;								// the hash function

};



/*_____________________________________________________________
|
|  Hash map: 64 bits -> <class T>
|______________________________________________________________*/

template<class V>
class hash64map
{
public:
  struct entry
  {
    uint64_t key;
    V val;
    entry() {}
    entry(uint64_t k, V v) : key(k), val(v) {}
    ~entry() {}
  };

private:
	uint32_t sz;								// count of hashed entries
	uint32_t dsz;								// tab (directory) allocated size
	float ld;										// maximum load factor, default = .6
	std::vector<entry> v;				// hash entries
	int* tab;										// hash directory, indexes 'v', -1 = EMPTY
	uint32_t depth;							// = lg(sz)
	rwlock rwl;									// readers-writers synchronization

public:	// ctor,dtor
	hash64map(uint32_t sz, float ld);
	hash64map();
	~hash64map();

public:	// housekeeping
	uint32_t size();														// the number of hashed entries
	uint32_t size_unsync();
	uint32_t alloc_size() const { return dsz; }	// size of underlying array
	float load() const { return ld; }						// return the load factor
	void resize();	// double the array
	void resize_unsync();

public:	// iterator interface
	typename vector<entry>::const_iterator begin() { return v.begin(); }
	typename vector<entry>::const_iterator end() { return v.end(); }

public:	// map interface
  bool find_unsync(uint64_t key) const;					// find hash index(key), true on match
  bool find(uint64_t key, uint32_t& index);			// find hash index(key), true on match
  bool find_unsync(uint64_t key, uint32_t& index);	// find hash index(key), true on match
  bool get(uint64_t key, V& result);						// copy hash entry to result, true on match
  bool get_unsync(uint64_t key, V& result);			// copy hash entry to result, true on match
  bool put(uint64_t key, V val);								// add (key,val) entry to map, true on match
  bool put_unsync(uint64_t key, V val);					// add (key,val) entry to map, true on match
	uint32_t h(uint64_t key) const;								// the hash function

};




/*_____________________________________________________________
|
|  hashmap implementations
|______________________________________________________________*/

template<class V>
void hashmap<V>::displayentry(uint32_t n) const
{
	cout << "tab["<<n<<"] = ("<<v[n].key<<','<<v[n].val<<endl;
}
	

template<class V>
void hashmap<V>::displayEntries() const
{
	typename vector<entry>::const_iterator it;
	for (it = v.begin(); it!=v.end(); it++) {
		const entry& e = *it;
		cout << "tab -> ("<<e.key<<','<<e.val<<endl;
	}
}
	
template<class V>
hashmap<V>::hashmap(
	uint32_t initial_size,
	float load_factor)
:
	sz(0),
	tsz(initial_size),
	ld(load_factor),
	minsz(initial_size*0.2f),
	tab(new int[initial_size]),
	dp(0)
{
	for (uint32_t n=0; n<tsz; ++n) tab[n] = -1;
	for (uint32_t d = tsz; d>0; d>>=1) dp++;
}

/*daniel
template<class V>
hashmap<V>::hashmap(
	hashmap<V> & m)
:
	sz(m.sz),
	tsz(m.tsz),
	ld(m.ld),
	minsz(m.minsz),
	tab(new int[m.tsz]),
	dp(m.dp)
{
	memcpy(tab, m.tab, tsz*sizeof(int));
	typename vector<entry>::const_iterator it = m.begin();
	typename vector<entry>::const_iterator en = m.end();
	for (; it!=en; ++it) { v.push_back(*it); }
}
*/

template<class V>
hashmap<V>::hashmap(
	hashmap<V> const& m)
:
	sz(m.sz),
	tsz(m.tsz),
	ld(m.ld),
	minsz(m.minsz),
	tab(new int[m.tsz]),
	dp(m.dp)
{
	memcpy(tab, m.tab, tsz*sizeof(int));
	typename vector<entry>::const_iterator it = m.begin();
	typename vector<entry>::const_iterator en = m.end();
	for (; it!=en; ++it) { v.push_back(*it); }
}

template<class V>
hashmap<V>::~hashmap()
{
	delete[] tab;
}

template<class V>
inline void hashmap<V>::clear()
{
	sz = 0;
	v.clear();
	memset((char*)tab, -1, tsz*sizeof(int));
	//for (uint32_t k=0;k<tsz;++k) tab[k] = -1;
}


template<class V>
inline void hashmap<V>::resize()
{
	uint32_t tsz0;
	int* tab0;
	int oldIndex;

	// reallocate
	tsz0 = tsz;						// save old table size
	tsz <<= 1;						// double the table size
	minsz = tsz*0.2f;			// replace min table size
	dp += 1;							// increment depth 
	tab0 = tab;						// save old table
	tab  = new int[tsz];	// create and init new table
	for (uint32_t n=0; n<tsz; ++n) tab[n] = -1;

	// rehash: place old entry index in new hash location
	for (uint32_t k = 0; k<tsz0; ++k) {
		oldIndex = tab0[k];
		if (oldIndex>=0) {
			uint32_t h0 = h(v[oldIndex].key);
			while (true) {
				if (tab[h0] == -1) break;
				h0 = (h0 + 1) % tsz;
			}
			tab[h0] = oldIndex;
		}
	}

	// cleanup
	delete[] tab0;
}



//	Store the hash location for a given key (or next available slot) 
//	in 'index'.  Return true on match, else false. 
template<class V>
inline bool hashmap<V>::find(const string& key, uint32_t& index) const
{
	uint32_t h0 = h(key);
	bool result = false;
	while (true) {
		int x = tab[h0];
		if (x==-1) break;
		const entry& e = v[x];
		if (strcmp(e.key.c_str(), key.c_str ())==0) {
      result = true; 
      break;
    }
		h0 = (h0 + 1) % tsz;
	}
	index = h0;
	return result;
}


//  Store the hash location for a given key (or next available slot) 
//  into 'index'.  Return true on match, else false.   
template<class V>
inline bool hashmap<V>::find( const char* key, uint32_t& index) const
{
	uint32_t h0 = h(key);
	bool result = false;
	while (true) {
		int x = tab[h0];
		if (x==-1) break;
		const entry& e = v[x];
		if (strcmp(e.key.c_str(),key)==0) { result = true; break; }
		h0 = (h0 + 1) % tsz;
	}
	index = h0;
	return result;
}


//  Store the hash location for a given key (or next available slot) 
//  into 'index'.  Return true on match, else false.   
template<class V>
inline bool hashmap<V>::find(
	const char* key, uint32_t len, uint32_t& index) const
{
	uint32_t h0 = h(key, len);
	bool result = false;
	while (true) {
		int x = tab[h0];
		if (x==-1) break;
		const entry& e = v[x];
		if (strncasecmp(e.key.c_str(),key,len)==0) { result = true; break; }
		h0 = (h0 + 1) % tsz;
	}
	index = h0;
	return result;
}


//  Copy hash value for a given key, return false if not found. 
template<class V>
inline bool hashmap<V>::get(const string& key, V& result) const
{
	uint32_t h0;
	if (find(key,h0)) { result = v[tab[h0]].val; return true; }
	return false;
}


//  Copy hash value for a given key, return false if not found. 
template<class V>
inline bool hashmap<V>::get(const char* key, V& result) const
{
	uint32_t h0;
	if (find(key,h0)) { result = v[tab[h0]].val; return true; }
	return false;
}


//  Copy hash value for a given key, return false if not found. 
template<class V>
inline bool hashmap<V>::get(const char* key, uint32_t len, V& result) const
{
	uint32_t h0;
	if (find(key,len,h0)) { result = v[tab[h0]].val; return true; }
	return false;
}



//  Store a new (key.val) pair in the map.
//  Return true if key was matched, else false.
template<class V>
inline bool hashmap<V>::put(const string& key, V val)
{
	if (sz>tsz*ld) resize();

	uint32_t h0;
	if (find(key,h0)) {
		entry* e = &v[tab[h0]]; 
		e->val = val;
		return true;
	} else {
		v.push_back(entry(key,val));
		tab[h0] = sz++;
		return false;
	}
}


//  Store a new (key.val) pair in the map.
//  Return true if key was matched, else false.
template<class V>
inline bool hashmap<V>::put(const char* key, V val) 
{
	if (sz>tsz*ld) resize();

	uint32_t h0;
	if (find(key,h0)) {
		entry* e = &v[tab[h0]]; 
		e->val = val;
		return true;
	} else {
		v.push_back(entry(key,val));
		tab[h0] = sz++;
		return false;
	}
}


//  Store a new (key.val) pair in the map.
//  Return true if key was matched, else false.
template<class V>
inline bool hashmap<V>::put(const char* key, uint32_t len, V val) 
{
	if (sz>tsz*ld) resize();

	uint32_t h0;
	if (find(key,len,h0)) {
		entry* e = &v[tab[h0]]; 
		e->val = val;
		return true;
	} else {
		v.push_back(entry(key,val));
		tab[h0] = sz++;
		return false;
	}
}


//  Store a new (key.val) pair in the map.
//  Return key heap offset.
template<class V>
inline uint64_t hashmap<V>::put0(const char* key, V val) 
{
	if (sz>tsz*ld) resize();

	uint32_t h0;
	if (find(key,h0)) {
		entry* e = &v[tab[h0]]; 
		e->val = val;
		return e->key;
	} else {
		v.push_back(entry(key,val));
		tab[h0] = sz++;
		return false;
	}
}



//  The hash functions.
template<class V>
inline uint32_t hashmap<V>::h(const string& key) const
{
	return  hashfun::h32(key) % tsz;
}

template<class V>
inline uint32_t hashmap<V>::h(const char* key) const
{
	return  hashfun::h32(key,FNV_32_INIT) % tsz;
}

template<class V>
inline uint32_t hashmap<V>::h(const char* key, uint32_t len) const
{
	return  hashfun::h32(key,len,FNV_32_INIT) % tsz;
}




/*_______________________________________________________
|                                                        
|          hash32map implementations
|________________________________________________________*/


// ctor, dtor
template<class V>
hash32map<V>::hash32map(
  uint32_t initial_size,
  float load_factor)
:
  sz(0),
  dsz(initial_size),
  ld(load_factor),
  tab(initial_size),
  depth(0)
{
#ifdef DEBUG
std::cout << __FUNCTION__ << std::endl;
#endif

  for (uint32_t n=0; n<dsz; ++n) tab[n] = EMPTY;
  for (uint32_t d = dsz; d>0; d>>=1) depth++;
}

template<class V>
hash32map<V>::hash32map()
:
  sz(0),
  dsz(1024),
  ld(0.6f),
  tab(new int[1024]),
  depth(0)
{
#ifdef DEBUG
std::cout << __FUNCTION__ << std::endl;
#endif

  for (uint32_t n=0; n<dsz; ++n) tab[n] = EMPTY;
  for (uint32_t d = dsz; d>0; d>>=1) depth++;
}

template<class V>
hash32map<V>::~hash32map()
{
#ifdef DEBUG
std::cout << __FUNCTION__ << std::endl;
#endif

  delete[] tab;
}


template<class V>
inline uint32_t hash32map<V>::size_unsync()
{
#ifdef DEBUG
std::cout << __FUNCTION__ << std::endl;
#endif

	return v.size();
}


template<class V>
inline uint32_t hash32map<V>::size() 
{
#ifdef DEBUG
std::cout << __FUNCTION__ << std::endl;
#endif

	if (rwl.readlock()!=0) {
		ZORBA_ERROR_ALERT(AlertCodes::XQP0008_SYSTEM_READ_LOCK_FAILED);
	}
	uint32_t z = v.size();
	rwl.readunlock();
	return z;
}


template<class V>
inline void hash32map<V>::resize()
{
#ifdef DEBUG
std::cout << __FUNCTION__ << std::endl;
#endif

  int oldIndex;
  uint32_t dsz0 = dsz;  // save old table size
  dsz <<= 1;            // double the table size
  depth += 1;           // increment depth
  int* tab0 = tab;      // save old table
  tab  = new int[dsz];  // create and init new table
  for (uint32_t n=0; n<dsz; ++n) tab[n] = EMPTY;

  // rehash: place old entry index in new hash location
	for (uint32_t k = 0; k<dsz0; ++k) {
		oldIndex = tab0[k];
		if (oldIndex==EMPTY) continue;
		uint32_t h0 = h(v[oldIndex].key);
		while (true) {
			if (tab[h0] == EMPTY) break;
			h0 = (h0+1) % dsz;
		}
		tab[h0] = oldIndex;
	}

	// cleanup
	delete[] tab0;
}


template<class V>
inline bool hash32map<V>::find_unsync(
	uint32_t key, uint32_t& index) 
{
#ifdef DEBUG
std::cout << __FUNCTION__ << std::endl;
#endif

  uint32_t h0 = h(key);
  bool result = false;
  while (true) {
    int x = tab[h0];
    if (x==EMPTY) break;
    const entry& e = v[x];
    if (e.key==key) { result = true; break; }
    h0 = (h0 + 1) % dsz;
  }
  index = h0;
  return result;
}

template<class V>
inline bool hash32map<V>::find(
	uint32_t key, uint32_t& index) 
{
#ifdef DEBUG
std::cout << __FUNCTION__ << std::endl;
#endif

	if (rwl.readlock()!=0) {
		//throw xqp_exception(__FUNCTION__,"read lock failed");
		ZORBA_ERROR_ALERT(AlertCodes::XQP0008_SYSTEM_READ_LOCK_FAILED);
	}
	bool b = find_unsync(key, index);
	rwl.readunlock();
	return b;
}


template<class V>
inline bool hash32map<V>::get_unsync(
	uint32_t key, V& result)
{
#ifdef DEBUG
std::cout << __FUNCTION__ << std::endl;
#endif

  uint32_t h0;
  if (find_unsync(key,h0)) {
		result = v[tab[h0]].val;
		return true;
	}
  return false;
}

template<class V>
inline bool hash32map<V>::get(
	uint32_t key, V& result) 
{
#ifdef DEBUG
std::cout << __FUNCTION__ << std::endl;
#endif

	if (rwl.readlock()!=0) {
		//throw xqp_exception(__FUNCTION__,"read lock failed");
		ZORBA_ERROR_ALERT(AlertCodes::XQP0008_SYSTEM_READ_LOCK_FAILED);
	}
	bool b = get_unsync(key, result);
	rwl.readunlock();
	return b;
}


template<class V>
inline bool hash32map<V>::put_unsync(
	uint32_t key, V val)
{
#ifdef DEBUG
std::cout << __FUNCTION__ << std::endl;
#endif

  if (sz>dsz*ld) resize();
  uint32_t h0;
  if (find_unsync(key,h0)) {
    entry* e = &v[tab[h0]];
    e->val = val;
    return true;
  } else {
    v.push_back(entry(key,val));
    tab[h0] = sz++;
    return false;
  }
}

template<class V>
inline bool hash32map<V>::put(
	uint32_t key, V val)
{
#ifdef DEBUG
std::cout << __FUNCTION__ << std::endl;
#endif

	if (rwl.writelock()!=0) {
		//throw xqp_exception(__FUNCTION__,"write lock failed");
		ZORBA_ERROR_ALERT(AlertCodes::XQP0009_SYSTEM_WRITE_LOCK_FAILED);
	}
	bool b = put_unsync(key, val);
	rwl.writeunlock();
	return b;
}

template<class V>
inline uint32_t hash32map<V>::h(
	uint32_t key) const
{
#ifdef DEBUG
std::cout << __FUNCTION__ << std::endl;
#endif

	char buf[5];
	buf[0] = (unsigned char)(key>>24);
	buf[1] = (unsigned char)(key>>16);
	buf[2] = (unsigned char)(key>>8 );
	buf[3] = (unsigned char)(key    );
	buf[4] = 0;
	return hashfun::h32((void*)buf,4,FNV_32_INIT) % dsz;
}



/*_______________________________________________________
|
|          hash64map implementations
|________________________________________________________*/

// ctor, dtor
template<class V>
hash64map<V>::hash64map(
  uint32_t initial_size,
  float load_factor)
:
  sz(0),
  dsz(initial_size),
  ld(load_factor),
  tab(new int[initial_size]),
  depth(0)
{
#ifdef DEBUG
std::cout << __FUNCTION__ << std::endl;
#endif

	std::cout << "dsz = " << dsz << std::endl;

  for (uint32_t n=0; n<dsz; ++n) tab[n] = EMPTY;
  for (uint32_t d = dsz; d>0; d>>=1) depth++;

	for (uint32_t j=0; j<20; ++j) {
		std::cout << "tab["<<j<<"] = "<<tab[j]<<std::endl;
	}
}

template<class V>
hash64map<V>::hash64map()
:
  sz(0),
  dsz(1024),
  ld(0.6f),
  tab(new int[1024]),
  depth(0)
{
#ifdef DEBUG
std::cout << __FUNCTION__ << std::endl;
#endif

  for (uint32_t n=0; n<dsz; ++n) tab[n] = EMPTY;
  for (uint32_t d = dsz; d>0; d>>=1) depth++;
}

template<class V>
hash64map<V>::~hash64map()
{
#ifdef DEBUG
std::cout << __FUNCTION__ << std::endl;
#endif

  delete[] tab;
}


template<class V>
inline uint32_t hash64map<V>::size_unsync()
{
#ifdef DEBUG
std::cout << __FUNCTION__ << std::endl;
#endif

	return v.size();
}


template<class V>
inline uint32_t hash64map<V>::size() 
{
#ifdef DEBUG
std::cout << __FUNCTION__ << std::endl;
#endif

	if (rwl.readlock()!=0) {
		//throw xqp_exception(__FUNCTION__,"read lock failed");
		ZORBA_ERROR_ALERT(AlertCodes::XQP0008_SYSTEM_READ_LOCK_FAILED);
	}
	uint32_t z = v.size();
	rwl.readunlock();
	return z;
}


template<class V>
inline void hash64map<V>::resize()
{
#ifdef DEBUG
std::cout << __FUNCTION__ << std::endl;
#endif

  int oldIndex;
  uint32_t dsz0 = dsz;  // save old table size
  dsz <<= 1;            // double the table size
  depth += 1;           // increment depth
  int* tab0 = tab;      // save old table
  tab  = new int[dsz];  // create and init new table
  for (uint32_t n=0; n<dsz; ++n) tab[n] = EMPTY;

  // rehash: place old entry index in new hash location
	for (uint32_t k = 0; k<dsz0; ++k) {
		oldIndex = tab0[k];
		if (oldIndex==EMPTY) continue;
		uint32_t h0 = h(v[oldIndex].key);
		while (true) {
			if (tab[h0] == EMPTY) break;
			h0 = (h0+1) % dsz;
		}
		tab[h0] = oldIndex;
	}

	// cleanup
	delete[] tab0;
}


template<class V>
inline bool hash64map<V>::find_unsync(
	uint64_t key, uint32_t& index) 
{
#ifdef DEBUG
std::cout << __FUNCTION__ << std::endl;
#endif

  uint32_t h0 = h(key);
  bool result = false;
  while (true) {
    int x = tab[h0];
    if (x==EMPTY) break;
    const entry& e = v[x];
    if (e.key==key) { result = true; break; }
    h0 = (h0 + 1) % dsz;
  }
  index = h0;
  return result;
}


template<class V>
inline bool hash64map<V>::find(
	uint64_t key, uint32_t& index) 
{
#ifdef DEBUG
std::cout << __FUNCTION__ << std::endl;
#endif

	if (rwl.readlock()!=0) {
		//throw xqp_exception(__FUNCTION__,"read lock failed");
		ZORBA_ERROR_ALERT(AlertCodes::XQP0008_SYSTEM_READ_LOCK_FAILED);
	}
	bool b = find_unsync(key, index);
	rwl.readunlock();
	return b;
}


template<class V>
inline bool hash64map<V>::find_unsync(
	uint64_t key) const 
{
#ifdef DEBUG
std::cout << __FUNCTION__ << std::endl;
#endif

  uint32_t h0 = h(key);
  bool result = false;
  while (true) {
    int x = tab[h0];
    if (x==EMPTY) break;
    const entry& e = v[x];
    if (e.key==key) { result = true; break; }
    h0 = (h0 + 1) % dsz;
  }
  return result;
}


template<class V>
inline bool hash64map<V>::get_unsync(
	uint64_t key, V& result)
{
#ifdef DEBUG
std::cout << __FUNCTION__ << std::endl;
#endif

  uint32_t h0;
  if (find_unsync(key,h0)) {
		result = v[tab[h0]].val;
		return true;
	}
  return false;
}


template<class V>
inline bool hash64map<V>::get(
	uint64_t key, V& result) 
{
#ifdef DEBUG
std::cout << __FUNCTION__ << std::endl;
#endif

	if (rwl.readlock()!=0) {
		//throw xqp_exception(__FUNCTION__,"read lock failed");
		ZORBA_ERROR_ALERT(AlertCodes::XQP0008_SYSTEM_READ_LOCK_FAILED);
	}
	bool b = get_unsync(key, result);
	rwl.readunlock();
	return b;
}


template<class V>
inline bool hash64map<V>::put_unsync(
	uint64_t key, V val)
{
#ifdef DEBUG
std::cout << __FUNCTION__ << std::endl;
#endif

  if (sz>dsz*ld) resize();
  uint32_t h0;
  if (find_unsync(key,h0)) {
    entry* e = &v[tab[h0]];
    e->val = val;
    return true;
  } else {
    v.push_back(entry(key,val));
    tab[h0] = sz++;
    return false;
  }
}


template<class V>
inline bool hash64map<V>::put(
	uint64_t key, V val)
{
#ifdef DEBUG
std::cout << __FUNCTION__ << std::endl;
#endif

	if (rwl.writelock()!=0) {
		//throw xqp_exception(__FUNCTION__,"write lock failed");
		ZORBA_ERROR_ALERT(AlertCodes::XQP0009_SYSTEM_WRITE_LOCK_FAILED);
	}
	bool b = put_unsync(key, val);
	rwl.writeunlock();
	return b;
}


template<class V>
inline uint32_t hash64map<V>::h(
	uint64_t key) const
{
#ifdef DEBUG
std::cout << __FUNCTION__ << std::endl;
#endif

	char buf[9];
	buf[0] = (unsigned char)(key>>56);
	buf[1] = (unsigned char)(key>>48);
	buf[2] = (unsigned char)(key>>40);
	buf[3] = (unsigned char)(key>>32);
	buf[4] = (unsigned char)(key>>24);
	buf[5] = (unsigned char)(key>>16);
	buf[6] = (unsigned char)(key>>8 );
	buf[7] = (unsigned char)(key    );
	buf[8] = 0;
	return hashfun::h64((void*)buf,8,FNV_64_INIT) % dsz;
}



}	/* namespace xqp	*/
#endif	/* XQP_HASHMAP_H */
