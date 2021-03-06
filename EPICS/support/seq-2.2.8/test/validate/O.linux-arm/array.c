/* C code for program arrayTest, generated by snc from ../array.st */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>

#include "seq_snc.h"
# line 9 "../array.st"
#include "../testSupport.h"

/* Variable declarations */
# line 11 "../array.st"
static	unsigned short longer[10];
# line 14 "../array.st"
static	unsigned short shorter[3];
struct seqg_vars_array {
# line 22 "../array.st"
	string a4a5s[4][5];
	struct {
# line 30 "../array.st"
		string (*a4ps[4])[5];
	} seqg_vars_init;
} seqg_vars_array;


/* Function declarations */

#define seqg_var (*(struct seqg_vars *const *)seqg_env)

/* Program init func */
static void seqg_init(PROG_ID seqg_env)
{
	{
# line 11 "../array.st"
	static unsigned short seqg_initvar_longer[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	memcpy(&longer, &seqg_initvar_longer, sizeof(seqg_initvar_longer));
	}
	{
# line 14 "../array.st"
	static unsigned short seqg_initvar_shorter[3] = {10, 11, 12};
	memcpy(&shorter, &seqg_initvar_shorter, sizeof(seqg_initvar_shorter));
	}
	{
# line 22 "../array.st"
	static string seqg_initvar_a4a5s[4][5] = {{"00", "01", "02", "03", "04"}, {"10", "11", "12", "13", "14"}, {"20", "21", "22", "23", "24"}, {"30", "31", "32", "33", "34"}};
	memcpy(&seqg_vars_array.a4a5s, &seqg_initvar_a4a5s, sizeof(seqg_initvar_a4a5s));
	}
	{
# line 30 "../array.st"
	static string (*seqg_initvar_a4ps[4])[5] = {&seqg_vars_array.a4a5s[0], &seqg_vars_array.a4a5s[1], &seqg_vars_array.a4a5s[2], &seqg_vars_array.a4a5s[3]};
	memcpy(&seqg_vars_array.seqg_vars_init.a4ps, &seqg_initvar_a4ps, sizeof(seqg_initvar_a4ps));
	}
}

/* Program entry func */
static void seqg_entry(SS_ID seqg_env)
{
# line 18 "../array.st"
	seq_test_init(33);
}

/****** Code for state "init" in state set "array" ******/

/* Event function for state "init" in state set "array" */
static seqBool seqg_event_array_0_init(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
	if (TRUE)
	{
		*seqg_pnst = 1;
		*seqg_ptrn = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "init" in state set "array" */
static void seqg_action_array_0_init(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 37 "../array.st"
			int i;
# line 37 "../array.st"
			int j;
# line 38 "../array.st"
			for (i = 0; i < 4; i++)
			{
# line 39 "../array.st"
				for (j = 0; j < 5; j++)
				{
# line 42 "../array.st"
					testOk(seqg_vars_array.a4a5s[i][j] == (*seqg_vars_array.seqg_vars_init.a4ps[i])[j], "a4a5s[%d][%d]=%s==%s=(*a4ps[%d])[%d])", i, j, seqg_vars_array.a4a5s[i][j], (*seqg_vars_array.seqg_vars_init.a4ps[i])[j], i, j);
				}
			}
# line 45 "../array.st"
			for (i = 0; i < 4; i++)
			{
# line 46 "../array.st"
				testDiag("a4ps[%d]=%p", i, seqg_vars_array.seqg_vars_init.a4ps[i]);
			}
# line 49 "../array.st"
			seq_pvPutTmo(seqg_env, 0/*longer*/, SYNC, DEFAULT_TIMEOUT);
# line 50 "../array.st"
			seq_pvGetTmo(seqg_env, 0/*longer*/, DEFAULT, DEFAULT_TIMEOUT);
# line 51 "../array.st"
			for (i = 0; i < 10; i++)
			{
# line 52 "../array.st"
				testOk1(longer[i] == i);
# line 53 "../array.st"
				longer[i] = 0;
			}
# line 55 "../array.st"
			seq_pvAssign(seqg_env, 1/*shorter*/, "array");
		}
		return;
	}
}

/****** Code for state "reconnect" in state set "array" ******/

/* Event function for state "reconnect" in state set "array" */
static seqBool seqg_event_array_0_reconnect(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 59 "../array.st"
	if (seq_pvConnectCount(seqg_env) == seq_pvAssignCount(seqg_env))
	{
		seq_exit(seqg_env);
		*seqg_ptrn = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "reconnect" in state set "array" */
static void seqg_action_array_0_reconnect(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 60 "../array.st"
			int i;
# line 62 "../array.st"
			seq_pvPutTmo(seqg_env, 1/*shorter*/, SYNC, DEFAULT_TIMEOUT);
# line 63 "../array.st"
			seq_pvGetTmo(seqg_env, 1/*shorter*/, DEFAULT, DEFAULT_TIMEOUT);
# line 64 "../array.st"
			for (i = 0; i < 3; i++)
			{
# line 65 "../array.st"
				testOk1(shorter[i] == i + 10);
			}
		}
		return;
	}
}

/* Program exit func */
static void seqg_exit(SS_ID seqg_env)
{
# line 72 "../array.st"
	seq_test_done();
}

#undef seqg_var

/************************ Tables ************************/

/* Channel table */
static seqChan seqg_chans[] = {
	/* chName, offset, varName, varType, count, eventNum, efId, monitored, queueSize, queueIndex */
	{"array", (size_t)&longer, "longer", P_USHORT, 10, 1, 0, 0, 0, 0},
	{"", (size_t)&shorter, "shorter", P_USHORT, 3, 2, 0, 0, 0, 0},
	{"", (size_t)&seqg_vars_array.a4a5s[0], "a4a5s[0]", P_STRING, 5, 3, 0, 0, 0, 0},
	{"", (size_t)&seqg_vars_array.a4a5s[1], "a4a5s[1]", P_STRING, 5, 4, 0, 0, 0, 0},
	{"", (size_t)&seqg_vars_array.a4a5s[2], "a4a5s[2]", P_STRING, 5, 5, 0, 0, 0, 0},
	{"", (size_t)&seqg_vars_array.a4a5s[3], "a4a5s[3]", P_STRING, 5, 6, 0, 0, 0, 0},
};

/* Event masks for state set "array" */
static const seqMask seqg_mask_array_0_init[] = {
	0x00000000,
};
static const seqMask seqg_mask_array_0_reconnect[] = {
	0x00000000,
};

/* State table for state set "array" */
static seqState seqg_states_array[] = {
	{
	/* state name */        "init",
	/* action function */   seqg_action_array_0_init,
	/* event function */    seqg_event_array_0_init,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_array_0_init,
	/* state options */     (0)
	},
	{
	/* state name */        "reconnect",
	/* action function */   seqg_action_array_0_reconnect,
	/* event function */    seqg_event_array_0_reconnect,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_array_0_reconnect,
	/* state options */     (0)
	},
};

/* State set table */
static seqSS seqg_statesets[] = {
	{
	/* state set name */    "array",
	/* states */            seqg_states_array,
	/* number of states */  2
	},
};

/* Program table (global) */
seqProgram arrayTest = {
	/* magic number */      2002008,
	/* program name */      "arrayTest",
	/* channels */          seqg_chans,
	/* num. channels */     6,
	/* state sets */        seqg_statesets,
	/* num. state sets */   1,
	/* user var size */     0,
	/* param */             "",
	/* num. event flags */  0,
	/* encoded options */   (0 | OPT_CONN | OPT_NEWEF),
	/* init func */         seqg_init,
	/* entry func */        seqg_entry,
	/* exit func */         seqg_exit,
	/* num. queues */       0
};

#define PROG_NAME arrayTest
#include "seqMain.c"

/* Register sequencer commands and program */
#include "epicsExport.h"
static void arrayTestRegistrar (void) {
    seqRegisterSequencerCommands();
    seqRegisterSequencerProgram (&arrayTest);
}
epicsExportRegistrar(arrayTestRegistrar);
