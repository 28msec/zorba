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

#ifndef ZORBA_SIMPLE_STORE_DATAGUIDE
#define ZORBA_SIMPLE_STORE_DATAGUIDE

#include "store/api/item.h"

//#define DATAGUIDE


namespace zorba 
{ 
namespace simplestore 
{

class ElementGuideNode;


class GuideNode
{
  friend class AttributeGuideNode;
  friend class ElementGuideNode;

protected:
  ElementGuideNode  * theParent;
  store::Item_t       theName;
  bool                theIsUnique;

public:
  GuideNode(ElementGuideNode* parent, store::Item_t& name)
    :
    theParent(parent),
    theIsUnique(true)
  {
    theName.transfer(name);
  }

  virtual ~GuideNode() {}

  virtual store::StoreConsts::NodeKind getNodeKind() const = 0;

  ElementGuideNode* getParent() const { return theParent; }

  store::Item* getName() const { return theName.getp(); }

  bool getUnique() const       { return theIsUnique; }
  void setUnique(bool v)       { theIsUnique = v; }

  virtual ulong numChildren() const { return 0; }
  virtual ulong numAttributes() const { return 0; }

  void deleteTree() throw();

  virtual void getPathInfo(
        std::vector<const store::Item*>& ctxPath,
        std::vector<const store::Item*>& relPath,
        bool                             attrPath,
        bool&                            found,
        bool&                            unique) = 0;

  virtual std::string show(ulong depth) const = 0;
};


/*******************************************************************************

********************************************************************************/
class AttributeGuideNode : public GuideNode
{
  friend class GuideNode;
  friend class ElementGuideNode;

public:
  AttributeGuideNode(ElementGuideNode* parent, store::Item_t& name)
    :
    GuideNode(parent, name)
  {
  }

  store::StoreConsts::NodeKind getNodeKind() const
  {
    return store::StoreConsts::attributeNode; 
  }

  void getPathInfo(
        std::vector<const store::Item*>& ctxPath,
        std::vector<const store::Item*>& relPath,
        bool                             attrPath,
        bool&                            found,
        bool&                            unique);

  std::string show(ulong depth) const { return "attr"; }
};


/*******************************************************************************

********************************************************************************/
class ElementGuideNode : public GuideNode
{
  friend class GuideNode;

protected:
  std::vector<ElementGuideNode*>   theChildren;
  std::vector<AttributeGuideNode*> theAttributes;

public:
  ElementGuideNode(ElementGuideNode* parent, store::Item_t& name)
    :
    GuideNode(parent, name)
  {
    if (parent)
      parent->theChildren.push_back(this);
  }

  store::StoreConsts::NodeKind getNodeKind() const
  {
    return store::StoreConsts::elementNode; 
  }

  ulong numChildren() const { return theChildren.size(); }
  ulong numAttributes() const { return theAttributes.size(); }

  void getPathInfo(
        std::vector<const store::Item*>& ctxPath,
        std::vector<const store::Item*>& relPath,
        bool                             attrPath,
        bool&                            found,
        bool&                            unique);

  GuideNode* findPath(
        std::vector<const store::Item*>& path,
        bool                             attrPath,
        bool&                            unique);

  ElementGuideNode* findChild(const store::Item* name);
  AttributeGuideNode* findAttr(const store::Item* name);

  std::string show(ulong depth) const;
};


}
}

#endif
