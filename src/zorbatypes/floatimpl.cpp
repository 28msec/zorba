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

#include "common/common.h"
#include "zorbatypes/floatimpl.h"
#include "zorbatypes/integer.h"
#include "zorbatypes/decimal.h"
#include "zorbatypes/numconversions.h"

/*
#if defined WIN32 || defined WIN_CE
  #define   _fpclass   __fpclass
#else
//#define FP_NAN         0
//#define FP_INFINITE    1
//#define FP_ZERO        2
//#define FP_SUBNORMAL   3
//#define FP_NORMAL      4

#define _FPCLASS_SNAN      FP_NAN  // Signaling NaN
#define _FPCLASS_QNAN      -1      // Quiet NaN
#define _FPCLASS_NINF      FP_INFINITE // Negative infinity ( –INF)
_FPCLASS_NN:// Negative normalized non-zero
    case _FPCLASS_ND:// Negative denormalized
      return FloatCommons::NORMAL_NEG;
    case _FPCLASS_NZ:// Negative zero ( – 0)
    case _FPCLASS_PZ:// Positive 0 (+0)
    case _FPCLASS_PD:// Positive denormalized
    case _FPCLASS_PN:// Positive normalized non-zero
      return FloatCommons::NORMAL;
    case _FPCLASS_PINF:// Positive infinity (+INF)
     return FloatCommons::INF_POS;
#endif
*/

namespace zorba {

const xqpString& FloatCommons::get_INF_POS_STR()
{
   static const xqpString INF_POS_STR = "INF";
   return INF_POS_STR;
}


const xqpString& FloatCommons::get_INF_NEG_STR()
{
   static const xqpString INF_NEG_STR = "-INF";
   return INF_NEG_STR;
}


const xqpString& FloatCommons::get_NOT_A_NUM_STR()
{
   static const xqpString NOT_A_NUM_STR = "NaN";
   return NOT_A_NUM_STR;
}


Double FloatCommons::parseFloat(const Float& aFloat) {
  Double lDouble(aFloat.getType(), aFloat.getNumber());
  return lDouble;
}

Float FloatCommons::parseDouble(const Double& aDouble) {
  Float lFloat(aDouble.getType(), aDouble.getNumber());
  FloatImpl<float>::checkInfZeroPrecision(lFloat);
  return lFloat;
}

#ifndef ZORBA_NO_BIGNUMBERS

bool FloatImplTraits<double>::isPosInf(MAPM aMAPM) {
  if (aMAPM > 0) {
    return aMAPM.exponent() > 308 || aMAPM > MAPM("1.7976931348623157e+308");
  } else {
    return false;
  }
}

bool FloatImplTraits<double>::isZero(MAPM aMAPM) { 
  int lExp = aMAPM.exponent();
  return lExp < -308 || (lExp == -308 && aMAPM.abs() < MAPM("2.2250738585072014e-308"));
}

bool FloatImplTraits<double>::isNegInf(MAPM aMAPM) { 
  if (aMAPM < 0) {
    return aMAPM.exponent() > 308 || aMAPM.abs() > MAPM("1.7976931348623157e+308");
  } else {
    return false;
  }
}

// FIXME this is not yet correct! Just a very simple temporary solution.
MAPM FloatImplTraits<double>::cutMantissa(MAPM aMAPM) {
  return Decimal::round(aMAPM, 16-aMAPM.exponent());
}

uint32_t FloatImplTraits<double>::hash(FloatCommons::NumType aType, MAPM aMAPM) {
  if (aType == FloatCommons::INF_POS 
   || aType == FloatCommons::INF_NEG
   || aType == FloatCommons::NOT_A_NUM)
  {
    return 0;
  }

  Double lDouble(aType, aMAPM % 65535);
  if (lDouble < Double::zero())
    lDouble = -lDouble;
  Integer lInteger;
  Integer::parseDouble(lDouble, lInteger);
  uint32_t lHash;
  NumConversions::integerToUInt(lInteger, lHash);
  return lHash;
}
  
bool FloatImplTraits<float>::isPosInf(MAPM aMAPM) {
  if (aMAPM > 0) {
    return aMAPM.exponent() > 38 || aMAPM > MAPM("3.4028235e+38");
  } else {
    return false;
  }
}

bool FloatImplTraits<float>::isZero(MAPM aMAPM) { 
  int lExp = aMAPM.exponent();
  return lExp < -38 || (lExp == -38 && aMAPM.abs() < MAPM("1.1754944e-38"));
}

bool FloatImplTraits<float>::isNegInf(MAPM aMAPM) { 
  if (aMAPM < 0) {
    return aMAPM.exponent() > 38 || aMAPM.abs() > MAPM("3.4028235e+38");
  } else {
    return false;
  }
}


// FIXME this is not yet correct! Just a very simple temporary solution.
MAPM FloatImplTraits<float>::cutMantissa(MAPM aMAPM) {
  return Decimal::round(aMAPM, 7-aMAPM.exponent());
}


uint32_t FloatImplTraits<float>::hash(FloatCommons::NumType aType, MAPM aMAPM) {
  if (aType == FloatCommons::INF_POS 
   || aType == FloatCommons::INF_NEG
   || aType == FloatCommons::NOT_A_NUM)
  {
    return 0;
  }

  Float lFloat(aType, aMAPM % 65535);
  if (lFloat < Float::zero())
    lFloat = -lFloat;
  Integer lInteger;
  Integer::parseFloat(lFloat, lInteger);
  uint32_t lHash;
  NumConversions::integerToUInt(lInteger, lHash);
  return lHash;
}

#else

template <typename FloatType>
bool FloatImplTraits<FloatType>::isPosInf(FloatType aMAPM)
{
#if defined WIN32 || defined WIN_CE
  int fclass;
  fclass = _fpclass(aMAPM);
  if(fclass == _FPCLASS_PINF)
    return true;
  else
    return false;
#else
  if(!isfinite(aMAPM) && !isnan(aMAPM) && (aMAPM>0))
    return true;
  else
    return false;
#endif
}


template <typename FloatType>
bool FloatImplTraits<FloatType>::isZero(FloatType aMAPM)
{
  return false;
/*
#if defined WIN32 || defined WIN_CE
  int fclass;
  fclass = _fpclass(aMAPM);
  if((fclass == _FPCLASS_NZ) || (fclass == _FPCLASS_PZ))
    return true;
  else
    return false;
#else
  if(aMAPM == 0)
    return true;
  else
    return false;
#endif
*/
}


template <typename FloatType>
bool FloatImplTraits<FloatType>::isNegInf(FloatType aMAPM)
{
#if defined WIN32 || defined WIN_CE
  int fclass;
  fclass = _fpclass(aMAPM);
  if(fclass == _FPCLASS_NINF)
    return true;
  else
    return false;
#else
  if(!isfinite(aMAPM) && !isnan(aMAPM) && (aMAPM<0))
    return true;
  else
    return false;
#endif
}


template <typename FloatType>
FloatType FloatImplTraits<FloatType>::cutMantissa(FloatType aMAPM) 
{
  return aMAPM;
}


template <typename FloatType>
uint32_t FloatImplTraits<FloatType>::hash(FloatCommons::NumType aType, FloatType aMAPM)
{
  if (aType == FloatCommons::INF_POS 
   || aType == FloatCommons::INF_NEG
   || aType == FloatCommons::NOT_A_NUM)
  {
    return 0;
  }

  return ((uint32_t)aMAPM) % 65535;
}

#endif


template <typename FloatType>
FloatImpl<FloatType>& FloatImpl<FloatType>::zero() {
  static FloatImpl<FloatType> lValue(FloatCommons::NORMAL, MAPM(0));
  return lValue;
}

template <typename FloatType>
FloatImpl<FloatType>& FloatImpl<FloatType>::zero_neg() {
  static FloatImpl<FloatType> lValue(FloatCommons::NORMAL_NEG, MAPM(0));
  return lValue;
}

template <typename FloatType>
FloatImpl<FloatType>& FloatImpl<FloatType>::nan() {
  static FloatImpl<FloatType> lValue(FloatCommons::NOT_A_NUM, MAPM(0));
  return lValue;
}

template <typename FloatType>
FloatImpl<FloatType>& FloatImpl<FloatType>::inf_pos() {
  static FloatImpl<FloatType> lValue(FloatCommons::INF_POS, MAPM(0));
  return lValue;
}

template <typename FloatType>
FloatImpl<FloatType>& FloatImpl<FloatType>::inf_neg() {
  static FloatImpl<FloatType> lValue(FloatCommons::INF_NEG, MAPM(0));
  return lValue;
}

template <typename FloatType>
void FloatImpl<FloatType>::checkInfZeroPrecision(FloatImpl& aFloatImpl) {
  if (aFloatImpl.theType == FloatCommons::NORMAL || aFloatImpl.theType == FloatCommons::NORMAL_NEG) {
    aFloatImpl.theFloatImpl = FloatImplTraits<FloatType>::cutMantissa(aFloatImpl.theFloatImpl);
    if (FloatImplTraits<FloatType>::isPosInf(aFloatImpl.theFloatImpl)) {
      aFloatImpl.theType = FloatCommons::INF_POS;
      aFloatImpl.theFloatImpl = 0;
    } else if (FloatImplTraits<FloatType>::isNegInf(aFloatImpl.theFloatImpl)) {
      aFloatImpl.theType = FloatCommons::INF_NEG;
      aFloatImpl.theFloatImpl = 0;
    } else if (FloatImplTraits<FloatType>::isZero(aFloatImpl.theFloatImpl)) {
      aFloatImpl.theType = FloatCommons::NORMAL;
      aFloatImpl.theFloatImpl = 0;
    }
  }
}

template <typename FloatType>
FloatCommons::NumType FloatImpl<FloatType>::checkInfNaNNeg(const char* aCharStar) {
#if defined (ZORBA_HAVE_STRCASECMP_FUNCTION) && (! defined (WIN32) )
    if (strcasecmp(aCharStar, "inf") == 0 || strcasecmp(aCharStar, "+inf") == 0 )
#else
    if (_stricmp(aCharStar, "inf") == 0 || _stricmp(aCharStar, "+inf") == 0 )
#endif
    {
      return FloatCommons::INF_POS;
    }
#if defined (ZORBA_HAVE_STRCASECMP_FUNCTION) && (! defined (WIN32) )
    else if (strcasecmp(aCharStar, "-inf") == 0 )
#else
    else if (_stricmp(aCharStar, "-inf") == 0 )
#endif
    {
      return FloatCommons::INF_NEG;
    }
#if defined (ZORBA_HAVE_STRCASECMP_FUNCTION) && (! defined (WIN32) )
    else if (strcasecmp(aCharStar, "nan") == 0 )
#else
    else if (_stricmp(aCharStar, "nan") == 0 )
#endif
    {
      return FloatCommons::NOT_A_NUM;
    }
    else if (aCharStar[0] == '-') 
    {
      return FloatCommons::NORMAL_NEG;
    }  
    else
    {
      return FloatCommons::NORMAL;
    }
}

template <typename FloatType>
FloatCommons::NumType FloatImpl<FloatType>::checkInfNaNNeg(FloatType aFloat) {
#ifndef ZORBA_NO_BIGNUMBERS
  if (aFloat != aFloat) {
    return FloatCommons::NOT_A_NUM;
  } else if (aFloat == std::numeric_limits<FloatType>::infinity()) {
    return FloatCommons::INF_POS;
  } else if (aFloat == -std::numeric_limits<FloatType>::infinity()) {
    return FloatCommons::INF_NEG;
  } else if (aFloat < 0) {
    return FloatCommons::NORMAL_NEG;
  } else {
    return FloatCommons::NORMAL;
  }
#else
#if !defined WIN32 && !defined WIN_CE
  if(finite(aFloat))
    if(aFloat >= 0)
      return FloatCommons::NORMAL;
    else
      return FloatCommons::NORMAL_NEG;

  if(isnan(aFloat))
    return FloatCommons::NOT_A_NUM;

  if(aFloat > 0)
    return FloatCommons::INF_POS;
  else
    return FloatCommons::INF_NEG;
#else
  int fclass;
  fclass = _fpclass(aFloat);
  switch(fclass)
  {
    case _FPCLASS_SNAN:// Signaling NaN
    case _FPCLASS_QNAN:// Quiet NaN
      return FloatCommons::NOT_A_NUM;
    case _FPCLASS_NINF:// Negative infinity ( –INF)
      return FloatCommons::INF_NEG;
    case _FPCLASS_NN:// Negative normalized non-zero
    case _FPCLASS_ND:// Negative denormalized
      return FloatCommons::NORMAL_NEG;
    case _FPCLASS_NZ:// Negative zero ( – 0)
    case _FPCLASS_PZ:// Positive 0 (+0)
    case _FPCLASS_PD:// Positive denormalized
    case _FPCLASS_PN:// Positive normalized non-zero
      return FloatCommons::NORMAL;
    case _FPCLASS_PINF:// Positive infinity (+INF)
     return FloatCommons::INF_POS;
    default:
      return FloatCommons::NORMAL;
  };
#endif//WIN32
#endif
}

template <typename FloatType>
bool FloatImpl<FloatType>::parseString(const char* aCharStar, FloatImpl& aFloatImpl) {
  const char* lCur = aCharStar;

  bool lGotBase = false;
  bool lGotPoint = false;
  bool lGotSign = false;
  bool lGotDigit = false;
  bool lStop = false;
  bool lIsNegative = false;

  char lTmp;
  while(!lStop && *lCur != 0) {
    lTmp = *lCur++;
    
    switch(lTmp) {

    case '+': {
      if(lGotSign || lGotDigit) {
        lStop = true;
      } else {
        lGotSign = true;
      }
      break;
    }
             
    case '-': {
      if(lGotSign || lGotSign) {
        lStop = true;
      } else {
        lGotSign = true;
        if(!lGotBase) lIsNegative = true;
      }
      break;
    }
             
    case 'E':
    case 'e': {
      if(!lGotDigit || lGotBase) {
        lStop = true;
      } else {
        lGotPoint = false;
        lGotSign = false;        
        lGotBase = true;
        lGotDigit = false;
      }
      break;
    }
             
    case '.': {
      if(lGotPoint || lGotBase) {
        lStop = true;
      } else {
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
    case '9': {
      lGotDigit = true;
      break;
    }
             
    default:
      lStop = true;
      break;
             
    }
  }

  FloatCommons::NumType lType;
  MAPM lNumber = 0;

  if(!lGotDigit || lStop) {
    switch(lType = checkInfNaNNeg(aCharStar)) {
    case FloatCommons::INF_NEG:
    case FloatCommons::NOT_A_NUM:
    case FloatCommons::INF_POS:
      break;
    default:
      return false;
      break;
    }
  } else {
#ifndef ZORBA_NO_BIGNUMBERS
    lNumber = aCharStar;
#else
    lNumber = atof(aCharStar);
#endif
    if (lIsNegative) {
      lType = FloatCommons::NORMAL_NEG;
    } else {
      lType = FloatCommons::NORMAL;
    }
  }

  aFloatImpl.theType = lType;
  aFloatImpl.theFloatImpl = lNumber;

  checkInfZeroPrecision(aFloatImpl);
  return true;




}

template <typename FloatType>
FloatImpl<FloatType> FloatImpl<FloatType>::parseFloatType(FloatType aFloatImpl){
  FloatImpl<FloatType> lFloating;
  switch(lFloating.theType = checkInfNaNNeg(aFloatImpl)) {
    case FloatCommons::INF_NEG:
    case FloatCommons::NOT_A_NUM:
    case FloatCommons::INF_POS:
      lFloating.theFloatImpl = 0;
      break;
    case FloatCommons::NORMAL_NEG:
    case FloatCommons::NORMAL:
      lFloating.theFloatImpl = aFloatImpl;
      break;
  }
  return lFloating;
}

template <typename FloatType>
FloatImpl<FloatType> FloatImpl<FloatType>::parseInt(int32_t aInt) {
  FloatImpl<FloatType> lFloating;
  lFloating.theType = ( aInt < 0 ? FloatCommons::NORMAL_NEG : FloatCommons::NORMAL );
  lFloating.theFloatImpl = aInt;
  return lFloating;
}

template <typename FloatType>
FloatImpl<FloatType> FloatImpl<FloatType>::parseLong(long aLong) {
  FloatImpl<FloatType> lFloating;
  lFloating.theType = ( aLong < 0 ? FloatCommons::NORMAL_NEG : FloatCommons::NORMAL );
  lFloating.theFloatImpl = aLong;
  return lFloating;
}

template <typename FloatType>
FloatImpl<FloatType> FloatImpl<FloatType>::parseDecimal(const Decimal& aDecimal)
{
  FloatImpl<FloatType> lFloat;
  lFloat.theFloatImpl = aDecimal.theDecimal; 
  lFloat.theType 
    = ( lFloat.theFloatImpl >= 0 ? FloatCommons::NORMAL : FloatCommons::NORMAL_NEG);
  checkInfZeroPrecision(lFloat);
  return lFloat;
}

template <typename FloatType>
FloatImpl<FloatType> FloatImpl<FloatType>::parseInteger(const Integer& aInteger)
{
  FloatImpl<FloatType> lFloat;
  lFloat.theFloatImpl = aInteger.theInteger; 
  lFloat.theType 
    = ( lFloat.theFloatImpl >= 0 ? FloatCommons::NORMAL : FloatCommons::NORMAL_NEG);
  checkInfZeroPrecision(lFloat);
  return lFloat;
}

template <typename FloatType>
FloatImpl<FloatType> FloatImpl<FloatType>::operator+(const FloatImpl& aFloatImpl) const{
  FloatImpl lFloatImpl;
  switch(theType) {
  case FloatCommons::NOT_A_NUM:
    lFloatImpl.theType = FloatCommons::NOT_A_NUM;    
    break;
  case FloatCommons::INF_NEG:
    switch(aFloatImpl.theType) {
    case FloatCommons::NOT_A_NUM:
    case FloatCommons::INF_POS:
      lFloatImpl.theType = FloatCommons::NOT_A_NUM;    
      break;
    case FloatCommons::INF_NEG:
    case FloatCommons::NORMAL:
    case FloatCommons::NORMAL_NEG:
      lFloatImpl.theType = FloatCommons::INF_NEG;
      break;
    }
    break;
  case FloatCommons::INF_POS:
    switch(aFloatImpl.theType) {
    case FloatCommons::NOT_A_NUM:
    case FloatCommons::INF_NEG:
      lFloatImpl.theType = FloatCommons::NOT_A_NUM;    
      break;
    case FloatCommons::INF_POS:
    case FloatCommons::NORMAL:
    case FloatCommons::NORMAL_NEG:
      lFloatImpl.theType = FloatCommons::INF_POS;
      break;
    }
    break;
  case FloatCommons::NORMAL:
  case FloatCommons::NORMAL_NEG:
    switch(aFloatImpl.theType) {
    case FloatCommons::NOT_A_NUM:
      lFloatImpl.theType = FloatCommons::NOT_A_NUM;    
      break;
    case FloatCommons::INF_NEG:
      lFloatImpl.theType = FloatCommons::INF_NEG;
      break;
    case FloatCommons::INF_POS:
      lFloatImpl.theType = FloatCommons::INF_POS;
      break;
    case FloatCommons::NORMAL:
    case FloatCommons::NORMAL_NEG:
      if (theFloatImpl == 0 && aFloatImpl.theFloatImpl == 0) {
        lFloatImpl.theFloatImpl = 0;
        if (theType == aFloatImpl.theType) {
          lFloatImpl.theType = theType;
        } else {
          lFloatImpl.theType = FloatCommons::NORMAL;
        }
      } else {
        lFloatImpl.theFloatImpl = theFloatImpl + aFloatImpl.theFloatImpl;
        if (lFloatImpl.theFloatImpl < 0) {
          lFloatImpl.theType = FloatCommons::NORMAL_NEG;
        } else {
          lFloatImpl.theType = FloatCommons::NORMAL;
        }
        checkInfZeroPrecision(lFloatImpl);
      }
      break;
    }
    break;
  }
  return lFloatImpl;
}

template <typename FloatType>
FloatImpl<FloatType> FloatImpl<FloatType>::operator-(const FloatImpl& aFloatImpl) const{
  FloatImpl lFloatImpl;
  switch(theType) {
  case FloatCommons::NOT_A_NUM:
    lFloatImpl.theType = FloatCommons::NOT_A_NUM;    
    break;
  case FloatCommons::INF_NEG:
    switch(aFloatImpl.theType) {
    case FloatCommons::NOT_A_NUM:
    case FloatCommons::INF_NEG:
      lFloatImpl.theType = FloatCommons::NOT_A_NUM;    
      break;
    case FloatCommons::INF_POS:
    case FloatCommons::NORMAL:
    case FloatCommons::NORMAL_NEG:
      lFloatImpl.theType = FloatCommons::INF_NEG;
      break;
    }
    break;
  case FloatCommons::INF_POS:
    switch(aFloatImpl.theType) {
    case FloatCommons::NOT_A_NUM:
    case FloatCommons::INF_POS:
      lFloatImpl.theType = FloatCommons::NOT_A_NUM;    
      break;
    case FloatCommons::INF_NEG:
    case FloatCommons::NORMAL:
    case FloatCommons::NORMAL_NEG:
      lFloatImpl.theType = FloatCommons::INF_POS;
      break;
    }
    break;
  case FloatCommons::NORMAL:
  case FloatCommons::NORMAL_NEG:
    switch(aFloatImpl.theType) {
    case FloatCommons::NOT_A_NUM:
      lFloatImpl.theType = FloatCommons::NOT_A_NUM;    
      break;
    case FloatCommons::INF_NEG:
      lFloatImpl.theType = FloatCommons::INF_NEG;
      break;
    case FloatCommons::INF_POS:
      lFloatImpl.theType = FloatCommons::INF_POS;
      break;
    case FloatCommons::NORMAL:
    case FloatCommons::NORMAL_NEG:
      if (theFloatImpl == 0 && aFloatImpl.theFloatImpl == 0) {
        lFloatImpl.theFloatImpl = 0;
        if (theType == FloatCommons::NORMAL_NEG && aFloatImpl.theType == FloatCommons::NORMAL) {
          lFloatImpl.theType = FloatCommons::NORMAL_NEG;
        } else {
          lFloatImpl.theType = FloatCommons::NORMAL;
        }
      } else {
        lFloatImpl.theFloatImpl = theFloatImpl - aFloatImpl.theFloatImpl;
        if (lFloatImpl.theFloatImpl < 0) {
          lFloatImpl.theType = FloatCommons::NORMAL_NEG;
        } else {
          lFloatImpl.theType = FloatCommons::NORMAL;
        }
        checkInfZeroPrecision(lFloatImpl);
      }
      break;
    }
    break;
  }
  return lFloatImpl;
}

template <typename FloatType>
FloatImpl<FloatType> FloatImpl<FloatType>::operator*(const FloatImpl& aFloatImpl) const{
  FloatImpl lFloatImpl;
  switch(theType) {
  case FloatCommons::NOT_A_NUM:
    lFloatImpl.theType = FloatCommons::NOT_A_NUM;    
    break;
  case FloatCommons::INF_NEG:
    switch(aFloatImpl.theType) {
    case FloatCommons::NOT_A_NUM:
      lFloatImpl.theType = FloatCommons::NOT_A_NUM;    
      break;
    case FloatCommons::INF_NEG:
    case FloatCommons::NORMAL_NEG:
      lFloatImpl.theType = FloatCommons::INF_POS;
      break;
    case FloatCommons::INF_POS:
    case FloatCommons::NORMAL:
      lFloatImpl.theType = FloatCommons::INF_NEG;
      break;
    }
    break;
  case FloatCommons::INF_POS:
    switch(aFloatImpl.theType) {
    case FloatCommons::NOT_A_NUM:
      lFloatImpl.theType = FloatCommons::NOT_A_NUM;    
      break;
    case FloatCommons::INF_POS:
    case FloatCommons::NORMAL:
      lFloatImpl.theType = FloatCommons::INF_POS;
      break;
    case FloatCommons::NORMAL_NEG:
    case FloatCommons::INF_NEG:
      lFloatImpl.theType = FloatCommons::INF_NEG;
      break;
    }
    break;
  case FloatCommons::NORMAL:
  case FloatCommons::NORMAL_NEG:
    switch(aFloatImpl.theType) {
    case FloatCommons::NOT_A_NUM:
      lFloatImpl.theType = FloatCommons::NOT_A_NUM;    
      break;
    case FloatCommons::INF_NEG:
      lFloatImpl.theType = (isPos() ? FloatCommons::INF_NEG : FloatCommons::INF_POS);
      break;
    case FloatCommons::INF_POS:
      lFloatImpl.theType = (isNeg() ? FloatCommons::INF_POS : FloatCommons::INF_NEG);
      break;
    case FloatCommons::NORMAL:
    case FloatCommons::NORMAL_NEG:
      if (theFloatImpl == 0 || aFloatImpl.theFloatImpl == 0) {
        lFloatImpl.theFloatImpl = 0;
        if (theType == FloatCommons::NORMAL_NEG || aFloatImpl.theType == FloatCommons::NORMAL_NEG) {
          lFloatImpl.theType = FloatCommons::NORMAL_NEG;
        } else {
          lFloatImpl.theType = FloatCommons::NORMAL;
        }
      } else {
        lFloatImpl.theFloatImpl = theFloatImpl * aFloatImpl.theFloatImpl;
        if (lFloatImpl.theFloatImpl < 0) {
          lFloatImpl.theType = FloatCommons::NORMAL_NEG;
        } else {
          lFloatImpl.theType = FloatCommons::NORMAL;
        }
        checkInfZeroPrecision(lFloatImpl);
      }
      break;
    }
    break;
  }
  return lFloatImpl;
}

template <typename FloatType>
FloatImpl<FloatType> FloatImpl<FloatType>::operator/(const FloatImpl& aFloatImpl) const{
  FloatImpl lFloatImpl;
  switch(theType) {
  case FloatCommons::NOT_A_NUM:
    lFloatImpl.theType = FloatCommons::NOT_A_NUM;    
    break;
  case FloatCommons::INF_NEG:
    switch(aFloatImpl.theType) {
    case FloatCommons::NOT_A_NUM:
    case FloatCommons::INF_POS:
    case FloatCommons::INF_NEG:
      lFloatImpl.theType = FloatCommons::NOT_A_NUM;    
      break;
    case FloatCommons::NORMAL:
      lFloatImpl.theType = FloatCommons::INF_NEG;
      break;
    case FloatCommons::NORMAL_NEG:
      lFloatImpl.theType = FloatCommons::INF_POS;
      break;
    }
    break;
  case FloatCommons::INF_POS:
    switch(aFloatImpl.theType) {
    case FloatCommons::NOT_A_NUM:
    case FloatCommons::INF_POS:
    case FloatCommons::INF_NEG:
      lFloatImpl.theType = FloatCommons::NOT_A_NUM;    
      break;
    case FloatCommons::NORMAL:
      lFloatImpl.theType = FloatCommons::INF_POS;
      break;
    case FloatCommons::NORMAL_NEG:
      lFloatImpl.theType = FloatCommons::INF_NEG;
      break;
    }
    break;
  case FloatCommons::NORMAL:
  case FloatCommons::NORMAL_NEG:
    switch(aFloatImpl.theType) {
    case FloatCommons::NOT_A_NUM:
      lFloatImpl.theType = FloatCommons::NOT_A_NUM;    
      break;
    case FloatCommons::INF_NEG:
      lFloatImpl.theFloatImpl = 0;
      lFloatImpl.theType = (isPos() ? FloatCommons::NORMAL_NEG : FloatCommons::NORMAL);
      break;
    case FloatCommons::INF_POS:
      lFloatImpl.theFloatImpl = 0;
      lFloatImpl.theType = (isNeg() ? FloatCommons::NORMAL_NEG : FloatCommons::NORMAL);
      break;
    case FloatCommons::NORMAL:
    case FloatCommons::NORMAL_NEG:
      if (aFloatImpl.isZero()) {
        if (isZero()) {
          lFloatImpl.theType = FloatCommons::NOT_A_NUM;
        } else if ((isPos() && aFloatImpl.isNeg()) || (isNeg() && aFloatImpl.isPos())) {
          lFloatImpl.theType = FloatCommons::INF_NEG;
        } else {
          lFloatImpl.theType = FloatCommons::INF_POS;
        }
      } else if (isZero()) {
        lFloatImpl.theFloatImpl = 0;
        if ((isPos() && aFloatImpl.isNeg()) || (isNeg() && aFloatImpl.isPos())) {
          lFloatImpl.theType = FloatCommons::NORMAL_NEG;
        } else {
          lFloatImpl.theType = FloatCommons::NORMAL;
        }
      } else {
        lFloatImpl.theFloatImpl = theFloatImpl / aFloatImpl.theFloatImpl;
        if (lFloatImpl.theFloatImpl < 0) {
          lFloatImpl.theType = FloatCommons::NORMAL_NEG;
        } else {
          lFloatImpl.theType = FloatCommons::NORMAL;
        }
        checkInfZeroPrecision(lFloatImpl);
      }
      break;
    }
    break;
  }
  return lFloatImpl;
}

template <typename FloatType>
FloatImpl<FloatType> FloatImpl<FloatType>::operator%(const FloatImpl& aFloatImpl) const{
  FloatImpl lFloatImpl;
  if (isNaN() || aFloatImpl.isNaN() || !isFinite() || aFloatImpl.isZero()) {
    lFloatImpl.theType = FloatCommons::NOT_A_NUM;
  } else if (!aFloatImpl.isFinite() || isZero()) {
    lFloatImpl = *this;
  } else {
#ifndef ZORBA_NO_BIGNUMBERS
    MAPM lRes = theFloatImpl % aFloatImpl.theFloatImpl;
#else
    MAPM lRes = fmod(theFloatImpl, aFloatImpl.theFloatImpl);
#endif
    if ( lRes == 0 && isNeg()) {
      lFloatImpl.theType = FloatCommons::NORMAL_NEG;
      lFloatImpl.theFloatImpl = 0;
    } else {
      lFloatImpl.theFloatImpl = lRes;
      if (lRes < 0) {
        lFloatImpl.theType = FloatCommons::NORMAL_NEG;
      } else {
        lFloatImpl.theType = FloatCommons::NORMAL;
      }
    }
  }
  return lFloatImpl;
}

template <typename FloatType>
FloatImpl<FloatType> FloatImpl<FloatType>::operator-() const{
  FloatImpl lFloatImpl;
  switch(theType) {
  case FloatCommons::NORMAL:
    lFloatImpl.theType = FloatCommons::NORMAL_NEG;
    lFloatImpl.theFloatImpl = -theFloatImpl;
    break;
  case FloatCommons::NORMAL_NEG:
    lFloatImpl.theType = FloatCommons::NORMAL;
    lFloatImpl.theFloatImpl = -theFloatImpl;
    break;
  case FloatCommons::NOT_A_NUM:
    lFloatImpl.theType = FloatCommons::NOT_A_NUM;
    break;
  case FloatCommons::INF_POS:
    lFloatImpl.theType = FloatCommons::INF_NEG;
    break;
  case FloatCommons::INF_NEG:
    lFloatImpl.theType = FloatCommons::INF_POS;
    break;
  }
  return lFloatImpl;
}

template <typename FloatType>
FloatImpl<FloatType> FloatImpl<FloatType>::floor() const { 
  FloatImpl lFloatImpl;

  switch(theType) {
  case FloatCommons::NORMAL_NEG:
  case FloatCommons::NORMAL:
#ifndef ZORBA_NO_BIGNUMBERS
    lFloatImpl.theFloatImpl = theFloatImpl.floor();
#else
    lFloatImpl.theFloatImpl = ::floor(theFloatImpl);
#endif
  case FloatCommons::NOT_A_NUM:
  case FloatCommons::INF_POS:
  case FloatCommons::INF_NEG:
    lFloatImpl.theType = theType;
    break;
  }
  return lFloatImpl;
}

template <typename FloatType>
FloatImpl<FloatType> FloatImpl<FloatType>::ceil() const { 
  FloatImpl lFloatImpl;

  switch(theType) {
  case FloatCommons::NORMAL_NEG:
  case FloatCommons::NORMAL:
#ifndef ZORBA_NO_BIGNUMBERS
    lFloatImpl.theFloatImpl = theFloatImpl.ceil();
#else
    lFloatImpl.theFloatImpl = ::ceil(theFloatImpl);
#endif
  case FloatCommons::NOT_A_NUM:
  case FloatCommons::INF_POS:
  case FloatCommons::INF_NEG:
    lFloatImpl.theType = theType;
    break;
  }
  return lFloatImpl;
}

template <typename FloatType>
FloatImpl<FloatType> FloatImpl<FloatType>::round() const{
  return round(Integer::parseInt(0));
}

template <typename FloatType>
FloatImpl<FloatType> FloatImpl<FloatType>::round(Integer aPrecision) const{
  FloatImpl lFloatImpl;
  switch(theType) {
  case FloatCommons::NORMAL_NEG:
  case FloatCommons::NORMAL:
  {
    lFloatImpl.theType = theType;
    lFloatImpl.theFloatImpl = Decimal::round(theFloatImpl, aPrecision.theInteger);
    checkInfZeroPrecision(lFloatImpl);
  }
    break;
  case FloatCommons::NOT_A_NUM:
  case FloatCommons::INF_POS:
  case FloatCommons::INF_NEG:
    lFloatImpl.theType = theType;
    break;
  }
  return lFloatImpl;
}

template <typename FloatType>
FloatImpl<FloatType> FloatImpl<FloatType>::roundHalfToEven(Integer aPrecision) const{
  FloatImpl lFloatImpl;
  switch(theType) {
  case FloatCommons::NORMAL_NEG:
  case FloatCommons::NORMAL:
  {
    lFloatImpl.theType = theType;
    lFloatImpl.theFloatImpl = Decimal::roundHalfToEven(theFloatImpl, aPrecision.theInteger);
    checkInfZeroPrecision(lFloatImpl);
  }
    break;
  case FloatCommons::NOT_A_NUM:
  case FloatCommons::INF_POS:
  case FloatCommons::INF_NEG:
    lFloatImpl.theType = theType;
    break;
  }
  return lFloatImpl;
}

template <typename FloatType>
bool FloatImpl<FloatType>::operator==(const FloatImpl& aFloatImpl) const{
  switch(theType) {
  case FloatCommons::NOT_A_NUM:
    return false;
  case FloatCommons::INF_POS:
    switch(aFloatImpl.theType) {
    case FloatCommons::NOT_A_NUM:
    case FloatCommons::INF_NEG:
    case FloatCommons::NORMAL_NEG:
    case FloatCommons::NORMAL:
      return false;
    case FloatCommons::INF_POS:
      return true;
    }
  case FloatCommons::INF_NEG:
    switch(aFloatImpl.theType) {
    case FloatCommons::NOT_A_NUM:
    case FloatCommons::INF_POS:
    case FloatCommons::NORMAL_NEG:
    case FloatCommons::NORMAL:
      return false;
    case FloatCommons::INF_NEG:
      return true;
    }
  case FloatCommons::NORMAL_NEG:
    switch(aFloatImpl.theType) {
    case FloatCommons::NOT_A_NUM:
    case FloatCommons::INF_POS:
    case FloatCommons::INF_NEG:
      return false;
    case FloatCommons::NORMAL_NEG:
    case FloatCommons::NORMAL:
      return theFloatImpl == aFloatImpl.theFloatImpl;
    }
  case FloatCommons::NORMAL:
    switch(aFloatImpl.theType) {
    case FloatCommons::NOT_A_NUM:
    case FloatCommons::INF_POS:
    case FloatCommons::INF_NEG:
      return false;
    case FloatCommons::NORMAL_NEG:
    case FloatCommons::NORMAL:
      return theFloatImpl == aFloatImpl.theFloatImpl;
    }
  }
  return false;
}

template <typename FloatType>
bool FloatImpl<FloatType>::operator!=(const FloatImpl& aFloatImpl) const{
  if(isNaN() || aFloatImpl.isNaN())
    return false;
  else
    return !(*this == aFloatImpl);
}

template <typename FloatType>
bool FloatImpl<FloatType>::operator<(const FloatImpl& aFloatImpl) const{
  switch(theType) {
  case FloatCommons::NOT_A_NUM:
  case FloatCommons::INF_POS:
    return false;
  case FloatCommons::INF_NEG:
    switch(aFloatImpl.theType) {
    case FloatCommons::NOT_A_NUM:
    case FloatCommons::INF_NEG:
      return false;
    case FloatCommons::INF_POS:
    case FloatCommons::NORMAL_NEG:
    case FloatCommons::NORMAL:
      return true;
    }
  case FloatCommons::NORMAL_NEG:
    switch(aFloatImpl.theType) {
    case FloatCommons::NOT_A_NUM:
    case FloatCommons::INF_NEG:
      return false;
    case FloatCommons::INF_POS:
      return true;
    case FloatCommons::NORMAL:
    case FloatCommons::NORMAL_NEG:
      return theFloatImpl < aFloatImpl.theFloatImpl;
    }
  case FloatCommons::NORMAL:
    switch(aFloatImpl.theType) {
    case FloatCommons::NOT_A_NUM:
    case FloatCommons::INF_NEG:
      return false;
    case FloatCommons::INF_POS:
      return true;
    case FloatCommons::NORMAL_NEG:
    case FloatCommons::NORMAL:
      return theFloatImpl < aFloatImpl.theFloatImpl;
    }
  }
  return false;
} 

template <typename FloatType>
bool FloatImpl<FloatType>::operator<=(const FloatImpl& aFloatImpl) const{
  if(isNaN() || aFloatImpl.isNaN())
    return false;
  else
    return !(*this > aFloatImpl);
}

template <typename FloatType>
bool FloatImpl<FloatType>::operator>(const FloatImpl& aFloatImpl) const{
  switch(theType) {
  case FloatCommons::NOT_A_NUM:
  case FloatCommons::INF_NEG:
    return false;
  case FloatCommons::INF_POS:
    switch(aFloatImpl.theType) {
    case FloatCommons::NOT_A_NUM:
    case FloatCommons::INF_POS:
      return false;
    case FloatCommons::INF_NEG:
    case FloatCommons::NORMAL_NEG:
    case FloatCommons::NORMAL:
      return true;
    }
  case FloatCommons::NORMAL_NEG:
    switch(aFloatImpl.theType) {
    case FloatCommons::NOT_A_NUM:
    case FloatCommons::INF_POS:
      return false;
    case FloatCommons::INF_NEG:
      return true;
    case FloatCommons::NORMAL:
    case FloatCommons::NORMAL_NEG:
      return theFloatImpl > aFloatImpl.theFloatImpl;
    }
  case FloatCommons::NORMAL:
    switch(aFloatImpl.theType) {
    case FloatCommons::NOT_A_NUM:
    case FloatCommons::INF_POS:
      return false;
    case FloatCommons::INF_NEG:
      return true;
    case FloatCommons::NORMAL:
    case FloatCommons::NORMAL_NEG:
      return theFloatImpl > aFloatImpl.theFloatImpl;
    }
  }
  return false;
}

template <typename FloatType>
bool FloatImpl<FloatType>::operator>=(const FloatImpl& aFloatImpl) const{
  if(isNaN() || aFloatImpl.isNaN())
    return false;
  else
    return !(*this < aFloatImpl);
}

template <typename FloatType>
xqpString FloatImpl<FloatType>::toIntegerString() const {
  switch(theType) {
    case FloatCommons::NOT_A_NUM:
      return FloatCommons::get_NOT_A_NUM_STR();
    case FloatCommons::INF_POS:
      return FloatCommons::get_INF_POS_STR();
    case FloatCommons::INF_NEG:
      return FloatCommons::get_INF_NEG_STR();
    case FloatCommons::NORMAL_NEG:
      if (theFloatImpl == 0)
        return "-0";
    default: 
      break;
  }

#ifndef ZORBA_NO_BIGNUMBERS
  char lBuffer[1024];
  theFloatImpl.toIntegerString(lBuffer);
#else
  char lBuffer[124];
  sprintf(lBuffer, "%d", (int)theFloatImpl);
#endif
  xqpString lResult = lBuffer;
  return lResult;
}

#ifndef ZORBA_NO_BIGNUMBERS
template <typename FloatType>
xqpString FloatImpl<FloatType>::toString() const {
  switch(theType) {
    case FloatCommons::NOT_A_NUM:
      return FloatCommons::get_NOT_A_NUM_STR();
    case FloatCommons::INF_POS:
      return FloatCommons::get_INF_POS_STR();
    case FloatCommons::INF_NEG:
      return FloatCommons::get_INF_NEG_STR();
    case FloatCommons::NORMAL_NEG:
      if (theFloatImpl == 0)
        return "-0";
    default: 
      break;
  }

  MAPM absVal = theFloatImpl.abs();
  MAPM lower("0.000001"), upper("1000000");
  if((absVal < upper && absVal >= lower) || absVal == 0) {
    return Decimal::decimalToString(theFloatImpl);
  } else {
    char lBuffer[1024];
    theFloatImpl.toString(lBuffer, ZORBA_FLOAT_POINT_PRECISION);
    std::string lResult = lBuffer;
    size_t lE = lResult.find('E');
    if (lE < lResult.size()) {
      bool lPosExp = lResult[lE+1] == '+';
      size_t lZeros = lE;
      while(lResult[lZeros-1] == '0') {
        --lZeros; 
      }
      if(lResult[lZeros-1] == '.') {
        ++lZeros;
      }
      if (lE != lZeros && lPosExp) {
        lResult = lResult.substr(0, lZeros) + "E" + lResult.substr(lE+2);
      } else if (lPosExp) {
        lResult = lResult.substr(0, lE+1) + lResult.substr(lE+2);
      } else {
        lResult = lResult.substr(0, lZeros) + lResult.substr(lE);
      }
    }
    return lResult;
  }
}

#else //ZORBA_NO_BIGNUMBERS
template <typename FloatType>
xqpString FloatImpl<FloatType>::toString() const {
  switch(theType) {
    case FloatCommons::NOT_A_NUM:
      return FloatCommons::NOT_A_NUM_STR;
    case FloatCommons::INF_POS:
      return FloatCommons::INF_POS_STR;
    case FloatCommons::INF_NEG:
      return FloatCommons::INF_NEG_STR;
    case FloatCommons::NORMAL_NEG:
      if (theFloatImpl == 0)
        return "-0";
    default: 
      break;
  }

  char lBuffer[124];
  sprintf(lBuffer, "%#G", (double)theFloatImpl);

  char  *lE = strchr(lBuffer, 'E');
  char  *lZeros;

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
    lE++;
    if(*lE == '+')
      lE ++;
    lZeros[1] = 'E';
    strcpy(lZeros+2, lE);
  }
  else
  {
    if(*lZeros == '.')
      lZeros--;
    lZeros[1] = 0;
  }

  return lBuffer;
}

#endif//ZORBA_NO_BIGNUMBERS

template <typename FloatType>
uint32_t FloatImpl<FloatType>::hash() const
{
  return FloatImplTraits<FloatType>::hash(theType, theFloatImpl);
}

template class FloatImpl<double>;
template class FloatImpl<float>;

std::ostream& operator<<(std::ostream& os, const Double& aDouble) {
  os << aDouble.toString();
  return os;
}

std::ostream& operator<<(std::ostream& os, const Float& aDouble) {
  os << aDouble.toString();
  return os;
}

Double operator+(const Double& aDouble, const Float& aFloat) {
  return aDouble + FloatCommons::parseFloat(aFloat);   
}
Double operator+(const Float& aFloat, const Double& aDouble) {
  return FloatCommons::parseFloat(aFloat) + aDouble;
}

Double operator-(const Double& aDouble, const Float& aFloat) {
  return aDouble - FloatCommons::parseFloat(aFloat);   
}
Double operator-(const Float& aFloat, const Double& aDouble) {
  return FloatCommons::parseFloat(aFloat) - aDouble;
}

Double operator*(const Double& aDouble, const Float& aFloat) {
  return aDouble * FloatCommons::parseFloat(aFloat);   
}
Double operator*(const Float& aFloat, const Double& aDouble) {
  return FloatCommons::parseFloat(aFloat) * aDouble;
}

Double operator/(const Double& aDouble, const Float& aFloat) {
  return aDouble / FloatCommons::parseFloat(aFloat);   
}
Double operator/(const Float& aFloat, const Double& aDouble) {
  return FloatCommons::parseFloat(aFloat) / aDouble;
}

Double operator%(const Double& aDouble, const Float& aFloat) {
  return aDouble % FloatCommons::parseFloat(aFloat);   
}
Double operator%(const Float& aFloat, const Double& aDouble) {
  return FloatCommons::parseFloat(aFloat) % aDouble;
}

}
