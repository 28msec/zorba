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
#include "zorbatypes/xqpstring.h"
#include "util/rchandle.h"

using namespace zorba;

template<typename T>
class SharedWrapper
{
public:
  boost::shared_ptr<T> theObject;

  SharedWrapper(boost::shared_ptr<T> a) throw() : theObject(a) {}
};

XQUERY_ERROR 
zorba_query_compile(const char* aChar, XQUERY_REF aQuery)
{
  SharedWrapper<XQuery>* lQueryWrapper = 0;
  try {
    XQuery_t lQuerySmart = Zorba::getInstance()->compileQuery(aChar);
    lQueryWrapper        = new SharedWrapper<XQuery>(lQuerySmart);
    *aQuery = static_cast<XQUERY>(lQueryWrapper);

    return XQ_SUCCESS;
  } catch (ZorbaException& e) {
    return e.getErrorCode(); 
  } catch (...) {
    return XQP0019_INTERNAL_ERROR; 
  }
}

void 
zorba_query_release(XQUERY aQuery)
{
  SharedWrapper<XQuery>* lQueryWrapper = static_cast<SharedWrapper<XQuery>* >(aQuery);
  delete lQueryWrapper; 
}

XQUERY_ERROR
zorba_query_execute(XQUERY aQuery, FILE* aFile)
{
  SharedWrapper<XQuery>* lQuery = static_cast<SharedWrapper<XQuery>* >(aQuery);

  std::stringstream lStream;
  char lBuf[1024];

  try {
    // TODO this is eager at the moment, we need a pull serializer
    lStream << lQuery->theObject; 
    lStream.seekg(0);

    int lRes = 0;
    while ( (lRes = lStream.readsome(lBuf, 1023)) > 0 ) {
      lBuf[lRes] = 0;
      fprintf (aFile, "%s", lBuf);
    }
    return XQ_SUCCESS;
  } catch (ZorbaException& e) {
    return e.getErrorCode();
  } catch (...) {
    return XQP0019_INTERNAL_ERROR;
  }
}


XQUERY_ERROR 
zorba_stream_init(XQUERY aQuery, XQUERY_STREAM_REF aStream)
{
  SharedWrapper<XQuery>* lQuery = static_cast<SharedWrapper<XQuery>* >(aQuery);

  try {
    std::stringstream* lStream = new std::stringstream();
    *aStream = (XQUERY_STREAM) lStream;

    // TODO this is eager at the moment, we need a pull serializer
    *lStream << lQuery->theObject;
    lStream->seekg(0);

    return XQ_SUCCESS;
  } catch (ZorbaException& e) {
    return e.getErrorCode();
  } catch (...) {
    return XQP0019_INTERNAL_ERROR;
  }
}

int 
zorba_stream_next(XQUERY_STREAM aStream, char* aChar, int aLen, XQUERY_ERROR_REF aError)
{
  std::stringstream* lStream = static_cast<std::stringstream*>(aStream);

  int lReturn = -1; 
  try {
    lReturn = lStream->readsome(aChar, aLen);

    *aError = XQ_SUCCESS;

    return lReturn;
  } catch (ZorbaException& e) { // can't occur at the moment because init is eager
    *aError = e.getErrorCode();
  } catch (...) {
    *aError = XQP0019_INTERNAL_ERROR;
  }
  return -1;
}

void 
zorba_stream_release(XQUERY_STREAM aStream)
{
  std::stringstream* lStream = static_cast<std::stringstream*>(aStream);
  delete lStream;
}


XQUERY_ERROR
zorba_sequence_init(XQUERY aQuery, XQUERY_SEQUENCE_REF aSeq)
{
  SharedWrapper<XQuery>* lQuery = static_cast<SharedWrapper<XQuery>* >(aQuery);
  SharedWrapper<ResultIterator>* lSeq = 0;

  try {
    ResultIterator_t lResultSmart = lQuery->theObject->iterator();
    lResultSmart->open();
    lSeq = new SharedWrapper<ResultIterator>(lResultSmart);
    *aSeq = static_cast<XQUERY_SEQUENCE>(lSeq);

    return XQ_SUCCESS;
  } catch (ZorbaException& e) {
    return e.getErrorCode();
  } catch (...) {
    return XQP0019_INTERNAL_ERROR; 
  }
}

XQUERY_ERROR
zorba_sequence_next(XQUERY_SEQUENCE aResult, XQUERY_ITEM aItem)
{
  SharedWrapper<ResultIterator>* lResult = static_cast<SharedWrapper<ResultIterator>*>(aResult);
  Item* lItem = static_cast<Item*>(aItem);

  try {
    if (lResult->theObject->next(*lItem)) {
      return XQ_SUCCESS;
    }
    return API0025_END_OF_SEQUENCE;
  } catch (ZorbaException& e) {
    return e.getErrorCode();
  } catch (...) {
    return XQP0019_INTERNAL_ERROR;
  }
}

void 
zorba_sequence_release(XQUERY_SEQUENCE aResult)
{
  SharedWrapper<ResultIterator>* lResult = static_cast<SharedWrapper<ResultIterator>*>(aResult);
  delete lResult;
}

XQUERY_ERROR
zorba_item_init(XQUERY_ITEM_REF aItem)
{
  Item* lItem = 0;
  try {
    lItem = new Item();
    *aItem = static_cast<XQUERY_ITEM>(lItem);
    return XQ_SUCCESS;
  } catch (...) {
    delete lItem;
    return XQP0019_INTERNAL_ERROR;
  }
}


void 
zorba_item_release(XQUERY_ITEM aItem)
{
  Item* lItem = static_cast<Item*>(aItem);
  delete lItem;
}

XQUERY_ERROR
zorba_string_init(XQUERY_STRING_REF aString)
{
  String* lString = 0;
  try {
    // we create an empty wrapper here
    // this is a one time thing
    // later the actual string stores will be put
    // in that wrapper
    lString = new String("");
    *aString = static_cast<XQUERY_STRING>(lString);
    return XQ_SUCCESS;
  } catch (ZorbaException& e) {
    delete lString;
    return e.getErrorCode();
  } catch (...) {
    delete lString;
    return XQP0019_INTERNAL_ERROR;
  }
}

XQUERY_ERROR 
zorba_item_stringvalue(XQUERY_ITEM aItem, XQUERY_STRING aString)
{
  const Item* lItem = static_cast<const Item*>(aItem);

  try {
    String* lStringWrapper = static_cast<String*>(aString);
    // assign the String to the new one
    // the assignment operator does the correct handling
    // of transfering the stringstores and handling
    // the reference counts
    *lStringWrapper = lItem->getStringValue();
    return XQ_SUCCESS;
  } catch (ZorbaException& e) {
    return e.getErrorCode();
  } catch (...) {
    return XQP0019_INTERNAL_ERROR;
  }
}

void 
zorba_string_release(XQUERY_STRING aString)
{
  delete static_cast<String*>(aString);
}

const char* 
zorba_string_to_char(XQUERY_STRING aString)
{
  String* lString = static_cast<String*>(aString);
  return lString->c_str();
}

XQUERY_ERROR
zorba_dynamic_context(XQUERY aXQuery, XQUERY_DC_REF aContext)
{
  SharedWrapper<XQuery>* lQuery = static_cast<SharedWrapper<XQuery>* >(aXQuery);

  try {
    DynamicContext* lContext = lQuery->theObject->getDynamicContext();
    *aContext = static_cast<XQUERY_DC>(lContext);
    return XQ_SUCCESS;
  } catch (ZorbaException& e) {
    return e.getErrorCode();
  } catch (...) {
    return XQP0019_INTERNAL_ERROR;
  }
}

XQUERY_API* 
zorba_init()
{
  XQUERY_API* lAPI = new XQUERY_API();

  // init zorba
  Zorba::getInstance();

  // query functions
  lAPI->query_compile       = zorba_query_compile;
  lAPI->query_release       = zorba_query_release;
  lAPI->query_execute       = zorba_query_execute;

  // dynamic context
  lAPI->dynamic_context     = zorba_dynamic_context;

  // stream functions
  lAPI->stream_init         = zorba_stream_init;
  lAPI->stream_next         = zorba_stream_next;
  lAPI->stream_release      = zorba_stream_release;

  // sequence functions
  lAPI->sequence_init       = zorba_sequence_init;
  lAPI->sequence_release    = zorba_sequence_release;
  lAPI->sequence_next       = zorba_sequence_next;

  // item functions
  lAPI->item_init           = zorba_item_init;
  lAPI->item_release        = zorba_item_release;
  lAPI->item_stringvalue    = zorba_item_stringvalue;

  lAPI->string_init         = zorba_string_init;
  lAPI->string_release      = zorba_string_release;
  lAPI->string_to_char      = zorba_string_to_char;

  return lAPI;
}

void 
zorba_release(XQUERY_API* aAPI)
{
  Zorba::getInstance()->shutdown();
  delete aAPI;
}
