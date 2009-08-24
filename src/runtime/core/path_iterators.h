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
#ifndef ZORBA_PATH_ITERATORS_H
#define ZORBA_PATH_ITERATORS_H

#include <stack>
#include <zorba/store_consts.h>

#include "zorbautils/fatal.h"
#include "common/shared_types.h"
#include "context/static_context.h"
#include "compiler/expression/expr_consts.h"
#include "types/typeimpl.h"
#include "types/typeops.h"
#include "types/typemanager.h"

#include "runtime/base/unarybase.h"

#include "store/api/iterator.h"

namespace zorba 
{


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

public:
  AxisIteratorHelper() 
    :
    theTestKind(match_anykind_test),
    theDocTestKind(match_no_test),
    theNodeKind(store::StoreConsts::anyNode),
    theQName(NULL),
    theWildKind(match_no_wild),
    theType(NULL),
    theNilledAllowed(false)
  {
  }

  virtual ~AxisIteratorHelper() {}

  void setTestKind(match_test_t k)                 { theTestKind = k; }
  void setDocTestKind(match_test_t k)              { theDocTestKind = k; }
  void setNodeKind(store::StoreConsts::NodeKind k) { theNodeKind = k; }
  void setQName(const store::Item_t& qn)           { theQName = qn; }
  void setWildKind(match_wild_t k)                 { theWildKind = k; }
  void setType(const xqtref_t& t)                  { theType = t; }
  void setNilledAllowed(bool v)                    { theNilledAllowed = v; }

  const match_test_t& getTestKind() const { return theTestKind; }

  const match_test_t& getDocTestKind() const { return theDocTestKind; }

  const store::Item_t& getQName() const { return theQName; }

  const xqtref_t& getType() const { return theType; }

  bool nilledAllowed() const { return theNilledAllowed; }

  bool nameOrKindTest(const store::Item* node, PlanState& planState) const;
};


/*******************************************************************************

********************************************************************************/
class AxisState : public PlanIteratorState
{
public:
  store::Item_t     theContextNode;   

  void init(PlanState& planState) { PlanIteratorState::init( planState ); }
  void reset(PlanState& planState) { PlanIteratorState::reset( planState ); }
};


template <class AxisIter, class State>
class AxisIterator : public UnaryBaseIterator<AxisIter, State>,
                     public AxisIteratorHelper
{
public:
  SERIALIZABLE_TEMPLATE_ABSTRACT_CLASS(AxisIterator)
  AxisIterator(::zorba::serialization::Archiver &ar)
    :
    UnaryBaseIterator<AxisIter, State>(ar)
  {
  }
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (UnaryBaseIterator<AxisIter, State>*)this);
    SERIALIZE_ENUM(match_test_t, theTestKind);
    SERIALIZE_ENUM(match_test_t, theDocTestKind);
    SERIALIZE_ENUM(store::StoreConsts::NodeKind, theNodeKind);
    ar & theQName;
    SERIALIZE_ENUM(match_wild_t, theWildKind);
    ar & theType;
    ar & theNilledAllowed;
  }

public:
  AxisIterator(short sctx, const QueryLoc& loc, PlanIter_t input)
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


class SelfAxisIterator : public AxisIterator<SelfAxisIterator, SelfAxisState>
{
public:
  SERIALIZABLE_CLASS(SelfAxisIterator)
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(SelfAxisIterator, AxisIterator<SelfAxisIterator, SelfAxisState>)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (AxisIterator<SelfAxisIterator, SelfAxisState>*)this);
  }

public:
  SelfAxisIterator(short sctx, const QueryLoc& loc, PlanIter_t input)
    :
    AxisIterator<SelfAxisIterator, SelfAxisState>(sctx, loc, input)
  {
  }

  ~SelfAxisIterator() {}

  bool nextImpl(store::Item_t& result, PlanState& planState) const;

  virtual void accept(PlanIterVisitor&) const;
};


/*******************************************************************************

********************************************************************************/
class AttributeAxisState : public AxisState
{
public:
  rchandle<store::AttributesIterator> theAttributes;

  AttributeAxisState();
  ~AttributeAxisState();

  void init(PlanState&);
  void reset(PlanState&);
};


class AttributeAxisIterator : public AxisIterator<AttributeAxisIterator,
                                                  AttributeAxisState>
{
public:
  SERIALIZABLE_CLASS(AttributeAxisIterator)
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(AttributeAxisIterator, AxisIterator<AttributeAxisIterator, AttributeAxisState>)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (AxisIterator<AttributeAxisIterator, AttributeAxisState>*)this);
  }

public:
  AttributeAxisIterator(short sctx, const QueryLoc& loc, PlanIter_t input)
    :
    AxisIterator<AttributeAxisIterator, AttributeAxisState>(sctx, loc, input)
  {
  }

  ~AttributeAxisIterator() {}

  bool nextImpl(store::Item_t& result, PlanState& planState) const;

  uint32_t getStateSize() const { return sizeof(AttributeAxisState); }

  virtual void accept(PlanIterVisitor&) const;
};


/*******************************************************************************

********************************************************************************/
class ParentAxisState : public AxisState
{
};


class ParentAxisIterator : public AxisIterator<ParentAxisIterator, ParentAxisState>
{
public:
  SERIALIZABLE_CLASS(ParentAxisIterator)
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ParentAxisIterator, AxisIterator<ParentAxisIterator, ParentAxisState>)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (AxisIterator<ParentAxisIterator, ParentAxisState>*)this);
  }

public:
  ParentAxisIterator(short sctx, const QueryLoc& loc, PlanIter_t input)
    :
    AxisIterator<ParentAxisIterator, ParentAxisState>(sctx, loc, input)
  {
  }

  ~ParentAxisIterator() {}

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
 
  virtual void accept(PlanIterVisitor&) const;
};


/*******************************************************************************

********************************************************************************/
class AncestorAxisState : public AxisState
{
public:
  std::vector<store::Item_t>  theAncestors;
  long                        theCurrentAncPos;
};


class AncestorAxisIter : public AxisIterator<AncestorAxisIter, AncestorAxisState>
{
public:
  SERIALIZABLE_CLASS(AncestorAxisIter)
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(AncestorAxisIter,
                                   AxisIterator<AncestorAxisIter, AncestorAxisState>)
  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar, (AxisIterator<AncestorAxisIter, AncestorAxisState>*)this);
  }

public:
  AncestorAxisIter(short sctx, const QueryLoc& loc, PlanIter_t input)
    :
    AxisIterator<AncestorAxisIter, AncestorAxisState>(sctx, loc, input)
  {
  }

  ~AncestorAxisIter() {}

  bool nextImpl(store::Item_t& result, PlanState& planState) const;

  void accept(PlanIterVisitor&) const;
};


/*******************************************************************************

********************************************************************************/
class AncestorReverseAxisState : public AxisState
{
public:
  store::Item_t theCurrentAnc;
};


class AncestorReverseAxisIter : public AxisIterator<AncestorReverseAxisIter,
                                                    AncestorReverseAxisState>
{
public:
  SERIALIZABLE_CLASS(AncestorReverseAxisIter)
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(AncestorReverseAxisIter,
                                   AxisIterator<AncestorReverseAxisIter,
                                                AncestorReverseAxisState>)
  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar, (AxisIterator<AncestorReverseAxisIter,
                             AncestorReverseAxisState>*)this);
  }

public:
  AncestorReverseAxisIter(short sctx, const QueryLoc& loc, PlanIter_t input)
    :
    AxisIterator<AncestorReverseAxisIter, AncestorReverseAxisState>(sctx, loc, input)
  {
  }

  ~AncestorReverseAxisIter() {}

  bool nextImpl(store::Item_t& result, PlanState& planState) const;

  void accept(PlanIterVisitor&) const;
};


/*******************************************************************************

********************************************************************************/
class AncestorSelfAxisIter : public AxisIterator<AncestorSelfAxisIter,
                                                 AncestorAxisState>
{
public:
  SERIALIZABLE_CLASS(AncestorSelfAxisIter)
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(AncestorSelfAxisIter,
                                   AxisIterator<AncestorSelfAxisIter,
                                   AncestorAxisState>)
  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar, (AxisIterator<AncestorSelfAxisIter,
                                          AncestorAxisState>*)this);
  }

public:
  AncestorSelfAxisIter(short sctx, const QueryLoc& loc, PlanIter_t input)
    :
    AxisIterator<AncestorSelfAxisIter, AncestorAxisState>(sctx, loc, input)
  {
  }

  ~AncestorSelfAxisIter() {}

  bool nextImpl(store::Item_t& result, PlanState& planState) const;

  void accept(PlanIterVisitor&) const;
};


/*******************************************************************************

********************************************************************************/
class AncestorSelfReverseAxisIter : public AxisIterator<AncestorSelfReverseAxisIter,
                                                        AncestorReverseAxisState>
{
public:
  SERIALIZABLE_CLASS(AncestorSelfReverseAxisIter)
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(AncestorSelfReverseAxisIter,
                                   AxisIterator<AncestorSelfReverseAxisIter,
                                                AncestorReverseAxisState>)
  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar, (AxisIterator<AncestorSelfReverseAxisIter,
                                          AncestorReverseAxisState>*)this);
  }

public:
  AncestorSelfReverseAxisIter(short sctx, const QueryLoc& loc, PlanIter_t input)
    :
    AxisIterator<AncestorSelfReverseAxisIter, AncestorReverseAxisState>(sctx, loc, input)
  {
  }

  ~AncestorSelfReverseAxisIter() {}

  bool nextImpl(store::Item_t& result, PlanState& planState) const;

  void accept(PlanIterVisitor&) const;
};


/*******************************************************************************

********************************************************************************/
class RSiblingAxisState : public AxisState
{
public:
  rchandle<store::ChildrenIterator> theChildren;

public:
  RSiblingAxisState() {}

  ~RSiblingAxisState() {}

  void init(PlanState&);

  void reset(PlanState&);
};


class RSiblingAxisIter : public AxisIterator<RSiblingAxisIter, RSiblingAxisState>
{
public:
  SERIALIZABLE_CLASS(RSiblingAxisIter)
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(RSiblingAxisIter, 
                                   AxisIterator<RSiblingAxisIter, RSiblingAxisState>)
  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar, (AxisIterator<RSiblingAxisIter, RSiblingAxisState>*)this);
  }

public:
  RSiblingAxisIter(short sctx, const QueryLoc& loc, PlanIter_t input)
    :
    AxisIterator<RSiblingAxisIter, RSiblingAxisState>(sctx, loc, input)
  {
  }

  ~RSiblingAxisIter() {}

  bool nextImpl(store::Item_t& result, PlanState& planState) const;

  virtual void accept(PlanIterVisitor&) const;
};


/*******************************************************************************

********************************************************************************/
class LSiblingAxisState : public AxisState
{
public:
  rchandle<store::ChildrenIterator> theChildren;

public:
  LSiblingAxisState() {}

  ~LSiblingAxisState() {}

  void init(PlanState&);

  void reset(PlanState&);
};


class LSiblingAxisIter : public AxisIterator<LSiblingAxisIter, LSiblingAxisState>
{
public:
  SERIALIZABLE_CLASS(LSiblingAxisIter)
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(LSiblingAxisIter,
                                   AxisIterator<LSiblingAxisIter, LSiblingAxisState>)
  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar, (AxisIterator<LSiblingAxisIter, LSiblingAxisState>*)this);
  }

public:
  LSiblingAxisIter(short sctx, const QueryLoc& loc, PlanIter_t input)
    :
    AxisIterator<LSiblingAxisIter, LSiblingAxisState>(sctx, loc, input)
  {
  }

  ~LSiblingAxisIter() {}

  bool nextImpl(store::Item_t& result, PlanState& planState) const;

  void accept(PlanIterVisitor&) const;
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


class LSiblingReverseAxisIter : public AxisIterator<LSiblingReverseAxisIter,
                                                    LSiblingReverseAxisState>
{
public:
  SERIALIZABLE_CLASS(LSiblingReverseAxisIter)
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(LSiblingReverseAxisIter,
                                   AxisIterator<LSiblingReverseAxisIter,
                                                LSiblingReverseAxisState>)
  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar, (AxisIterator<LSiblingReverseAxisIter,
                                          LSiblingReverseAxisState>*)this);
  }

public:
  LSiblingReverseAxisIter(short sctx, const QueryLoc& loc, PlanIter_t input)
    :
    AxisIterator<LSiblingReverseAxisIter, LSiblingReverseAxisState>(sctx, loc, input)
  {
  }

  ~LSiblingReverseAxisIter() {}

  bool nextImpl(store::Item_t& result, PlanState& planState) const;

  void accept(PlanIterVisitor&) const;
};


/*******************************************************************************

********************************************************************************/
class ChildAxisState : public AxisState
{
public:
  rchandle<store::ChildrenIterator>  theChildren;

  ChildAxisState();
  ~ChildAxisState();

  void init(PlanState&);
  void reset(PlanState&);
};


class ChildAxisIterator : public AxisIterator<ChildAxisIterator, ChildAxisState>
{
public:
  ChildAxisIterator(short sctx, const QueryLoc& loc, PlanIter_t input)
    :
    AxisIterator<ChildAxisIterator, ChildAxisState>(sctx, loc, input)
  {
  }

  ~ChildAxisIterator() {}

  bool nextImpl(store::Item_t& result, PlanState& planState) const;

  virtual void accept(PlanIterVisitor&) const;
public:
  SERIALIZABLE_CLASS(ChildAxisIterator)
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ChildAxisIterator, AxisIterator<ChildAxisIterator, ChildAxisState>)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (AxisIterator<ChildAxisIterator, ChildAxisState>*)this);
  }
};


/*******************************************************************************

********************************************************************************/
class DescendantAxisState : public AxisState
{
public:
  ulong theTop;
  std::vector<std::pair<const store::Item*, store::ChildrenIterator*> > theCurrentPath;

public:
  DescendantAxisState();

  ~DescendantAxisState();

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


class DescendantAxisIterator : public AxisIterator<DescendantAxisIterator,
                                                   DescendantAxisState>
{
public:
  DescendantAxisIterator(short sctx, const QueryLoc& loc, PlanIter_t input)
    :
    AxisIterator<DescendantAxisIterator, DescendantAxisState>(sctx, loc, input)
  {
  }

  ~DescendantAxisIterator() {}

  bool nextImpl(store::Item_t& result, PlanState& planState) const;

  virtual void accept(PlanIterVisitor&) const;
public:
  SERIALIZABLE_CLASS(DescendantAxisIterator)
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(DescendantAxisIterator, AxisIterator<DescendantAxisIterator,DescendantAxisState>)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (AxisIterator<DescendantAxisIterator,DescendantAxisState>*)this);
  }
};


/*******************************************************************************

********************************************************************************/
class DescendantSelfAxisIterator : public AxisIterator<DescendantSelfAxisIterator,
                                                       DescendantAxisState>
{
public:
  DescendantSelfAxisIterator(short sctx, const QueryLoc& loc, PlanIter_t input)
    :
    AxisIterator<DescendantSelfAxisIterator, DescendantAxisState>(sctx, loc, input)
  {
  }

  ~DescendantSelfAxisIterator() {}

  bool nextImpl(store::Item_t& result, PlanState& planState) const;

  virtual void accept(PlanIterVisitor&) const;
public:
  SERIALIZABLE_CLASS(DescendantSelfAxisIterator)
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(DescendantSelfAxisIterator, AxisIterator<DescendantSelfAxisIterator,DescendantAxisState>)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (AxisIterator<DescendantSelfAxisIterator,DescendantAxisState>*)this);
  }
};


/*******************************************************************************

********************************************************************************/
class PrecedingAxisState : public AxisState
{
public:
  std::stack<store::Item_t>                                theAncestorPath;
  std::stack<std::pair<store::Item_t, store::Iterator_t> > theCurrentPath;

public:
  PrecedingAxisState() {}

  ~PrecedingAxisState();

  void init(PlanState&);

  void reset(PlanState&);
};


class PrecedingAxisIterator : public AxisIterator<PrecedingAxisIterator,
                                                  PrecedingAxisState>
{
public:
  SERIALIZABLE_CLASS(PrecedingAxisIterator)
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(PrecedingAxisIterator, AxisIterator<PrecedingAxisIterator, PrecedingAxisState>)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (AxisIterator<PrecedingAxisIterator, PrecedingAxisState>*)this);
  }

public:
  PrecedingAxisIterator(short sctx, const QueryLoc& loc, PlanIter_t input)
    :
    AxisIterator<PrecedingAxisIterator, PrecedingAxisState>(sctx, loc, input)
  {
  }

  ~PrecedingAxisIterator() {}

  bool nextImpl(store::Item_t& result, PlanState& planState) const;

  virtual void accept(PlanIterVisitor&) const;
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


class PrecedingReverseAxisIter : public AxisIterator<PrecedingReverseAxisIter,
                                                     PrecedingReverseAxisState>
{
public:
  SERIALIZABLE_CLASS(PrecedingReverseAxisIter)
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(PrecedingReverseAxisIter,
                                   AxisIterator<PrecedingReverseAxisIter,
                                                PrecedingReverseAxisState>)
  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar, (AxisIterator<PrecedingReverseAxisIter,
                                          PrecedingReverseAxisState>*)this);
  }

public:
  PrecedingReverseAxisIter(short sctx, const QueryLoc& loc, PlanIter_t input)
    :
    AxisIterator<PrecedingReverseAxisIter, PrecedingReverseAxisState>(sctx, loc, input)
  {
  }

  ~PrecedingReverseAxisIter() {}

  bool nextImpl(store::Item_t& result, PlanState& planState) const;

  void accept(PlanIterVisitor&) const;
};


/*******************************************************************************

********************************************************************************/
class FollowingAxisState : public AxisState
{
public:
  std::stack<store::Item_t>                                theAncestorPath;
  std::stack<std::pair<store::Item_t, store::Iterator_t> > theCurrentPath;

  FollowingAxisState() {}

  ~FollowingAxisState();

  void init(PlanState&);

  void reset(PlanState&);
};


class FollowingAxisIterator : public AxisIterator<FollowingAxisIterator,
                                                  FollowingAxisState>
{
public:
  SERIALIZABLE_CLASS(FollowingAxisIterator)
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FollowingAxisIterator, AxisIterator<FollowingAxisIterator,FollowingAxisState>)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (AxisIterator<FollowingAxisIterator,FollowingAxisState>*)this);
  }

public:
  FollowingAxisIterator(short sctx, const QueryLoc& loc, PlanIter_t input)
    :
    AxisIterator<FollowingAxisIterator, FollowingAxisState>(sctx, loc, input)
  {
  }

  ~FollowingAxisIterator() {}

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
  
  void accept(PlanIterVisitor&) const;
};


} /* namespace zorba */

#endif  /* ZORBA_PATH_ITERATORS_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */

