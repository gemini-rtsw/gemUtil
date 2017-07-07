TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#==================================================
# build a support library

LIBRARY_IOC_RTEMS += electricFence

# xxxRecord.h will be created from xxxRecord.dbd
#DBDINC += xxxRecord
# install electricFence.dbd into <top>/dbd
#DBD += electricFence.dbd

# specify all source files to be compiled and added to the library
electricFence_SRCS += efence.c

#electricFence_LIBS += $(EPICS_BASE_IOC_LIBS)

#===========================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

