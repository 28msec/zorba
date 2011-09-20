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
#pragma once
#ifndef ZORBA_HASHMAP32_H
#define ZORBA_HASHMAP32_H

#include "common/common.h"
#include "zorbautils/hashfun.h"
#include "zorbautils/checked_vector.h"
#include "zorbautils/latch.h"
//#include "diagnostics/xquery_diagnostics.h"

namespace zorba {

/*_____________________________________________________________
|
|  Hash map: 32 bits -> <class V>
|______________________________________________________________*/

#define EMPTY -1

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
  uint32_t sz;                // count of hashed entries
  uint32_t dsz;               // tab (directory) allocated size
  float ld;                   // maximum load factor, default = .6
  checked_vector<entry> v;  // hash entries
  checked_vector<int> tab;  // hash directory, indexes 'v', -1 = EMPTY
  uint32_t depth;             // = lg(sz)
  SYNC_CODE(Latch rwl;)                 // readers-writers synchronization

public: // ctor,dtor
  hash32map(uint32_t sz, float ld);
  hash32map();
  ~hash32map();

public: // housekeeping
  uint32_t size();                            // the number of hashed entries
  uint32_t size_unsync();
  uint32_t alloc_size() const { return dsz; } // size of underlying array
  float load() const { return ld; }           // return the load factor
  void resize();  // double the array
  void resize_unsync();

public: // iterator interface
  typename checked_vector<entry>::const_iterator begin() { return v.begin(); }
  typename checked_vector<entry>::const_iterator end() { return v.end(); }

public: // map interface
  bool find(uint32_t key, uint32_t& index);     // find hash index(key), true on match
  bool find_unsync(uint32_t key, uint32_t& index);  // find hash index(key), true on match
  bool get(uint32_t key, V& result);            // copy hash entry to result, true on match
  bool get_unsync(uint32_t key, V& result);     // copy hash entry to result, true on match
  bool put(uint32_t key, V val);                // add (key,val) entry to map, true on match
  bool put_unsync(uint32_t key, V val);         // add (key,val) entry to map, true on match
  uint32_t h(uint32_t key) const;               // the hash function

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
  uint32_t sz;                // count of hashed entries
  uint32_t dsz;               // tab (directory) allocated size
  float ld;                   // maximum load factor, default = .6
  checked_vector<entry> v;  // hash entries
  checked_vector<int> tab;  // hash directory, indexes 'v', -1 = EMPTY
  uint32_t depth;             // = lg(sz)
  SYNC_CODE(Latch rwl;)                 // readers-writers synchronization

public: // ctor,dtor
  hash64map(uint32_t sz, float ld);
  hash64map();
  ~hash64map();

public: // housekeeping
  uint32_t size();                            // the number of hashed entries
  uint32_t size_unsync();
  uint32_t alloc_size() const { return dsz; } // size of underlying array
  float load() const { return ld; }           // return the load factor
  void resize();  // double the array
  void resize_unsync();

public: // iterator interface
  typename checked_vector<entry>::const_iterator begin() { return v.begin(); }
  typename checked_vector<entry>::const_iterator end() { return v.end(); }

public: // map interface
  bool find_unsync(uint64_t key) const;         // find hash index(key), true on match
  bool find(uint64_t key, uint32_t& index);     // find hash index(key), true on match
  bool find_unsync(uint64_t key, uint32_t& index);  // find hash index(key), true on match
  bool get(uint64_t key, V& result);            // copy hash entry to result, true on match
  bool get_unsync(uint64_t key, V& result);     // copy hash entry to result, true on match
  bool put(uint64_t key, V val);                // add (key,val) entry to map, true on match
  bool put_unsync(uint64_t key, V val);         // add (key,val) entry to map, true on match
  uint32_t h(uint64_t key) const;               // the hash function

};




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
  for (uint32_t n=0; n<dsz; ++n) tab[n] = EMPTY;
  for (uint32_t d = dsz; d>0; d>>=1) depth++;
}

template<class V>
hash32map<V>::hash32map()
:
  sz(0),
  dsz(1024),
  ld(0.6f),
  tab (1024),
  depth(0)
{
  for (uint32_t n=0; n<dsz; ++n) tab[n] = EMPTY;
  for (uint32_t d = dsz; d>0; d>>=1) depth++;
}

template<class V>
hash32map<V>::~hash32map()
{
}


template<class V>
inline uint32_t hash32map<V>::size_unsync()
{
  return v.size();
}


template<class V>
inline uint32_t hash32map<V>::size() 
{
  SYNC_CODE(rwl.rlock();)
  uint32_t z = v.size();
  SYNC_CODE(rwl.unlock();)
  return z;
}


template<class V>
inline void hash32map<V>::resize()
{
  int oldIndex;
  uint32_t dsz0 = dsz;  // save old table size
  dsz <<= 1;            // double the table size
  depth += 1;           // increment depth
  checked_vector<int> tab0 (dsz);

  tab.swap (tab0);
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
}


template<class V>
inline bool hash32map<V>::find_unsync(
  uint32_t key, uint32_t& index) 
{
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
  SYNC_CODE(rwl.rlock();)
  bool b = find_unsync(key, index);
  SYNC_CODE(rwl.unlock();)
  return b;
}


template<class V>
inline bool hash32map<V>::get_unsync(
  uint32_t key, V& result)
{
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
  SYNC_CODE(rwl.rlock();)
  bool b = get_unsync(key, result);
  SYNC_CODE(rwl.unlock();)
  return b;
}


template<class V>
inline bool hash32map<V>::put_unsync(
  uint32_t key, V val)
{
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
  SYNC_CODE(rwl.wlock();)
  bool b = put_unsync(key, val);
  SYNC_CODE(rwl.unlock();)
  return b;
}

template<class V>
inline uint32_t hash32map<V>::h(
  uint32_t key) const
{
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
  tab (initial_size),
  depth(0)
{
  for (uint32_t n=0; n<dsz; ++n) tab[n] = EMPTY;
  for (uint32_t d = dsz; d>0; d>>=1) depth++;
}

template<class V>
hash64map<V>::hash64map()
:
  sz(0),
  dsz(1024),
  ld(0.6f),
  tab (1024),
  depth(0)
{
  for (uint32_t n=0; n<dsz; ++n) tab[n] = EMPTY;
  for (uint32_t d = dsz; d>0; d>>=1) depth++;
}

template<class V>
hash64map<V>::~hash64map()
{
}


template<class V>
inline uint32_t hash64map<V>::size_unsync()
{
  return v.size();
}


template<class V>
inline uint32_t hash64map<V>::size() 
{
  SYNC_CODE(rwl.rlock();)
  uint32_t z = v.size();
  SYNC_CODE(rwl.unlock();)
  return z;
}


template<class V>
inline void hash64map<V>::resize()
{
  int oldIndex;
  uint32_t dsz0 = dsz;  // save old table size
  dsz <<= 1;            // double the table size
  depth += 1;           // increment depth
  checked_vector<int> tab0 (dsz);

  tab.swap (tab0);

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
}


template<class V>
inline bool hash64map<V>::find_unsync(
  uint64_t key, uint32_t& index) 
{
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
  SYNC_CODE(rwl.rlock();)
  bool b = find_unsync(key, index);
  SYNC_CODE(rwl.unlock();)
  return b;
}


template<class V>
inline bool hash64map<V>::find_unsync(
  uint64_t key) const 
{
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
  SYNC_CODE(rwl.rlock();)
  bool b = get_unsync(key, result);
  SYNC_CODE(rwl.unlock();)
  return b;
}


template<class V>
inline bool hash64map<V>::put_unsync(
  uint64_t key, V val)
{
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
  SYNC_CODE(rwl.wlock();)
  bool b = put_unsync(key, val);
  SYNC_CODE(rwl.unlock();)
  return b;
}


template<class V>
inline uint32_t hash64map<V>::h(
  uint64_t key) const
{
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
  return (uint32_t)hashfun::h64((void*)buf,8,FNV_64_INIT) % dsz;
}

}

#endif
/* vim:set et sw=2 ts=2: */
