TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE

#=============================
# Build a support module called <APPNAME>

LIBRARY_IOC += systemTickTools

# systemTickTools.dbd will be created and installed
DBD += systemTickTools.dbd

# systemTickTools.dbd will be made up from these files:
# List local .dbd files here
# systemTickTools_DBD += xxx.dbd

# Include dbd files for external support modules:
# systemTickTools_DBD += genSubRecord.dbd

# specify all source files to be compiled
systemTickTools_SRCS += systemTickTools.c

#=============================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

