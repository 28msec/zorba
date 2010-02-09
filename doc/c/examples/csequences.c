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

/**
 * Utility function for checking XQC_Errors. Returns true if error raised.
 */
int
check_error(const char* func_name, XQC_Error error)
{
  if (error != XQC_NO_ERROR) {
    printf("%s returned %d\n", func_name, error);
    return 1;
  }
  return 0;
}

/**
 * Test case for create_foo_sequence. Args:
 * @arg ctype The C type.
 * @arg printftype The % escape sequence for the C type.
 * @arg typename The name of the type in XQC function names.
 * @arg xqctype The XQC_ItemType expected.
 * @arg schematype the localname of the schema type.
 *
 * Provide input array as a global variable named typename##Array;
 * must be of size 5. Also define a comparison function name
 * typename##Compare which takes two ctype args and returns int (0 for
 * equal, anything else for not equal).
 */
#define CREATE_FOO_SEQUENCE_TEST(ctype, printftype, typename, xqctype, schematype) \
  XQC_Error   lError = XQC_NO_ERROR;                                    \
  XQC_Sequence* lSeq;                                                   \
  int i;                                                                \
  const char* lUri;                                                      \
  const char* lName;                                                     \
  lError = impl->create_##typename##_sequence                           \
    (impl, typename##Array, 5, &lSeq);                                  \
  if (check_error("create_" #typename "_sequence", lError)) return 0;   \
  for (i = 0; i <= 4; i++) {                                            \
    ctype lValue;                                                       \
    XQC_ItemType lType;                                                 \
    lError = lSeq->next(lSeq);                                          \
    if (check_error("next", lError)) return 0;                          \
    lError = lSeq->item_type(lSeq, &lType);                             \
    if (check_error("item_type", lError)) return 0;                     \
    if (lType != xqctype) {                                             \
      printf("item_type returned wrong type %d for " #ctype " #%d\n",   \
        lType, i);                                                      \
      return 0;                                                         \
    }                                                                   \
    lError = lSeq->type_name(lSeq, &lUri, &lName);                      \
    if (check_error("type_name", lError)) return 0;                     \
    if (strcmp(lUri, "http://www.w3.org/2001/XMLSchema") != 0) {        \
      printf("type_name returned wrong namespace %s for " #ctype " #%d\n", \
        lUri, i);                                                       \
      return 0;                                                         \
    }                                                                   \
    if (strcmp(lName, #schematype) != 0) {                              \
      printf("type_name returned wrong localname %s for " #ctype " #%d\n", \
        lName, i);                                                      \
      return 0;                                                         \
    }                                                                   \
    lError = lSeq->typename##_value(lSeq, &lValue);                     \
    if (check_error(#typename "_value", lError)) return 0;              \
    if ( typename##Compare(lValue, typename##Array[i]) != 0 ) {         \
      printf("%s_value returned wrong value " #printftype               \
        " for " #ctype " #%d\n",                                        \
        #typename, lValue, i);                                          \
      return 0;                                                         \
    }                                                                   \
  }                                                                     \
  lSeq->free(lSeq);                                                     \
  return 1
  


// Test create_integer_sequence().

int integerArray[] = { 1, 25, 36, 49, 535631 };
int integerCompare(int a, int b) { return (a == b) ? 0 : 1; }

int
csequences_1(XQC_Implementation* impl)
{
  CREATE_FOO_SEQUENCE_TEST(int, %d, integer, XQC_DECIMAL_TYPE, int);
}


// Test create_double_sequence().

double doubleArray[] = { 1.0, 3.5, 86.9230985, 930.59, 3.1415926535 };
int doubleCompare(double a, double b) { return (a == b) ? 0 : 1; }

int
csequences_2(XQC_Implementation* impl)
{
  CREATE_FOO_SEQUENCE_TEST(double, %f, double, XQC_DOUBLE_TYPE, double);
}


// Test create_string_sequence().

const char* stringArray[] = { "hello", "world", "are", "you", "there" };
int stringCompare(const char* a, const char* b) { return (strcmp(a, b)); }

int
csequences_3(XQC_Implementation* impl)
{
  CREATE_FOO_SEQUENCE_TEST(const char*, %s, string, XQC_STRING_TYPE, string);
}


// Test create_empty_sequence().

int
csequences_4(XQC_Implementation* impl)
{
  XQC_Error lError = XQC_NO_ERROR;
  XQC_Sequence *lSeq;
  lError = impl->create_empty_sequence(impl, &lSeq);
  if (check_error("create_empty_sequence", lError)) return 0;
  lError = lSeq->next(lSeq);
  if (lError != XQC_END_OF_SEQUENCE) {
    printf("next failed to return XQC_END_OF_SEQUENCE for empty sequence");
    return 0;
  }
  lSeq->free(lSeq);
  return 1;  
}


// Test create_singleton_sequence(), with several types.

/**
 * Test case for create_singleton_sequence. Args:
 * @arg impl the XQC_Implementation.
 * @arg xqctype the XQC_ItemType.
 * @arg schematype the localname of the schema type.
 * @arg value the (string) value to test with.
 */
int
cr_sngl_test
(XQC_Implementation* impl, XQC_ItemType xqctype, const char* schematype,
  const char* value)
{
  XQC_Error lError = XQC_NO_ERROR;
  XQC_Sequence *lSeq;
  const char* lUri;
  const char* lName;
  const char* lValue;

  lError = impl->create_singleton_sequence(impl, xqctype, value, &lSeq);
  if (check_error("create_singleton_sequence", lError)) return 0;
  lError = lSeq->next(lSeq);
  if (check_error("next", lError)) return 0;
  lError = lSeq->type_name(lSeq, &lUri, &lName);
  if (check_error("type_name", lError)) return 0;
  if (strcmp(lUri, "http://www.w3.org/2001/XMLSchema") != 0) {
    printf("type_name returned wrong namespace %s for xqctype %d\n",
      lUri, xqctype);
    return 0;
  }
  if (strcmp(lName, schematype) != 0) {
    printf("type_name returned wrong localname %s for xqctype %d\n",
      lName, xqctype);
    return 0;
  }
  lError = lSeq->string_value(lSeq, &lValue);
  if (strcmp(lValue, value) != 0) {
    printf("string_value returned wrong value %s for xqctype %d\n", lValue,
      xqctype);
    return 0;
  }
  lError = lSeq->next(lSeq);
  if (lError != XQC_END_OF_SEQUENCE) {
    printf("more than one value from singleton sequence!");
    return 0;
  }
  // Leaks if test fails...
  lSeq->free(lSeq);
  return 1;
}

int csequences_5(XQC_Implementation* impl)
{
  int lI = 0;
  lI += cr_sngl_test(impl, XQC_ANY_URI_TYPE, "anyURI",
    "http://www.zorba-xquery.com/");
  lI += cr_sngl_test(impl, XQC_DATE_TYPE, "date", "2010-01-13");
  lI += cr_sngl_test(impl, XQC_FLOAT_TYPE, "float", "8.25");
  lI += cr_sngl_test(impl, XQC_DOUBLE_TYPE, "double", "8.25123532152");
  lI += cr_sngl_test(impl, XQC_STRING_TYPE, "string", "hello world!");
  lI += cr_sngl_test(impl, XQC_DECIMAL_TYPE, "decimal", "2.35");
  lI += cr_sngl_test(impl, XQC_G_YEAR_TYPE, "gYear", "1984");
  lI += cr_sngl_test(impl, XQC_TIME_TYPE, "time", "18:55:32");
  return (lI == 8) ? 1 : 0;
}

int
csequences(int argc, char** argv)
{
  int res = 0; 
  XQC_Implementation* impl;

  void* store = create_store();

  if ( zorba_implementation(&impl, store) != XQC_NO_ERROR)
    return 1;

  printf("executing C csequences 1\n");
  res = csequences_1(impl);
  if (!res) { impl->free(impl); return 1; };
  printf("\n");

  printf("executing C csequences 2\n");
  res = csequences_2(impl);
  if (!res) { impl->free(impl); return 1; };
  printf("\n");

  printf("executing C csequences 3\n");
  res = csequences_3(impl);
  if (!res) { impl->free(impl); return 1; };
  printf("\n");

  printf("executing C csequences 4\n");
  res = csequences_4(impl);
  if (!res) { impl->free(impl); return 1; };
  printf("\n");

  printf("executing C csequences 5\n");
  res = csequences_5(impl);
  if (!res) { impl->free(impl); return 1; };
  printf("\n");

  impl->free(impl);
  shutdown_store(store);
   
  return 0;
}
