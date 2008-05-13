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

%module zorba_api
%include cpointer.i
%{
#include <zorba/zorbac.h>

typedef struct {
  XQUERY_API* theAPI;
  XQUERY theXQuery;
} XQuery_s;

typedef struct {
  XQUERY_API* theAPI;
  XQUERY_SEQUENCE theSequence;
} XQuerySequence_s;

typedef struct {
  XQUERY_API* theAPI;
  XQUERY_ITEM theItem;
} XQueryItem_s;

typedef struct {
  XQUERY_API* theAPI;
  XQUERY_STRING theString;
} XQueryString_s;

XQuery_s* query_compile(XQUERY_API* aAPI, const char* aChar, XQUERY_ERROR* aError)
{
  XQuery_s* l = new XQuery_s(); 
  l->theAPI = aAPI;
  l->theXQuery = aAPI->query_compile(aChar, aError);   
  return l;
}

void query_release(XQuery_s* aQuery)
{
  aQuery->theAPI->query_release(aQuery->theXQuery);
  delete aQuery;
}

XQuerySequence_s* sequence_init(XQuery_s* aQuery, XQUERY_ERROR* aError)
{
  XQuerySequence_s* l = new XQuerySequence_s(); 
  l->theAPI = aQuery->theAPI;
  l->theSequence = aQuery->theAPI->sequence_init(aQuery->theXQuery, aError);
  return l;
}

int sequence_next(XQuerySequence_s* aResult, XQueryItem_s* aItem, XQUERY_ERROR* aError)
{
  return aResult->theAPI->sequence_next(aResult->theSequence, aItem->theItem, aError);
}

void sequence_close(XQuerySequence_s* aResult)
{
  aResult->theAPI->sequence_close(aResult->theSequence);
  delete aResult;
}

XQueryItem_s* item_init(XQUERY_API* aAPI)
{
  XQueryItem_s* l = new XQueryItem_s(); 
  l->theAPI = aAPI;
  l->theItem = aAPI->item_init();
  return l;
}

void item_release(XQueryItem_s* aItem)
{
  aItem->theAPI->item_release(aItem->theItem);
  delete aItem;
}

void item_stringvalue(XQueryItem_s* aItem, XQueryString_s* aString, XQUERY_ERROR* aError)
{
  aItem->theAPI->item_stringvalue(aItem->theItem, aString->theString, aError);
}

XQueryString_s* string_init(XQUERY_API* aAPI)
{
  XQueryString_s* l = new XQueryString_s();
  l->theAPI = aAPI;
  l->theString = aAPI->string_init();
  return l;
}

void string_release(XQueryString_s* aString)
{
  aString->theAPI->string_release(aString->theString);
  delete aString;
}

const char* string_to_char(XQueryString_s* aString)
{
  return aString->theAPI->string_to_char(aString->theString);
}
%}

%pointer_functions(XQUERY_ERROR, errorp);
%pointer_functions(XQUERY_API, apip);

void zorba_init(XQUERY_API*);
void zorba_release();

%newobject query_compile;
XQuery_s* query_compile(XQUERY_API*, const char* aChar, XQUERY_ERROR* aError);
%delobject query_release;
void query_release(XQuery_s* aQuery);

%newobject sequence_init;
XQuerySequence_s* sequence_init(XQuery_s* aQuery, XQUERY_ERROR* aError);
int sequence_next(XQuerySequence_s* aResult, XQueryItem_s* aItem, XQUERY_ERROR* aError);
%delobject sequence_close;
void sequence_close(XQuerySequence_s* aResult);

%newobject item_init;
XQueryItem_s* item_init(XQUERY_API*);
%delobject item_release;
void item_release(XQueryItem_s* aItem);
void item_stringvalue(XQueryItem_s* aItem, XQueryString_s* aString, XQUERY_ERROR* aError);

%newobject string_init;
XQueryString_s* string_init(XQUERY_API*);
%delobject string_release;
void string_release(XQueryString_s* aString);
const char* string_to_char(XQueryString_s* aString);


