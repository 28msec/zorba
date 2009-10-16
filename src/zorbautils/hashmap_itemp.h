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

#include "store/api/item.h"

namespace zorba 
{ 


/*********************as**********************************************************

  A hash-based map container mappin item pointers to values of type V. Equality
  is based on the Item::equals() method.

********************************************************************************/
template <class V>
class ItemPointerHashMap
{
public:

  class CompareFunction
  {
  protected:
    long               theTimeZone;
    const XQPCollator* theCollation;

  public:
    CompareFunction(long tmz, const XQPCollator* collation) 
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

  typedef typename HashMap<const store::Item*, V, CompareFunction>::iterator iterator;

private:
  HashMap<const store::Item*, V, CompareFunction>  theMap;

public:
  ItemPointerHashMap(
        long timezone,
        const XQPCollator* collation,
        ulong size,
        bool sync) 
    :
    theMap(CompareFunction(timezone, collation), size, sync)
  {
  }

  iterator begin() { return theMap.begin(); }

  iterator end() { return theMap.end(); }

  bool empty() const { return theMap.empty(); }

  void clear() { theMap.clear(); }

  bool get(const store::Item* key, V& value) { return theMap.get(key, value); }

  bool find(const store::Item* key) { return theMap.find(key); }

  bool insert(const store::Item* key, V& value) { return theMap.insert(key, value); }

  bool update(const store::Item* key, V& value) { return theMap.update(key, value); }

  bool remove(const store::Item* key) { return theMap.remove(key); }
};


} // namespace zorba

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
