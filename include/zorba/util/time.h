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
#pragma once
#ifndef ZORBA_UTIL_TIME_H
#define ZORBA_UTIL_TIME_H

#include <zorba/config.h>

#if defined(ZORBA_HAVE_CLOCKGETTIME) && defined(_POSIX_CPUTIME)
#include <time.h>
#elif defined(ZORBA_HAVE_GETRUSAGE)
#include <sys/time.h>
#include <sys/resource.h>
#else /* no rusage, no clock_gettime */
#include <time.h>
#endif /* ZORBA_HAVE_CLOCKGETTIME */

#if defined(ZORBA_HAVE_CLOCKGETTIME)
#include <time.h>
#elif defined(WIN32)
#include <sys/timeb.h>
#else /* not Windows, and no clock_gettime() */
#include <time.h>
#include <sys/time.h>
#endif /* ZORBA_HAVE_CLOCKGETTIME */


/**
 * This header includes utility functions for certain timing-related
 * operations, namely getting current wall-clock time and current
 * CPU-used time values in a platform-dependent fashion, and computing
 * deltas for both types.
 *
 * Types:
 *   cputime - type representing CPU time utilized thus far by this process
 *   walltime - type representing wall-clock time since some
 *     platform-dependent epoch
 *
 * Function signatures:
 *   void get_current_cputime(cputime& t) - returns current CPU time
 *
 *   double get_cputime_elapsed(const cputime& t0, const cputime& t1) -
 *     calculates elapsed CPU time (in ms) between two cputimes
 *
 *   void get_current_walltime(walltime& t) - returns current wall-clock time
 *
 *   double get_walltime_elapsed(const walltime& t0, const walltime& t1) -
 *    calculates elapsed wall-clock time (in ms) between two walltimes
 */

/**
 * TODO These functions should probably be defined in a .cpp file
 * somewhere rather than here in time.h; as it is they will be
 * compiled into every .o that uses them. So far, though, this is only
 * zorbacmd and the implementation of fn:doc(), so it's not too bad.
 */

namespace zorba {
namespace time {

///////////////////////////////////////////////////////////////////////////////

// Large enough to hold number of milliseconds since epoch.
#if ZORBA_SIZEOF_LONG <= 4
typedef long long msec_type;
#else
typedef long msec_type;
#endif /* ZORBA_SIZEOF_LONG */

//
//
// Types and functions for CPU time
//
//

#if defined(ZORBA_HAVE_CLOCKGETTIME) && defined(_POSIX_CPUTIME)

typedef struct timespec cputime;

inline double get_cputime_elapsed( cputime const &t0, cputime const &t1 ) {
  return ((t1.tv_sec - t0.tv_sec) * 1000.0) +
    ((t1.tv_nsec - t0.tv_nsec) / 1000000.0);
}

inline void get_current_cputime( cputime &t ) {
  clock_gettime( CLOCK_PROCESS_CPUTIME_ID, &t );
}

#elif defined(ZORBA_HAVE_GETRUSAGE)

typedef struct timeval cputime;

inline double get_cputime_elapsed( cputime const &t0, cputime const &t1 ) {
  return ((t1.tv_sec - t0.tv_sec) * 1000.0) +
    ((t1.tv_usec - t0.tv_usec) / 1000.0);
}

inline void get_current_cputime( cputime &t ) {
  struct rusage ru;
  getrusage( RUSAGE_SELF, &ru );
  t = ru.ru_utime;
}

#else /* no rusage, no clock_gettime */

typedef clock_t cputime;

inline double get_cputime_elapsed( cputime const &t0, cputime const &t1 ) {
  return (double)(t1 - t0) / (CLOCKS_PER_SEC / 1000);
}

inline void get_current_cputime( cputime &t ) {
  t = clock();
}

#endif /* ZORBA_HAVE_CLOCKGETTIME */

///////////////////////////////////////////////////////////////////////////////

//
//
// Types and functions for wall-clock time
//
//

#if defined(ZORBA_HAVE_CLOCKGETTIME)

typedef struct timespec walltime;

inline double get_walltime_elapsed( walltime const &t0, walltime const &t1 ) {
  return ((t1.tv_sec - t0.tv_sec) * 1000.0) +
    ((t1.tv_nsec - t0.tv_nsec) / 1000000.0);
}

inline void get_current_walltime( walltime &t ) {
#ifdef _POSIX_MONOTONIC_CLOCK
  clock_gettime( CLOCK_MONOTONIC, &t );
#else
  clock_gettime( CLOCK_REALTIME, &t );
#endif /* _POSIX_MONOTONIC_CLOCK */
}

inline msec_type get_walltime_in_millis( walltime const &t ) {
  return t.tv_sec * (msec_type)1000 + t.tv_nsec / 1000000;
}

#elif defined(WIN32)

// TODO: Should maybe use QueryPerformanceCounter() or
// GetSystemTimeAsFileTime() for this, rather than ftime(), but I
// don't know enough about any of these alternatives to choose
// one. See http://msdn.microsoft.com/en-us/magazine/cc163996.aspx .

#ifdef WINCE
typedef struct timeb walltime;
#else
typedef struct _timeb walltime;
#endif /* WINCE */

inline double get_walltime_elapsed(walltime const &t0, walltime const &t1 ) {
  return ((t1.time - t0.time) * 1000.0) + (t1.millitm - t0.millitm);
}

inline void get_current_walltime( walltime &t ) {
#ifdef WINCE
  ftime( &t );
#else
  _ftime_s( &t );
#endif /* WINCE */
}

inline msec_type get_walltime_in_millis( walltime const &t ) {
  return t.time * (msec_type)1000 + t.millitm;
}

#else /* not Windows, and no clock_gettime() */

typedef struct timeval walltime;

inline double get_walltime_elapsed( walltime const &t0, walltime const &t1 ) {
  return ((t1.tv_sec - t0.tv_sec) * 1000.0) +
    ((t1.tv_usec - t0.tv_usec) / 1000.0);
}

inline void get_current_walltime( walltime &t ) {
  gettimeofday( &t, NULL );
}

inline msec_type get_walltime_in_millis( walltime const &t ) {
  return t.tv_sec * (msec_type)1000 + t.tv_usec / 1000;
}

#endif /* ZORBA_HAVE_CLOCKGETTIME */

///////////////////////////////////////////////////////////////////////////////

} // namespace time
} // namespace zorba

#endif /* ZORBA_UTIL_TIME_H */
/*
* Local variables:
* mode: c++
* End:
*/
/* vim:set et sw=2 ts=2: */
