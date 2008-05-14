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

#include <zorba/error.h>

typedef void* XQUERY;
typedef void* XQUERY_STREAM;
typedef void* XQUERY_SEQUENCE;
typedef void* XQUERY_ITEM;
typedef void* XQUERY_STRING;
typedef void* XQUERY_DC;

typedef XQUERY*           XQUERY_REF;
typedef XQUERY_STREAM*    XQUERY_STREAM_REF;
typedef XQUERY_SEQUENCE*  XQUERY_SEQUENCE_REF;
typedef XQUERY_ITEM*      XQUERY_ITEM_REF;
typedef XQUERY_STRING*    XQUERY_STRING_REF;
typedef XQUERY_DC*        XQUERY_DC_REF;
typedef XQUERY_ERROR*     XQUERY_ERROR_REF;

#ifdef __cplusplus
extern "C" {
#endif

typedef XQUERY_ERROR  (*xquery_query_compile)(const char*, XQUERY_REF); 

typedef XQUERY_ERROR  (*xquery_query_compile_file)(FILE*, XQUERY_REF);

typedef XQUERY_ERROR  (*xquery_query_execute)(XQUERY, FILE*);

typedef void          (*xquery_query_release)(XQUERY);

// dynamic context is only valid as long as the XQUERY
typedef XQUERY_ERROR  (*xquery_dynamic_context)(XQUERY, XQUERY_DC_REF);

typedef XQUERY_ERROR  (*xquery_stream_init)(XQUERY, XQUERY_STREAM_REF);

// return -1 if XQUERY_ERROR is not XQ_SUCCESS
typedef int           (*xquery_stream_next)(XQUERY_STREAM stream, char* buffer, 
                                            int buffer_size, XQUERY_ERROR_REF);

typedef void          (*xquery_stream_release)(XQUERY_STREAM);

typedef XQUERY_ERROR  (*xquery_item_init)(XQUERY_ITEM_REF); 

typedef void          (*xquery_item_release)(XQUERY_ITEM);

typedef XQUERY_ERROR  (*xquery_item_stringvalue)(XQUERY_ITEM, XQUERY_STRING);

typedef XQUERY_ERROR  (*xquery_sequence_init)(XQUERY, XQUERY_SEQUENCE_REF);

typedef XQUERY_ERROR  (*xquery_sequence_next)(XQUERY_SEQUENCE, XQUERY_ITEM);

typedef void          (*xquery_sequence_release)(XQUERY_SEQUENCE);

typedef XQUERY_ERROR  (*xquery_string_init)(XQUERY_STRING_REF);

typedef void          (*xquery_string_release)(XQUERY_STRING);

// const char* is only valid as long as the XQUERY_STRING
typedef const char*   (*xquery_string_to_char)(XQUERY_STRING);

typedef struct {
  // functions related to queries
  xquery_query_compile       query_compile;
  xquery_query_compile_file  query_compile_file;
  xquery_query_release       query_release;
  xquery_query_execute       query_execute;

  // dynamic context
  xquery_dynamic_context     dynamic_context;
  
  // functions related to streams
  xquery_stream_init         stream_init;
  xquery_stream_next         stream_next;
  xquery_stream_release      stream_release;

  // function related to result iterators
  xquery_sequence_init       sequence_init;
  xquery_sequence_next       sequence_next;
  xquery_sequence_release    sequence_release;

  // item functions
  xquery_item_init           item_init;
  xquery_item_release        item_release;
  xquery_item_stringvalue    item_stringvalue;

  // string functions
  xquery_string_init         string_init;
  xquery_string_release      string_release;
  xquery_string_to_char      string_to_char;
} XQUERY_API;

XQUERY_API*
zorba_init();

void 
zorba_release(XQUERY_API*);



#ifdef __cplusplus
}
#endif

#endif
