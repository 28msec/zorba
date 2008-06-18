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
#include <inmemorystore/inmemorystorec.h>

// user define data struct
// created in my_ext_fct_init
// passed to my_ext_fct_next
// released in my_ext_fct_release
typedef struct
{
  XQC_Item        item;
  XQC_ItemFactory factory;
  XQC_Sequence    seq;
  int             i;
} my_ext_data;

// callback function called once when initializing the external function
// The user_data parameter can be created in this function and is available
// during the execution.
// The global_user_data parameter can be supplied as a parameter to the
// XQC_StaticContext::register_external_function function
void
my_ext_fct_init(void** user_data, void* global_user_data)
{
  XQC_Implementation impl = (XQC_Implementation) global_user_data;
  my_ext_data* data;

  *user_data = malloc(sizeof(my_ext_data));

  data = (my_ext_data*)(*user_data);
  data->i = 0;

  impl->item_factory(impl, &(data->factory));  
  impl->create_item(impl, &(data->item));
}

// callback function called for each invocation of the external function in the query
XQUERY_ERROR
my_ext_fct_next(XQC_Sequence args, // arguments
                int argc, // number of arguments two this function
                XQC_Item_Ref result,
                void* user_data,
                void* global_user_data)
{
  my_ext_data* data = (my_ext_data*)(user_data);

  // concat the input sequence
  while ( data->i < argc ) {
    if ( args[data->i].next(&(args[data->i]), data->item) != API0025_END_OF_SEQUENCE ) {
      *result = data->item;
      return XQ_NO_ERROR;
    }
    ++(data->i);
  }

  return API0025_END_OF_SEQUENCE;
  

}

// called after the execution of the query has finished
// cleanup of the user_data should be done here
void
my_ext_fct_release(void* user_data,
                   void* global_user_data)
{
  my_ext_data* data = (my_ext_data*)(user_data);
  data->item->free(data->item);
  data->factory->free(data->factory);
  free(user_data);
}

/**
 * register an external function in the static context and execute a query with it
 */
int
external_function_example_1(XQC_Implementation impl)
{
  XQC_Query          lXQuery;
  XQC_StaticContext  lContext;

  impl->create_context(impl, &lContext);

  lContext->register_external_function(lContext, "urn:foo", "bar", 
                                       my_ext_fct_init, 
                                       my_ext_fct_next, 
                                       my_ext_fct_release,
                                       impl);

  impl->prepare(impl, "declare namespace foo=\"urn:foo\"; declare function foo:bar($x, $y, $z) external; foo:bar((1, 2, 3), 1, 2)", lContext, 0, &lXQuery);

  // execute it and print the result on standard out
  lXQuery->execute(lXQuery, stdout);

  // release resources
  lXQuery->free(lXQuery);
  lContext->free(lContext);

  return 1;
}

int
cexternal_functions(int argc, char** argv)
{
  int res = 0; 
  XQC_Implementation impl;

  void* store = create_inmemory_store();

  if ( zorba_implementation(&impl, store) != XQ_NO_ERROR)
      return 1;

  printf("executing C example 1\n");
  res = external_function_example_1(impl);
  if (!res) { impl->free(impl); return 1; };
  printf("\n");

  impl->free(impl);
  shutdown_inmemory_store(store);

  return 0;
}
