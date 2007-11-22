/*
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: David Graf (david.graf@28msec.com)
 *
 */

#ifndef XQP_SIMPLE_COLLECTION_H
#define XQP_SIMPLE_COLLECTION_H

#include <vector>
#include "store/api/collection.h"

namespace xqp
{

class SimpleCollection : public Collection
{
protected:
  Item_t               theUri;
  std::vector<Item_t>  theNodes;

public:
  SimpleCollection(const Item_t& uri);
  virtual ~SimpleCollection();

  virtual Iterator_t getIterator(bool idsNeeded);

  virtual void addToCollection(Item_t item, long position = -1);
  virtual void addToCollection(Iterator_t& items, long position = -1);
  virtual void addToCollection(std::iostream& stream, long position = -1);

  virtual void deleteFromCollection(long position);

  Item_t getUri() { return theUri; }
};

} /* namespace xqp */

#endif /* XQP_SIMPLE_COLLECTION_H */
