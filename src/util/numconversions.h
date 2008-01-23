#ifndef XQP_NUM_CONVERSIONS_H
#define XQP_NUM_CONVERSIONS_H

#include "zorba/types/representations.h"

namespace xqp {

/**
 * Class contains all num conversions and string to num and num to string conversions
 * that are used in Zorba.
 *
 * All functions which might not work return a bool which indicates the success of the
 * conversions. Functions which aways work return the value directly.
 */
class NumConversions {
private:
  static bool isNegZero(const xqpString& aStr);
  /**
   * @return -1 if aCharStar can be parsed to '-inf'
   *          1 if aCharStar can be parsed to 'inf'
   *          0 else
   */
  static short isInf(const char* aCharStar);

public:
  /**********************************************************************************
   * String to Numeric and Numeric to String Conversions
   *********************************************************************************/
  static bool strToInteger(const xqpString& aStr, xqp_integer& aInteger);
  static xqpString integerToStr(xqp_integer aInteger);
  static bool strToUInteger(const xqpString& aStr, xqp_uinteger& aUInteger);
  static xqpString uintegerToStr(xqp_uinteger aUInteger);
  static bool starCharToInt(const char* aStarChar, xqp_int& aInt);
  static bool strToInt(const xqpString& aStr, xqp_int& aInt);
  static xqpString intToStr(xqp_int aInt);
  static bool strToUInt(const xqpString& aStr, xqp_uint& aUInt);
  static xqpString uintToStr(xqp_uint aUInt);
  static bool strToLong(const xqpString& aStr, xqp_long& aLong);
  static xqpString longToStr(xqp_long aLong);
  static bool strToULong(const xqpString& aStr, xqp_ulong& aULong);
  static xqpString ulongToStr(xqp_ulong aULong);
  static bool strToShort(const xqpString& aStr, xqp_short& aShort);
  static xqpString shortToStr(xqp_short aShort);
  static bool strToUShort(const xqpString& aStr, xqp_ushort& aUShort);
  static xqpString ushortToStr(xqp_ushort aUShort);
  static bool starCharToDecimal(const char* aStarChar, xqp_decimal& aDecimal);
  static bool strToDecimal(const xqpString& aStr, xqp_decimal& aDecimal);
  static xqpString decimalToStr(xqp_decimal aDecimal);
  static bool starCharToFloat(const char* aStarChar, xqp_float& aFloat);
  static bool strToFloat(const xqpString& aStr, xqp_float& aFloat);
  static xqpString floatToStr(xqp_float aFloat);
  static bool starCharToDouble(const char* aStarChar, xqp_double& aDouble);
  static bool strToDouble(const xqpString& aStr, xqp_double& aDouble);
  static xqpString doubleToStr(xqp_double aDouble);
  static bool strToByte(const xqpString& aStr, xqp_byte& aByte);
  static xqpString byteToStr(xqp_byte aByte);
  static bool strToUByte(const xqpString& aStr, xqp_ubyte& aUByte);
  static xqpString ubyteToStr(xqp_ubyte aUByte);
  static bool isNaN(xqp_double);
  static bool isNaN(xqp_float);
  static bool isPosOrNegInf(xqp_double);
  static bool isPosOrNegInf(xqp_float);

  /********************************************************************************
   * Numeric to Numeric Conversions
   * *****************************************************************************/
  // TODO
}; /* class NumConversions */

} /* namespace xqp */

#endif
