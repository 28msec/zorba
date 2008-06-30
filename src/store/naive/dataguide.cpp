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

#include "zorbautils/fatal.h"
#include "store/naive/dataguide.h"


namespace zorba 
{ 

namespace simplestore 
{


/*******************************************************************************

********************************************************************************/
void GuideNode::deleteTree() throw()
{
  assert(theParent == NULL);

  ulong numChildren = this->numChildren();
  ulong numAttrs = this->numAttributes();

  if (numChildren > 0 || numAttrs > 0)
  {
    ElementGuideNode* node = reinterpret_cast<ElementGuideNode*>(this);

    for (ulong i = 0; i < numChildren; i++)
    {
      GuideNode* child = node->theChildren[i];
      assert(child->theParent == this);
      child->theParent = NULL; 
      child->deleteTree();
    }

    for (ulong i = 0; i < numAttrs; i++)
    {
      GuideNode* attr = node->theAttributes[i];
      assert(attr->theParent == this);
      delete attr;
    } 
  }

  delete this;
}


/*******************************************************************************

********************************************************************************/
void AttributeGuideNode::getPathInfo(
    std::vector<const store::Item*>& ctxPath,
    std::vector<const store::Item*>& relPath,
    bool                             attrPath,
    bool&                            found,
    bool&                            unique)
{
  ZORBA_FATAL(0, "");
}


/*******************************************************************************

********************************************************************************/
void ElementGuideNode::getPathInfo(
    std::vector<const store::Item*>& ctxPath,
    std::vector<const store::Item*>& relPath,
    bool                             attrPath,
    bool&                            found,
    bool&                            unique)
{
  found = true;

  if (relPath.empty())
  {
    GuideNode* ctxNode = findPath(ctxPath, attrPath, unique);

    if (ctxNode == NULL)
      found = false;
  }
  else
  {
    assert(!ctxPath.empty());

    GuideNode* ctxNode = findPath(ctxPath, false, unique);

    if (ctxNode == NULL)
    {
      found = false;
      return;
    }

    assert(ctxNode->getNodeKind() == store::StoreConsts::elementNode);

    GuideNode* pathNode = reinterpret_cast<ElementGuideNode*>(ctxNode)->
                          findPath(relPath, attrPath, unique);

    if (pathNode == NULL)
      found = false;
  }
}


/*******************************************************************************

********************************************************************************/
GuideNode* ElementGuideNode::findPath(
    std::vector<const store::Item*>& path,
    bool                             attrPath,
    bool&                            unique)
{
  ElementGuideNode* parent = this;
  GuideNode* child = NULL;

  unique = true;

  ulong pathLen = path.size();

  for (ulong i = 0; i < pathLen; i++)
  {
    if (attrPath && i == pathLen - 1)
    {
      child = parent->findAttr(path[i]);
    }
    else
    {
      child = parent->findChild(path[i]);
    }

    if (child == NULL)
      return NULL;

    if (unique && !child->theIsUnique)
      unique = false;

    parent = reinterpret_cast<ElementGuideNode*>(child);
  }

  return child;
}


/*******************************************************************************

********************************************************************************/
ElementGuideNode* ElementGuideNode::findChild(const store::Item* name)
{
  ulong numChildren = theChildren.size();
  for (ulong i = 0; i < numChildren; i++)
  {
    if (theChildren[i]->theName->equals(name))
      return theChildren[i];
  }

  return NULL;
}


/*******************************************************************************

********************************************************************************/
AttributeGuideNode* ElementGuideNode::findAttr(const store::Item* name)
{
  ulong numAttrs = theAttributes.size();
  for (ulong i = 0; i < numAttrs; i++)
  {
    if (theAttributes[i]->theName->equals(name))
      return theAttributes[i];
  }

  return NULL;
}


/*******************************************************************************

********************************************************************************/
std::string ElementGuideNode::show(ulong depth) const
{
  std::stringstream str;

  if (depth > 0)
  {
    std::string indent(depth, ' ');
    str << indent;
  }

  depth += 2;

  ulong numChildren = theChildren.size();

  if (theName != NULL)
  {
    if (numChildren > 0)
      str <<  "<" << *theName->getStringValue() << " unique=" << theIsUnique
          << ">" << std::endl;
    else
      str <<  "<" << *theName->getStringValue() << " unique=" << theIsUnique
          << "/>" << std::endl;
  }
  else
  {
    str <<  "<DOC>" << std::endl;
  }

  for (ulong i = 0; i < numChildren; i++)
  {
    str << theChildren[i]->show(depth);
  }

  depth -= 2;

  if (theName != NULL)
  {
    if (numChildren > 0)
    {
      if (depth > 0)
      {
        std::string indent(depth, ' ');
        str << indent;
      }
      str << "</" << *theName->getStringValue() << ">" << std::endl;
    }
  }
  else
  {
    str <<  "</DOC>" << std::endl;
  }

  return str.str().c_str();
}


}
}
