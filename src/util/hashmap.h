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

#ifndef ZORBA_UTILS_HASHMAP
#define ZORBA_UTILS_HASHMAP

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

#include "diagnostics/xquery_diagnostics.h"

namespace zorba 
{

/*___________________________________________________________
|
|  Hash map: string (or equivalent) -> <class V>
|____________________________________________________________*/

template<class K, class V>   // V = value type, K = key type
class hashmap
{
public:
  struct entry 
  {
    K key;
    V val;

  public:
    entry() {}

    entry(K const& k, V v) : key(k), val(v) {}

    entry(char const* k, uint32_t l, V v) : key(K(k,0,l)), val(v) {}

    entry(entry const& e) : key(e.key), val(e.val) {}

    entry(const char* k1, K const& k2, V v) : val(v)
    {
      key = k1;
      key += k2;
    }

    ~entry() {}

    entry& operator=(entry const& e) 
    {
      key = e.key; val = e.val; return *this; 
    }

    bool matchKey2(const char* key1, const K& key2) const
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

  hashmap(const hashmap&);

  ~hashmap();

public: // housekeeping
  void clear();
  uint32_t size() const    { return sz; }   // return the number of hashed entries
  float load() const       { return ld; }   // return the load factor
  uint32_t tabSize() const { return tsz; }  // return the current hash table size
  void resize();                            // double the hash table

  V getentryVal(uint32_t n) const { return v[n].val; }
  const K& getentryKey(uint32_t n) const { return v[n].key; }
  void displayentry(uint32_t n) const;
  void displayEntries() const;

public: // iterator interface
  typename checked_vector<entry>::iterator begin() { return v.begin(); }
  typename checked_vector<entry>::iterator end() { return v.end(); }
  typename checked_vector<entry>::const_iterator begin() const { return v.begin(); }
  typename checked_vector<entry>::const_iterator end() const { return v.end(); }

public: // map interface
  bool put(K const& key, V val, bool replace = true); 
  bool put(char const* key, V val, bool replace = true); 
  bool put(char const* key, uint32_t, V val, bool replace = true);
  bool put2(const char* key1, K const& key2, V val, bool replace = true);

  bool find(K const& key, uint32_t& index) const; 
  bool find(char const* key, uint32_t& index) const;
  bool find(char const* key, uint32_t len, uint32_t&) const;
  bool find2(const char* key1, K const& key2, uint32_t& index) const;

  bool get(K const& key, V& result) const;
  bool get(char const* key, V& result) const;
  bool get(char const* key, uint32_t, V&) const;
  bool get2(const char *key1, K const& key2, V& result) const;

public: // the hash functions
  uint32_t h(K const& key) const;
  uint32_t h(char const*) const;
  uint32_t h(char const*, uint32_t len) const;
  uint32_t h(const char* key1, const K& key2) const;

};

/*******************************************************************************

********************************************************************************/
template<class K, class V>
hashmap<K,V>::hashmap(uint32_t initial_size, float load_factor)
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
template<class K, class V>
hashmap<K,V>::hashmap(hashmap<K,V> const& m)
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
template<class K, class V>
hashmap<K,V>::~hashmap()
{
}


/*******************************************************************************

********************************************************************************/
template<class K, class V>
inline void hashmap<K,V>::clear()
{
  sz = 0;
  v.clear();
  memset((char*)tab, -1, tsz*sizeof(int));
  //for (uint32_t k=0;k<tsz;++k) tab[k] = -1;
}


/*******************************************************************************

********************************************************************************/
template<class K, class V>
void hashmap<K,V>::displayentry(uint32_t n) const
{
  std::cout << "tab["<<n<<"] = ("<<v[n].key<<','<<v[n].val<<std::endl;
}
  

/*******************************************************************************

********************************************************************************/
template<class K, class V>
void hashmap<K,V>::displayEntries() const
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
template<class K, class V>
inline void hashmap<K,V>::resize()
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
template<class K, class V>
inline bool hashmap<K,V>::put(const K& key, V val, bool replace)
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
template<class K, class V>
inline bool hashmap<K,V>::put(const char* key, V val, bool replace)
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
template<class K, class V>
inline bool hashmap<K,V>::put(const char* key, uint32_t len, V val, bool replace)
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
  key is the concatenation of key1 and key2. If key is in the map already, and 
  "replace" is true, the value associated with key is replaced with the new value. 

  Return true if key was in map already, else false.
********************************************************************************/
template<class K, class V>
inline bool hashmap<K,V>::put2(
    const char* key1,
    const K& key2,
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
template<class K, class V>
inline bool hashmap<K,V>::get(const K& key, V& result) const
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
template<class K, class V>
inline bool hashmap<K,V>::get(const char* key, V& result) const
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
template<class K, class V>
inline bool hashmap<K,V>::get(const char* key, uint32_t len, V& result) const
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
template<class K, class V>
inline bool hashmap<K,V>::get2(const char* key1, const K& key2, V& result) const
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
template<class K, class V>
inline bool hashmap<K,V>::find(const K& key, uint32_t& bucket) const
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
template<class K, class V>
inline bool hashmap<K,V>::find(const char* key, uint32_t& bucket) const
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
template<class K, class V>
inline bool hashmap<K,V>::find(const char* key, uint32_t len, uint32_t& bucket) const
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
template<class K, class V>
inline bool hashmap<K,V>::find2(
    const char* key1,
    const K& key2,
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
template<class K, class V>
inline uint32_t hashmap<K,V>::h(const K& key) const
{
  return  hashfun::h32(key.c_str(), FNV_32_INIT) % tsz;
}


template<class K, class V>
inline uint32_t hashmap<K,V>::h(const char* key) const
{
  return  hashfun::h32(key, FNV_32_INIT) % tsz;
}


template<class K, class V>
inline uint32_t hashmap<K,V>::h(const char* key, uint32_t len) const
{
  return  hashfun::h32(key, len, FNV_32_INIT) % tsz;
}


template<class K, class V>
inline uint32_t hashmap<K,V>::h(const char* key1, const K& key2) const
{
  return  hashfun::h32(key2.c_str(), key2.length(), hashfun::h32(key1)) % tsz;
}


} /* namespace zorba  */
#endif  /* ZORBA_HASHMAP_H */
/* vim:set et sw=2 ts=2: */
