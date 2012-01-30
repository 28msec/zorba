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

#include "store/naive/string_pool.h"
#include "store/naive/qname_pool.h"
#include "store/naive/atomic_items.h"
#include "store/naive/simple_store.h"
#include "store/naive/store_defs.h"
#include "store/naive/node_items.h"
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

  for (uint16_t i = 1; qn < last; qn++, i++)
  {
    qn->theNextFree = i + 1;
    qn->thePrevFree = i - 1;
    qn->thePosition = i;
  }
  (--qn)->theNextFree = 0;
}


/*******************************************************************************

********************************************************************************/
QNamePool::~QNamePool() 
{
  csize n = theHashSet.theHashTab.size();
  for (csize i = 0; i < n; ++i)
  {
    if (!theHashSet.theHashTab[i].isFree() &&
        theHashSet.theHashTab[i].theItem->isOverflow())
      delete theHashSet.theHashTab[i].theItem;
  }

  if (theCache != NULL)
  {
    delete [] theCache;
    theCache = NULL;
  }
}


/*******************************************************************************

********************************************************************************/
void QNamePool::remove(QNameItem* qn)
{
  SYNC_CODE(AutoMutex lock(&theHashSet.theMutex);)

  if (qn->getRefCount() > 0 || hasNormalizingBackPointers(qn))
    return;

  if (qn->isInCache())
  {
    qn->theNextFree = (uint16_t)theFirstFree;
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
    QNameItem* normVictim = NULL;
    unregisterNormalizingBackPointer(qn, normVictim);
    theHashSet.eraseNoSync(qn);
    qn->invalidate();
    delete qn;

    if (normVictim)
    {
      // Tail call. Should avoid deadlock because no new stack frame.
      remove(normVictim);
    }
  }
}

store::Item_t QNamePool::insert(const char* ns,
                                const char* pre,
                                const char* ln,
                                bool        sync)
{
  return insert_internal(ns, pre, ln, sync);
}

store::Item_t QNamePool::insert(const zstring& ns,
                                const zstring& pre,
                                const zstring& ln,
                                bool        sync)
{
  return insert_internal(ns, pre, ln, sync);
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
QNameItem* QNamePool::insert_internal(
    const char* ns,
    const char* pre,
    const char* ln,
    bool        sync)
{
  QNameItem* qn;
  QNameItem* normVictim = NULL;
  SYNC_CODE(bool haveLock = false;)
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

    QNHashEntry* entry = hashFind(ns, pre, ln,
                                  (ulong)pooledNs.size(), (ulong)strlen(pre), (ulong)strlen(ln),
                                  hval);
    if (entry == 0)
    {
      if (normalized)
      {
        // Build a new QName (either new object or in cache).
        qn = cacheInsert(normVictim);
        qn->initializeAsNormalizedQName(pooledNs, zstring(ln));
      }
      else
      {
        if (normQName == NULL)
        {
          SYNC_CODE(theHashSet.theMutex.unlock();\
          haveLock = false;)

          normQName = insert_internal(ns, NULL, ln, false);

          goto retry;
        }
        // Build a new QName (either new object or in cache).
        qn = cacheInsert(normVictim);
        qn->initializeAsUnnormalizedQName(normQName, pre);
        registerNormalizingBackPointer(qn);
      }

      bool found;
      entry = theHashSet.hashInsert(qn, hval, found);
      entry->theItem = qn;
      ZORBA_FATAL(!found, "");
    }
    else
    {
      qn = entry->theItem;
      cachePin(qn);
    }

    SYNC_CODE(theHashSet.theMutex.unlock();\
    haveLock = false;)
  }
  catch (...)
  {
    SYNC_CODE(if (haveLock) \
      theHashSet.theMutex.unlock();)

    ZORBA_FATAL(0, "Unexpected exception");
  }

  if (normVictim)
  {
    remove(normVictim);
  }
  return qn;
}


/*******************************************************************************
  If the pool does not already contain a qname with the given namespace, prefix,
  and local name, then create such a qname, insert it in the pool and return an
  rchandle to it. Otherwise, return an rchandle to the existing qname. 
********************************************************************************/
QNameItem* QNamePool::insert_internal(
    const zstring& ns,
    const zstring& pre,
    const zstring& ln,
    bool sync)
{
  QNameItem* qn = NULL;
  QNameItem* normVictim = NULL;
  SYNC_CODE(bool haveLock = false;)
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

    QNHashEntry* entry = hashFind(ns.c_str(), pre.c_str(), ln.c_str(),
                                  (ulong)ns.size(), (ulong)pre.size(), (ulong)ln.size(),
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
          normQName = insert_internal(pooledNs, zstring(), ln, false);

          goto retry;
        }
        // Build a new QName (either new object or in cache).
        qn = cacheInsert(normVictim);
        qn->initializeAsUnnormalizedQName(normQName, pre);
        registerNormalizingBackPointer(qn);
      }

      bool found;
      entry = theHashSet.hashInsert(qn, hval, found);
      entry->theItem = qn;
      ZORBA_FATAL(!found, "");
    }
    else
    {
      qn = entry->theItem;
      cachePin(qn);
    }

    SYNC_CODE(theHashSet.theMutex.unlock();\
    haveLock = false;)
  }
  catch (...)
  {
  SYNC_CODE(  if (haveLock) \
      theHashSet.theMutex.unlock();)

    ZORBA_FATAL(0, "Unexpected exception");
  }

  if (normVictim)
  {
    remove(normVictim);
  }
  return qn;
}


/*******************************************************************************
  Return a qname slot for a new qname to be stored in. If the cache free list
  is not empty, we use the 1st slot from tha list; the qname currently in that
  slot (if any) is removed from the pool. If the cache free list is empty a new
  QNameItem is allocated from the heap.
********************************************************************************/
QNameItem* QNamePool::cacheInsert(QNameItem*& normVictim)
{
  assert (normVictim == NULL);
  if (theFirstFree != 0)
  {
    QNameItem* qn = &theCache[theFirstFree];

    theFirstFree = qn->theNextFree;
    theCache[theFirstFree].thePrevFree = 0;

    if (qn->isValid())
    {
      unregisterNormalizingBackPointer(qn, normVictim);
      ulong hval = CompareFunction::hash(qn);
      theHashSet.eraseNoSync(qn, hval);
      qn->invalidate();
    }

    qn->theNextFree = qn->thePrevFree = 0;

    theNumFree--;
    return qn;
  }
  else
  {
    return new QNameItem();
  }
}


/*******************************************************************************
  If the given qname slot is in the free list of the cache, remove it from that
  list.
********************************************************************************/
void QNamePool::cachePin(QNameItem* qn)
{
  if (qn->isInCache() && (qn->theNextFree != 0 || qn->thePrevFree != 0))
  {
    if (qn->theNextFree != 0)
      theCache[qn->theNextFree].thePrevFree = qn->thePrevFree;

    if (qn->thePrevFree != 0)
    {
      theCache[qn->thePrevFree].theNextFree = qn->theNextFree;
    }
    else if (theFirstFree == qn->thePosition)
    {
      theFirstFree = qn->theNextFree;
    }

    qn->theNextFree = qn->thePrevFree = 0;
    theNumFree--;
  }
}


/*******************************************************************************

********************************************************************************/
QNamePool::QNHashEntry* QNamePool::hashFind(
    const char* ns,
    const char* pre,
    const char* ln,
    ulong       nslen,
    ulong       prelen,
    ulong       lnlen,
    ulong       hval)
{
  QNHashEntry* entry = theHashSet.bucket(hval);

  if (entry->isFree())
    return NULL;

  while (entry != NULL)
  {
    QNameItem* qn = entry->theItem;

    if (ztd::equals(qn->getLocalName(), ln, lnlen) &&
        ztd::equals(qn->getNamespace(), ns, nslen) &&
        ztd::equals(qn->getPrefix(), pre, prelen))
      return entry;

    entry = entry->getNext();
  }

  return NULL;
}
  
bool QNamePool::hasNormalizingBackPointers(const QNameItem* aNormalizedQName) const
{
  std::map<const QNameItem*, std::set<const QNameItem*> >::const_iterator lIterator =
  theWhoNormalizesToMe.find(aNormalizedQName);
  return !lIterator->second.empty();
}

void QNamePool::registerNormalizingBackPointer(const QNameItem* aQName)
{
  if (!aQName->isNormalized())
  {
    theWhoNormalizesToMe[aQName->getNormalized()].insert(aQName);
  }
}

void QNamePool::unregisterNormalizingBackPointer(const QNameItem* aQName,
                                                 QNameItem*& normVictim)
{
  if (aQName->isNormalized())
  {
    return;
  }
  // Entry exists for this normalized QName.
  assert(theWhoNormalizesToMe.find(aQName->getNormalized())
         != theWhoNormalizesToMe.end());
  // Backpointer exists.
  assert(theWhoNormalizesToMe[aQName->getNormalized()].find(aQName)
         != theWhoNormalizesToMe[aQName->getNormalized()].end());

  std::set<const QNameItem*>& lSet =
      theWhoNormalizesToMe[aQName->getNormalized()];

  // Remove backpointer.
  lSet.erase(aQName);

  // Set normalization victim if the set is now empty.
  if (lSet.empty())
    normVictim = const_cast<QNameItem*>(aQName->getNormalized());
}
  
  



} // namespace store
} // namespace zorba

/* vim:set et sw=2 ts=2: */
