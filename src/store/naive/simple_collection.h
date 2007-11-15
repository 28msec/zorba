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
template <class Object> class rchandle;

class NodeItem;
typedef rchandle<class NodeItem> NodeItem_t;


class SimpleCollection : public Collection
{
protected:
  AnyUriItem_t             theUri;
  std::vector<NodeItem_t>  theNodes;

public:
  SimpleCollection(const AnyUriItem_t& uri);
  virtual ~SimpleCollection();

  virtual Iterator_t getIterator(bool idsNeeded);
  virtual void addToCollection(Item_t item, int32_t position = -1);
  virtual void addToCollection(Iterator_t& items, int32_t position = -1);
  virtual void addToCollection(std::iostream& stream, int32_t position = -1);
  virtual void deleteFromCollection(int32_t position);

  AnyUriItem_t getURI() { return theUri; }
};

} /* namespace xqp */

#endif /* XQP_SIMPLE_COLLECTION_H */
