/* C code for program traffic, generated by snc from ../traffic.st */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>

#include "seq_snc.h"

/* Variable declarations */
# line 7 "../traffic.st"
static	int lights[3];
# line 14 "../traffic.st"
static	double red_time;
# line 15 "../traffic.st"
static	double red_yellow_time;
# line 16 "../traffic.st"
static	double green_time;
# line 17 "../traffic.st"
static	double yellow_time;


/* Function declarations */

#define seqg_var (*(struct seqg_vars *const *)seqg_env)

/* Program init func */
static void seqg_init(PROG_ID seqg_env)
{
	{
# line 14 "../traffic.st"
	static double seqg_initvar_red_time = 3.0;
	memcpy(&red_time, &seqg_initvar_red_time, sizeof(seqg_initvar_red_time));
	}
	{
# line 15 "../traffic.st"
	static double seqg_initvar_red_yellow_time = 1.0;
	memcpy(&red_yellow_time, &seqg_initvar_red_yellow_time, sizeof(seqg_initvar_red_yellow_time));
	}
	{
# line 16 "../traffic.st"
	static double seqg_initvar_green_time = 4.0;
	memcpy(&green_time, &seqg_initvar_green_time, sizeof(seqg_initvar_green_time));
	}
	{
# line 17 "../traffic.st"
	static double seqg_initvar_yellow_time = 1.0;
	memcpy(&yellow_time, &seqg_initvar_yellow_time, sizeof(seqg_initvar_yellow_time));
	}
}

/****** Code for state "red" in state set "light" ******/

/* Entry function for state "red" in state set "light" */
static void seqg_entry_light_0_red(SS_ID seqg_env)
{
# line 22 "../traffic.st"
	lights[0] = 1;
# line 22 "../traffic.st"
	seq_pvPutTmo(seqg_env, 0/*lights*/ + (CH_ID)(0), DEFAULT, DEFAULT_TIMEOUT);
# line 23 "../traffic.st"
	lights[1] = 0;
# line 23 "../traffic.st"
	seq_pvPutTmo(seqg_env, 0/*lights*/ + (CH_ID)(1), DEFAULT, DEFAULT_TIMEOUT);
# line 24 "../traffic.st"
	lights[2] = 0;
# line 24 "../traffic.st"
	seq_pvPutTmo(seqg_env, 0/*lights*/ + (CH_ID)(2), DEFAULT, DEFAULT_TIMEOUT);
}

/* Event function for state "red" in state set "light" */
static seqBool seqg_event_light_0_red(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 26 "../traffic.st"
	if (seq_delay(seqg_env, red_time))
	{
		*seqg_pnst = 1;
		*seqg_ptrn = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "red" in state set "light" */
static void seqg_action_light_0_red(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
		}
		return;
	}
}

/****** Code for state "red_yellow" in state set "light" ******/

/* Entry function for state "red_yellow" in state set "light" */
static void seqg_entry_light_0_red_yellow(SS_ID seqg_env)
{
# line 31 "../traffic.st"
	lights[0] = 1;
# line 31 "../traffic.st"
	seq_pvPutTmo(seqg_env, 0/*lights*/ + (CH_ID)(0), DEFAULT, DEFAULT_TIMEOUT);
# line 32 "../traffic.st"
	lights[1] = 1;
# line 32 "../traffic.st"
	seq_pvPutTmo(seqg_env, 0/*lights*/ + (CH_ID)(1), DEFAULT, DEFAULT_TIMEOUT);
# line 33 "../traffic.st"
	lights[2] = 0;
# line 33 "../traffic.st"
	seq_pvPutTmo(seqg_env, 0/*lights*/ + (CH_ID)(2), DEFAULT, DEFAULT_TIMEOUT);
}

/* Event function for state "red_yellow" in state set "light" */
static seqBool seqg_event_light_0_red_yellow(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 35 "../traffic.st"
	if (seq_delay(seqg_env, red_yellow_time))
	{
		*seqg_pnst = 2;
		*seqg_ptrn = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "red_yellow" in state set "light" */
static void seqg_action_light_0_red_yellow(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
		}
		return;
	}
}

/****** Code for state "green" in state set "light" ******/

/* Entry function for state "green" in state set "light" */
static void seqg_entry_light_0_green(SS_ID seqg_env)
{
# line 40 "../traffic.st"
	lights[0] = 0;
# line 40 "../traffic.st"
	seq_pvPutTmo(seqg_env, 0/*lights*/ + (CH_ID)(0), DEFAULT, DEFAULT_TIMEOUT);
# line 41 "../traffic.st"
	lights[1] = 0;
# line 41 "../traffic.st"
	seq_pvPutTmo(seqg_env, 0/*lights*/ + (CH_ID)(1), DEFAULT, DEFAULT_TIMEOUT);
# line 42 "../traffic.st"
	lights[2] = 1;
# line 42 "../traffic.st"
	seq_pvPutTmo(seqg_env, 0/*lights*/ + (CH_ID)(2), DEFAULT, DEFAULT_TIMEOUT);
}

/* Event function for state "green" in state set "light" */
static seqBool seqg_event_light_0_green(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 44 "../traffic.st"
	if (seq_delay(seqg_env, green_time))
	{
		*seqg_pnst = 3;
		*seqg_ptrn = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "green" in state set "light" */
static void seqg_action_light_0_green(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
		}
		return;
	}
}

/****** Code for state "yellow" in state set "light" ******/

/* Entry function for state "yellow" in state set "light" */
static void seqg_entry_light_0_yellow(SS_ID seqg_env)
{
# line 49 "../traffic.st"
	lights[0] = 0;
# line 49 "../traffic.st"
	seq_pvPutTmo(seqg_env, 0/*lights*/ + (CH_ID)(0), DEFAULT, DEFAULT_TIMEOUT);
# line 50 "../traffic.st"
	lights[1] = 1;
# line 50 "../traffic.st"
	seq_pvPutTmo(seqg_env, 0/*lights*/ + (CH_ID)(1), DEFAULT, DEFAULT_TIMEOUT);
# line 51 "../traffic.st"
	lights[2] = 0;
# line 51 "../traffic.st"
	seq_pvPutTmo(seqg_env, 0/*lights*/ + (CH_ID)(2), DEFAULT, DEFAULT_TIMEOUT);
}

/* Event function for state "yellow" in state set "light" */
static seqBool seqg_event_light_0_yellow(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 53 "../traffic.st"
	if (seq_delay(seqg_env, yellow_time))
	{
		*seqg_pnst = 0;
		*seqg_ptrn = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "yellow" in state set "light" */
static void seqg_action_light_0_yellow(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
		}
		return;
	}
}

#undef seqg_var

/************************ Tables ************************/

/* Channel table */
static seqChan seqg_chans[] = {
	/* chName, offset, varName, varType, count, eventNum, efId, monitored, queueSize, queueIndex */
	{"traffic:red_light", (size_t)&lights[0], "lights[0]", P_INT, 1, 1, 0, 0, 0, 0},
	{"traffic:yellow_light", (size_t)&lights[1], "lights[1]", P_INT, 1, 2, 0, 0, 0, 0},
	{"traffic:green_light", (size_t)&lights[2], "lights[2]", P_INT, 1, 3, 0, 0, 0, 0},
};

/* Event masks for state set "light" */
static const seqMask seqg_mask_light_0_red[] = {
	0x00000000,
};
static const seqMask seqg_mask_light_0_red_yellow[] = {
	0x00000000,
};
static const seqMask seqg_mask_light_0_green[] = {
	0x00000000,
};
static const seqMask seqg_mask_light_0_yellow[] = {
	0x00000000,
};

/* State table for state set "light" */
static seqState seqg_states_light[] = {
	{
	/* state name */        "red",
	/* action function */   seqg_action_light_0_red,
	/* event function */    seqg_event_light_0_red,
	/* entry function */    seqg_entry_light_0_red,
	/* exit function */     0,
	/* event mask array */  seqg_mask_light_0_red,
	/* state options */     (0)
	},
	{
	/* state name */        "red_yellow",
	/* action function */   seqg_action_light_0_red_yellow,
	/* event function */    seqg_event_light_0_red_yellow,
	/* entry function */    seqg_entry_light_0_red_yellow,
	/* exit function */     0,
	/* event mask array */  seqg_mask_light_0_red_yellow,
	/* state options */     (0)
	},
	{
	/* state name */        "green",
	/* action function */   seqg_action_light_0_green,
	/* event function */    seqg_event_light_0_green,
	/* entry function */    seqg_entry_light_0_green,
	/* exit function */     0,
	/* event mask array */  seqg_mask_light_0_green,
	/* state options */     (0)
	},
	{
	/* state name */        "yellow",
	/* action function */   seqg_action_light_0_yellow,
	/* event function */    seqg_event_light_0_yellow,
	/* entry function */    seqg_entry_light_0_yellow,
	/* exit function */     0,
	/* event mask array */  seqg_mask_light_0_yellow,
	/* state options */     (0)
	},
};

/* State set table */
static seqSS seqg_statesets[] = {
	{
	/* state set name */    "light",
	/* states */            seqg_states_light,
	/* number of states */  4
	},
};

/* Program table (global) */
seqProgram traffic = {
	/* magic number */      2002008,
	/* program name */      "traffic",
	/* channels */          seqg_chans,
	/* num. channels */     3,
	/* state sets */        seqg_statesets,
	/* num. state sets */   1,
	/* user var size */     0,
	/* param */             "",
	/* num. event flags */  0,
	/* encoded options */   (0 | OPT_CONN | OPT_NEWEF),
	/* init func */         seqg_init,
	/* entry func */        0,
	/* exit func */         0,
	/* num. queues */       0
};

/* Register sequencer commands and program */
#include "epicsExport.h"
static void trafficRegistrar (void) {
    seqRegisterSequencerCommands();
    seqRegisterSequencerProgram (&traffic);
}
epicsExportRegistrar(trafficRegistrar);
