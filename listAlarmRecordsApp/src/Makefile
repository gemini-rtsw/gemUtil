TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE

#=============================
# Build a support module called <APPNAME>

LIBRARY_IOC += listAlarmRecords

# <APPNAME>.dbd will be created and installed
DBD += listAlarmRecords.dbd

# listAlarmRecords.dbd will be made up from these files:
listAlarmRecords_DBD += base.dbd
# List local .dbd files here
# listAlarmRecords_DBD += xxx.dbd

# Include dbd files for external support modules:
# listAlarmRecords_DBD += genSubRecord.dbd

# specify all source files to be compiled
# including sequencer (.st) source files
listAlarmRecords_SRCS += listAlarmRecords.c
#listAlarmRecords_SRCS += xxx.st

#=============================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

