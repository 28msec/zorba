#ifndef ZORBA_STORE_UTIL_HASHSET
#define ZORBA_STORE_UTIL_HASHSET

#include "util/checked_vector.h"

#include "common/shared_types.h"

#include "store/util/mutex.h"
#include "store/util/hashmap.h"

namespace zorba { namespace store {


class DummyHashValue
{
};


/*******************************************************************************

********************************************************************************/
template <class T, class E, class C = DummyCompareParam>
class HashSet : public HashMap<T, DummyHashValue, E, C>
{
public:

HashSet(ulong size) : HashMap<T, DummyHashValue, E, C>(size) 
{
}


HashSet(C* compParam, ulong size) :  HashMap<T, DummyHashValue, E, C>(compParam, size) 
{
}


virtual ~HashSet()
{
}

/*******************************************************************************

********************************************************************************/
void clear() 
{
  HashMap<T, DummyHashValue, E, C>::clear();
}


/*******************************************************************************
  Return true if the set already contains an item that is "equal" to the given
  item; otherwise return false.
********************************************************************************/
bool find(const T& item)
{
  return HashMap<T, DummyHashValue, E, C>::find(item);
}


/******************************************************************************
  If the set does not already contain an item that is "equal" to the given item,
  insert the given item to the set and return true. Otherwise, return false.
********************************************************************************/
bool insert(T& item)
{
  bool found;

  SYNC_CODE(AutoMutex lock(this->theMutex);)

  HashEntry<T, DummyHashValue>* entry;
  entry = hashInsert(item,
                     Externals<T,E,C>::hash(item, this->theCompareParam),
                     found);

  if (!found)
    entry->theItem = (item);

  return !found;
}


/******************************************************************************
  If the set does not already contain an item I that is "equal" to the given
  item, insert the given item to the set and return true. Otherwise, return
  false and an rchandle to the found item I.
********************************************************************************/
bool insert(T& item,  T& outItem)
{
  bool found;

  SYNC_CODE(AutoMutex lock(this->theMutex);)

  HashEntry<T, DummyHashValue>* entry;
  entry = hashInsert(item,
                     Externals<T,E,C>::hash(item, this->theCompareParam),
                     found);
  if (!found)
  {
    entry->theItem = item;
    outItem = entry->theItem;
    return true;
  }
  else
  {
    outItem = entry->theItem;
    return false;
  }
}


/*******************************************************************************
  If the set contains an item that is "equal" to the given item, remove that
  item from the set and return true. Otherwise, return false.
********************************************************************************/
bool remove(const T& item)
{
  return HashMap<T, DummyHashValue, E, C>::remove(item);
}

};


} // namespace store
} // namespace zorba

#endif
