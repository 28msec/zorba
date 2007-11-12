#ifndef XQP_QNAME_POOL_H
#define XQP_QNAME_POOL_H

#include "store/api/item.h"


namespace xqp
{
class QNamePool;

typedef rchandle<class xqpStringStore> xqpStringStore_t;

/*******************************************************************************

********************************************************************************/
class QNameItemImpl : public QNameItem
{
  friend class QNamePool;

private:
  xqpStringStore_t  theNamespace;
  xqpStringStore_t  thePrefix;
  xqpStringStore_t  theLocal;

  uint16_t          thePosition;
  uint16_t          theNextFree;
  uint16_t          thePrevFree;

public:
  QNameItemImpl() : thePosition(0), theNextFree(0), thePrevFree(0) {}

  QNameItemImpl(
        const xqpStringStore_t& ns,
        const xqpStringStore_t& pre,
        const xqpStringStore_t& ln);
 
  QNameItemImpl(
        const char* ns,
        const char* pre,
        const char* ln);

  virtual ~QNameItemImpl() { }

  void free();

  bool isInCache() const                  { return thePosition != 0; }
  bool isOverflow() const                 { return thePosition == 0; }

  virtual xqp_string getNamespace() const { return theNamespace.get_ptr(); }
  virtual xqp_string getPrefix() const    { return thePrefix.get_ptr(); }
  virtual xqp_string getLocalName() const { return theLocal.get_ptr(); }

  virtual TypeCode getType() const        { return xs_qname; }
  virtual Item_t getAtomizationValue() const;
  virtual uint32_t hash() const;
  virtual bool equals(Item_t) const;
  virtual Item_t getEBV() const;
  virtual xqp_string getStringProperty() const;

  virtual xqp_string show() const;
};


/*******************************************************************************

  theCache       : An array of QName slots that is managed as a cache. This
                   means that slots that are not used are placed in a free list.
                   When a new qname is inserted in the cache, a slot is taken
                   from the free list and the qname currently in that slot is
                   replaced with the new slot.
  theCacheSize   : The size of theCache (number of slots). This size is given
                   as a param to the QNamePool constructor, and it never changes
                   afterwards. 
  theFirstFree   : The position in theCache of the 1st free slot. NOTE: the 1st
                   slot of theCache (at position 0) is reserved (i.e., never
                   used) so that position 0 can be used to indicate the end of
                   the free list.
  theNumFree     : Number of free slots in theCache.

  theNumQnames   : The total number of qnames stored in the pool.

  theHashTab     : A hash table mapping qnames (i.e. triplets of strings) to
                   QName slots.
  theHashTabSize : The number of hash buckets in theHashTab. 
  theLoadFactor  :
********************************************************************************/
class QNamePool
{
protected:

  class HashEntry
  {
  public:
    QNameItemImpl  * theQNameSlot;
    HashEntry      * theNext;

    HashEntry() : theQNameSlot(NULL), theNext(NULL) { }

    ~HashEntry() { }
  };

public:
  static const xqp_ulong MAX_CACHE_SIZE = 65536;
  static const float DEFAULT_LOAD_FACTOR;// = 0.6;//daniel: to compile on windows

protected:
  QNameItemImpl         * theCache;
  xqp_ulong               theCacheSize;
  xqp_ulong               theFirstFree;
  xqp_ulong               theNumFree;

  xqp_ulong               theNumQNames;

  std::vector<HashEntry>  theHashTab;
  xqp_ulong               theHashTabSize;
  float                   theLoadFactor;

public:
  QNamePool(xqp_ulong size);

  ~QNamePool();

  QNameItemImpl* insert(
        const char* ns,
        const char* pre,
        const char* ln);

  QNameItemImpl* insert(
        const xqpStringStore& ns,
        const xqpStringStore& pre,
        const xqpStringStore& ln);

  void remove(QNameItemImpl* qn);

protected:
  QNameItemImpl* cacheInsert(HashEntry* entry);

  HashEntry* hashInsert(
        const char* ns,
        const char* pre,
        const char* ln,
        xqp_ulong   nslen,
        xqp_ulong   prelen,
        xqp_ulong   lnlen,
        bool&       found);

  void hashRemove(
        const xqpStringStore_t& ns,
        const xqpStringStore_t& pre,
        const xqpStringStore_t& ln);

  void resizeHashTab();
};


}

#endif
