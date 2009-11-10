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
#include <vector>

#include "common/shared_types.h"

#include "zorbaerrors/Assert.h"
#include "zorbaerrors/error_manager.h"
#include "zorbatypes/zorbatypes_decl.h"
#include "zorbatypes/xqpstring.h"

#include "system/globalenv.h"

#include "util/tracer.h"

#include "types/casting.h"
#include "types/typeconstants.h"
#include "types/typeops.h"

#include "context/static_context.h"

#include "compiler/api/compilercb.h"

#include "runtime/numerics/numerics.h"
#include "runtime/visitors/planiter_visitor.h"
#include "runtime/core/arithmetic_impl.h"
#include "runtime/api/runtimecb.h"

#include "store/api/item_factory.h"
#include "store/api/item.h"

namespace zorba
{
//6.4.1 fn:abs
bool
AbsIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t item;
  xqtref_t type;

  const TypeManager& tm = *theSctx->get_typemanager();

  const RootTypeManager& rtm = GENV_TYPESYSTEM;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );

  if (consumeNext(result, theChildren[0].getp(), planState ))
  {
    assert(result->isAtomic());

    type = tm.create_value_type(result);
    if ( TypeOps::is_subtype(*type, *rtm.UNTYPED_ATOMIC_TYPE_ONE))
    {
      GenericCast::castToAtomic(result, result, &*rtm.DOUBLE_TYPE_ONE, tm);
      type = tm.create_value_type(result);
    }

    if ( TypeOps::is_subtype ( *type, *rtm.DOUBLE_TYPE_ONE ) )
    {
      if ( result->getDoubleValue().isPos() || result->getDoubleValue().isPosZero()  ) 
      {
        if ( !TypeOps::is_equal ( *type, *rtm.DOUBLE_TYPE_ONE ) )
          GENV_ITEMFACTORY->createDouble (result, result->getDoubleValue() );
      }
      else
        GENV_ITEMFACTORY->createDouble (result, -result->getDoubleValue() );
    }
    else if ( TypeOps::is_subtype ( *type, *rtm.FLOAT_TYPE_ONE ) )
      if ( result->getFloatValue().isPos() || result->getFloatValue().isPosZero() ) {
        if ( !TypeOps::is_equal ( *type, *rtm.FLOAT_TYPE_ONE ) )
          GENV_ITEMFACTORY->createFloat (result, result->getFloatValue() );
      }
      else
        GENV_ITEMFACTORY->createFloat (result, -result->getFloatValue() );
    else if ( TypeOps::is_subtype ( *type, *rtm.INTEGER_TYPE_ONE ) )
      if ( result->getIntegerValue() >= xqp_decimal::zero() ) {
        if ( !TypeOps::is_equal ( *type, *rtm.INTEGER_TYPE_ONE ) )
          GENV_ITEMFACTORY->createInteger (result, result->getIntegerValue() );
      }
      else
        GENV_ITEMFACTORY->createInteger (result, -result->getIntegerValue() );
    else if ( TypeOps::is_subtype ( *type, *rtm.DECIMAL_TYPE_ONE ) )
      if ( result->getDecimalValue() >= xqp_decimal::zero() ) {
        if ( !TypeOps::is_equal ( *type, *rtm.DECIMAL_TYPE_ONE ) )
          GENV_ITEMFACTORY->createDecimal (result, result->getDecimalValue() );
      }
      else
        GENV_ITEMFACTORY->createDecimal (result, -result->getDecimalValue() );
    else
    {
      ZORBA_ERROR_LOC_DESC( XPTY0004,
                            loc, "Wrong operand type for fn:abs.");
    }

    if ( consumeNext(item, theChildren[0].getp(), planState ))
    {
      ZORBA_ERROR_LOC_DESC(XPTY0004, loc,
                           "fn:abs has a sequence longer than one as an operand.");
    }
    STACK_PUSH ( true, state );
  }
  STACK_END (state);
}

//6.4.2 fn:ceiling
bool
CeilingIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t item;
  xqtref_t type;

  const TypeManager& tm = *theSctx->get_typemanager();
  const RootTypeManager& rtm = GENV_TYPESYSTEM;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );

  if (consumeNext(result, theChildren[0].getp(), planState ))
  {
    //get the value and the type of the item
    assert(result->isAtomic());

    type = tm.create_value_type(result);

    //Parameters of type xs:untypedAtomic are always promoted to xs:double
    if ( TypeOps::is_subtype(*type, *rtm.UNTYPED_ATOMIC_TYPE_ONE))
    {
      GenericCast::castToAtomic(result, result, &*rtm.DOUBLE_TYPE_ONE, tm);
      type = tm.create_value_type(result);
    }

    //item type is subtype of DOUBLE
    if ( TypeOps::is_subtype(*type, *rtm.DOUBLE_TYPE_ONE))
      GENV_ITEMFACTORY->createDouble(result, result->getDoubleValue().ceil());

    //item type is subtype of FLOAT
    else if ( TypeOps::is_subtype ( *type, *rtm.FLOAT_TYPE_ONE ) )
      GENV_ITEMFACTORY->createFloat(result, result->getFloatValue().ceil());

    //item type is subtype of INTEGER 
    else if(TypeOps::is_subtype ( *type, *rtm.INTEGER_TYPE_ONE ))
    { /* do nothing */ }

    //item type is subtype of DECIMAL
    else if (TypeOps::is_subtype ( *type, *rtm.DECIMAL_TYPE_ONE ))
      GENV_ITEMFACTORY->createDecimal(result, result->getDecimalValue().ceil());

    else
    {
      ZORBA_ERROR_LOC_DESC( XPTY0004,
                            loc, "Wrong operand type for fn:ceiling.");
    }

    if ( consumeNext(item, theChildren[0].getp(), planState ))
    {
      ZORBA_ERROR_LOC_DESC( XPTY0004,
                            loc, "fn:ceiling has a sequence longer than one as an operand.");
    }
    STACK_PUSH ( true, state );
  }
  STACK_END (state);
}

//6.4.3 fn:floor
bool
FloorIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t item;
  xqtref_t type;

  const TypeManager& tm = *theSctx->get_typemanager();
  const RootTypeManager& rtm = GENV_TYPESYSTEM;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );

  if (consumeNext(result, theChildren[0].getp(), planState ))
  {
    //get the value and the type of the item
    assert(result->isAtomic());

    type = tm.create_value_type(result);

    //Parameters of type xs:untypedAtomic are always promoted to xs:double
    if ( TypeOps::is_subtype(*type, *rtm.UNTYPED_ATOMIC_TYPE_ONE ) )
    {
      GenericCast::castToAtomic(result, result, &*rtm.DOUBLE_TYPE_ONE, tm);
      type = tm.create_value_type(result);
    }

    //item type is subtype of DOUBLE
    if ( TypeOps::is_subtype ( *type, *rtm.DOUBLE_TYPE_ONE ) )
      GENV_ITEMFACTORY->createDouble(result, result->getDoubleValue().floor());

    //item type is subtype of FLOAT
    else if ( TypeOps::is_subtype ( *type, *rtm.FLOAT_TYPE_ONE ) )
      GENV_ITEMFACTORY->createFloat(result, result->getFloatValue().floor());

    //item type is subtype of INTEGER 
    else if(TypeOps::is_subtype ( *type, *rtm.INTEGER_TYPE_ONE ))
    { /* do nothing */ }

    //item type is subtype of DECIMAL
    else if (TypeOps::is_subtype ( *type, *rtm.DECIMAL_TYPE_ONE ))
      GENV_ITEMFACTORY->createDecimal(result, result->getDecimalValue().floor());

    else
    {
      ZORBA_ERROR_LOC_DESC( XPTY0004,
                            loc, "Wrong operand type for fn:floor.");
    }

    if ( consumeNext(item, theChildren[0].getp(), planState ) )
    {
      ZORBA_ERROR_LOC_DESC( XPTY0004,
                            loc, "fn:floor has a sequence longer than one as an operand.");
    }
    STACK_PUSH (true, state );
  }
  STACK_END (state);
}

//6.4.4 fn:round
bool
RoundIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t item;
  store::Item_t res;
  xqtref_t type;

  const TypeManager& tm = *theSctx->get_typemanager();
  const RootTypeManager& rtm = GENV_TYPESYSTEM;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );

  if (consumeNext(result, theChildren[0].getp(), planState ))
  {
    //get the value and the type of the item
    assert(result->isAtomic());

    type = tm.create_value_type(result);

    //Parameters of type xs:untypedAtomic are always promoted to xs:double
    if ( TypeOps::is_subtype(*type, *rtm.UNTYPED_ATOMIC_TYPE_ONE ) )
    {
      GenericCast::castToAtomic(result, result, &*rtm.DOUBLE_TYPE_ONE, tm);
      type = tm.create_value_type(result);
    }

    //item type is subtype of DOUBLE
    if ( TypeOps::is_subtype ( *type, *rtm.DOUBLE_TYPE_ONE ) )
      GENV_ITEMFACTORY->createDouble(result, result->getDoubleValue().round());

    //item type is subtype of FLOAT
    else if ( TypeOps::is_subtype ( *type, *rtm.FLOAT_TYPE_ONE ) )
      GENV_ITEMFACTORY->createFloat(result, result->getFloatValue().round());

    //item type is subtype of INTEGER 
    else if(TypeOps::is_subtype ( *type, *rtm.INTEGER_TYPE_ONE ))
    { /* do nothing */ }

    //item type is subtype of DECIMAL
    else if (TypeOps::is_subtype ( *type, *rtm.DECIMAL_TYPE_ONE ))
      GENV_ITEMFACTORY->createDecimal(result, result->getDecimalValue().round());

    else
    {
      ZORBA_ERROR_LOC_DESC(XPTY0004, loc, "Wrong operand type for fn:round.");
    }

    if ( consumeNext(item, theChildren[0].getp(), planState ))
    {
      ZORBA_ERROR_LOC_DESC(XPTY0004, loc,
                           "fn:round has a sequence longer than one as an operator.");
    }
    STACK_PUSH (true, state );
  }
  STACK_END (state);
}

//6.4.5 fn:round-half-to-even
bool
RoundHalfToEvenIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t item;
  store::Item_t itemPrec;
  store::Item_t res;
  xqtref_t type;
  Integer precision = Integer::parseInt((int32_t)0);

  const TypeManager& tm = *theSctx->get_typemanager();
  const RootTypeManager& rtm = GENV_TYPESYSTEM;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );

  if (consumeNext(result, theChildren [0].getp(), planState ))
  {
    if (theChildren.size () == 2) 
    {
      consumeNext(itemPrec, theChildren[1].getp(), planState);
      assert(itemPrec->isAtomic());

      precision = itemPrec->getIntegerValue();
    }

    //get the value and the type of the item
    assert(result->isAtomic());

    type = tm.create_value_type (result);

    //Parameters of type xs:untypedAtomic are always promoted to xs:double
    if ( TypeOps::is_subtype ( *type, *rtm.UNTYPED_ATOMIC_TYPE_ONE ) )
    {
      GenericCast::castToAtomic(result, result, &*rtm.DOUBLE_TYPE_ONE, tm);
      type = tm.create_value_type (result);
    }

    //item type is subtype of DOUBLE
    if ( TypeOps::is_subtype ( *type, *rtm.DOUBLE_TYPE_ONE ) )
      GENV_ITEMFACTORY->createDouble(result, result->getDoubleValue().roundHalfToEven(precision));

    //item type is subtype of FLOAT
    else if ( TypeOps::is_subtype ( *type, *rtm.FLOAT_TYPE_ONE ) )
      GENV_ITEMFACTORY->createFloat(result, result->getFloatValue().roundHalfToEven(precision));

    //item type is subtype of INTEGER 
    else if(TypeOps::is_subtype ( *type, *rtm.INTEGER_TYPE_ONE ))
    { /* do nothing */ }
    //item type is subtype of DECIMAL
    else if (TypeOps::is_subtype ( *type, *rtm.DECIMAL_TYPE_ONE ))
      GENV_ITEMFACTORY->createDecimal(result, result->getDecimalValue().roundHalfToEven(precision));

    else
    {
      ZORBA_ERROR_LOC_DESC( XPTY0004,
                            loc, "Wrong operand type for fn:round-half-to-even.");
    }

    if ( consumeNext(item, theChildren [0].getp(), planState ))
    {
      ZORBA_ERROR_LOC_DESC( XPTY0004,
                            loc, "fn:round-half-to-even has a sequence longer than one as an operand.");
    }
    STACK_PUSH ( true, state );
  }
  STACK_END (state);
}

//XQuery 1.1 functions
/*******************************************************************************

********************************************************************************/
static const char* decimal_separator_param = "decimal-separator";
static const char* grouping_separator_param = "grouping-separator";
static const char* infinity_param = "infinity";
static const char* minus_sign_param = "minus-sign";
static const char* nan_param = "NaN";
static const char* percent_param = "percent";
static const char* per_mille_param = "per-mille";
static const char* zero_digit_param = "zero-digit";
static const char* digit_param = "digit";
static const char* pattern_separator_param = "pattern-separator";


class FormatNumberInfo
{
public:
  QueryLoc loc;
  // Separators
  xqpStringStore_t decimal_separator;
  xqpStringStore_t grouping_separator;
  xqpStringStore_t percent;
  xqpStringStore_t per_mille;
  xqpStringStore_t zero_digit;
  xqpStringStore_t digit_sign;
  xqpStringStore_t pattern_separator;
  xqpStringStore_t infinity;
  xqpStringStore_t NaN;
  xqpStringStore_t minus;

  class PartInfo
  {
  public:
    xqpStringStore_t str;
    std::vector<int> grouping_pos;
    int N;
    int minimum_size;
    int maximum_size;
    PartInfo() : str(new xqpStringStore()), N(-1), minimum_size(0), maximum_size(0) {};
  };

  class SubPictureInfo
  {
  public:
    xqpStringStore_t str;
    xqpStringStore_t prefix;
    xqpStringStore_t suffix;
    PartInfo integer_part;
    PartInfo fractional_part;
    SubPictureInfo() : str(new xqpStringStore()), prefix(new xqpStringStore()), suffix(new xqpStringStore()) {};
  } pos_subpicture, neg_subpicture;
  
  FormatNumberInfo()
  {
    decimal_separator = new xqpStringStore(".");
    grouping_separator = new xqpStringStore(",");
    percent = new xqpStringStore("%");
    xqpString temp;
    temp = (uint32_t)0x2030;    
    per_mille = temp.theStrStore;
    zero_digit = new xqpStringStore("0");
    digit_sign = new xqpStringStore("#");
    pattern_separator = new xqpStringStore(";");
    infinity = new xqpStringStore("Infinity");
    NaN = new xqpStringStore("NaN");
    minus = new xqpStringStore("-");
  }

  void readFormat(const DecimalFormat_t& df_t)
  {
    if (df_t.isNull())
      return;

    const DecimalFormat::param_vector_type* params = df_t->getParamVector();

    for ( DecimalFormat::param_vector_type::const_iterator it = params->begin(); it != params->end(); it++)
    {
      if (it->first == decimal_separator_param)
        decimal_separator = new xqpStringStore(it->second);
      else if (it->first == grouping_separator_param)
        grouping_separator = new xqpStringStore(it->second);
      else if (it->first == infinity_param)
        infinity = new xqpStringStore(it->second);
      else if (it->first == minus_sign_param)
        minus = new xqpStringStore(it->second);
      else if (it->first == nan_param)
        NaN = new xqpStringStore(it->second);
      else if (it->first == percent_param)
        percent = new xqpStringStore(it->second);
      else if (it->first == per_mille_param)
        per_mille = new xqpStringStore(it->second);
      else if (it->first == zero_digit_param)
        zero_digit = new xqpStringStore(it->second);
      else if (it->first == digit_param)
        digit_sign = new xqpStringStore(it->second);
      else if (it->first == pattern_separator_param)
        pattern_separator = new xqpStringStore(it->second);
    }
  }
};


// returns an error if there are two or more instances of the given pattern in the string
template <typename T>
static void errorIfTwoOrMore(xqpStringStore& part, T sep, QueryLoc& loc)
{
  int pos = part.indexOf(sep);
  if (pos != -1)
    if (part.indexOf(sep, pos+1) != -1)
      ZORBA_ERROR_LOC(XTDE1310, loc);
}


static void parsePart(
    FormatNumberInfo& info,
    FormatNumberInfo::PartInfo& part,
    bool fractional = false)
{
  xqpStringStore& str = *part.str;
  if (str.size() == 0)
    return;

  errorIfTwoOrMore(str, info.percent->c_str(), info.loc);
  errorIfTwoOrMore(str, info.per_mille->c_str(), info.loc);

  if (str.indexOf(info.percent->c_str()) != -1 && str.indexOf(info.per_mille->c_str()) != -1)
    ZORBA_ERROR_LOC(XTDE1310, info.loc);

  if (str.indexOf(info.digit_sign->c_str()) == -1 && str.indexOf(info.zero_digit->c_str()) == -1)
    ZORBA_ERROR_LOC(XTDE1310, info.loc);

  // get grouping separators
  int digit_signs = 0;
  int zero_signs = 0;
  int start = fractional? 0 : str.numChars()-1;
  int end = fractional? str.numChars() : -1;
  int delta = fractional? 1 : -1;  
  int first_digit_sign = -1;
  int last_zero_sign = -1;
  while (start != end)
  {
    xqpStringStore::char_type ch = str.charAt(start);
    if (*info.digit_sign == ch)
    {
      if (first_digit_sign == -1)
        first_digit_sign = start;
      digit_signs++;
    }
    else if (*info.zero_digit == ch)
    {
      last_zero_sign = start;
      zero_signs++;
    }
    else if (*info.grouping_separator == ch)
      part.grouping_pos.push_back(digit_signs+zero_signs);
    start += delta;
  }

  if (first_digit_sign != -1 && last_zero_sign != -1
      &&
      ((!fractional && first_digit_sign > last_zero_sign)
        ||
        (fractional && first_digit_sign < last_zero_sign)))
    ZORBA_ERROR_LOC(XTDE1310, info.loc);

  if (part.grouping_pos.size() > 0 && part.grouping_pos[0] == 0)
    ZORBA_ERROR_LOC(XTDE1310, info.loc);

  if (part.grouping_pos.size() > 0)
  {
    part.N = part.grouping_pos[0];
    for (unsigned int i=1; i<part.grouping_pos.size(); i++)
      if ((part.grouping_pos[i] % part.N) != 0)
      {
        part.N = -1;
        break;
      }
  }
 
  part.minimum_size = zero_signs;
  if (!fractional && zero_signs == 0 && str.indexOf(info.decimal_separator->c_str()) == -1)
    part.minimum_size = 1;

  if (fractional)
    part.maximum_size = digit_signs + zero_signs;
}


static void parseSubpicture(
    FormatNumberInfo::SubPictureInfo& sub_picture,
    FormatNumberInfo& info)
{
  int chars;
  xqpStringStore& str = *sub_picture.str;
  if (str.size() == 0)
    return;

  errorIfTwoOrMore(str, info.decimal_separator->c_str(), info.loc);
  int pos = str.indexOf(info.decimal_separator->c_str());
  if (pos != -1)
  {
    sub_picture.integer_part.str = str.substr(0, pos);
    sub_picture.fractional_part.str = str.substr(pos+1, str.size()-pos);
  }
  else
    sub_picture.integer_part.str = &str;

  parsePart(info, sub_picture.integer_part);
  parsePart(info, sub_picture.fractional_part, true);

  // prefix
  xqpStringStore_t temp = sub_picture.integer_part.str;
  chars = temp->numChars();
  for (int i = 0; i < chars; i++)
  {
    xqpStringStore::char_type ch = temp->charAt(i);
    if (*info.decimal_separator == ch || *info.grouping_separator == ch || *info.zero_digit == ch 
      || *info.digit_sign == ch || *info.pattern_separator == ch || i == chars-1)
    {
      sub_picture.prefix = temp->substr(0, i);
      break;
    }
  }
  // suffix
  temp = sub_picture.fractional_part.str;
  chars = temp->numChars();
  for (int i=chars-1; i >= 0; i--)
  {
    xqpStringStore::char_type ch = temp->charAt(i);
    if (*info.decimal_separator == ch || *info.grouping_separator == ch || *info.zero_digit == ch 
      || *info.digit_sign == ch || *info.pattern_separator == ch || i == 0)
    {
      sub_picture.suffix = temp->substr(i+1, chars-i-1);
      break;
    }
  }
}

static void parsePicture(xqpStringStore& picture, FormatNumberInfo& info)
{
  errorIfTwoOrMore(picture, info.pattern_separator->c_str(), info.loc);

  int pos = picture.indexOf(info.pattern_separator->c_str());
  if (pos != -1)
  {
    info.pos_subpicture.str = picture.substr(0, pos);
    info.neg_subpicture.str = picture.substr(pos+1, picture.size() - pos);
  }
  else 
    info.pos_subpicture.str = &picture;

  parseSubpicture(info.pos_subpicture, info);
  if (info.neg_subpicture.str->size() == 0)
  {
    info.neg_subpicture = info.pos_subpicture;
    xqpStringStore_t temp(info.minus);
    temp->append_in_place(info.pos_subpicture.prefix);
    info.neg_subpicture.prefix = temp;
  }
  else
    parseSubpicture(info.neg_subpicture, info);
}

static bool isAllowedType(store::Item* type_qname)
{
  const RootTypeManager& rtm = GENV_TYPESYSTEM;

  if (type_qname->equals(rtm.XS_FLOAT_QNAME)     
    || type_qname->equals(rtm.XS_DOUBLE_QNAME)
    || type_qname->equals(rtm.XS_DECIMAL_QNAME)
    || type_qname->equals(rtm.XS_INTEGER_QNAME)
    || type_qname->equals(rtm.XS_NON_POSITIVE_INTEGER_QNAME)
    || type_qname->equals(rtm.XS_NEGATIVE_INTEGER_QNAME)
    || type_qname->equals(rtm.XS_LONG_QNAME)
    || type_qname->equals(rtm.XS_INT_QNAME)
    || type_qname->equals(rtm.XS_SHORT_QNAME)
    || type_qname->equals(rtm.XS_BYTE_QNAME)
    || type_qname->equals(rtm.XS_NON_NEGATIVE_INTEGER_QNAME)
    || type_qname->equals(rtm.XS_UNSIGNED_LONG_QNAME)
    || type_qname->equals(rtm.XS_UNSIGNED_INT_QNAME)
    || type_qname->equals(rtm.XS_UNSIGNED_SHORT_QNAME)
    || type_qname->equals(rtm.XS_UNSIGNED_BYTE_QNAME)
    || type_qname->equals(rtm.XS_POSITIVE_INTEGER_QNAME))
    return true;
  else
    return false;
}

// returns n zeros "0". n can be 0 and then the function will return ""
static xqpStringStore_t createZeros(int n)
{
  xqpStringStore_t result = new xqpStringStore("");
  for (int i=0; i<n; i++)
    result->append_in_place("0");
  return result;
}


static void formatGroupings(
    xqpStringStore_t& result,
    xqpStringStore_t& str,
    FormatNumberInfo::PartInfo& part,
    FormatNumberInfo& info)
{
  unsigned int grouping_index = 0;
  result = new xqpStringStore();
  int len = str->numChars();
  for (int i = len-1; i >= 0; i--)
  {
    xqpStringStore::char_type ch = str->charAt(i);

    if (((grouping_index < part.grouping_pos.size()
        &&
        len-i-1 == part.grouping_pos[grouping_index])
      || 
      (part.N != -1 
        &&
        len-1-i != 0
        &&
        ((len-1-i) % part.N) == 0))
      &&
      ch != '-')
    {
      result->append_in_place(info.grouping_separator);
      if (grouping_index < part.grouping_pos.size())
        grouping_index++;
      while (grouping_index < part.grouping_pos.size()
          &&
          part.grouping_pos[grouping_index] == part.grouping_pos[grouping_index-1])
      {
        result->append_in_place(info.grouping_separator);
        grouping_index++;
      }
    }

    if (ch == '0')
      result->append_in_place(info.zero_digit);
    else if (ch == '-')
      ; // skip the '-' sign
    else
      result->append_in_place(ch);
  }
}


static void formatNumber(
    xqpStringStore& resultString,
    store::Item_t& number,
    FormatNumberInfo& info,
    const TypeManager* tm)
{
  const RootTypeManager& rtm = GENV_TYPESYSTEM;

  if (number->isNaN())
  {
    resultString.append_in_place(info.NaN);
    return;
  }

  store::Item_t zero;
  store::Item_t doubleItem;
  bool positive = true;
  FormatNumberInfo::SubPictureInfo& sub_picture = info.pos_subpicture;

  GENV_ITEMFACTORY->createDouble(zero, xqp_double::zero());

  GenericCast::castToAtomic(doubleItem, number, &*rtm.DOUBLE_TYPE_ONE, *tm);

  if (doubleItem->compare(zero) == -1)
  {
    positive = false;
    sub_picture = info.neg_subpicture;
  }

  if (doubleItem->isPosOrNegInf())
  {
    resultString.append_in_place(sub_picture.prefix);
    resultString.append_in_place(info.infinity);
    resultString.append_in_place(sub_picture.suffix);
    return;
  }

  xqp_double adjusted = doubleItem->getDoubleValue();
  if (sub_picture.str->indexOf(info.percent->c_str()) != -1)
    adjusted = adjusted * Double::parseInt(100);
  else if (sub_picture.str->indexOf(info.per_mille->c_str()) != -1)
    adjusted = adjusted * Double::parseInt(1000);

  adjusted = adjusted.roundHalfToEven(Integer::parseInt(sub_picture.fractional_part.maximum_size));
  xqpStringStore_t converted = adjusted.toString(true).theStrStore;
  
  // process min sizes
  xqpStringStore_t integer_part, fractional_part;
  int pos = converted->indexOf(".");
  if (pos == -1)
  {
    integer_part = converted;
    fractional_part = new xqpStringStore("");
  }
  else
  {
    integer_part = converted->substr(0, pos);
    fractional_part = converted->substr(pos+1, converted->numChars() - pos + 1);
  }

  // Add zeros
  xqpStringStore_t temp = createZeros(sub_picture.integer_part.minimum_size - integer_part->numChars());
  temp->append_in_place(integer_part);
  integer_part = temp;  
  fractional_part->append_in_place(createZeros(sub_picture.fractional_part.minimum_size - fractional_part->numChars()));

  // groupings
  xqpStringStore_t integer_part_result, fractional_part_result;
  formatGroupings(integer_part_result, integer_part, sub_picture.integer_part, info);
  integer_part_result = integer_part_result->reverse();
  fractional_part = fractional_part->reverse();
  formatGroupings(fractional_part_result, fractional_part, sub_picture.fractional_part, info);

  resultString.append_in_place(sub_picture.prefix);
  resultString.append_in_place(integer_part_result);
  if (fractional_part->numChars() != 0)
  {
    resultString.append_in_place(info.decimal_separator);
    resultString.append_in_place(fractional_part_result);
  }
  resultString.append_in_place(sub_picture.suffix);
}


bool
FormatNumberIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  xqpStringStore_t resultString, pictureString;
  store::Item_t numberItem, pictureItem, formatName;
  FormatNumberInfo info;
  DecimalFormat_t df_t;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );

  if (planState.theCompilerCB->theRootSctx->xquery_version() == StaticContextConsts::xquery_version_1_0)
    ZORBA_ERROR_LOC_DESC(XPST0017, loc, "The format-number() function is only available in the XQuery 1.1 processing mode.");

  if (!consumeNext(result, theChildren[0].getp(), planState ))
  {
    // Got void, returning void
      STACK_PUSH(false, state);
  }
  else
  {
    info.loc = loc;
    if (!isAllowedType(result->getType()))
      ZORBA_ERROR_LOC(XPTY0004, info.loc);

    consumeNext(pictureItem, theChildren[1].getp(), planState);

    if (theChildren.size() >= 3 &&
        consumeNext(formatName, theChildren[2].getp(), planState))
      df_t = planState.theCompilerCB->theRootSctx->get_decimal_format(formatName);
    else
      df_t = planState.theCompilerCB->theRootSctx->get_decimal_format(NULL);

    info.readFormat(df_t);

    pictureString = pictureItem->getStringValue();
    resultString = new xqpStringStore();
    parsePicture(*pictureString, info);
    formatNumber(*resultString, result, info, theSctx->get_typemanager());

    STACK_PUSH (GENV_ITEMFACTORY->createString(result, resultString), state);
  }
  STACK_END (state);
}

} // namespace zorba