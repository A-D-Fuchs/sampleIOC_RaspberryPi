/* C code for program pvGetAsyncTest, generated by snc from ../pvGetAsync.st */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>

#include "seq_snc.h"
# line 9 "../pvGetAsync.st"
#include "../testSupport.h"

/* Variable declarations */
struct seqg_vars_pvGetAsync {
# line 19 "../pvGetAsync.st"
	int x;
# line 19 "../pvGetAsync.st"
	int old_x;
# line 21 "../pvGetAsync.st"
	int n;
} seqg_vars_pvGetAsync;


/* Function declarations */

#define seqg_var (*(struct seqg_vars *const *)seqg_env)

/* Program init func */
static void seqg_init(PROG_ID seqg_env)
{
	{
# line 19 "../pvGetAsync.st"
	static int seqg_initvar_x = 0;
	memcpy(&seqg_vars_pvGetAsync.x, &seqg_initvar_x, sizeof(seqg_initvar_x));
	}
	{
# line 19 "../pvGetAsync.st"
	static int seqg_initvar_old_x = 0;
	memcpy(&seqg_vars_pvGetAsync.old_x, &seqg_initvar_old_x, sizeof(seqg_initvar_old_x));
	}
}

/* Program entry func */
static void seqg_entry(SS_ID seqg_env)
{
# line 14 "../pvGetAsync.st"
	seq_test_init(1);
# line 15 "../pvGetAsync.st"
	testDiag("start");
}

/****** Code for state "init" in state set "pvGetAsync" ******/

/* Event function for state "init" in state set "pvGetAsync" */
static seqBool seqg_event_pvGetAsync_0_init(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
	if (TRUE)
	{
		*seqg_pnst = 1;
		*seqg_ptrn = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "init" in state set "pvGetAsync" */
static void seqg_action_pvGetAsync_0_init(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 25 "../pvGetAsync.st"
			seqg_vars_pvGetAsync.n = 0;
		}
		return;
	}
}

/****** Code for state "get_async" in state set "pvGetAsync" ******/

/* Event function for state "get_async" in state set "pvGetAsync" */
static seqBool seqg_event_pvGetAsync_0_get_async(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 29 "../pvGetAsync.st"
	if (seqg_vars_pvGetAsync.n == 100000)
	{
		seq_exit(seqg_env);
		*seqg_ptrn = 0;
		return TRUE;
	}
	if (TRUE)
	{
		*seqg_pnst = 2;
		*seqg_ptrn = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "get_async" in state set "pvGetAsync" */
static void seqg_action_pvGetAsync_0_get_async(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 30 "../pvGetAsync.st"
			testPass("pvGet completed %d times", 100000);
		}
		return;
	case 1:
		{
		}
		return;
	}
}

/****** Code for state "wait_complete" in state set "pvGetAsync" ******/

/* Entry function for state "wait_complete" in state set "pvGetAsync" */
static void seqg_entry_pvGetAsync_0_wait_complete(SS_ID seqg_env)
{
# line 37 "../pvGetAsync.st"
	seq_pvGetTmo(seqg_env, 0/*x*/, ASYNC, DEFAULT_TIMEOUT);
}

/* Exit function for state "wait_complete" in state set "pvGetAsync" */
static void seqg_exit_pvGetAsync_0_wait_complete(SS_ID seqg_env)
{
# line 45 "../pvGetAsync.st"
	seqg_vars_pvGetAsync.n++;
}

/* Event function for state "wait_complete" in state set "pvGetAsync" */
static seqBool seqg_event_pvGetAsync_0_wait_complete(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 39 "../pvGetAsync.st"
	if (seq_delay(seqg_env, 5.0))
	{
		seq_exit(seqg_env);
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 42 "../pvGetAsync.st"
	if (seq_pvGetComplete(seqg_env, 0/*x*/))
	{
		*seqg_pnst = 1;
		*seqg_ptrn = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "wait_complete" in state set "pvGetAsync" */
static void seqg_action_pvGetAsync_0_wait_complete(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 40 "../pvGetAsync.st"
			testFail("pvGet completion timeout");
		}
		return;
	case 1:
		{
		}
		return;
	}
}

/* Program exit func */
static void seqg_exit(SS_ID seqg_env)
{
# line 51 "../pvGetAsync.st"
	testDiag("exit");
# line 52 "../pvGetAsync.st"
	seq_test_done();
}

#undef seqg_var

/************************ Tables ************************/

/* Channel table */
static seqChan seqg_chans[] = {
	/* chName, offset, varName, varType, count, eventNum, efId, monitored, queueSize, queueIndex */
	{"pvGetAsync1", (size_t)&seqg_vars_pvGetAsync.x, "x", P_INT, 1, 1, 0, 0, 0, 0},
};

/* Event masks for state set "pvGetAsync" */
static const seqMask seqg_mask_pvGetAsync_0_init[] = {
	0x00000000,
};
static const seqMask seqg_mask_pvGetAsync_0_get_async[] = {
	0x00000000,
};
static const seqMask seqg_mask_pvGetAsync_0_wait_complete[] = {
	0x00000002,
};

/* State table for state set "pvGetAsync" */
static seqState seqg_states_pvGetAsync[] = {
	{
	/* state name */        "init",
	/* action function */   seqg_action_pvGetAsync_0_init,
	/* event function */    seqg_event_pvGetAsync_0_init,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_pvGetAsync_0_init,
	/* state options */     (0)
	},
	{
	/* state name */        "get_async",
	/* action function */   seqg_action_pvGetAsync_0_get_async,
	/* event function */    seqg_event_pvGetAsync_0_get_async,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_pvGetAsync_0_get_async,
	/* state options */     (0)
	},
	{
	/* state name */        "wait_complete",
	/* action function */   seqg_action_pvGetAsync_0_wait_complete,
	/* event function */    seqg_event_pvGetAsync_0_wait_complete,
	/* entry function */    seqg_entry_pvGetAsync_0_wait_complete,
	/* exit function */     seqg_exit_pvGetAsync_0_wait_complete,
	/* event mask array */  seqg_mask_pvGetAsync_0_wait_complete,
	/* state options */     (0)
	},
};

/* State set table */
static seqSS seqg_statesets[] = {
	{
	/* state set name */    "pvGetAsync",
	/* states */            seqg_states_pvGetAsync,
	/* number of states */  3
	},
};

/* Program table (global) */
seqProgram pvGetAsyncTest = {
	/* magic number */      2002008,
	/* program name */      "pvGetAsyncTest",
	/* channels */          seqg_chans,
	/* num. channels */     1,
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

#define PROG_NAME pvGetAsyncTest
#include "seqMain.c"

/* Register sequencer commands and program */
#include "epicsExport.h"
static void pvGetAsyncTestRegistrar (void) {
    seqRegisterSequencerCommands();
    seqRegisterSequencerProgram (&pvGetAsyncTest);
}
epicsExportRegistrar(pvGetAsyncTestRegistrar);
