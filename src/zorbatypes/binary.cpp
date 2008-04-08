#include <cassert>
#include <zorba/error.h>
#include "zorbatypes/binary.h"
#include "errors/error_manager.h"

namespace zorba {

const char* Base64::ENCODE_TABLE = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";
const char Base64::DECODE_TABLE[ 0x80 ] = {
  /*00-07*/ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  /*08-0f*/ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  /*10-17*/ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  /*18-1f*/ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  /*20-27*/ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  /*28-2f*/ 0xFF, 0xFF, 0xFF, 0x3e, 0xFF, 0xFF, 0xFF, 0x3f, //2 = '+' and '/'
  /*30-37*/ 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x3b, //8 = '0'-'7'
  /*38-3f*/ 0x3c, 0x3d, 0xFF, 0xFF, 0xFF, 0x40, 0xFF, 0xFF, //2 = '8'-'9' and '='
  /*40-47*/ 0xFF, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, //7 = 'A'-'G'
  /*48-4f*/ 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, //8 = 'H'-'O'
  /*50-57*/ 0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, //8 = 'P'-'W'
  /*58-5f*/ 0x17, 0x18, 0x19, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //3 = 'X'-'Z'
  /*60-67*/ 0xFF, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20, //7 = 'a'-'g'
  /*68-6f*/ 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, //8 = 'h'-'o'
  /*70-77*/ 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f, 0x30, //8 = 'p'-'w'
  /*78-7f*/ 0x31, 0x32, 0x33, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF  //3 = 'x'-'z'
};

size_t Base64::ENCODE_INPUT = 3;
size_t Base64::ENCODE_OUTPUT = 4;
size_t Base64::DECODE_INPUT = 4;
size_t Base64::DECODE_OUTPUT = 3;

Base64::Base64(const Base16& aBase16)
{
  std::vector<char> lOrig = Base16::decode(aBase16.getData());
  theData = Base64::encode(lOrig);
}

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
    } else if (lChar == '=' && i > 0 && i == (len-2) && aCharStar[i+1] == '=' )
    {
      if (aCharStar[i-1] == 'A'
       || aCharStar[i-1] == 'Q'
       || aCharStar[i-1] == 'g'
       || aCharStar[i-1] == 'w'
      )
      {
        theData.push_back('=');
        theData.push_back('=');
        ++i;
      } else {
        ZORBA_ERROR_DESC(ZorbaError::FORG0001,"In Base 64, '==' must be at the end and must be succeed by [AQgw]");
      }
    } else if (lChar == '=' && i > 0 && i == (len-1))
    {
      switch(aCharStar[i-1]) {
      case 'A': case 'E': case 'I': case 'M': case 'Q': case 'U': case 'Y':
      case 'c': case 'g': case 'k': case 'o': case 's': case 'w': case '0':
      case '4': case '8':
        theData.push_back('=');
        break;
      default:
        ZORBA_ERROR_DESC(ZorbaError::FORG0001,"In Base 64, '=' must be at the end and must be succeed by [AEIMQUYcgkosw048]");
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

std::vector<char> Base64::encode(const std::vector<char>& aSource)
{
  std::vector<char> lRes;
  size_t lSourceSize = aSource.size();
  size_t lSourcePos = 0;

  while (lSourceSize >= 1)
  {
    size_t lBlockSize = (lSourceSize < ENCODE_INPUT ? lSourceSize : ENCODE_INPUT);
    assert( 1 <= lBlockSize && lBlockSize <= ENCODE_INPUT );

    // Encode inputs...
    char n1 = 0, n2 = 0, n3 = 0, n4 = 0;

    switch (lBlockSize)
    {
      case 3:
        n4  =  (aSource[ lSourcePos+2 ] & 0x3f);
        n3  = ((aSource[ lSourcePos+2 ] & 0xc0) >> 6);
      case 2:
        n3 |= ((aSource[ lSourcePos+1 ] & 0x0f) << 2);
        n2  = ((aSource[ lSourcePos+1 ] & 0xf0) >> 4);
      case 1:
        n2 |= ((aSource[ lSourcePos ] & 0x03) << 4);
        n1  = ((aSource[ lSourcePos ] & 0xfc) >> 2);
        break;
      default:
        assert( false );
    }

    lSourcePos += lBlockSize;
    lSourceSize -= lBlockSize;

    // Validate...
    assert( 0 <= n1 && n1 <= 63 );
    assert( 0 <= n2 && n2 <= 63 );
    assert( 0 <= n3 && n3 <= 63 );
    assert( 0 <= n4 && n4 <= 63 );

    // Padding...
    switch (lBlockSize)
    {
      case 1: n3 = 64;
      case 2: n4 = 64;
      case 3:
              break;
      default:
              assert( false );
    }

    // 4 outputs...
    lRes.push_back(ENCODE_TABLE[n1]);
    lRes.push_back(ENCODE_TABLE[n2]);
    lRes.push_back(ENCODE_TABLE[n3]);
    lRes.push_back(ENCODE_TABLE[n4]);
  }

  return lRes;
}

std::vector<char> Base64::decode(const std::vector<char>& aSource)
{
  std::vector<char> lRes;
  size_t lSrcSize = aSource.size();
  size_t lSrcPos = 0;
  assert(lSrcSize % DECODE_INPUT == 0); 

  while (lSrcSize >= 1)
  {
    // 4 inputs...
    char in1 = aSource[lSrcPos++];
    char in2 = aSource[lSrcPos++];
    char in3 = aSource[lSrcPos++];
    char in4 = aSource[lSrcPos++];

    lSrcSize -= DECODE_INPUT; //4

    // Validate ascii...
    assert( 0 <= in1 /*&& in1 <= 0x7f*/ );
    assert( 0 <= in2 /*&& in2 <= 0x7f*/ );
    assert( 0 <= in1 /*&& in3 <= 0x7f*/ );
    assert( 0 <= in2 /*&& in4 <= 0x7f*/ );

    // Convert ascii to base16...
    in1 = DECODE_TABLE[ int(in1) ];
    in2 = DECODE_TABLE[ int(in2) ];
    in3 = DECODE_TABLE[ int(in3) ];
    in4 = DECODE_TABLE[ int(in4) ];

    // Validate base16...
    /*assert( in1 != 0xff );*/
    /*assert( in2 != 0xff );*/
    /*assert( in3 != 0xff );*/
    /*assert( in4 != 0xff );*/
    assert( 0 <= in1 && in1 <= 63 );
    assert( 0 <= in2 && in2 <= 63 );
    assert( 0 <= in3 && in3 <= 64 ); //possible padding
    assert( 0 <= in4 && in4 <= 64 ); //possible padding

    // 3 outputs...
    char lChar = ((in1 & 0x3f) << 2) | ((in2 & 0x30) >> 4);
    if (lChar != 0)
      lRes.push_back(lChar);
    lChar = ((in2 & 0x0f) << 4) | ((in3 & 0x3c) >> 2);
    if (lChar != 0)
      lRes.push_back(lChar);
    lChar = ((in3 & 0x03) << 6) | (in4 & 0x3f);
    if (lChar != 0)
      lRes.push_back(lChar);
  }

  return lRes;
}

uint32_t Base64::hash() const
{
  uint32_t lHash = 0;
  std::vector<char>::const_iterator lIter = theData.begin();
  std::vector<char>::const_iterator lEnd = theData.end();
  for(;lIter!=lEnd;++lIter)
  {
    uint32_t lDiff = 65535-*lIter;
    if (lDiff < lHash)
    {
      lHash = lHash - lDiff;
    } else {
      lHash += *lIter; 
    }
  }
  return lHash;
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

const char* Base16::ENCODE_TABLE = "0123456789ABCDEF";
const char Base16::DECODE_TABLE[ 0x80 ] = {
  /*00-07*/ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  /*08-0f*/ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  /*10-17*/ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  /*18-1f*/ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  /*20-27*/ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  /*28-2f*/ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  /*30-37*/ 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, //8 = '0'-'7'
  /*38-3f*/ 0x08, 0x09, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //2 = '8'-'9'
  /*40-47*/ 0xFF, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0xFF, //6 = 'A'-'F'
  /*48-4f*/ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  /*50-57*/ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  /*58-5f*/ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  /*60-67*/ 0xFF, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0xFF, //6 = 'a'-'f' (same as 'A'-'F')
  /*68-6f*/ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  /*70-77*/ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  /*78-7f*/ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};

size_t Base16::ENCODE_INPUT = 1;
size_t Base16::ENCODE_OUTPUT = 2;
size_t Base16::DECODE_INPUT = 2;
size_t Base16::DECODE_OUTPUT = 1;

Base16::Base16(const Base64& aBase64)
{
  std::vector<char> lOrig = Base64::decode(aBase64.getData());
  theData = Base16::encode(lOrig);
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

std::vector<char> Base16::encode(const std::vector<char>& aSource)
{
  std::vector<char> lRes;
  size_t lSrcPos = 0;
  size_t lSrcSize = aSource.size();

  while (lSrcSize >= 1)
  {
    // 1 input...
    char ch = aSource[lSrcPos++];
    lSrcSize -= ENCODE_INPUT; //1

    // 2 outputs...
    lRes.push_back(ENCODE_TABLE[ (ch & 0xf0) >> 4 ]);
    lRes.push_back(ENCODE_TABLE[ (ch & 0x0f)      ]);
  }

  return lRes;
}

std::vector<char> Base16::decode(const std::vector<char>& aSource)
{
  std::vector<char> lRes;

  size_t lSrcSize = aSource.size();
  size_t lSrcPos = 0;
  assert(lSrcSize % DECODE_INPUT == 0);

  while (lSrcSize >= 1)
  {
    // 2 inputs...
    char in1 = aSource[lSrcPos++];
    char in2 = aSource[lSrcPos++];
    lSrcSize -= DECODE_INPUT;

    // Validate ascii...
    assert( 0 <= in1 /*&& in1 <= 0x7f*/ );
    assert( 0 <= in2 /*&& in2 <= 0x7f*/ );

    // Convert ascii to base16...
    in1 = DECODE_TABLE[ int(in1) ];
    in2 = DECODE_TABLE[ int(in2) ];

    // Validate base16...
    /*assert( in1 != 0xff );*/
    assert( 0 <= in1 && in1 <= 15 );
    assert( 0 <= in2 && in2 <= 15 );

    // 1 output...
    lRes.push_back(((in1 << 4) | in2));
  }
  return lRes;
}

uint32_t Base16::hash() const
{
  uint32_t lHash = 0;
  std::vector<char>::const_iterator lIter = theData.begin();
  std::vector<char>::const_iterator lEnd = theData.end();
  for(;lIter!=lEnd;++lIter)
  {
    uint32_t lDiff = 65535-*lIter;
    if (lDiff < lHash)
    {
      lHash = lHash - lDiff;
    } else {
      lHash += *lIter; 
    }
  }
  return lHash;
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
