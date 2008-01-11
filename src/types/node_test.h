#ifndef XQP_NODE_TEST_H
#define XQP_NODE_TEST_H

#include "util/rchandle.h"
#include "util/utf8/xqpString.h"
#include "store/api/store_consts.h"

namespace xqp {

class Item;

class NodeNameTest : virtual public rcobject
{
 public:
  typedef enum {
    CONSTANT,
    CONSTANT_WILDCARD,
    WILDCARD_CONSTANT,
    WILDCARD
  } kind_t;

  NodeNameTest(rchandle<xqpStringStore> uri, rchandle<xqpStringStore> local);
  NodeNameTest(rchandle<Item> qname);
    
  rchandle<xqpStringStore> get_uri() const;
  rchandle<xqpStringStore> get_local() const;
  
  bool operator==(const NodeNameTest& other) const;
  bool is_subname_of(const NodeNameTest& other) const;

 private:
  kind_t                   m_kind;
  rchandle<xqpStringStore> m_uri;
  rchandle<xqpStringStore> m_local;
};


class NodeTest : virtual public rcobject
{
 public:
  static const rchandle<NodeTest> ANY_NODE_TEST;
  static const rchandle<NodeTest> PI_TEST;
  static const rchandle<NodeTest> TEXT_TEST;
  static const rchandle<NodeTest> COMMENT_TEST;
  static const rchandle<NodeTest> ITEM_TEST;

  NodeTest(StoreConsts::NodeKind_t kind);

  NodeTest(StoreConsts::NodeKind_t kind, rchandle<NodeNameTest> name_test);

  StoreConsts::NodeKind_t get_kind() const;
  rchandle<NodeNameTest> get_nametest() const;
  Item_t get_type_name() const;

  bool is_sub_nodetest_of(const NodeTest& other) const;
  bool operator ==(const NodeTest& other) const;

 private:
  StoreConsts::NodeKind_t  m_kind;
  rchandle<NodeNameTest>   m_name_test;
};

}

#endif /* XQP_TEST_TYPES_H */
/* vim:set ts=2 sw=2: */
