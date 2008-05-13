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
#include <zorba/zorbac.h> 
#include <zorba/zorba.h>
#include "api/unmarshaller.h"
#include "store/api/item.h"

using namespace zorba;

template<typename T>
class SharedWrapper
{
public:
  boost::shared_ptr<T> theObject;

  SharedWrapper(boost::shared_ptr<T> a) : theObject(a) {}
};

XQUERY 
zorba_query_compile(const char* aChar, XQUERY_ERROR* aError)
{
  SharedWrapper<XQuery>* lQuery = 0;
  try {
    XQuery_t lQuerySmart = Zorba::getInstance()->compileQuery(aChar);
    lQuery = new SharedWrapper<XQuery>(lQuerySmart);
    return lQuery;
  } catch (ZorbaException& e) {
    *aError = e.getErrorCode(); 
  } catch (...) {
    *aError = XQP0019_INTERNAL_ERROR; 
  }
  return 0;
}

void 
zorba_query_release(XQUERY aQuery)
{
  SharedWrapper<XQuery>* lQuery = static_cast<SharedWrapper<XQuery>* >(aQuery);
  delete lQuery; 
}

void
zorba_query_execute(XQUERY aQuery, FILE* aFile, XQUERY_ERROR* aError)
{
  SharedWrapper<XQuery>* lQuery = static_cast<SharedWrapper<XQuery>* >(aQuery);
  std::stringstream lStream;
  char lBuf[1024];

  try {
    lStream << lQuery->theObject;
    lStream.seekg(0);

    int lRes = 0;
    while ( (lRes = lStream.readsome(lBuf, 1023)) > 0 ) {
      lBuf[lRes] = 0;
      fprintf (aFile, "%s", lBuf);
    }

    *aError = XQ_SUCCESS;
  } catch (ZorbaException& e) {
    *aError = e.getErrorCode();
  } catch (...) {
    *aError = XQP0019_INTERNAL_ERROR;
  }
}


XQUERY_STREAM 
zorba_stream_init(XQUERY aQuery, XQUERY_ERROR* aError)
{
  SharedWrapper<XQuery>* lQuery = static_cast<SharedWrapper<XQuery>* >(aQuery);
  std::stringstream* lStream = new std::stringstream();
  try {
    *lStream << lQuery->theObject;
    lStream->seekg(0);
    *aError = XQ_SUCCESS;
  } catch (ZorbaException& e) {
    *aError = e.getErrorCode();
  } catch (...) {
    *aError = XQP0019_INTERNAL_ERROR;
  }
  return lStream;
}

int 
zorba_stream_next(XQUERY_STREAM aStream, char* aChar, int aLen, XQUERY_ERROR* aError)
{
  std::stringstream* lStream = static_cast<std::stringstream*>(aStream);
  int lReturn = -1; 
  try {
    lReturn = lStream->readsome(aChar, aLen);
    *aError = XQ_SUCCESS;
  } catch (...) {
    *aError = XQP0019_INTERNAL_ERROR;
  }

  return lReturn;
}

void 
zorba_stream_release(XQUERY_STREAM aStream)
{
  std::stringstream* lStream = static_cast<std::stringstream*>(aStream);
  delete lStream;
}


XQUERY_SEQUENCE
zorba_sequence_init(XQUERY aQuery, XQUERY_ERROR* aError)
{
  SharedWrapper<ResultIterator>* lResult = 0;
  try {
    SharedWrapper<XQuery>* lQuery = static_cast<SharedWrapper<XQuery>* >(aQuery);
    ResultIterator_t lResultSmart = lQuery->theObject->iterator();
    lResultSmart->open();
    lResult = new SharedWrapper<ResultIterator>(lResultSmart);
    *aError = XQ_SUCCESS;
  } catch (ZorbaException& e) {
    *aError = e.getErrorCode();
  }
  return lResult;
}

int
zorba_sequence_next(XQUERY_SEQUENCE aResult, XQUERY_ITEM aItem, XQUERY_ERROR* aError)
{
  SharedWrapper<ResultIterator>* lResult = static_cast<SharedWrapper<ResultIterator>*>(aResult);
  Item* lItem = static_cast<Item*>(aItem);
  int lReturn = 0; 

  try {
    if (lResult->theObject->next(*lItem)) {
      lReturn = 1;
    }
    *aError = XQ_SUCCESS;
  } catch (ZorbaException& e) {
    *aError = e.getErrorCode();
  }

  return lReturn;
}

void 
zorba_sequence_close(XQUERY_SEQUENCE aResult)
{
  SharedWrapper<ResultIterator>* lResult = static_cast<SharedWrapper<ResultIterator>*>(aResult);
  delete lResult;
}

XQUERY_ITEM 
zorba_item_init()
{
  return new Item();
}


void 
zorba_item_release(XQUERY_ITEM aItem)
{
  Item* lItem = static_cast<Item*>(aItem);
  delete lItem;
}

XQUERY_STRING 
zorba_string_init()
{
  return new String("");
}

void 
zorba_item_stringvalue(XQUERY_ITEM aItem, XQUERY_STRING aString, XQUERY_ERROR* aError)
{
  String* lString = static_cast<String*>(aString);
  Item* lItem = static_cast<Item*>(aItem);

  try {
    *lString = Unmarshaller::getInternalString(lItem->getStringValue());
    *aError = XQ_SUCCESS;
  } catch (ZorbaException& e) {
    *aError = e.getErrorCode();
  }
}

void 
zorba_string_release(XQUERY_STRING aString)
{
  String* lString = static_cast<String*>(aString);
  delete lString;
}

const char* 
zorba_string_to_char(XQUERY_STRING aString)
{
  String* lString = static_cast<String*>(aString);
  return lString->c_str();
}

XQUERY_DYNAMIC_CONTEXT
zorba_dynamic_context(XQUERY aXQuery, XQUERY_ERROR* aError)
{
  SharedWrapper<XQuery>* lQuery = static_cast<SharedWrapper<XQuery>* >(aXQuery);
  XQUERY_DYNAMIC_CONTEXT lContext = 0;
  try {
    lContext = lQuery->theObject->getDynamicContext();
    *aError = XQ_SUCCESS;
  } catch (ZorbaException& e) {
    *aError = e.getErrorCode();
  } catch (...) {
    *aError = XQP0019_INTERNAL_ERROR;
  }
  return lContext;
}

void 
zorba_init(XQUERY_API* aAPI)
{
  Zorba::getInstance();

  // query functions
  aAPI->query_compile       = zorba_query_compile;
  aAPI->query_release       = zorba_query_release;
  aAPI->query_execute       = zorba_query_execute;

  // dynamic context
  aAPI->dynamic_context     = zorba_dynamic_context;

  // stream functions
  aAPI->stream_init         = zorba_stream_init;
  aAPI->stream_next         = zorba_stream_next;
  aAPI->stream_release      = zorba_stream_release;

  // sequence functions
  aAPI->sequence_init       = zorba_sequence_init;
  aAPI->sequence_close      = zorba_sequence_close;
  aAPI->sequence_next       = zorba_sequence_next;

  // item functions
  aAPI->item_init           = zorba_item_init;
  aAPI->item_release        = zorba_item_release;
  aAPI->item_stringvalue    = zorba_item_stringvalue;

  aAPI->string_init         = zorba_string_init;
  aAPI->string_release      = zorba_string_release;
  aAPI->string_to_char      = zorba_string_to_char;
}

void zorba_release()
{
  Zorba::getInstance()->shutdown();
}
