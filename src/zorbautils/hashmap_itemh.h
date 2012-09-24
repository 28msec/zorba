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

#ifndef HASHMAP_ITEMH_H
#define HASHMAP_ITEMH_H

#include "zorbautils/hashfun.h"
#include "zorbautils/hashmap.h"

#include "store/api/item.h"

namespace zorba 
{ 

class ItemHandleHashMapCmp
{
protected:
  long          theTimeZone;
  XQPCollator * theCollator;

public:
  ItemHandleHashMapCmp()
    :
    theTimeZone(0),
    theCollator(NULL)
  {
  }

  ItemHandleHashMapCmp(long tmz, XQPCollator* collator) 
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


/*******************************************************************************
  A hash-based map mapping item handles to data items of type V. Equality is
  based on the store::Item::equals() method.

  It is used to map annotation names to annotation ids.

  NOTE: Although the map uses raw item pointers instead of rchandles, reference
        counting is still done, but done manually (see insert and clear methods)
********************************************************************************/
template <class V>
class ItemHandleHashMap
{
public:
  typedef typename HashMap<store::Item*, V, ItemHandleHashMapCmp>::iterator iterator;

private:
  HashMap<store::Item*, V, ItemHandleHashMapCmp> theMap;

public:
  ItemHandleHashMap(
        long timezone,
        XQPCollator* collation,
        ulong size,
        bool sync) 
    :
    theMap(ItemHandleHashMapCmp(timezone, collation), size, sync)
  {
  }
  
 ~ItemHandleHashMap()
  {
    clear();
  }

  void clear()
  {
    SYNC_CODE(AutoMutex lock(theMap.get_mutex());)

    iterator ite = this->begin();
    iterator end = this->end();

    for (; ite != end; ++ite)
    {
      (*ite).first->removeReference();
    }

    theMap.clearNoSync();
  }
  
  iterator begin() const { return theMap.begin(); }

  iterator end() const { return theMap.end(); }

  iterator find(const store::Item_t& item)
  {
    return theMap.find(item.getp());
  }

  bool insert(const store::Item_t& item, V& value)
  {
    bool inserted = theMap.insert(item.getp(), value);
                    
    if (inserted)
      item->addReference();

    return inserted;
  }

  bool erase(const store::Item_t& key)
  {
    bool found = theMap.erase(key.getp());

    if (found)
      key->removeReference();

    return found;
  }

};

}

#endif
