#ifndef XQP_TEST_TYPES_H
#define XQP_TEST_TYPES_H

#include "util/rchandle.h"
#include "util/utf8/xqpString.h"

namespace xqp {

class QNameItem;

class NodeNameTest : virtual public rcobject {
  public:
    typedef enum {
      CONSTANT,
      CONSTANT_WILDCARD,
      WILDCARD_CONSTANT,
      WILDCARD
    } kind_t;

    NodeNameTest(rchandle<xqpStringStore> uri, rchandle<xqpStringStore> local);
    NodeNameTest(rchandle<QNameItem> qname);
    
    rchandle<xqpStringStore> get_uri() const;
    rchandle<xqpStringStore> get_local() const;

    bool operator ==(const NodeNameTest& other) const;
    bool is_subname_of(const NodeNameTest& other) const;
  private:
    kind_t m_kind;
    rchandle<xqpStringStore> m_uri;
    rchandle<xqpStringStore> m_local;
};

class NodeTest : virtual public rcobject {
  public:
    typedef enum {
      ATTRIBUTE,
      COMMENT,
      DOCUMENT,
      ELEMENT,
      NODE,
      PI,
      TEXT
    } kind_t;

    NodeTest(kind_t kind);
    NodeTest(kind_t kind, rchandle<NodeNameTest> name_test);
    kind_t get_kind();
    rchandle<NodeNameTest> get_nametest();

    bool is_sub_nodetest_of(const NodeTest& other) const;
    bool operator ==(const NodeTest& other) const;
  private:
    kind_t m_kind;
    rchandle<NodeNameTest> m_name_test;
};

}

#endif /* XQP_TEST_TYPES_H */
/* vim:set ts=2 sw=2: */
