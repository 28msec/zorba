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

#include "util/Assert.h"
#include "store/api/item.h"
#include "path_iterators.h"


#define MYTRACE(msg) \
{\
  cout << __PRETTY_FUNCTION__ << ":" << __LINE__ << "  " << msg << endl; \
}


namespace xqp
{


/*******************************************************************************

********************************************************************************/
Item_t NameTestIterator::nextImpl()
{
  while (true)
  {
    theContextNode = consumeNext(theInput);
    if (theContextNode == NULL)
      return NULL;

    switch (theWildKind)
    {
    case match_no_wild:
    {
      if (theQName->equals(theContextNode->getNodeName()))
        return theContextNode;

      break;
    }
    case match_all_wild:
    {
      return theContextNode;
    }
    case match_prefix_wild:
    {
      if (theQName->getLocalName() == theContextNode->getNodeName()->getLocalName())
        return theContextNode;

      break;
    }
    case match_name_wild:
    {
      if (theQName->getNamespace() == theContextNode->getNodeName()->getPrefix())
        return theContextNode;

      break;
    }
    default:
      ZorbaErrorAlerts::error_alert(
         error_messages::XQP0014_SYSTEM_SHOUD_NEVER_BE_REACHED,
         error_messages::SYSTEM_ERROR,
         NULL,
         false,
         "Unknown name test kind");
    }
  }

  return NULL;
}


void NameTestIterator::resetImpl()
{
  resetChild(theInput);
}


void NameTestIterator::releaseResourcesImpl()
{
  releaseChildResources(theInput);
  theQName = NULL;
  theContextNode = NULL;
}


std::ostream& NameTestIterator::_show(std::ostream& os)	const
{
  os << IT_DEPTH << " " << "context node: " << std::endl;
  if (theContextNode != NULL)
    os << IT_DEPTH << " " << theContextNode->show() << std::endl;

  if (theQName != NULL)
    os << IT_DEPTH << " " << "qname: " << theQName->show() << std::endl;
  else
    os << IT_DEPTH << " " << "qname: *" << endl;

  theInput->show(os);
  return os;
}


/*******************************************************************************

********************************************************************************/
Item_t SelfAxisIterator::nextImpl()
{
  do
  {
    theContextNode = consumeNext(theInput);
  }
  while (theContextNode != NULL &&
         thePrincipalNodeKind &&
         theContextNode->getNodeKind() != elementNode);

  return theContextNode;
}


void SelfAxisIterator::resetImpl()
{
  resetChild(theInput);
}


void SelfAxisIterator::releaseResourcesImpl()
{
  releaseChildResources(theInput);
  theContextNode = NULL;
}


std::ostream& SelfAxisIterator::_show(std::ostream& os)	const
{
  os << IT_DEPTH << " " << "context node: " << std::endl;
  if (theContextNode != NULL)
    os << IT_DEPTH << " " << theContextNode->show() << std::endl;

  theInput->show(os);
  return os;
}


/*******************************************************************************

********************************************************************************/
Item_t AttributeAxisIterator::nextImpl()
{
  Item_t attr;

  STACK_INIT();

  while (true)
  {
    do
    {
      theContextNode = consumeNext(theInput);
      if (theContextNode == NULL)
        return NULL;
    }
    while (theContextNode->getNodeKind() != elementNode);

    theAttributes = theContextNode->getAttributes();

    attr = consumeNext(theAttributes);

    while (attr != NULL)
    {
#ifdef DEBUG
      theCurrentAttr = attr;
#endif
      STACK_PUSH(attr);
      attr = consumeNext(theAttributes);
    }
  }

  STACK_END();
}


void AttributeAxisIterator::resetImpl()
{
  resetChild(theInput);
#ifdef DEBUG
  theCurrentAttr = NULL;
#endif
}


void AttributeAxisIterator::releaseResourcesImpl()
{
  releaseChildResources(theInput);
  theAttributes = NULL;
  theContextNode = NULL;
#ifdef DEBUG
  theCurrentAttr = NULL;
#endif
}


std::ostream& AttributeAxisIterator::_show(std::ostream& os)	const
{
  os << IT_DEPTH << " " << "context node: " << std::endl;
  if (theContextNode != NULL)
    os << IT_DEPTH << " " << theContextNode->show() << std::endl;

#ifdef DEBUG
  os << IT_DEPTH << " " << "current attr: "<< std::endl;
  if (theCurrentAttr != NULL)
    os << IT_DEPTH << " " << theCurrentAttr->show() << std::endl;
#endif

  theAttributes->show(os);
  theInput->show(os);
  return os;
}


/*******************************************************************************

********************************************************************************/
Item_t ParentAxisIterator::nextImpl()
{
  Item_t parent;

  do
  {
    theContextNode = consumeNext(theInput);
    if (theContextNode == NULL)
      return NULL;

    parent = theContextNode->getParent();
  }
  while (parent != NULL &&
         thePrincipalNodeKind && parent->getNodeKind() != elementNode);

#ifdef DEBUG
  theParent = parent;
#endif
  return parent;
}


void ParentAxisIterator::resetImpl()
{
  resetChild(theInput);
#ifdef DEBUG
  theParent = NULL;
#endif
}


void ParentAxisIterator::releaseResourcesImpl()
{
  releaseChildResources(theInput);
  theContextNode = NULL;
#ifdef DEBUG
  theParent = NULL;
#endif
}


std::ostream& ParentAxisIterator::_show(std::ostream& os)	const
{
  os << IT_DEPTH << " " << "context node: " << std::endl;
  if (theContextNode != NULL)
    os << IT_DEPTH << " " << theContextNode->show() << std::endl;

#ifdef DEBUG
  os << IT_DEPTH << " " << "parent node: " << std::endl;
  if (theParent != NULL)
    os << IT_DEPTH << " " << theParent->show() << std::endl;
#endif
  theInput->show(os);
  return os;
}


/*******************************************************************************

********************************************************************************/
Item_t AncestorAxisIterator::nextImpl()
{
  STACK_INIT();

  while (true)
  {
    theContextNode = consumeNext(theInput);
    if (theContextNode == NULL)
      return NULL;

    theCurrentAnc = theContextNode->getParent();

    while (theCurrentAnc != NULL)
    {
      if (!thePrincipalNodeKind || theCurrentAnc->getNodeKind() == elementNode)
      {
        STACK_PUSH(theCurrentAnc);
      }

      theCurrentAnc = theCurrentAnc->getParent();
    }
  }

  STACK_END();
}


void AncestorAxisIterator::resetImpl()
{
  resetChild(theInput);
}


void AncestorAxisIterator::releaseResourcesImpl()
{
  releaseChildResources(theInput);
  theCurrentAnc = NULL;
  theContextNode = NULL;
}


std::ostream& AncestorAxisIterator::_show(std::ostream& os)	const
{
  os << IT_DEPTH << " " << "context node: " << std::endl;
  if (theContextNode != NULL)
    os << IT_DEPTH << " " << theContextNode->show() << std::endl;

  os << IT_DEPTH << " " << "ancestor node: " << std::endl;
  if (theCurrentAnc != NULL)
    os << IT_DEPTH << " " << theCurrentAnc->show() << std::endl;

  theInput->show(os);
  return os;
}


/*******************************************************************************

********************************************************************************/
Item_t AncestorSelfAxisIterator::nextImpl()
{
  STACK_INIT();

  while (true)
  {
    theContextNode = consumeNext(theInput);
    if (theContextNode == NULL)
      return NULL;

    theCurrentAnc = theContextNode;

    while (theCurrentAnc != NULL)
    {
      if (!thePrincipalNodeKind || theCurrentAnc->getNodeKind() == elementNode)
      {
        STACK_PUSH(theCurrentAnc);
      }

      theCurrentAnc = theCurrentAnc->getParent();
    }
  }

  STACK_END();
}


void AncestorSelfAxisIterator::resetImpl()
{
  resetChild(theInput);
}


void AncestorSelfAxisIterator::releaseResourcesImpl()
{
  releaseChildResources(theInput);
  theCurrentAnc = NULL;
  theContextNode = NULL;
}


std::ostream& AncestorSelfAxisIterator::_show(std::ostream& os)	const
{
  os << IT_DEPTH << " " << "context node: " << std::endl;
  if (theContextNode != NULL)
    os << IT_DEPTH << " " << theContextNode->show() << std::endl;

  os << IT_DEPTH << " " << "ancestor node: " << std::endl;
  if (theCurrentAnc != NULL)
    os << IT_DEPTH << " " << theCurrentAnc->show() << std::endl;

  theInput->show(os);
  return os;
}


/*******************************************************************************

********************************************************************************/
Item_t RSiblingAxisIterator::nextImpl()
{
  Item_t parent;
  Item_t sibling;

  STACK_INIT();

  while (true)
  {
    do
    {
      theContextNode = consumeNext(theInput);
      if (theContextNode == NULL)
        return NULL;
    }
    while (theContextNode->getNodeKind() == attributeNode);

    parent = theContextNode->getParent();

    if (parent == NULL)
      return NULL;

    theChildren = parent->getChildren();

    while (theChildren->next() != theContextNode) ;

    sibling = theChildren->next();

    while (sibling != NULL)
    {
      if (!thePrincipalNodeKind || sibling->getNodeKind() == elementNode)
      {
#ifdef DEBUG
        theRSibling = sibling;
#endif
        STACK_PUSH(sibling);
      }

      sibling = theChildren->next();
    }
  }

  STACK_END();
}


void RSiblingAxisIterator::resetImpl()
{
  resetChild(theInput);
#ifdef DEBUG
  theRSibling = NULL;
#endif
}


void RSiblingAxisIterator::releaseResourcesImpl()
{
  releaseChildResources(theInput);
  theChildren = NULL; 
  theContextNode = NULL;
#ifdef DEBUG
  theRSibling = NULL;
#endif
}


std::ostream& RSiblingAxisIterator::_show(std::ostream& os)	const
{
  os << IT_DEPTH << " " << "context node: " << std::endl;
  if (theContextNode != NULL)
    os << IT_DEPTH << " " << theContextNode->show() << std::endl;

#ifdef DEBUG
  os << IT_DEPTH << " " << "rsibling node: " << std::endl;
  if (theRSibling != NULL)
    os << IT_DEPTH << " " << theRSibling->show() << std::endl;
#endif
  theInput->show(os);
  return os;
}


/*******************************************************************************

********************************************************************************/
Item_t LSiblingAxisIterator::nextImpl()
{
  Item_t parent;
  Item_t sibling;

  STACK_INIT();

  while (true)
  {
    do
    {
      theContextNode = consumeNext(theInput);
      if (theContextNode == NULL)
        return NULL;
    }
    while (theContextNode->getNodeKind() == attributeNode);

    parent = theContextNode->getParent();

    if (parent == NULL)
      return NULL;

    theChildren = parent->getChildren();

    sibling = theChildren->next();

    while (sibling != theContextNode)
    {
      if (!thePrincipalNodeKind || sibling->getNodeKind() == elementNode)
      {
#ifdef DEBUG
        theLSibling = sibling;
#endif
        STACK_PUSH(sibling);
      }

      sibling = theChildren->next();
    }
  }

  STACK_END();
}


void LSiblingAxisIterator::resetImpl()
{
  resetChild(theInput);
#ifdef DEBUG
  theLSibling = NULL;
#endif
}


void LSiblingAxisIterator::releaseResourcesImpl()
{
  releaseChildResources(theInput);
  theChildren = NULL;
  theContextNode = NULL;
#ifdef DEBUG
  theLSibling = NULL;
#endif
}


std::ostream& LSiblingAxisIterator::_show(std::ostream& os)	const
{
  os << IT_DEPTH << " " << "context node: " << std::endl;
  if (theContextNode != NULL)
    os << IT_DEPTH << " " << theContextNode->show() << std::endl;

#ifdef DEBUG
  os << IT_DEPTH << " " << "lsibling node: " << std::endl;
  if (theLSibling != NULL)
    os << IT_DEPTH << " " << theLSibling->show() << std::endl;
#endif
  theInput->show(os);
  return os;
}


/*******************************************************************************

********************************************************************************/
Item_t ChildAxisIterator::nextImpl()
{
  Item_t child;

  STACK_INIT();

  while (true)
  {
    do
    {
      theContextNode = consumeNext(theInput);
      if (theContextNode == NULL)
        return NULL;
    }
    while (theContextNode->getNodeKind() != elementNode &&
           theContextNode->getNodeKind() != documentNode);

    theChildren = theContextNode->getChildren();

    child = consumeNext(theChildren);

    while (child != NULL)
    {
      /*
      cout << "ite = " << this << " node = " << &*child
           << " is node child = " << child->isNode();
      if (child->isNode())
        cout << " node kind = "
             << sequence_type::describe(child->getNodeKind()) << endl;
      else
        cout << endl;
      */
      if (!thePrincipalNodeKind || child->getNodeKind() == elementNode)
      {
#ifdef DEBUG
        theCurrentChild = child;
#endif
        STACK_PUSH(child);
      }

      child = consumeNext(theChildren);
    }
  }

  STACK_END();
}


void ChildAxisIterator::resetImpl()
{
  resetChild(theInput);
#ifdef DEBUG
  theCurrentCild = NULL;
#endif
}


void ChildAxisIterator::releaseResourcesImpl()
{
  releaseChildResources(theInput);
  theChildren = NULL; 
  theContextNode = NULL;
#ifdef DEBUG
  theCurrentChild = NULL;
#endif
}


std::ostream& ChildAxisIterator::_show(std::ostream& os)	const
{
  os << IT_DEPTH << " " << "context node: " << std::endl;
  if (theContextNode != NULL)
    os << IT_DEPTH << " " << theContextNode->show() << std::endl;

#ifdef DEBUG
  os << IT_DEPTH << " " << "current child: " << std::endl;
  if (theCurrentChild != NULL)
    os << IT_DEPTH << " " << theCurrentChild->show() << std::endl;
#endif
  theInput->show(os);
  return os;
}


/*******************************************************************************

********************************************************************************/
Item_t DescendantAxisIterator::nextImpl()
{
  Item_t desc;
  Iterator_t children;

  STACK_INIT();

  while (true)
  {
    do
    {
      theContextNode = theInput->next();
      if (theContextNode == NULL)
        return NULL;
    }
    while (theContextNode->getNodeKind() != elementNode &&
           theContextNode->getNodeKind() != documentNode);

    MYTRACE("iter = " << this << " ctxNode = [" << &*theContextNode << " " << theContextNode->getNodeName()->show() << "]");

    children = theContextNode->getChildren();

    theCurrentPath.push(std::pair<Item_t, Iterator_t>(theContextNode, children));
    
    desc = children->next();

    while (desc != NULL)
    {
      if (desc->getNodeKind() == elementNode)
        theCurrentPath.push(std::pair<Item_t, Iterator_t>(desc, desc->getChildren()));

      if (!thePrincipalNodeKind || desc->getNodeKind() == elementNode)
      {
#ifdef DEBUG
        theCurrentDesc = desc;
#endif
        STACK_PUSH(desc);
      }

      // The next descendant is the next child of the node N that is currently
      // at the top of the path stack. If N has no children or all of its
      // children have been processed already, N is removed from the stack
      // and the process is repeated.
      desc = theCurrentPath.top().second->next();

      while (desc == NULL)
      {
        theCurrentPath.pop();
        if (!theCurrentPath.empty())
          desc = theCurrentPath.top().second->next();
        else
          break;
      }
    }
  }

  STACK_END();
}


void DescendantAxisIterator::resetImpl()
{
  resetChild(theInput);

  while (!theCurrentPath.empty())
  {
    theCurrentPath.pop();
  }
#ifdef DEBUG
  theCurrentDesc = NULL;
#endif
}


void DescendantAxisIterator::releaseResourcesImpl()
{
  releaseChildResources(theInput);

  while (!theCurrentPath.empty())
  {
    theCurrentPath.pop();
  }

  theContextNode = NULL;

#ifdef DEBUG
  theCurrentDesc = NULL;
#endif
}


std::ostream& DescendantAxisIterator::_show(std::ostream& os)	const
{
  os << IT_DEPTH << " " << "context node: " << std::endl;
  if (theContextNode != NULL)
    os << IT_DEPTH << " " << theContextNode->show() << std::endl;

#ifdef DEBUG
  os << IT_DEPTH << " " << "current descendant: " << std::endl;
  if (theCurrentDesc != NULL)
    os << IT_DEPTH << " " << theCurrentDesc->show() << std::endl;
#endif
  theInput->show(os);
  return os;
}


/*******************************************************************************

********************************************************************************/
Item_t DescendantSelfAxisIterator::nextImpl()
{
  Item_t desc;

  STACK_INIT();

  while (true)
  {
    do
    {
      theContextNode = consumeNext(theInput);
      if (theContextNode == NULL)
        return NULL;
    }
    while (theContextNode->getNodeKind() != elementNode &&
           theContextNode->getNodeKind() != documentNode);

    desc = theContextNode;

    while (desc != NULL)
    {
      if (desc->getNodeKind() == elementNode ||
          theContextNode->getNodeKind() == documentNode)
        theCurrentPath.push(std::pair<Item_t, Iterator_t>(desc, desc->getChildren()));

      if (!thePrincipalNodeKind || desc->getNodeKind() == elementNode)
      {
#ifdef DEBUG
        theCurrentDesc = desc;
#endif
        STACK_PUSH(desc);
      }

      // The next descendant is the next child of the node N that is currently
      // at the top of the path stack. If N has no children or all of its
      // children have been processed already, N is removed from the stack
      // and the process is repeated.
      desc = theCurrentPath.top().second->next();

      while (desc == NULL)
      {
        theCurrentPath.pop();
        if (!theCurrentPath.empty())
          desc = theCurrentPath.top().second->next();
        else
          break;
      }
    }
  }

  STACK_END();
}


void DescendantSelfAxisIterator::resetImpl()
{
  resetChild(theInput);

  while (!theCurrentPath.empty())
  {
    theCurrentPath.pop();
  }
#ifdef DEBUG
  theCurrentDesc = NULL;
#endif
}


void DescendantSelfAxisIterator::releaseResourcesImpl()
{
  releaseChildResources(theInput);

  while (!theCurrentPath.empty())
  {
    theCurrentPath.pop();
  }

  theContextNode = NULL;

#ifdef DEBUG
  theCurrentDesc = NULL;
#endif
}


std::ostream& DescendantSelfAxisIterator::_show(std::ostream& os)	const
{
  os << IT_DEPTH << " " << "context node: " << std::endl;
  if (theContextNode != NULL)
    os << IT_DEPTH << " " << theContextNode->show() << std::endl;

#ifdef DEBUG
  os << IT_DEPTH << " " << "current descendant: " << std::endl;
  if (theCurrentDesc != NULL)
    os << IT_DEPTH << " " << theCurrentDesc->show() << std::endl;
#endif
  theInput->show(os);
  return os;
}


/*******************************************************************************

********************************************************************************/
Item_t PrecedingAxisIterator::nextImpl()
{
  Item_t ancestor;
  Item_t desc;
  Iterator_t children;

  STACK_INIT();

  while (true)
  {
    theContextNode = consumeNext(theInput);
    if (theContextNode == NULL)
      return NULL;

    // Collect the context node and its ancestors
    ancestor = theContextNode;
    theAncestorPath.push(ancestor);

    while (ancestor != NULL)
    {
      theAncestorPath.push(ancestor);
      ancestor = ancestor->getParent();
    }

    // For each ancestor N (starting from the top) return its descendants,
    // up to the point where the next ancestor M is reached (M is a child
    // of N). Then repeat the process with the subtree rooted at M. 
    while (theAncestorPath.size() > 1)
    {
      ancestor = theAncestorPath.top();

      theAncestorPath.pop();

      children = ancestor->getChildren();

      theCurrentPath.push(std::pair<Item_t, Iterator_t>(ancestor, children));
    
      desc = children->next();

      while (desc != theAncestorPath.top())
      {
        if (desc->getNodeKind() == elementNode)
          theCurrentPath.push(std::pair<Item_t, Iterator_t>(desc, desc->getChildren()));

        if (!thePrincipalNodeKind || desc->getNodeKind() == elementNode)
        {
#ifdef DEBUG
          theCurrentPrec = desc;
#endif
          STACK_PUSH(desc);
        }

        desc = theCurrentPath.top().second->next();

        while (desc == NULL)
        {
          theCurrentPath.pop();
          Assert(!theCurrentPath.empty());
          desc = theCurrentPath.top().second->next();
        }
      }

      theCurrentPath.pop();
      theCurrentPath.pop();
      Assert(theCurrentPath.empty());
    }
  }

  STACK_END();
}


void PrecedingAxisIterator::resetImpl()
{
  resetChild(theInput);

  while (!theCurrentPath.empty())
    theCurrentPath.pop();

  while (!theAncestorPath.empty())
    theAncestorPath.pop();

#ifdef DEBUG
  theCurrentPrec = NULL;
#endif
}


void PrecedingAxisIterator::releaseResourcesImpl()
{
  releaseChildResources(theInput);

  while (!theCurrentPath.empty())
    theCurrentPath.pop();

  while (!theAncestorPath.empty())
    theAncestorPath.pop();

  theContextNode = NULL;

#ifdef DEBUG
  theCurrentPrec = NULL;
#endif
}


std::ostream& PrecedingAxisIterator::_show(std::ostream& os)	const
{
  os << IT_DEPTH << " " << "context node: " << std::endl;
  if (theContextNode != NULL)
    os << IT_DEPTH << " " << theContextNode->show() << std::endl;

#ifdef DEBUG
  os << IT_DEPTH << " " << "preceding node: " << std::endl;
  if (theCurrentPrec != NULL)
    os << IT_DEPTH << " " << theCurrentPrec->show() << std::endl;
#endif
  theInput->show(os);
  return os;
}


/*******************************************************************************

********************************************************************************/
Item_t FollowingAxisIterator::nextImpl()
{
  Item_t ancestor;
  Item_t following;
  Iterator_t children;

  STACK_INIT();

  while (true)
  {
    theContextNode = consumeNext(theInput);
    if (theContextNode == NULL)
      return NULL;

    // Collect the context node and its ancestors
    ancestor = theContextNode;
    theAncestorPath.push(ancestor);

    while (ancestor != NULL)
    {
      theAncestorPath.push(ancestor);
      ancestor = ancestor->getParent();
    }

    // For each ancestor N (starting from the top) return its descendants,
    // starting from the rsibling of next ancestor M (M is a child of N).
    // Then repeat the process with the subtree rooted at M. 
    while (theAncestorPath.size() > 1)
    {
      ancestor = theAncestorPath.top();

      theAncestorPath.pop();

      children = ancestor->getChildren();

      theCurrentPath.push(std::pair<Item_t, Iterator_t>(ancestor, children));

      do
      {
        following = children->next();
      }
      while (following != theAncestorPath.top());

      following = children->next();

      while (following != NULL)
      {
        if (following->getNodeKind() == elementNode)
          theCurrentPath.push(std::pair<Item_t, Iterator_t>(following, following->getChildren()));

        if (!thePrincipalNodeKind || following->getNodeKind() == elementNode)
        {
#ifdef DEBUG
          theCurrentFollowing = following;
#endif
          STACK_PUSH(following);
        }

        following = theCurrentPath.top().second->next();

        while (following == NULL)
        {
          theCurrentPath.pop();
          Assert(!theCurrentPath.empty());
          following = theCurrentPath.top().second->next();
        }
      }

      theCurrentPath.pop();
      Assert(theCurrentPath.empty());
    }
  }

  STACK_END();
}


void FollowingAxisIterator::resetImpl()
{
  resetChild(theInput);

  while (!theCurrentPath.empty())
    theCurrentPath.pop();

  while (!theAncestorPath.empty())
    theAncestorPath.pop();

  theContextNode = NULL;

#ifdef DEBUG
  theCurrentPrec = NULL;
#endif
}


void FollowingAxisIterator::releaseResourcesImpl()
{
  releaseChildResources(theInput);

  while (!theCurrentPath.empty())
    theCurrentPath.pop();

  while (!theAncestorPath.empty())
    theAncestorPath.pop();

  theContextNode = NULL;

#ifdef DEBUG
  theCurrentPrec = NULL;
#endif
}


std::ostream& FollowingAxisIterator::_show(std::ostream& os)	const
{
  os << IT_DEPTH << " " << "context node: " << std::endl;
  if (theContextNode != NULL)
    os << IT_DEPTH << " " << theContextNode->show() << std::endl;

#ifdef DEBUG
  os << IT_DEPTH << " " << "following node: " << std::endl;
  if (theCurrentFollowing != NULL)
    os << IT_DEPTH << " " << theCurrentFollowing->show() << std::endl;
#endif
  theInput->show(os);
  return os;
}


};
