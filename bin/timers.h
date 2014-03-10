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

#ifndef ZORBA_CMD_TIMERS_H
#define ZORBA_CMD_TIMERS_H

// standard
#include <iostream>

// Zorba
#include <zorba/util/time.h>

///////////////////////////////////////////////////////////////////////////////

#define DECLARE_TIMER(KIND)                       \
  zorba::time::walltime start_##KIND##_walltime;  \
  zorba::time::walltime stop_##KIND##_walltime;   \
  zorba::time::cputime start_##KIND##_cputime;    \
  zorba::time::cputime stop_##KIND##_cputime;     \
  double elapsed_##KIND##_walltime;               \
  double elapsed_##KIND##_cputime

struct Timers {
  enum kind {
    init,
    deinit,
    comp,
    exec,
    unload,
    plan_save,
    plan_load,
    total
  };

  unsigned long num_execs_;

  DECLARE_TIMER( init );
  DECLARE_TIMER( deinit );
  DECLARE_TIMER( comp );
  DECLARE_TIMER( exec );
  DECLARE_TIMER( load );
  DECLARE_TIMER( unload );
  DECLARE_TIMER( plan_save );
  DECLARE_TIMER( plan_load );
  DECLARE_TIMER( total );

  Timers( unsigned long num_execs );

  void startTimer( kind, unsigned long iteration );
  void stopTimer( kind, unsigned long iteration );

  std::ostream& print( std::ostream&, bool );
};

#undef DECLARE_TIMER

///////////////////////////////////////////////////////////////////////////////

#endif /* ZORBA_CMD_TIMERS_H */
/* vim:set et sw=2 ts=2: */
