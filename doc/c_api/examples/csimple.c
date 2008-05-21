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
#include <errno.h>
#include <zorba/zorbac.h>

/**
 * A simple C API example
 * Compile a query and print the result.  No error checking is done.
 */
int
example_1(XQC_Implementation impl)
{
  XQUERY_ERROR   lError = XQ_SUCCESS;
  XQC_Query      lXQuery;
  FILE*          lOutFile = stdout;

  // compile the query
  lError = impl->compile(impl, "(1+2, 3, 4)", 0, &lXQuery);

  // execute it and print the result on standard out
  lXQuery->execute(lXQuery, lOutFile);

  // release the query
  lXQuery->free(lXQuery);

  return 1;
}

/**
 * A simple C API example
 * Compile a query, iterate over the item sequence, and print the string value for each item.
 * No error checking is done.
 */ 
int
example_2(XQC_Implementation impl) 
{
  XQUERY_ERROR   lError = XQ_SUCCESS;
  XQC_Query      lXQuery;
  XQC_Item       lItem;
  XQC_String     lString;
  const char*          lStringValue;
  XQC_Sequence   lResult;
  FILE*          lOutFile = stdout;

  // create an Item and a String holder
  impl->create_item(impl, &lItem);
  impl->create_string(impl, 0, &lString);

  // compile the query and get the result as a sequence
  lError = impl->compile(impl, "for $i in 1 to 10 return $i", 0, &lXQuery);

  lXQuery->sequence(lXQuery, &lResult);

  while ( lResult->next(lResult, lItem) != API0025_END_OF_SEQUENCE ) {
    lItem->string_value(lItem, lString);
    lString->to_char(lString, &lStringValue);
    printf("%s ", lStringValue);
  }

  // release all aquired resources
  lString->free(lString);
  lItem->free(lItem);
  lResult->free(lResult);
  lXQuery->free(lXQuery);

  return 1;
}


int
csimple(int argc, char** argv)
{
  int res = 0; 
  XQC_Implementation impl;

  if ( zorba_implementation(&impl) != XQ_SUCCESS )
      return 1;

  printf("executing C example 1\n");
  res = example_1(impl);
  if (!res) { impl->free(impl); return 1; };
  printf("\n");

  printf("executing C example 2\n");
  res = example_2(impl);
  if (!res) { impl->free(impl); return 1; };
  printf("\n");


  impl->free(impl);
   
  return 0;
}
