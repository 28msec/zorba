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
#include "store/api/item.h"

namespace zorba {


/***************************************************************************//**
  Class XQType and its subtypes implement xquery's SequenceType spec.
********************************************************************************/
class XQType : public SimpleRCObject
{
public:
  typedef enum 
  {
    ATOMIC_TYPE_KIND,  // Atomic builtin type
    NODE_TYPE_KIND,
    ANY_TYPE_KIND,
    ITEM_KIND,
    ANY_SIMPLE_TYPE_KIND,
    UNTYPED_KIND,
    EMPTY_KIND,
    NONE_KIND,
    USER_DEFINED_KIND, // May be atomic, list, union, or complex
  } type_kind_t;

  typedef enum 
  {
    MIXED_CONTENT_KIND,             // children elements and text
    ELEMENT_ONLY_CONTENT_KIND,      // only children elements
    SIMPLE_CONTENT_KIND,            // no children elements only text
    EMPTY_CONTENT_KIND,             // empty
  } content_kind_t;


protected:
  static const char            * KIND_STRINGS[NONE_KIND + 1];

  const TypeManager            * m_manager;
  const type_kind_t              m_type_kind;
  TypeConstants::quantifier_t    m_quantifier;
  bool                           theIsBuiltin;

  //SYNC_CODE(RCLock               theLock;)


public:
  virtual ~XQType() { }

  virtual std::ostream& serialize(std::ostream& os) const;

  virtual std::string toString() const;

  type_kind_t type_kind() const { return m_type_kind; }

  virtual content_kind_t content_kind() const { return MIXED_CONTENT_KIND; };

  TypeConstants::quantifier_t get_quantifier() const { return m_quantifier; }

  const TypeManager* get_manager() const { return m_manager; }

  virtual store::Item_t get_qname() const { return NULL; }

  void free() 
  {
    if (!theIsBuiltin)
      delete this;
  }

  //long* getSharedRefCounter() { return NULL; }

  //SYNC_CODE(RCLock *getRCLock() { return &theLock; })

protected:
  XQType(const TypeManager* manager,
         type_kind_t type_kind,
         TypeConstants::quantifier_t quantifier,
         bool builtin)
    :
    m_manager(manager),
    m_type_kind(type_kind),
    m_quantifier(quantifier),
    theIsBuiltin(builtin)
  {
  }
};


/***************************************************************************//**
  Class AtomicXQType represents all the sequence types whose ItemType is one
  of the XQDM builtin atomic types.
********************************************************************************/
class AtomicXQType : public XQType
{
 public:
   static const char* ATOMIC_TYPE_CODE_STRINGS[TypeConstants::ATOMIC_TYPE_CODE_LIST_SIZE];

 private:
   TypeConstants::atomic_type_code_t m_type_code;

 public:
   AtomicXQType(
        const TypeManager *manager,
        TypeConstants::atomic_type_code_t type_code,
        TypeConstants::quantifier_t quantifier,
        bool builtin = false)
     :
     XQType(manager, ATOMIC_TYPE_KIND, quantifier, builtin),
     m_type_code(type_code)
   {
   }

   TypeConstants::atomic_type_code_t get_type_code() const { return m_type_code; }

   content_kind_t content_kind() const { return SIMPLE_CONTENT_KIND; };

   virtual std::ostream& serialize(std::ostream& os) const;

   store::Item_t get_qname() const;
};


/***************************************************************************//**
  Class NodeXQType represents all the sequence types whose ItemType is a
  KindTest.
********************************************************************************/
class NodeXQType : public XQType
{
private:
  rchandle<NodeTest> m_nodetest;
  xqtref_t           m_content_type;
  bool               m_nillable;

public:
  NodeXQType(
        const TypeManager* manager,
        rchandle<NodeTest> nodetest,
        xqtref_t content_type,
        TypeConstants::quantifier_t quantifier,
        bool nillable,
        bool builtin = false);

  rchandle<NodeTest> get_nodetest() const { return m_nodetest; }

  xqtref_t get_content_type() const { return m_content_type; }

  content_kind_t content_kind() const { return MIXED_CONTENT_KIND; };

  bool get_nillable() const { return m_nillable; }

  virtual std::ostream& serialize(std::ostream& os) const;
};


/***************************************************************************//**
  Class ItemXQType represents sequence types item(), item()?, item()*, or item()+
********************************************************************************/
class ItemXQType : public XQType
{
public:
  ItemXQType(
        const TypeManager* manager,
        TypeConstants::quantifier_t quantifier,
        bool builtin = false)
    :
    XQType(manager, ITEM_KIND, quantifier, builtin) 
  { 
  }
};


/***************************************************************************//**

********************************************************************************/
class AnyXQType : public XQType
{
public:
  AnyXQType(const TypeManager* manager, bool builtin = false)
    :
    XQType(manager, ANY_TYPE_KIND, TypeConstants::QUANT_STAR, builtin) 
  {
  }

  store::Item_t get_qname() const;
};


/***************************************************************************//**

********************************************************************************/
class AnySimpleXQType : public XQType
{
public:
  AnySimpleXQType(const TypeManager* manager, bool builtin = false)
    :
    XQType(manager, ANY_SIMPLE_TYPE_KIND, TypeConstants::QUANT_STAR, builtin)
  { 
  }

  content_kind_t content_kind() const { return SIMPLE_CONTENT_KIND; };

  store::Item_t get_qname() const;
};


/***************************************************************************//**

********************************************************************************/
class UntypedXQType : public XQType
{
public:
  UntypedXQType(const TypeManager* manager, bool builtin = false)
    :
    XQType(manager, UNTYPED_KIND, TypeConstants::QUANT_STAR, builtin)
  {
  }

  store::Item_t get_qname() const;
};


/***************************************************************************//**
  Represents the empty sequence
********************************************************************************/
class EmptyXQType : public XQType
{
public:
  EmptyXQType(const TypeManager* manager, bool builtin = false)
    :
    XQType(manager, EMPTY_KIND, TypeConstants::QUANT_QUESTION, builtin) 
  { 
  }

  content_kind_t content_kind() const { return EMPTY_CONTENT_KIND; };
};


/***************************************************************************//**

********************************************************************************/
class NoneXQType : public XQType
{
public:
  NoneXQType(const TypeManager* manager, bool builtin = false)
    :
    XQType(manager, NONE_KIND, TypeConstants::QUANT_ONE, builtin) 
  { 
  }

  content_kind_t content_kind() const { return EMPTY_CONTENT_KIND; };
};


/***************************************************************************//**
  UserDefinedXQType does NOT really correspond to a sequence type. Instead, it
  represents a XMLSchema user-defined type that describes the content of an
  element or attribute node.

  Note: m_base_type is NULL for list or union user-defined types.
********************************************************************************/
class UserDefinedXQType : public XQType
{
public:
  enum TYPE_CATEGORY
  {
    ATOMIC_TYPE,  // atomic types: ex: int, date, token, string
    LIST_TYPE,    // list of simple types: ex: list of int: "1 2 33"
    UNION_TYPE,   // union of simple types: ShirtSize int or string: "8", "small"
                  // ATOMIC, LIST and UNION types are all SIMPLE types: i.e. 
                  // their representation is a text value
    COMPLEX_TYPE  // complex types: they represent structure
  };


private:
  store::Item_t              m_qname;
  xqtref_t                   m_baseType;
  TYPE_CATEGORY              m_typeCategory;
  content_kind_t             m_contentKind;
  const XQType*              m_listItemType;
  std::vector<const XQType*> m_unionItemTypes;

public:
  UserDefinedXQType(
        const TypeManager *manager,
        store::Item_t qname,
        xqtref_t baseType,
        TypeConstants::quantifier_t quantifier, 
        content_kind_t contentKind);

  // Constructor for List types 
  UserDefinedXQType(
        const TypeManager *manager,
        store::Item_t qname,
        xqtref_t baseType,
        TypeConstants::quantifier_t quantifier,
        const XQType* listItemType);

  // Constructor for Union types 
  UserDefinedXQType(
        const TypeManager *manager,
        store::Item_t qname,
        xqtref_t baseType,
        TypeConstants::quantifier_t quantifier,
        std::vector<const XQType*> unionItemTypes);

  virtual ~UserDefinedXQType() {}

  virtual content_kind_t content_kind() const { return m_contentKind; };

  store::Item_t get_qname() const { return m_qname;    }

  bool isAtomic()                 const { return m_typeCategory == ATOMIC_TYPE;  }
  bool isList()                   const { return m_typeCategory == LIST_TYPE;    }
  bool isUnion()                  const { return m_typeCategory == UNION_TYPE;   }
  bool isComplex()                const { return m_typeCategory == COMPLEX_TYPE; }
  TYPE_CATEGORY getTypeCategory() const { return m_typeCategory; }

  xqtref_t getBaseType()                            const { return m_baseType; }
  const XQType*  getListItemType()                  const { return m_listItemType; }
  std::vector<const XQType*> getUnionItemTypes()    const { return m_unionItemTypes; }

  bool isSuperTypeOf(const XQType& subType) const;

  virtual std::ostream& serialize(std::ostream& os) const;
};

}

#endif /* ZORBA_TYPEIMPL_H */
/* vim:set ts=2 sw=2: */

/*
 * Local variables:
 * mode: c++
 * End:
 */

