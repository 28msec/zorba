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

#pragma once
#ifndef ZORBA_NUMERIC_CONSTS_H
#define ZORBA_NUMERIC_CONSTS_H

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

class integer_check;
class negative_check;
class nonNegative_check;
class nonPositive_check;
class positive_check;

template<class C> class IntegerImpl;
typedef IntegerImpl<integer_check>      Integer;
typedef IntegerImpl<negative_check>     NegativeInteger;
typedef IntegerImpl<nonNegative_check>  NonNegativeInteger;
typedef IntegerImpl<nonPositive_check>  NonPositiveInteger;
typedef IntegerImpl<positive_check>     PositiveInteger;

class Decimal;

template<typename F> class FloatImpl;
typedef FloatImpl<float> Float;
typedef FloatImpl<double> Double;

template<class NumericType>
struct numeric_consts {
  static NumericType const& neg_one();
  static NumericType const& zero();
  static NumericType const& one();
};

template<>
struct numeric_consts<NegativeInteger> {
  static NegativeInteger const& neg_one();
};

template<>
struct numeric_consts<NonNegativeInteger> {
  static NonNegativeInteger const& zero();
  static NonNegativeInteger const& one();
};

template<>
struct numeric_consts<NonPositiveInteger> {
  static NonPositiveInteger const& neg_one();
  static NonPositiveInteger const& zero();
};

template<>
struct numeric_consts<PositiveInteger> {
  static PositiveInteger const& one();
};

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba

#endif // ZORBA_NUMERIC_CONSTS_H
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
