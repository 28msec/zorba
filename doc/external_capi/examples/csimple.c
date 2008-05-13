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
#include <zorbac/zorbac.h>

#if 0
int
checkError(XQUERY aQuery, XQUERY_ERROR* aError)
{
  if (*aError == XQUERY_SUCCESS)
    return 0;

  return 1;
  // TODO print error message
}
#endif

/**
 * A simple C API example
 * Compile a query and print the result.  No error checking is done.
 */
int
example_1(XQUERY_CAPI* aAPI)
{
  char          lBuffer[256];
  XQUERY_ERROR  lError = XQ_SUCCESS;
  XQUERY_STREAM lStream;
  XQUERY        lXQuery;

  // initialize the buffer
  memset(lBuffer, 0, 256);

  // compile the query
  lXQuery = aAPI->query_compile("(1+2, 'testsdfadsfsd')", &lError);

  // get the result as a stream
  lStream = aAPI->stream_init(lXQuery, &lError);

  while (aAPI->stream_next(lStream, lBuffer, 255, &lError) > 0) {
    printf("%s", lBuffer);
  }
  
  // release resources
  aAPI->stream_release(lStream);
  aAPI->query_release(lXQuery);
  return 1;
}

/**
 * A simple C API example
 * Compile a query, iterate over the item sequence, and print the string value for each item.
 * No error checking is done.
 */ 
int
example_2(XQUERY_CAPI* aAPI) 
{
  XQUERY_ERROR    lError  = XQ_SUCCESS;
  XQUERY_ITEM     lItem   = aAPI->item_init();
  XQUERY_STRING   lString = aAPI->string_init();
  XQUERY          lXQuery;
  XQUERY_SEQUENCE lResult;

  lXQuery = aAPI->query_compile("(1+2,3+4)", &lError);

  lResult = aAPI->sequence_init(lXQuery, &lError);

  while (aAPI->sequence_next(lResult, lItem, &lError)) {

    aAPI->item_stringvalue(lItem, lString, &lError);

    printf("%s\n", aAPI->string_to_char(lString));
  }

  aAPI->sequence_close(lResult);
  aAPI->string_release(lString);
  aAPI->item_release(lItem);
  aAPI->query_release(lXQuery);

  return 1;
}

int
csimple(int argc, char** argv)
{
  int res = 0; 
  XQUERY_CAPI lAPI;
  zorba_create_capi(&lAPI);

  printf("executing C example 1\n");
  res = example_1(&lAPI);
  if (!res) return 1;
  printf("\n");

  printf("executing C example 2\n");
  res = example_2(&lAPI);
  if (!res) return 1;
  printf("\n");

  return 0;
}
