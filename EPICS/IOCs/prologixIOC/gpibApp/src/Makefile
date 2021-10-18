TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#=============================
# Build the IOC application

PROD_IOC = gpib
# gpib.dbd will be created and installed
DBD += gpib.dbd

# gpib.dbd will be made up from these files:
gpib_DBD += base.dbd

# Include dbd files from all support applications:
gpib_DBD += calc.dbd
gpib_DBD += drvPrologixGPIB.dbd
gpib_DBD += stream.dbd
gpib_DBD += asyn.dbd

# Add all the support libraries needed by this IOC
gpib_LIBS += calc
gpib_LIBS += drvPrologixGPIB
gpib_LIBS += stream
gpib_LIBS += asyn

# gpib_registerRecordDeviceDriver.cpp derives from gpib.dbd
gpib_SRCS += gpib_registerRecordDeviceDriver.cpp

# Build the main IOC entry point on workstation OSs.
gpib_SRCS_DEFAULT += gpibMain.cpp
gpib_SRCS_vxWorks += -nil-

# Add support from base/src/vxWorks if needed
#gpib_OBJS_vxWorks += $(EPICS_BASE_BIN)/vxComLibrary

# Finally link to the EPICS Base libraries
gpib_LIBS += $(EPICS_BASE_IOC_LIBS)

#===========================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

