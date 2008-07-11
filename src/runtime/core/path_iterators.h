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
#include "runtime/base/unarybase.h" 
#include "compiler/expression/expr_consts.h"
#include "types/typeimpl.h"
#include "types/typeops.h"
#include "types/typemanager.h"
#include "context/static_context.h"

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
protected:

public:
  AxisIterator(const QueryLoc& loc, PlanIter_t input)
    :
    UnaryBaseIterator<AxisIter, State>(loc, input)
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
protected:
public:
  SelfAxisIterator(const QueryLoc& loc, PlanIter_t input)
    :
    AxisIterator<SelfAxisIterator, SelfAxisState>(loc, input)
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
protected:

public:
  AttributeAxisIterator(const QueryLoc& loc, PlanIter_t input)
    :
    AxisIterator<AttributeAxisIterator, AttributeAxisState>(loc, input)
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
  ParentAxisIterator(const QueryLoc& loc, PlanIter_t input)
    :
    AxisIterator<ParentAxisIterator, ParentAxisState>(loc, input)
  {
  }

  ~ParentAxisIterator() {}

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
 
  // Manually instantiated here, as MSVC does not do it
  // void closeImpl(PlanState& planState); 
  
  virtual void accept(PlanIterVisitor&) const;
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
  AncestorAxisIterator(const QueryLoc& loc, PlanIter_t input)
    :
    AxisIterator<AncestorAxisIterator, AncestorAxisState>(loc, input)
  {
  }

  ~AncestorAxisIterator() {}

  bool nextImpl(store::Item_t& result, PlanState& planState) const;

  virtual void accept(PlanIterVisitor&) const;
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
  AncestorSelfAxisIterator(const QueryLoc& loc, PlanIter_t input)
    :
    AxisIterator<AncestorSelfAxisIterator, AncestorSelfAxisState>(loc, input)
  {
  }

  ~AncestorSelfAxisIterator() {}

  bool nextImpl(store::Item_t& result, PlanState& planState) const;

  virtual void accept(PlanIterVisitor&) const;
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
  RSiblingAxisIterator(const QueryLoc& loc, PlanIter_t input)
    :
    AxisIterator<RSiblingAxisIterator, RSiblingAxisState>(loc, input)
  {
  }

  ~RSiblingAxisIterator() {}

  bool nextImpl(store::Item_t& result, PlanState& planState) const;

  virtual void accept(PlanIterVisitor&) const;
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
  LSiblingAxisIterator(const QueryLoc& loc, PlanIter_t input)
    :
    AxisIterator<LSiblingAxisIterator, LSiblingAxisState>(loc, input)
  {
  }

  ~LSiblingAxisIterator() {}

  bool nextImpl(store::Item_t& result, PlanState& planState) const;

  virtual void accept(PlanIterVisitor&) const;
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
  ChildAxisIterator(const QueryLoc& loc, PlanIter_t input)
    :
    AxisIterator<ChildAxisIterator, ChildAxisState>(loc, input)
  {
  }

  ~ChildAxisIterator() {}

  bool nextImpl(store::Item_t& result, PlanState& planState) const;

  virtual void accept(PlanIterVisitor&) const;
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
  DescendantAxisIterator(const QueryLoc& loc, PlanIter_t input)
    :
    AxisIterator<DescendantAxisIterator, DescendantAxisState>(loc, input)
  {
  }

  ~DescendantAxisIterator() {}

  bool nextImpl(store::Item_t& result, PlanState& planState) const;

  virtual void accept(PlanIterVisitor&) const;
};


/*******************************************************************************

********************************************************************************/
class DescendantSelfAxisIterator : public AxisIterator<DescendantSelfAxisIterator,
                                                       DescendantAxisState>
{
public:
  DescendantSelfAxisIterator(const QueryLoc& loc, PlanIter_t input)
    :
    AxisIterator<DescendantSelfAxisIterator, DescendantAxisState>(loc, input)
  {
  }

  ~DescendantSelfAxisIterator() {}

  bool nextImpl(store::Item_t& result, PlanState& planState) const;

  virtual void accept(PlanIterVisitor&) const;
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
  PrecedingAxisIterator(const QueryLoc& loc, PlanIter_t input)
    :
    AxisIterator<PrecedingAxisIterator, PrecedingAxisState>(loc, input)
  {
  }

  ~PrecedingAxisIterator() {}

  bool nextImpl(store::Item_t& result, PlanState& planState) const;

  virtual void accept(PlanIterVisitor&) const;
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
  FollowingAxisIterator(const QueryLoc& loc, PlanIter_t input)
    :
    AxisIterator<FollowingAxisIterator, FollowingAxisState>(loc, input)
  {
  }

  ~FollowingAxisIterator() {}

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
  
  virtual void accept(PlanIterVisitor&) const;
};


/*******************************************************************************

********************************************************************************/

} /* namespace zorba */

#endif  /* ZORBA_PATH_ITERATORS_H */
