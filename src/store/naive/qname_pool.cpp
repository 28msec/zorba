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
  ulong n = (ulong)theHashSet.theHashTab.size();
  for (ulong i = 0; i < n; i++)
  {
    if (!theHashSet.theHashTab[i].isFree())
    {
      QNameItem* qn = theHashSet.theHashTab[i].theItem;

      // Make sure that the associated normalized QN will not be destroyed here
      if (!qn->isNormalized())
        qn->detachNormQName();

      if (theHashSet.theHashTab[i].theItem->isOverflow())
        delete theHashSet.theHashTab[i].theItem;
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
void QNamePool::remove(QNameItem* qn)
{
  SYNC_CODE(AutoMutex lock(&theHashSet.theMutex);)

  if (qn->getRefCount() > 0)
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
    theHashSet.eraseNoSync(qn);
    delete qn;
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
store::Item_t QNamePool::insert(
    const char* ns,
    const char* pre,
    const char* ln,
    bool        sync)
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

    QNHashEntry* entry = hashFind(ns, pre, ln,
                                  (ulong)pooledNs.size(), (ulong)strlen(pre), (ulong)strlen(ln),
                                  hval);
    if (entry == 0)
    {
      if (normalized)
      {
        qn = cacheInsert(normVictim);

        qn->theNamespace = pooledNs;
        qn->thePrefix.clear();
        qn->setLocalName(zstring(ln));
      }
      else
      {
        if (normQName == NULL)
        {
          SYNC_CODE(theHashSet.theMutex.unlock();\
          haveLock = false;)

          normItem = insert(ns, NULL, ln, false);

          normQName = reinterpret_cast<QNameItem*>(normItem.getp());

          goto retry;
        }

        qn = cacheInsert(normVictim);

        qn->theNamespace = normQName->theNamespace;
        qn->thePrefix = pre;
        qn->setNormQName(normQName);
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

  if (normVictim != NULL)
  {
    normVictim->removeReference();
  }

  return qn;
}


/*******************************************************************************
  If the pool does not already contain a qname with the given namespace, prefix,
  and local name, then create such a qname, insert it in the pool and return an
  rchandle to it. Otherwise, return an rchandle to the existing qname. 
********************************************************************************/
store::Item_t QNamePool::insert(
    const zstring& ns,
    const zstring& pre,
    const zstring& ln,
    bool sync)
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

    QNHashEntry* entry = hashFind(ns.c_str(), pre.c_str(), ln.c_str(),
                                  (ulong)ns.size(), (ulong)pre.size(), (ulong)ln.size(),
                                  hval);
    if (entry == 0)
    {
      if (normalized)
      {
        qn = cacheInsert(normVictim);

        qn->theNamespace = pooledNs;
        qn->thePrefix.clear();
        qn->setLocalName(ln);
      }
      else
      {
        if (normQName == NULL)
        {
          SYNC_CODE(theHashSet.theMutex.unlock();\
          haveLock = false;)

          normItem = insert(pooledNs, zstring(), ln, false);

          normQName = reinterpret_cast<QNameItem*>(normItem.getp());

          goto retry;
        }

        qn = cacheInsert(normVictim);
      
        qn->theNamespace = normQName->theNamespace;
        qn->thePrefix = pre;
        qn->setNormQName(normQName);
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

  if (normVictim != NULL)
  {
    normVictim->removeReference();
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
  normVictim = NULL;

  if (theFirstFree != 0)
  {
    QNameItem* qn = &theCache[theFirstFree];

    theFirstFree = qn->theNextFree;
    theCache[theFirstFree].thePrevFree = 0;

    if (qn->isValid())
    {
      ulong hval = hashfun::h32(qn->getPrefix().c_str(),
                                hashfun::h32(qn->getLocalName().c_str(),
                                             hashfun::h32(qn->getNamespace().c_str())));
      theHashSet.eraseNoSync(qn, hval);

      if (!qn->isNormalized())
      {
        // Let NQ be the associated normalized qname. Here, wave the pointer
        // to NQ and then set that pointer to null, without decrementing NQ's
        // ref count of the. This way (a) we can decerement NQ's ref counter
        // *after* releasing theHashSet.theMutex (otherwise, we would run into
        // a self-deadlock if NQ must be be freed because it is not referenced
        // from anywhere else), and (b) removeReference is not called
        // when we overwite the pointer with the new local name.
        normVictim = qn->detachNormQName();
      }
      else
      {
        // Unset qn->theLocal so that the assertion in setNormQName() (which is
        // invoked later by the caller of this method) will not trigger.
        qn->unsetLocalName();
      }
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


} // namespace store
} // namespace zorba

/* vim:set et sw=2 ts=2: */
