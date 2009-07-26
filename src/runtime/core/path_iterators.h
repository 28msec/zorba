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
class AxisIteratorHelper : virtual public ::zorba::serialization::SerializeBaseClass
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
  SERIALIZABLE_CLASS(AxisIteratorHelper)
  SERIALIZABLE_CLASS_CONSTRUCTOR(AxisIteratorHelper)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    SERIALIZE_ENUM(match_test_t, theTestKind);
    SERIALIZE_ENUM(match_test_t, theDocTestKind);
    SERIALIZE_ENUM(store::StoreConsts::NodeKind, theNodeKind);
    ar & theQName;
    SERIALIZE_ENUM(match_wild_t, theWildKind);
    ar & theType;
    ar & theNilledAllowed;
  }
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
protected:

public:
  AxisIterator(short sctx, const QueryLoc& loc, PlanIter_t input)
    :
    UnaryBaseIterator<AxisIter, State>(sctx, loc, input)
  {
  }

  virtual ~AxisIterator() {}
public:
  SERIALIZABLE_TEMPLATE_ABSTRACT_CLASS(AxisIterator)
  AxisIterator(::zorba::serialization::Archiver &ar) :
  UnaryBaseIterator<AxisIter, State>(ar), AxisIteratorHelper(ar) {}
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (UnaryBaseIterator<AxisIter, State>*)this);
    serialize_baseclass(ar, (AxisIteratorHelper*)this);
  }
};


/*******************************************************************************

********************************************************************************/
class SelfAxisState : public AxisState
{
};


class SelfAxisIterator : public AxisIterator<SelfAxisIterator, SelfAxisState>
{
protected:
public:
  SelfAxisIterator(short sctx, const QueryLoc& loc, PlanIter_t input)
    :
    AxisIterator<SelfAxisIterator, SelfAxisState>(sctx, loc, input)
  {
  }

  ~SelfAxisIterator() {}

  bool nextImpl(store::Item_t& result, PlanState& planState) const;

  virtual void accept(PlanIterVisitor&) const;
public:
  SERIALIZABLE_CLASS(SelfAxisIterator)
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(SelfAxisIterator, AxisIterator<SelfAxisIterator, SelfAxisState>)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (AxisIterator<SelfAxisIterator, SelfAxisState>*)this);
  }
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
protected:

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
public:
  SERIALIZABLE_CLASS(AttributeAxisIterator)
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(AttributeAxisIterator, AxisIterator<AttributeAxisIterator, AttributeAxisState>)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (AxisIterator<AttributeAxisIterator, AttributeAxisState>*)this);
  }
};


/*******************************************************************************

********************************************************************************/
class ParentAxisState : public AxisState
{

};

class ParentAxisIterator : public AxisIterator<ParentAxisIterator, ParentAxisState>
{
public:
  ParentAxisIterator(short sctx, const QueryLoc& loc, PlanIter_t input)
    :
    AxisIterator<ParentAxisIterator, ParentAxisState>(sctx, loc, input)
  {
  }

  ~ParentAxisIterator() {}

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
 
  // Manually instantiated here, as MSVC does not do it
  // void closeImpl(PlanState& planState); 
  
  virtual void accept(PlanIterVisitor&) const;
public:
  SERIALIZABLE_CLASS(ParentAxisIterator)
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ParentAxisIterator, AxisIterator<ParentAxisIterator, ParentAxisState>)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (AxisIterator<ParentAxisIterator, ParentAxisState>*)this);
  }
};


/*******************************************************************************

********************************************************************************/
class AncestorAxisState : public AxisState
{
public:
  store::Item_t  theCurrentAnc;
};

class AncestorAxisIterator : public AxisIterator<AncestorAxisIterator, AncestorAxisState>
{
public:
  AncestorAxisIterator(short sctx, const QueryLoc& loc, PlanIter_t input)
    :
    AxisIterator<AncestorAxisIterator, AncestorAxisState>(sctx, loc, input)
  {
  }

  ~AncestorAxisIterator() {}

  bool nextImpl(store::Item_t& result, PlanState& planState) const;

  virtual void accept(PlanIterVisitor&) const;
public:
  SERIALIZABLE_CLASS(AncestorAxisIterator)
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(AncestorAxisIterator, AxisIterator<AncestorAxisIterator, AncestorAxisState>)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (AxisIterator<AncestorAxisIterator, AncestorAxisState>*)this);
  }
};


/*******************************************************************************

********************************************************************************/
class AncestorSelfAxisState : public AxisState
{
public:
  store::Item_t  theCurrentAnc;
};


class AncestorSelfAxisIterator : public AxisIterator<AncestorSelfAxisIterator, AncestorSelfAxisState>
{
protected:

public:
  AncestorSelfAxisIterator(short sctx, const QueryLoc& loc, PlanIter_t input)
    :
    AxisIterator<AncestorSelfAxisIterator, AncestorSelfAxisState>(sctx, loc, input)
  {
  }

  ~AncestorSelfAxisIterator() {}

  bool nextImpl(store::Item_t& result, PlanState& planState) const;

  virtual void accept(PlanIterVisitor&) const;
public:
  SERIALIZABLE_CLASS(AncestorSelfAxisIterator)
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(AncestorSelfAxisIterator, AxisIterator<AncestorSelfAxisIterator, AncestorSelfAxisState>)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (AxisIterator<AncestorSelfAxisIterator, AncestorSelfAxisState>*)this);
  }
};


/*******************************************************************************

********************************************************************************/
class RSiblingAxisState : public AxisState
{
public:
  store::Iterator_t  theChildren;

  RSiblingAxisState();
  ~RSiblingAxisState();
  void init(PlanState&);
  void reset(PlanState&);
};


class RSiblingAxisIterator : public AxisIterator<RSiblingAxisIterator, RSiblingAxisState>
{
public:
  RSiblingAxisIterator(short sctx, const QueryLoc& loc, PlanIter_t input)
    :
    AxisIterator<RSiblingAxisIterator, RSiblingAxisState>(sctx, loc, input)
  {
  }

  ~RSiblingAxisIterator() {}

  bool nextImpl(store::Item_t& result, PlanState& planState) const;

  virtual void accept(PlanIterVisitor&) const;
public:
  SERIALIZABLE_CLASS(RSiblingAxisIterator)
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(RSiblingAxisIterator, AxisIterator<RSiblingAxisIterator, RSiblingAxisState>)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (AxisIterator<RSiblingAxisIterator, RSiblingAxisState>*)this);
  }
};


/*******************************************************************************

********************************************************************************/
class LSiblingAxisState : public AxisState
{
public:
  store::Iterator_t  theChildren;

  LSiblingAxisState();
  ~LSiblingAxisState();
  void init(PlanState&);
  void reset(PlanState&);
};


class LSiblingAxisIterator : public AxisIterator<LSiblingAxisIterator, LSiblingAxisState>
{
protected:

public:
  LSiblingAxisIterator(short sctx, const QueryLoc& loc, PlanIter_t input)
    :
    AxisIterator<LSiblingAxisIterator, LSiblingAxisState>(sctx, loc, input)
  {
  }

  ~LSiblingAxisIterator() {}

  bool nextImpl(store::Item_t& result, PlanState& planState) const;

  virtual void accept(PlanIterVisitor&) const;
public:
  SERIALIZABLE_CLASS(LSiblingAxisIterator)
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(LSiblingAxisIterator, AxisIterator<LSiblingAxisIterator, LSiblingAxisState>)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (AxisIterator<LSiblingAxisIterator, LSiblingAxisState>*)this);
  }
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
  std::vector<std::pair<store::Item*, store::ChildrenIterator*> > theCurrentPath;

public:
  DescendantAxisState();
  ~DescendantAxisState();

  void init(PlanState&);
  void reset(PlanState&);

  bool empty() const
  {
    return theTop == 0;
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

  void push(store::Item_t& node);
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

  PrecedingAxisState();
  ~PrecedingAxisState();

  void init(PlanState&);
  void reset(PlanState&);
};

class PrecedingAxisIterator : public AxisIterator<PrecedingAxisIterator,
                                                  PrecedingAxisState>
{
public:
  PrecedingAxisIterator(short sctx, const QueryLoc& loc, PlanIter_t input)
    :
    AxisIterator<PrecedingAxisIterator, PrecedingAxisState>(sctx, loc, input)
  {
  }

  ~PrecedingAxisIterator() {}

  bool nextImpl(store::Item_t& result, PlanState& planState) const;

  virtual void accept(PlanIterVisitor&) const;
public:
  SERIALIZABLE_CLASS(PrecedingAxisIterator)
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(PrecedingAxisIterator, AxisIterator<PrecedingAxisIterator, PrecedingAxisState>)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (AxisIterator<PrecedingAxisIterator, PrecedingAxisState>*)this);
  }
};


/*******************************************************************************

********************************************************************************/
class FollowingAxisState : public AxisState
{
public:
  std::stack<store::Item_t>                                theAncestorPath;
  std::stack<std::pair<store::Item_t, store::Iterator_t> > theCurrentPath;

  FollowingAxisState();
  ~FollowingAxisState();

  void init(PlanState&);
  void reset(PlanState&);
};


class FollowingAxisIterator : public AxisIterator<FollowingAxisIterator,
                                                  FollowingAxisState>
{

public:
  FollowingAxisIterator(short sctx, const QueryLoc& loc, PlanIter_t input)
    :
    AxisIterator<FollowingAxisIterator, FollowingAxisState>(sctx, loc, input)
  {
  }

  ~FollowingAxisIterator() {}

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
  
  virtual void accept(PlanIterVisitor&) const;
public:
  SERIALIZABLE_CLASS(FollowingAxisIterator)
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FollowingAxisIterator, AxisIterator<FollowingAxisIterator,FollowingAxisState>)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (AxisIterator<FollowingAxisIterator,FollowingAxisState>*)this);
  }
};


/*******************************************************************************

********************************************************************************/

} /* namespace zorba */

#endif  /* ZORBA_PATH_ITERATORS_H */
