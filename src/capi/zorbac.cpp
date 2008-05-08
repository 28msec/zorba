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

#include <sstream>
#include <zorba/api_shared_types.h>
#include <zorbac/zorbac.h> 
#include <zorba/zorba.h>
#include "api/unmarshaller.h"
#include "store/api/item.h"

using namespace zorba;

template<typename T>
class SharedWrapper
{
public:
  boost::shared_ptr<T> the;

  SharedWrapper(boost::shared_ptr<T> a) : the(a) {}
};

XQUERY zorba_compile(const char* aChar, XQUERY_ERROR* aError)
{
  SharedWrapper<XQuery>* lQuery = 0;
  try {
    XQuery_t lQuerySmart = Zorba::getInstance()->compileQuery(aChar);
    lQuery = new SharedWrapper<XQuery>(lQuerySmart);
    *aError = XQUERY_SUCCESS;
  } catch (...) {
    *aError = XQUERY_FAILURE; 
  }
  return lQuery;
}

void zorba_release_query(XQUERY aQuery)
{
  SharedWrapper<XQuery>* lQuery = static_cast<SharedWrapper<XQuery>* >(aQuery);
  delete lQuery; 
}

XQUERY_STREAM zorba_init_stream(XQUERY aQuery, XQUERY_ERROR* aError)
{
  SharedWrapper<XQuery>* lQuery = static_cast<SharedWrapper<XQuery>* >(aQuery);
  std::stringstream* lStream = new std::stringstream();
  try {
    *lStream << lQuery->the;
    *aError = XQUERY_SUCCESS;
  } catch (...) {
    *aError = XQUERY_FAILURE;
  }
  return lStream;
}

int zorba_stream_next(XQUERY_STREAM aStream, char* aChar, int aLen, XQUERY_ERROR* aError)
{
  std::stringstream* lStream = static_cast<std::stringstream*>(aStream);
  int lReturn = -1; 
  try {
    lReturn = lStream->readsome(aChar, aLen);
    *aError = XQUERY_SUCCESS;
  } catch (...) {
    *aError = XQUERY_FAILURE;
  }

  return lReturn;
}

void zorba_release_stream(XQUERY_STREAM aStream)
{
  std::stringstream* lStream = static_cast<std::stringstream*>(aStream);
  delete lStream;
}


XQUERY_RESULT zorba_init_iterator(XQUERY aQuery, XQUERY_ERROR* aError)
{
  SharedWrapper<ResultIterator>* lResult = 0;
  try {
    SharedWrapper<XQuery>* lQuery = static_cast<SharedWrapper<XQuery>* >(aQuery);
    ResultIterator_t lResultSmart = lQuery->the->iterator();
    lResultSmart->open();
    lResult = new SharedWrapper<ResultIterator>(lResultSmart);
    *aError = XQUERY_SUCCESS;
  } catch (...) {
    *aError = XQUERY_FAILURE;
  }
  return lResult;
}

void zorba_close_iterator(XQUERY_RESULT aResult)
{
  SharedWrapper<ResultIterator>* lResult = static_cast<SharedWrapper<ResultIterator>*>(aResult);
  delete lResult;
}

XQUERY_ITEM zorba_init_item()
{
  return new Item();
}

int zorba_iterator_next(XQUERY_RESULT aResult, XQUERY_ITEM aItem, XQUERY_ERROR* aError)
{
  SharedWrapper<ResultIterator>* lResult = static_cast<SharedWrapper<ResultIterator>*>(aResult);
  Item* lItem = static_cast<Item*>(aItem);
  int lReturn = 0; 

  try {
    if (lResult->the->next(*lItem)) {
      lReturn = 1;
    }
    *aError = XQUERY_SUCCESS;
  } catch (...) {
    *aError = XQUERY_FAILURE;
  }

  return lReturn;
}

void zorba_release_item(XQUERY_ITEM aItem)
{
  Item* lItem = static_cast<Item*>(aItem);
  delete lItem;
}

XQUERY_STRING zorba_init_string()
{
  return new String("");
}

void zorba_item_stringvalue(XQUERY_ITEM aItem, XQUERY_STRING aString, XQUERY_ERROR* aError)
{
  String* lString = static_cast<String*>(aString);
  Item* lItem = static_cast<Item*>(aItem);

  try {
    *lString = Unmarshaller::getInternalString(lItem->getStringValue());
    *aError = XQUERY_SUCCESS;
  } catch (...) {
    *aError = XQUERY_FAILURE;
  }
}

void zorba_release_string(XQUERY_STRING aString)
{
  String* lString = static_cast<String*>(aString);
  delete lString;
}

const char* zorba_stringvalue_to_char(XQUERY_STRING aString)
{
  String* lString = static_cast<String*>(aString);
  return lString->c_str();
}

void zorba_create_capi(XQUERY_CAPI* aAPI)
{
  aAPI->compile             = zorba_compile;
  aAPI->release_query       = zorba_release_query;
  aAPI->init_stream         = zorba_init_stream;
  aAPI->stream_next         = zorba_stream_next;
  aAPI->release_stream      = zorba_release_stream;
  aAPI->init_iterator       = zorba_init_iterator;
  aAPI->close_iterator      = zorba_close_iterator;
  aAPI->init_item           = zorba_init_item;
  aAPI->iterator_next       = zorba_iterator_next;
  aAPI->release_item        = zorba_release_item;
  aAPI->init_string         = zorba_init_string;
  aAPI->item_stringvalue    = zorba_item_stringvalue;
  aAPI->release_string      = zorba_release_string;
  aAPI->stringvalue_to_char = zorba_stringvalue_to_char;
}
