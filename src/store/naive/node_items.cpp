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
#include "stdafx.h"

#include <memory>
#include <stack>

#include <zorba/config.h>

#include "diagnostics/assert.h"
#include "diagnostics/xquery_diagnostics.h"
#include "zorbatypes/URI.h"
#ifndef ZORBA_NO_FULL_TEXT
#include "zorbautils/locale.h"
#include "zorbautils/tokenizer.h"
#endif /* ZORBA_NO_FULL_TEXT */

#include "zorbamisc/ns_consts.h"

#include "store/api/copymode.h"
#include "store/naive/atomic_items.h"
#include "store/naive/node_items.h"
#include "store/naive/node_iterators.h"
#include "store/naive/simple_store.h"
#include "store/naive/simple_collection.h"
#include "store/naive/simple_item_factory.h"
#include "store/naive/qname_pool.h"
#include "store/naive/store_defs.h"
#include "store/naive/nsbindings.h"
#include "store/naive/item_iterator.h"
#include "store/naive/dataguide.h"
#include "store/naive/node_factory.h"

#include "util/string_util.h"

namespace zorba { namespace simplestore {

using namespace locale;


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  XmlTree                                                                   //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
XmlTree::XmlTree()
  :
  theRefCount(0),
  theId(0),
  thePos(0),
  theCollection(NULL),
  theRootNode(NULL),
  theDataGuideRootNode(NULL),
  theIsValidated(false),
  theIsRecursive(false)
#ifndef EMBEDED_TYPE
  ,
  theTypesMap(NULL)
#endif
{
}


XmlTree::XmlTree(XmlNode* root, ulong id)
  :
  theRefCount(0),
  theId(id),
  thePos(0),
  theCollection(NULL),
  theRootNode(root),
  theDataGuideRootNode(NULL),
  theIsValidated(false),
  theIsRecursive(false)
#ifndef EMBEDED_TYPE
  ,
  theTypesMap(NULL)
#endif
{
}


/*******************************************************************************

********************************************************************************/
void XmlTree::setCollection(SimpleCollection* collection, ulong pos)
{
  ZORBA_ASSERT(collection == NULL || theCollection == NULL);

  theCollection = collection;
  thePos = pos;

  if (collection != NULL)
    theId = collection->createTreeId();
}


/*******************************************************************************

********************************************************************************/
ulong XmlTree::getCollectionId() const
{
  if (theCollection != NULL)
    return theCollection->getId();
  else
    return 0;
}


/*******************************************************************************

********************************************************************************/
void XmlTree::free()
{
  // std::cout << "Deleting Xml Tree: " << this << std::endl;

  if (theRootNode != 0)
  {
    theRootNode->destroy(false);
    theRootNode = NULL;
  }

  if (theDataGuideRootNode != NULL)
  {
    theDataGuideRootNode->deleteTree();
    theDataGuideRootNode = NULL;
  }

#ifndef EMBEDED_TYPE
  if (theTypesMap)
    delete theTypesMap;
#endif

  delete this;
}


#ifndef EMBEDED_TYPE

/*******************************************************************************

********************************************************************************/
store::Item* XmlTree::getType(const XmlNode* n) const
{
  assert(theTypesMap != NULL);

  NodeTypeMap::iterator ite = theTypesMap->get(n);

  assert(ite != theTypesMap->end());

  return ite.getValue().getp();
}


/*******************************************************************************

********************************************************************************/
void XmlTree::addType(const XmlNode* n, store::Item_t& type)
{
  if (theTypesMap == NULL)
  {
    theTypesMap = new NodeTypeMap(32, false);
  }

  if (! theTypesMap->insert(n, type))
  {
    assert(false);
  }
}


/*******************************************************************************

********************************************************************************/
void XmlTree::setType(const XmlNode* n, store::Item_t& type)
{
  if (theTypesMap == NULL)
  {
    theTypesMap = new NodeTypeMap(32, false);
  }

  NodeTypeMap::iterator ite = theTypesMap->get(n);

  if (ite == theTypesMap->end())
  {
    theTypesMap->insert(n, type);
  }
  else
  {
    ite.setValue(type);
  }
}


/*******************************************************************************

********************************************************************************/
void XmlTree::removeType(const XmlNode* n)
{
  assert(theTypesMap != NULL);

  if (! theTypesMap->remove(n))
  {
    assert(false);
  }
}


/*******************************************************************************
  This method is called frpm XmlNode::attach(), i.e., when one tree is attached
  to another tree.
********************************************************************************/
void XmlTree::copyTypesMap(const XmlTree* source)
{
  if (source->theTypesMap == NULL || source->theTypesMap->empty())
    return;

  if (theTypesMap == NULL)
  {
    theTypesMap = new NodeTypeMap(source->theTypesMap->object_count(), false);
  }

  NodeTypeMap::iterator ite = source->theTypesMap->begin();
  NodeTypeMap::iterator end = source->theTypesMap->end();

  for (; ite != end; ++ite)
  {
    store::Item_t type = ite.getValue();
    theTypesMap->insert(ite.getKey(), type);
  }
}


#endif // #ifndef EMBEDED_TYPE


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class XmlNode                                                              //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************
  Create a new node C within a given tree T and with a given node Pas parent.

  If P is NULL, C becomes the root (and single node) of T. If P is not NULL,
  then T is the same as the tree that P belongs to.
********************************************************************************/
XmlNode::XmlNode(
    XmlTree* tree,
    InternalNode* parent,
    store::StoreConsts::NodeKind nodeKind)
  :
  theParent(parent),
  theFlags(0)
{
  assert(tree || parent);
  assert(parent == NULL || parent->getTree() != NULL);
  assert(tree == NULL || parent == NULL || parent->getTree() == tree);

  theFlags = (uint32_t)nodeKind;

  if (parent == NULL)
  {
    setTree(tree);
    tree->setRoot(this);
  }
  else
  {
    setTree(parent->getTree());
  }
}


/*******************************************************************************

********************************************************************************/
#ifndef NDEBUG
XmlNode::~XmlNode()
{
  NODE_TRACE1("Deleted " << store::StoreConsts::toString(getNodeKind()) << this);
}
#endif


/*******************************************************************************
  Private method
********************************************************************************/
void XmlNode::setTree(const XmlTree* t)
{
  theUnion.treeRCPtr = (long*)t;
}


/*******************************************************************************
  Method called only from the loader and PutUpd::apply()
********************************************************************************/
void XmlNode::setId(XmlTree* tree, const OrdPathStack* op)
{
  ZORBA_ASSERT(getTree() == NULL);

  setTree(tree);

#ifndef TEXT_ORDPATH
  if (getNodeKind() != store::StoreConsts::textNode)
  {
#endif
    if (op != NULL)
      static_cast<OrdPathNode*>(this)->getOrdPath() = *op;
    else
      static_cast<OrdPathNode*>(this)->getOrdPath().setAsRoot();
#ifndef TEXT_ORDPATH
  }
#endif
}


#ifndef TEXT_ORDPATH
/*******************************************************************************

********************************************************************************/
long XmlNode::compareInSameTree(const XmlNode* n1, const XmlNode* n2) const
{
  assert(n1 != n2);
  assert(n1->getTree() == n2->getTree());
  assert(n1->theParent != NULL || n2->theParent != NULL);

  store::StoreConsts::NodeKind kind1 = n1->getNodeKind();
  store::StoreConsts::NodeKind kind2 = n2->getNodeKind();

  if (kind1 != store::StoreConsts::textNode &&
      kind2 != store::StoreConsts::textNode)
  {
    if (static_cast<const OrdPathNode*>(n1)->getOrdPath() <
        static_cast<const OrdPathNode*>(n2)->getOrdPath())
      return -1;
    else
      return 1;
  }
  else if (n1->theParent != n2->theParent)
  {
    const InternalNode* p1 = n1->theParent;
    const InternalNode* p2 = n2->theParent;

    if (p1 == NULL)
      return -1;

    if (p2 == NULL)
      return 1;

    const OrdPath& op1 = p1->getOrdPath();
    const OrdPath& op2 = p2->getOrdPath();

    OrdPath::RelativePosition relPos = op1.getRelativePosition(op2);

    if (relPos == OrdPath::FOLLOWING)
    {
      return -1;
    }
    else if (relPos == OrdPath::PRECEDING)
    {
      return 1;
    }
    else if (relPos == OrdPath::DESCENDANT)
    {
      // p2 is a descendant of p1
      InternalNode::const_iterator ite = p1->childrenBegin();
      InternalNode::const_iterator end = p1->childrenEnd();

      for (; ite != end; ++ite)
      {
        if (*ite == n1)
          return -1;

        if ((*ite)->getNodeKind() != store::StoreConsts::elementNode)
          continue;

        const ElementNode* elem = static_cast<const ElementNode*>(*ite);

        if (elem == p2)
          return 1;

        OrdPath::RelativePosition relPos2 =
        elem->getOrdPath().getRelativePosition(op2);

        if (relPos2 == OrdPath::DESCENDANT)
          return 1;
      }

      assert(ite != end);
    }
    else if (relPos == OrdPath::ANCESTOR)
    {
      // p1 is a descendant of p2
      InternalNode::const_iterator ite = p2->childrenBegin();
      InternalNode::const_iterator end = p2->childrenEnd();

      for (; ite != end; ++ite)
      {
        if (*ite == n2)
          return 1;

        if ((*ite)->getNodeKind() != store::StoreConsts::elementNode)
          continue;

        const ElementNode* elem = static_cast<const ElementNode*>(*ite);

        if (elem == p1)
          return -1;

        OrdPath::RelativePosition relPos2 =
        elem->getOrdPath().getRelativePosition(op1);

        if (relPos2 == OrdPath::DESCENDANT)
          return -1;
      }

      assert(ite != end);
    }
    else
    {
      ZORBA_ASSERT(false);
    }
  }
  else if (kind1 == store::StoreConsts::attributeNode)
  {
    // both nodes are under the same parent, n1 is attribute and n2 is text.
    return -1;
  }
  else if (kind2 == store::StoreConsts::attributeNode)
  {
    // both nodes are under the same parent, n1 is text and n2 is attribute.
    return 1;
  }
  else
  {
    // both nodes are under the same parent, and none of them is an attribute
    InternalNode::const_iterator ite = theParent->childrenBegin();
    InternalNode::const_iterator end = theParent->childrenEnd();

    for (; ite != end; ++ite)
    {
      if (*ite == n1)
        return -1;
      else if (*ite == n2)
        return 1;
    }

    assert(ite != end);
  }

  assert(false); // we shouldn't reach here
  return 1;
}

#endif // ! TEXT_ORDPATH


/*******************************************************************************

********************************************************************************/
store::Item_t XmlNode::getEBV() const
{
  store::Item_t bVal;
  GET_FACTORY().createBoolean(bVal, true);
  return bVal;
}


/*******************************************************************************
  Document and element methods redefine this method.
********************************************************************************/
void XmlNode::getBaseURIInternal(zstring& uri, bool& local) const
{
  local = false;

  if (theParent)
    theParent->getBaseURI(uri);
}


/*******************************************************************************
  Make a copy of the xml tree rooted at this node and place the copied tree as
  the last child/agttribute of a given node. Return a pointer to the root node
  of the copied tree.

  parent   : The node P under which the copied tree is to be placed. P may be
             NULL, in which case the copied tree becomes a new standalone tree.
  copymode : Encapsulates the construction-mode and copy-namespace-mode
             components of the query's static context.
********************************************************************************/
store::Item* XmlNode::copy(
    store::Item* inParent,
    const store::CopyMode& copymode) const
{
  InternalNode* parent = NULL;
  csize pos = 0;

  if (inParent)
  {
    parent = reinterpret_cast<InternalNode*>(inParent);
    pos = parent->numChildren();

    ZORBA_ASSERT(inParent->getNodeKind() == store::StoreConsts::elementNode ||
                 inParent->getNodeKind() == store::StoreConsts::documentNode);
  }

  if (getNodeKind() == store::StoreConsts::attributeNode)
  {
    if (parent)
    {
      ElementNode* pnode = reinterpret_cast<ElementNode*>(parent);
      pnode->checkUniqueAttr(getNodeName());
      pos = pnode->numAttrs();
    }
  }

  return copyInternal(parent, parent, pos, NULL, copymode);
}



/*******************************************************************************
  Make a copy of the xml tree rooted at this node and place the copied tree at
  a given position under a given node. Return a pointer to the root node of the
  copied tree.

  parent   : The node P under which the copied tree is to be placed. P may be
             NULL, in which case the copied tree becomes a new standalone tree.
  pos      : The position under P where the copied tree is to be placed. If
             "this" is an attribute node, pos is a position among the attributes
             of P; otherwise it is a position among the children of P. If pos
             is greater or equal to the current number of attrs/children in P,
             then the copied tree is appended to P's attributes/children.
  copymode : Encapsulates the construction-mode and copy-namespace-mode
             components of the query's static context.
********************************************************************************/
store::Item* XmlNode::copy(
    store::Item* inParent,
    csize pos,
    const store::CopyMode& copymode) const
{
  InternalNode* parent = NULL;

  if (inParent)
  {
    parent = reinterpret_cast<InternalNode*>(inParent);
    ZORBA_ASSERT(inParent->getNodeKind() == store::StoreConsts::elementNode ||
                 inParent->getNodeKind() == store::StoreConsts::documentNode);
  }

  if (getNodeKind() == store::StoreConsts::attributeNode)
  {
    if (parent)
    {
      ElementNode* pnode = reinterpret_cast<ElementNode*>(parent);
      pnode->checkUniqueAttr(getNodeName());
    }
  }

  return copyInternal(parent, parent, pos, NULL, copymode);
}


/*******************************************************************************
  Connect "this" to the given parent at the given position.
********************************************************************************/
void XmlNode::connect(InternalNode* parent, csize pos)
{
  ZORBA_FATAL(theParent == NULL, "");

  if (getNodeKind() == store::StoreConsts::attributeNode)
  {
    parent->insertAttr(this, pos);
  }
  else
  {
    parent->insertChild(this, pos);
  }
}


/*******************************************************************************
  Disconnect "this" node from its parent, if any.
********************************************************************************/
bool XmlNode::disconnect(csize& pos)
{
  if (theParent == NULL)
    return false;

  try
  {
    if (getNodeKind() == store::StoreConsts::attributeNode)
    {
      csize numAttrs = theParent->numAttrs();
      pos = theParent->removeAttr(this);
      ZORBA_FATAL(pos <= numAttrs, "");
    }
    else
    {
      csize numChildren = theParent->numChildren();
      pos = theParent->removeChild(this);
      ZORBA_FATAL(pos <= numChildren, "");
    }

    return true;
  }
  catch(...)
  {
    ZORBA_FATAL(false, "Unexpected exception");
  }
}


/*******************************************************************************
  Deallocate all nodes in the subtree rooted at "this".
********************************************************************************/
void XmlNode::destroy(bool removeType)
{
  try
  {
    csize pos;
    disconnect(pos);

    destroyInternal(removeType);
  }
  catch (...)
  {
    ZORBA_FATAL(false, "Unexpectd exception");
  }
}


void XmlNode::destroyInternal(bool removeType)
{
  store::StoreConsts::NodeKind kind = getNodeKind();

  if (kind == store::StoreConsts::elementNode ||
      kind == store::StoreConsts::documentNode)
  {
    InternalNode* node = static_cast<InternalNode*>(this);

    InternalNode::iterator ite = node->childrenBegin();
    InternalNode::iterator end = node->childrenEnd();

    for (; ite != end; ++ite)
    {
      (*ite)->destroyInternal(removeType);
    }

    ite = node->attrsBegin();
    end = node->attrsEnd();

    for (; ite != end; ++ite)
    {
      (*ite)->destroyInternal(removeType);
    }
  }

#ifndef EMBEDED_TYPE
  if (removeType)
  {
    if (kind == store::StoreConsts::elementNode)
    {
      ElementNode* elem = static_cast<ElementNode*>(this);
      if (elem->haveType())
        getTree()->removeType(this);
    }
    else if (kind == store::StoreConsts::attributeNode)
    {
      AttributeNode* attr = static_cast<AttributeNode*>(this);
      if (attr->haveType())
        getTree()->removeType(this);
    }
  }
#endif

  delete this;
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class OrdPathNode                                                          //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************
  Create a new node C within a given tree T and compute its ordpath based on its
  given position among the attributes or children of a given node P, who will
  become the parent of C.

  If P is NULL, C becomes the root (and single node) of T. In this case, C's
  ordpath is the root one (= 1).

  If P != NULL and append == false, C will become the "pos"-th child/attribute
  of P. In this case, the ordpath of C is computed based on the ordpaths of its
  left and right siblings (if any). Note: If "pos" >= P->numChildren, then C
  will be appended to P's children/attributes.

  If P != NULL and append == true, C will be appended to P's children/attributes,
  and C's ordpath is computed based on the current number of children/attributes
  in P. This ordpath evaluation assumes that P never had a child that was later
  deleted. The assumption holds because this case is used only during the
  evaluation of a node-constructor expression, or during the copying of a
  subtree S, if the node to be created is not the copy of the root of S.
********************************************************************************/
OrdPathNode::OrdPathNode(
    XmlTree* tree,
    InternalNode* parent,
    bool append,
    csize pos,
    store::StoreConsts::NodeKind nodeKind)
  :
  XmlNode(tree, parent, nodeKind)
{
  if (parent == NULL)
  {
    theOrdPath.setAsRoot();

    if (nodeKind != store::StoreConsts::documentNode)
      theOrdPath.appendComp(1);
  }
  else
  {
    setOrdPath(parent, append, pos, nodeKind);
  }
}


/*******************************************************************************

********************************************************************************/
void OrdPathNode::setOrdPath(
    InternalNode* parent,
    bool append,
    csize pos,
    store::StoreConsts::NodeKind nodeKind)
{
  if (parent == NULL)
  {
    theOrdPath.setAsRoot();
    return;
  }

  if (!parent->theOrdPath.isValid())
    return;

  csize numChildren = parent->numChildren();
  csize numAttrs = 0;
  ElementNode* elemParent = NULL;

  if (parent->getNodeKind() == store::StoreConsts::elementNode)
  {
    elemParent = reinterpret_cast<ElementNode*>(parent);
    numAttrs =  elemParent->numAttrs();
  }

  if (nodeKind == store::StoreConsts::attributeNode)
  {
    if (append)
    {
      theOrdPath = parent->getOrdPath();
      theOrdPath.appendComp(2 * numAttrs + 1);
    }
    // Parent has some existing attributes.
    else if (numAttrs > 0)
    {
      if (pos == 0)
      {
        OrdPath::insertBefore(parent->theOrdPath,
                              elemParent->getAttr(0)->getOrdPath(),
                              theOrdPath);
      }
      else if (pos >= numAttrs)
      {
        const OrdPath* upperOrdPath = parent->getFirstChildOrdPathAfter(0);

        if (upperOrdPath != NULL)
        {
          OrdPath::insertInto(parent->theOrdPath,
                              elemParent->getAttr(numAttrs-1)->theOrdPath,
                              *upperOrdPath,
                              theOrdPath);
        }
        else
        {
          OrdPath::insertAfter(parent->theOrdPath,
                               elemParent->getAttr(numAttrs-1)->getOrdPath(),
                               theOrdPath);
        }
      }
      else
      {
        OrdPath::insertInto(parent->theOrdPath,
                            elemParent->getAttr(pos-1)->getOrdPath(),
                            elemParent->getAttr(pos)->getOrdPath(),
                            theOrdPath);
      }
    }
    // Parent has no existing attributes.
    else
    {
      const OrdPath* upperOrdPath = parent->getFirstChildOrdPathAfter(0);

      if (upperOrdPath != NULL)
      {
        OrdPath::insertBefore(parent->theOrdPath, *upperOrdPath, theOrdPath);
      }
      else
      {
        theOrdPath = parent->theOrdPath;
        theOrdPath.appendComp(1);
      }
    }
  }

  else
  {
    if (append)
    {
      theOrdPath = parent->getOrdPath();
      theOrdPath.appendComp(2 * (numAttrs + numChildren) + 1);
    }

    // Parent has some other children
    else if (numChildren > 0)
    {
      const OrdPath* upperOrdPath = NULL;
      const OrdPath* lowerOrdPath = NULL;

      if (pos < numChildren)
        upperOrdPath = parent->getFirstChildOrdPathAfter(pos);

      if (pos == 0)
      {
        if (numAttrs > 0)
          lowerOrdPath = &elemParent->getAttr(numAttrs-1)->theOrdPath;
      }
      else
      {
        lowerOrdPath = parent->getFirstChildOrdPathBefore(pos-1);

        if (lowerOrdPath == NULL && numAttrs > 0)
          lowerOrdPath = &elemParent->getAttr(numAttrs-1)->theOrdPath;
      }

      if (upperOrdPath != NULL && lowerOrdPath != NULL)
      {
        OrdPath::insertInto(parent->theOrdPath,
                            *lowerOrdPath,
                            *upperOrdPath,
                            theOrdPath);
      }
      else if (upperOrdPath == NULL && lowerOrdPath != NULL)
      {
        OrdPath::insertAfter(parent->theOrdPath, *lowerOrdPath, theOrdPath);
      }
      else if (upperOrdPath != NULL && lowerOrdPath == NULL)
      {
        OrdPath::insertBefore(parent->theOrdPath, *upperOrdPath, theOrdPath);
      }
      else
      {
        theOrdPath = parent->theOrdPath;
        theOrdPath.appendComp(1);
      }
    }

    // Parent has no children, but some attributes
    else if (numAttrs > 0)
    {
      OrdPath::insertAfter(parent->getOrdPath(),
                           elemParent->getAttr(numAttrs-1)->getOrdPath(),
                           theOrdPath);
    }

    // Parent has no children and no attributes
    else
    {
      theOrdPath = parent->theOrdPath;
      theOrdPath.appendComp(1);
    }
  }
}


/*******************************************************************************
  Return true if "aOther" is an ancestore of "this".
********************************************************************************/
bool OrdPathNode::isAncestor(const store::Item_t& aOther) const
{
  const OrdPathNode* lThisNode = static_cast<const OrdPathNode*>(this);
  const OrdPathNode* lOtherNode = static_cast<const OrdPathNode*>(aOther.getp());
  const OrdPath& lOtherOrdPath = lOtherNode->getOrdPath();
  const OrdPath& lThisOrdPath = lThisNode->getOrdPath();

  return 
    (
      lThisNode->getTree() == lOtherNode->getTree() &&
      (lThisOrdPath.getRelativePosition(lOtherOrdPath) == OrdPath::ANCESTOR)
    );
}


/*******************************************************************************

********************************************************************************/
bool OrdPathNode::isFollowingSibling(const store::Item_t& aOther) const
{ 
  return isFollowing(aOther) && getParent() == aOther->getParent();
}


/*******************************************************************************

********************************************************************************/
bool OrdPathNode::isFollowing(const store::Item_t& aOther) const
{ 
  const OrdPathNode* lThisNode = static_cast<const OrdPathNode*>(this);
  const OrdPathNode* lOtherNode = static_cast<const OrdPathNode*>(aOther.getp());
  const OrdPath& lOtherOrdPath = lOtherNode->getOrdPath();
  const OrdPath& lThisOrdPath = lThisNode->getOrdPath();

  return 
    (
      lThisNode->getTree() == lOtherNode->getTree() &&
      (lThisOrdPath.getRelativePosition(lOtherOrdPath) == OrdPath::FOLLOWING)
    );
}


/*******************************************************************************

********************************************************************************/
bool OrdPathNode::isDescendant(const store::Item_t& aOther) const
{ 
  const OrdPathNode* lThisNode = static_cast<const OrdPathNode*>(this);
  const OrdPathNode* lOtherNode = static_cast<const OrdPathNode*>(aOther.getp());
  const OrdPath& lOtherOrdPath = lOtherNode->getOrdPath();
  const OrdPath& lThisOrdPath = lThisNode->getOrdPath();

  return 
    (
      lThisNode->getTree() == lOtherNode->getTree() &&
      (lThisOrdPath.getRelativePosition(lOtherOrdPath) == OrdPath::DESCENDANT)
    );
}


/*******************************************************************************

********************************************************************************/
bool OrdPathNode::isPrecedingSibling(const store::Item_t& aOther) const
{ 
  return isPreceding(aOther) && getParent() == aOther->getParent();
}


/*******************************************************************************

********************************************************************************/
bool OrdPathNode::isPreceding(const store::Item_t& aOther) const
{ 
  const OrdPathNode* lThisNode = static_cast<const OrdPathNode*>(this);
  const OrdPathNode* lOtherNode = static_cast<const OrdPathNode*>(aOther.getp());
  const OrdPath& lOtherOrdPath = lOtherNode->getOrdPath();
  const OrdPath& lThisOrdPath = lThisNode->getOrdPath();

  return 
    (
      lThisNode->getTree() == lOtherNode->getTree() &&
      (lThisOrdPath.getRelativePosition(lOtherOrdPath) == OrdPath::PRECEDING)
    );
}


/*******************************************************************************

********************************************************************************/
bool OrdPathNode::isChild(const store::Item_t& aOther) const
{ 
  return aOther->getParent() == this;
}


/*******************************************************************************

********************************************************************************/
bool OrdPathNode::isParent(const store::Item_t& aOther) const
{ 
  return this->getParent() == aOther;
}


/*******************************************************************************

********************************************************************************/
store::Item_t OrdPathNode::getLevel() const
{ 
  ulong lNumLevels = 1;
  store::Item_t lCurrent = this->getParent();
  while (lCurrent)
  {
    ++lNumLevels;
    lCurrent = lCurrent->getParent();
  }
  store::Item_t lRes;
  GET_STORE().getItemFactory()->createInteger(lRes, lNumLevels);
  return lRes;
}


/*******************************************************************************

********************************************************************************/
store::Item_t OrdPathNode::leastCommonAncestor(const store::Item_t& aOther) const
{
  const OrdPathNode* lThisNode = static_cast<const OrdPathNode*>(this);
  const OrdPathNode* lOtherNode = static_cast<const OrdPathNode*>(aOther.getp());

  if (lThisNode->getTree() != lOtherNode->getTree())
  {
    return NULL;
  } 

  if (this == aOther.getp() || isDescendant(aOther))
  {
    return const_cast<OrdPathNode*>(this);
  }

  if (isAncestor(aOther))
  {
    return aOther;
  }

  const Item* lThisCurr = lThisNode->getParent();
  const Item* lOtherCurr = lOtherNode->getParent();

  while (lThisCurr != lOtherCurr)
  {
    if (!lThisCurr)
    {
      return const_cast<OrdPathNode*>(lThisNode);
    }

    if (!lOtherCurr)
    {
      return const_cast<OrdPathNode*>(lOtherNode);
    }

    lThisCurr = lThisCurr->getParent();
    lOtherCurr = lOtherCurr->getParent();
  }
  return const_cast<Item*>(lThisCurr);
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class InternalNode                                                         //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
const OrdPath* InternalNode::getFirstChildOrdPathAfter(csize pos) const
{
  assert((pos == 0 && numChildren() == 0) || pos < numChildren());

  const_iterator ite = childrenBegin() + pos;
  const_iterator end = childrenEnd();

  assert((pos == 0 && numChildren() == 0) || *ite == getChild(pos));

#ifndef TEXT_ORDPATH
  for (; ite != end; ++ite)
  {
    if ((*ite)->getNodeKind() != store::StoreConsts::textNode)
      break;
  }
#endif

  return (ite == end ?
          NULL :
          &static_cast<const OrdPathNode*>((*ite))->getOrdPath());
}


/*******************************************************************************

********************************************************************************/
const OrdPath* InternalNode::getFirstChildOrdPathBefore(csize pos) const
{
  assert(pos < numChildren());

  const_reverse_iterator ite = childrenRBegin() + (numChildren() - 1 - pos);
  const_reverse_iterator end = childrenREnd();

  assert(*ite == getChild(pos));

#ifndef TEXT_ORDPATH
  for (; ite != end; ++ite)
  {
    if ((*ite)->getNodeKind() != store::StoreConsts::textNode)
      break;
  }
#endif

  return (ite == end ?
          NULL :
          &static_cast<const OrdPathNode*>((*ite))->getOrdPath());
}


/*******************************************************************************
  Return the position of the given node among the children of "this". If the
  given node is not a child of "this", return the number of children of "this".
********************************************************************************/
csize InternalNode::findChild(XmlNode* child) const
{
  const_iterator begin = childrenBegin();
  const_iterator end = childrenEnd();

  const_iterator ite = std::find(begin, end, child);

  return (ite - begin);
}


/*******************************************************************************
  Insert a new child node as the i-th child of "this". If i > theChildren2.size()
  the new child is inserted as the last child.
********************************************************************************/
void InternalNode::insertChild(XmlNode* child, csize pos)
{
  assert(pos <= numChildren());

  if (pos >= numChildren())
    theNodes.push_back(child);
  else
    theNodes.insert(childrenBegin() + pos, child);

  assert(child->theParent == NULL || child->theParent == this);

  child->theParent = this;
}


/*******************************************************************************
  Remove the i-th child of "this", if it exists, ie, if i < numChildren.
********************************************************************************/
void InternalNode::removeChild(csize pos)
{
  if (pos < numChildren())
  {
    iterator ite = childrenBegin() + pos;
    assert((*ite)->theParent == this);
    (*ite)->theParent = NULL;
    theNodes.erase(ite);
  }
}


/*******************************************************************************
  If the given node N is a child of "this", disconnect N from "this" and return
  the position of N among the children of "this". Else, return the number of
  children.
********************************************************************************/
csize InternalNode::removeChild(XmlNode* child)
{
  iterator begin = childrenBegin();
  iterator end = childrenEnd();

  iterator ite = std::find(begin, end, child);

  if (ite != end)
  {
    assert(child->theParent == this);

    csize pos = (ite - begin);

    child->theParent = NULL;

    theNodes.erase(ite);

    return pos;
  }
  else
  {
    return numChildren();
  }
}


/*******************************************************************************
  Return the position of the given attr among the attribute of "this". If the
  given node is not an attribute of "this", return the number of attribute of
  "this".
********************************************************************************/
csize InternalNode::findAttr(XmlNode* attr) const
{
  const_iterator begin = attrsBegin();
  const_iterator end = attrsEnd();

  const_iterator ite = std::find(begin, end, attr);

  return (ite - begin);
}


/*******************************************************************************

********************************************************************************/
void InternalNode::insertAttr(XmlNode* attr, csize pos)
{
  assert(pos <= numAttrs());
  assert(attr->theParent == NULL || attr->theParent == this);

  theNodes.insert(attrsBegin() + pos, attr);
  ++theNumAttrs;

  attr->theParent = this;
}


/*******************************************************************************
  Remove the i-th attribute of "this", if it exists, ie, if i < numAttributes.
********************************************************************************/
void InternalNode::removeAttr(csize pos)
{
  if (pos < numAttrs())
  {
    iterator ite = attrsBegin() + pos;
    assert((*ite)->theParent == this);
    (*ite)->theParent = NULL;
    theNodes.erase(ite);
    --theNumAttrs;
  }
}


/*******************************************************************************
  If the given node N is an attr of "this", disconnect N from "this" and return
  the position of N among the attributes of "this". Else, return the number of
  attributes.
********************************************************************************/
csize InternalNode::removeAttr(XmlNode* attr)
{
  iterator begin = attrsBegin();
  iterator end = attrsEnd();

  iterator ite = std::find(begin, end, attr);

  if (ite != end)
  {
    assert(attr->theParent == this);

    csize pos = (ite - begin);

    attr->theParent = NULL;
    theNodes.erase(ite);
    --theNumAttrs;

    return pos;
  }
  else
  {
    return numAttrs();
  }
}


/*******************************************************************************

********************************************************************************/
void InternalNode::finalizeNode()
{
  if (theNodes.capacity() > theNodes.size())
  {
    std::vector<XmlNode*> tmp(theNodes.size());
    tmp = theNodes;
    theNodes.swap(tmp);
  }
}

/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class DocumentNode                                                         //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************
  Node constructor used by FastXmlLoader
********************************************************************************/
DocumentNode::DocumentNode()
  :
  InternalNode(store::StoreConsts::documentNode)
{
  NODE_TRACE1("Loaded doc node " << this);
}


/*******************************************************************************

********************************************************************************/
DocumentNode::DocumentNode(
    XmlTree* tree,
    zstring& baseUri,
    zstring& docUri)
  :
  InternalNode(tree, NULL, false, 0, store::StoreConsts::documentNode)
{
  if (!baseUri.empty())
    tree->setBaseUri(baseUri);

  tree->setDocUri(docUri);

  NODE_TRACE1("{\nConstructing doc node " << this << " tree = "
              << getTree()->getId() << ":" << getTree()
              << " doc uri = " << docUri);
}


/*******************************************************************************

********************************************************************************/
XmlNode* DocumentNode::copyInternal(
    InternalNode*          rootParent,
    InternalNode*          parent,
    csize                pos,
    const XmlNode*         rootCopy,
    const store::CopyMode& copymode) const
{
  ZORBA_ASSERT(rootParent == NULL && parent == NULL);

  XmlTree* tree = NULL;
  InternalNode* copyNode = NULL;

  try
  {
    tree = NodeFactory::instance().createXmlTree();

    zstring baseuri = getBaseUri();
    zstring docuri = getDocUri();

    copyNode = NodeFactory::instance().createDocumentNode(tree, baseuri, docuri);

    const_iterator ite = childrenBegin();
    const_iterator end = childrenEnd();

    for (; ite != end; ++ite)
    {
      (*ite)->copyInternal(rootParent, copyNode, 0, NULL, copymode);
    }
  }
  catch (...)
  {
    // Note: no rchandles to copied nodes should be used during the copy, so
    // that we can call tree->free() and destroy all the nodes in the copied
    // tree.
    if (tree)
      tree->free();

    throw;
  }

  NODE_TRACE1("}");
  NODE_TRACE1("Copied doc node " << this << " to node " << copyNode);

  return copyNode;
}


/*******************************************************************************

********************************************************************************/
void DocumentNode::getBaseURIInternal(zstring& uri, bool& local) const
{
  local = true;
  uri = getBaseUri();
}


/*******************************************************************************

********************************************************************************/
store::Iterator_t DocumentNode::getChildren() const
{
  ChildrenIteratorImpl* res = new ChildrenIteratorImpl();
  res->init((InternalNode*)this);
  return res;
}


/*******************************************************************************

********************************************************************************/
store::Item* DocumentNode::getType() const
{
  // ???? should return NULL?
  return GET_STORE().theSchemaTypeNames[XS_UNTYPED];
}


/*******************************************************************************

********************************************************************************/
void DocumentNode::getTypedValue(store::Item_t& val, store::Iterator_t& iter) const
{
  zstring rch;
  getStringValue2(rch);
  GET_STORE().getItemFactory()->createUntypedAtomic(val, rch);
  iter = NULL;
}


/*******************************************************************************

********************************************************************************/
zstring DocumentNode::getStringValue() const
{
  zstring strval;
  getStringValue2(strval);
  return strval;
}


void DocumentNode::getStringValue2(zstring& val) const
{
  store::StoreConsts::NodeKind kind;

  if (numChildren() == 1)
  {
    kind = getChild(0)->getNodeKind();

    if (kind != store::StoreConsts::commentNode &&
        kind != store::StoreConsts::piNode)
    {
      getChild(0)->getStringValue2(val);
    }
  }
  else
  {
    const_iterator ite = childrenBegin();
    const_iterator end = childrenEnd();

    for (; ite != end; ++ite)
    {
      kind = (*ite)->getNodeKind();

      if (kind != store::StoreConsts::commentNode &&
          kind != store::StoreConsts::piNode)
        (*ite)->appendStringValue(val);
    }
  }
}


void DocumentNode::appendStringValue(zstring& buf) const
{
  const_iterator ite = childrenBegin();
  const_iterator end = childrenEnd();

  for (; ite != end; ++ite)
  {
    store::StoreConsts::NodeKind kind = (*ite)->getNodeKind();

    if (kind != store::StoreConsts::commentNode &&
        kind != store::StoreConsts::piNode)
      (*ite)->appendStringValue(buf);
  }
}


/*******************************************************************************

********************************************************************************/
zstring DocumentNode::show() const
{
  std::stringstream strStream;

  strStream << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << std::endl
            << "<document";
  strStream << " baseUri = \"" << getBaseUri();
  strStream << " docUri = \"" << getDocUri();
  strStream << "\">" << std::endl;

  store::Iterator_t iter = getChildren();
  store::Item_t item;
  while (iter->next(item))
  {
    strStream << item->show();
  }

  strStream << std::endl << "</document>";

  return strStream.str();
}



/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class ElementNode                                                          //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************
  Node constructor used during loading of an xml doc
********************************************************************************/
ElementNode::ElementNode(
    store::Item_t& nodeName,
    csize numBindings,
    csize numAttributes)
  :
  InternalNode(store::StoreConsts::elementNode)
{
  theName.transfer(nodeName);
  setHaveValue();
  resetRecursive();

  if (numBindings > 0)
  {
    theNsContext = new NsBindingsContext(numBindings);
    theFlags |= HaveLocalBindings;
  }

  if (numAttributes > 0)
  {
    theNumAttrs = numAttributes;
    theNodes.resize(numAttributes);
  }

  NODE_TRACE1("Loaded elem node " << this << " name = " << theName->show()
              << " num bindings = " << numBindings << " num attributes = "
              << numAttributes << std::endl);
}


/*******************************************************************************
  Note: localBindings will be NULL if this contructor is called from the copy()
  method (because in that case, the in-scope bindings must be computed by the
  copy() method based on the copy mode). Otherwise, localBindings should not be
  NULL (but may be empty).
********************************************************************************/
ElementNode::ElementNode(
    XmlTree*                    tree,
    InternalNode*               parent,
    bool                        append,
    csize                       pos,
    store::Item_t&              nodeName,
    store::Item_t&              typeName,
    bool                        haveTypedValue,
    bool                        haveEmptyValue,
    bool                        isInSubstGroup,
    const store::NsBindings*    localBindings,
    zstring&                    baseUri)
  :
  InternalNode(tree, parent, append, pos, store::StoreConsts::elementNode)
{
  try
  {
    theName.transfer(nodeName);
    setType(typeName);

    if (haveTypedValue)
    {
      setHaveValue();

      if (haveEmptyValue)
        setHaveEmptyValue();
    }

    if (isInSubstGroup)
      setInSubstGroup();

    resetRecursive();

    if (localBindings)
    {
      if (!localBindings->empty())
      {
        theNsContext = new NsBindingsContext(*localBindings);
        theFlags |= HaveLocalBindings;
      }

      if (parent && parent->getNodeKind() == store::StoreConsts::elementNode)
      {
        setNsContext(reinterpret_cast<ElementNode*>(parent)->getNsContext());
      }
      else if (theNsContext == NULL)
      {
        // There is no parent or the parent is a doc node. Create an enpty
        // NsContext so that the (future) children of this node can inherit
        // from this NsContext. This way, if "this" node gets later inserted
        // under another node N and has to inherit the ns bindings of N, all
        // descendants of "this" will also inherit N's bindings by simply
        // setting this->theNsCntext->theParent to N->theNsContext.
        theNsContext = new NsBindingsContext();
        theFlags |= HaveLocalBindings;
      }

      addBindingForQName(theName, false, true);
    }

    // Note: Setting the base uri property of "this" involves the creation of an
    // attribute node having "this" as the parent. So, if addBaseUriProperty()
    // fails, we must manually remove that attribute to avoid memory leak.
    if (!baseUri.empty())
    {
      zstring dummy;
      addBaseUriProperty(baseUri, dummy);
    }

    // Connect this new node to its parent. Do this here (at the end of the try
    // stmt), so that we don't have to undo it inside the catch stmt.
    if (parent)
    {
      if (append)
        pos = parent->numChildren();

      parent->insertChild(this, pos);

      XmlNode* ancestor = parent;

      while (ancestor != NULL &&
             ancestor->getNodeKind() == store::StoreConsts::elementNode)
      {
        ElementNode* elemAncestor = reinterpret_cast<ElementNode*>(ancestor);
        if (elemAncestor->theName->equals(theName))
        {
          elemAncestor->setRecursive();
          break;
        }

        ancestor = ancestor->theParent;
      }
    }
  }
  catch (...)
  {
    theName = NULL;
    store::Item_t null;
    setType(null);
    theNsContext = NULL;

    if (numAttrs() != 0)
    {
      ulong pos = 0;
      XmlNode* attr = getAttr(pos);
      removeAttr(pos);
      delete attr;
    }

    throw;
  }

  NODE_TRACE1("Constructed element node " << this << " parent = "
              << std::hex << (parent ? (ulong)parent : 0) << " pos = " << pos
              << " tree = " << getTree()->getId() << ":" << getTree()
              << " ordpath = " << theOrdPath.show()
              << " name = " << theName->getStringValue()
              << " type = " << getType()->getStringValue());
}


/*******************************************************************************
  This is a recursive function that copies a subtree rooted at node N and places
  the copied subtree under the given "rootParent" node, making it the "pos"-th
  child of "rootParent".

  N is "this" node during the 1st (non-recursive) invocation of this method.
  During this 1st invocation, "rootParent" and "parent" point to the same node
  (which may be NULL), "pos" is the position under rootParent where the copied
  subtree will be placed at, and "rootCopy" is NULL.

  During a recursive invocation, "parent" is the copy of the parent of "this",
  In this case, the copy of "this" will be appended to the children's list of
  "parent".

  "rootCopy" is the first copied node, i.e., the copy of node N.
********************************************************************************/
XmlNode* ElementNode::copyInternal(
    InternalNode* rootParent,
    InternalNode* parent,
    csize pos,
    const XmlNode* rootCopy,
    const store::CopyMode& copymode) const
{
  assert(parent != NULL || rootParent == NULL);

  XmlTree* tree = NULL;
  ElementNode* copyNode = NULL;

  store::Item_t nodeName = theName;
  store::Item_t typeName;
  bool haveValue;
  bool haveEmptyValue;
  bool inSubstGroup;

  NsBindingsContext* myParentNsContext = NULL;
  NsBindingsContext* copyParentNsContext = NULL;
  NsBindingsContext* rootNsContext = NULL;

  if (theParent && theParent->getNodeKind() == store::StoreConsts::elementNode)
    myParentNsContext = static_cast<ElementNode*>(theParent)->getNsContext();

  if (parent && parent->getNodeKind() == store::StoreConsts::elementNode)
    copyParentNsContext = static_cast<ElementNode*>(parent)->getNsContext();

  if (rootParent && rootParent->getNodeKind() == store::StoreConsts::elementNode)
    rootNsContext = reinterpret_cast<ElementNode*>(rootParent)->getNsContext();

  if (copymode.theTypePreserve)
  {
    typeName = getType();
    haveValue = this->haveValue();
    haveEmptyValue = this->haveEmptyValue();
    inSubstGroup = this->isInSubstitutionGroup();
  }
  else
  {
    typeName = NULL;
    haveValue = true;
    haveEmptyValue = false;
    inSubstGroup = false;
  }

  zstring baseUri;

  try
  {
    if (parent == NULL)
      tree = NodeFactory::instance().createXmlTree();

    bool append = (parent != rootParent);

    copyNode = NodeFactory::instance().createElementNode(
                 tree, parent, append, pos,
                 nodeName, typeName,
                 haveValue, haveEmptyValue, inSubstGroup,
                 NULL, // local bindings
                 baseUri);

    if (rootCopy == NULL)
      rootCopy = copyNode;

    if (copymode.theNsPreserve)
    {
      // If we are copying the root of an xml subtree, or a node that does
      // not inherit ns bindings directly from its parent (but may inherit
      // from another ancestor).
      if (parent == rootParent ||
          (haveLocalBindings() && theNsContext->getParent() != myParentNsContext) ||
          (!haveLocalBindings() && theNsContext != myParentNsContext))
      {
        store::NsBindings bindings;
        getNamespaceBindings(bindings);

        if (!bindings.empty())
        {
          copyNode->theNsContext = new NsBindingsContext();
          copyNode->theNsContext->getBindings().swap(bindings);
          copyNode->theFlags |= HaveLocalBindings;
        }

        if (rootParent &&
            rootParent->getNodeKind() == store::StoreConsts::elementNode &&
            copymode.theNsInherit)
        {
          // If "this" does not belong to any namespace and the root parent
          // has a default ns binding, then undeclare this default binding.
          const zstring& prefix = theName->getPrefix();
          const zstring& nsuri = theName->getNamespace();
          if (prefix.empty() &&
              nsuri.empty() &&
              rootParent->getNodeKind() == store::StoreConsts::elementNode)
          {
            zstring ns;
            if (reinterpret_cast<ElementNode*>(rootParent)->findBinding(prefix, ns))
              copyNode->addLocalBinding(prefix, nsuri);
          }

          copyNode->setNsContext(rootNsContext);
        }
      }

      // Else the node we are copying is not the root of the xml subtree and
      // it inherits ns bindings directly from its parent.
      else
      {
        if (haveLocalBindings())
        {
          copyNode->theNsContext = new NsBindingsContext(getLocalBindings());
          copyNode->theFlags |= HaveLocalBindings;
        }

        if (parent && parent->getNodeKind() == store::StoreConsts::elementNode)
          copyNode->setNsContext(copyParentNsContext);
      }

      if (copyNode->theNsContext == NULL)
      {
        copyNode->theNsContext = new NsBindingsContext();
        copyNode->theFlags |= HaveLocalBindings;
      }
    }
    else // ! nsPreserve
    {
      if (copymode.theTypePreserve)
      {
        store::Item* typeName = getType();

        if (typeName != NULL &&
            (typeName->equals(GET_STORE().theSchemaTypeNames[XS_QNAME]) ||
             typeName->equals(GET_STORE().theSchemaTypeNames[XS_NOTATION])))
        {
          throw XQUERY_EXCEPTION(err::XQTY0086);
        }
      }

      const zstring& prefix = theName->getPrefix();
      zstring ns;

      bool found = getNsContext()->findBinding(prefix, ns);

      // binding may be absent only if the prefix was empty and there was no
      // default namespace declaration in scope.
      ZORBA_ASSERT(prefix.empty() || found);

      std::auto_ptr<NsBindingsContext> ctx(new NsBindingsContext);

      if (found)
      {
        zstring ns2;
        bool found2 = false;

        if (rootParent &&
            rootParent->getNodeKind() == store::StoreConsts::elementNode &&
            copymode.theNsInherit)
        {
          found2 = rootNsContext->findBinding(prefix, ns2);
        }

        if (!found2 || ns != ns2)
          ctx->addBinding(prefix, ns);
      }

      const_iterator ite = attrsBegin();
      const_iterator end = attrsEnd();

      for (; ite != end; ++ite)
      {
        const zstring& prefix = (*ite)->getNodeName()->getPrefix();
        bool found = getNsContext()->findBinding(prefix, ns);

        ZORBA_ASSERT(prefix.empty() || prefix == "xml" || found);

        if (found)
        {
          zstring ns2;
          bool found2 = false;

          if (rootParent &&
              rootParent->getNodeKind() == store::StoreConsts::elementNode &&
              copymode.theNsInherit)
          {
            found2 = rootNsContext->findBinding(prefix, ns2);
          }

          if (!found2 || ns != ns2)
            ctx->addBinding(prefix, ns);
        }
      }

      if (!ctx->empty())
      {
        copyNode->theNsContext = ctx.release();
        copyNode->theFlags |= HaveLocalBindings;
      }

      if (copymode.theNsInherit && rootParent)
      {
        copyNode->setNsContext(rootNsContext);
      }

      if (copyNode->theNsContext == NULL)
      {
        copyNode->theNsContext = new NsBindingsContext();
        copyNode->theFlags |= HaveLocalBindings;
      }
    }

    // Copy the attributes of this node
    AttributeNode* baseUriAttr = NULL;
    AttributeNode* hiddenBaseUriAttr = NULL;

    const_iterator ite = attrsBegin();
    const_iterator end = attrsEnd();

    for (; ite != end; ++ite)
    {
      AttributeNode* attr = static_cast<AttributeNode*>(*ite);

      if (attr->isBaseUri())
      {
        if (attr->isHidden())
        {
          hiddenBaseUriAttr = attr;
          continue;
        }
        else
        {
          baseUriAttr = attr;
        }
      }

      attr->copyInternal(rootParent, copyNode, 0, rootCopy, copymode);
    }

    if (hiddenBaseUriAttr)
    {
      if (parent == 0)
      {
        zstring absuri;
        hiddenBaseUriAttr->getStringValue2(absuri);
        zstring reluri;
        copyNode->addBaseUriProperty(absuri, reluri);
      }
      else if (baseUriAttr)
      {
        zstring absuri;
        zstring reluri;
        parent->getBaseURI(absuri);
        baseUriAttr->getBaseURI(reluri);

        copyNode->addBaseUriProperty(absuri, reluri);
      }
      else
      {
        // do not add explicit base uri property in the copy ==> copy inherits
        // the base-uri property of its parent.
      }
    }

    // Copy the children of this node
    ite = childrenBegin();
    end = childrenEnd();

    for (; ite != end; ++ite)
    {
      XmlNode* child = (*ite);

      // If we are copying a subtree into its own containing tree, then avoid
      // copying the root of this subtree again.
      if (child == rootCopy)
        continue;

      child->copyInternal(rootParent, copyNode, 0, rootCopy, copymode);
    }
  }
  catch (...)
  {
    if (tree)
    {
      tree->free();
    }
    else if (copyNode && (parent == rootParent))
    {
      copyNode->destroy(true);
    }

    throw;
  }

  NODE_TRACE1("Copied elem node " << this << " to node " << copyNode
              << " name = " << theName->getStringValue() << " parent = "
              << (parent ? parent : 0x0)
              << " pos = " << pos << " copy mode = " << copymode.toString());

  return copyNode;
}


/*******************************************************************************

********************************************************************************/
#ifdef EMBEDED_TYPE
store::Item* ElementNode::getType() const
{
  return (theTypeName != NULL ?
          theTypeName.getp() :
          GET_STORE().theSchemaTypeNames[XS_UNTYPED].getp());
}


void ElementNode::setType(store::Item_t& type)
{
  theTypeName.transfer(type);
}

#else

store::Item* ElementNode::getType() const
{
  return (haveType() ?
          getTree()->getType(this) :
          GET_STORE().theSchemaTypeNames[XS_UNTYPED].getp());
}


void ElementNode::setType(store::Item_t& type)
{
  if (haveType())
  {
    if (type == NULL ||
        type == GET_STORE().theSchemaTypeNames[XS_UNTYPED])
    {
      getTree()->removeType(this);
      resetHaveType();
    }
    else
    {
      getTree()->setType(this, type);
    }
  }
  else if (type != NULL &&
           type != GET_STORE().theSchemaTypeNames[XS_UNTYPED])
  {
    getTree()->addType(this, type);
    setHaveType();
  }
}

#endif


/*******************************************************************************

********************************************************************************/
bool ElementNode::haveTypedTypedValue() const
{
  if (numChildren() == 1 &&
      getChild(0)->getNodeKind() == store::StoreConsts::textNode)
  {
    if (reinterpret_cast<TextNode*>(getChild(0))->isTyped())
      return true;
  }

  return false;
}


/*******************************************************************************

********************************************************************************/
bool ElementNode::isId() const
{
  if (numChildren() == 1 &&
      getChild(0)->getNodeKind() == store::StoreConsts::textNode)
  {
		if (reinterpret_cast<TextNode*>(getChild(0))->isIdInternal())
      return true;
	}

  return false;
}


/*******************************************************************************

********************************************************************************/
bool ElementNode::isIdRefs() const
{
  if (numChildren() == 1 &&
      getChild(0)->getNodeKind() == store::StoreConsts::textNode)
  {
    if (reinterpret_cast<TextNode*>(getChild(0))->isIdRefsInternal())
      return true;
  }

  return false;
}


/*******************************************************************************

********************************************************************************/
void ElementNode::getTypedValue(store::Item_t& val, store::Iterator_t& iter) const
{
  if (haveValue())
  {
    if (haveEmptyValue())
    {
      val = NULL;
      iter = NULL;
    }
    else if (haveTypedTypedValue())
    {
      const TextNode* child = reinterpret_cast<const TextNode*>(getChild(0));

      if (child->haveListValue())
      {
        ItemVector* vec = reinterpret_cast<ItemVector*>(child->getValue());
        iter = new ItemIterator(vec->getItems(), true);
        val = NULL;
      }
      else
      {
        val = child->getValue();
        iter = NULL;
      }
    }
    else
    {
      zstring rch;
      getStringValue2(rch);
      GET_FACTORY().createUntypedAtomic(val, rch);
    }
  }
  else
  {
    throw XQUERY_EXCEPTION(
      err::FOTY0012,
      ERROR_PARAMS( theName->getStringValue(), getType()->getStringValue() )
    );
  }
}


/*******************************************************************************

********************************************************************************/
zstring ElementNode::getStringValue() const
{
  zstring strval;
  getStringValue2(strval);
  return strval;
}


/*******************************************************************************

********************************************************************************/
void ElementNode::getStringValue2(zstring& val) const
{
  store::StoreConsts::NodeKind kind;

  if (numChildren() == 1)
  {
    kind = getChild(0)->getNodeKind();

    if (kind != store::StoreConsts::commentNode &&
        kind != store::StoreConsts::piNode)
    {
      getChild(0)->getStringValue2(val);
    }
  }
  else
  {
    const_iterator ite = childrenBegin();
    const_iterator end = childrenEnd();

    for (; ite != end; ++ite)
    {
      kind = (*ite)->getNodeKind();

      if (kind != store::StoreConsts::commentNode &&
          kind != store::StoreConsts::piNode)
        (*ite)->appendStringValue(val);
    }
  }
}


/*******************************************************************************

********************************************************************************/
void ElementNode::appendStringValue(zstring& buf) const
{
  const_iterator ite = childrenBegin();
  const_iterator end = childrenEnd();

  for (; ite != end; ++ite)
  {
    store::StoreConsts::NodeKind kind = (*ite)->getNodeKind();

    if (kind != store::StoreConsts::commentNode &&
        kind != store::StoreConsts::piNode)
      (*ite)->appendStringValue(buf);
  }
}


/*******************************************************************************

********************************************************************************/
store::Item_t ElementNode::getNilled() const
{
  store::Item_t val;

  if (getType()->equals(GET_STORE().theSchemaTypeNames[XS_UNTYPED]))
  {
    GET_STORE().getItemFactory()->createBoolean(val, false);
    return val;
  }

  bool nilled = true;

  const_iterator ite = childrenBegin();
  const_iterator end = childrenEnd();

  for (; ite != end; ++ite)
  {
    if ((*ite)->getNodeKind() == store::StoreConsts::elementNode ||
        (*ite)->getNodeKind() == store::StoreConsts::textNode)
    {
      nilled = false;
      break;
    }
  }

  if (!nilled)
  {
    GET_FACTORY().createBoolean(val, false);
    return val;
  }

  nilled = false;

  //const char* xsi = "http://www.w3.org/2001/XMLSchema-instance";
  //ulong xsilen = strlen(xsi);

  ite = attrsBegin();
  end = attrsEnd();

  for (; ite != end; ++ite)
  {
    AttributeNode* attr = static_cast<AttributeNode*>(*ite);
    if (ZSTREQ(attr->getNodeName()->getNamespace(), "xsi") &&
        ZSTREQ(attr->getNodeName()->getLocalName(), "nil"))
    {
      nilled = true;
      break;
    }
  }

  GET_STORE().getItemFactory()->createBoolean(val, nilled);
  return val;
}


/*******************************************************************************

********************************************************************************/
store::Iterator_t ElementNode::getAttributes() const
{
  AttributesIteratorImpl* res = new AttributesIteratorImpl();
  res->init(this);
  return res;
}


/*******************************************************************************

********************************************************************************/
store::Iterator_t ElementNode::getChildren() const
{
  ChildrenIteratorImpl* res = new ChildrenIteratorImpl();
  res->init((XmlNode*)this);
  return res;
}


/*******************************************************************************
  Carefull with this function: it generates the namespaces in the reverse order.
  The higher parent gives the latest namespaces, instead of first.
********************************************************************************/
void ElementNode::getNamespaceBindings(
    store::NsBindings&            bindings,
    store::StoreConsts::NsScoping ns_scoping) const
{
  assert(bindings.empty());
  assert(theNsContext != NULL);

  if (ns_scoping != store::StoreConsts::ONLY_PARENT_NAMESPACES)
  {
    bindings = theNsContext->getBindings();
  }

  if (ns_scoping == store::StoreConsts::ONLY_LOCAL_NAMESPACES)
    return;

  const NsBindingsContext* parentContext = theNsContext->getParent();

  while (parentContext != NULL)
  {
    const store::NsBindings& parentBindings = parentContext->getBindings();
    csize parentSize = parentBindings.size();
    csize currSize = bindings.size();

    // for each parent binding, add it to the result, if it doesn't have the
    // same prefix as another binding that is already in the result.
    for (csize i = 0; i < parentSize; ++i)
    {
      csize j;
      for (j = 0; j < currSize; ++j)
      {
        if (bindings[j].first == parentBindings[i].first)
          break;
      }

      if (j == currSize)
      {
        bindings.push_back(parentBindings[i]);
      }
    }

    parentContext = parentContext->getParent();
  }

  return;
}


/*******************************************************************************
  Make "this" inherit the ns bindings of its parent.
********************************************************************************/
void ElementNode::setNsContext(NsBindingsContext* parentCtx)
{
  assert(parentCtx != NULL);

  if (theNsContext == NULL)
  {
    theNsContext = parentCtx;
  }
  else if (theNsContext.getp() != parentCtx)
  {
    theNsContext->setParent(parentCtx);
  }
}


/*******************************************************************************
  Search all the in-scope ns bindings of "this" to find the ns uri associated
  with the given prefix. Return NULL if no binding exists for the given prefix.
********************************************************************************/
bool ElementNode::findBinding(const zstring& prefix, zstring& uri) const
{
  assert(theNsContext != NULL);

  return theNsContext->findBinding(prefix, uri);
}


/*******************************************************************************

********************************************************************************/
const store::NsBindings& ElementNode::getLocalBindings() const
{
  ZORBA_ASSERT(haveLocalBindings());
  return theNsContext->getBindings();
}


/*******************************************************************************
  Add the ns binding that is implied by the given qname, if such a binding does
  not exist already among the bindings of "this" node. The method returns true
  if a binding was added, or false otherwise.

  The method also checks if the given binding conflicts with the current bindings
  of "this" node. If a conflict exists and replacePrefix is false, an error is
  thrown. Else, if a conflict exists and replacePrefix is true, then the method
  creates and returns a qname with the same local name and ns uri as the given
  qname, but with a prefix that is artificially generated so that the conflict
  is resolved.

  This method is used by the ElementNode and AttributeNode constructors with
  replacePrefix set to true. It is also used by updating methods with
  replacePrefix set to false.
********************************************************************************/
bool ElementNode::addBindingForQName(
    store::Item_t& qname,
    bool           isAttr,
    bool           replacePrefix)
{
  const zstring& prefix = qname->getPrefix();
  const zstring& ns = qname->getNamespace();

  // If ns is empty, then prefix must be empty
  ZORBA_FATAL(!ns.empty() || prefix.empty(),
              "prefix = " << prefix << " ns = " << ns);

  // No ns binding is implied by an attribute qname whose ns uri is empty
  if (ns.empty() && isAttr)
    return false;

  if (prefix != "xml")
  {
    zstring ns2;
    bool found = findBinding(prefix, ns2);

    if (!found)
    {
      if (!ns.empty())
      {
        addLocalBinding(prefix, ns);
        return true;
      }
    }
    else if (ns2 != ns)
    {
      if (ns2.empty())
      {
        if (!haveLocalBindings())
        {
          theNsContext = new NsBindingsContext(theNsContext.getp());
        }

        theNsContext->updateBinding(prefix, ns);
      }

      if (replacePrefix)
      {
        //std::cout << "Prefix: " << prefix << " ns: " << ns << " ns2: " << ns2 << " local: " << qname->getLocalName() << "\n";
        ZORBA_FATAL(!ns.empty(), "");

        zstring prefix("XXX");
        zstring dummy;

        while (findBinding(prefix, dummy))
          prefix += "X";

        GET_FACTORY().createQName(qname, ns, prefix, qname->getLocalName());
        addLocalBinding(prefix, ns);
        return true;
      }
      else
      {
        throw XQUERY_EXCEPTION(
          err::XUDY0024, ERROR_PARAMS( qname->show(), prefix, ns2 )
        );
      }
    }
  }

  return false;
}


/*******************************************************************************
  Same as above, but used when we know that no ns binding conflict exists
********************************************************************************/
void ElementNode::addBindingForQName2(const store::Item* qname)
{
  const zstring& prefix = qname->getPrefix();
  const zstring& ns = qname->getNamespace();

  // If ns is empty, then prefix must be empty
  ZORBA_FATAL(!ns.empty() || prefix.empty(),
              "prefix = " << prefix << "ns = " << ns);

  if (prefix != "xml")
  {
    zstring ns2;
    bool found = findBinding(prefix, ns2);

    if (!found)
    {
      if (!ns.empty())
        addLocalBinding(prefix, ns);
    }
    else if (ns2 != ns)
    {
      ZORBA_FATAL(0, "");
    }
  }
}


/*******************************************************************************
  Add a given ns binding to the local ns bindings of "this", if it's not already
  there. It is assumed that the given binding does not conflit with the other
  local bindings of "this" (ZORBA_FATAL is called if this condition is not true).

  Note: it is possible to add the binding (empty --> empty); this happens when we
  need to delete the default binding (empty --> ns) from the bindings of "this".
********************************************************************************/
void ElementNode::addLocalBinding(const zstring& prefix, const zstring& ns)
{
  if (!haveLocalBindings())
  {
    NsBindingsContext* parent = theNsContext;
    theNsContext = new NsBindingsContext();
    theNsContext->setParent(parent);
  }

  theNsContext->addBinding(prefix, ns);

  theFlags |= HaveLocalBindings;
}


/*******************************************************************************
  Remove the given ns binding from the local ns bindings of "this", if it is
  there.
********************************************************************************/
void ElementNode::removeLocalBinding(const zstring& prefix, const zstring& ns)
{
  if (haveLocalBindings())
    theNsContext->removeBinding(prefix, ns);
}

#if 1
/*******************************************************************************

********************************************************************************/
void ElementNode::uninheritBinding(
    NsBindingsContext* rootNSCtx,
    const zstring& prefix)
{
  if (theNsContext.getp() == rootNSCtx || theNsContext->getParent() == rootNSCtx)
  {
    if (theNsContext.getp() == rootNSCtx)
    {
      theNsContext = new NsBindingsContext;
    }

    zstring emptyStr;

    theNsContext->addBinding(prefix, emptyStr, true);
  }

  const_iterator ite = childrenBegin();
  const_iterator end = childrenEnd();

  for (; ite != end; ++ite)
  {
    if ((*ite)->getNodeKind() == store::StoreConsts::elementNode)
    {
      static_cast<ElementNode*>((*ite))->uninheritBinding(rootNSCtx, prefix);
    }
  }
}
#endif

/*******************************************************************************
  Check if the ns binding implied by the given qname conflicts with the current
  ns bindings of "this" node.
********************************************************************************/
void ElementNode::checkNamespaceConflict(
    const store::Item*  qname,
    Error const& ecode) const
{
  const QNameItem* qn = reinterpret_cast<const QNameItem*>(qname);

  const zstring& prefix = qn->getPrefix();
  const zstring& ns = qn->getNamespace();

  // Nothing to do if the qname does not imply any ns binding
  if (prefix.empty() && ns.empty())
    return;

  zstring ns2;
  bool found = findBinding(prefix, ns2);

  if (found && ns2 != ns)
  {
    throw XQUERY_EXCEPTION_VAR(
      ecode, ERROR_PARAMS( qname->show(), prefix, ns2 )
    );
  }
}


/*******************************************************************************
  Check that "this" does not have an attr with the same name as the given name.
********************************************************************************/
void ElementNode::checkUniqueAttr(const store::Item* attrName) const
{
  const_iterator ite = attrsBegin();
  const_iterator end = attrsEnd();

  for (; ite != end; ++ite)
  {
    AttributeNode* attr = static_cast<AttributeNode*>(*ite);
    if (!attr->isHidden() && attr->getNodeName()->equals(attrName))
    {
      throw XQUERY_EXCEPTION(
        err::XQDY0025, ERROR_PARAMS( attrName->getStringValue() )
      );
    }
  }
}


/*******************************************************************************
  Check that "this" does not have any attrs with the same name.
********************************************************************************/
void ElementNode::checkUniqueAttrs() const
{
  const_iterator ite = attrsBegin();
  const_iterator end = attrsEnd();

  for (; ite != end; ++ite)
  {
    AttributeNode* attr = static_cast<AttributeNode*>(*ite);

    if (attr->isHidden())
      continue;

    const store::Item* attrName = attr->theName.getp();

    const_iterator ite2 = ite + 1;

    for (; ite2 != end; ++ite2)
    {
      AttributeNode* otherAttr = static_cast<AttributeNode*>(*ite2);

      if (!otherAttr->isHidden() && otherAttr->getNodeName()->equals(attrName))
      {
        throw XQUERY_EXCEPTION(
          err::XUDY0021, ERROR_PARAMS( attrName->getStringValue() )
        );
      }
    }
  }
}


/*******************************************************************************
  Compute the base-uri property of this element node and store it as a a special
  (hidden) attribute of the node. In general, the base-uri property is computed
  by resolving the "relUri" based on the absolute "absUri". However, if "relUri"
  is an absolute uri already, the base-uri property of the node is set to "relUri".
  It is also possible that "relUri" is empty, in which case, the base-uri property
  of the node is set to "absUri".

  It is assumed that both "absUri" and "relUri" (if not empty) are well-formed
  uri strings.
********************************************************************************/
void ElementNode::addBaseUriProperty(
    zstring& absUri,
    zstring& relUri)
{
  ZORBA_FATAL(!absUri.empty(), "");

  const SimpleStore& store = GET_STORE();

  store::Item_t qname = store.getQNamePool().insert(store.XML_URI, "xml", "base");
  store::Item_t typeName = store.theSchemaTypeNames[XS_ANY_URI];

  store::Item_t typedValue;

  if (relUri.empty())
  {
    GET_STORE().getItemFactory()->createAnyURI(typedValue, absUri);
  }
  else
  {
    zstring resolvedUriString;

    try
    {
      URI absoluteURI(absUri);
      URI resolvedURI(absoluteURI, relUri);
      resolvedUriString = resolvedURI.toString();
    }
    catch (ZorbaException const&)
    {
      resolvedUriString = relUri;
    }

    GET_STORE().getItemFactory()->createAnyURI(typedValue, resolvedUriString);
  }

  checkUniqueAttr(qname.getp());

  // this might look like a nop but it isn't
  // the this pointer is used in the constructor to
  // attach it to the parent
  GET_NODE_FACTORY().createAttributeNode(
    NULL,  // xml tree
    this,  // parent
    false, // not append
    0,     // position
    qname,
    typeName,
    typedValue,
    false, // isListVale
    true); // hidden

  setHaveBaseUri();
}


/*******************************************************************************
  Change the base-uri property of this node. The new base-uri value is computed
  by resolving the "relUri" based on the "absUri". If "relUri" is NULL, then the
  new base-uri value is set to "absUri". If "relUri" is already an absolute uri,
  then the new base-uri value is set to "relUri". "attr" is the hidden attribute
  that stores the base-uri value.
********************************************************************************/
void ElementNode::adjustBaseUriProperty(
    AttributeNode* attr,
    zstring& absUri,
    zstring& relUri)
{
  ZORBA_FATAL(!absUri.empty(), "");

  store::Item_t typedValue;
  if (relUri == NULL)
  {
    GET_FACTORY().createAnyURI(typedValue, absUri);
  }
  else
  {
    zstring resolvedUriString;

    try
    {
      URI lAbsoluteUri(absUri);
      URI lResolvedUri(lAbsoluteUri, relUri);
      resolvedUriString = lResolvedUri.toString();
    }
    catch (ZorbaException const& e)
    {
      ZORBA_FATAL( false, e.what() );
    }

    GET_FACTORY().createAnyURI(typedValue, resolvedUriString);
  }

  attr->setTypedValue(typedValue);
}


/*******************************************************************************

********************************************************************************/
void ElementNode::getBaseURIInternal(zstring& uri, bool& local) const
{
  const_iterator ite = attrsBegin();
  const_iterator end = attrsEnd();

  for (; ite != end; ++ite)
  {
    AttributeNode* attr = static_cast<AttributeNode*>(*ite);

    if (attr->isBaseUri() && attr->isHidden())
    {
      local = true;
      attr->getStringValue2(uri);
      return;
    }
  }

  local = false;

  if (theParent)
    theParent->getBaseURI(uri);
}


/*******************************************************************************

********************************************************************************/
zstring ElementNode::show() const
{
  std::stringstream str;

  str <<  "<" << theName->getStringValue() << "-elem";

  str << " nid=\"" << theOrdPath.show() << "\"";

  store::NsBindings nsBindings;
  getNamespaceBindings(nsBindings);

  for (ulong i = 0; i < nsBindings.size(); i++)
  {
    str << " xmlns:" <<  nsBindings[i].first << "=\""
        << nsBindings[i].second << "\"";
  }

  store::Iterator_t iter = getAttributes();
  store::Item_t item;
  while (iter->next(item))
  {
    str << " " << item->show();
  }

  str << ">";

  iter = getChildren();
  iter->open();
  while (iter->next(item))
  {
    str << item->show();
  }

  str << "</" << theName->getStringValue() << "-elem>";
  return str.str();
}



/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class AttributeNode                                                        //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************
  Node constructor used by FastXmlLoader only.
********************************************************************************/
AttributeNode::AttributeNode(store::Item_t& attrName)
  :
  OrdPathNode(store::StoreConsts::attributeNode)
{
  theName.transfer(attrName);

  QNameItem* qn = reinterpret_cast<QNameItem*>(theName.getp());

  if (qn->isBaseUri())
    theFlags |= IsBaseUri;

  NODE_TRACE1("Loaded attr node " << this << " name = " << theName->getStringValue());
}


/*******************************************************************************
  Note: Constructor does NOT check whether the the attr node to create has the
  same name as an existing attr of the parent node. This is so because sometimes
  we know that a name conflict cannot arise (e.g. when the attr is created as
  part of a subtree copy, and the root node of that subtree is not an attr node),
  so we save the overhead of checking. When a check is required, it is the
  responsibility of the caller to call checkUniqueAttr() on the parent before
  invoking this constructor.
********************************************************************************/
AttributeNode::AttributeNode(
    XmlTree* tree,
    ElementNode* parent,
    bool append,
    csize pos,
    store::Item_t& attrName,
    store::Item_t& typeName,
    store::Item_t& typedValue,
    bool isListValue,
    bool hidden)
  :
  OrdPathNode(tree, parent, append, pos, store::StoreConsts::attributeNode)
{
  // Normally, no exceptions are expected by the rest of the code here, but
  // just to be safe, we use a try-catch.
  try
  {
    if (attrName->getPrefix().empty() && !attrName->getNamespace().empty())
    {
      zstring prefix;
      const zstring& lAttrNs = attrName->getNamespace();
      if (lAttrNs == XML_NS)
        prefix = "xml";
      else if (lAttrNs == XMLNS_NS)
        prefix = "xmlns";
      else
        prefix = "XXX";

      GET_FACTORY().createQName(attrName,
                                attrName->getNamespace(),
                                prefix,
                                attrName->getLocalName());
    }

    theName.transfer(attrName);
    theTypedValue.transfer(typedValue);
    setType(typeName);

    if (isListValue)
      setHaveListValue();

    QNameItem* qn = reinterpret_cast<QNameItem*>(theName.getp());

    if (qn->isBaseUri())
      theFlags |= IsBaseUri;

    if (hidden)
      setHidden();

    if (parent)
    {
      // If this is an explicit base uri attribute, (a) set or update the base-uri
      // property of the parent, and (b) create an additional hidden base-uri attr
      // with the resolved version of the given uri.
      if (isBaseUri() && !isHidden())
      {
        zstring parentBaseUri;
        parent->getBaseURI(parentBaseUri);
        zstring baseUri;
        this->getStringValue2(baseUri);

        if (parent->haveBaseUri())
        {
          InternalNode::const_iterator ite = parent->attrsBegin();
          InternalNode::const_iterator end = parent->attrsEnd();

          for (; ite != end; ++ite)
          {
            AttributeNode* attr = static_cast<AttributeNode*>(*ite);

            if (attr->isBaseUri() && attr->isHidden())
            {
              attr->destroy(true);
              break;
            }
          }
        }

        if (parentBaseUri.empty())
          parent->addBaseUriProperty(baseUri, parentBaseUri);
        else
          parent->addBaseUriProperty(parentBaseUri, baseUri);
      }

      // Else, add the ns binding implied by the attr name into the in-scope ns
      // bindings of the parent (if this ns binding is not there already)
      else if (!isHidden())
      {
        parent->addBindingForQName(theName, true, true);
      }

      // Connect "this" to its parent. We do this at the end of this method
      // so that we don't have to undo it inside the catch clause below.

      if (append)
        pos = parent->numAttrs();

      parent->insertAttr(this, pos);
    }
  }
  catch (...)
  {
    theName = NULL;
    theTypedValue = NULL;
    store::Item_t null;
    setType(null);

    throw;
  }

  NODE_TRACE1("Constructed attribute node " << this << " parent = "
              << std::hex << (parent ? (ulong)parent : 0) << " pos = " << pos
              << " tree = " << getTree()->getId() << ":" << getTree()
              << " ordpath = " << theOrdPath.show()
              << " name = " << theName->getStringValue()
              << " value = " << getStringValue());
}


/*******************************************************************************

********************************************************************************/
XmlNode* AttributeNode::copyInternal(
    InternalNode* rootParent,
    InternalNode* parent,
    csize pos,
    const XmlNode* rootCopy,
    const store::CopyMode& copymode) const
{
  assert(parent != NULL || rootParent == NULL);
  ZORBA_FATAL(!isHidden(), "");

  SimpleStore& store = GET_STORE();

  XmlTree* tree = NULL;
  AttributeNode* copyNode = NULL;
  store::Item_t nodeName = theName;
  store::Item_t typeName;
  store::Item_t typedValue;

  bool isListValue;

  if (copymode.theTypePreserve)
  {
    typeName = getType();
    typedValue = theTypedValue;

    isListValue = haveListValue();
  }
  else
  {
    isListValue = false;

    typeName = NULL;

    if (!haveListValue() &&
        theTypedValue->getType()->equals(store.theSchemaTypeNames[XS_UNTYPED_ATOMIC]))
    {
      typedValue = theTypedValue;
    }
    else
    {
      zstring rch;
      getStringValue2(rch);
      GET_STORE().getItemFactory()->createUntypedAtomic(typedValue, rch);
    }
  }

  try
  {
    if (parent == NULL)
      tree = GET_STORE().getNodeFactory().createXmlTree();

    else if (parent == rootParent)
      reinterpret_cast<ElementNode*>(parent)->checkUniqueAttr(nodeName);

    bool append = (rootParent != parent);

    copyNode = GET_STORE().getNodeFactory().createAttributeNode(
                 tree,
                 static_cast<ElementNode*>(parent),
                 append,
                 pos,
                 nodeName,
                 typeName, typedValue, isListValue,
                 false); // hidden
  }
  catch (...)
  {
    delete tree;
    throw;
  }

  NODE_TRACE1("Copied attribute node " << this << " to node " << copyNode
              << " name = " << theName->show() << " parent = "
              << std::hex << (parent ? (ulong)parent : 0) << " pos = " << pos
              << " copy mode = " << copymode.toString());

  return copyNode;
}


/*******************************************************************************

********************************************************************************/
#ifdef EMBEDED_TYPE
store::Item* AttributeNode::getType() const
{
  return (theTypeName != NULL ?
          theTypeName.getp() :
          GET_STORE().theSchemaTypeNames[XS_UNTYPED_ATOMIC].getp());
}


void AttributeNode::setType(store::Item_t& type)
{
  theTypeName.transfer(type);
}

#else

store::Item* AttributeNode::getType() const
{
  return (haveType() ?
          getTree()->getType(this) :
          GET_STORE().theSchemaTypeNames[XS_UNTYPED_ATOMIC].getp());
}


void AttributeNode::setType(store::Item_t& type)
{
  if (haveType())
  {
    if (type == NULL ||
        type == GET_STORE().theSchemaTypeNames[XS_UNTYPED_ATOMIC])
    {
      getTree()->removeType(this);
      resetHaveType();
    }
    else
    {
      getTree()->setType(this, type);
    }
  }
  else if (type != NULL &&
           type != GET_STORE().theSchemaTypeNames[XS_UNTYPED_ATOMIC])
  {
    getTree()->addType(this, type);
    setHaveType();
  }
}

#endif

/*******************************************************************************

********************************************************************************/
void AttributeNode::setTypedValue(store::Item_t& value)
{
  resetHaveListValue();
  theTypedValue.transfer(value);
}


/*******************************************************************************

********************************************************************************/
void AttributeNode::getTypedValue(store::Item_t& val, store::Iterator_t& iter) const
{
  if (haveListValue())
  {
    iter = new ItemIterator(getValueVector().getItems(), true);
    val = NULL;
  }
  else
  {
    val = theTypedValue;
    iter = NULL;
  }
}


/*******************************************************************************

********************************************************************************/
bool AttributeNode::isId() const
{
  QNameItem* qn = reinterpret_cast<QNameItem*>(theName.getp());

  if (qn->isIdQName())
    return true;

  if (dynamic_cast<IDItem*>(theTypedValue.getp()) != NULL)
    return true;

  return false;
}


/*******************************************************************************

********************************************************************************/
bool AttributeNode::isIdRefs() const
{
  if (haveListValue())
  {
    const ItemVector& values = getValueVector();
    ulong numValues = values.size();

    for (ulong i = 0; i < numValues; ++i)
    {
      if (dynamic_cast<IDREFItem*>(values.getItem(i)) != NULL)
      {
        return true;
      }
      else if (dynamic_cast<UserTypedAtomicItem*>(values.getItem(i)) != NULL)
      {
        UserTypedAtomicItem* utai = dynamic_cast<UserTypedAtomicItem*>(values.getItem(i));
        if ( utai->getTypeCode() == XS_IDREF )
          return true;
        if ( (dynamic_cast<AtomicItem*>(utai->getBaseItem()))->getTypeCode() == XS_IDREF )
          return true;
      }
    }
  }
  else if (dynamic_cast<IDREFItem*>(theTypedValue.getp()) != NULL)
  {
    return true;
  }
  else if (dynamic_cast<UserTypedAtomicItem*>(theTypedValue.getp()) != NULL)
  {
    UserTypedAtomicItem* utai = dynamic_cast<UserTypedAtomicItem*>(theTypedValue.getp());
    if ( utai->getTypeCode() == XS_IDREF )
      return true;
    if ( (dynamic_cast<AtomicItem*>(utai->getBaseItem()))->getTypeCode() == XS_IDREF )
      return true;
  }

  return false;
}


/*******************************************************************************

********************************************************************************/
zstring AttributeNode::getStringValue() const
{
  zstring strval;
  getStringValue2(strval);
  return strval;
}


void AttributeNode::getStringValue2(zstring& val) const
{
  if (haveListValue())
  {
    const std::vector<store::Item_t>& items = getValueVector().getItems();

    ulong size = (ulong)items.size();

    if (size == 1)
    {
      items[0]->getStringValue2(val);
    }
    else if (size > 0)
    {
      items[0]->appendStringValue(val);

      for (ulong i = 1; i < size; ++i)
      {
        val += " ";
        items[i]->appendStringValue(val);
      }
    }
  }
  else
  {
    theTypedValue->getStringValue2(val);
  }
}


void AttributeNode::appendStringValue(zstring& buf) const
{
  if (haveListValue())
  {
    const std::vector<store::Item_t>& items = getValueVector().getItems();

    ulong size = (ulong)items.size();

    if (size > 0)
    {
      items[0]->appendStringValue(buf);

      for (ulong i = 1; i < size; i++)
      {
        buf += " ";
        items[i]->appendStringValue(buf);
      }
    }
  }
  else
  {
    theTypedValue->appendStringValue(buf);
  }
}


/*******************************************************************************

********************************************************************************/
zstring AttributeNode::show() const
{
  return theName->getStringValue() + "=\"" + getStringValue() + "\"";
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class TextNode                                                             //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************
  Node constructor used by FastXmlLoader
********************************************************************************/
TextNode::TextNode(zstring& content)
  :
#ifdef TEXT_ORDPATH
  OrdPathNode(store::StoreConsts::textNode)
#else
  XmlNode(store::StoreConsts::textNode)
#endif
{
  setText(content);

  NODE_TRACE1("Loaded text node " << this << " content = " << getText());
}


/*******************************************************************************
  Note: constructor does NOT check if the new text node will be adjacent to an
  existing text node of the parent. This is so because sometimes we know that
  this case cannot arise (e.g. when the text node is created as part of a subtree
  copy, and the root node of that subtree is not a text node), so we save the
  overhead of checking. When a check is required, it is the responsibility of
  the caller to merge the new text content into the existing text node and skip
  invoking this constructor.
********************************************************************************/
TextNode::TextNode(
    XmlTree* tree,
    InternalNode* parent,
    bool append,
    csize pos,
    zstring& content)
  :
#ifdef TEXT_ORDPATH
  OrdPathNode(tree, parent, append, pos, store::StoreConsts::textNode)
#else
  XmlNode(tree, parent, store::StoreConsts::textNode)
#endif
{
  setText(content);

  if (parent)
  {
#ifndef NDEBUG
    if (parent->getNodeKind() == store::StoreConsts::elementNode &&
        parent->numChildren() == 1 &&
        parent->getChild(0)->getNodeKind() == store::StoreConsts::textNode)
    {
      TextNode* textChild = reinterpret_cast<TextNode*>(parent->getChild(0));
      ZORBA_ASSERT(!textChild->isTyped());
    }
#endif

    if (append)
      pos = parent->numChildren();

    parent->insertChild(this, pos);
  }

#ifdef TEXT_ORDPATH
  NODE_TRACE1("Constructed text node " << this << " parent = "
              << std::hex << (parent ? (ulong)parent : 0) << " pos = " << pos
              << " tree = " << getTree()->getId() << ":" << getTree()
              << " ordpath = " << theOrdPath.show()
              << " content = " << getText());
#else
  NODE_TRACE1("Constructed text node " << this << " parent = "
              << std::hex << (parent ? (ulong)parent : 0) << " pos = " << pos
              << " tree = " << getTree()->getId() << ":" << getTree()
              << " content = " << getText());
#endif
}


/*******************************************************************************

********************************************************************************/
TextNode::TextNode(
    InternalNode*  parent,
    store::Item_t& content,
    bool           isListValue)
  :
#ifdef TEXT_ORDPATH
  OrdPathNode(NULL, parent, true, 0, store::StoreConsts::textNode)
#else
  XmlNode(NULL, parent, store::StoreConsts::textNode)
#endif
{
  assert(parent != NULL);

  ZORBA_ASSERT(parent->getNodeKind() == store::StoreConsts::elementNode);

  ElementNode* p = reinterpret_cast<ElementNode*>(parent);

  ZORBA_ASSERT(p->numChildren() == 0);
  ZORBA_ASSERT(p->haveValue() && !p->haveEmptyValue());

  setTypedValue(content);
  if (isListValue)
    setHaveListValue();

  p->insertChild(this, 0);

#ifdef TEXT_ORDPATH
  NODE_TRACE1("Constructed text node " << this << " parent = "
              << std::hex << (parent ? (ulong)parent : 0)
              << " ordpath = " << theOrdPath.show()
              << " content = " << getValue()->getStringValue());
#else
  NODE_TRACE1("Constructed text node " << this << " parent = "
              << std::hex << (parent ? (ulong)parent : 0)
              << " content = " << getValue()->getStringValue());
#endif
}


/*******************************************************************************

********************************************************************************/
XmlNode* TextNode::copyInternal(
    InternalNode* rootParent,
    InternalNode* parent,
    csize pos,
    const XmlNode* rootCopy,
    const store::CopyMode& copymode) const
{
  assert(parent != NULL || rootParent == NULL);

  NodeFactory& factory = NodeFactory::instance();

  XmlTree* tree = NULL;
  TextNode* copyNode = NULL;
  store::Item_t typedContent;

  try
  {
    if (parent == NULL)
    {
      tree = factory.createXmlTree();

      zstring content = getText();
      copyNode = factory.createTextNode(tree, NULL, true, pos, content);
    }
    else
    {
      if (parent == rootParent)
      {
        // We are copying a subtree consisting of a single text node ("this").
        // The text node may or may not be typed, but the copied node will
        // always be untyped.

        // Merge adjacent text nodes.
        ulong numChildren = parent->numChildren();

        XmlNode* lsib = (pos > 0 ? parent->getChild(pos-1) : NULL);
        XmlNode* rsib = (pos < numChildren ? parent->getChild(pos) : NULL);

        if (lsib != NULL &&
            lsib->getNodeKind() == store::StoreConsts::textNode)
        {
          TextNode* textSibling = reinterpret_cast<TextNode*>(lsib);
          ZORBA_ASSERT(!textSibling->isTyped());

          zstring content = textSibling->getText();
          appendStringValue(content);

          textSibling->setText(content);
          copyNode = textSibling;
        }
        else if (rsib != NULL &&
                 rsib->getNodeKind() == store::StoreConsts::textNode)
        {
          TextNode* textSibling = reinterpret_cast<TextNode*>(rsib);
          ZORBA_ASSERT(!textSibling->isTyped());

          zstring content;
          getStringValue2(content);
          content += textSibling->getText();

          textSibling->setText(content);
          copyNode = textSibling;
        }
        else if (isTyped())
        {
          zstring content;
          getValue()->getStringValue2(content);
          copyNode = factory.createTextNode(NULL, parent, false, pos, content);
        }
        else
        {
          zstring content = getText();
          copyNode = factory.createTextNode(NULL, parent, false, pos, content);
        }
      }
      else if (isTyped())
      {
        if (copymode.theTypePreserve)
        {
          typedContent = getValue();
          copyNode = factory.createTextNode(parent, typedContent, haveListValue());
        }
        else
        {
          zstring content;
          getValue()->getStringValue2(content);
          copyNode = factory.createTextNode(NULL, parent, true, pos, content);
        }
      }
      else
      {
        zstring content = getText();
        copyNode = factory.createTextNode(NULL, parent, true, pos, content);
      }
    }
  }
  catch (...)
  {
    delete tree;
    throw;
  }

  NODE_TRACE1("Copied text node " << this << " to node " << copyNode
              << " parent = " << std::hex << (parent ? (ulong)parent : 0)
              << " pos = " << pos);

  return copyNode;
}



/*******************************************************************************

********************************************************************************/
bool TextNode::isTyped() const
{
  return (theFlags & IsTyped) != 0;
}


/*******************************************************************************

********************************************************************************/
void TextNode::setTypedValue(store::Item_t& value)
{
  if (!isTyped())
  {
    destroyText();

    setValue(value);

    theFlags |= IsTyped;
  }
  else
  {
    setValue(value);
  }
}


/*******************************************************************************

********************************************************************************/
void TextNode::revertToTextContent()
{
  if (isTyped())
  {
    zstring textValue;
    getStringValue2(textValue);

    setValue(NULL);

    setText(textValue);

    theFlags &= ~IsTyped;
  }
}


/*******************************************************************************

********************************************************************************/
store::Item* TextNode::getType() const
{
  return GET_STORE().theSchemaTypeNames[XS_UNTYPED_ATOMIC];
}


/*******************************************************************************

********************************************************************************/
void TextNode::getTypedValue(store::Item_t& val, store::Iterator_t& iter) const
{
  zstring rch;

  if (isTyped())
  {
    getValue()->getStringValue2(rch);
    GET_STORE().getItemFactory()->createUntypedAtomic(val, rch);
  }
  else
  {
    rch = getText();
    GET_STORE().getItemFactory()->createUntypedAtomic(val, rch);
  }
  iter = NULL;
}


/*******************************************************************************

********************************************************************************/
bool TextNode::isIdInternal() const
{
  if (isTyped() &&
    (static_cast<AtomicItem*>(getValue()))->isAtomic() &&
    (static_cast<AtomicItem*>(getValue()))->getTypeCode() == XS_ID)
    return true;

  return false;
}


/*******************************************************************************

********************************************************************************/
bool TextNode::isIdRefsInternal() const
{
  if (isTyped())
  {
    store::Item* value = getValue();

    if (haveListValue())
    {
      const ItemVector& values = *reinterpret_cast<ItemVector*>(value);
      ulong numValues = values.size();

      for (ulong i = 0; i < numValues; ++i)
      {
        if (dynamic_cast<IDREFItem*>(values.getItem(i)) != NULL)
        {
          return true;
        }
        else if (dynamic_cast<UserTypedAtomicItem*>(values.getItem(i)) != NULL)
        {
          UserTypedAtomicItem* utai = dynamic_cast<UserTypedAtomicItem*>(values.getItem(i));
          if ( utai->getTypeCode() == XS_IDREF )
            return true;
          if ( (dynamic_cast<AtomicItem*>(utai->getBaseItem()))->getTypeCode() == XS_IDREF )
            return true;
        }
      }
    }
    else if (dynamic_cast<IDREFItem*>(value) != NULL)
    {
      return true;
    }
    else if (dynamic_cast<UserTypedAtomicItem*>(value) != NULL)
    {
      UserTypedAtomicItem* utai = dynamic_cast<UserTypedAtomicItem*>(value);
      if ( utai->getTypeCode() == XS_IDREF )
        return true;
      if ( (dynamic_cast<AtomicItem*>(utai->getBaseItem()))->getTypeCode() == XS_IDREF )
        return true;
    }
  }

  return false;
}


/*******************************************************************************

********************************************************************************/
zstring TextNode::getStringValue() const
{
  if (isTyped())
  {
    return getValue()->getStringValue();
  }
  else
  {
    return getText();
  }
}


void TextNode::getStringValue2(zstring& val) const
{
  if (isTyped())
  {
    getValue()->getStringValue2(val);
  }
  else
  {
    val = getText();
  }
}


void TextNode::appendStringValue(zstring& buf) const
{
  if (isTyped())
  {
    getValue()->appendStringValue(buf);
  }
  else
  {
    buf += getText();
  }
}


/*******************************************************************************

********************************************************************************/
zstring TextNode::show() const
{
#ifdef TEXT_ORDPATH
  return "<text nid=\"" + theOrdPath.show() + "\">"
    + getStringValue() + "</text>";
#else
  return "<text>" + getStringValue() + "</text>";
#endif
}


#ifndef TEXT_ORDPATH

/*******************************************************************************

********************************************************************************/
bool TextNode::isAncestor(const store::Item_t& aOther) const
{
  store::Item_t lParent = getParent();
  if (lParent == aOther)
  {
    return true;
  }
  else
  {
    return lParent->isAncestor(aOther);
  }
}


/*******************************************************************************

********************************************************************************/
bool TextNode::isFollowingSibling(const store::Item_t& aOther) const
{
  const store::Item_t lParent = getParent();
  store::Iterator_t lChildren = lParent->getChildren();
  lChildren->open();

  // search for this node in the list of children of the parent
  store::Item_t lCurr;
  while (lChildren->next(lCurr))
  {
    if (lCurr == this) // found this node in the list of children
    {
      // if there are following siblings of this text node,
      // ask them the question
      if (lChildren->next(lCurr))
      { 
        if (lCurr == aOther)
        {
          return true;
        }
        else
        {
          return lCurr->isFollowingSibling(aOther);
        }
      }
    }
  }
  return false;
}

/*******************************************************************************

********************************************************************************/
bool TextNode::isFollowing(const store::Item_t& aOther) const
{
  return getParent()->isFollowing(aOther);
}

/*******************************************************************************

********************************************************************************/
bool TextNode::isDescendant(const store::Item_t&) const
{
  // text nodes can't have descendants
  return false;
}


/*******************************************************************************

********************************************************************************/
bool TextNode::isPrecedingSibling(const store::Item_t& aOther) const
{
  const store::Item_t lParent = getParent();
  store::Iterator_t lChildren = lParent->getChildren();
  lChildren->open();

  // search for this node in the list of children of the parent
  // and remember the according first preceding one
  store::Item_t lCurr;
  lChildren->next(lCurr); // there must be at least this one.

  store::Item_t lPrev = lCurr;

  if (lPrev == this)
  {
    return false; // no preceding siblings at all
  }

  if (lPrev == aOther)
  {
    return true; // immediate preceding-sibling
  }

  while (lChildren->next(lCurr))
  {
    if (lCurr == this) // found this node in the list of children
    {
      if (lPrev == aOther)
      {
        return true;
      }
      else
      {
        return lPrev->isPrecedingSibling(aOther);
      }
    }
    else
    {
      lPrev = lCurr; // remember preceding sibling
    }
  }
  return false;
}


/*******************************************************************************

********************************************************************************/
bool TextNode::isPreceding(const store::Item_t& aOther) const
{
  return getParent()->isPreceding(aOther);
}


/*******************************************************************************

********************************************************************************/
bool TextNode::isChild(const store::Item_t&) const
{
  // text nodes can't have children
  return false;
}


/*******************************************************************************

********************************************************************************/
bool TextNode::isParent(const store::Item_t& aOther) const
{
  return getParent() == aOther;
}


/*******************************************************************************

********************************************************************************/
store::Item_t TextNode::getLevel() const
{
  xs_integer lParentLevel = getParent()->getLevel()->getIntegerValue();

  store::Item_t lRes;
  GET_STORE().getItemFactory()->createInteger(lRes, ++lParentLevel);

  return lRes;
}


/*******************************************************************************

********************************************************************************/
store::Item_t TextNode::leastCommonAncestor(const store::Item_t& aOther) const
{
  store::Item_t lParent = getParent();

  if (aOther == lParent)
  {
    return lParent;
  }

  return lParent->leastCommonAncestor(aOther);
}

#endif // ! TEXT_ORDPATH


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class PiNode                                                               //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************
  Node constructor used by FastXmlLoader
********************************************************************************/
PiNode::PiNode(zstring& target, zstring& content)
  :
  OrdPathNode(store::StoreConsts::piNode)
{
  QNamePool& qnpool = GET_STORE().getQNamePool();

  theTarget.take(target);
  theContent.take(content);

  theName = qnpool.insert(zstring(), zstring(), theTarget);

  NODE_TRACE1("Loaded pi node " << this << " target = " << theTarget
              << std::endl);
}


/*******************************************************************************

********************************************************************************/
PiNode::PiNode(
    XmlTree*      tree,
    InternalNode* parent,
    bool append,
    csize pos,
    zstring& target,
    zstring& content)
  :
  OrdPathNode(tree, parent, append, pos, store::StoreConsts::piNode)
{
  QNamePool& qnpool = GET_STORE().getQNamePool();

  theTarget.take(target);
  theContent.take(content);

  theName = qnpool.insert(zstring(), zstring(), theTarget);

  if (parent)
  {
    if (append)
      pos = parent->numChildren();

    parent->insertChild(this, pos);
  }

  NODE_TRACE1("Constructed pi node " << this << " parent = "
              << std::hex << (parent ? (ulong)parent : 0) << " pos = " << pos
              << " tree = " << getTree()->getId() << ":" << getTree()
              << " ordpath = " << theOrdPath.show() << " target = " << theTarget);
}


/*******************************************************************************

********************************************************************************/
XmlNode* PiNode::copyInternal(
    InternalNode* rootParent,
    InternalNode* parent,
    csize pos,
    const XmlNode* rootCopy,
    const store::CopyMode& copymode) const
{
  assert(parent != NULL || rootParent == NULL);

  NodeFactory& factory = GET_NODE_FACTORY();
  PiNode* copyNode = NULL;
  XmlTree* tree = NULL;
  zstring content;
  zstring target;
  bool append;

  try
  {
    target = theTarget;
    content = theContent;

    if (parent == NULL)
    {
      tree = factory.createXmlTree();
      append = false;
    }
    else
    {
      append = (parent != rootParent);
    }

    copyNode = factory.createPiNode(tree, parent, append, pos, target, content);
  }
  catch (...)
  {
    delete tree;
    throw;
  }

  NODE_TRACE1("Copied pi node " << this << " to node " << copyNode
              << " parent = " << std::hex << (parent ? (ulong)parent : 0)
              << " pos = " << pos);

  return copyNode;
}


/*******************************************************************************

********************************************************************************/
store::Item* PiNode::getType() const
{
  return GET_STORE().theSchemaTypeNames[XS_UNTYPED_ATOMIC];
}


void PiNode::getTypedValue(store::Item_t& val, store::Iterator_t& iter) const
{
  zstring rch = theContent;
  GET_STORE().getItemFactory()->createString(val, rch);
  iter = NULL;
}


/*******************************************************************************

********************************************************************************/
zstring PiNode::show() const
{
  return "<?" + theTarget + " " + theContent + "?>";
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class CommentNode                                                          //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************
  Node constructor used during loading of an xml doc
********************************************************************************/
CommentNode::CommentNode(zstring& content)
  :
  OrdPathNode(store::StoreConsts::commentNode)
{
  theContent.take(content);

  NODE_TRACE1("Loaded comment node " << this << " content = " << theContent);
}


/*******************************************************************************

********************************************************************************/
CommentNode::CommentNode(
    XmlTree*      tree,
    InternalNode* parent,
    bool          append,
    csize         pos,
    zstring&      content)
  :
  OrdPathNode(tree, parent, append, pos, store::StoreConsts::commentNode)
{
  theContent.take(content);

  if (parent)
  {
    if (append)
      pos = parent->numChildren();

    parent->insertChild(this, pos);
  }

  NODE_TRACE1("Constructed comment node " << this << " parent = "
              << std::hex << (parent ? (ulong)parent : 0) << " pos = " << pos
              << " tree = " << getTree()->getId() << ":" << getTree()
              << " ordpath = " << theOrdPath.show() << " content = "
              << theContent);
}


/*******************************************************************************

********************************************************************************/
XmlNode* CommentNode::copyInternal(
    InternalNode* rootParent,
    InternalNode* parent,
    csize pos,
    const XmlNode* rootCopy,
    const store::CopyMode& copymode) const
{
  assert(parent != NULL || rootParent == NULL);

  NodeFactory& factory = GET_NODE_FACTORY();
  CommentNode* copyNode = NULL;
  XmlTree* tree = NULL;
  zstring content;
  bool append;

  try
  {
    if (parent == NULL)
    {
      tree = factory.createXmlTree();
      append = false;
    }
    else
    {
      append = (parent != rootParent);
    }

    content = theContent;
    copyNode = factory.createCommentNode(tree, parent, append, pos, content);
  }
  catch (...)
  {
    delete tree;
    throw;
  }

  NODE_TRACE1("Copied coment node " << this << " to node " << copyNode
              << " parent = " << std::hex << (parent ? (ulong)parent : 0)
              << " pos = " << pos);

  return copyNode;
}


/*******************************************************************************

********************************************************************************/
store::Item* CommentNode::getType() const
{
  return NULL;
  // return GET_STORE().theSchemaTypeNames[XS_UNTYPED_ATOMIC];
}


void CommentNode::getTypedValue(store::Item_t& val, store::Iterator_t& iter) const
{
  zstring rch = theContent;
  GET_STORE().getItemFactory()->createString(val, rch);
  iter = NULL;
}


/*******************************************************************************

********************************************************************************/
zstring CommentNode::show() const
{
  return "<!--" + theContent + "-->";
}

#ifndef ZORBA_NO_FULL_TEXT

/******************************************************************************
 *
 *  Full-text
 *
 ******************************************************************************/

XmlNodeTokenizerCallback::XmlNodeTokenizerCallback( Tokenizer &tokenizer,
                                                    FTTokenStore &token_store,
                                                    iso639_1::type lang ) :
  tokenizer_( tokenizer ),
  token_store_( &token_store ),
  tokens_( token_store.getDocumentTokens() )
{
  push_lang( lang );
}


XmlNodeTokenizerCallback::XmlNodeTokenizerCallback( Tokenizer &tokenizer,
                                                    container_type &tokens,
                                                    iso639_1::type lang ) :
  tokenizer_( tokenizer ),
  token_store_( NULL ),
  tokens_( tokens )
{
  push_lang( lang );
}


inline XmlNodeTokenizerCallback::begin_type
XmlNodeTokenizerCallback::beginTokenization() const {
  return token_store_->getDocumentTokens().size();
}


inline void XmlNodeTokenizerCallback::endTokenization(
    XmlNode const *node,
    XmlNodeTokenizerCallback::begin_type begin )
{
  token_store_->putRange(node, begin, token_store_->getDocumentTokens().size());
}


void XmlNodeTokenizerCallback::operator()( char const *utf8_s, size_t utf8_len,
                                           int_t pos, int_t sent, int_t para,
                                           void *payload )
{
  store::Item const *const item = static_cast<store::Item*>( payload );
  FTToken t( utf8_s, utf8_len, pos, sent, para, item, get_lang() );
  tokens_.push_back( t );
}


inline void XmlNodeTokenizerCallback::tokenize( char const *utf8_s,
                                                size_t len ) {
  tokenizer_.tokenize(
    utf8_s, len, get_lang(), *this,
    element_stack_.empty() ? NULL : static_cast<void*>( get_element() )
  );
}


void XmlNode::tokenize( XmlNodeTokenizerCallback& )
{
  // do nothing
}


void AttributeNode::tokenize( XmlNodeTokenizerCallback &cb )
{
  zstring text;
  getStringValue2( text );
  cb.tokenize( text.data(), text.size() );
}


FTTokenIterator_t
AttributeNode::getDocumentTokens( iso639_1::type lang ) const
{
  FTTokenStore &token_store = getTree()->getTokenStore();
  while ( true ) {
    FTTokenStore::container_type const *tokens = token_store.getAttr( this );
    if ( tokens )
      return FTTokenIterator_t(
        new NaiveFTTokenIterator( *tokens, 0, tokens->size() )
      );
    FTTokenStore::container_type att_tokens;
    std::auto_ptr<Tokenizer> tokenizer( Tokenizer::create() );
    XmlNodeTokenizerCallback cb( *tokenizer, att_tokens, lang );
    const_cast<AttributeNode*>( this )->tokenize( cb );
    token_store.putAttr( this, att_tokens );
  }
}


void InternalNode::tokenize( XmlNodeTokenizerCallback& cb )
{
  Tokenizer &tokenizer = cb.tokenizer();
  tokenizer.para( tokenizer.para() + 1 );

  XmlNodeTokenizerCallback::begin_type const begin = cb.beginTokenization();
  for ( ulong i = 0; i < numChildren(); ++i )
    getChild( i )->tokenize( cb );
  cb.endTokenization( this, begin );
}


void ElementNode::tokenize( XmlNodeTokenizerCallback& cb )
{
  //
  // See if this XML element has an xml:lang attribute: if so, switch to that
  // language.
  //
  bool pushed_lang = false;
  for ( ulong i = 0; i < numAttrs(); ++i ) {
    AttributeNode *const at = getAttr( i );
    Item const *const name = at->getNodeName();
    if ( name->getLocalName() == "lang" && name->getNamespace() == XML_NS ) {
      cb.push_lang( locale::find_lang( at->getStringValue().c_str() ) );
      pushed_lang = true;
      break;
    }
  }

  cb.push_element( this );
  InternalNode::tokenize( cb );
  cb.pop_element();
  if ( pushed_lang )
    cb.pop_lang();
}


void TextNode::tokenize( XmlNodeTokenizerCallback &cb )
{
  const zstring* text;
  zstring listText;

  if (isTyped())
  {
    const store::Item* value = getValue();

    assert(value->isAtomic() || value->isList());

    if (value->isAtomic())
    {
      const AtomicItem* avalue = static_cast<const AtomicItem*>(value);

      if (avalue->getTypeCode() < XS_STRING ||
          avalue->getTypeCode() > XS_ENTITY)
        return;

      text = &getString();
    }
    else
    {
      const ItemVector* lvalue = static_cast<const ItemVector*>(value);

      ulong numItems = lvalue->size();

      for (ulong i = 0; i < numItems; ++i)
      {
        assert(lvalue->getItem(i)->isAtomic());

        const AtomicItem* avalue = static_cast<const AtomicItem*>(lvalue->getItem(i));

        if (avalue->getTypeCode() < XS_STRING ||
            avalue->getTypeCode() > XS_ENTITY)
          continue;

        listText += avalue->getString();
      }

      if (listText.empty())
        return;

      text = &listText;
    }
  }
  else
  {
    text = &getText();
  }

  XmlNodeTokenizerCallback::begin_type const begin = cb.beginTokenization();
  cb.tokenize( text->data(), text->size() );
  cb.endTokenization( this, begin );
}


FTTokenIterator_t
XmlNode::getDocumentTokens( iso639_1::type lang ) const
{
  FTTokenStore &token_store = getTree()->getTokenStore();
  FTTokenStore::container_type &tokens = token_store.getDocumentTokens();

  if ( tokens.empty() )
  {
    std::auto_ptr<Tokenizer> tokenizer( Tokenizer::create() );
    XmlNodeTokenizerCallback cb( *tokenizer, token_store, lang );
    getRoot()->tokenize( cb );
  }

  FTTokenStore::range_type const &r = token_store.getRange( this );
  return FTTokenIterator_t(
    new NaiveFTTokenIterator( tokens, r.first, r.second )
  );
}

#endif /* ZORBA_NO_FULL_TEXT */

} // namespace store
} // namespace zorba
/* vim:set et sw=2 ts=2: */
