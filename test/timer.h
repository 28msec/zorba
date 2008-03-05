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

public:
    // timer routines
    void start();
    void end();
    void suspend();
    void resume();

    double getClock();
#ifndef WIN32
    double getTime();
#endif
    // print all information
    std::ostream& print(std::ostream& os);
    bool isRunning();
};
#endif

/* vim:set ts=2 sw=2: */
/*
 * Local variables:
 * mode: c++
 * End:
 */
