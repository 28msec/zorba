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

// standard
#include <sstream>
#include <vector>

// Zorba
#include "common/shared_types.h"
#include "context/dynamic_context.h"
#include "context/static_context.h"
#include "diagnostics/xquery_diagnostics.h"
#include "runtime/core/arithmetic_impl.h"
#include "runtime/numerics/numerics.h"
#include "runtime/visitors/planiter_visitor.h"
#include "store/api/item.h"
#include "store/api/item_factory.h"
#include "system/globalenv.h"
#include "util/ascii_util.h"
#include "util/stream_util.h"
#include "util/unicode_util.h"
#include "util/utf8_string.h"
#include "zorbatypes/numconversions.h"

using namespace std;
using namespace zorba::locale;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

namespace {

struct picture {
  enum primary_type {
    arabic,       // '1' : 0 1 2 ... 10 11 12 ...
    alpha,        // 'a' : a b c ... z aa ab ac ...
    ALPHA,        // 'A' : A B C ... Z AA AB AC ...
    one,          // limited-range integer sequence
    roman,        // 'i' : i ii iii iv v vi vii viii ix x ...
    ROMAN,        // 'I' : I II III IV V VI VII VIII IX X ...
    words,        // 'w' : one two three four ...
    Words,        // 'Ww': One Two Three Four ...
    WORDS         // 'W' : ONE TWO THREE FOUR ...
  };

  enum co_type {
    no_co,
    cardinal,     // 'c': 7 or seven
    ordinal       // 'o': 7th or seventh
  };

  enum at_type {
    no_at,
    alphabetic,   // 'a'
    traditional,  // 't'
  };

  struct {
    primary_type type;
    zstring format;
    int grouping_interval;
    int mandatory_digits;
    int mandatory_grouping_seps;
    unicode::code_point zero, one;
  } primary;

  struct {
    co_type co;
    zstring co_string;
    at_type at;
  } modifier;

  //
  // This stuff isn't part of the "presentation modifier" as discussed in the
  // XQuery 3.0 F&O spec, but this is a convenient place to put it nonetheless.
  //
  iso639_1::type lang;
  bool lang_is_fallback;
  iso3166_1::type country;

  picture() {
    primary.type = arabic;
    primary.grouping_interval = 0;
    primary.mandatory_digits = 0;
    primary.mandatory_grouping_seps = 0;
    primary.zero = '0';
    modifier.co = cardinal;
    modifier.at = no_at;
  }

  // default picture(picture const&) is fine
  // default picture& operator=(picture const&) is fine
};

} // namespace

///////////////////////////////////////////////////////////////////////////////

/**
 * For a code-point of a format token that represents the number 1, gets the
 * range of values said token can be used to format.
 *
 * @param cp The code-point of a format token that represents the number 1.
 * @param min A pointer to an \c int to receive the minimum value of the range.
 * @param max A pointer to an \c int to receive the maximum value of the range.
 */
static bool get_one_range( unicode::code_point cp, int *min, int *max ) {
  using namespace unicode;
  switch ( cp ) {
    case CIRCLED_DIGIT_ONE:
    case DIGIT_ONE_FULL_STOP:
    case DINGBAT_NEGATIVE_CIRCLED_DIGIT_ONE:
    case PARENTHESIZED_DIGIT_ONE:
      *min = 1, *max = 20;
      break;
    case CIRCLED_IDEOGRAPH_ONE:
    case DINGBAT_CIRCLED_SANS_SERIF_DIGIT_ONE:
    case DINGBAT_NEGATIVE_CIRCLED_SANS_SERIF_DIGIT_ONE:
    case DOUBLE_CIRCLED_DIGIT_ONE:
    case PARENTHESIZED_IDEOGRAPH_ONE:
      *min = 1, *max = 10;
      break;
    case ROMAN_NUMERAL_ONE:
    case SMALL_ROMAN_NUMERAL_ONE:
      *min = 1, *max = 12;
      break;
    case SUBSCRIPT_ONE:
    case SUPERSCRIPT_ONE:
      *min = 0, *max = 9;
      break;
    default:
      return false;
  }
  return true;
}

static char const* ordinal( xs_integer const &i ) {
  xs_integer a( i );
  if ( a.sign() < 0 )
    a = -a;
  static xs_integer const ten( 10 );
  xs_integer const a_mod_10( a % ten );
  switch ( to_xs_int( a_mod_10 ) ) {
    case 11:
    case 12:
    case 13:
      break;
    default: {
      static xs_integer const hundred( 100 );
      xs_integer const a_mod_100( a % hundred );
      switch ( to_xs_int( a_mod_100 ) ) {
        case 1: return "st";
        case 2: return "nd";
        case 3: return "rd";
      }
    }
  }
  return "th";
}

static void format_integer( xs_integer const &xs_n, picture const &pic,
                            zstring *dest ) {
  picture default_pic;

  switch ( pic.primary.type ) {
    case picture::one:
      //
      // XQuery F&O 3.0: 4.6.1: For all format tokens other than [ones that
      // consists of decimal digits], there may be implementation-defined lower
      // and upper bounds on the range of numbers that can be formatted using
      // this format token; indeed, for some numbering sequences there may be
      // intrinsic limits. For example, the format token &#x2460; (circled
      // digit one) has a range of 1 to 20 imposed by the Unicode character
      // repertoire.
      //
      try {
        xs_long const n = to_xs_long( xs_n );
        int min, max;
        if ( get_one_range( pic.primary.one, &min, &max ) &&
            n >= min && n <= max ) {
          utf8_string<zstring> u_dest( *dest );
          u_dest = (unicode::code_point)(pic.primary.one + n - 1);
          break;
        }
        //
        // Ibid: Numbers that fall outside this range must be formatted using
        // the format token 1.
        //
        format_integer( xs_n, default_pic, dest );
      }
      catch ( range_error const& ) {
        format_integer( xs_n, default_pic, dest );
      }
      break;

    case picture::arabic: {
      xs_integer xs_n2( xs_n );
      if ( xs_n2.sign() < 0 )
        xs_n2 = -xs_n2;

      zstring const s( xs_n2.toString() );
      zstring::const_reverse_iterator n_i( s.rbegin() );
      zstring::const_reverse_iterator const n_end( s.rend() );

      utf8_string<zstring const> const u_pic_format( pic.primary.format );
      utf8_string<zstring const>::const_reverse_iterator
        pic_i( u_pic_format.rbegin() );
      utf8_string<zstring const>::const_reverse_iterator const
        pic_end( u_pic_format.rend() );

      int digit_pos = 0;
      unicode::code_point grouping_cp;
      bool just_inserted_grouping_separator = false;
      int mandatory_digits = pic.primary.mandatory_digits;
      int mandatory_grouping_seps = pic.primary.mandatory_grouping_seps;
      utf8_string<zstring> u_dest( *dest );

      //
      // Step through both the integer and picture from right-to-left.
      //
      while ( n_i != n_end || pic_i != pic_end ) {
        unicode::code_point digit_cp = pic.primary.zero;
        if ( n_i != n_end )
          digit_cp += *n_i - '0';
        if ( pic_i != pic_end ) {       // haven't exhausted the picture
          if ( !mandatory_digits && !mandatory_grouping_seps && n_i == n_end )
            break;
          unicode::code_point const pic_cp = *pic_i++;
          if ( pic_cp == '#' || unicode::is_Nd( pic_cp ) ) {
            u_dest.insert( 0, 1, digit_cp );
            if ( n_i != n_end ) ++n_i;
            ++digit_pos;
            if ( pic_cp != '#' )
              --mandatory_digits;
          } else {                      // must be a grouping-separator
            grouping_cp = pic_cp;       // remember for later
            u_dest.insert( 0, 1, grouping_cp );
            if ( mandatory_grouping_seps )
              --mandatory_grouping_seps;
          }
        } else {                        // have exhausted the picture
          if ( pic.primary.grouping_interval &&
               digit_pos % pic.primary.grouping_interval == 0 ) {
            if ( just_inserted_grouping_separator )
              just_inserted_grouping_separator = false;
            else {
              u_dest.insert( 0, 1, grouping_cp );
              just_inserted_grouping_separator = true;
              continue;
            }
          }
          u_dest.insert( 0, 1, digit_cp );
          if ( n_i != n_end ) ++n_i;
          ++digit_pos;
        }
      } // while

      if ( xs_n.sign() < 0 )
        dest->insert( (zstring::size_type)0, 1, '-' );
      if ( pic.modifier.co == picture::ordinal )
        *dest += ordinal( xs_n );
      break;
    }

    case picture::alpha:
    case picture::ALPHA:
      if ( xs_n.sign() == 0 ) {
        //
        // Ibid: Numbers that fall outside this range must be formatted using
        // the format token 1.
        //
        *dest = '0';
      } else
        try {
          xs_long n = to_xs_long( xs_n );
          if ( n < 0 ) {
            *dest = '-';
            n = -n;
          }
          *dest += ztd::alpha( n, pic.primary.type == picture::ALPHA );
        }
        catch ( range_error const& ) {
          format_integer( xs_n, default_pic, dest );
        }
      break;

    case picture::roman:
    case picture::ROMAN:
      if ( xs_n.sign() == 0 ) {
        //
        // Ibid: Numbers that fall outside this range must be formatted using
        // the format token 1.
        //
        *dest = '0';
      } else
        try {
          xs_long n = to_xs_long( xs_n );
          if ( n < 0 ) {
            *dest = '-';
            n = -n;
          }
          ostringstream oss;
          if ( pic.primary.type == picture::ROMAN )
            oss << uppercase;
          oss << roman( static_cast<unsigned>( n ) );
          *dest += oss.str();
        }
        catch ( range_error const& ) {
          format_integer( xs_n, default_pic, dest );
        }
      break;

    case picture::words:
      try {
        xs_long const n = to_xs_long( xs_n );
        *dest = ztd::english( n, pic.modifier.co == picture::ordinal );
      }
      catch ( range_error const& ) {
        format_integer( xs_n, default_pic, dest );
      }
      break;

    case picture::Words:
      try {
        xs_long const n = to_xs_long( xs_n );
        *dest = ztd::english( n, pic.modifier.co == picture::ordinal );
        std::transform(
          dest->begin(), dest->end(), dest->begin(), ascii::to_title()
        );
      }
      catch ( range_error const& ) {
        format_integer( xs_n, default_pic, dest );
      }
      break;

    case picture::WORDS:
      try {
        xs_long const n = to_xs_long( xs_n );
        *dest = ztd::english( n, pic.modifier.co == picture::ordinal );
        ascii::to_upper( *dest );
      }
      catch ( range_error const& ) {
        format_integer( xs_n, default_pic, dest );
      }
      break;
  } // switch
}

static void parse_primary( zstring const &picture_str,
                           zstring::const_iterator *i, picture *pic,
                           QueryLoc const &loc ) {
  if ( picture_str.empty() ) {
    //
    // XQuery 3.0 F&O 4.6.1: The primary format token is always present and
    // must not be zero-length.
    //
empty_format:
    throw XQUERY_EXCEPTION(
      err::FODF1310,
      ERROR_PARAMS( ZED( FODF1310_EmptyFormat ) ),
      ERROR_LOC( loc )
    );
  }

  //
  // Because of:
  //
  //    Ibid: If the string contains one or more semicolons then everything
  //    that precedes the last semicolon is taken as the primary format token
  //    and everything that follows is taken as the format modifier.
  //
  // we have to count the number of semicolons in order to know when we've
  // reached the last one.
  //
  int semicolon_counter = 0;
  FOR_EACH( zstring, c, picture_str )
    if ( *c == ';' )
      ++semicolon_counter;
  int const semicolons = semicolon_counter;

  if ( semicolons == 1 && picture_str[0] == ';' ) {
    //
    // This also means that the primary format token is zero-length.
    //
    goto empty_format;
  }

  unicode::code_point cp;
  utf8_string<zstring const> const u_picture_str( picture_str );
  utf8_string<zstring const>::const_iterator u;

  //
  // Determine whether the primary format token is a decimal-digit-pattern:
  //
  //    Ibid: If the primary format token contains at least one Unicode digit
  //    then it is taken as a decimal digit pattern.
  //
  // and whether all digits are from the same digit family:
  //
  //    Ibid: All mandatory-digit-signs within the format token must be from
  //    the same digit family, where a digit family is a sequence of ten
  //    consecutive characters in Unicode category Nd, having digit values 0
  //    through 9.
  //
  bool is_decimal_digit_pattern = false;
  unicode::code_point zero[] = { '0', '0' };
  semicolon_counter = semicolons;
  for ( u = u_picture_str.begin(); u != u_picture_str.end(); ++u ) {
    cp = *u;
    if ( cp == ';' && !--semicolon_counter )
      break;
    if ( unicode::is_Nd( cp, &zero[ is_decimal_digit_pattern ] ) ) {
      if ( is_decimal_digit_pattern && zero[1] != zero[0] ) {
        throw XQUERY_EXCEPTION(
          err::FODF1310,
          ERROR_PARAMS(
            picture_str,
            ZED( FODF1310_DigitNotSameFamily_34 ),
            unicode::printable_cp( cp ),
            unicode::printable_cp( zero[0] )
          ),
          ERROR_LOC( loc )
        );
      }
      is_decimal_digit_pattern = true;
      ++pic->primary.mandatory_digits;
    }
  }

  u = u_picture_str.begin();
  cp = *u;

  if ( is_decimal_digit_pattern ) {
    if ( cp != '#' && unicode::is_grouping_separator( cp ) ) {
      //
      // Ibid 4.6.1: A grouping-separator-sign must not appear at the start ...
      // of the decimal-digit-pattern ....
      //
      throw XQUERY_EXCEPTION(
        err::FODF1310,
        ERROR_PARAMS(
          picture_str,
          ZED( FODF1310_NoGroupSepAtStart_3 ),
          unicode::printable_cp( cp )
        ),
        ERROR_LOC( loc )
      );
    }

    pic->primary.zero = zero[0];

    utf8_string<zstring> u_pic_format( pic->primary.format );
    u_pic_format += cp;

    bool got_grouping_separator = false;
    bool got_mandatory_digit = cp != '#';
    int grouping_interval = 0;
    bool grouping_interval_possible = true;
    unicode::code_point grouping_separator_cp = 0;
    int grouping_separators = 0;
    utf8::size_type pos = 1, prev_grouping_pos = utf8::npos;

    semicolon_counter = semicolons;
    while ( ++u != u_picture_str.end() ) {
      cp = *u;
      if ( cp == '#' ) {
        if ( got_mandatory_digit ) {
          //
          // Ibid: There may be zero or more optional-digit-signs, and (if
          // present) these must precede all mandatory-digit-signs.
          //
          throw XQUERY_EXCEPTION(
            err::FODF1310,
            ERROR_PARAMS(
              picture_str,
              ZED( FODF1310_NoOptDigitAfterMandatory )
            ),
            ERROR_LOC( loc )
          );
        }
        got_grouping_separator = false;
      } else if ( unicode::is_Nd( cp ) ) {
        got_mandatory_digit = true;
        got_grouping_separator = false;
      } else if ( unicode::is_grouping_separator( cp ) ) {
        if ( cp == ';' && !--semicolon_counter ) {
          //
          // Ibid: If the string contains one or more semicolons then
          // everything that precedes the last semicolon is taken as the
          // primary format token and everything that follows is taken as the
          // format modifier.
          //
          break;
        }
        if ( got_grouping_separator ) {
          //
          // Ibid: A grouping-separator-sign must not appear ... adjacent to
          // another grouping-separator-sign.
          //
          throw XQUERY_EXCEPTION(
            err::FODF1310,
            ERROR_PARAMS(
              picture_str,
              ZED( FODF1310_NoAdjacentGroupSep_3 ),
              unicode::printable_cp( cp )
            ),
            ERROR_LOC( loc )
          );
        }
        got_grouping_separator = true;
        ++grouping_separators;

        if ( grouping_interval_possible ) {
          //
          // Ibid: If grouping-separator-signs appear at regular intervals
          // within the format token, that is if the same grouping separator
          // appears at positions forming a sequence N, 2N, 3N, ... for some
          // integer value N (including the case where there is only one number
          // in the list), then the sequence is extrapolated to the left, so
          // grouping separators will be used in the formatted number at every
          // multiple of N. For example, if the format token is 0'000 then the
          // number one million will be formatted as 1'000'000, while the
          // number fifteen will be formatted as 0'015.
          //
          if ( !grouping_separator_cp )
            grouping_separator_cp = cp;
          else if ( cp != grouping_separator_cp )
            grouping_interval_possible = false;
          else if ( !grouping_interval )
            grouping_interval = pos - prev_grouping_pos;
          else if ( pos - prev_grouping_pos != grouping_interval )
            grouping_interval_possible = false;
          prev_grouping_pos = pos + 1;
        }
      } else {
        throw XQUERY_EXCEPTION(
          err::FODF1310,
          ERROR_PARAMS(
            picture_str,
            ZED( FODF1310_BadCharacter_3 ),
            unicode::printable_cp( cp )
          ),
          ERROR_LOC( loc )
        );
      }
      u_pic_format += cp;
      ++pos;
    } // while

    if ( got_grouping_separator ) {
      //
      // Ibid: A grouping-separator-sign must not appear at the ... end of the
      // decimal-digit-pattern ....
      //
      throw XQUERY_EXCEPTION(
        err::FODF1310,
        ERROR_PARAMS(
          picture_str,
          ZED( FODF1310_NoGroupSepAtEnd_3 ),
          unicode::printable_cp( cp )
        ),
        ERROR_LOC( loc )
      );
    }

    if ( grouping_interval_possible ) {
      if ( !grouping_interval ) {
        if ( grouping_separator_cp ) {
          //
          // There's only a single grouping separator, e.g., "1,000".
          //
          grouping_interval = pos - prev_grouping_pos;
        }
      } else if ( pos - prev_grouping_pos != grouping_interval ) {
        //
        // There are multiple grouping separators, but they're not equally
        // spaced from the last digit, e.g., "1,000,00".  (This is most likely
        // a mistake on the part of the user.)
        //
        grouping_interval = 0;
      }
      pic->primary.grouping_interval = grouping_interval;
    } else
      pic->primary.mandatory_grouping_seps = grouping_separators;

  } else {

    using namespace unicode;
    ++u;
    switch ( cp ) {
      case 'A':
        pic->primary.type = picture::ALPHA;
        break;
      case 'a':
        pic->primary.type = picture::alpha;
        break;
      case 'I':
        pic->primary.type = picture::ROMAN;
        break;
      case 'i':
        pic->primary.type = picture::roman;
        break;
      case 'W':
        if ( u != u_picture_str.end() && *u == 'w' )
          pic->primary.type = picture::Words, ++u;
        else
          pic->primary.type = picture::WORDS;
        break;
      case 'w':
        pic->primary.type = picture::words;
        break;
      case CIRCLED_DIGIT_ONE:
      case CIRCLED_IDEOGRAPH_ONE:
      case DIGIT_ONE_FULL_STOP:
      case DINGBAT_CIRCLED_SANS_SERIF_DIGIT_ONE:
      case DINGBAT_NEGATIVE_CIRCLED_DIGIT_ONE:
      case DINGBAT_NEGATIVE_CIRCLED_SANS_SERIF_DIGIT_ONE:
      case DOUBLE_CIRCLED_DIGIT_ONE:
      case PARENTHESIZED_DIGIT_ONE:
      case PARENTHESIZED_IDEOGRAPH_ONE:
      case SUBSCRIPT_ONE:
      case SUPERSCRIPT_ONE:
        pic->primary.type = picture::one;
        pic->primary.one = cp;
        break;
      default:
        //
        // Ibid: If an implementation does not support a numbering sequence
        // represented by the given token, it must use a format token of 1.
        //
        pic->primary.type = picture::arabic;
        pic->primary.format = "1";

        //
        // Ibid: If the string contains one or more semicolons then
        // everything that precedes the last semicolon is taken as the
        // primary format token and everything that follows is taken as the
        // format modifier.
        //
        // Hence, we have to skip everything up to (but not including) the last
        // semicolon (if any).
        //
        semicolon_counter = semicolons;
        for ( ; u != u_picture_str.end(); ++u )
          if ( *u == ';' && !--semicolon_counter )
            break;
    } // switch
  }
  *i = u.base();
}

static void parse_variation( utf8_string<zstring const> const &u_picture_str,
                             utf8_string<zstring const>::const_iterator *u,
                             picture *pic, QueryLoc const &loc ) {
  utf8_string<zstring const>::const_iterator &v = *u;
  if ( v == u_picture_str.end() )
    return;
  if ( *v == '(' ) {
    //
    // XQuery F&O 3.0 4.6.1: The string of characters between the parentheses,
    // if present, is used to select between other possible variations of
    // cardinal or ordinal numbering sequences. The interpretation of this
    // string is implementation-defined. No error occurs if the implementation
    // does not define any interpretation for the defined string.
    //
    utf8_string<zstring> u_pic_co_string( pic->modifier.co_string );
    while ( true ) {
      if ( ++v == u_picture_str.end() )
        throw XQUERY_EXCEPTION(
          err::FODF1310,
          ERROR_PARAMS( *u_picture_str.get(), ZED( CharExpected_3 ), ')' ),
          ERROR_LOC( loc )
        );
      unicode::code_point const cp = *v;
      if ( cp == ')' )
        break;
      u_pic_co_string += cp;
    }
    ++v;
  }
}

static void parse_format_modifier( zstring const &picture_str,
                                   zstring::const_iterator *i, picture *pic,
                                   QueryLoc const &loc ) {
  utf8_string<zstring const> const u_picture_str( picture_str );
  utf8_string<zstring const>::const_iterator u( u_picture_str.current( *i ) );

  unicode::code_point cp = *u++;
  if ( cp != ';' )
    goto bad_format_modifier;

  bool got_c, got_o, got_a, got_t;
  got_c = got_o = got_a = got_t = false;

  while ( u != u_picture_str.end() ) {
    cp = *u++;
    switch ( cp ) {
      case 'c':
        if ( got_c )
          goto dup_format_modifier;
        if ( got_o || got_a || got_t )
          goto bad_format_modifier_here;
        got_c = true;
        pic->modifier.co = picture::cardinal;
        parse_variation( u_picture_str, &u, pic, loc );
        break;
      case 'o':
        if ( got_o )
          goto dup_format_modifier;
        if ( got_c || got_a || got_t )
          goto bad_format_modifier_here;
        got_o = true;
        pic->modifier.co = picture::ordinal;
        parse_variation( u_picture_str, &u, pic, loc );
        break;
      case 'a':
        if ( got_a )
          goto dup_format_modifier;
        if ( got_t )
          goto bad_format_modifier_here;
        got_a = true;
        pic->modifier.at = picture::alphabetic;
        break;
      case 't':
        if ( got_t )
          goto dup_format_modifier;
        if ( got_a )
          goto bad_format_modifier_here;
        got_t = true;
        pic->modifier.at = picture::traditional;
        break;
      default:
        goto bad_format_modifier;
    } // switch
  } // while
  *i = u.base();
  return;

bad_format_modifier:
  throw XQUERY_EXCEPTION(
    err::FODF1310,
    ERROR_PARAMS(
      picture_str,
      ZED( FODF1310_BadFormatModifier_3 ),
      unicode::printable_cp( cp )
    ),
    ERROR_LOC( loc )
  );

bad_format_modifier_here:
  throw XQUERY_EXCEPTION(
    err::FODF1310,
    ERROR_PARAMS(
      picture_str,
      ZED( FODF1310_BadFormatModifierHere_3 ),
      unicode::printable_cp( cp )
    )
  );

dup_format_modifier:
  throw XQUERY_EXCEPTION(
    err::FODF1310,
    ERROR_PARAMS(
      picture_str,
      ZED( FODF1310_DupFormatModifier_3 ),
      unicode::printable_cp( cp )
    )
  );
}

bool FormatIntegerIterator::nextImpl( store::Item_t &result,
                                      PlanState &planState ) const {
  store::Item_t item;
  iso639_1::type lang = iso639_1::unknown;
  iso3166_1::type country = iso3166_1::unknown;
  picture pic;
  zstring::const_iterator pic_i;
  zstring picture_str, result_str;
  xs_integer value;
  PlanIteratorState *state;

  DEFAULT_STACK_INIT( PlanIteratorState, state, planState );

  if ( consumeNext( item, theChildren[0].getp(), planState ) ) {
    value = item->getIntegerValue();
    consumeNext( item, theChildren[1].getp(), planState );
    item->getStringValue2( picture_str );

    if ( theChildren.size() > 2 ) {
      consumeNext( item, theChildren[2].getp(), planState );
      if ( !locale::parse( item->getStringValue(), &lang, &country ) ||
           !locale::is_supported( lang, country ) ) {
        lang = iso639_1::unknown;
        pic.lang_is_fallback = true;
      }
    }

    if ( !lang ) {
      //
      // XQuery 3.0 F&O 4.6.1: If the $lang argument is absent, or is set to an
      // empty sequence, or is invalid, or is not a language supported by the
      // implementation, then the number is formatted using the default
      // language from the dynamic context.
      //
      planState.theLocalDynCtx->get_locale( &lang, &country );
      if ( !locale::is_supported( lang, country ) ) {
        //
        // If the language defined in the dynamic context isn't supported
        // either, try the host's language and hope for the best.
        //
        lang = locale::get_host_lang();
        country = locale::get_host_country();
        pic.lang_is_fallback = true;
      }
    }

    pic.lang = lang;
    pic.country = country;

    pic_i = picture_str.begin();
    parse_primary( picture_str, &pic_i, &pic, loc );
    if ( pic_i != picture_str.end() )
      parse_format_modifier( picture_str, &pic_i, &pic, loc );

    format_integer( value, pic, &result_str );
  }
  STACK_PUSH( GENV_ITEMFACTORY->createString( result, result_str ), state );
  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
