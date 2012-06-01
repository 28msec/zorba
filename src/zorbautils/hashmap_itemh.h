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


template <class V>
class ItemHandleHashMap : public HashMap<store::Item*,
                                         V,
                                         ItemHandleHashMapCmp>
{
public:
  typedef typename HashMap<store::Item*, V, ItemHandleHashMapCmp>::iterator iterator;

public:
  ItemHandleHashMap(
        long timezone,
        XQPCollator* collation,
        ulong size,
        bool sync) 
    :
    HashMap<store::Item*, V, ItemHandleHashMapCmp>(
            ItemHandleHashMapCmp(timezone, collation),
            size,
            sync)
  {
  }
  
 ~ItemHandleHashMap()
  {
    iterator ite = this->begin();
    iterator end = this->end();

    for (; ite != end; ++ite)
    {
      (*ite).first->removeReference();
    }
  }

  void clear()
  {
    SYNC_CODE(AutoMutex lock(this->theMutexp);)

    iterator ite = this->begin();
    iterator end = this->end();

    for (; ite != end; ++ite)
    {
      (*ite).first->removeReference();
    }

    HashMap<store::Item*, V, ItemHandleHashMapCmp>::clearNoSync();
  }
  
  void eraseEntry(
      HashEntry<store::Item*, V>* entry,
      HashEntry<store::Item*, V>* preventry)
  {
    entry->theItem->removeReference();

    HashMap<store::Item*, V, ItemHandleHashMapCmp>::eraseEntry(entry, preventry);
  }

  iterator find(const store::Item_t& item)
  {
    return HashMap<store::Item*, V, ItemHandleHashMapCmp>::find(item.getp());
  }

  bool insert(const store::Item_t& item, V& value)
  {
    bool inserted = 
    HashMap<store::Item*, V, ItemHandleHashMapCmp>::insert(item.getp(), value);
                    
    if (inserted)
      item->addReference();

    return inserted;
  }
};

}

#endif
