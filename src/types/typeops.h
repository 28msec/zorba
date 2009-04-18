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
#ifndef ZORBA_TYPEOPS_H
#define ZORBA_TYPEOPS_H

#include <string>
#include <zorba/config.h>
#include "common/shared_types.h"
#include "types/typeconstants.h"
#include "zorba/typeident.h"
#include "store/api/item.h"


namespace zorba {

typedef TypeIdentifier_t type_ident_ref_t;

// exported for unit testing only
class ZORBA_DLL_PUBLIC TypeOps 
{
public:
  /*
   * Writes a string representation of the given type to the output stream.
   */
  static std::ostream& serialize(std::ostream& os, const XQType& type);
  
  static const char *decode_quantifier (TypeConstants::quantifier_t quant);

  static std::string toString (const XQType& type);

  /**
   * Of the 2 given type managers, return the one with a lower level.
   */
  static const TypeManager* get_lower_manager(const TypeManager* m1, const TypeManager* m2);

  /*
   * Returns the quantifier of the argument.
   */
  static TypeConstants::quantifier_t quantifier(const XQType& type);

  /*
   * Returns the castability fron the source ItemType to the target ItemType. It
   * works only if both source and target types are builtin atomic types.
   * Otherwise, it returns NOT_CASTABLE.
   */
  static TypeConstants::castable_t castability(const XQType& src, const XQType& target);

  /*
   * Returns true iff type1 is equal to type2 including the quantifier,
   * false otherwise.
   */
  static bool is_equal(const XQType& type1, const XQType& type2);

  /*
   * Returns true if _subtype_ is a subtype of _supertype_, false otherwise.
   */
  static bool is_subtype(const XQType& subtype, const XQType& supertype);

  /*
   * Returns true if _item_ is treatable as _type_, false otherwise.
   */
  static bool is_treatable(const store::Item_t& item, const XQType& type);

  /*
   * Returns true if the quantifier of the given sequence type is QUANT_ONE and
   * its ItemType is a builtin atomic type.
   */
  static bool is_atomic(const XQType& type);

  /*
   * Returns true if the ItemType of the given sequence type is a builtin
   * atomic type.
   *
   */
  static bool is_simple(const XQType& type);

  /*
   * Returns true is the given sequence type is a subtype of an atomic builtin
   * nu,eric type (xs:decimal, xs:double, or xs:float)
   */
  static bool is_numeric(const XQType& type);
  
  /*
   * Returns true if the given sequence type is the empty sequence.
   */
  static bool is_empty(const XQType& type);

  /*
   * Returns true if the given sequence type is the none type.
   */
  static bool is_none(const XQType& type);
  
  /*
   * Returns true is the given type could be a date / time type.
   */
  static bool maybe_date_time (const XQType& type);

  /*
   * Returns the atomic_type_code_t for the given type.
   * The input type MUST be atomic.
   */
  static TypeConstants::atomic_type_code_t get_atomic_type_code(const XQType& type);

  /*
   * Computes the union type (type1 | type2), of the two types.
   * The output _u_ of this call satisfies the following invariant.
   *      is_subtype(_type1_, _u_) == true && is_subtype(_type2_, _u_) == true
   */
  static xqtref_t union_type(const XQType& type1, const XQType& type2);

  /*
   * Computes the intersection of the two types.
   * The output _u_ of this call satisfies the following invariant.
   *      there exists some type(not necessarily representable in this TypeSystem), _t_
   *      such that:
   *          is_subtype(_t_, _type1_) == true && is_subtype(_t_, _type2_) == true
   *          && is_subtype(_t_, _u_) == true.
   *
   * Informally, the returned type is a supertype (not necessarily a perfect supertype)
   * of the actual intersection type.
   */
  static xqtref_t intersect_type(const XQType& type1, const XQType& type2);

  /*
   * Returns the prime type of the given type.
   */
  static xqtref_t prime_type(const XQType& type);

  /*
   * Returns the type to be used for arithmetic ops.
   */
  static xqtref_t arithmetic_type_exact(const XQType& type1, const XQType& type2);

  /*
   * Returns the type to be used for arithmetic ops.
   */
  static xqtref_t arithmetic_type_static(const XQType& type1, const XQType& type2);

  /*
   * Returns the type to be used for arithmetic ops.
   */
  static xqtref_t arithmetic_type(const XQType& type1, const XQType& type2);

  /*
   * Returns the NodeNameTest for the given type, if one exists.
   */
  static rchandle<NodeNameTest> get_nametest(const XQType& type);

  /*
   * Returns a type identifier that represents the given type.
   * The invariant that is guaranteed is:
   *    is_subtype(_t_, create_type(*get_type_identifier(_t_))) == true
   */
  static type_ident_ref_t get_type_identifier(const XQType& type);

  /*
   * @return 0, 1 or 2 (2 meaning "many")
   */
  static int type_max_cnt (const XQType& type);
  
  /*
   * @return 0 or 1
   */
  static int type_min_cnt (const XQType& type);
  
  /*
   * @return 0, 1 or -1 (-1 means "not certain")
   */
  static int type_cnt (const XQType& type);

  /*
   * @return QName of the type if known.
   */
  static store::Item_t getQName(const XQType& type);

public:
  static const int QUANT_MAX_CNT [TypeConstants::QUANTIFIER_LIST_SIZE];
  
  static const int QUANT_MIN_CNT [TypeConstants::QUANTIFIER_LIST_SIZE];
};

}

#endif /* ZORBA_TYPEOPS_H */
/* vim:set ts=2 sw=2: */
/*
 * Local variables:
 * mode: c++
 * End:
 */
