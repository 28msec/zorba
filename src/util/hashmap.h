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

#if !defined ZORBA_HASHMAP_H && !defined ZORBA_HASHMAP_WITH_SERIALIZATION || !defined ZORBA_HASHMAP_SERIALIZATION_H && defined ZORBA_HASHMAP_WITH_SERIALIZATION
#ifndef ZORBA_HASHMAP_WITH_SERIALIZATION
#define ZORBA_HASHMAP_H
#else
#define ZORBA_HASHMAP_SERIALIZATION_H
#endif

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

#include "zorbaserialization/serialize_basic_types.h"


namespace zorba {

#ifdef ZORBA_HASHMAP_WITH_SERIALIZATION
#define HASHMAP  serializable_hashmap
#else
#define HASHMAP hashmap
#endif

/*___________________________________________________________
|
|  Hash map: string (or equivalent) -> <class V>
|____________________________________________________________*/

template<class K, class V>   // V = value type, K = key type
class HASHMAP    // key type = string
#ifdef ZORBA_HASHMAP_WITH_SERIALIZATION
                  : public ::zorba::serialization::SerializeBaseClass   
#endif
{
public:
  struct entry 
#ifdef ZORBA_HASHMAP_WITH_SERIALIZATION
    : public ::zorba::serialization::SerializeBaseClass
#endif
  {
    K key;
    V val;

    public:
#ifdef ZORBA_HASHMAP_WITH_SERIALIZATION
      SERIALIZABLE_TEMPLATE_CLASS(entry)
      entry(::zorba::serialization::Archiver &ar) : val(ar) {}
      void serialize(::zorba::serialization::Archiver &ar)
      {
        ar & key;
        ar & val;
      }
#endif
    entry() {}

    entry(K const& k, V v) : key(k), val(v) {}

    entry(char const* k, uint32_t l, V v) : key(K(k,0,l)), val(v) {}

    entry(entry const& e) :
#ifdef ZORBA_HASHMAP_WITH_SERIALIZATION
      ::zorba::serialization::SerializeBaseClass(),
#endif
      key(e.key), val(e.val) {}

    entry(const char* k1, K const& k2, V v) : val(v)
    {
      key = k1;
      key += k2;
      //val = v;
    }

#ifdef ZORBA_HASHMAP_WITH_SERIALIZATION
    virtual ~entry() {}
#else
    ~entry() {}
#endif
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
#ifdef ZORBA_HASHMAP_WITH_SERIALIZATION
  SERIALIZABLE_TEMPLATE_CLASS(serializable_hashmap)
  serializable_hashmap(::zorba::serialization::Archiver &ar) : ::zorba::serialization::SerializeBaseClass()
  {
  }
  void serialize(::zorba::serialization::Archiver &ar)
  {
    ar & sz;
    ar & tsz;
    ar & ld;
    ar & minsz;
    ar & v;
    //ar & tab;
    //compress tab
    int tab_size = (int)tab.size();
    ar.set_is_temp_field_one_level(true);
    ar & tab_size;
    if(ar.is_serializing_out())
    {
      typename checked_vector<int>::iterator tab_it;
      tab_it = tab.begin();
      int last_val = *tab_it;
      int nr_dupl = 1;
      for(tab_it++; tab_it != tab.end(); tab_it++)
      {
        if((*tab_it) != last_val)
        {
          ar & nr_dupl;
          ar & last_val;
          last_val  = (*tab_it);
          nr_dupl = 1;
        }
        else
          nr_dupl++;
      }
      ar & nr_dupl;
      ar & last_val;
      nr_dupl = 0;
      ar & nr_dupl;
    }
    else
    {
      tab.resize(tab_size);
      int last_val;
      int nr_dupl, i;
      typename checked_vector<int>::iterator  tab_it = tab.begin();
      while(1)
      {
        ar & nr_dupl;
        if(!nr_dupl)
          break;
        ar & last_val;
        for(i=0;i<nr_dupl;i++)
        {
          //tab.push_back(last_val);
          *tab_it = last_val;
          tab_it++;
        }
      }

      assert((int)tab.size() == (int)tab_size);
    }
    ar.set_is_temp_field_one_level(false);
  }
#endif
public:
  HASHMAP(uint32_t sz = 1024, float ld = .6);

  HASHMAP(HASHMAP const&);

#ifdef ZORBA_HASHMAP_WITH_SERIALIZATION
  virtual ~HASHMAP();
#else
  ~HASHMAP();
#endif

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
HASHMAP<K,V>::HASHMAP(uint32_t initial_size, float load_factor)
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
HASHMAP<K,V>::HASHMAP(HASHMAP<K,V> const& m)
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
HASHMAP<K,V>::~HASHMAP()
{
}


/*******************************************************************************

********************************************************************************/
template<class K, class V>
inline void HASHMAP<K,V>::clear()
{
  sz = 0;
  v.clear();
  memset((char*)tab, -1, tsz*sizeof(int));
  //for (uint32_t k=0;k<tsz;++k) tab[k] = -1;
}


/*******************************************************************************

********************************************************************************/
template<class K, class V>
void HASHMAP<K,V>::displayentry(uint32_t n) const
{
  std::cout << "tab["<<n<<"] = ("<<v[n].key<<','<<v[n].val<<std::endl;
}
  

/*******************************************************************************

********************************************************************************/
template<class K, class V>
void HASHMAP<K,V>::displayEntries() const
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
inline void HASHMAP<K,V>::resize()
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
inline bool HASHMAP<K,V>::put(const K& key, V val, bool replace)
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
inline bool HASHMAP<K,V>::put(const char* key, V val, bool replace)
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
inline bool HASHMAP<K,V>::put(const char* key, uint32_t len, V val, bool replace)
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
inline bool HASHMAP<K,V>::put2(
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
inline bool HASHMAP<K,V>::get(const K& key, V& result) const
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
inline bool HASHMAP<K,V>::get(const char* key, V& result) const
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
inline bool HASHMAP<K,V>::get(const char* key, uint32_t len, V& result) const
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
inline bool HASHMAP<K,V>::get2(const char* key1, const K& key2, V& result) const
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
inline bool HASHMAP<K,V>::find(const K& key, uint32_t& bucket) const
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
inline bool HASHMAP<K,V>::find(const char* key, uint32_t& bucket) const
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
inline bool HASHMAP<K,V>::find(const char* key, uint32_t len, uint32_t& bucket) const
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
inline bool HASHMAP<K,V>::find2(
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
inline uint32_t HASHMAP<K,V>::h(const K& key) const
{
  return  hashfun::h32(key.c_str(), FNV_32_INIT) % tsz;
}


template<class K, class V>
inline uint32_t HASHMAP<K,V>::h(const char* key) const
{
  return  hashfun::h32(key, FNV_32_INIT) % tsz;
}


template<class K, class V>
inline uint32_t HASHMAP<K,V>::h(const char* key, uint32_t len) const
{
  return  hashfun::h32(key, len, FNV_32_INIT) % tsz;
}


template<class K, class V>
inline uint32_t HASHMAP<K,V>::h(const char *key1, const K& key2) const
{
  return  hashfun::h32(key2.c_str(), key2.length(), hashfun::h32(key1)) % tsz;
}


#undef HASHMAP

} /* namespace zorba  */
#endif  /* ZORBA_HASHMAP_H */
/* vim:set et sw=2 ts=2: */
