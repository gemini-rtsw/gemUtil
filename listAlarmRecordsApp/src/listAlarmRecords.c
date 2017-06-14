#include "epicsStdio.h"
#include "epicsStdioRedirect.h"
#include "dbStaticLib.h"
#include "epicsString.h"
#include "iocsh.h"
#include "epicsExport.h"

extern DBBASE *pdbbase;

void listAlarmRecords()
{
    long status;
    DBENTRY dbentry;
    dbInitEntry(pdbbase, &dbentry);
    for (status = dbFirstRecordType(&dbentry); !status; status = dbNextRecordType(&dbentry))
        for (status = dbFirstRecord(&dbentry); !status; status = dbNextRecord(&dbentry))
        {
            if (dbFindField(&dbentry, "SEVR") != 0) continue;
            if (dbGetMenuIndex(&dbentry) != 0)
                printf("%s %s\n", dbGetRecordName(&dbentry), dbGetString(&dbentry));
        }
}

static const iocshFuncDef listAlarmRecordsDef =
{ "listAlarmRecords", 0, (const iocshArg *[]) {
                                              }};

static void listAlarmRecordsRegistrar(void)
{
    iocshRegister(&listAlarmRecordsDef, listAlarmRecords);
}

epicsExportRegistrar(listAlarmRecordsRegistrar);
