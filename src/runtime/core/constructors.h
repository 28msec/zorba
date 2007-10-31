
#ifndef XQP_CONSTRUCTORS_H
#define XQP_CONSTRUCTORS_H

#include "context/common.h"
#include "util/rchandle.h"
#include "util/tracer.h"
#include "compiler/parser/location.hh"
#include "runtime/base/iterator.h"
#include "runtime/base/unarybase.h"

#include <assert.h>
#include <iostream>
#include <vector>

namespace xqp {

class Item;
class node;
class zorba;


/*******************************************************************************

  ElementIterator computes a direct element constructor.

  theQName      : The qname of the node (ns, pre, local)
  theChildren   : The iterator that produces the child nodes of the new node.
                  Normally, this will be an ElementContentIterator, followed
                  by a ConcatIterator.
  theAttributes : The iterator that produces the attributes of the new node.
  theNamespaceBindings :

********************************************************************************/
class ElementIterator : public Batcher<ElementIterator>
{
private:
  QNameItem_t theQName;
  PlanIter_t  theChildren;
  PlanIter_t  theAttributes;
  PlanIter_t  theNamespaceBindings;
	
public:
  ElementIterator(
        const yy::location& loc, 
        const QNameItem_t& qname,
        PlanIter_t& children,
        PlanIter_t& attributes);
	
  Item_t nextImpl(PlanState& planState);
  void resetImpl(PlanState& planState);
  void releaseResourcesImpl(PlanState& planState);

	std::ostream& _show(std::ostream& os) const;

  virtual int32_t getStateSize();
  virtual int32_t getStateSizeOfSubtree();
  virtual void setOffset(PlanState& planState, int32_t& offset);
};
	

/*******************************************************************************
  Used to make e.g. the concatenation of adjacent text nodes in the content 
  sequence of an element constructor. Normally, the child of this iterator
  will be a ConcatIterator that computes the content sequence from its various
  components.
********************************************************************************/
class ElementContentIterator : public UnaryBaseIterator<ElementContentIterator>
{
protected:
  class ElementContentState : public PlanIteratorState
  {
  public:
    xqp_string theString;
    Item_t     theContextItem;

    void init();
  };

public:
  ElementContentIterator(const yy::location& loc, PlanIter_t& childIter);

  Item_t nextImpl(PlanState& planState);
  void resetImpl(PlanState& planState);
  void releaseResourcesImpl(PlanState& planState);

  int32_t getStateSize() { return sizeof(ElementContentState); }

  void setOffset(PlanState& planState, int32_t& offset);
};
	

/*******************************************************************************

********************************************************************************/
class AttributeIterator : public UnaryBaseIterator<AttributeIterator>
{
private:
  QNameItem_t theQName;
		
public:
  AttributeIterator(
        const yy::location& loc,
        const QNameItem_t& qname,
        PlanIter_t& value);
		
  Item_t nextImpl(PlanState& planState);
};


}	/* namespace xqp */
#endif	/* XQP_CONSTRUCTORS_H */

