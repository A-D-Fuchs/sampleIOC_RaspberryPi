/* C code for program safeMonitorTest, generated by snc from ../safeMonitor.st */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>

#include "seq_snc.h"
# line 9 "../safeMonitor.st"
#include "../testSupport.h"
# line 16 "../safeMonitor.st"
static const EF_ID ef_cnt = 1;

/* Variable declarations */
struct seqg_vars {
# line 13 "../safeMonitor.st"
	double cnt;
	struct seqg_vars_read {
# line 26 "../safeMonitor.st"
		double on_entry;
# line 27 "../safeMonitor.st"
		int n;
	} seqg_vars_read;
};


/* Function declarations */

#define seqg_var (*(struct seqg_vars *const *)seqg_env)

/* Program init func */
static void seqg_init(PROG_ID seqg_env)
{
	{
# line 13 "../safeMonitor.st"
	static double seqg_initvar_cnt = 1.0;
	memcpy(&seqg_var->cnt, &seqg_initvar_cnt, sizeof(seqg_initvar_cnt));
	}
	{
# line 27 "../safeMonitor.st"
	static int seqg_initvar_n = 1;
	memcpy(&seqg_var->seqg_vars_read.n, &seqg_initvar_n, sizeof(seqg_initvar_n));
	}
}

/* Program entry func */
static void seqg_entry(SS_ID seqg_env)
{
# line 22 "../safeMonitor.st"
	seq_test_init(10);
}

/****** Code for state "react" in state set "read" ******/

/* Event function for state "react" in state set "read" */
static seqBool seqg_event_read_0_react(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 29 "../safeMonitor.st"
	if (seqg_var->seqg_vars_read.n > 10)
	{
		seq_exit(seqg_env);
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 31 "../safeMonitor.st"
	if (seq_efTestAndClear(seqg_env, ef_cnt))
	{
		*seqg_pnst = 0;
		*seqg_ptrn = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "react" in state set "read" */
static void seqg_action_read_0_react(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
		}
		return;
	case 1:
		{
# line 32 "../safeMonitor.st"
			seqg_var->seqg_vars_read.on_entry = seqg_var->cnt;
# line 33 "../safeMonitor.st"
			testDiag("read: enter action block, cnt=%.1f", seqg_var->cnt);
# line 34 "../safeMonitor.st"
			epicsThreadSleep(0.1);
# line 36 "../safeMonitor.st"
			testOk(seqg_var->seqg_vars_read.on_entry == seqg_var->cnt, "read: exit action block, on_entry=%.1f==%.1f=cnt", seqg_var->seqg_vars_read.on_entry, seqg_var->cnt);
# line 37 "../safeMonitor.st"
			seqg_var->seqg_vars_read.n++;
		}
		return;
	}
}

/****** Code for state "send" in state set "write" ******/

/* Event function for state "send" in state set "write" */
static seqBool seqg_event_write_1_send(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 44 "../safeMonitor.st"
	if (seq_delay(seqg_env, 0.04))
	{
		*seqg_pnst = 0;
		*seqg_ptrn = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "send" in state set "write" */
static void seqg_action_write_1_send(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 45 "../safeMonitor.st"
			seqg_var->cnt += 1.0;
# line 46 "../safeMonitor.st"
			seq_pvPutTmo(seqg_env, 0/*cnt*/, DEFAULT, DEFAULT_TIMEOUT);
# line 47 "../safeMonitor.st"
			testDiag("write: pvPut(cnt=%.1f)", seqg_var->cnt);
		}
		return;
	}
}

/* Program exit func */
static void seqg_exit(SS_ID seqg_env)
{
# line 53 "../safeMonitor.st"
	seq_test_done();
}

#undef seqg_var

/************************ Tables ************************/

/* Channel table */
static seqChan seqg_chans[] = {
	/* chName, offset, varName, varType, count, eventNum, efId, monitored, queueSize, queueIndex */
	{"", offsetof(struct seqg_vars, cnt), "cnt", P_DOUBLE, 1, 2, 1, 1, 0, 0},
};

/* Event masks for state set "read" */
static const seqMask seqg_mask_read_0_react[] = {
	0x00000002,
};

/* State table for state set "read" */
static seqState seqg_states_read[] = {
	{
	/* state name */        "react",
	/* action function */   seqg_action_read_0_react,
	/* event function */    seqg_event_read_0_react,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_read_0_react,
	/* state options */     (0)
	},
};

/* Event masks for state set "write" */
static const seqMask seqg_mask_write_1_send[] = {
	0x00000000,
};

/* State table for state set "write" */
static seqState seqg_states_write[] = {
	{
	/* state name */        "send",
	/* action function */   seqg_action_write_1_send,
	/* event function */    seqg_event_write_1_send,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_write_1_send,
	/* state options */     (0)
	},
};

/* State set table */
static seqSS seqg_statesets[] = {
	{
	/* state set name */    "read",
	/* states */            seqg_states_read,
	/* number of states */  1
	},

	{
	/* state set name */    "write",
	/* states */            seqg_states_write,
	/* number of states */  1
	},
};

/* Program table (global) */
seqProgram safeMonitorTest = {
	/* magic number */      2002008,
	/* program name */      "safeMonitorTest",
	/* channels */          seqg_chans,
	/* num. channels */     1,
	/* state sets */        seqg_statesets,
	/* num. state sets */   2,
	/* user var size */     sizeof(struct seqg_vars),
	/* param */             "",
	/* num. event flags */  1,
	/* encoded options */   (0 | OPT_CONN | OPT_NEWEF | OPT_REENT | OPT_SAFE),
	/* init func */         seqg_init,
	/* entry func */        seqg_entry,
	/* exit func */         seqg_exit,
	/* num. queues */       0
};

#define PROG_NAME safeMonitorTest
#include "seqMain.c"

/* Register sequencer commands and program */
#include "epicsExport.h"
static void safeMonitorTestRegistrar (void) {
    seqRegisterSequencerCommands();
    seqRegisterSequencerProgram (&safeMonitorTest);
}
epicsExportRegistrar(safeMonitorTestRegistrar);
