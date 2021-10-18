#!../../bin/linux-arm/sampleIOC

#- You may have to change sampleIOC to something else
#- everywhere it appears in this file

< envPaths

cd "${TOP}"

## Register all support components
dbLoadDatabase "dbd/sampleIOC.dbd"
sampleIOC_registerRecordDeviceDriver pdbbase

## Load record instances
dbLoadTemplate "db/user.substitutions"
dbLoadRecords "db/sampleIOCVersion.db", "user=epics"
dbLoadRecords "db/dbSubExample.db", "user=epics"

#quick mcc devSupport .... only channel 0
dbLoadRecords("db/mcc.db", "P=test:mcc, D=MCC118Demo, C=0")

#- Set this to see messages from mySub
#var mySubDebug 1

#- Run this to trace the stages of iocInit
#traceIocInit

cd "${TOP}/iocBoot/${IOC}"
iocInit

## Start any sequence programs
#seq sncExample, "user=epics"
