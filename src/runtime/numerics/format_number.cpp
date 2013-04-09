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

namespace {

struct picture {

  struct part {
    zstring format;
    int mandatory_grouping_seps;
    int minimum_size;
    union {
      int maximum_size;                 // only in fractional part
      int grouping_interval;            // only in integer part
    };

    part() {
      mandatory_grouping_seps = minimum_size = maximum_size = 0;
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

  // See XQuery F&O 3.0 4.7.1.
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

  picture() {
    var[ decimal_separator_sign ] = ".";
    var[ grouping_separator_sign ] = ",";
    var[ infinity ] = "Infinity";
    var[ mandatory_digit_sign ] = "0";
    var[ minus_sign ] = "-";
    var[ NaN ] = "NaN";
    var[ optional_digit_sign ] = "#";
    var[ pattern_separator_sign ] = ";";
    var[ percent_sign ] = "%";
    var[ per_mille_sign ] = "\xE2\x80\xB0";
    set_format_codepoints();
  }

  // default picture(picture const&) is fine
  // default picture& operator=(picture const&) is fine

#if 0
  bool is_active( unicode::code_point cp ) {
    //
    // XQuery F&O 3.0 4.7.3: The ... variables decimal-separator-sign,
    // grouping-sign, decimal-digit-family, optional-digit-sign and pattern-
    // separator-sign are classified as active characters, and all other
    // characters (including the percent-sign and per-mille-sign) are
    // classified as passive characters.
    //
    unicode::code_point zero_cp;
    return cp == var_cp[ decimal_separator_sign ]
        || cp == var_cp[ grouping_separator_sign ]
        || cp == var_cp[ optional_digit_sign ]
        || (unicode::is_Nd( cp, &zero_cp ) &&
            zero_cp == var_cp[ mandatory_digit_sign ] )
        || cp == var_cp[ pattern_separator_sign ];
  }
#endif

  void set_format_codepoints() {
    for ( int i = 0; i < NUM_VARS; ++i )
      var_cp[i] = utf8::decode( var[i].c_str() );
  }
};

} // namespace

#define VAR(NAME) var[ ::zorba::picture::NAME ]
#define VAR_CP(NAME) var_cp[ ::zorba::picture::NAME ]

///////////////////////////////////////////////////////////////////////////////

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

static void format_integer_part( zstring const &value,
                                 picture::sub_picture const &sub_pic,
                                 picture const &pic, zstring *dest ) {
  zstring::const_reverse_iterator n_i( value.rbegin() );
  zstring::const_reverse_iterator const n_end( value.rend() );

  picture::part const &part = sub_pic.integer_part;

  utf8_string<zstring const> const u_format( part.format );
  utf8_string<zstring const>::const_reverse_iterator
    format_i( u_format.rbegin() );
  utf8_string<zstring const>::const_reverse_iterator const
    format_end( u_format.rend() );

  int digit_pos = 0;
  bool just_inserted_grouping_separator = false;
  int minimum_size = part.minimum_size;
  int mandatory_grouping_seps = part.mandatory_grouping_seps;
  utf8_string<zstring> u_dest( *dest );

  //
  // Step through both the integer part and sub-picture from right-to-left.
  //
  while ( n_i != n_end || format_i != format_end ) {
    unicode::code_point digit_cp = pic.VAR_CP( mandatory_digit_sign );
    if ( n_i != n_end )
      digit_cp += *n_i - '0';
    if ( format_i != format_end ) {     // haven't exhausted the picture
      if ( !minimum_size && !mandatory_grouping_seps && n_i == n_end )
        break;
      unicode::code_point const format_cp = *format_i++;
      if ( format_cp == pic.VAR_CP( optional_digit_sign ) ||
           unicode::is_Nd( format_cp ) ) {
        u_dest.insert( 0, 1, digit_cp );
        if ( n_i != n_end ) ++n_i;
        ++digit_pos;
        if ( format_cp != pic.VAR_CP( optional_digit_sign ) )
          --minimum_size;
      } else {                          // must be a grouping-separator
        u_dest.insert( 0, 1, pic.VAR_CP( grouping_separator_sign ) );
        --mandatory_grouping_seps;
      }
    } else {                            // have exhausted the picture
      if ( part.grouping_interval && !(digit_pos % part.grouping_interval) ) {
        if ( just_inserted_grouping_separator )
          just_inserted_grouping_separator = false;
        else {
          u_dest.insert( 0, 1, pic.VAR_CP( grouping_separator_sign ) );
          just_inserted_grouping_separator = true;
          continue;
        }
      }
      u_dest.insert( 0, 1, digit_cp );
      if ( n_i != n_end ) ++n_i;
      ++digit_pos;
    }
  } // while
}

static void format_fractional_part( zstring const &value,
                                    picture::sub_picture const &sub_pic,
                                    picture const &pic, zstring *dest ) {
  zstring::const_iterator n_i( value.begin() );
  zstring::const_iterator const n_end( value.end() );

  picture::part const &part = sub_pic.fractional_part;

  utf8_string<zstring const> const u_format( part.format );
  utf8_string<zstring const>::const_iterator format_i( u_format.begin() );
  utf8_string<zstring const>::const_iterator const format_end( u_format.end() );

  int digit_pos = 0;
  bool just_appended_grouping_separator = false;
  int minumum_size = part.minimum_size;
  int mandatory_grouping_seps = part.mandatory_grouping_seps;
  utf8_string<zstring> u_dest( *dest );

  //
  // Step through both the fractional part and sub-picture from left-to-right.
  //
  while ( n_i != n_end || format_i != format_end ) {
    unicode::code_point digit_cp = pic.VAR_CP( mandatory_digit_sign );
    if ( n_i != n_end )
      digit_cp += *n_i - '0';
    if ( format_i != format_end ) {     // haven't exhausted the picture
      if ( !minumum_size && !mandatory_grouping_seps && n_i == n_end )
        break;
      unicode::code_point const format_cp = *format_i++;
      if ( format_cp == pic.VAR_CP( optional_digit_sign ) ||
           unicode::is_Nd( format_cp ) ) {
        u_dest += digit_cp;
        if ( n_i != n_end ) ++n_i;
        ++digit_pos;
        if ( format_cp != pic.VAR_CP( optional_digit_sign ) )
          --minumum_size;
      } else {                          // must be a grouping-separator
        u_dest += pic.VAR_CP( grouping_separator_sign );
        --mandatory_grouping_seps;
      }
    } else {                            // have exhausted the picture
      if ( part.grouping_interval && !(digit_pos % part.grouping_interval) ) {
        if ( just_appended_grouping_separator )
          just_appended_grouping_separator = false;
        else {
          u_dest += pic.VAR_CP( grouping_separator_sign );
          just_appended_grouping_separator = true;
          continue;
        }
      }
      u_dest += digit_cp;
      if ( n_i != n_end ) ++n_i;
      ++digit_pos;
    }
  } // while
}

static void format_number( store::Item_t &number_item, picture const &pic,
                           TypeManager const *tm, QueryLoc const &loc,
                           zstring *dest ) {
  if ( number_item->isNaN() ) {
    //
    // XQuery F&O 3.0 4.7.5: If the input number is NaN (not a number), the
    // result is the specified NaN-symbol (with no prefix or suffix).
    //
    *dest = pic.VAR( NaN );
    return;
  }

  store::Item_t double_item;
  GenericCast::castToAtomic(
    double_item, number_item, &*GENV_TYPESYSTEM.DOUBLE_TYPE_ONE, tm, nullptr,
    loc
  );

  store::Item_t zero;
  GENV_ITEMFACTORY->createDouble( zero, xs_double::zero() );

  //
  // Ibid: [T]he positive sub-picture and its associated variables are used if
  // the input number is positive, and the negative sub-picture and its
  // associated variables are used otherwise.
  //
  bool const is_negative = double_item->compare( zero ) < 0;
  picture::sub_picture const &sub_pic =
    is_negative ? pic.neg_subpicture : pic.pos_subpicture;

  if ( double_item->isPosOrNegInf() ) {
    //
    // Ibid: If the input number is positive or negative infinity, the result
    // is the concatenation of the appropriate prefix, the infinity-symbol, and
    // the appropriate suffix.
    //
    *dest  = sub_pic.prefix;
    *dest += pic.VAR( infinity );
    *dest += sub_pic.suffix;
    return;
  }

  //
  // Ibid: If the sub-picture contains a percent-sign, the number is multiplied
  // by 100. If the sub-picture contains a per-mille-sign, the number is
  // multiplied by 1000. The resulting number is referred to ... as the
  // adjusted number.
  //
  xs_double adjusted_number( double_item->getDoubleValue().abs() );
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
  zstring::size_type const decimal_separator_pos = converted.find( '.' );
  integer_part = converted.substr( 0, decimal_separator_pos );
  ascii::left_pad( &integer_part, sub_pic.integer_part.minimum_size, '0' );
  if ( decimal_separator_pos != zstring::npos ) {
    fractional_part = converted.substr( decimal_separator_pos + 1 );
    ascii::right_pad(
      &fractional_part, sub_pic.fractional_part.minimum_size, '0'
    );
  }

  format_integer_part( integer_part, sub_pic, pic, dest );
  // Insert prefix afterwards so as not to complicate format_integer_part().
  dest->insert( 0, sub_pic.prefix );

  if ( decimal_separator_pos != zstring::npos && !fractional_part.empty() ) {
    *dest += pic.VAR( decimal_separator_sign );
    format_fractional_part( fractional_part, sub_pic, pic, dest );
  }
  *dest += sub_pic.suffix;
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

static void parse_subpicture( picture::sub_picture *sub_pic,
                              picture const &pic, QueryLoc const &loc ) {
  if ( sub_pic->format.empty() )
    return;

  picture::part picture::sub_picture::*cur_part =
    &picture::sub_picture::integer_part;

  zstring::size_type decimal_separator_pos = zstring::npos;
  zstring::size_type leftmost_active_pos = zstring::npos;
  zstring::size_type rightmost_active_pos = zstring::npos;

  bool got_active = false;
  bool got_grouping_separator = false;    // used only for integer part
  bool got_mandatory_digit = false;
  bool got_optional_digit = false;
  bool got_part_mandatory_digit = false;
  bool got_part_optional_digit = false;
  bool got_passive = false;
  bool grouping_interval_possible = true; // used only for integer part
  bool just_got_decimal_separator = false;
  bool just_got_grouping_separator = false;

  int grouping_interval = 0;              // used only for integer part
  int grouping_separators = 0;

  utf8::size_type pos = 0, prev_grouping_pos = utf8::npos;

  unicode::code_point cp, zero_cp;

  utf8_string<zstring> u_sub_pic_format( sub_pic->format );
  utf8_string<zstring>::const_iterator u( u_sub_pic_format.begin() );
  utf8_string<zstring>::const_iterator const u_end( u_sub_pic_format.end() );

  for ( ; u != u_end; ++u, ++pos ) {
    cp = *u;

    if ( cp == pic.VAR_CP( decimal_separator_sign ) ) {
      if ( decimal_separator_pos != zstring::npos ) {
        //
        // XQuery F&O 3.0 4.7.3: A sub-picture must not contain more than one
        // decimal-separator-sign.
        //
        goto got_multiple_signs;
      }
      if ( just_got_grouping_separator ) {
        //
        // Ibid: A sub-picture must not contain a grouping-separator-sign
        // adjacent to a decimal-separator-sign.
        //
        goto got_decimal_grouping_adjacent;
      }
      cur_part = &picture::sub_picture::fractional_part;
      decimal_separator_pos = u.base() - sub_pic->format.begin();
      got_part_mandatory_digit = got_part_optional_digit = false;
      just_got_decimal_separator = true;
      just_got_grouping_separator = false;
      goto set_active;
    }

    if ( cp == pic.VAR_CP( grouping_separator_sign ) ) {
      if ( just_got_decimal_separator ) {
        //
        // Ibid: A sub-picture must not contain a grouping-separator-sign
        // adjacent to a decimal-separator-sign.
        //
        goto got_decimal_grouping_adjacent;
      }
      just_got_decimal_separator = false;
      just_got_grouping_separator = true;
      ++(sub_pic->*cur_part).mandatory_grouping_seps;

      if ( decimal_separator_pos == zstring::npos &&
           grouping_interval_possible ) {
        //
        // [I]f these integer-part-grouping-positions are at regular intervals
        // (that is, if they form a sequence N, 2N, 3N, ... for some integer
        // value N, including the case where there is only one number in the
        // list), then the sequence contains all integer multiples of N as far
        // as necessary to accommodate the largest possible number.
        //
        if ( !got_grouping_separator )
          got_grouping_separator = true;
        else if ( !grouping_interval )
          grouping_interval = pos = prev_grouping_pos;
        else if ( pos - prev_grouping_pos != grouping_interval )
          grouping_interval_possible = false;
        prev_grouping_pos = pos + 1;
      }

      goto set_active;
    }

    just_got_decimal_separator = just_got_grouping_separator = false;

    if ( cp == pic.VAR_CP( optional_digit_sign ) ) {
      if ( decimal_separator_pos != zstring::npos ) {
        //
        // Ibid 4.7.4: The maximum-fractional-part-size is set to the total
        // number of optional-digit-sign and decimal-digit-family characters
        // found in the fractional part of the sub-picture.
        //
        ++sub_pic->fractional_part.maximum_size;
      } else if ( got_part_mandatory_digit ) {
        //
        // Ibid 4.7.3: The integer part of a sub-picture must not contain a
        // member of the decimal-digit-family that is followed by an optional-
        // digit-sign.
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
      got_optional_digit = got_part_optional_digit = true;
      goto set_active;
    }

    if ( cp == pic.VAR_CP( percent_sign ) ) {
      //
      // Ibid 4.7.3: A sub-picture must not contain more than one percent-sign
      // or per-mille-sign, and it must not contain one of each.
      //
      if ( sub_pic->has_percent )
        goto got_multiple_signs;
      if ( sub_pic->has_per_mille )
        goto got_percent_per_mille;
      sub_pic->has_percent = true;
    }

    else if ( cp == pic.VAR_CP( per_mille_sign ) ) {
      //
      // Ibid: A sub-picture must not contain more than one percent-sign or
      // per-mille-sign, and it must not contain one of each.
      //
      if ( sub_pic->has_per_mille )
        goto got_multiple_signs;
      if ( sub_pic->has_percent )
        goto got_percent_per_mille;
      sub_pic->has_per_mille = true;
    }

    else if ( unicode::is_Nd( cp, &zero_cp ) &&
              zero_cp == pic.VAR_CP( mandatory_digit_sign ) ) {
      if ( decimal_separator_pos != zstring::npos ) {
        if ( got_part_optional_digit ) {
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
        // Ibid 4.7.4: The maximum-fractional-part-size is set to the total
        // number of optional-digit-sign and decimal-digit-family characters
        // found in the fractional part of the sub-picture.
        //
        ++sub_pic->fractional_part.maximum_size;
      }
      got_mandatory_digit = got_part_mandatory_digit = true;

      //
      // Ibid 4.7.4: The minimum-integer-part-size is an integer indicating the
      // minimum number of digits that will appear to the left of the decimal-
      // separator-sign. It is normally set to the number of decimal-digit-
      // family characters found in the integer part of the sub-picture.
      //
      // Ibid: The minimum-fractional-part-size is set to the number of
      // decimal-digit-family characters found in the fractional part of the
      // sub-picture.
      //
      ++(sub_pic->*cur_part).minimum_size;

      goto set_active;
    }

    got_passive = true;
    continue;

set_active:
    //
    // XQuery F&O 3.0 4.7.3: The ... variables decimal-separator-sign,
    // grouping-sign, decimal-digit-family, optional-digit-sign and pattern-
    // separator-sign are classified as active characters, and all other
    // characters (including the percent-sign and per-mille-sign) are
    // classified as passive characters.
    //
    if ( got_active && got_passive ) {
      //
      // Ibid 4.7.3: A sub-picture must not contain a passive character that is
      // preceded by an active character and that is followed by another active
      // character.
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
    //if ( decimal_separator_pos != zstring::npos )
      rightmost_active_pos = cur_pos;
  } // for

  if ( !(got_optional_digit || got_mandatory_digit) ) {
    throw XQUERY_EXCEPTION(
      //
      // Ibid: A sub-picture must contain at least one character that is an
      // optional-digit-sign or a member of the decimal-digit-family.
      //
      err::FODF1310,
      ERROR_PARAMS( ZED( FODF1310_MustHaveOptOrMandatoryDigit ) ),
      ERROR_LOC( loc )
    );
  }

  if ( grouping_interval_possible ) {
    if ( decimal_separator_pos != zstring::npos )
      pos = decimal_separator_pos;
    if ( !grouping_interval ) {
      if ( got_grouping_separator ) {
        //
        // There's only a single grouping separator, e.g., "1,000".
        //
        grouping_interval = pos - prev_grouping_pos;
      }
    } else if ( pos - prev_grouping_pos != grouping_interval ) {
      //
      // There are multiple grouping separators, but they're not equally spaced
      // from the last digit, e.g., "1,000,00".  (This is most likely a mistake
      // on the part of the user.)
      //
      grouping_interval = 0;
    }
    sub_pic->integer_part.grouping_interval = grouping_interval;
  }

  //
  // Ibid 4.7.4: [I]f the sub-picture contains no decimal-digit-family
  // character and no decimal-separator-sign, [the minimum-integer-part-size]
  // is set to one.
  //
  if ( !got_mandatory_digit && decimal_separator_pos == zstring::npos )
    sub_pic->integer_part.minimum_size = 1;

  if ( leftmost_active_pos != zstring::npos ) {
    //
    // Ibid: The prefix is set to contain all passive characters in the
    // sub-picture to the left of the leftmost active character.
    //
    sub_pic->prefix = sub_pic->format.substr( 0, leftmost_active_pos );
    sub_pic->format.erase( 0, leftmost_active_pos );
    if ( decimal_separator_pos != zstring::npos )
      decimal_separator_pos -= leftmost_active_pos;
  }
  if ( rightmost_active_pos != zstring::npos &&
       rightmost_active_pos + 1 < sub_pic->format.size() ) {
    //
    // Ibid: The suffix is set to contain all passive characters to the right
    // of the rightmost active character in the fractional part of the
    // sub-picture.
    //
    sub_pic->suffix = sub_pic->format.substr( rightmost_active_pos + 1 );
    sub_pic->format.erase( rightmost_active_pos + 1 );
  }

  sub_pic->integer_part.format =
    sub_pic->format.substr( 0, decimal_separator_pos );
  if ( decimal_separator_pos != zstring::npos )
    sub_pic->fractional_part.format = sub_pic->format.substr(
      decimal_separator_pos + pic.VAR( decimal_separator_sign ).size()
    );

  return;

got_decimal_grouping_adjacent:
  throw XQUERY_EXCEPTION(
    err::FODF1310,
    ERROR_PARAMS(
      pic.format,
      ZED( FODF1310_NoDecimalGroupingAdjacent_34 ),
      unicode::printable_cp( pic.VAR_CP( decimal_separator_sign )  ),
      unicode::printable_cp( pic.VAR_CP( grouping_separator_sign ) )
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

  pic->pos_subpicture.format = pic->format.substr( 0, pos );
  if ( pos != zstring::npos ) {
    pic->neg_subpicture.format =
      pic->format.substr( pos + pic->VAR( pattern_separator_sign ).size() );
  }

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

  DEFAULT_STACK_INIT( PlanIteratorState, state, planState );

  if ( !consumeNext( value, theChildren[0].getp(), planState ) ) {
    //
    // XQuery F&O 3.0 4.7.2: If the supplied value of the $value argument is an
    // empty sequence, the function behaves as if the supplied value were the
    // xs:double value NaN.
    //
    GENV_ITEMFACTORY->createDouble( value, xs_double::nan() );
  } else if ( !is_allowed_type( value->getType() ) ) {
    //
    // Ibid: The $value argument may be of any numeric data type (xs:double,
    // xs:float, xs:decimal, or their subtypes including xs:integer).
    //
    throw XQUERY_EXCEPTION(
      err::XPTY0004,
      ERROR_PARAMS(
        ZED( XPTY0004_FormatNumberBadType_2 ),
        value->getType()->getStringValue()
      ),
      ERROR_LOC( loc )
    );
  }

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
      GENV_ITEMFACTORY->createQName( format_name_item, "", "", format_name );
    } else {
      zstring ns;
      if ( theSctx->lookup_ns( ns, prefix, loc, false ) ) {
        GENV_ITEMFACTORY->createQName( format_name_item, ns, prefix, local );
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
  format_number( value, pic, theSctx->get_typemanager(), loc, &result_str );
  STACK_PUSH( GENV_ITEMFACTORY->createString( result, result_str ), state );
  STACK_END (state);
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
