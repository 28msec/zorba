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

#include <cstdlib>

#include "compiler/api/compilercb.h"
#include "context/dynamic_context.h"
#include "context/static_context.h"
#include "runtime/core/arithmetic_impl.h"
#include "runtime/visitors/planiter_visitor.h"
#include "store/api/item.h"
#include "store/api/item_factory.h"
#include "store/api/store.h"
#include "system/globalenv.h"
#include "types/casting.h"
#include "util/ascii_util.h"
#include "util/string_util.h"
#include "zorbatypes/datetime.h"
#include "zorbatypes/datetime/parse.h"
#include "zorbatypes/duration.h"
#include "zorbatypes/numconversions.h"
#include "zorbautils/locale.h"

#include "format_dateTime.h"

using namespace zorba::locale;

namespace zorba {

SERIALIZABLE_CLASS_VERSIONS(FnFormatDateTimeIterator)
NARY_ACCEPT(FnFormatDateTimeIterator);

///////////////////////////////////////////////////////////////////////////////

struct modifier {
  enum first_type {
    arabic,       // '1' : 0 1 2 ... 10 11 12 ...
    arabic0,      // '01': 00 01 02 ... 09 10 11 12 ... 99 100 101 ...
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
  second_co_type second_co;
  zstring second_co_string;
  second_at_type second_at;

  typedef unsigned long width_type;

  enum width_special_value {
    unspecified = -2,
    star = -1
    // >= 0 means explicitly specified width
  };

  width_type min_width;
  width_type max_width;

  modifier() {
    first = arabic;
    second_co = cardinal;
    second_at = no_second_at;
    min_width = max_width = unspecified;
  };
};

static void append_number( long n, modifier const &mod, zstring *s ) {
  switch ( mod.first ) {
    case modifier::arabic:
    case modifier::arabic0:
    case modifier::alpha:
    case modifier::ALPHA:
    case modifier::roman:
    case modifier::ROMAN:
      ;
    case modifier::words:
    case modifier::Words:
    case modifier::WORDS:
      ;
    case modifier::name:
    case modifier::Name:
    case modifier::NAME:
      ;
  }

#if 0
  zstring temp;

  if ( mod.first_string.size() > 0 && mod.first == modifier::arabic0 ) {
    ztd::to_string( n, &temp );
    while ( temp.size() < mod.first_string.size() )
      temp = "0" + temp;
  }
  else // "1" or fallback
  {
    ztd::to_string(n, &temp);
  }

  if ( mod.second_co == modifier::ordinal ) {
    long const n10 = n % 10;
    long const n100 = n % 100;

    if ( n10 == 1 && n100 != 11 )
      temp += "st";
    else if ( n10 == 2 && n100 != 12 )
      temp += "nd";
    else if ( n10 == 3 && n100 != 13 )
      temp += "rd";
    else
      temp += "th";
  }

  if ( mod.min_width > 0 )
    while ( temp.size() < (unsigned int)mod.min_width )
      temp = "0" + temp;

  str += temp;
#endif
}

static void pad_width( zstring const &s, modifier const &mod, zstring *dest ) {
  while ( (modifier::width_type)dest->size() < mod.max_width )
    *dest += ' ';
}

static bool append_string( zstring const &s, modifier const &mod,
                           zstring *dest ) {
  zstring temp;
  switch ( mod.first ) {
    case modifier::name:
      utf8::to_lower( s, &temp );
      break;
    case modifier::Name: {
      utf8::to_upper( s.substr( 0, 1 ), &temp );
      zstring temp2;
      utf8::to_lower( s.substr( 1 ), &temp2 );
      temp += temp2;
      break;
    }
    case modifier::NAME:
      utf8::to_upper( s, &temp );
      break;
    default:
      return false;
  }

  pad_width( temp, mod, dest );
  return true;
}

inline bool append_string( char const *s, modifier const &mod, zstring *dest ) {
  zstring const temp( s );
  return append_string( temp, mod, dest );
}

static void append_component( long n, zstring const &s, modifier const &mod,
                              zstring *dest ) {
  if ( !append_string( s, mod, dest ) )
    append_number( n, mod, dest );
}

static void append_year( long year, modifier const &mod, zstring *s ) {
#if 0
  append_number( destination, number, mod );

  if (mod.max_width >= 0) {
    if ( (unsigned int)mod.max_width > destination.size() )
      mod.max_width = destination.size();

    destination = destination.substr(destination.size() - mod.max_width, mod.max_width);
  }
#endif
}

static void append_month( long m, iso639_1::type lang, iso3166_1::type country,
                          modifier const &mod, zstring *dest ) {
  zstring name( locale::get_month_name( m - 1 ), lang, country );
  utf8_string<zstring> u_name( name );

  if ( mod.max_width > 0 && u_name.size() > (unsigned int)mod.max_width )
    u_name = u_name.substr( 0, mod.max_width );

  append_component( m, name, mod, dest );
}

static void append_weekday( long d, iso639_1::type lang,
                            iso3166_1::type country, modifier &mod,
                            zstring *dest ) {
  zstring name( locale::get_weekday_name( d, lang, country ) );
  utf8_string<zstring> u_name( name );

  if ( mod.max_width > 0 && u_name.size() > (unsigned int)mod.max_width )
    u_name = u_name.substr( 0, mod.max_width );

#if 0
  if (mod.first.size() == 0)
    mod.first = "n"; // Default for day of week is "n"
#endif

  append_component( d, name, mod, dest );
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
  if ( j == picture_str.end() )
    return;

  utf8_string<zstring const> const u_picture_str( picture_str );
  utf8_string<zstring const>::const_iterator u( *i );
  utf8_string<zstring> u_mod_first_string( mod->first_string );
  unicode::code_point cp = *u;

  if ( is_grouping_separator( cp ) ) {
    //
    // XQuery 3.0 F&O: 4.6.1: A grouping-separator-sign must not appear
    // at the start ... of the decimal-digit-pattern ....
    //
    throw XQUERY_EXCEPTION(
      err::XTDE1340, ERROR_PARAMS( picture_str ), ERROR_LOC( loc )
    );
  }

  bool got_grouping_separator = false;
  bool got_mandatory_digit = false;
  unicode::code_point zero[2];

  if ( cp == '#' || unicode::is_Nd( cp, &zero[0] ) ) {
    if ( cp != '#' ) {
      got_mandatory_digit = true;
      mod->first = cp == zero[0] ? modifier::arabic0 : modifier::arabic;
    }
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
            err::XTDE1340, ERROR_PARAMS( picture_str ), ERROR_LOC( loc )
          );
        }
        got_grouping_separator = false;
      } else if ( unicode::is_Nd( cp, &zero[1] ) ) {
        if ( zero[0] != zero[1] ) {
          //
          // XQuery 3.0 F&O: 4.6.1: All mandatory-digit-signs within the format
          // token must be from the same digit family, where a digit family is
          // a sequence of ten consecutive characters in Unicode category Nd,
          // having digit values 0 through 9.
          //
          throw XQUERY_EXCEPTION(
            err::XTDE1340, ERROR_PARAMS( picture_str ), ERROR_LOC( loc )
          );
        }
        got_grouping_separator = false;
        got_mandatory_digit = true;
      } else if ( is_grouping_separator( cp ) ) {
        if ( got_grouping_separator ) {
          //
          // XQuery 3.0 F&O: 4.6.1: A grouping-separator-sign must not appear
          // ... adjacent to another grouping-separator-sign.
          //
          throw XQUERY_EXCEPTION(
            err::XTDE1340, ERROR_PARAMS( picture_str ), ERROR_LOC( loc )
          );
        }
        got_grouping_separator = true;
      }
      u_mod_first_string += cp;
    } // while
    if ( got_grouping_separator ) {
      //
      // XQuery 3.0 F&O: 4.6.1: A grouping-separator-sign must not appear
      // at the ... end of the decimal-digit-pattern ....
      //
      throw XQUERY_EXCEPTION(
        err::XTDE1340, ERROR_PARAMS( picture_str ), ERROR_LOC( loc )
      );
    }
    if ( !got_mandatory_digit ) {
      //
      // XQuery 3.0 F&O: 4.6.1: There must be at least one mandatory-digit-
      // sign.
      //
      throw XQUERY_EXCEPTION(
        err::XTDE1340, ERROR_PARAMS( picture_str ), ERROR_LOC( loc )
      );
    }
  } else {
    switch ( *u ) {
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
        if ( ztd::peek( picture_str, j ) == 'n' ) {
          ++j;
          mod->first = modifier::Name;
        } else
          mod->first = modifier::NAME;
        break;
      case 'n':
        mod->first = modifier::name;
        break;
      case 'W':
        if ( ztd::peek( picture_str, j ) == 'w' ) {
          ++j;
          mod->first = modifier::Words;
        } else
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
        break;
    } // switch
  }

done:
  j = u.base();
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
          err::XTDE1340, ERROR_PARAMS( picture_str ), ERROR_LOC( loc )
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
    throw XQUERY_EXCEPTION(
      err::XTDE1340, ERROR_PARAMS( picture_str ), ERROR_LOC( loc )
    );
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
      throw XQUERY_EXCEPTION(
        err::XTDE1340, ERROR_PARAMS( picture_str ), ERROR_LOC( loc )
      );
    }
  }

  mod->max_width = modifier::star;

  ascii::skip_whitespace( picture_str, &j );
  if ( j == picture_str.end() || *j != '-' )
    return;
  ++j;
  ascii::skip_whitespace( picture_str, &j );
  if ( j == picture_str.end() )
    throw XQUERY_EXCEPTION(
      err::XTDE1340, ERROR_PARAMS( picture_str ), ERROR_LOC( loc )
    );
  if ( *j == '*' )
    ++j;
  else {
    try {
      mod->max_width = static_cast<modifier::width_type>(
        ztd::atoull( j, picture_str.end(), &j )
      );
    }
    catch ( std::exception const& ) {
      throw XQUERY_EXCEPTION(
        err::XTDE1340, ERROR_PARAMS( picture_str ), ERROR_LOC( loc )
      );
    }
  }
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
  zstring lang_str, calendar_str, place_str;
  zstring picture_str, result_str;
  iso639_1::type lang;
  iso3166_1::type country;
  store::Item_t item;
  xs_dateTime dateTime;
  PlanIteratorState* state;
  bool in_variable_marker;

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
      lang_str = item->getStringValue();

      if ( !locale::parse( lang_str, &lang, &country ) || !lang ||
           !locale::is_supported( lang, country ) ) {
        // TODO: use lang in dynamic context
      }

      consumeNext( item, theChildren[3].getp(), planState );
      calendar_str = item->getStringValue();
      consumeNext( item, theChildren[4].getp(), planState );
      place_str = item->getStringValue();
    }

    in_variable_marker = false;

    FOR_EACH( zstring, i, picture_str ) {

      if ( !in_variable_marker ) {
        switch ( *i ) {
          case '[':
            if ( ztd::peek( picture_str, i ) == '[' )
              ++i;
            else {
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

      char component = 0;
      modifier mod;

      switch ( *i ) {
        case ' ':
        case '\f':
        case '\n':
        case '\r':
        case '\t':
        case '\v':
          continue; // ignore whitespace
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
              err::XTDE1340, ERROR_PARAMS( picture_str ), ERROR_LOC( loc )
            );
          component = *i;
          break;
        case ']':
          in_variable_marker = false;
          continue;
        default:
          throw XQUERY_EXCEPTION(
            err::XTDE1340, ERROR_PARAMS( picture_str ), ERROR_LOC( loc )
          );
      }

      parse_first_modifier( picture_str, &i, &mod, loc );
      parse_second_modifier( picture_str, &i, &mod, loc );
      parse_width_modifier( picture_str, &i, &mod, loc );

      int const data_type = get_data_type( component );
      if ( data_type != -1 && !DateTime::FACET_MEMBERS[facet_type][data_type] )
        throw XQUERY_EXCEPTION( err::XTDE1350, ERROR_LOC( loc ) );

      switch ( component ) {
        case 'C': // calendar
#if 0
          if ( mod.first.empty() )
            mod.first += "n";
#endif
          append_string( "gregorian", mod, &result_str );
          break;
        case 'D':
          append_number( dateTime.getDay(), mod, &result_str );
          break;
        case 'd':
          append_number( dateTime.getDayOfYear(), mod, &result_str );
          break;
        case 'E': // era
#if 0
          if ( mod.first.empty() )
            mod.first += "n";
#endif
          append_string( dateTime.getYear() < 0 ? "ad" : "bc", mod, &result_str );
          break;
        case 'F':
          append_weekday(
            dateTime.getDayOfWeek(), lang, country, mod, &result_str
          );
          break;
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
        case 'm':
#if 0
          if (mod.first.empty())
            mod.first += "01";
#endif
          append_number( dateTime.getMinutes(), mod, &result_str );
          break;
        case 'P':
#if 0
          if (mod.first.empty())
            mod.first = "n";  // Default for the AM/PM marker is "n"
#endif
          append_string(
            locale::get_time_ampm( dateTime.getHours() >= 12, lang, country ),
            mod, &result_str
          );
          break;
        case 's':
#if 0
          if (mod.first.empty())
            mod.first += "01";
#endif
          append_number( dateTime.getIntSeconds(), mod, &result_str );
          break;
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
          zstring temp( "GMT" );
          temp += dateTime.getTimezone().toString();
          append_string( temp, mod, &result_str );
          break;
        }
      } // switch
    } // for

    STACK_PUSH( GENV_ITEMFACTORY->createString( result, result_str ), state );
  }

  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
