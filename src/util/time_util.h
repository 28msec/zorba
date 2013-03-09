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
#ifdef ZORBA_HAVE_TZFILE_H
# include <tzfile.h>                    /* for TM_YEAR_BASE */
#endif /* ZORBA_HAVE_TZFILE_H */

// Zorba
#include <zorba/config.h>
#include "cxx_util.h"

#ifndef TM_YEAR_BASE
# define TM_YEAR_BASE 1900
#endif

namespace zorba {
namespace time {

///////////////////////////////////////////////////////////////////////////////

typedef time_t sec_type;

#ifdef WIN32
typedef unsigned long usec_type;
#else
typedef suseconds_t usec_type;
#endif /* WIN32 */

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

//
// Always use this macro to access the tm_gmtoff field of the tm struct since
// its name varies across plattorms.
//
#ifdef ZORBA_HAVE_STRUCT_TM___TM_GMTOFF
# define ZTM_GMTOFF __tm_gmtoff
#else
# define ZTM_GMTOFF tm_gmtoff
#endif

///////////////////////////////////////////////////////////////////////////////

/**
 * Calculates the day of the month and month from the given day of the year.
 *
 * @param yday The year day (0-365) where 0 = January 1.
 * @param mday A pointer to the result for the month day (1-31) or \c null if
 * this is not desired.
 * @param mon A pointer to the result for the month (0-11) or \c null if this
 * is not desired.
 * @param year The year.
 * @return Returns \c true if \a yday and \a year are a valid combination and
 * a result is yielded.
 */
bool calc_mday_mon( unsigned yday, unsigned *mday, unsigned *mon,
                    unsigned year );

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
 * Gets the number of seconds and microseconds since epoch.
 *
 * @param sec A pointer to the result in seconds.
 * @param usec A pointer to the result in microseconds or \c null if this is
 * not desired.
 */
void get_epoch( sec_type *sec, usec_type *usec = nullptr );

/**
 * Gets the Greenwich time and populates the given ztm structure.
 *
 * @param tm A pointer to the ztm struct to populate.
 * @param when If &gt; 0, populates \a tm based on \a when number of seconds
 * since \e epoch; if 0, populates \a when based on \e now.
 */
void get_gmtime( ztm *tm, sec_type when = 0 );

/**
 * Gets the offset of the current timezone from Greenwich time.
 *
 * @return Returns the offset in seconds with positive values being east of the
 * prime meridian.
 */
long get_gmt_offset();

/**
 * Gets the local time and populates the given ztm structure.
 *
 * @param tm A pointer to the ztm struct to populate.
 * @param when If &gt; 0, populates \a tm based on \a when number of seconds
 * since \e epoch; if 0, populates \a when based on \e now.
 */
void get_localtime( ztm *tm, sec_type when = 0 );

/**
 * Gets the military timezone letter code for the given GMT hour offset.
 *
 * @param hour The number of hours offset from GMT.
 * @return Returns one of ABCDEFGHIKLMNOPQRSTUVWXYZ (no J).
 */
char get_military_tz( int hour );

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
