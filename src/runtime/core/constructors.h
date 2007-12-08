
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

  theQName          : The qname of the node (ns, pre, local)
  theChildrenIter   : The iterator that produces the child nodes of the new node.
                      This will ALWAYS be an ElementContentIterator, usually
                      followed by a ConcatIterator.
  theAttributesIter : The iterator that produces the attributes of the new node.
  theNamespacesIter : This is to be used in the future, when it will be possible
                      to have namespace declarations whose URI is not constant.
  theNsBindings     : The (prefix, nsURI) pairs corrsponding to namespace
                      declarations that appear in the opening tag of the
                      element, and whose URI part is a contant. 

********************************************************************************/
class ElementIterator : public Batcher<ElementIterator>
{
  typedef std::vector<std::pair<xqpString, xqpString> > NamespaceBindings;

private:
  QNameItem_t       theQName;
  PlanIter_t        theQNameIter;
  PlanIter_t        theChildrenIter;
  PlanIter_t        theAttributesIter;
  PlanIter_t        theNamespacesIter;
  NamespaceBindings theNsBindings;

public:
  ElementIterator(
        const yy::location& loc, 
        const QNameItem_t& aQName,
        PlanIter_t& aChildren,
        PlanIter_t& aAttrs);
  
  ElementIterator(
        const yy::location& loc,
        PlanIter_t aQNameIter,
        PlanIter_t aChildren);
  
  const QNameItem_t& getQName() const { return theQName; }
  
  Item_t nextImpl(PlanState& planState);
  void resetImpl(PlanState& planState);
  void releaseResourcesImpl(PlanState& planState);

  virtual uint32_t getStateSize() const { return sizeof(PlanIterator::PlanIteratorState); }
  virtual uint32_t getStateSizeOfSubtree() const;
  virtual void setOffset(PlanState& planState, uint32_t& offset);
  
  virtual void accept(PlanIterVisitor&) const;
};
  

/*******************************************************************************
  Used to make e.g. the concatenation of adjacent text nodes in the content 
  sequence of an element constructor. Usually, the child of this iterator
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

  uint32_t getStateSize() const { return sizeof(ElementContentState); }

  void setOffset(PlanState& planState, uint32_t& offset);
  
  virtual void accept(PlanIterVisitor&) const;
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
  
  virtual void accept(PlanIterVisitor&) const;
};


/*******************************************************************************

  CommentIterator constructs a comment element.

  theExpressionIter : The iterator that produces the content of the comment. It
                      could be a simple text iterator, or a full expression.

********************************************************************************/

class CommentIterator : public UnaryBaseIterator<CommentIterator> {

public:
  CommentIterator(
        const yy::location& loc, 
        PlanIter_t& aComment);
  
  Item_t nextImpl(PlanState& planState);
  
  virtual void accept(PlanIterVisitor&) const;
};


/*******************************************************************************

  TextIterator constructs a comment element.

  theChild : The iterator that produces the text. It
             could be a simple text iterator, or a full expression.

********************************************************************************/

class TextIterator : public UnaryBaseIterator<TextIterator>
{

public:
  TextIterator( const yy::location& loc, PlanIter_t& aChild);
  
  Item_t nextImpl(PlanState& planState);
  virtual void accept(PlanIterVisitor&) const;
};

} /* namespace xqp */
#endif  /* XQP_CONSTRUCTORS_H */
