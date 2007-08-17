/**
 * Class to measure execution time based on CPU clocks and system time.
 * made by Dongseop Kwon (subby@db.snu.ac.kr), 23/07/2003
 */


#ifndef XQP_TIMER_H
#define XQP_TIMER_H

#include <ctime>
#include <sys/time.h>

class Timer
{
    clock_t startClock;
    clock_t suspendClock;
    clock_t endClock;
    double startTime;
    double endTime;
    double suspendTime;
    bool suspended;
    bool running;

public:
    // timer routines
    void start();
    void end();
    void suspend();
    void resume();

    double getClock();
    double getTime();

    // print all information
    void print();
    bool isRunning();
};
#endif
