/*
 * Copyright 2006-2010 The FLWOR Foundation.
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

#ifndef CEXAMPLES_HELPERS_H
#define CEXAMPLES_HELPERS_H

/**
 * Utility function for checking XQC_Errors. Returns true if error raised.
 * (function defined in csequences.c)
 */
int
check_error(const char* func_name, XQC_Error error);

#endif
