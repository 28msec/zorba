/*
 *  Copyright 2008 FLWOR Foundation.
 *
 *  Authors: David Graf (davidgraf@28msec.com)
 */

#ifndef XQP_INTEGER_H
#define XQP_INTEGER_H

#include "mapm/m_apm.h"
#include "zorba/common.h"
#include "util/utf8/xqpString.h"

namespace xqp {

class Decimal;
template <typename Type> class FloatImpl;
typedef FloatImpl<double> Double;
typedef FloatImpl<float> Float;

class Integer {
  friend class Decimal;
  template <typename Type>
  friend class FloatImpl;

private:
  MAPM theInteger;
  Integer(MAPM aInteger) : theInteger(aInteger) { }
public:
  Integer() : theInteger(0) { }
  Integer(const Integer& aInteger) : theInteger(aInteger.theInteger) { }
  Integer(const Decimal& aDecimal);
  Integer(long long aLong);
  Integer(unsigned long long aULong);
  Integer(int32_t aInt) : theInteger(aInt) { }
  Integer(uint32_t aUInt);
  
private:
  static MAPM longlongToMAPM(long long);
  static MAPM floatingToInteger(MAPM theFloating) {
    // TODO inf and nan handling
    if (theFloating >= 0)
      return theFloating.floor();
    else
      return theFloating.ceil();
  }

public:
  static bool parse(const char*, Integer&);
  static bool parseUnsigned(const char*, Integer&);
  static bool parse(const Double&, Integer&);
  static bool parse(const Float&, Integer&);

  static Integer parseLong(long aLong);
  static Integer parseULong(unsigned long);
  static Integer parseSizeT(size_t);

  Integer& operator=(const Integer&);
  Integer& operator=(long long);
  Integer& operator=(int32_t);

  Integer operator+(const Integer&) const;
  Integer operator+(long long) const;
  Integer operator+(int32_t) const;
  Decimal operator+(const Decimal&) const;
  Decimal operator+(double) const;

  Integer& operator+=(const Integer&);
  Integer& operator+=(long long);
  Integer& operator+=(int32_t);

  Integer operator-(const Integer&) const;
  Integer operator-(long long) const;
  Integer operator-(int32_t) const;
  Decimal operator-(const Decimal&) const;
  Decimal operator-(double) const;

  Integer& operator-=(const Integer&);
  Integer& operator-=(long long);
  Integer& operator-=(int32_t);

  Integer operator*(const Integer&) const;
  Integer operator*(long long) const;
  Integer operator*(int32_t) const;
  Decimal operator*(const Decimal&) const;
  Decimal operator*(double) const;

  Integer& operator*=(const Integer&);
  Integer& operator*=(long long);
  Integer& operator*=(int32_t);

  Integer operator/(const Integer&) const;
  Integer operator/(long long) const;
  Integer operator/(int32_t) const;
  Decimal operator/(const Decimal&) const;
  Decimal operator/(double) const;

  Integer& operator/=(const Integer&);
  Integer& operator/=(long long);
  Integer& operator/=(int32_t);

  Integer operator%(const Integer&) const;
  Integer operator%(long long) const;
  Integer operator%(int32_t) const;
  Decimal operator%(const Decimal&) const;
  Decimal operator%(double) const;

  Integer& operator%=(const Integer&);
  Integer& operator%=(long long);
  Integer& operator%=(int32_t);

  Integer operator-() const; 
  /** prefix */
  Integer& operator++();
  /** postfix */
  Integer operator++(int);
  Integer round(Integer aPrecision) const; 
  Integer roundHalfToEven(Integer aPrecision) const;

  bool operator==(const Integer& aInteger) const { return theInteger == aInteger.theInteger; } 
  bool operator==(long long) const;
  bool operator==(int32_t aInt) const { return theInteger == aInt; } 
  bool operator==(const Decimal&) const;
  bool operator==(double aDouble) const { return theInteger == aDouble; }

  bool operator!=(const Integer& aInteger) const { return theInteger != aInteger.theInteger; } 
  bool operator!=(long long) const;
  bool operator!=(int32_t aInt) const { return theInteger != aInt; } 
  bool operator!=(const Decimal&) const;
  bool operator!=(double aDouble) const { return theInteger != aDouble; }

  bool operator<(const Integer& aInteger) const { return theInteger < aInteger.theInteger; } 
  bool operator<(long long) const;
  bool operator<(int32_t aInt) const { return theInteger < aInt; } 
  bool operator<(const Decimal&) const;
  bool operator<(double aDouble) const { return theInteger < aDouble; }

  bool operator<=(const Integer& aInteger) const { return theInteger <= aInteger.theInteger; } 
  bool operator<=(long long) const;
  bool operator<=(int32_t aInt) const { return theInteger <= aInt; } 
  bool operator<=(const Decimal&) const;
  bool operator<=(double aDouble) const { return theInteger <= aDouble; }
  bool operator<=(const Double&) const;

  bool operator>(const Integer& aInteger) const { return theInteger > aInteger.theInteger; } 
  bool operator>(long long) const;
  bool operator>(int32_t aInt) const { return theInteger > aInt; } 
  bool operator>(const Decimal&) const;
  bool operator>(double aDouble) const { return theInteger > aDouble; }

  bool operator>=(const Integer& aInteger) const { return theInteger >= aInteger.theInteger; } 
  bool operator>=(long long) const;
  bool operator>=(int32_t aInt) const { return theInteger >= aInt; } 
  bool operator>=(const Decimal&) const;
  bool operator>=(double aDouble) const { return theInteger >= aDouble; }
  bool operator>=(const Double&) const;

  xqpString toString() const;
}; // class Integer

std::ostream& operator<<(std::ostream& os, const Integer&);

} // namespace xqp

#endif // XQP_INTEGER_H
