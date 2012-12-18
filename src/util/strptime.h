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

#ifndef ZORBA_STRPTIME
#define ZORBA_STRPTIME

// standard
#include <ctime>
#include <stdexcept>

// Zorba
#include <zorba/config.h>
#include "cxx_util.h"
#include "string_util.h"

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

//
// If the OS's tm struct has a GMT-timezone offset field, simply typedef tm as
// ztm; otherwise declare ztm as a struct derived from tm that adds a
// GMT-timezone offset field.
//
#if defined(ZORBA_HAVE_STRUCT_TM_TM_GMTOFF) || \
    defined(ZORBA_HAVE_STRUCT_TM___TM_GMTOFF)
typedef struct tm ztm;
#else
struct ztm : tm {
  long tm_gmtoff;
};
#endif

namespace ztd {

/**
 * Gets the GMT offset from the given ztm.
 *
 * @param tm The ztm to get the GMT offset from.
 * @return Returns the GMT offset in seconds east of Greenwich.
 */
inline long get_gmtoff_field( ztm const &tm ) {
#if defined(ZORBA_HAVE_STRUCT_TM___TM_GMTOFF)
  return tm.__tm_gmtoff;
#else
  return tm.tm_gmtoff;
#endif
}

/**
 * Sets the GMT offset of the given ztm.
 *
 * @param tm The ztm to set the GMT offset of.
 * @param gmtoff The GMT offset in seconds east of Greenwich.
 */
inline void set_gmtoff_field( ztm &tm, long gmtoff ) {
#if defined(ZORBA_HAVE_STRUCT_TM___TM_GMTOFF)
  tm.__tm_gmtoff = gmtoff;
#else
  tm.tm_gmtoff = gmtoff;
#endif
}

///////////////////////////////////////////////////////////////////////////////

class time_exception : public std::invalid_argument {
public:
  ~time_exception() throw();
protected:
  time_exception( std::string const &msg );
};

/**
 * This exception is thrown when an invalid conversion specification is given,
 * i.e., an invalid character after a \c %.
 */
class invalid_specification : public time_exception {
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
  public time_exception {
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

/**
 * This exception is thrown when a literal character in the \a buf parameter of
 * the strptime() function does not match is corresponding character in the
 * \a fmt parameter.
 */
class literal_mismatch : public time_exception {
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

// unrecognized timezone
// invalid timezone offset
// value not in range
// invalid alternate representation
// invalid day-of-month
// invalid weekday for date
// invalid day-of-year for date


//
// The bit-wise-or of these constants comprise the value returned by the
// \c set_fields parameter of the strptime() function.
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
 * @param tm The tm structure to fill in.
 * @param set_fields If not null, this is set to the bit-wise-or of the tm
 * structure fields that have been set.
 * @return Returns a pointer to the first character in \a buf past the last
 * character parsed.
 * @throws invalid_argument if \a fmt contains an invalid character following
 * \c % or if the value for a conversion specification is invalid.
 */
char const* strptime( char const *buf, char const *fmt, ztm *tm,
                      unsigned *set_fields = nullptr );

//
// Template version of strptime().
//
template<class BufferType> inline
typename std::enable_if<
  ztd::has_c_str<BufferType,char const* (BufferType::*)() const>::value,
  char const*
>::type
strptime( BufferType const &buf, char const *fmt, ztm *tm,
          unsigned *set_fields = nullptr ) {
  return ztd::strptime( buf.c_str(), fmt, tm, set_fields );
}

//
// Template version of strptime().
//
template<class BufferType,class FormatType> inline
typename std::enable_if<
  ztd::has_c_str<BufferType,char const* (BufferType::*)() const>::value &&
  ztd::has_c_str<FormatType,char const* (FormatType::*)() const>::value,
  char const*
>::type
strptime( BufferType const &buf, FormatType const &fmt, ztm *tm,
          unsigned *set_fields = nullptr ) {
  return ztd::strptime( buf.c_str(), fmt.c_str(), tm, set_fields );
}

} // namespace ztd

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
#endif /* ZORBA_STRPTIME */
/* vim:set et sw=2 ts=2: */
