#ifndef XQP_STRING_POOL_H
#define XQP_STRING_POOL_H

#include "types/representations.h"

namespace xqp
{

/*******************************************************************************

  theNumEntries  : The total number of strings stored in the pool.

  theHashTab     : The hash table. Each hash bucket consists of a list of
                   hash entries, and each hash entry contains a pointer to
                   an xqpStringStore_t.   
  theHashTabSize : The number of hash buckets in theHashTab. 
  theLoadFactor  : The max fraction of non-empty hash buckets after which
                   the hash table is doubled in size.

********************************************************************************/
class StringPool
{
  typedef rchandle<class xqpStringStore> xqpStringStore_t;

protected:

  class HashEntry
  {
  public:
    xqpStringStore_t   theString;
    HashEntry        * theNext;

    HashEntry() : theString(NULL), theNext(NULL) { }

    ~HashEntry() { theString = NULL; }
  };

public:
  static const unsigned long DEFAULT_POOL_SIZE;
  static const float DEFAULT_LOAD_FACTOR;

protected:
  unsigned long           theNumEntries;

  std::vector<HashEntry>  theHashTab;
  unsigned long           theHashTabSize;
  float                   theLoadFactor;

public:
  StringPool(unsigned long size = DEFAULT_POOL_SIZE);

  ~StringPool();

  bool insert(const char* str, xqpStringStore_t& outStr);
  bool insert(const xqpStringStore& str);

  bool find(const xqp_string& str);

protected:
  HashEntry* hashInsert(
        const char* str,
        unsigned long strlen,
        unsigned long strhash,
        bool& found);

  void resizeHashTab(unsigned long newSize);
  void garbageCollect();
};


}

#endif
