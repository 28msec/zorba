
#include <zorba/hashfun.h>

#include "util/Assert.h"
#include "system/globalenv.h"
#include "store/naive/qname_pool.h"
#include "store/naive/atomic_items.h"
#include "store/naive/simple_store.h"
#include "store/naive/store_defs.h"

namespace zorba { namespace store {

const float QNamePool::DEFAULT_LOAD_FACTOR = 0.6f;


/*******************************************************************************

********************************************************************************/
QNamePool::QNamePool(ulong size) 
  :
  theCache(new QNameItemImpl[size]),
  theCacheSize(size),
  theFirstFree(1),
  theNumFree(size - 1),
  theNumQNames(0),
  theHashTabSize(2 * size),
  theLoadFactor(DEFAULT_LOAD_FACTOR)
{
  // Put all the preallocated slots in the free list of the cahce.
  QNameItemImpl* qn = &theCache[1];
  QNameItemImpl* last = qn + size - 1;

  for (ulong i = 1; qn < last; qn++, i++)
  {
    qn->theNextFree = i + 1;
    qn->thePrevFree = i - 1;
    qn->thePosition = i;
  }
  (--qn)->theNextFree = 0;

  // Allocate the hash table. Its initial size is double the size of theCache,
  // plus an inital 32 overflow entries.
  theHashTab.resize(theHashTabSize + 32);

  // Format the overflow area of theHashTab as a list of free entries
  HashEntry* lastentry = &theHashTab[theHashTabSize + 31];
  for (HashEntry* entry = &theHashTab[theHashTabSize]; entry < lastentry; entry++)
    entry->theNext = entry + 1;
}


/*******************************************************************************

********************************************************************************/
QNamePool::~QNamePool() 
{
  ulong n = theHashTab.size();
  for (ulong i = 0; i < n; i++)
  {
    if (theHashTab[i].theQNameSlot != NULL &&
        theHashTab[i].theQNameSlot->isOverflow())
    {
      delete theHashTab[i].theQNameSlot;
    }
  }

  if (theCache != NULL)
  {
    delete [] theCache;
    theCache = NULL;
  }
}


/*******************************************************************************

********************************************************************************/
Item_t QNamePool::insert(
    const char* ns,
    const char* pre,
    const char* ln)
{
  QNameItemImpl* qn;
  bool found;

  SimpleStore& store = GET_STORE();

  if (ns == NULL) ns = "";
  if (pre == NULL) pre = "";
  Assert(ln != NULL && *ln != '\0');

  xqpStringStore_t pooledNs;
  store.getNamespacePool().insertc(ns, pooledNs);

  AutoMutex lock(theMutex);

  HashEntry* entry = hashInsert(pooledNs->c_str(), pre, ln,
                                pooledNs->bytes(), strlen(pre), strlen(ln),
                                found);

  qn = cacheInsert(entry);

  if (!found)
  {
    qn->theNamespace = pooledNs;
    qn->thePrefix = new xqpStringStore(pre);
    qn->theLocal = new xqpStringStore(ln);
  }

  return qn;
}


/*******************************************************************************

********************************************************************************/
Item_t QNamePool::insert(
    xqpStringStore* ns,
    xqpStringStore* pre,
    xqpStringStore* ln)
{
  QNameItemImpl* qn;
  bool found;

  AutoMutex lock(theMutex);

  HashEntry* entry = hashInsert(ns->c_str(), pre->c_str(), ln->c_str(),
                                ns->bytes(), pre->bytes(), ln->bytes(),
                                found);

  qn = cacheInsert(entry);

  if (!found)
  {
    qn->theNamespace = ns;
    qn->thePrefix = pre;
    qn->theLocal = ln;
  }

  return qn;
}


/*******************************************************************************

********************************************************************************/
QNameItemImpl* QNamePool::cacheInsert(HashEntry* entry)
{
  QNameItemImpl* qnslot;

  // If the qname is already in the pool, return a ptr to its containing slot.
  // If the slot is in the free list of the cache, it is first removed from
  // that list.  
  if (entry->theQNameSlot != NULL)
  {
    qnslot = entry->theQNameSlot;

    if (qnslot->isInCache())
    {
      if (qnslot->theNextFree != 0)
        theCache[qnslot->theNextFree].thePrevFree = qnslot->thePrevFree;

      if (qnslot->thePrevFree != 0)
      {
        theCache[qnslot->thePrevFree].theNextFree = qnslot->theNextFree;
      }
      else if (theFirstFree == qnslot->thePosition)
      {
        theFirstFree = qnslot->theNextFree;
      }

      qnslot->theNextFree = qnslot->thePrevFree = 0;
      theNumFree--;
    }

    return qnslot;
  }

  // The qname is not in the pool.
  // Use the 1st slot from the free list of the cache to store the new qname.
  // The qname is currently in that slot is removed from the cache.
  if (theFirstFree != 0)
  {
    qnslot = &theCache[theFirstFree];
    entry->theQNameSlot = qnslot;

    theFirstFree = qnslot->theNextFree;
    theCache[theFirstFree].thePrevFree = 0;

    if (qnslot->theLocal != NULL)
      hashRemove(qnslot->theNamespace, qnslot->thePrefix, qnslot->theLocal);

    qnslot->theNextFree = qnslot->thePrevFree = 0;

    theNumFree--;
    return qnslot;
  }

  // The cache was full, so allocate a QNameItem from the heap.
  qnslot = new QNameItemImpl();
  entry->theQNameSlot = qnslot;
  return qnslot;
}


/*******************************************************************************
  Check if the given qname is already in the pool, and if so, return its hash
  entry. If not, allocate a new hash entry for it, and return it to the caller.
********************************************************************************/
QNamePool::HashEntry* QNamePool::hashInsert(
    const char* ns,
    const char* pre,
    const char* ln,
    ulong       nslen,
    ulong       prelen,
    ulong       lnlen,
    bool&       found)
{
  HashEntry* entry;
  HashEntry* lastentry;

  found = false;

  // Get ptr to the 1st entry of the hash bucket corresponding to the given qname
  ulong hval = hashfun::h32(pre, hashfun::h32(ln, hashfun::h32(ns)));
  entry = &theHashTab[hval % theHashTabSize];

  // If the hash bucket is empty, its 1st entry is used to store the new qname.
  if (entry->theQNameSlot == NULL)
  {
    theNumQNames++;
    return entry;
  }

  // Search the hash bucket looking for the given qname.
  while (entry != NULL)
  {
    QNameItemImpl* qnslot = entry->theQNameSlot;

    if (qnslot->theLocal->byteEqual(ln, lnlen) &&
        qnslot->theNamespace->byteEqual(ns, nslen) &&
        qnslot->thePrefix->byteEqual(pre, prelen))
    {
      found = true;
      return entry;
    }

    lastentry = entry;
    entry =  entry->theNext;
  }

  // The qname was not found.
  theNumQNames++;

  // Double the size of hash table if it is more than 60% full. 
  if (theNumQNames > theHashTabSize * theLoadFactor)
  {
    resizeHashTab();

    hval = hashfun::h32(pre, hashfun::h32(ln, hashfun::h32(ns))) % theHashTabSize;
    entry = &theHashTab[ hval % theHashTabSize];

    if (entry->theQNameSlot == NULL)
      return entry;

    while (entry != NULL)
    {
      lastentry = entry;
      entry =  entry->theNext;
    }
  }

  // Get an entry from the free list in the overflow section of the hash teble
  // If no free entry exists, a new entry is appended into the hash table. 
  if (theHashTab[theHashTabSize].theNext == 0)
  {
    theHashTab.push_back(HashEntry());
    entry = &theHashTab[theHashTab.size() - 1];
    lastentry->theNext = entry;
  }
  else
  {
    entry = theHashTab[theHashTabSize].theNext;
    theHashTab[theHashTabSize].theNext = entry->theNext;
    lastentry->theNext = entry;
    entry->theNext = NULL;
  }

  return entry;
}


/*******************************************************************************

********************************************************************************/
void QNamePool::remove(QNameItemImpl* qn)
{
  if (qn->getRefCount(qn->getSync()) > 0)
    return;

  AutoMutex lock(theMutex);

  if (qn->isInCache())
  {
    qn->theNextFree = theFirstFree;
    theCache[theFirstFree].thePrevFree = qn->thePosition;
    theFirstFree = qn->thePosition;
    theNumFree++;
  }
  else
  {
    // If all the pointers to QNameItems were smart pointers, we could leave
    // qn in the pool, and let the pool garbage-collect it later (if it still
    // unused). If however QNameItems may be referenced by regular pointers as
    // well, then qn must be removed from the pool and really deleted
    hashRemove(qn->theNamespace, qn->thePrefix, qn->theLocal);
    delete qn;
  }
}


/*******************************************************************************
  Remove the given qname from the hash table, if it is found there.
********************************************************************************/
void QNamePool::hashRemove(
   xqpStringStore* ns,
   xqpStringStore* pre,
   xqpStringStore* ln)
{
  HashEntry* entry;
  HashEntry* preventry = NULL;

  // Get ptr to the 1st entry of the hash bucket corresponding to the given qname
  ulong hval = hashfun::h32(pre->c_str(),
                                hashfun::h32(ln->c_str(),
                                             hashfun::h32(ns->c_str())));
  entry = &theHashTab[hval % theHashTabSize];

  // If the hash bucket is empty, the qname is not in the hash table.
  if (entry->theQNameSlot == NULL)
    return;

  // Search the hash bucket looking for the given qname.
  while (entry != NULL)
  {
    QNameItemImpl* qnslot = entry->theQNameSlot;

    if (!qnslot->theLocal->byteEqual(*ln) ||
        !qnslot->theNamespace->byteEqual(*ns) ||
        !qnslot->thePrefix->byteEqual(*pre))
    {
      preventry = entry;
      entry =  entry->theNext;
    }

    // Found the qname in the current entry. Must remove the entry from the
    // hash bucket and add it to the free list.
    if (preventry != NULL)
    {
      preventry->theNext = entry->theNext;
      entry->theQNameSlot = NULL;
      entry->theNext = theHashTab[theHashTabSize].theNext;
      theHashTab[theHashTabSize].theNext = entry;
    }
    else if (entry->theNext != NULL)
    {
      HashEntry* nextentry = entry->theNext;
      *entry = *nextentry;
      nextentry->theQNameSlot = NULL;
      nextentry->theNext = theHashTab[theHashTabSize].theNext;
      theHashTab[theHashTabSize].theNext = nextentry;
    }
    else
    {
      entry->theQNameSlot = NULL;
    }

    theNumQNames--;

    return;
  }
}


/*******************************************************************************

********************************************************************************/
void QNamePool::resizeHashTab()
{
  HashEntry* entry;
  HashEntry* lastentry;

  // Make a copy of theHashTab, and then resize it to double theHashTabSize
  std::vector<HashEntry> oldTab = theHashTab;
  ulong oldsize = oldTab.size();

  theHashTabSize <<= 1;

  theHashTab.clear();
  theHashTab.resize(theHashTabSize + 32);

  // Format the overflow area of theHashTab as a list of free entries
  lastentry = &theHashTab[theHashTabSize + 31];
  for (entry = &theHashTab[theHashTabSize]; entry < lastentry; entry++)
    entry->theNext = entry + 1;
 
  // Now rehash every entry
  for (ulong i = 0; i < oldsize; i++)
  {
    QNameItemImpl* qn = oldTab[i].theQNameSlot;

    ulong h = hashfun::h32(qn->thePrefix->c_str(),
                           hashfun::h32(qn->theLocal->c_str(),
                                        hashfun::h32(qn->theNamespace->c_str())));
    entry = &theHashTab[h % theHashTabSize];

    if (entry->theQNameSlot != NULL)
    {
      // Go to the last entry of the current bucket
      HashEntry* lastentry = entry;
      while (lastentry->theNext != NULL)
        lastentry = lastentry->theNext;

      // Get an entry from the free list in the overflow section of the hash
      // table. If no free entry exists, a new entry is appended into the table.
      if (theHashTab[theHashTabSize].theNext == 0)
      {
        theHashTab.push_back(HashEntry());
        entry = &theHashTab[theHashTab.size() - 1];
        lastentry->theNext = entry;
      }
      else
      {
        entry = theHashTab[theHashTabSize].theNext;
        theHashTab[theHashTabSize].theNext = entry->theNext;
        lastentry->theNext = entry;
        entry->theNext = NULL;
      }
    }

    entry->theQNameSlot = qn;
  }
}
} // namespace store
} // namespace zorba

