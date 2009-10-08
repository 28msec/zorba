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
#if !defined ZORBA_ZORBAUTILS_ITEM_POINTER_HASHMAP_H && !defined ZORBA_ZORBAUTILS_ITEM_POINTER_HASHMAP_WITH_SERIALIZATION || !defined ZORBA_ZORBAUTILS_ITEM_POINTER_HASHMAP_SERIALIZATION_H && defined ZORBA_ZORBAUTILS_ITEM_POINTER_HASHMAP_WITH_SERIALIZATION
#ifndef ZORBA_ZORBAUTILS_ITEM_POINTER_HASHMAP_WITH_SERIALIZATION
#define ZORBA_ZORBAUTILS_ITEM_POINTER_HASHMAP_H
#else
#define ZORBA_ZORBAUTILS_ITEM_POINTER_HASHMAP_SERIALIZATION_H
#endif

#include "zorbautils/hashfun.h"
#ifdef ZORBA_ZORBAUTILS_ITEM_POINTER_HASHMAP_WITH_SERIALIZATION
#define ZORBA_UTILS_HASHMAP_WITH_SERIALIZATION
#endif
#include "zorbautils/hashmap.h"
#ifdef ZORBA_ZORBAUTILS_ITEM_POINTER_HASHMAP_WITH_SERIALIZATION
#undef ZORBA_UTILS_HASHMAP_WITH_SERIALIZATION
#endif

#include "store/api/item.h"

namespace zorba 
{ 

#ifdef ZORBA_ZORBAUTILS_ITEM_POINTER_HASHMAP_WITH_SERIALIZATION
#define ITEMPOINTERHASHMAP        serializable_ItemPointerHashMap
#define HASHMAP_UTILS             serializable_HashMap
#define COMPAREFUNCTION           serializable_CompareFunction
#else
#define ITEMPOINTERHASHMAP        ItemPointerHashMap
#define HASHMAP_UTILS             HashMap
#define COMPAREFUNCTION           COMPAREFUNCTION
#endif

/*********************as**********************************************************

  A hash-based map container mappin item pointers to values of type V. Equality
  is based on the Item::equals() method.

********************************************************************************/
template <class V>
class ITEMPOINTERHASHMAP 
#ifdef ZORBA_ZORBAUTILS_ITEM_POINTER_HASHMAP_WITH_SERIALIZATION
  : public ::zorba::serialization::SerializeBaseClass   
#endif
{
public:

  class COMPAREFUNCTION 
#ifdef ZORBA_ZORBAUTILS_ITEM_POINTER_HASHMAP_WITH_SERIALIZATION
    : public ::zorba::serialization::SerializeBaseClass   
#endif
  {
  protected:
    long               theTimeZone;
    /*const*/ XQPCollator* theCollation;

#ifdef ZORBA_ZORBAUTILS_ITEM_POINTER_HASHMAP_WITH_SERIALIZATION
  public:
    SERIALIZABLE_TEMPLATE_CLASS(COMPAREFUNCTION)
    SERIALIZABLE_CLASS_CONSTRUCTOR(COMPAREFUNCTION)
    void serialize(::zorba::serialization::Archiver &ar)
    {
      ar & theTimeZone;
      ar & theCollation;
    }
#endif
  public:
    COMPAREFUNCTION(long tmz, /*const */ XQPCollator* collation) 
      :
      theTimeZone(tmz),
      theCollation(collation)
    {
    }

    bool equal(const store::Item* t1, const store::Item* t2)
    {
      return t1->equals(t2, theTimeZone, theCollation);
    }

    uint32_t hash(const store::Item* t)
    {
      return t->hash(theTimeZone, theCollation);
    }
  };

#ifdef ZORBA_ZORBAUTILS_ITEM_POINTER_HASHMAP_WITH_SERIALIZATION
  typedef typename serializable_HashMap</*const*/ store::Item*, V, COMPAREFUNCTION >::iterator iterator;
#else
  typedef typename HashMap<const store::Item*, V, COMPAREFUNCTION >::iterator iterator;
#endif

private:
#ifdef ZORBA_ZORBAUTILS_ITEM_POINTER_HASHMAP_WITH_SERIALIZATION
  HASHMAP_UTILS</*const*/ store::Item*, V, COMPAREFUNCTION >  theMap;
#else
  HASHMAP_UTILS<const store::Item*, V, COMPAREFUNCTION >  theMap;
#endif

#ifdef ZORBA_ZORBAUTILS_ITEM_POINTER_HASHMAP_WITH_SERIALIZATION
public:
  SERIALIZABLE_TEMPLATE_CLASS(ITEMPOINTERHASHMAP)
  ITEMPOINTERHASHMAP(::zorba::serialization::Archiver &ar) : theMap(ar) {}
  void serialize(::zorba::serialization::Archiver &ar)
  {
    ar & theMap;
  }
#endif
public:
  ITEMPOINTERHASHMAP(
        long timezone,
        /*const */ XQPCollator* collation,
        ulong size,
        bool sync) 
    :
    theMap(COMPAREFUNCTION(timezone, collation), size, sync)
  {
  }

  iterator begin() { return theMap.begin(); }

  iterator end() { return theMap.end(); }

  bool empty() const { return theMap.empty(); }

  void clear() { theMap.clear(); }

  bool get(const store::Item* key, V& value) { return theMap.get((store::Item*)key, value); }

  bool find(const store::Item* key) { return theMap.find((store::Item*)key); }

#ifdef ZORBA_ZORBAUTILS_ITEM_POINTER_HASHMAP_WITH_SERIALIZATION
  bool insert(/*const */store::Item* key, V& value) { return theMap.insert(key, value); }
#else
  bool insert(const store::Item* key, V& value) { return theMap.insert(key, value); }
#endif
  bool update(const store::Item* key, V& value) { return theMap.update((store::Item*)key, value); }

  bool remove(const store::Item* key) { return theMap.remove((store::Item*)key); }
};


#undef ITEMPOINTERHASHMAP
#undef HASHMAP_UTILS
#undef COMPAREFUNCTION

} // namespace zorba

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
