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

%{
#include "zend_exceptions.h"
%}
%include ../zorba_api.i
%{
#define SWIG_exception(code, msg) { mt_zend_throw_exception(0, msg, code TSRMLS_CC); }

ZEND_API zval * mt_zend_throw_exception(zend_class_entry *exception_ce, const char *message, long code TSRMLS_DC);

zval * mt_zend_throw_exception(zend_class_entry *exception_ce, const char *message, long code TSRMLS_DC)
{
  char *mt_message = (char *)malloc(sizeof(message));
  strcpy(mt_message, message);
  zval *retval = zend_throw_exception(exception_ce, mt_message, code);
  free(mt_message);
  return retval;
}
%}

