#include "store/naive/atomic_items.h"
#include "test_types.h"

using namespace xqp;

NodeNameTest::NodeNameTest(rchandle<xqpString_t> uri, rchandle<xqpString_t> local)
    : m_uri(uri),
    m_local(local)
{
    const xqpString_t *urip = uri.get_ptr();
    const xqpString_t *localp = local.get_ptr();

    if (urip) {
        m_kind = localp ? CONSTANT : CONSTANT_WILDCARD;
    } else {
        m_kind = localp ? WILDCARD_CONSTANT : WILDCARD;
    }
}

NodeNameTest::NodeNameTest(rchandle<QNameItem> qname)
  : m_kind(CONSTANT),
  m_uri(qname->getNamespace().utf8String),
  m_local(qname->getLocalName().utf8String)
{
}

rchandle<xqpString_t> NodeNameTest::get_uri()
{
  return m_uri;
}

rchandle<xqpString_t> NodeNameTest::get_local()
{
  return m_local;
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

/* vim:set ts=2 sw=2: */
