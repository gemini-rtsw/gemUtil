#include <stdio.h>
#include <epicsThread.h>
#include <epicsTime.h>
#include "iocsh.h"
#include "epicsExport.h"

#define MAX_LOOPS 1000
#define MAX_TIMES 8
#define SECONDS_TO_MICROSECS 1e6

void systemTickShow() {
    printf("EPICS Thread Quantum set to %f seconds\n",epicsThreadSleepQuantum());
}

void systemTickTest()
{

    int itime, iloop;
    epicsTimeStamp startTime, endTime;
    double elapsedTime;
    double sleepTimes[MAX_TIMES] = {0.001, 0.00125, 0.0015, 0.002, 0.0025, 0.005, 0.01, 0.02 };

    printf("EPICS Thread Quantum set to %f seconds\n",epicsThreadSleepQuantum());
    for (itime=0; itime<MAX_TIMES; itime++) {
        int diff_us; /*Difference in microseconds*/

        epicsTimeGetCurrent(&startTime);

        /* Interval between fundamental epoch J2000.0 and given epoch (JC). */
        for (iloop=0; iloop<MAX_LOOPS; iloop++) {

            epicsThreadSleep(sleepTimes[itime]);
        }
        epicsTimeGetCurrent(&endTime);
        elapsedTime = epicsTimeDiffInSeconds(&endTime, &startTime);
        diff_us = (elapsedTime - sleepTimes[itime]*MAX_LOOPS) * SECONDS_TO_MICROSECS;

        printf("Elapsed time to sleep %d times @ %f secs = %f secs [expected %f, diff=%d (us)]\n",
                MAX_LOOPS, sleepTimes[itime], elapsedTime, sleepTimes[itime]*MAX_LOOPS, diff_us);

    }

    printf("System Tick Test Finished\n");
}


static const iocshFuncDef systemTickTestDef =
{ "systemTickTest", 0, (const iocshArg *[]) { } };

static const iocshFuncDef systemTickShowDef =
{ "systemTickShow", 0, (const iocshArg *[]) { } };

static void systemTickToolsRegistrar(void)
{
    iocshRegister(&systemTickTestDef, systemTickTest);
    iocshRegister(&systemTickShowDef, systemTickShow);
}

epicsExportRegistrar(systemTickToolsRegistrar);


