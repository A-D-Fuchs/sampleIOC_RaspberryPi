#include <stdio.h>

#include <dbDefs.h>
#include <registryFunction.h>
#include <subRecord.h>
#include <aSubRecord.h>
#include <epicsExport.h>
#include <epicsThread.h>

#include <wiringPi.h>

int mySubDebug;

// BRM const unsigned char ledList[] = {26,24,6,25,23,16,22};
const unsigned int ledList[7] = {25,5,22,6,4,27,3};

const unsigned int disp[10][7] = {
    {25,5,22,6,4,27,0},
    {5,22,0,0,0,0},
    {25,5,3,4,6,0,0},
    {25,5,3,22,6,0,0},
    {27,3,5,22,0,0,0},
    {25,27,3,22,6,0,0},
    {25,27,3,4,6,22,0},
    {27,25,5,22,0,0,0},
    {25,5,22,6,4,27,3},
    {25,5,22,6,27,3,0}
};

static long mySubInit(subRecord *precord)
{
    if (mySubDebug)
        printf("Record %s called mySubInit(%p)\n",
               precord->name, (void*) precord);

    wiringPiSetup();
    /* set all led gpio's to output */
    for (int i = 0; i < 7; i++){
      pinMode(ledList[i], OUTPUT);
    }
    /* set all on ... */
    for (int i = 0; i < 7; i++){
      digitalWrite(ledList[i], HIGH);
    }
    epicsThreadSleep(0.3);
    /* set all off... */
    for (int i = 0; i < 7; i++){
      digitalWrite(ledList[i], LOW);
    }

    return 0;
}

static long mySubProcess(subRecord *precord)
{
    if (mySubDebug)
        printf("Record %s called mySubProcess(%p)\n",
               precord->name, (void*) precord);
    int val = (int)precord->a;
//    printf(" mySubProcess val = %d\n", val);
    if( val >= 0 && val <=9 ) {
    /* set all off... */
    for (int i = 0; i < 7; i++){
      digitalWrite(ledList[i], LOW);
    }
	/* display value on 7-segment display */
      for (int i = 0; i < 7; i++){
        if(disp[val][i])
          digitalWrite(disp[val][i], HIGH);
      }
	
    }	
    return 0;
}

static long myAsubInit(aSubRecord *precord)
{
    if (mySubDebug)
        printf("Record %s called myAsubInit(%p)\n",
               precord->name, (void*) precord);
    return 0;
}

static long myAsubProcess(aSubRecord *precord)
{
    if (mySubDebug)
        printf("Record %s called myAsubProcess(%p)\n",
               precord->name, (void*) precord);
    return 0;
}

/* Register these symbols for use by IOC code: */

epicsExportAddress(int, mySubDebug);
epicsRegisterFunction(mySubInit);
epicsRegisterFunction(mySubProcess);
epicsRegisterFunction(myAsubInit);
epicsRegisterFunction(myAsubProcess);
