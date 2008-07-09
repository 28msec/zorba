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
#ifndef ZORBA_TYPEIMPL_H
#define ZORBA_TYPEIMPL_H

#include "common/shared_types.h"
#include "types/node_test.h"
#include "types/typeconstants.h"
#include "zorbatypes/rchandle.h"


namespace zorba {

/*
 * Implementation specific classes after this point.
 */

class XQType : public RCObject 
{
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

  virtual ~XQType() { }

  virtual std::ostream& serialize(std::ostream& os) const;
  virtual std::string toString() const;

  type_kind_t type_kind() const { return m_type_kind; }

  TypeConstants::quantifier_t get_quantifier() const { return m_quantifier; }

  const TypeManager *get_manager() const { return m_manager; }

  long *getSharedRefCounter() { return NULL; }

  SYNC_CODE(RCLock *getRCLock() { return &theLock; })

protected:
  XQType(const TypeManager *manager,
         type_kind_t type_kind,
         TypeConstants::quantifier_t quantifier)
    :
    m_manager(manager),
    m_type_kind(type_kind),
    m_quantifier(quantifier)
  { 
  }

protected:
  const TypeManager            * m_manager;
  const type_kind_t              m_type_kind;
  TypeConstants::quantifier_t    m_quantifier;
  static const char            * KIND_STRINGS[NONE_KIND + 1];
  SYNC_CODE(RCLock               theLock;)
};


class AtomicXQType : public XQType 
{
 public:
   static const char *ATOMIC_TYPE_CODE_STRINGS[TypeConstants::ATOMIC_TYPE_CODE_LIST_SIZE];

 public:
   AtomicXQType(
        const TypeManager *manager,
        TypeConstants::atomic_type_code_t type_code,
        TypeConstants::quantifier_t quantifier)
     :
     XQType(manager, ATOMIC_TYPE_KIND, quantifier),
     m_type_code(type_code)
   {
   }

   TypeConstants::atomic_type_code_t get_type_code() const { return m_type_code; }

   virtual std::ostream& serialize(std::ostream& os) const;

 private:
   TypeConstants::atomic_type_code_t m_type_code;
};


class NodeXQType : public XQType 
{
public:
  NodeXQType(
        const TypeManager *manager,
        rchandle<NodeTest> nodetest,
        xqtref_t content_type,
        TypeConstants::quantifier_t quantifier);

  rchandle<NodeTest> get_nodetest() const { return m_nodetest; }

  xqtref_t get_content_type() const { return m_content_type; }

  virtual std::ostream& serialize(std::ostream& os) const;

private:
  rchandle<NodeTest> m_nodetest;
  xqtref_t           m_content_type;
};


class AnyXQType : public XQType 
{
public:
  AnyXQType(const TypeManager *manager)
    :
    XQType(manager, ANY_TYPE_KIND, TypeConstants::QUANT_STAR) { }
};


class ItemXQType : public XQType 
{
public:
  ItemXQType(const TypeManager *manager, TypeConstants::quantifier_t quantifier)
    :
    XQType(manager, ITEM_KIND, quantifier) { }
};


class AnySimpleXQType : public XQType 
{
public:
  AnySimpleXQType(const TypeManager *manager) 
    :
    XQType(manager, ANY_SIMPLE_TYPE_KIND, TypeConstants::QUANT_STAR) { }
};


class UntypedXQType : public XQType 
{
public:
  UntypedXQType(const TypeManager *manager) 
    :
    XQType(manager, UNTYPED_KIND, TypeConstants::QUANT_STAR) { }
};


class EmptyXQType : public XQType 
{
public:
  EmptyXQType(const TypeManager *manager) 
    :
    XQType(manager, EMPTY_KIND, TypeConstants::QUANT_STAR) { }
};


class NoneXQType : public XQType 
{
public:
  NoneXQType(const TypeManager *manager) 
    :
    XQType(manager, NONE_KIND, TypeConstants::QUANT_ONE) { }
};


class UserDefinedXQType : public XQType
{
private:
  store::Item_t m_qname;
  xqtref_t      m_baseType;
  bool          m_isAtomic;
    
public:
  UserDefinedXQType(
        const TypeManager *manager,
        store::Item_t qname,
        xqtref_t baseType,
        TypeConstants::quantifier_t quantifier);
    
  bool isSuperTypeOf(const XQType& subType) const;

  store::Item_t getQName() const { return m_qname;    }
  bool isAtomic()          const { return m_isAtomic; }
  xqtref_t getBaseType()   const { return m_baseType; }

  virtual std::ostream& serialize(std::ostream& os) const;
};

}

#endif /* ZORBA_TYPEIMPL_H */
/* vim:set ts=2 sw=2: */
