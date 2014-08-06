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

// local
#include "timers.h"

using namespace std;

///////////////////////////////////////////////////////////////////////////////

#define INIT_TIMER(KIND)          \
  elapsed_##KIND##_walltime( 0 ), \
  elapsed_##KIND##_cputime( 0 )

#define START_TIMER(KIND)                                       \
  zorba::time::get_current_walltime( start_##KIND##_walltime ); \
  zorba::time::get_current_cputime( start_##KIND##_cputime )

#define STOP_TIMER(KIND)                                        \
  zorba::time::get_current_walltime( stop_##KIND##_walltime );  \
  elapsed_##KIND##_walltime += zorba::time::get_walltime_elapsed( start_##KIND##_walltime, stop_##KIND##_walltime ); \
  zorba::time::get_current_cputime( stop_##KIND##_cputime );    \
  elapsed_##KIND##_cputime += zorba::time::get_cputime_elapsed( start_##KIND##_cputime, stop_##KIND##_cputime )

Timers::Timers( unsigned long num_execs ) :
  num_execs_( num_execs ),
  INIT_TIMER( init ),
  INIT_TIMER( deinit ),
  INIT_TIMER( comp ),
  INIT_TIMER( exec ),
  INIT_TIMER( load ),
  INIT_TIMER( unload ),
  INIT_TIMER( plan_save ),
  INIT_TIMER( plan_load ),
  INIT_TIMER( total )
{
}

void Timers::startTimer( kind k, unsigned long iteration ) {
  if ( iteration == 0 && num_execs_ > 1 )
    return;
  switch ( k ) {
    case init:
      START_TIMER( init );
      break;
    case deinit:
      START_TIMER( deinit );
      break;
    case total:
      START_TIMER( total );
      break;
    case comp:
      START_TIMER( comp );
      break;
    case exec:
      START_TIMER( exec );
      break;
    case unload:
      START_TIMER( unload );
      break;
    case plan_save:
      START_TIMER( plan_save );
      break;
    case plan_load:
      START_TIMER( plan_load );
      break;
  } // switch
}

void Timers::stopTimer( kind k, unsigned long iteration ) {
  if ( iteration == 0 && num_execs_ > 1 )
    return;
  switch ( k ) {
    case init:
      STOP_TIMER( init );
      break;
    case deinit:
      STOP_TIMER( deinit );
      break;
    case total:
      STOP_TIMER( total );
      break;
    case comp:
      STOP_TIMER( comp );
      break;
    case exec:
      STOP_TIMER( exec );
      break;
    case unload:
      STOP_TIMER( unload );
      break;
    case plan_save:
      STOP_TIMER( plan_save );
      break;
    case plan_load:
      STOP_TIMER( plan_load );
      break;
  } // switch
}

ostream& Timers::print( ostream &os, bool serializePlan ) {
  os.precision( 3 );
  os.setf( ios::fixed );

  os << "\nNumber of executions = " << num_execs_ << endl;

  unsigned long timeDiv = num_execs_ == 1 ? 1 : (num_execs_ - 1);
  double cWalltime = elapsed_comp_walltime / timeDiv;
  double eWalltime = elapsed_exec_walltime / timeDiv;
  double lWalltime = elapsed_load_walltime / timeDiv;
  double uWalltime = elapsed_unload_walltime / timeDiv;
  double psWalltime = elapsed_plan_save_walltime / timeDiv;
  double plWalltime = elapsed_plan_load_walltime / timeDiv;
  double tWalltime = elapsed_total_walltime / timeDiv;

  double cCputime = elapsed_comp_cputime / timeDiv;
  double eCputime = elapsed_exec_cputime / timeDiv;
  double lCputime = elapsed_load_cputime / timeDiv;
  double uCputime = elapsed_unload_cputime / timeDiv;
  double psCputime = elapsed_plan_save_cputime / timeDiv;
  double plCputime = elapsed_plan_load_cputime / timeDiv;
  double tCputime = elapsed_total_cputime / timeDiv;

  os << "Engine Startup Time     : " << elapsed_init_walltime
     << " (user: " << elapsed_init_cputime << ")"
     << " milliseconds" << endl;

  os << "Average Compilation Time: " << cWalltime
     << " (user: " << cCputime << ")"
     << " milliseconds" << endl;

  if ( serializePlan ) {
    os << "Average Plan Saving Time: " << psWalltime
       << " (user: " << psCputime << ")"
       << " milliseconds" << endl;
    
    os << "Average Plan Loading Time: " << plWalltime
       << " (user: " << plCputime << ")"
       << " milliseconds" << endl;
  }

  os << "Average Execution Time  : " << eWalltime - lWalltime
     << " (user: " << eCputime - lCputime  << ")"
     << " milliseconds" << endl;

  os << "Average Loading Time    : " << lWalltime
     << " (user: " << lCputime << ")"
     << " milliseconds" << endl;

  os << "Average Unloading Time  : " << uWalltime
     << " (user: " << uCputime << ")"
     << " milliseconds" << endl;

  os << "Average Total Time      : " << tWalltime
     << " (user: " << tCputime << ")"
     << " milliseconds" << endl;

  return os;
}

///////////////////////////////////////////////////////////////////////////////

/* vim:set et sw=2 ts=2: */
