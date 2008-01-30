
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

  DocumentIterator constructs a document node and its subtree.
  
  theChild:      Iter that produces the content of the document element

*********************************************************************************/
class DocumentIterator : public UnaryBaseIterator<DocumentIterator>
{
protected:
  class DocumentIteratorState : public PlanIteratorState
  {
  public:
    bool theTypePreserve;
    bool theNsPreserve;
    bool theNsInherit;
  };

public:
  DocumentIterator(const yy::location& loc, PlanIter_t& aChild);
  
  Item_t nextImpl(PlanState& planState);

  uint32_t getStateSize() const { return sizeof(DocumentIteratorState); }
  void setOffset(PlanState& planState, uint32_t& offset);

  void accept(PlanIterVisitor&) const;
};


/*********************************************************************************

  DocumentContentIterator checks that the children of a doc node do not include
  any attribute nodes.
  
  theChild:      Iter that produces the content of the document element

*********************************************************************************/
class DocumentContentIterator : public UnaryBaseIterator<DocumentContentIterator> 
{
public:
  DocumentContentIterator(const yy::location& loc, PlanIter_t& aContent);
  
  Item_t nextImpl(PlanState& planState);

  void accept(PlanIterVisitor&) const;
};


/*******************************************************************************

  ElementIterator constructs an element node and its subtree.

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
  theAssignId       : Whether to assign an id to the new node and its subtree.

********************************************************************************/
class ElementIterator : public Batcher<ElementIterator>
{
  typedef std::vector<std::pair<xqpString, xqpString> > NsBindings;

protected:
  class ElementIteratorState : public PlanIteratorState
  {
  public:
    bool theTypePreserve;
    bool theNsPreserve;
    bool theNsInherit;
  };

private:
  PlanIter_t  theQNameIter;
  PlanIter_t  theAttributesIter;
  PlanIter_t  theChildrenIter;
  PlanIter_t  theNamespacesIter;
  NsBindings  theNsBindings;
  bool        theAssignId;

public:
  ElementIterator (
      const yy::location& loc,
      PlanIter_t&  aQNameIter,
      PlanIter_t&  aAttrs,
      PlanIter_t&  aChildren,
      NsBindings&  nsBindings,
      bool         assignId);
  
  ElementIterator (
      const yy::location& loc,
      PlanIter_t&  aQNameIter,
      PlanIter_t&  aChildren,
      bool         assignId);

  Item_t nextImpl(PlanState& planState);
  void resetImpl(PlanState& planState);
  void releaseResourcesImpl(PlanState& planState);

  uint32_t getStateSize() const { return sizeof(ElementIteratorState); }
  uint32_t getStateSizeOfSubtree() const;
  void setOffset(PlanState& planState, uint32_t& offset);
  
  void accept(PlanIterVisitor&) const;
};
  

/*******************************************************************************

  ElementContentIterator

  Used to (a) create text nodes in the content sequence of an
  element constructor, and (b) to check that all attribute nodes in the content
  sequence appear before any other item in the sequence.

  Usually, the child of this iterator will be a ConcatIterator that computes
  the content sequence from its various components.

********************************************************************************/
class ElementContentState : public PlanIteratorState
{
public:
  bool  theNoAttrAllowed;

  void init();
  void reset();
};

NARY_ITER_STATE(ElementContentIterator, ElementContentState);


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

  PiIterator constructs a PI element.

********************************************************************************/
class PiIterator : public BinaryBaseIterator<PiIterator>
{
protected:
  bool       theAssignId;

public:
  PiIterator(
        const yy::location& loc, 
        PlanIter_t& aTarget,
        PlanIter_t& aContent,
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


/*******************************************************************************
   Used to make the casting and concatenation of 
   atomic values in the sequences of an enclosed expression.
********************************************************************************/
class EnclosedIterator : public UnaryBaseIterator<EnclosedIterator>
{
private:
  bool theAttrContent;
  
protected:
  class EnclosedState : public PlanIteratorState
  {
  public:
    xqpStringStore* theString;
    Item_t          theContextItem;

    void init();
  };

public:
  EnclosedIterator(
        const yy::location& loc,
        PlanIter_t& childIter);

  Item_t nextImpl(PlanState& planState);
  void resetImpl(PlanState& planState);
  void releaseResourcesImpl(PlanState& planState);

  uint32_t getStateSize() const { return sizeof(EnclosedState); }

  void setOffset(PlanState& planState, uint32_t& offset);
  
  virtual void accept(PlanIterVisitor&) const;

  bool getAttrContent() const { return theAttrContent; }
  void setAttrContent()       { theAttrContent = true; }
};


/*******************************************************************************

  Filters out all DocumentNodes and returns their children instead of them.

********************************************************************************/
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


} /* namespace xqp */
#endif  /* XQP_CONSTRUCTORS_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
