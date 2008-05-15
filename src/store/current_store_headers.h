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
#ifndef ZORBA_STORE_HEADERS_FOR_CURRENT_STORE
#define ZORBA_STORE_HEADERS_FOR_CURRENT_STORE

#include "common/common.h"

#if defined (ZORBA_MINIMAL_STORE)
#include "store/minimal/min_store.h"
#elif defined (ZORBA_XBROWSER)
// TODO
#else
#include "store/naive/simple_store.h"
#endif


#endif
