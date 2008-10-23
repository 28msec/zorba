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

#ifndef ZORBA_UTIL_UUID_SYSDEP_H
#define ZORBA_UTIL_UUID_SYSDEP_H

#include "zorbatypes/representations.h"

#ifdef WIN32
  #include <windows.h>
#else
  #include <sys/types.h>
  #include <sys/time.h>
#endif

/* Set the following to a calls to get and release a global lock */
#define LOCK
#define UNLOCK

// /* Set this to what your compiler uses for 64-bit data type */
#ifdef WIN32
  #define unsigned64_t unsigned __int64
  #define I64(C) C
#else
  #define unsigned64_t unsigned long long
  #define I64(C) C##LL
#endif

namespace zorba {

/* set the following to the number of 100ns ticks of the actual
resolution of your system's clock */
#define UUIDS_PER_TICK 1024

typedef struct {
  char nodeID[6];
} uuid_node_t;

void get_system_time(xqp_ulong *uuid_time);

}/*namespace zorba*/

#endif /* ZORBA_UTIL_UUID_SYSDEP_H */
