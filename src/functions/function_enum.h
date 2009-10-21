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
 
// ******************************************
// *                                        *
// * THIS IS A GENERATED FILE. DO NOT EDIT! *
// * SEE .xml FILE WITH SAME NAME           *
// *                                        *
// ******************************************
#ifndef ZORBA_ZORBA_FUNCTIONS_FUNCTION_CONSTS_H
#define ZORBA_ZORBA_FUNCTIONS_FUNCTION_CONSTS_H
namespace zorba{
  
class FunctionConsts
{
  
public:
typedef enum {
  FN_UNKNOWN,
#include "functions/function_consts.h"
  FN_CONCATENATE,
  FN_INDEX_OF,
  FN_EMPTY,
  FN_EXISTS,
  FN_INSERT_BEFORE,
  FN_REMOVE,
  FN_REVERSE,
  FN_SUBSEQUENCE,
  FN_ZERO_OR_ONE,
  FN_ONE_OR_MORE,
  FN_DEEP_EQUAL,
  FN_COUNT,
  FN_AVG,
  FN_SUM,
  FN_SUM_DOUBLE,
  FN_SUM_FLOAT,
  FN_SUM_DECIMAL,
  FN_SUM_INTEGER,
  FN_TO,
  FN_DOC,
  FN_DOC_AVAILABLE,
  FN_ZORBA_UTIL_PARSE,
  FN_IS_SAME_NODE,
  FN_NODE_BEFORE,
  FN_NODE_AFTER,
  FN_NODE_NAME,
  FN_NILLED,
  FN_BASE_URI,
  FN_DOCUMENT_URI,
  FN_ROOT,
  FN_CODEPOINTS_TO_STRING,
  FN_COMPARE,
  FN_CODEPOINT_EQUAL,
  FN_CONCAT,
  FN_STRING_JOIN,
  FN_SUBSTRING,
  FN_STRING_LENGTH,
  FN_NORMALIZE_SPACE,
  FN_NORMALIZE_UNICODE,
  FN_UPPER_CASE,
  FN_LOWER_CASE,
  FN_TRANSLATE,
  FN_ENCODE_FOR_URI,
  FN_IRI_TO_URI,
  FN_ESCAPE_HTML_URI,
  FN_CONTAINS,
  FN_STARTS_WITH,
  FN_ENDS_WITH,
  FN_SUBSTRING_BEFORE,
  FN_SUBSTRING_AFTER,
  FN_MATCHES,
  FN_REPLACE,
  FN_CURRENT_DATETIME,
  FN_CURRENT_DATE,
  FN_CURRENT_TIME,
  FN_IMPLICIT_TIMEZONE,
  FN_DEFAULT_COLLATION
} FunctionKind;


typedef enum 
{ 
  NO = 0,
  YES,
  PRESERVE
} AnnotationValue;


typedef enum
{
  DoDistinct    = 1,   // Used by fn:zore-or-one and fn:exaclty-one 
  SkipCodeGen   = 2,
  hasFnNamespace = 4
} AnnotationFlags;
};
} //namespace zorba
#endif 
