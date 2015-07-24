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

XQC_Error gError;

// define a callback function that is called if an error occurs
// during preparing or executing the query. This version is using
// Zorba's extended error handler.
void
zerror_handler(XQC_ErrorHandler* handler,
              XQC_Error    error,
              const char   *local_name,
              const char   *description,
              const char   *query_uri,
              unsigned int line,
              unsigned int column)
{
  printf("query_uri: %s\nlocalname: %s\ndescription: %s\nline: %i\ncolumn: %i\n", 
    query_uri, local_name, description, line, column);
  // Remember the error code
  gError = error;
}

// This version uses XQC's basic error handler.
void error_handler(XQC_ErrorHandler* handler, XQC_Error error,
  const char* error_uri, const char* error_name, const char* description,
  XQC_Sequence* error_object)
{
  printf("error: %s:%s\ndescription: %s\n", error_uri, error_name, description);
  gError = error;
}

// Convenience function
XQC_ErrorHandler*
create_error_handler()
{
  XQC_ErrorHandler* lErrorHandler =
    (XQC_ErrorHandler*) malloc(sizeof(XQC_ErrorHandler));
  lErrorHandler->error = error_handler;
  // reset global error code
  gError = XQC_NO_ERROR;
  return lErrorHandler;
}

/**
 * Use an error handler and test it by preparing a syntactically wrong query.
 */
int
cerror_example_1(XQC_Implementation* impl)
{
  XQC_Error         lError = XQC_NO_ERROR;
  XQC_Expression*   lExpr;
  XQC_StaticContext* lCtx;
  XQC_ErrorHandler* lErrorHandler = create_error_handler();

  // Assign error handler to the static context
  impl->create_context(impl, &lCtx);
  lCtx->set_error_handler(lCtx, lErrorHandler);

  // compile the query
  lError = impl->prepare(impl, "for $i in 1, 2, 3", lCtx, &lExpr);

  // no need to free the query
  // because it was not successfully created
  free(lErrorHandler);
  lCtx->free(lCtx);

  return (gError == XQC_STATIC_ERROR && lError == XQC_STATIC_ERROR) ? 1 : 0;
}

/**
 * Use an error handler and test it by executing a query that raises an error.
 */
int
cerror_example_2(XQC_Implementation* impl)
{
  XQC_Expression*   lExpr;
  XQC_DynamicContext* lCtx;
  XQC_ErrorHandler* lErrorHandler = create_error_handler();
  XQC_Sequence*     lResult;

  // compile the query
  impl->prepare(impl, "1 div 0", NULL, &lExpr);

  // set the error handler for handling errors
  // during query execution
  lExpr->create_context(lExpr, &lCtx);
  lCtx->set_error_handler(lCtx, lErrorHandler);

  // execute it and iterate results
  lExpr->execute(lExpr, lCtx, &lResult);
  while (lResult->next(lResult) == XQC_NO_ERROR);
  
  // release all resources
  lResult->free(lResult);
  lExpr->free(lExpr);
  lCtx->free(lCtx);
  free(lErrorHandler);

  return gError == XQC_DYNAMIC_ERROR ? 1 : 0;
}

int
cerror_example_3(XQC_Implementation* impl) 
{
  XQC_Error       lError = XQC_NO_ERROR;
  XQC_Expression* lExpr;
  XQC_StaticContext* lCtx;
  const char*     lStringValue;
  XQC_Sequence*   lResult;
  XQC_ErrorHandler* lErrorHandler = create_error_handler();

  // Assign error handler to the static context
  impl->create_context(impl, &lCtx);
  lCtx->set_error_handler(lCtx, lErrorHandler);

  // compile the query and get the result as a sequence
  lError = impl->prepare(impl, "for $i in (3, 2, 1, 0) return 3 div $i",
    lCtx, &lExpr);

  lExpr->execute(lExpr, NULL, &lResult);

  // an error is reported during the last for iteration
  // the error callback function is called and the loop terminates
  while ( lResult->next(lResult) == XQC_NO_ERROR ) {
    lResult->string_value(lResult, &lStringValue);
    printf("%s ", lStringValue);
  }

  // release all aquired resources
  free(lErrorHandler);
  lResult->free(lResult);
  lExpr->free(lExpr);
  lCtx->free(lCtx);

  return (gError == XQC_DYNAMIC_ERROR && lError == XQC_NO_ERROR) ? 1 : 0;
}

int
cerror(int argc, char** argv)
{
  int res = 0; 
  XQC_Implementation* impl;

  void* store = create_store();

  if ( zorba_implementation(&impl, store) != XQC_NO_ERROR)
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
  shutdown_store(store);

  return 0;
}
