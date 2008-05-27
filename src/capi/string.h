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
#ifndef ZORBAC_STRING_H
#define ZORBAC_STRING_H

#include <zorba/zorbac.h>

namespace zorbac {

  class String {
    public:
      static XQUERY_ERROR
      create(XQC_String_Ref str);

      static XQUERY_ERROR
      to_char(XQC_String str, const char** res);

      static void
      free(XQC_String str);

      static void
      assign_functions(XQC_String str);

  }; /* class String */

} /* namespace zorbac */

#endif

