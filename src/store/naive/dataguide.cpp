
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
