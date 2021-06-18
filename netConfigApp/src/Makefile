TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE

#=============================
# Build a support module called <APPNAME>

LIBRARY_IOC += netConfig

# <APPNAME>.dbd will be created and installed
DBD += netConfig.dbd

# netConfig.dbd will be made up from these files:
netConfig_DBD += net_config.dbd
# List local .dbd files here
# netConfig_DBD += xxx.dbd

# Include dbd files for external support modules:
# netConfig_DBD += genSubRecord.dbd

# specify all source files to be compiled
# including sequencer (.st) source files
netConfig_SRCS += net_config.c
#netConfig_SRCS += xxx.st

#=============================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

