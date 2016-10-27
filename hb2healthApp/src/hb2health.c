/*
 * Copyright 1996 Association of Universities for Research in Astronomy, Inc.
 * See the file COPYRIGHT for more details.
 *
 * FILENAME
 * hb2health.c
 *
 * FUNCTION NAME(S)
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
