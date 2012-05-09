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
#pragma once
#ifndef ZORBA_RUNTIME_CONSTRUCTORS
#define ZORBA_RUNTIME_CONSTRUCTORS

#include <vector>

#include "common/shared_types.h"

#include "context/namespace_context.h"

#include "runtime/base/unarybase.h"
#include "runtime/base/binarybase.h"
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
  bool      theCopyInputNodes;

public:
  SERIALIZABLE_CLASS(DocumentIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  DocumentIterator,
  UnaryBaseIterator<DocumentIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar);

public:
  DocumentIterator(
      static_context* sctx,
      const QueryLoc& loc,
      PlanIter_t& aChild,
      bool copyInputNodes);

  bool copyInputNodes() const { return theCopyInputNodes; }

  bool isConstructor() const { return true; }

  void accept(PlanIterVisitor& v) const;

  void openImpl(PlanState& planState, uint32_t& offset);

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
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
  zstring baseUri;

  void init(PlanState&);
  void reset(PlanState&);
};


class ElementIterator : public NoaryBaseIterator<ElementIterator, ElementIteratorState>
{
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
  bool                theCopyInputNodes;

public:
  SERIALIZABLE_CLASS(ElementIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  ElementIterator,
  NoaryBaseIterator<ElementIterator, ElementIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar);

public:
  ElementIterator (
      static_context*     sctx,
      const QueryLoc&     loc,
      PlanIter_t&         aQNameIter,
      PlanIter_t&         aAttrs,
      PlanIter_t&         aChildren,
      const namespace_context* localBindings,
      bool                isRoot,
      bool                copyInputNodes);

  bool copyInputNodes() const { return theCopyInputNodes; }

  bool isConstructor() const { return true; }

  uint32_t getStateSizeOfSubtree() const;
  
  void accept(PlanIterVisitor&) const;

  void openImpl(PlanState& planState, uint32_t& offset);

  bool nextImpl(store::Item_t& result, PlanState& planState) const;

  void resetImpl(PlanState& planState) const;

  void closeImpl(PlanState& planState);
};
  

/*******************************************************************************
  AttributeIterator constructs an attribute node
  
  theQName  : If the attribute qname is known at compile time, it is given as
              input to the attribute iterator. In this case, theChild0 is not
              used.
  theChild0 : Iter that produces the qname of the node (if qname is not constant)
  theChild1 : Iter that produces the value of the node.
********************************************************************************/
class AttributeIterator : public BinaryBaseIterator<AttributeIterator, PlanIteratorState>
{
private:
  store::Item_t theQName;
  bool          theIsId;
  bool          theIsRoot;
  bool          theRaiseXQDY0074;
  bool          theRaiseXQDY0044;

public:
  SERIALIZABLE_CLASS(AttributeIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  AttributeIterator,
  BinaryBaseIterator<AttributeIterator,PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar);

public:
  AttributeIterator(
        static_context* sctx,
        const QueryLoc& loc,
        const store::Item_t& qname,
        PlanIter_t& qnameIter,
        PlanIter_t& valueIter,
        bool isRoot);

  store::Item* getQName() const { return theQName.getp(); }

  bool isConstructor() const { return true; }

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
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
  SERIALIZABLE_CLASS(TextIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  TextIterator,
  UnaryBaseIterator<TextIterator,PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (UnaryBaseIterator<TextIterator, PlanIteratorState>*)this);

    ar & theIsRoot;
  }

public:
  TextIterator(
        static_context* sctx,
        const QueryLoc& loc,
        PlanIter_t& aChild,
        bool isRoot);

  bool isConstructor() const { return true; }

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
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
  SERIALIZABLE_CLASS(CommentIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  CommentIterator,
  UnaryBaseIterator<CommentIterator,PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar, 
    (UnaryBaseIterator<CommentIterator, PlanIteratorState>*)this);

    ar & theIsRoot;
  }

public:
  CommentIterator(
        static_context* sctx,
        const QueryLoc& loc, 
        PlanIter_t& aComment,
        bool isRoot);

  bool isConstructor() const { return true; }

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
};


/*******************************************************************************

  PiIterator constructs a PI element.

********************************************************************************/
class PiIterator : public BinaryBaseIterator<PiIterator, PlanIteratorState>
{
protected:
  bool       theIsRoot;

public:
  SERIALIZABLE_CLASS(PiIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  PiIterator,
  BinaryBaseIterator<PiIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (BinaryBaseIterator<PiIterator, PlanIteratorState>*)this);

    ar & theIsRoot;
  }

public:
  PiIterator(
        static_context* sctx,
        const QueryLoc& loc, 
        PlanIter_t& aTarget,
        PlanIter_t& aContent,
        bool isRoot);

  bool isConstructor() const { return true; }

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
};


/*******************************************************************************
   Used to concatenate adjacent atomic values in the input sequence into a 
   text node. Concatenation inserts a single space between each pair of atomic
   values.
********************************************************************************/
class EnclosedIteratorState : public PlanIteratorState
{
public:
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
  bool theTextContent;
  bool theIsInUpdateExpr;

public:
  SERIALIZABLE_CLASS(EnclosedIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  EnclosedIterator,
  UnaryBaseIterator<EnclosedIterator, EnclosedIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar);

public:
  EnclosedIterator(
        static_context* sctx,
        const QueryLoc& loc,
        PlanIter_t& childIter);

  bool getAttrContent() const;

  void setAttrContent();

  bool getTextContent() const;

  void setTextContent();

  void setInUpdateExpr();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
};


/*******************************************************************************
  NameCast Iterator casts QNames of computed elements or attributes that are not
  known till execution time.
********************************************************************************/
class NameCastIterator : public UnaryBaseIterator<NameCastIterator,
                                                  PlanIteratorState>
{
  friend class PrinterVisitor;
private:
  NamespaceContext_t theNCtx;
  bool               theIsAttrName;

public:
  SERIALIZABLE_CLASS(NameCastIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  NameCastIterator,
  UnaryBaseIterator<NameCastIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (UnaryBaseIterator<NameCastIterator, PlanIteratorState>*)this);

    ar & theNCtx;
	  ar & theIsAttrName;
  }

public:
  NameCastIterator(
        static_context* sctx,
        const QueryLoc& loc,
        PlanIter_t& aChild,
        const namespace_context* aNCtx,
        bool isAttrName);

  virtual ~NameCastIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
};


}

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
