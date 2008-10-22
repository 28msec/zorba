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

#include "sysdep.h"

namespace zorba {
/* system dependent call to get the current system time. Returned as
   100ns ticks since UUID epoch, but resolution may be less than
   100ns. */
#ifdef WIN32

void get_system_time(xqp_ulong *uuid_time)
{
  ULARGE_INTEGER time;

  /* NT keeps time in FILETIME format which is 100ns ticks since
  Jan 1, 1601. UUIDs use time in 100ns ticks since Oct 15, 1582.
  The difference is 17 Days in Oct + 30 (Nov) + 31 (Dec)
  + 18 years and 5 leap days, meaning P6653D*/
  GetSystemTimeAsFileTime((FILETIME *)&time);
  time.QuadPart +=  (xqp_ulong) (1000*1000*10)       // seconds
                  * (xqp_ulong) (60 * 60 * 24)       // days
                  * (xqp_ulong) (17+30+31+365*18+5); // 6653 of days
  *uuid_time = time.QuadPart;
}

#else

void get_system_time(xqp_ulong *uuid_time)
{
  struct timeval tp;

  gettimeofday(&tp, (struct timezone *)0);

  /* Offset between UUID formatted times and Unix formatted times.
  UUID UTC base time is October 15, 1582.
  Unix base time is January 1, 1970, meaning P141427D*/
  *uuid_time = ((xqp_ulong)tp.tv_sec * 10000000)
      + ((xqp_ulong)tp.tv_usec * 10)
      + I64(0x01B21DD213814000);
}

#endif
}/*namespace zorba*/
