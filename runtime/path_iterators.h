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
  Item_t       theContextNode;
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
  Item_t nextImpl(int8_t* stateBlock);
  void resetImpl(int8_t* stateBlock);
  void releaseResourcesImpl(int8_t* stateBlock);

  std::ostream& _show(std::ostream& os) const;
};


/*******************************************************************************

********************************************************************************/
class SelfAxisIterator : public Batcher<SelfAxisIterator>
{
private:
  Iterator_t  theInput;
  Item_t      theContextNode;
  bool        thePrincipalNodeKind;

public:
  SelfAxisIterator(yy::location loc, Iterator_t input)
    :
    Batcher<SelfAxisIterator>(loc),
    theInput(input),
    thePrincipalNodeKind(false)
  {
  }

  ~SelfAxisIterator() {}

public:
  Item_t nextImpl(int8_t* stateBlock);
  void resetImpl(int8_t* stateBlock);
  void releaseResourcesImpl(int8_t* stateBlock);

  std::ostream& _show(std::ostream& os) const;

  void setPrincipalNodeKind(bool v) { thePrincipalNodeKind = v; }
};


/*******************************************************************************

********************************************************************************/
class AttributeAxisIterator : public Batcher<AttributeAxisIterator>
{
private:
  Iterator_t  theInput;
  Iterator_t  theAttributes;
  Item_t      theContextNode;
#ifdef DEBUG
  Item_t      theCurrentAttr;
#endif

public:
  AttributeAxisIterator(yy::location loc, Iterator_t input)
    :
    Batcher<AttributeAxisIterator>(loc),
    theInput(input)
  {
  }

  ~AttributeAxisIterator() {}

public:
  Item_t nextImpl(int8_t* stateBlock);
  void resetImpl(int8_t* stateBlock);
  void releaseResourcesImpl(int8_t* stateBlock);

  std::ostream& _show(std::ostream& os) const;
};


/*******************************************************************************

********************************************************************************/
class ParentAxisIterator : public Batcher<ParentAxisIterator>
{
private:
  Iterator_t  theInput;
  Item_t      theContextNode;
  bool        thePrincipalNodeKind;
#ifdef DEBUG
  Item_t      theParent;
#endif

public:
  ParentAxisIterator(yy::location loc, Iterator_t input)
    :
    Batcher<ParentAxisIterator>(loc),
    theInput(input),
    thePrincipalNodeKind(false)
  {
  }

  ~ParentAxisIterator() {}

public:
  Item_t nextImpl(int8_t* stateBlock);
  void resetImpl(int8_t* stateBlock);
  void releaseResourcesImpl(int8_t* stateBlock);

  std::ostream& _show(std::ostream& os) const;

  void setPrincipalNodeKind(bool v) { thePrincipalNodeKind = v; }
};


/*******************************************************************************

********************************************************************************/
class AncestorAxisIterator : public Batcher<AncestorAxisIterator>
{
private:
  Iterator_t  theInput;
  Item_t      theContextNode;
  Item_t      theCurrentAnc;
  bool        thePrincipalNodeKind;

public:
  AncestorAxisIterator(yy::location loc, Iterator_t input)
    :
    Batcher<AncestorAxisIterator>(loc),
    theInput(input),
    thePrincipalNodeKind(false)
  {
  }

  ~AncestorAxisIterator() {}

public:
  Item_t nextImpl(int8_t* stateBlock);
  void resetImpl(int8_t* stateBlock);
  void releaseResourcesImpl(int8_t* stateBlock);

  std::ostream& _show(std::ostream& os) const;

  void setPrincipalNodeKind(bool v) { thePrincipalNodeKind = v; }
};


/*******************************************************************************

********************************************************************************/
class AncestorSelfAxisIterator : public Batcher<AncestorSelfAxisIterator>
{
private:
  Iterator_t  theInput;
  Item_t      theContextNode;
  Item_t      theCurrentAnc;
  bool        thePrincipalNodeKind;

public:
  AncestorSelfAxisIterator(yy::location loc, Iterator_t input)
    :
    Batcher<AncestorSelfAxisIterator>(loc),
    theInput(input),
    thePrincipalNodeKind(false)
  {
  }

  ~AncestorSelfAxisIterator() {}

public:
  Item_t nextImpl(int8_t* stateBlock);
  void resetImpl(int8_t* stateBlock);
  void releaseResourcesImpl(int8_t* stateBlock);

  std::ostream& _show(std::ostream& os) const;

  void setPrincipalNodeKind(bool v) { thePrincipalNodeKind = v; }
};


/*******************************************************************************

********************************************************************************/
class RSiblingAxisIterator : public Batcher<RSiblingAxisIterator>
{
private:
  Iterator_t  theInput;
  Iterator_t  theChildren;
  Item_t      theContextNode;
  bool        thePrincipalNodeKind;
#ifdef DEBUG
  Item_t      theRSibling;
#endif

public:
  RSiblingAxisIterator(yy::location loc, Iterator_t input)
    :
    Batcher<RSiblingAxisIterator>(loc),
    theInput(input),
    thePrincipalNodeKind(false)
  {
  }

  ~RSiblingAxisIterator() {}

public:
  Item_t nextImpl(int8_t* stateBlock);
  void resetImpl(int8_t* stateBlock);
  void releaseResourcesImpl(int8_t* stateBlock);

  std::ostream& _show(std::ostream& os) const;

  void setPrincipalNodeKind(bool v) { thePrincipalNodeKind = v; }
};


/*******************************************************************************

********************************************************************************/
class LSiblingAxisIterator : public Batcher<LSiblingAxisIterator>
{
private:
  Iterator_t  theInput;
  Iterator_t  theChildren;
  Item_t      theContextNode;
  bool        thePrincipalNodeKind;
#ifdef DEBUG
  Item_t      theLSibling;
#endif

public:
  LSiblingAxisIterator(yy::location loc, Iterator_t input)
    :
    Batcher<LSiblingAxisIterator>(loc),
    theInput(input),
    thePrincipalNodeKind(false)
  {
  }

  ~LSiblingAxisIterator() {}

public:
  Item_t nextImpl(int8_t* stateBlock);
  void resetImpl(int8_t* stateBlock);
  void releaseResourcesImpl(int8_t* stateBlock);

  std::ostream& _show(std::ostream& os) const;

  void setPrincipalNodeKind(bool v) { thePrincipalNodeKind = v; }
};


/*******************************************************************************

********************************************************************************/
class ChildAxisIterator : public Batcher<ChildAxisIterator>
{
private:
  Iterator_t  theInput;
  Iterator_t  theChildren;
  Item_t      theContextNode;
  bool        thePrincipalNodeKind;
#ifdef DEBUG
  Item_t      theCurrentChild;
#endif

public:
  ChildAxisIterator(yy::location loc, Iterator_t input)
    :
    Batcher<ChildAxisIterator>(loc),
    theInput(input),
    thePrincipalNodeKind(false)
  {
  }

  ~ChildAxisIterator() {}

public:
  Item_t nextImpl(int8_t* stateBlock);
  void resetImpl(int8_t* stateBlock);
  void releaseResourcesImpl(int8_t* stateBlock);

  std::ostream& _show(std::ostream& os) const;

  void setPrincipalNodeKind(bool v) { thePrincipalNodeKind = v; }
};


/*******************************************************************************

********************************************************************************/
class DescendantAxisIterator : public Batcher<DescendantAxisIterator>
{
private:
  Iterator_t                                 theInput;
  Item_t                                     theContextNode;
  std::stack<std::pair<Item_t, Iterator_t> > theCurrentPath;
  bool                                       thePrincipalNodeKind;
#ifdef DEBUG
  Item_t                                     theCurrentDesc;
#endif
public:
  DescendantAxisIterator(yy::location loc, Iterator_t input)
    :
    Batcher<DescendantAxisIterator>(loc),
    theInput(input),
    thePrincipalNodeKind(false)
  {
  }

  ~DescendantAxisIterator() {}

public:
  Item_t nextImpl(int8_t* stateBlock);
  void resetImpl(int8_t* stateBlock);
  void releaseResourcesImpl(int8_t* stateBlock);

  std::ostream& _show(std::ostream& os) const;

  void setPrincipalNodeKind(bool v) { thePrincipalNodeKind = v; }
};


/*******************************************************************************

********************************************************************************/
class DescendantSelfAxisIterator : public Batcher<DescendantSelfAxisIterator>
{
private:
  Iterator_t                                 theInput;
  Item_t                                     theContextNode;
  std::stack<std::pair<Item_t, Iterator_t> > theCurrentPath;
  bool                                       thePrincipalNodeKind;
#ifdef DEBUG
  Item_t                                     theCurrentDesc;
#endif
public:
  DescendantSelfAxisIterator(yy::location loc, Iterator_t input)
    :
    Batcher<DescendantSelfAxisIterator>(loc),
    theInput(input),
    thePrincipalNodeKind(false)
  {
  }

  ~DescendantSelfAxisIterator() {}

public:
  Item_t nextImpl(int8_t* stateBlock);
  void resetImpl(int8_t* stateBlock);
  void releaseResourcesImpl(int8_t* stateBlock);

  std::ostream& _show(std::ostream& os) const;

  void setPrincipalNodeKind(bool v) { thePrincipalNodeKind = v; }
};


/*******************************************************************************

********************************************************************************/
class PrecedingAxisIterator : public Batcher<PrecedingAxisIterator>
{
private:
  Iterator_t                                 theInput;
  Item_t                                     theContextNode;
  std::stack<Item_t>                         theAncestorPath;
  std::stack<std::pair<Item_t, Iterator_t> > theCurrentPath;
  bool                                       thePrincipalNodeKind;
#ifdef DEBUG
  Item_t                                     theCurrentPrec;
#endif
public:
  PrecedingAxisIterator(yy::location loc, Iterator_t input)
    :
    Batcher<PrecedingAxisIterator>(loc),
    theInput(input),
    thePrincipalNodeKind(false)
  {
  }

  ~PrecedingAxisIterator() {}

public:
  Item_t nextImpl(int8_t* stateBlock);
  void resetImpl(int8_t* stateBlock);
  void releaseResourcesImpl(int8_t* stateBlock);

  std::ostream& _show(std::ostream& os) const;

  void setPrincipalNodeKind(bool v) { thePrincipalNodeKind = v; }
};


/*******************************************************************************

********************************************************************************/
class FollowingAxisIterator : public Batcher<FollowingAxisIterator>
{
private:
  Iterator_t                                 theInput;
  Item_t                                     theContextNode;
  std::stack<Item_t>                         theAncestorPath;
  std::stack<std::pair<Item_t, Iterator_t> > theCurrentPath;
  bool                                       thePrincipalNodeKind;
#ifdef DEBUG
  Item_t                                     theCurrentFollowing;
#endif
public:
  FollowingAxisIterator(yy::location loc, Iterator_t input)
    :
    Batcher<FollowingAxisIterator>(loc),
    theInput(input),
    thePrincipalNodeKind(false)
  {
  }

  ~FollowingAxisIterator() {}

public:
  Item_t nextImpl(int8_t* stateBlock);
  void resetImpl(int8_t* stateBlock);
  void releaseResourcesImpl(int8_t* stateBlock);

  std::ostream& _show(std::ostream& os) const;

  void setPrincipalNodeKind(bool v) { thePrincipalNodeKind = v; }
};


} /* namespace xqp */

#endif  /* XQP_PATH_ITERATORS_H */
