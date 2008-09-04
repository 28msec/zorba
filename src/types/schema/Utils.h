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
#ifndef ZORBA_SCHEMA_UTILS_H_
#define ZORBA_SCHEMA_UTILS_H_

#include "xercesIncludes.h"
#include "types/schema/SchemaValidatorFilter.h"
#include "types/schema/StrX.h"
#include "types/schema/ValidationEventHandler.h"
#include "store/api/item.h"
#include "common/shared_types.h"
#include "types/root_typemanager.h"

namespace zorba
{

void validateAfterUpdate(
    const set<zorba::store::Item*>& nodes,
    zorba::store::Item_t& pul,
    static_context* staticContext, 
    const QueryLoc& loc);

} // namespace zorba

#endif /*ZORBA_SCHEMA_UTILS_H_*/

