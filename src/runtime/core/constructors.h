
#ifndef XQP_CONSTRUCTORS_H
#define XQP_CONSTRUCTORS_H

#include "context/common.h"
#include "util/rchandle.h"
#include "util/tracer.h"
#include "compiler/parser/location.hh"
#include "runtime/base/iterator.h"
#include "runtime/base/unarybase.h"
#include "runtime/base/binarybase.h"

#include <assert.h>
#include <iostream>
#include <vector>

namespace xqp {

class Item;
class node;
class zorba;


/*********************************************************************************

  DocumentIterator constructs a document element
  
  theChild:      Iter that produces the content of the document element

*********************************************************************************/
class DocumentIterator : public UnaryBaseIterator<DocumentIterator>
{
public:
  DocumentIterator( const yy::location& loc, PlanIter_t& aChild);
  
  Item_t nextImpl(PlanState& planState);
  virtual void accept(PlanIterVisitor&) const;
};


class DocumentContentIterator : public UnaryBaseIterator<DocumentContentIterator> 
{
public:
  DocumentContentIterator( const yy::location& loc, PlanIter_t& aContent);
  
  Item_t nextImpl(PlanState& planState);
  virtual void accept(PlanIterVisitor&) const;
};


/**
 * Filters out all DocumentNodes and returns their children instead of them.
 **/
class DocFilterIterator : public UnaryBaseIterator<DocFilterIterator>
{
protected:
  class DocFilterIteratorState : public PlanIteratorState
  {
    public:
      Iterator_t theChildren;
      Item_t     theCurItem;
      
      void init();
  };
public:
  DocFilterIterator( const yy::location& loc, PlanIter_t& aChild);

  Item_t nextImpl(PlanState& planState);
  void releaseResourcesImpl(PlanState& planState);

  uint32_t getStateSize() const { return sizeof(DocFilterIteratorState); }

  virtual void accept(PlanIterVisitor&) const;
};


/*******************************************************************************

  ElementIterator constructs an element node.

  theQNameIter      : Iter that produces the qname of the element
  theChildrenIter   : The iterator that produces the child nodes of the new node.
                      This will ALWAYS be an ElementContentIterator, usually
                      followed by a ConcatIterator.
  theAttributesIter : The iterator that produces the attributes of the new node.
  theNamespacesIter : This is to be used in the future, when it will be possible
                      to have namespace declarations whose URI is not constant.
  theNsBindings     : The (prefix, nsURI) pairs corrsponding to namespace
                      declarations that appear in the opening tag of the
                      element, and whose URI part is a contant. 
  theAssignId       : Whether to assign an id to the new node or not. Initially,
                      only the root node of a constructed xml tree is assigned
                      a node id. Node ids to the children are assigned when the
                      children are actually accessed via the getChildren() method
                      (see ChildrenIterator and AttributesIterator in node_items.h)

********************************************************************************/
class ElementIterator : public Batcher<ElementIterator>
{
  typedef std::vector<std::pair<xqpString, xqpString> > NamespaceBindings;

private:
  PlanIter_t        theQNameIter;
  PlanIter_t        theAttributesIter;
  PlanIter_t        theChildrenIter;
  PlanIter_t        theNamespacesIter;
  NamespaceBindings theNsBindings;
  bool              theAssignId;

public:
  ElementIterator (
      const yy::location& loc,
      PlanIter_t& aQNameIter,
      PlanIter_t& aAttrs,
      PlanIter_t& aChildren,
      bool assignId);
  
  ElementIterator (
      const yy::location& loc,
      PlanIter_t& aQNameIter,
      PlanIter_t& aChildren,
      bool assignId);

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
    bool       theNoAttrAllowed;

    void init();
  };

public:
  ElementContentIterator(const yy::location& loc, PlanIter_t& childIter);

  Item_t nextImpl(PlanState& planState);
  void resetImpl(PlanState& planState);
  void releaseResourcesImpl(PlanState& planState);

  uint32_t getStateSize() const { return sizeof(ElementContentState); }
  
  virtual void accept(PlanIterVisitor&) const;
};
  

/*******************************************************************************
  AttributeIterator constructs an attribute element
  
  theQNameIter:     Iter that produces the name (qname) of the element
  theChild:         Iter that produces the value of the attribute element
********************************************************************************/
class AttributeIterator : public BinaryBaseIterator<AttributeIterator>
{
private:
  bool       theAssignId;

public:
  AttributeIterator(
        const yy::location& loc,
        PlanIter_t& aQNameIter,
        PlanIter_t& aValueIter,
        bool assignId);
    
  Item_t nextImpl(PlanState& planState);
  
  virtual void accept(PlanIterVisitor&) const;
};


/*******************************************************************************

  CommentIterator constructs a comment element.

  theExpressionIter : The iterator that produces the content of the comment. It
                      could be a simple text iterator, or a full expression.

********************************************************************************/

class CommentIterator : public UnaryBaseIterator<CommentIterator>
{
protected:
  bool       theAssignId;

public:
  CommentIterator(
        const yy::location& loc, 
        PlanIter_t& aComment,
        bool assignId);
  
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
protected:
  bool       theAssignId;

public:
  TextIterator( const yy::location& loc, PlanIter_t& aChild, bool assignId);
  
  Item_t nextImpl(PlanState& planState);
  virtual void accept(PlanIterVisitor&) const;
};

} /* namespace xqp */
#endif  /* XQP_CONSTRUCTORS_H */
