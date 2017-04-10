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
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <sstream>

// Zorba
#include "context/dynamic_context.h"

#include "runtime/visitors/planiter_visitor.h"

#include "store/api/item.h"
#include "store/api/item_factory.h"
#include "store/api/store.h"

#include "system/globalenv.h"

#include "util/ascii_util.h"
#include "util/locale.h"
#include "util/stream_util.h"
#include "util/string_util.h"
#include "util/time_util.h"
#include "util/utf8_util.h"
#include "util/xml_util.h"

#include "zorbatypes/datetime.h"
#include "zorbatypes/zstring.h"

// local
#include "format_dateTime.h"

using namespace std;
using namespace zorba::locale;
using namespace zorba::time;

namespace zorba {

SERIALIZABLE_CLASS_VERSIONS(FnFormatDateTimeIterator)
NARY_ACCEPT(FnFormatDateTimeIterator);
DEF_GET_NAME_AS_STRING(FnFormatDateTimeIterator)

///////////////////////////////////////////////////////////////////////////////

/**
 * Holds presentation modifier data.
 */
struct modifier {
  enum first_type {
    arabic,       // '1' : 0 1 2 ... 10 11 12 ...
    alpha,        // 'a' : a b c ... z aa ab ac ...
    ALPHA,        // 'A' : A B C ... Z AA AB AC ...
    roman,        // 'i' : i ii iii iv v vi vii viii ix x ...
    ROMAN,        // 'I' : I II III IV V VI VII VIII IX X ...
    name,         // 'n' : name
    Name,         // 'Nn': Name
    NAME,         // 'N' : NAME
    words,        // 'w' : one two three four ...
    Words,        // 'Ww': One Two Three Four ...
    WORDS,        // 'W' : ONE TWO THREE FOUR ...
    military_tz   // 'Z' : A B C ... J ... X Y Z
  };

  enum co_type {
    no_second_co,
    cardinal,     // 'c': 7 or seven
    ordinal       // 'o': 7th or seventh
  };

  enum at_type {
    no_second_at,
    alphabetic,   // 'a'
    traditional   // 't'
  };

  typedef unsigned width_type;

  struct {
    bool parsed;
    first_type type;
    zstring format;
    bool has_grouping_separators;
    unicode::code_point zero;
  } first;

  struct {
    co_type co;
    zstring co_string;
    at_type at;
  } second;

  width_type min_width;
  width_type max_width;

  //
  // This stuff isn't part of the "presentation modifier" as discussed in the
  // XQuery F&O 3.0 spec, but this is a convenient place to put it nonetheless.
  //
  iso639_1::type lang;
  bool lang_is_fallback;
  iso3166_1::type country;
  calendar::type cal;
  bool cal_is_fallback;

  void append_if_fallback_lang( zstring *s ) const {
    if ( lang_is_fallback ) {
      //
      // XQuery F&O 3.0: 9.8.4.3: If the fallback representation uses a
      // different language from that requested, the output string must
      // identify the language actually used, for example by prefixing the
      // string with [Language: Y] (where Y is the language actually used)
      // localized in an implementation-dependent way.
      //
      ostringstream oss;
      // TODO: localize "Language"
      oss << "[Language: " << lang << ']';
      *s += oss.str();
    }
  }

  bool gt_max_width( width_type n ) const {
    return max_width > 0 && n > max_width;
  }

  zstring const& left_pad_zero( zstring *s ) const {
    if ( min_width )
      utf8::left_pad( s, min_width, first.zero );
    return *s;
  }

  zstring const& right_pad_space( zstring *s ) const {
    if ( min_width )
      utf8::right_pad( s, min_width, ' ' );
    return *s;
  }

  void set_default_width( width_type width ) {
    if ( !(first.parsed || min_width || max_width) )
      min_width = max_width = width;
  }

  modifier() {
    first.parsed = false;
    first.type = arabic;
    first.has_grouping_separators = false;
    first.zero = '0';
    second.co = cardinal;
    second.at = no_second_at;
    min_width = max_width = 0;
  };

  // default modifier(modifier const&) is fine
  // default modifier& operator=(modifier const&) is fine
};

///////////////////////////////////////////////////////////////////////////////

static void append_number( int n, modifier const &mod, zstring *dest ) {
  switch ( mod.first.type ) {
    case modifier::arabic: {
      utf8::itou_buf_type buf;
      zstring tmp( utf8::itou( n, buf, mod.first.zero ) );
      if ( mod.second.co == modifier::ordinal )
        tmp += ztd::ordinal( n );
      *dest += mod.left_pad_zero( &tmp );
      break;
    }

    case modifier::alpha:
    case modifier::ALPHA: {
      zstring tmp( ztd::alpha( n, mod.first.type == modifier::ALPHA ) );
      *dest += mod.right_pad_space( &tmp );
      break;
    }

    case modifier::roman:
    case modifier::ROMAN: {
      ostringstream oss;
      if ( mod.first.type == modifier::ROMAN )
        oss << uppercase;
      oss << roman( n );
      zstring tmp( oss.str() );
      *dest += mod.right_pad_space( &tmp );
      break;
    }

    case modifier::words: {
      zstring tmp( ztd::english( n, mod.second.co == modifier::ordinal ) );
      *dest += mod.right_pad_space( &tmp );
      break;
    }

    case modifier::Words: {
      zstring tmp( ztd::english( n, mod.second.co == modifier::ordinal ) );
      std::transform( tmp.begin(), tmp.end(), tmp.begin(), ascii::to_title() );
      *dest += mod.right_pad_space( &tmp );
      break;
    }

    case modifier::WORDS: {
      zstring tmp( ztd::english( n, mod.second.co == modifier::ordinal ) );
      ascii::to_upper( tmp );
      *dest += mod.right_pad_space( &tmp );
      break;
    }

    default:
      /* handled elsewhere */;
  }
}

static void append_fractional_seconds( int n, modifier const &mod,
                                       zstring *dest ) {
  switch ( mod.first.type ) {
    case modifier::arabic:
      if ( mod.min_width || mod.max_width ) {
        if ( mod.max_width ) {
          double const f = (double)n / DateTime::FRAC_SECONDS_UPPER_LIMIT;
          double const p = ::pow( (double)10, (double)mod.max_width );
          n = (int)( f * p + 0.5 );
        } else
          n = (int)( n * 1000.0 / DateTime::FRAC_SECONDS_UPPER_LIMIT );

        ascii::itoa_buf_type buf;
        zstring tmp( ascii::itoa( n, buf ) );

        if ( tmp.size() < mod.min_width )
          ascii::right_pad( &tmp, mod.min_width, '0' );
        else if ( mod.min_width > 0 )
          while ( tmp.size() > mod.min_width &&
                  tmp[ tmp.size() - 1 ] == '0' ) {
            tmp = tmp.substr( 0, tmp.size() - 1 );
          }
        *dest += tmp;
        break;
      }
      n = (int)( n * 1000.0 / DateTime::FRAC_SECONDS_UPPER_LIMIT );
      // no break;
    default:
      append_number( n, mod, dest );
  }
}

static void append_string( zstring const &s, modifier const &mod,
                           zstring *dest ) {
  zstring tmp;
  switch ( mod.first.type ) {
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
      break;
  }
  *dest += mod.right_pad_space( &tmp );
}

static void append_month( unsigned mon, modifier const &mod, zstring *dest ) {
  modifier mod_copy( mod );
  switch ( mod.first.type ) {
    case modifier::name:
    case modifier::Name:
    case modifier::NAME: {
      zstring name( locale::get_month_name( mon, mod.lang, mod.country ) );
      if ( !name.empty() ) {
        utf8_string<zstring> u_name( name );
        if ( mod.gt_max_width( u_name.size() ) ) {
          //
          // XQuery F&O 3.0: 9.8.4.1: If the full representation of the value
          // exceeds the specified maximum width, then the processor should
          // attempt to use an alternative shorter representation that fits
          // within the maximum width.  Where the presentation modifier is N,
          // n, or Nn, this is done by abbreviating the name, using either
          // conventional abbreviations if available, or crude right-truncation
          // if not.
          //
          zstring abbr( locale::get_month_abbr( mon, mod.lang, mod.country ) );
          if ( !abbr.empty() ) {
            utf8_string<zstring> u_abbr( abbr );
            if ( mod.gt_max_width( u_abbr.size() ) )
              u_abbr = u_abbr.substr( 0, mod.max_width );
            name = abbr;
          } else
            u_name = u_name.substr( 0, mod.max_width );
        }
        mod.append_if_fallback_lang( dest );
        append_string( name, mod, dest );
        break;
      }
      mod_copy.first.type = modifier::arabic;
      mod_copy.first.format.clear();
      // no break;
    }
    default:
      int const new_mon = calendar::convert_mon_to( mon, mod.cal );
      if ( mod.cal_is_fallback || new_mon == -1 ) {
        //
        // Ibid: If the fallback representation uses a different calendar from
        // that requested, the output string must identify the calendar
        // actually used, for example by prefixing the string with [Calendar:
        // X] (where X is the calendar actually used), localized as appropriate
        // to the requested language.
        //
        ostringstream oss;
        // TODO: localize "Calendar"
        oss << "[Calendar: "
            << (new_mon == -1 ? calendar::get_default() : mod.cal) << ']';
        *dest += oss.str();
      } else
        mon = new_mon;
      append_number( mon + 1, mod_copy, dest );
  }
}

static void append_timezone( char component, TimeZone const &tz,
                             modifier const &mod, zstring *dest ) {
  ascii::itoa_buf_type buf;
  zstring format, tmp;
  bool has_grouping_separators;

  if ( mod.first.format.empty() ) {
    format = "01:01";
    has_grouping_separators = true;
  } else {
    format = mod.first.format;
    has_grouping_separators = mod.first.has_grouping_separators;
  }

  int hour = tz.getHours();
  int const min  = std::abs( tz.getMinutes() );

  switch ( mod.first.type ) {
    case modifier::NAME:
      //
      // XQuery F&O 3.0: 9.8.4.2: If the first presentation modifier is N, then
      // the timezone is output (where possible) as a timezone name, for
      // example EST or CET. The same timezone offset has different names in
      // different places; it is therefore recommended that this option should
      // be used only if a country code or Olson timezone name is supplied in
      // the $place argument. In the absence of this information, the
      // implementation may apply a default, for example by using the timezone
      // names that are conventional in North America. If no timezone name can
      // be identified, the timezone offset is output using the fallback format
      // +01:01.
      //
      if ( !min )
        switch ( hour ) {
          case  0: tmp += "GMT"; goto append;
          case -5: tmp += "EST"; goto append;
          case -6: tmp += "CST"; goto append;
          case -7: tmp += "MST"; goto append;
          case -8: tmp += "PST"; goto append;
        }
      // TODO: use Olson timezone names
      goto fallback;

    case modifier::military_tz:
      //
      // Ibid: If the first presentation modifier is Z, then the timezone is
      // formatted as a military timezone letter, using the convention Z =
      // +00:00, A = +01:00, B = +02:00, ..., M = +12:00, N = -01:00, O =
      // -02:00, ... Y = -12:00.
      //
      if ( !tz ) {
        //
        // Ibid: The letter J (meaning local time) is used in the case of a
        // value that does not specify a timezone offset.
        //
        tmp += 'J';
        break;
      }
      if ( hour >= -12 && hour <= 12 && !min ) {
        tmp += time::get_military_tz( hour );
        break;
      }
      //
      // Ibid: Timezone offsets that have no representation in this system
      // (for example Indian Standard Time, +05:30) are output as if the
      // format 01:01 had been requested.
      //
      // no break;

fallback:
      format = "01:01";
      has_grouping_separators = true;
      // no break;

    default:
      if ( component == 'z' ) {
        //
        // Ibid: When the component specifier is z, the output is the same as
        // for component specifier Z, except that it is prefixed by the
        // characters GMT or some localized equivalent. The prefix is omitted,
        // however, in cases where the timezone is identified by name rather
        // than by a numeric offset from UTC.
        //
        tmp = "GMT";
      }

      if ( mod.second.at == modifier::traditional && !hour && !min ) {
        //
        // Ibid: If the first presentation modifier is numeric, in any of the
        // above formats, and the second presentation modifier is t, then a
        // zero timezone offset (that is, UTC) is output as Z instead of a
        // signed numeric value.
        //
        tmp += 'Z';
        break;
      }

      if ( tz < 0 )
        tmp += '-', hour = std::abs( hour );
      else
        tmp += '+';

      if ( has_grouping_separators ) {
        //
        // Ibid: If the first presentation modifier is numeric with a grouping-
        // separator (for example 1:01 or 01.01), then the timezone offset is
        // output in hours and minutes, separated by the grouping separator,
        // even if the number of minutes is zero: for example +5:00 or +10.30.
        //
        int grouping_separators = 0;
        bool got_digit = false;
        int hm_width[] = { 0, 0 };      // hour/minute widths
        utf8_string<zstring const> const u_format( format );
        utf8_string<zstring> u_tmp( tmp );

        FOR_EACH( utf8_string<zstring const>, i, u_format ) {
          unicode::code_point const cp = *i;
          if ( unicode::is_Nd( cp ) ) {
            got_digit = true;
            if ( grouping_separators < 2 )
              ++hm_width[ grouping_separators ];
            continue;
          }
          if ( got_digit && unicode::is_grouping_separator( cp ) ) {
            if ( ++grouping_separators == 1 ) {
              zstring tmp2( utf8::itou( hour, buf, mod.first.zero ) );
              tmp += utf8::left_pad( &tmp2, hm_width[0], mod.first.zero );
            }
          } else if ( grouping_separators )
            grouping_separators = 99;
          u_tmp += cp;
        }

        if ( hm_width[1] ) {
          zstring tmp2( utf8::itou( min, buf, mod.first.zero ) );
          tmp += utf8::left_pad( &tmp2, hm_width[1], mod.first.zero );
        }
      } else {
        utf8_string<zstring const> const u_format( format );
        utf8_string<zstring const>::size_type const u_size( u_format.size() );

        if ( u_size <= 2 ) {
          //
          // Ibid: If the first presentation modifier is numeric and comprises
          // one or two digits with no grouping-separator (for example 1 or
          // 01), then the timezone is formatted as a displacement from UTC in
          // hours, preceded by a plus or minus sign: for example -5 or +03. If
          // the actual timezone offset is not an integral number of hours,
          // then the minutes part of the offset is appended, separated by a
          // colon: for example +10:30 or -1:15.
          //
          zstring tmp2( utf8::itou( hour, buf, mod.first.zero ) );
          tmp += utf8::left_pad( &tmp2, u_size, mod.first.zero );
          if ( min ) {
            tmp2 = utf8::itou( min, buf, mod.first.zero );
            tmp += ':';
            tmp += utf8::left_pad( &tmp2, 2, mod.first.zero );
          }
          break;
        }
        if ( u_size <= 4 ) {
          //
          // Ibid: If the first presentation modifier is numeric and comprises
          // three or four digits with no grouping-separator, for example 001
          // or 0001, then the timezone offset is shown in hours and minutes
          // with no separator, for example -0500 or +1030.
          //
          int const hhmm = hour * 100 + min;
          zstring tmp2( utf8::itou( hhmm, buf, mod.first.zero ) );
          tmp += utf8::left_pad( &tmp2, u_size, mod.first.zero );
          break;
        }
      } // else
  } // switch

append:
  *dest += tmp;
}

static void append_weekday( unsigned mday, unsigned mon, unsigned year,
                            modifier const &mod, zstring *dest ) {
  int wday = time::calc_wday( mday, mon, year );

  modifier mod_copy( mod );
  if ( !mod.first.parsed )
    mod_copy.first.type = modifier::name;

  switch ( mod_copy.first.type ) {
    case modifier::name:
    case modifier::Name:
    case modifier::NAME: {
      zstring name( locale::get_weekday_name( wday, mod.lang, mod.country ) );
      if ( !name.empty() ) {
        utf8_string<zstring> u_name( name );
        if ( mod.gt_max_width( u_name.size() ) ) {
          //
          // XQuery F&O 3.0: 9.8.4.1: If the full representation of the value
          // exceeds the specified maximum width, then the processor should
          // attempt to use an alternative shorter representation that fits
          // within the maximum width.  Where the presentation modifier is N,
          // n, or Nn, this is done by abbreviating the name, using either
          // conventional abbreviations if available, or crude right-truncation
          // if not.
          //
          zstring abbr(
            locale::get_weekday_abbr( wday, mod.lang, mod.country )
          );
          if ( !abbr.empty() ) {
            utf8_string<zstring> u_abbr( abbr );
            if ( mod.gt_max_width( u_abbr.size() ) )
              u_abbr = u_abbr.substr( 0, mod.max_width );
            name = abbr;
          } else
            u_name = u_name.substr( 0, mod.max_width );
        }
        mod.append_if_fallback_lang( dest );
        append_string( name, mod_copy, dest );
        break;
      }
      mod_copy.first.type = modifier::arabic;
      mod_copy.first.format.clear();
      // no break;
    }
    default: {
      int const new_wday = calendar::convert_wday_to( wday, mod.cal );
      if ( mod.cal_is_fallback || new_wday == -1 ) {
        //
        // Ibid: If the fallback representation uses a different calendar from
        // that requested, the output string must identify the calendar
        // actually used, for example by prefixing the string with [Calendar:
        // X] (where X is the calendar actually used), localized as appropriate
        // to the requested language.
        //
        ostringstream oss;
        // TODO: localize "Calendar"
        oss << "[Calendar: "
            << (new_wday == -1 ? calendar::get_default() : mod.cal) << ']';
        *dest += oss.str();
      } else
        wday = new_wday;
      append_number( wday, mod_copy, dest );
    }
  }
}

static void append_week_in_month( unsigned mday, unsigned mon, unsigned year,
                                  modifier const &mod, zstring *dest ) {
  int week = calendar::calc_week_in_month( mday, mon, year, mod.cal );
  if ( week == -1 ) {
    week = calendar::calc_week_in_month( mday, mon, year, calendar::ISO );
    ostringstream oss;
    // TODO: localize "Calendar"
    oss << "[Calendar: " << calendar::string_of[ calendar::ISO ] << ']';
    *dest += oss.str();
  }
  append_number( week, mod, dest );
}

static void append_week_in_year( unsigned mday, unsigned mon, unsigned year,
                                 modifier const &mod, zstring *dest ) {
  int week = calendar::calc_week_in_year( mday, mon, year, mod.cal );
  if ( week == -1 ) {
    week = calendar::calc_week_in_year( mday, mon, year, calendar::ISO );
    ostringstream oss;
    // TODO: localize "Calendar"
    oss << "[Calendar: " << calendar::string_of[ calendar::ISO ] << ']';
    *dest += oss.str();
  }
  append_number( week, mod, dest );
}

static void append_year( int year, modifier const &mod, zstring *s ) {
  zstring tmp;
  append_number( year, mod, &tmp );

  if ( mod.first.type == modifier::arabic ) {
    utf8_string<zstring> u_tmp( tmp );
    utf8_string<zstring>::size_type const u_size = u_tmp.size();
    if ( mod.gt_max_width( u_size ) ) {
      //
      // XQuery F&O 3.0: 9.8.4.1: If the full representation of the value
      // exceeds the specified maximum width, then the processor should attempt
      // to use an alternative shorter representation that fits within the
      // maximum width.  ... In the case of the year component, setting
      // max-width requests omission of high-order digits from the year, for
      // example, if max-width is set to 2 then the year 2003 will be output as
      // 03.
      //
      u_tmp = u_tmp.substr( u_size - mod.max_width );
    }
  }
  *s += tmp;
}

static void parse_first_modifier( zstring const &picture_str,
                                  zstring::const_iterator *i,
                                  modifier *mod, QueryLoc const &loc ) {
  zstring::const_iterator &j = *i;
  ascii::skip_space( picture_str, &j );
  if ( j == picture_str.end() || *j == ',' ) {
    //
    // Assume that the ',' is the start of the width modifier (hence there is
    // neither a first nor second modifier).
    //
    return;
  }

  utf8_string<zstring const> const u_picture_str( picture_str );
  utf8_string<zstring const>::const_iterator u( u_picture_str.current( j ) );
  utf8_string<zstring> u_mod_format( mod->first.format );
  unicode::code_point cp = *u;

  if ( cp != '#' && unicode::is_grouping_separator( cp ) ) {
    //
    // XQuery F&O 3.0: 4.6.1: A grouping-separator-sign must not appear
    // at the start ... of the decimal-digit-pattern ....
    //
    throw XQUERY_EXCEPTION(
      err::FOFD1340,
      ERROR_PARAMS(
        picture_str,
        ZED( FOFD1340_Picture ),
        ZED( FOFD1340_NoGroupSepAtStart_4 ),
        unicode::printable_cp( cp )
      ),
      ERROR_LOC( loc )
    );
  }

  //
  // Because of:
  //
  //    Ibid: if a variable marker contains one or more commas, then the last
  //    comma is treated as introducing the width modifier, and all others are
  //    treated as grouping separators.
  //
  // we have to count the number of commas in order to know when we've reached
  // the last one.
  //
  int commas = 0;
  for ( zstring::const_iterator c( *i ); c != picture_str.end(); ++c )
    if ( *c == ',' )
      ++commas;

  unicode::code_point zero[2];

  if ( cp == '#' || unicode::is_Nd( cp, &zero[0] ) ) {
    bool got_grouping_separator = false;
    bool got_mandatory_digit = cp != '#';

    u_mod_format = *u;
    while ( ++u != u_picture_str.end() ) {
      cp = *u;
      if ( cp == '#' ) {
        if ( got_mandatory_digit ) {
          //
          // Ibid: There may be zero or more optional-digit-signs, and (if
          // present) these must precede all mandatory-digit-signs.
          //
          throw XQUERY_EXCEPTION(
            err::FOFD1340,
            ERROR_PARAMS(
              picture_str,
              ZED( FOFD1340_Picture ),
              ZED( FOFD1340_NoOptDigitAfterMandatory )
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
              err::FOFD1340,
              ERROR_PARAMS(
                picture_str,
                ZED( FOFD1340_Picture ),
                ZED( FOFD1340_DigitNotSameFamily_45 ),
                unicode::printable_cp( cp ),
                unicode::printable_cp( zero[1] )
              ),
              ERROR_LOC( loc )
            );
          }
          //
          // Ibid: A format token containing more than one digit, such as 001
          // or 9999, sets the minimum and maximum width to the number of
          // digits appearing in the format token.
          //
          if ( !mod->min_width )
            mod->min_width = mod->max_width = 2;
          else
            mod->min_width = ++mod->max_width;
        } else
          got_mandatory_digit = true;
        got_grouping_separator = false;
      } else if ( cp == ';' || cp == ']' )
        break;
      else if ( unicode::is_space( cp ) )
        continue;
      else if ( unicode::is_grouping_separator( cp ) ) {
        if ( cp == ',' && !--commas ) {
          //
          // Ibid: if a variable marker contains one or more commas, then the
          // last comma is treated as introducing the width modifier, and all
          // others are treated as grouping separators.
          //
          break;
        }
        if ( got_grouping_separator ) {
          //
          // Ibid: A grouping-separator-sign must not appear ... adjacent to
          // another grouping-separator-sign.
          //
          throw XQUERY_EXCEPTION(
            err::FOFD1340,
            ERROR_PARAMS(
              picture_str,
              ZED( FOFD1340_Picture ),
              ZED( FOFD1340_NoAdjacentGroupSep_4 ),
              unicode::printable_cp( cp )
            ),
            ERROR_LOC( loc )
          );
        }
        got_grouping_separator = true;
        mod->first.has_grouping_separators = true;
      } else
        break;

      u_mod_format += cp;
    } // while
    if ( got_grouping_separator ) {
      //
      // Ibid: A grouping-separator-sign must not appear at the ... end of the
      // decimal-digit-pattern ....
      //
      throw XQUERY_EXCEPTION(
        err::FOFD1340,
        ERROR_PARAMS(
          picture_str,
          ZED( FOFD1340_Picture ),
          ZED( FOFD1340_NoGroupSepAtEnd_4 ),
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
        err::FOFD1340,
        ERROR_PARAMS(
          picture_str,
          ZED( FOFD1340_Picture ),
          ZED( FOFD1340_MustBeOneMandatoryDigit )
        ),
        ERROR_LOC( loc )
      );
    }
    mod->first.zero = zero[0];
    j = u.base();
  } else {
    switch ( *j++ ) {
      case 'A':
        mod->first.type = modifier::ALPHA;
        break;
      case 'a':
        mod->first.type = modifier::alpha;
        break;
      case 'I':
        mod->first.type = modifier::ROMAN;
        break;
      case 'i':
        mod->first.type = modifier::roman;
        break;
      case 'N':
        if ( j != picture_str.end() && *j == 'n' )
          mod->first.type = modifier::Name, ++j;
        else
          mod->first.type = modifier::NAME;
        break;
      case 'n':
        mod->first.type = modifier::name;
        break;
      case 'W':
        if ( j != picture_str.end() && *j == 'w' )
          mod->first.type = modifier::Words, ++j;
        else
          mod->first.type = modifier::WORDS;
        break;
      case 'w':
        mod->first.type = modifier::words;
        break;
      case 'Z':
        mod->first.type = modifier::military_tz;
        break;
      default:
        //
        // Ibid: If an implementation does not support a numbering sequence
        // represented by the given token, it must use a format token of 1.
        //
        mod->first.type = modifier::arabic;
    } // switch
  }
  mod->first.parsed = true;
}

static void parse_variation( utf8_string<zstring const> const &u_picture_str,
                             utf8_string<zstring const>::const_iterator *u,
                             modifier *mod, QueryLoc const &loc ) {
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
    utf8_string<zstring> u_pic_co_string( mod->second.co_string );
    while ( true ) {
      if ( ++v == u_picture_str.end() )
        throw XQUERY_EXCEPTION(
          err::FOFD1340,
          ERROR_PARAMS(
            *u_picture_str.get(),
            ZED( FOFD1340_Picture ),
            ZED( CharExpected_4 ),
            ')'
          ),
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

static void parse_second_modifier( zstring const &picture_str,
                                   zstring::const_iterator *i, modifier *mod,
                                   QueryLoc const &loc ) {
  zstring::const_iterator &j = *i;
  ascii::skip_space( picture_str, &j );
  if ( j == picture_str.end() )
    return;

  unicode::code_point cp;
  bool got_c, got_o, got_a, got_t;
  got_c = got_o = got_a = got_t = false;
  utf8_string<zstring const> const u_picture_str( picture_str );
  utf8_string<zstring const>::const_iterator u( u_picture_str.current( j ) );

  while ( u != u_picture_str.end() ) {
    cp = *u++;
    switch ( cp ) {
      case ']':
        return;
      case 'c':
        if ( got_c )
          goto dup_2nd_modifier;
        if ( got_o || got_a || got_t )
          goto bad_2nd_modifier_here;
        got_c = true;
        mod->second.co = modifier::cardinal;
        parse_variation( u_picture_str, &u, mod, loc );
        break;
      case 'o':
        if ( got_o )
          goto dup_2nd_modifier;
        if ( got_c || got_a || got_t )
          goto bad_2nd_modifier_here;
        got_o = true;
        mod->second.co = modifier::ordinal;
        parse_variation( u_picture_str, &u, mod, loc );
        break;
      case 'a':
        if ( got_a )
          goto dup_2nd_modifier;
        if ( got_t )
          goto bad_2nd_modifier_here;
        got_a = true;
        mod->second.at = modifier::alphabetic;
        break;
      case 't':
        if ( got_t )
          goto dup_2nd_modifier;
        if ( got_a )
          goto bad_2nd_modifier_here;
        got_t = true;
        mod->second.at = modifier::traditional;
        break;
      default:
        throw XQUERY_EXCEPTION(
          err::FOFD1340,
          ERROR_PARAMS(
            picture_str,
            ZED( FOFD1340_Picture ),
            ZED( FOFD1340_Bad2ndModifier_4 ),
            unicode::printable_cp( cp )
          ),
          ERROR_LOC( loc )
        );
    } // switch
  } // while
  j = u.base();
  return;

bad_2nd_modifier_here:
  throw XQUERY_EXCEPTION(
    err::FOFD1340,
    ERROR_PARAMS(
      picture_str,
      ZED( FOFD1340_Picture ),
      ZED( FOFD1340_Bad2ndModifierHere_4 ),
      unicode::printable_cp( cp )
    )
  );

dup_2nd_modifier:
  throw XQUERY_EXCEPTION(
    err::FOFD1340,
    ERROR_PARAMS(
      picture_str,
      ZED( FOFD1340_Picture ),
      ZED( FOFD1340_Dup2ndModifier_4 ),
      unicode::printable_cp( cp )
    )
  );
}

static void parse_width_modifier( zstring const &picture_str,
                                  zstring::const_iterator *i, modifier *mod,
                                  QueryLoc const &loc ) {
  zstring::const_iterator &j = *i;

  ascii::skip_space( picture_str, &j );
  if ( j == picture_str.end() || (*j != ',' && *j != ';') )
    return;
  ascii::skip_space( picture_str, &++j );
  if ( j == picture_str.end() )
    goto bad_width_modifier;
  if ( *j == '*' ) {
    mod->min_width = 0;
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

  mod->max_width = 0;

  ascii::skip_space( picture_str, &j );
  if ( j == picture_str.end() || *j != '-' )
    return;
  ascii::skip_space( picture_str, &++j );
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
    ERROR_PARAMS(
      picture_str,
      ZED( FOFD1340_Picture ),
      ZED( FOFD1340_BadWidthModifier )
    ),
    ERROR_LOC( loc )
  );
}

static int get_data_type( char component ) {
  switch ( component ) {
    case 'D': return DateTime::DAY_DATA;
    case 'd': return DateTime::DAY_DATA;
    case 'E': return DateTime::YEAR_DATA;
    case 'F': return DateTime::DAY_DATA;
    case 'f': return DateTime::FRACSECONDS_DATA;
    case 'H': return DateTime::HOUR_DATA;
    case 'h': return DateTime::HOUR_DATA;
    case 'm': return DateTime::MINUTE_DATA;
    case 'M': return DateTime::MONTH_DATA;
    case 'P': return DateTime::HOUR_DATA;
    case 's': return DateTime::SECONDS_DATA;
    case 'W': return DateTime::DAY_DATA;
    case 'w': return DateTime::DAY_DATA;
    case 'Y': return DateTime::YEAR_DATA;
    default : return -1;
  }
}

bool FnFormatDateTimeIterator::nextImpl( store::Item_t& result,
                                         PlanState &planState ) const {
  zstring picture_str, result_str, item_str;
  xs_dateTime dateTime;
  calendar::type cal = calendar::unknown;
  iso639_1::type lang = iso639_1::unknown;
  iso3166_1::type country = iso3166_1::unknown;
  bool cal_is_fallback = false, lang_is_fallback = false;
  bool in_variable_marker;
  store::Item_t item;
  PlanIteratorState *state;

  DEFAULT_STACK_INIT( PlanIteratorState, state, planState );

  if ( !consumeNext( item, theChildren[0].getp(), planState ) ) {
    // Got the empty sequence -- return same
    STACK_PUSH( false, state );
  } else {
    dateTime = item->getDateTimeValue();
    consumeNext( item, theChildren[1].getp(), planState );
    item->getStringValue2( picture_str );

    if ( theChildren.size() > 2 ) {
      if ( consumeNext( item, theChildren[2].getp(), planState ) &&
           (!locale::parse( item->getStringValue(), &lang, &country ) ||
            !locale::is_supported( lang, country )) ) {
        lang = iso639_1::unknown;
        lang_is_fallback = true;
      }

      if ( consumeNext( item, theChildren[3].getp(), planState ) ) {
        zstring const cal_str( item->getStringValue() );
        zstring prefix_or_uri, local;

        xml::split_uri_name( cal_str, &prefix_or_uri, &local )
        || xml::split_qname( cal_str, &prefix_or_uri, &local );

        if ( !prefix_or_uri.empty() ) {
          //
          // We don't know what to do with calendar designators in a namespace.
          //
          cal_is_fallback = true;
        } else {
          cal = calendar::find( local );
          if ( !cal ) {
            //
            // XQuery F&O 3.0: 9.4.8.3: If the expanded QName is in no
            // namespace, then it must identify a calendar with a designator
            // specified [in the table given in the section].
            //
            throw XQUERY_EXCEPTION(
              err::FOFD1340,
              ERROR_PARAMS(
                cal_str,
                ZED( FOFD1340_Calendar ),
                ZED( FOFD1340_BadCalendarDesignator )
              ),
              ERROR_LOC( loc )
            );
          }
        }
      }

      if ( consumeNext( item, theChildren[4].getp(), planState ) ) {
        // TODO: do something with place
      }
    }

    if ( !cal ) {
      //
      // Ibid: If the $calendar argument is omitted or is set to an empty
      // sequence then the default calendar defined in the dynamic context is
      // used.
      //
      cal = planState.theLocalDynCtx->get_calendar();
    }

    if ( !lang ) {
      //
      // Ibid: If the $language argument is omitted or is set to an empty
      // sequence, or if it is set to an invalid value or a value that the
      // implementation does not recognize, then the processor uses the default
      // language defined in the dynamic context.
      //
      planState.theLocalDynCtx->get_locale( &lang, &country );
      if ( !locale::is_supported( lang, country ) ) {
        //
        // If the language defined in the dynamic context isn't supported
        // either, try the host's language and hope for the best.
        //
        lang = GENV.get_host_lang();
        country = GENV.get_host_country();
        lang_is_fallback = true;
      }
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
              ERROR_PARAMS(
                picture_str,
                ZED( FOFD1340_Picture ),
                ZED( FOFD1340_NoComponent )
              ),
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
#if 0
          if ( component )
            throw XQUERY_EXCEPTION(
              err::FOFD1340,
              ERROR_PARAMS(
                picture_str,
                ZED( FOFD1340_Picture ),
                ZED( FOFD1340_MultipleComponent_4 ),
                *i
              ),
              ERROR_LOC( loc )
            );
#endif
          component = *i;
          break;
        default:
          throw XQUERY_EXCEPTION(
            err::FOFD1340,
            ERROR_PARAMS(
              picture_str,
              ZED( FOFD1340_Picture ),
              ZED( FOFD1340_BadComponent_4 ),
              *i
            ),
            ERROR_LOC( loc )
          );
      } // switch
      if ( ++i == picture_str.end() )
        goto eos;

      modifier mod;
      mod.lang = lang;
      mod.lang_is_fallback = lang_is_fallback;
      mod.country = country;
      mod.cal = cal;
      mod.cal_is_fallback = cal_is_fallback;

      if ( *i != ']' ) {
        parse_first_modifier( picture_str, &i, &mod, loc );
        if ( i == picture_str.end() )
          goto eos;
        if ( *i != ']' ) {
          if ( *i != ',' && *i != ';' ) {
            parse_second_modifier( picture_str, &i, &mod, loc );
            if ( i == picture_str.end() )
              goto eos;
          }
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
          modifier mod_copy( mod );
          if ( !mod.first.parsed )
            mod_copy.first.type = modifier::name;
          append_string( "gregorian", mod_copy, &result_str );
          break;
        }
        case 'D':
          append_number( dateTime.getDay(), mod, &result_str );
          break;
        case 'd':
          append_number( dateTime.getDayOfYear(), mod, &result_str );
          break;
        case 'E': { // era
          modifier mod_copy( mod );
          if ( !mod.first.parsed )
            mod_copy.first.type = modifier::name;
          int const year = dateTime.getYear();
          zstring const era( year > 0 ? "ad" : year < 0 ? "bc" : "" );
          append_string( era, mod_copy, &result_str );
          break;
        }
        case 'F': {
          modifier mod_copy( mod );
          if ( !mod.first.parsed )
            mod_copy.first.type = modifier::name;
          append_weekday(
            dateTime.getDay(), dateTime.getMonth() - 1, dateTime.getYear(),
            mod_copy, &result_str
          );
          break;
        }
        case 'f':
          append_fractional_seconds(
            dateTime.getFractionalSeconds(), mod, &result_str
          );
          break;
        case 'H': // hour (24 hours)
          append_number( dateTime.getHours(), mod, &result_str );
          break;
        case 'h': // hour (12 hours)
          // Convert hour from:  0 1 ... 12 13 ... 23
          //                to: 12 1 ... 12  1 ... 11
          append_number(
            1 + (11 + dateTime.getHours()) % 12, mod, &result_str
          );
          break;
        case 'M':
          append_month( dateTime.getMonth() - 1, mod, &result_str );
          break;
        case 'm': {
          modifier mod_copy( mod );
          mod_copy.set_default_width( 2 );
          append_number( dateTime.getMinutes(), mod_copy, &result_str );
          break;
        }
        case 'P': {
          modifier mod_copy( mod );
          if ( !mod.first.parsed )
            mod_copy.first.type = modifier::name;
          append_string(
            locale::get_time_ampm( dateTime.getHours() >= 12, lang, country ),
            mod_copy, &result_str
          );
          break;
        }
        case 's': {
          modifier mod_copy( mod );
          mod_copy.set_default_width( 2 );
          append_number( dateTime.getIntSeconds(), mod_copy, &result_str );
          break;
        }
        case 'W':
          append_week_in_year(
            dateTime.getDay(), dateTime.getMonth() - 1, dateTime.getYear(),
            mod, &result_str
          );
          break;
        case 'w':
          append_week_in_month(
            dateTime.getDay(), dateTime.getMonth() - 1, dateTime.getYear(),
            mod, &result_str
          );
          break;
        case 'Y':
          append_year( std::abs( dateTime.getYear() ), mod, &result_str );
          break;
        case 'Z':
        case 'z':
          append_timezone(
            component, dateTime.getTimezone(), mod, &result_str
          );
          break;
      } // switch
    } // for

    if ( in_variable_marker )
eos:  throw XQUERY_EXCEPTION(
        err::FOFD1340,
        ERROR_PARAMS(
          picture_str,
          ZED( FOFD1340_Picture ),
          ZED( CharExpected_4 ),
          ']'
        ),
        ERROR_LOC( loc )
      );

    STACK_PUSH( GENV_ITEMFACTORY->createString( result, result_str ), state );
  }

  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
