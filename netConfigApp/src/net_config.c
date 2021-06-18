#include <epicsExport.h>

#ifdef EPICS_RTEMS
#include <iocsh.h>
#include <epicsRtemsInitHooks.h>
#include <epicsThread.h>
#include <errlog.h>
#include <sys/ioctl.h>

static int pending_chars(void) {
	int n;

	ioctl(0, FIONREAD, &n);

	return n;
}

int epicsRtemsInitPreSetBootConfigFromNVRAM(struct rtems_bsdnet_config *config)
{
#ifdef RTEMS_NETWORK_CONFIG_MBUF_SPACE
	rtems_bsdnet_config.mbuf_bytecount = RTEMS_NETWORK_CONFIG_MBUF_SPACE*1024;
#endif
#ifdef RTEMS_NETWORK_CONFIG_CLUSTER_SPACE
	rtems_bsdnet_config.mbuf_cluster_bytecount = RTEMS_NETWORK_CONFIG_CLUSTER_SPACE*1024;
#endif
	return 0;
}

static void
rtems_netstat_mbufs (unsigned int times)
{
	if (times != 0)
		errlogPrintf("\x1b[2J");
	do {
		if (times != 0) {
			errlogPrintf("\x1b[HPress ESC to stop\n");
		}
		else {
		}
		rtems_bsdnet_show_mbuf_stats ();
		while (pending_chars() > 0) {
			int c = getchar();
			if ((c == 'q') || (c == '\x1b')) {
				times = 0;
				break;
			}
		}
		if (times != 0) {
			epicsThreadSleep(0.2);
		}
	} while(times != 0);
}

static const iocshArg netStatArg0 = { "times",iocshArgInt};
static const iocshArg * const netStatArgs[1] = {&netStatArg0};
static const iocshFuncDef netStatFuncDef = {"mbufs",1,netStatArgs};
static void netStatCallFunc(const iocshArgBuf *args)
{
	rtems_netstat_mbufs(args[0].ival);
}

static void iocshRegisterMbufs (void)
{
	iocshRegister(&netStatFuncDef, netStatCallFunc);
}
#else
static void iocshRegisterMbufs (void) {
	// Not meant for other SO
}
#endif // defined

epicsExportRegistrar(iocshRegisterMbufs);
