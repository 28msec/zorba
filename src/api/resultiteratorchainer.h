#ifndef ZORBA_RESULT_ITERATOR_CHAINER_H
#define ZORBA_RESULT_ITERATOR_CHAINER_H

#include <vector>
#include "store/api/iterator.h"
#include "common/shared_types.h"

namespace zorba { 
  
  class ResultIterator;

  namespace store {

// wrap the outside result iterator for query chaining
// we need to do this because only the result iterator know which error handler he needs to report to
class ResultIteratorChainer : public Iterator
{
private:
  ResultIterator* theResult;

public:
  ResultIteratorChainer(ResultIterator*);
  virtual ~ResultIteratorChainer();

  virtual void open();
  virtual Item_t next();
  virtual void reset();
  virtual void close();
};

} // namespace store
} // namespace zorba

#endif
