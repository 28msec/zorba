#include "store/naive/atomic_items.h"
#include "node_test.h"

using namespace xqp;

const rchandle<NodeTest> NodeTest::ANY_NODE_TEST(new NodeTest(StoreConsts::anyNode));
const rchandle<NodeTest> NodeTest::PI_TEST(new NodeTest(StoreConsts::piNode));
const rchandle<NodeTest> NodeTest::TEXT_TEST(new NodeTest(StoreConsts::textNode));
const rchandle<NodeTest> NodeTest::COMMENT_TEST(new NodeTest(StoreConsts::commentNode));

NodeNameTest::NodeNameTest(
    rchandle<xqpStringStore> uri,
    rchandle<xqpStringStore> local)
  :
  m_uri(uri),
  m_local(local)
{
  const xqpStringStore *urip = uri.get_ptr();
  const xqpStringStore *localp = local.get_ptr();

  if (urip) {
    m_kind = localp ? CONSTANT : CONSTANT_WILDCARD;
  } else {
    m_kind = localp ? WILDCARD_CONSTANT : WILDCARD;
  }
}


NodeNameTest::NodeNameTest(rchandle<Item> qname)
  :
  m_kind(CONSTANT),
  m_uri(qname->getNamespace().theStrStore),
  m_local(qname->getLocalName().theStrStore)
{
}


rchandle<xqpStringStore> NodeNameTest::get_uri() const
{
  return m_uri;
}


rchandle<xqpStringStore> NodeNameTest::get_local() const
{
  return m_local;
}


bool NodeNameTest::is_subname_of(const NodeNameTest& other) const
{
  return (((*other.m_uri) == "*" || (*other.m_uri) == (*m_uri))
    && ((*other.m_local) == "*" || (*other.m_local) == (*m_local)));
}


bool NodeNameTest::operator ==(const NodeNameTest& other) const
{
  return *other.m_uri == *m_uri && *other.m_local == *m_local;
}


NodeTest::NodeTest(StoreConsts::NodeKind kind) : m_kind(kind)
{
}


NodeTest::NodeTest(
    StoreConsts::NodeKind kind,
    rchandle<NodeNameTest> name_test)
  :
  m_kind(kind),
  m_name_test(name_test)
{
}


StoreConsts::NodeKind NodeTest::get_kind() const
{
  return m_kind;
}


rchandle<NodeNameTest> NodeTest::get_nametest() const
{
  return m_name_test;
}


bool NodeTest::is_sub_nodetest_of(const NodeTest& other) const
{
  return other.m_kind == StoreConsts::anyNode
    || (other.m_kind == m_kind
      && (other.m_name_test.get_ptr() == 0
        || (m_name_test.get_ptr() != 0 && m_name_test->is_subname_of(*other.m_name_test))));
}


bool NodeTest::operator ==(const NodeTest& other) const
{
  return other.m_kind == m_kind
    && (
      (other.m_name_test.get_ptr() == 0 && m_name_test.get_ptr() == 0)
        || (other.m_name_test.get_ptr() != 0 && m_name_test.get_ptr() != 0
          && *other.m_name_test == *m_name_test));
}

/* vim:set ts=2 sw=2: */
