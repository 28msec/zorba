/*
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: David Graf, Markos Zaharioudakis
 *
 */

#ifndef DEFAULT_STORE_COLLECTION
#define DEFAULT_STORE_COLLECTION

#include <set>
#include "store/api/collection.h"

namespace xqp
{
typedef rchandle<class SimpleCollection> SimpleCollection_t;


/*******************************************************************************

********************************************************************************/
class SimpleCollection : public Collection
{
  friend class CollectionIter;

public:
  class CollectionIter : public Iterator
	{
  private:
    SimpleCollection_t         theCollection;
    std::set<Item_t>::iterator theIterator;
    
  public:
    CollectionIter(const SimpleCollection_t& collection);

    virtual ~CollectionIter() { }

    Item_t next();
    void reset();
    void close();
  };


protected:
  Item_t            theUri;
  std::set<Item_t>  theNodes;

public:
  SimpleCollection(const Item_t& uri);
  virtual ~SimpleCollection();

  Item_t getUri() { return theUri; }

  unsigned long size() const { return theNodes.size(); }

  virtual Iterator_t getIterator(bool idsNeeded);

  virtual void addToCollection(const Item_t& node);
  virtual void addToCollection(Iterator_t& nodes);
  virtual Item_t addToCollection(std::iostream& stream);

  virtual void removeFromCollection(const Item_t& node);  
};

} /* namespace xqp */

#endif
