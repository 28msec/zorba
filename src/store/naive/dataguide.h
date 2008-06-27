
#ifndef ZORBA_SIMPLE_STORE_DATAGUIDE
#define ZORBA_SIMPLE_STORE_DATAGUIDE

#include "store/api/item.h"

namespace zorba 
{ 
namespace simplestore 
{

class ElementGuideNode;


class GuideNode
{
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

  virtual std::string show(ulong depth) const = 0;
};


class AttributeGuideNode : public GuideNode
{
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

  std::string show(ulong depth) const { return "attr"; }
};


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

  ElementGuideNode* findChild(const store::Item* name);

  std::string show(ulong depth) const;
};


}
}

#endif
