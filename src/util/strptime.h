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

// Zorba
#include <zorba/config.h>
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
inline long get_gmtoff( ztm const &tm ) {
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
inline void set_gmtoff( ztm &tm, long gmtoff ) {
#if defined(ZORBA_HAVE_STRUCT_TM___TM_GMTOFF)
  tm.__tm_gmtoff = gmtoff;
#else
  tm.tm_gmtoff = gmtoff;
#endif
}

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
 * @return Returns a pointer to the first character in \a buf past the last
 * character parsed.
 * @throws invalid_argument if \a fmt contains an invalid character following
 * \c % or if the value for a conversion specification is invalid.
 */
char const* strptime( char const *buf, char const *fmt, ztm *tm );

//
// Template version of strptime().
//
template<class BufferType> inline
typename std::enable_if<
  ztd::has_c_str<BufferType,char const* (BufferType::*)() const>::value,
  char const*
>::type
strptime( BufferType const &buf, char const *fmt, ztm *tm ) {
  return ztd::strptime( buf.c_str(), fmt, tm );
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
strptime( BufferType const &buf, FormatType const &fmt, ztm *tm ) {
  return ztd::strptime( buf.c_str(), fmt.c_str(), tm );
}

} // namespace ztd

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
#endif /* ZORBA_STRPTIME */
/* vim:set et sw=2 ts=2: */
