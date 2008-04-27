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

#include "zorbatypes/xqpstring.h"

#include "util/rchandle.h"
#include <zorba/store_consts.h>
#include "store/api/item.h"

namespace zorba {

class NodeNameTest : virtual public SimpleRCObject
{
 public:
  typedef enum {
    CONSTANT,
    CONSTANT_WILDCARD,
    WILDCARD_CONSTANT,
    WILDCARD
  } kind_t;

  NodeNameTest(rchandle<xqpStringStore> uri, rchandle<xqpStringStore> local);
  NodeNameTest(rchandle<store::Item> qname);
    
  rchandle<xqpStringStore> get_uri() const;
  rchandle<xqpStringStore> get_local() const;
  
  bool operator==(const NodeNameTest& other) const;
  bool is_subname_of(const NodeNameTest& other) const;
  bool matches(store::Item *qname) const;

 private:
  kind_t                   m_kind;
  rchandle<xqpStringStore> m_uri;
  rchandle<xqpStringStore> m_local;
};


class NodeTest : virtual public SimpleRCObject
{
 public:
  static const rchandle<NodeTest> ANY_NODE_TEST;
  static const rchandle<NodeTest> ELEMENT_TEST;
  static const rchandle<NodeTest> ATTRIBUTE_TEST;
  static const rchandle<NodeTest> PI_TEST;
  static const rchandle<NodeTest> TEXT_TEST;
  static const rchandle<NodeTest> COMMENT_TEST;
  static const rchandle<NodeTest> DOCUMENT_TEST;
  static const rchandle<NodeTest> ITEM_TEST;

  NodeTest(store::StoreConsts::NodeKind kind);

  NodeTest(store::StoreConsts::NodeKind kind, rchandle<NodeNameTest> name_test);

  store::StoreConsts::NodeKind get_kind() const;
  rchandle<NodeNameTest> get_nametest() const;
  store::Item_t get_type_name() const;

  bool is_sub_nodetest_of(const NodeTest& other) const;
  bool operator ==(const NodeTest& other) const;

 private:
  store::StoreConsts::NodeKind    m_kind;
  rchandle<NodeNameTest>   m_name_test;
};

}

#endif /* ZORBA_TEST_TYPES_H */
/* vim:set ts=2 sw=2: */
