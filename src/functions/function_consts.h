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
#ifndef ZORBA_FUNCTIONS_FUNCTION_CONSTS
#define ZORBA_FUNCTIONS_FUNCTION_CONSTS

namespace zorba 
{


class FunctionConsts
{
public:

  typedef enum
  {
    FN_UNKNOWN,

    FN_CONCATENATE,
    FN_SUM,

    FN_ENCLOSED,

    FN_VAR_ASSIGN,

    FN_COLLECTION,

    FN_CREATE_INTERNAL_INDEX,
    FN_CREATE_INDEX,
    FN_DROP_INDEX,
    FN_REFRESH_INDEX,
    FN_INDEX_PROBE_POINT,
    FN_INDEX_PROBE_RANGE
  }
  FunctionKind;


  typedef enum 
  { 
    NO = 0,
    YES,
    PRESERVE
  }
  AnnotationValue;


  typedef enum
  {
    DoDistinct    = 1,   // Used by fn:zore-or-one and fn:exaclty-one 
    SkipCodeGen   = 2,

    hasFnNamespace = 4
  }
  AnnotationFlags;

};


}
#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
