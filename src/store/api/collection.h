/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*- */

/*
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Authors: David Graf, Donald Kossmann, Tim Kraska, Markos Zaharioudakis
 */

#ifndef STORE_COLLECTION
#define STORE_COLLECTION

#include "common/shared_types.h"

namespace xqp 
{

class Collection : public rcobject
{
public:
  virtual ~Collection() {}

  /**
   * Returns the URI of the collection
   * @return URI
   */
  virtual Item_t getUri() = 0;

  /**
   * Reads the whole Collection from beginning to end; it is allowed to have
   * several concurrent iterators on the same Collection.
   * 
   * @param idsNeeded whether the returned items contain ids, e.g. for sorting
   * @return Iterator which iterates over the complete Collection
   * 
   * Ids == false is likely to be faster. 'idsNeeded' should only be set to
   * true if clients wants to sort or compare the items or sub-items generated
   * from the returned iterator.
   */
  virtual Iterator_t getIterator(bool idsNeeded) = 0;

  /**
   * Inserts into the collection an xml document or fragment given as text via
   * an input stream.
   *
   * @param stream The stream providing the data to insert (e.g. from a file).
   * @return The root node of the xml document or fragment.
   */
  virtual Item_t addToCollection(std::istream& stream) = 0;

  /**
   * Inserts a node to the collection.
   *
   * @param node The node to insert
   */
  virtual void addToCollection(const Item* node) = 0;

  /**
   * Inserts to the collection the set of nodes returned by the given iterator.
   *
   * @param nodeIter The iterator which produces the nodes to insert
   */
  virtual void addToCollection(Iterator* nodeIter) = 0;
		
  /**
   * Removes a node from the collection.
   *
   * @param node to be removed
   */
  virtual void removeFromCollection(const Item* node) = 0;
};

} /* namespace xqp */
#endif
