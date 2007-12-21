#include <boost/lexical_cast.hpp>
#include <sstream>
#include <climits>
#include "util/numconversions.h"

namespace xqp {
  bool NumConversions::strToInteger(const xqpString& aStr, xqp_integer& aInteger){
    try {
      aInteger = boost::lexical_cast<xqp_integer>(aStr.c_str());
      return true;
    } catch (boost::bad_lexical_cast &) {
      return false;
    }
  }
  xqpString NumConversions::integerToStr(xqp_integer aInteger){
    return boost::lexical_cast<std::string>(aInteger);
  }
  bool NumConversions::strToUInteger(const xqpString& aStr, xqp_uinteger& aUInteger){
    try {
      aUInteger = boost::lexical_cast<xqp_uinteger>(aStr.c_str());
      return true;
    } catch (boost::bad_lexical_cast &) {
      return false;
    }
  }
  xqpString NumConversions::uintegerToStr(xqp_uinteger aUInteger){
    return boost::lexical_cast<std::string>(aUInteger);
  }
  bool NumConversions::starCharToInt(const char* aStarChar, xqp_int& aInt){
    try {
      aInt =  boost::lexical_cast<xqp_int>(aStarChar);
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
  bool NumConversions::strToLong(const xqpString& aStr, xqp_long& aLong){
    try {
      aLong = boost::lexical_cast<xqp_long>(aStr.c_str());
      return true;
    } catch (boost::bad_lexical_cast &) {
      return false;
    }
  }
  xqpString NumConversions::longToStr(xqp_long aLong){
    return boost::lexical_cast<std::string>(aLong);
  }
  bool NumConversions::strToULong(const xqpString& aStr, xqp_ulong& aULong){
    try {
      aULong = boost::lexical_cast<xqp_ulong>(aStr.c_str());
      return true;
    } catch (boost::bad_lexical_cast &) {
      return false;
    }
  }
  xqpString NumConversions::ulongToStr(xqp_ulong aULong){
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
  bool NumConversions::starCharToDecimal(const char* aStarChar, xqp_decimal& aDecimal){
    try {
      aDecimal = boost::lexical_cast<xqp_decimal>(aStarChar);
      return true;
    } catch (boost::bad_lexical_cast &) {
      return false;
    }
  }
  bool NumConversions::strToDecimal(const xqpString& aStr, xqp_decimal& aDecimal) {
    return starCharToDecimal(aStr.c_str(), aDecimal);
  }
  xqpString NumConversions::decimalToStr(xqp_decimal aDecimal){
    return boost::lexical_cast<std::string>(aDecimal);
  }
  bool NumConversions::starCharToFloat(const char* aCharStar, xqp_float& aFloat) {
    char* lEndPtr;
     aFloat = (xqp_float)strtod(aCharStar, &lEndPtr);//daniel: changed from strtof to compile on Windows
    if (*lEndPtr != '\0')
      return false;
    else
      return true;

  }
  bool NumConversions::strToFloat(const xqpString& aStr, xqp_float& aFloat){
    return NumConversions::starCharToFloat(aStr.c_str(), aFloat);
  }
  xqpString NumConversions::floatToStr(xqp_float aFloat){
    if (aFloat == std::numeric_limits<float>::infinity())
      return "INF";
    else if (aFloat == -std::numeric_limits<float>::infinity())
      return "-INF";
    else if (aFloat != aFloat)
      return "NaN";
    else {
      std::stringstream lStream;
      lStream << aFloat;
      return lStream.str();
    }
  }
  bool NumConversions::starCharToDouble(const char* aStarChar, xqp_double& aDouble){
    char* lEndPtr;
    aDouble = strtod(aStarChar, &lEndPtr);
    if (*lEndPtr != '\0')
      return false;
    else
      return true;
  }
  bool NumConversions::strToDouble(const xqpString& aStr, xqp_double& aDouble) {
    return starCharToDouble(aStr.c_str(), aDouble);
  }
  xqpString NumConversions::doubleToStr(xqp_double aDouble){
    if (aDouble == std::numeric_limits<double>::infinity())
      return "INF";
    else if (aDouble == -std::numeric_limits<double>::infinity())
      return "-INF";
    else if (aDouble != aDouble)
      return "NaN";
    else {
      std::stringstream lStream;
      lStream << aDouble;
      return lStream.str();
    }
  }
  bool NumConversions::strToByte(const xqpString& aStr, xqp_byte& aByte){
    try {
      aByte = boost::lexical_cast<xqp_byte>(aStr.c_str());
      return true;
    } catch (boost::bad_lexical_cast &) {
      return false;
    }
  }
  xqpString NumConversions::byteToStr(xqp_byte aByte){
    return boost::lexical_cast<std::string>(aByte);
  }
  bool NumConversions::strToUByte(const xqpString& aStr, xqp_ubyte& aUByte){
    try {
      aUByte = boost::lexical_cast<xqp_ubyte>(aStr.c_str());
      return true;
    } catch (boost::bad_lexical_cast &) {
      return false;
    }
  }
  xqpString NumConversions::ubyteToStr(xqp_ubyte aUByte){
    return boost::lexical_cast<std::string>(aUByte);
  }
} /* namespace xqp */
