/**
 *
 * @copyright
 * ========================================================================
 *  Copyright 2007 FLWOR Foundation
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *  
 *    http://www.apache.org/licenses/LICENSE-2.0
 *  
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 * ========================================================================
 *
 * @author Markos Zaharioudakis
 * @file runtime/path_iterators.h
 *
 */

#ifndef XQP_PATH_ITERATORS_H
#define XQP_PATH_ITERATORS_H

#include <stack>
#include <zorba/store_consts.h>
#include "common/shared_types.h"
#include "runtime/base/unarybase.h" 
#include "compiler/expression/expr_consts.h"

namespace xqp 
{

/*******************************************************************************

********************************************************************************/
class KindTestIterator : public UnaryBaseIterator<KindTestIterator, PlanIteratorState>
{
private:
  Item_t       theQName;
  Item_t       theTypeName;
  match_test_t theTestKind;
  match_test_t theDocTestKind;
  bool         theNilledAllowed;

public:
  KindTestIterator(
        const yy::location& loc,
        PlanIter_t input,
        Item_t qname,
        Item_t tname,
        match_test_t kind,
        match_test_t docTestKind,
        bool nilled = false)
    :
    UnaryBaseIterator<KindTestIterator, PlanIteratorState>(loc, input),
    theQName(qname),
    theTypeName(tname),
    theTestKind(kind),
    theDocTestKind(docTestKind),
    theNilledAllowed(nilled)
  {
  }

  ~KindTestIterator() {}
  
  const Item_t& getQName() const { return theQName; }
  const Item_t& getTypeName() const { return theTypeName; }
  const match_test_t& getTestKind() const { return theTestKind; }
  const match_test_t& getDocTestKind() const { return theDocTestKind; }
  bool nilledAllowed() const { return theNilledAllowed; }

public:
  Item_t nextImpl(PlanState& planState) const;

  virtual void accept(PlanIterVisitor&) const;
};


/*******************************************************************************

********************************************************************************/
class NameTestIterator : public UnaryBaseIterator<NameTestIterator, PlanIteratorState>
{
private:
  Item_t       theQName;
  match_wild_t theWildKind;

public:
  NameTestIterator(
        const yy::location& loc,
        PlanIter_t input,
        Item_t qname,
        match_wild_t kind)
    :
    UnaryBaseIterator<NameTestIterator, PlanIteratorState>(loc, input),
    theQName(qname),
    theWildKind(kind)
  {
  }

  ~NameTestIterator() {}
  
  const Item_t& getQName() const { return theQName; }

public:
  Item_t nextImpl(PlanState& planState) const;

  virtual void accept(PlanIterVisitor&) const;
};


/*******************************************************************************

********************************************************************************/
class AxisIteratorHelper
{
protected:
  StoreConsts::NodeKind theNodeKind;

public:
  AxisIteratorHelper() : theNodeKind(StoreConsts::anyNode) { }

  virtual ~AxisIteratorHelper() {}

  void setNodeKind(StoreConsts::NodeKind k) { theNodeKind = k; }
};


/*******************************************************************************

********************************************************************************/
class AxisState : public PlanIteratorState
{
public:
  Item_t     theContextNode;   

  void init(PlanState& planState) { PlanIteratorState::init( planState ); }
  void reset(PlanState& planState) { PlanIteratorState::reset( planState ); }
};

template <class AxisIter, class State>
class AxisIterator : public UnaryBaseIterator<AxisIter, State>,
                     public AxisIteratorHelper
{
protected:

public:
  AxisIterator(const yy::location& loc, PlanIter_t input)
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
  SelfAxisIterator(const yy::location& loc, PlanIter_t input)
    :
    AxisIterator<SelfAxisIterator, SelfAxisState>(loc, input)
  {
  }

  ~SelfAxisIterator() {}

  Item_t nextImpl(PlanState& planState) const;

  // Manually instantiated here, as MSVC does not do it
  // void closeImpl(PlanState& planState); 

  virtual void accept(PlanIterVisitor&) const;

};


/*******************************************************************************

********************************************************************************/
class AttributeAxisState : public AxisState
{
public:
  Iterator_t  theAttributes;
  AttributeAxisState();
  ~AttributeAxisState();
  void init(PlanState&);
  void reset(PlanState&);
};

class AttributeAxisIterator : public AxisIterator<AttributeAxisIterator, AttributeAxisState>
{
protected:

public:
  AttributeAxisIterator(const yy::location& loc, PlanIter_t input)
    :
    AxisIterator<AttributeAxisIterator, AttributeAxisState>(loc, input)
  {
  }

  ~AttributeAxisIterator() {}

  Item_t nextImpl(PlanState& planState) const;

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
  ParentAxisIterator(const yy::location& loc, PlanIter_t input)
    :
    AxisIterator<ParentAxisIterator, ParentAxisState>(loc, input)
  {
  }

  ~ParentAxisIterator() {}

  Item_t nextImpl(PlanState& planState) const;
 
  // Manually instantiated here, as MSVC does not do it
  // void closeImpl(PlanState& planState); 
  
  virtual void accept(PlanIterVisitor&) const;
};


/*******************************************************************************

********************************************************************************/
class AncestorAxisState : public AxisState
{
public:
  Item_t  theCurrentAnc;
};

class AncestorAxisIterator : public AxisIterator<AncestorAxisIterator, AncestorAxisState>
{
public:
  AncestorAxisIterator(const yy::location& loc, PlanIter_t input)
    :
    AxisIterator<AncestorAxisIterator, AncestorAxisState>(loc, input)
  {
  }

  ~AncestorAxisIterator() {}

  //void openImpl(PlanState& planState, uint32_t& offset);
  Item_t nextImpl(PlanState& planState) const;
  //void closeImpl(PlanState& planState);

  virtual void accept(PlanIterVisitor&) const;
};


/*******************************************************************************

********************************************************************************/
class AncestorSelfAxisState : public AxisState
{
public:
  Item_t  theCurrentAnc;
};

class AncestorSelfAxisIterator : public AxisIterator<AncestorSelfAxisIterator, AncestorSelfAxisState>
{
protected:

public:
  AncestorSelfAxisIterator(const yy::location& loc, PlanIter_t input)
    :
    AxisIterator<AncestorSelfAxisIterator, AncestorSelfAxisState>(loc, input)
  {
  }

  ~AncestorSelfAxisIterator() {}

  Item_t nextImpl(PlanState& planState) const;

  virtual void accept(PlanIterVisitor&) const;
};


/*******************************************************************************

********************************************************************************/
class RSiblingAxisState : public AxisState
{
public:
  Iterator_t  theChildren;
  RSiblingAxisState();
  ~RSiblingAxisState();
  void init(PlanState&);
  void reset(PlanState&);
};
class RSiblingAxisIterator : public AxisIterator<RSiblingAxisIterator, RSiblingAxisState>
{
public:
  RSiblingAxisIterator(const yy::location& loc, PlanIter_t input)
    :
    AxisIterator<RSiblingAxisIterator, RSiblingAxisState>(loc, input)
  {
  }

  ~RSiblingAxisIterator() {}

  Item_t nextImpl(PlanState& planState) const;

  virtual void accept(PlanIterVisitor&) const;
};


/*******************************************************************************

********************************************************************************/
class LSiblingAxisState : public AxisState
{
public:
  Iterator_t  theChildren;
  LSiblingAxisState();
  ~LSiblingAxisState();
  void init(PlanState&);
  void reset(PlanState&);
};

class LSiblingAxisIterator : public AxisIterator<LSiblingAxisIterator, LSiblingAxisState>
{
protected:

public:
  LSiblingAxisIterator(const yy::location& loc, PlanIter_t input)
    :
    AxisIterator<LSiblingAxisIterator, LSiblingAxisState>(loc, input)
  {
  }

  ~LSiblingAxisIterator() {}

  Item_t nextImpl(PlanState& planState) const;

  virtual void accept(PlanIterVisitor&) const;
};


/*******************************************************************************

********************************************************************************/
class ChildAxisState : public AxisState
{
public:
  Iterator_t  theChildren;

  ChildAxisState();
  ~ChildAxisState();

  void init(PlanState&);
  void reset(PlanState&);
};

class ChildAxisIterator : public AxisIterator<ChildAxisIterator, ChildAxisState>
{
protected:

public:
  ChildAxisIterator(const yy::location& loc, PlanIter_t input)
    :
    AxisIterator<ChildAxisIterator, ChildAxisState>(loc, input)
  {
  }

  ~ChildAxisIterator() {}

  Item_t nextImpl(PlanState& planState) const;

  virtual void accept(PlanIterVisitor&) const;
};


/*******************************************************************************

********************************************************************************/
class DescendantAxisState : public AxisState
{
public:
  std::stack<std::pair<Item_t, Iterator_t> > theCurrentPath;
  DescendantAxisState();
  ~DescendantAxisState();
  void init(PlanState&);
  void reset(PlanState&);
};

class DescendantAxisIterator : public AxisIterator<DescendantAxisIterator, DescendantAxisState>
{
protected:

public:
  DescendantAxisIterator(const yy::location& loc, PlanIter_t input)
    :
    AxisIterator<DescendantAxisIterator, DescendantAxisState>(loc, input)
  {
  }

  ~DescendantAxisIterator() {}

  Item_t nextImpl(PlanState& planState) const;

  virtual void accept(PlanIterVisitor&) const;
};


/*******************************************************************************

********************************************************************************/
class DescendantSelfAxisState : public AxisState
{
public:
  std::stack<std::pair<Item_t, Iterator_t> > theCurrentPath;
  DescendantSelfAxisState();
  ~DescendantSelfAxisState();
  void init(PlanState&);
  void reset(PlanState&);
};
class DescendantSelfAxisIterator : public AxisIterator<DescendantSelfAxisIterator, DescendantSelfAxisState>
{
protected:

public:
  DescendantSelfAxisIterator(const yy::location& loc, PlanIter_t input)
    :
    AxisIterator<DescendantSelfAxisIterator, DescendantSelfAxisState>(loc, input)
  {
  }

  ~DescendantSelfAxisIterator() {}

  Item_t nextImpl(PlanState& planState) const;

  virtual void accept(PlanIterVisitor&) const;
};


/*******************************************************************************

********************************************************************************/
class PrecedingAxisState : public AxisState
{
public:
  std::stack<Item_t>                         theAncestorPath;
  std::stack<std::pair<Item_t, Iterator_t> > theCurrentPath;
  PrecedingAxisState();
  ~PrecedingAxisState();
  void init(PlanState&);
  void reset(PlanState&);
};

class PrecedingAxisIterator : public AxisIterator<PrecedingAxisIterator, PrecedingAxisState>
{
public:
  PrecedingAxisIterator(const yy::location& loc, PlanIter_t input)
    :
    AxisIterator<PrecedingAxisIterator, PrecedingAxisState>(loc, input)
  {
  }

  ~PrecedingAxisIterator() {}

  Item_t nextImpl(PlanState& planState) const;

  virtual void accept(PlanIterVisitor&) const;
};


/*******************************************************************************

********************************************************************************/
class FollowingAxisState : public AxisState
{
public:
  std::stack<Item_t>                         theAncestorPath;
  std::stack<std::pair<Item_t, Iterator_t> > theCurrentPath;
  FollowingAxisState();
  ~FollowingAxisState();
  void init(PlanState&);
  void reset(PlanState&);
};
class FollowingAxisIterator : public AxisIterator<FollowingAxisIterator, FollowingAxisState>
{

public:
  FollowingAxisIterator(const yy::location& loc, PlanIter_t input)
    :
    AxisIterator<FollowingAxisIterator, FollowingAxisState>(loc, input)
  {
  }

  ~FollowingAxisIterator() {}

  Item_t nextImpl(PlanState& planState) const;
  
  virtual void accept(PlanIterVisitor&) const;
};


} /* namespace xqp */

#endif  /* XQP_PATH_ITERATORS_H */
