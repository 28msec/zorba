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
#ifndef ZORBA_NODE_TEST_H
#define ZORBA_NODE_TEST_H

#include <zorba/store_consts.h>

#include "zorbatypes/rchandle.h"
#include "zorbatypes/xqpstring.h"

#include "store/api/item.h"

namespace zorba {

class TypeManager;


class NodeNameTest : virtual public SimpleRCObject
{
public:
  typedef enum 
  {
    CONSTANT,
    CONSTANT_WILDCARD,
    WILDCARD_CONSTANT,
    WILDCARD
  } wildcard_kind_t;

private:
  xqpStringStore_t         m_uri;
  xqpStringStore_t         m_local;

public:
  SERIALIZABLE_CLASS(NodeNameTest)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(NodeNameTest, SimpleRCObject)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    //serialize_baseclass(ar, (SimpleRCObject*)this);
    ar & m_uri;
    ar & m_local;
  }
public:
  NodeNameTest(const xqpStringStore_t& uri, const xqpStringStore_t& local);

  NodeNameTest(const store::Item_t& qname);

  bool operator==(const NodeNameTest& other) const;

  bool is_subname_of(const NodeNameTest& other) const;

  bool matches(const store::Item* qname) const;

  bool matches(
        const xqpStringStore* lname,
        const xqpStringStore* ns) const;
};


}

#endif /* ZORBA_TEST_TYPES_H */
/* vim:set ts=2 sw=2: */

/*
 * Local variables:
 * mode: c++
 * End:
 */
