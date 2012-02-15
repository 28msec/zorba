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
#include "stdafx.h"

#include <vector>

#include "common/shared_types.h"

#include "diagnostics/assert.h"
#include "diagnostics/util_macros.h"
#include "diagnostics/xquery_diagnostics.h"
#include "zorbatypes/zorbatypes_decl.h"

#include "system/globalenv.h"

#include "util/tracer.h"
#include "util/utf8_string.h"

#include "types/casting.h"
#include "types/typeconstants.h"
#include "types/typeops.h"

#include "context/static_context.h"

#include "compiler/api/compilercb.h"

#include "runtime/numerics/numerics.h"
#include "runtime/visitors/planiter_visitor.h"
#include "runtime/core/arithmetic_impl.h"

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

  const TypeManager* tm = theSctx->get_typemanager();

  const RootTypeManager& rtm = GENV_TYPESYSTEM;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(result, theChildren[0].getp(), planState))
  {
    assert(result->isAtomic());

    type = tm->create_value_type(result);

    if (TypeOps::is_subtype(tm, *type, *rtm.UNTYPED_ATOMIC_TYPE_ONE))
    {
      GenericCast::castToAtomic(result, result, &*rtm.DOUBLE_TYPE_ONE, tm, NULL, loc);
      type = tm->create_value_type(result);
    }

    if (TypeOps::is_subtype(tm, *type, *rtm.DOUBLE_TYPE_ONE))
    {
      if (result->getDoubleValue().isPos() || result->getDoubleValue().isPosZero())
      {
        if ( !TypeOps::is_equal(tm, *type, *rtm.DOUBLE_TYPE_ONE))
          GENV_ITEMFACTORY->createDouble (result, result->getDoubleValue());
      }
      else
      {
        GENV_ITEMFACTORY->createDouble(result, -result->getDoubleValue());
      }
    }
    else if (TypeOps::is_subtype(tm, *type, *rtm.FLOAT_TYPE_ONE))
    {
      if ( result->getFloatValue().isPos() || result->getFloatValue().isPosZero())
      {
        if ( !TypeOps::is_equal(tm, *type, *rtm.FLOAT_TYPE_ONE))
          GENV_ITEMFACTORY->createFloat (result, result->getFloatValue());
      }
      else
      {
        GENV_ITEMFACTORY->createFloat(result, -result->getFloatValue());
      }
    }
    else if (TypeOps::is_subtype(tm, *type, *rtm.INTEGER_TYPE_ONE))
    {
      if (result->getIntegerValue() >= xs_decimal::zero())
      {
        if ( !TypeOps::is_equal(tm, *type, *rtm.INTEGER_TYPE_ONE))
          GENV_ITEMFACTORY->createInteger(result, result->getIntegerValue());
      }
      else
      {
        GENV_ITEMFACTORY->createInteger(result, -result->getIntegerValue());
      }
    }
    else if (TypeOps::is_subtype(tm, *type, *rtm.DECIMAL_TYPE_ONE))
    {
      if ( result->getDecimalValue() >= xs_decimal::zero())
      {
        if ( !TypeOps::is_equal(tm, *type, *rtm.DECIMAL_TYPE_ONE))
          GENV_ITEMFACTORY->createDecimal(result, result->getDecimalValue());
      }
      else
      {
        GENV_ITEMFACTORY->createDecimal (result, -result->getDecimalValue());
      }
    }
    else
    {
      RAISE_ERROR(err::XPTY0004, loc,
      ERROR_PARAMS(ZED(BadTypeFor_23), type, "fn:abs" ));
    }

    if ( consumeNext(item, theChildren[0].getp(), planState ))
    {
      RAISE_ERROR(err::XPTY0004, loc,
      ERROR_PARAMS(ZED(NoSeqForFnOp_2), "fn:abs"));
    }

    STACK_PUSH(true, state);
  }
  STACK_END(state);
}

//6.4.2 fn:ceiling
bool
CeilingIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t item;
  xqtref_t type;

  const TypeManager* tm = theSctx->get_typemanager();
  const RootTypeManager& rtm = GENV_TYPESYSTEM;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(result, theChildren[0].getp(), planState))
  {
    //get the value and the type of the item
    assert(result->isAtomic());

    type = tm->create_value_type(result);

    //Parameters of type xs:untypedAtomic are always promoted to xs:double
    if ( TypeOps::is_subtype(tm, *type, *rtm.UNTYPED_ATOMIC_TYPE_ONE))
    {
      GenericCast::castToAtomic(result, result, &*rtm.DOUBLE_TYPE_ONE, tm, NULL, loc);
      type = tm->create_value_type(result);
    }

    //item type is subtype of DOUBLE
    if ( TypeOps::is_subtype(tm, *type, *rtm.DOUBLE_TYPE_ONE))
      GENV_ITEMFACTORY->createDouble(result, result->getDoubleValue().ceil());

    //item type is subtype of FLOAT
    else if ( TypeOps::is_subtype(tm, *type, *rtm.FLOAT_TYPE_ONE))
      GENV_ITEMFACTORY->createFloat(result, result->getFloatValue().ceil());

    //item type is subtype of INTEGER
    else if(TypeOps::is_subtype(tm, *type, *rtm.INTEGER_TYPE_ONE))
    { /* do nothing */ }

    //item type is subtype of DECIMAL
    else if (TypeOps::is_subtype(tm, *type, *rtm.DECIMAL_TYPE_ONE))
      GENV_ITEMFACTORY->createDecimal(result, result->getDecimalValue().ceil());

    else
    {
      RAISE_ERROR(err::XPTY0004, loc,
      ERROR_PARAMS(ZED(BadTypeFor_23), type, "fn:ceiling" ));
    }

    if ( consumeNext(item, theChildren[0].getp(), planState ))
    {
      RAISE_ERROR(err::XPTY0004, loc,
      ERROR_PARAMS(ZED(NoSeqForFnOp_2), "fn:ceiling"));
    }
    STACK_PUSH(true, state);
  }
  STACK_END(state);
}

//6.4.3 fn:floor
bool
FloorIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t item;
  xqtref_t type;

  const TypeManager* tm = theSctx->get_typemanager();
  const RootTypeManager& rtm = GENV_TYPESYSTEM;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(result, theChildren[0].getp(), planState))
  {
    //get the value and the type of the item
    assert(result->isAtomic());

    type = tm->create_value_type(result);

    //Parameters of type xs:untypedAtomic are always promoted to xs:double
    if (TypeOps::is_subtype(tm, *type, *rtm.UNTYPED_ATOMIC_TYPE_ONE))
    {
      GenericCast::castToAtomic(result, result, &*rtm.DOUBLE_TYPE_ONE, tm, NULL, loc);
      type = tm->create_value_type(result);
    }

    //item type is subtype of DOUBLE
    if (TypeOps::is_subtype(tm, *type, *rtm.DOUBLE_TYPE_ONE))
      GENV_ITEMFACTORY->createDouble(result, result->getDoubleValue().floor());

    //item type is subtype of FLOAT
    else if (TypeOps::is_subtype(tm, *type, *rtm.FLOAT_TYPE_ONE))
      GENV_ITEMFACTORY->createFloat(result, result->getFloatValue().floor());

    //item type is subtype of INTEGER
    else if(TypeOps::is_subtype(tm, *type, *rtm.INTEGER_TYPE_ONE))
    { /* do nothing */ }

    //item type is subtype of DECIMAL
    else if (TypeOps::is_subtype(tm, *type, *rtm.DECIMAL_TYPE_ONE))
      GENV_ITEMFACTORY->createDecimal(result, result->getDecimalValue().floor());

    else
    {
      RAISE_ERROR(err::XPTY0004, loc,
      ERROR_PARAMS(ZED(BadTypeFor_23), type, "fn:floor"));
    }

    if ( consumeNext(item, theChildren[0].getp(), planState ) )
    {
      RAISE_ERROR(err::XPTY0004, loc,
      ERROR_PARAMS(ZED(NoSeqForFnOp_2), "fn:floor" ));
    }
    STACK_PUSH (true, state );
  }
  STACK_END (state);
}

bool
RoundIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t item;
  store::Item_t res;
  xqtref_t type;
  store::Item_t precision;
  Integer precision_integer(0);

  const TypeManager* tm = theSctx->get_typemanager();
  const RootTypeManager& rtm = GENV_TYPESYSTEM;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(result, theChildren[0].getp(), planState))
  {
    if (theChildren.size() == 2)
    {
      consumeNext(precision, theChildren[1].getp(), planState);
      assert(precision->isAtomic());

      precision_integer = precision->getIntegerValue();
    }

    //get the value and the type of the item
    assert(result->isAtomic());

    type = tm->create_value_type(result);

    //Parameters of type xs:untypedAtomic are always promoted to xs:double
    if ( TypeOps::is_subtype(tm, *type, *rtm.UNTYPED_ATOMIC_TYPE_ONE))
    {
      GenericCast::castToAtomic(result, result, &*rtm.DOUBLE_TYPE_ONE, tm, NULL, loc);
      type = tm->create_value_type(result);
    }

    //item type is subtype of DOUBLE
    if ( TypeOps::is_subtype(tm, *type, *rtm.DOUBLE_TYPE_ONE))
      GENV_ITEMFACTORY->createDouble(result, result->getDoubleValue().round(precision_integer));

    //item type is subtype of FLOAT
    else if ( TypeOps::is_subtype(tm, *type, *rtm.FLOAT_TYPE_ONE))
      GENV_ITEMFACTORY->createFloat(result, result->getFloatValue().round(precision_integer));

    //item type is subtype of INTEGER
    else if(TypeOps::is_subtype(tm, *type, *rtm.INTEGER_TYPE_ONE))
    {
      if(precision_integer < Integer::zero())
        GENV_ITEMFACTORY->createInteger(result, result->getIntegerValue().round(precision_integer));
    }

    //item type is subtype of DECIMAL
    else if (TypeOps::is_subtype(tm, *type, *rtm.DECIMAL_TYPE_ONE))
      GENV_ITEMFACTORY->createDecimal(result, result->getDecimalValue().round(precision_integer));

    else
    {
      RAISE_ERROR(err::XPTY0004, loc,
      ERROR_PARAMS(ZED(BadTypeFor_23), type, "fn:round"));
    }

    if ( consumeNext(item, theChildren[0].getp(), planState ))
    {
      RAISE_ERROR(err::XPTY0004, loc,
      ERROR_PARAMS(ZED(NoSeqForFnOp_2), "fn:round" ));
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
  Integer precision(0);

  const TypeManager* tm = theSctx->get_typemanager();
  const RootTypeManager& rtm = GENV_TYPESYSTEM;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );

  if (consumeNext(result, theChildren [0].getp(), planState ))
  {
    if (theChildren.size() == 2)
    {
      consumeNext(itemPrec, theChildren[1].getp(), planState);
      assert(itemPrec->isAtomic());

      precision = itemPrec->getIntegerValue();
    }

    //get the value and the type of the item
    assert(result->isAtomic());

    type = tm->create_value_type(result);

    //Parameters of type xs:untypedAtomic are always promoted to xs:double
    if ( TypeOps::is_subtype(tm, *type, *rtm.UNTYPED_ATOMIC_TYPE_ONE))
    {
      GenericCast::castToAtomic(result, result, &*rtm.DOUBLE_TYPE_ONE, tm, NULL, loc);
      type = tm->create_value_type (result);
    }

    //item type is subtype of DOUBLE
    if ( TypeOps::is_subtype(tm, *type, *rtm.DOUBLE_TYPE_ONE))
      GENV_ITEMFACTORY->createDouble(result, result->getDoubleValue().roundHalfToEven(precision));

    //item type is subtype of FLOAT
    else if ( TypeOps::is_subtype(tm, *type, *rtm.FLOAT_TYPE_ONE))
      GENV_ITEMFACTORY->createFloat(result, result->getFloatValue().roundHalfToEven(precision));

    //item type is subtype of INTEGER
    else if(TypeOps::is_subtype(tm, *type, *rtm.INTEGER_TYPE_ONE))
    { /* do nothing */ }
    //item type is subtype of DECIMAL
    else if (TypeOps::is_subtype (tm, *type, *rtm.DECIMAL_TYPE_ONE))
      GENV_ITEMFACTORY->createDecimal(result, result->getDecimalValue().roundHalfToEven(precision));

    else
    {
      RAISE_ERROR(err::XPTY0004, loc,
      ERROR_PARAMS(ZED(BadTypeFor_23), type, "fn:round-half-to-even"));
    }

    if ( consumeNext(item, theChildren [0].getp(), planState ))
    {
      RAISE_ERROR(err::XPTY0004, loc,
      ERROR_PARAMS(ZED(NoSeqForFnOp_2), "fn:round-half-to-even"));
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
  zstring decimal_separator;
  zstring grouping_separator;
  zstring percent;
  zstring per_mille;
  zstring zero_digit;
  zstring digit_sign;
  zstring pattern_separator;
  zstring infinity;
  zstring NaN;
  zstring minus;

  class PartInfo
  {
  public:
    zstring str;
    std::vector<int> grouping_pos;
    int N;
    int minimum_size;
    int maximum_size;
    PartInfo() :  N(-1), minimum_size(0), maximum_size(0) {};
  };

  class SubPictureInfo
  {
  public:
    zstring str;
    zstring prefix;
    zstring suffix;
    PartInfo integer_part;
    PartInfo fractional_part;
    SubPictureInfo() { }
  } pos_subpicture, neg_subpicture;

  FormatNumberInfo() :
    decimal_separator( "." ),
    grouping_separator( "," ),
    percent( "%" ),
    zero_digit( "0" ),
    digit_sign( "#" ),
    pattern_separator( ";" ),
    infinity( "Infinity" ),
    NaN( "NaN" ),
    minus( "-" )
  {
    utf8_string<zstring> u_per_mille( per_mille );
    u_per_mille = 0x2030;
  }

  void readFormat(const DecimalFormat_t& df_t)
  {
    if (df_t.isNull())
      return;

    const DecimalFormat::param_vector_type* params = df_t->getParamVector();

    for ( DecimalFormat::param_vector_type::const_iterator it = params->begin(); it != params->end(); it++)
    {
      if (it->first == decimal_separator_param)
        decimal_separator = it->second.c_str();
      else if (it->first == grouping_separator_param)
        grouping_separator = it->second.c_str();
      else if (it->first == infinity_param)
        infinity = it->second.c_str();
      else if (it->first == minus_sign_param)
        minus = it->second.c_str();
      else if (it->first == nan_param)
        NaN = it->second.c_str();
      else if (it->first == percent_param)
        percent = it->second.c_str();
      else if (it->first == per_mille_param)
        per_mille = it->second.c_str();
      else if (it->first == zero_digit_param)
        zero_digit = it->second.c_str();
      else if (it->first == digit_param)
        digit_sign = it->second.c_str();
      else if (it->first == pattern_separator_param)
        pattern_separator = it->second.c_str();
    }
  }
};


// returns an error if there are two or more instances of the given pattern in the string
static void errorIfTwoOrMore(zstring const& part, const char* sep, QueryLoc& loc)
{
  zstring::size_type const pos = part.find(sep);

  if (pos != zstring::npos)
  {
    if (part.find(sep, strlen(sep), pos+1) != zstring::npos)
      throw XQUERY_EXCEPTION(err::XTDE1310, ERROR_LOC(loc));
  }
}


static void parsePart(
    FormatNumberInfo& info,
    FormatNumberInfo::PartInfo& part,
    bool fractional = false)
{
  zstring& str = part.str;
  if (str.empty())
    return;

  errorIfTwoOrMore(str, info.percent.c_str(), info.loc);
  errorIfTwoOrMore(str, info.per_mille.c_str(), info.loc);

  if (str.find(info.percent.c_str()) != zstring::npos &&
      str.find(info.per_mille.c_str()) != zstring::npos)
  {
    throw XQUERY_EXCEPTION(err::XTDE1310, ERROR_LOC(info.loc));
  }

  if (str.find(info.digit_sign.c_str()) == zstring::npos &&
      str.find(info.zero_digit.c_str()) == zstring::npos)
  {
    throw XQUERY_EXCEPTION(err::XTDE1310, ERROR_LOC(info.loc));
  }

  // get grouping separators
  int digit_signs = 0;
  int zero_signs = 0;
  int start = fractional? 0 : (int)str.size()-1;
  int end = fractional? (int)str.size() : -1;
  int delta = fractional? 1 : -1;
  int first_digit_sign = -1;
  int last_zero_sign = -1;
  while (start != end)
  {
    zstring::value_type ch = str[start];
    if (info.digit_sign[0] == ch)
    {
      if (first_digit_sign == -1)
        first_digit_sign = start;
      digit_signs++;
    }
    else if (info.zero_digit[0] == ch)
    {
      last_zero_sign = start;
      zero_signs++;
    }
    else if (info.grouping_separator[0] == ch)
      part.grouping_pos.push_back(digit_signs+zero_signs);
    start += delta;
  }

  if (first_digit_sign != -1 && last_zero_sign != -1
      &&
      ((!fractional && first_digit_sign > last_zero_sign)
        ||
        (fractional && first_digit_sign < last_zero_sign)))
    throw XQUERY_EXCEPTION(err::XTDE1310, ERROR_LOC(info.loc));

  if (part.grouping_pos.size() > 0 && part.grouping_pos[0] == 0)
    throw XQUERY_EXCEPTION(err::XTDE1310, ERROR_LOC(info.loc));

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
  if (!fractional &&
      zero_signs == 0 &&
      str.find(info.decimal_separator.c_str()) == zstring::npos)
  {
    part.minimum_size = 1;
  }

  if (fractional)
    part.maximum_size = digit_signs + zero_signs;
}


static void parseSubpicture(
    FormatNumberInfo::SubPictureInfo& sub_picture,
    FormatNumberInfo& info)
{
  int chars;
  zstring& str = sub_picture.str;
  if (str.empty())
    return;

  errorIfTwoOrMore(str, info.decimal_separator.c_str(), info.loc);
  zstring::size_type pos = str.find(info.decimal_separator.c_str());
  if (pos != zstring::npos)
  {
    sub_picture.integer_part.str = str.substr(0, pos);
    sub_picture.fractional_part.str = str.substr(pos+1, str.size()-pos);
  }
  else
    sub_picture.integer_part.str = str;

  parsePart(info, sub_picture.integer_part);
  parsePart(info, sub_picture.fractional_part, true);

  // prefix
  zstring temp = sub_picture.integer_part.str;
  chars = (int)temp.size();
  for (int i = 0; i < chars; i++)
  {
    zstring::value_type ch = temp[i];
    if (info.decimal_separator[0] == ch || info.grouping_separator[0] == ch || info.zero_digit[0] == ch
      || info.digit_sign[0] == ch || info.pattern_separator[0] == ch || i == chars-1)
    {
      sub_picture.prefix = temp.substr(0, i);
      break;
    }
  }
  // suffix
  temp = sub_picture.fractional_part.str;
  chars = (int)temp.size();
  for (int i=chars-1; i >= 0; i--)
  {
    zstring::value_type ch = temp[i];
    if (info.decimal_separator[0] == ch || info.grouping_separator[0] == ch || info.zero_digit[0] == ch
      || info.digit_sign[0] == ch || info.pattern_separator[0] == ch || i == 0)
    {
      sub_picture.suffix = temp.substr(i+1, chars-i-1);
      break;
    }
  }
}


static void parsePicture(zstring& picture, FormatNumberInfo& info)
{
  errorIfTwoOrMore(picture, info.pattern_separator.c_str(), info.loc);

  zstring::size_type pos = picture.find(info.pattern_separator.c_str());
  if (pos != zstring::npos)
  {
    info.pos_subpicture.str = picture.substr(0, pos);
    info.neg_subpicture.str = picture.substr(pos+1, picture.size() - pos);
  }
  else
    info.pos_subpicture.str = picture;

  parseSubpicture(info.pos_subpicture, info);
  if (info.neg_subpicture.str.empty())
  {
    info.neg_subpicture = info.pos_subpicture;
    zstring temp(info.minus);
    temp.append(info.pos_subpicture.prefix);
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

// returns n zeros "0". n can be <=0 and then the function will return ""
static zstring createZeros(int n)
{
  zstring result;
  // bugfix for bug #3134696
  // if called from formatNumber with n = -1
  if (n > 0) {
    result.append(n, '0');
  }
  return result;
}


static void formatGroupings(
    zstring& result,
    const zstring& str,
    FormatNumberInfo::PartInfo& part,
    FormatNumberInfo& info)
{
  unsigned int grouping_index = 0;

  result.clear();

  long len = (long)str.size();

  for (long i = len-1; i >= 0; i--)
  {
    char ch = str[i];

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
      result.append(info.grouping_separator);
      if (grouping_index < part.grouping_pos.size())
        grouping_index++;
      while (grouping_index < part.grouping_pos.size()
          &&
          part.grouping_pos[grouping_index] == part.grouping_pos[grouping_index-1])
      {
        result.append(info.grouping_separator);
        grouping_index++;
      }
    }

    if (ch == '0')
      result.append(info.zero_digit);
    else if (ch == '-')
      ; // skip the '-' sign
    else
      result.push_back(ch);
  }
}


static void formatNumber(
    zstring& resultString,
    store::Item_t& number,
    FormatNumberInfo& info,
    const TypeManager* tm,
    const QueryLoc& loc)
{
  const RootTypeManager& rtm = GENV_TYPESYSTEM;

  if (number->isNaN())
  {
    resultString.append(info.NaN);
    return;
  }

  store::Item_t zero;
  store::Item_t doubleItem;
  FormatNumberInfo::SubPictureInfo& sub_picture = info.pos_subpicture;

  GENV_ITEMFACTORY->createDouble(zero, xs_double::zero());

  GenericCast::castToAtomic(doubleItem, number, &*rtm.DOUBLE_TYPE_ONE, tm, NULL, loc);

  if (doubleItem->compare(zero) == -1)
  {
    sub_picture = info.neg_subpicture;
  }

  if (doubleItem->isPosOrNegInf())
  {
    resultString.append(sub_picture.prefix);
    resultString.append(info.infinity);
    resultString.append(sub_picture.suffix);
    return;
  }

  xs_double adjusted = doubleItem->getDoubleValue();

  if (sub_picture.str.find(info.percent) != zstring::npos)
    adjusted *= 100;
  else if (sub_picture.str.find(info.per_mille) != zstring::npos)
    adjusted *= 1000;

  adjusted = adjusted.roundHalfToEven(Integer(sub_picture.fractional_part.maximum_size));

  zstring converted = adjusted.toString(true);

  // process min sizes
  zstring integer_part;
  zstring fractional_part;
  zstring::size_type pos = converted.find(".", 0, 1);
  if (pos == zstring::npos)
  {
    integer_part = converted;
  }
  else
  {
    integer_part = converted.substr(0, pos);
    fractional_part = converted.substr(pos+1, converted.size() - pos + 1);
  }

  // Add zeros
  zstring temp = createZeros((int)(sub_picture.integer_part.minimum_size - integer_part.size()));
  temp.append(integer_part);
  integer_part = temp;
  fractional_part.append(createZeros((int)(sub_picture.fractional_part.minimum_size - fractional_part.size())));

  // groupings
  zstring integer_part_result;
  zstring fractional_part_result;
  formatGroupings(integer_part_result, integer_part, sub_picture.integer_part, info);

  zstring tmp;
  ascii::reverse(integer_part_result, &tmp);
  integer_part_result.swap(tmp);

  tmp.clear();
  ascii::reverse(fractional_part, &tmp);
  fractional_part.swap(tmp);

  formatGroupings(fractional_part_result,
                  fractional_part,
                  sub_picture.fractional_part,
                  info);

  resultString.append(sub_picture.prefix);
  resultString.append(integer_part_result);
  if (fractional_part.size() != 0)
  {
    resultString.append(info.decimal_separator);
    resultString.append(fractional_part_result);
  }
  resultString.append(sub_picture.suffix);
}


bool
FormatNumberIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  zstring resultString;
  zstring pictureString;
  store::Item_t numberItem, pictureItem, formatName;
  FormatNumberInfo info;
  DecimalFormat_t df_t;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );

  if (!consumeNext(result, theChildren[0].getp(), planState ))
  {
    // Got void, assume NaN, return "NaN"
    GENV_ITEMFACTORY->createDouble(result, xs_double::nan());
  }

  {
    info.loc = loc;
    if (!isAllowedType(result->getType()))
    {
      RAISE_ERROR(err::XPTY0004, info.loc,
      ERROR_PARAMS(ZED(FormatNumber_2), result->getType()->getStringValue()));
    }

    consumeNext(pictureItem, theChildren[1].getp(), planState);

    if (theChildren.size() < 3)
    {
      df_t = planState.theCompilerCB->theRootSctx->get_decimal_format(NULL);
    }
    else
    {
      do // use a do/while to avoid a horde of nested if/then/elses
      {
        // The formatName is a string, which must be interpreted as a QName -> 
        // must resolve the namespace, if any
        consumeNext(formatName, theChildren[2].getp(), planState);
        zstring tmpFormatName = formatName->getStringValue();
        formatName = NULL;
        if (tmpFormatName.find(':') ==  zstring::npos)
        {
          GENV_ITEMFACTORY->createQName(formatName, "", "", tmpFormatName);
          break;
        }

        zstring ns;
        zstring prefix = tmpFormatName.substr(0, tmpFormatName.find(':'));
        if (theSctx->lookup_ns(ns, prefix, loc, zerr::ZXQP0000_NO_ERROR))
        {
          GENV_ITEMFACTORY->createQName(formatName, ns, prefix, tmpFormatName.substr(tmpFormatName.find(':')+1));
          break;
        }

        // The prefix is not in the known namespaces, the only posibility left is for the function to be invoked from an EnclosedIterator
        if (planState.theNodeConstuctionPath.empty())
        {
          throw XQUERY_EXCEPTION(err::FODF1280, ERROR_PARAMS(tmpFormatName), ERROR_LOC(loc));
        }

        store::NsBindings bindings;
        planState.theNodeConstuctionPath.top()->getNamespaceBindings(bindings);
        for (unsigned int i=0; i<bindings.size(); i++)
          if (prefix == bindings[i].first)
          {
            GENV_ITEMFACTORY->createQName(formatName, bindings[i].second, prefix, tmpFormatName.substr(tmpFormatName.find(':')+1));
            break;
          }

      } while(0);

      if (formatName.isNull())
        throw XQUERY_EXCEPTION(
          err::FODF1280, ERROR_PARAMS( "<null>" ), ERROR_LOC( loc )
        );

      if ( (df_t = planState.theCompilerCB->theRootSctx->get_decimal_format(formatName)).getp() == NULL )
        throw XQUERY_EXCEPTION(
          err::FODF1280, ERROR_PARAMS( formatName->getStringValue() ),
          ERROR_LOC( loc )
        );

    } // if (theChildren.size() < 3)

    info.readFormat(df_t);

    pictureString = pictureItem->getStringValue();
    parsePicture(pictureString, info);
    formatNumber(resultString, result, info, theSctx->get_typemanager(), loc);

    STACK_PUSH (GENV_ITEMFACTORY->createString(result, resultString), state);
  }

  STACK_END (state);
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
