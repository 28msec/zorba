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
#ifndef ZORBA_DECIMAL_H
#define ZORBA_DECIMAL_H

#include "common/common.h"

#ifndef ZORBA_NO_BIGNUMBERS
#include "zorbatypes/m_apm.h"
#else
#include <math.h>
#endif
#include "zorbatypes/xqpstring.h"
#include "zorbatypes/zorbatypes_decl.h"

namespace zorba {

#ifdef ZORBA_NO_BIGNUMBERS
typedef double    MAPM;
#endif

class Decimal {
  friend class Integer;
  template <typename Type>
    friend class FloatImpl;

private:
  MAPM theDecimal;
  Decimal(MAPM aDecimal) : theDecimal(aDecimal) { }

public:
  Decimal() : theDecimal(0) { }
  Decimal(const Decimal& aDecimal) : theDecimal(aDecimal.theDecimal) { }

public:
#ifndef ZORBA_NO_BIGNUMBERS
  static MAPM round(MAPM aValue, MAPM aPrecision);
  static MAPM roundHalfToEven(MAPM aValue, MAPM aPrecision);
#else
  static MAPM round(MAPM aValue, int aPrecision);
  static MAPM roundHalfToEven(MAPM aValue, int aPrecision);
#endif

private:
  static xqpString decimalToString(MAPM);

public:
  static Decimal& zero();
  static bool parseString(const char*, Decimal&);
  static bool parseNativeDouble(double, Decimal&);
  static Decimal parseLong(long aLong);
  static Decimal parseULong(unsigned long aULong);
  static Decimal parseInteger(const Integer& aInteger);
  static Decimal parseLongLong(long long);
  static Decimal parseULongLong(unsigned long long);
  static Decimal parseInt(int32_t aInt);
  static Decimal parseUInt(uint32_t aUInt);
  static bool parseFloat(const Float&, Decimal&);
  static bool parseDouble(const Double&, Decimal&);

  Decimal& operator=(const Decimal&);

  Decimal operator+(const Integer&) const;
  Decimal operator+(const Decimal&) const;

  Decimal& operator+=(const Integer&);
  Decimal& operator+=(const Decimal&);

  Decimal operator-(const Integer&) const;
  Decimal operator-(const Decimal&) const;

  Decimal& operator-=(const Integer&);
  Decimal& operator-=(const Decimal&);

  Decimal operator*(const Integer&) const;
  Decimal operator*(const Decimal&) const;

  Decimal& operator*=(const Integer&);
  Decimal& operator*=(const Decimal&);

  Decimal operator/(const Integer&) const;
  Decimal operator/(const Decimal&) const;

  Decimal& operator/=(const Integer&);
  Decimal& operator/=(const Decimal&);

  Decimal operator%(const Integer&) const;
  Decimal operator%(const Decimal&) const;

  Decimal& operator%=(const Integer&);
  Decimal& operator%=(const Decimal&);

  Decimal operator-() const; 
#ifndef ZORBA_NO_BIGNUMBERS
  Decimal floor() const { return Decimal(theDecimal.floor()); }
  Decimal ceil() const { return Decimal(theDecimal.ceil()); }
#else
  Decimal floor() const { return Decimal(::floor(theDecimal)); }
  Decimal ceil() const { return Decimal(::ceil(theDecimal)); }
#endif
  Decimal round() const;
  Decimal round(Integer aPrecision) const; 
  Decimal roundHalfToEven(Integer aPrecision) const;

  Decimal sqrt () const;

  bool operator==(const Integer&) const;
  bool operator==(const Decimal& aDecimal) const { return theDecimal == aDecimal.theDecimal; }

  bool operator!=(const Integer&) const;
  bool operator!=(const Decimal& aDecimal) const { return theDecimal != aDecimal.theDecimal; }

  bool operator<(const Integer&) const;
  bool operator<(const Decimal& aDecimal) const { return theDecimal < aDecimal.theDecimal; }

  bool operator<=(const Integer&) const;
  bool operator<=(const Decimal& aDecimal) const { return theDecimal <= aDecimal.theDecimal; }

  bool operator>(const Integer&) const;
  bool operator>(const Decimal& aDecimal) const { return theDecimal > aDecimal.theDecimal; }

  bool operator>=(const Integer&) const;
  bool operator>=(const Decimal& aDecimal) const { return theDecimal >= aDecimal.theDecimal; }

  xqpString toString() const;
  xqpString toIntegerString() const;
  uint32_t hash() const;
}; // class Decimal


std::ostream& operator<<(std::ostream& os, const Decimal&);

} // namespace zorba

#endif // ZORBA_DECIMAL_H

