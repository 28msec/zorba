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

/**
 * A simple C API example
 * Compile a query and print the result.  No error checking is done.
 */
int
example_1(XQUERY_API* aAPI)
{
  char           lBuffer[256];
  XQUERY_ERROR   lError = XQ_SUCCESS;
  XQUERY_STREAM  lStream;
  XQUERY         lXQuery;

  // initialize the buffer
  memset(lBuffer, 0, 256);

  // compile the query
  lError = aAPI->query_compile("(1+2, 'testsdfadsfsd')", &lXQuery);

  // get the result as a stream
  lError = aAPI->stream_init(lXQuery, &lStream);

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
example_2(XQUERY_API* aAPI) 
{
  XQUERY_ITEM      lItem;
  XQUERY_STRING    lString;
  XQUERY           lXQuery;
  XQUERY_SEQUENCE  lResult;
  
  aAPI->item_init(&lItem);
  aAPI->string_init(&lString);
  
  aAPI->query_compile("(1+2,3+4)", &lXQuery);

  aAPI->sequence_init(lXQuery, &lResult);

  while (aAPI->sequence_next(lResult, lItem) == XQ_SUCCESS) {

    aAPI->item_stringvalue(lItem, lString);

    printf("%s\n", aAPI->string_to_char(lString));
  }

  aAPI->sequence_release(lResult);
  aAPI->query_release(lXQuery);
  aAPI->string_release(lString);
  aAPI->item_release(lItem);

  return 1;
}

/**
 * A simple C API example
 * Compile a query and write the output to stream.
 * No error checking is done.
 */ 
int
example_3(XQUERY_API* aAPI) 
{
  XQUERY          lXQuery;
  FILE*           lFile = stdout;

  aAPI->query_compile("(1+2,3+4)", &lXQuery);

  aAPI->query_execute(lXQuery, lFile);

  aAPI->query_release(lXQuery);

  return 1;
}

int
csimple(int argc, char** argv)
{
  int res = 0; 
  XQUERY_API* lAPI = zorba_init();

  printf("executing C example 1\n");
  res = example_1(lAPI);
  if (!res) { zorba_release(lAPI); return 1; };
  printf("\n");

  printf("executing C example 2\n");
  res = example_2(lAPI);
  if (!res) { zorba_release(lAPI); return 1; };
  printf("\n");

  printf("executing C example 3\n");
  res = example_3(lAPI);
  if (!res) { zorba_release(lAPI); return 1; };
  printf("\n");

  zorba_release(lAPI);
  return 0;
}
