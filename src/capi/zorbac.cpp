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

#include <zorba/zorba.h>
#include <zorba/zorbac.h> 

#include "capi/implementation.h"
#if 0
#include "capi/dynamic_context.h"
#include "capi/static_context.h"
#include "capi/string.h"
#include "capi/item.h"
#include "capi/item_factory.h"
#include "capi/sequence.h"
#endif




#if 0

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

XQUERY_ERROR 
zorba_query_compile_file(FILE* aFile, XQUERY_REF aQuery)
{
  SharedWrapper<XQuery>* lQueryWrapper = 0;
  try {
    std::stringstream lStream;
    char lBuf[1024];
    size_t lSize;

    while ((lSize = fread(lBuf, 1, 1024, aFile)) > 0) {
        lStream.write(lBuf, lSize);
    }

    XQuery_t lQuerySmart = Zorba::getInstance()->compileQuery(lStream);
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
  SharedWrapper<ResultIterator>* lResult = 
    static_cast<SharedWrapper<ResultIterator>*>(aResult);
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
  SharedWrapper<ResultIterator>* lResult = 
    static_cast<SharedWrapper<ResultIterator>*>(aResult);
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
  Item* lItem = static_cast<Item*>(aItem);

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

XQUERY_ERROR
zorba_dc_set_context_item(XQUERY_DC aCtx, XQUERY_ITEM aItem)
{
  DynamicContext* lContext = static_cast<DynamicContext*>(aCtx); 
  Item* lItem = static_cast<Item*>(aItem);
  
  try {
    lContext->setContextItem(*lItem);
    return XQ_SUCCESS;
  } catch (ZorbaException &e) {
    return e.getErrorCode();
  } catch (...) {
    return XQP0019_INTERNAL_ERROR;
  }

}

XQUERY_ERROR
zorba_string_create(const char* aString, XQUERY_STRING_REF aRes)
{
  String* lString = 0;
  try {
    lString = new String(aString);
    *aRes = static_cast<XQUERY_STRING>(lString);
    return XQ_SUCCESS;
  } catch (ZorbaException &e) {
    delete lString;
    return e.getErrorCode();
  } catch (...) {
    delete lString;
    return XQP0019_INTERNAL_ERROR;
  }
}

XQUERY_ERROR
zorba_item_create_string(XQUERY_STRING aString, XQUERY_ITEM_REF aItem);

XQUERY_ERROR
zorba_item_create_anyuri(XQUERY_STRING, XQUERY_ITEM_REF);

XQUERY_ERROR
zorba_item_create_qname2(XQUERY_STRING, XQUERY_STRING, XQUERY_ITEM_REF);

XQUERY_ERROR
zorba_item_create_qname3(XQUERY_STRING, XQUERY_STRING, XQUERY_STRING, XQUERY_ITEM_REF);

XQUERY_ERROR
zorba_item_create_boolean(int, XQUERY_ITEM_REF);
#endif

XQUERY_ERROR
zorba_implementation(XQC_Implementation_Ref impl)
{
  *impl = 0;
  try {
    // init zorba
    zorba::Zorba* lZorba = zorba::Zorba::getInstance();

    *impl = new XQC_Implementation_s();

    (*impl)->data =  lZorba;
    (*impl)->create_context = zorbac::Implementation::create_context;
    (*impl)->compile        = zorbac::Implementation::compile;
    (*impl)->compile_file   = zorbac::Implementation::compile_file;
    (*impl)->free           = zorbac::Implementation::free;
    (*impl)->create_item    = zorbac::Implementation::create_item;
    (*impl)->create_string  = zorbac::Implementation::create_string;
    (*impl)->item_factory   = zorbac::Implementation::item_factory;
    return XQ_SUCCESS;
  } catch (zorba::ZorbaException &e) {
    return e.getErrorCode();
  } catch (...) {
    delete *impl;
    return XQP0019_INTERNAL_ERROR;
  }
}

