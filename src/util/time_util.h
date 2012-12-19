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

#ifndef ZORBA_TIME_UTIL_H
#define ZORBA_TIME_UTIL_H

// standard
#include <ctime>                        /* for struct tm */

// Zorba
#include <zorba/config.h>

namespace zorba {
namespace time {

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

/**
 * Calculates the weekday for the given date.
 *
 * @param mday The month day (1-31).
 * @param mon The month (0-11).
 * @param year The year.
 * @return Returns the weekday (0-6) where 0 = Sunday.
 */
unsigned calc_wday( unsigned mday, unsigned mon, unsigned year );

/**
 * Calculates the day of the year for the given date.
 *
 * @param mday The month day (1-31).
 * @param mon The month (0-11).
 * @param year The year.
 * @return Returns the day of the year (0-365) where 0 = January 1.
 */
unsigned calc_yday( unsigned mday, unsigned mon, unsigned year );

/**
 * Gets the number of days in the given month.
 *
 * @param mon The month (0-11).
 * @param year The year.
 * @return Returns said number of days (1-31).
 */
unsigned days_in_month( unsigned mon, unsigned year );

/**
 * Checks whether the given year is a leap year.
 *
 * @param year The year to check.
 * @return Returns \c true only if \a year is a leap year.
 */
inline bool is_leap_year( unsigned year ) {
  return !(year % 4) && ((year % 100) || !(year % 400));
}

/**
 * Checks whether the given day of the month is valid.
 *
 * @param mday The month day (1-31).
 * @param mon The month (0-11).
 * @param year The year.
 * @return Returns \a true only if the given day of the month is valid.
 */
inline bool is_mday_valid( unsigned mday, unsigned mon, unsigned year ) {
  return mday >= 1 && mday <= days_in_month( mon, year );
}

/**
 * Checks whether the given weekday is valid.
 *
 * @param wday The weekday (0-6) where 0 = Sunday.
 * @param mday The month day (1-31).
 * @param mon The month (0-11).
 * @param year The year.
 * @return Returns \a true only if the given weekday is valid.
 */
inline bool is_wday_valid( unsigned wday, unsigned mday, unsigned mon,
                           unsigned year ) {
  return wday == calc_wday( mday, mon, year );
}

/**
 * Checks whether the given day of the year is valid.
 *
 * @param yday The day of the year (0-365).
 * @param mday The month day (1-31).
 * @param mon The month (0-11).
 * @param year The year.
 * @return Returns \a true only if the given day of the year is valid.
 */
inline bool is_yday_valid( unsigned yday, unsigned mday, unsigned mon,
                           unsigned year ) {
  return yday == calc_yday( mday, mon, year );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace time
} // namespace zorba
#endif /* ZORBA_TIME_UTIL_H */
/* vim:set et sw=2 ts=2: */
