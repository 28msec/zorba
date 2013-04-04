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
#include "compiler/api/compilercb.h"
#include "context/static_context.h"
#include "diagnostics/xquery_diagnostics.h"
#include "runtime/core/arithmetic_impl.h"
#include "runtime/numerics/numerics.h"
#include "runtime/visitors/planiter_visitor.h"
#include "store/api/item.h"
#include "store/api/item_factory.h"
#include "system/globalenv.h"
#include "types/casting.h"
#include "types/typeconstants.h"
#include "types/typeops.h"
#include "util/xml_util.h"
#include "zorbatypes/zorbatypes_decl.h"

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

struct picture {

  struct part {
    zstring format;
    std::vector<int> grouping_pos;
    int N;
    int minimum_size;
    int maximum_size;
    part() : N( -1 ), minimum_size( 0 ) , maximum_size( 0 ) {
    }
  };

  struct sub_picture {
    zstring format;
    zstring prefix;
    zstring suffix;
    part integer_part;
    part fractional_part;
  };

  zstring format;                       // original $picture
  sub_picture pos_subpicture, neg_subpicture;

  // See XQuery F&O 3.0: 4.7.1.
  enum var_type {
    decimal_separator_sign,
    grouping_separator_sign,
    infinity,
    mandatory_digit_sign,
    minus_sign,
    NaN,
    optional_digit_sign,
    pattern_separator_sign,
    percent_sign,
    per_mille_sign,
    NUM_VARS
  };

  zstring var[ NUM_VARS ];

# define VAR(NAME) var[ picture::NAME ]

  picture() {
    VAR( decimal_separator_sign ) = ".";
    VAR( grouping_separator_sign ) = ",";
    VAR( infinity ) = "Infinity";
    VAR( mandatory_digit_sign ) = "0";
    VAR( minus_sign ) = "-";
    VAR( NaN ) = "NaN";
    VAR( optional_digit_sign ) = "#";
    VAR( pattern_separator_sign ) = ";";
    VAR( percent_sign ) = "%";
    VAR( per_mille_sign ) = "\xE2\x80\xB0";
  }

  // default picture(picture const&) is fine
  // default picture& operator=(picture const&) is fine
};

///////////////////////////////////////////////////////////////////////////////

static bool is_active( int pic_var_type ) {
  //
  // XQuery F&O 3.0 4.7.3: The ... variables decimal-separator-sign,
  // grouping-sign, decimal-digit-family, optional-digit-sign and
  // pattern-separator-sign are classified as active characters, and all other
  // characters (including the percent-sign and per-mille-sign) are classified
  // as passive characters.
  //
  switch ( pic_var_type ) {
    case picture::decimal_separator_sign:
    case picture::grouping_separator_sign:
    case picture::mandatory_digit_sign: // aka, decimal-digit-family
    case picture::optional_digit_sign:
    case picture::pattern_separator_sign:
      return true;
    default:
      return false;
  }
}

static void check_multiple( zstring const &sub_pic, zstring const &sign,
                            picture const &pic, QueryLoc const &loc ) {
  zstring::size_type const pos = sub_pic.find( sign );
  if ( pos != zstring::npos &&
       sub_pic.find( sign, pos + sign.size() ) != zstring::npos ) {
    throw XQUERY_EXCEPTION(
      err::FODF1310,
      ERROR_PARAMS( pic.format, ZED( FODF1310_MultipleSign_3 ), sign ),
      ERROR_LOC( loc )
    );
  }
}

static bool is_allowed_type( store::Item const *type_qname ) {
  RootTypeManager const &rtm = GENV_TYPESYSTEM;
  return type_qname->equals( rtm.XS_FLOAT_QNAME )
      || type_qname->equals( rtm.XS_DOUBLE_QNAME )
      || type_qname->equals( rtm.XS_DECIMAL_QNAME )
      || type_qname->equals( rtm.XS_INTEGER_QNAME )
      || type_qname->equals( rtm.XS_INT_QNAME )
      || type_qname->equals( rtm.XS_LONG_QNAME )
      || type_qname->equals( rtm.XS_SHORT_QNAME )
      || type_qname->equals( rtm.XS_BYTE_QNAME )
      || type_qname->equals( rtm.XS_NON_NEGATIVE_INTEGER_QNAME )
      || type_qname->equals( rtm.XS_NON_POSITIVE_INTEGER_QNAME )
      || type_qname->equals( rtm.XS_NEGATIVE_INTEGER_QNAME )
      || type_qname->equals( rtm.XS_POSITIVE_INTEGER_QNAME )
      || type_qname->equals( rtm.XS_UNSIGNED_INT_QNAME )
      || type_qname->equals( rtm.XS_UNSIGNED_LONG_QNAME )
      || type_qname->equals( rtm.XS_UNSIGNED_SHORT_QNAME )
      || type_qname->equals( rtm.XS_UNSIGNED_BYTE_QNAME );
}

static void parse_part( picture::part *part, picture const &pic,
                        QueryLoc const &loc, bool is_fractional = false ) {
  if ( part->format.empty() )
    return;

#if 0
  if ( part.format.find( pic.mandatory_digit_sign ) == zstring::npos &&
       part.format.find( pic.zero_digit ) == zstring::npos ) {
    throw XQUERY_EXCEPTION(
      err::FODF1310,
      ERROR_PARAMS(
        pic.format,
        ZED( FormatNumberAtLeastOneOptionalOrDecimal )
      ),
      ERROR_LOC( pic.loc )
    );
  }

  // get grouping separators
  int digit_signs = 0;
  int zero_signs = 0;
  int start = is_fractional? 0 : (int)part.format.size()-1;
  int end = is_fractional? (int)part.format.size() : -1;
  int delta = is_fractional? 1 : -1;
  int first_digit_sign = -1;
  int last_zero_sign = -1;

  while ( start != end ) {
    zstring::value_type ch = part.format[start];
    if ( pic.mandatory_digit_sign[0] == ch ) {
      if ( first_digit_sign == -1 )
        first_digit_sign = start;
      ++digit_signs;
    } else if ( pic.zero_digit[0] == ch ) {
      last_zero_sign = start;
      ++zero_signs;
    } else if ( pic.grouping_separator[0] == ch )
      part.grouping_pos.push_back( digit_signs + zero_signs );
    start += delta;
  }

  if ( first_digit_sign != -1 && last_zero_sign != -1 ) {
    if (!is_fractional && first_digit_sign > last_zero_sign)
      throw XQUERY_EXCEPTION(
        err::FODF1310,
        ERROR_PARAMS( pic.format, ZED( FormatNumberIntegerPart ) ),
        ERROR_LOC( loc )
      );
    else if ( is_fractional && first_digit_sign < last_zero_sign )
      throw XQUERY_EXCEPTION(
        err::FODF1310,
        ERROR_PARAMS( pic.format, ZED( FormatNumberFractionalPart ) ),
        ERROR_LOC( loc )
      );
  }

  if ( part.grouping_pos.size() > 0 && part.grouping_pos[0] == 0 )
    throw XQUERY_EXCEPTION(
      err::FODF1310,
      ERROR_PARAMS(
        pic.format,
        ZED( FormatNumberGroupingAdjacentToDecimal )
      ),
      ERROR_LOC(pic.loc)
    );

  if (part.grouping_pos.size() > 0) {
    part.N = part.grouping_pos[0];
    for (unsigned int i=1; i<part.grouping_pos.size(); i++)
      if ( part.grouping_pos[i] % part.N ) {
        part.N = -1;
        break;
      }
  }

  part.minimum_size = zero_signs;
  if ( !is_fractional &&
       zero_signs == 0 &&
       part.format.find(pic.decimal_separator) == zstring::npos) {
    part.minimum_size = 1;
  }

  if ( is_fractional )
    part.maximum_size = digit_signs + zero_signs;
#endif
}


static void parse_subpicture( picture::sub_picture *sub_pic,
                              picture const &pic, QueryLoc const &loc ) {
  if ( sub_pic->format.empty() )
    return;

  //
  // XQuery F&O 3.0: 4.7.3:
  //
  // * A sub-picture must not contain more than one decimal-separator-sign.
  //
  // * A sub-picture must not contain more than one percent-sign or
  //   per-mille-sign, and it must not contain one of each.
  //
  check_multiple( sub_pic->format, pic.VAR( decimal_separator_sign ), pic, loc );
  check_multiple( sub_pic->format, pic.VAR( percent_sign ), pic, loc );
  check_multiple( sub_pic->format, pic.VAR( per_mille_sign ), pic, loc );
  if ( sub_pic->format.find( pic.VAR( percent_sign ) ) != zstring::npos &&
       sub_pic->format.find( pic.VAR( per_mille_sign ) ) != zstring::npos ) {
    throw XQUERY_EXCEPTION(
      err::FODF1310,
      ERROR_PARAMS( pic.format, ZED( FormatNumberPercentPermille ) ),
      ERROR_LOC( loc )
    );
  }

  zstring::size_type pos
    = sub_pic->format.find( pic.VAR( decimal_separator_sign ) );
  if ( pos != zstring::npos ) {
    sub_pic->integer_part.format = sub_pic->format.substr( 0, pos );
    sub_pic->fractional_part.format =
      sub_pic->format.substr( pos + pic.VAR( decimal_separator_sign ).size() );
  } else
    sub_pic->integer_part.format = sub_pic->format;

  parse_part( &sub_pic->integer_part, pic, loc );
  parse_part( &sub_pic->fractional_part, pic, loc, true );

  //
  // Ibid: The prefix is set to contain all passive characters in the
  // sub-picture to the left of the leftmost active character.
  //
  zstring::size_type left_pos = zstring::npos;
  for ( int i = 0; i < picture::NUM_VARS; ++i ) {
    if ( is_active( i ) )
      if ( (pos = sub_pic->format.find( pic.var[ i ] )) < left_pos )
        left_pos = pos;
  }
  sub_pic->prefix = sub_pic->format.substr( 0, left_pos );

  //
  // Ibid: The suffix is set to contain all passive characters to the right of
  // the rightmost active character in the fractional part of the sub-picture.
  //
  zstring::size_type right_pos = 0;
  for ( int i = 0; i < picture::NUM_VARS; ++i ) {
    if ( is_active( i ) ) {
      pos = sub_pic->fractional_part.format.find( pic.var[ i ] );
      if ( pos > right_pos )
        right_pos = pos;
    }
  }
  sub_pic->suffix = sub_pic->fractional_part.format.substr( right_pos );
}

static void format_groupings( zstring &result, zstring const &format,
                              picture::part const &part, picture const &pic ) {
#if 0
  unsigned int grouping_index = 0;

  result.clear();

  long len = (long)format.size();

  for ( long i = len-1; i >= 0; --i ) {
    char ch = format[i];

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
      result.append( pic.VAR( grouping_separator_sign ) );
      if ( grouping_index < part.grouping_pos.size() )
        ++grouping_index;
      while (grouping_index < part.grouping_pos.size()
          &&
          part.grouping_pos[grouping_index] == part.grouping_pos[grouping_index-1])
      {
        result.append( pic.VAR( grouping_separator_sign ) );
        ++grouping_index;
      }
    }

    if ( ch == '0' )
      result.append( pic.zero_digit );
    else if ( ch == '-' )
      ; // skip the '-' sign
    else
      result.push_back( ch );
  }
#endif
}

static void format_number( store::Item_t &number, picture const &pic,
                           TypeManager const *tm, QueryLoc const &loc,
                           zstring *dest ) {
  if ( number->isNaN() ) {
    //
    // XQuery F&O 3.0: 4.7.5: If the input number is NaN (not a number), the
    // result is the specified NaN-symbol (with no prefix or suffix).
    //
    *dest = pic.NaN;
    return;
  }

  store::Item_t zero;
  store::Item_t double_number;
  RootTypeManager const &rtm = GENV_TYPESYSTEM;

  GENV_ITEMFACTORY->createDouble( zero, xs_double::zero() );

  GenericCast::castToAtomic(
    double_number, number, &*rtm.DOUBLE_TYPE_ONE, tm, nullptr, loc
  );

  picture::sub_picture const &sub_pic =
    double_number->compare( zero ) == -1 ?
      pic.pos_subpicture : pic.neg_subpicture;

  if ( double_number->isPosOrNegInf() ) {
    dest->append( sub_pic.prefix );
    dest->append( pic.VAR( infinity ) );
    dest->append( sub_pic.suffix );
    return;
  }

  xs_double adjusted = double_number->getDoubleValue();

  if ( sub_pic.format.find( pic.percent_sign ) != zstring::npos )
    adjusted *= 100;
  else if ( sub_pic.format.find( pic.per_mille_sign ) != zstring::npos )
    adjusted *= 1000;

  adjusted = adjusted.roundHalfToEven(
    xs_integer( sub_pic.fractional_part.maximum_size )
  );

  zstring converted = adjusted.toString( true );

  // process min sizes
  zstring integer_part;
  zstring fractional_part;
  zstring::size_type pos = converted.find( ".", 0, 1 );
  if ( pos == zstring::npos ) {
    integer_part = converted;
  } else {
    integer_part = converted.substr( 0, pos );
    fractional_part = converted.substr( pos + 1 );
  }

#if 0
  // Add zeros
  zstring temp = createZeros((int)(sub_pic.integer_part.minimum_size - integer_part.size()));
  temp.append(integer_part);
  integer_part = temp;
  fractional_part.append(createZeros((int)(sub_pic.fractional_part.minimum_size - fractional_part.size())));
#endif

  // groupings
  zstring integer_part_result;
  zstring fractional_part_result;
  format_groupings(
    integer_part_result, integer_part, sub_pic.integer_part, pic
  );

  zstring tmp;
  ascii::reverse( integer_part_result, &tmp );
  integer_part_result.swap( tmp );

  tmp.clear();
  ascii::reverse( fractional_part, &tmp );
  fractional_part.swap( tmp );

  format_groupings(
    fractional_part_result, fractional_part, sub_pic.fractional_part, pic
  );

  dest->append( sub_pic.prefix );
  dest->append( integer_part_result );
  if ( fractional_part.size() != 0 ) {
    dest->append( pic.VAR( decimal_separator_sign ) );
    dest->append( fractional_part_result );
  }
  dest->append( sub_pic.suffix );
}

static void parse_picture( picture *pic, QueryLoc const &loc ) {
  check_multiple( pic->format, pic->VAR( pattern_separator_sign ), *pic, loc );

  zstring::size_type const pos =
    pic->format.find( pic->VAR( pattern_separator_sign ) );

  if ( pos != zstring::npos ) {
    pic->pos_subpicture.format = pic->format.substr( 0, pos );
    pic->neg_subpicture.format =
      pic->format.substr( pos + pic->VAR( pattern_separator_sign ).size() );
  } else
    pic->pos_subpicture.format = pic->format;

  parse_subpicture( &pic->pos_subpicture, *pic, loc );
  if ( pic->neg_subpicture.format.empty() ) {
    //
    // Ibid: If the picture string contains only one sub-picture, the prefix
    // for the negative sub-picture is set by concatenating the minus-sign
    // character and the prefix for the positive sub-picture (if any), in that
    // order.
    //
    pic->neg_subpicture = pic->pos_subpicture;
    pic->neg_subpicture.prefix = pic->VAR( minus_sign );
    pic->neg_subpicture.prefix += pic->pos_subpicture.prefix;
  } else
    parse_subpicture( &pic->neg_subpicture, *pic, loc );
}

static void set_format( DecimalFormat_t const &df, picture *pic ) {
  //
  // See XQuery 3.9 2.1.1 and XQuery F&O 3.0 4.7.1.
  //
  FOR_EACH( DecimalFormat::properties_type, prop, df->getProperties() ) {
    if ( prop->first == "decimal-separator" )
      pic->VAR( decimal_separator_sign ) = prop->second;
    else if ( prop->first == "digit" )
      pic->VAR( optional_digit_sign ) = prop->second;
    else if ( prop->first == "grouping-separator" )
      pic->VAR( grouping_separator_sign ) = prop->second;
    else if ( prop->first == "infinity" )
      pic->VAR( infinity ) = prop->second;
    else if ( prop->first == "minus-sign" )
      pic->VAR( minus_sign ) = prop->second;
    else if ( prop->first == "NaN" )
      pic->VAR( NaN ) = prop->second;
    else if ( prop->first == "pattern-separator" )
      pic->VAR( pattern_separator_sign ) = prop->second;
    else if ( prop->first == "percent" )
      pic->VAR( percent_sign ) = prop->second;
    else if ( prop->first == "per-mille" )
      pic->VAR( per_mille_sign ) = prop->second;
    else if ( prop->first == "zero-digit" )
      pic->VAR( mandatory_digit_sign ) = prop->second;
  }
}

bool FormatNumberIterator::nextImpl( store::Item_t &result,
                                     PlanState& planState ) const {
  DecimalFormat_t df;
  store::Item_t format_name_item;
  store::Item_t item, value;
  picture pic;
  zstring result_str;
  PlanIteratorState *state;

  DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );

  if ( !consumeNext( value, theChildren[0].getp(), planState ) ) {
    //
    // XQuery F&O 3.0: 4.7.2: If the supplied value of the $value argument is
    // an empty sequence, the function behaves as if the supplied value were
    // the xs:double value NaN.
    //
    GENV_ITEMFACTORY->createDouble( result, xs_double::nan() );
  } else {
    if ( !is_allowed_type( result->getType() ) )
      throw XQUERY_EXCEPTION(
        err::XPTY0004,
        ERROR_PARAMS(
          ZED( XPTY0004_FormatNumberBadType_2 ),
          value->getType()->getStringValue()
        ),
        ERROR_LOC( loc )
      );

    consumeNext( item, theChildren[1].getp(), planState );
    item->getStringValue2( pic.format );

    if ( theChildren.size() >= 3 )
      consumeNext( format_name_item, theChildren[2].getp(), planState );

    if ( theChildren.size() < 3 || !format_name_item ) {
      df = planState.theCompilerCB->theRootSctx->get_decimal_format( NULL );
    } else {

      zstring format_name( format_name_item->getStringValue() );
      zstring prefix, local;
      if ( !xml::split_name( format_name, &prefix, &local ) ) {
        GENV_ITEMFACTORY->createQName(
          format_name_item, "", "", format_name
        );
      } else {
        zstring ns;
        if ( theSctx->lookup_ns( ns, prefix, loc, false ) ) {
          GENV_ITEMFACTORY->createQName(
            format_name_item, ns, prefix,
            format_name.substr(format_name.find(':')+1)
          );
        } else {
          //
          // The prefix is not in the known namespaces so the only posibility
          // left is for the function to be invoked from an EnclosedIterator.
          //
          if ( planState.theNodeConstuctionPath.empty() )
            throw XQUERY_EXCEPTION(
              err::FODF1280,
              ERROR_PARAMS( format_name ),
              ERROR_LOC( loc )
            );
          store::NsBindings bindings;
          planState.theNodeConstuctionPath.top()->
            getNamespaceBindings( bindings );
          FOR_EACH( store::NsBindings, binding, bindings ) {
            if ( prefix == binding->first ) {
              GENV_ITEMFACTORY->createQName(
                format_name_item, binding->second, prefix, local
              );
              break;
            }
          }
        }
      }

      if ( format_name_item.isNull() )
        throw XQUERY_EXCEPTION(
          err::FODF1280, ERROR_PARAMS( "<null>" ), ERROR_LOC( loc )
        );
      df = planState.theCompilerCB->theRootSctx->
        get_decimal_format( format_name_item );
      if ( !df )
        throw XQUERY_EXCEPTION(
          err::FODF1280, ERROR_PARAMS( format_name_item->getStringValue() ),
          ERROR_LOC( loc )
        );

    } // if ( theChildren.size() < 3 ... )

    if ( !df.isNull() )
      set_format( df, &pic );
    parse_picture( &pic, loc );

    format_number( result, pic, theSctx->get_typemanager(), loc, &result_str );

    STACK_PUSH( GENV_ITEMFACTORY->createString( result, result_str ), state );
  }

  STACK_END (state);
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
