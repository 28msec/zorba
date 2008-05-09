#ifndef XQP_DEBUGGER_COMMON_H
#define XQP_DEBUGGER_COMMON_H

#include "common/common.h"

/* Type definitions */
typedef unsigned char StepCommand;
typedef unsigned char ExecutionStatus;
typedef unsigned short SuspensionCause;

/* Kind of step command */
const StepCommand STEP_INTO = 0x01;
const StepCommand STEP_OUT  = 0x02;
const StepCommand STEP_OVER = 0x03;

/* Status of the engine */
const ExecutionStatus QUERY_IDLE       = 0x01;
const ExecutionStatus QUERY_RUNNING    = 0x02;
const ExecutionStatus QUERY_RESUMED    = 0x03;
const ExecutionStatus QUERY_SUSPENDED  = 0x04;
const ExecutionStatus QUERY_TERMINATED = 0x05;

/* Cause of the suspension of the engine */
const SuspensionCause CAUSE_USER       = 0x01;
const SuspensionCause CAUSE_BREAKPOINT = 0x02;
const SuspensionCause CAUSE_STEP       = 0x03;
#endif
