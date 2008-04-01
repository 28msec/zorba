#include <zorba/error.h>
#include "zorbatypes/binary.h"
#include "errors/error_manager.h"

namespace zorba {

void Base64::insertData(const char* aCharStar, size_t len)
{
  if (len % 4 != 0) {
    ZORBA_ERROR_DESC(ZorbaError::FORG0001, "Base64 input must be a multiple of four characters");
  }

  for (size_t i = 0; i < len; ++i)
  {
    char lChar = aCharStar[i];
    if ((lChar >= 65 && lChar <= 90)  // A-Z
     || (lChar >= 97 && lChar <= 122) // a-z
     || (lChar >= 48 && lChar <= 57)  // 0-9
     || (lChar == 43)                 // +
     || (lChar == 47))                // /
    {
      theData.push_back(lChar);
    } else if (lChar == '=')
    {
      if ( 
         (i > 0 && i == (len-2))
      && (aCharStar[i+1] == '=')
      && (   aCharStar[i-1] == 'A'
          || aCharStar[i-1] == 'Q'
          || aCharStar[i-1] == 'g'
          || aCharStar[i-1] == 'w')
      )
      {
        theData.push_back('=');
        theData.push_back('=');
        ++i;
      } else {
        ZORBA_ERROR_DESC(ZorbaError::FORG0001,"Base64 can contain '=' only in the suffix [AQgw]==");
      }
    } else {
      std::stringstream lStream;
      lStream << "invalid character '" << aCharStar[i] << "' in Base64 value";
      ZORBA_ERROR_DESC(ZorbaError::FORG0001, lStream.str());
    }
  }
}

bool Base64::equal(const Base64& aBase64) const
{
  if (size() != aBase64.size())
    return false;

  std::vector<char>::const_iterator lIter0 = theData.begin();
  std::vector<char>::const_iterator lEnd0 = theData.end();
  std::vector<char>::const_iterator lIter1 = aBase64.theData.begin();

  for (; lIter0 != lEnd0 ; )
  {
    if (*lIter0 != *lIter1)
      return false;
    ++lIter0; ++lIter1;
  }
  return true;
}

xqpString Base64::str() const {
  std::stringstream lStream;
  lStream << *this;
  return lStream.str();
}

std::ostream& operator<<(std::ostream& os, const Base64& aBase64)
{
  std::vector<char>::const_iterator lIter = aBase64.getData().begin();
  std::vector<char>::const_iterator lEnd = aBase64.getData().end();
  for( ; lIter != lEnd ; ++lIter)
  {
    os << *lIter;
  }
  return os;
}

void Base16::insertData(const char* aCharStar, size_t len)
{

  if (len % 2 != 0) {
    ZORBA_ERROR_DESC(ZorbaError::FORG0001, "A hexBinary value must contain an even number of characters");
  }

  for (size_t i = 0; i < len; ++i)
  {
    char lChar = aCharStar[i];
    if ((lChar >= 65 && lChar <= 70)  // A-F
     || (lChar >= 48 && lChar <= 57))  // 0-9
    {
      theData.push_back(lChar);
    } else if (lChar >= 97 && lChar <= 102) // a-f
    {
      theData.push_back(lChar-32);
    } else {
      std::stringstream lStream;
      lStream << "Invalid hexadecimal digit";
      ZORBA_ERROR_DESC(ZorbaError::FORG0001, lStream.str());
    }
  }
}

bool Base16::equal(const Base16& aBase16) const
{
  if (size() != aBase16.size())
    return false;

  std::vector<char>::const_iterator lIter0 = theData.begin();
  std::vector<char>::const_iterator lEnd0 = theData.end();
  std::vector<char>::const_iterator lIter1 = aBase16.theData.begin();

  for (; lIter0 != lEnd0 ; )
  {
    if (*lIter0 != *lIter1)
      return false;
    ++lIter0; ++lIter1;
  }
  return true;
}

xqpString Base16::str() const {
  std::stringstream lStream;
  lStream << *this;
  return lStream.str();
}

std::ostream& operator<<(std::ostream& os, const Base16& aBase16)
{
  std::vector<char>::const_iterator lIter = aBase16.getData().begin();
  std::vector<char>::const_iterator lEnd = aBase16.getData().end();
  for( ; lIter != lEnd ; ++lIter)
  {
    os << *lIter;
  }
  return os;
}


} // namespace zorba
