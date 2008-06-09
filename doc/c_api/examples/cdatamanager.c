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

/**
 */
int
cdatamanager_example_1(XQC_Implementation impl, XQC_DataManager mgr)
{
  XQC_Collection     lCollection;
  XQC_Item           lURIItem;
  XQC_Query          lXQuery;
  XQC_DynamicContext lDynContext;
  const char*        lStringBuffer;
  FILE*              lOutput = stdout;
  int                i;
  
  // create a new collection
  mgr->create_collection(mgr, "http://www.zorba-xquery.com/collections/mybooks", &lCollection);

  lCollection->get_uri(lCollection, &lURIItem);

  lURIItem->string_value(lURIItem, &lStringBuffer);

  printf("Collection URI %s\n", lStringBuffer);

  for (i = 0; i < 10 ; ++i)
    lCollection->add_document_char(lCollection, 
                                   "<books><book>Book 1</book><book>Book 2</book></books>");

  impl->prepare(impl, "for $i in fn:collection()[3] return $i//book", 0, &lXQuery);

  lXQuery->get_dynamic_context(lXQuery, &lDynContext);

  lDynContext->set_default_collection(lDynContext, lURIItem);

  lXQuery->execute(lXQuery, lOutput);

  // free all resources
  lDynContext->free(lDynContext);
  lXQuery->free(lXQuery);
  lURIItem->free(lURIItem);
  lCollection->free(lCollection);

  return 1;
}

int
cdatamanager(int argc, char** argv)
{
  int res = 0; 
  XQC_Implementation impl;
  XQC_DataManager mgr;

  void* store = create_inmemory_store();

  if ( zorba_implementation(&impl, store) != XQ_NO_ERROR)
    return 1;
 
  impl->data_manager(impl, &mgr);

  printf("executing C example 1\n");
  res = cdatamanager_example_1(impl, mgr);
  if (!res) { impl->free(impl); return 1; };
  printf("\n");

  mgr->free(mgr);
  impl->free(impl);
  shutdown_inmemory_store(store);
  return 0;
}
