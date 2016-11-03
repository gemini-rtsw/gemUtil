TOP=../..
include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE

#----------------------------------------------------
# Find any .sym files in the Db directory
vpath %.sym ..

# Install database files created from .sch files
# using TDCT (or just install .db files) into <top>/db.
# TDCT_CFG can be redefined here if needed
#TDCT_CFG = ../tdct.cfg

# Make depends on all .sch files
DEPSCHS = $(wildcard ../*.sch)

# Add target .db files below here. Each must
# correspond to a .sch file
DB += timer.db

TEMPLATES_DIR = schematics
TEMPLATES += timer.sch
TEMPLATES += timer.sym


include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE
#
#
clean:: 
	$(RM) *.bak *.dat
