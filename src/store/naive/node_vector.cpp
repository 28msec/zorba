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


namespace zorba 
{

namespace simplestore 
{

NodeVector dummyVector;


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


NodeVector::iterator NodeVector::remove(XmlNode* n)
{
  NodeVector::iterator pos = std::find(theNodes, n);

  if (pos != theNodes.end())
  {
    theNodes.erase(pos);
  }
  return pos;
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
/* vim:set et sw=2 ts=2: */
