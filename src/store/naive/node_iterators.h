#ifndef XQP_DEFAULT_STORE_NODE_ITERATORS
#define XQP_DEFAULT_STORE_NODE_ITERATORS


#include "util/Assert.h"
#include "store/api/item.h"
#include "store/naive/ordpath.h"
#include "store/util/handle_set.h"

namespace xqp
{

template <class Object> class rchandle;

typedef rchandle<class Item> Item_t;
typedef rchandle<class NodeImpl> NodeImpl_t;
typedef rchandle<class ElementNodeImpl> ElementNodeImpl_t;


/*******************************************************************************
  This iterator is used during the getChildren() method to set the parent
  pointer and the nodeid in each child node of an element or document node.

  theParentNode : The element or doc node whose children are being retrieved.
  theCurrentPos : The next child to be retrieved.
********************************************************************************/
class ChildrenIterator : public Iterator
{
protected:
  NodeImpl_t          theParentNode;
  NodeVector&         theChildNodes;

  unsigned long       theStartingId;

  unsigned long       theCurrentPos;

public:
  ChildrenIterator(NodeImpl* parent, unsigned long startid);

  Item_t next();
  void reset();
  void close();
};


/*******************************************************************************
  This iterator is used during the getAttributes() method to set the parent
  pointer and the nodeid in each attribute node of an element node.

  theParentNode : The element node whose attributes are being retrieved.
  theAttrNodes  : The attributes of theParentNode.
  theCurrentPos : The next attribute to be retrieved.

********************************************************************************/
class AttributesIterator : public Iterator
{
protected:
  ElementNodeImpl_t   theParentNode;
  NodeVector&         theAttrNodes;

  unsigned long       theCurrentPos;

public:
  AttributesIterator(ElementNodeImpl* parent);

  Item_t next();
  void reset();
  void close();
};


/*******************************************************************************
  This iterator is used to eliminated duplicate nodes in the multiset of nodes
  produced by another iterator.

  theInput   : This is actually a PlanIterWrapper object that wraps the actual
               runtime iterator that produces the node multiset.
  theNodeSet : A hash-based set used to do the duplicate elimination. The
               elimination is done based on the values of the pointers that
               point to the input nodes.
********************************************************************************/
class StoreNodeDistinctIterator : public Iterator
{
protected:
  Iterator_t       theInput;
  HandleSet<Item>  theNodeSet;

public:
  StoreNodeDistinctIterator(const Iterator_t& input) : theInput(input) { }

  virtual ~StoreNodeDistinctIterator() { close(); }

  Item_t next();
  void reset();
  void close();
};

/*******************************************************************************
  This is an extension to StoreNodeDistinctIterator which allows atomic items 
  in the received sequences. The received sequences must contain nodes are atomic
  items, but not a mixture. In case of atomic items, the output sequences
  is equivalent to the input sequence, else, the same operations as in
  StoreNodeDistinctIterator are applied.
********************************************************************************/
class StoreNodeDistinctOrAtomicIterator : public StoreNodeDistinctIterator
{
protected:
  bool theAtomic;
  bool theUsed;

public:
  StoreNodeDistinctOrAtomicIterator(const Iterator_t& aInput)
    : StoreNodeDistinctIterator(aInput), theAtomic(false), theUsed(false){}

  Item_t next(); 
  void reset() { theUsed = false; StoreNodeDistinctIterator::reset(); }
  void close() { StoreNodeDistinctIterator::close(); }
};


/*******************************************************************************
  This iterator is used to sort by document order the nodes produced by another
  iterator.

  theInput  : This is actually a PlanIterWrapper object that wraps the actual
              runtime iterator that produces the input nodes.
  theNodes  : A vector that stores rchandles to the nodes.
********************************************************************************/
class StoreNodeSortIterator : public Iterator
{
protected:
  class ComparisonFunction
  {
  protected:
    bool theAscending;

  public:
    ComparisonFunction(bool asc = true) : theAscending(asc) { }

    bool operator()(const NodeImpl_t& n1, const NodeImpl_t& n2) const
    {
      return (theAscending ?
              n1->getTreeId() < n2->getTreeId() ||
              n1->getTreeId() == n2->getTreeId() &&
              n1->getOrdPath() < n2->getOrdPath()
              : 
              n1->getTreeId() > n2->getTreeId() ||
              n1->getTreeId() == n2->getTreeId() &&
              n1->getOrdPath() > n2->getOrdPath());
    }
  };

protected:
  Iterator_t               theInput;
  bool                     theAscendant;
  bool                     theDistinct;

  std::vector<NodeImpl_t>  theNodes;
  long                     theCurrentNode;

public:
  StoreNodeSortIterator(
        const Iterator_t& input,
        bool              ascendant,
        bool              distinct)
    :
    theInput(input),
    theAscendant(ascendant),
    theDistinct(distinct),
    theCurrentNode(-1)
  {
  }

  virtual ~StoreNodeSortIterator() { close(); }

  Item_t next();
  void reset();
  void close();
};


/*******************************************************************************
  This is an extension to StoreNodeSortIterator which allows atomic items 
  in the received sequences. The received sequences must contain nodes are atomic
  items, but not a mixture. In case of atomic items, the output sequences
  is equivalent to the input sequence, else, the same operations as in
  StoreNodeSortIterator are applied.
********************************************************************************/
class StoreNodeSortOrAtomicIterator : public StoreNodeSortIterator
{
protected:
  bool theAtomic;
  bool theUsed;

public:
  StoreNodeSortOrAtomicIterator(const Iterator_t& aInput, bool aAsc, bool aDistinct)
    : StoreNodeSortIterator(aInput, aAsc, aDistinct), theAtomic(false), theUsed(false) {}

  Item_t next();
  void reset() { theUsed = false; StoreNodeSortIterator::reset(); }
  void close() { StoreNodeSortIterator::close(); }
};


}

#endif
