#include "common/common.h"

#include <boost/lexical_cast.hpp>
#include <sstream>
#include <limits>
#include "zorbatypes/numconversions.h"

namespace zorba {
  bool NumConversions::isNegZero(const xqpString& aStr) {
    xqpString lStr = aStr.trim(" \n\r\t", 4);
    size_t lLength = aStr.length();
    const char* lChars = aStr.c_str();
    if (lChars[0] == '-') {
      for(size_t i = 1; i < lLength; ++i) {
        if (lChars[i] != '0') {
          return false;
        }
      }
      return true;
    } else {
      return false;
    }
  }

  bool NumConversions::starCharToInteger(const char* aCharStar, xqp_integer& aInteger) {
    return Integer::parseString(aCharStar, aInteger);
  }

  bool NumConversions::strToInteger(const xqpString& aStr, xqp_integer& aInteger){
    return starCharToInteger(aStr.c_str(), aInteger);
  }
  xqpString NumConversions::integerToStr(xqp_integer aInteger){
    return aInteger.toString();
  }
  bool NumConversions::strToUInteger(const xqpString& aStr, xqp_uinteger& aUInteger){
    return Integer::parseStringUnsigned(aStr.c_str(), aUInteger);
  }
  xqpString NumConversions::uintegerToStr(xqp_uinteger aUInteger){
    return aUInteger.toString();
  }
  bool NumConversions::starCharToInt(const char* aCharStar, xqp_int& aInt){
    try {
      aInt =  boost::lexical_cast<xqp_int>(aCharStar);
      return true;
    } catch (boost::bad_lexical_cast &) {
      return false;
    }
  }
  bool NumConversions::strToInt(const xqpString& aStr, xqp_int& aInt) {
    return starCharToInt(aStr.c_str(), aInt);
  }
  xqpString NumConversions::intToStr(xqp_int aInt){
    return boost::lexical_cast<std::string>(aInt);
  }
  bool NumConversions::strToUInt(const xqpString& aStr, xqp_uint& aUInt){
    if ( isNegZero(aStr)) {
      aUInt = 0;
      return true;
    }
    try {
      aUInt =  boost::lexical_cast<xqp_uint>(aStr.c_str());
      return true;
    } catch (boost::bad_lexical_cast &) {
      return false;
    }
  }
  xqpString NumConversions::uintToStr(xqp_uint aUInt){
    return boost::lexical_cast<std::string>(aUInt);
  }
  bool NumConversions::strToLongLong(const xqpString& aStr, xqp_long& aLong){
    try {
      aLong = boost::lexical_cast<xqp_long>(aStr.c_str());
      return true;
    } catch (boost::bad_lexical_cast &) {
      return false;
    }
  }
  xqpString NumConversions::longLongToStr(xqp_long aLong){
    return boost::lexical_cast<std::string>(aLong);
  }
  bool NumConversions::strToLong(const xqpString& aStr, long& aLong){
    try {
      aLong = boost::lexical_cast<long>(aStr.c_str());
      return true;
    } catch (boost::bad_lexical_cast &) {
      return false;
    }
  }
  xqpString NumConversions::longToStr(long aLong) {
    return boost::lexical_cast<std::string>(aLong);
  }
  bool NumConversions::strToULongLong(const xqpString& aStr, xqp_ulong& aULong){
    if ( isNegZero(aStr)) {
      aULong = 0;
      return true;
    }
    try {
      aULong = boost::lexical_cast<xqp_ulong>(aStr.c_str());
      return true;
    } catch (boost::bad_lexical_cast &) {
      return false;
    }
  }
  xqpString NumConversions::ulongLongToStr(xqp_ulong aULong){
    return boost::lexical_cast<std::string>(aULong);
  }
  xqpString NumConversions::ulongToStr(unsigned long aULong) {
    return boost::lexical_cast<std::string>(aULong);
  }
  bool NumConversions::strToShort(const xqpString& aStr, xqp_short& aShort){
    try {
      aShort = boost::lexical_cast<xqp_short>(aStr.c_str());
      return true;
    } catch (boost::bad_lexical_cast &) {
      return false;
    }
  }
  xqpString NumConversions::shortToStr(xqp_short aShort){
    return boost::lexical_cast<std::string>(aShort);
  }
  bool NumConversions::strToUShort(const xqpString& aStr, xqp_ushort& aUShort){
    if ( isNegZero(aStr )) {
      aUShort = 0;
      return true;
    }
    try {
      aUShort = boost::lexical_cast<xqp_ushort>(aStr.c_str());
      return true;
    } catch (boost::bad_lexical_cast &) {
      return false;
    }
  }
  xqpString NumConversions::ushortToStr(xqp_ushort aUShort){
    return boost::lexical_cast<std::string>(aUShort);
  }
  bool NumConversions::starCharToDecimal(const char* aCharStar, xqp_decimal& aDecimal){
    return Decimal::parseString(aCharStar, aDecimal);
  }
  bool NumConversions::strToDecimal(const xqpString& aStr, xqp_decimal& aDecimal) {
    return starCharToDecimal(aStr.c_str(), aDecimal);
  }
  xqpString NumConversions::decimalToStr(xqp_decimal aDecimal){
    return aDecimal.toString();
  }

  bool NumConversions::starCharToFloat(const char* aCharStar, xqp_float& aFloat) {
    return Float::parseString(aCharStar, aFloat);
  }

  bool NumConversions::strToFloat(const xqpString& aStr, xqp_float& aFloat){
    return NumConversions::starCharToFloat(aStr.c_str(), aFloat);
  }
  xqpString NumConversions::floatToStr(xqp_float aFloat){
    return aFloat.toString();
  }
  bool NumConversions::starCharToDouble(const char* aCharStar, xqp_double& aDouble){
    return Double::parseString(aCharStar, aDouble);
  }
  bool NumConversions::strToDouble(const xqpString& aStr, xqp_double& aDouble) {
    return starCharToDouble(aStr.c_str(), aDouble);
  }
  xqpString NumConversions::doubleToStr(xqp_double aDouble){
    return aDouble.toString();
  }
  bool NumConversions::strToByte(const xqpString& aStr, xqp_byte& aByte){
    try {
      xqp_int lInt = boost::lexical_cast<xqp_int>(aStr.c_str());
      if (lInt >= -128 && lInt <= 127) {
        aByte = lInt;
        return true;
      } else {
        return false;
      }
    } catch (boost::bad_lexical_cast &) {
      return false;
    }
  }
  xqpString NumConversions::byteToStr(xqp_byte aByte){
    xqp_int lInt = aByte;
    return boost::lexical_cast<std::string>(lInt);
  }
  bool NumConversions::strToUByte(const xqpString& aStr, xqp_ubyte& aUByte){
    if ( isNegZero(aStr)) {
      aUByte = 0;
      return true;
    }
    try {
      xqp_uint lUInt = boost::lexical_cast<xqp_uint>(aStr.c_str());
      if (lUInt <= 255) {
        aUByte = lUInt;
        return true;
      } else {
        return false;
      }
    } catch (boost::bad_lexical_cast &) {
      return false;
    }
  }
  xqpString NumConversions::ubyteToStr(xqp_ubyte aUByte){
    xqp_uint lUInt = aUByte;
    return boost::lexical_cast<std::string>(lUInt);
  }

  xqpString NumConversions::sizetToStr(size_t aSizeT) {
    return boost::lexical_cast<std::string>(aSizeT);
  }

  // TODO must be tested if it works for numbers like 1e3
  bool NumConversions::doubleToInt(const xqp_double& aDouble, xqp_int& aInt) {
    xqpString lStr = aDouble.toIntegerString();
    return NumConversions::strToInt(lStr, aInt);
  }

  // TODO must be tested if it works for numbers like 1e3
  bool NumConversions::doubleToLongLong(const xqp_double& aDouble, xqp_long& aLong) {
    xqpString lStr = aDouble.toIntegerString();
    return NumConversions::strToLongLong(lStr, aLong);
  }

  bool NumConversions::doubleToLong(const xqp_double& aDouble, long& aLong) {
    xqpString lStr = aDouble.toIntegerString();
    return NumConversions::strToLong(lStr, aLong);
  }

  bool NumConversions::integerToUInt(const xqp_integer& aInteger, xqp_uint& aUInt) {
    xqpString lStr = aInteger.toString();
    return NumConversions::strToUInt(lStr, aUInt);
  }

} /* namespace zorba */
