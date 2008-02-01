/*
 *  Copyright 2008 FLWOR Foundation.
 *
 *  Authors: David Graf (davidgraf@28msec.com)
 */

#ifndef XQP_DECIMAL_H
#define XQP_DECIMAL_H

#include "mapm/m_apm.h"
#include "util/utf8/xqpString.h"

namespace xqp {

class Integer;

class Decimal {
  friend class Integer;
private:
  MAPM theDecimal;
  Decimal(MAPM aDecimal) { theDecimal = aDecimal; }

public:
  Decimal() { theDecimal = 0; }
  Decimal(const Decimal& aDecimal) { theDecimal = aDecimal.theDecimal; }
  Decimal(const Integer& aInteger);
  Decimal(const xqpString& aStr) { theDecimal = aStr.c_str(); }
  Decimal(const char* aStr) { theDecimal = aStr; }
  Decimal(double aDouble) { theDecimal = aDouble; }
  Decimal(long long);
  Decimal(unsigned long long);
  Decimal(int32_t aInt) { theDecimal = aInt; }
  Decimal(uint32_t aUInt);

private:
  static MAPM round(MAPM aValue, MAPM aPrecision);
  static MAPM roundHalfToEven(MAPM aValue, MAPM aPrecision);
  static double mapmToDouble(MAPM);
  static float mapmToFloat(MAPM);

public:
  static Decimal parseLong(long aLong);

  static double round(double, Integer aPrecision = 0);
  static float round(float, Integer aPrecision = 0);
  static double roundHalfToEven(double, Integer aPrecision);
  static float roundHalfToEven(float, Integer aPrecision);

  Decimal& operator=(const xqpString&);
  Decimal& operator=(const char*);
  Decimal& operator=(const Decimal&);
  Decimal& operator=(double);
  Decimal& operator=(const Integer&);
  Decimal& operator=(long long);
  Decimal& operator=(int32_t);

  Decimal operator+(const Integer&) const;
  Decimal operator+(long long) const;
  Decimal operator+(int32_t) const;
  Decimal operator+(const Decimal&) const;
  Decimal operator+(double) const;

  Decimal& operator+=(const Integer&);
  Decimal& operator+=(long long);
  Decimal& operator+=(int32_t);
  Decimal& operator+=(const Decimal&);
  Decimal& operator+=(double);

  Decimal operator-(const Integer&) const;
  Decimal operator-(long long) const;
  Decimal operator-(int32_t) const;
  Decimal operator-(const Decimal&) const;
  Decimal operator-(double) const;

  Decimal& operator-=(const Integer&);
  Decimal& operator-=(long long);
  Decimal& operator-=(int32_t);
  Decimal& operator-=(const Decimal&);
  Decimal& operator-=(double);

  Decimal operator*(const Integer&) const;
  Decimal operator*(long long) const;
  Decimal operator*(int32_t) const;
  Decimal operator*(const Decimal&) const;
  Decimal operator*(double) const;

  Decimal& operator*=(const Integer&);
  Decimal& operator*=(long long);
  Decimal& operator*=(int32_t);
  Decimal& operator*=(const Decimal&);
  Decimal& operator*=(double);

  Decimal operator/(const Integer&) const;
  Decimal operator/(long long) const;
  Decimal operator/(int32_t) const;
  Decimal operator/(const Decimal&) const;
  Decimal operator/(double) const;

  Decimal& operator/=(const Integer&);
  Decimal& operator/=(long long);
  Decimal& operator/=(int32_t);
  Decimal& operator/=(const Decimal&);
  Decimal& operator/=(double);

  Decimal operator%(const Integer&) const;
  Decimal operator%(long long) const;
  Decimal operator%(int32_t) const;
  Decimal operator%(const Decimal&) const;
  Decimal operator%(double) const;

  Decimal& operator%=(const Integer&);
  Decimal& operator%=(long long);
  Decimal& operator%=(int32_t);
  Decimal& operator%=(const Decimal&);
  Decimal& operator%=(double);

  Decimal operator-(); 
  Decimal floor() const { return Decimal(theDecimal.floor()); }
  Decimal ceil() const { return Decimal(theDecimal.ceil()); }
  Decimal round(Integer aPrecision = 0) const { return Decimal(Decimal::round(theDecimal, aPrecision.theInteger)); }
  Decimal roundHalfToEven(Integer aPrecision) const { return Decimal(Decimal::roundHalfToEven(theDecimal, aPrecision.theInteger)); }

  bool operator==(const Integer&) const;
  bool operator==(long long) const;
  bool operator==(int32_t aInt) const { return theDecimal == aInt; }
  bool operator==(const Decimal& aDecimal) const { return theDecimal == aDecimal.theDecimal; }
  bool operator==(double aDouble) const { return theDecimal == aDouble; }

  bool operator!=(const Integer&) const;
  bool operator!=(long long) const;
  bool operator!=(int32_t aInt) const { return theDecimal != aInt; }
  bool operator!=(const Decimal& aDecimal) const { return theDecimal != aDecimal.theDecimal; }
  bool operator!=(double aDouble) const { return theDecimal != aDouble; }

  bool operator<(const Integer&) const;
  bool operator<(long long) const;
  bool operator<(int32_t aInt) const { return theDecimal < aInt; }
  bool operator<(const Decimal& aDecimal) const { return theDecimal < aDecimal.theDecimal; }
  bool operator<(double aDouble) const { return theDecimal < aDouble; }

  bool operator<=(const Integer&) const;
  bool operator<=(long long) const;
  bool operator<=(int32_t aInt) const { return theDecimal <= aInt; }
  bool operator<=(const Decimal& aDecimal) const { return theDecimal <= aDecimal.theDecimal; }
  bool operator<=(double aDouble) const { return theDecimal <= aDouble; }

  bool operator>(const Integer&) const;
  bool operator>(long long) const;
  bool operator>(int32_t aInt) const { return theDecimal > aInt; }
  bool operator>(const Decimal& aDecimal) const { return theDecimal > aDecimal.theDecimal; }
  bool operator>(double aDouble) const { return theDecimal > aDouble; }

  bool operator>=(const Integer&) const;
  bool operator>=(long long) const;
  bool operator>=(int32_t aInt) const { return theDecimal >= aInt; }
  bool operator>=(const Decimal& aDecimal) const { return theDecimal >= aDecimal.theDecimal; }
  bool operator>=(double aDouble) const { return theDecimal >= aDouble; }

  xqpString toString() const;
}; // class Decimal


std::ostream& operator<<(std::ostream& os, const Decimal&);

} // namespace xqp

#endif // XQP_DECIMAL_H

