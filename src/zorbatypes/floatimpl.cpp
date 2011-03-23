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
#include <limits>
#include <string>
#include <stdlib.h>

#include "common/common.h"
#include "zorbatypes/floatimpl.h"
#include "zorbatypes/integer.h"
#include "zorbatypes/decimal.h"
#include "zorbatypes/numconversions.h"

#include "zorbaserialization/serialization_engine.h"


#undef  IS_ZERO
#define IS_ZERO(mapm_obj)                 (mapm_obj == 0)
#undef  IS_POSITIVE
#define IS_POSITIVE(mapm_obj)             (mapm_obj > 0)
#undef  IS_POSITIVE_OR_ZERO
#define IS_POSITIVE_OR_ZERO(mapm_obj)     (mapm_obj >= 0)
#undef  IS_NEGATIVE
#define IS_NEGATIVE(mapm_obj)             (mapm_obj < 0)

float acosh( float z)
{
  //formula from www.mathworks.com
  return ::log(z + ::sqrt(z*z-1));
}

double acosh( double z)
{
  return ::log(z + ::sqrt(z*z-1));
}

float asinh( float z)
{
  //formula from www.mathworks.com
  return ::log(z + ::sqrt(z*z+1));
}

double asinh( double z)
{
  return ::log(z + ::sqrt(z*z+1));
}

float atanh( float z)
{
  //formula from www.mathworks.com
  return (float)0.5*(float)::log((1+z)/(1-z));
}

double atanh( double z)
{
  return 0.5*::log((1+z)/(1-z));
}


namespace zorba 
{

SERIALIZABLE_TEMPLATE_VERSIONS(FloatImpl)
END_SERIALIZABLE_TEMPLATE_VERSIONS(FloatImpl)

SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS(FloatImpl, FloatImpl<float>, 1)
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS(FloatImpl, FloatImpl<double>, 2)


#ifdef ZORBA_NUMERIC_OPTIMIZATION
template<>  HashCharPtrObjPtrLimited<FloatImpl<float>>   FloatImpl<float>::parsed_floats;
template<>  HashCharPtrObjPtrLimited<FloatImpl<double>>  FloatImpl<double>::parsed_floats;
#endif


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  FloatCommons                                                              //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

const zstring& FloatCommons::get_INF_POS_STR()
{
  static const zstring INF_POS_STR("INF");
  return INF_POS_STR;
}


const zstring& FloatCommons::get_INF_NEG_STR()
{
  static const zstring INF_NEG_STR("-INF");
  return INF_NEG_STR;
}


const zstring& FloatCommons::get_NOT_A_NUM_STR()
{
  static const zstring NOT_A_NUM_STR("NaN");
  return NOT_A_NUM_STR;
}


Double FloatCommons::parseFloat(const Float& aFloat) 
{
  Double lDouble(aFloat.getNumber());
  return lDouble;
}


Float FloatCommons::parseDouble(const Double& aDouble) 
{
  Float lFloat((float)aDouble.getNumber());
  return lFloat;
}


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  FloatImpl                                                                 //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


template <typename FloatType>
FloatImpl<FloatType>& FloatImpl<FloatType>::zero() 
{
  static FloatImpl<FloatType> lValue(0);
  return lValue;
}


template <typename FloatType>
FloatImpl<FloatType>& FloatImpl<FloatType>::zero_neg() 
{
  static FloatImpl<FloatType> lValue(-0.0);
  return lValue;
}


template <typename FloatType>
FloatImpl<FloatType>& FloatImpl<FloatType>::one() 
{
  static FloatImpl<FloatType> lValue(1);
  return lValue;
}

template <typename FloatType>
FloatImpl<FloatType>& FloatImpl<FloatType>::one_neg() {
  static FloatImpl<FloatType> lValue(-1);
  return lValue;
}


template <typename FloatType>
FloatImpl<FloatType>& FloatImpl<FloatType>::nan() 
{
  static FloatImpl<FloatType> lValue(::sqrt(-1.0f));
  return lValue;
}


template <typename FloatType>
FloatImpl<FloatType>& FloatImpl<FloatType>::inf_pos() 
{
  static FloatImpl<FloatType> lValue(std::numeric_limits<FloatType>::infinity());
  return lValue;
}


template <typename FloatType>
FloatImpl<FloatType>& FloatImpl<FloatType>::inf_neg() 
{
  static FloatImpl<FloatType> lValue(-std::numeric_limits<FloatType>::infinity());
  return lValue;
}


template<>
int FloatImpl<float>::max_precision() 
{
  return 7;
}


template<>
int FloatImpl<double>::max_precision() 
{
  return 16;
}


template <typename FloatType>
bool FloatImpl<FloatType>::parseString(const char* aCharStar, FloatImpl& aFloatImpl) 
{
#ifdef ZORBA_NUMERIC_OPTIMIZATION
  FloatImpl *hashed_float;
  if(parsed_floats.get(aCharStar, hashed_float))
  {
    //found in hash
    aFloatImpl = *hashed_float;
    return true;
  }
#endif

  const char* lCur = aCharStar;

  bool lGotBase = false;
  bool lGotPoint = false;
  bool lGotSign = false;
  bool lGotDigit = false;
  bool lStop = false;
  int  signif_digits = 0;
  int  trailing_zero = 0;

  char ch = *lCur;

  // Skip leading space
  while (ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n')
  {
    ++lCur;
    ch = *lCur;
  }

  aCharStar = lCur;

  while (!lStop && *lCur != 0) 
  {
    ch = *lCur;
    
    switch(ch) 
    {
    case '+': 
    {
      if(lGotSign || lGotDigit) 
      {
        lStop = true;
      }
      else 
      {
        lGotSign = true;
      }
      break;
    }
             
    case '-': 
    {
      if (lGotSign || lGotDigit)
      {
        lStop = true;
      }
      else 
      {
        lGotSign = true;
      }
      break;
    }
             
    case 'E':
    case 'e': 
    {
      if(!lGotDigit || lGotBase) 
      {
        lStop = true;
      }
      else
      {
        lGotPoint = false;
        lGotSign = false; 
        lGotBase = true;
        lGotDigit = false;
      }
      break;
    }
             
    case '.': 
    {
      if (lGotPoint || lGotBase) 
      {
        lStop = true;
      }
      else
      {
        lGotPoint = true;
      }
      break;
    }
             
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9': 
    {
      if(!lGotBase)
      {
        if(ch == '0')
        {
          trailing_zero++;
        }
        else
        {
          if (signif_digits)
            signif_digits = signif_digits + 1 + trailing_zero;
          else
            signif_digits++;

          trailing_zero = 0;
        }
      }

      lGotDigit = true;
      break;
    }
             
    case ' ':
    case '\t':
    case '\n':
    case '\r':
    {
      // Skip trailing space
      while(ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n') 
      {
        ++lCur;
        ch = *lCur;
      }
      
      if (*lCur != 0)
      {
        lStop = true;
      }
      else
      {
        lCur--;
      }

      break;
    }

    default:
      lStop = true;
      break;
    }

    lCur++;
  }

  if (!lGotDigit || lStop) 
  {
    if (!parseInfNaNString(aCharStar, aFloatImpl)) 
    {
      return false;
    }
  }
  else 
  {
    aFloatImpl.theFloating = (FloatType)atof(aCharStar);
  }

  if (signif_digits < max_precision())
    aFloatImpl.precision = signif_digits;

#ifdef ZORBA_NUMERIC_OPTIMIZATION
  hashed_float = new FloatImpl<FloatType>(aFloatImpl);
  const char* dup_str = _strdup(aCharStar);
  parsed_floats.insert(dup_str, hashed_float);
#endif

  return true;
}


template <typename FloatType>
bool FloatImpl<FloatType>::parseInfNaNString(const char* str, FloatImpl& result) 
{
  if (strncmp(str, "INF", 3) == 0)
  {
    result.theFloating = FloatImpl<FloatType>::inf_pos().theFloating;
    str += 3;
  }
  else if (strncmp(str, "-INF", 4) == 0)
  {
    result.theFloating = FloatImpl<FloatType>::inf_neg().theFloating;
    str += 4;
  }
  else if (strncmp(str, "NaN", 3) == 0 )
  {
    result.theFloating = FloatImpl<FloatType>::nan().theFloating;
    str += 3;
  }
  else
  {
    return false;
  }

  char ch = *str;

  // Skip trailing space
  while (ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n')
  {
    ++str;
    ch = *str;
  }

  if (ch != '\0')
    return false;

  return true;
}


template <typename FloatType>
FloatImpl<FloatType> FloatImpl<FloatType>::parseFloatType(FloatType aFloatImpl)
{
  FloatImpl<FloatType> lFloating(aFloatImpl);
  return lFloating;
}


template <typename FloatType>
FloatImpl<FloatType> FloatImpl<FloatType>::parseDecimal(const Decimal& aDecimal)
{
  FloatImpl<FloatType> lFloat;
  zstring decimal_string = aDecimal.toString();
  parseString(decimal_string.c_str(), lFloat);
  return lFloat;
}


template <typename FloatType>
FloatImpl<FloatType> FloatImpl<FloatType>::parseInteger(const Integer& aInteger)
{
  FloatImpl<FloatType> lFloat;
  zstring integer_string = aInteger.toString();
  parseString(integer_string.c_str(), lFloat);
  return lFloat;
}


template <typename FloatType>
FloatImpl<FloatType> FloatImpl<FloatType>::parseULong(uint64_t aLong) 
{
  FloatImpl<FloatType> lFloating(static_cast<FloatType>(aLong));
  return lFloating;
}


template <typename FloatType>
FloatImpl<FloatType> FloatImpl<FloatType>::parseLong(int64_t aLong) 
{
  FloatImpl<FloatType> lFloating(static_cast<FloatType>(aLong));
  return lFloating;
}


template <typename FloatType>
FloatImpl<FloatType> FloatImpl<FloatType>::parseInt(int32_t aInt) 
{
  FloatImpl<FloatType> lFloating((FloatType)aInt);
  return lFloating;
}


template <typename FloatType>
FloatImpl<FloatType> FloatImpl<FloatType>::parseUInt(uint32_t aInt) 
{
  FloatImpl<FloatType> lFloating((FloatType)aInt);
  return lFloating;
}


template <typename FloatType>
void FloatImpl<FloatType>::serialize(::zorba::serialization::Archiver& ar)
{
  ar & theFloating;
  ar & precision;
}


template <typename FloatType>
FloatImpl<FloatType> FloatImpl<FloatType>::operator+(const FloatImpl& aFloatImpl) const
{
  FloatImpl lFloatImpl(theFloating + aFloatImpl.theFloating);
  return lFloatImpl;
}


template <typename FloatType>
FloatImpl<FloatType> FloatImpl<FloatType>::operator-(const FloatImpl& aFloatImpl) const
{
  FloatImpl lFloatImpl(theFloating - aFloatImpl.theFloating);
  return lFloatImpl;
}


template <typename FloatType>
FloatImpl<FloatType> FloatImpl<FloatType>::operator*(const FloatImpl& aFloatImpl) const
{
  FloatImpl lFloatImpl(theFloating * aFloatImpl.theFloating);
  return lFloatImpl;
}


template <typename FloatType>
FloatImpl<FloatType> FloatImpl<FloatType>::operator/(const FloatImpl& aFloatImpl) const
{
  FloatImpl lFloatImpl(theFloating / aFloatImpl.theFloating);
  return lFloatImpl;
}


template <typename FloatType>
FloatImpl<FloatType> FloatImpl<FloatType>::operator%(const FloatImpl& aFloatImpl) const
{
  FloatImpl lFloatImpl(::fmod(theFloating, aFloatImpl.theFloating));
  return lFloatImpl;
}

template <typename FloatType>
FloatImpl<FloatType> FloatImpl<FloatType>::operator-() const{
  FloatImpl lFloatImpl(-theFloating);
  lFloatImpl.precision = precision;
  return lFloatImpl;
}


template <typename FloatType>
FloatImpl<FloatType> FloatImpl<FloatType>::floor() const 
{ 
  FloatImpl lFloatImpl(::floor(theFloating));
  return lFloatImpl;
}


template <typename FloatType>
FloatImpl<FloatType> FloatImpl<FloatType>::ceil() const 
{ 
  FloatImpl lFloatImpl(::ceil(theFloating));
  return lFloatImpl;
}


template <typename FloatType>
FloatImpl<FloatType> FloatImpl<FloatType>::round() const
{
  return round(Integer::parseInt(0));
}


template <typename FloatType>
FloatImpl<FloatType> FloatImpl<FloatType>::round(Integer aPrecision) const
{
  FloatImpl lFloatImpl;
  if (isFinite() && !isZero())
  {
#ifndef ZORBA_NO_BIGNUMBERS
    MAPM mapmval = Decimal::round(theFloating, aPrecision.theInteger);
    if(IS_NEGATIVE(theFloating) && IS_ZERO(mapmval))
      lFloatImpl = zero_neg();
    else
    {
      char  strval[200];
      mapmval.toString(strval, ZORBA_FLOAT_POINT_PRECISION);
      parseString(strval, lFloatImpl);
    }
#else
    lFloatImpl.theFloating = Decimal::round(theFloating, aPrecision.theInteger);
#endif
  }
  else 
  {
    lFloatImpl.theFloating = theFloating;
  }
  return lFloatImpl;
}

template <typename FloatType>
FloatImpl<FloatType> FloatImpl<FloatType>::roundHalfToEven(Integer aPrecision) const
{
  FloatImpl lFloatImpl;
  if (isFinite() && !isZero())
  {
#ifndef ZORBA_NO_BIGNUMBERS
    MAPM mapmval = Decimal::roundHalfToEven(theFloating, aPrecision.theInteger);
    if(IS_NEGATIVE(theFloating) && IS_ZERO(mapmval))
      lFloatImpl = zero_neg();
    else
    {
      char  strval[200];
      mapmval.toString(strval, ZORBA_FLOAT_POINT_PRECISION);
      parseString(strval, lFloatImpl);
    }
#else
    lFloatImpl.theFloating = Decimal::roundHalfToEven(theFloating, aPrecision.theInteger);
#endif
  }
  else 
  {
    lFloatImpl.theFloating = theFloating;
  }
  return lFloatImpl;
}


template <typename FloatType>
bool FloatImpl<FloatType>::isNaN() const
{
  return theFloating != theFloating;
}


template <typename FloatType>
bool FloatImpl<FloatType>::isFinite() const
{
  return !isNaN() && !isPosInf() && !isNegInf();
}


template <typename FloatType>
bool FloatImpl<FloatType>::isPosInf() const
{
  return theFloating == std::numeric_limits<FloatType>::infinity();
}


template <typename FloatType>
bool FloatImpl<FloatType>::isNegInf() const
{
 if (theFloating == -std::numeric_limits<FloatType>::infinity())
   return true;
 else
   return false;
}


template <typename FloatType>
bool FloatImpl<FloatType>::isNeg() const
{
  return theFloating < 0;
}


template <typename FloatType>
bool FloatImpl<FloatType>::isPos() const
{
  return theFloating > 0;
}


template <typename FloatType>
bool FloatImpl<FloatType>::isZero() const
{
  return theFloating == 0;
}


template <typename FloatType>
bool FloatImpl<FloatType>::isPosZero() const
{
  return theFloating == 0 && !isNegZero();
}


template <>
bool FloatImpl<double>::isNegZero() const
{
  if(theFloating == 0) 
  {
    unsigned char *byteaccess = (unsigned char *)&theFloating;
    if(byteaccess[0] || byteaccess[7])//test for little endian and big endian
      return true;
    else
      return false;
  }
  else
    return false;
}


template <>
bool FloatImpl<float>::isNegZero() const
{
  if(theFloating == 0)
  {
    unsigned char *byteaccess = (unsigned char *)&theFloating;
    if(byteaccess[0] || byteaccess[3])//test for little endian and big endian
      return true;
    else
      return false;
  }
  else
    return false;
}


template <typename FloatType>
uint32_t FloatImpl<FloatType>::hash() const
{
  return static_cast<uint32_t>(theFloating);
}


template <typename FloatType>
bool FloatImpl<FloatType>::operator==(const FloatImpl& aFloatImpl) const
{
  return theFloating == aFloatImpl.theFloating;
}


template <typename FloatType>
FloatImpl<FloatType> FloatImpl<FloatType>::sqrt() const
{
  if (*this < zero())
    return nan();
  return FloatImpl (::sqrt(theFloating));
}


template <typename FloatType>
FloatImpl<FloatType> FloatImpl<FloatType>::pow(FloatImpl<FloatType> p) const
{
  if(!p.isNaN())
    return FloatImpl (::pow(theFloating, p.theFloating));
  else
    return FloatImpl(theFloating);
}

template <typename FloatType>
FloatImpl<FloatType> FloatImpl<FloatType>::pow(int p) const
{
  return FloatImpl (::pow(theFloating, p));
}


template <typename FloatType>
FloatImpl<FloatType> FloatImpl<FloatType>::fmod(FloatImpl<FloatType> p) const
{
  return FloatImpl (::fmod(theFloating, p.theFloating));
}


template <typename FloatType>
void FloatImpl<FloatType>::frexp(FloatImpl<FloatType> &out_mantissa, Integer &out_exponent) const
{
  int expint;
  out_mantissa = FloatImpl (::frexp(theFloating, &expint));
  out_exponent = Integer(expint);
}


template <>
void FloatImpl<double>::modf(FloatImpl<double> &out_fraction, FloatImpl<double> &out_integer) const
{
  double int_part;
  out_fraction = FloatImpl (::modf(theFloating, &int_part));
  out_integer = FloatImpl(int_part);
}


template <>
void FloatImpl<float>::modf(FloatImpl<float> &out_fraction, FloatImpl<float> &out_integer) const
{
  float int_part;
  out_fraction = FloatImpl (::modff(theFloating, &int_part));
  out_integer = FloatImpl(int_part);
}


#define PASSTHRU( fn )                                    \
  template <typename FloatType>                           \
  FloatImpl<FloatType> FloatImpl<FloatType>::fn() const   \
{ return FloatImpl (::fn(theFloating)); }


template <typename FloatType>
FloatImpl<FloatType> FloatImpl<FloatType>::log() const
{
  if (*this < zero())
    return nan();
  return FloatImpl (::log(theFloating));
}


template <typename FloatType>
FloatImpl<FloatType> FloatImpl<FloatType>::log10() const
{
  if (*this < zero())
    return nan();
  return FloatImpl (::log10(theFloating));
}

template <typename FloatType>
FloatImpl<FloatType> FloatImpl<FloatType>::exp10() const
{
  return FloatImpl (::pow(10, theFloating));
}


template <typename FloatType>
FloatImpl<FloatType> FloatImpl<FloatType>::asin() const
{
  if (*this < one_neg() || *this > one())
    return nan();
  return FloatImpl (::asin(theFloating));
}


template <typename FloatType>
FloatImpl<FloatType> FloatImpl<FloatType>::acos() const
{
  if (*this < one_neg() || *this > one())
    return nan();
  if(!isNegZero())
    return FloatImpl (::acos(theFloating));
  else
    return FloatImpl (-::acos(theFloating));
}


template <typename FloatType>
FloatImpl<FloatType> FloatImpl<FloatType>::atan2(FloatImpl<FloatType> x) const
{
  return FloatImpl (::atan2(theFloating, x.theFloating));
}


PASSTHRU (exp)
PASSTHRU (sin)
PASSTHRU (cos)
PASSTHRU (tan)
PASSTHRU (atan)
PASSTHRU (sinh)
PASSTHRU (cosh)
PASSTHRU (tanh)
PASSTHRU (asinh)
PASSTHRU (acosh)
PASSTHRU (atanh)


template <typename FloatType>
bool FloatImpl<FloatType>::operator!=(const FloatImpl& aFloatImpl) const
{
  return !(*this == aFloatImpl);
}


template <typename FloatType>
bool FloatImpl<FloatType>::operator<(const FloatImpl& aFloatImpl) const
{
  return theFloating < aFloatImpl.theFloating;
} 


template <typename FloatType>
bool FloatImpl<FloatType>::operator<=(const FloatImpl& aFloatImpl) const
{
  if(isNaN() || aFloatImpl.isNaN())
    return false;
  else
    return !(*this > aFloatImpl);
}


template <typename FloatType>
bool FloatImpl<FloatType>::operator>(const FloatImpl& aFloatImpl) const
{
  return theFloating > aFloatImpl.theFloating;
}


template <typename FloatType>
bool FloatImpl<FloatType>::operator>=(const FloatImpl& aFloatImpl) const
{
  if(isNaN() || aFloatImpl.isNaN())
    return false;
  else
    return !(*this < aFloatImpl);
}


template <typename FloatType>
zstring FloatImpl<FloatType>::toIntegerString() const 
{
  if (isNaN()) 
  {
    return FloatCommons::get_NOT_A_NUM_STR();
  }
  else if (isPosInf()) 
  {
    return FloatCommons::get_INF_POS_STR();
  }
  else if (isNegInf()) 
  {
    return FloatCommons::get_INF_NEG_STR();
  }
  else if (isPosZero()) 
  {
    return "0";
  }
  else if (isNegZero()) 
  {
    return "-0";
  }

  char lBuffer[174];
  sprintf(lBuffer, "%d", (int)theFloating);

  return lBuffer;
}


template <typename FloatType>
zstring FloatImpl<FloatType>::toString(bool no_scientific_format) const 
{
  if (isNaN()) 
  {
    return FloatCommons::get_NOT_A_NUM_STR();
  }
  else if (isPosInf()) 
  {
    return FloatCommons::get_INF_POS_STR();
  }
  else if (isNegInf()) 
  {
    return FloatCommons::get_INF_NEG_STR();
  }
  else if (isPosZero()) 
  {
    return "0";
  }
  else if (isNegZero()) 
  {
    return "-0";
  }

  FloatType absVal = fabs(theFloating);
  FloatType lower = 0.000001f, upper = 1000000.0f;

  if (no_scientific_format || (absVal < upper && absVal >= lower) || absVal == 0) 
  {
#if 1
    // This is the "spec" implementation, i.e., it is an exact application of
    // the spec in  http://www.w3.org/TR/xpath-functions/#casting
    MAPM  decimal_mapm = theFloating;
#ifndef ZORBA_NO_BIGNUMBERS
    decimal_mapm = decimal_mapm.round(precision);
#endif
    return Decimal::decimalToString(decimal_mapm, max_precision());
#else
    std::stringstream stream;
    stream.precision(7);
    stream.setf(std::ios::fixed);
    stream << theFloating;

    zstring result(stream.str());

    // remove non-significant trailing 0's
    long i = result.size() - 1;
    while (str[i] == '0')
      --i;

    if (i >= 0)
    {
      long j = i;
      while (str[j] != '.')
        --j;

      if (j >= 0)
      {
        if (j == i)
        {
          result.resize(i);
        }
        else
        {
          result.resize(i+1);
        }
      }
    }

    return result;
#endif
  }
  else
  {
    char lBuffer[174];
    char strformat[10];
    sprintf(strformat, "%%#1.%dE", precision);
    sprintf(lBuffer, strformat, (double)theFloating);
    //write_to_string(lBuffer, theFloating);

    char* lE = strchr(lBuffer, 'E');
    char* lZeros;

    if(lE)
      lZeros = lE-1;
    else
      lZeros = lBuffer + strlen(lBuffer) - 1;

    while(*lZeros == '0') 
      --lZeros; 

    if (lE)
    {
      if(*lZeros == '.')
        ++lZeros;

      lZeros[1] = 'E';
      lE++;

      if(*lE == '+')
        lE++;

      else if(*lE == '-')
      {
        lZeros++;
        lZeros[1] = '-';
        lE++;
      }

      while(*lE == '0')
        lE++;

      strcpy(lZeros+2, lE);
    }
    else
    {
      if(*lZeros == '.')
        lZeros--;
      lZeros[1] = 0;
    }

    Decimal::reduceFloatingPointString(lBuffer);
    return lBuffer;
  }
}

template class FloatImpl<double>;
template class FloatImpl<float>;


std::ostream& operator<<(std::ostream& os, const Double& aDouble) 
{
  os << aDouble.toString();
  return os;
}


std::ostream& operator<<(std::ostream& os, const Float& aFloat) 
{
  os << aFloat.toString();
  return os;
}


Double operator+(const Double& aDouble, const Float& aFloat) 
{
  return aDouble + FloatCommons::parseFloat(aFloat);   
}


Double operator+(const Float& aFloat, const Double& aDouble) 
{
  return FloatCommons::parseFloat(aFloat) + aDouble;
}


Double operator-(const Double& aDouble, const Float& aFloat) 
{
  return aDouble - FloatCommons::parseFloat(aFloat);   
}


Double operator-(const Float& aFloat, const Double& aDouble) 
{
  return FloatCommons::parseFloat(aFloat) - aDouble;
}


Double operator*(const Double& aDouble, const Float& aFloat) 
{
  return aDouble * FloatCommons::parseFloat(aFloat);   
}


Double operator*(const Float& aFloat, const Double& aDouble) 
{
  return FloatCommons::parseFloat(aFloat) * aDouble;
}


Double operator/(const Double& aDouble, const Float& aFloat) 
{
  return aDouble / FloatCommons::parseFloat(aFloat);   
}


Double operator/(const Float& aFloat, const Double& aDouble) 
{
  return FloatCommons::parseFloat(aFloat) / aDouble;
}

Double operator%(const Double& aDouble, const Float& aFloat) 
{
  return aDouble % FloatCommons::parseFloat(aFloat);   
}


Double operator%(const Float& aFloat, const Double& aDouble) 
{
  return FloatCommons::parseFloat(aFloat) % aDouble;
}

#ifdef WIN32
// exported for testing only
template class ZORBA_DLL_PUBLIC FloatImpl<double>;
template class ZORBA_DLL_PUBLIC FloatImpl<float>;
#endif

}
