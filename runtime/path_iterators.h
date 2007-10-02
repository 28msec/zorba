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


#include "util/rchandle.h"
#include "exprtree/expr_consts.h"
#include "batching.h"
#include <stack>


namespace xqp {


/*******************************************************************************

********************************************************************************/
class NameTestIterator : public Batcher<NameTestIterator>
{
private:
  Iterator_t   theInput;
  Item_t       theQName;
  match_wild_t theWildKind;
#ifdef DEBUG
  Item_t       theContextNode;
#endif

public:
  NameTestIterator(yy::location loc, Iterator_t input, Item_t qname, match_wild_t kind)
    :
    Batcher<NameTestIterator>(loc),
    theInput(input),
    theQName(qname),
    theWildKind(kind)
  {
  }

  ~NameTestIterator() {}

public:
  Item_t nextImpl();
  void resetImpl();
  void releaseResourcesImpl();

  std::ostream& _show(std::ostream& os) const;
};


/*******************************************************************************

********************************************************************************/
class SelfIterator : public Batcher<SelfIterator>
{
private:
  Iterator_t  theInput;
  bool        thePrincipalNodeKind;
#ifdef DEBUG
  Item_t      theContextNode;
#endif

public:
  SelfIterator(yy::location loc, Iterator_t input)
    :
    Batcher<SelfIterator>(loc),
    theInput(input)
  {
  }

  ~SelfIterator() {}

public:
  Item_t nextImpl();
  void resetImpl();
  void releaseResourcesImpl();

  std::ostream& _show(std::ostream& os) const;
};


/*******************************************************************************

********************************************************************************/
class AttributeIterator : public Batcher<AttributeIterator>
{
private:
  Iterator_t  theInput;
  Iterator_t  theAttributes;
#ifdef DEBUG
  Item_t      theContextNode;
  Item_t      theCurrentAttr;
#endif

public:
  AttributeIterator(yy::location loc, Iterator_t input)
    :
    Batcher<AttributeIterator>(loc),
    theInput(input)
  {
  }

  ~AttributeIterator() {}

public:
  Item_t nextImpl();
  void resetImpl();
  void releaseResourcesImpl();

  std::ostream& _show(std::ostream& os) const;
};


/*******************************************************************************

********************************************************************************/
class ParentIterator : public Batcher<ParentIterator>
{
private:
  Iterator_t  theInput;
  bool        thePrincipalNodeKind;
#ifdef DEBUG
  Item_t      theContextNode;
  Item_t      theParent;
#endif

public:
  ParentIterator(yy::location loc, Iterator_t input)
    :
    Batcher<ParentIterator>(loc),
    theInput(input)
  {
  }

  ~ParentIterator() {}

public:
  Item_t nextImpl();
  void resetImpl();
  void releaseResourcesImpl();

  std::ostream& _show(std::ostream& os) const;
};


/*******************************************************************************

********************************************************************************/
class AncestorIterator : public Batcher<AncestorIterator>
{
private:
  Iterator_t  theInput;
  Item_t      theCurrentAnc;
  bool        thePrincipalNodeKind;
#ifdef DEBUG
  Item_t      theContextNode;
#endif

public:
  AncestorIterator(yy::location loc, Iterator_t input)
    :
    Batcher<AncestorIterator>(loc),
    theInput(input)
  {
  }

  ~AncestorIterator() {}

public:
  Item_t nextImpl();
  void resetImpl();
  void releaseResourcesImpl();

  std::ostream& _show(std::ostream& os) const;
};


/*******************************************************************************

********************************************************************************/
class AncestorSelfIterator : public Batcher<AncestorSelfIterator>
{
private:
  Iterator_t  theInput;
  Item_t      theCurrentAnc;
#ifdef DEBUG
  Item_t      theContextNode;
#endif

public:
  AncestorSelfIterator(yy::location loc, Iterator_t input)
    :
    Batcher<AncestorSelfIterator>(loc),
    theInput(input)
  {
  }

  ~AncestorSelfIterator() {}

public:
  Item_t nextImpl();
  void resetImpl();
  void releaseResourcesImpl();

  std::ostream& _show(std::ostream& os) const;
};


/*******************************************************************************

********************************************************************************/
class RSiblingIterator : public Batcher<RSiblingIterator>
{
private:
  Iterator_t  theInput;
  Iterator_t  theChildren;
  bool        thePrincipalNodeKind;
#ifdef DEBUG
  Item_t      theContextNode;
  Item_t      theRSibling;
#endif

public:
  RSiblingIterator(yy::location loc, Iterator_t input)
    :
    Batcher<RSiblingIterator>(loc),
    theInput(input)
  {
  }

  ~RSiblingIterator() {}

public:
  Item_t nextImpl();
  void resetImpl();
  void releaseResourcesImpl();

  std::ostream& _show(std::ostream& os) const;
};


/*******************************************************************************

********************************************************************************/
class LSiblingIterator : public Batcher<LSiblingIterator>
{
private:
  Iterator_t  theInput;
  Iterator_t  theChildren;
  bool        thePrincipalNodeKind;
#ifdef DEBUG
  Item_t      theContextNode;
  Item_t      theLSibling;
#endif

public:
  LSiblingIterator(yy::location loc, Iterator_t input)
    :
    Batcher<LSiblingIterator>(loc),
    theInput(input)
  {
  }

  ~LSiblingIterator() {}

public:
  Item_t nextImpl();
  void resetImpl();
  void releaseResourcesImpl();

  std::ostream& _show(std::ostream& os) const;
};


/*******************************************************************************

********************************************************************************/
class ChildIterator : public Batcher<ChildIterator>
{
private:
  Iterator_t  theInput;
  Iterator_t  theChildren;
  bool        thePrincipalNodeKind;
#ifdef DEBUG
  Item_t      theContextNode;
  Item_t      theCurrentChild;
#endif

public:
  ChildIterator(yy::location loc, Iterator_t input)
    :
    Batcher<ChildIterator>(loc),
    theInput(input)
  {
  }

  ~ChildIterator() {}

public:
  Item_t nextImpl();
  void resetImpl();
  void releaseResourcesImpl();

  std::ostream& _show(std::ostream& os) const;
};


/*******************************************************************************

********************************************************************************/
class DescendantIterator : public Batcher<DescendantIterator>
{
private:
  Iterator_t                                 theInput;
  std::stack<std::pair<Item_t, Iterator_t> > theCurrentPath;
#ifdef DEBUG
  Item_t                                     theContextNode;
  Item_t                                     theCurrentDesc;
#endif
public:
  DescendantIterator(yy::location loc, Iterator_t input)
    :
    Batcher<DescendantIterator>(loc),
    theInput(input)
  {
  }

  ~DescendantIterator() {}

public:
  Item_t nextImpl();
  void resetImpl();
  void releaseResourcesImpl();

  std::ostream& _show(std::ostream& os) const;
};


/*******************************************************************************

********************************************************************************/
class DescendantSelfIterator : public Batcher<DescendantSelfIterator>
{
private:
  Iterator_t                                 theInput;
  std::stack<std::pair<Item_t, Iterator_t> > theCurrentPath;
#ifdef DEBUG
  Item_t                                     theContextNode;
  Item_t                                     theCurrentDesc;
#endif
public:
  DescendantSelfIterator(yy::location loc, Iterator_t input)
    :
    Batcher<DescendantSelfIterator>(loc),
    theInput(input)
  {
  }

  ~DescendantSelfIterator() {}

public:
  Item_t nextImpl();
  void resetImpl();
  void releaseResourcesImpl();

  std::ostream& _show(std::ostream& os) const;
};


/*******************************************************************************

********************************************************************************/
class PrecedingIterator : public Batcher<PrecedingIterator>
{
private:
  Iterator_t                                 theInput;
  std::stack<Item_t>                         theAncestorPath;
  std::stack<std::pair<Item_t, Iterator_t> > theCurrentPath;
#ifdef DEBUG
  Item_t                                     theContextNode;
  Item_t                                     theCurrentPrec;
#endif
public:
  PrecedingIterator(yy::location loc, Iterator_t input)
    :
    Batcher<PrecedingIterator>(loc),
    theInput(input)
  {
  }

  ~PrecedingIterator() {}

public:
  Item_t nextImpl();
  void resetImpl();
  void releaseResourcesImpl();

  std::ostream& _show(std::ostream& os) const;
};


/*******************************************************************************

********************************************************************************/
class FollowingIterator : public Batcher<FollowingIterator>
{
private:
  Iterator_t                                 theInput;
  std::stack<Item_t>                         theAncestorPath;
  std::stack<std::pair<Item_t, Iterator_t> > theCurrentPath;
#ifdef DEBUG
  Item_t                                     theContextNode;
  Item_t                                     theCurrentFollowing;
#endif
public:
  FollowingIterator(yy::location loc, Iterator_t input)
    :
    Batcher<FollowingIterator>(loc),
    theInput(input)
  {
  }

  ~FollowingIterator() {}

public:
  Item_t nextImpl();
  void resetImpl();
  void releaseResourcesImpl();

  std::ostream& _show(std::ostream& os) const;
};


} /* namespace xqp */

#endif  /* XQP_PATH_ITERATORS_H */
