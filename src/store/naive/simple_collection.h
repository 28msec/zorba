/*
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: David Graf, Markos Zaharioudakis
 *
 */

#ifndef XQO_DEFAULT_STORE_COLLECTION
#define XQP_DEFAULT_STORE_COLLECTION

#include <set>
#include "common/shared_types.h"
#include "store/api/collection.h"
#include "runtime/iterator.h"


namespace xqp
{

/*******************************************************************************

********************************************************************************/
class SimpleCollection : public Collection
{
  friend class CollectionIter;

public:
  class CollectionIter : public Iterator
	{
  private:
    SimpleCollection_t            theCollection;
    std::set<XmlTree_t>::iterator theIterator;
    
  public:
    CollectionIter(SimpleCollection* collection);

    virtual ~CollectionIter() { }

    void open();
    Item_t next();
    void reset();
    void close();
  };


protected:
  Item_t               theUri;
  std::set<XmlTree_t>  theXmlTrees;

public:
  SimpleCollection(Item* uri);
  virtual ~SimpleCollection();

  Item_t getUri() { return theUri; }

  unsigned long size() const { return theXmlTrees.size(); }

  Iterator_t getIterator(bool idsNeeded);

  Item_t addToCollection(std::istream& stream);
  void addToCollection(const Item* node);
  void addToCollection(Iterator* nodes);

  void removeFromCollection(const Item* node);  
};

} /* namespace xqp */

#endif
