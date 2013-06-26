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
#include "stdafx.h"

#include "diagnostics/assert.h"
#include "system/globalenv.h"

#include "string_pool.h"
#include "qname_pool.h"
#include "atomic_items.h"
#include "simple_store.h"
#include "store_defs.h"
#include "node_items.h"
#include "store/api/collection.h"
#include "zorbatypes/datetime.h"
#include "util/string_util.h"


namespace zorba { namespace simplestore {


/*******************************************************************************

********************************************************************************/
QNamePool::QNamePool(ulong size, StringPool* nspool) 
  :
  theCache(new QNameItem[size]),
  theCacheSize(size),
  theFirstFree(1),
  theNumFree(size - 1),
  theHashSet(2 * size),
  theNamespacePool(nspool)
{
  // Put all the preallocated slots in the free list of the cahce.
  QNameItem* qn = &theCache[1];
  QNameItem* last = qn + size - 1;

  for (csize i = 1; qn < last; ++qn, ++i)
  {
    qn->theNextFree = i + 1;
    qn->thePrevFree = i - 1;
    qn->thePosition = i;
  }
  (--qn)->theNextFree = 0;

  qn = &theCache[0];
  qn->theNextFree =  qn->thePrevFree = qn->thePosition = 0;
}


/*******************************************************************************

********************************************************************************/
QNamePool::~QNamePool() 
{
  csize n = theHashSet.capacity();
  for (csize i = 0; i < n; ++i)
  {
    if (!theHashSet.theHashTab[i].isFree() &&
        theHashSet.theHashTab[i].key()->isOverflow())
      delete theHashSet.theHashTab[i].key();
  }

  if (theCache != NULL)
  {
    delete [] theCache;
    theCache = NULL;
  }
}


/*******************************************************************************

********************************************************************************/
void QNamePool::addInFreeList(QNameItem* qn)
{
  assert(qn->thePrevFree == 0);
  assert(qn->theNextFree == 0);
  assert(qn->getRefCount() == 0);
  assert(theCache[theFirstFree].thePrevFree == 0);

  qn->theNextFree = (uint16_t)theFirstFree;

  if (theFirstFree != 0)
  {
    assert(theCache[theFirstFree].thePosition == theFirstFree);

    theCache[theFirstFree].thePrevFree = qn->thePosition;
  }

  theFirstFree = qn->thePosition;

  assert(theFirstFree > 0 && theFirstFree < theCacheSize);

  ++theNumFree;
}


/*******************************************************************************

********************************************************************************/
void QNamePool::removeFromFreeList(QNameItem* qn)
{
  assert(qn->isInCache());

  if (qn->theNextFree != 0)
  {
    assert(qn->getRefCount() == 0);
    assert(theFirstFree > 0 && theFirstFree < theCacheSize);
    assert(theCache[qn->theNextFree].thePrevFree = qn->thePosition);

    theCache[qn->theNextFree].thePrevFree = qn->thePrevFree;
  }

  if (qn->thePrevFree != 0)
  {
    assert(qn->getRefCount() == 0);
    assert(theFirstFree > 0 && theFirstFree < theCacheSize);
    assert(theCache[qn->thePrevFree].theNextFree = qn->thePosition);
    
    theCache[qn->thePrevFree].theNextFree = qn->theNextFree;
  }
  else if (qn->theNextFree == 0)
  {
    // Either qn does not belong to the free list, or is the only one in the
    // free list
    if (theFirstFree != qn->thePosition)
      return;

    assert(qn->getRefCount() == 0);
    assert(theFirstFree == qn->thePosition);
    assert(theNumFree == 1);

    theFirstFree = qn->theNextFree;
  }
  else
  {
    // qn is the 1st slot in the free list
    assert(qn->getRefCount() == 0);
    assert(theFirstFree == qn->thePosition);

    theFirstFree = qn->theNextFree;
  }

  qn->theNextFree = qn->thePrevFree = 0;

  --theNumFree;
}


/*******************************************************************************

********************************************************************************/
QNameItem* QNamePool::popFreeList()
{
  if (theFirstFree != 0)
  {
    assert(theNumFree > 0);

    QNameItem* qn = &theCache[theFirstFree];

    assert(qn->getRefCount() == 0);

    theFirstFree = qn->theNextFree;

    assert(theFirstFree == 0 ||
           theCache[theFirstFree].thePrevFree == qn->thePosition);

    theCache[theFirstFree].thePrevFree = 0;

    qn->theNextFree = qn->thePrevFree = 0;

    --theNumFree;

    return qn;
  }
  else
  {
    assert(theNumFree == 0);
    return NULL;
  }
}


/*******************************************************************************

********************************************************************************/
void QNamePool::remove(QNameItem* qn)
{
  QNameItem* normVictim = NULL;

  SYNC_CODE(theHashSet.theMutex.lock();)

  try 
  {
    if (qn->getRefCount() > 0)
    {
      SYNC_CODE(theHashSet.theMutex.unlock();)
      return;
    }

    if (qn->isInCache())
    {
      addInFreeList(qn);
    }
    else
    {
      ZORBA_ASSERT(false);
      // If all the pointers to QNameItems were smart pointers, we could leave
      // qn in the pool, and let the pool garbage-collect it later (if it still
      // unused). If however QNameItems may be referenced by regular pointers
      // as well, then qn must be removed from the pool and really deleted.
      theHashSet.eraseNoSync(qn);
      qn->invalidate(true, &normVictim);
      delete qn;
    }

    // Releasing the lock here to avoid deadlock, because decrementing the 
    // normVictim counter might reenter QNamePool::remove.
    SYNC_CODE(theHashSet.theMutex.unlock();)
  }
  catch(...)
  {
    SYNC_CODE(theHashSet.theMutex.unlock();)
              
    ZORBA_FATAL(0, "Unexpected exception");
  }

  if (normVictim)
  {
    assert(normVictim->getRefCount() > 0 && normVictim->getRefCount() < 10000);
    normVictim->removeReference();
  }
}


/*******************************************************************************
  If the pool does not already contain a qname with the given namespace, prefix,
  and local name, then create such a qname, insert it in the pool and return an
  rchandle to it. Otherwise, return an rchandle to the existing qname. 

  Note: The given namespace, prefix, and local name pointers may point to heap 
  or stack allocated strings. If a qname is inserted, then the strings are 
  copied internally into zstring objects. So, it's always the caller who is
  resposnible for freeing the given strings.
********************************************************************************/
void QNamePool::insert(
    store::Item_t& res,
    const char* ns,
    const char* pre,
    const char* ln)
{
  QNameItem* qn;
  QNameItem* normVictim = NULL;
  SYNC_CODE(bool haveLock = false;)
  store::Item_t normItem;
  QNameItem* normQName = NULL;

  bool normalized = (pre == NULL || *pre == '\0');

  if (ns == NULL) ns = "";
  if (pre == NULL) pre = "";
  ZORBA_FATAL(ln != NULL && *ln != '\0', "");

  zstring pooledNs;
  theNamespacePool->insertc(ns, pooledNs);

  ulong hval = hashfun::h32(pre, hashfun::h32(ln, hashfun::h32(ns)));

  try
  {
retry:
    SYNC_CODE(theHashSet.theMutex.lock();\
    haveLock = true;)

    QNHashEntry* entry = 
    hashFind(ns, pre, ln, pooledNs.size(), strlen(pre), strlen(ln), hval);

    if (entry == 0)
    {
      if (normalized)
      {
        // Build a new QName (either new object or in cache).
        qn = cacheInsert(normVictim);
        qn->initializeAsNormalizedQName(pooledNs, ln);
      }
      else
      {
        if (normQName == NULL)
        {
          SYNC_CODE(theHashSet.theMutex.unlock();\
          haveLock = false;)

          insert(normItem, ns, NULL, ln);
          normQName = static_cast<QNameItem*>(normItem.getp());
          goto retry;
        }
        // Build a new QName (either new object or in cache).
        qn = cacheInsert(normVictim);
        qn->initializeAsUnnormalizedQName(normQName, pre);
      }

      bool found;
      entry = theHashSet.hashInsert(qn, hval, found);
      entry->key() = qn;
      ZORBA_FATAL(!found, "");
    }
    else
    {
      qn = entry->key();
      cachePin(qn);
    }

    res = qn;

    SYNC_CODE(theHashSet.theMutex.unlock();\
    haveLock = false;)
  }
  catch (...)
  {
    SYNC_CODE(if (haveLock) \
      theHashSet.theMutex.unlock();)

    ZORBA_FATAL(0, "Unexpected exception");
  }

  if (normVictim != NULL)
  {
    assert(normVictim->getRefCount() > 0 && normVictim->getRefCount() < 10000);
    normVictim->removeReference();
  }
}


/*******************************************************************************
  If the pool does not already contain a qname with the given namespace, prefix,
  and local name, then create such a qname, insert it in the pool and return an
  rchandle to it. Otherwise, return an rchandle to the existing qname. 
********************************************************************************/
void QNamePool::insert(
    store::Item_t& res,
    const zstring& ns,
    const zstring& pre,
    const zstring& ln)
{
  QNameItem* qn = NULL;
  QNameItem* normVictim = NULL;
  SYNC_CODE(bool haveLock = false;)
  store::Item_t normItem;
  QNameItem* normQName = NULL;

  bool normalized = pre.empty();

  zstring pooledNs;
  theNamespacePool->insert(ns, pooledNs);

  ulong hval = hashfun::h32(pre.c_str(),
                            hashfun::h32(ln.c_str(),
                                         hashfun::h32(ns.c_str())));
  try
  {
retry:
    SYNC_CODE(theHashSet.theMutex.lock();\
    haveLock = true;)

    QNHashEntry* entry =
    hashFind(ns.c_str(), pre.c_str(), ln.c_str(),
             ns.size(), pre.size(), ln.size(),
             hval);

    if (entry == 0)
    {
      if (normalized)
      {
        // Build a new QName (either new object or in cache).
        qn = cacheInsert(normVictim);
        qn->initializeAsNormalizedQName(pooledNs, ln);
      }
      else
      {
        if (normQName == NULL)
        {
          SYNC_CODE(theHashSet.theMutex.unlock();\
          haveLock = false;)

          // This call will need the lock.
          insert(normItem, pooledNs, zstring(), ln);
          normQName = static_cast<QNameItem*>(normItem.getp());

          goto retry;
        }
        // Build a new QName (either new object or in cache).
        qn = cacheInsert(normVictim);
        qn->initializeAsUnnormalizedQName(normQName, pre);
      }

      bool found;
      entry = theHashSet.hashInsert(qn, hval, found);
      entry->key() = qn;
      ZORBA_FATAL(!found, "");
    }
    else
    {
      qn = entry->key();
      cachePin(qn);
    }

    res = qn;

    SYNC_CODE(theHashSet.theMutex.unlock();\
    haveLock = false;)
  }
  catch (...)
  {
    SYNC_CODE(if (haveLock) theHashSet.theMutex.unlock();)

    ZORBA_FATAL(0, "Unexpected exception");
  }

  if (normVictim != NULL)
  {
    assert(normVictim->getRefCount() > 0 && normVictim->getRefCount() < 10000);
    normVictim->removeReference();
  }
}


/*******************************************************************************
  Return a qname slot for a new qname to be stored in. If the cache free list
  is not empty, we use the 1st slot from tha list; the qname currently in that
  slot (if any) is removed from the pool. If the cache free list is empty a new
  QNameItem is allocated from the heap.
********************************************************************************/
QNameItem* QNamePool::cacheInsert(QNameItem*& normVictim)
{
  assert(normVictim == NULL);

  QNameItem* qn = popFreeList();

  if (qn == NULL)
  {
    ZORBA_ASSERT(false);
    return new QNameItem();
  }

  if (qn->isValid())
  {
    ulong hval = CompareFunction::hash(qn);
    theHashSet.eraseNoSync(qn, hval);
    qn->invalidate(true, &normVictim);
  }
  
  return qn;
}


/*******************************************************************************
  If the given qname slot is in the free list of the cache, remove it from that
  list.
********************************************************************************/
void QNamePool::cachePin(QNameItem* qn)
{
  if (qn->isInCache())
  {
    removeFromFreeList(qn);
  }
}


/*******************************************************************************

********************************************************************************/
QNamePool::QNHashEntry* QNamePool::hashFind(
    const char* ns,
    const char* pre,
    const char* ln,
    csize       nslen,
    csize       prelen,
    csize       lnlen,
    csize       hval)
{
  QNHashEntry* entry = theHashSet.bucket(hval);

  if (entry->isFree())
    return NULL;

  while (entry != NULL)
  {
    QNameItem* qn = entry->key();

    if (ztd::equals(qn->getLocalName2(), ln, lnlen) &&
        ztd::equals(qn->getNamespace2(), ns, nslen) &&
        ztd::equals(qn->getPrefix2(), pre, prelen))
      return entry;

    entry = entry->getNext();
  }

  return NULL;
}


} // namespace store
} // namespace zorba

/* vim:set et sw=2 ts=2: */
