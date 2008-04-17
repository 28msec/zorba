#ifndef ZORBA_TYPEIMPL_H
#define ZORBA_TYPEIMPL_H

#include "common/shared_types.h"
#include "types/node_test.h"


namespace zorba {

/*
 * Implementation specific classes after this point.
 */

class XQType : virtual public SimpleRCObject {
public:
    typedef enum {
      ATOMIC_TYPE_KIND,
      NODE_TYPE_KIND,
      ANY_TYPE_KIND,
      ITEM_KIND,
      ANY_SIMPLE_TYPE_KIND,
      UNTYPED_KIND,
      EMPTY_KIND,
      NONE_KIND,
      USER_DEFINED_KIND,
    } type_kind_t;

    virtual std::ostream& serialize(std::ostream& os) const;
    virtual std::string toString() const;
    virtual type_kind_t type_kind() const = 0;
    TypeConstants::quantifier_t get_quantifier() const { return m_quantifier; }
    virtual ~XQType() { }

    const TypeManager *get_manager() const { return m_manager; }

  protected:
    const TypeManager *m_manager;
    TypeConstants::quantifier_t m_quantifier;
    static const char *KIND_STRINGS[NONE_KIND + 1];

    XQType(const TypeManager *manager, TypeConstants::quantifier_t quantifier)
      : m_manager(manager),
      m_quantifier(quantifier) { }
};

class AtomicXQType : public XQType {
  public:
    AtomicXQType(const TypeManager *manager, TypeConstants::atomic_type_code_t type_code, TypeConstants::quantifier_t quantifier)
      : XQType(manager, quantifier), m_type_code(type_code) { }

    virtual type_kind_t type_kind() const
    {
      return ATOMIC_TYPE_KIND;
    }

    TypeConstants::atomic_type_code_t get_type_code() const { return m_type_code; }

    static const char *ATOMIC_TYPE_CODE_STRINGS[TypeConstants::ATOMIC_TYPE_CODE_LIST_SIZE];

    virtual std::ostream& serialize(std::ostream& os) const;

  private:
    TypeConstants::atomic_type_code_t m_type_code;
};

class NodeXQType : public XQType {
  public:
    virtual type_kind_t type_kind() const
    {
      return NODE_TYPE_KIND;
    }

    NodeXQType(const TypeManager *manager, rchandle<NodeTest> nodetest, xqtref_t content_type, TypeConstants::quantifier_t quantifier);

    rchandle<NodeTest> get_nodetest() const { return m_nodetest; }

    xqtref_t get_content_type() const { return m_content_type; }

    virtual std::ostream& serialize(std::ostream& os) const;

  private:
    rchandle<NodeTest> m_nodetest;
    xqtref_t m_content_type;
};

class AnyXQType : public XQType {
  public:
    virtual type_kind_t type_kind() const
    {
      return ANY_TYPE_KIND;
    }

    AnyXQType(const TypeManager *manager) : XQType(manager, TypeConstants::QUANT_STAR) { }
};

class ItemXQType : public XQType {
  public:
    virtual type_kind_t type_kind() const
    {
      return ITEM_KIND;
    }

    ItemXQType(const TypeManager *manager, TypeConstants::quantifier_t quantifier) : XQType(manager, quantifier) { }
};

class AnySimpleXQType : public XQType {
  public:
    virtual type_kind_t type_kind() const
    {
      return ANY_SIMPLE_TYPE_KIND;
    }

    AnySimpleXQType(const TypeManager *manager) : XQType(manager, TypeConstants::QUANT_STAR) { }
};

class UntypedXQType : public XQType {
  public:
    virtual type_kind_t type_kind() const
    {
      return UNTYPED_KIND;
    }

    UntypedXQType(const TypeManager *manager) : XQType(manager, TypeConstants::QUANT_STAR) { }
};

class EmptyXQType : public XQType {
  public:
    virtual type_kind_t type_kind() const
    {
      return EMPTY_KIND;
    }

    EmptyXQType(const TypeManager *manager) : XQType(manager, TypeConstants::QUANT_ONE) { }
};

class NoneXQType : public XQType {
  public:
    virtual type_kind_t type_kind() const
    {
      return NONE_KIND;
    }

    NoneXQType(const TypeManager *manager) : XQType(manager, TypeConstants::QUANT_ONE) { }
};


class UserDefinedXQType : public XQType
{
private:
    store::Item_t _qname;
    xqtref_t _baseType;
    bool _isAtomic;
    
public:
    virtual type_kind_t type_kind() const
    {
      return USER_DEFINED_KIND;
    }

    UserDefinedXQType(const TypeManager *manager, store::Item_t qname, xqtref_t baseType, TypeConstants::quantifier_t quantifier);
    
    bool isSubTypeOf(const XQType& superType) const;

    store::Item_t getQName() const { return _qname;    }
    bool isAtomic()          const { return _isAtomic; }
    xqtref_t getBaseType()   const { return _baseType; }

    virtual std::ostream& serialize(std::ostream& os) const;
};

}

#endif /* ZORBA_TYPEIMPL_H */
/* vim:set ts=2 sw=2: */
