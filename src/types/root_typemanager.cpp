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
#include "stdafx.h"

#include <assert.h>

#include <zorba/identtypes.h>
#include <zorba/typeident.h>

#include "zorbatypes/datetime.h"
#include "zorbatypes/duration.h"

#include "system/globalenv.h"

#include "types/root_typemanager.h"
#include "types/node_test.h"

#include "store/api/item_factory.h"
#include "store/api/store.h"



using namespace zorba;

//SERIALIZABLE_CLASS_VERSIONS(RootTypeManager)
//END_SERIALIZABLE_CLASS_VERSIONS(RootTypeManager)


#define N TypeConstants::NOT_CASTABLE
#define Y TypeConstants::CASTABLE
#define M TypeConstants::MAYBE_CASTABLE


const TypeConstants::castable_t RootTypeManager::ATOMIC_CAST_MATRIX[45][45] = 
{
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

const bool RootTypeManager::ATOMIC_SUBTYPE_MATRIX[45][45] = 
{
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


const bool RootTypeManager::QUANT_SUBTYPE_MATRIX[4][4] = 
{
  // 1  ?  *  +
  {  T, T, T, T }, // 1
  {  F, T, T, F }, // ?
  {  F, F, T, F }, // *
  {  F, F, T, T }, // +
};

#undef T
#undef F

#define Q( q ) TypeConstants::QUANT_##q


const TypeConstants::quantifier_t RootTypeManager::QUANT_UNION_MATRIX [4] [4] = 
{
  //  ONE          QUESTION     STAR     PLUS
  { Q(ONE),      Q(QUESTION), Q(STAR), Q(PLUS) }, // ONE
  { Q(QUESTION), Q(QUESTION), Q(STAR), Q(STAR) }, // QUESTION
  { Q(STAR),     Q(STAR),     Q(STAR), Q(STAR) }, // STAR
  { Q(PLUS),     Q(STAR),     Q(STAR), Q(PLUS) }, // PLUS
};


const TypeConstants::quantifier_t RootTypeManager::QUANT_INTERS_MATRIX [4] [4] = 
{
  //  ONE          QUESTION     STAR         PLUS
  { Q(ONE),      Q(ONE),      Q(ONE),      Q(ONE)  },  // ONE
  { Q(ONE),      Q(QUESTION), Q(QUESTION), Q(ONE)  },  // QUESTION
  { Q(ONE),      Q(QUESTION), Q(STAR),     Q(PLUS) },  // STAR
  { Q(ONE),      Q(ONE),      Q(PLUS),     Q(PLUS) }   // PLUS
};

#undef Q

//                                       1  ?  *  +
const int RootTypeManager::QUANT_MIN_CNT [4] = { 1, 0, 0, 1 };

const int RootTypeManager::QUANT_MAX_CNT [4] = { 1, 1, 2, 2 };


#define ATOMIC_QNAMETYPE_MAP_SIZE 150   //50
 

#ifdef ZORBA_WITH_JSON
const XQType* RootTypeManager::JSON_TYPES_MAP[4][4];
#endif


RootTypeManager::RootTypeManager()
  :
  TypeManagerImpl(NULL),
  m_atomic_qnametype_map(ATOMIC_QNAMETYPE_MAP_SIZE, false)
{
#define XS_URI "http://www.w3.org/2001/XMLSchema"
#define XS_PREFIX "xs"

#define ZXSE_URI "http://www.zorba-xquery.com/zorba/schema-extensions"
#define ZXSE_PREFIX "zxse"

#define XSQNDECL(var, local)  \
  GENV.getStore().getItemFactory()->createQName(var, XS_URI, XS_PREFIX, local)

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
  GENV.getStore().getItemFactory()->createQName(ZXSE_TUPLE_QNAME, ZXSE_URI, ZXSE_PREFIX, "tuple");

  store::Item* tempQN = NULL;
  TypeConstants::atomic_type_code_t tempCode;

#define ATOMIC_TYPE_DEFN(tname)                                                 \
  tname##_TYPE_ONE = new AtomicXQType(this,                                     \
                                      TypeConstants::XS_##tname,                \
                                      TypeConstants::QUANT_ONE,                 \
                                      true);                                    \
                                                                                \
  tname##_TYPE_QUESTION = new AtomicXQType(this,                                \
                                           TypeConstants::XS_##tname,           \
                                           TypeConstants::QUANT_QUESTION,       \
                                           true);                               \
                                                                                \
  tname##_TYPE_STAR = new AtomicXQType(this,                                    \
                                       TypeConstants::XS_##tname,               \
                                       TypeConstants::QUANT_STAR,               \
                                       true);                                   \
                                                                                \
  tname##_TYPE_PLUS = new AtomicXQType(this,                                    \
                                       TypeConstants::XS_##tname,               \
                                       TypeConstants::QUANT_PLUS,               \
                                       true);                                   \
                                                                                \
  m_atomic_typecode_qname_map[TypeConstants::XS_##tname] = XS_##tname##_QNAME;  \
                                                                                \
  tempQN = XS_##tname##_QNAME.getp();                                           \
  tempCode = TypeConstants::XS_##tname;                                         \
  m_atomic_qnametype_map.insert(tempQN, tempCode);                              \
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

  ANY_TYPE = new AnyXQType(this, true);

  ANY_SIMPLE_TYPE = new AnySimpleXQType(this, true);

  UNTYPED_TYPE = new UntypedXQType(this, true);

  EMPTY_TYPE = new EmptyXQType(this, true);

  NONE_TYPE = new NoneXQType(this, true);

  ITEM_TYPE_ONE = new ItemXQType(this, TypeConstants::QUANT_ONE, true);
  ITEM_TYPE_QUESTION = new ItemXQType(this, TypeConstants::QUANT_QUESTION, true);
  ITEM_TYPE_STAR = new ItemXQType(this, TypeConstants::QUANT_STAR, true);
  ITEM_TYPE_PLUS = new ItemXQType(this, TypeConstants::QUANT_PLUS, true);

  ANY_FUNCTION_TYPE_ONE = new AnyFunctionXQType(this, TypeConstants::QUANT_ONE, true);
  ANY_FUNCTION_TYPE_QUESTION = new AnyFunctionXQType(this, TypeConstants::QUANT_QUESTION, true);
  ANY_FUNCTION_TYPE_STAR = new AnyFunctionXQType(this, TypeConstants::QUANT_STAR, true);
  ANY_FUNCTION_TYPE_PLUS = new AnyFunctionXQType(this, TypeConstants::QUANT_PLUS, true);
  
  store::Item_t nullNodeName;

#define NODE_TYPE_DEFN(basename, nodeKind, contentType)                 \
  basename##_TYPE_ONE = new NodeXQType(this,                            \
                                       nodeKind,                        \
                                       nullNodeName,                    \
                                       contentType,                     \
                                       TypeConstants::QUANT_ONE,        \
                                       false,                           \
                                       false,                           \
                                       true);                           \
                                                                        \
  basename##_TYPE_QUESTION = new NodeXQType(this,                       \
                                            nodeKind,                   \
                                            nullNodeName,               \
                                            contentType,                \
                                            TypeConstants::QUANT_QUESTION, \
                                            false,                      \
                                            false,                      \
                                            true);                      \
                                                                        \
  basename##_TYPE_STAR = new NodeXQType(this,                           \
                                        nodeKind,                       \
                                        nullNodeName,                   \
                                        contentType,                    \
                                        TypeConstants::QUANT_STAR,      \
                                        false,                          \
                                        false,                          \
                                        true);                          \
                                                                        \
  basename##_TYPE_PLUS = new NodeXQType(this,                           \
                                        nodeKind,                       \
                                        nullNodeName,                   \
                                        contentType,                    \
                                        TypeConstants::QUANT_PLUS,      \
                                        false,                          \
                                        false,                          \
                                        true)

  NODE_TYPE_DEFN(ANY_NODE, store::StoreConsts::anyNode, ANY_TYPE);

  NODE_TYPE_DEFN(ANY_NODE_UNTYPED, store::StoreConsts::anyNode, UNTYPED_TYPE);

  NODE_TYPE_DEFN(DOCUMENT, store::StoreConsts::documentNode, ANY_TYPE);

  NODE_TYPE_DEFN(DOCUMENT_UNTYPED, store::StoreConsts::documentNode, UNTYPED_TYPE);

  NODE_TYPE_DEFN(ELEMENT, store::StoreConsts::elementNode, ANY_TYPE);

  NODE_TYPE_DEFN(ELEMENT_UNTYPED, store::StoreConsts::elementNode, UNTYPED_TYPE);

  NODE_TYPE_DEFN(ATTRIBUTE, store::StoreConsts::attributeNode, ANY_SIMPLE_TYPE);

  NODE_TYPE_DEFN(ATTRIBUTE_UNTYPED, store::StoreConsts::attributeNode, UNTYPED_ATOMIC_TYPE_ONE);

  NODE_TYPE_DEFN(TEXT, store::StoreConsts::textNode, UNTYPED_ATOMIC_TYPE_ONE);

  NODE_TYPE_DEFN(PI, store::StoreConsts::piNode, STRING_TYPE_ONE);

  NODE_TYPE_DEFN(COMMENT, store::StoreConsts::commentNode, STRING_TYPE_ONE);

#undef NODE_TYPE_DEFN

#ifdef ZORBA_WITH_JSON

#define JSON_TYPE_DEFN(basename, kind)                                      \
  basename##_TYPE_ONE = new JSONXQType(this,                                     \
                                  kind,                                     \
                                  TypeConstants::QUANT_ONE,                 \
                                  true);                                    \
                                                                            \
  basename##_TYPE_QUESTION = new JSONXQType(this,                                \
                                       kind,                                \
                                       TypeConstants::QUANT_QUESTION,       \
                                       true);                               \
                                                                            \
  basename##_TYPE_STAR = new JSONXQType(this,                                    \
                                   kind,                                    \
                                   TypeConstants::QUANT_STAR,               \
                                   true);                                   \
                                                                            \
  basename##_TYPE_PLUS = new JSONXQType(this,                                    \
                                   kind,                                    \
                                   TypeConstants::QUANT_PLUS,               \
                                   true);                                   \
                                                                            \
  JSON_TYPES_MAP[kind][TypeConstants::QUANT_ONE] = basename##_TYPE_ONE.getp();   \
  JSON_TYPES_MAP[kind][TypeConstants::QUANT_QUESTION] = basename##_TYPE_QUESTION.getp(); \
  JSON_TYPES_MAP[kind][TypeConstants::QUANT_PLUS] = basename##_TYPE_STAR.getp(); \
  JSON_TYPES_MAP[kind][TypeConstants::QUANT_STAR] = basename##_TYPE_STAR.getp();

  JSON_TYPE_DEFN(JSON_ITEM, store::StoreConsts::jsonItem);
  JSON_TYPE_DEFN(JSON_OBJECT, store::StoreConsts::jsonObject);
  JSON_TYPE_DEFN(JSON_ARRAY, store::StoreConsts::jsonArray);
  JSON_TYPE_DEFN(JSON_PAIR, store::StoreConsts::jsonPair);

#undef JSON_TYPE_DEFN
#endif // ZORBA_WITH_JSON
}


RootTypeManager::~RootTypeManager()
{

#define DELETE_TYPE(tname) \
  delete tname##_TYPE_ONE.getp();       \
  delete tname##_TYPE_QUESTION.getp();  \
  delete tname##_TYPE_STAR.getp();      \
  delete tname##_TYPE_PLUS.getp();      \
  tname##_TYPE_ONE.setNull();           \
  tname##_TYPE_QUESTION.setNull();      \
  tname##_TYPE_STAR.setNull();          \
  tname##_TYPE_PLUS.setNull();          \

  DELETE_TYPE(COMMENT)
  DELETE_TYPE(PI)
  DELETE_TYPE(TEXT)
  DELETE_TYPE(ATTRIBUTE_UNTYPED)
  DELETE_TYPE(ATTRIBUTE)
  DELETE_TYPE(ELEMENT_UNTYPED)
  DELETE_TYPE(ELEMENT)
  DELETE_TYPE(DOCUMENT_UNTYPED)
  DELETE_TYPE(DOCUMENT)
  DELETE_TYPE(ANY_NODE_UNTYPED)
  DELETE_TYPE(ANY_NODE)

  DELETE_TYPE(ITEM)

  DELETE_TYPE(NOTATION)
  DELETE_TYPE(QNAME)
  DELETE_TYPE(ANY_URI)
  DELETE_TYPE(HEXBINARY)
  DELETE_TYPE(BASE64BINARY)
  DELETE_TYPE(BOOLEAN)
  DELETE_TYPE(GMONTH)
  DELETE_TYPE(GDAY)
  DELETE_TYPE(GMONTH_DAY)
  DELETE_TYPE(GYEAR)
  DELETE_TYPE(GYEAR_MONTH)
  DELETE_TYPE(POSITIVE_INTEGER)
  DELETE_TYPE(UNSIGNED_BYTE)
  DELETE_TYPE(UNSIGNED_SHORT)
  DELETE_TYPE(UNSIGNED_INT)
  DELETE_TYPE(UNSIGNED_LONG)
  DELETE_TYPE(NON_NEGATIVE_INTEGER)
  DELETE_TYPE(BYTE)
  DELETE_TYPE(SHORT)
  DELETE_TYPE(INT)
  DELETE_TYPE(LONG)
  DELETE_TYPE(NEGATIVE_INTEGER)
  DELETE_TYPE(NON_POSITIVE_INTEGER)
  DELETE_TYPE(INTEGER)
  DELETE_TYPE(DECIMAL)
  DELETE_TYPE(DOUBLE)
  DELETE_TYPE(FLOAT)
  DELETE_TYPE(YM_DURATION)
  DELETE_TYPE(DT_DURATION)
  DELETE_TYPE(DURATION)
  DELETE_TYPE(TIME)
  DELETE_TYPE(DATE)
  DELETE_TYPE(DATETIME)
  DELETE_TYPE(UNTYPED_ATOMIC)
  DELETE_TYPE(ENTITY)
  DELETE_TYPE(IDREF)
  DELETE_TYPE(ID)
  DELETE_TYPE(NCNAME)
  DELETE_TYPE(NAME)
  DELETE_TYPE(NMTOKEN)
  DELETE_TYPE(LANGUAGE)
  DELETE_TYPE(TOKEN)
  DELETE_TYPE(NORMALIZED_STRING)
  DELETE_TYPE(STRING)
  DELETE_TYPE(ANY_ATOMIC)

#undef DELETE_TYPE

#ifdef ZORBA_WITH_JSON

#define DELETE_JSON_TYPE(tname)    \
  delete tname##_TYPE_ONE.getp();       \
  delete tname##_TYPE_QUESTION.getp();  \
  delete tname##_TYPE_STAR.getp();      \
  delete tname##_TYPE_PLUS.getp();      \
  tname##_TYPE_ONE.setNull();           \
  tname##_TYPE_QUESTION.setNull();      \
  tname##_TYPE_STAR.setNull();          \
  tname##_TYPE_PLUS.setNull();          \

  DELETE_JSON_TYPE(JSON_ITEM)
  DELETE_JSON_TYPE(JSON_OBJECT)
  DELETE_JSON_TYPE(JSON_ARRAY)
  DELETE_JSON_TYPE(JSON_PAIR)

#undef DELETE_JSON_TYPE
#endif // // ZORBA_WITH_JSON

  delete ANY_TYPE.getp();
  ANY_TYPE.setNull();

  delete ANY_SIMPLE_TYPE.getp();
  ANY_SIMPLE_TYPE.setNull();

  delete UNTYPED_TYPE.getp();
  UNTYPED_TYPE.setNull();

  delete EMPTY_TYPE.getp();
  EMPTY_TYPE.setNull();

  delete NONE_TYPE.getp();
  NONE_TYPE.setNull();

  delete ANY_FUNCTION_TYPE_ONE.getp();
  ANY_FUNCTION_TYPE_ONE.setNull();

  delete ANY_FUNCTION_TYPE_QUESTION.getp();
  ANY_FUNCTION_TYPE_QUESTION.setNull();

  delete ANY_FUNCTION_TYPE_PLUS.getp();
  ANY_FUNCTION_TYPE_PLUS.setNull();

  delete ANY_FUNCTION_TYPE_STAR.getp();
  ANY_FUNCTION_TYPE_STAR.setNull();
}
/* vim:set et sw=2 ts=2: */
