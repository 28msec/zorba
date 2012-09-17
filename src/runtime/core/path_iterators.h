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
#ifndef ZORBA_RUNTIME_PATH_ITERATORS
#define ZORBA_RUNTIME_PATH_ITERATORS

#include <stack>
#include <zorba/store_consts.h>

#include "zorbautils/fatal.h"

#include "common/shared_types.h"

#include "context/static_context.h"

#include "compiler/expression/expr_consts.h"

#include "runtime/base/unarybase.h"

#include "store/api/iterator.h"

#include "types/typeimpl.h"


namespace zorba 
{

namespace store
{
  class ChildrenIterator;
  class ChildrenReverseIterator;
  class AttributesIterator;
}


/*******************************************************************************
  A non-template class used to store some data that is common to all axis
  iterators.
********************************************************************************/
class AxisIteratorHelper
{
protected:
  match_test_t                 theTestKind;
  match_test_t                 theDocTestKind;
  store::StoreConsts::NodeKind theNodeKind;
  store::Item_t                theQName;
  match_wild_t                 theWildKind;
  xqtref_t                     theType;
  bool                         theNilledAllowed;

  xs_long                      theTargetPos;
 
public:
  AxisIteratorHelper() 
    :
    theTestKind(match_anykind_test),
    theDocTestKind(match_no_test),
    theNodeKind(store::StoreConsts::anyNode),
    theQName(NULL),
    theWildKind(match_no_wild),
    theType(NULL),
    theNilledAllowed(false),
    theTargetPos(-2)
  {
  }

  virtual ~AxisIteratorHelper() {}

  void serialize(::zorba::serialization::Archiver& ar);

  void setTestKind(match_test_t k) { theTestKind = k; }

  void setDocTestKind(match_test_t k) { theDocTestKind = k; }

  void setNodeKind(store::StoreConsts::NodeKind k) { theNodeKind = k; }

  void setQName(const store::Item_t& qn) { theQName = qn; }

  void setWildKind(match_wild_t k) { theWildKind = k; }

  void setType(const xqtref_t& t) { theType = t; }

  void setNilledAllowed(bool v) { theNilledAllowed = v; }

  bool setTargetPos(xs_long pos);

  xs_long getTargetPos() const { return theTargetPos; }

  const match_test_t& getTestKind() const { return theTestKind; }

  const match_test_t& getDocTestKind() const { return theDocTestKind; }

  const store::Item_t& getQName() const { return theQName; }

  const xqtref_t& getType() const { return theType; }

  bool nilledAllowed() const { return theNilledAllowed; }

  bool nameOrKindTest(
      static_context* sctx,
      const store::Item* node,
      const QueryLoc& loc) const;
};


/*******************************************************************************

********************************************************************************/
class AxisState : public PlanIteratorState
{
public:
  store::Item_t  theContextNode;   

  xs_long        theCurrentPos;

public:
  void init(PlanState& planState) 
  {
    PlanIteratorState::init(planState);
  }

  void reset(PlanState& planState) 
  {
    PlanIteratorState::reset(planState);
  }
};


template <class AxisIter, class State>
class AxisIterator : public UnaryBaseIterator<AxisIter, State>,
                     public AxisIteratorHelper
{
public:
  SERIALIZABLE_TEMPLATE_ABSTRACT_CLASS(AxisIterator)

  AxisIterator(::zorba::serialization::Archiver& ar)
    :
    UnaryBaseIterator<AxisIter, State>(ar)
  {
  }

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar, (UnaryBaseIterator<AxisIter, AxisState>*)this);

    SERIALIZE_ENUM(match_test_t, theTestKind);
    SERIALIZE_ENUM(match_test_t, theDocTestKind);
    SERIALIZE_ENUM(store::StoreConsts::NodeKind, theNodeKind);
    ar & theQName;
    SERIALIZE_ENUM(match_wild_t, theWildKind);
    ar & theType;
    ar & theNilledAllowed;
    ar & theTargetPos;
  }

public:
  AxisIterator(static_context* sctx, const QueryLoc& loc, PlanIter_t input)
    :
    UnaryBaseIterator<AxisIter, State>(sctx, loc, input)
  {
  }

  virtual ~AxisIterator() {}
};


/*******************************************************************************

********************************************************************************/
class SelfAxisState : public AxisState
{
};


class SelfAxisIterator : public UnaryBaseIterator<SelfAxisIterator, SelfAxisState>,
                         public AxisIteratorHelper
{
public:
  SERIALIZABLE_CLASS(SelfAxisIterator);
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(SelfAxisIterator,
  UnaryBaseIterator<SelfAxisIterator, SelfAxisState>);
  void serialize(::zorba::serialization::Archiver& ar);

public:
  SelfAxisIterator(static_context* sctx, const QueryLoc& loc, PlanIter_t input)
    :
    UnaryBaseIterator<SelfAxisIterator, SelfAxisState>(sctx, loc, input)
  {
  }

  ~SelfAxisIterator() {}

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
};


/*******************************************************************************

********************************************************************************/
class AttributeAxisState : public AxisState
{
public:
  rchandle<store::AttributesIterator> theAttributes;

  AttributeAxisState() {}

  ~AttributeAxisState() {}

  void init(PlanState&);

  void reset(PlanState&);
};


class AttributeAxisIterator : public UnaryBaseIterator<AttributeAxisIterator,
                                                       AttributeAxisState>,
                              public AxisIteratorHelper
{
public:
  SERIALIZABLE_CLASS(AttributeAxisIterator);
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(AttributeAxisIterator,
  UnaryBaseIterator<AttributeAxisIterator, AttributeAxisState>);
  void serialize(::zorba::serialization::Archiver& ar);

public:
  AttributeAxisIterator(static_context* sctx, const QueryLoc& loc, PlanIter_t input)
    :
    UnaryBaseIterator<AttributeAxisIterator, AttributeAxisState>(sctx, loc, input)
  {
  }

  ~AttributeAxisIterator() {}

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
};


/*******************************************************************************

********************************************************************************/
class ParentAxisState : public AxisState
{
};


class ParentAxisIterator : public UnaryBaseIterator<ParentAxisIterator, ParentAxisState>,
                           public AxisIteratorHelper
{
public:
  SERIALIZABLE_CLASS(ParentAxisIterator);
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ParentAxisIterator,
  UnaryBaseIterator<ParentAxisIterator, ParentAxisState>);
  void serialize(::zorba::serialization::Archiver& ar);

public:
  ParentAxisIterator(static_context* sctx, const QueryLoc& loc, PlanIter_t input)
    :
    UnaryBaseIterator<ParentAxisIterator, ParentAxisState>(sctx, loc, input)
  {
  }

  ~ParentAxisIterator() {}

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
};


/*******************************************************************************

********************************************************************************/
class AncestorAxisState : public AxisState
{
public:
  std::vector<store::Item_t>  theAncestors;
  long                        theCurrentAncPos;
};


class AncestorAxisIterator : public UnaryBaseIterator<AncestorAxisIterator,
                                                      AncestorAxisState>,
                             public AxisIteratorHelper
{
public:
  SERIALIZABLE_CLASS(AncestorAxisIterator);
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(AncestorAxisIterator,
  UnaryBaseIterator<AncestorAxisIterator, AncestorAxisState>);
  void serialize(::zorba::serialization::Archiver& ar);

public:
  AncestorAxisIterator(static_context* sctx, const QueryLoc& loc, PlanIter_t input)
    :
    UnaryBaseIterator<AncestorAxisIterator, AncestorAxisState>(sctx, loc, input)
  {
  }

  ~AncestorAxisIterator() {}

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
};


/*******************************************************************************

********************************************************************************/
class AncestorReverseAxisState : public AxisState
{
public:
  store::Item_t theCurrentAnc;
};


class AncestorReverseAxisIterator : 
public UnaryBaseIterator<AncestorReverseAxisIterator,
                         AncestorReverseAxisState>,
public AxisIteratorHelper
{
public:
  SERIALIZABLE_CLASS(AncestorReverseAxisIterator);
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  AncestorReverseAxisIterator,
  UnaryBaseIterator<AncestorReverseAxisIterator, AncestorReverseAxisState>);
  void serialize(::zorba::serialization::Archiver& ar);

public:
  AncestorReverseAxisIterator(static_context* sctx, const QueryLoc& loc, PlanIter_t input)
    :
    UnaryBaseIterator<AncestorReverseAxisIterator,
                      AncestorReverseAxisState>(sctx, loc, input)
  {
  }

  ~AncestorReverseAxisIterator() {}

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
};


/*******************************************************************************

********************************************************************************/
class AncestorSelfAxisIterator : public UnaryBaseIterator<AncestorSelfAxisIterator,
                                                          AncestorAxisState>,
                                 public AxisIteratorHelper
{
public:
  SERIALIZABLE_CLASS(AncestorSelfAxisIterator);
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  AncestorSelfAxisIterator,
  UnaryBaseIterator<AncestorSelfAxisIterator, AncestorAxisState>);
  void serialize(::zorba::serialization::Archiver& ar);

public:
  AncestorSelfAxisIterator(static_context* sctx, const QueryLoc& loc, PlanIter_t input)
    :
    UnaryBaseIterator<AncestorSelfAxisIterator, AncestorAxisState>(sctx, loc, input)
  {
  }

  ~AncestorSelfAxisIterator() {}

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
};


/*******************************************************************************

********************************************************************************/
class AncestorSelfReverseAxisIterator : 
public UnaryBaseIterator<AncestorSelfReverseAxisIterator,
                         AncestorReverseAxisState>,
public AxisIteratorHelper
{
public:
  SERIALIZABLE_CLASS(AncestorSelfReverseAxisIterator);
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  AncestorSelfReverseAxisIterator,
  UnaryBaseIterator<AncestorSelfReverseAxisIterator, AncestorReverseAxisState>);
  void serialize(::zorba::serialization::Archiver& ar);

public:
  AncestorSelfReverseAxisIterator(
        static_context* sctx,
        const QueryLoc& loc,
        PlanIter_t input)
    :
    UnaryBaseIterator<AncestorSelfReverseAxisIterator,
                      AncestorReverseAxisState>(sctx, loc, input)
  {
  }

  ~AncestorSelfReverseAxisIterator() {}

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
};


/*******************************************************************************

********************************************************************************/
class SiblingAxisState : public AxisState
{
public:
  rchandle<store::ChildrenIterator> theChildren;

public:
  SiblingAxisState() {}

  ~SiblingAxisState() {}

  void init(PlanState&);

  void reset(PlanState&);
};


class RSiblingAxisIterator : public UnaryBaseIterator<RSiblingAxisIterator,
                                                      SiblingAxisState>,
                             public AxisIteratorHelper
{
public:
  SERIALIZABLE_CLASS(RSiblingAxisIterator);
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  RSiblingAxisIterator, 
  UnaryBaseIterator<RSiblingAxisIterator, SiblingAxisState>);
  void serialize(::zorba::serialization::Archiver& ar);

public:
  RSiblingAxisIterator(
      static_context* sctx,
      const QueryLoc& loc,
      PlanIter_t input)
    :
    UnaryBaseIterator<RSiblingAxisIterator, SiblingAxisState>(sctx, loc, input)
  {
  }

  ~RSiblingAxisIterator() {}

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
};


/*******************************************************************************

********************************************************************************/
class LSiblingAxisIterator : public UnaryBaseIterator<LSiblingAxisIterator,
                                                      SiblingAxisState>,
                             public AxisIteratorHelper
{
public:
  SERIALIZABLE_CLASS(LSiblingAxisIterator);
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  LSiblingAxisIterator,
  UnaryBaseIterator<LSiblingAxisIterator, SiblingAxisState>);
  void serialize(::zorba::serialization::Archiver& ar);

public:
  LSiblingAxisIterator(
        static_context* sctx,
        const QueryLoc& loc,
        PlanIter_t input)
    :
    UnaryBaseIterator<LSiblingAxisIterator, SiblingAxisState>(sctx, loc, input)
  {
  }

  ~LSiblingAxisIterator() {}

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
};


/*******************************************************************************

********************************************************************************/
class LSiblingReverseAxisState : public AxisState
{
public:
  rchandle<store::ChildrenReverseIterator> theChildren;

public:
  LSiblingReverseAxisState() {}

  ~LSiblingReverseAxisState() {}

  void init(PlanState&);

  void reset(PlanState&);
};


class LSiblingReverseAxisIterator : 
public UnaryBaseIterator<LSiblingReverseAxisIterator,
                         LSiblingReverseAxisState>,
public AxisIteratorHelper
{
public:
  SERIALIZABLE_CLASS(LSiblingReverseAxisIterator);
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  LSiblingReverseAxisIterator,
  UnaryBaseIterator<LSiblingReverseAxisIterator, LSiblingReverseAxisState>);
  void serialize(::zorba::serialization::Archiver& ar);

public:
  LSiblingReverseAxisIterator(
        static_context* sctx, 
        const QueryLoc& loc,
        PlanIter_t input)
    :
    UnaryBaseIterator<LSiblingReverseAxisIterator,
                      LSiblingReverseAxisState>(sctx, loc, input)
  {
  }

  ~LSiblingReverseAxisIterator() {}

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
};


/*******************************************************************************

********************************************************************************/
class ChildAxisState : public AxisState
{
public:
  rchandle<store::ChildrenIterator>  theChildren;

  ChildAxisState() {}

  ~ChildAxisState() {}

  void init(PlanState&);

  void reset(PlanState&);
};


class ChildAxisIterator : public UnaryBaseIterator<ChildAxisIterator, ChildAxisState>,
                          public AxisIteratorHelper
{
public:
  SERIALIZABLE_CLASS(ChildAxisIterator);
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  ChildAxisIterator,
  UnaryBaseIterator<ChildAxisIterator, ChildAxisState>);
  void serialize(::zorba::serialization::Archiver& ar);

public:
  ChildAxisIterator(static_context* sctx, const QueryLoc& loc, PlanIter_t input)
    :
    UnaryBaseIterator<ChildAxisIterator, ChildAxisState>(sctx, loc, input)
  {
  }

  ~ChildAxisIterator() {}

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
};


/*******************************************************************************

********************************************************************************/
class DescendantAxisState : public AxisState
{
public:
  typedef std::pair<const store::Item*, store::ChildrenIterator*> PathPair;

public:
  ulong                 theTop;
  std::vector<PathPair> theCurrentPath;

public:
  DescendantAxisState() : theTop(0) {}

  ~DescendantAxisState();

  void init(PlanState&);

  void reset(PlanState&);

  bool empty() const
  {
    return theTop == 0;
  }

  void clear()
  {
    for (ulong i = 0; i < theTop; ++i)
    {
      theCurrentPath[i].second->close();
    }

    theTop = 0;
  }

  const store::Item* topNode() const
  {
    return theCurrentPath[theTop-1].first; 
  }

  store::ChildrenIterator* top() const
  {
    return theCurrentPath[theTop-1].second; 
  }

  void pop()
  {
    theCurrentPath[theTop-1].second->close();
    theTop--;
  }

  void push(const store::Item* node);
};


class DescendantAxisIterator : public UnaryBaseIterator<DescendantAxisIterator,
                                                        DescendantAxisState>,
                               public AxisIteratorHelper
{
public:
  SERIALIZABLE_CLASS(DescendantAxisIterator);
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  DescendantAxisIterator,
  UnaryBaseIterator<DescendantAxisIterator, DescendantAxisState>);
  void serialize(::zorba::serialization::Archiver& ar);

public:
  DescendantAxisIterator(
        static_context* sctx,
        const QueryLoc& loc,
        PlanIter_t input)
    :
    UnaryBaseIterator<DescendantAxisIterator, DescendantAxisState>(sctx, loc, input)
  {
  }

  ~DescendantAxisIterator() {}

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
};


/*******************************************************************************

********************************************************************************/
class DescendantSelfAxisIterator : 
public UnaryBaseIterator<DescendantSelfAxisIterator,
                         DescendantAxisState>,
public AxisIteratorHelper
{
public:
  SERIALIZABLE_CLASS(DescendantSelfAxisIterator)
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  DescendantSelfAxisIterator,
  UnaryBaseIterator<DescendantSelfAxisIterator, DescendantAxisState>)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  DescendantSelfAxisIterator(
      static_context* sctx, 
      const QueryLoc& loc,
      PlanIter_t input)
    :
    UnaryBaseIterator<DescendantSelfAxisIterator,
                      DescendantAxisState>(sctx, loc, input)
  {
  }

  ~DescendantSelfAxisIterator() {}

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
};


/*******************************************************************************

********************************************************************************/
class PrecedingAxisState : public DescendantAxisState
{
public:
  std::vector<store::Item_t>         theAncestorPath;
  rchandle<store::ChildrenIterator>  theAncestorChildren;

public:
  PrecedingAxisState() {}

  ~PrecedingAxisState() {}

  void clear()
  {
    DescendantAxisState::clear();
    theAncestorPath.clear();
  }

  void init(PlanState&);

  void reset(PlanState&);
};


class PrecedingAxisIterator : public AxisIterator<PrecedingAxisIterator,
                                                  PrecedingAxisState>
{
public:
  SERIALIZABLE_CLASS(PrecedingAxisIterator);
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  PrecedingAxisIterator,
  AxisIterator<PrecedingAxisIterator, PrecedingAxisState>);
  void serialize(::zorba::serialization::Archiver& ar);

public:
  PrecedingAxisIterator(static_context* sctx, const QueryLoc& loc, PlanIter_t input)
    :
    AxisIterator<PrecedingAxisIterator, PrecedingAxisState>(sctx, loc, input)
  {
  }

  ~PrecedingAxisIterator() {}

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
};


/*******************************************************************************
  Let N be the context node whose preceding nodes we are looking for. Let AP be
  the ancestor path of N. Let A be a node in AP and AC be the child of A along
  AP. Then, for each child C of A that is to the left of AC, we do a reverse
  traversal of the subtree rooted at C. This process is repeated for each node
  A in AP, starting from the parent of N and moving upwards in AP.

  theAncestor       : A pair containg a node A in AP and a reverse iterator
                      over the children of A.
  theAncestorChild  : The child AC of A in AP.

  theCurrentPath    : Used to do the reverse traversal of the subtree rooted
                      at a child C of A,
  theTop            : Used to make theCurrentPath behave like a stack.
********************************************************************************/
class PrecedingReverseAxisState : public AxisState
{
public:
  typedef std::pair<const store::Item*, store::ChildrenReverseIterator*> PathPair;

public:
  PathPair                  theAncestor;
  const store::Item*        theAncestorChild;

  ulong                     theTop;
  std::vector<PathPair>     theCurrentPath;

  PrecedingReverseAxisState();

  ~PrecedingReverseAxisState();

  void init(PlanState&);

  void reset(PlanState&);

  bool empty() const
  {
    return theTop == 0;
  }

  const store::Item* topNode() const
  {
    return theCurrentPath[theTop-1].first; 
  }

  store::ChildrenReverseIterator* top() const
  {
    return theCurrentPath[theTop-1].second; 
  }

  void pop()
  {
    theCurrentPath[theTop-1].second->close();
    theTop--;
  }

  void push(const store::Item* node);
};


class PrecedingReverseAxisIterator : public AxisIterator<PrecedingReverseAxisIterator,
                                                         PrecedingReverseAxisState>
{
public:
  SERIALIZABLE_CLASS(PrecedingReverseAxisIterator);
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  PrecedingReverseAxisIterator,
  AxisIterator<PrecedingReverseAxisIterator, PrecedingReverseAxisState>);
  void serialize(::zorba::serialization::Archiver& ar);

public:
  PrecedingReverseAxisIterator(
        static_context* sctx,
        const QueryLoc& loc,
        PlanIter_t input)
    :
    AxisIterator<PrecedingReverseAxisIterator,
                 PrecedingReverseAxisState>(sctx, loc, input)
  {
  }

  ~PrecedingReverseAxisIterator() {}

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
};


/*******************************************************************************

********************************************************************************/
class FollowingAxisState : public DescendantAxisState
{
public:
  std::vector<store::Item_t>        theAncestorPath;
  rchandle<store::ChildrenIterator> theAncestorChildren;

public:
  FollowingAxisState() : DescendantAxisState() {}

  ~FollowingAxisState() {}

  void clear()
  {
    DescendantAxisState::clear();
    theAncestorPath.clear();
  }

  void init(PlanState&);

  void reset(PlanState&);
};


class FollowingAxisIterator : public AxisIterator<FollowingAxisIterator,
                                                  FollowingAxisState>
{
public:
  SERIALIZABLE_CLASS(FollowingAxisIterator);
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  FollowingAxisIterator,
  AxisIterator<FollowingAxisIterator, FollowingAxisState>);
  void serialize(::zorba::serialization::Archiver& ar);

public:
  FollowingAxisIterator(
      static_context* sctx,
      const QueryLoc& loc,
      PlanIter_t input)
    :
    AxisIterator<FollowingAxisIterator, FollowingAxisState>(sctx, loc, input)
  {
  }

  ~FollowingAxisIterator() {}

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
};


} /* namespace zorba */

#endif  /* ZORBA_PATH_ITERATORS_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */

/* vim:set et sw=2 ts=2: */
