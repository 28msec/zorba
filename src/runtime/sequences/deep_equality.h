/*
 * Copyright 2006-2014 The FLWOR Foundation.
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
#ifndef ZORBA_DEEP_EQUALITY_H
#define ZORBA_DEEP_EQUALITY_H

#include "common/shared_types.h"
#include "store/api/iterator.h"

namespace zorba
{

namespace equality
{

bool deepEqual(
    const QueryLoc& loc,
    static_context* sctx,
    store::Item_t& item1,
    store::Item_t& item2,
    XQPCollator* collator,
    int timezone,
    bool raiseError);

bool deepEqualChildren(
    const QueryLoc& loc,
    static_context* sctx,
    const store::Iterator_t& it1,
    const store::Iterator_t& it2,
    XQPCollator* collator,
    int timezone,
    bool raiseError);

bool deepEqualAttributes(
    const QueryLoc& loc,
    static_context* sctx,
    const store::Iterator_t& it1,
    const store::Iterator_t& it2,
    XQPCollator* collator,
    int timezone,
    bool raiseError);

bool deepEqualNodes(
    const QueryLoc& loc,
    static_context* sctx,
    const store::Item* item1,
    const store::Item* item2,
    XQPCollator* collator,
    int timezone,
    bool raiseError);

bool deepEqualObjects(
    const QueryLoc& loc,
    static_context* sctx,
    const store::Item* item1,
    const store::Item* item2,
    XQPCollator* collator,
    int timezone,
    bool raiseError);

bool deepEqualArrays(
    const QueryLoc& loc,
    static_context* sctx,
    const store::Item* item1,
    const store::Item* item2,
    XQPCollator* collator,
    int timezone,
    bool raiseError);

uint32_t deHash(
    const QueryLoc& loc,
    static_context* sctx,
    const store::Item* item,
    XQPCollator* collator,
    int timezone);

uint32_t deHashChildren(
    const QueryLoc& loc,
    static_context* sctx,
    const store::Iterator_t& it,
    XQPCollator* collator,
    int timezone);

uint32_t deHashAttributes(
    const QueryLoc& loc,
    static_context* sctx,
    const store::Iterator_t& it,
    XQPCollator* collator,
    int timezone);

uint32_t deHashNode(
    const QueryLoc& loc,
    static_context* sctx,
    const store::Item* item,
    XQPCollator* collator,
    int timezone);

uint32_t deHashObject(
    const QueryLoc& loc,
    static_context* sctx,
    const store::Item* item,
    XQPCollator* collator,
    int timezone);

uint32_t deHashArray(
    const QueryLoc& loc,
    static_context* sctx,
    const store::Item* item,
    XQPCollator* collator,
    int timezone);

}
}
#endif
