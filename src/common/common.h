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
#ifndef __COMMON_H__
#define __COMMON_H__
#include <cassert>
#include "zorbamisc/config/platform.h"

//use this macro to activate or deactivate use of sync code
#ifndef ZORBA_FOR_ONE_THREAD_ONLY
  #define SYNC_CODE(x)    x
  #define SYNC_PARAM2(x)  , x
#else
  #define SYNC_CODE(x)    
  #define SYNC_PARAM2(x)
#endif

#endif //__COMMON_H__
