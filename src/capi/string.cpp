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

#include <cassert>

#include "capi/string.h"

#include <cassert>
#include <zorba/zorba.h>

using namespace zorba;

namespace zorbac {
 
  XQUERY_ERROR
  String::to_char(XQC_String str, const char** res)
  {
    try {
      zorba::String* lInnerString = static_cast<zorba::String*>(str->data);
      *res = lInnerString->c_str();
      return XQ_SUCCESS;
    } catch (ZorbaException &e) {
      return e.getErrorCode();
    } catch (...) {
      return XQP0019_INTERNAL_ERROR;
    }
  }
 
  void
  String::free(XQC_String str)
  {
    try {
      zorba::String* lInnerString = static_cast<zorba::String*>(str->data);
      delete lInnerString;
      delete str;
    } catch (ZorbaException &e) {
      assert(false); 
    } catch (...) {
      assert(false); 
    }
  }

  void
  String::assign_functions(XQC_String str)
  {
    str->to_char  = String::to_char;
    str->free     = String::free;
  }
}; /* namespace zorbac */
