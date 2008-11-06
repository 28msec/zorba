/*
 * Copyright 2006-2008 The FLWOR Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ZORBA_DEBUGGER_COMMON_H
#define ZORBA_DEBUGGER_COMMON_H

#include "common/common.h"

/* Type definitions */
typedef unsigned char StepCommand;
typedef unsigned char ExecutionStatus;
typedef unsigned short SuspensionCause;

/* Kind of step command */
const StepCommand STEP_INTO   = 0x01;
const StepCommand STEP_OUT    = 0x02;
const StepCommand STEP_OVER   = 0x03;

/* Status of the engine */
const ExecutionStatus QUERY_IDLE       = 0x01;
const ExecutionStatus QUERY_RUNNING    = 0x02;
const ExecutionStatus QUERY_RESUMED    = 0x03;
const ExecutionStatus QUERY_SUSPENDED  = 0x04;
const ExecutionStatus QUERY_TERMINATED = 0x05;

/* Cause of the suspension of the engine */
const SuspensionCause CAUSE_USER               = 0x01;
const SuspensionCause CAUSE_BREAKPOINT         = 0x02;
const SuspensionCause CAUSE_STEP               = 0x03;
const SuspensionCause CAUSE_FUNCTION_EXECUTION = 0x04;
#endif
