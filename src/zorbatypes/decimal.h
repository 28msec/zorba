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

#include <zorba/config.h>
#include "common/common.h"

#ifndef ZORBA_NO_BIGNUMBERS
#include "zorbatypes/m_apm.h"
#else
#include <math.h>
#endif
#include "zorbatypes/xqpstring.h"
#include "zorbatypes/zorbatypes_decl.h"
#include "zorbaserialization/serialization_engine.h"


namespace zorba {

#ifdef ZORBA_NO_BIGNUMBERS
typedef double    MAPM;
#endif

// exported for testing only
class ZORBA_DLL_PUBLIC  Decimal  : public ::zorba::serialization::SerializeBaseClass
{
  friend class Integer;
  template <typename Type>
    friend class FloatImpl;
  friend class NumConversions;

private:
  MAPM theDecimal;
  Decimal(MAPM aDecimal) : theDecimal(aDecimal) { }


public:
  SERIALIZABLE_CLASS(Decimal)
  SERIALIZABLE_CLASS_CONSTRUCTOR(Decimal)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    ar & theDecimal;
  }
#ifdef ZORBA_NUMERIC_OPTIMIZATION
public:
  static  HashCharPtrObjPtrLimited<Decimal>  parsed_decimals;
#endif

public:
  Decimal() : theDecimal(0) { }

  Decimal(const Decimal& aDecimal) 
    :
  ::zorba::serialization::SerializeBaseClass(), theDecimal(aDecimal.theDecimal) { }

  virtual ~Decimal() {}

public:
#ifndef ZORBA_NO_BIGNUMBERS
  //static MAPM round(const MAPM &aValue, int aPrecision);
  static MAPM round(const MAPM &aValue, const MAPM &aPrecision);
  static MAPM roundHalfToEven(const MAPM &aValue, const MAPM &aPrecision);
#else
  static MAPM round(MAPM aValue, int aPrecision);
  static MAPM roundHalfToEven(MAPM aValue, int aPrecision);
#endif

private:
  static xqpStringStore_t decimalToString(
        MAPM,
        int precision=ZORBA_FLOAT_POINT_PRECISION);

  static void reduceFloatingPointString(char *str);

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

  long compare(const Decimal& other) const
  {
#ifndef ZORBA_NO_BIGNUMBERS
    return theDecimal.compare(other.theDecimal);
#else
    return (theDecimal < other.theDecimal ?
            -1 :
            (theDecimal == other.theDecimal ? 0 : 1)); 
#endif
  }

  xqpStringStore_t toString() const;

  xqpStringStore_t toIntegerString() const;

  uint32_t hash() const;

  int getValueAsInt();
}; // class Decimal

  
 std::ostream& operator<<(std::ostream& os, const Decimal&);

} // namespace zorba

#endif // ZORBA_DECIMAL_H

