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
  XQC_Item           lItem;
  XQC_String         lString = 0;

  // create string
  impl->create_string(impl, "Zorba", &lString);

  // get the ItemFactory and create a string item
  impl->item_factory(impl, &lFactory);
  lFactory->create_string(lFactory, lString, &lItem);

  impl->compile(impl, "(., ., .)", 0, &lXQuery);

  // get the dynmamic context and set the context item
  lXQuery->get_dynamic_context(lXQuery, &lContext);

  lContext->set_context_item(lContext, lItem);

  // execute the query
  lXQuery->execute(lXQuery, lOutFile);

  // free all resources
  lItem->free(lItem);
  lString->free(lString);
  lXQuery->free(lXQuery);
  lFactory->free(lFactory);

  return 1;
}

int
ccontext_example_2(XQC_Implementation impl)
{
  XQUERY_ERROR       lError = XQ_SUCCESS;
  XQC_Query          lXQuery;
  XQC_StaticContext  lContext;
  FILE*              lOutFile = stdout;
  XQC_String         lBaseURI;
  XQC_String         lCollation;
  XQC_String         lTmpString;
  const char*        lStringValue;

  impl->create_string(impl, "http://www.flworfound.org/", &lBaseURI);
  impl->create_string(impl, "http://www.flworfound.org/collations/PRIMARY/de/DE", &lCollation);

  impl->create_context(impl, &lContext);

  lContext->set_base_uri(lContext, lBaseURI);
  lContext->add_collation(lContext, lCollation);

  lContext->get_base_uri(lContext, &lTmpString);
  lTmpString->to_char(lTmpString, &lStringValue);
  if ( strcmp (lStringValue, "http://www.flworfound.org/") != 0) return 0;

  impl->compile(impl, 
                "fn:compare('Strasse', 'Straße', 'http://www.flworfound.org/collations/PRIMARY/de/DE')",
                lContext, &lXQuery);

  lError = lXQuery->execute(lXQuery, lOutFile);

  lTmpString->free(lTmpString);
  lCollation->free(lCollation);
  lBaseURI->free(lBaseURI);
  lContext->free(lContext);
  lXQuery->free(lXQuery);
  return 1;
}

int
ccontext_example_3(XQC_Implementation impl)
{
  XQUERY_ERROR       lError = XQ_SUCCESS;
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
  impl->compile(impl, "declare ordering unordered; 1", lProvidedContext, &lXQuery);
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
  FILE*              lOutFile = stdout;

  XQC_DynamicContext lContext;
  XQC_Sequence       lSequence;
  XQC_String         lVarName;

  // compile the first query and get its result sequence
  impl->compile(impl, "for $i in (1, 2, 3) return $i", 0, &lXQuery1);

  lXQuery1->sequence(lXQuery1, &lSequence);

  // compile the sequence query
  impl->compile(impl, "declare variable $var external; $var * $var", 0, &lXQuery2);

  // get the dynmamic context and set the context item
  lXQuery2->get_dynamic_context(lXQuery2, &lContext);

  impl->create_string(impl, "var", &lVarName);
  lContext->set_variable_sequence(lContext, lVarName, lSequence);

  // execute the query
  lXQuery2->execute(lXQuery2, lOutFile);

  // free all resources
  lXQuery2->free(lXQuery2);
  lContext->free(lContext);
  lVarName->free(lVarName);

  lSequence->free(lSequence);
  lXQuery1->free(lXQuery1);

  return 1;
}

int
ccontext(int argc, char** argv)
{
  int res = 0; 
  XQC_Implementation impl;

  if ( zorba_implementation(&impl) != XQ_SUCCESS )
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

#if 0
  printf("executing C example 4\n");
  res = ccontext_example_4(impl);
  if (!res) { impl->free(impl); return 1; };
  printf("\n");
#endif

  impl->free(impl);
  return 0;
}
