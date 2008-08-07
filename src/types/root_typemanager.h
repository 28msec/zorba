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
#ifndef ZORBA_ROOT_TYPEMANAGER_H
#define ZORBA_ROOT_TYPEMANAGER_H

#include <map>
#include <assert.h>
#include "types/typeconstants.h"
#include "types/typeimpl.h"
#include "types/typemanagerimpl.h"

namespace zorba {


/* 
 * Comparator for qnames. First compares local names and if equal then
 * compares namespace
 */
struct qname_compare {
  bool operator()(const store::Item *qn1, const store::Item *qn2) const
  {
    const xqpStringStore *qn1local = qn1->getLocalName();
    const xqpStringStore *qn2local = qn2->getLocalName();

    int lComp = qn1local->compare(qn2local);
    if (lComp < 0) {
      return true;
    } else if (lComp > 0) {
      return false;
    }
    const xqpStringStore *qn1ns = qn1->getNamespace();
    const xqpStringStore *qn2ns = qn2->getNamespace();

    return qn1ns->compare(qn2ns) < 0;
  }
};

class RootTypeManager : public TypeManagerImpl 
{
public:
  ~RootTypeManager();

  store::Item_t XS_ANY_TYPE_QNAME;

  store::Item_t XS_ANY_SIMPLE_TYPE_QNAME;

  store::Item_t XS_UNTYPED_QNAME;

#define ATOMIC_DECL(basename) \
    store::Item_t XS_##basename##_QNAME; \
    xqtref_t basename##_TYPE_ONE;\
    xqtref_t basename##_TYPE_QUESTION; \
    xqtref_t basename##_TYPE_STAR; \
    xqtref_t basename##_TYPE_PLUS;

  ATOMIC_DECL(ANY_ATOMIC)
  ATOMIC_DECL(STRING)
  ATOMIC_DECL(NORMALIZED_STRING)
  ATOMIC_DECL(TOKEN)
  ATOMIC_DECL(LANGUAGE)
  ATOMIC_DECL(NMTOKEN)
  ATOMIC_DECL(NAME)
  ATOMIC_DECL(NCNAME)
  ATOMIC_DECL(ID)
  ATOMIC_DECL(IDREF)
  ATOMIC_DECL(ENTITY)
  ATOMIC_DECL(UNTYPED_ATOMIC)
  ATOMIC_DECL(DATETIME)
  ATOMIC_DECL(DATE)
  ATOMIC_DECL(TIME)
  ATOMIC_DECL(DURATION)
  ATOMIC_DECL(DT_DURATION)
  ATOMIC_DECL(YM_DURATION)
  ATOMIC_DECL(FLOAT)
  ATOMIC_DECL(DOUBLE)
  ATOMIC_DECL(DECIMAL)
  ATOMIC_DECL(INTEGER)
  ATOMIC_DECL(NON_POSITIVE_INTEGER)
  ATOMIC_DECL(NEGATIVE_INTEGER)
  ATOMIC_DECL(LONG)
  ATOMIC_DECL(INT)
  ATOMIC_DECL(SHORT)
  ATOMIC_DECL(BYTE)
  ATOMIC_DECL(NON_NEGATIVE_INTEGER)
  ATOMIC_DECL(UNSIGNED_LONG)
  ATOMIC_DECL(UNSIGNED_INT)
  ATOMIC_DECL(UNSIGNED_SHORT)
  ATOMIC_DECL(UNSIGNED_BYTE)
  ATOMIC_DECL(POSITIVE_INTEGER)
  ATOMIC_DECL(GYEAR_MONTH)
  ATOMIC_DECL(GYEAR)
  ATOMIC_DECL(GMONTH_DAY)
  ATOMIC_DECL(GDAY)
  ATOMIC_DECL(GMONTH)
  ATOMIC_DECL(BOOLEAN)
  ATOMIC_DECL(BASE64BINARY)
  ATOMIC_DECL(HEXBINARY)
  ATOMIC_DECL(ANY_URI)
  ATOMIC_DECL(QNAME)
  ATOMIC_DECL(NOTATION)
#undef ATOMIC_DECL

  xqtref_t ANY_TYPE;

  xqtref_t ANY_SIMPLE_TYPE;

  xqtref_t UNTYPED_TYPE;

  xqtref_t EMPTY_TYPE;

  xqtref_t NONE_TYPE;

#define ALL_QUANT_TYPE_DECL(basename) \
    xqtref_t basename##_TYPE_ONE; \
    xqtref_t basename##_TYPE_QUESTION; \
    xqtref_t basename##_TYPE_STAR; \
    xqtref_t basename##_TYPE_PLUS;

  ALL_QUANT_TYPE_DECL(ITEM)
  ALL_QUANT_TYPE_DECL(ANY_NODE)
  ALL_QUANT_TYPE_DECL(DOCUMENT)
  ALL_QUANT_TYPE_DECL(ELEMENT)
  ALL_QUANT_TYPE_DECL(ATTRIBUTE)
  ALL_QUANT_TYPE_DECL(TEXT)
  ALL_QUANT_TYPE_DECL(PI)
  ALL_QUANT_TYPE_DECL(COMMENT)
#undef ALL_QUANT_TYPE_DECL


  private:

  /**
   * Maps each atomic type code and each quantifier code to a pre-allocated XQType
   * object for that atomic type and quantifier.
   */
  xqtref_t* m_atomic_typecode_map[TypeConstants::ATOMIC_TYPE_CODE_LIST_SIZE][TypeConstants::QUANTIFIER_LIST_SIZE];

  /**
   * Maps the typecode of an atomic type to its qname.
   */
  store::Item* m_atomic_typecode_qname_map[TypeConstants::ATOMIC_TYPE_CODE_LIST_SIZE];

  /**
   *  Maps the qname of an atomic type to its typecode.
   */
  typedef std::map<store::Item*, TypeConstants::atomic_type_code_t, qname_compare> qnametype_map_t;
  qnametype_map_t m_atomic_qnametype_map;

  static const bool ATOMIC_SUBTYPE_MATRIX[TypeConstants::ATOMIC_TYPE_CODE_LIST_SIZE][TypeConstants::ATOMIC_TYPE_CODE_LIST_SIZE];

  static const bool QUANT_SUBTYPE_MATRIX[TypeConstants::QUANTIFIER_LIST_SIZE][TypeConstants::QUANTIFIER_LIST_SIZE];

  static const TypeConstants::castable_t ATOMIC_CAST_MATRIX[TypeConstants::ATOMIC_TYPE_CODE_LIST_SIZE][TypeConstants::ATOMIC_TYPE_CODE_LIST_SIZE];

  /**
   * Given 2 quantifiers, q1 and q2, find the "minimum" quantifier that is
   * equally or more permissive than both q1 and q2.
   */
  static const TypeConstants::quantifier_t QUANT_MULT_MATRIX[TypeConstants::QUANTIFIER_LIST_SIZE][TypeConstants::QUANTIFIER_LIST_SIZE];

  static const TypeConstants::quantifier_t QUANT_INTERS_MATRIX[TypeConstants::QUANTIFIER_LIST_SIZE][TypeConstants::QUANTIFIER_LIST_SIZE];

  RootTypeManager();

  friend class root_static_context;
  friend class TypeOps;
  friend class TypeManagerImpl;
};

}

#endif /* ZORBA_TYPESYSTEM_H */
/* vim:set ts=2 sw=2: */
/*
 * Local variables:
 * mode: c++
 * End:
 */
