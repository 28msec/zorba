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

#include "zorbaerrors/Assert.h"
#include "system/globalenv.h"

#include "store/naive/string_pool.h"
#include "store/naive/qname_pool.h"
#include "store/naive/atomic_items.h"
#include "store/naive/simple_store.h"
#include "store/naive/store_defs.h"
#include "store/naive/node_items.h"
#include "store/api/collection.h"
#include "zorbatypes/datetime.h"


namespace zorba { namespace simplestore {


/*******************************************************************************

********************************************************************************/
QNamePool::QNamePool(ulong size, StringPool* nspool) 
  :
  theCache(new QNameItemImpl[size]),
  theCacheSize(size),
  theFirstFree(1),
  theNumFree(size - 1),
  theHashSet(2 * size),
  theNamespacePool(nspool)
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
}


/*******************************************************************************

********************************************************************************/
QNamePool::~QNamePool() 
{
  ulong n = theHashSet.theHashTab.size();
  for (ulong i = 0; i < n; i++)
  {
    if (theHashSet.theHashTab[i].theItem != NULL)
    {
      QNameItemImpl* qn = theHashSet.theHashTab[i].theItem;

      if (!qn->isNormalized())
        qn->theLocal.setNull();

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
void QNamePool::remove(QNameItemImpl* qn)
{
  SYNC_CODE(AutoMutex lock(&theHashSet.theMutex);)

  if (qn->getRefCount() > 0)
    return;

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
    theHashSet.remove(qn);
    delete qn;
  }
}


/*******************************************************************************
  If the pool does not already contain a qname with the given namespace, prefix,
  and local name, then create such a qname, insert it in the pool and return an
  rchandle to it. Otherwise, return an rchandle to the existing qname. 

  Note: The given namespace, prefix, and local name pointers may point to heap 
  or stack allocated strings. If a qname is inserted, then the strings are 
  copied internally into xqpStringStore objects. So, it's always the caller
  who is resposnible for freeing the given strings.
********************************************************************************/
store::Item_t QNamePool::insert(
    const char* ns,
    const char* pre,
    const char* ln,
    bool        sync)
{
  QNameItemImpl* qn;
  QNameItemImpl* normVictim = NULL;
  bool haveLock = false;
  bool haveNormQName = false;
  store::Item_t normItem;
  QNameItemImpl* normQName;

  bool normalized = (pre == NULL || *pre == '\0');

  if (ns == NULL) ns = "";
  if (pre == NULL) pre = "";
  ZORBA_FATAL(ln != NULL && *ln != '\0', "");

  xqpStringStore_t pooledNs;
  theNamespacePool->insertc(ns, pooledNs);

  ulong hval = hashfun::h32(pre, hashfun::h32(ln, hashfun::h32(ns)));

  try
  {
retry:
    theHashSet.theMutex.lock();
    haveLock = true;

    QNHashEntry* entry = hashFind(ns, pre, ln,
                                  pooledNs->bytes(), strlen(pre), strlen(ln),
                                  hval);
    if (entry == 0)
    {
      if (normalized)
      {
        qn = cacheInsert(normVictim);

        qn->theNamespace.transfer(pooledNs);
        qn->thePrefix = QNameItemImpl::theEmptyPrefix;
        qn->theLocal = new xqpStringStore(ln);
      }
      else
      {
        if (!haveNormQName)
        {
          theHashSet.theMutex.unlock();
          haveLock = false;

          normItem = insert(ns, NULL, ln, false);

          normQName = reinterpret_cast<QNameItemImpl*>(normItem.getp());


          haveNormQName = true;
          goto retry;
        }

        qn = cacheInsert(normVictim);

        qn->theNamespace = normQName->theNamespace;
        qn->thePrefix = new xqpStringStore(pre);
        qn->setNormalized(normQName);
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

    theHashSet.theMutex.unlock();
    haveLock = false;
  }
  catch (...)
  {
    if (haveLock)
      theHashSet.theMutex.unlock();

    ZORBA_FATAL(0, "Unexpected exception");
  }

  if (normVictim != NULL)
  {
    normVictim->removeReference(NULL SYNC_PARAM2(normVictim->getRCLock()));
  }

  return qn;
}


/*******************************************************************************
  If the pool does not already contain a qname with the given namespace, prefix,
  and local name, then create such a qname, insert it in the pool and return an
  rchandle to it. Otherwise, return an rchandle to the existing qname. 
********************************************************************************/
store::Item_t QNamePool::insert(
    const xqpStringStore_t& ns,
    const xqpStringStore_t& pre,
    const xqpStringStore_t& ln,
    bool                    sync)
{
  QNameItemImpl* qn;
  QNameItemImpl* normVictim = NULL;
  bool haveLock = false;
  bool haveNormQName = false;
  store::Item_t normItem;
  QNameItemImpl* normQName;

  bool normalized = pre->empty();

  xqpStringStore_t pooledNs;
  theNamespacePool->insert(ns, pooledNs);

  ulong hval = hashfun::h32(pre->c_str(),
                            hashfun::h32(ln->c_str(),
                                         hashfun::h32(ns->c_str())));
  try
  {
retry:
    theHashSet.theMutex.lock();
    haveLock = true;

    QNHashEntry* entry = hashFind(ns->c_str(), pre->c_str(), ln->c_str(),
                                  ns->bytes(), pre->bytes(), ln->bytes(),
                                  hval);
    if (entry == 0)
    {
      if (normalized)
      {
        qn = cacheInsert(normVictim);

        qn->theNamespace.transfer(pooledNs);
        qn->thePrefix = QNameItemImpl::theEmptyPrefix;
        qn->theLocal = ln;
      }
      else
      {
        if (!haveNormQName)
        {
          theHashSet.theMutex.unlock();
          haveLock = false;

          normItem = insert(pooledNs,
                            QNameItemImpl::theEmptyPrefix,
                            ln,
                            false);

          normQName = reinterpret_cast<QNameItemImpl*>(normItem.getp());

          haveNormQName = true;
          goto retry;
        }

        qn = cacheInsert(normVictim);
      
        qn->theNamespace = normQName->theNamespace;
        qn->thePrefix = pre;
        qn->setNormalized(normQName);
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

    theHashSet.theMutex.unlock();
    haveLock = false;
  }
  catch (...)
  {
    if (haveLock)
      theHashSet.theMutex.unlock();

    ZORBA_FATAL(0, "Unexpected exception");
  }

  if (normVictim != NULL)
  {
    normVictim->removeReference(NULL SYNC_PARAM2(normVictim->getRCLock()));
  }

  return qn;
}


/*******************************************************************************
  Return a qname slot for a new qname to be stored in. If the cache free list
  is not empty, we use the 1st slot from tha list; the qname currently in that
  slot (if any) is removed from the pool. If the cache free list is empty a new
  QNameItem is allocated from the heap.
********************************************************************************/
QNameItemImpl* QNamePool::cacheInsert(QNameItemImpl*& normVictim)
{
  normVictim = NULL;

  if (theFirstFree != 0)
  {
    QNameItemImpl* qn = &theCache[theFirstFree];

    theFirstFree = qn->theNextFree;
    theCache[theFirstFree].thePrevFree = 0;

    if (qn->isValid())
    {
      ulong hval = hashfun::h32(qn->getPrefix()->c_str(),
                                hashfun::h32(qn->getLocalName()->c_str(),
                                             hashfun::h32(qn->getNamespace()->c_str())));
      theHashSet.removeNoSync(qn, hval);

      if (!qn->isNormalized())
      {
        // Save the pointer to the associated normalized qname and then set
        // that pointer to null. This way (a) we can decerement the ref
        // counter of the normalized qname after releasing theHashSet.theMutex
        // (otherwise, we would run into a self-deadlock if the normalized
        // qname needs to be freed),and (b) removeReference is not called
        // when we overwite the pointer with the new local name.
        normVictim = qn->detachNormalized();
      }
      else
      {
        // Set qn->theLocal so that the assertion in setNormalized() (which is
        // invoked later by the caller of this method) will not trigger.
        qn->theLocal = NULL;
      }
    }

    qn->theNextFree = qn->thePrevFree = 0;

    theNumFree--;
    return qn;
  }
  else
  {
    return new QNameItemImpl();
  }
}


/*******************************************************************************
  If the given qname slot is in the free list of the cache, remove it from that
  list.
********************************************************************************/
void QNamePool::cachePin(QNameItemImpl* qn)
{
  ZORBA_FATAL(qn != NULL, "");

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
HashEntry<QNameItemImpl*, DummyHashValue>* QNamePool::hashFind(
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
    QNameItemImpl* qn = entry->theItem;

    if (qn->getLocalName()->byteEqual(ln, lnlen) &&
        qn->getNamespace()->byteEqual(ns, nslen) &&
        qn->getPrefix()->byteEqual(pre, prelen))
      return entry;

    entry = entry->getNext();
  }

  return NULL;
}


} // namespace store
} // namespace zorba

