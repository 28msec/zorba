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
#include <assert.h>

#include <zorba/identtypes.h>
#include <zorba/typeident.h>
#include "zorbatypes/xqpstring.h"
#include "system/globalenv.h"
#include "types/node_test.h"
#include "types/typeops.h"
#include "store/api/item_factory.h"
#include "store/api/store.h"
#include "types/root_typemanager.h"
#include "zorbatypes/datetime.h"
#include "zorbatypes/duration.h"


using namespace zorba;

#define N TypeConstants::NOT_CASTABLE
#define Y TypeConstants::CASTABLE
#define M TypeConstants::MAYBE_CASTABLE


const TypeConstants::castable_t RootTypeManager::ATOMIC_CAST_MATRIX[45][45] = {
  {Y, Y, M, M, M, M, M, M, M, M, M, Y, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M}, /* anyAtomicType */
  {Y, Y, M, M, M, M, M, M, M, M, M, Y, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M}, /* string */
  {Y, Y, Y, M, M, M, M, M, M, M, M, Y, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M}, /* normalizedString */
  {Y, Y, Y, Y, M, M, M, M, M, M, M, Y, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M}, /* token */
  {Y, Y, Y, Y, Y, M, M, M, M, M, M, Y, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M}, /* language */
  {Y, Y, Y, Y, M, Y, M, M, M, M, M, Y, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M}, /* NMTOKEM */
  {Y, Y, Y, Y, M, M, Y, M, M, M, M, Y, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M}, /* Name */
  {Y, Y, Y, Y, M, M, Y, Y, M, M, M, Y, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M}, /* NCMame */
  {Y, Y, Y, Y, M, M, Y, Y, Y, M, M, Y, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M}, /* ID */
  {Y, Y, Y, Y, M, M, Y, Y, M, Y, M, Y, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M}, /* IDREF */
  {Y, Y, Y, Y, M, M, Y, Y, M, M, Y, Y, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M}, /* EMTITY */
  {Y, Y, M, M, M, M, M, M, M, M, M, Y, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, N, N}, /* untypedAtomic */
  {Y, Y, M, M, M, M, M, M, M, M, M, Y, Y, Y, Y, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, Y, Y, Y, Y, Y, N, N, N, N, N, N}, /* dateTime */
  {Y, Y, M, M, M, M, M, M, M, M, M, Y, Y, Y, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, Y, Y, Y, Y, Y, N, N, N, N, N, N}, /* date */
  {Y, Y, M, M, M, M, M, M, M, M, M, Y, N, N, Y, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N}, /* time */
  {Y, Y, M, M, M, M, M, M, M, M, M, Y, N, N, N, Y, Y, Y, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N}, /* duration */
  {Y, Y, M, M, M, M, M, M, M, M, M, Y, N, N, N, Y, Y, Y, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N}, /* yearMonthDuration */
  {Y, Y, M, M, M, M, M, M, M, M, M, Y, N, N, N, Y, Y, Y, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N}, /* dayTimeDuration */
  {Y, Y, M, M, M, M, M, M, M, M, M, Y, N, N, N, N, N, N, Y, Y, M, M, M, M, M, M, M, M, M, M, M, M, M, M, N, N, N, N, N, Y, N, N, N, N, N}, /* float */
  {Y, Y, M, M, M, M, M, M, M, M, M, Y, N, N, N, N, N, N, Y, Y, M, M, M, M, M, M, M, M, M, M, M, M, M, M, N, N, N, N, N, Y, N, N, N, N, N}, /* double */
  {Y, Y, M, M, M, M, M, M, M, M, M, Y, N, N, N, N, N, N, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, N, N, N, N, N, Y, N, N, N, N, N}, /* decimal */
  {Y, Y, M, M, M, M, M, M, M, M, M, Y, N, N, N, N, N, N, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, N, N, N, N, N, Y, N, N, N, N, N}, /* integer */
  {Y, Y, M, M, M, M, M, M, M, M, M, Y, N, N, N, N, N, N, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, N, N, N, N, N, Y, N, N, N, N, N}, /* nonPositiveInteger */
  {Y, Y, M, M, M, M, M, M, M, M, M, Y, N, N, N, N, N, N, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, N, N, N, N, N, Y, N, N, N, N, N}, /* negativeInteger */
  {Y, Y, M, M, M, M, M, M, M, M, M, Y, N, N, N, N, N, N, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, N, N, N, N, N, Y, N, N, N, N, N}, /* long */
  {Y, Y, M, M, M, M, M, M, M, M, M, Y, N, N, N, N, N, N, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, N, N, N, N, N, Y, N, N, N, N, N}, /* int */
  {Y, Y, M, M, M, M, M, M, M, M, M, Y, N, N, N, N, N, N, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, N, N, N, N, N, Y, N, N, N, N, N}, /* short */
  {Y, Y, M, M, M, M, M, M, M, M, M, Y, N, N, N, N, N, N, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, N, N, N, N, N, Y, N, N, N, N, N}, /* byte */
  {Y, Y, M, M, M, M, M, M, M, M, M, Y, N, N, N, N, N, N, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, N, N, N, N, N, Y, N, N, N, N, N}, /* nonNegativeInteger */
  {Y, Y, M, M, M, M, M, M, M, M, M, Y, N, N, N, N, N, N, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, N, N, N, N, N, Y, N, N, N, N, N}, /* unsignedLong */
  {Y, Y, M, M, M, M, M, M, M, M, M, Y, N, N, N, N, N, N, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, N, N, N, N, N, Y, N, N, N, N, N}, /* unsignedInt */
  {Y, Y, M, M, M, M, M, M, M, M, M, Y, N, N, N, N, N, N, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, N, N, N, N, N, Y, N, N, N, N, N}, /* unsignedShort */
  {Y, Y, M, M, M, M, M, M, M, M, M, Y, N, N, N, N, N, N, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, N, N, N, N, N, Y, N, N, N, N, N}, /* unsignedByte */
  {Y, Y, M, M, M, M, M, M, M, M, M, Y, N, N, N, N, N, N, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, N, N, N, N, N, Y, N, N, N, N, N}, /* positiveInteger */
  {Y, Y, M, M, M, M, M, M, M, M, M, Y, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, Y, N, N, N, N, N, N, N, N, N, N}, /* gYearMonth */
  {Y, Y, M, M, M, M, M, M, M, M, M, Y, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, Y, N, N, N, N, N, N, N, N, N}, /* gYear */
  {Y, Y, M, M, M, M, M, M, M, M, M, Y, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, Y, N, N, N, N, N, N, N, N}, /* gMonthDay */
  {Y, Y, M, M, M, M, M, M, M, M, M, Y, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, Y, N, N, N, N, N, N, N}, /* gDay */
  {Y, Y, M, M, M, M, M, M, M, M, M, Y, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, Y, N, N, N, N, N, N}, /* gMonth */
  {Y, Y, M, M, M, M, M, M, M, M, M, Y, N, N, N, N, N, N, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, Y, N, N, N, N, N, Y, N, N, N, N, N}, /* boolean */
  {Y, Y, M, M, M, M, M, M, M, M, M, Y, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, Y, Y, N, N, N}, /* base64Binary */
  {Y, Y, M, M, M, M, M, M, M, M, M, Y, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, Y, Y, N, N, N}, /* hexBinary */
  {Y, Y, M, M, M, M, M, M, M, M, M, Y, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, Y, N, N}, /* anyURI */
  {Y, Y, M, M, M, M, M, M, M, M, M, Y, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, Y, N}, /* QName */
  {Y, Y, M, M, M, M, M, M, M, M, M, Y, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, M}, /* NOTATION */
};

#undef MAYBE_CASTABLE
#undef CASTABLE
#undef NOT_CASTABLE

#define T true
#define F false

const bool RootTypeManager::ATOMIC_SUBTYPE_MATRIX[45][45] = {
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* anyAtomicType */
  {T, T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* string */
  {T, T, T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* normalizedString */
  {T, T, T, T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* token */
  {T, T, T, T, T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* language */
  {T, T, T, T, F, T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* NMTOKEN */
  {T, T, T, T, F, F, T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* Name */
  {T, T, T, T, F, F, T, T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* NCName */
  {T, T, T, T, F, F, T, T, T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* ID */
  {T, T, T, T, F, F, T, T, F, T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* IDREF */
  {T, T, T, T, F, F, T, T, F, F, T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* ENTITY */
  {T, F, F, F, F, F, F, F, F, F, F, T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* untypedAtomic */
  {T, F, F, F, F, F, F, F, F, F, F, F, T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* dateTime */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* date */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* time */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* duration */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, T, T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* yearMonthDuration */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, T, F, T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* dayTimeDuration */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* float */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* double */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* decimal */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, T, T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* integer */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, T, T, T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* nonPositiveInteger */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, T, T, T, T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* negativeInteger */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, T, T, F, F, T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* long */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, T, T, F, F, T, T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* int */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, T, T, F, F, T, T, T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* short */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, T, T, F, F, T, T, T, T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* byte */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, T, T, F, F, F, F, F, F, T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* nonNegativeInteger */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, T, T, F, F, F, F, F, F, T, T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* unsignedLong */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, T, T, F, F, F, F, F, F, T, T, T, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* unsignedInt */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, T, T, F, F, F, F, F, F, T, T, T, T, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* unsignedShort */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, T, T, F, F, F, F, F, F, T, T, T, T, T, F, F, F, F, F, F, F, F, F, F, F, F}, /* unsignedByte */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, T, T, F, F, F, F, F, F, T, F, F, F, F, T, F, F, F, F, F, F, F, F, F, F, F}, /* positiveInteger */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, T, F, F, F, F, F, F, F, F, F, F}, /* gYearMonth */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, T, F, F, F, F, F, F, F, F, F}, /* gYear */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, T, F, F, F, F, F, F, F, F}, /* gMonthDay */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, T, F, F, F, F, F, F, F}, /* gDay */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, T, F, F, F, F, F, F}, /* gMonth */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, T, F, F, F, F, F}, /* boolean */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, T, F, F, F, F}, /* base64Binary */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, T, F, F, F}, /* hexBinary */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, T, F, F}, /* anyURI */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, T, F}, /* QName */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, T}, /* NOTATION */
};

const bool RootTypeManager::QUANT_SUBTYPE_MATRIX[4][4] = {
  {T, T, T, T}, /* QUANT_ONE */
  {F, T, T, F}, /* QUANT_QUESTION */
  {F, F, T, F}, /* QUANT_STAR */
  {F, F, T, T}, /* QUANT_PLUS */
};

#undef T
#undef F

#define Q( q ) TypeConstants::QUANT_##q

const TypeConstants::quantifier_t RootTypeManager::QUANT_MULT_MATRIX [4] [4] = {
  //  ONE          QUESTION     STAR     PLUS
  { Q(ONE),      Q(QUESTION), Q(STAR), Q(PLUS) }, // ONE
  { Q(QUESTION), Q(QUESTION), Q(STAR), Q(STAR) }, // QUESTION
  { Q(STAR),     Q(STAR),     Q(STAR), Q(STAR) }, // STAR
  { Q(PLUS),     Q(STAR),     Q(STAR), Q(PLUS) }, // PLUS
};

const TypeConstants::quantifier_t RootTypeManager::QUANT_INTERS_MATRIX [4] [4] = {
  //  ONE          QUESTION     STAR         PLUS
  { Q(ONE),      Q(ONE),      Q(ONE),      Q(ONE)  },  // ONE
  { Q(ONE),      Q(QUESTION), Q(QUESTION), Q(ONE)  },  // QUESTION
  { Q(ONE),      Q(QUESTION), Q(STAR),     Q(PLUS) },  // STAR
  { Q(ONE),      Q(ONE),      Q(PLUS),     Q(PLUS) }   // PLUS
};

#undef Q
  
RootTypeManager::RootTypeManager()
  : TypeManagerImpl(0, NULL)
{
#define XS_URI "http://www.w3.org/2001/XMLSchema"
#define XS_PREFIX "xs"

#define XSQNDECL(var, local)                         \
        var =                    \
            GENV.getStore().getItemFactory()->   \
            createQName(XS_URI, XS_PREFIX, local)

  XSQNDECL(XS_ANY_ATOMIC_QNAME, "anyAtomicType");
  XSQNDECL(XS_STRING_QNAME, "string");
  XSQNDECL(XS_NORMALIZED_STRING_QNAME, "normalizedString");
  XSQNDECL(XS_TOKEN_QNAME, "token");
  XSQNDECL(XS_LANGUAGE_QNAME, "language");
  XSQNDECL(XS_NMTOKEN_QNAME, "NMTOKEN");
  XSQNDECL(XS_NAME_QNAME, "Name");
  XSQNDECL(XS_NCNAME_QNAME, "NCName");
  XSQNDECL(XS_ID_QNAME, "ID");
  XSQNDECL(XS_IDREF_QNAME, "IDREF");
  XSQNDECL(XS_ENTITY_QNAME, "ENTITY");
  XSQNDECL(XS_UNTYPED_ATOMIC_QNAME, "untypedAtomic");
  XSQNDECL(XS_DATETIME_QNAME, "dateTime");
  XSQNDECL(XS_DATE_QNAME, "date");
  XSQNDECL(XS_TIME_QNAME, "time");
  XSQNDECL(XS_DURATION_QNAME, "duration");
  XSQNDECL(XS_DT_DURATION_QNAME, "dayTimeDuration");
  XSQNDECL(XS_YM_DURATION_QNAME, "yearMonthDuration");
  XSQNDECL(XS_FLOAT_QNAME, "float");
  XSQNDECL(XS_DOUBLE_QNAME, "double");
  XSQNDECL(XS_DECIMAL_QNAME, "decimal");
  XSQNDECL(XS_INTEGER_QNAME, "integer");
  XSQNDECL(XS_NON_POSITIVE_INTEGER_QNAME, "nonPositiveInteger");
  XSQNDECL(XS_NEGATIVE_INTEGER_QNAME, "negativeInteger");
  XSQNDECL(XS_LONG_QNAME, "long");
  XSQNDECL(XS_INT_QNAME, "int");
  XSQNDECL(XS_SHORT_QNAME, "short");
  XSQNDECL(XS_BYTE_QNAME, "byte");
  XSQNDECL(XS_NON_NEGATIVE_INTEGER_QNAME, "nonNegativeInteger");
  XSQNDECL(XS_UNSIGNED_LONG_QNAME, "unsignedLong");
  XSQNDECL(XS_UNSIGNED_INT_QNAME, "unsignedInt");
  XSQNDECL(XS_UNSIGNED_SHORT_QNAME, "unsignedShort");
  XSQNDECL(XS_UNSIGNED_BYTE_QNAME, "unsignedByte");
  XSQNDECL(XS_POSITIVE_INTEGER_QNAME, "positiveInteger");
  XSQNDECL(XS_GYEAR_MONTH_QNAME, "gYearMonth");
  XSQNDECL(XS_GYEAR_QNAME, "gYear");
  XSQNDECL(XS_GMONTH_DAY_QNAME, "gMonthDay");
  XSQNDECL(XS_GDAY_QNAME, "gDay");
  XSQNDECL(XS_GMONTH_QNAME, "gMonth");
  XSQNDECL(XS_BOOLEAN_QNAME, "boolean");
  XSQNDECL(XS_BASE64BINARY_QNAME, "base64Binary");
  XSQNDECL(XS_HEXBINARY_QNAME, "hexBinary");
  XSQNDECL(XS_ANY_URI_QNAME, "anyURI");
  XSQNDECL(XS_QNAME_QNAME, "QName");
  XSQNDECL(XS_NOTATION_QNAME, "NOTATION");
  XSQNDECL(XS_ANY_TYPE_QNAME, "anyType");
  XSQNDECL(XS_ANY_SIMPLE_TYPE_QNAME, "anySimpleType");
  XSQNDECL(XS_UNTYPED_QNAME, "untyped");

#define ATOMIC_TYPE_DEFN(tname)                                                 \
  tname##_TYPE_ONE = new AtomicXQType(this,                                     \
                                      TypeConstants::XS_##tname,                \
                                      TypeConstants::QUANT_ONE);                \
                                                                                \
  tname##_TYPE_QUESTION = new AtomicXQType(this,                                \
                                          TypeConstants::XS_##tname,            \
                                          TypeConstants::QUANT_QUESTION);       \
                                                                                \
  tname##_TYPE_STAR = new AtomicXQType(this,                                    \
                                       TypeConstants::XS_##tname,               \
                                       TypeConstants::QUANT_STAR);              \
                                                                                \
  tname##_TYPE_PLUS = new AtomicXQType(this,                                    \
                                       TypeConstants::XS_##tname,               \
                                       TypeConstants::QUANT_PLUS);              \
                                                                                \
  m_atomic_typecode_qname_map[TypeConstants::XS_##tname] = XS_##tname##_QNAME;  \
                                                                                \
  m_atomic_qnametype_map[XS_##tname##_QNAME] = TypeConstants::XS_##tname;       \
                                                                                \
  m_atomic_typecode_map[TypeConstants::XS_##tname][TypeConstants::QUANT_ONE] =  \
    &tname##_TYPE_ONE;                                                          \
                                                                                \
  m_atomic_typecode_map[TypeConstants::XS_##tname][TypeConstants::QUANT_QUESTION] = \
    &tname##_TYPE_QUESTION;                                                     \
                                                                                \
  m_atomic_typecode_map[TypeConstants::XS_##tname][TypeConstants::QUANT_STAR] = \
    &tname##_TYPE_STAR;                                                         \
                                                                                \
  m_atomic_typecode_map[TypeConstants::XS_##tname][TypeConstants::QUANT_PLUS] = \
    &tname##_TYPE_PLUS;

  ATOMIC_TYPE_DEFN(ANY_ATOMIC)
  ATOMIC_TYPE_DEFN(STRING)
  ATOMIC_TYPE_DEFN(NORMALIZED_STRING)
  ATOMIC_TYPE_DEFN(TOKEN)
  ATOMIC_TYPE_DEFN(LANGUAGE)
  ATOMIC_TYPE_DEFN(NMTOKEN)
  ATOMIC_TYPE_DEFN(NAME)
  ATOMIC_TYPE_DEFN(NCNAME)
  ATOMIC_TYPE_DEFN(ID)
  ATOMIC_TYPE_DEFN(IDREF)
  ATOMIC_TYPE_DEFN(ENTITY)
  ATOMIC_TYPE_DEFN(UNTYPED_ATOMIC)
  ATOMIC_TYPE_DEFN(DATETIME)
  ATOMIC_TYPE_DEFN(DATE)
  ATOMIC_TYPE_DEFN(TIME)
  ATOMIC_TYPE_DEFN(DURATION)
  ATOMIC_TYPE_DEFN(DT_DURATION)
  ATOMIC_TYPE_DEFN(YM_DURATION)
  ATOMIC_TYPE_DEFN(FLOAT)
  ATOMIC_TYPE_DEFN(DOUBLE)
  ATOMIC_TYPE_DEFN(DECIMAL)
  ATOMIC_TYPE_DEFN(INTEGER)
  ATOMIC_TYPE_DEFN(NON_POSITIVE_INTEGER)
  ATOMIC_TYPE_DEFN(NEGATIVE_INTEGER)
  ATOMIC_TYPE_DEFN(LONG)
  ATOMIC_TYPE_DEFN(INT)
  ATOMIC_TYPE_DEFN(SHORT)
  ATOMIC_TYPE_DEFN(BYTE)
  ATOMIC_TYPE_DEFN(NON_NEGATIVE_INTEGER)
  ATOMIC_TYPE_DEFN(UNSIGNED_LONG)
  ATOMIC_TYPE_DEFN(UNSIGNED_INT)
  ATOMIC_TYPE_DEFN(UNSIGNED_SHORT)
  ATOMIC_TYPE_DEFN(UNSIGNED_BYTE)
  ATOMIC_TYPE_DEFN(POSITIVE_INTEGER)
  ATOMIC_TYPE_DEFN(GYEAR_MONTH)
  ATOMIC_TYPE_DEFN(GYEAR)
  ATOMIC_TYPE_DEFN(GMONTH_DAY)
  ATOMIC_TYPE_DEFN(GDAY)
  ATOMIC_TYPE_DEFN(GMONTH)
  ATOMIC_TYPE_DEFN(BOOLEAN)
  ATOMIC_TYPE_DEFN(BASE64BINARY)
  ATOMIC_TYPE_DEFN(HEXBINARY)
  ATOMIC_TYPE_DEFN(ANY_URI)
  ATOMIC_TYPE_DEFN(QNAME)
  ATOMIC_TYPE_DEFN(NOTATION)
#undef ATOMIC_TYPE_DEFN

  ANY_TYPE = new AnyXQType(this);

  ANY_SIMPLE_TYPE = new AnySimpleXQType(this);

  UNTYPED_TYPE = new UntypedXQType(this);

  EMPTY_TYPE = new EmptyXQType(this);

  NONE_TYPE = new NoneXQType(this);

  ITEM_TYPE_ONE = new ItemXQType(this, TypeConstants::QUANT_ONE);
  ITEM_TYPE_QUESTION = new ItemXQType(this, TypeConstants::QUANT_QUESTION);
  ITEM_TYPE_STAR = new ItemXQType(this, TypeConstants::QUANT_STAR);
  ITEM_TYPE_PLUS = new ItemXQType(this, TypeConstants::QUANT_PLUS);

#define NODE_TYPE_DEFN(basename) \
  basename##_TYPE_ONE = new NodeXQType(this, NodeTest::basename##_TEST, EMPTY_TYPE, TypeConstants::QUANT_ONE); \
  basename##_TYPE_QUESTION = new NodeXQType(this, NodeTest::basename##_TEST, EMPTY_TYPE, TypeConstants::QUANT_QUESTION); \
  basename##_TYPE_STAR = new NodeXQType(this, NodeTest::basename##_TEST, EMPTY_TYPE, TypeConstants::QUANT_STAR); \
  basename##_TYPE_PLUS = new NodeXQType(this, NodeTest::basename##_TEST, EMPTY_TYPE, TypeConstants::QUANT_PLUS);

  NODE_TYPE_DEFN(ANY_NODE)
  NODE_TYPE_DEFN(DOCUMENT)
  NODE_TYPE_DEFN(ELEMENT)
  NODE_TYPE_DEFN(ATTRIBUTE)
  NODE_TYPE_DEFN(TEXT)
  NODE_TYPE_DEFN(PI)
  NODE_TYPE_DEFN(COMMENT)

#undef NODE_TYPE_DEFN
}

RootTypeManager::~RootTypeManager()
{
}

/* vim:set ts=2 sw=2: */
