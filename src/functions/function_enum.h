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
  FN_NODE_NAME_1,
  FN_NILLED_1,
  FN_STRING_1,
  FN_DATA_1,
  FN_BASE_URI_1,
  FN_DOCUMENT_URI_1,
  FN_ROOT_1,
  OP_IS_SAME_NODE_2,
  OP_NODE_BEFORE_2,
  OP_NODE_AFTER_2,
  FN_CURRENT_DATETIME_0,
  FN_CURRENT_DATE_0,
  FN_CURRENT_TIME_0,
  FN_IMPLICIT_TIMEZONE_0,
  FN_DEFAULT_COLLATION_0,
  ZORBA_JSON_PARSE_1,
  ZORBA_JSON_SERIALIZE_1,
  ZORBA_JSON_ML_PARSE_1,
  ZORBA_JSON_ML_SERIALIZE_1,
  FN_YEARS_FROM_DURATION_1,
  FN_MONTHS_FROM_DURATION_1,
  FN_DAYS_FROM_DURATION_1,
  FN_HOURS_FROM_DURATION_1,
  FN_MINUTES_FROM_DURATION_1,
  FN_SECONDS_FROM_DURATION_1,
  FN_YEAR_FROM_DATETIME_1,
  FN_MONTH_FROM_DATETIME_1,
  FN_DAY_FROM_DATETIME_1,
  FN_HOURS_FROM_DATETIME_1,
  FN_MINUTES_FROM_DATETIME_1,
  FN_SECONDS_FROM_DATETIME_1,
  FN_TIMEZONE_FROM_DATETIME_1,
  FN_YEAR_FROM_DATE_1,
  FN_MONTH_FROM_DATE_1,
  FN_DAY_FROM_DATE_1,
  FN_TIMEZONE_FROM_DATE_1,
  FN_HOURS_FROM_TIME_1,
  FN_MINUTES_FROM_TIME_1,
  FN_SECONDS_FROM_TIME_1,
  FN_TIMEZONE_FROM_TIME_1,
  FN_PUT_2,
  FN_TRACE_2,
  OP_ZORBA_READ_LINE_0,
  OP_ZORBA_PRINT_1,
  FN_RESOLVE_URI_2,
  FN_ERROR_0,
  FN_ERROR_1,
  FN_ERROR_2,
  FN_ERROR_3,
  FN_ZORBA_REF_NODE_REFERENCE_1,
  FN_ZORBA_REF_NODE_BY_REFERENCE_1,
  FN_LOCAL_NAME_1,
  FN_NAMESPACE_URI_1,
  FN_LANG_2,
  OP_CONCATENATE_N,
  FN_INDEX_OF_2,
  FN_INDEX_OF_3,
  FN_EMPTY_1,
  FN_EXISTS_1,
  FN_INSERT_BEFORE_3,
  FN_REMOVE_2,
  FN_REVERSE_1,
  FN_SUBSEQUENCE_2,
  FN_SUBSEQUENCE_3,
  FN_ZERO_OR_ONE_1,
  FN_ONE_OR_MORE_1,
  FN_DEEP_EQUAL_2,
  FN_DEEP_EQUAL_3,
  FN_COUNT_1,
  FN_AVG_1,
  FN_SUM_1,
  FN_SUM_2,
  FN_SUM_DOUBLE_1,
  FN_SUM_DOUBLE_2,
  FN_SUM_FLOAT_1,
  FN_SUM_FLOAT_2,
  FN_SUM_DECIMAL_1,
  FN_SUM_DECIMAL_2,
  FN_SUM_INTEGER_1,
  FN_SUM_INTEGER_2,
  OP_TO_2,
  FN_DOC_1,
  FN_DOC_AVAILABLE_1,
  FN_ZORBA_UTIL_PARSE_1,
  FN_CODEPOINTS_TO_STRING_1,
  FN_STRING_TO_CODEPOINTS_1,
  FN_COMPARE_2,
  FN_COMPARE_3,
  FN_CODEPOINT_EQUAL_2,
  FN_CONCAT_N,
  FN_STRING_JOIN_2,
  FN_SUBSTRING_2,
  FN_SUBSTRING_3,
  FN_STRING_LENGTH_1,
  FN_NORMALIZE_SPACE_1,
  FN_NORMALIZE_UNICODE_1,
  FN_NORMALIZE_UNICODE_2,
  FN_UPPER_CASE_1,
  FN_LOWER_CASE_1,
  FN_TRANSLATE_3,
  FN_ENCODE_FOR_URI_1,
  FN_IRI_TO_URI_1,
  FN_ESCAPE_HTML_URI_1,
  FN_CONTAINS_2,
  FN_CONTAINS_3,
  FN_STARTS_WITH_2,
  FN_STARTS_WITH_3,
  FN_ENDS_WITH_2,
  FN_ENDS_WITH_3,
  FN_SUBSTRING_BEFORE_2,
  FN_SUBSTRING_BEFORE_3,
  FN_SUBSTRING_AFTER_2,
  FN_SUBSTRING_AFTER_3,
  FN_MATCHES_2,
  FN_MATCHES_3,
  FN_REPLACE_3,
  FN_REPLACE_4,
  FN_TOKENIZE_2,
  FN_TOKENIZE_3,
  FN_MAX_FUNC
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
