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

#include "store/naive/node_vector.h"
//#include "store/naive/node_items.h"

namespace zorba 
{

namespace simplestore 
{

NodeVector dummyVector;


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


void NodeVector::insert(XmlNode* n, long pos)
{
  if (pos < 0 || pos >= (long)size())
  {
    theNodes.push_back(n);
  }
  else
  {
    theNodes.insert(theNodes.begin() + pos, n);
  }
}


void NodeVector::remove(ulong pos)
{
  ZORBA_FATAL(pos < size(),  "pos = " << pos << " size = " << size());

  theNodes.erase(theNodes.begin() + pos);
}


bool NodeVector::remove(XmlNode* n)
{
  ulong pos = find(n);

  if (pos < theNodes.size())
  {
    theNodes.erase(theNodes.begin() + pos);
    return true;
  }
  return false;
}


void NodeVector::compact()
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
