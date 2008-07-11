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
#ifndef ZORBA_PATH_ITERATOR
#define ZORBA_PATH_ITERATOR

//#define PATH_ITERATOR

#include <stack>
#include <zorba/store_consts.h>
#include "zorbautils/fatal.h"

#include "common/shared_types.h"
#include "runtime/base/unarybase.h" 
#include "compiler/expression/expr_consts.h"
#include "store/api/iterator.h"

namespace zorba 
{

#ifdef PATH_ITERATOR

/*******************************************************************************

********************************************************************************/
class NodePredicate
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
  NodePredicate() 
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

  virtual ~NodePredicate() {}

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

  inline bool apply(const store::Item* node, PlanState& planState) const;
};


/*******************************************************************************

********************************************************************************/
class PathStepState
{
public:
  store::Item*  theContextNode;
  bool          theStart;

public:
 PathStepState() : theContextNode(NULL), theStart(false) {}

  virtual ~PathStepState() {}

  virtual void reset() = 0;
};


/*******************************************************************************

********************************************************************************/
class SelfStepState : public PathStepState
{
public:
  SelfStepState()  { }
  ~SelfStepState() { }

  void reset() { }
};


/*******************************************************************************

********************************************************************************/
class AttributeStepState : public PathStepState
{
public:
  rchandle<store::AttributesIterator> theAttributes;

public:
  AttributeStepState();
  ~AttributeStepState() { }

  void reset();
};


/*******************************************************************************

********************************************************************************/
class ParentStepState : public PathStepState
{
public:
  ParentStepState()  { }
  ~ParentStepState() { }

  void reset() { }
};


/*******************************************************************************

********************************************************************************/
class AncestorStepState : public PathStepState
{
public:
  store::Item*  theCurrentAnc;

public:
  AncestorStepState() : PathStepState(), theCurrentAnc(NULL) { }
  ~AncestorStepState() { }

  void reset() { theCurrentAnc = NULL; }
};


/*******************************************************************************

********************************************************************************/
class SiblingStepState : public PathStepState
{
public:
  rchandle<store::ChildrenIterator>  theChildren;

public:
  SiblingStepState();
  ~SiblingStepState() { }

  void reset();
};


/*******************************************************************************

********************************************************************************/
class ChildStepState : public PathStepState
{
public:
  rchandle<store::ChildrenIterator>  theChildren;

public:
  ChildStepState();
  ~ChildStepState() { }

  void reset();
};


/*******************************************************************************

********************************************************************************/
class DescendantStepState : public PathStepState
{
public:
  ulong theTop;
  std::vector<std::pair<store::Item*, store::ChildrenIterator*> > theCurrentPath;

public:
  DescendantStepState() : theTop(0) { }
  ~DescendantStepState();

  void reset()  { theTop = 0; }

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

  void push(store::Item* node);
};


#if 0
/*******************************************************************************

********************************************************************************/
class PrecedingAxisState : public PathStepState
{
public:
  std::stack<store::Item_t>                                theAncestorPath;
  std::stack<std::pair<store::Item_t, store::Iterator_t> > theCurrentPath;

  PrecedingAxisState();
  ~PrecedingAxisState();

  void init(PlanState&);
  void reset(PlanState&);
};


/*******************************************************************************

********************************************************************************/
class FollowingAxisState : public PathStepState
{
public:
  std::stack<store::Item_t>                                theAncestorPath;
  std::stack<std::pair<store::Item_t, store::Iterator_t> > theCurrentPath;

  FollowingAxisState();
  ~FollowingAxisState();

  void init(PlanState&);
  void reset(PlanState&);
};
#endif

/*******************************************************************************

********************************************************************************/
class PathIteratorState : public PlanIteratorState
{
public:
  store::Item_t                theContextNode;   

  ulong                        theCurrentStep;

  ulong                        theNumSteps;

  std::vector<PathStepState*>  theStepStates;

public:
  PathIteratorState() : theCurrentStep(0), theNumSteps(0)  {}

  ~PathIteratorState();

  void init(PlanState& planState);
  void reset(PlanState& planState);
};


/*******************************************************************************

********************************************************************************/
class PathIterator : public UnaryBaseIterator<PathIterator, PathIteratorState>
{
protected:
  std::vector<axis_kind_t>    theAxes;
  std::vector<NodePredicate*> theNodePreds;

public:
  PathIterator(const QueryLoc&  loc, PlanIter_t input)
    :
    UnaryBaseIterator<PathIterator, PathIteratorState>(loc, input)
  {
  }

  virtual ~PathIterator();

  void addStep(axis_kind_t axis, NodePredicate* prd);

  void accept(PlanIterVisitor&) const;

  void openImpl(PlanState& planState, uint32_t& offset);

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
};


#else

/*******************************************************************************

********************************************************************************/
class PathIteratorState : public PlanIteratorState
{
public:
  PathIteratorState() {}

  ~PathIteratorState() {}

  void init(PlanState& planState) {}
  void reset(PlanState& planState) {}
};


/*******************************************************************************

********************************************************************************/
class PathIterator : public UnaryBaseIterator<PathIterator, PathIteratorState>
{
public:
  PathIterator(const QueryLoc&  loc, PlanIter_t input)
    :
    UnaryBaseIterator<PathIterator, PathIteratorState>(loc, input)
  {
  }

  virtual ~PathIterator() { }

  void accept(PlanIterVisitor&) const;

  void openImpl(PlanState& planState, uint32_t& offset) {}

  bool nextImpl(store::Item_t& result, PlanState& planState) const
  {
    return false;
  }
};

#endif // PATH_ITERATOR

} /* namespace zorba */


#endif  /* ZORBA_PATH_ITERATORS_H */
