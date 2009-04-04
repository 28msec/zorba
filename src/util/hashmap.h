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
#ifndef ZORBA_HASHMAP_H
#define ZORBA_HASHMAP_H

#include "common/common.h"

#include <stddef.h>
#include <stdlib.h>
#ifndef WIN32
# include <strings.h>
#else
# include <string.h>
#endif
#include <string>
#include <iostream>

#include "zorbautils/hashfun.h"
#include "zorbautils/checked_vector.h"
#include "zorbautils/latch.h"
#include "zorbaerrors/error_manager.h"


namespace zorba {


/*___________________________________________________________
|
|  Hash map: string -> <class V>
|____________________________________________________________*/

template<class V>   // V = value type
class hashmap       // key type = string
{
public:
  struct entry
  {
    std::string key;
    V val;

    entry() {}

    entry(std::string const& k, V v) : key(k), val(v) {}

    entry(char const* k, uint32_t l, V v) : key(std::string(k,0,l)), val(v) {}

    entry(entry const& e) : key(e.key), val(e.val) {}

    entry(const char* k1, std::string const& k2, V v)
    {
      key = k1;
      key += k2;
      val = v;
    }

    ~entry() {}

    entry& operator=(entry const& e) 
    {
      key = e.key; val = e.val; return *this; 
    }

    bool matchKey2(const char* key1, const std::string& key2) const
    {
      const char* k = key.c_str();
      while(*key1)
      {
        if(*k != *key1)
          return false;
        k++;
        key1++;
      }

      if(strcmp(k, key2.c_str()))
        return false;

      return true;
    }
  };

private:
  uint32_t sz;               // entry count 
  uint32_t tsz;              // allocated size
  float ld;                  // maximum load factor, default = .6
  float minsz;               // minimum size, default = .2*tsz
  checked_vector<entry> v;   // hash entries
  checked_vector<int> tab;   // hash table, indexes into 'v', -1 = empty

public:
  hashmap(uint32_t sz = 1024, float ld = .6);

  hashmap(hashmap const&);

  ~hashmap();

public: // housekeeping
  void clear();
  uint32_t size() const    { return sz; }   // return the number of hashed entries
  float load() const       { return ld; }   // return the load factor
  uint32_t tabSize() const { return tsz; }  // return the current hash table size
  void resize();                            // double the hash table

  V getentryVal(uint32_t n) const { return v[n].val; }
  const std::string& getentryKey(uint32_t n) const { return v[n].key; }
  void displayentry(uint32_t n) const;
  void displayEntries() const;

public: // iterator interface
  typename checked_vector<entry>::const_iterator begin() { return v.begin(); }
  typename checked_vector<entry>::const_iterator end() { return v.end(); }
  typename checked_vector<entry>::const_iterator begin() const { return v.begin(); }
  typename checked_vector<entry>::const_iterator end() const { return v.end(); }

public: // map interface
  bool put(std::string const& key, V val, bool replace = true); 
  bool put(char const* key, V val, bool replace = true); 
  bool put(char const* key, uint32_t, V val, bool replace = true);
  bool put2(const char* key1, std::string const& key2, V val, bool replace = true);

  bool find(std::string const& key, uint32_t& index) const; 
  bool find(char const* key, uint32_t& index) const;
  bool find(char const* key, uint32_t len, uint32_t&) const;
  bool find2(const char* key1, std::string const& key2, uint32_t& index) const;

  bool get(std::string const& key, V& result) const;
  bool get(char const* key, V& result) const;
  bool get(char const* key, uint32_t, V&) const;
  bool get2(const char *key1, std::string const& key2, V& result) const;

public: // the hash functions
  uint32_t h(std::string const& key) const;
  uint32_t h(char const*) const;
  uint32_t h(char const*, uint32_t len) const;
  uint32_t h(const char* key1, const std::string& key2) const;

};


/*******************************************************************************

********************************************************************************/
template<class V>
hashmap<V>::hashmap(uint32_t initial_size, float load_factor)
:
  sz(0),
  tsz(initial_size),
  ld(load_factor),
  minsz(initial_size*0.2f),
  tab (initial_size)
{
  for (uint32_t n=0; n<tsz; ++n) tab[n] = -1;
}


/*******************************************************************************

********************************************************************************/
template<class V>
hashmap<V>::hashmap(hashmap<V> const& m)
:
  sz(m.sz),
  tsz(m.tsz),
  ld(m.ld),
  minsz(m.minsz),
  tab (m.tsz)
{
  {
    typename checked_vector<int>::const_iterator it = m.tab.begin();
    typename checked_vector<int>::const_iterator en = m.tab.end();
    for (; it!=en; ++it) { tab.push_back(*it); }
  }

  {
    typename checked_vector<entry>::const_iterator it = m.begin();
    typename checked_vector<entry>::const_iterator en = m.end();
    for (; it!=en; ++it) { v.push_back(*it); }
  }
}


/*******************************************************************************

********************************************************************************/
template<class V>
hashmap<V>::~hashmap()
{
}


/*******************************************************************************

********************************************************************************/
template<class V>
inline void hashmap<V>::clear()
{
  sz = 0;
  v.clear();
  memset((char*)tab, -1, tsz*sizeof(int));
  //for (uint32_t k=0;k<tsz;++k) tab[k] = -1;
}


/*******************************************************************************

********************************************************************************/
template<class V>
void hashmap<V>::displayentry(uint32_t n) const
{
  std::cout << "tab["<<n<<"] = ("<<v[n].key<<','<<v[n].val<<std::endl;
}
  

/*******************************************************************************

********************************************************************************/
template<class V>
void hashmap<V>::displayEntries() const
{
  typename checked_vector<entry>::const_iterator it;
  for (it = v.begin(); it!=v.end(); it++) {
    const entry& e = *it;
    std::cout << "tab -> ("<<e.key<<','<<e.val<<std::endl;
  }
}


/*******************************************************************************
  Double the size of the hash table and rehash all existing entries.
********************************************************************************/
template<class V>
inline void hashmap<V>::resize()
{
  int oldIndex;

  uint32_t tsz0 = tsz;  // save old table size
  tsz <<= 1;            // double the table size
  minsz = tsz * 0.2f;   // replace min table size

  // reallocate
  checked_vector<int> tab0 (tsz);
  tab.swap (tab0);

  for (uint32_t n = 0; n < tsz; ++n) tab[n] = -1;

  // rehash: place old entry index in new hash location
  for (uint32_t k = 0; k < tsz0; ++k) 
  {
    oldIndex = tab0[k];
    if (oldIndex >= 0) 
    {
      uint32_t h0 = h(v[oldIndex].key);
      while (true) 
      {
        if (tab[h0] == -1) break;
        h0 = (h0 + 1) % tsz;
      }
      tab[h0] = oldIndex;
    }
  }
}


/*******************************************************************************
  Store a new (key, val) pair in the map, if key is not in the map already. If
  key is in the map already, and "replace" is true, the value associated with
  key is replaced with the new value. 

  Return true if key was in map already, else false.
********************************************************************************/
template<class V>
inline bool hashmap<V>::put(const std::string& key, V val, bool replace)
{
  if (sz > tsz*ld) resize();

  uint32_t h0;
  if (find(key,h0)) 
  {
    if (replace) 
    {
      entry* e = &v[tab[h0]]; 
      e->val = val;
    }
    return true;
  }
  else 
  {
    v.push_back(entry(key,val));
    tab[h0] = sz++;
    return false;
  }
}


/*******************************************************************************
  Store a new (key, val) pair in the map, if key is not in the map already. If
  key is in the map already, and "replace" is true, the value associated with
  key is replaced with the new value. 

  Return true if key was in map already, else false.
********************************************************************************/
template<class V>
inline bool hashmap<V>::put(const char* key, V val, bool replace)
{
  if (sz > tsz*ld) resize();

  uint32_t h0;
  if (find(key,h0)) 
  {
    if (replace) 
    {
      entry* e = &v[tab[h0]]; 
      e->val = val;
    }
    return true;
  } 
  else 
  {
    v.push_back(entry(key,val));
    tab[h0] = sz++;
    return false;
  }
}


/*******************************************************************************
  Store a new (key, val) pair in the map, if key is not in the map already. If
  key is in the map already, and "replace" is true, the value associated with
  key is replaced with the new value. 

  Return true if key was in map already, else false.
********************************************************************************/
template<class V>
inline bool hashmap<V>::put(const char* key, uint32_t len, V val, bool replace)
{
  if (sz > tsz*ld) resize();

  uint32_t h0;
  if (find(key, len, h0)) 
  {
    if (replace) 
    {
      entry* e = &v[tab[h0]]; 
      e->val = val;
    }
    return true;
  } 
  else 
  {
    v.push_back(entry(key, val));
    tab[h0] = sz++;
    return false;
  }
}


/*******************************************************************************
  Store a new (key, val) pair in the map, if key is not in the map already. Here,
  key is the concatenation of key1 and k2. If key is in the map already, and 
  "replace" is true, the value associated with key is replaced with the new value. 

  Return true if key was in map already, else false.
********************************************************************************/
template<class V>
inline bool hashmap<V>::put2(
    const char* key1,
    const std::string& key2,
    V val,
    bool replace)
{
  if (sz > tsz*ld) resize();

  uint32_t h0;
  if (find2(key1, key2, h0)) 
  {
    if (replace) 
    {
      entry* e = &v[tab[h0]]; 
      e->val = val;
    }
    return true;
  }
  else 
  {
    v.push_back(entry(key1, key2, val));
    tab[h0] = sz++;
    return false;
  }
}


/*******************************************************************************
  Get a copy of the value for a given key, return false if key not found
********************************************************************************/
template<class V>
inline bool hashmap<V>::get(const std::string& key, V& result) const
{
  uint32_t h0;
  if (find(key, h0))
  {
    result = v[tab[h0]].val;
    return true; 
  }
  return false;
}


/*******************************************************************************
  Get a copy of the value for a given key, return false if key not found.
********************************************************************************/
template<class V>
inline bool hashmap<V>::get(const char* key, V& result) const
{
  uint32_t h0;
  if (find(key,h0)) 
  {
    result = v[tab[h0]].val;
    return true; 
  }
  return false;
}


/*******************************************************************************
  Get a copy of the value for a given key, return false if key not found.
********************************************************************************/
template<class V>
inline bool hashmap<V>::get(const char* key, uint32_t len, V& result) const
{
  uint32_t h0;
  if (find(key,len,h0)) 
  {
    result = v[tab[h0]].val;
    return true; 
  }
  return false;
}


/*******************************************************************************
  Get a copy of the value for a given key, return false if key not found.
********************************************************************************/
template<class V>
inline bool hashmap<V>::get2(const char* key1, const std::string& key2, V& result) const
{
  uint32_t h0;
  if (find2(key1, key2, h0)) 
  {
    result = v[tab[h0]].val;
    return true; 
  }
  return false;
}


/*******************************************************************************
  Find the hash bucket for the given key. 

  If the key is already in the map, return true and its hash bucket. If the key
  is not already in the map, return false and the (free) hash bucket where the
  key should be inserted. 
********************************************************************************/  
template<class V>
inline bool hashmap<V>::find(const std::string& key, uint32_t& bucket) const
{
  uint32_t h0 = h(key);
  bool result = false;

  while (true) 
  {
    int x = tab[h0];
    if (x==-1) break;

    const entry& e = v[x];
    if (strcmp(e.key.c_str(), key.c_str ()) == 0) 
    {
      result = true; 
      break;
    }
    h0 = (h0 + 1) % tsz;
  }

  bucket = h0;
  return result;
}


/*******************************************************************************
  Find the hash bucket for the given key. 

  If the key is already in the map, return true and its hash bucket. If the key
  is not already in the map, return false and the (free) hash bucket where the
  key should be inserted. 
********************************************************************************/
template<class V>
inline bool hashmap<V>::find(const char* key, uint32_t& bucket) const
{
  uint32_t h0 = h(key);
  bool result = false;

  while (true) 
  {
    int x = tab[h0];
    if (x==-1) break;

    const entry& e = v[x];
    if (strcmp(e.key.c_str(),key) == 0) 
    {
      result = true; 
      break; 
    }
    h0 = (h0 + 1) % tsz;
  }

  bucket = h0;
  return result;
}


/*******************************************************************************
  Find the hash bucket for the given key. 

  If the key is already in the map, return true and its hash bucket. If the key
  is not already in the map, return false and the (free) hash bucket where the
  key should be inserted. 

  NOTE: method does case-insesitive string comparison when looking for the key
********************************************************************************/
template<class V>
inline bool hashmap<V>::find(const char* key, uint32_t len, uint32_t& bucket) const
{
  uint32_t h0 = h(key, len);
  bool result = false;

  while (true)
  {
    int x = tab[h0];
    if (x==-1) break;

    const entry& e = v[x];
    if (strncasecmp(e.key.c_str(), key, len)==0) 
    {
      result = true;
      break; 
    }
    h0 = (h0 + 1) % tsz;
  }

  bucket = h0;
  return result;
}


/*******************************************************************************
  Find the hash bucket for the given key. Here, key is the concatenation of key1
  and k2.

  If the key is already in the map, return true and its hash bucket. If the key
  is not already in the map, return false and the (free) hash bucket where the
  key should be inserted. 
********************************************************************************/
template<class V>
inline bool hashmap<V>::find2(
    const char* key1,
    const std::string& key2,
    uint32_t& bucket) const
{
  uint32_t h0 = h(key1, key2);
  bool result = false;

  while (true) 
  {
    int x = tab[h0];
    if (x==-1) break;

    const entry& e = v[x];
    if (e.matchKey2(key1, key2))
    {
      result = true; 
      break;
    }
    h0 = (h0 + 1) % tsz;
  }

  bucket = h0;
  return result;
}


/*******************************************************************************
  The hash functions
********************************************************************************/
template<class V>
inline uint32_t hashmap<V>::h(const std::string& key) const
{
  return  hashfun::h32(key) % tsz;
}


template<class V>
inline uint32_t hashmap<V>::h(const char* key) const
{
  return  hashfun::h32(key, FNV_32_INIT) % tsz;
}


template<class V>
inline uint32_t hashmap<V>::h(const char* key, uint32_t len) const
{
  return  hashfun::h32(key, len, FNV_32_INIT) % tsz;
}


template<class V>
inline uint32_t hashmap<V>::h(const char *key1, const std::string& key2) const
{
  return  hashfun::h32(key2, hashfun::h32(key1)) % tsz;
}



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
  return hashfun::h64((void*)buf,8,FNV_64_INIT) % dsz;
}



} /* namespace zorba  */
#endif  /* ZORBA_HASHMAP_H */
