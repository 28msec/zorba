#ifndef XQP_CONSTRUCTORS_H
#define XQP_CONSTRUCTORS_H

#include "runtime/base/iterator.h"
#include "runtime/base/unarybase.h" // TODO delete after iterator refactoring
#include "runtime/base/binarybase.h" // TODO delete after iterator refactoring
#include "runtime/base/narybase.h"
#include "common/shared_types.h"

#include <vector>

namespace xqp {


/*********************************************************************************

  DocumentIterator constructs a document node and its subtree.
  
  theChild:      Iter that produces the content of the document element

*********************************************************************************/
class DocumentIteratorState : public PlanIteratorState
{
public:
  ~DocumentIteratorState();
  bool theTypePreserve;
  bool theNsPreserve;
  bool theNsInherit;
  Iterator* childWrapper;

  void init(PlanState&);
  void reset(PlanState&);
};


class DocumentIterator : public UnaryBaseIterator<DocumentIterator,
                                                  DocumentIteratorState>
{
public:
  DocumentIterator(const yy::location& loc, PlanIter_t& aChild)
    :
    UnaryBaseIterator<DocumentIterator, DocumentIteratorState>(loc, aChild) {}

  Item_t nextImpl(PlanState& planState);

  void accept(PlanIterVisitor&) const;
};


/*********************************************************************************

  DocumentContentIterator checks that the children of a doc node do not include
  any attribute nodes.
  
  theChild:      Iter that produces the content of the document element

*********************************************************************************/
class DocumentContentIterator : public UnaryBaseIterator<DocumentContentIterator,
                                                         PlanIteratorState> 
{
public:
  DocumentContentIterator(const yy::location& loc, PlanIter_t& aContent)
    : UnaryBaseIterator<DocumentContentIterator, PlanIteratorState>(loc, aContent)
  {}

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
  theLocalBindings  : The (prefix, nsURI) pairs corresponding to namespace
                      declarations that appear in the opening tag of the
                      element, and whose URI part is a contant. 
  theIsRoot         : Whether this is the root in a tree of constructor iterators.
                      

********************************************************************************/
class ElementIteratorState : public PlanIteratorState
{
public:
  bool theTypePreserve;
  bool theNsPreserve;
  bool theNsInherit;

  void init(PlanState&);
  void reset(PlanState&);
};

class ElementIterator : public Batcher<ElementIterator>
{
  typedef std::vector<std::pair<xqpString, xqpString> > NsBindings;

private:
  PlanIter_t          theQNameIter;
  PlanIter_t          theAttributesIter;
  PlanIter_t          theChildrenIter;
  PlanIter_t          theNamespacesIter;

  NamespaceContext_t  theContextBindings;
  NamespaceContext_t  theLocalBindings;

  bool                theIsRoot;

public:
  ElementIterator (
      const yy::location& loc,
      PlanIter_t&         aQNameIter,
      PlanIter_t&         aAttrs,
      PlanIter_t&         aChildren,
      namespace_context*  ctxBindings,
      namespace_context*  localBindings,
      bool                isRoot);
  
  void openImpl(PlanState& planState, uint32_t& offset);
  Item_t nextImpl(PlanState& planState);
  void resetImpl(PlanState& planState);
  void closeImpl(PlanState& planState);

  uint32_t getStateSize() const { return sizeof(ElementIteratorState); }
  uint32_t getStateSizeOfSubtree() const;
  
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

  void init(PlanState&);
  void reset(PlanState&);
};

NARY_ITER_STATE(ElementContentIterator, ElementContentState);


/*******************************************************************************
  AttributeIterator constructs an attribute element
  
  theQNameIter:     Iter that produces the name (qname) of the element
  theChild:         Iter that produces the value of the attribute element
********************************************************************************/
class AttributeIterator : public BinaryBaseIterator<AttributeIterator, PlanIteratorState>
{
private:
  bool       theIsRoot;

public:
  AttributeIterator(
        const yy::location& loc,
        PlanIter_t& aQNameIter,
        PlanIter_t& aValueIter,
        bool isRoot);
    
  Item_t nextImpl(PlanState& planState);
  
  virtual void accept(PlanIterVisitor&) const;
};


/*******************************************************************************

  CommentIterator constructs a comment element.

  theExpressionIter : The iterator that produces the content of the comment. It
                      could be a simple text iterator, or a full expression.

********************************************************************************/
class CommentIterator : public UnaryBaseIterator<CommentIterator, PlanIteratorState>
{
protected:
  bool       theIsRoot;

public:
  CommentIterator(
        const yy::location& loc, 
        PlanIter_t& aComment,
        bool isRoot);
  
  Item_t nextImpl(PlanState& planState);
  
  virtual void accept(PlanIterVisitor&) const;
};


/*******************************************************************************

  PiIterator constructs a PI element.

********************************************************************************/
class PiIterator : public BinaryBaseIterator<PiIterator, PlanIteratorState>
{
protected:
  bool       theIsRoot;

public:
  PiIterator(
        const yy::location& loc, 
        PlanIter_t& aTarget,
        PlanIter_t& aContent,
        bool isRoot);
  
  Item_t nextImpl(PlanState& planState);
  
  virtual void accept(PlanIterVisitor&) const;
};


/*******************************************************************************

  TextIterator constructs a comment element.

  theChild : The iterator that produces the text. It
             could be a simple text iterator, or a full expression.

********************************************************************************/
class TextIterator : public UnaryBaseIterator<TextIterator, PlanIteratorState>
{
protected:
  bool       theIsRoot;

public:
  TextIterator( const yy::location& loc, PlanIter_t& aChild, bool isRoot);
  
  Item_t nextImpl(PlanState& planState);
  virtual void accept(PlanIterVisitor&) const;
};


/*******************************************************************************
   Used to make the casting and concatenation of 
   atomic values in the sequences of an enclosed expression.
********************************************************************************/
class EnclosedIteratorState : public PlanIteratorState
{
public:
  xqpStringStore* theString;
  Item_t     theContextItem;

  void init(PlanState&);
  void reset(PlanState&);
  ~EnclosedIteratorState();
};

class EnclosedIterator : public UnaryBaseIterator<EnclosedIterator,
                                                  EnclosedIteratorState>
{
private:
  bool theAttrContent;
  
public:
  EnclosedIterator(
        const yy::location& loc,
        PlanIter_t& childIter);

  Item_t nextImpl(PlanState& planState);
  
  virtual void accept(PlanIterVisitor&) const;

  bool getAttrContent() const { return theAttrContent; }
  void setAttrContent()       { theAttrContent = true; }
};


/*******************************************************************************

  Filters out all DocumentNodes and returns their children instead of them.

********************************************************************************/
class DocFilterIteratorState : public PlanIteratorState
{
public:
  Iterator_t theChildren;
  Item_t     theCurItem;
    
  void init(PlanState&);
  void reset(PlanState&);

  ~DocFilterIteratorState()
  {
    if (theChildren != NULL) {
      theChildren->close();
    }
  }
};

class DocFilterIterator : public UnaryBaseIterator<DocFilterIterator,
                                                   DocFilterIteratorState>
{
public:
  DocFilterIterator( const yy::location& loc, PlanIter_t& aChild)
    : UnaryBaseIterator<DocFilterIterator, DocFilterIteratorState>(loc, aChild) {}

  Item_t nextImpl(PlanState& planState);

  virtual void accept(PlanIterVisitor&) const;
};


} /* namespace xqp */
#endif  /* XQP_CONSTRUCTORS_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
