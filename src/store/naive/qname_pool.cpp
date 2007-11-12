
#include "util/zorba.h"
#include "store/naive/qname_pool.h"
#include "store/naive/simple_store.h"

namespace xqp
{

const float QNamePool::DEFAULT_LOAD_FACTOR = 0.6;


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  QNamePool                                                                  //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
QNamePool::QNamePool(xqp_unsignedLong size) 
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

  for (xqp_unsignedLong i = 1; qn < last; qn++, i++)
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
#if 0
  xqp_unsignedLong n = theOverflow.size();
  for (xqp_unsignedLong i = 0; i < n; i++)
  {
    if (theOverflow[i] != NULL)
      delete theOverflow[i];
  }
#else
  xqp_unsignedLong n = theHashTab.size();
  for (xqp_unsignedLong i = 0; i < n; i++)
  {
    if (theHashTab[i].theQName != NULL && theHashTab[i].theQName->isOverflow())
      ::delete theHashTab[i].theQName;
  }
#endif

  if (theCache != NULL)
  {
    delete [] theCache;
    theCache = NULL;
  }
}


/*******************************************************************************

********************************************************************************/
QNameItemImpl* QNamePool::insert(
    const char* ns,
    const char* pre,
    const char* ln)
{
  QNameItemImpl* qn;

  HashEntry* entry = hash(ns, pre, ln);

  // If the qname is already in the pool, return a ptr to its containing slot.
  // If the slot is in the free list of the cache, it is first removed from
  // that list.  
  if (entry->theQName != NULL)
  {
    qn = entry->theQName;

    if (qn->isInCache())
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

    return qn;
  }

  // The qname is not in the pool.
  // Use the 1st slot from the free list of the cache to store the new qname.
  // The qname was is currently in that slot is removed from the cache.
  if (theFirstFree != 0)
  {
    qn = &theCache[theFirstFree];
    entry->theQName = qn;

    theFirstFree = qn->theNextFree;
    theCache[theFirstFree].thePrevFree = 0;

    if (!qn->theLocal.empty())
      unhash(qn->theNamespace.c_str(), qn->thePrefix.c_str(), qn->theLocal.c_str());

    qn->theNextFree = qn->thePrevFree = 0;
    qn->theNamespace = ns;
    qn->thePrefix = pre;
    qn->theLocal = ln;

    theNumFree--;

    return qn;
  }

  // The cache was full, so allocate a QNameItem from the heap.
  qn = new QNameItemImpl(ns, pre, ln);
  //theOverflow.push_back(qn);
  entry->theQName = qn;
  return qn;
}


/*******************************************************************************

********************************************************************************/
void QNamePool::remove(QNameItemImpl* qn)
{
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
    unhash(qn->getNamespace().c_str(),
           qn->getPrefix().c_str(),
           qn->getLocalName().c_str());

    //std::vector<QNameItemImpl *>::iterator it;
    //it = theOverflow.begin() + qn->thePosition;
    //theOverflow.erase(it);

    ::delete qn;
  }
}


/*******************************************************************************
  Check if the given qname is already in the pool, and if so, return its hash
  entry. If not, allocate a new hash entry for it, and return it to the caller.
********************************************************************************/
QNamePool::HashEntry*
QNamePool::hash(const char* ns, const char* pre, const char* ln)
{
  xqp_unsignedLong len;
  HashEntry* entry;
  HashEntry* lastentry;

  // Get ptr to the 1st entry of the hash bucket corresponding to the given qname
  xqp_unsignedLong hval = hashfun::h32(pre,
                                       hashfun::h32(ln,
                                                    hashfun::h32(ns))) % theHashTabSize;
  entry = &theHashTab[ hval % theHashTabSize];

  // If the hash bucket is empty, its 1st entry is used to store the new qname.
  if (entry->isFree())
  {
    theNumQNames++;
    return entry;
  }

  // Search the hash bucket looking for the given qname.
  while (entry != NULL)
  {
    QNameItemImpl* qn = entry->theQName;

    len = qn->theLocal.bytes();
    if (len != strlen(ln) || memcmp(qn->theLocal.c_str(), ln, len) != 0)
    {
      lastentry = entry;
      entry =  entry->theNext;
      continue;
    }

    len = qn->theNamespace.bytes();
    if (len != strlen(ns) || memcmp(qn->theNamespace.c_str(), ns, len) != 0)
    {
      lastentry = entry;
      entry =  entry->theNext;
      continue;
    }
    
    len = qn->thePrefix.bytes();
    if (len != strlen(pre) || memcmp(qn->thePrefix.c_str(), pre, len) != 0)
    {
      lastentry = entry;
      entry =  entry->theNext;
      continue;
    }

    return entry;
  }

  // The qname was not found.
  theNumQNames++;

  // Double the size of hash table if it is more than 60% full. 
  if (theNumQNames > theHashTabSize * theLoadFactor)
  {
    resizeHashTab();

    hval = hashfun::h32(pre, hashfun::h32(ln, hashfun::h32(ns))) % theHashTabSize;
    entry = &theHashTab[ hval % theHashTabSize];

    if (entry->isFree())
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
  Remove the given qname from the hash table, if it is found there.
********************************************************************************/
void QNamePool::unhash(const char* ns, const char* pre, const char* ln)
{
  xqp_unsignedLong len;
  HashEntry* entry;
  HashEntry* preventry = NULL;

  // Get ptr to the 1st entry of the hash bucket corresponding to the given qname
  xqp_unsignedLong hval = hashfun::h32(pre,
                                       hashfun::h32(ln,
                                                    hashfun::h32(ns))) % theHashTabSize;
  entry = &theHashTab[ hval % theHashTabSize];

  // If the hash bucket is empty, the qname is not in the hash table.
  if (entry->isFree())
    return;

  // Search the hash bucket looking for the given qname.
  while (entry != NULL)
  {
    QNameItemImpl* qn = entry->theQName;

    len = qn->theLocal.bytes();
    if (len != strlen(ln) || memcmp(qn->theLocal.c_str(), ln, len) != 0)
    {
      preventry = entry;
      entry =  entry->theNext;
      continue;
    }

    len = qn->theNamespace.bytes();
    if (len != strlen(ns) || memcmp(qn->theNamespace.c_str(), ns, len) != 0)
    {
      preventry = entry;
      entry =  entry->theNext;
      continue;
    }
    
    len = qn->thePrefix.bytes();
    if (len != strlen(pre) || memcmp(qn->thePrefix.c_str(), pre, len) != 0)
    {
      preventry = entry;
      entry =  entry->theNext;
      continue;
    }

    // Found the qname in the current entry. Must remove the entry from the
    // hash bucket and add it to the free list.
    if (preventry != NULL)
    {
      preventry->theNext = entry->theNext;
      entry->theQName = NULL;
      entry->theNext = theHashTab[theHashTabSize].theNext;
      theHashTab[theHashTabSize].theNext = entry;
    }
    else if (entry->theNext != NULL)
    {
      HashEntry* nextentry = entry->theNext;
      *entry = *nextentry;
      nextentry->theQName = NULL;
      nextentry->theNext = theHashTab[theHashTabSize].theNext;
      theHashTab[theHashTabSize].theNext = nextentry;
    }
    else
    {
      entry->theQName = NULL;
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
  xqp_unsignedLong oldsize = oldTab.size();

  theHashTabSize <<= 1;

  theHashTab.clear();
  theHashTab.resize(theHashTabSize + 32);

  // Format the overflow area of theHashTab as a list of free entries
  lastentry = &theHashTab[theHashTabSize + 31];
  for (entry = &theHashTab[theHashTabSize]; entry < lastentry; entry++)
    entry->theNext = entry + 1;
 
  // Now rehash every entry
  for (xqp_unsignedLong i = 0; i < oldsize; i++)
  {
    QNameItemImpl* qn = oldTab[i].theQName;

    xqp_unsignedLong h = hashfun::h32(qn->thePrefix.c_str(),
                           hashfun::h32(qn->theLocal.c_str(),
                                        hashfun::h32(qn->theNamespace.c_str())));
    entry = &theHashTab[h % theHashTabSize];

    if (!entry->isFree())
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

    entry->theQName = qn;
  }
}



/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  QNameItem                                                                  //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


QNameItemImpl::QNameItemImpl(
    const xqp_string& ns,
    const xqp_string& pre,
    const xqp_string& local)
  :
  theNamespace(ns),
  thePrefix (pre),
  theLocal(local),
  theNextFree(0),
  thePrevFree(0)
{
}


QNameItemImpl::QNameItemImpl(
    const char* ns,
    const char* pre,
    const char* local)
  :
  theNamespace(ns),
  thePrefix (pre),
  theLocal(local),
  theNextFree(0),
  thePrevFree(0)
{
}


void QNameItemImpl::free()
{
  reinterpret_cast<SimpleStore*>(&Store::getInstance())->getQNamePool().remove(this);
}


Item_t QNameItemImpl::getAtomizationValue( ) const
{
  return zorba::getItemFactory()->createQName(theNamespace, thePrefix, theLocal).get_ptr();
}


uint32_t QNameItemImpl::hash() const
{
  return Item::createQNameKey(theNamespace, thePrefix, theLocal);
}


bool QNameItemImpl::equals(Item_t item) const
{
  return (this == item.get_ptr() ||
          (item->getNamespace() == theNamespace &&
           item->getLocalName() == theLocal));
}


Item_t QNameItemImpl::getEBV( ) const
{
  ZorbaErrorAlerts::error_alert (
        error_messages::FORG0006_INVALID_ARGUMENT_TYPE,
		    error_messages::RUNTIME_ERROR,
		    NULL,
		    false,
		    "Effective Boolean Value is not defined for QName!");
  return NULL;
}


xqp_string QNameItemImpl::getStringProperty( ) const
{
  return thePrefix != "" ? thePrefix + ":" + theLocal : theLocal;
}


xqp_string QNameItemImpl::show() const
{
  return "xs:qname(" + theNamespace + "," + thePrefix + "," + theLocal + ")";
}

}
