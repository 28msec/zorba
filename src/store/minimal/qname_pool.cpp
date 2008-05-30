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

#include "store/minimal/string_pool.h"
#include "store/minimal/qname_pool.h"
#include "store/minimal/min_atomic_items.h"
#include "store/minimal/min_store.h"
#include "store/minimal/min_store_defs.h"
#include "store/minimal/min_node_items.h"
#include "store/api/collection.h"
#include "zorbatypes/datetime.h"


namespace zorba { namespace store {

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
    if (theHashSet.theHashTab[i].theItem != NULL &&
        theHashSet.theHashTab[i].theItem->isOverflow())
    {
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
Item_t QNamePool::insert(
    const char* ns,
    const char* pre,
    const char* ln)
{
  QNameItemImpl* qn;

  if (ns == NULL) ns = "";
  if (pre == NULL) pre = "";
  ZORBA_ASSERT(((ln != NULL) && (*ln != '\0')));

  xqpStringStore_t pooledNs;
  theNamespacePool->insertc(ns, pooledNs);

  ulong hval = hashfun::h32(pre, hashfun::h32(ln, (uint32_t)pooledNs.getp()));
                                              //hashfun::h32(ns)));

  SYNC_CODE(AutoMutex lock(&theHashSet.theMutex);)

  QNHashEntry* entry = hashFind(pooledNs.getp(), pre, ln,
                                //pooledNs->bytes(), strlen(pre), strlen(ln),
                                hval);

  if (entry == 0)
  {
    qn = cacheInsert(hval);

    qn->theNamespace.transfer(pooledNs);
    qn->thePrefix = new xqpStringStore(pre);
    qn->theLocal = new xqpStringStore(ln);

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

  return qn;
}


/*******************************************************************************
  If the pool does not already contain a qname with the given namespace, prefix,
  and local name, then create such a qname, insert it in the pool and return an
  rchandle to it. Otherwise, return an rchandle to the existing qname. 

  The method also returns a boolean that says whether a qname was inserted or
  one existed already in the pool.

  Note: The given namespace, prefix, and local name must be heap-allocated
  xqpStringStore objects. If a qname is inserted, then ownership of those
  xqpStringStore objects is transfered to the inserted qname. Otherwise, the
  caller is resposnible for freeing the objects.
********************************************************************************/
Item_t QNamePool::insert(
    xqpStringStore_t ns,
    xqpStringStore* pre,
    xqpStringStore* ln,
    bool*           inserted)
{
  QNameItemImpl* qn;
  bool found;

  xqpStringStore_t pooledNs;
  theNamespacePool->insertc(ns.getp(), pooledNs);

  ulong hval = hashfun::h32(pre->c_str(),
                            hashfun::h32(ln->c_str(), (uint32_t)pooledNs.getp()));
                                         //hashfun::h32(ns->c_str())));

  SYNC_CODE(AutoMutex lock(&theHashSet.theMutex);)

  QNHashEntry* entry = hashFind(pooledNs.getp(), pre, ln,
                                //ns->bytes(), pre->bytes(), ln->bytes(),
                                hval);
  if (entry == 0)
  {
    qn = cacheInsert(hval);

    qn->theNamespace = pooledNs;//ns;
    qn->thePrefix = pre;
    qn->theLocal = ln;

    entry = theHashSet.hashInsert(qn, hval, found);
    entry->theItem = qn;
    ZORBA_FATAL(!found, "");
  }
  else
  {
    found = true;
    qn = entry->theItem;
    cachePin(qn);
  }

  if (inserted)    
    *inserted = (!found);

  return qn;
}


/*******************************************************************************
  Return a qname slot for a new qname to be stored in. If the cache free list
  is not empty, we use the 1st slot from tha list; the qname currently in that
  slot (if any) is removed from the pool. If the cache free list is empty a new
  QNameItem is allocated from the heap.
********************************************************************************/
QNameItemImpl* QNamePool::cacheInsert(ulong hval)
{
  QNameItemImpl* qn;

  if (theFirstFree != 0)
  {
    qn = &theCache[theFirstFree];

    theFirstFree = qn->theNextFree;
    theCache[theFirstFree].thePrevFree = 0;

    if (qn->theLocal != NULL)
      theHashSet.removeNoSync(qn, hval);

    qn->theNextFree = qn->thePrevFree = 0;

    theNumFree--;
    return qn;
  }

  qn = new QNameItemImpl();
  return qn;
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

QNamePool::QNHashEntry* QNamePool::hashFind(
    const xqpStringStore* ns,
    const char* pre,
    const char* ln,
//    ulong       nslen,
//    ulong       prelen,
//    ulong       lnlen,
    ulong       hval)
{
  QNHashEntry* entry = theHashSet.bucket(hval);

  if (entry->isFree())
    return NULL;

  while (entry != NULL)
  {
    QNameItemImpl* qn = entry->theItem;

    if (qn->theLocal->byteEqual(ln) &&
        qn->thePrefix->byteEqual(pre) &&
        qn->theNamespace->byteEqual(*ns)
        )
      return entry;

    entry = entry->getNext();
  }

  return NULL;
}

QNamePool::QNHashEntry* QNamePool::hashFind(
    const xqpStringStore* ns,
    const xqpStringStore* pre,
    const xqpStringStore* ln,
//    ulong       nslen,
//    ulong       prelen,
//    ulong       lnlen,
    ulong       hval)
{
  QNHashEntry* entry = theHashSet.bucket(hval);

  if (entry->isFree())
    return NULL;

  while (entry != NULL)
  {
    QNameItemImpl* qn = entry->theItem;

    if (qn->theLocal->byteEqual(*ln) &&
        qn->thePrefix->byteEqual(*pre) &&
        qn->theNamespace->byteEqual(*ns)
        )
      return entry;

    entry = entry->getNext();
  }

  return NULL;
}


} // namespace store
} // namespace zorba

