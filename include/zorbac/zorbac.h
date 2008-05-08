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

#ifndef ZORBA_ZORBAC_API_H
#define ZORBA_ZORBAC_API_H

typedef void* XQUERY;
typedef void* XQUERY_STREAM;
typedef void* XQUERY_RESULT;
typedef void* XQUERY_ITEM;
typedef void* XQUERY_STRING;

typedef enum {
  XQUERY_SUCCESS = 0,
  XQUERY_FAILURE
} XQUERY_ERROR;


#ifdef __cplusplus
extern "C" {
#endif

typedef XQUERY        (*xquery_compile)(
                          const char*,
                          XQUERY_ERROR*
                      ); 
typedef void          (*xquery_release_query)(
                          XQUERY
                      );

typedef XQUERY_STREAM (*xquery_init_stream)(
                          XQUERY, 
                          XQUERY_ERROR*
                      );
typedef int           (*xquery_stream_next)(
                          XQUERY_STREAM, 
                          char*, 
                          int, 
                          XQUERY_ERROR*
                      );
typedef void          (*xquery_release_stream)(
                          XQUERY_STREAM
                      );

typedef XQUERY_RESULT (*xquery_init_iterator)(
                          XQUERY, 
                          XQUERY_ERROR*
                      );
typedef void          (*xquery_close_iterator)(
                          XQUERY_RESULT
                      );

typedef XQUERY_ITEM   (*xquery_init_item)();
typedef int           (*xquery_iterator_next)(
                          XQUERY_RESULT, 
                          XQUERY_ITEM, 
                          XQUERY_ERROR*
                      );
typedef void          (*xquery_release_item)(
                          XQUERY_ITEM
                      );

typedef XQUERY_STRING (*xquery_init_string)();
typedef void          (*xquery_item_stringvalue)(
                          XQUERY_ITEM, 
                          XQUERY_STRING, 
                          XQUERY_ERROR*
                      );
typedef void          (*xquery_release_string)(
                          XQUERY_STRING
                      );

typedef const char*   (*xquery_stringvalue_to_char)(
                          XQUERY_STRING
                      );

typedef struct {
  xquery_compile             compile;
  xquery_release_query       release_query;
  xquery_init_stream         init_stream;
  xquery_stream_next         stream_next;
  xquery_release_stream      release_stream;
  xquery_init_iterator       init_iterator;
  xquery_close_iterator      close_iterator;
  xquery_init_item           init_item;
  xquery_iterator_next       iterator_next;
  xquery_release_item        release_item;
  xquery_init_string         init_string;
  xquery_item_stringvalue    item_stringvalue;
  xquery_release_string      release_string;
  xquery_stringvalue_to_char stringvalue_to_char;
} XQUERY_CAPI;

void zorba_create_capi(XQUERY_CAPI*);



#ifdef __cplusplus
}
#endif

#endif
