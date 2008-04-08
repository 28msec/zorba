#ifndef ZORBA_CONSTRUCTORS_H
#define ZORBA_CONSTRUCTORS_H

#include <vector>
#include "zorbatypes/xqpstring.h"

#include "common/shared_types.h"
#include "runtime/base/unarybase.h"
#include "runtime/base/binarybase.h"
#include "runtime/base/narybase.h"
#include "store/api/iterator.h"

namespace zorba {


/*********************************************************************************

  DocumentIterator constructs a document node and its subtree.
  
  theChild:      Iter that produces the content of the document element

*********************************************************************************/
class DocumentIteratorState : public PlanIteratorState
{
public:
  bool      theTypePreserve;
  bool      theNsPreserve;
  bool      theNsInherit;

  Iterator* childWrapper;

  ~DocumentIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};


class DocumentIterator : public UnaryBaseIterator<DocumentIterator,
                                                  DocumentIteratorState>
{
public:
  DocumentIterator(const QueryLoc& loc, PlanIter_t& aChild)
    : UnaryBaseIterator<DocumentIterator, DocumentIteratorState>(loc, aChild) {}

  bool isUpdateIterator() const { return false; }

  void openImpl(PlanState& planState, uint32_t& offset);
  store::Item_t nextImpl(PlanState& planState) const;

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
  DocumentContentIterator(const QueryLoc& loc, PlanIter_t& aContent)
    : UnaryBaseIterator<DocumentContentIterator, PlanIteratorState>(loc, aContent)
  {}

  store::Item_t nextImpl(PlanState& planState) const;

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
                      element, and whose URI part is a constant. 
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

  NamespaceContext_t  theLocalBindings;

  bool                theIsRoot;

public:
  ElementIterator (
      const QueryLoc&     loc,
      PlanIter_t&         aQNameIter,
      PlanIter_t&         aAttrs,
      PlanIter_t&         aChildren,
      namespace_context*  localBindings,
      bool                isRoot);

  bool isUpdateIterator() const { return false; }
  
  void openImpl(PlanState& planState, uint32_t& offset);
  store::Item_t nextImpl(PlanState& planState) const;
  void resetImpl(PlanState& planState) const;
  void closeImpl(PlanState& planState);

  uint32_t getStateSize() const { return sizeof(ElementIteratorState); }
  uint32_t getStateSizeOfSubtree() const;
  
  void accept(PlanIterVisitor&) const;
};
  

/*******************************************************************************

  ElementContentIterator

  Used to (a) create text nodes in the content sequence of an element constructor,
  and (b) to check that all attribute nodes in the content sequence appear before
  any other item in the sequence.

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
        const QueryLoc& loc,
        PlanIter_t& aQNameIter,
        PlanIter_t& aValueIter,
        bool isRoot);

  bool isUpdateIterator() const { return false; }
    
  store::Item_t nextImpl(PlanState& planState) const;
  
  virtual void accept(PlanIterVisitor&) const;
};


/*******************************************************************************
  NameCast Iterator casts QNames of computed elements that are not known
  till execution time.
********************************************************************************/
class NameCastIterator : public UnaryBaseIterator<NameCastIterator, PlanIteratorState> {
  friend class PrinterVisitor;
private:
  NamespaceContext_t theNCtx;

public:
  NameCastIterator(const QueryLoc& loc, PlanIter_t& aChild, NamespaceContext_t aNCtx);

  virtual ~NameCastIterator();

  store::Item_t nextImpl(PlanState& planState) const;
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
        const QueryLoc& loc, 
        PlanIter_t& aComment,
        bool isRoot);

  bool isUpdateIterator() const { return false; }
  
  store::Item_t nextImpl(PlanState& planState) const;
  
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
        const QueryLoc& loc, 
        PlanIter_t& aTarget,
        PlanIter_t& aContent,
        bool isRoot);

  bool isUpdateIterator() const { return false; }
  
  store::Item_t nextImpl(PlanState& planState) const;
  
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
  TextIterator( const QueryLoc& loc, PlanIter_t& aChild, bool isRoot);

  bool isUpdateIterator() const { return false; }
  
  store::Item_t nextImpl(PlanState& planState) const;
  virtual void accept(PlanIterVisitor&) const;
};


/*******************************************************************************
   Used to concatenate adjacent atomic values in the input sequence into a 
   text node. Concatenation inserts a single space between each pair of atomic
   values.
********************************************************************************/
class EnclosedIteratorState : public PlanIteratorState
{
public:
  xqpStringStore  * theAttrContentString;
  xqpStringStore  * theElemContentString;
  store::Item_t     theContextItem;
  Iterator_t        theDocChildren;

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
        const QueryLoc& loc,
        PlanIter_t& childIter);

  store::Item_t nextImpl(PlanState& planState) const;
  
  virtual void accept(PlanIterVisitor&) const;

  bool getAttrContent() const;
  void setAttrContent();

  bool isUpdateIterator() const { return theChild->isUpdateIterator(); }
};

} /* namespace zorba */
#endif  /* ZORBA_CONSTRUCTORS_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
