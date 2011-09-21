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

// user define data struct
// created in my_ext_fct_init
// passed to my_ext_fct_next
// released in my_ext_fct_release
typedef struct
{
  unsigned int i;
} my_ext_data;

// callback function called once when initializing the external function
// The user_data parameter can be created in this function and is available
// during the execution.
// The function_user_data parameter is supplied as a parameter to the
// Zorba_StaticContext::register_external_function method and passed to
// all callbacks.
void
my_ext_fct_init(void** user_data, void* function_user_data)
{
  my_ext_data* data;

  *user_data = malloc(sizeof(my_ext_data));

  data = (my_ext_data*)(*user_data);
  data->i = 0;
}

// callback function called to retrieve the next item in the external
// function's result. The Zorba_ItemSetter struct is used to provide that
// item. This function should return XQC_END_OF_SEQUENCE when it is done.
XQC_Error
my_ext_fct_next(XQC_Sequence** args, unsigned int argc,
  Zorba_ItemSetter* setter, void* user_data, void* function_data)
{
  // Our function concantenates the input argument sequences
  my_ext_data* data = (my_ext_data*) user_data;
  while (data->i < argc) {
    XQC_Sequence* lSeq = args[data->i];
    XQC_ItemType lItemType;
    if ( (lSeq->next(lSeq)) == XQC_END_OF_SEQUENCE) {
      // Finished one of the arguments
      data->i++;
      continue;
    }
    lSeq->item_type(lSeq, &lItemType);
    switch (lItemType) {
      case XQC_DECIMAL_TYPE: {
        int lValue;
        lSeq->integer_value(lSeq, &lValue);
        setter->set_integer(setter, lValue);
        break;
      }
      case XQC_DOUBLE_TYPE: {
        double lValue;
        lSeq->double_value(lSeq, &lValue);
        setter->set_double(setter, lValue);
        break;
      }
      case XQC_STRING_TYPE: {
        const char* lValue;
        lSeq->string_value(lSeq, &lValue);
        setter->set_string(setter, lValue);
        break;
      }
      case XQC_ANY_URI_TYPE:
      case XQC_DATE_TYPE:
      case XQC_DATE_TIME_TYPE:
      case XQC_DURATION_TYPE:
      case XQC_FLOAT_TYPE:
      case XQC_G_DAY_TYPE:
      case XQC_G_MONTH_TYPE:
      case XQC_G_MONTH_DAY_TYPE:
      case XQC_G_YEAR_TYPE:
      case XQC_G_YEAR_MONTH_TYPE:
      case XQC_TIME_TYPE: {
        const char* lValue;
        lSeq->string_value(lSeq, &lValue);
        setter->set_typed_value(setter, lItemType, lValue);
        break;
      }

      default:
        printf("Unsupported type %d\n", lItemType);
        break;
    }
    return XQC_NO_ERROR;
  }

  return XQC_END_OF_SEQUENCE;
}

// called after the execution of the query has finished
// cleanup of the user_data should be done here
void
my_ext_fct_free(void* user_data, void* function_user_data)
{
  my_ext_data* data = (my_ext_data*)(user_data);
  free(data);
}

/**
 * register an external function in the static context and execute a
 * query with it
 */
int
external_function_example_1(XQC_Implementation* impl)
{
  XQC_Expression*     lExpr;
  XQC_StaticContext*  lContext;
  Zorba_StaticContext* lZContext;
  XQC_Sequence*       lSeq;

  impl->create_context(impl, &lContext);
  lZContext = (Zorba_StaticContext*)
    lContext->get_interface(lContext, "Zorba_StaticContext");
  lZContext->register_external_function(lZContext, "urn:foo", "bar",
    my_ext_fct_init, my_ext_fct_next, my_ext_fct_free, impl);

  impl->prepare(impl,
    "declare namespace foo=\"urn:foo\";\n"
    "declare function foo:bar($x, $y, $z) external;\n"
    "( foo:bar((1, 2, 3), \"2.57\", xs:double(2.57)),\n"
    "  foo:bar(xs:date(\"2010-01-13\"), xs:gYear(\"1984\"), xs:float(2.57)) )",
    lContext, &lExpr);

  // execute it and print the result on standard out
  lExpr->execute(lExpr, NULL, &lSeq);
  while ( lSeq->next(lSeq) == XQC_NO_ERROR ) {
    XQC_ItemType lItemType;
    lSeq->item_type(lSeq, &lItemType);
    switch (lItemType) {
      case XQC_DECIMAL_TYPE: {
        int lValue;
        lSeq->integer_value(lSeq, &lValue);
        printf("[int] %d\n", lValue);
        break;
      }
      case XQC_DOUBLE_TYPE: {
        double lValue;
        lSeq->double_value(lSeq, &lValue);
        printf("[double] %f\n", lValue);
        break;
      }
      case XQC_STRING_TYPE: {
        const char* lValue;
        lSeq->string_value(lSeq, &lValue);
        printf("[string] %s\n", lValue);
        break;
      }
      case XQC_ANY_URI_TYPE:
      case XQC_DATE_TYPE:
      case XQC_DATE_TIME_TYPE:
      case XQC_DURATION_TYPE:
      case XQC_FLOAT_TYPE:
      case XQC_G_DAY_TYPE:
      case XQC_G_MONTH_TYPE:
      case XQC_G_MONTH_DAY_TYPE:
      case XQC_G_YEAR_TYPE:
      case XQC_G_YEAR_MONTH_TYPE:
      case XQC_TIME_TYPE: {
        const char* lValue;
        const char* lTypename;
        lSeq->type_name(lSeq, &lValue, &lTypename);
        lSeq->string_value(lSeq, &lValue);
        printf("[typed_value %s] %s\n", lTypename, lValue);
        break;
      }

      default:
        printf("Unsupported type %d\n", lItemType);
        break;
    }
  }
  printf("\n");

  // release resources
  lSeq->free(lSeq);
  lExpr->free(lExpr);
  lContext->free(lContext);

  return 1;
}

int
cexternal_functions(int argc, char** argv)
{
  int res = 0; 
  XQC_Implementation* impl;

  void* store = create_store();

  if ( zorba_implementation(&impl, store) != XQC_NO_ERROR)
      return 1;

  printf("executing C example 1\n");
  res = external_function_example_1(impl);
  if (!res) { impl->free(impl); return 1; };
  printf("\n");

  impl->free(impl);
  shutdown_store(store);

  return 0;
}
