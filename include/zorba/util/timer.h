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

#ifndef ZORBA_UTIL_TIMER_H
#define ZORBA_UTIL_TIMER_H

#include <zorba/util/time.h>

namespace zorba {
namespace time {

///////////////////////////////////////////////////////////////////////////////

class Timer {
public:
  void start() {
    get_current_walltime(theStart);
  }

  double elapsed() const {
    walltime lEnd;
    get_current_walltime(lEnd);
    return get_walltime_elapsed(theStart, lEnd);
  }

  time::msec_type getStart() const {
    return get_walltime_in_millis(theStart);
  }

private:
  walltime theStart;
};

namespace cpu {

#if defined(ZORBA_HAVE_CLOCKGETTIME) && defined(_POSIX_CPUTIME)
typedef struct timespec time_type;
#elif defined(ZORBA_HAVE_GETRUSAGE)
typedef struct timeval time_type;
#else
struct time_type { clock_t value; };    // struct allows operator overloading
#endif

/**
 * Gets a monotonically increasing value for the current CPU time.
 *
 * @param t A pointer to the result.
 */
inline void get_time( time_type *t ) {
#if defined(ZORBA_HAVE_CLOCKGETTIME) && defined(_POSIX_CPUTIME)
  clock_gettime( CLOCK_PROCESS_CPUTIME_ID, t );
#elif defined(ZORBA_HAVE_GETRUSAGE)
  struct rusage ru;
  getrusage( RUSAGE_SELF, &ru );
  *t = ru.ru_utime;
#else
  t->value = clock();
#endif
}

/**
 * Calculates the difference between two CPU times.
 *
 * @param t1 The later time.
 * @param t0 The earlier time.
 * @return Returns the difference in milliseconds.
 */
inline double operator-( time_type const &t1, time_type const &t0 ) {
#if defined(ZORBA_HAVE_CLOCKGETTIME) && defined(_POSIX_CPUTIME)
  return (t1.tv_sec  - t0.tv_sec) * 1000 + (t1.tv_nsec - t0.tv_nsec) / 1000000.0;
#elif defined(ZORBA_HAVE_GETRUSAGE)
  return (t1.tv_sec  - t0.tv_sec) * 1000 + (t1.tv_usec - t0.tv_usec + 500) / 1000.0;
#else
  return (t1.value - t0.value) / (CLOCKS_PER_SEC / 1000.0);
#endif
}

/**
 * A %timer class is used to measure the amount of CPU time used by some block
 * of code.
 */
class timer {
public:
  /**
   * Starts the timer.  Calling this function again resets the start time.
   */
  void start() {
    get_time( &start_ );
  }

  /**
   * Gets the amount of time that has elapsed since the last time start() was
   * called.
   *
   * @return Returns said amount of time in milliseconds.
   */
  double elapsed() const {
    time_type now;
    get_time( &now );
    return now - start_;
  }

private:
  time_type start_;
};

} // namespace cpu

///////////////////////////////////////////////////////////////////////////////

namespace wall {

#if defined(ZORBA_HAVE_CLOCKGETTIME)
typedef struct timespec time_type;
#elif defined(WIN32)
typedef struct _timeb time_type;
#else
typedef struct timeval time_type;
#endif

/**
 * Gets a monotonically increasing value for the current wall time.
 *
 * @param t A pointer to the result.
 */
inline void get_time( time_type *t ) {
#if defined(ZORBA_HAVE_CLOCKGETTIME)
#ifdef _POSIX_MONOTONIC_CLOCK
  clock_gettime( CLOCK_MONOTONIC, t );
#else
  clock_gettime( CLOCK_REALTIME, t );
#endif /* _POSIX_MONOTONIC_CLOCK */
#elif defined(WIN32)
  _ftime_s( t );
#else
  gettimeofday( t, nullptr );
#endif
}

/**
 * Calculates the difference between two wall times.
 *
 * @param t1 The later time.
 * @param t0 The earlier time.
 * @return Returns the difference in milliseconds.
 */
inline double operator-( time_type const &t1, time_type const &t0 ) {
#if defined(ZORBA_HAVE_CLOCKGETTIME)
  return (t1.tv_sec - t0.tv_sec) * 1000 + (t1.tv_nsec - t0.tv_nsec) / 1000000.0;
#elif defined(WIN32)
  return static_cast<double>((t1.time - t0.time) * 1000 + (t1.millitm - t0.millitm));
#else
  return (t1.tv_sec - t0.tv_sec) * 1000 + (t1.tv_usec - t0.tv_usec) / 1000.0;
#endif
}

/**
 * A %timer class is used to measure the amount of wall time used by some block
 * of code.
 */
class timer {
public:
  /**
   * Starts the timer.  Calling this function again resets the start time.
   */
  void start() {
    get_time( &start_ );
  }

  /**
   * Gets the amount of time that has elapsed since the last time start() was
   * called.
   *
   * @return Returns said amount of time in milliseconds.
   */
  double elapsed() const {
    time_type now;
    get_time( &now );
    return now - start_;
  }

private:
  time_type start_;
};

} // namespace wall

///////////////////////////////////////////////////////////////////////////////

} // namespace time
} // namespace zorba

#endif /* ZORBA_UTIL_TIMER_H */
/*
* Local variables:
* mode: c++
* End:
*/
/* vim:set et sw=2 ts=2: */
