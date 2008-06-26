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
#include "common/shared_types.h"
#include "zorbautils/fatal.h"

#include "store/minimal/min_node_vector.h"
#include "store/minimal/min_node_items.h"
#include "store/minimal/shared_types.h"

namespace zorba { namespace storeminimal {

typedef rchandle<XmlNode>   XmlNode_t;
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


void LoadedNodeVector::insert(XmlNode* n, ulong pos, bool shared)
{
  if(pos > size())
    pos = size();

  theNodes.insert(theNodes.begin() + pos, n);
}


void LoadedNodeVector::remove(ulong pos)
{
  ZORBA_FATAL(pos < size(),  "pos = " << pos << " size = " << size());

  theNodes.erase(theNodes.begin() + pos);
}


bool LoadedNodeVector::remove(XmlNode* n)
{
  ulong pos = find(n);

  if (pos < theNodes.size())
  {
    theNodes.erase(theNodes.begin() + pos);
    return true;
  }
  return false;
}


void LoadedNodeVector::copy(ConstrNodeVector& dest)
{
  ulong size = this->size();

  ZORBA_FATAL(dest.empty(), "");

  dest.theNodes.resize(size);
  dest.theBitmap.resize(size);

  for (ulong i = 0; i < size; i++)
  {
    dest.theNodes[i] = theNodes[i];
    dest.theBitmap[i] = false;
  }
}

void LoadedNodeVector::compact()
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
//  class ConstrNodeVector                                                     //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


ConstrNodeVector::ConstrNodeVector(ulong size) : NodeVector(size), theBitmap(size)
{
  for (ulong i = 0; i < size; i++)
  {
    theBitmap[i] = false;
    theNodes[i] = 0;
  }
}


void ConstrNodeVector::insert(XmlNode* n, ulong pos, bool shared)
{
  if(pos > size())
    pos = size();

  theNodes.insert(theNodes.begin() + pos, n);
  theBitmap.insert(theBitmap.begin() + pos, shared);

  if (shared)
  {
    n->addReference(n->getSharedRefCounter()
                    SYNC_PARAM2(n->getRCLock()));
  }
}


void ConstrNodeVector::set(XmlNode* node, ulong pos, bool shared)
{
  ZORBA_FATAL(pos <= size(),  "pos = " << pos << " size = " << size());
  
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


void ConstrNodeVector::remove(ulong pos)
{
  ZORBA_FATAL(pos < size(),  "pos = " << pos << " size = " << size());

  if (theBitmap[pos])
    *(reinterpret_cast<XmlNode_t*>(&theNodes[pos])) = NULL;

  theNodes.erase(theNodes.begin() + pos);
  theBitmap.erase(theBitmap.begin() + pos);
}


bool ConstrNodeVector::remove(XmlNode* n)
{
  ulong pos = find(n);

  if (pos < theNodes.size())
  {
    if (theBitmap[pos])
      *(reinterpret_cast<XmlNode_t*>(&theNodes[pos])) = NULL;

    theNodes.erase(theNodes.begin() + pos);
    theBitmap.erase(theBitmap.begin() + pos);

    return true;
  }
  return false;
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
  theBitmap.clear();
}


void ConstrNodeVector::resize(ulong newSize)
{
  if (newSize == 0)
  {
    clear();
    return;
  }

  ulong oldSize = size();

  if (newSize > oldSize)
  {
    theNodes.resize(newSize);
    theBitmap.resize(newSize);

    for (ulong i = oldSize; i < newSize; i++)
    {
      theBitmap[i] = false;
      theNodes[i] = NULL;
    }
  }
  else if (newSize < oldSize)
  {
    for (ulong i = newSize; i < oldSize; i++)
    {
      if (theBitmap[i])
        *(reinterpret_cast<XmlNode_t*>(&theNodes[i])) = NULL; 
     }

    theNodes.resize(newSize);
    theBitmap.resize(newSize);
  }
}


void ConstrNodeVector::copy(ConstrNodeVector& dest)
{
  ulong size = this->size();

  ZORBA_FATAL(dest.empty(), "");

  dest.theNodes.resize(size);
  dest.theBitmap.resize(size);

  for (ulong i = 0; i < size; i++)
  {
    if (theBitmap[i])
    {
      *(reinterpret_cast<XmlNode_t*>(&dest.theNodes[i])) = theNodes[i];
      dest.theBitmap[i] = true;
    }
    else
    {
      dest.theNodes[i] = theNodes[i];
      dest.theBitmap[i] = false;
    }
  }
}

void ConstrNodeVector::compact()
{
  if (theNodes.capacity() > theNodes.size())
  {
    std::vector<XmlNode*> tmp(theNodes.size());
    tmp = theNodes;
    theNodes.swap(tmp);
  }
}

}
}
