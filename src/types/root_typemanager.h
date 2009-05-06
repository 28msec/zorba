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

#include <assert.h>
#include "types/typeconstants.h"
#include "types/typeimpl.h"
#include "types/typemanagerimpl.h"
#include "zorbautils/hashmap.h"

namespace zorba {


class RootTypeManager : public TypeManagerImpl 
{
public:
  /**
   * Pre-allocated XQType and QNameItem objects for all of the built-in atomic
   * types of XQDM. Specifically, for each built-in atomic XQDM type T, we pre-
   * allocate a QNameItem for the name of T (as defined by XMLSchema), and 4 
   * XQType objects representing the sequence tyoes T, T?, T*, and T+.
   */
#define ATOMIC_DECL(basename) \
    store::Item_t XS_##basename##_QNAME; \
    xqtref_t basename##_TYPE_ONE;\
    xqtref_t basename##_TYPE_QUESTION; \
    xqtref_t basename##_TYPE_STAR; \
    xqtref_t basename##_TYPE_PLUS;

  ATOMIC_DECL(ANY_ATOMIC)
  ATOMIC_DECL(UNTYPED_ATOMIC)
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

  /**
   *  Pre-allocated XQType objects for all of the XQDM built-in node types and
   *  for the "item" built-in XQDM type. Specifically, we preallocate 4 XQType
   *  objects representing the sequence tyoes T, T?, T*, and T+, where T is either
   *  the "item" type or one of the 6 node types. Note: these types are not part
   *  of XMLSchema, and as a result, do not have qnames.
   */
#define ALL_NODE_OR_ITEM_TYPE_DECL(basename)    \
  xqtref_t basename##_TYPE_ONE;                 \
  xqtref_t basename##_TYPE_QUESTION;            \
  xqtref_t basename##_TYPE_STAR;                \
  xqtref_t basename##_TYPE_PLUS
#define ALL_NODE_TYPE_DECL(basename)                  \
  ALL_NODE_OR_ITEM_TYPE_DECL(basename);               \
  ALL_NODE_OR_ITEM_TYPE_DECL(basename##_UNTYPED_CONT)

  ALL_NODE_OR_ITEM_TYPE_DECL(ITEM);
  ALL_NODE_TYPE_DECL(ANY_NODE);
  ALL_NODE_TYPE_DECL(DOCUMENT);
  ALL_NODE_TYPE_DECL(ELEMENT);
  ALL_NODE_TYPE_DECL(ATTRIBUTE);
  ALL_NODE_TYPE_DECL(TEXT);
  ALL_NODE_TYPE_DECL(PI);
  ALL_NODE_TYPE_DECL(COMMENT);

#undef ALL_NODE_TYPE_DECL
#undef ALL_NODE_OR_ITEM_TYPE_DECL


  /**
   * Pre-allocated XQType and QNameItem objects for the remaining build-in
   * XQDM types (no including the built-in list types xs:IDREFS, xs:NMTOKENS,
   * and xs:ENTITIES).
   */
  xqtref_t ANY_TYPE;
  xqtref_t UNTYPED_TYPE;
  xqtref_t ANY_SIMPLE_TYPE;

  store::Item_t XS_ANY_TYPE_QNAME;
  store::Item_t XS_UNTYPED_QNAME;
  store::Item_t XS_ANY_SIMPLE_TYPE_QNAME;

  /**
   * Pre-allocated XQType object for the () sequence type (the empty sequence).
   */ 
  xqtref_t EMPTY_TYPE;

  /**
   *
   */
  xqtref_t NONE_TYPE;

  /**
   *
   */
  store::Item_t ZXSE_TUPLE_QNAME;

private:

  /**
   * Maps each atomic type code and each quantifier code to a pre-allocated XQType
   * object for that atomic type and quantifier.
   */
  xqtref_t* m_atomic_typecode_map[TypeConstants::ATOMIC_TYPE_CODE_LIST_SIZE]
                                 [TypeConstants::QUANTIFIER_LIST_SIZE];

  /**
   * Maps the typecode of an atomic type to its qname.
   */
  store::Item* m_atomic_typecode_qname_map[TypeConstants::ATOMIC_TYPE_CODE_LIST_SIZE];

  /**
   *  Maps the qname of an atomic type to its typecode.
   */
  typedef zorba::HashMap<store::Item*,
                         TypeConstants::atomic_type_code_t,
                         qname_hash_equals> qnametype_map_t;

  qnametype_map_t m_atomic_qnametype_map;

  /**
   * For each pair T1, T2 of built-in atomic types, ATOMIC_SUBTYPE_MATRIX[T1][T2]
   * contains true if T1 is a subtype of T2; otherwise it contains false.
   */
  static const bool 
  ATOMIC_SUBTYPE_MATRIX[TypeConstants::ATOMIC_TYPE_CODE_LIST_SIZE]
                       [TypeConstants::ATOMIC_TYPE_CODE_LIST_SIZE];

  /**
   * For each quantifier Q, let S(Q) be the following function:
   *
   * S(one) = { 1 }
   * S(?)   = { 0, 1 }
   * S(*)   = { 0, 1, INF }
   * S(+)   = { 1, INF }
   *
   * Then, QUANT_SUBTYPE_MATRIX[q1][q2] is true iff S(q1) is a subset of S(q2).
   */
  static const bool 
  QUANT_SUBTYPE_MATRIX[TypeConstants::QUANTIFIER_LIST_SIZE]
                      [TypeConstants::QUANTIFIER_LIST_SIZE];

  /**
   * Let IS be the inverse of the function S defined above. Then:
   *
   * QUANT_UNION_MATRIX[q1][q2] = q <==> q is IS(S(q1) union S(q2)) 
   * 
   * In other words, q is the "minimum" quantifier that is equally or more
   *  permissive than both q1 and q2.
   */
  static const TypeConstants::quantifier_t
  QUANT_UNION_MATRIX[TypeConstants::QUANTIFIER_LIST_SIZE]
                    [TypeConstants::QUANTIFIER_LIST_SIZE];

  /**
   *  QUANT_INTERS_MATRIX[q1][q2] = q <==> q is IS(S(q1) intersect S(q2)) 
   */
  static const TypeConstants::quantifier_t 
  QUANT_INTERS_MATRIX[TypeConstants::QUANTIFIER_LIST_SIZE]
                     [TypeConstants::QUANTIFIER_LIST_SIZE];

  /**
   * For each pair T1, T2 of built-in atomic types, ATOMIC_CAST_MATRIX[T1][T2]
   * says whether an instance of T1 can be cast to an instance of T2. There are
   * 3 posiblities: YES means that such a cast is always possible, MAYBE means
   * that a cast may be possible depending on the particular value of the T1
   * instance, and NO means that the cast is never possible. 
   */
  static const TypeConstants::castable_t 
  ATOMIC_CAST_MATRIX[TypeConstants::ATOMIC_TYPE_CODE_LIST_SIZE]
                    [TypeConstants::ATOMIC_TYPE_CODE_LIST_SIZE];


public:
  ~RootTypeManager();

private:
  RootTypeManager();

  friend class root_static_context;
  friend class TypeOps;
  friend class TypeManagerImpl;
  friend class AtomicXQType;
};

}

#endif /* ZORBA_TYPESYSTEM_H */
/* vim:set ts=2 sw=2: */
/*
 * Local variables:
 * mode: c++
 * End:
 */
