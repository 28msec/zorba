#ifndef ZORBA_DECIMAL_H
#define ZORBA_DECIMAL_H

#include <zorba/m_apm.h>
#include <zorba/xqpString.h>

namespace xqp {

class Integer;

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
  static MAPM round(MAPM aValue, MAPM aPrecision);
  static MAPM roundHalfToEven(MAPM aValue, MAPM aPrecision);

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
  Decimal floor() const { return Decimal(theDecimal.floor()); }
  Decimal ceil() const { return Decimal(theDecimal.ceil()); }
  Decimal round() const;
  Decimal round(Integer aPrecision) const; 
  Decimal roundHalfToEven(Integer aPrecision) const;

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
}; // class Decimal


std::ostream& operator<<(std::ostream& os, const Decimal&);

} // namespace xqp

#endif // XQP_DECIMAL_H

