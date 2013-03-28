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

  enum modifier_at_type {
    no_at,
    alphabetic,   // 'a'
    traditional,  // 't'
  };

  struct {
    bool parsed;
    primary_type type;
    zstring format;
    int grouping_interval;
    unicode::code_point zero, one;
  } primary;

  struct {
    co_type co;
    zstring co_string;
    modifier_at_type at;
  } modifier;

  //
  // This stuff isn't part of the "presentation modifier" as discussed in the
  // XQuery 3.0 F&O spec, but this is a convenient place to put it nonetheless.
  //
  iso639_1::type lang;
  bool lang_is_fallback;
  iso3166_1::type country;

  picture() {
    primary.parsed = false;
    primary.type = arabic;
    primary.grouping_interval = 0;
    primary.zero = '0';
    modifier.co = cardinal;
    modifier.at = no_at;
  }

  // default picture(picture const&) is fine
  // default picture& operator=(picture const&) is fine
};

///////////////////////////////////////////////////////////////////////////////

#if 0
/*
  represent integer as sequence of letters A, B, ... Z, AA, AB, ....
  'A' is 1
  0 is empty string
  The sequence includes the characters 'I' and 'O'
  There is no upper limit for the input integer
*/
void FormatIntegerIterator::formatIntegerAZ(xs_integer valueInteger, char c0, zstring &resultString)
{
  static const unsigned int letter_range = 'Z' - 'A' + 1;
  static xs_integer integer_digit(letter_range);
  xs_integer  upper_int = valueInteger/integer_digit;
  if(upper_int > 0)
    formatIntegerAZ(upper_int - 1, c0, resultString);
  xs_integer  mod_integer = valueInteger % integer_digit;
  xs_int      mod_int = to_xs_int(mod_integer);
  resultString += (c0 + mod_int);
}
#endif

///////////////////////////////////////////////////////////////////////////////

static bool get_one_range( unicode::code_point cp, int *min, int *max ) {
  using namespace unicode;
  switch ( cp ) {
    case CIRCLED_DIGIT_ONE:
      *min = 0, *max = 50;
      break;
    case CIRCLED_IDEOGRAPH_ONE:
    case DINGBAT_CIRCLED_SANS_SERIF_DIGIT_ONE:
    case DINGBAT_NEGATIVE_CIRCLED_SANS_SERIF_DIGIT_ONE:
    case DOUBLE_CIRCLED_DIGIT_ONE:
    case PARENTHESIZED_IDEOGRAPH_ONE:
      *min = 1, *max = 10;
      break;
    case DIGIT_ONE_FULL_STOP:
    case DINGBAT_NEGATIVE_CIRCLED_DIGIT_ONE:
    case PARENTHESIZED_DIGIT_ONE:
      *min = 1, *max = 20;
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

static void format_number( xs_integer const &xs_n, picture const &pic,
                           zstring *dest ) {
  unicode::code_point zero = pic.primary.zero;
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
        // Ibid: If an implementation does not support a numbering sequence
        // represented by the given token, it must use a format token of 1.
        //
        // Ibid: Numbers that fall outside this range must be formatted using
        // the format token 1.
        //
        zero = '0';
      }
      catch ( range_error const& ) {
        picture default_pic;
        format_number( xs_n, default_pic, dest );
        break;
      }
      // no break;

    case picture::arabic: {
      xs_integer xs_n2( xs_n );
      if ( xs_n2.sign() < 0 ) {
        xs_n2 = -xs_n2;
        *dest = '-';
      }

      zstring const s( xs_n2.toString() );
      zstring::const_reverse_iterator n_i( s.rbegin() );
      zstring::const_reverse_iterator const n_end( s.rend() );

      utf8_string<zstring const> const u_pic_format( pic.primary.format );
      utf8_string<zstring const>::const_reverse_iterator
        pic_i( u_pic_format.rbegin() );
      utf8_string<zstring const>::const_reverse_iterator const
        pic_end( u_pic_format.rend() );

      utf8_string<zstring> u_dest( *dest );

      unicode::code_point digit_cp, grouping_cp, pic_cp;
      int digit_pos = 0;
      bool just_inserted_grouping_separator = false;

      while ( n_i != n_end || pic_i != pic_end ) {
        digit_cp = pic.primary.zero;
        if ( n_i != n_end )
          digit_cp += *n_i - '0';
        if ( pic_i != pic_end ) {
          pic_cp = *pic_i++;
          if ( pic_cp == '#' && n_i == n_end )
            break;
          if ( pic_cp == '#' || unicode::is_Nd( pic_cp ) ) {
            u_dest.insert( 0, 1, digit_cp );
            if ( n_i != n_end ) ++n_i;
            ++digit_pos;
          } else {                      // must be a grouping-separator
            grouping_cp = pic_cp;       // remember for later
            u_dest.insert( 0, 1, grouping_cp );
          }
        } else {
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
      break;
    }

    case picture::alpha:
    case picture::ALPHA:
      try {
        xs_long const n = to_xs_long( xs_n );
        *dest = ztd::alpha( n, pic.primary.type == picture::ALPHA );
      }
      catch ( range_error const& ) {
        picture default_pic;
        format_number( xs_n, default_pic, dest );
      }
      break;

    case picture::roman:
    case picture::ROMAN:
      try {
        xs_long n = to_xs_long( xs_n );
        if ( n < 0 ) {
          *dest = '-';
          n = -n;
        }
        ostringstream oss;
        if ( pic.primary.type == picture::ROMAN )
          oss << uppercase;
        oss << roman( n );
        *dest += oss.str();
      }
      catch ( range_error const& ) {
        picture default_pic;
        format_number( xs_n, default_pic, dest );
      }
      break;

    case picture::words:
      try {
        xs_long const n = to_xs_long( xs_n );
        *dest = ztd::english( n, pic.modifier.co == picture::ordinal );
      }
      catch ( range_error const& ) {
        picture default_pic;
        format_number( xs_n, default_pic, dest );
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
        picture default_pic;
        format_number( xs_n, default_pic, dest );
      }
      break;

    case picture::WORDS:
      try {
        xs_long const n = to_xs_long( xs_n );
        *dest = ztd::english( n, pic.modifier.co == picture::ordinal );
        ascii::to_upper( *dest );
      }
      catch ( range_error const& ) {
        picture default_pic;
        format_number( xs_n, default_pic, dest );
      }
      break;
  } // switch
}

static void parse_primary( zstring const &picture_str,
                           zstring::const_iterator *i, picture *pic,
                           QueryLoc const &loc ) {
  if ( picture_str.empty() ) {
    //
    // XQuery 3.0 F&O: 4.6.1: The primary format token is always present and
    // must not be zero-length.
    //
    throw XQUERY_EXCEPTION(
      err::FODF1310,
      ERROR_PARAMS( ZED( FODF1310_EmptyPictureString ) ),
      ERROR_LOC( loc )
    );
  }

  pic->primary.format = picture_str;

  utf8_string<zstring const> const u_picture_str( picture_str );
  utf8_string<zstring const>::const_iterator u( u_picture_str.current( *i ) );
  unicode::code_point cp = *u;

  if ( cp != '#' && unicode::is_grouping_separator( cp ) ) {
    //
    // XQuery 3.0 F&O: 4.6.1: A grouping-separator-sign must not appear
    // at the start ... of the decimal-digit-pattern ....
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
  int semicolons = 0;
  for ( zstring::const_iterator c( *i ); c != picture_str.end(); ++c )
    if ( *c == ';' )
      ++semicolons;

  unicode::code_point zero[2];

  if ( cp == '#' || unicode::is_Nd( cp, &zero[0] ) ) {
    bool got_grouping_separator = false;
    bool got_mandatory_digit = cp != '#';
    bool grouping_interval_possible = true;
    zstring::size_type pos = 0, prev_grouping_pos = zstring::npos;
    unicode::code_point prev_grouping_separator = 0;

    while ( ++u != u_picture_str.end() ) {
      cp = *u, ++pos;
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
      } else if ( unicode::is_Nd( cp, &zero[ got_mandatory_digit ] ) ) {
        if ( got_mandatory_digit ) {
          if ( zero[1] != zero[0] ) {
            //
            // Ibid: All mandatory-digit-signs within the format token must be
            // from the same digit family, where a digit family is a sequence
            // of ten consecutive characters in Unicode category Nd, having
            // digit values 0 through 9.
            //
            throw XQUERY_EXCEPTION(
              err::FODF1310,
              ERROR_PARAMS(
                picture_str,
                ZED( FODF1310_DigitNotSameFamily_34 ),
                unicode::printable_cp( cp ),
                unicode::printable_cp( zero[1] )
              ),
              ERROR_LOC( loc )
            );
          }
        } else
          got_mandatory_digit = true;
        got_grouping_separator = false;
      } else if ( unicode::is_grouping_separator( cp ) ) {
        if ( cp == ';' && !--semicolons ) {
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
          if ( !prev_grouping_separator )
            prev_grouping_separator = cp;
          else if ( cp != prev_grouping_separator )
            goto no_inter;
          else if ( !pic->primary.grouping_interval )
            pic->primary.grouping_interval = pos - prev_grouping_pos;
          else if ( pos - prev_grouping_pos !=
                    pic->primary.grouping_interval ) {
no_inter:   pic->primary.grouping_interval = 0;
            grouping_interval_possible = false;
          }
          prev_grouping_pos = pos;
        }
      } else
        throw XQUERY_EXCEPTION(
          err::FODF1310,
          ERROR_PARAMS(
            picture_str,
            ZED( FODF1310_BadCharacter_3 ),
            unicode::printable_cp( cp )
          ),
          ERROR_LOC( loc )
        );
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
    if ( !got_mandatory_digit ) {
      //
      // Ibid: There must be at least one mandatory-digit-sign.
      //
      throw XQUERY_EXCEPTION(
        err::FODF1310,
        ERROR_PARAMS( picture_str, ZED( FODF1310_MustBeOneMandatoryDigit ) ),
        ERROR_LOC( loc )
      );
    }
    if ( prev_grouping_separator && !pic->primary.grouping_interval )
      pic->primary.grouping_interval = pos - prev_grouping_pos;
    pic->primary.zero = zero[0];
  } else {
    using namespace unicode;
    cp = *u++;
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
    } // switch
  }
  *i = u.base();
  pic->primary.parsed = true;
}

static void parse_format_modifier( zstring const &picture_str,
                                   zstring::const_iterator *i, picture *pic,
                                   QueryLoc const &loc ) {
  zstring::const_iterator &j = *i;
  switch ( *j ) {
    case 'c': pic->modifier.co = picture::cardinal   ; break;
    case 'o': pic->modifier.co = picture::ordinal    ; break;
    case 'a': pic->modifier.at = picture::alphabetic ; ++j; return;
    case 't': pic->modifier.at = picture::traditional; ++j; return;
    default : return;
  }
  if ( ++j == picture_str.end() )
    return;
  if ( *j == '(' ) {
    //
    // XQuery F&O 3.0 4.6.1: The string of characters between the parentheses,
    // if present, is used to select between other possible variations of
    // cardinal or ordinal numbering sequences. The interpretation of this
    // string is implementation-defined. No error occurs if the implementation
    // does not define any interpretation for the defined string.
    //
    while ( true ) {
      if ( ++j == picture_str.end() )
        throw XQUERY_EXCEPTION(
          err::FODF1310,
          ERROR_PARAMS( picture_str, ZED( CharExpected_3 ), ')' ),
          ERROR_LOC( loc )
        );
      if ( *j == ')' )
        break;
      pic->modifier.co_string += *j;
    }
    ++j;
  }
}

bool FormatIntegerIterator::nextImpl( store::Item_t &result,
                                      PlanState &planState ) const {
  store::Item_t item;
  iso639_1::type lang = iso639_1::unknown;
  iso3166_1::type country = iso3166_1::unknown;
  bool lang_is_fallback = false;
  picture pic;
  zstring::const_iterator pic_i;
  zstring picture_str, result_str;
  xs_integer value;
  PlanIteratorState *state;

  DEFAULT_STACK_INIT( PlanIteratorState, state, planState );

  if ( !consumeNext( item, theChildren[0].getp(), planState ) ) {
    // Got the empty sequence -- return same
    STACK_PUSH( false, state );
  } else {
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
      // XQuery 3.0 F&O: 4.6.1: If the $lang argument is absent, or is set to
      // an empty sequence, or is invalid, or is not a language supported by
      // the implementation, then the number is formatted using the default
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

    format_number( value, pic, &result_str );
    STACK_PUSH( GENV_ITEMFACTORY->createString( result, result_str ), state );
  }
  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
