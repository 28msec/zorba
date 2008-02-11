/*
 *  Copyright 2008 FLWOR Foundation.
 *
 *  Authors: David Graf (davidgraf@28msec.com)
 */

#ifndef XQP_INTEGER_H
#define XQP_INTEGER_H

#include "mapm/m_apm.h"
#include "zorba/common.h"
#include "zorba/util/utf8/xqpString.h"

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
  /**
   * @return integer that represents 0
   */
  static Integer& zero();
  /**
   * Parse string to Integer.
   * @param aStr String
   * @param aInteger Result
   * @return true if parsing succeed, else false
   */ 
  static bool parseString(const char* aStr, Integer& aInteger);
  /**
   * Parsing of string to unsigned integer. Zorba does not differ between
   * unsigned and signed Integer because unsigned Integer is never a result
   * of an numeric operation => The only places where the unsignedness must
   * be checked is the parsing.
   *
   * @param aStr String
   * @param aInteger result
   * @return true if parsing succeed, else false
   */
  static bool parseStringUnsigned(const char*, Integer&);
  /**
   * Parsing form double to Integer. Decimal places are cut of.
   */
  static bool parseDouble(const Double&, Integer&);
  /**
   * Parsing form float to Integer. Decimal places are cut of.
   */
  static bool parseFloat(const Float&, Integer&);
  /**
   * Parsing form Decimal to Integer. Decimal places are cut of.
   */
  static Integer parseDecimal(const Decimal&);
  static Integer parseLongLong(long long);
  static Integer parseULongLong(unsigned long long);
  static Integer parseInt(int32_t);
  static Integer parseUInt(uint32_t);
  static Integer parseLong(long aLong);
  static Integer parseULong(unsigned long);
  static Integer parseSizeT(size_t);

  Integer& operator=(const Integer&);

  Integer operator+(const Integer&) const;
  Decimal operator+(const Decimal&) const;

  Integer& operator+=(const Integer&);

  Integer operator-(const Integer&) const;
  Decimal operator-(const Decimal&) const;

  Integer& operator-=(const Integer&);

  Integer operator*(const Integer&) const;
  Decimal operator*(const Decimal&) const;

  Integer& operator*=(const Integer&);

  Integer operator/(const Integer&) const;
  Decimal operator/(const Decimal&) const;

  Integer& operator/=(const Integer&);

  Integer operator%(const Integer&) const;
  Decimal operator%(const Decimal&) const;

  Integer& operator%=(const Integer&);

  Integer operator-() const; 
  /** prefix */
  Integer& operator++();
  /** postfix */
  Integer operator++(int);
  Integer round(Integer aPrecision) const; 
  Integer roundHalfToEven(Integer aPrecision) const;

  bool operator==(const Integer& aInteger) const { return theInteger == aInteger.theInteger; } 
  bool operator==(const Decimal&) const;

  bool operator!=(const Integer& aInteger) const { return theInteger != aInteger.theInteger; } 
  bool operator!=(const Decimal&) const;

  bool operator<(const Integer& aInteger) const { return theInteger < aInteger.theInteger; } 
  bool operator<(const Decimal&) const;

  bool operator<=(const Integer& aInteger) const { return theInteger <= aInteger.theInteger; } 
  bool operator<=(const Decimal&) const;
  bool operator<=(const Double&) const;

  bool operator>(const Integer& aInteger) const { return theInteger > aInteger.theInteger; } 
  bool operator>(const Decimal&) const;

  bool operator>=(const Integer& aInteger) const { return theInteger >= aInteger.theInteger; } 
  bool operator>=(const Decimal&) const;
  bool operator>=(const Double&) const;

  xqpString toString() const;
}; // class Integer

std::ostream& operator<<(std::ostream& os, const Integer&);

} // namespace xqp

#endif // XQP_INTEGER_H
