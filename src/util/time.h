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
#ifndef ZORBA_UTIL_TIME_H
#define ZORBA_UTIL_TIME_H

namespace zorba {

  namespace time {

#ifdef ZORBA_HAVE_RUSAGE_FUNCTION
#include <sys/time.h>
#include <sys/resource.h>
    typedef struct rusage timeinfo;
    typedef struct timeval time_detail;

    double get_time_elapsed (const time_detail &t0, const time_detail &t1) {
      return ((t1.tv_sec - t0.tv_sec) * 1000.0) + ((t1.tv_usec - t0.tv_usec) / 1000.0);
    }
#define ZORBA_HAVE_SYSTEM_TIME 1
    time_detail extract_user_time_detail (const timeinfo &rusage) {
      return rusage.ru_utime;
    }
    void get_timeinfo (timeinfo &t) {
      getrusage (RUSAGE_SELF, &t);
    }

#else

#include <time.h>
    typedef clock_t timeinfo;
    typedef clock_t time_detail;

    double get_time_elapsed (const time_detail &t0, const time_detail &t1) {
      return (double) (t1 - t0) / (CLOCKS_PER_SEC / 1000);
    }
    time_detail extract_user_time_detail (const timeinfo &rusage) {
      return rusage;
    }
    void get_timeinfo (timeinfo &t) {
      t = clock ();
    }
#define ZORBA_HAVE_SYSTEM_TIME 0

#endif

  }  // ::time

}  // ::zorba

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
