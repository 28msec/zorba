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
#pragma once
#ifndef ZORBA_ROOT_TYPEMANAGER_H
#define ZORBA_ROOT_TYPEMANAGER_H

#include <assert.h>
#include "types/typeconstants.h"
#include "types/typeimpl.h"
#include "types/typemanagerimpl.h"
#include "zorbautils/hashmap.h"

namespace zorba {


/*******************************************************************************
  RootTypeManager instantiates and stores all of the zorba built-in types. It
  also defines various global, const data structs that are useful in various
  type-related operations. 
********************************************************************************/
class RootTypeManager : public TypeManagerImpl 
{
  friend class GlobalEnvironment;
  friend class TypeOps;
  friend class XQType;
  friend class TypeManagerImpl;
  friend class AtomicXQType;

public:
  /**
   * Pre-allocated XQType object for the "none" type
   */
  xqtref_t NONE_TYPE;

  /**
   * Pre-allocated XQType object for the () sequence type (the empty sequence).
   */ 
  xqtref_t EMPTY_TYPE;

  /**
   *  Pre-allocate XQType objects for item(), item()?, item()+, and item()*.
   */
  xqtref_t ITEM_TYPE_ONE; 
  xqtref_t ITEM_TYPE_QUESTION;
  xqtref_t ITEM_TYPE_STAR;
  xqtref_t ITEM_TYPE_PLUS;

  /**
   * Pre-allocated any function item objects
   */
  xqtref_t ANY_FUNCTION_TYPE_ONE; 
  xqtref_t ANY_FUNCTION_TYPE_QUESTION;
  xqtref_t ANY_FUNCTION_TYPE_STAR;
  xqtref_t ANY_FUNCTION_TYPE_PLUS;

  /**
   * Pre-allocated XQType and QNameItem objects for all of the 45 built-in atomic
   * types of XQDM. Specifically, for each built-in atomic XQDM type T, we pre-
   * allocate a QNameItem for the name of T (as defined by XMLSchema), and 4 
   * XQType objects representing the sequence types T, T?, T*, and T+.
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
  ATOMIC_DECL(NORMALIZED_STRING)      // derived
  ATOMIC_DECL(TOKEN)                  // derived
  ATOMIC_DECL(LANGUAGE)               // derived
  ATOMIC_DECL(NMTOKEN)                // derived
  ATOMIC_DECL(NAME)                   // derived
  ATOMIC_DECL(NCNAME)                 // derived
  ATOMIC_DECL(ID)                     // derived
  ATOMIC_DECL(IDREF)                  // derived
  ATOMIC_DECL(ENTITY)                 // derived
  ATOMIC_DECL(DATETIME)
  ATOMIC_DECL(DATE)
  ATOMIC_DECL(TIME)
  ATOMIC_DECL(DURATION)
  ATOMIC_DECL(DT_DURATION)            // derived
  ATOMIC_DECL(YM_DURATION)            // derived
  ATOMIC_DECL(FLOAT)
  ATOMIC_DECL(DOUBLE)
  ATOMIC_DECL(DECIMAL)
  ATOMIC_DECL(INTEGER)                // derived
  ATOMIC_DECL(NON_POSITIVE_INTEGER)   // derived
  ATOMIC_DECL(NEGATIVE_INTEGER)       // derived
  ATOMIC_DECL(LONG)                   // derived
  ATOMIC_DECL(INT)                    // derived
  ATOMIC_DECL(SHORT)                  // derived
  ATOMIC_DECL(BYTE)                   // derived
  ATOMIC_DECL(NON_NEGATIVE_INTEGER)   // derived
  ATOMIC_DECL(UNSIGNED_LONG)          // derived
  ATOMIC_DECL(UNSIGNED_INT)           // derived
  ATOMIC_DECL(UNSIGNED_SHORT)         // derived
  ATOMIC_DECL(UNSIGNED_BYTE)          // derived
  ATOMIC_DECL(POSITIVE_INTEGER)       // derived
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

#ifdef ZORBA_WITH_JSON
  /**
   * Pre-allocate XQType objects for the following sequence types:
   *
   * N, N?, N+, N*, where N is the jdm::null atomic type
   */
  store::Item_t JS_NULL_QNAME;
  xqtref_t JS_NULL_TYPE_ONE;
  xqtref_t JS_NULL_TYPE_QUESTION;
  xqtref_t JS_NULL_TYPE_STAR;
  xqtref_t JS_NULL_TYPE_PLUS;
#endif

  /**
   *  Pre-allocate XQType objects for structured-item(), structured-item()?,
   *  structured-item()+, and structured-item()*.
   */
  xqtref_t STRUCTURED_ITEM_TYPE_ONE; 
  xqtref_t STRUCTURED_ITEM_TYPE_QUESTION;
  xqtref_t STRUCTURED_ITEM_TYPE_STAR;
  xqtref_t STRUCTURED_ITEM_TYPE_PLUS;

#ifdef ZORBA_WITH_JSON
  /**
   * Pre-allocate XQType objects for the following JSONTest sequence types:
   *
   * N(), N()?, N()+, N()*, where N is one of json-item, object, or array
   */
#define JSON_DECL(basename) \
    xqtref_t basename##_TYPE_ONE;\
    xqtref_t basename##_TYPE_QUESTION; \
    xqtref_t basename##_TYPE_STAR; \
    xqtref_t basename##_TYPE_PLUS;\

  JSON_DECL(JSON_ITEM);
  JSON_DECL(JSON_OBJECT);
  JSON_DECL(JSON_ARRAY);

#undef JSON_DECL

  /**
   * Maps a [json item kind, quantifier] to the corresponding pre-allocated json type
   */
  static const XQType* JSON_TYPES_MAP[3][4];

#endif // ZORBA_WITH_JSON

  /**
   * Pre-allocate XQType objects for the following KindTest sequence types:
   *
   * N(), N()?, N()+, N()*, where N is one of node, document-node, text, comment,
   * or processing-instruction.
   *
   * N(xs:untyped), N(xs:untyped)?, N(xs:untyped)+, N(xs:untyped)*, where N is
   * one of node or document.
   *
   * element(*, xs:anyType), element(*, xs:anyType)?, element(*, xs:anyType)+,
   * element(*, xs:anyType)*
   *
   * element(*, xs:untyped), element(*, xs:untyped)?, element(*, xs:untyped)+,
   * element(*, xs:untyped)*
   *
   * attribute(*, xs:anySimpleType), attribute(*, xs:anySimpleType)?,
   * attribute(*, xs:anySimpleType)+, attribute(*, xs:anySimpleType)*
   *
   * attribute(*, xs:untypedAtomic), attribute(*, xs:untypedAtomic)?,
   * attribute(*, xs:untypedAtomic)+, attribute(*, xs:untypedAtomic)*
   *
   * Note: these types are not part of XMLSchema, and as a result, do not have qnames.
   */
#define ALL_NODE_TYPE_DECL(basename)            \
  xqtref_t basename##_TYPE_ONE;                 \
  xqtref_t basename##_TYPE_QUESTION;            \
  xqtref_t basename##_TYPE_STAR;                \
  xqtref_t basename##_TYPE_PLUS

  ALL_NODE_TYPE_DECL(ANY_NODE);
  ALL_NODE_TYPE_DECL(DOCUMENT);
  ALL_NODE_TYPE_DECL(ELEMENT);
  ALL_NODE_TYPE_DECL(ATTRIBUTE);
  ALL_NODE_TYPE_DECL(TEXT);
  ALL_NODE_TYPE_DECL(PI);
  ALL_NODE_TYPE_DECL(COMMENT);

  ALL_NODE_TYPE_DECL(ANY_NODE_UNTYPED);
  ALL_NODE_TYPE_DECL(DOCUMENT_UNTYPED);
  ALL_NODE_TYPE_DECL(ELEMENT_UNTYPED);
  ALL_NODE_TYPE_DECL(ATTRIBUTE_UNTYPED);

#undef ALL_NODE_TYPE_DECL

  /**
   * Pre-allocated XQType and QNameItem objects for the remaining build-in
   * XQDM types (not including the built-in list types xs:IDREFS, xs:NMTOKENS,
   * and xs:ENTITIES).
   */
  xqtref_t ANY_TYPE;
  xqtref_t UNTYPED_TYPE;
  xqtref_t ANY_SIMPLE_TYPE;

  store::Item_t XS_ANY_TYPE_QNAME;
  store::Item_t XS_UNTYPED_QNAME;
  store::Item_t XS_ANY_SIMPLE_TYPE_QNAME;

private:

  /**
   * Maps each atomic type code and each quantifier code to a built-in XQType
   * object for that built-in atomic type and quantifier.
   */
  xqtref_t* m_atomic_typecode_map[store::XS_LAST][TypeConstants::QUANTIFIER_LIST_SIZE];

  /**
   * Maps the typecode of a built-in atomic type to its qname.
   */
  store::Item* m_atomic_typecode_qname_map[store::XS_LAST];

  /**
   *  Maps the qname of a built-in atomic type to its typecode.
   */
  typedef zorba::HashMap<store::Item*,
                         store::SchemaTypeCode,
                         qname_hash_equals> qnametype_map_t;

  qnametype_map_t m_atomic_qnametype_map;

  /**
   * For each pair T1, T2 of built-in atomic types, ATOMIC_SUBTYPE_MATRIX[T1][T2]
   * contains true if T1 is a subtype of T2; otherwise it contains false.
   */
  static const bool 
  ATOMIC_SUBTYPE_MATRIX[store::XS_LAST][store::XS_LAST];

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
   * For each quatifier q, QUANT_MAX_CNT[q] gives the maximum number of items
   * that can appear in an instance of a sequence type quantified with q. 
   * QUANT_MAX_CNT[q] is either 1 or 2, with 2 meaning infinity.
   */
  static const int QUANT_MAX_CNT[TypeConstants::QUANTIFIER_LIST_SIZE];
  
  /**
   * For each quatifier q, QUANT_MIN_CNT[q] gives the minimum number of items
   * that can appear in an instance of a sequence type quantified with q. 
   */
  static const int QUANT_MIN_CNT[TypeConstants::QUANTIFIER_LIST_SIZE];

  /**
   * For each pair T1, T2 of built-in atomic types, ATOMIC_CAST_MATRIX[T1][T2]
   * says whether an instance of T1 can be cast to an instance of T2. There are
   * 3 posiblities: YES means that such a cast is always possible, MAYBE means
   * that a cast may be possible depending on the particular value of the T1
   * instance, and NO means that the cast is never possible. 
   */
  static const TypeConstants::castable_t 
  ATOMIC_CAST_MATRIX[store::XS_LAST][store::XS_LAST];

public:
  ~RootTypeManager();

private:
  RootTypeManager();
};

}

#endif /* ZORBA_TYPESYSTEM_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
