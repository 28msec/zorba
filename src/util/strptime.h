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
// If the OS's tm struct has GMT-timezone offset field, simply typedef tm as
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
 * the given tm structure.
 *
 * @param buf The buffer to parse.
 * @param fmt The format string containing zero or more conversion
 * specifications and ordinary characters.  All ordinary characters are matched
 * exactly with the buffer; all white space characters string match any amount
 * of white space in the buffer.
 * @param tm The tm structure to fill in.
 * @return Returns a pointer to the first character in \a buf past the last
 * character parsed.
 * @throws invalid_argument if \a fmt contains an invalid character following
 * \c % or if the value for a conversion specification is invalid.
 */
char const* strptime( char const *buf, char const *fmt, ztm *tm );

template<class BufferType> inline
typename std::enable_if<
  ztd::has_c_str<BufferType,char const* (BufferType::*)() const>::value,
  char const*
>::type
strptime( BufferType const &buf, char const *fmt, ztm *tm ) {
  return ztd::strptime( buf.c_str(), fmt, tm );
}

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
