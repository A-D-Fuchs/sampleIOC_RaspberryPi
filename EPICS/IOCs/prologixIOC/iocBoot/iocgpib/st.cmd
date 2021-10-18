#!../../bin/linux-arm/gpib 

#- You may have to change gpib to something else
#- everywhere it appears in this file

epicsEnvSet("IOC","Prologix")
epicsEnvSet("TOP","/home/epics/EPICS/IOCs/prologixIOC") 
epicsEnvSet("STREAM_PROTOCOL_PATH", "$(TOP)/db")
epicsEnvSet("PROLOGIX_ADDRESS", "$(PROLOGIX_ADDRESS=10.131.162.32)");
epicsEnvSet("P", "$(P=Prologix:)");
epicsEnvSet("R", "$(R=Test:)");
epicsEnvSet("A", "$(A=5)");
epicsEnvSet("B", "$(B=23)");
#epicsEnvSet("EPICS_CAS_INTF_ADDR_LIST", "localhost");

cd "${TOP}"

## Register all support components
dbLoadDatabase "dbd/gpib.dbd"
gpib_registerRecordDeviceDriver pdbbase

# Set up ASYN port
prologixGPIBConfigure("L0", "$(PROLOGIX_ADDRESS)")
asynOctetSetInputEos("L0", -1, "\n")
asynSetTraceIOMask("L0_TCP", -1, 0x2)
asynSetTraceMask("L0_TCP", -1, 0x9)
asynSetTraceIOMask("L0", $(A), 0x2)
asynSetTraceMask("L0", $(A), 0x9)

## Load record instances
dbLoadRecords("db/gpib_win.db","P=$(IOC):,R=Test:,PORT=L0,A=11,B=23")

iocInit

## Start any sequence programs
#seq sncxxx,"user=od93yces"
