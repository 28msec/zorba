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
#ifndef ZORBA_SIMPLESTORE_NODE_POINTER_HASHMAP
#define ZORBA_SIMPLESTORE_NODE_POINTER_HASHMAP

#include "zorbautils/hashfun.h"
#include "zorbautils/hashmap.h"

namespace zorba
{

namespace simplestore
{

class XmlNode;


/***************************************************************************//**
  Class to privide the equality and hash functions for the NodePointerHashMap
  class defined below.
*******************************************************************************/
class NodePointerHashMapCmp
{
public:
  static bool equal(const XmlNode* n1, const XmlNode* n2)
  {
    return n1 == n2;
  }

  static uint32_t hash(const XmlNode* n)
  {
    return hashfun::h32((void*)(&n), sizeof(n));
  }
};


/*******************************************************************************
  A hash-based map container mapping item pointers to values of type V. 
  Equality is based on the Item::equals() method.
*******************************************************************************/
template <class V>
class NodePointerHashMap : public HashMap<const XmlNode*,
                                          V,
                                          NodePointerHashMapCmp>
{
public:
  NodePointerHashMap(ulong size, bool sync) 
    :
    HashMap<const XmlNode*, V, NodePointerHashMapCmp>(size, sync)
  {
  }
};


}
}

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
