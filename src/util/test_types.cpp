#include "store/naive/atomic_items.h"
#include "test_types.h"

using namespace xqp;

NodeNameTest::NodeNameTest(rchandle<xqpStringStore> uri, rchandle<xqpStringStore> local)
    : m_uri(uri),
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

NodeNameTest::NodeNameTest(rchandle<QNameItem> qname)
  : m_kind(CONSTANT),
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

NodeTest::NodeTest(NodeTest::kind_t kind) : m_kind(kind)
{
}

NodeTest::NodeTest(NodeTest::kind_t kind, rchandle<NodeNameTest> name_test)
  : m_kind(kind),
  m_name_test(name_test)
{
}

NodeTest::kind_t NodeTest::get_kind()
{
  return m_kind;
}

rchandle<NodeNameTest> NodeTest::get_nametest()
{
  return m_name_test;
}

bool NodeTest::is_sub_nodetest_of(const NodeTest& other) const
{
  return other.m_kind == NODE
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
