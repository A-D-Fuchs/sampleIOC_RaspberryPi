#include <stdio.h>
#include <stdlib.h>
#include <dbAccess.h>
#include <devSup.h>
#include <recGbl.h>
#include <alarm.h>

#include <aiRecord.h>

#include <epicsExport.h>

#include <daqhats/daqhats.h>

struct mcc118State {
  unsigned int channel;
  unsigned int mccAddress;
};

static long init_record(aiRecord *prec)
{
  struct mcc118State* priv;
  unsigned long channelNr;

  priv=malloc(sizeof(struct mcc118State));
  if(!priv){
    recGblRecordError(S_db_noMemory, (void*)prec,
      "devAiMcc118 failed to allocate private struct");
    return S_db_noMemory;
  }

  priv->mccAddress = 1; // here fixed addr 1 ... inp? oooset ?
  int result = mcc118_open(priv->mccAddress);
  if(result != RESULT_SUCCESS){
    recGblRecordError(S_db_noMemory, (void*)prec,
      "devAiMcc118 failed to open device at address 1");
    return S_db_noMemory;
  }

  mcc118_blink_led(priv->mccAddress, 0); // blink continously, shows initialized

  recGblInitConstantLink(&prec->inp,DBF_ULONG,&channelNr);

  if(channelNr > 4) channelNr = 0;
  priv->channel=channelNr;
  prec->dpvt=priv;

  return 0;
}

static long read_ai(aiRecord *prec)
{
	double dumm;

  struct mcc118State* priv=prec->dpvt;
  if(!priv) {
    (void)recGblSetSevr(prec, COMM_ALARM, INVALID_ALARM);
    return 0;
  }
  if(mcc118_is_open(priv->mccAddress))
  {
    mcc118_a_in_read(priv->mccAddress, priv->channel, OPTS_NOSCALEDATA, &dumm);
    printf(" read value  0x%x\n", (unsigned int)dumm);
    prec->rval = (unsigned int)dumm;
  }
  else {
	  printf("can not open device ...\n");
  }
  return 0;
}

struct {
  long num;
  DEVSUPFUN  report;
  DEVSUPFUN  init;
  DEVSUPFUN  init_record;
  DEVSUPFUN  get_ioint_info;
  DEVSUPFUN  read_ai;
  DEVSUPFUN  special_linconv;
} devAiMcc118 = {
  6, /* space for 6 functions */
  NULL,
  NULL,
  init_record,
  NULL,
  read_ai,
  NULL
};
epicsExportAddress(dset,devAiMcc118);
