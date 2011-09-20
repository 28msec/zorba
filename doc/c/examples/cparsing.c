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

#include "helpers.h"

const char* cparsing_xml =
  "<doc><a b=\"5\"><elem>hello</elem><elem>world</elem></a></doc>";


// define the callback functions fot the input stream
unsigned int
read_document_stream(XQC_InputStream* stream, void* buf, unsigned int length) 
{
  strcpy(buf, cparsing_xml);
  return strlen(cparsing_xml);
}

void
free_document_stream(XQC_InputStream* stream) 
{
  free(stream);
}


/**
 * Utility testing method for parsed documents.
 */
int
parse_test(XQC_Implementation* impl, XQC_Sequence* doc)
{
  XQC_Error           lError;
  XQC_Expression*     lExpr;
  XQC_DynamicContext* lContext;
  XQC_Sequence*       lResult;

  // Advance to the document node in the sequence (since we will bind
  // to the context *item*)
  lError = doc->next(doc);
  if (check_error("next", lError)) return 0;

  // Compile query over document
  lError = impl->prepare(impl, "./doc/a/elem/text()", NULL, &lExpr);
  if (check_error("prepare", lError)) return 0;

  // get the dynamic context and set the context item
  lError = lExpr->create_context(lExpr, &lContext);
  if (check_error("create_context", lError)) return 0;
  lError = lContext->set_context_item(lContext, doc);
  if (check_error("set_context_item", lError)) return 0;

  // execute the query
  lError = lExpr->execute(lExpr, lContext, &lResult);
  if (check_error("execute", lError)) return 0;
  while ( (lResult->next(lResult)) == XQC_NO_ERROR) {
    const char* lValue;
    lResult->string_value(lResult, &lValue);
    printf("%s\n", lValue);
  }

  // free all resources
  lResult->free(lResult);
  lContext->free(lContext);
  lExpr->free(lExpr);
  // Must free the document sequence also since it was bound to the
  // context item, not a variable
  doc->free(doc);
  return 1;
}


/**
 * Execute a query over an XML document parsed from a string.
 */
int
cparsing_example_1(XQC_Implementation* impl)
{
  XQC_Error     lError;
  XQC_Sequence* lDoc;

  // Create a sequence by parsing a document - will contain a single
  // document-node() item
  lError = impl->parse_document(impl, cparsing_xml, &lDoc);
  if (check_error("parse_document", lError)) return 0;

  // Complete test
  return parse_test(impl, lDoc);
}


/**
 * Execute a query over an XML document parsed from an XQC_InputStream.
 */
int
cparsing_example_2(XQC_Implementation* impl)
{
  XQC_Error        lError;
  XQC_InputStream* lStream = (XQC_InputStream*) malloc(sizeof(XQC_InputStream));
  XQC_Sequence*    lDoc;

  lStream->read = read_document_stream;
  lStream->free = free_document_stream;

  // Create a sequence by parsing a document - will contain a single
  // document-node() item
  lError = impl->parse_document_stream(impl, lStream, &lDoc);
  if (check_error("parse_document_stream", lError)) return 0;

  // Complete test
  return parse_test(impl, lDoc);
}


/**
 * Execute a query over an XML document parsed from a FILE*.
 */
int
cparsing_example_3(XQC_Implementation* impl)
{
  XQC_Error        lError;
  FILE*            lFile;
  XQC_Sequence*    lDoc;

  // Create a sequence by parsing a document - will contain a single
  // document-node() item
  lFile = fopen("cparsing.xml", "r");
  if (lFile == NULL) {
    printf("Could not open cparsing.xml - in wrong directory?\n");
    return 0;
  }
  lError = impl->parse_document_file(impl, lFile, &lDoc);
  if (check_error("parse_document_file", lError)) return 0;
  fclose(lFile);

  // Complete test
  return parse_test(impl, lDoc);
}


int
cparsing(int argc, char** argv)
{
  int res = 0; 
  XQC_Implementation* impl;

  void* store = create_store();

  for (res = 0; res < argc; res++) {
    printf("####%s\n", argv[res]);
  }

  if ( zorba_implementation(&impl, store) != XQC_NO_ERROR)
    return 1;

  printf("executing C parsing example 1\n");
  res = cparsing_example_1(impl);
  if (!res) { impl->free(impl); return 1; };
  printf("\n");

  printf("executing C parsing example 2\n");
  res = cparsing_example_2(impl);
  if (!res) { impl->free(impl); return 1; };
  printf("\n");

  printf("executing C parsing example 3\n");
  res = cparsing_example_3(impl);
  if (!res) { impl->free(impl); return 1; };
  printf("\n");

  impl->free(impl);
  shutdown_store(store);
  return 0;
}
