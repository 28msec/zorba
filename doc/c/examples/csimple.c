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
#include <zorba/store_manager_c.h>


/**
 * A simple C API example.
 *
 * Compile a query, iterate over the item sequence, and print the
 * string value for each item.  No error checking is done.
 */ 
int
example_1(XQC_Implementation* impl) 
{
  XQC_Expression*     lExpr;
  const char*    lStringValue;
  XQC_Sequence*   lResult;

  // compile the query and get the result as a sequence
  impl->prepare(impl, "for $i in 1 to 10 return $i", NULL, &lExpr);
  lExpr->execute(lExpr, NULL, &lResult);

  while ( lResult->next(lResult) == XQC_NO_ERROR ) {
    lResult->string_value(lResult, &lStringValue);
    printf("%s ", lStringValue);
  }
  printf("\n");
  // release all aquired resources
  lResult->free(lResult);
  lExpr->free(lExpr);

  return 1;
}

/**
 * Compile a syntactically wrong query and check the expected error
 */
int
example_2(XQC_Implementation* impl)
{
  XQC_Error    lError = XQC_NO_ERROR;
  XQC_Expression*   lExpr;

  // compile the query
  lError = impl->prepare(impl, "for $x in (1, 2, 3, 4)", NULL, &lExpr);
  printf("%d", lError);
  return lError == XQC_STATIC_ERROR ? 1 : 0;
}

/**
 * Compile a query which does division by 0 and check the expected error
 */
int
example_3(XQC_Implementation* impl)
{
  XQC_Error      lError = XQC_NO_ERROR;
  XQC_Expression*     lExpr;
  XQC_Sequence*       lResult;

  // compile the query
  impl->prepare(impl, "1 div 0", NULL, &lExpr);

  // execute it and iterate
  lError = lExpr->execute(lExpr, NULL, &lResult);
  while ( (lError = lResult->next(lResult)) == XQC_NO_ERROR);

  // release resources
  lResult->free(lResult);
  lExpr->free(lExpr);

  return lError == XQC_DYNAMIC_ERROR ? 1 : 0;

}

// define the callback functions for the input stream
unsigned int
read_stream(XQC_InputStream* stream, void* buf, unsigned int length) 
{
  strcpy(buf, "for $i in (1 to 10) return $i");
  return 29;
}

void
free_stream(XQC_InputStream* stream) 
{
  free(stream);
}


/**
 * Compile a query by passing it in via an XQC_InputStream.
 */
int
example_4(XQC_Implementation* impl)
{
  XQC_Expression*       lExpr;
  XQC_InputStream* lStream = (XQC_InputStream*) malloc(sizeof(XQC_InputStream));
  XQC_Sequence*    lResult;
  const char*      lStringValue;

  lStream->read = read_stream;
  lStream->free = free_stream;

  // compile the query
  impl->prepare_stream(impl, lStream, NULL, &lExpr);

  // execute it and iterate
  lExpr->execute(lExpr, NULL, &lResult);
  while (lResult->next(lResult) == XQC_NO_ERROR) {
    lResult->string_value(lResult, &lStringValue);
    printf("%s ", lStringValue);
  }  

  // release resources
  lResult->free(lResult);
  lExpr->free(lExpr);

  // the stream is freed by calling the free_stream function after the query has been prepared

  return 1;
}


int
csimple(int argc, char** argv)
{
  int res = 0; 
  XQC_Implementation* impl;

  void* store = create_store();

  if ( zorba_implementation(&impl, store) != XQC_NO_ERROR)
    return 1;

  printf("executing C example 1\n");
  res = example_1(impl);
  if (!res) { impl->free(impl); return 1; };
  printf("\n");

  printf("executing C example 2\n");
  res = example_2(impl);
  if (!res) { impl->free(impl); return 1; };
  printf("\n");

  printf("executing C example 3\n");
  res = example_3(impl);
  if (!res) { impl->free(impl); return 1; };
  printf("\n");

  printf("executing C example 4\n");
  res = example_4(impl);
  if (!res) { impl->free(impl); return 1; };
  printf("\n");

  impl->free(impl);
  shutdown_store(store);
   
  return 0;
}
