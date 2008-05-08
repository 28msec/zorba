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
#include <zorbac/zorbac.h>

int example_1(XQUERY_CAPI* aAPI)
{

  XQUERY_ERROR lError = XQUERY_SUCCESS;

  XQUERY lXQuery = aAPI->compile("(1+2,3+4, 'This is a Test')", &lError);
  if (lError != XQUERY_SUCCESS) return 0;

  char lString[3];
  lString[2] = '\0';
  XQUERY_STREAM lStream = aAPI->init_stream(lXQuery, &lError); 
  if (lError != XQUERY_SUCCESS) return 0;

  while (aAPI->stream_next(lStream, lString, 2, &lError) > 0)
  {
    if (lError != XQUERY_SUCCESS) return 0;
    printf("%s", lString);
  }
  printf("\n");

  aAPI->release_stream(lStream);
  aAPI->release_query(lXQuery);

  return 1;
}

int
example_2(XQUERY_CAPI* aAPI) 
{
  XQUERY_ERROR lError = XQUERY_SUCCESS;
  XQUERY_ITEM lItem = aAPI->init_item();
  XQUERY_STRING lString = aAPI->init_string();

  XQUERY lXQuery = aAPI->compile("(1+2,3+4)", &lError);
  if (lError != XQUERY_SUCCESS) return 0;

  XQUERY_RESULT lResult = aAPI->init_iterator(lXQuery, &lError);
  if (lError != XQUERY_SUCCESS) return 0;

  while (aAPI->iterator_next(lResult, lItem, &lError))
  {
    if (lError != XQUERY_SUCCESS) return 0;

    aAPI->item_stringvalue(lItem, lString, &lError);
    if (lError != XQUERY_SUCCESS) return 0;

    printf("%s\n", aAPI->stringvalue_to_char(lString));
  }

  aAPI->close_iterator(lResult);
  aAPI->release_string(lString);
  aAPI->release_item(lItem);
  aAPI->release_query(lXQuery);

  return 1;
}

int
csimple(int argc, char** argv)
{
  int res = 0; 
  XQUERY_CAPI lAPI;
  zorba_create_capi(&lAPI);

  printf("executing C example 1\n");
  res = example_1(&lAPI);
  if (!res) return 1;
  printf("\n");

  printf("executing C example 2\n");
  res = example_2(&lAPI);
  if (!res) return 1;
  printf("\n");

  return 0;
}
