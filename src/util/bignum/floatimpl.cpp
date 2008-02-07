#include "util/bignum/floatimpl.h"
#include <limits>
#include <string>

namespace xqp {

std::ostream& operator<<(std::ostream& os, const Double& aDouble) {
  os << aDouble.toString();
  return os;
}

std::ostream& operator<<(std::ostream& os, const Float& aDouble) {
  os << aDouble.toString();
  return os;
}

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
  
const xqpString FloatConsts::INF_POS_STR = "INF";
const xqpString FloatConsts::INF_NEG_STR = "-INF";
const xqpString FloatConsts::NOT_A_NUM_STR = "NaN";

template <typename FloatType>
void FloatImpl<FloatType>::setFloatImpl(FloatType aFloatImpl){
  switch(theType = checkInfNaNNeg(aFloatImpl)) {
    case FloatConsts::INF_NEG:
    case FloatConsts::NOT_A_NUM:
    case FloatConsts::INF_POS:
      theFloatImpl = 0;
      break;
    case FloatConsts::NORMAL_NEG:
    case FloatConsts::NORMAL:
      theFloatImpl = aFloatImpl;
      break;
  }
}

template <typename FloatType>
bool FloatImpl<FloatType>::checkInfNaN(FloatImpl& aFloatImpl) {
  if (aFloatImpl.theType == FloatConsts::NORMAL || aFloatImpl.theType == FloatConsts::NORMAL_NEG) {
    if (FloatImplTraits<FloatType>::isPosInf(aFloatImpl.theFloatImpl)) {
      aFloatImpl.theType = FloatConsts::INF_POS;
      aFloatImpl.theFloatImpl = 0;
      return true;
    } else if (FloatImplTraits<FloatType>::isNegInf(aFloatImpl.theFloatImpl)) {
      aFloatImpl.theType = FloatConsts::INF_NEG;
      aFloatImpl.theFloatImpl = 0;
      return true;
    } else if (FloatImplTraits<FloatType>::isZero(aFloatImpl.theFloatImpl)) {
      aFloatImpl.theType = FloatConsts::NORMAL;
      aFloatImpl.theFloatImpl = 0;
      return true;
    }
  }
  return false;
}

template <typename FloatType>
FloatConsts::NumType FloatImpl<FloatType>::checkInfNaNNeg(const char* aCharStar) {
#if HAVE_STRCASECMP_FUNCTION && !WIN32
    if (strcasecmp(aCharStar, "inf") == 0 || strcasecmp(aCharStar, "+inf") == 0 )
#else
    if (_stricmp(aCharStar, "inf") == 0 || _stricmp(aCharStar, "+inf") == 0 )
#endif
    {
      return FloatConsts::INF_POS;
    }
#if HAVE_STRCASECMP_FUNCTION && !WIN32
    else if (strcasecmp(aCharStar, "-inf") == 0 )
#else
    else if (_stricmp(aCharStar, "-inf") == 0 )
#endif
    {
      return FloatConsts::INF_NEG;
    }
#if HAVE_STRCASECMP_FUNCTION && !WIN32
    else if (strcasecmp(aCharStar, "nan") == 0 )
#else
    else if (_stricmp(aCharStar, "nan") == 0 )
#endif
    {
      return FloatConsts::NOT_A_NUM;
    }
    else if (aCharStar[0] == '-') 
    {
      return FloatConsts::NORMAL_NEG;
    }  
    else
    {
      return FloatConsts::NORMAL;
    }
}

template <typename FloatType>
FloatConsts::NumType FloatImpl<FloatType>::checkInfNaNNeg(FloatType aFloat) {
  if (aFloat != aFloat) {
    return FloatConsts::NOT_A_NUM;
  } else if (aFloat == std::numeric_limits<FloatType>::infinity()) {
    return FloatConsts::INF_POS;
  } else if (aFloat == -std::numeric_limits<FloatType>::infinity()) {
    return FloatConsts::INF_NEG;
  } else if (aFloat < 0) {
    return FloatConsts::NORMAL_NEG;
  } else {
    return FloatConsts::NORMAL;
  }
}

template <typename FloatType>
bool FloatImpl<FloatType>::parse(const char* aCharStar, FloatImpl& aFloatImpl) {
  const char* lCur = aCharStar;
  std::string lBuffer(aCharStar);

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

  FloatConsts::NumType lType;
  MAPM lNumber = 0;

  if(!lGotDigit || lStop) {
    switch(lType = checkInfNaNNeg(aCharStar)) {
    case FloatConsts::INF_NEG:
    case FloatConsts::NOT_A_NUM:
    case FloatConsts::INF_POS:
      break;
    default:
      return false;
      break;
    }
  } else {
    lNumber = lBuffer.c_str();
    if (lIsNegative) {
      lType = FloatConsts::NORMAL_NEG;
    } else {
      lType = FloatConsts::NORMAL;
    }
  }

  aFloatImpl.theType = lType;
  aFloatImpl.theFloatImpl = lNumber;

  checkInfNaN(aFloatImpl);
  return true;
}

template <typename FloatType>
FloatImpl<FloatType> FloatImpl<FloatType>::operator+(const FloatImpl& aFloatImpl) const{
  FloatImpl lFloatImpl;
  switch(theType) {
  case FloatConsts::NOT_A_NUM:
    lFloatImpl.theType = FloatConsts::NOT_A_NUM;    
    break;
  case FloatConsts::INF_NEG:
    switch(aFloatImpl.theType) {
    case FloatConsts::NOT_A_NUM:
    case FloatConsts::INF_POS:
      lFloatImpl.theType = FloatConsts::NOT_A_NUM;    
      break;
    case FloatConsts::INF_NEG:
    case FloatConsts::NORMAL:
    case FloatConsts::NORMAL_NEG:
      lFloatImpl.theType = FloatConsts::INF_NEG;
      break;
    }
    break;
  case FloatConsts::INF_POS:
    switch(aFloatImpl.theType) {
    case FloatConsts::NOT_A_NUM:
    case FloatConsts::INF_NEG:
      lFloatImpl.theType = FloatConsts::NOT_A_NUM;    
      break;
    case FloatConsts::INF_POS:
    case FloatConsts::NORMAL:
    case FloatConsts::NORMAL_NEG:
      lFloatImpl.theType = FloatConsts::INF_POS;
      break;
    }
    break;
  case FloatConsts::NORMAL:
  case FloatConsts::NORMAL_NEG:
    switch(aFloatImpl.theType) {
    case FloatConsts::NOT_A_NUM:
      lFloatImpl.theType = FloatConsts::NOT_A_NUM;    
      break;
    case FloatConsts::INF_NEG:
      lFloatImpl.theType = FloatConsts::INF_NEG;
      break;
    case FloatConsts::INF_POS:
      lFloatImpl.theType = FloatConsts::INF_POS;
      break;
    case FloatConsts::NORMAL:
    case FloatConsts::NORMAL_NEG:
      if (theFloatImpl == 0 && aFloatImpl.theFloatImpl == 0) {
        lFloatImpl.theFloatImpl = 0;
        if (theType == aFloatImpl.theType) {
          lFloatImpl.theType = theType;
        } else {
          lFloatImpl.theType = FloatConsts::NORMAL;
        }
      } else {
        lFloatImpl.theFloatImpl = theFloatImpl + aFloatImpl.theFloatImpl;
        if (lFloatImpl.theFloatImpl < 0) {
          lFloatImpl.theType = FloatConsts::NORMAL_NEG;
        } else {
          lFloatImpl.theType = FloatConsts::NORMAL;
        }
        checkInfNaN(lFloatImpl);
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
  case FloatConsts::NOT_A_NUM:
    lFloatImpl.theType = FloatConsts::NOT_A_NUM;    
    break;
  case FloatConsts::INF_NEG:
    switch(aFloatImpl.theType) {
    case FloatConsts::NOT_A_NUM:
    case FloatConsts::INF_NEG:
      lFloatImpl.theType = FloatConsts::NOT_A_NUM;    
      break;
    case FloatConsts::INF_POS:
    case FloatConsts::NORMAL:
    case FloatConsts::NORMAL_NEG:
      lFloatImpl.theType = FloatConsts::INF_NEG;
      break;
    }
    break;
  case FloatConsts::INF_POS:
    switch(aFloatImpl.theType) {
    case FloatConsts::NOT_A_NUM:
    case FloatConsts::INF_POS:
      lFloatImpl.theType = FloatConsts::NOT_A_NUM;    
      break;
    case FloatConsts::INF_NEG:
    case FloatConsts::NORMAL:
    case FloatConsts::NORMAL_NEG:
      lFloatImpl.theType = FloatConsts::INF_POS;
      break;
    }
    break;
  case FloatConsts::NORMAL:
  case FloatConsts::NORMAL_NEG:
    switch(aFloatImpl.theType) {
    case FloatConsts::NOT_A_NUM:
      lFloatImpl.theType = FloatConsts::NOT_A_NUM;    
      break;
    case FloatConsts::INF_NEG:
      lFloatImpl.theType = FloatConsts::INF_NEG;
      break;
    case FloatConsts::INF_POS:
      lFloatImpl.theType = FloatConsts::INF_POS;
      break;
    case FloatConsts::NORMAL:
    case FloatConsts::NORMAL_NEG:
      if (theFloatImpl == 0 && aFloatImpl.theFloatImpl == 0) {
        lFloatImpl.theFloatImpl = 0;
        if (theType == FloatConsts::NORMAL_NEG && aFloatImpl.theType == FloatConsts::NORMAL) {
          lFloatImpl.theType = FloatConsts::NORMAL_NEG;
        } else {
          lFloatImpl.theType = FloatConsts::NORMAL;
        }
      } else {
        lFloatImpl.theFloatImpl = theFloatImpl - aFloatImpl.theFloatImpl;
        if (lFloatImpl.theFloatImpl < 0) {
          lFloatImpl.theType = FloatConsts::NORMAL_NEG;
        } else {
          lFloatImpl.theType = FloatConsts::NORMAL;
        }
        checkInfNaN(lFloatImpl);
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
  case FloatConsts::NOT_A_NUM:
    lFloatImpl.theType = FloatConsts::NOT_A_NUM;    
    break;
  case FloatConsts::INF_NEG:
    switch(aFloatImpl.theType) {
    case FloatConsts::NOT_A_NUM:
      lFloatImpl.theType = FloatConsts::NOT_A_NUM;    
      break;
    case FloatConsts::INF_NEG:
    case FloatConsts::NORMAL_NEG:
      lFloatImpl.theType = FloatConsts::INF_POS;
      break;
    case FloatConsts::INF_POS:
    case FloatConsts::NORMAL:
      lFloatImpl.theType = FloatConsts::INF_NEG;
      break;
    }
    break;
  case FloatConsts::INF_POS:
    switch(aFloatImpl.theType) {
    case FloatConsts::NOT_A_NUM:
      lFloatImpl.theType = FloatConsts::NOT_A_NUM;    
      break;
    case FloatConsts::INF_POS:
    case FloatConsts::NORMAL:
      lFloatImpl.theType = FloatConsts::INF_POS;
      break;
    case FloatConsts::NORMAL_NEG:
    case FloatConsts::INF_NEG:
      lFloatImpl.theType = FloatConsts::INF_NEG;
      break;
    }
    break;
  case FloatConsts::NORMAL:
  case FloatConsts::NORMAL_NEG:
    switch(aFloatImpl.theType) {
    case FloatConsts::NOT_A_NUM:
      lFloatImpl.theType = FloatConsts::NOT_A_NUM;    
      break;
    case FloatConsts::INF_NEG:
      lFloatImpl.theType = (isPos() ? FloatConsts::INF_NEG : FloatConsts::INF_POS);
      break;
    case FloatConsts::INF_POS:
      lFloatImpl.theType = (isNeg() ? FloatConsts::INF_POS : FloatConsts::INF_NEG);
      break;
    case FloatConsts::NORMAL:
    case FloatConsts::NORMAL_NEG:
      if (theFloatImpl == 0 || aFloatImpl.theFloatImpl == 0) {
        lFloatImpl.theFloatImpl = 0;
        if (theType == FloatConsts::NORMAL_NEG || aFloatImpl.theType == FloatConsts::NORMAL_NEG) {
          lFloatImpl.theType = FloatConsts::NORMAL_NEG;
        } else {
          lFloatImpl.theType = FloatConsts::NORMAL;
        }
      } else {
        lFloatImpl.theFloatImpl = theFloatImpl * aFloatImpl.theFloatImpl;
        if (lFloatImpl.theFloatImpl < 0) {
          lFloatImpl.theType = FloatConsts::NORMAL_NEG;
        } else {
          lFloatImpl.theType = FloatConsts::NORMAL;
        }
        checkInfNaN(lFloatImpl);
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
  case FloatConsts::NOT_A_NUM:
    lFloatImpl.theType = FloatConsts::NOT_A_NUM;    
    break;
  case FloatConsts::INF_NEG:
    switch(aFloatImpl.theType) {
    case FloatConsts::NOT_A_NUM:
    case FloatConsts::INF_POS:
    case FloatConsts::INF_NEG:
      lFloatImpl.theType = FloatConsts::NOT_A_NUM;    
      break;
    case FloatConsts::NORMAL:
      lFloatImpl.theType = FloatConsts::INF_NEG;
      break;
    case FloatConsts::NORMAL_NEG:
      lFloatImpl.theType = FloatConsts::INF_POS;
      break;
    }
    break;
  case FloatConsts::INF_POS:
    switch(aFloatImpl.theType) {
    case FloatConsts::NOT_A_NUM:
    case FloatConsts::INF_POS:
    case FloatConsts::INF_NEG:
      lFloatImpl.theType = FloatConsts::NOT_A_NUM;    
      break;
    case FloatConsts::NORMAL:
      lFloatImpl.theType = FloatConsts::INF_POS;
      break;
    case FloatConsts::NORMAL_NEG:
      lFloatImpl.theType = FloatConsts::INF_NEG;
      break;
    }
    break;
  case FloatConsts::NORMAL:
  case FloatConsts::NORMAL_NEG:
    switch(aFloatImpl.theType) {
    case FloatConsts::NOT_A_NUM:
      lFloatImpl.theType = FloatConsts::NOT_A_NUM;    
      break;
    case FloatConsts::INF_NEG:
      lFloatImpl.theFloatImpl = 0;
      lFloatImpl.theType = (isPos() ? FloatConsts::NORMAL_NEG : FloatConsts::NORMAL);
      break;
    case FloatConsts::INF_POS:
      lFloatImpl.theFloatImpl = 0;
      lFloatImpl.theType = (isNeg() ? FloatConsts::NORMAL_NEG : FloatConsts::NORMAL);
      break;
    case FloatConsts::NORMAL:
    case FloatConsts::NORMAL_NEG:
      if (aFloatImpl.isZero()) {
        if (isZero()) {
          lFloatImpl.theType = FloatConsts::NOT_A_NUM;
        } else if ((isPos() && aFloatImpl.isNeg()) || (isNeg() && aFloatImpl.isPos())) {
          lFloatImpl.theType = FloatConsts::INF_NEG;
        } else {
          lFloatImpl.theType = FloatConsts::INF_POS;
        }
      } else if (isZero()) {
        lFloatImpl.theFloatImpl = 0;
        if ((isPos() && aFloatImpl.isNeg()) || (isNeg() && aFloatImpl.isPos())) {
          lFloatImpl.theType = FloatConsts::NORMAL_NEG;
        } else {
          lFloatImpl.theType = FloatConsts::NORMAL;
        }
      } else {
        lFloatImpl.theFloatImpl = theFloatImpl / aFloatImpl.theFloatImpl;
        if (lFloatImpl.theFloatImpl < 0) {
          lFloatImpl.theType = FloatConsts::NORMAL_NEG;
        } else {
          lFloatImpl.theType = FloatConsts::NORMAL;
        }
        checkInfNaN(lFloatImpl);
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
    lFloatImpl.theType = FloatConsts::NOT_A_NUM;
  } else if (!aFloatImpl.isFinite() || isZero()) {
    lFloatImpl = *this;
  } else {
    MAPM lRes = theFloatImpl % aFloatImpl.theFloatImpl;
    if ( lRes == 0 && isNeg()) {
      lFloatImpl.theType = FloatConsts::NORMAL_NEG;
      lFloatImpl.theFloatImpl = 0;
    } else {
      lFloatImpl.theFloatImpl = lRes;
      if (lRes < 0) {
        lFloatImpl.theType = FloatConsts::NORMAL_NEG;
      } else {
        lFloatImpl.theType = FloatConsts::NORMAL;
      }
    }
  }
  return lFloatImpl;
}

template <typename FloatType>
FloatImpl<FloatType> FloatImpl<FloatType>::operator-() const{
  FloatImpl lFloatImpl;
  switch(theType) {
  case FloatConsts::NORMAL:
    lFloatImpl.theType = FloatConsts::NORMAL_NEG;
    lFloatImpl.theFloatImpl = -theFloatImpl;
    break;
  case FloatConsts::NORMAL_NEG:
    lFloatImpl.theType = FloatConsts::NORMAL;
    lFloatImpl.theFloatImpl = -theFloatImpl;
    break;
  case FloatConsts::NOT_A_NUM:
    lFloatImpl.theType = FloatConsts::NOT_A_NUM;
    break;
  case FloatConsts::INF_POS:
    lFloatImpl.theType = FloatConsts::INF_NEG;
    break;
  case FloatConsts::INF_NEG:
    lFloatImpl.theType = FloatConsts::INF_POS;
    break;
  }
  return lFloatImpl;
}

template <typename FloatType>
FloatImpl<FloatType> FloatImpl<FloatType>::floor() const { 
  FloatImpl lFloatImpl;

  switch(theType) {
  case FloatConsts::NORMAL_NEG:
  case FloatConsts::NORMAL:
    lFloatImpl.theFloatImpl = theFloatImpl.floor();
  case FloatConsts::NOT_A_NUM:
  case FloatConsts::INF_POS:
  case FloatConsts::INF_NEG:
    lFloatImpl.theType = theType;
    break;
  }
  return lFloatImpl;
}

template <typename FloatType>
FloatImpl<FloatType> FloatImpl<FloatType>::ceil() const { 
  FloatImpl lFloatImpl;

  switch(theType) {
  case FloatConsts::NORMAL_NEG:
  case FloatConsts::NORMAL:
    lFloatImpl.theFloatImpl = theFloatImpl.ceil();
  case FloatConsts::NOT_A_NUM:
  case FloatConsts::INF_POS:
  case FloatConsts::INF_NEG:
    lFloatImpl.theType = theType;
    break;
  }
  return lFloatImpl;
}

template <typename FloatType>
FloatImpl<FloatType> FloatImpl<FloatType>::round(Integer aPrecision) const{
  FloatImpl lFloatImpl;
  switch(theType) {
  case FloatConsts::NORMAL_NEG:
  case FloatConsts::NORMAL:
  {
    lFloatImpl.theType = theType;
    lFloatImpl.theFloatImpl = Decimal::round(theFloatImpl, aPrecision.theInteger);
    checkInfNaN(lFloatImpl);
  }
    break;
  case FloatConsts::NOT_A_NUM:
  case FloatConsts::INF_POS:
  case FloatConsts::INF_NEG:
    lFloatImpl.theType = theType;
    break;
  }
  return lFloatImpl;
}

template <typename FloatType>
FloatImpl<FloatType> FloatImpl<FloatType>::roundHalfToEven(Integer aPrecision) const{
  FloatImpl lFloatImpl;
  switch(theType) {
  case FloatConsts::NORMAL_NEG:
  case FloatConsts::NORMAL:
  {
    lFloatImpl.theType = theType;
    lFloatImpl.theFloatImpl = Decimal::roundHalfToEven(theFloatImpl, aPrecision.theInteger);
    checkInfNaN(lFloatImpl);
  }
    break;
  case FloatConsts::NOT_A_NUM:
  case FloatConsts::INF_POS:
  case FloatConsts::INF_NEG:
    lFloatImpl.theType = theType;
    break;
  }
  return lFloatImpl;
}

template <typename FloatType>
bool FloatImpl<FloatType>::operator==(const FloatImpl& aFloatImpl) const{
  switch(theType) {
  case FloatConsts::NOT_A_NUM:
    return false;
  case FloatConsts::INF_POS:
    switch(aFloatImpl.theType) {
    case FloatConsts::NOT_A_NUM:
    case FloatConsts::INF_NEG:
    case FloatConsts::NORMAL_NEG:
    case FloatConsts::NORMAL:
      return false;
    case FloatConsts::INF_POS:
      return true;
    }
  case FloatConsts::INF_NEG:
    switch(aFloatImpl.theType) {
    case FloatConsts::NOT_A_NUM:
    case FloatConsts::INF_POS:
    case FloatConsts::NORMAL_NEG:
    case FloatConsts::NORMAL:
      return false;
    case FloatConsts::INF_NEG:
      return true;
    }
  case FloatConsts::NORMAL_NEG:
    switch(aFloatImpl.theType) {
    case FloatConsts::NOT_A_NUM:
    case FloatConsts::INF_POS:
    case FloatConsts::INF_NEG:
      return false;
    case FloatConsts::NORMAL_NEG:
    case FloatConsts::NORMAL:
      return theFloatImpl == aFloatImpl.theFloatImpl;
    }
  case FloatConsts::NORMAL:
    switch(aFloatImpl.theType) {
    case FloatConsts::NOT_A_NUM:
    case FloatConsts::INF_POS:
    case FloatConsts::INF_NEG:
      return false;
    case FloatConsts::NORMAL_NEG:
    case FloatConsts::NORMAL:
      return theFloatImpl == aFloatImpl.theFloatImpl;
    }
  }
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
  case FloatConsts::NOT_A_NUM:
  case FloatConsts::INF_POS:
    return false;
  case FloatConsts::INF_NEG:
    switch(aFloatImpl.theType) {
    case FloatConsts::NOT_A_NUM:
    case FloatConsts::INF_NEG:
      return false;
    case FloatConsts::INF_POS:
    case FloatConsts::NORMAL_NEG:
    case FloatConsts::NORMAL:
      return true;
    }
  case FloatConsts::NORMAL_NEG:
    switch(aFloatImpl.theType) {
    case FloatConsts::NOT_A_NUM:
    case FloatConsts::INF_NEG:
      return false;
    case FloatConsts::INF_POS:
      return true;
    case FloatConsts::NORMAL:
    case FloatConsts::NORMAL_NEG:
      return theFloatImpl < aFloatImpl.theFloatImpl;
    }
  case FloatConsts::NORMAL:
    switch(aFloatImpl.theType) {
    case FloatConsts::NOT_A_NUM:
    case FloatConsts::INF_NEG:
      return false;
    case FloatConsts::INF_POS:
      return true;
    case FloatConsts::NORMAL_NEG:
    case FloatConsts::NORMAL:
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
  case FloatConsts::NOT_A_NUM:
  case FloatConsts::INF_NEG:
    return false;
  case FloatConsts::INF_POS:
    switch(aFloatImpl.theType) {
    case FloatConsts::NOT_A_NUM:
    case FloatConsts::INF_POS:
      return false;
    case FloatConsts::INF_NEG:
    case FloatConsts::NORMAL_NEG:
    case FloatConsts::NORMAL:
      return true;
    }
  case FloatConsts::NORMAL_NEG:
    switch(aFloatImpl.theType) {
    case FloatConsts::NOT_A_NUM:
    case FloatConsts::INF_POS:
      return false;
    case FloatConsts::INF_NEG:
      return true;
    case FloatConsts::NORMAL:
    case FloatConsts::NORMAL_NEG:
      return theFloatImpl > aFloatImpl.theFloatImpl;
    }
  case FloatConsts::NORMAL:
    switch(aFloatImpl.theType) {
    case FloatConsts::NOT_A_NUM:
    case FloatConsts::INF_POS:
      return false;
    case FloatConsts::INF_NEG:
      return true;
    case FloatConsts::NORMAL:
    case FloatConsts::NORMAL_NEG:
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
xqpString FloatImpl<FloatType>::toString() const {
  switch(theType) {
    case FloatConsts::NOT_A_NUM:
      return FloatConsts::NOT_A_NUM_STR;
    case FloatConsts::INF_POS:
      return FloatConsts::INF_POS_STR;
    case FloatConsts::INF_NEG:
      return FloatConsts::INF_NEG_STR;
    case FloatConsts::NORMAL_NEG:
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
    theFloatImpl.toString(lBuffer, 16);
    xqpString lResult = lBuffer;
    int32_t lE = lResult.indexOf("E");
    if (lE >= 0) {
      bool lPosExp = (lResult.substr(lE+1,1) == "+");
      int32_t lZeros = lE;
      while(lResult.substr(lZeros-1,1) == "0") {
        --lZeros; 
      }
      if(lResult.substr(lZeros-1,1) == ".") {
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

template class FloatImpl<double>;
template class FloatImpl<float>;

}
