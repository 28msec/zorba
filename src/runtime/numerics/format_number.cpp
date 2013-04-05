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

    part() {
      N = -1;
      minimum_size = maximum_size = 0;
    }
  };

  struct sub_picture {
    zstring format;
    zstring prefix;
    zstring suffix;
    bool has_percent;
    bool has_per_mille;
    part integer_part;
    part fractional_part;

    sub_picture() {
      has_percent = has_per_mille = false;
    }
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
  unicode::code_point var_cp[ NUM_VARS ];

# define VAR(NAME) var[ ::zorba::picture::NAME ]
# define VAR_CP(NAME) var_cp[ ::zorba::picture::NAME ]

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
    set_format_codepoints();
  }

  // default picture(picture const&) is fine
  // default picture& operator=(picture const&) is fine

  void set_format_codepoints() {
    for ( int i = 0; i < NUM_VARS; ++i )
      var_cp[i] = utf8::decode( var[i].c_str() );
  }

};

///////////////////////////////////////////////////////////////////////////////

#if 0
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
#endif

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

  store::Item_t double_number;
  GenericCast::castToAtomic(
    double_number, number, &*GENV_TYPESYSTEM.DOUBLE_TYPE_ONE, tm, nullptr, loc
  );

  store::Item_t zero;
  GENV_ITEMFACTORY->createDouble( zero, xs_double::zero() );

  //
  // Ibid: [T]he positive sub-picture and its associated variables are used if
  // the input number is positive, and the negative sub-picture and its
  // associated variables are used otherwise.
  //
  picture::sub_picture const &sub_pic =
    double_number->compare( zero ) > 0 ?
      pic.pos_subpicture : pic.neg_subpicture;

  if ( double_number->isPosOrNegInf() ) {
    //
    // Ibid: If the input number is positive or negative infinity, the result
    // is the concatenation of the appropriate prefix, the infinity-symbol, and
    // the appropriate suffix.
    //
    dest->append( sub_pic.prefix );
    dest->append( pic.VAR( infinity ) );
    dest->append( sub_pic.suffix );
    return;
  }

  //
  // Ibid: If the sub-picture contains a percent-sign, the number is multiplied
  // by 100. If the sub-picture contains a per-mille-sign, the number is
  // multiplied by 1000. The resulting number is referred to ... as the
  // adjusted number.
  //
  xs_double adjusted_number( double_number->getDoubleValue() );
  if ( sub_pic.has_percent )
    adjusted_number *= 100;
  else if ( sub_pic.has_per_mille )
    adjusted_number *= 1000;

  //
  // Ibid: This value is then rounded so that it uses no more than maximum-
  // fractional-part-size digits in its fractional part. The rounded number is
  // defined to be the result of converting the adjusted number to an
  // xs:decimal value, as described above, and then calling the function
  // fn:round-half-to-even with this converted number as the first argument and
  // the maximum-fractional-part-size as the second argument.
  //
  adjusted_number = adjusted_number.roundHalfToEven(
    xs_integer( sub_pic.fractional_part.maximum_size )
  );

  zstring const converted( adjusted_number.toString( true ) );

  //
  // Ibid: If the number of digits to the left of the decimal-separator-sign is
  // less than minimum-integer-part-size, leading zero-digit-sign characters
  // are added to pad out to that size.
  //
  // Ibid: If the number of digits to the right of the decimal-separator-sign
  // is less than minimum-fractional-part-size, trailing zero-digit-sign
  // characters are added to pad out to that size.
  //
  zstring integer_part, fractional_part;
  zstring::size_type const pos = converted.find( '.' );
  if ( pos == zstring::npos ) {
    integer_part = converted;
  } else {
    integer_part = converted.substr( 0, pos );
    fractional_part = converted.substr( pos + 1 );
    ascii::right_pad(
      &fractional_part, sub_pic.fractional_part.minimum_size, '0'
    );
  }
  ascii::left_pad( &integer_part, sub_pic.integer_part.minimum_size, '0' );

#if 0
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

  *dest += sub_pic.prefix;
  *dest += integer_part_result;
  if ( !fractional_part.empty() ) {
    *dest += pic.VAR( decimal_separator_sign );
    *dest += fractional_part_result;
  }
  *dest += sub_pic.suffix;
#endif
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

  // get grouping separators
  int mandatory_digit_signs = 0;
  int optional_digit_signs = 0;

  zstring::size_type pos, end, delta;
  if ( is_fractional )
    pos = 0, end = part->format.size() - 1, delta = 1;
  else
    pos = part->format.size() - 1, end = -1, delta = -1;

  int first_optional_digit_sign_pos = -1;
  int last_mandatory_digit_sign_pos = -1;

#if 0
  for ( ; pos != end; pos += delta ) {
    zstring::value_type ch = part->format[ pos ];
    if ( pic.VAR( mandatory_digit_sign ) == ch ) {
      if ( first_optional_digit_sign_pos == -1 )
        first_optional_digit_sign_pos = pos;
      ++digit_signs;
    } else if ( pic.zero_digit[0] == ch ) {
      last_mandatory_digit_sign_pos = pos;
      ++zero_signs;
    } else if ( pic.grouping_separator[0] == ch )
      part->grouping_pos.push_back( digit_signs + zero_signs );
  }

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

  picture::part picture::sub_picture::*cur_part =
    &picture::sub_picture::integer_part;

  zstring::size_type decimal_separator_pos = zstring::npos;
  zstring::size_type leftmost_active_pos = zstring::npos;
  zstring::size_type rightmost_active_pos = zstring::npos;

  unicode::code_point decimal_separator_cp = 0;
  unicode::code_point grouping_separator_cp = 0;

  bool got_active = false;
  bool got_mandatory_digit = false;
  bool got_optional_digit = false;
  bool got_passive = false;

  int part_mandatory_digits = 0;
  int part_optional_digits = 0;

  unicode::code_point cp;
  unicode::code_point zero[2];
  unicode::is_Nd( pic.VAR_CP( mandatory_digit_sign ), &zero[0] );

  utf8_string<zstring> u_sub_pic_format( sub_pic->format );
  utf8_string<zstring>::const_iterator u( u_sub_pic_format.begin() );
  utf8_string<zstring>::const_iterator const u_end( u_sub_pic_format.end() );

  for ( ; u != u_end; ++u ) {
    cp = *u;

    if ( cp == pic.VAR_CP( decimal_separator_sign ) ) {
      if ( decimal_separator_pos != zstring::npos ) {
        //
        // XQuery F&O 3.0 4.7.3: A sub-picture must not contain more than one
        // decimal-separator-sign.
        //
        goto got_multiple_signs;
      }
      decimal_separator_cp = cp;
      if ( grouping_separator_cp ) {
        //
        // Ibid: A sub-picture must not contain a grouping-separator-sign
        // adjacent to a decimal-separator-sign.
        //
        goto got_decimal_grouping_adjacent;
      }
      cur_part = &picture::sub_picture::fractional_part;
      decimal_separator_pos = u.base() - sub_pic->format.begin();
      part_mandatory_digits = part_optional_digits = 0;
      grouping_separator_cp = 0;
      goto set_active;
    }

    if ( cp == pic.VAR_CP( grouping_separator_sign ) ) {
      grouping_separator_cp = cp;
      if ( decimal_separator_cp ) {
        //
        // Ibid: A sub-picture must not contain a grouping-separator-sign
        // adjacent to a decimal-separator-sign.
        //
        goto got_decimal_grouping_adjacent;
      }
      decimal_separator_cp = 0;
      if ( decimal_separator_pos != zstring::npos ) {
        //
        // XQuery F&O 3.0 4.7.4: The fractional-part-grouping-positions is a
        // sequence of integers representing the positions of grouping
        // separators within the fractional part of the sub-picture. For each
        // grouping-separator-sign that appears within the fractional part of
        // the sub-picture, this sequence contains an integer that is equal to
        // the total number of optional-digit-sign and decimal-digit-family
        // characters that appear within the fractional part of the sub-picture
        // and to the left of the grouping-separator-sign.
        //
        int const total_digits = part_mandatory_digits + part_optional_digits;
        sub_pic->fractional_part.grouping_pos.push_back( total_digits );
#if 0
        // The spec doesn't say anything about the fractional part grouping
        // positions forming a sequence of N, 2N, 3N, ....
        if ( sub_pic->fractional_part.grouping_pos.size() == 1 )
          sub_pic->fractional_part.N = total_digits;
        else if ( total_digits % sub_pic->fractional_part.N )
          sub_pic->fractional_part.N = -1;
#endif
      }
      goto set_active;
    }

    decimal_separator_cp = grouping_separator_cp = 0;

    if ( cp == pic.VAR_CP( optional_digit_sign ) ) {
      if ( decimal_separator_pos != zstring::npos ) {
        //
        // XQuery F&O 3.0 4.7.4: The maximum-fractional-part-size is set to the
        // total number of optional-digit-sign and decimal-digit-family
        // characters found in the fractional part of the sub-picture.
        //
        ++sub_pic->fractional_part.maximum_size;
      } else if ( part_mandatory_digits ) {
        //
        // XQuery F&O 3.0 4.7.3: The integer part of a sub-picture must not
        // contain a member of the decimal-digit-family that is followed by an
        // optional-digit-sign.
        //
        throw XQUERY_EXCEPTION(
          err::FODF1310,
          ERROR_PARAMS(
            pic.format,
            ZED( FODF1310_NoOptDigitAfterMandatory_3 ),
            unicode::printable_cp( cp )
          ),
          ERROR_LOC( loc )
        );
      }
      got_optional_digit = true;
      ++part_optional_digits;
      goto set_active;
    }

    if ( cp == pic.VAR_CP( percent_sign ) ) {
      //
      // XQuery F&O 3.0 4.7.3: A sub-picture must not contain more than one
      // percent-sign or per-mille-sign, and it must not contain one of each.
      //
      if ( sub_pic->has_percent )
        goto got_multiple_signs;
      if ( sub_pic->has_per_mille )
        goto got_percent_per_mille;
      sub_pic->has_percent = true;
      continue;
    }

    if ( cp == pic.VAR_CP( per_mille_sign ) ) {
      //
      // Ibid: A sub-picture must not contain more than one percent-sign or
      // per-mille-sign, and it must not contain one of each.
      //
      if ( sub_pic->has_per_mille )
        goto got_multiple_signs;
      if ( sub_pic->has_percent )
        goto got_percent_per_mille;
      sub_pic->has_per_mille = true;
      continue;
    }

    if ( unicode::is_Nd( cp, &zero[1] ) ) {
      if ( zero[1] != zero[0] ) {
        throw XQUERY_EXCEPTION(
          err::FODF1310,
          ERROR_PARAMS(
            pic.format,
            ZED( FODF1310_DigitNotSameFamily_34 ),
            unicode::printable_cp( cp ),
            unicode::printable_cp( zero[0] )
          ),
          ERROR_LOC( loc )
        );
      }
      if ( decimal_separator_pos != zstring::npos ) {
        if ( part_optional_digits ) {
          //
          // Ibid: The fractional part of a sub-picture must not contain an
          // optional-digit-sign that is followed by a member of the decimal-
          // digit-family.
          //
          throw XQUERY_EXCEPTION(
            err::FODF1310,
            ERROR_PARAMS(
              pic.format,
              ZED( FODF1310_NoMandatoryDigitAfterOpt_3 ),
              unicode::printable_cp( cp )
            ),
            ERROR_LOC( loc )
          );
        }
        //
        // XQuery F&O 3.0 4.7.4: The maximum-fractional-part-size is set to the
        // total number of optional-digit-sign and decimal-digit-family
        // characters found in the fractional part of the sub-picture.
        //
        ++sub_pic->fractional_part.maximum_size;
      }
      got_mandatory_digit = true;
      ++part_mandatory_digits;

      //
      // XQuery F&O 3.0 4.7.4: The minimum-integer-part-size is an integer
      // indicating the minimum number of digits that will appear to the left
      // of the decimal-separator-sign. It is normally set to the number of
      // decimal-digit-family characters found in the integer part of the
      // sub-picture.
      //
      // Ibid: The minimum-fractional-part-size is set to the number of
      // decimal-digit-family characters found in the fractional part of the
      // sub-picture.
      //
      ++(sub_pic->*cur_part).minimum_size;

      goto set_active;
    }

    continue;

set_active:
    if ( got_active && got_passive ) {
      //
      // XQuery F&O 3.0 4.7.3: A sub-picture must not contain a passive
      // character that is preceded by an active character and that is followed
      // by another active character.
      //
      throw XQUERY_EXCEPTION(
        err::FODF1310,
        ERROR_PARAMS(
          pic.format,
          ZED( FODF1310_NoActivePassiveActive ),
          unicode::printable_cp( cp )
        ),
        ERROR_LOC( loc )
      );
    }
    got_active = true;

    zstring::size_type const cur_pos = u.base() - sub_pic->format.begin();
    if ( leftmost_active_pos == zstring::npos )
      leftmost_active_pos = cur_pos;
    if ( decimal_separator_pos != zstring::npos )
      rightmost_active_pos = cur_pos;
  } // for

  if ( !(got_optional_digit || got_mandatory_digit) ) {
    throw XQUERY_EXCEPTION(
      //
      // XQuery F&O 3.0 4.7.3: A sub-picture must contain at least one
      // character that is an optional-digit-sign or a member of the
      // decimal-digit-family.
      //
      err::FODF1310,
      ERROR_PARAMS( ZED( FODF1310_MustHaveOptOrMandatoryDigit ) ),
      ERROR_LOC( loc )
    );
  }

  //
  // XQuery F&O 3.0 4.7.4: [I]f the sub-picture contains no decimal-digit-
  // family character and no decimal-separator-sign, [the minimum-integer-part-
  // size] is set to one.
  //
  if ( !got_mandatory_digit && decimal_separator_pos == zstring::npos )
    sub_pic->integer_part.minimum_size = 1;

  if ( decimal_separator_pos != zstring::npos ) {
    sub_pic->integer_part.format =
      sub_pic->format.substr( 0, decimal_separator_pos );
    sub_pic->fractional_part.format = sub_pic->format.substr(
      decimal_separator_pos + pic.VAR( decimal_separator_sign ).size()
    );
  } else
    sub_pic->integer_part.format = sub_pic->format;

  parse_part( &sub_pic->integer_part, pic, loc );
  parse_part( &sub_pic->fractional_part, pic, loc, true );

  if ( leftmost_active_pos != zstring::npos ) {
    //
    // Ibid: The prefix is set to contain all passive characters in the
    // sub-picture to the left of the leftmost active character.
    //
    sub_pic->prefix = sub_pic->format.substr( 0, leftmost_active_pos );
  }
  if ( rightmost_active_pos != zstring::npos ) {
    //
    // Ibid: The suffix is set to contain all passive characters to the right
    // of the rightmost active character in the fractional part of the
    // sub-picture.
    //
    sub_pic->suffix = sub_pic->format.substr( rightmost_active_pos );
  }

  return;

got_decimal_grouping_adjacent:
  throw XQUERY_EXCEPTION(
    err::FODF1310,
    ERROR_PARAMS(
      pic.format,
      ZED( FODF1310_NoDecimalGroupingAdjacent_34 ),
      unicode::printable_cp( decimal_separator_cp ),
      unicode::printable_cp( grouping_separator_cp )
    ),
    ERROR_LOC( loc )
  );

got_multiple_signs:
  throw XQUERY_EXCEPTION(
    err::FODF1310,
    ERROR_PARAMS(
      pic.format,
      ZED( FODF1310_MultipleSign_3 ),
      unicode::printable_cp( cp )
    ),
    ERROR_LOC( loc )
  );

got_percent_per_mille:
  throw XQUERY_EXCEPTION(
    err::FODF1310,
    ERROR_PARAMS( pic.format, ZED( FODF1310_NoPercentPermille ) ),
    ERROR_LOC( loc )
  );
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
    pic->neg_subpicture = pic->pos_subpicture;
    //
    // Ibid: If the picture string contains only one sub-picture, the prefix
    // for the negative sub-picture is set by concatenating the minus-sign
    // character and the prefix for the positive sub-picture (if any), in that
    // order.
    //
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
  pic->set_format_codepoints();
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
