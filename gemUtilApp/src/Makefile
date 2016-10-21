TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE

#=============================
# Build a support module called <APPNAME>

LIBRARY_IOC += gemUtil

# <APPNAME>.dbd will be created and installed
DBD += gemUtil.dbd

# gemUtil.dbd will be made up from these files:
gemUtil_DBD += base.dbd
# List local .dbd files here
# gemUtil_DBD += xxx.dbd

# Include dbd files for external support modules:
# gemUtil_DBD += genSubRecord.dbd

# specify all source files to be compiled
# including sequencer (.st) source files
#gemUtil_SRCS += xxx.c
#gemUtil_SRCS += xxx.st

#=============================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

