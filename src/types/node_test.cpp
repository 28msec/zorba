#include "store/naive/atomic_items.h"
#include "node_test.h"

using namespace zorba;

const rchandle<NodeTest> NodeTest::ANY_NODE_TEST(new NodeTest(store::StoreConsts::anyNode));
const rchandle<NodeTest> NodeTest::PI_TEST(new NodeTest(store::StoreConsts::piNode));
const rchandle<NodeTest> NodeTest::TEXT_TEST(new NodeTest(store::StoreConsts::textNode));
const rchandle<NodeTest> NodeTest::COMMENT_TEST(new NodeTest(store::StoreConsts::commentNode));

NodeNameTest::NodeNameTest(
    rchandle<xqpStringStore> uri,
    rchandle<xqpStringStore> local)
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


NodeNameTest::NodeNameTest(rchandle<store::Item> qname)
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


NodeTest::NodeTest(store::StoreConsts::NodeKind kind) : m_kind(kind)
{
}


NodeTest::NodeTest(
    store::StoreConsts::NodeKind kind,
    rchandle<NodeNameTest> name_test)
  :
  m_kind(kind),
  m_name_test(name_test)
{
}


store::StoreConsts::NodeKind NodeTest::get_kind() const
{
  return m_kind;
}


rchandle<NodeNameTest> NodeTest::get_nametest() const
{
  return m_name_test;
}


bool NodeTest::is_sub_nodetest_of(const NodeTest& other) const
{
  return other.m_kind == store::StoreConsts::anyNode
    || (other.m_kind == m_kind
      && (other.m_name_test.getp() == 0
        || (m_name_test.getp() != 0 && m_name_test->is_subname_of(*other.m_name_test))));
}


bool NodeTest::operator ==(const NodeTest& other) const
{
  return other.m_kind == m_kind
    && (
      (other.m_name_test.getp() == 0 && m_name_test.getp() == 0)
        || (other.m_name_test.getp() != 0 && m_name_test.getp() != 0
          && *other.m_name_test == *m_name_test));
}

/* vim:set ts=2 sw=2: */
