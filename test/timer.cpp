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


//#define DEBUG

void Timer::start()
{
    startClock = clock();
#ifndef WIN32
    struct timeval stime;
    gettimeofday(&stime, NULL);
    startTime=(double)stime.tv_sec+(1.e-6)*stime.tv_usec;
#ifdef DEBUG
    printf("Start time: %lf\n",startTime);
#endif
#else//WIN32
#ifdef DEBUG
		printf("Start time: %lf\n",(double)startClock/CLOCKS_PER_SEC);
#endif
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
#ifdef DEBUG
    printf("End time: %lf\n",endTime);
#endif
#else///WIN32
#ifdef DEBUG
		printf("End time: %lf\n",(double)endClock/CLOCKS_PER_SEC);
#endif
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
#ifdef DEBUG
    printf("Suspend time: %lf\n",suspendTime);
#endif
#else
#ifdef DEBUG
    printf("Suspend time: %lf\n",(double)suspendClock/CLOCKS_PER_SEC);
#endif
#endif

    suspended = true;
}

void Timer::resume()
{
		clock_t		resumeClock = clock();
    startClock = startClock +(resumeClock-suspendClock);
#ifndef WIN32
    struct timeval sustime;
    gettimeofday(&sustime,NULL);
    double resumeTime = (double)sustime.tv_sec+(1.e-6)*sustime.tv_usec;
#ifdef DEBUG
    printf("Resume time: %lf\n",resumeTime);
#endif
    startTime = startTime +(resumeTime-suspendTime);
#ifdef DEBUG
    printf("New start Time: %lf\n",startTime);
#endif
#else//WIN32
#ifdef DEBUG
    printf("Resume time: %lf\n",(double)resumeClock/CLOCKS_PER_SEC);
#endif
#endif

    suspended = false;
}

double Timer::getClock()
{
    if (!suspended)
        return (double)(endClock-startClock)/(double) CLOCKS_PER_SEC;

    return (double)(suspendClock-startClock)/(double) CLOCKS_PER_SEC;
}

#ifndef WIN32
double Timer::getTime()
{
    if (!suspended)
        return (double)(endTime-startTime);

    return (double)(suspendTime-startTime);
}
#endif

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
