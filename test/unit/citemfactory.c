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
#include <string.h>
#include <stdlib.h>
#include <zorba/zorbac.h>

#define UNIT_ASSERT(x) \
  do { \
    if (! (x)) { \
      printf("%s %i\n", "assertion in line", __LINE__); \
      exit(1); \
    } \
  } while (0)

int 
citemfactory(int argc, char* argv[])
{
  XQC_Implementation impl = 0;
  XQC_ItemFactory    lFactory = 0;
  XQC_Item           lItem = 0;
  XQC_String         lString = 0;
  XQC_String         lURI = 0;
  XQC_String         lPrefix = 0;
  XQC_String         lTmpString = 0;
  int                lTmpInt = 0;
  const char*        lStringValue = 0;


  if ( zorba_implementation(&impl) != XQ_SUCCESS )
      return 1;

  impl->item_factory(impl, &lFactory);

  impl->create_string(impl, "1", &lString);
  impl->create_string(impl, "http://www.zorba-xquery.com/", &lURI);
  impl->create_string(impl, "zorba", &lPrefix);
  impl->create_string(impl, 0, &lTmpString);

  /* String */
  UNIT_ASSERT ( lFactory->create_string(lFactory, lString, &lItem) == XQ_SUCCESS );
  lItem->string_value(lItem, lString);
  lString->to_char(lString, &lStringValue);
  UNIT_ASSERT ( strcmp(lStringValue, "1") == 0 );
  lItem->free(lItem);

  /* AnyURI */
  UNIT_ASSERT ( lFactory->create_anyuri(lFactory, lURI, &lItem) == XQ_SUCCESS );
  lItem->string_value(lItem, lTmpString);
  lTmpString->to_char(lTmpString, &lStringValue);
  UNIT_ASSERT ( strcmp(lStringValue, "http://www.zorba-xquery.com/") == 0 );
  lItem->free(lItem);

  /* QName */
  UNIT_ASSERT ( lFactory->create_qname2(lFactory, lURI, lString, &lItem) == XQ_SUCCESS );
  lItem->string_value(lItem, lTmpString);
  lTmpString->to_char(lTmpString, &lStringValue);
  UNIT_ASSERT ( strcmp(lStringValue, "1") == 0 );
  lItem->ns(lItem, lTmpString);
  lTmpString->to_char(lTmpString, &lStringValue);
  UNIT_ASSERT ( strcmp(lStringValue, "http://www.zorba-xquery.com/") == 0 );
  lItem->localname(lItem, lTmpString);
  lTmpString->to_char(lTmpString, &lStringValue);
  UNIT_ASSERT ( strcmp(lStringValue, "1") == 0 );
  lItem->free(lItem);
  
  UNIT_ASSERT ( lFactory->create_qname3(lFactory, lURI, lPrefix, lString, &lItem) == XQ_SUCCESS );
  lItem->string_value(lItem, lTmpString);
  lTmpString->to_char(lTmpString, &lStringValue);
  UNIT_ASSERT ( strcmp(lStringValue, "zorba:1") == 0 );
  lItem->ns(lItem, lTmpString);
  lTmpString->to_char(lTmpString, &lStringValue);
  UNIT_ASSERT ( strcmp(lStringValue, "http://www.zorba-xquery.com/") == 0 );
  lItem->localname(lItem, lTmpString);
  lTmpString->to_char(lTmpString, &lStringValue);
  UNIT_ASSERT ( strcmp(lStringValue, "1") == 0 );
  lItem->prefix(lItem, lTmpString);
  lTmpString->to_char(lTmpString, &lStringValue);
  UNIT_ASSERT ( strcmp(lStringValue, "zorba") == 0 );
  lItem->free(lItem);

  /* Boolean */
  UNIT_ASSERT ( lFactory->create_boolean(lFactory, 1, &lItem) == XQ_SUCCESS );
  lItem->string_value(lItem, lTmpString);
  lTmpString->to_char(lTmpString, &lStringValue);
  UNIT_ASSERT ( strcmp(lStringValue, "true") == 0 );
  lItem->boolean_value(lItem, &lTmpInt);
  UNIT_ASSERT ( lTmpInt  == 1 );
  UNIT_ASSERT (lItem->nan(lItem, &lTmpInt) == XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE );
  UNIT_ASSERT (lItem->ns(lItem, lTmpString) == XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE );
  UNIT_ASSERT (lItem->localname(lItem, lTmpString) == XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE );
  UNIT_ASSERT (lItem->prefix(lItem, lTmpString) == XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE );
  lItem->free(lItem);

  UNIT_ASSERT ( lFactory->create_boolean(lFactory, 0, &lItem) == XQ_SUCCESS );
  lItem->string_value(lItem, lTmpString);
  lTmpString->to_char(lTmpString, &lStringValue);
  UNIT_ASSERT ( strcmp(lStringValue, "false") == 0 );
  lItem->boolean_value(lItem, &lTmpInt);
  UNIT_ASSERT ( lTmpInt  == 0 );
  lItem->free(lItem);

  lPrefix->free(lPrefix);
  lURI->free(lURI);
  lString->free(lString);
  lString->free(lTmpString);

  lFactory->free(lFactory);
    
  impl->free(impl);

  return 0;
}
