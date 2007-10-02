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

namespace xqp
{


/*******************************************************************************

********************************************************************************/
Item_t NameTestIterator::nextImpl()
{
  Item_t contextNode;

  do
  {
    contextNode = theInput->next();
#ifdef DEBUG
    theContextNode = contextNode;
#endif

    switch (theWildKind)
    {
    case no_wild:
      if (theQName->equals(contextNode->getNodeName()))
        return contextNode;

    case all_wild:
      return contextNode;

    case prefix_wild:
      if (theQName->getLocalName() == contextNode->getNodeName()->getLocalName())
        return contextNode;

    case name_wild:
      if (theQName->getNamespace() == contextNode->getNodeName()->getPrefix())
        return contextNode;

    default:
      ZorbaErrorAlerts::error_alert(
         error_messages::XQP0014_SYSTEM_SHOUD_NEVER_BE_REACHED,
         error_messages::SYSTEM_ERROR,
         NULL,
         false,
         "Unknown name test kind");
    }
  }
  while (contextNode != NULL);

  return NULL;
}


void NameTestIterator::resetImpl()
{
  resetChild(theInput);
#ifdef DEBUG
  theContextNode = NULL;
#endif
}


void NameTestIterator::releaseResourcesImpl()
{
  releaseChildResources(theInput);
  theQName = NULL;
#ifdef DEBUG
  theContextNode = NULL;
#endif
}


std::ostream& NameTestIterator::_show(std::ostream& os)	const
{
#ifdef DEBUG
  os << "context node: " << std::endl;
  if (theContextNode != NULL)
    os << theContextNode->show() << std::endl;
#endif
  os << "qnmae: " << theQName->show() << std::endl;
  theInput->show(os);
  return os;
}


/*******************************************************************************

********************************************************************************/
Item_t SelfIterator::nextImpl()
{
#ifdef DEBUG
  theContextNode = theInput->next();
  return theContextNode;
#else
  return theInput->next();
#endif
}


void SelfIterator::resetImpl()
{
  resetChild(theInput);
#ifdef DEBUG
  theContextNode = NULL;
#endif
}


void SelfIterator::releaseResourcesImpl()
{
  releaseChildResources(theInput);
#ifdef DEBUG
  theContextNode = NULL;
#endif
}


std::ostream& SelfIterator::_show(std::ostream& os)	const
{
#ifdef DEBUG
  os << "context node: " << std::endl;
  if (theContextNode != NULL)
    os << theContextNode->show() << std::endl;
#endif
  theInput->show(os);
  return os;
}


/*******************************************************************************

********************************************************************************/
Item_t AttributeIterator::nextImpl()
{
  Item_t contextNode;
  Item_t attr;

  STACK_INIT();

  while (true)
  {
    do
    {
      contextNode = theInput->next();
#ifdef DEBUG
      theContextNode = contextNode;
#endif
      if (contextNode == NULL)
        return NULL;
    }
    while (contextNode->getNodeKind() != elementNode);

    theAttributes = contextNode->getAttributes();

    attr = theAttributes->next();

    while (attr != NULL)
    {
#ifdef DEBUG
      theCurrentAttr = attr;
#endif
      STACK_PUSH(attr);
      attr = theAttributes->next();
    }
  }

  STACK_END();
}


void AttributeIterator::resetImpl()
{
  resetChild(theInput);
#ifdef DEBUG
  theContextNode = NULL;
  theCurrentAttr = NULL;
#endif
}


void AttributeIterator::releaseResourcesImpl()
{
  releaseChildResources(theInput);
  theAttributes = NULL;
#ifdef DEBUG
  theContextNode = NULL;
  theCurrentAttr = NULL;
#endif
}


std::ostream& AttributeIterator::_show(std::ostream& os)	const
{
#ifdef DEBUG
  os << "context node: " << std::endl;
  if (theContextNode != NULL)
    os << theContextNode->show() << std::endl;

  os << "current attr: "<< std::endl;
  if (theCurrentAttr != NULL)
    os << theCurrentAttr->show() << std::endl;
#endif
  theAttributes->show(os);
  theInput->show(os);
  return os;
}


/*******************************************************************************

********************************************************************************/
Item_t ParentIterator::nextImpl()
{
  Item_t contextNode = consumeNext(theInput);
#ifdef DEBUG
    theContextNode = contextNode;
#endif

  if (contextNode == NULL)
    return NULL;

#ifdef DEBUG
  theParent = contextNode->getParent();
  return theParent;
#else
  return contextNode->getParent();
#endif
}


void ParentIterator::resetImpl()
{
  resetChild(theInput);
#ifdef DEBUG
  theContextNode = NULL;
  theParent = NULL;
#endif
}


void ParentIterator::releaseResourcesImpl()
{
  releaseChildResources(theInput);
#ifdef DEBUG
  theContextNode = NULL;
  theParent = NULL;
#endif
}


std::ostream& ParentIterator::_show(std::ostream& os)	const
{
#ifdef DEBUG
  os << "context node: " << std::endl;
  if (theContextNode != NULL)
    os << theContextNode->show() << std::endl;

  os << "parent node: " << std::endl;
  if (theParent != NULL)
    os << theParent->show() << std::endl;
#endif
  theInput->show(os);
  return os;
}


/*******************************************************************************

********************************************************************************/
Item_t AncestorIterator::nextImpl()
{
  Item_t contextNode;

  STACK_INIT();

  while (true)
  {
    contextNode = consumeNext(theInput);
#ifdef DEBUG
    theContextNode = contextNode;
#endif

    if (contextNode == NULL)
      return NULL;

    theCurrentAnc = contextNode->getParent();

    while (theCurrentAnc != NULL)
    {
      STACK_PUSH(theCurrentAnc);
      theCurrentAnc = theCurrentAnc->getParent();
    }
  }

  STACK_END();
}


void AncestorIterator::resetImpl()
{
  resetChild(theInput);
#ifdef DEBUG
  theContextNode = NULL;
#endif
}


void AncestorIterator::releaseResourcesImpl()
{
  releaseChildResources(theInput);
  theCurrentAnc = NULL;
#ifdef DEBUG
  theContextNode = NULL;
#endif
}


std::ostream& AncestorIterator::_show(std::ostream& os)	const
{
#ifdef DEBUG
  os << "context node: " << std::endl;
  if (theContextNode != NULL)
    os << theContextNode->show() << std::endl;

  os << "ancestor node: " << std::endl;
  if (theCurrentAnc != NULL)
    os << theCurrentAnc->show() << std::endl;
#endif
  theInput->show(os);
  return os;
}


/*******************************************************************************

********************************************************************************/
Item_t AncestorSelfIterator::nextImpl()
{
  Item_t contextNode;

  STACK_INIT();

  while (true)
  {
    contextNode = consumeNext(theInput);
#ifdef DEBUG
    theContextNode = contextNode;
#endif

    if (contextNode == NULL)
      return NULL;

    theCurrentAnc = contextNode;

    while (theCurrentAnc != NULL)
    {
      STACK_PUSH(theCurrentAnc);
      theCurrentAnc = theCurrentAnc->getParent();
    }
  }

  STACK_END();
}


void AncestorSelfIterator::resetImpl()
{
  resetChild(theInput);
#ifdef DEBUG
  theContextNode = NULL;
#endif
}


void AncestorSelfIterator::releaseResourcesImpl()
{
  releaseChildResources(theInput);
  theCurrentAnc = NULL;
#ifdef DEBUG
  theContextNode = NULL;
#endif
}


std::ostream& AncestorSelfIterator::_show(std::ostream& os)	const
{
#ifdef DEBUG
  os << "context node: " << std::endl;
  if (theContextNode != NULL)
    os << theContextNode->show() << std::endl;

  os << "ancestor node: " << std::endl;
  if (theCurrentAnc != NULL)
    os << theCurrentAnc->show() << std::endl;
#endif
  theInput->show(os);
  return os;
}


/*******************************************************************************

********************************************************************************/
Item_t RSiblingIterator::nextImpl()
{
  Item_t contextNode;
  Item_t parent;
  Item_t sibling;

  STACK_INIT();

  while (true)
  {
    do
    {
      contextNode = consumeNext(theInput);
#ifdef DEBUG
      theContextNode = contextNode;
#endif
    
      if (contextNode == NULL)
        return NULL;
    }
    while (contextNode->getNodeKind() != attributeNode);

    parent = contextNode->getParent();

    if (parent == NULL)
      return NULL;

    theChildren = parent->getChildren();

    while (theChildren->next() != contextNode) ;

    sibling = theChildren->next();

    while (sibling != NULL)
    {
#ifdef DEBUG
      theRSibling = sibling;
#endif
      STACK_PUSH(sibling);

      sibling = theChildren->next();
    }
  }

  STACK_END();
}


void RSiblingIterator::resetImpl()
{
  resetChild(theInput);
#ifdef DEBUG
  theContextNode = NULL;
  theRSibling = NULL;
#endif
}


void RSiblingIterator::releaseResourcesImpl()
{
  releaseChildResources(theInput);
  theChildren = NULL; 
#ifdef DEBUG
  theContextNode = NULL;
  theRSibling = NULL;
#endif
}


std::ostream& RSiblingIterator::_show(std::ostream& os)	const
{
#ifdef DEBUG
  os << "context node: " << std::endl;
  if (theContextNode != NULL)
    os << theContextNode->show() << std::endl;

  os << "rsibling node: " << std::endl;
  if (theRSibling != NULL)
    os << theRSibling->show() << std::endl;
#endif
  theInput->show(os);
  return os;
}


/*******************************************************************************

********************************************************************************/
Item_t LSiblingIterator::nextImpl()
{
  Item_t contextNode;
  Item_t parent;
  Item_t sibling;

  STACK_INIT();

  while (true)
  {
    do
    {
      contextNode = consumeNext(theInput);
#ifdef DEBUG
      theContextNode = contextNode;
#endif

      if (contextNode == NULL)
        return NULL;
    }
    while (contextNode->getNodeKind() != attributeNode);

    parent = contextNode->getParent();

    if (parent == NULL)
      return NULL;

    theChildren = parent->getChildren();

    sibling = theChildren->next();

    while (sibling != contextNode)
    {
#ifdef DEBUG
      theLSibling = sibling;
#endif
      STACK_PUSH(sibling);

      sibling = theChildren->next();
    }
  }

  STACK_END();
}


void LSiblingIterator::resetImpl()
{
  resetChild(theInput);
#ifdef DEBUG
  theContextNode = NULL;
  theLSibling = NULL;
#endif
}


void LSiblingIterator::releaseResourcesImpl()
{
  releaseChildResources(theInput);
  theChildren = NULL;
#ifdef DEBUG
  theContextNode = NULL;
  theLSibling = NULL;
#endif
}


std::ostream& LSiblingIterator::_show(std::ostream& os)	const
{
#ifdef DEBUG
  os << "context node: " << std::endl;
  if (theContextNode != NULL)
    os << theContextNode->show() << std::endl;

  os << "lsibling node: " << std::endl;
  if (theLSibling != NULL)
    os << theLSibling->show() << std::endl;
#endif
  theInput->show(os);
  return os;
}


/*******************************************************************************

********************************************************************************/
Item_t ChildIterator::nextImpl()
{
  Item_t contextNode;
  Item_t child;

  STACK_INIT();

  while (true)
  {
    do
    {
      contextNode = theInput->next();
#ifdef DEBUG
      theContextNode = contextNode;
#endif

      if (contextNode == NULL)
        return NULL;
    }
    while (contextNode->getNodeKind() != elementNode &&
           contextNode->getNodeKind() != documentNode);

    theChildren = contextNode->getChildren();

    child = theChildren->next();

    while (child != NULL)
    {
#ifdef DEBUG
      theCurrentChild = child;
#endif
      STACK_PUSH(child);

      child = theChildren->next();
    }
  }

  STACK_END();
}


void ChildIterator::resetImpl()
{
  resetChild(theInput);
#ifdef DEBUG
  theContextNode = NULL;
  theCurrentCild = NULL;
#endif
}


void ChildIterator::releaseResourcesImpl()
{
  releaseChildResources(theInput);
  theChildren = NULL; 
#ifdef DEBUG
  theContextNode = NULL;
  theCurrentChild = NULL;
#endif
}


std::ostream& ChildIterator::_show(std::ostream& os)	const
{
#ifdef DEBUG
  os << "context node: " << std::endl;
  if (theContextNode != NULL)
    os << theContextNode->show() << std::endl;

  os << "current child: " << std::endl;
  if (theCurrentChild != NULL)
    os << theCurrentChild->show() << std::endl;
#endif
  theInput->show(os);
  return os;
}


/*******************************************************************************

********************************************************************************/
Item_t DescendantIterator::nextImpl()
{
  Item_t contextNode;
  Item_t desc;
  Iterator_t children;

  STACK_INIT();

  while (true)
  {
    do
    {
      contextNode = theInput->next();
#ifdef DEBUG
      theContextNode = contextNode;
#endif

      if (contextNode == NULL)
        return NULL;
    }
    while (contextNode->getNodeKind() != elementNode &&
           contextNode->getNodeKind() != documentNode);

    children = contextNode->getChildren();

    theCurrentPath.push(std::pair<Item_t, Iterator_t>(contextNode, children));
    
    desc = children->next();

    while (desc != NULL)
    {
      if (desc->getNodeKind() == elementNode)
        theCurrentPath.push(std::pair<Item_t, Iterator_t>(desc, desc->getChildren()));

#ifdef DEBUG
      theCurrentDesc = desc;
#endif
      STACK_PUSH(desc);

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


void DescendantIterator::resetImpl()
{
  resetChild(theInput);

  while (!theCurrentPath.empty())
  {
    theCurrentPath.pop();
  }
#ifdef DEBUG
  theContextNode = NULL;
  theCurrentDesc = NULL;
#endif
}


void DescendantIterator::releaseResourcesImpl()
{
  releaseChildResources(theInput);

  while (!theCurrentPath.empty())
  {
    theCurrentPath.pop();
  }
#ifdef DEBUG
  theContextNode = NULL;
  theCurrentDesc = NULL;
#endif
}


std::ostream& DescendantIterator::_show(std::ostream& os)	const
{
#ifdef DEBUG
  os << "context node: " << std::endl;
  if (theContextNode != NULL)
    os << theContextNode->show() << std::endl;

  os << "current descendant: " << std::endl;
  if (theCurrentDesc != NULL)
    os << theCurrentDesc->show() << std::endl;
#endif
  theInput->show(os);
  return os;
}


/*******************************************************************************

********************************************************************************/
Item_t DescendantSelfIterator::nextImpl()
{
  Item_t contextNode;
  Item_t desc;

  STACK_INIT();

  while (true)
  {
    do
    {
      contextNode = consumeNext(theInput);
#ifdef DEBUG
      theContextNode = contextNode;
#endif

      if (contextNode == NULL)
        return NULL;
    }
    while (contextNode->getNodeKind() != elementNode &&
           contextNode->getNodeKind() != documentNode);

    desc = contextNode;

    while (desc != NULL)
    {
      if (desc->getNodeKind() == elementNode ||
          contextNode->getNodeKind() == documentNode)
        theCurrentPath.push(std::pair<Item_t, Iterator_t>(desc, desc->getChildren()));

#ifdef DEBUG
      theCurrentDesc = desc;
#endif
      STACK_PUSH(desc);

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


void DescendantSelfIterator::resetImpl()
{
  resetChild(theInput);

  while (!theCurrentPath.empty())
  {
    theCurrentPath.pop();
  }
#ifdef DEBUG
  theContextNode = NULL;
  theCurrentDesc = NULL;
#endif
}


void DescendantSelfIterator::releaseResourcesImpl()
{
  releaseChildResources(theInput);

  while (!theCurrentPath.empty())
  {
    theCurrentPath.pop();
  }
#ifdef DEBUG
  theContextNode = NULL;
  theCurrentDesc = NULL;
#endif
}


std::ostream& DescendantSelfIterator::_show(std::ostream& os)	const
{
#ifdef DEBUG
  os << "context node: " << std::endl;
  if (theContextNode != NULL)
    os << theContextNode->show() << std::endl;

  os << "current descendant: " << std::endl;
  if (theCurrentDesc != NULL)
    os << theCurrentDesc->show() << std::endl;
#endif
  theInput->show(os);
  return os;
}


/*******************************************************************************

********************************************************************************/
Item_t PrecedingIterator::nextImpl()
{
  Item_t contextNode;
  Item_t ancestor;
  Item_t desc;
  Iterator_t children;

  STACK_INIT();

  while (true)
  {
    contextNode = consumeNext(theInput);
#ifdef DEBUG
    theContextNode = contextNode;
#endif

    if (contextNode == NULL)
      return NULL;

    // Collect the context node and its ancestors
    ancestor = contextNode;
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

#ifdef DEBUG
        theCurrentPrec = desc;
#endif
        STACK_PUSH(desc);

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


void PrecedingIterator::resetImpl()
{
  resetChild(theInput);

  while (!theCurrentPath.empty())
    theCurrentPath.pop();

  while (!theAncestorPath.empty())
    theAncestorPath.pop();

#ifdef DEBUG
  theContextNode = NULL;
  theCurrentPrec = NULL;
#endif
}


void PrecedingIterator::releaseResourcesImpl()
{
  releaseChildResources(theInput);

  while (!theCurrentPath.empty())
    theCurrentPath.pop();

  while (!theAncestorPath.empty())
    theAncestorPath.pop();

#ifdef DEBUG
  theContextNode = NULL;
  theCurrentPrec = NULL;
#endif
}


std::ostream& PrecedingIterator::_show(std::ostream& os)	const
{
#ifdef DEBUG
  os << "context node: " << std::endl;
  if (theContextNode != NULL)
    os << theContextNode->show() << std::endl;

  os << "preceding node: " << std::endl;
  if (theCurrentPrec != NULL)
    os << theCurrentPrec->show() << std::endl;
#endif
  theInput->show(os);
  return os;
}


/*******************************************************************************

********************************************************************************/
Item_t FollowingIterator::nextImpl()
{
  Item_t contextNode;
  Item_t ancestor;
  Item_t following;
  Iterator_t children;

  STACK_INIT();

  while (true)
  {
    contextNode = consumeNext(theInput);
#ifdef DEBUG
    theContextNode = contextNode;
#endif

    if (contextNode == NULL)
      return NULL;

    // Collect the context node and its ancestors
    ancestor = contextNode;
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

#ifdef DEBUG
        theCurrentFollowing = following;
#endif
        STACK_PUSH(following);

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


void FollowingIterator::resetImpl()
{
  resetChild(theInput);

  while (!theCurrentPath.empty())
    theCurrentPath.pop();

  while (!theAncestorPath.empty())
    theAncestorPath.pop();

#ifdef DEBUG
  theContextNode = NULL;
  theCurrentPrec = NULL;
#endif
}


void FollowingIterator::releaseResourcesImpl()
{
  releaseChildResources(theInput);

  while (!theCurrentPath.empty())
    theCurrentPath.pop();

  while (!theAncestorPath.empty())
    theAncestorPath.pop();

#ifdef DEBUG
  theContextNode = NULL;
  theCurrentPrec = NULL;
#endif
}


std::ostream& FollowingIterator::_show(std::ostream& os)	const
{
#ifdef DEBUG
  os << "context node: " << std::endl;
  if (theContextNode != NULL)
    os << theContextNode->show() << std::endl;

  os << "following node: " << std::endl;
  if (theCurrentFollowing != NULL)
    os << theCurrentFollowing->show() << std::endl;
#endif
  theInput->show(os);
  return os;
}


};
