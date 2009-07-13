/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef ZORBA_CONSTRUCTORS_H
#define ZORBA_CONSTRUCTORS_H

#include <vector>
#include "zorbatypes/xqpstring.h"

#include "common/shared_types.h"
#include "runtime/base/unarybase.h"
#include "runtime/base/binarybase.h"
#include "runtime/base/narybase.h"
#include "runtime/base/noarybase.h"
#include "store/api/iterator.h"

namespace zorba {


/*********************************************************************************

  DocumentIterator constructs a document node and its subtree.
  
  theChild:      Iter that produces the content of the document element

*********************************************************************************/
class DocumentIterator : public UnaryBaseIterator<DocumentIterator,
                                                  PlanIteratorState>
{
private:
  bool      theTypePreserve;
  bool      theNsPreserve;
  bool      theNsInherit;

public:
  DocumentIterator(short sctx, const QueryLoc& loc, PlanIter_t& aChild)
    :
    UnaryBaseIterator<DocumentIterator, PlanIteratorState>(sctx, loc, aChild)
  {}

  void openImpl(PlanState& planState, uint32_t& offset);
  bool nextImpl(store::Item_t& result, PlanState& planState) const;

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
  DocumentContentIterator(short sctx, const QueryLoc& loc, PlanIter_t& aContent)
    :
    UnaryBaseIterator<DocumentContentIterator, PlanIteratorState>(sctx, loc, aContent)
  {}

  bool nextImpl(store::Item_t& result, PlanState& planState) const;

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
  static_context*  sctx;
  xqpStringStore_t baseUri;

  void init(PlanState&);
  void reset(PlanState&);
};

class ElementIterator : public NoaryBaseIterator<ElementIterator, ElementIteratorState>
{
  typedef std::vector<std::pair<xqpString, xqpString> > NsBindings;

private:
  PlanIter_t          theQNameIter;
  PlanIter_t          theAttributesIter;
  PlanIter_t          theChildrenIter;
  PlanIter_t          theNamespacesIter;

  NamespaceContext_t  theLocalBindings;

  bool                theIsRoot;

  bool                theTypePreserve;
  bool                theNsPreserve;
  bool                theNsInherit;

public:
  ElementIterator (
      short               sctx,
      const QueryLoc&     loc,
      PlanIter_t&         aQNameIter,
      PlanIter_t&         aAttrs,
      PlanIter_t&         aChildren,
      namespace_context*  localBindings,
      bool                isRoot);

  void openImpl(PlanState& planState, uint32_t& offset);
  bool nextImpl(store::Item_t& result, PlanState& planState) const;
  void resetImpl(PlanState& planState) const;
  void closeImpl(PlanState& planState);

  uint32_t getStateSizeOfSubtree() const;

  void accept(PlanIterVisitor&) const;
};
  

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
        short sctx,
        const QueryLoc& loc,
        PlanIter_t& aQNameIter,
        PlanIter_t& aValueIter,
        bool isRoot);

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
  
  virtual void accept(PlanIterVisitor&) const;
};


/*******************************************************************************
  NameCast Iterator casts QNames of computed elements that are not known
  till execution time.
********************************************************************************/
class NameCastIterator : public UnaryBaseIterator<NameCastIterator, PlanIteratorState>
{
  friend class PrinterVisitor;
private:
  NamespaceContext_t theNCtx;

public:
  NameCastIterator(short sctx, const QueryLoc& loc, PlanIter_t& aChild, NamespaceContext_t aNCtx);

  virtual ~NameCastIterator();

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
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
        short sctx,
        const QueryLoc& loc, 
        PlanIter_t& aComment,
        bool isRoot);

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
  
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
        short sctx,
        const QueryLoc& loc, 
        PlanIter_t& aTarget,
        PlanIter_t& aContent,
        bool isRoot);

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
  
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
  TextIterator( short sctx, const QueryLoc& loc, PlanIter_t& aChild, bool isRoot);

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
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
  std::string     * theAttrValueString;
  xqpStringStore  * theElemContentString;
  store::Item_t     theContextItem;
  store::Iterator_t theDocChildren;

  ~EnclosedIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};


class EnclosedIterator : public UnaryBaseIterator<EnclosedIterator,
                                                  EnclosedIteratorState>
{
private:
  bool theAttrContent;
  
public:
  EnclosedIterator(
        short sctx,
        const QueryLoc& loc,
        PlanIter_t& childIter);

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
  
  virtual void accept(PlanIterVisitor&) const;

  bool getAttrContent() const;
  void setAttrContent();
};

} /* namespace zorba */
#endif  /* ZORBA_CONSTRUCTORS_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
