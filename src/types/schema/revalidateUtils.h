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
#ifndef ZORBA_TYPES_SCHEMA_REVALIDATION
#define ZORBA_TYPES_SCHEMA_REVALIDATION

#include <set>

#include "common/shared_types.h"

namespace zorba
{

namespace store
{
class PUL;
}

class QueryLoc;
class static_context;


void validateAfterUpdate(
    const std::set<zorba::store::Item*>& nodes,
    store::PUL* pul,
    static_context* staticContext,
    const QueryLoc& loc);

}

#endif

