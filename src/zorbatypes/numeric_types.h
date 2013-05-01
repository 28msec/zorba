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

class integer_traits;
class negative_traits;
class nonNegative_traits;
class nonPositive_traits;
class positive_traits;

template<class C> class IntegerImpl;
typedef IntegerImpl<integer_traits>     Integer;
typedef IntegerImpl<negative_traits>    NegativeInteger;
typedef IntegerImpl<nonNegative_traits> NonNegativeInteger;
typedef IntegerImpl<nonPositive_traits> NonPositiveInteger;
typedef IntegerImpl<positive_traits>    PositiveInteger;

class Decimal;

template<typename F> class FloatImpl;
typedef FloatImpl<float> Float;
typedef FloatImpl<double> Double;

/**
 * This contains references to singleton objects having constant values for the
 * often-used numeric constants -1, 0, and +1.
 *
 * @tparam NumericType One of Integer, NegativeInteger, NonNegativeInteger,
 * NonPositiveInteger, PositiveInteger, Decimal, Float, or Double.
 */
template<class NumericType>
struct numeric_consts {
  static NumericType const& neg_one();
  static NumericType const& zero();
  static NumericType const& one();
};

/**
 * Specialization for NegativeInteger that has only a reference to a singleton
 * object having the constant value -1.
 */
template<>
struct numeric_consts<NegativeInteger> {
  static NegativeInteger const& neg_one();
};

/**
 * Specialization for NonNegativeInteger that has only references to the
 * singleton objects having the constant values 0 and 1.
 */
template<>
struct numeric_consts<NonNegativeInteger> {
  static NonNegativeInteger const& zero();
  static NonNegativeInteger const& one();
};

/**
 * Specialization for NonPositiveInteger that has only references to the
 * singleton objects having the constant values -1 and 0.
 */
template<>
struct numeric_consts<NonPositiveInteger> {
  static NonPositiveInteger const& neg_one();
  static NonPositiveInteger const& zero();
};

/**
 * Specialization for NegativeInteger that has only a reference to a singleton
 * object having the constant value 1.
 */
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
