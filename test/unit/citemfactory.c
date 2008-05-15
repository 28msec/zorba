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
#include <assert.h>
#include <stdlib.h>
#include <zorba/zorbac.h>

#define UNIT_ASSERT(x) \
  do { \
    if (! (x)) { \
      printf("%s", "assertion in file __FILE__ in line __LINE__"); \
      exit(1); \
    } \
  } while (0)

int 
citemfactory(int argc, char* argv[])
{
  XQUERY_API*   lAPI = zorba_init();
  XQUERY_ITEM   lItem;
  XQUERY_STRING lString;
  XQUERY_STRING lURI;
  XQUERY_STRING lPrefix;

  // create some types
  UNIT_ASSERT ( lAPI->string_create("1", &lString) == XQ_SUCCESS );
  UNIT_ASSERT ( lAPI->string_create("http://www.zorba-xquery.com/", &lURI) == XQ_SUCCESS );
  UNIT_ASSERT ( lAPI->string_create("1", &lString) == XQ_SUCCESS );
  UNIT_ASSERT ( lAPI->string_create("zorba", &lPrefix) == XQ_SUCCESS );

  /* String */
  UNIT_ASSERT ( lAPI->item_create_string(lString, &lItem) == XQ_SUCCESS );
  lAPI->item_release(lItem);

  /* AnyURI */
  UNIT_ASSERT ( lAPI->item_create_anyuri(lString, &lItem) == XQ_SUCCESS );
  lAPI->item_release(lItem);

  /* QName */
  UNIT_ASSERT ( lAPI->item_create_qname2(lURI, lString, &lItem) == XQ_SUCCESS );
  lAPI->item_release(lItem);
  
  UNIT_ASSERT ( lAPI->item_create_qname3(lURI, lString, lPrefix, &lItem) == XQ_SUCCESS );
  lAPI->item_release(lItem);

  /* Boolean */
  UNIT_ASSERT ( lAPI->item_create_boolean(1, &lItem) == XQ_SUCCESS );
  lAPI->item_release(lItem);


  lAPI->string_release(lPrefix);
  lAPI->string_release(lURI);
  lAPI->string_release(lString);

  zorba_release(lAPI);

  return 0;
}
