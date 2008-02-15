#ifndef XQP_ITERATOR
#define XQP_ITERATOR

#include "util/rchandle.h"


namespace xqp
{

template <class Object> class rchandle;
  
typedef rchandle<class Item> Item_t;
typedef rchandle<class Iterator> Iterator_t;


/**
 * General iterator interface. Used to program iterators which return a
 * sequence of items, wrapped into a rchandle object for garbage collection
 */
class Iterator : virtual public rcobject
{
public:
  virtual ~Iterator() {}

  virtual void open() = 0;
  virtual Item_t next() = 0;
  virtual void reset() = 0;
  virtual void close() = 0;
};
  
}

#endif
