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
#include <simplestore/simplestorec.h>

// define a callback function that is called if an error occurs
// during preparing or executing the query
void
error_handler(XQC_ErrorHandler handler,
              XQUERY_ERROR error,
              const char   *local_name,
              const char   *description,
              const char   *query_uri,
              unsigned int line,
              unsigned int column)
{
  printf("localname: %s\ndescription: %s\nline: %i\ncolumn: %i", 
          local_name, description, line, column);
}


/**
 * Use an error handler and test it by preparing a syntactically wrong query.
 */
int
cerror_example_1(XQC_Implementation impl)
{
  XQUERY_ERROR     lError = XQ_NO_ERROR;
  XQC_Query        lXQuery;
  XQC_ErrorHandler lErrorHandler = (XQC_ErrorHandler) malloc(sizeof(struct XQC_ErrorHandler_s));
  lErrorHandler->error = error_handler;

  // compile the query
  lError = impl->prepare(impl, "for $i in 1, 2, 3", 0, lErrorHandler, &lXQuery);

  // no need to free the query
  // because it was not successfully created
  free(lErrorHandler);

  return lError == XPST0003?1:0;
}

/**
 * Use an error handler and test it by executing a query that raises an error.
 */
int
cerror_example_2(XQC_Implementation impl)
{
  XQUERY_ERROR     lError = XQ_NO_ERROR;
  XQC_Query        lXQuery;
  FILE*            lOutFile = stdout;
  XQC_ErrorHandler lErrorHandler = (XQC_ErrorHandler) malloc(sizeof(struct XQC_ErrorHandler_s));
  lErrorHandler->error = error_handler;

  // compile the query
  impl->prepare(impl, "1 div 0", 0, 0, &lXQuery);

  // set the error handler for handling errors
  // during query execution
  lXQuery->set_error_handler(lXQuery, lErrorHandler);

  // execute it and print the result on standard out
  lError = lXQuery->execute(lXQuery, lOutFile);

  // release the query
  lXQuery->free(lXQuery);
  free(lErrorHandler);

  return lError == FOAR0001?1:0;
}

int
cerror_example_3(XQC_Implementation impl) 
{
  XQUERY_ERROR   lError = XQ_NO_ERROR;
  XQC_Query      lXQuery;
  XQC_Item       lItem;
  const char*    lStringValue;
  XQC_Sequence   lResult;
  XQC_ErrorHandler lErrorHandler = (XQC_ErrorHandler) malloc(sizeof(struct XQC_ErrorHandler_s));
  lErrorHandler->error = error_handler;

  impl->create_item(impl, &lItem);

  // compile the query and get the result as a sequence
  lError = impl->prepare(impl, "for $i in (3, 2, 1, 0) return 3 div $i", 0, lErrorHandler, &lXQuery);

  lXQuery->sequence(lXQuery, &lResult);

  // an error is reported during the last for iteration
  // the error callback function is called and the loop terminates
  while ( lResult->next(lResult, lItem) == XQ_NO_ERROR ) {
    lItem->string_value(lItem, &lStringValue);
    printf("%s ", lStringValue);
  }

  // release all aquired resources
  free(lErrorHandler);
  lItem->free(lItem);
  lResult->free(lResult);
  lXQuery->free(lXQuery);

  return 1;
}

int
cerror(int argc, char** argv)
{
  int res = 0; 
  XQC_Implementation impl;

  void* store = create_simple_store();

  if ( zorba_implementation(&impl, store) != XQ_NO_ERROR)
    return 1;

  printf("executing C example 1\n");
  res = cerror_example_1(impl);
  if (!res) { impl->free(impl); return 1; };
  printf("\n");

  printf("executing C example 2\n");
  res = cerror_example_2(impl);
  if (!res) { impl->free(impl); return 1; };
  printf("\n");

  printf("executing C example 3\n");
  res = cerror_example_3(impl);
  if (!res) { impl->free(impl); return 1; };
  printf("\n");

  impl->free(impl);
  shutdown_simple_store(store);

  return 0;
}
