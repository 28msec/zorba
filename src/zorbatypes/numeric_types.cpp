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

// local
#include "decimal.h"
#include "float.h"
#include "integer.h"

using namespace std;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

template<class NumericType>
NumericType const& numeric_consts<NumericType>::zero() {
  static NumericType const n(0);
  return n;
}

template<class NumericType>
NumericType const& numeric_consts<NumericType>::one() {
  static NumericType const n(1);
  return n;
}

template<class NumericType>
NumericType const& numeric_consts<NumericType>::neg_one() {
  static NumericType const n(-1);
  return n;
}

// instantiate non-special cases
template struct numeric_consts<Decimal>;
template struct numeric_consts<Double>;
template struct numeric_consts<Float>;
template struct numeric_consts<Integer>;

NonNegativeInteger const& numeric_consts<NonNegativeInteger>::zero() {
  static NonNegativeInteger const n(0);
  return n;
}

NonNegativeInteger const& numeric_consts<NonNegativeInteger>::one() {
  static NonNegativeInteger const n(1);
  return n;
}

NonPositiveInteger const& numeric_consts<NonPositiveInteger>::zero() {
  static NonPositiveInteger const n(0);
  return n;
}

NonPositiveInteger const& numeric_consts<NonPositiveInteger>::neg_one() {
  static NonPositiveInteger const n(-1);
  return n;
}

PositiveInteger const& numeric_consts<PositiveInteger>::one() {
  static PositiveInteger const n(1);
  return n;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
