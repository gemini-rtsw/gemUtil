TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE

#=============================
# Build a support module called <APPNAME>

LIBRARY_IOC += hb2health

# <APPNAME>.dbd will be created and installed
DBD += hb2health.dbd
hb2health_DBD += base.dbd
hb2health_DBD += geminiRecords.dbd
hb2health_DBD += hb2healthSubs.dbd

# specify all source files to be compiled
# including sequencer (.st) source files
hb2health_SRCS += hb2health.c

#=============================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

