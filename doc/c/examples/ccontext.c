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

#include "helpers.h"

/**
 * An example that shows how to use the dynamic context to set the context item.
 */
int
ccontext_example_1(XQC_Implementation* impl)
{
  XQC_Error           lError;
  XQC_Expression*     lExpr;
  XQC_DynamicContext* lContext;
  XQC_Sequence*       lSeq;
  XQC_Sequence*       lResult;
  const char*         lZorba[] = { "Zorba" };

  // Create a sequence with a single string item, and advance to that item
  lError = impl->create_string_sequence(impl, lZorba, 1, &lSeq);
  if (check_error("create_string_sequence", lError)) return 0;
  lError = lSeq->next(lSeq);
  if (check_error("next", lError)) return 0;

  lError = impl->prepare(impl, "(., ., .)", NULL, &lExpr);
  if (check_error("prepare", lError)) return 0;

  // get the dynamic context and set the context item
  lError = lExpr->create_context(lExpr, &lContext);
  if (check_error("create_context", lError)) return 0;
  lError = lContext->set_context_item(lContext, lSeq);
  if (check_error("set_context_item", lError)) return 0;

  // execute the query
  lError = lExpr->execute(lExpr, lContext, &lResult);
  if (check_error("execute", lError)) return 0;
  while ( (lResult->next(lResult)) == XQC_NO_ERROR) {
    const char* lValue;
    lResult->string_value(lResult, &lValue);
    printf("%s\n", lValue);
    if ( (strcmp("Zorba", lValue)) != 0 ) {
      printf("Incorrect value: %s\n", lValue);
      break;
    }
  }

  // free all resources
  lResult->free(lResult);
  lContext->free(lContext);
  lExpr->free(lExpr);
  // Must free lSeq also since it was bound to the context item, not a variable
  lSeq->free(lSeq);
  return 1;
}

/**
 * An example that shows how to use the static context with a new collation.
 * No error checking is done.
 */
int
ccontext_example_2(XQC_Implementation* impl)
{
/* TODO reimplement with Zorba_StaticContext for collations */
/*   XQC_Expression*          lExpr; */
/*   XQC_StaticContext*  lContext; */
/*   FILE*              lOutFile = stdout; */
/*   const char*        lStringValue; */

/*   impl->create_context(impl, &lContext); */

/*   lContext->set_base_uri(lContext, "http://www.zorba-xquery.com/"); */
/*   lContext->add_collation(lContext, "http://www.zorba-xquery.com/collations/PRIMARY/de/DE"); */

/*   lContext->get_base_uri(lContext, &lStringValue); */
/*   if ( strcmp (lStringValue, "http://www.zorba-xquery.com/") != 0) return 0; */

/*   impl->prepare(impl,  */
/*                 "fn:compare('Strasse', 'Straße', 'http://www.zorba-xquery.com/collations/PRIMARY/de/DE')", */
/*                 lContext, &lExpr); */

/*   lExpr->execute(lExpr, NULL, lOutFile); */

/*   lContext->free(lContext); */
/*   lExpr->free(lExpr); */
  return 1;
}

/**
 * Compile a query with a static context supplied, modify the context in the query and check
 * if the context was modified after the query has been prepared.
 * No error checking is done.
 */
int
ccontext_example_3(XQC_Implementation* impl)
{
/* TODO no get_static_context()? */
/*   XQC_Error          lError = XQC_NO_ERROR; */
/*   XQC_Expression*         lExpr; */
/*   XQC_StaticContext* lProvidedContext; */
/*   XQC_StaticContext* lQueryContext; */
/*   FILE*              lOutFile = stdout; */
/*   ordering_mode_t    lOrderingMode; */

/*   impl->create_context(impl, &lProvidedContext); */

/*   // get the ordering mode and print it */
/*   lProvidedContext->get_ordering_mode(lProvidedContext, &lOrderingMode); */
/*   printf("%s %i", "ordering mode ", lOrderingMode); */
  
/*   // compile and execute the query and get the new static context after executing the query */
/*   impl->prepare(impl, "declare ordering unordered; 1", lProvidedContext, 0, &lExpr); */
/*   lError = lExpr->execute(lExpr, lOutFile); */
/*   lExpr->get_static_context(lExpr, &lQueryContext); */

/*   // get the ordering mode and print it */
/*   lProvidedContext->get_ordering_mode(lQueryContext, &lOrderingMode); */
/*   printf("%s %i", "ordering mode ", lOrderingMode); */

/*   lProvidedContext->free(lProvidedContext); */
/*   lQueryContext->free(lQueryContext); */
/*   lExpr->free(lExpr); */
  return 1;
}

/**
 * Chain two queries, i.e. pipe the result of executing query one into a variable used in query 2.
 * No error checking is done.
 */
int
ccontext_example_4(XQC_Implementation* impl)
{
  XQC_Expression*          lExpr1;
  XQC_Expression*          lExpr2;

  XQC_DynamicContext* lContext;
  XQC_Sequence*       lSequence1;

  XQC_Sequence*       lSequence2;
  const char*        lStringValue;

  // compile the first query and get its result sequence
  impl->prepare(impl, "for $i in (1, 2, 3) return $i", NULL, &lExpr1);

  lExpr1->execute(lExpr1, NULL, &lSequence1);

  // compile the sequence query
  impl->prepare(impl, "declare variable $var external; ($var, $var)", NULL, &lExpr2);

  // get the dynamic context and set the external variable
  lExpr2->create_context(lExpr2, &lContext);

  lContext->set_variable(lContext, NULL, "var", lSequence1);

  lExpr2->execute(lExpr2, lContext, &lSequence2);

  // iterate over the result two times
  while ( lSequence2->next(lSequence2) != XQC_END_OF_SEQUENCE ) {
    lSequence2->string_value(lSequence2, &lStringValue);
    printf("%s ", lStringValue);
  }

  // free all resources

  lSequence2->free(lSequence2);
  lExpr2->free(lExpr2);
  lContext->free(lContext);

  lSequence1->free(lSequence1);
  lExpr1->free(lExpr1);

  return 1;
}

/**
 * Example showing how to bind a variable to a simple value.
 */
int
ccontext_example_5(XQC_Implementation* impl)
{
  XQC_Error           lError;
  XQC_Expression*     lExpr;
  XQC_DynamicContext* lContext;
  XQC_Sequence*       lSeq;
  XQC_Sequence*       lResult;
  const char*         lZorba[] = { "Zorba" };

  // Create a sequence with a single string item, and advance to that item
  lError = impl->create_string_sequence(impl, lZorba, 1, &lSeq);
  if (check_error("create_string_sequence", lError)) return 0;
/*   lError = lSeq->next(lSeq); */
/*   if (check_error("next", lError)) return 0; */

  lError = impl->prepare(impl,
    "declare namespace ns=\"http://www.zorba-xquery.com/\";\n"
    "declare variable $ns:foo as xs:string external;\n"
    "($ns:foo, $ns:foo, $ns:foo)", NULL, &lExpr);
  if (check_error("prepare", lError)) return 0;

  // get the dynamic context and set the context item
  lError = lExpr->create_context(lExpr, &lContext);
  if (check_error("create_context", lError)) return 0;
  lError = lContext->set_variable(lContext, "http://www.zorba-xquery.com/",
    "foo", lSeq);
  if (check_error("set_variable", lError)) return 0;

  // execute the query
  lError = lExpr->execute(lExpr, lContext, &lResult);
  if (check_error("execute", lError)) return 0;
  while ( (lResult->next(lResult)) == XQC_NO_ERROR) {
    const char* lValue;
    lResult->string_value(lResult, &lValue);
    printf("%s\n", lValue);
    if ( (strcmp("Zorba", lValue)) != 0 ) {
      printf("Incorrect value: %s\n", lValue);
      break;
    }
  }

  // free all resources
  lResult->free(lResult);
  lContext->free(lContext);
  lExpr->free(lExpr);
  // Must free lSeq also since it was bound to the context item, not a variable
  lSeq->free(lSeq);
  return 1;
}


int
ccontext(int argc, char** argv)
{
  int res = 0; 
  XQC_Implementation* impl;

  void* store = create_simple_store();

  if ( zorba_implementation(&impl, store) != XQC_NO_ERROR)
    return 1;

  printf("executing C example 1\n");
  res = ccontext_example_1(impl);
  if (!res) { impl->free(impl); return 1; };
  printf("\n");

  printf("executing C example 2\n");
  res = ccontext_example_2(impl);
  if (!res) { impl->free(impl); return 1; };
  printf("\n");

  printf("executing C example 3\n");
  res = ccontext_example_3(impl);
  if (!res) { impl->free(impl); return 1; };
  printf("\n");

  printf("executing C example 4\n");
  res = ccontext_example_4(impl);
  if (!res) { impl->free(impl); return 1; };
  printf("\n");

  printf("executing C example 5\n");
  res = ccontext_example_5(impl);
  if (!res) { impl->free(impl); return 1; };
  printf("\n");

  impl->free(impl);
  shutdown_simple_store(store);
  return 0;
}
