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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <zorba/zorbac.h>
#if 0
/**
 * A C API example that shows how to use the static and dynamic context.
 * No error checking is done.
 */
int
context_example_1(XQUERY_API* aAPI)
{
  XQUERY    lXQuery;
  XQUERY_DC lContext;
  FILE*     lFile = stdout;

  // compile the query
  aAPI->query_compile("declare variable $var external; $var + $var", &lXQuery);

  aAPI->dynamic_context(lXQuery, lContext);

  aAPI->query_execute(lXQuery, lFile);

  aAPI->query_release(lXQuery);
  return 1;
}
#endif

int
ccontext(int argc, char** argv)
{
  int res = 0; 
  XQUERY_API* lAPI = zorba_init();

#if 0
  printf("executing C context example 1\n");
  res = context_example_1(lAPI);
  if (!res) { zorba_release(lAPI); return 1; };
  printf("\n");
#endif

  zorba_release(lAPI);

  return 0;
}
