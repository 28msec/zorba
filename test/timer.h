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
/**
 * Class to measure execution time based on CPU clocks and system time.
 * made by Dongseop Kwon (subby@db.snu.ac.kr), 23/07/2003
 */


#ifndef ZORBA_TIMER_H
#define ZORBA_TIMER_H

#include <ctime>
#ifndef WIN32
#include <sys/time.h>
#else
#include <time.h>
#endif

#include <iostream>


class Timer
{
    clock_t startClock;
    clock_t suspendClock;
    clock_t endClock;

#ifndef WIN32
    double startTime;
    double endTime;
    double suspendTime;
#endif

		bool suspended;
    bool running;
    bool verbose;

public:
    // timer routines
    void start();
    void end();
    void suspend();
    void resume();

    double getClock();
    double getTime();

    // print all information
    std::ostream& print(std::ostream& os);
    bool isRunning();

  Timer(bool start = true, bool verbose = false);
};
#endif

/* vim:set ts=2 sw=2: */
/*
 * Local variables:
 * mode: c++
 * End:
 */
