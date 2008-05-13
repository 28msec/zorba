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
typedef void* XQUERY_DYNAMIC_CONTEXT;

#ifdef __cplusplus
extern "C" {
#endif

/**
 * query related functions
 */
typedef XQUERY        (*xquery_query_compile)(const char*, XQUERY_ERROR*); 

typedef void          (*xquery_query_release)(XQUERY);

typedef void          (*xquery_query_execute)(XQUERY, FILE*, XQUERY_ERROR*);

/**
 * dynamic context related functions
 */
typedef XQUERY_DYNAMIC_CONTEXT (*xquery_dynamic_context)(XQUERY, XQUERY_ERROR*);

#if 0
typedef void                   (*xquery_dc_setvar(XQUERY_DYNAMIC_CONTEXT, 
                                                  XQUERY_VAR_TYPE,
                                                  XQUERY_STRING,
                                                  void*));
#endif

/**
 * stream related functions
 */
typedef XQUERY_STREAM (*xquery_stream_init)(XQUERY, XQUERY_ERROR*);

typedef int           (*xquery_stream_next)(XQUERY_STREAM, char*, int, XQUERY_ERROR*);

typedef void          (*xquery_stream_release)(XQUERY_STREAM);

/** 
 * iterator related functions
 */
typedef XQUERY_SEQUENCE (*xquery_sequence_init) (XQUERY, XQUERY_ERROR*);
typedef int             (*xquery_sequence_next) (XQUERY_SEQUENCE, XQUERY_ITEM, XQUERY_ERROR*);
typedef void            (*xquery_sequence_close)(XQUERY_SEQUENCE);

/**
 * item related functions
 */
typedef XQUERY_ITEM   (*xquery_item_init)(); 
typedef void          (*xquery_item_release)(XQUERY_ITEM);
typedef void          (*xquery_item_stringvalue)(XQUERY_ITEM, XQUERY_STRING, XQUERY_ERROR*);

/**
 * string related functions
 */
typedef XQUERY_STRING (*xquery_string_init)();
typedef void          (*xquery_string_release)(XQUERY_STRING);
typedef const char*   (*xquery_string_to_char)(XQUERY_STRING);

typedef struct {
  // functions related to queries
  xquery_query_compile       query_compile;
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
  xquery_sequence_close      sequence_close;

  // item functions
  xquery_item_init           item_init;
  xquery_item_release        item_release;
  xquery_item_stringvalue    item_stringvalue;

  // string functions
  xquery_string_init         string_init;
  xquery_string_release      string_release;
  xquery_string_to_char      string_to_char;
} XQUERY_API;

void
zorba_init(XQUERY_API*);

void 
zorba_release();



#ifdef __cplusplus
}
#endif

#endif
