
#include "common/shared_types.h"
#include "util/Assert.h"

#include "store/naive/node_vector.h"
#include "store/naive/node_items.h"

namespace zorba { namespace store {


ConstrNodeVector dummyVector;


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class NodeVector                                                           //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


ulong NodeVector::find(XmlNode* n)
{
  ulong size = theNodes.size();
  ulong i;
  for (i = 0; i < size; i++)
  {
    if (theNodes[i] == n)
      return i;
  }
  return i;
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class LoadedNodeVector                                                     //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


void LoadedNodeVector::remove(XmlNode* n)
{
  ulong pos = find(n);

  assert(pos < theNodes.size());

  theNodes.erase(theNodes.begin() + pos);
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class ConstrNodeVector                                                     //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


ConstrNodeVector::ConstrNodeVector(ulong size) : NodeVector(size)
{
  theBitmap.resize(size);
  for (ulong i = 0; i < size; i++)
  {
    theBitmap[i] = false;
    theNodes[i] = 0;
  }
}


void ConstrNodeVector::set(ulong pos, XmlNode* node, bool shared)
{
  ZORBA_ASSERT(pos <= size());
  
  if (pos == size())
  {
    push_back(node, shared);
    return;
  }

  if (shared)
  {
    if (!theBitmap[pos])
      theNodes[pos] = NULL;

    *(reinterpret_cast<XmlNode_t*>(&theNodes[pos])) = node;
    theBitmap[pos] = true;
  }
  else
  {
    if (theBitmap[pos])
      *(reinterpret_cast<XmlNode_t*>(&theNodes[pos])) = NULL;

    theNodes[pos] = node;
    theBitmap[pos] = false;
  }
}


void ConstrNodeVector::push_back(XmlNode* node, bool shared)
{
  theNodes.push_back(node);
  theBitmap.push_back(shared);

  if (shared)
    node->addReference(node->getSharedRefCounter()
                       SYNC_PARAM2(node->getRCLock()));
}


void ConstrNodeVector::remove(XmlNode* n)
{
  ulong pos = find(n);

  assert(pos < theNodes.size());

  if (theBitmap[pos])
  {
    *(reinterpret_cast<XmlNode_t*>(&theNodes[pos])) = NULL;
  }

  theNodes.erase(theNodes.begin() + pos);
  theBitmap.erase(theBitmap.begin() + pos);
}


void ConstrNodeVector::clear()
{
  ulong size = this->size();
  for (ulong i = 0; i < size; i++)
  {
    if (theBitmap[i])
      *(reinterpret_cast<XmlNode_t*>(&theNodes[i])) = NULL; 
  }

  theNodes.clear();
}


void ConstrNodeVector::resize(ulong newSize)
{
  if (newSize == 0)
  {
    clear();
    return;
  }

  ulong oldSize = size();

  theNodes.resize(newSize);
  theBitmap.resize(newSize);
  for (ulong i = oldSize; i < newSize; i++)
  {
    theBitmap[i] = false;
    theNodes[i] = NULL;
  }
}


void ConstrNodeVector::copy(const NodeVector& src)
{
  ulong size = src.size();

  resize(size);

  for (ulong i = 0; i < size; i++)
  {
    *(reinterpret_cast<XmlNode_t*>(&theNodes[i])) = src.theNodes[i];
    theBitmap[i] = true;
  }
}

}
}
