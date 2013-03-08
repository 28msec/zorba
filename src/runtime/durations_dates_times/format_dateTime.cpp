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
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <sstream>

// Zorba
#include "context/dynamic_context.h"
#include "context/static_context.h"
#include "runtime/core/arithmetic_impl.h"
#include "runtime/visitors/planiter_visitor.h"
#include "store/api/item.h"
#include "store/api/item_factory.h"
#include "store/api/store.h"
#include "system/globalenv.h"
#include "util/ascii_util.h"
#include "util/stream_util.h"
#include "util/string_util.h"
#include "zorbatypes/datetime.h"
#include "zorbatypes/datetime/parse.h"
#include "zorbatypes/duration.h"
#include "zorbatypes/zstring.h"
#include "zorbautils/locale.h"

// local
#include "format_dateTime.h"

using namespace std;
using namespace zorba::locale;

namespace zorba {

SERIALIZABLE_CLASS_VERSIONS(FnFormatDateTimeIterator)
NARY_ACCEPT(FnFormatDateTimeIterator);

///////////////////////////////////////////////////////////////////////////////

struct modifier {
  enum first_type {
    arabic,       // '1' : 0 1 2 ... 10 11 12 ...
    alpha,        // 'a' : a b c ... z aa ab ac ...
    ALPHA,        // 'A' : A B C ... Z AA AB AC ...
    roman,        // 'i' : i ii iii iv v vi vii viii ix x ...
    ROMAN,        // 'I' : I II III IV V VI VII VIII IX X ...
    words,        // 'w' : one two three four ...
    Words,        // 'Ww': One Two Three Four ...
    WORDS,        // 'W' : ONE TWO THREE FOUR ...
    name,         // 'n' : name
    Name,         // 'Nn': Name
    NAME          // 'N' : NAME
  };

  enum second_co_type {
    no_second_co,
    cardinal,     // 'c': 7 or seven
    ordinal       // 'o': 7th or seventh
  };

  enum second_at_type {
    no_second_at,
    alphabetic,   // 'a'
    traditional   // 't'
  };

  first_type first;
  zstring first_string;
  unicode::code_point first_zero;

  second_co_type second_co;
  zstring second_co_string;
  second_at_type second_at;

  typedef unsigned long width_type;

  enum width_special_value {
    star = 0
    // > 0 means explicitly specified width
  };

  width_type min_width;
  width_type max_width;

  bool is_set() const {
    return !first_string.empty();
  }

  bool gt_max_width( width_type n ) const {
    return max_width > 0 && n > max_width;
  }

  zstring const& pad_space( zstring *s ) const {
    if ( min_width ) {
      utf8_string<zstring> u( *s );
      utf8_string<zstring>::size_type const u_size( u.size() );
      if ( u_size < min_width )
        s->append( min_width - u_size, ' ' );
    }
    return *s;
  }

  zstring const& zero_pad( zstring *s ) const {
    if ( min_width ) {
      utf8_string<zstring> u( *s );
      utf8_string<zstring>::size_type u_size( u.size() );
      zstring zero;
      utf8::encode( first_zero, &zero );
      while ( u_size++ < min_width )
        u.insert( 0, zero );
    }
    return *s;
  }

  modifier() {
    first = arabic;
    first_zero = '0';
    second_co = cardinal;
    second_at = no_second_at;
    min_width = max_width = star;
  };
};

///////////////////////////////////////////////////////////////////////////////

zstring alpha( unsigned long n, bool capital ) {
  char const c = capital ? 'A' : 'a';
  zstring result;
  while ( n ) {
    unsigned long const m = n - 1;
    result.insert( (zstring::size_type)0, 1, c + m % 26 );
    n = m / 26;
  }
  return result;
}

///////////////////////////////////////////////////////////////////////////////

namespace english_impl {

// Based on code from:
// http://www.cprogramming.com/challenges/integer-to-english-sol.html

static string const ones[][2] = {
  { "",          ""            },
  { "one",       "first"       },
  { "two",       "second"      },
  { "three",     "third"       },
  { "four",      "fourth"      },
  { "five",      "fifth"       },
  { "six",       "sixth"       },
  { "seven",     "seventh"     },
  { "eight",     "eighth"      },
  { "nine",      "ninth"       },
  { "ten",       "tenth"       },
  { "eleven",    "eleventh"    },
  { "twelve",    "twelveth"    },
  { "thirteen",  "thirteenth"  },
  { "fourteen",  "fourteenth"  },
  { "fifteen",   "fifteenth"   },
  { "sixteen",   "sixteenth"   },
  { "seventeen", "seventeenth" },
  { "eighteen",  "eighteenth"  },
  { "nineteen",  "nineteenth"  }
};

static zstring const tens[][2] = {
  { "",        ""           },
  { "",        ""           },
  { "twenty",  "twentieth"  },
  { "thirty",  "thirtieth"  },
  { "forty",   "fortieth"   },
  { "fifty",   "fiftieth"   },
  { "sixty",   "sixtieth"   },
  { "seventy", "seventieth" },
  { "eighty",  "eighteenth" },
  { "ninety",  "ninetieth"  }
};

// Enough entries to print English for 64-bit integers.
static zstring const big[][2] = {
  { "",            ""              },
  { "thousand",    "thousandth"    },
  { "million",     "millionth"     },
  { "billion",     "billionth"     },
  { "trillion",    "trillionth"    },
  { "quadrillion", "quadrillionth" },
  { "quintillion", "quintillionth" }
};

inline zstring if_space( zstring const &s ) {
  return s.empty() ? "" : ' ' + s;
}

zstring hundreds( int64_t n, bool ordinal ) {
  if ( n < 20 )
    return ones[ n ][ ordinal ];
  zstring const tmp( if_space( ones[ n % 10 ][ ordinal ] ) );
  return tens[ n / 10 ][ ordinal && tmp.empty() ] + tmp;
}

} // namespace english_impl

/**
 * Converts a signed integer to English, e.g, 42 becomes "forty two".
 *
 * @param n The integer to convert.
 * @param ordinal If \c true, ordinal words ("forty second") are returned.
 * @return Returns \a n in English.
 */
static zstring english( int64_t n, bool ordinal = false ) {
  using namespace english_impl;

  if ( !n )
    return ordinal ? "zeroth" : "zero";

  bool const negative = n < 0;
  if ( negative )
    n = -n;

  int big_count = 0;
  bool big_ordinal = ordinal;
  zstring r;

  while ( n ) {
    if ( int64_t const m = n % 1000 ) {
      zstring s;
      if ( m < 100 )
        s = hundreds( m, ordinal );
      else {
        zstring const tmp( if_space( hundreds( m % 100, ordinal ) ) );
        s = ones[ m / 100 ][0] + ' '
          + (ordinal && tmp.empty() ? "hundredth" : "hundred") + tmp;
      }
      zstring const tmp( if_space( r ) );
      r = s + if_space( big[ big_count ][ big_ordinal && tmp.empty() ] + tmp );
      big_ordinal = false;
    }
    n /= 1000;
    ++big_count;
    ordinal = false;
  }

  if ( negative )
    r = "negative " + r;
  return r;
}

///////////////////////////////////////////////////////////////////////////////

/**
 * Returns the English ordinal suffix for an integer, e.g., "st" for 1, "nd"
 * for 2, etc.
 *
 * @param n The integer to return the ordinal suffix for.
 * @return Returns said suffix.
 */
static char const* ordinal( long n ) {
  switch ( n % 100 ) {
    case 11:
    case 12:
    case 13:
      break;
    default:
      switch ( n % 10 ) {
        case 1: return "st";
        case 2: return "nd";
        case 3: return "rd";
      }
  }
  return "th";
}

///////////////////////////////////////////////////////////////////////////////

/**
 * A unary_function to convert a (presumed) lower-case string to title-case
 * "Like This."
 */
class to_title : public unary_function<char,char> {
public:
  to_title() : capitalize_( true ) { }

  result_type operator()( argument_type c ) {
    if ( ascii::is_alpha( c ) ) {
      if ( capitalize_ ) {
        c = ascii::to_upper( c );
        capitalize_ = false;
      }
    } else if ( ascii::is_space( c ) )
      capitalize_ = true;
    return c;
  };

private:
  bool capitalize_;
};

///////////////////////////////////////////////////////////////////////////////

static void append_number( long n, modifier const &mod, zstring *dest ) {
  switch ( mod.first ) {
    case modifier::arabic: {
      ztd::itoa_buf_type buf;
      // TODO: should use appropriate digits
      zstring tmp( ztd::itoa( n, buf ) );
      if ( mod.second_co == modifier::ordinal )
        tmp += ordinal( n );
      *dest += mod.zero_pad( &tmp );
      break;
    }

    case modifier::alpha:
    case modifier::ALPHA: {
      zstring tmp( alpha( n, mod.first == modifier::ALPHA ) );
      *dest += mod.pad_space( &tmp );
      break;
    }

    case modifier::roman:
    case modifier::ROMAN: {
      ostringstream oss;
      if ( mod.first == modifier::ROMAN )
        oss << uppercase;
      oss << roman( n );
      zstring tmp( oss.str() );
      *dest += mod.pad_space( &tmp );
      break;
    }

    case modifier::words: {
      zstring tmp( english( n, mod.second_co == modifier::ordinal ) );
      *dest += mod.pad_space( &tmp );
      break;
    }

    case modifier::Words: {
      zstring tmp( english( n, mod.second_co == modifier::ordinal ) );
      std::transform( tmp.begin(), tmp.end(), tmp.begin(), to_title() );
      *dest += mod.pad_space( &tmp );
      break;
    }

    case modifier::WORDS: {
      zstring tmp( english( n, mod.second_co == modifier::ordinal ) );
      ascii::to_upper( tmp );
      *dest += mod.pad_space( &tmp );
      break;
    }

    case modifier::name:
    case modifier::Name:
    case modifier::NAME:
      ;
  }
}

static bool append_string( zstring const &s, modifier const &mod,
                           zstring *dest ) {
  zstring tmp;
  switch ( mod.first ) {
    case modifier::name:
      utf8::to_lower( s, &tmp );
      break;
    case modifier::Name: {
      utf8::to_upper( s.substr( 0, 1 ), &tmp );
      zstring tmp2;
      utf8::to_lower( s.substr( 1 ), &tmp2 );
      tmp += tmp2;
      break;
    }
    case modifier::NAME:
      utf8::to_upper( s, &tmp );
      break;
    default:
      return false;
  }

  *dest += mod.pad_space( &tmp );
  return true;
}

inline void append_component( long n, zstring const &s, modifier const &mod,
                              zstring *dest ) {
  if ( !append_string( s, mod, dest ) )
    append_number( n, mod, dest );
}

static void append_month( long month, iso639_1::type lang,
                          iso3166_1::type country, modifier const &mod,
                          zstring *dest ) {
  zstring name( locale::get_month_name( month - 1, lang, country ) );
  utf8_string<zstring> u_name( name );

  if ( mod.gt_max_width( u_name.size() ) ) {
    //
    // XQuery 3.0 F&O: 9.8.4.1: If the full representation of the value exceeds
    // the specified maximum width, then the processor should attempt to use an
    // alternative shorter representation that fits within the maximum width.
    // Where the presentation modifier is N, n, or Nn, this is done by
    // abbreviating the name, using either conventional abbreviations if
    // available, or crude right-truncation if not.
    //
    name = locale::get_month_abbr( month - 1, lang, country );
    if ( mod.gt_max_width( u_name.size() ) )
      u_name = u_name.substr( 0, mod.max_width );
  }

  append_component( month, name, mod, dest );
}

static void append_year( long year, modifier const &mod, zstring *s ) {
  zstring tmp;
  append_number( year, mod, &tmp );

  if ( mod.first == modifier::arabic && mod.gt_max_width( tmp.size() ) )
    tmp = tmp.substr( tmp.size() - mod.max_width );
  *s += tmp;
}

static void append_weekday( long day, iso639_1::type lang,
                            iso3166_1::type country, modifier &mod,
                            zstring *dest ) {
  zstring name( locale::get_weekday_name( day, lang, country ) );
  utf8_string<zstring> u_name( name );

  if ( mod.gt_max_width( u_name.size() ) ) {
    //
    // XQuery 3.0 F&O: 9.8.4.1: If the full representation of the value exceeds
    // the specified maximum width, then the processor should attempt to use an
    // alternative shorter representation that fits within the maximum width.
    // Where the presentation modifier is N, n, or Nn, this is done by
    // abbreviating the name, using either conventional abbreviations if
    // available, or crude right-truncation if not.
    //
    name = locale::get_weekday_abbr( day, lang, country );
    if ( mod.gt_max_width( u_name.size() ) )
      u_name = u_name.substr( 0, mod.max_width );
  }

  modifier default_mod( mod );
  if ( !mod.is_set() )
    default_mod.first = modifier::name;

  append_component( day, name, default_mod, dest );
}

static bool is_grouping_separator( unicode::code_point cp ) {
  using namespace unicode;
  //
  // XQuery 3.0 F&O: 4.6.1: a grouping-separator-sign is a non-alphanumeric
  // character, that is a character whose Unicode category is other than Nd,
  // Nl, No, Lu, Ll, Lt, Lm or Lo.
  //
  return !( is_category( cp, Nd )
         || is_category( cp, Nl )
         || is_category( cp, No )
         || is_category( cp, Lu )
         || is_category( cp, Ll )
         || is_category( cp, Lt )
         || is_category( cp, Lm )
         || is_category( cp, Lo )
  );
}

static void parse_first_modifier( zstring const &picture_str,
                                  zstring::const_iterator *i,
                                  modifier *mod, QueryLoc const &loc ) {
  zstring::const_iterator &j = *i;
  ascii::skip_whitespace( picture_str, &j );
  if ( j == picture_str.end() || *j == ',' ) {
    //
    // Assume that the ',' is the start of the width modifier (hence there is
    // neither a first nor second modifier).
    //
    return;
  }

  utf8_string<zstring const> const u_picture_str( picture_str );
  utf8_string<zstring const>::const_iterator u( u_picture_str.current( j ) );
  utf8_string<zstring> u_mod_first_string( mod->first_string );
  unicode::code_point cp = *u;

  if ( is_grouping_separator( cp ) ) {
    //
    // XQuery 3.0 F&O: 4.6.1: A grouping-separator-sign must not appear
    // at the start ... of the decimal-digit-pattern ....
    //
    throw XQUERY_EXCEPTION(
      err::FOFD1340,
      ERROR_PARAMS(
        picture_str,
        ZED( FOFD1340_NoGroupSepAtStart_3 ),
        unicode::printable_cp( cp )
      ),
      ERROR_LOC( loc )
    );
  }

  unicode::code_point zero[2];

  if ( cp == '#' || unicode::is_Nd( cp, &zero[0] ) ) {
    bool got_grouping_separator = false;
    bool got_mandatory_digit;

    if ( cp != '#' ) {
      got_mandatory_digit = true;
      mod->first = modifier::arabic;
    } else
      got_mandatory_digit = false;

    u_mod_first_string = *u;

    while ( ++u != u_picture_str.end() ) {
      cp = *u;
      if ( cp == '#' ) {
        if ( got_mandatory_digit ) {
          //
          // XQuery 3.0 F&O: 4.6.1: There may be zero or more optional-digit-
          // signs, and (if present) these must precede all mandatory-digit-
          // signs.
          //
          throw XQUERY_EXCEPTION(
            err::FOFD1340,
            ERROR_PARAMS(
              picture_str,
              ZED( FOFD1340_NoOptDigitAfterMandatory )
            ),
            ERROR_LOC( loc )
          );
        }
        got_grouping_separator = false;
      } else if ( unicode::is_Nd( cp, &zero[ got_mandatory_digit ] ) ) {
        if ( got_mandatory_digit && zero[1] != zero[0] ) {
          //
          // XQuery 3.0 F&O: 4.6.1: All mandatory-digit-signs within the format
          // token must be from the same digit family, where a digit family is
          // a sequence of ten consecutive characters in Unicode category Nd,
          // having digit values 0 through 9.
          //
          throw XQUERY_EXCEPTION(
            err::FOFD1340,
            ERROR_PARAMS(
              picture_str,
              ZED( FOFD1340_DigitNotSameFamily_34 ),
              unicode::printable_cp( cp ),
              unicode::printable_cp( zero[1] )
            ),
            ERROR_LOC( loc )
          );
        }
        got_grouping_separator = false;
        got_mandatory_digit = true;
      } else if ( cp == ']' )
        break;
      else if ( unicode::is_space( cp ) )
        continue;
      else if ( is_grouping_separator( cp ) ) {
        if ( got_grouping_separator ) {
          //
          // XQuery 3.0 F&O: 4.6.1: A grouping-separator-sign must not appear
          // ... adjacent to another grouping-separator-sign.
          //
          throw XQUERY_EXCEPTION(
            err::FOFD1340,
            ERROR_PARAMS(
              picture_str,
              ZED( FOFD1340_NoAdjacentGroupSep_3 ),
              unicode::printable_cp( cp )
            ),
            ERROR_LOC( loc )
          );
        }
        got_grouping_separator = true;
      } else
        break;

      u_mod_first_string += cp;
      if ( !mod->min_width )
        mod->min_width = 1;
      mod->max_width = ++mod->min_width;
    } // while
    if ( got_grouping_separator ) {
      //
      // XQuery 3.0 F&O: 4.6.1: A grouping-separator-sign must not appear
      // at the ... end of the decimal-digit-pattern ....
      //
      throw XQUERY_EXCEPTION(
        err::FOFD1340,
        ERROR_PARAMS(
          picture_str,
          ZED( FOFD1340_NoGroupSepAtEnd_3 ),
          unicode::printable_cp( cp )
        ),
        ERROR_LOC( loc )
      );
    }
    if ( !got_mandatory_digit ) {
      //
      // XQuery 3.0 F&O: 4.6.1: There must be at least one mandatory-digit-
      // sign.
      //
      throw XQUERY_EXCEPTION(
        err::FOFD1340,
        ERROR_PARAMS( picture_str, ZED( FOFD1340_MustBeOneMandatoryDigit ) ),
        ERROR_LOC( loc )
      );
    }
    mod->first_zero = zero[0];
    j = u.base();
  } else {
    switch ( *j ) {
      case 'A':
        mod->first = modifier::ALPHA;
        break;
      case 'a':
        mod->first = modifier::alpha;
        break;
      case 'I':
        mod->first = modifier::ROMAN;
        break;
      case 'i':
        mod->first = modifier::roman;
        break;
      case 'N':
        if ( ztd::peek( picture_str, j ) == 'n' )
          ++j, mod->first = modifier::Name;
        else
          mod->first = modifier::NAME;
        break;
      case 'n':
        mod->first = modifier::name;
        break;
      case 'W':
        if ( ztd::peek( picture_str, j ) == 'w' )
          ++j, mod->first = modifier::Words;
        else
          mod->first = modifier::WORDS;
        break;
      case 'w':
        mod->first = modifier::words;
        break;
      default:
        //
        // XQuery 3.0 F&O: 4.6.1: If an implementation does not support a
        // numbering sequence represented by the given token, it must use a
        // format token of 1.
        //
        mod->first = modifier::arabic;
    } // switch
  }
}

static void parse_second_modifier( zstring const &picture_str,
                                   zstring::const_iterator *i, modifier *mod,
                                   QueryLoc const &loc ) {
  zstring::const_iterator &j = *i;
  ascii::skip_whitespace( picture_str, &j );
  if ( j == picture_str.end() )
    return;
  switch ( *j ) {
    case 'c': mod->second_co = modifier::cardinal   ; break;
    case 'o': mod->second_co = modifier::ordinal    ; break;
    case 'a': mod->second_at = modifier::alphabetic ; ++j; return;
    case 't': mod->second_at = modifier::traditional; ++j; return;
    default : return;
  }
  if ( ++j == picture_str.end() )
    return;
  if ( *j == '(' ) {
    while ( true ) {
      if ( ++j == picture_str.end() )
        throw XQUERY_EXCEPTION(
          err::FOFD1340,
          ERROR_PARAMS( picture_str, ZED( CharExpected_3 ), ')' ),
          ERROR_LOC( loc )
        );
      if ( *j == ')' )
        break;
      mod->second_co_string += *j;
    } 
    ++j;
  }
}

static void parse_width_modifier( zstring const &picture_str,
                                  zstring::const_iterator *i, modifier *mod,
                                  QueryLoc const &loc ) {
  zstring::const_iterator &j = *i;

  ascii::skip_whitespace( picture_str, &j );
  if ( j == picture_str.end() || (*j != ',' && *j != ';') )
    return;
  ++j;
  ascii::skip_whitespace( picture_str, &j );
  if ( j == picture_str.end() )
    goto bad_width_modifier;
  if ( *j == '*' ) {
    mod->min_width = modifier::star;
    ++j;
  } else {
    try {
      mod->min_width = static_cast<modifier::width_type>(
        ztd::atoull( j, picture_str.end(), &j )
      );
    }
    catch ( std::exception const& ) {
      goto bad_width_modifier;
    }
  }

  mod->max_width = modifier::star;

  ascii::skip_whitespace( picture_str, &j );
  if ( j == picture_str.end() || *j != '-' )
    return;
  ++j;
  ascii::skip_whitespace( picture_str, &j );
  if ( j == picture_str.end() )
    goto bad_width_modifier;
  if ( *j == '*' )
    ++j;
  else {
    try {
      mod->max_width = static_cast<modifier::width_type>(
        ztd::atoull( j, picture_str.end(), &j )
      );
    }
    catch ( std::exception const& ) {
      goto bad_width_modifier;
    }
  }

  return;

bad_width_modifier:
  throw XQUERY_EXCEPTION(
    err::FOFD1340,
    ERROR_PARAMS( picture_str, ZED( FOFD1340_BadWidthModifier ) ),
    ERROR_LOC( loc )
  );
}

static int get_data_type( char component ) {
  switch ( component ) {
    case 'Y':
      return DateTime::YEAR_DATA;
    case 'M':
      return DateTime::MONTH_DATA;
    case 'D':
      return DateTime::DAY_DATA;
    case 'd': // day in year
      return DateTime::DAY_DATA;
    case 'F': // day of week
      return DateTime::DAY_DATA;
    case 'W': // week in year
      return DateTime::DAY_DATA;
    case 'w': // week in month
      return DateTime::DAY_DATA;
    case 'H': // hour in day (24 hours)
      return DateTime::HOUR_DATA;
    case 'h': // hour in half-day (12 hours)
      return DateTime::HOUR_DATA;
    case 'P': // am/pm marker
      return DateTime::HOUR_DATA;
    case 'm':
      return DateTime::MINUTE_DATA;
    case 's':
      return DateTime::SECONDS_DATA;
    case 'f': // fractional seconds
      return DateTime::FRACSECONDS_DATA;
    case 'Z': // timezone as a time offset from UTC, or if an alphabetic modifier is present the conventional name of a timezone (such as PST)
      return -1;
    case 'z': // timezone as a time offset using GMT, for example GMT+1
      return -1;
    case 'C': // calendar: the name or abbreviation of a calendar name
      return -1;
    case 'E': // era: the name of a baseline for the numbering of years, for example the reign of a monarch
      return -1;
    default:
      return -1;
  }
}

bool FnFormatDateTimeIterator::nextImpl( store::Item_t& result,
                                         PlanState &planState ) const {
  zstring picture_str, result_str, calendar_str, place_str;
  xs_dateTime dateTime;
  iso639_1::type lang = iso639_1::unknown;
  iso3166_1::type country = iso3166_1::unknown;
  bool in_variable_marker;
  store::Item_t item;
  PlanIteratorState *state;

  DEFAULT_STACK_INIT( PlanIteratorState, state, planState);

  if ( !consumeNext( item, theChildren[0].getp(), planState ) ) {
    // Got the empty sequence -- return same
    STACK_PUSH( false, state );
  } else {
    dateTime = item->getDateTimeValue();
    consumeNext( item, theChildren[1].getp(), planState );
    item->getStringValue2( picture_str );

    if ( theChildren.size() > 2 ) {
      consumeNext( item, theChildren[2].getp(), planState );
      locale::parse( item->getStringValue(), &lang, &country );

      consumeNext( item, theChildren[3].getp(), planState );
      item->getStringValue2( calendar_str );
      consumeNext( item, theChildren[4].getp(), planState );
      item->getStringValue2( place_str );
      // TODO: do something with calendar_str & place_str
    }

    if ( !lang || !locale::is_supported( lang, country ) ) {
      //
      // XQuery 3.0 F&O: 9.8.4.3: If the $language argument is omitted or is
      // set to an empty sequence, or if it is set to an invalid value or a
      // value that the implementation does not recognize, then the processor
      // uses the default language defined in the dynamic context.
      //
      planState.theLocalDynCtx->get_locale( &lang, &country );
    }

    char component;
    in_variable_marker = false;

    FOR_EACH( zstring, i, picture_str ) {
      if ( !in_variable_marker ) {
        switch ( *i ) {
          case '[':
            if ( ztd::peek( picture_str, i ) == '[' )
              ++i;
            else {
              component = 0;
              in_variable_marker = true;
              continue;
            }
            break;
          case ']':
            if ( ztd::peek( picture_str, i ) == ']' )
              ++i;
            break;
        }
        result_str += *i;
        continue;
      }

      if ( ascii::is_space( *i ) )
        continue;                       // ignore all whitespace

      switch ( *i ) {
        case ']':
          if ( !component )
            throw XQUERY_EXCEPTION(
              err::FOFD1340,
              ERROR_PARAMS( picture_str, ZED( FOFD1340_NoComponent ) ),
              ERROR_LOC( loc )
            );
          component = 0;
          in_variable_marker = false;
          continue;
        case 'C':
        case 'D':
        case 'd':
        case 'E':
        case 'F':
        case 'f':
        case 'H':
        case 'h':
        case 'M':
        case 'm':
        case 'P':
        case 's':
        case 'W':
        case 'w':
        case 'Y':
        case 'Z':
        case 'z':
          if ( component )
            throw XQUERY_EXCEPTION(
              err::FOFD1340,
              ERROR_PARAMS(
                picture_str, ZED( FOFD1340_MultipleComponent_3 ), *i
              ),
              ERROR_LOC( loc )
            );
          component = *i;
          break;
        default:
          throw XQUERY_EXCEPTION(
            err::FOFD1340,
            ERROR_PARAMS( picture_str, ZED( FOFD1340_BadComponent_3 ), *i ),
            ERROR_LOC( loc )
          );
      } // switch
      if ( ++i == picture_str.end() )
        goto eos;

      modifier mod;

      if ( *i != ']' ) {
        parse_first_modifier( picture_str, &i, &mod, loc );
        if ( i == picture_str.end() )
          goto eos;
        if ( *i != ']' ) {
          parse_second_modifier( picture_str, &i, &mod, loc );
          if ( i == picture_str.end() )
            goto eos;
          parse_width_modifier( picture_str, &i, &mod, loc );
          if ( i == picture_str.end() )
            goto eos;
        }
      }
      if ( *i == ']' )
        --i;

      int const data_type = get_data_type( component );
      if ( data_type != -1 && !DateTime::FACET_MEMBERS[facet_type][data_type] )
        throw XQUERY_EXCEPTION(
          err::FOFD1350, ERROR_PARAMS( component ), ERROR_LOC( loc )
        );

      switch ( component ) {
        case 'C': { // calendar
          modifier default_mod( mod );
          if ( !mod.is_set() )
            default_mod.first = modifier::name;
          append_string( "gregorian", default_mod, &result_str );
          break;
        }
        case 'D':
          append_number( dateTime.getDay(), mod, &result_str );
          break;
        case 'd':
          append_number( dateTime.getDayOfYear(), mod, &result_str );
          break;
        case 'E': { // era
          modifier default_mod( mod );
          if ( !mod.is_set() )
            default_mod.first = modifier::name;
          append_string(
            dateTime.getYear() < 0 ? "ad" : "bc", default_mod, &result_str
          );
          break;
        }
        case 'F': {
          modifier default_mod( mod );
          if ( !mod.is_set() )
            default_mod.first = modifier::name;
          append_weekday(
            dateTime.getDayOfWeek(), lang, country, default_mod, &result_str
          );
          break;
        }
        case 'f': // fractional seconds
          append_number(
            (long)(dateTime.getFractionalSeconds() * 1000.0 /
              DateTime::FRAC_SECONDS_UPPER_LIMIT),
            mod, &result_str
          );
          break;
        case 'H': // hour in day (24 hours)
          append_number( dateTime.getHours(), mod, &result_str );
          break;
        case 'h': // hour in half-day (12 hours)
          // Convert hour from:      0  1  ...  12  13  ...  23   0
          //                to:     12  1  ...  12   1  ...  11  12
          append_number( 1 + (11 + dateTime.getHours()) % 12, mod, &result_str );
          break;
        case 'M':
          append_month( dateTime.getMonth(), lang, country, mod, &result_str );
          break;
        case 'm': {
          modifier default_mod( mod );
          if ( !mod.is_set() )
            default_mod.min_width = default_mod.max_width = 2;
          append_number( dateTime.getMinutes(), default_mod, &result_str );
          break;
        }
        case 'P': {
          modifier default_mod( mod );
          if ( !mod.is_set() )
            default_mod.first = modifier::name;
          append_string(
            locale::get_time_ampm( dateTime.getHours() >= 12, lang, country ),
            default_mod, &result_str
          );
          break;
        }
        case 's': {
          modifier default_mod( mod );
          if ( !mod.is_set() )
            default_mod.min_width = default_mod.max_width = 2;
          append_number( dateTime.getIntSeconds(), default_mod, &result_str );
          break;
        }
        case 'W':
          append_number( dateTime.getWeekInYear(), mod, &result_str );
          break;
        case 'w':
          append_number( dateTime.getWeekInMonth(), mod, &result_str );
          break;
        case 'Y':
          append_year( std::abs( dateTime.getYear() ), mod, &result_str );
          break;
        case 'Z': // timezone as a time offset from UTC, or if an alphabetic modifier is present the conventional name of a timezone (such as PST)
          // deliberate fall-through
        case 'z': { // timezone as a time offset using GMT, for example GMT+1
          zstring tmp( "GMT" );
          tmp += dateTime.getTimezone().toString();
          append_string( tmp, mod, &result_str );
          break;
        }
      } // switch
    } // for

    if ( in_variable_marker )
eos:  throw XQUERY_EXCEPTION(
        err::FOFD1340,
        ERROR_PARAMS( picture_str, ZED( CharExpected_3 ), ']' ),
        ERROR_LOC( loc )
      );

    STACK_PUSH( GENV_ITEMFACTORY->createString( result, result_str ), state );
  }

  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
