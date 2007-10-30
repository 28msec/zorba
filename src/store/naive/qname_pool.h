#ifndef XQP_QNAME_POOL_H
#define XQP_QNAME_POOL_H

#include "store/api/item.h"
//#include "store/naive/atomic_items.h"

namespace xqp
{
class QNamePool;


/*******************************************************************************

********************************************************************************/
class QNameItemNaive : public QNameItem
{
  friend class QNamePool;

private:
  static QNamePool* theQNamePool;

private:
  xqp_string theNamespace;
  xqp_string thePrefix;
  xqp_string theLocal;

  uint16_t   thePosition;
  uint16_t   theNextFree;
  uint16_t   thePrevFree;

public:
  static QNamePool* getQNamePool()        { return theQNamePool; }
  static void setQNamePool(QNamePool* p);

public:
  QNameItemNaive() : thePosition(0), theNextFree(0), thePrevFree(0) {}

  QNameItemNaive(const xqp_string& ns, const xqp_string& pre, const xqp_string& ln);
 
  QNameItemNaive(const char* ns, const char* pre, const char* ln);

  virtual ~QNameItemNaive() { }

  void free();

  bool isInCache() const                  { return thePosition != 0; }
  bool isOverflow() const                 { return thePosition == 0; }

  virtual xqp_string getNamespace() const { return theNamespace; }
  virtual xqp_string getPrefix() const    { return thePrefix; }
  virtual xqp_string getLocalName() const { return theLocal; }
  virtual qnamekey_t getQNameKey( ) const;

  virtual TypeCode getType( ) const       { return xs_qname; }
  virtual Item_t getAtomizationValue( ) const;
  virtual bool equals ( Item_t ) const;
  virtual Item_t getEBV( ) const;
  virtual xqp_string getStringProperty( ) const;

  virtual xqp_string show() const;
};


/*******************************************************************************

  theCache       : An array of QNameItem slots that is managed as a cache. This
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

  theOverflow    : If theCache is full and a new qname must be inserted, a
                   QNameItem is allocated in the heap and a pointer to it is
                   placed in theOverflow vector. So, theOverflow is a vector of
                   overflow slots. 

  theNumQnames   : The total number of qnames stored in the pool.

  theHashTab     : A hash table mapping qnames (i.e. triplets of strings) to
                   QNameItem slots.
  theHashTabSize : The number of hash buckets in theHashTab. 
  theLoadFactor  :
********************************************************************************/
class QNamePool
{
protected:

  class HashEntry
  {
  public:
    QNameItemNaive  * theQName;
    HashEntry       * theNext;

    HashEntry() : theQName(NULL), theNext(NULL) { }

    ~HashEntry() { theQName = NULL; theNext = NULL; }

    bool isFree() const { return theQName == NULL; } 
  };

public:
  static const ulong MAX_CACHE_SIZE = 65536;
  static const float DEFAULT_LOAD_FACTOR = 0.6;

protected:
  QNameItemNaive*                theCache;
  ulong                          theCacheSize;
  ulong                          theFirstFree;
  ulong                          theNumFree;

  //std::vector<QNameItemNaive *>  theOverflow;

  ulong                          theNumQNames;

  std::vector<HashEntry>         theHashTab;
  ulong                          theHashTabSize;
  float                          theLoadFactor;

public:
  QNamePool(ulong size);

  ~QNamePool();

  QNameItemNaive* insert(const char* ns, const char* pre, const char* ln);

  void remove(QNameItemNaive* qn);

  HashEntry* hash(const char* ns, const char* pre, const char* ln);
  void unhash(const char* ns, const char* pre, const char* ln);
  void resizeHashTab();
};


}

#endif
