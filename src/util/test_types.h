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

    NodeNameTest(rchandle<xqpString_t> uri, rchandle<xqpString_t> local);
    NodeNameTest(rchandle<QNameItem> qname);
    
    rchandle<xqpString_t> get_uri();
    rchandle<xqpString_t> get_local();
  private:
    kind_t m_kind;
    rchandle<xqpString_t> m_uri;
    rchandle<xqpString_t> m_local;
};

class NodeTest : virtual public rcobject {
  public:
    typedef enum {
      ATTRIBUTE,
      COMMENT,
      DOCUMENT,
      ELEMENT,
      PI,
      TEXT
    } kind_t;

    NodeTest(kind_t kind);
    NodeTest(kind_t kind, rchandle<NodeNameTest> name_test);
    kind_t get_kind();
    rchandle<NodeNameTest> get_nametest();
  private:
    kind_t m_kind;
    rchandle<NodeNameTest> m_name_test;
};

}

#endif /* XQP_TEST_TYPES_H */
/* vim:set ts=2 sw=2: */
