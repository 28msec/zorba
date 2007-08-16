#include "timer.h"
#include <iostream>


//#define DEBUG

void Timer::start()
{
    startClock = clock();
    struct timeval stime;
    gettimeofday(&stime, NULL);
    startTime=(double)stime.tv_sec+(1.e-6)*stime.tv_usec;
#ifdef DEBUG

    printf("Start time: %lf\n",startTime);
#endif

    suspended = false;
    running = true;
}

void Timer::end()
{
    endClock = clock();
    struct timeval etime;
    gettimeofday(&etime, NULL);
    endTime=(double)etime.tv_sec+(1.e-6)*etime.tv_usec;
    running = false;
#ifdef DEBUG

    printf("End time: %lf\n",endTime);
#endif
}

void Timer::suspend()
{
    suspendClock = clock();
    struct timeval sustime;
    gettimeofday(&sustime,NULL);
    suspendTime = (double)sustime.tv_sec+(1.e-6)*sustime.tv_usec;
#ifdef DEBUG

    printf("Suspend time: %lf\n",suspendTime);
#endif

    suspended = true;
}

void Timer::resume()
{
    startClock = startClock +(clock()-suspendClock);
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
    if (!suspended)
        return (double)(endTime-startTime);

    return (double)(suspendTime-startTime);
}


void Timer::print()
{
	std::cout << "Duration (with System Time): " << getTime() << "s" << std::endl;
	std::cout << "Duration (with CPU Clocks): " << getClock() << "s" << std::endl;
}

bool Timer::isRunning()
{
    return running;
}
