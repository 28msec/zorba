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

#include "zorbatypes/collation_manager.h"

#include "zorbaserialization/class_serializer.h"
#include "zorbaserialization/serialize_basic_types.h"

#include "store/api/item.h"

namespace zorba 
{ 

/***************************************************************************//**
  Class to privide the equality and hash functions for the ItemPointerHashMap
  class defined below.
*******************************************************************************/
class ser_ItemPointerHashMapCmp : public ::zorba::serialization::SerializeBaseClass
{
protected:
  long          theTimeZone;
  XQPCollator * theCollator;

public:
  SERIALIZABLE_CLASS(ser_ItemPointerHashMapCmp);
  SERIALIZABLE_CLASS_CONSTRUCTOR(ser_ItemPointerHashMapCmp);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    ar & theTimeZone;
    ar & theCollator;
  }

public:
  ser_ItemPointerHashMapCmp()
    :
    theTimeZone(0),
    theCollator(NULL)
  {
  }

  ser_ItemPointerHashMapCmp(long tmz, XQPCollator* collator) 
    :
    theTimeZone(tmz),
    theCollator(collator)
  {
  }

  bool equal(const store::Item* t1, const store::Item* t2) const
  {
    return t1->equals(t2, theTimeZone, theCollator);
  }

  uint32_t hash(const store::Item* t) const
  {
    return t->hash(theTimeZone, theCollator);
  }

  long get_timezone() const { return theTimeZone; }
  
  const XQPCollator* get_collator() const { return theCollator; }
};


#define ITEM_PTR_HASH_MAP(ValueType, MapType) \
typedef HashMap<store::Item*, ValueType, ser_ItemPointerHashMapCmp> MapType;


/***************************************************************************//**
  Class to privide the equality and hash functions for the ItemPointerHashMap
  class defined below.
*******************************************************************************/
class ItemPointerHashMapCmp
{
protected:
  long          theTimeZone;
  XQPCollator * theCollator;

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

  bool equal(const store::Item* t1, const store::Item* t2) const
  {
    return t1->equals(t2, theTimeZone, theCollator);
  }

  uint32_t hash(const store::Item* t) const
  {
    return t->hash(theTimeZone, theCollator);
  }

  long get_timezone() const { return theTimeZone; }
  
  const XQPCollator* get_collator() const { return theCollator; }
};


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



} // namespace zorba

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
