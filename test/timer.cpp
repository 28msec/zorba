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
#include "timer.h"
#include <iostream>
#include <stdio.h>


//#define DEBUG

Timer::Timer (bool start_, bool verbose_) : verbose (verbose_)
{
  if (start_) start ();
}

void Timer::start()
{
    startClock = clock();
#ifndef WIN32
    struct timeval stime;
    gettimeofday(&stime, NULL);
    startTime=(double)stime.tv_sec+(1.e-6)*stime.tv_usec;
    if (verbose) printf("Start time: %lf\n",startTime);
#else//WIN32
    if (verbose) printf("Start time: %lf\n",(double)startClock/CLOCKS_PER_SEC);
#endif

    suspended = false;
    running = true;
}

void Timer::end()
{
    endClock = clock();
#ifndef WIN32
    struct timeval etime;
    gettimeofday(&etime, NULL);
    endTime=(double)etime.tv_sec+(1.e-6)*etime.tv_usec;
    if (verbose) printf("End time: %lf\n",endTime);
#else///WIN32
    if (verbose) printf("End time: %lf\n",(double)endClock/CLOCKS_PER_SEC);
#endif
    running = false;
}

void Timer::suspend()
{
    suspendClock = clock();
#ifndef WIN32
    struct timeval sustime;
    gettimeofday(&sustime,NULL);
    suspendTime = (double)sustime.tv_sec+(1.e-6)*sustime.tv_usec;
    if (verbose) printf("Suspend time: %lf\n",suspendTime);
#else
    if (verbose) printf("Suspend time: %lf\n",(double)suspendClock/CLOCKS_PER_SEC);
#endif

    suspended = true;
}

void Timer::resume()
{
    clock_t   resumeClock = clock();
    startClock = startClock +(resumeClock-suspendClock);
#ifndef WIN32
    struct timeval sustime;
    gettimeofday(&sustime,NULL);
    double resumeTime = (double)sustime.tv_sec+(1.e-6)*sustime.tv_usec;
    if (verbose) printf("Resume time: %lf\n",resumeTime);
    startTime = startTime +(resumeTime-suspendTime);
    if (verbose) printf("New start Time: %lf\n",startTime);
#else//WIN32
    if (verbose) printf("Resume time: %lf\n",(double)resumeClock/CLOCKS_PER_SEC);
#endif

    suspended = false;
}

double Timer::getClock()
{
    if (!suspended)
        return (double)(endClock-startClock)/(double) CLOCKS_PER_SEC;

    return (double)(suspendClock-startClock)/(double) CLOCKS_PER_SEC;
}


double Timer::getTime()
{
#ifndef WIN32
    if (!suspended)
        return (double)(endTime-startTime);

    return (double)(suspendTime-startTime);
#else
    return 0;
#endif
}


std::ostream& Timer::print(std::ostream& os)
{
#ifndef WIN32
  os << "Duration (with System Time): " << getTime() << " s" << std::endl;
#endif
  os << "Duration (with CPU Clocks): " << getClock() << " s" << std::endl;

  return os;
}

bool Timer::isRunning()
{
    return running;
}
