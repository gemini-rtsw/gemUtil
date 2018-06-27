TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE

#=============================
# Build a support module called <APPNAME>

LIBRARY_IOC += systemTickTest

# systemTickTest.dbd will be created and installed
DBD += systemTickTest.dbd

# systemTickTest.dbd will be made up from these files:
systemTickTest_DBD += base.dbd
# List local .dbd files here
# systemTickTest_DBD += xxx.dbd

# Include dbd files for external support modules:
# systemTickTest_DBD += genSubRecord.dbd

# specify all source files to be compiled
systemTickTest_SRCS += systemTickTest.c

#=============================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

