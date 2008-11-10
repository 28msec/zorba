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
#include <simplestore/simplestorec.h>


/**
 * Example that shows HTML serialization of the results.
 */
int
cserialization_example_1(XQC_Implementation impl)
{
  XQC_Query      lXQuery;
  FILE*          lOutFile = stdout;
  Zorba_SerializerOptions_t* lSerOptions = Zorba_SerializerOptions_default();

  // compile the query
  impl->prepare(impl, "(1+2, 3, 4)", 0, 0, &lXQuery);

  // Set serialization method to html
  Zorba_SerializerOptions_set(lSerOptions, "method", "html");

  // execute it and print the result on standard out
  lXQuery->serialize_file(lXQuery, lSerOptions, lOutFile);

  // release the serialization options
  Zorba_SerializerOptions_free(lSerOptions);
  
  // release the query
  lXQuery->free(lXQuery);

  return 1;
}

/**
 * Example that shows how the serializer options can be used to
 * omit the xml declaration when serializing the query result.
 */
int
cserialization_example_2(XQC_Implementation impl)
{
  XQC_Query      lXQuery;
  FILE*          lOutFile = stdout;
  Zorba_SerializerOptions_t* lSerOptions = Zorba_SerializerOptions_default();

  // compile the query
  impl->prepare(impl, "(1+2, 3, 4)", 0, 0, &lXQuery);

  // Omit the <?xml?> declaration
  Zorba_SerializerOptions_set(lSerOptions, "omit-xml-declaration", "yes");

  // execute it and print the result on standard out
  lXQuery->serialize_file(lXQuery, lSerOptions, lOutFile);
  
  // release the serialization options
  Zorba_SerializerOptions_free(lSerOptions);

  // release the query
  lXQuery->free(lXQuery);

  return 1;
}

// callback function used by the XQC_OutputStream
void
stream_writer(XQC_OutputStream stream, const char* buf, unsigned int length)
{
  printf("%s", buf);
}

// callback function called after the query result has been completely serialized
void
free_writer(XQC_OutputStream stream)
{
  free(stream);
}

int
cserialization_example_3(XQC_Implementation impl)
{
  XQC_Query      lXQuery;
  XQC_OutputStream lStream = (XQC_OutputStream) malloc(sizeof(struct XQC_OutputStream_s));

  lStream->write  = stream_writer;
  lStream->free   = free_writer;

  // compile the query
  impl->prepare(impl, "(1+2, 3, 4)", 0, 0, &lXQuery);

  // execute it and stream the result to the supplied XQC_OutputStream
  lXQuery->serialize_stream(lXQuery, 0, lStream);

  // release the query
  lXQuery->free(lXQuery);

  return 1;
}

int
cserialization(int argc, char** argv)
{
  int res = 0; 
  XQC_Implementation impl;

  void* store = create_simple_store();

  if ( zorba_implementation(&impl, store) != XQ_NO_ERROR)
    return 1;

  printf("executing C example 1\n");
  res = cserialization_example_1(impl);
  if (!res) { impl->free(impl); return 1; };
  printf("\n");

  printf("executing C example 2\n");
  res = cserialization_example_2(impl);
  if (!res) { impl->free(impl); return 2; };
  printf("\n");

  printf("executing C example 3\n");
  res = cserialization_example_3(impl);
  if (!res) { impl->free(impl); return 3; };
  printf("\n");

  impl->free(impl);
  shutdown_simple_store(store);
   
  return 0;
}
