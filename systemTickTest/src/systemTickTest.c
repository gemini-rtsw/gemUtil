#include <stdio.h>
#include <epicsThread.h>
#include <epicsTime.h>
#include "iocsh.h"
#include "epicsExport.h"

#define MAX_LOOPS 1000
#define MAX_TIMES 8

void systemTickTest()
{

    int itime, iloop;
    epicsTimeStamp startTime, endTime;
    double elapsedTime;
    double sleepTimes[MAX_TIMES] = {0.001, 0.00125, 0.0015, 0.002, 0.0025, 0.005, 0.01, 0.02 };

    printf("EPICS Thread Quantum set to %f\n",epicsThreadSleepQuantum());
    for (itime=0; itime<MAX_TIMES; itime++) {

        epicsTimeGetCurrent(&startTime);

        /* Interval between fundamental epoch J2000.0 and given epoch (JC). */
        for (iloop=0; iloop<MAX_LOOPS; iloop++) {

            epicsThreadSleep(sleepTimes[itime]);
        }
        epicsTimeGetCurrent(&endTime);
        elapsedTime = epicsTimeDiffInSeconds(&endTime, &startTime);
        printf("Elapsed time to sleep %d times %f seconds = %f\n", MAX_LOOPS, sleepTimes[itime], elapsedTime);
    }

    printf("System Tick Test Finished\n");
}


static const iocshFuncDef systemTickTestDef =
{ "systemTickTest", 0, (const iocshArg *[]) { } };

static void systemTickTestRegistrar(void)
{
    iocshRegister(&systemTickTestDef, systemTickTest);
}

epicsExportRegistrar(systemTickTestRegistrar);


