/*
 * Copyright 2006-2013 The FLWOR Foundation.
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

#ifndef ZORBA_SPECIALIZATIONS_H
#define ZORBA_SPECIALIZATIONS_H

#include "store/api/item.h"
#include "util/hash/hash.h"

namespace zorba {
namespace ztd {

///////////////////////////////////////////////////////////////////////////////

/** Specialization for <code>store::Item*</code>. */
template<> inline
size_t hash<store::Item*>::operator()( store::Item *item ) const {
  return item->hash();
}

/** Specialization for <code>store::Item const*</code>. */
template<> inline
size_t hash<store::Item const*>::operator()( store::Item const *item ) const {
  return item->hash();
}

///////////////////////////////////////////////////////////////////////////////

} // namespace ztd
} // namespace zorba

#endif /* ZORBA_SPECIALIZATIONS_H */
/* vim:set et sw=2 ts=2: */
