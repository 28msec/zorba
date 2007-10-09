/**
 *
 * @copyright
 * ========================================================================
 *	Copyright 2007 FLWOR Foundation
 *
 *	Licensed under the Apache License, Version 2.0 (the "License");
 *	you may not use this file except in compliance with the License.
 *	You may obtain a copy of the License at
 *	
 *		http://www.apache.org/licenses/LICENSE-2.0
 *	
 *	Unless required by applicable law or agreed to in writing, software
 *	distributed under the License is distributed on an "AS IS" BASIS,
 *	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *	See the License for the specific language governing permissions and
 *	limitations under the License.
 * ========================================================================
 *
 * @author Markos Zaharioudakis
 * @file runtime/path_iterators.h
 *
 */

#ifndef XQP_PATH_ITERATORS_H
#define XQP_PATH_ITERATORS_H

#include <stack>

#include "util/rchandle.h"
#include "compiler/expression/expr_consts.h"
#include "runtime/core/batching.h"


namespace xqp {


/*******************************************************************************

********************************************************************************/
class KindTestIterator : public Batcher<KindTestIterator>
{
private:
  Iterator_t   theInput;
  Item_t       theQName;
  Item_t       theTypeName;
  match_test_t theTestKind;
  bool         theNilledAllowed;

public:
  KindTestIterator(
        yy::location loc,
        Iterator_t input,
        Item_t qname,
        Item_t tname,
        match_test_t kind,
        bool nilled = false)
    :
    Batcher<KindTestIterator>(loc),
    theInput(input),
    theQName(qname),
    theTypeName(tname),
    theTestKind(kind),
    theNilledAllowed(nilled)
  {
  }

  ~KindTestIterator() {}

public:
  Item_t nextImpl(IteratorTreeStateBlock& stateBlock);
  void resetImpl(IteratorTreeStateBlock& stateBlock);
  void releaseResourcesImpl(IteratorTreeStateBlock& stateBlock);

  std::ostream& _show(std::ostream& os) const;
};


/*******************************************************************************

********************************************************************************/
class NameTestIterator : public Batcher<NameTestIterator>
{
private:
  Iterator_t   theInput;
  Item_t       theQName;
  match_wild_t theWildKind;

public:
  NameTestIterator(
        yy::location loc,
        Iterator_t input,
        Item_t qname,
        match_wild_t kind)
    :
    Batcher<NameTestIterator>(loc),
    theInput(input),
    theQName(qname),
    theWildKind(kind)
  {
  }

  ~NameTestIterator() {}

public:
  Item_t nextImpl(IteratorTreeStateBlock& stateBlock);
  void resetImpl(IteratorTreeStateBlock& stateBlock);
  void releaseResourcesImpl(IteratorTreeStateBlock& stateBlock);

  std::ostream& _show(std::ostream& os) const;
};


/*******************************************************************************

********************************************************************************/
class AxisIterator
{
protected:
  Iterator_t  theInput;
  Item_t      theContextNode;
  TypeCode    theNodeKind;

public:
  AxisIterator(Iterator_t input)
    :
    theInput(input),
    theNodeKind(anyNode)
  {
  }

  virtual ~AxisIterator() {}

  void setNodeKind(TypeCode k) { theNodeKind = k; }
};


/*******************************************************************************

********************************************************************************/
class SelfAxisIterator : public Batcher<SelfAxisIterator>,
                         public AxisIterator
{
public:
  SelfAxisIterator(yy::location loc, Iterator_t input)
    :
    Batcher<SelfAxisIterator>(loc),
    AxisIterator(input)
  {
  }

  ~SelfAxisIterator() {}

public:
  Item_t nextImpl(IteratorTreeStateBlock& stateBlock);
  void resetImpl(IteratorTreeStateBlock& stateBlock);
  void releaseResourcesImpl(IteratorTreeStateBlock& stateBlock);

  std::ostream& _show(std::ostream& os) const;
};


/*******************************************************************************

********************************************************************************/
class AttributeAxisIterator : public Batcher<AttributeAxisIterator>,
                              public AxisIterator
{
private:
  Iterator_t  theAttributes;
#ifdef DEBUG
  Item_t      theCurrentAttr;
#endif

public:
  AttributeAxisIterator(yy::location loc, Iterator_t input)
    :
    Batcher<AttributeAxisIterator>(loc),
    AxisIterator(input)
  {
  }

  ~AttributeAxisIterator() {}

public:
  Item_t nextImpl(IteratorTreeStateBlock& stateBlock);
  void resetImpl(IteratorTreeStateBlock& stateBlock);
  void releaseResourcesImpl(IteratorTreeStateBlock& stateBlock);

  std::ostream& _show(std::ostream& os) const;
};


/*******************************************************************************

********************************************************************************/
class ParentAxisIterator : public Batcher<ParentAxisIterator>,
                           public AxisIterator
{
private:
#ifdef DEBUG
  Item_t  theParent;
#endif

public:
  ParentAxisIterator(yy::location loc, Iterator_t input)
    :
    Batcher<ParentAxisIterator>(loc),
    AxisIterator(input)
  {
  }

  ~ParentAxisIterator() {}

public:
  Item_t nextImpl(IteratorTreeStateBlock& stateBlock);
  void resetImpl(IteratorTreeStateBlock& stateBlock);
  void releaseResourcesImpl(IteratorTreeStateBlock& stateBlock);

  std::ostream& _show(std::ostream& os) const;
};


/*******************************************************************************

********************************************************************************/
class AncestorAxisIterator : public Batcher<AncestorAxisIterator>,
                             public AxisIterator
{
private:
  Item_t  theCurrentAnc;

public:
  AncestorAxisIterator(yy::location loc, Iterator_t input)
    :
    Batcher<AncestorAxisIterator>(loc),
    AxisIterator(input)
  {
  }

  ~AncestorAxisIterator() {}

public:
  Item_t nextImpl(IteratorTreeStateBlock& stateBlock);
  void resetImpl(IteratorTreeStateBlock& stateBlock);
  void releaseResourcesImpl(IteratorTreeStateBlock& stateBlock);

  std::ostream& _show(std::ostream& os) const;
};


/*******************************************************************************

********************************************************************************/
class AncestorSelfAxisIterator : public Batcher<AncestorSelfAxisIterator>,
                                 public AxisIterator
{
private:
  Item_t  theCurrentAnc;

public:
  AncestorSelfAxisIterator(yy::location loc, Iterator_t input)
    :
    Batcher<AncestorSelfAxisIterator>(loc),
    AxisIterator(input)
  {
  }

  ~AncestorSelfAxisIterator() {}

public:
  Item_t nextImpl(IteratorTreeStateBlock& stateBlock);
  void resetImpl(IteratorTreeStateBlock& stateBlock);
  void releaseResourcesImpl(IteratorTreeStateBlock& stateBlock);

  std::ostream& _show(std::ostream& os) const;
};


/*******************************************************************************

********************************************************************************/
class RSiblingAxisIterator : public Batcher<RSiblingAxisIterator>,
                             public AxisIterator
{
private:
  Iterator_t  theChildren;
#ifdef DEBUG
  Item_t      theRSibling;
#endif

public:
  RSiblingAxisIterator(yy::location loc, Iterator_t input)
    :
    Batcher<RSiblingAxisIterator>(loc),
    AxisIterator(input)
  {
  }

  ~RSiblingAxisIterator() {}

public:
  Item_t nextImpl(IteratorTreeStateBlock& stateBlock);
  void resetImpl(IteratorTreeStateBlock& stateBlock);
  void releaseResourcesImpl(IteratorTreeStateBlock& stateBlock);

  std::ostream& _show(std::ostream& os) const;
};


/*******************************************************************************

********************************************************************************/
class LSiblingAxisIterator : public Batcher<LSiblingAxisIterator>,
                             public AxisIterator
{
private:
  Iterator_t  theChildren;
#ifdef DEBUG
  Item_t      theLSibling;
#endif

public:
  LSiblingAxisIterator(yy::location loc, Iterator_t input)
    :
    Batcher<LSiblingAxisIterator>(loc),
    AxisIterator(input)
  {
  }

  ~LSiblingAxisIterator() {}

public:
  Item_t nextImpl(IteratorTreeStateBlock& stateBlock);
  void resetImpl(IteratorTreeStateBlock& stateBlock);
  void releaseResourcesImpl(IteratorTreeStateBlock& stateBlock);

  std::ostream& _show(std::ostream& os) const;
};


/*******************************************************************************

********************************************************************************/
class ChildAxisIterator : public Batcher<ChildAxisIterator>,
                          public AxisIterator
{
private:
  Iterator_t  theChildren;
#ifdef DEBUG
  Item_t      theCurrentChild;
#endif

public:
  ChildAxisIterator(yy::location loc, Iterator_t input)
    :
    Batcher<ChildAxisIterator>(loc),
    AxisIterator(input)
  {
  }

  ~ChildAxisIterator() {}

public:
  Item_t nextImpl(IteratorTreeStateBlock& stateBlock);
  void resetImpl(IteratorTreeStateBlock& stateBlock);
  void releaseResourcesImpl(IteratorTreeStateBlock& stateBlock);

  std::ostream& _show(std::ostream& os) const;
};


/*******************************************************************************

********************************************************************************/
class DescendantAxisIterator : public Batcher<DescendantAxisIterator>,
                               public AxisIterator
{
private:
  std::stack<std::pair<Item_t, Iterator_t> > theCurrentPath;
#ifdef DEBUG
  Item_t                                     theCurrentDesc;
#endif
public:
  DescendantAxisIterator(yy::location loc, Iterator_t input)
    :
    Batcher<DescendantAxisIterator>(loc),
    AxisIterator(input)
  {
  }

  ~DescendantAxisIterator() {}

public:
  Item_t nextImpl(IteratorTreeStateBlock& stateBlock);
  void resetImpl(IteratorTreeStateBlock& stateBlock);
  void releaseResourcesImpl(IteratorTreeStateBlock& stateBlock);

  std::ostream& _show(std::ostream& os) const;
};


/*******************************************************************************

********************************************************************************/
class DescendantSelfAxisIterator : public Batcher<DescendantSelfAxisIterator>,
                                   public AxisIterator
{
private:
  std::stack<std::pair<Item_t, Iterator_t> > theCurrentPath;
#ifdef DEBUG
  Item_t                                     theCurrentDesc;
#endif
public:
  DescendantSelfAxisIterator(yy::location loc, Iterator_t input)
    :
    Batcher<DescendantSelfAxisIterator>(loc),
    AxisIterator(input)
  {
  }

  ~DescendantSelfAxisIterator() {}

public:
  Item_t nextImpl(IteratorTreeStateBlock& stateBlock);
  void resetImpl(IteratorTreeStateBlock& stateBlock);
  void releaseResourcesImpl(IteratorTreeStateBlock& stateBlock);

  std::ostream& _show(std::ostream& os) const;
};


/*******************************************************************************

********************************************************************************/
class PrecedingAxisIterator : public Batcher<PrecedingAxisIterator>,
                              public AxisIterator
{
private:
  std::stack<Item_t>                         theAncestorPath;
  std::stack<std::pair<Item_t, Iterator_t> > theCurrentPath;
#ifdef DEBUG
  Item_t                                     theCurrentPrec;
#endif
public:
  PrecedingAxisIterator(yy::location loc, Iterator_t input)
    :
    Batcher<PrecedingAxisIterator>(loc),
    AxisIterator(input)
  {
  }

  ~PrecedingAxisIterator() {}

public:
  Item_t nextImpl(IteratorTreeStateBlock& stateBlock);
  void resetImpl(IteratorTreeStateBlock& stateBlock);
  void releaseResourcesImpl(IteratorTreeStateBlock& stateBlock);

  std::ostream& _show(std::ostream& os) const;
};


/*******************************************************************************

********************************************************************************/
class FollowingAxisIterator : public Batcher<FollowingAxisIterator>,
                              public AxisIterator
{
private:
  std::stack<Item_t>                         theAncestorPath;
  std::stack<std::pair<Item_t, Iterator_t> > theCurrentPath;
#ifdef DEBUG
  Item_t                                     theCurrentFollowing;
#endif
public:
  FollowingAxisIterator(yy::location loc, Iterator_t input)
    :
    Batcher<FollowingAxisIterator>(loc),
    AxisIterator(input)
  {
  }

  ~FollowingAxisIterator() {}

public:
  Item_t nextImpl(IteratorTreeStateBlock& stateBlock);
  void resetImpl(IteratorTreeStateBlock& stateBlock);
  void releaseResourcesImpl(IteratorTreeStateBlock& stateBlock);

  std::ostream& _show(std::ostream& os) const;
};


} /* namespace xqp */

#endif  /* XQP_PATH_ITERATORS_H */
