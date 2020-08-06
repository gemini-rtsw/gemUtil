TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE

#=============================
# Build a support module called <APPNAME>


# timer.dbd will be created and installed
DBD += timer.dbd
DBD += timerSupp.dbd

timerSupp_DBD += geminiRecords.dbd

timer_DBD += $(timerSupp_DBD)
timer_DBD += base.dbd


#=============================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

