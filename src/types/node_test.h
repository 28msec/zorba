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
#pragma once
#ifndef ZORBA_TYPES_NODE_TEST_H
#define ZORBA_TYPES_NODE_TEST_H

#include <zorba/store_consts.h>

#include "zorbatypes/rchandle.h"

#include "store/api/item.h"
#include "zorbaserialization/serialization_engine.h"

namespace zorba {

class TypeManager;


class NodeNameTest : virtual public SimpleRCObject
{
private:
  zstring  m_uri;
  zstring  m_local;

public:
  SERIALIZABLE_CLASS(NodeNameTest)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(NodeNameTest, SimpleRCObject)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  NodeNameTest(const zstring& uri, const zstring& local);

  NodeNameTest(const store::Item_t& qname);

  bool operator==(const NodeNameTest& other) const;

  bool is_subname_of(const NodeNameTest& other) const;

  bool matches(const store::Item* qname) const;

  bool matches(const zstring& lname,  const zstring& ns) const;
};


}

#endif /* ZORBA_TEST_TYPES_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
