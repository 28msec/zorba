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
#include <store/naive/simple_storec.h>


/**
 * A C API example that shows how to use the static and dynamic context.
 * No error checking is done.
 */
int
ccontext_example_1(XQC_Implementation impl)
{
  XQC_Query          lXQuery;
  XQC_DynamicContext lContext;
  XQC_ItemFactory    lFactory;
  FILE*              lOutFile = stdout;
  XQC_Item           lItem = 0;

  impl->item_factory(impl, &lFactory);
  lFactory->create_string(lFactory, "Zorba", &lItem);

  impl->prepare(impl, "(., ., .)", 0, &lXQuery);

  // get the dynmamic context and set the context item
  lXQuery->get_dynamic_context(lXQuery, &lContext);

  lContext->set_context_item(lContext, lItem);

  // execute the query
  lXQuery->execute(lXQuery, lOutFile);

  // free all resources
  lContext->free(lContext);
  lItem->free(lItem);
  lXQuery->free(lXQuery);
  lFactory->free(lFactory);

  return 1;
}

int
ccontext_example_2(XQC_Implementation impl)
{
  XQC_Query          lXQuery;
  XQC_StaticContext  lContext;
  FILE*              lOutFile = stdout;
  const char*        lStringValue;

  impl->create_context(impl, &lContext);

  lContext->set_base_uri(lContext, "http://www.flworfound.org/");
  lContext->add_collation(lContext, "http://www.flworfound.org/collations/PRIMARY/de/DE");

  lContext->get_base_uri(lContext, &lStringValue);
  if ( strcmp (lStringValue, "http://www.flworfound.org/") != 0) return 0;

  impl->prepare(impl, 
                "fn:compare('Strasse', 'Straße', 'http://www.flworfound.org/collations/PRIMARY/de/DE')",
                lContext, &lXQuery);

  lXQuery->execute(lXQuery, lOutFile);

  lContext->free(lContext);
  lXQuery->free(lXQuery);
  return 1;
}

int
ccontext_example_3(XQC_Implementation impl)
{
  XQUERY_ERROR       lError = XQ_NO_ERROR;
  XQC_Query          lXQuery;
  XQC_StaticContext  lProvidedContext;
  XQC_StaticContext  lQueryContext;
  FILE*              lOutFile = stdout;
  ordering_mode_t    lOrderingMode;

  impl->create_context(impl, &lProvidedContext);

  // get the ordering mode and print it
  lProvidedContext->get_ordering_mode(lProvidedContext, &lOrderingMode);
  printf("%s %i", "ordering mode ", lOrderingMode);
  
  // compile and execute the query and get the new static context after executing the query
  impl->prepare(impl, "declare ordering unordered; 1", lProvidedContext, &lXQuery);
  lError = lXQuery->execute(lXQuery, lOutFile);
  lXQuery->get_static_context(lXQuery, &lQueryContext);

  // get the ordering mode and print it
  lProvidedContext->get_ordering_mode(lQueryContext, &lOrderingMode);
  printf("%s %i", "ordering mode ", lOrderingMode);

  lProvidedContext->free(lProvidedContext);
  lQueryContext->free(lQueryContext);
  lXQuery->free(lXQuery);
  return 1;
}

int
ccontext_example_4(XQC_Implementation impl)
{
  XQC_Query          lXQuery1;
  XQC_Query          lXQuery2;

  XQC_DynamicContext lContext;
  XQC_Sequence       lSequence1;

  XQC_Sequence       lSequence2;
  XQC_Item           lItem = 0;
  const char*        lStringValue;

  // compile the first query and get its result sequence
  impl->prepare(impl, "for $i in (1, 2, 3) return $i", 0, &lXQuery1);

  lXQuery1->sequence(lXQuery1, &lSequence1);

  // compile the sequence query
  impl->prepare(impl, "declare variable $var external; ($var, $var)", 0, &lXQuery2);

  // get the dynmamic context and set the context item
  lXQuery2->get_dynamic_context(lXQuery2, &lContext);

  lContext->set_variable_sequence(lContext, "var", lSequence1);

  lXQuery2->sequence(lXQuery2, &lSequence2);

  // create an Item and a String holder
  impl->create_item(impl, &lItem);

  // iterate over the result two times
  while ( lSequence2->next(lSequence2, lItem) != API0025_END_OF_SEQUENCE ) {
    lItem->string_value(lItem, &lStringValue);
    printf("%s ", lStringValue);
  }

  // free all resources
  lItem->free(lItem);

  lSequence2->free(lSequence2);
  lXQuery2->free(lXQuery2);
  lContext->free(lContext);

  lSequence1->free(lSequence1);
  lXQuery1->free(lXQuery1);

  return 1;
}

int
ccontext(int argc, char** argv)
{
  int res = 0; 
  XQC_Implementation impl;

  void* store = create_simple_store();

  if ( zorba_implementation(&impl, store) != XQ_NO_ERROR)
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

  impl->free(impl);
  return 0;
}
