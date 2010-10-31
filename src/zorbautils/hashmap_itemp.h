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
#ifndef ZORBA_ZORBAUTILS_ITEM_POINTER_HASHMAP
#define ZORBA_ZORBAUTILS_ITEM_POINTER_HASHMAP

#include "zorbautils/hashfun.h"
#include "zorbautils/hashmap.h"

#include "zorbaserialization/serialization_engine.h"
#include "zorbatypes/collation_manager.h"

#include "store/api/item.h"

namespace zorba 
{ 

/***************************************************************************//**
  Class to privide the equality and hash functions for the ItemPointerHashMap
  class defined below.
*******************************************************************************/
class ItemPointerHashMapCmp : public ::zorba::serialization::SerializeBaseClass
{
protected:
  long          theTimeZone;
  XQPCollator * theCollator;

public:
  SERIALIZABLE_CLASS(ItemPointerHashMapCmp);
  SERIALIZABLE_CLASS_CONSTRUCTOR(ItemPointerHashMapCmp);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    ar & theTimeZone;
    ar & theCollator;
  }

public:
  ItemPointerHashMapCmp()
    :
    theTimeZone(0),
    theCollator(NULL)
  {
  }

  ItemPointerHashMapCmp(long tmz, XQPCollator* collator) 
    :
    theTimeZone(tmz),
    theCollator(collator)
  {
  }

  bool equal(const store::Item* t1, const store::Item* t2)
  {
    return t1->equals(t2, theTimeZone, theCollator);
  }

  uint32_t hash(const store::Item* t)
  {
    return t->hash(theTimeZone, theCollator);
  }

  long get_timezone() { return theTimeZone; }
  
  const XQPCollator* get_collator() { return theCollator; }
};


/*******************************************************************************
  A hash-based map container mapping item pointers to values of type V. 
  Equality is based on the Item::equals() method.
*******************************************************************************/
#ifdef ZORBA_UTILS_HASHMAP_WITH_SERIALIZATION

template <class V>
class serializable_ItemPointerHashMap : public serializable_HashMap<store::Item*,
                                                                    V,
                                                                    ItemPointerHashMapCmp>
{
public:

  SERIALIZABLE_TEMPLATE_CLASS(serializable_ItemPointerHashMap)

  serializable_ItemPointerHashMap(::zorba::serialization::Archiver& ar)
    :
    serializable_HashMap<store::Item*, V, ItemPointerHashMapCmp>(ar)
  {
  }

public:
  serializable_ItemPointerHashMap(
        long timezone,
        XQPCollator* collation,
        ulong size,
        bool sync) 
    :
    serializable_HashMap<store::Item*, V, ItemPointerHashMapCmp>(
           ItemPointerHashMapCmp(timezone, collation),
           size,
           sync)
  {
  }
};

#else

template <class V>
class ItemPointerHashMap : public HashMap<store::Item*,
                                          V,
                                          ItemPointerHashMapCmp>
{
public:
  ItemPointerHashMap(
        long timezone,
        XQPCollator* collation,
        ulong size,
        bool sync) 
    :
    HashMap<store::Item*, V, ItemPointerHashMapCmp>(
            ItemPointerHashMapCmp(timezone, collation),
            size,
            sync)
  {
  }
};


#endif


} // namespace zorba

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
