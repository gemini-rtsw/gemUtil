/*
 * Copyright 1996 Association of Universities for Research in Astronomy, Inc.
 * See the file COPYRIGHT for more details.
 *
 * FILENAME
 * hb2health.c
 *
 * FUNCTION NAME(S)
 * hb2healthHeartbeatSub  - Check heartbeat and set health accordingly
 * hb2healthealthSirSub   - Convert health code into message
 *
 */

#include <stdlib.h>
#include <string.h>

#include <genSubRecord.h>
#include <dbFldTypes.h>
#include <sirRecord.h>
#include <epicsGeneralTime.h>
#include <epicsExport.h>
#include <registryFunction.h>

#define IN_HEARTBEAT_TIMEOUT   *((long *) pgsub->a)
#define IN_HEARTBEAT_HB      *((long *) pgsub->b)
#define IN_HEARTBEAT_DEBUG   *((long *) pgsub->f)
#define   OUT_HEARTBEAT_HEALTH   *((long *) pgsub->vala)
#define   OUT_HEARTBEAT_OLDHB   *((long *) pgsub->valb)
#define   OUT_HEARTBEAT_OLDTIME   *((long *) pgsub->valc)

/*
 *  * Health values.
 *   */
#define HEALTH_GOOD     0
#define HEALTH_WARNING  1
#define HEALTH_BAD      2
#define HEALTH_INVALID  3


/*
 *+
 * FUNCTION NAME:
 * hb2healthHeartbeatSub
 *
 * INVOCATION:
 * hb2healthHeartbeatSub (psub)
 *
 * PARAMETERS: (">" input, "!" modified, "<" output)
 * (>) psub (struct subRecord *)   sub record pointer
 * 
 * FUNCTION VALUE:
 * (long)       always zero
 *
 * PURPOSE:
 * Check heartbeat and set health accordingly
 *
 * DESCRIPTION:
 * This routine checks whether the heartbeat coming from a "device" changes
 * in less than a certain ammount of time. If that's the case then set the
 * health to GOOD, otherwise set it to BAD. The maximum time is read from
 * one of the record fields and it's actually the maximum number of times
 * this routine can execute before changing the health. This number can be
 * calculated as follows:
 *
 *   max = timeout_time(seconds) / scan_time(seconds)
 *
 * EPICS INPUT FIELDS:
 * (long)   A   device heartbeat
 * (long)   B   debug level
 *
 * EPICS OUTPUT FIELDS:
 * (long)    VAL   health
 *
 * EXTERNAL VARIABLES:
 * None
 *
 * PRIOR REQUIREMENTS:
 * None
 *
 * DEFICIENCIES:
 * This routine doesn't really check for time, but instead for number of
 * iterations. The time depends on the scan rate of the record calling this
 * routine.
 *-
 */
long hb2healthHeartbeatSub (struct genSubRecord *pgsub)
{
   long            curhb, oldhb, health;
   long            debug, tmout, tdiff;
   epicsTimeStamp  time, otime = {0,0};

   /*
    * Get input links.
    */
   tmout = IN_HEARTBEAT_TIMEOUT;
   debug = IN_HEARTBEAT_DEBUG;
   curhb = IN_HEARTBEAT_HB;
   oldhb = OUT_HEARTBEAT_OLDHB;
   otime.secPastEpoch = OUT_HEARTBEAT_OLDTIME;
#if 0
   count = OUT_HEARTBEAT_COUNT;
#endif

   /*
    * Get current clock time in seconds since the time the machine
    * was last rebooted. Don't worry about counter overflows.
    */
   //time = tickGet () / sysClkRateGet ();   /* seconds */
   epicsTimeGetCurrent(&time);

#if 0
   /*
    * Assign a default value to the timeout count if it's negative
    * or zero. This value should be initialized using pvload
    * and/or a dm screen (NOW DONE IN CAPFAST).
    */
   if (tmout <= 0)
       tmout = DEF_FROZEN_COUNT;
#endif

#if 0
   if (DEBUG_MIN)
       printErr ("heartbeatSub: debug=%d\n", debug);

   if (DEBUG_FULL) {
       printErr ("heartbeatSub: curhb=%d, oldhb=%d\n",
            (int) curhb, (int) oldhb);
   }
#endif
         
#if 0
   /*
    * Check whether the heartbeat has changed. Reset the beat
    * counter and update the old heartbeat value if that's the
    * case. Increment the counter otherwise.
    */
   if (oldhb != curhb) {
       oldhb = curhb;
       count = 0;
   } else
       count++;

   /*
    * Check whether the heartbeat has been frozen for more than
    * the maximum allowed time, or if it has the uninitialized value
    * zero. Change output health and message accordingly.
    */
   if (count < tmout && curhb != 0)
       health = HEALTH_GOOD;
   else
       health = HEALTH_BAD;
#endif

   /*
    * Check whether the heartbeat has changed since the last time.
    * If that's the case reset the time it last changed to now.
    * Otherwise calculate the time difference since the last change.
    * The current approach could give a big difference every ~400
    * days because of a tick counter overflow to negative numbers.
    * It's very unlikely that the system will be up for that long
    * and in the worst case the health will be reevaluated in the
    * next iteration and set back to its normal value.
    */
   if (oldhb != curhb) {
       OUT_HEARTBEAT_OLDTIME = time.secPastEpoch;
       tdiff = 0;
   } else
       //tdiff = time - otime;
       tdiff = (long)epicsTimeDiffInSeconds(&time, &otime);

   /* Check whether the time the heartbeat last changed is greater
    * than the timeout. Also check whether the heartbeat is zero,
    * i.e. never initialized. In both cases set the heath to BAD.
    */
   if (tdiff < tmout && curhb != 0)
       health = HEALTH_GOOD;
   else
       health = HEALTH_BAD;

   /*
    * Update output links
    */
   OUT_HEARTBEAT_HEALTH = health;
   OUT_HEARTBEAT_OLDHB   = curhb;

#if 0
   /*
    * Update output links
    */
   OUT_HEARTBEAT_HEALTH = health;
   OUT_HEARTBEAT_OLDHB  = oldhb;
   OUT_HEARTBEAT_COUNT  = count;
#endif

#if 0
   if (DEBUG_FULL) {
       printErr (
      "hb2healthHeartbeatSub: curhb=%d, oldhb=%d, count=%d, health=%d\n",
      (int) curhb, (int) oldhb, count, (int) health);
   }
#endif

   return (0L);
}
epicsRegisterFunction(hb2healthHeartbeatSub);


/*
 *+
 * FUNCTION NAME:
 * hb2healthSirSub
 *
 * INVOCATION:
 * hb2healthSirSub (psir)
 *
 * PARAMETERS: (">" input, "!" modified, "<" output)
 * (>) psir (struct sirRecord *)   SIR record pointer
 * 
 * FUNCTION VALUE:
 * (long)       always returns zero
 *
 * PURPOSE:
 * Convert health code into message
 *
 * DESCRIPTION:
 * This routine converts the health code in VAL into the corresponding
 * message. The program can handle STRING or LONG values in the VAL field.
 * The GWS code uses numeric values for the health, but the TCS expects a
 * string in the top level health.
 *
 * EPICS INPUT FIELDS:
 * (string|long)   VAL   health level code
 *
 * EPICS OUTPUT FIELDS:
 * (string)      IMSS   health level message
 *            INVALID if no match
 *
 * EXTERNAL VARIABLES:
 * None
 *
 * PRIOR REQUIREMENTS:
 * None
 *
 * DEFICIENCIES:
 * It is assumed that VAL will be either STRING or LONG. No error is
 * generated if this is not true.
 *-
 */
long hb2healthSirSub (struct sirRecord *psir)
{
   int   health;
   char   hstr[40];

   /* Check data type of VAL field and read the value accodingly.
    */
   if (psir->ftvl == DBF_STRING)
       health = atoi (psir->val);
   else
       health = *(long *) psir->val;

   /* Convert (string or long) health code into a readable word.
    */
   if (health == HEALTH_GOOD)
       strcpy (hstr, "GOOD");
   else if (health == HEALTH_WARNING)
       strcpy (hstr, "WARNING");
   else if (health == HEALTH_BAD)
       strcpy (hstr, "BAD");
   else
       strcpy (hstr, "INVALID");

   /* Update output fields. The value needs to be updated only when
    * it's a string because the health code (in string representation)
    * code needs to be converted into a readable word.
    */
   if (psir->ftvl == DBF_STRING)
       strcpy (psir->val, hstr);
   strcpy (psir->imss, hstr);

   return(0L);
}
epicsRegisterFunction(hb2healthSirSub);
