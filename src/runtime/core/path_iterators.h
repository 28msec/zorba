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


#include "util/rchandle.h"
#include "util/logging/logging.hh"
#include "compiler/expression/expr_consts.h"
#include "runtime/base/iterator.h"
#include "runtime/base/unarybase.h"
#include "store/api/store_consts.h"
#include <stack>

namespace xqp 
{

/*******************************************************************************

********************************************************************************/
class KindTestIterator : public UnaryBaseIterator<KindTestIterator>
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
    UnaryBaseIterator<KindTestIterator>(loc, input),
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
  Item_t nextImpl(PlanState& planState);

  virtual void accept(PlanIterVisitor&) const;
};


/*******************************************************************************

********************************************************************************/
class NameTestIterator : public UnaryBaseIterator<NameTestIterator>
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
    UnaryBaseIterator<NameTestIterator>(loc, input),
    theQName(qname),
    theWildKind(kind)
  {
  }

  ~NameTestIterator() {}
  
  const Item_t& getQName() const { return theQName; }

public:
  Item_t nextImpl(PlanState& planState);

  virtual void accept(PlanIterVisitor&) const;
};


/*******************************************************************************

********************************************************************************/
class AxisIteratorHelper
{
protected:
  StoreConsts::NodeKind_t theNodeKind;

public:
  AxisIteratorHelper() : theNodeKind(StoreConsts::anyNode) { }

  virtual ~AxisIteratorHelper() {}

  void setNodeKind(StoreConsts::NodeKind_t k) { theNodeKind = k; }
};


/*******************************************************************************

********************************************************************************/
template <class AxisIter>
class AxisIterator : public UnaryBaseIterator<AxisIter>,
                     public AxisIteratorHelper
{
protected:
  class AxisState : public PlanIteratorState
  {
  public:
    Item_t     theContextNode;   
  };

public:
  AxisIterator(const yy::location& loc, PlanIter_t input)
    :
    UnaryBaseIterator<AxisIter>(loc, input)
  {
  }

  virtual ~AxisIterator() {}

  void releaseResourcesImpl(PlanState& planState);

  uint32_t getStateSize() const { return sizeof(AxisState); }
};


/*******************************************************************************

********************************************************************************/
class SelfAxisIterator : public AxisIterator<SelfAxisIterator>
{
protected:
  class SelfAxisState : public AxisState
  {
  };

public:
  SelfAxisIterator(const yy::location& loc, PlanIter_t input)
    :
    AxisIterator<SelfAxisIterator>(loc, input)
  {
  }

  ~SelfAxisIterator() {}

  Item_t nextImpl(PlanState& planState);

  // Manually instantiated here, as MSVC does not do it
  void releaseResourcesImpl(PlanState& planState); 

  virtual void accept(PlanIterVisitor&) const;
};


/*******************************************************************************

********************************************************************************/
class AttributeAxisIterator : public AxisIterator<AttributeAxisIterator>
{
protected:
  class AttributeAxisState : public AxisState
  {
  public:
    Iterator_t  theAttributes;
  };

public:
  AttributeAxisIterator(const yy::location& loc, PlanIter_t input)
    :
    AxisIterator<AttributeAxisIterator>(loc, input)
  {
  }

  ~AttributeAxisIterator() {}

  Item_t nextImpl(PlanState& planState);
  void resetImpl(PlanState& planState);
  void releaseResourcesImpl(PlanState& planState);

  uint32_t getStateSize() const { return sizeof(AttributeAxisState); }

  virtual void accept(PlanIterVisitor&) const;
};


/*******************************************************************************

********************************************************************************/
class ParentAxisIterator : public AxisIterator<ParentAxisIterator>
{
protected:
  class ParentAxisState : public AxisState
  {
  };

public:
  ParentAxisIterator(const yy::location& loc, PlanIter_t input)
    :
    AxisIterator<ParentAxisIterator>(loc, input)
  {
  }

  ~ParentAxisIterator() {}

  Item_t nextImpl(PlanState& planState);
 
  // Manually instantiated here, as MSVC does not do it
  void releaseResourcesImpl(PlanState& planState); 
  
  virtual void accept(PlanIterVisitor&) const;
};


/*******************************************************************************

********************************************************************************/
class AncestorAxisIterator : public AxisIterator<AncestorAxisIterator>
{
protected:
  class AncestorAxisState : public AxisState
  {
  public:
    Item_t  theCurrentAnc;
  };

public:
  AncestorAxisIterator(const yy::location& loc, PlanIter_t input)
    :
    AxisIterator<AncestorAxisIterator>(loc, input)
  {
  }

  ~AncestorAxisIterator() {}

  Item_t nextImpl(PlanState& planState);
  void releaseResourcesImpl(PlanState& planState);

  uint32_t getStateSize() const { return sizeof(AncestorAxisState); }

  virtual void accept(PlanIterVisitor&) const;
};


/*******************************************************************************

********************************************************************************/
class AncestorSelfAxisIterator : public AxisIterator<AncestorSelfAxisIterator>
{
protected:
  class AncestorSelfAxisState : public AxisState
  {
  public:
    Item_t  theCurrentAnc;
  };

public:
  AncestorSelfAxisIterator(const yy::location& loc, PlanIter_t input)
    :
    AxisIterator<AncestorSelfAxisIterator>(loc, input)
  {
  }

  ~AncestorSelfAxisIterator() {}

  Item_t nextImpl(PlanState& planState);
  void releaseResourcesImpl(PlanState& planState);

  uint32_t getStateSize() const { return sizeof(AncestorSelfAxisState); }

  virtual void accept(PlanIterVisitor&) const;
};


/*******************************************************************************

********************************************************************************/
class RSiblingAxisIterator : public AxisIterator<RSiblingAxisIterator>
{
protected:
  class RSiblingAxisState : public AxisState
  {
  public:
    Iterator_t  theChildren;
  };

public:
  RSiblingAxisIterator(const yy::location& loc, PlanIter_t input)
    :
    AxisIterator<RSiblingAxisIterator>(loc, input)
  {
  }

  ~RSiblingAxisIterator() {}

  Item_t nextImpl(PlanState& planState);
  void resetImpl(PlanState& planState);
  void releaseResourcesImpl(PlanState& planState);

  uint32_t getStateSize() const { return sizeof(RSiblingAxisState); }

  virtual void accept(PlanIterVisitor&) const;
};


/*******************************************************************************

********************************************************************************/
class LSiblingAxisIterator : public AxisIterator<LSiblingAxisIterator>
{
protected:
  class LSiblingAxisState : public AxisState
  {
  public:
    Iterator_t  theChildren;
  };

public:
  LSiblingAxisIterator(const yy::location& loc, PlanIter_t input)
    :
    AxisIterator<LSiblingAxisIterator>(loc, input)
  {
  }

  ~LSiblingAxisIterator() {}

  Item_t nextImpl(PlanState& planState);
  void resetImpl(PlanState& planState);
  void releaseResourcesImpl(PlanState& planState);

  uint32_t getStateSize() const { return sizeof(LSiblingAxisState); }

  virtual void accept(PlanIterVisitor&) const;
};


/*******************************************************************************

********************************************************************************/
class ChildAxisIterator : public AxisIterator<ChildAxisIterator>
{
protected:
  class ChildAxisState : public AxisState
  {
  public:
    Iterator_t  theChildren;
  };

public:
  ChildAxisIterator(const yy::location& loc, PlanIter_t input)
    :
    AxisIterator<ChildAxisIterator>(loc, input)
  {
  }

  ~ChildAxisIterator() {}

  Item_t nextImpl(PlanState& planState);
  void resetImpl(PlanState& planState);
  void releaseResourcesImpl(PlanState& planState);

  uint32_t getStateSize() const { return sizeof(ChildAxisState); }

  virtual void accept(PlanIterVisitor&) const;
};


/*******************************************************************************

********************************************************************************/
class DescendantAxisIterator : public AxisIterator<DescendantAxisIterator>
{
protected:
  class DescendantAxisState : public AxisState
  {
  public:
    std::stack<std::pair<Item_t, Iterator_t> > theCurrentPath;
  };

public:
  DescendantAxisIterator(const yy::location& loc, PlanIter_t input)
    :
    AxisIterator<DescendantAxisIterator>(loc, input)
  {
  }

  ~DescendantAxisIterator() {}

  Item_t nextImpl(PlanState& planState);
  void resetImpl(PlanState& planState);
  void releaseResourcesImpl(PlanState& planState);

  uint32_t getStateSize() const { return sizeof(DescendantAxisState); }

  void setOffset(PlanState& planState, uint32_t& offset);

  virtual void accept(PlanIterVisitor&) const;
};


/*******************************************************************************

********************************************************************************/
class DescendantSelfAxisIterator : public AxisIterator<DescendantSelfAxisIterator>
{
protected:
  class DescendantSelfAxisState : public AxisState
  {
  public:
    std::stack<std::pair<Item_t, Iterator_t> > theCurrentPath;
  };

public:
  DescendantSelfAxisIterator(const yy::location& loc, PlanIter_t input)
    :
    AxisIterator<DescendantSelfAxisIterator>(loc, input)
  {
  }

  ~DescendantSelfAxisIterator() {}

  Item_t nextImpl(PlanState& planState);
  void resetImpl(PlanState& planState);
  void releaseResourcesImpl(PlanState& planState);

  uint32_t getStateSize() const { return sizeof(DescendantSelfAxisState); }

  void setOffset(PlanState& planState, uint32_t& offset);

  virtual void accept(PlanIterVisitor&) const;
};


/*******************************************************************************

********************************************************************************/
class PrecedingAxisIterator : public AxisIterator<PrecedingAxisIterator>
{
protected:
  class PrecedingAxisState : public AxisState
  {
  public:
    std::stack<Item_t>                         theAncestorPath;
    std::stack<std::pair<Item_t, Iterator_t> > theCurrentPath;
  };

public:
  PrecedingAxisIterator(const yy::location& loc, PlanIter_t input)
    :
    AxisIterator<PrecedingAxisIterator>(loc, input)
  {
  }

  ~PrecedingAxisIterator() {}

  Item_t nextImpl(PlanState& planState);
  void resetImpl(PlanState& planState);
  void releaseResourcesImpl(PlanState& planState);

  uint32_t getStateSize() const { return sizeof(PrecedingAxisState); }

  void setOffset(PlanState& planState, uint32_t& offset);

  virtual void accept(PlanIterVisitor&) const;
};


/*******************************************************************************

********************************************************************************/
class FollowingAxisIterator : public AxisIterator<FollowingAxisIterator>
{
  class FollowingAxisState : public AxisState
  {
  public:
    std::stack<Item_t>                         theAncestorPath;
    std::stack<std::pair<Item_t, Iterator_t> > theCurrentPath;
  };

public:
  FollowingAxisIterator(const yy::location& loc, PlanIter_t input)
    :
    AxisIterator<FollowingAxisIterator>(loc, input)
  {
  }

  ~FollowingAxisIterator() {}

  Item_t nextImpl(PlanState& planState);
  void resetImpl(PlanState& planState);
  void releaseResourcesImpl(PlanState& planState);

  uint32_t getStateSize() const { return sizeof(FollowingAxisState); }

  void setOffset(PlanState& planState, uint32_t& offset);
  
  virtual void accept(PlanIterVisitor&) const;
};


} /* namespace xqp */

#endif  /* XQP_PATH_ITERATORS_H */
