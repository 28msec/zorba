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

#ifndef ZORBA_STRPTIME_H
#define ZORBA_STRPTIME_H

// standard
#include <stdexcept>
#include <ostream>

// Zorba
#include <zorba/config.h>
#include <zorba/internal/cxx_util.h>
#include "string_util.h"
#include "time_util.h"
#include "util/locale.h"

namespace zorba {
namespace time {

///////////////////////////////////////////////////////////////////////////////

/**
 * An %exception is the root of time::parse %exception hierarchy.
 */
class exception : public std::runtime_error {
public:
  ~exception() throw();
protected:
  exception( std::string const &msg );
};

/**
 * This exception is thrown when the buffer is exhausted before the format
 * string.
 */
class insufficient_buffer : public exception {
public:
  insufficient_buffer();
};

/**
 * This exception is thrown when an invalid conversion specification is given,
 * i.e., an invalid character after a \c %.
 */
class invalid_specification : public std::invalid_argument {
public:
  invalid_specification( char spec );
  ~invalid_specification() throw();

  /**
   * Gets the invalid specification.
   *
   * @return Returns said specification character.
   */
  char get_spec() const {
    return spec_;
  }

private:
  char spec_;
};

/**
 * This is a helper class for invalid_value.
 */
class invalid_value_specs {
protected:
  invalid_value_specs( char spec );
  invalid_value_specs( char const *specs );

  std::string specs_;
};

/**
 * This is a helper class for invalid_value.
 */
class invalid_value_value {
protected:
  invalid_value_value( char c );
  invalid_value_value( char const *buf, size_t len );

  template<typename ValueType>
  invalid_value_value( ValueType const &value );

  std::string value_;
};

/**
 * This exception is thrown when an invalid value for a given specification was
 * given.
 */
class invalid_value :
  protected invalid_value_value,
  protected invalid_value_specs,
  public exception {
public:
  invalid_value( char const *buf, size_t len, char spec );
  invalid_value( char const *buf, size_t len, char const *specs );

  template<typename ValueType>
  invalid_value( ValueType const &value, char spec );

  template<typename ValueType>
  invalid_value( ValueType const &value, char const *specs );

  ~invalid_value() throw();

  /**
   * Gets the conversion specification character(s) the value is invalid for.
   *
   * @return Returns said character(s).
   */
  std::string const& get_specs() const {
    return specs_;
  }

  /**
   * Gets the invalid value.
   *
   * @return Returns said value.
   */
  std::string const& get_value() const {
    return value_;
  }

private:
  static std::string build_msg( std::string const &value,
                                std::string const &specs );
};

#ifdef WIN32
std::ostream& operator<<( std::ostream &os, const zorba::time::invalid_value &i );
#endif

/**
 * This exception is thrown when a literal character in the \a buf parameter of
 * the parse() function does not match is corresponding character in the
 * \a fmt parameter.
 */
class literal_mismatch : public exception {
public:
  literal_mismatch( char expected, char got );
  ~literal_mismatch() throw();

  /**
   * Gets the character that was expected.
   *
   * @return Returns said character.
   */
  char get_expected() const {
    return expected_;
  }

  /**
   * Gets the character that was actually gotten.
   *
   * @return Returns said character.
   */
  char get_got() const {
    return got_;
  }

private:
  char expected_;
  char got_;
};

///////////////////////////////////////////////////////////////////////////////

//
// The bit-wise-or of these constants comprise the value returned by the
// set_fields parameter of the parse() function.
//
unsigned const set_gmtoff = 0x001;      // minutes: 0-59
unsigned const set_hour   = 0x002;      // hour: 0-23
unsigned const set_mday   = 0x004;      // month day: 1-{28,29,30,31}
unsigned const set_min    = 0x008;      // minutes: 0-59
unsigned const set_mon    = 0x010;      // month: 0-11
unsigned const set_sec    = 0x020;      // seconds: 0-60
unsigned const set_wday   = 0x040;      // weekday: 0-6
unsigned const set_yday   = 0x080;      // day of the year: 0-365
unsigned const set_year   = 0x100;

/**
 * Parses the string in the buffer according to the given format and fills in
 * the given \c tm structure.
 *
 * @param buf The buffer to parse.
 * @param fmt The format string containing zero or more directives. Each
 * specification is of one of the following:
 *  - one or more white-space characters
 *  - an ordinary character (neither \c '%' nor a whitespace character)
 *  - a conversion specification
 * All whitespace characters in \a fmt match one or more whitespace characters
 * in \a buf.
 * Every ordinary character in \a fmt must exactly match the same character in
 * the same position in \a buf.
 * A conversion specification is composed of a \c '%' character followed by a
 * conversion character that specifies the replacement required.  The following
 * conversion specifications are supported:
 *  <table>
 *    <tr>
 *      <td>%a</td>
 *      <td>
 *        The day of the week using the locale's weekday names;
 *        either the abbreviated or full name may be specified.
 *      </td>
 *    </tr>
 *    <tr>
 *      <td>%A</td>
 *      <td>Same as \c %a.</td>
 *    </tr>
 *    <tr>
 *      <td>%b</td>
 *      <td>
 *        The month using the locale's month names;
 *        either the abbreviated or full name may be specified.
 *      </td>
 *    </tr>
 *    <tr>
 *      <td>%B</td>
 *      <td>Same as \c %a.</td>
 *    </tr>
 *    <tr>
 *      <td>%c</td>
 *      <td>
 *        The locale's appropriate date and time representation.
 *      </td>
 *    </tr>
 *    <tr>
 *      <td>%C</td>
 *      <td>
 *        The century number [00,99]; leading zeros are permitted but not
 *        required.
 *      </td>
 *    </tr>
 *    <tr>
 *      <td>%d</td>
 *      <td>
 *        The day of the month [01,31]; leading zeros are permitted but not
 *        required.
 *      </td>
 *    </tr>
 *    <tr>
 *      <td>%D</td>
 *      <td>Same as <code>%m/%d/%y</code>.</td>
 *    </tr>
 *    <tr>
 *      <td>%e</td>
 *      <td>Same as \c %d.</td>
 *    </tr>
 *    <tr>
 *      <td>%h</td>
 *      <td>Same as \c %b.</td>
 *    </tr>
 *    <tr>
 *      <td>%H</td>
 *      <td>
 *        The hour (24-hour clock) [00,23]; leading zeros are permitted but not
 *        required.
 *      </td>
 *    </tr>
 *    <tr>
 *      <td>%I</td>
 *      <td>
 *        The hour (12-hour clock) [01,12]; leading zeros are permitted but not
 *        required.
 *      </td>
 *    </tr>
 *    <tr>
 *      <td>%j</td>
 *      <td>
 *        The day number of the year [001,366]; leading zeros are permitted but
 *        not required.
 *      </td>
 *    </tr>
 *    <tr>
 *      <td>%m</td>
 *      <td>
 *        The month number [01,12]; leading zeros are permitted but not
 *        required.
 *      </td>
 *    </tr>
 *    <tr>
 *      <td>%M</td>
 *      <td>
 *        The minute [00,59]; leading zeros are permitted but not required.
 *      </td>
 *    </tr>
 *    <tr>
 *      <td>%n</td>
 *      <td>Any whitespace.</td>
 *    </tr>
 *    <tr>
 *      <td>%p</td>
 *      <td>
 *        The locale's equivalent of \c AM or \c PM.
 *      </td>
 *    </tr>
 *    <tr>
 *      <td>%r</td>
 *      <td>
 *        The 12-hour clock time using the AM/PM notation.
 *      </td>
 *    </tr>
 *    <tr>
 *      <td>%R</td>
 *      <td>Same as <code>%H:%M</code>.</td>
 *    </tr>
 *    <tr>
 *      <td>%S</td>
 *      <td>
 *        The seconds [00,60]; leading zeros are permitted but not required.
 *      </td>
 *    </tr>
 *    <tr>
 *      <td>%t</td>
 *      <td>Any whitespace.</td>
 *    </tr>
 *    <tr>
 *      <td>%T</td>
 *      <td>Same as <code>%H:%M:%S</code>.</td>
 *    </tr>
 *    <tr>
 *      <td>%U</td>
 *      <td>
 *        The week number of the year (Sunday as the first day of the week)
 *        [00,53]; leading zeros are permitted but not required.
 *      </td>
 *    <tr>
 *      <td>%w</td>
 *      <td>
 *        The weekday [0,6] with 0 representing Sunday; leading zeros are
 *        permitted but not required.
 *      </td>
 *    </tr>
 *    <tr>
 *      <td>%W</td>
 *      <td>
 *        The week number of the year (Monday as the first day of the week)
 *        [00,53]; leading zeros are permitted but not required.
 *      </td>
 *    </tr>
 *    <tr>
 *      <td>%x</td>
 *      <td>
 *        The date using the locale's date format.
 *      </td>
 *    </tr>
 *    <tr>
 *      <td>%X</td>
 *      <td>
 *        The time using the locale's time format.
 *      </td>
 *    </tr>
 *    <tr>
 *      <td>%y</td>
 *      <td>
 *        The year within century. When a century is not otherwise specified
 *        (via \c %C), values in the range [69,99] shall refer to years 1969 to
 *        1999 and values in the range [00,68] shall refer to years 2000 to
 *        2068; leading zeros are permitted but not required.
 *      </td>
 *    </tr>
 *    <tr>
 *      <td>%Y</td>
 *      <td>
 *        The year including the century (for example, 1988).
 *      </td>
 *    </tr>
 *    <tr>
 *      <td>%%</td>
 *      <td>Literal \c %.</td>
 *    </tr>
 *  </table>
 * @param lang The language of the locale to use.
 * @param country The country of the locale to use.
 * @param tm The tm structure to fill in.
 * @param set_fields If not null, this is set to the bit-wise-or of the tm
 * structure fields that have been set.
 * @return Returns a pointer to the first character in \a buf past the last
 * character parsed.
 * @throws insufficient_buffer if \a buf is insufficient for \a fmt.
 * @throws invalid_specification if \a fmt contains an invalid character
 * following \c %
 * @throws invalid_value if \a buf contains an invalid value for a
 * specification.
 * @throws literal_mismatch if a literal character in \a buf does not match is
 * corresponding character in \a fmt.
 */
char const* parse( char const *buf, char const *fmt,
                   locale::iso639_1::type lang,
                   locale::iso3166_1::type country,
                   ztm *tm, unsigned *set_fields = nullptr );

//
// Template version of parse().
//
template<class BufferType> inline
typename std::enable_if<ZORBA_HAS_C_STR(BufferType),char const*>::type
parse( BufferType const &buf, char const *fmt,
       locale::iso639_1::type lang, locale::iso3166_1::type country,
       ztm *tm, unsigned *set_fields = nullptr ) {
  return parse( buf.c_str(), fmt, lang, country, tm, set_fields );
}

//
// Template version of parse().
//
template<class FormatType> inline
typename std::enable_if<ZORBA_HAS_C_STR(FormatType),char const*>::type
parse( char const *buf, FormatType const &fmt,
       locale::iso639_1::type lang, locale::iso3166_1::type country,
       ztm *tm, unsigned *set_fields = nullptr ) {
  return parse( buf, fmt.c_str(), lang, country, tm, set_fields );
}

//
// Template version of parse().
//
template<class BufferType,class FormatType> inline
typename std::enable_if<ZORBA_HAS_C_STR(BufferType)
                     && ZORBA_HAS_C_STR(FormatType),
                        char const*>::type
parse( BufferType const &buf, FormatType const &fmt,
       locale::iso639_1::type lang, locale::iso3166_1::type country,
       ztm *tm, unsigned *set_fields = nullptr ) {
  return parse( buf.c_str(), fmt.c_str(), lang, country, tm, set_fields );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace time
} // namespace zorba
#endif /* ZORBA_STRPTIME_H */
/* vim:set et sw=2 ts=2: */
