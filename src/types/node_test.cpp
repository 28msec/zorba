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
#include "common/common.h"
#include "node_test.h"
#include "zorbatypes/datetime.h"

namespace zorba
{
SERIALIZABLE_CLASS_VERSIONS(NodeTest)
END_SERIALIZABLE_CLASS_VERSIONS(NodeTest)

SERIALIZABLE_CLASS_VERSIONS(NodeNameTest)
END_SERIALIZABLE_CLASS_VERSIONS(NodeNameTest)
}

using namespace zorba;

const rchandle<NodeTest> NodeTest::ANY_NODE_TEST(new NodeTest(store::StoreConsts::anyNode));
const rchandle<NodeTest> NodeTest::ELEMENT_TEST(new NodeTest(store::StoreConsts::elementNode));
const rchandle<NodeTest> NodeTest::ATTRIBUTE_TEST(new NodeTest(store::StoreConsts::attributeNode));
const rchandle<NodeTest> NodeTest::PI_TEST(new NodeTest(store::StoreConsts::piNode));
const rchandle<NodeTest> NodeTest::TEXT_TEST(new NodeTest(store::StoreConsts::textNode));
const rchandle<NodeTest> NodeTest::COMMENT_TEST(new NodeTest(store::StoreConsts::commentNode));
const rchandle<NodeTest> NodeTest::DOCUMENT_TEST(new NodeTest(store::StoreConsts::documentNode));


NodeNameTest::NodeNameTest(
    xqpStringStore_t uri,
    xqpStringStore_t local)
  :
  m_uri(uri),
  m_local(local)
{
  const xqpStringStore *urip = uri.getp();
  const xqpStringStore *localp = local.getp();

  if (urip) {
    m_kind = localp ? CONSTANT : CONSTANT_WILDCARD;
  } else {
    m_kind = localp ? WILDCARD_CONSTANT : WILDCARD;
  }
}


NodeNameTest::NodeNameTest(const store::Item* qname)
  :
  m_kind(CONSTANT),
  m_uri(qname->getNamespace()),
  m_local(qname->getLocalName())
{
}


xqpStringStore_t NodeNameTest::get_uri() const
{
  return m_uri;
}


xqpStringStore_t NodeNameTest::get_local() const
{
  return m_local;
}


bool NodeNameTest::is_subname_of(const NodeNameTest& other) const
{
  return ((other.m_uri->str() == "*" || other.m_uri->byteEqual(*m_uri))
          &&
          (other.m_local->str() == "*" || other.m_local->byteEqual(*m_local)));
}


bool NodeNameTest::operator ==(const NodeNameTest& other) const
{
  return other.m_uri->byteEqual(*m_uri) && other.m_local->byteEqual(*m_local);
}


bool NodeNameTest::matches(const store::Item* qname) const
{
  return ((m_uri->str() == "*" || m_uri->byteEqual(*qname->getNamespace()))
          &&
          (m_local->str() == "*" || m_local->byteEqual(*qname->getLocalName())));
}


bool NodeNameTest::matches(
    const xqpStringStore* lname,
    const xqpStringStore* ns) const
{
  return ((m_uri->str() == "*" || m_uri->byteEqual(*ns))
          &&
          (m_local->str() == "*" || m_local->byteEqual(*lname)));
}


NodeTest::NodeTest(store::StoreConsts::NodeKind kind) 
  :
  m_node_kind(kind)
{
}


NodeTest::NodeTest(
    store::StoreConsts::NodeKind kind,
    rchandle<NodeNameTest> name_test)
  :
  m_node_kind(kind),
  m_name_test(name_test)
{
}


NodeTest::NodeTest(
    store::StoreConsts::NodeKind kind,
    const store::Item* name)
  :
  m_node_kind(kind)
{
  if (name != NULL)
    m_name_test = new NodeNameTest(name);
}


bool NodeTest::is_sub_nodetest_of(const NodeTest& other) const
{
  return (other.m_node_kind == store::StoreConsts::anyNode ||
          (other.m_node_kind == m_node_kind &&
           (other.m_name_test.getp() == 0 ||
            (m_name_test.getp() != 0 &&
             m_name_test->is_subname_of(*other.m_name_test)))));
}


bool NodeTest::operator==(const NodeTest& other) const
{
  return (other.m_node_kind == m_node_kind &&
          ( (other.m_name_test.getp() == 0 && m_name_test.getp() == 0) ||
            (other.m_name_test.getp() != 0 && m_name_test.getp() != 0 &&
             *other.m_name_test == *m_name_test)));
}

/* vim:set ts=2 sw=2: */
