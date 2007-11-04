/*
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: David Graf (david.graf@28msec.com)
 *
 */

#ifndef XQP_SIMPLE_TEMP_SEQ_H
#define XQP_SIMPLE_TEMP_SEQ_H

#include <vector>

#include "store/api/temp_seq.h"
#include "runtime/base/iterator.h"

namespace xqp
{

/**
 * Very simple implementation of Temp Sequence. It saves the resulting items
 * of an iterator eager in a vector.
 */
class SimpleTempSeq : public TempSeq
{
 private:
  std::vector<Item_t> theItems;

 public:
  SimpleTempSeq(Iterator_t iterator);

 SimpleTempSeq(const std::vector<Item_t>& items) : theItems(items) {}

  virtual ~SimpleTempSeq();

  virtual Iterator_t getIterator();

  virtual Iterator_t getIterator(
        int32_t startPos,
        int32_t endPos,
        bool streaming = false);

  virtual Iterator_t getIterator(
        int32_t startPos,
        Iterator_t function,
        const std::vector<var_iterator>& var,
        bool streaming = false );

  virtual Iterator_t getIterator(
        const std::vector<int32_t>& positions,
        bool streaming = false);

  virtual Iterator_t getIterator(
        Iterator_t positions,
        bool streaming = false);

  virtual Item_t getItem ( int32_t position );
  virtual bool containsItem( int32_t position );

  virtual void purge();
  virtual void purgeUpTo(int32_t upTo );
  virtual void purgeItem(const std::vector<int32_t>& positions );
  virtual void purgeItem(int32_t position );
  virtual bool empty();

  class SimpleTempSeqIter : public Iterator
	{
  private:
    enum BorderType
    {
      none,
      startEnd,
      specificPositions
    };

    const std::vector<Item_t>* theItems;
    BorderType                 theBorderType;

    int32_t                    theCurPos;
    int32_t                    theStartPos;
    int32_t                    theEndPos;
    std::vector<int32_t>       thePositions;
    
  public:
    SimpleTempSeqIter(const std::vector<Item_t>* items);
    SimpleTempSeqIter(const std::vector<Item_t>* items, int startPos, int endPos);
    SimpleTempSeqIter(const std::vector<Item_t>* items, const std::vector<int32_t>& positions);
    ~SimpleTempSeqIter();

    Item_t next();
    void reset();
  };

}; /* class SimpleTempSeq */

} /* namespace xqp */

#endif /* XQP_SIIMPLE_TEMP_SEQ_H */
