
#include "errors/error_factory.h"
#include "util/Assert.h"
#include "store/naive/ordpath.h"
#include "store/naive/store_defs.h"


namespace zorba { namespace store {

/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class OrdPath                                                              //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************
  Masks used during decompression
********************************************************************************/
const unsigned char OrdPath::theByteMasks[8][2] = 
{
  { 0xff, 0x00 },  // 0
  { 0x7f, 0x80 },  // 1
  { 0x3f, 0xc0 },  // 2
  { 0x1f, 0xe0 },  // 3
  { 0x0f, 0xf0 },  // 4
  { 0x07, 0xf8 },  // 5
  { 0x03, 0xfc },  // 6
  { 0x01, 0xfe }   // 7
};


/*******************************************************************************
  Masks ussed during compression
********************************************************************************/
const uint32_t OrdPath::theValueMasks[9] = 
{
  0x00000000,
  0x80000000,  // 1 -> 1000-0000
  0xC0000000,  // 2 -> 1100-0000
  0xE0000000,  // 3 -> 1110-0000
  0xF0000000,  // 4 -> 1111-0000
  0xF8000000,  // 5 -> 1111-1000
  0xFC000000,  // 6 -> 1111-1100
  0xFE000000,  // 7 -> 1111-1110
  0xFF000000   // 8 -> 1111-1111
};


/*******************************************************************************
  This array gives the total number of bits needed for the encoding of 
  components with values between 0 and DEFAULT_FAN_OUT - 1.
********************************************************************************/
const unsigned char OrdPath::thePosV2LMap[DEFAULT_FAN_OUT] = 
{
  /* 0 */        3,
  /* 1 */        2,               
  /* 2 - 3 */    3, 3,
  /* 4 - 7 */    5, 5, 5, 5,
  /* 8 - 23 */   8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
  /* 24 - 279 */ 13, 13, 13, 13, 13, 13, 13, 13
};


/*******************************************************************************
  This array gives the total number of bits needed for the encoding of 
  id components with values between -(DEFAULT_FAN_OUT - 1) and 0.
********************************************************************************/
const unsigned char OrdPath::theNegV2LMap[DEFAULT_FAN_OUT] = 
{
  /*   0      */    3, 
  /*  -1,   -4 */   6, 6, 6, 6,
  /*  -5,  -20 */   9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 
  /* -21, -276 */   14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14 
};


/*******************************************************************************
  This array maps each component value between 0 and DEFAULT_FAN_OUT - 1 to its
  encoded version.
********************************************************************************/
const uint16_t OrdPath::thePosV2EVMap[DEFAULT_FAN_OUT] = 
{
  0x2000,  // 0   = 001             -> 0010-0000-0000-0000

  0x4000,  // 1   = 01              -> 0100-0000-0000-0000

  0x8000,  // 2   = 10,0            -> 1000-0000-0000-0000
  0xA000,  // 3   = 10,1            -> 1010-0000-0000-0000

  0xC000,  // 4   = 110,00          -> 1100-0000-0000-0000
  0xC800,  // 5   = 110,01          -> 1100-1000-0000-0000 
  0xD000,  // 6   = 110,10          -> 1101-0000-0000-0000
  0xD800,  // 7   = 110,11          -> 1101-1000-0000-0000

  0xE000,  // 8   = 1110,0000       -> 1110-0000-0000-0000
  0xE100,  // 9   = 1110,0001       -> 1110-0001-0000-0000
  0xE200,  // 10  = 1110,0010       -> 1110-0010-0000-0000
  0xE300,  // 11  = 1110,0011       -> 1110-0011-0000-0000
  0xE400,  // 12  = 1110,0100       -> 1110-0100-0000-0000
  0xE500,  // 13  = 1110,0101       -> 1110-0101-0000-0000
  0xE600,  // 14  = 1110,0110       -> 1110-0110-0000-0000
  0xE700,  // 15  = 1110,0111       -> 1110-0111-0000-0000
  0xE800,  // 16  = 1110,1000       -> 1110-1000-0000-0000
  0xE900,  // 17  = 1110,1001       -> 1110-1001-0000-0000
  0xEA00,  // 18  = 1110,1010       -> 1110-1010-0000-0000
  0xEB00,  // 19  = 1110,1011       -> 1110-1011-0000-0000
  0xEC00,  // 20  = 1110,1100       -> 1110-1100-0000-0000
  0xED00,  // 21  = 1110,1101       -> 1110-1101-0000-0000
  0xEE00,  // 22  = 1110,1110       -> 1110-1110-0000-0000
  0xEF00,  // 23  = 1110,1111       -> 1110-1111-0000-0000

  0xF000,  // 24  = 11110,00000000  -> 1111-0000-0000-0000
  0xF008,  // 25  = 11110,00000001  -> 1111-0000-0000-1000
  0xF010,  // 26  = 11110,00000010  -> 1111-0000-0001-0000
  0xF018,  // 27  = 11110,00000011  -> 1111-0000-0001-1000
  0xF020,  // 28  = 11110,00000100  -> 1111-0000-0010-0000
  0xF028,  // 29  = 11110,00000101  -> 1111-0000-0010-1000
  0xF030,  // 30  = 11110,00000110  -> 1111-0000-0011-0000
  0xF038   // 31  = 11110,00000111  -> 1111-0000-0011-1000
};


/*******************************************************************************
  This array maps each component value between 0 and DEFAULT_FAN_OUT - 1 to its
  encoded version.
********************************************************************************/
const uint16_t OrdPath::theNegV2EVMap[DEFAULT_FAN_OUT] = 
{
  0x2000,  //  0   = 001               -> 0010-0000-0000-0000

  0x1C00,  // -1   = 0001,11           -> 0001-1100-0000-0000
  0x1800,  // -2   = 0001,10           -> 0001-1000-0000-0000
  0x1400,  // -3   = 0001,01           -> 0001-0100-0000-0000
  0x1000,  // -4   = 0001,00           -> 0001-0000-0000-0000

  0x0F80,  // -5   = 00001,1111        -> 0000-1111-1000-0000 
  0x0F00,  // -6   = 00001,1110        -> 0000-1111-0000-0000
  0x0E80,  // -7   = 00001,1101        -> 0000-1110-1000-0000
  0x0E00,  // -8   = 00001,1100        -> 0000-1110-0000-0000
  0x0D80,  // -9   = 00001,1011        -> 0000-1101-1000-0000
  0x0D00,  // -10  = 00001,1010        -> 0000-1101-0000-0000
  0x0C80,  // -11  = 00001,1001        -> 0000-1100-1000-0000
  0x0C00,  // -12  = 00001,1000        -> 0000-1100-0000-0000
  0x0B80,  // -13  = 00001,0111        -> 0000-1011-1000-0000
  0x0B00,  // -14  = 00001,0110        -> 0000-1011-0000-0000
  0x0A80,  // -15  = 00001,0101        -> 0000-1010-1000-0000
  0x0A00,  // -16  = 00001,0100        -> 0000-1010-0000-0000
  0x0980,  // -17  = 00001,0011        -> 0000-1001-1000-0000
  0x0900,  // -18  = 00001,0010        -> 0000-1001-0000-0000
  0x0880,  // -19  = 00001,0001        -> 0000-1000-1000-0000
  0x0800,  // -20  = 00001,0000        -> 0000-1000-0000-0000

  0x07FC,  // -21  = 000001,11111111   -> 0000-0111-1111-1100
  0x07F8,  // -22  = 000001,11111110   -> 0000-0111-1111-1000
  0x07F4,  // -23  = 000001,11111101   -> 0000-0111-1111-0100
  0x07F0,  // -24  = 000001,11111100   -> 0000-0111-1111-0000
  0x07EC,  // -25  = 000001,11111011   -> 0000-0111-1110-1100
  0x07E8,  // -26  = 000001,11111010   -> 0000-0111-1110-1000
  0x07E4,  // -27  = 000001,11111001   -> 0000-0111-1110-0100
  0x07E0,  // -28  = 000001,11111000   -> 0000-0111-1110-0000
  0x07DC,  // -29  = 000001,11110111   -> 0000-0111-1101-1100
  0x07D8,  // -30  = 000001,11110110   -> 0000-0111-1101-1000
  0x07D4   // -31  = 000001,11110101   -> 0000-0111-1101-0100
};


/*******************************************************************************

********************************************************************************/
void OrdPath::init()
{
  if (theBuffer != NULL)
    delete [] theBuffer;

  theBuffer = new unsigned char[2];
  theBuffer[0] = 2;
  theBuffer[1] = 0x40;
}


/*******************************************************************************

********************************************************************************/
OrdPath& OrdPath::operator=(const OrdPath& other)
{
  if (theBuffer != NULL)
    delete [] theBuffer;

  ulong len = other.getByteLength();
  if (len > 0)
  {
    theBuffer = new unsigned char[len];
    memcpy(theBuffer, other.theBuffer, len);
    theBuffer[0] = (unsigned char)len;
  }
  return *this;
}


/*******************************************************************************

********************************************************************************/
OrdPath& OrdPath::operator=(const OrdPathStack& ops)
{
  if (theBuffer != NULL)
    delete [] theBuffer;

  ulong len = ops.getByteLength();
  theBuffer = new unsigned char[len];
  memcpy(theBuffer, ops.theBuffer, len);
  theBuffer[0] = (unsigned char)len;
  return *this;
}


/*******************************************************************************

********************************************************************************/
ulong OrdPath::getByteLength() const
{
  if (theBuffer == NULL)
    return 0;

  return theBuffer[0];
}

#if 0
/*******************************************************************************

********************************************************************************/
bool OrdPath::operator==(const OrdPath& other) const
{
  ulong len = getByteLength();

  if (len != other.getByteLength())
    return false;

  return !memcmp(theBuffer, other.theBuffer, len);
}
#endif

/*******************************************************************************

********************************************************************************/
int OrdPath::operator<(const OrdPath& other) const
{
  ulong len1 = getByteLength();
  ulong len2 = other.getByteLength();

  unsigned char* p1 = &theBuffer[1];
  unsigned char* p2 = &other.theBuffer[1];

  if (len1 < len2)
  {
    unsigned char* end = p1 + (len1-1);

    while (p1 != end)
    {
      if (*p1 < *p2)
        return 1;
      else if (*p1 > *p2)
        return 0;

      p1++;
      p2++;
    }

    return 1;
  }
  else
  {
    unsigned char* end = p2 + (len2-1);

    while (p2 != end)
    {
      if (*p1 < *p2)
        return 1;
      else if (*p1 > *p2)
        return 0;

      p1++;
      p2++;
    }

    return 0;
  }
}


/*******************************************************************************

********************************************************************************/
int OrdPath::operator>(const OrdPath& other) const
{
  ulong len1 = getByteLength();
  ulong len2 = other.getByteLength();

  unsigned char* p1 = &theBuffer[1];
  unsigned char* p2 = &other.theBuffer[1];

  if (len1 <= len2)
  {
    unsigned char* end = p1 + (len1-1);

    while (p1 != end)
    {
      if (*p1 > *p2)
        return 1;
      else if (*p1 < *p2)
        return 0;

      p1++;
      p2++;
    }

    return 0;
  }
  else
  {
    unsigned char* end = p2 + (len2-1);

    while (p2 != end)
    {
      if (*p1 > *p2)
        return 1;
      else if (*p1 < *p2)
        return 0;

      p1++;
      p2++;
    }

    return 1;
  }
}


/*******************************************************************************

********************************************************************************/
void OrdPath::compress(const std::vector<long>& dewey)
{
  if (theBuffer != 0)
  {
    delete [] theBuffer;
    theBuffer = 0;
  }

  theBuffer = new unsigned char[MAX_BYTE_LEN];
  memset(theBuffer, 0, MAX_BYTE_LEN);

  ulong bitSize = 8;

  ulong numComps = dewey.size();
  for (ulong i = 0; i < numComps; i++)
    pushComp(dewey[i], bitSize);

  ulong byteSize = (bitSize + 7) / 8;

  unsigned char* newBuffer = new unsigned char[byteSize];
  memset(newBuffer, 0, byteSize);
  memcpy(newBuffer, theBuffer, byteSize);
  delete [] theBuffer;
  theBuffer = newBuffer;
  theBuffer[0] = byteSize;
}


/*******************************************************************************

********************************************************************************/
void OrdPath::insertBefore(
    const OrdPath& p1,
    OrdPath&       result)
{
}


/*******************************************************************************

********************************************************************************/
void OrdPath::insertAfter(
    const OrdPath& p1,
    OrdPath&       result)
{
}


/*******************************************************************************

********************************************************************************/
void OrdPath::insertInto(
    const OrdPath& p1,
    const OrdPath& p2,
    OrdPath&       result)
{
  assert(p1 < p2);

  ulong numComps1 = 0;
  ulong bitSize1 = 0;
  long dewey1[MAX_NUM_COMPS];
  ulong offsets1[MAX_NUM_COMPS];

  ulong numComps2;
  ulong bitSize2;
  long dewey2[MAX_BYTE_LEN];
  ulong offsets2[MAX_BYTE_LEN];

  // decompress all of p1.
  p1.decompress(8, dewey1, offsets1, numComps1, bitSize1);

  // Find the start of the last level-component in p1.
  ulong compPos = numComps1 - 2;
  while (compPos > 0 && dewey1[compPos] % 2 == 0)
    compPos--;
  compPos++;

  // decompress the last level-component of p2.
  numComps2 = compPos;
  bitSize2 = offsets1[compPos];
  p2.decompress(bitSize2, dewey2, offsets2, numComps2, bitSize2);

  // Within the last level-component, find the 1st pair of differing comps.
  while (dewey1[compPos] == dewey2[compPos])
  {
    compPos++;
    ZORBA_ASSERT(compPos < numComps1 && compPos < numComps2);
  }

  long comp1 = dewey1[compPos];
  long comp2 = dewey2[compPos];
  bool odd1 = (comp1 % 2 != 0);
  bool odd2 = (comp2 % 2 != 0);

  ZORBA_ASSERT(comp1 < comp2);

  ulong diff = comp2 - comp1;

  long newcomp1;
  long newcomp2 = 0;
  ulong commonBitSize;
  ulong newBits = 0;
  ulong bitSize;
  uint32_t dummy;

  bool copy1 = true;

  // If there is an odd number between comp1 and comp2, use it
  if (diff > 2 || (!odd1 && diff == 2))
  {
    commonBitSize = offsets1[compPos];

    newcomp1 = comp1 + diff / 2;
    if (newcomp1 % 2 == 0)
      newcomp1++;

    bitsNeeded(newcomp1, newBits, dummy);
  }
  // Else if comp1 and comp2 are 2 consecutive odd numbers...
  else if (odd1 && odd2)
  {
    commonBitSize = offsets1[compPos];

    newcomp1 = comp1 + 1;
    newcomp2 = 1;

    bitsNeeded(newcomp1, newBits, dummy);
    newBits += 2;
  }
  // Else if comp1 is odd and comp2 == comp1 + 1, keep comp2 and add
  // dewey2[compPos+1] - (1 or 2)
  else if (odd1)
  {
    commonBitSize = offsets2[compPos+1];

    newcomp1 = dewey2[compPos+1];
    if (newcomp1 % 2 == 0)
      newcomp1 -= 1;
    else
      newcomp1 -= 2;

    bitsNeeded(newcomp1, newBits, dummy);
    copy1 = false;
  }
  // Else if comp2 is odd and comp1 == comp2 - 1, keep comp1 and add
  // dewey1[compPos+1] + (1 or 2)
  else if (odd2)
  {
    commonBitSize = offsets1[compPos+1];

    newcomp1 = dewey1[compPos+1];
    if (newcomp1 % 2 == 0)
      newcomp1 += 1;
    else
      newcomp1 += 2;

    bitsNeeded(newcomp1, newBits, dummy);
  }
  else
  {
    ZORBA_ASSERT(0);
  }

  bitSize = commonBitSize + newBits;
  ulong commonByteSize = (commonBitSize + 7) / 8;
  ulong byteSize = (bitSize + 7) / 8;
  result.theBuffer = new unsigned char[byteSize];
  memset(result.theBuffer, 0, byteSize);
  memcpy(result.theBuffer, (copy1 ? p1.theBuffer : p2.theBuffer), commonByteSize);
  result.theBuffer[0] = (unsigned char)byteSize;
  if (commonBitSize % 8 != 0)
    result.theBuffer[commonByteSize-1] &= (0xff << (8 - commonBitSize % 8));

  result.pushComp(newcomp1, commonBitSize);
  if (newcomp2 != 0)
    result.pushComp(newcomp2, commonBitSize);
}


/*******************************************************************************

********************************************************************************/
void OrdPath::pushComp(long value, ulong& bitSize)
{
  assert(bitSize >= 8);

  uint32_t eval;
  ulong bitsNeeded;

  ulong byteIndex = bitSize / 8;

  ulong bitsAvailable = 8 - bitSize % 8;
  if (bitsAvailable == 0)
    bitsAvailable = 8;

  OrdPath::bitsNeeded(value, bitsNeeded, eval);

  ulong bytesNeeded = byteIndex + (bitsNeeded + 15 - bitsAvailable) / 8;
  if (bytesNeeded > OrdPath::MAX_BYTE_LEN)
  {
    ZORBA_ERROR_ALERT_OSS(ZorbaError::XQP0018_NODEID_ERROR,
                          NULL, DONT_CONTINUE_EXECUTION,
                          "A nodeid requires more than " << OrdPath::MAX_BYTE_LEN
                          << " bytes", "");
  }

  do
  {
    ulong bitsUsed = (bitsNeeded < bitsAvailable ?
                      bitsNeeded : bitsAvailable);

    unsigned char byte = (unsigned char)
                         ((eval & OrdPath::theValueMasks[bitsUsed]) >>
                          (32 - bitsAvailable));

    theBuffer[byteIndex] |= byte;
    eval = eval << bitsUsed;
    bitsNeeded -= bitsUsed;
    bitsAvailable -= bitsUsed;
    ulong zerone = (bitsAvailable + 7) / 8;
    bitsAvailable = bitsAvailable * zerone + 8 * (1 - zerone);
    byteIndex += (1 - zerone);
  }
  while (bitsNeeded > 0);

  bitSize = (byteIndex * 8 + (8 - bitsAvailable));
}


/*******************************************************************************

********************************************************************************/
void OrdPath::appendComp(long value)
{
  uint32_t eval;
  ulong bitsNeeded;

  if (theBuffer == NULL)
  {
    theBuffer = new unsigned char[2];
    theBuffer[0] = 2;
    theBuffer[1] = 0;
  }

  ulong byteIndex = getByteLength() - 1;
  ulong bitsAvailable = 0;

  unsigned char lastByte = theBuffer[byteIndex];
  while (bitsAvailable < 8 && (lastByte & 0x01) == 0)
  {
    lastByte >>= 1;
    bitsAvailable++;
  }
  
  OrdPath::bitsNeeded(value, bitsNeeded, eval);

  ulong bytesNeeded = byteIndex + (bitsNeeded + 15 - bitsAvailable) / 8;
  if (bytesNeeded > OrdPath::MAX_BYTE_LEN)
  {
    ZORBA_ERROR_ALERT_OSS(ZorbaError::XQP0018_NODEID_ERROR,
                          NULL, DONT_CONTINUE_EXECUTION,
                          "A nodeid requires more than " << OrdPath::MAX_BYTE_LEN
                          << " bytes", "");
  }

  if (bytesNeeded > byteIndex + 1)
  {
    unsigned char* newBuffer = new unsigned char[bytesNeeded];
    memset(newBuffer, 0, bytesNeeded);
    memcpy(newBuffer, theBuffer, byteIndex+1);
    delete [] theBuffer;
    theBuffer = newBuffer;
    theBuffer[0] = bytesNeeded;
  }

  do
  {
    ulong bitsUsed = (bitsNeeded < bitsAvailable ?
                      bitsNeeded : bitsAvailable);

    unsigned char byte = (unsigned char)
                         ((eval & OrdPath::theValueMasks[bitsUsed]) >>
                          (32 - bitsAvailable));

    theBuffer[byteIndex] |= byte;
    eval = eval << bitsUsed;
    bitsNeeded -= bitsUsed;
    bitsAvailable -= bitsUsed;
    ulong zerone = (bitsAvailable + 7) / 8;
    bitsAvailable = bitsAvailable * zerone + 8 * (1 - zerone);
    byteIndex += (1 - zerone);
  }
  while (bitsNeeded > 0);
}


/*******************************************************************************

********************************************************************************/
void OrdPath::bitsNeeded(long value, ulong& bitsNeeded, uint32_t& eval)
{
  if (value < 0)
  {
    value = -value;

    if (value < OrdPath::DEFAULT_FAN_OUT)
    {
      bitsNeeded = OrdPath::theNegV2LMap[value];
      eval = OrdPath::theNegV2EVMap[value] << 16;
    }
    else if (value < 277)
    {
      bitsNeeded = 14;

      value = 276 - value;
      eval = ((uint32_t)value) << 24;
      eval >>= 6;
      eval |= 0x04000000;
    }
    else if (value < 4373)
    {
      bitsNeeded = 19;

      value = 2372 - value;
      eval = ((uint32_t)value) << 20;
      eval >>= 7;
      eval |= 0x02000000;
    }
    else if (value < 69909)
    {
      bitsNeeded = 24;

      value = 69908 - value;
      eval = ((uint32_t)value) << 16;
      eval >>= 8;
      eval |= 0x01000000;
    }
    else if (value < 1118485)
    {
      bitsNeeded = 29;

      value = 1118484 - value;
      eval = ((uint32_t)value) << 12;
      eval >>= 9;
      eval |= 0x00080000;
    }
    else
    {
      ZORBA_ERROR_ALERT(ZorbaError::XQP0018_NODEID_ERROR,
                        NULL, DONT_CONTINUE_EXECUTION,
                        "A nodeid component is too large to be encoded");
      return;
    }
  }
  else if (value < OrdPath::DEFAULT_FAN_OUT)
  {
    bitsNeeded = OrdPath::thePosV2LMap[value];
    eval = OrdPath::thePosV2EVMap[value] << 16;
  }
  else
  {
    if (value < 280)
    {
      bitsNeeded = 13;

      value -= 24;
      eval = ((uint32_t)value) << 24;
      while (!(eval & 0x8FFFFFFF))
        eval <<= 1;

      eval >>= 5;
      eval |= 0xF0000000;
    }
    else if (value < 4376)
    {
      bitsNeeded = 18;

      value -= 280;
      eval = ((uint32_t)value) << 20;
      while (!(eval & 0x8FFFFFFF))
        eval <<= 1;

      eval >>= 6;
      eval |= 0xF8000000;
    }
    else if (value < 69912)
    {
      bitsNeeded = 23;

      value -= 4376;
      eval = ((uint32_t)value) << 16;
      while (!(eval & 0x8FFFFFFF))
        eval <<= 1;

      eval >>= 7;
      eval |= 0xFC000000;
    }
    else if (value < 1118488)
    {
      bitsNeeded = 28;

      value -= 69912;
      eval = ((uint32_t)value) << 12;
      while (!(eval & 0x8FFFFFFF))
        eval <<= 1;

      eval >>= 8;
      eval |= 0xFE000000;
    }
    else
    {
      ZORBA_ERROR_ALERT(ZorbaError::XQP0018_NODEID_ERROR,
                        NULL, DONT_CONTINUE_EXECUTION,
                        "A nodeid component is too large to be encoded");
      return;
    }
  }
}


/*******************************************************************************

********************************************************************************/
std::string OrdPath::show() const
{
  std::stringstream str;

  str << "";

  if (theBuffer == NULL)
    return str.str().c_str();

  ulong len = getByteLength();
  for (ulong i = 1; i < len; i++)
  {
    str << std::hex << (unsigned short)theBuffer[i] << '|';
  }

  str << " ";

  ulong numComps = 0;
  ulong bitSize = 0;
  long deweyid[MAX_NUM_COMPS];
  ulong offsets[MAX_NUM_COMPS];

  decompress(8, deweyid, offsets, numComps, bitSize);

  for (ulong i = 0; i < numComps; i++)
  {
    str << std::dec << deweyid[i];
    if (i < numComps-1)
      str << ".";
  }

  return str.str().c_str();
}


/*******************************************************************************

********************************************************************************/
void OrdPath::decompress(
    ulong  startOffset,
    long*  deweyid,
    ulong* compOffsets,
    ulong& numComps,
    ulong& bitSize) const
{
  assert(startOffset >= 8);

  ulong byteIndex = startOffset / 8;
  ulong bitIndex = startOffset % 8;

  ulong len = getByteLength() - 1;

  bitSize = byteIndex * 8 + bitIndex;

  while (byteIndex < len)
  {
    unsigned char byte0 = theBuffer[byteIndex] & theByteMasks[bitIndex][0];
    unsigned char byte1 = theBuffer[byteIndex+1] & theByteMasks[bitIndex][1];
    unsigned char byte = (byte0 << bitIndex) | (byte1 >> (8 - bitIndex));

    decodeByte(deweyid, compOffsets, numComps, bitSize,
               byteIndex, bitIndex, byte);
  }

  // Treat the last byte
  if (byteIndex == len)
  {
    unsigned char lastByte = theBuffer[byteIndex];
    Assert(lastByte != 0);
    lastByte <<= bitIndex;
    if (lastByte != 0)
      decodeByte(deweyid, compOffsets, numComps, bitSize,
                 byteIndex, bitIndex, lastByte);
  }

#if 0
  for (ulong i = 0; i < numComps; i++)
  {
    if (deweyid[i] <= 0 || deweyid[i] % 2 == 0)
      ZORBA_ASSERT(0);
  }
#endif
}


/*******************************************************************************

********************************************************************************/
#define ADVANCE(bitSize, byteIndex, bitIndex, numBits) \
{                                                      \
  (bitSize) += (numBits);                              \
  (byteIndex) += ((bitIndex) + (numBits)) / 8;         \
  (bitIndex) = ((bitIndex) + (numBits)) % 8;           \
}


/*******************************************************************************

********************************************************************************/
void OrdPath::decodeByte(
    long*         deweyid,
    ulong*        compOffsets,
    ulong&        numComps,
    ulong&        bitSize,
    ulong&        byteIndex,
    ulong&        bitIndex,
    unsigned char byte) const
{
  compOffsets[numComps] = bitSize;

  switch (byte)
  {
  case 0:    // 0000 0000   00000000 ...            (29/9,20)
  {
    ADVANCE(bitSize, byteIndex, bitIndex, 9);
    extractValue(bitSize, byteIndex, bitIndex, 20, -1118484, deweyid[numComps]);
    numComps += 1;    
    break;
  }
  case 1:    // 0000 0001   00000001,...            (24/8,16)
  {
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    extractValue(bitSize, byteIndex, bitIndex, 16, -69908, deweyid[numComps]);
    numComps += 1;
    break;
  }
  case 2:    // 0000 0010   0000001,0...            (19/7,12)
  {
    ADVANCE(bitSize, byteIndex, bitIndex, 7);
    extractValue(bitSize, byteIndex, bitIndex, 12, -4372, deweyid[numComps]);
    numComps += 1;
    break;
  }
  case 3:    // 0000 0011   0000001,1...            (19/7,12)
  {
    ADVANCE(bitSize, byteIndex, bitIndex, 7);
    extractValue(bitSize, byteIndex, bitIndex, 12, -4372, deweyid[numComps]);
    numComps += 1;
    break;
  }
  case 4:    // 0000 0100   000001,00...            (14/6,8)
  {
    ADVANCE(bitSize, byteIndex, bitIndex, 6);
    extractValue(bitSize, byteIndex, bitIndex, 8, -276, deweyid[numComps]);
    numComps += 1;
    break;
  }
  case 5:    // 0000 0101   000001,01..             (14/6,8)
  {
    ADVANCE(bitSize, byteIndex, bitIndex, 6);
    extractValue(bitSize, byteIndex, bitIndex, 8, -276, deweyid[numComps]);
    numComps += 1;
    break;
  }
  case 6:    // 0000 0110   000001,10...            (14/6,8)
  {
    ADVANCE(bitSize, byteIndex, bitIndex, 6);
    extractValue(bitSize, byteIndex, bitIndex, 8, -276, deweyid[numComps]);
    numComps += 1;
    break;
  }
  case 7:    // 0000 0111   000001,11...            (14/6,8)
  {
    ADVANCE(bitSize, byteIndex, bitIndex, 6);
    extractValue(bitSize, byteIndex, bitIndex, 8, -276, deweyid[numComps]);
    numComps += 1;
    break;
  }
  case 8:    // 0000 1000   00001,000...            (9/5,4)
  {
    ADVANCE(bitSize, byteIndex, bitIndex, 5);
    extractValue(bitSize, byteIndex, bitIndex, 4, -20, deweyid[numComps]);
    numComps += 1;
    break;
  }
  case 9:    // 0000 1001   00001,001...            (9/5,4)
  {
    ADVANCE(bitSize, byteIndex, bitIndex, 5);
    extractValue(bitSize, byteIndex, bitIndex, 4, -20, deweyid[numComps]);
    numComps += 1;
    break;
  }
  case 10:   // 0000 1010   00001,010...            (9/5,4)
  {
    ADVANCE(bitSize, byteIndex, bitIndex, 5);
    extractValue(bitSize, byteIndex, bitIndex, 4, -20, deweyid[numComps]);
    numComps += 1;
    break;
  }
  case 11:   // 0000 1011   00001,011...            (9/5,4)
  {
    ADVANCE(bitSize, byteIndex, bitIndex, 5);
    extractValue(bitSize, byteIndex, bitIndex, 4, -20, deweyid[numComps]);
    numComps += 1;
    break;
  }
  case 12:   // 0000 1100   00001,100...            (9/5,4)
  {
    ADVANCE(bitSize, byteIndex, bitIndex, 5);
    extractValue(bitSize, byteIndex, bitIndex, 4, -20, deweyid[numComps]);
    numComps += 1;
    break;
  }
  case 13:   // 0000 1101   00001,101...            (9/5,4)
  {
    ADVANCE(bitSize, byteIndex, bitIndex, 5);
    extractValue(bitSize, byteIndex, bitIndex, 4, -20, deweyid[numComps]);
    numComps += 1;
    break;
  }
  case 14:   // 0000 1110   00001,110...            (9/5,4)
  {
    ADVANCE(bitSize, byteIndex, bitIndex, 5);
    extractValue(bitSize, byteIndex, bitIndex, 4, -20, deweyid[numComps]);
    numComps += 1;
    break;
  }
  case 15:   // 0000 1111   00001,111...            (9/5,4)
  {
    ADVANCE(bitSize, byteIndex, bitIndex, 5);
    extractValue(bitSize, byteIndex, bitIndex, 4, -20, deweyid[numComps]);
    numComps += 1;
    break;
  }


  case 16:   // 0001 0000   0001,00 + 00...       (6/4,2)
  {
    deweyid[numComps] = -4;    
    ADVANCE(bitSize, byteIndex, bitIndex, 6);
    numComps += 1;
    break;
  }
  case 17:   // 0001 0001   0001,00 + 01 +        (6/4,2 + 2/2,0)
  {
    deweyid[numComps] = -4; 
    deweyid[numComps+1] = 1;
    compOffsets[numComps+1] = bitSize + 6;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 18:   // 0001 0010   0001,00 + 10, ...     (6/4,2 + 3/2,1)
  {
    compOffsets[numComps+1] = bitSize + 6;
    deweyid[numComps] = -4; 
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    extractValue(bitSize, byteIndex, bitIndex, 1, 2, deweyid[numComps+1]);
    numComps += 2;
    break;
  }
  case 19:   // 0001 0011   0001,00 + 11...       (6/4,2)
  {
    deweyid[numComps] = -4;
    ADVANCE(bitSize, byteIndex, bitIndex, 6);
    numComps += 1;
    break;
  }
  case 20:   // 0001 0100   0001,01 + 00...       (6/4,2)
  {
    deweyid[numComps] = -3; 
    ADVANCE(bitSize, byteIndex, bitIndex, 6);
    numComps += 1;
    break;
  }
  case 21:   // 0001 0101   0001,01 + 01 +        (6/4,2 + 2/2,0)
  {
    compOffsets[numComps+1] = bitSize + 6;
    deweyid[numComps] = -3; 
    deweyid[numComps+1] = 1;    
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 22:   // 0001 0110   0001,01 + 10, ...     (6/4,2 + 3/2,1)
  {
    compOffsets[numComps+1] = bitSize + 6;
    deweyid[numComps] = -3;    
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    extractValue(bitSize, byteIndex, bitIndex, 1, 2, deweyid[numComps+1]);
    numComps += 2;
    break;
  }
  case 23:   // 0001 0111   0001,01 + 11...       (6/4,2)
  {
    deweyid[numComps] = -3;    
    ADVANCE(bitSize, byteIndex, bitIndex, 6);
    numComps += 1;
    break;
  }
  case 24:   // 0001 1000   0001,10 + 00...       (6/4,2)
  {
    deweyid[numComps] = -2;    
    ADVANCE(bitSize, byteIndex, bitIndex, 6);
    numComps += 1;
    break;
  }
  case 25:   // 0001 1001   0001,10 + 01 +        (6/4,2 + 2/2,0)
  {
    compOffsets[numComps+1] = bitSize + 6;
    deweyid[numComps] = -2; 
    deweyid[numComps+1] = 1;    
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 26:   // 0001 1010   0001,10 + 10, ...     (6/4,2 + 3/2,1)
  {
    compOffsets[numComps+1] = bitSize + 6;
    deweyid[numComps] = -2;    
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    extractValue(bitSize, byteIndex, bitIndex, 1, 2, deweyid[numComps+1]);
    numComps += 2;
    break;
  }
  case 27:   // 0001 1011   0001,10 + 11 ...      (6/4,2)
  {
    deweyid[numComps] = -2;    
    ADVANCE(bitSize, byteIndex, bitIndex, 6);
    numComps += 1;
    break;
  }
  case 28:   // 0001 1100   0001,11 + 00 ...        (6/4,2)
  {
    deweyid[numComps] = -1;    
    ADVANCE(bitSize, byteIndex, bitIndex, 6);
    numComps += 1;
    break;
  }
  case 29:   // 0001 1101   0001,11 + 01 +          (6/4,2 + 2/2,0)
  {
    compOffsets[numComps+1] = bitSize + 6;
    deweyid[numComps] = -1; 
    deweyid[numComps+1] = 1;    
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 30:   // 0001 1110   0001,11 + 10, ...       (6/4,2 + 3/2,1)
  {
    compOffsets[numComps+1] = bitSize + 6;
    deweyid[numComps] = -1;    
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    extractValue(bitSize, byteIndex, bitIndex, 1, 2, deweyid[numComps+1]);
    numComps += 2;
    break;
  }
  case 31:   // 0001 1111   0001,11 + 11 ...        (6/4,2)
  {
    deweyid[numComps] = -2;    
    ADVANCE(bitSize, byteIndex, bitIndex, 6);
    numComps += 1;
    break;
  }
  

  case 32:   // 0010 0000   001 + 00000 ...         (3/3,0)
  {
    deweyid[numComps] = 0;    
    ADVANCE(bitSize, byteIndex, bitIndex, 3);
    numComps += 1;
    break;
  }
  case 33:   // 0010 0001   001 + 00001, ...        (3/3,0 + 9/5,4)
  {
    compOffsets[numComps+1] = bitSize + 3;
    deweyid[numComps] = 0;    
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    extractValue(bitSize, byteIndex, bitIndex, 4, -20, deweyid[numComps+1]);
    numComps += 2;
    break;
  }
  case 34:   // 0010 0010   001 + 0001,0...         (3/3,0 + 6/4,2)
  {
    compOffsets[numComps+1] = bitSize + 3;
    deweyid[numComps] = 0;    
    ADVANCE(bitSize, byteIndex, bitIndex, 7);
    extractValue(bitSize, byteIndex, bitIndex, 2, -4, deweyid[numComps+1]);
    numComps += 2;
    break;
  }
  case 35:   // 0010 0011   001 + 0001,1...         (3/3,0 + 4/3,1)
  {
    compOffsets[numComps+1] = bitSize + 3;
    deweyid[numComps] = 0;
    ADVANCE(bitSize, byteIndex, bitIndex, 7);
    extractValue(bitSize, byteIndex, bitIndex, 2, -4, deweyid[numComps+1]);
    numComps += 2;
    break;
  }
  case 36:   // 0010 0100   001+001 + 00...         (3/3,0 + 3/3,0)
  {
    compOffsets[numComps+1] = bitSize + 3;
    deweyid[numComps] = 0;
    deweyid[numComps+1] = 0;
    ADVANCE(bitSize, byteIndex, bitIndex, 6);
    numComps += 2;
    break;
  }
  case 37:   // 0010 0101   001 + 001 + 01...       (3/3,0 + 3/3,0)
  {
    compOffsets[numComps+1] = bitSize + 3;
    deweyid[numComps] = 0;
    deweyid[numComps+1] = 0;
    ADVANCE(bitSize, byteIndex, bitIndex, 6);
    numComps += 2;
    break;
  }
  case 38:   // 0010 0110   001 + 001 + 10...       (3/3,0 + 3/3,0)
  {
    compOffsets[numComps+1] = bitSize + 3;
    deweyid[numComps] = 0;
    deweyid[numComps+1] = 0;
    ADVANCE(bitSize, byteIndex, bitIndex, 6);
    numComps += 2;
    break;
  }
  case 39:   // 0010 0111   001 + 001 + 11 ...     (3/3,0 + 3/3,0)
  {
    compOffsets[numComps+1] = bitSize + 3;
    deweyid[numComps] = 0;
    deweyid[numComps+1] = 0;
    ADVANCE(bitSize, byteIndex, bitIndex, 6);
    numComps += 2;
    break;
  }
  case 40:   // 0010 1000   001 + 01 + 000...       (3/3,0 + 2/2,0)
  {
    compOffsets[numComps+1] = bitSize + 3;
    deweyid[numComps] = 0;
    deweyid[numComps+1] = 1;
    ADVANCE(bitSize, byteIndex, bitIndex, 5);
    numComps += 2;
    break;
  }
  case 41:   // 0010 1001   001 + 01 + 001 +        (3/3,0 + 2/2,0 + 3/3,0)
  {
    compOffsets[numComps+1] = bitSize + 3;
    compOffsets[numComps+2] = bitSize + 5;
    deweyid[numComps] = 0;
    deweyid[numComps+1] = 1;
    deweyid[numComps+2] = 0;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 42:   // 0010 1010   001 + 01 + 01 + 0...    (3/3,0 + 2/2,0 + 2/2,0)
  {
    compOffsets[numComps+1] = bitSize + 3;
    compOffsets[numComps+2] = bitSize + 5;
    deweyid[numComps] = 0;
    deweyid[numComps+1] = 1;
    deweyid[numComps+2] = 1;
    ADVANCE(bitSize, byteIndex, bitIndex, 7);
    numComps += 3;
    break;
  }
  case 43:   // 0010 1011   001 + 01 + 01 + 1 ...   (3/3,0 + 2/2,0 + 2/2,0)
  {
    compOffsets[numComps+1] = bitSize + 3;
    compOffsets[numComps+2] = bitSize + 5;
    deweyid[numComps] = 0;
    deweyid[numComps+1] = 1;
    deweyid[numComps+2] = 1;
    ADVANCE(bitSize, byteIndex, bitIndex, 7);
    numComps += 3;
    break;
  }
  case 44:   // 0010 1100   001 + 01 + 10,0 +       (3/3,0 + 2/2,0, 3/2,1)
  {
    compOffsets[numComps+1] = bitSize + 3;
    compOffsets[numComps+2] = bitSize + 5;
    deweyid[numComps] = 0;
    deweyid[numComps+1] = 1;
    deweyid[numComps+2] = 2;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 45:   // 0010 1101   001 + 01 + 10,1 +       (3/3,0 + 2/2,0, 3/3,1)
  {
    compOffsets[numComps+1] = bitSize + 3;
    compOffsets[numComps+2] = bitSize + 5;
    deweyid[numComps] = 0;
    deweyid[numComps+1] = 1;
    deweyid[numComps+2] = 3;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 46:   // 0010 1110   001 + 01 + 110, ...     (3/3,0 + 2/2,0 + 5/3,2)
  {
    compOffsets[numComps+1] = bitSize + 3;
    compOffsets[numComps+2] = bitSize + 5;
    deweyid[numComps] = 0;
    deweyid[numComps+1] = 1;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    extractValue(bitSize, byteIndex, bitIndex, 2, 4, deweyid[numComps + 2]);
    numComps += 3;
    break;
  }
  case 47:   // 0010 1111   001 + 01 + 111 ...      (3/3,0 + 2/2,0)
  {
    compOffsets[numComps+1] = bitSize + 3;
    deweyid[numComps] = 0;
    deweyid[numComps+1] = 1;
    ADVANCE(bitSize, byteIndex, bitIndex, 5);
    numComps += 2;
    break;
  }

  case 48:   // 0011 0000   001 + 10,0 + 00 ...     (3/3,0 + 3/2,1)
  {
    compOffsets[numComps+1] = bitSize + 3;
    deweyid[numComps] = 0;
    deweyid[numComps+1] = 2;
    ADVANCE(bitSize, byteIndex, bitIndex, 6);
    numComps += 2;
    break;
  }
  case 49:   // 0011 0001   001 + 10,0 + 01 +       (3/3,0 + 3/2,1 + 2/2,0)
  {
    compOffsets[numComps+1] = bitSize + 3;
    compOffsets[numComps+2] = bitSize + 6;
    deweyid[numComps] = 0;
    deweyid[numComps+1] = 2;
    deweyid[numComps+2] = 1;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 50:   // 0011 0010   001 + 10,0 + 10, ...    (3/3,0 + 3/2,1 + 3/2,1)
  {
    compOffsets[numComps+1] = bitSize + 3;
    compOffsets[numComps+2] = bitSize + 6;
    deweyid[numComps] = 0;
    deweyid[numComps+1] = 2;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    extractValue(bitSize, byteIndex, bitIndex, 1, 2, deweyid[numComps + 2]);
    numComps += 3;
    break;
  }
  case 51:   // 0011 0011   001 + 10,0 + 11...      (3/3,0 + 3/2,1)
  {
    compOffsets[numComps+1] = bitSize + 3;
    deweyid[numComps] = 0;
    deweyid[numComps+1] = 2;
    ADVANCE(bitSize, byteIndex, bitIndex, 6);
    numComps += 2;
    break;
  }
  case 52:   // 0011 0100   001 + 10,1 + 00 ...     (3/3,0 + 3/2,1)
  {
    compOffsets[numComps+1] = bitSize + 3;
    deweyid[numComps] = 0;
    deweyid[numComps+1] = 3;
    ADVANCE(bitSize, byteIndex, bitIndex, 6);
    numComps += 2;
    break;
  }
  case 53:   // 0011 0101   001 + 10,1 + 01 +       (3/3,0 + 3/2,1 + 2/2,0)
  {
    compOffsets[numComps+1] = bitSize + 3;
    compOffsets[numComps+2] = bitSize + 6;
    deweyid[numComps] = 0;
    deweyid[numComps+1] = 3;
    deweyid[numComps+2] = 1;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 54:   // 0011 0110   001 + 10,1 + 10, ...    (3/3,0 + 3/2,1 + 3/2,1)
  {
    compOffsets[numComps+1] = bitSize + 3;
    compOffsets[numComps+2] = bitSize + 6;
    deweyid[numComps] = 0;
    deweyid[numComps+1] = 3;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    extractValue(bitSize, byteIndex, bitIndex, 1, 2, deweyid[numComps + 2]);
    numComps += 3;
    break;
  }
  case 55:   // 0011 0111   001 + 10,1 + 11 ...     (3/3,0 + 3/2,1)
  {
    compOffsets[numComps+1] = bitSize + 3;
    deweyid[numComps] = 0;
    deweyid[numComps+1] = 3;
    ADVANCE(bitSize, byteIndex, bitIndex, 6);
    numComps += 2;
    break;
  }
  case 56:   // 0011 1000   001 + 110,00 +          (3/3,0 + 5/3,2)
  {
    compOffsets[numComps+1] = bitSize + 3;
    deweyid[numComps] = 0;
    deweyid[numComps+1] = 4;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 57:   // 0011 1001   001 + 110,01 +          (3/3,0 + 5/3,2)
  {
    compOffsets[numComps+1] = bitSize + 3;
    deweyid[numComps] = 0;
    deweyid[numComps+1] = 5;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 58:   // 0011 1010   001 + 110,10 +          (3/3,0 + 5/3,2)
  {
    compOffsets[numComps+1] = bitSize + 3;
    deweyid[numComps] = 0;
    deweyid[numComps+1] = 6;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 59:   // 0011 1011   001 + 110,11 +          (3/3,0 + 5/3,2)
  {
    compOffsets[numComps+1] = bitSize + 3;
    deweyid[numComps] = 0;
    deweyid[numComps+1] = 7;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 60:   // 0011 1100   001 + 1110,0 ...        (3/3,0 + 8/4,4)
  {
    compOffsets[numComps+1] = bitSize + 3;
    deweyid[numComps] = 0;
    ADVANCE(bitSize, byteIndex, bitIndex, 7);
    extractValue(bitSize, byteIndex, bitIndex, 4, 8, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }
  case 61:   // 0011 1101   001 + 1110,1 ...        (3/3,0 + 8/4,4)
  {
    compOffsets[numComps+1] = bitSize + 3;
    deweyid[numComps] = 0;
    ADVANCE(bitSize, byteIndex, bitIndex, 7);
    extractValue(bitSize, byteIndex, bitIndex, 4, 8, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }
  case 62:   // 0011 1110   001 + 11110, ...        (3/3,0 + 13/5,8)
  {
    compOffsets[numComps+1] = bitSize + 3;
    deweyid[numComps] = 0;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    extractValue(bitSize, byteIndex, bitIndex, 8, 24, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }
  case 63:   // 0011 1111   001 + 11111 ...         (3/3,0)
  {
    deweyid[numComps] = 0;
    ADVANCE(bitSize, byteIndex, bitIndex, 3);
    numComps += 1;
    break;
  }


  case 64:   // 0100 0000   01 + 000000 ...         (2/2,0)
  {
    deweyid[numComps] = 1;
    numComps++;
    ADVANCE(bitSize, byteIndex, bitIndex, 2);
    break;
  }
  case 65:   // 0100 0001   01 + 000001, ...        (2/2,0 + 14/6,8)
  {
    compOffsets[numComps+1] = bitSize + 2;
    deweyid[numComps] = 1;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    extractValue(bitSize, byteIndex, bitIndex, 8, -276, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }
  case 66:   // 0100 0010   01 + 00001,0 ...        (2/2,0 + 9/5,4)
  {
    compOffsets[numComps+1] = bitSize + 2;
    deweyid[numComps] = 1;
    ADVANCE(bitSize, byteIndex, bitIndex, 7);
    extractValue(bitSize, byteIndex, bitIndex, 4, -20, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }
  case 67:   // 0100 0011   01 + 00001,1 ...      (2/2,0 + 9/5,4)
  {
    compOffsets[numComps+1] = bitSize + 2;
    deweyid[numComps] = 1;
    ADVANCE(bitSize, byteIndex, bitIndex, 7);
    extractValue(bitSize, byteIndex, bitIndex, 4, -20, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }
  case 68:   // 0100 0100   01 + 0001,00 +        (2/2,0 + 6/4,2)
  {
    compOffsets[numComps+1] = bitSize + 2;
    deweyid[numComps] = 1;
    deweyid[numComps+1] = -4;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 69:   // 0100 0101   01 + 0001,01 +        (2/2,0 + 6/4,2)
  {
    compOffsets[numComps+1] = bitSize + 2;
    deweyid[numComps] = 1;
    deweyid[numComps+1] = -3;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 70:   // 0100 0110   01 + 0001,10 +          (2/2,0 + 6/4,2)
  {
    compOffsets[numComps+1] = bitSize + 2;
    deweyid[numComps] = 1;
    deweyid[numComps+1] = -2;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 71:   // 0100 0111   01 + 0001,11 +          (2/2,0 + 6/4,2)
  {
    compOffsets[numComps+1] = bitSize + 2;
    deweyid[numComps] = 1;
    deweyid[numComps+1] = -1;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  
  case 72:   // 0100 1000   01 + 001 + 000 ...      (2/2,0 + 3/3,0)
  {
    compOffsets[numComps+1] = bitSize + 2;
    deweyid[numComps] = 1;
    deweyid[numComps+1] = 0;
    ADVANCE(bitSize, byteIndex, bitIndex, 5);
    numComps += 2;
    break;
  }
  case 73:   // 0100 1001   01 + 001 + 001 +        (2/2,0 + 3/3,0 + 3/3,0)
  {
    compOffsets[numComps+1] = bitSize + 2;
    compOffsets[numComps+2] = bitSize + 5;
    deweyid[numComps] = 1;
    deweyid[numComps+1] = 0;
    deweyid[numComps+2] = 0;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 74:   // 0100 1010   01 + 001 + 01 + 0 ...   (2/2,0 + 3/3,0 + 2/2,0)
  {
    compOffsets[numComps+1] = bitSize + 2;
    compOffsets[numComps+2] = bitSize + 5;
    deweyid[numComps] = 1;
    deweyid[numComps+1] = 0;
    deweyid[numComps+2] = 1;
    ADVANCE(bitSize, byteIndex, bitIndex, 7);
    numComps += 3;
    break;
  }
  case 75:   // 0100 1011   01 + 001 + 01 + 1 ...   (2/2,0 + 3/3,0 + 2/2,0)
  {
    compOffsets[numComps+1] = bitSize + 2;
    compOffsets[numComps+2] = bitSize + 5;
    deweyid[numComps] = 1;
    deweyid[numComps+1] = 0;
    deweyid[numComps+2] = 1;
    ADVANCE(bitSize, byteIndex, bitIndex, 7);
    numComps += 3;
    break;
  }
  case 76:   // 0100 1100   01 + 001 + 10,0 +       (2/2,0 + 3/3,0 + 3/2,1)
  {
    compOffsets[numComps+1] = bitSize + 2;
    compOffsets[numComps+2] = bitSize + 5;
    deweyid[numComps] = 1;
    deweyid[numComps+1] = 0;
    deweyid[numComps+2] = 2;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 77:   // 0100 1101   01 + 001 + 10,1 +       (2/2,0 + 3/3,0 + 3/2,1)
  {
    compOffsets[numComps+1] = bitSize + 2;
    compOffsets[numComps+2] = bitSize + 5;
    deweyid[numComps] = 1;
    deweyid[numComps+1] = 0;
    deweyid[numComps+2] = 3;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 78:   // 0100 1110   01 + 001 + 110, ...     (2/2,0 + 3/3,0 + 5/3,2)
  {
    compOffsets[numComps+1] = bitSize + 2;
    compOffsets[numComps+2] = bitSize + 5;
    deweyid[numComps] = 1;
    deweyid[numComps+1] = 0;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    extractValue(bitSize, byteIndex, bitIndex, 2, 4, deweyid[numComps + 2]);
    numComps += 3;
    break;
  }
  case 79:   // 0100 1111   01 + 001 + 111 ...      (2/2,0 + 3/3,0)
  {
    compOffsets[numComps+1] = bitSize + 2;
    compOffsets[numComps+2] = bitSize + 5;
    deweyid[numComps] = 1;
    deweyid[numComps+1] = 0;
    ADVANCE(bitSize, byteIndex, bitIndex, 5);
    numComps += 2;
    break;
  }

  case 80:   // 0101 0000   01 + 01 + 0000 ...      (2/2,0 + 2/2,0)
  {
    compOffsets[numComps+1] = bitSize + 2;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 1;
    ADVANCE(bitSize, byteIndex, bitIndex, 4);
    numComps += 2;
    break;
  }
  case 81:   // 0101 0000   01 + 01 + 0001, ...     (2/2,0 + 2/2,0 + 6/4,2)
  {
    compOffsets[numComps+1] = bitSize + 2;
    compOffsets[numComps+2] = bitSize + 4;
    deweyid[numComps] = 1;
    deweyid[numComps+1] = 1;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    extractValue(bitSize, byteIndex, bitIndex, 2, -4, deweyid[numComps + 2]);
    numComps += 3;
    break;
  }
  case 82:   // 0101 0010   01 + 01 + 001 + 0...    (2/2,0 + 2/2,0 + 3/3,0)
  {
    compOffsets[numComps+1] = bitSize + 2;
    compOffsets[numComps+2] = bitSize + 4;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 1;
    deweyid[numComps + 2] = 0;
    ADVANCE(bitSize, byteIndex, bitIndex, 7);
    numComps += 3;
    break;
  }
  case 83:   // 0101 0011   01 + 01 + 001 + 1...    (2/2,0 + 2/2,0 + 3/3,0)
  {
    compOffsets[numComps+1] = bitSize + 2;
    compOffsets[numComps+2] = bitSize + 4;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 1;
    deweyid[numComps + 2] = 0;
    ADVANCE(bitSize, byteIndex, bitIndex, 7);
    numComps += 3;
    break;
  }
  case 84:   // 0101 0100   01 + 01 + 01 + 00 ... (2/2,0 + 2/2,0 + 2/2,0)
  {
    compOffsets[numComps+1] = bitSize + 2;
    compOffsets[numComps+2] = bitSize + 4;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 1;
    deweyid[numComps + 2] = 1;
    numComps += 3;
    ADVANCE(bitSize, byteIndex, bitIndex, 6);
    break;
  }
  case 85:   // 0101 0101   01 + 01 + 01 + 01 + (2/2,0 + 2/2,0 + 2/2,0 + 2/2,0)
  {
    compOffsets[numComps+1] = bitSize + 2;
    compOffsets[numComps+2] = bitSize + 4;
    compOffsets[numComps+3] = bitSize + 6;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 1;
    deweyid[numComps + 2] = 1;
    deweyid[numComps + 3] = 1;
    numComps += 4;
    byteIndex++;
    break;
  }
  case 86:   // 0101 0110   01 + 01 + 01 + 10, ... (2/2,0 + 2/2,0 + 2/2,0 + 3/2,1)
  {
    compOffsets[numComps+1] = bitSize + 2;
    compOffsets[numComps+2] = bitSize + 4;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 1;
    deweyid[numComps + 2] = 1;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    extractValue(bitSize, byteIndex, bitIndex, 1, 2, deweyid[numComps + 3]);
    numComps += 3;
    break;
  }
  case 87:   // 0101 0111   01 + 01 + 01 + 11 ... (2/2,0 + 2/2,0 + 2/2,0)
  {
    compOffsets[numComps+1] = bitSize + 2;
    compOffsets[numComps+2] = bitSize + 4;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 1;
    deweyid[numComps + 2] = 1;
    ADVANCE(bitSize, byteIndex, bitIndex, 6);
    numComps += 3;
    break;
  }
  case 88:   // 0101 1000   01 + 01 + 10,0 + 0 ... (2/2,0 + 2/2,0 + 3/2,1)
  {
    compOffsets[numComps+1] = bitSize + 2;
    compOffsets[numComps+2] = bitSize + 4;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 1;
    deweyid[numComps + 2] = 2;
    ADVANCE(bitSize, byteIndex, bitIndex, 7);
    numComps += 3;
    break;
  }
  case 89:   // 0101 1001   01 + 01 + 10,0 + 1 ... (2/2,0 + 2/2,0 + 3/2,1)
  {
    compOffsets[numComps+1] = bitSize + 2;
    compOffsets[numComps+2] = bitSize + 4;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 1;
    deweyid[numComps + 2] = 2;
    ADVANCE(bitSize, byteIndex, bitIndex, 7);
    numComps += 3;
    break;
  }
  case 90:   // 0101 1010   01 + 01 + 10,1 + 0 ... (2/2,0 + 2/2,0 + 3/2,1)
  {
    compOffsets[numComps+1] = bitSize + 2;
    compOffsets[numComps+2] = bitSize + 4;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 1;
    deweyid[numComps + 2] = 3;
    ADVANCE(bitSize, byteIndex, bitIndex, 7);
    numComps += 3;
    break;
  }
  case 91:   // 0101 1011   01 + 01 + 10,1 + 1 ... (2/2,0 + 2/2,0 + 3/2,1)
  {
    compOffsets[numComps+1] = bitSize + 2;
    compOffsets[numComps+2] = bitSize + 4;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 1;
    deweyid[numComps + 2] = 3;
    ADVANCE(bitSize, byteIndex, bitIndex, 7);
    numComps += 3;
    break;
  }
  case 92:   // 0101 1100   01 + 01 + 110,0 ... (2/2,0 + 2/2,0 + 5/3,2)
  {
    compOffsets[numComps+1] = bitSize + 2;
    compOffsets[numComps+2] = bitSize + 4;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 1;
    ADVANCE(bitSize, byteIndex, bitIndex, 7);
    extractValue(bitSize, byteIndex, bitIndex, 2, 4, deweyid[numComps + 2]);
    numComps += 3;
    break;
  }
  case 93:   // 0101 1101   01 + 01 + 110,1 ...     (2/2,0 + 2/2,0 + 5/3,2)
  {
    compOffsets[numComps+1] = bitSize + 2;
    compOffsets[numComps+2] = bitSize + 4;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 1;
    ADVANCE(bitSize, byteIndex, bitIndex, 7);
    extractValue(bitSize, byteIndex, bitIndex, 2, 4, deweyid[numComps + 2]);
    numComps += 3;
    break;
  }
  case 94:   // 0101 1110   01 + 01 + 1110, ...     (2/2,0 + 2/2,0 + 8/4,4)
  {
    compOffsets[numComps+1] = bitSize + 2;
    compOffsets[numComps+2] = bitSize + 4;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 1;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    extractValue(bitSize, byteIndex, bitIndex, 4, 8, deweyid[numComps + 2]);
    numComps += 3;
    break;
  }
  case 95:   // 0101 1111   01 + 01 + 1111 ...      (2/2,0 + 2/2,0)
  {
    compOffsets[numComps+1] = bitSize + 2;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 1;
    ADVANCE(bitSize, byteIndex, bitIndex, 4);
    numComps += 2;
    break;
  }


  case 96:   // 0110 0000   01 + 10,0 + 000 ...     (2/2,0 + 3/2,1)
  {
    compOffsets[numComps+1] = bitSize + 2;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 2;
    ADVANCE(bitSize, byteIndex, bitIndex, 5);
    numComps += 2;
    break;
  }
  case 97:   // 0110 0001   01 + 10,0 + 001 +     (2/2,0 + 3/2,1 + 3/3,0)
  {
    compOffsets[numComps+1] = bitSize + 2;
    compOffsets[numComps+2] = bitSize + 5;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 2;
    deweyid[numComps + 2] = 0;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 98:   // 0110 0010   01 + 10,0 + 01 + 0 ...  (2/2,0 + 3/2,1 + 2/2,0)
  {
    compOffsets[numComps+1] = bitSize + 2;
    compOffsets[numComps+2] = bitSize + 5;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 2;
    deweyid[numComps + 2] = 1;
    ADVANCE(bitSize, byteIndex, bitIndex, 7);
    numComps += 3;
    break;
  }
  case 99:   // 0110 0011   01 + 10,0 + 01 + 1 ...  (2/2,0 + 3/2,1 + 2/2,0)
  {
    compOffsets[numComps+1] = bitSize + 2;
    compOffsets[numComps+2] = bitSize + 5;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 2;
    deweyid[numComps + 2] = 1;
    ADVANCE(bitSize, byteIndex, bitIndex, 7);
    numComps += 3;
    break;
  }
  case 100:   // 0110 0100   01 + 10,0 + 10,0 +     (2/2,0 + 3/2,1 + 3/2,1)
  {
    compOffsets[numComps+1] = bitSize + 2;
    compOffsets[numComps+2] = bitSize + 5;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 2;
    deweyid[numComps + 2] = 2;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 101:   // 0110 0101   01 + 10,0 + 10,1 +     (2/2,0 + 3/2,1 + 3/2,1)
  {
    compOffsets[numComps+1] = bitSize + 2;
    compOffsets[numComps+2] = bitSize + 5;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 2;
    deweyid[numComps + 2] = 3;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 102:   // 0110 0110   01 + 10,0 + 110, ...   (2/2,0 + 3/2,1 + 5/3,2)
  {
    compOffsets[numComps+1] = bitSize + 2;
    compOffsets[numComps+2] = bitSize + 5;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 2;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    extractValue(bitSize, byteIndex, bitIndex, 2, 4, deweyid[numComps + 2]);
    numComps += 3;
    break;
  }
  case 103:   // 0110 0111   01 + 10,0 + 111 ...    (2/2,0 + 3/2,1)
  {
    compOffsets[numComps+1] = bitSize + 2;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 2;
    ADVANCE(bitSize, byteIndex, bitIndex, 5);
    numComps += 2;
    break;
  }
  case 104:   // 0110 1000   01 + 10,1 + 000 ...    (2/2,0 + 3/2,1)
  {
    compOffsets[numComps+1] = bitSize + 2;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 3;
    ADVANCE(bitSize, byteIndex, bitIndex, 5);
    numComps += 2;
    break;
  }
  case 105:   // 0110 1001   01 + 10,1 + 001 +      (2/2,0 + 3/2,1 + 3/3,0)
  {
    compOffsets[numComps+1] = bitSize + 2;
    compOffsets[numComps+2] = bitSize + 5;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 3;
    deweyid[numComps + 2] = 0;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 106:   // 0110 1010   01 + 10,1 + 01 + 0 ... (2/2,0 + 3/2,1 + 2/2,0)
  {
    compOffsets[numComps+1] = bitSize + 2;
    compOffsets[numComps+2] = bitSize + 5;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 3;
    deweyid[numComps + 2] = 1;
    ADVANCE(bitSize, byteIndex, bitIndex, 7);
    numComps += 3;
    break;
  }
  case 107:   // 0110 1011   01 + 10,1 + 01 + 1 ... (2/2,0 + 3/2,1 + 2/2,0)
  {
    compOffsets[numComps+1] = bitSize + 2;
    compOffsets[numComps+2] = bitSize + 5;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 3;
    deweyid[numComps + 2] = 1;
    ADVANCE(bitSize, byteIndex, bitIndex, 7);
    numComps += 3;
    break;
  }
  case 108:   // 0110 1100   01 + 10,1 + 10,0 ...   (2/2,0 + 3/2,1 + 3/2,1)
  {
    compOffsets[numComps+1] = bitSize + 2;
    compOffsets[numComps+2] = bitSize + 5;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 3;
    deweyid[numComps + 2] = 2;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 109:   // 0110 1101   01 + 10,1 + 10,1 ...   (2/2,0 + 3/2,1 + 3/2,1)
  {
    compOffsets[numComps+1] = bitSize + 2;
    compOffsets[numComps+2] = bitSize + 5;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 3;
    deweyid[numComps + 2] = 3;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 110:   // 0110 1110   01 + 10,1 + 110, ...   (2/2,0 + 3/2,1 + 5/3,2)
  {
    compOffsets[numComps+1] = bitSize + 2;
    compOffsets[numComps+2] = bitSize + 5;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 3;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    extractValue(bitSize, byteIndex, bitIndex, 2, 4, deweyid[numComps + 2]);
    numComps += 3;
    break;
  }
  case 111:   // 0110 1111   01 + 10,1 + 111 ...    (2/2,0 + 3/2,1)
  {
    compOffsets[numComps+1] = bitSize + 2;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 3;
    ADVANCE(bitSize, byteIndex, bitIndex, 5);
    numComps += 2;
    break;
  }


  case 112:   // 0111 0000   01 + 110,00 + 0 ...    (2/2,0 + 5/3,2)
  {
    compOffsets[numComps+1] = bitSize + 2;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 4;
    ADVANCE(bitSize, byteIndex, bitIndex, 7);
    numComps += 2;
    break;
  }
  case 113:   // 0111 0001   01 + 110,00 + 1 ...    (2/2,0 + 5/3,2)
  {
    compOffsets[numComps+1] = bitSize + 2;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 4;
    ADVANCE(bitSize, byteIndex, bitIndex, 7);
    numComps += 2;
    break;
  }
  case 114:   // 0111 0010   01 + 110,01 + 0 ...    (2/2,0 + 5/3,2)
  {
    compOffsets[numComps+1] = bitSize + 2;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 5;
    ADVANCE(bitSize, byteIndex, bitIndex, 7);
    numComps += 2;
    break;
  }
  case 115:   // 0111 0011   01 + 110,01 + 1 ...    (2/2,0 + 5/3,2)
  {
    compOffsets[numComps+1] = bitSize + 2;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 5;
    ADVANCE(bitSize, byteIndex, bitIndex, 7);
    numComps += 2;
    break;
  }
  case 116:   // 0111 0100   01 + 110,10 + 0 ...    (2/2,0 + 5/3,2)
  {
    compOffsets[numComps+1] = bitSize + 2;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 6;
    ADVANCE(bitSize, byteIndex, bitIndex, 7);
    numComps += 2;
    break;
  }
  case 117:   // 0111 0101   01 + 110,10 + 1 ...    (2/2,0 + 5/3,2)
  {
    compOffsets[numComps+1] = bitSize + 2;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 6;
    ADVANCE(bitSize, byteIndex, bitIndex, 7);
    numComps += 2;
    break;
  }
  case 118:   // 0111 0110   01 + 110,11 + 0 ...    (2/2,0 + 5/3,2)
  {
    compOffsets[numComps+1] = bitSize + 2;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 7;
    ADVANCE(bitSize, byteIndex, bitIndex, 7);
    numComps += 2;
    break;
  }
  case 119:   // 0111 0111   01 + 110,11 + 1 ...    (2/2,0 + 5/3,2)
  {
    compOffsets[numComps+1] = bitSize + 2;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 7;
    ADVANCE(bitSize, byteIndex, bitIndex, 7);
    numComps += 2;
    break;
  }


  case 120:   // 0111 1000   01 + 1110,00 ...    (2/2,0 + 8/4,4)
  {
    compOffsets[numComps+1] = bitSize + 2;
    deweyid[numComps] = 1;
    ADVANCE(bitSize, byteIndex, bitIndex, 6);
    extractValue(bitSize, byteIndex, bitIndex, 4, 8, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }
  case 121:   // 0111 1001   01 + 1110,01 ...    (2/2,0 + 8/4,4)
  {
    compOffsets[numComps+1] = bitSize + 2;
    deweyid[numComps] = 1;
    ADVANCE(bitSize, byteIndex, bitIndex, 6);
    extractValue(bitSize, byteIndex, bitIndex, 4, 8, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }
  case 122:   // 0111 1010   01 + 1110,10 ...    (2/2,0 + 8/4,4)
  {
    compOffsets[numComps+1] = bitSize + 2;
    deweyid[numComps] = 1;
    ADVANCE(bitSize, byteIndex, bitIndex, 6);
    extractValue(bitSize, byteIndex, bitIndex, 4, 8, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }
  case 123:   // 0111 1011   01 + 1110,11 ...    (2/2,0 + 8/4,4)
  {
    compOffsets[numComps+1] = bitSize + 2;
    deweyid[numComps] = 1;
    ADVANCE(bitSize, byteIndex, bitIndex, 6);
    extractValue(bitSize, byteIndex, bitIndex, 4, 8, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }


  case 124:   // 0111 1100   01 + 11110,0 ...    (2/2,0 + 13/5,8)
  {
    compOffsets[numComps+1] = bitSize + 2;
    deweyid[numComps] = 1;
    ADVANCE(bitSize, byteIndex, bitIndex, 7);
    extractValue(bitSize, byteIndex, bitIndex, 8, 24, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }
  case 125:   // 0111 1101   01 + 11110,1 ...    (2/2,0 + 13/5,8)
  {
    compOffsets[numComps+1] = bitSize + 2;
    deweyid[numComps] = 1;
    ADVANCE(bitSize, byteIndex, bitIndex, 7);
    extractValue(bitSize, byteIndex, bitIndex, 8, 24, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }


  case 126:   // 0111 1110   01 + 111110, ...    (2/2,0 + 18/6,12)
  {
    compOffsets[numComps+1] = bitSize + 2;
    deweyid[numComps] = 1;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    extractValue(bitSize, byteIndex, bitIndex, 12, 280, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }


  case 127:   // 0111 1111   01 + 111111 ...    (2/2,0)
  {
    deweyid[numComps] = 1;
    ADVANCE(bitSize, byteIndex, bitIndex, 2);
    numComps += 1;
    break;
  }


  case 128:   // 1000 0000   10,0 + 00000 ...      (3/2,1)
  {
    deweyid[numComps] = 2;
    ADVANCE(bitSize, byteIndex, bitIndex, 3);
    numComps += 1;
    break;
  }
  case 129:   // 1000 0001   10,0 + 00001, ...      (3/2,1 + 9/5,4)
  {
    compOffsets[numComps+1] = bitSize + 3;
    deweyid[numComps] = 2;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    extractValue(bitSize, byteIndex, bitIndex, 4, -20, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }
  case 130:   // 1000 0010   10,0 + 0001,0 ...      (3/2,1 + 6/4,2)
  {
    compOffsets[numComps+1] = bitSize + 3;
    deweyid[numComps] = 2;
    ADVANCE(bitSize, byteIndex, bitIndex, 7);
    extractValue(bitSize, byteIndex, bitIndex, 2, -4, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }
  case 131:   // 1000 0011   10,0 + 0001,1 ...      (3/2,1 + 6/4,2)
  {
    compOffsets[numComps+1] = bitSize + 3;
    deweyid[numComps] = 2;
    ADVANCE(bitSize, byteIndex, bitIndex, 7);
    extractValue(bitSize, byteIndex, bitIndex, 2, -4, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }
  case 132:   // 1000 0100   10,0 + 001 + 00 ...   (3/2,1 + 3/3,0)
  {
    compOffsets[numComps+1] = bitSize + 3;
    deweyid[numComps] = 2;
    deweyid[numComps+1] = 0;
    ADVANCE(bitSize, byteIndex, bitIndex, 6);
    numComps += 2;
    break;
  }
  case 133:   // 1000 0101   10,0 + 001 + 01 ...   (3/2,1 + 3/3,0 + 2/2,0)
  {
    compOffsets[numComps+1] = bitSize + 3;
    compOffsets[numComps+2] = bitSize + 3;
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 0;
    deweyid[numComps + 1] = 1;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 134:   // 1000 0110   10,0 + 001 + 10, ...   (3/2,1 + 3/3,0 + 3/2,1)
  {
    compOffsets[numComps+1] = bitSize + 3;
    compOffsets[numComps+2] = bitSize + 3;
    deweyid[numComps] = 2;
    deweyid[numComps+1] = 0;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    extractValue(bitSize, byteIndex, bitIndex, 1, 2, deweyid[numComps + 2]);
    numComps += 3;
    break;
  }
  case 135:   // 1000 0111   10,0 + 001 + 11 ...    (3/2,1 + 3/3,0)
  {
    compOffsets[numComps+1] = bitSize + 3;
    deweyid[numComps] = 2;
    deweyid[numComps+1] = 0;
    ADVANCE(bitSize, byteIndex, bitIndex, 6);
    numComps += 2;
    break;
  }

  case 136:   // 1000 1000   10,0 + 01 + 000 ...    (3/2,1 + 2/2,0)
  {
    compOffsets[numComps+1] = bitSize + 3;
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 1;
    ADVANCE(bitSize, byteIndex, bitIndex, 5);
    numComps += 2;
    break;
  }
  case 137:   // 1000 1001   10,0 + 01 + 001 +      (3/2,1 + 2/2,0 + 3/3,0)
  {
    compOffsets[numComps+1] = bitSize + 3;
    compOffsets[numComps+2] = bitSize + 2;
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 1;
    deweyid[numComps + 1] = 0;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 138:   // 1000 1010   10,0 + 01 + 01 + 0 ... (3/2,1 + 2/2,0 + 2/2,0)
  {
    compOffsets[numComps+1] = bitSize + 3;
    compOffsets[numComps+2] = bitSize + 2;
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 1;
    deweyid[numComps + 1] = 1;
    ADVANCE(bitSize, byteIndex, bitIndex, 7);
    numComps += 3;
    break;
  }
  case 139:   // 1000 1011   10,0 + 01 + 01 + 1 ... (3/2,1 + 2/2,0 + 2/2,0)
  {
    compOffsets[numComps+1] = bitSize + 3;
    compOffsets[numComps+2] = bitSize + 2;
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 1;
    deweyid[numComps + 1] = 1;
    ADVANCE(bitSize, byteIndex, bitIndex, 7);
    numComps += 3;
    break;
  }
  case 140:   // 1000 1100   10,0 + 01 + 10,0 +     (3/2,1 + 2/2,0 + 3/2,1)
  {
    compOffsets[numComps+1] = bitSize + 3;
    compOffsets[numComps+2] = bitSize + 2;
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 1;
    deweyid[numComps + 1] = 2;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 141:   // 1000 1101   10,0 + 01 + 10,1 +     (3/2,1 + 2/2,0 + 3/2,1)
  {
    compOffsets[numComps+1] = bitSize + 3;
    compOffsets[numComps+2] = bitSize + 2;
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 1;
    deweyid[numComps + 1] = 3;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 142:   // 1000 1110   10,0 + 01 + 110 ...    (3/2,1 + 2/2,0 + 5/3,2)
  {
    compOffsets[numComps+1] = bitSize + 3;
    compOffsets[numComps+2] = bitSize + 2;
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 1;
    ADVANCE(bitSize, byteIndex, bitIndex, 5);
    extractValue(bitSize, byteIndex, bitIndex, 2, 4, deweyid[numComps + 2]);    
    numComps += 3;
    break;
  }
  case 143:   // 1000 1111   10,0 + 01 + 111 ...    (3/2,1 + 2/2,0)
  {
    compOffsets[numComps+1] = bitSize + 3;
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 1;
    ADVANCE(bitSize, byteIndex, bitIndex, 5);
    numComps += 2;
    break;
  }

  case 144:   // 1001 0000   10,0 + 10,0 + 00 ...   (3/2,1 + 3/2,1)
  {
    compOffsets[numComps+1] = bitSize + 3;
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 2;
    ADVANCE(bitSize, byteIndex, bitIndex, 6);
    numComps += 2;
    break;
  }
  case 145:   // 1001 0001   10,0 + 10,0 + 01 +     (3/2,1 + 3/2,1 + 2/2,0)
  {
    compOffsets[numComps+1] = bitSize + 3;
    compOffsets[numComps+2] = bitSize + 3;
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 2;
    deweyid[numComps + 2] = 1;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 146:   // 1001 0010   10,0 + 10,0 + 10, ...  (3/2,1 + 3/2,1 + 3/2,1)
  {
    compOffsets[numComps+1] = bitSize + 3;
    compOffsets[numComps+2] = bitSize + 3;
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 2;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    extractValue(bitSize, byteIndex, bitIndex, 1, 2, deweyid[numComps + 2]);
    numComps += 3;
    break;
  }
  case 147:   // 1001 0011   10,0 + 10,0 + 11 ...   (3/2,1 + 3/2,1)
  {
    compOffsets[numComps+1] = bitSize + 3;
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 2;
    ADVANCE(bitSize, byteIndex, bitIndex, 6);
    numComps += 2;
    break;
  }
  case 148:   // 1001 0100   10,0 + 10,1 + 00 ...   (3/2,1 + 3/2,1)
  {
    compOffsets[numComps+1] = bitSize + 3;
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 3;
    ADVANCE(bitSize, byteIndex, bitIndex, 6);
    numComps += 2;
    break;
  }
  case 149:   // 1001 0101   10,0 + 10,1 + 01 +     (3/2,1 + 3/2,1 + 2/2,0)
  {
    compOffsets[numComps+1] = bitSize + 3;
    compOffsets[numComps+2] = bitSize + 3;
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 3;
    deweyid[numComps + 2] = 1;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 150:   // 1001 0110   10,0 + 10,1 + 10, ...  (3/2,1 + 3/2,1 + 3/2,1)
  {
    compOffsets[numComps+1] = bitSize + 3;
    compOffsets[numComps+2] = bitSize + 3;
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 3;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    extractValue(bitSize, byteIndex, bitIndex, 1, 2, deweyid[numComps + 2]);
    numComps += 3;
    break;
  }
  case 151:   // 1001 0111   10,0 + 10,1 + 11 ...   (3/2,1 + 3/2,1)
  {
    compOffsets[numComps+1] = bitSize + 3;
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 3;
    ADVANCE(bitSize, byteIndex, bitIndex, 6);
    numComps += 2;
    break;
  }

  case 152:   // 1001 1000   10,0 + 110,00 +        (3/2,1 + 5/3,2)
  {
    compOffsets[numComps+1] = bitSize + 3;
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 4;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 153:   // 1001 1001   10,0 + 110,01 +        (3/2,1 + 5/3,2)
  {
    compOffsets[numComps+1] = bitSize + 3;
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 5;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 154:   // 1001 1010   10,0 + 110,10 +        (3/2,1 + 5/3,2)
  {
    compOffsets[numComps+1] = bitSize + 3;
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 6;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 155:   // 1001 1011   10,0 + 110,11 +        (3/2,1 + 5/3,2)
  {
    compOffsets[numComps+1] = bitSize + 3;
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 7;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }

  case 156:   // 1001 1100   10,0 + 1110, 0 ...     (3/2,1 + 8/4,4)
  {
    compOffsets[numComps+1] = bitSize + 3;
    deweyid[numComps] = 2;
    ADVANCE(bitSize, byteIndex, bitIndex, 7);
    extractValue(bitSize, byteIndex, bitIndex, 4, 8, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }
  case 157:   // 1001 1101   10,0 + 1110, 1 ...     (3/2,1 + 8/4,4)
  {
    compOffsets[numComps+1] = bitSize + 3;
    deweyid[numComps] = 2;
    ADVANCE(bitSize, byteIndex, bitIndex, 7);
    extractValue(bitSize, byteIndex, bitIndex, 4, 8, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }

  case 158:   // 1001 1110   10,0 + 11110, ...      (3/2,1 + 13/5,8)
  {
    compOffsets[numComps+1] = bitSize + 3;
    deweyid[numComps] = 2;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    extractValue(bitSize, byteIndex, bitIndex, 8, 24, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }

  case 159:   // 1001 1111   10,0 + 11111 ...       (3/2,1)
  {
    deweyid[numComps] = 2;
    ADVANCE(bitSize, byteIndex, bitIndex, 3);
    numComps += 1;
    break;
  }

  case 160:   // 1010 0000   10,1 + 00000 ...       (3/2,1)
  {
    deweyid[numComps] = 3;
    ADVANCE(bitSize, byteIndex, bitIndex, 3);
    numComps += 1;
    break;
  }

  case 161:   // 1010 0001   10,1 + 00001, ...      (3/2,1 + 9/5,4)
  {
    compOffsets[numComps+1] = bitSize + 3;
    deweyid[numComps] = 3;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    extractValue(bitSize, byteIndex, bitIndex, 4, -20, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }
  case 162:   // 1010 0010   10,1 + 0001,0 ...      (3/2,1 + 6/4,2)
  {
    compOffsets[numComps+1] = bitSize + 3;
    deweyid[numComps] = 3;
    ADVANCE(bitSize, byteIndex, bitIndex, 7);
    extractValue(bitSize, byteIndex, bitIndex, 2, -4, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }
  case 163:   // 1010 0011   10,1 + 0001,1 ...      (3/2,1 + 6/4,2)
  {
    compOffsets[numComps+1] = bitSize + 3;
    deweyid[numComps] = 3;
    ADVANCE(bitSize, byteIndex, bitIndex, 7);
    extractValue(bitSize, byteIndex, bitIndex, 2, -4, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }
  case 164:   // 1010 0100   10,1 + 001 + 00 ...    (3/2,1 + 3/3,0)
  {
    compOffsets[numComps+1] = bitSize + 3;
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 0;
    ADVANCE(bitSize, byteIndex, bitIndex, 5);
    numComps += 2;
    break;
  }
  case 165:   // 1010 0101   10,1 + 001 + 01 +      (3/2,1 + 3/3,0 + 2/2,0)
  {
    compOffsets[numComps+1] = bitSize + 3;
    compOffsets[numComps+2] = bitSize + 3;
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 0;
    deweyid[numComps + 2] = 1;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 166:   // 1010 0110   10,1 + 001 + 10, ...   (3/2,1 + 3/3,0 + 3/2,1)
  {
    compOffsets[numComps+1] = bitSize + 3;
    compOffsets[numComps+2] = bitSize + 3;
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 0;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    extractValue(bitSize, byteIndex, bitIndex, 1, 2, deweyid[numComps + 2]);
    numComps += 3;
    break;
  }
  case 167:   // 1010 0111   10,1 + 001 + 11 ...    (3/2,1 + 3/3,0)
  {
    compOffsets[numComps+1] = bitSize + 3;
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 0;
    ADVANCE(bitSize, byteIndex, bitIndex, 5);
    numComps += 2;
    break;
  }

  case 168:   // 1010 1000   10,1 + 01 + 000 ...    (3/2,1 + 2/2,0)
  {
    compOffsets[numComps+1] = bitSize + 3;
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 1;
    ADVANCE(bitSize, byteIndex, bitIndex, 5);
    numComps += 2;
    break;
  }
  case 169:   // 1010 1001   10,1 + 01 + 001 +      (3/2,1 + 2/2,0 + 3/3,0)
  {
    compOffsets[numComps+1] = bitSize + 3;
    compOffsets[numComps+2] = bitSize + 2;
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 1;
    deweyid[numComps + 2] = 0;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 170:   // 1010 1010   10,1 + 01 + 01 + 0 ... (3/2,1 + 2/2,0 + 2/2,0)
  {
    compOffsets[numComps+1] = bitSize + 3;
    compOffsets[numComps+2] = bitSize + 2;
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 1;
    deweyid[numComps + 2] = 1;
    ADVANCE(bitSize, byteIndex, bitIndex, 7);
    numComps += 3;
    break;
  }
  case 171:   // 1010 1011   10,1 + 01 + 01 + 1 ... (3/2,1 + 2/2,0 + 2/2,0)
  {
    compOffsets[numComps+1] = bitSize + 3;
    compOffsets[numComps+2] = bitSize + 2;
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 1;
    deweyid[numComps + 2] = 1;
    ADVANCE(bitSize, byteIndex, bitIndex, 7);
    numComps += 3;
    break;
  }
  case 172:   // 1010 1100   10,1 + 01 + 10,0 +     (3/2,1 + 2/2,0 + 3/2,1)
  {
    compOffsets[numComps+1] = bitSize + 3;
    compOffsets[numComps+2] = bitSize + 2;
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 1;
    deweyid[numComps + 2] = 2;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 173:   // 1010 1101   10,1 + 01 + 10,1 +     (3/2,1 + 2/2,0 + 3/2,1)
  {
    compOffsets[numComps+1] = bitSize + 3;
    compOffsets[numComps+2] = bitSize + 2;
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 1;
    deweyid[numComps + 2] = 3;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 174:   // 1010 1110   10,1 + 01 + 110, ...   (3/2,1 + 2/2,0 + 5/3,2)
  {
    compOffsets[numComps+1] = bitSize + 3;
    compOffsets[numComps+2] = bitSize + 2;
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 1;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    extractValue(bitSize, byteIndex, bitIndex, 2, 4, deweyid[numComps + 2]);
    numComps += 3;
    break;
  }
  case 175:   // 1010 1111   10,1 + 01 + 111 ...    (3/2,1 + 2/2,0)
  {
    compOffsets[numComps+1] = bitSize + 3;
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 1;
    ADVANCE(bitSize, byteIndex, bitIndex, 5);
    numComps += 2;
    break;
  }
  case 176:   // 1011 0000   10,1 + 10,0 + 00 ...   (3/2,1 + 3/2,1)
  {
    compOffsets[numComps+1] = bitSize + 3;
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 2;
    ADVANCE(bitSize, byteIndex, bitIndex, 6);
    numComps += 2;
    break;
  }
  case 177:   // 1011 0001   10,1 + 10,0 + 01 +     (3/2,1 + 3/2,1 + 2/2,0)
  {
    compOffsets[numComps+1] = bitSize + 3;
    compOffsets[numComps+2] = bitSize + 3;
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 2;
    deweyid[numComps + 2] = 1;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 178:   // 1011 0010   10,1 + 10,0 + 10, ...  (3/2,1 + 3/2,1 + 3/2,1)
  {
    compOffsets[numComps+1] = bitSize + 3;
    compOffsets[numComps+2] = bitSize + 3;
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 2;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    extractValue(bitSize, byteIndex, bitIndex, 1, 2, deweyid[numComps + 2]);
    numComps += 3;
    break;
  }
  case 179:   // 1011 0011   10,1 + 10,0 + 11 ...   (3/2,1 + 3/2,1)
  {
    compOffsets[numComps+1] = bitSize + 3;
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 2;
    ADVANCE(bitSize, byteIndex, bitIndex, 6);
    numComps += 2;
    break;
  }
  case 180:   // 1011 0100   10,1 + 10,1 + 00 ...   (3/2,1 + 3/2,1)
  {
    compOffsets[numComps+1] = bitSize + 3;
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 3;
    ADVANCE(bitSize, byteIndex, bitIndex, 6);
    numComps += 2;
    break;
  }
  case 181:   // 1011 0101   10,1 + 10,1 + 01 +     (3/2,1 + 3/2,1 + 2/2,0)
  {
    compOffsets[numComps+1] = bitSize + 3;
    compOffsets[numComps+2] = bitSize + 3;
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 3;
    deweyid[numComps + 2] = 1;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 182:   // 1011 0110   10,1 + 10,1 + 10, ...  (3/2,1 + 3/2,1 + 3/2,1)
  {
    compOffsets[numComps+1] = bitSize + 3;
    compOffsets[numComps+2] = bitSize + 3;
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 3;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    extractValue(bitSize, byteIndex, bitIndex, 1, 2, deweyid[numComps + 2]);
    numComps += 3;
    break;
  }
  case 183:   // 1011 0111   10,1 + 10,1 + 11 ...   (3/2,1 + 3/2,1)
  {
    compOffsets[numComps+1] = bitSize + 3;
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 3;
    ADVANCE(bitSize, byteIndex, bitIndex, 6);
    numComps += 2;
    break;
  }

  case 184:   // 1011 1000   10,1 + 110,00 +        (3/2,1 + 5/3,2)
  {
    compOffsets[numComps+1] = bitSize + 3;
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 4;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 185:   // 1011 1001   10,1 + 110,01 +        (3/2,1 + 5/3,2)
  {
    compOffsets[numComps+1] = bitSize + 3;
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 5;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 186:   // 1011 1010   10,1 + 110,10 +        (3/2,1 + 5/3,2)
  {
    compOffsets[numComps+1] = bitSize + 3;
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 6;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 187:   // 1011 1011   10,1 + 110,11 +        (3/2,1 + 5/3,2)
  {
    compOffsets[numComps+1] = bitSize + 3;
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 7;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }

  case 188:   // 1011 1100   10,1 + 1110,0 ...      (3/2,1 + 8/4,4)
  {
    compOffsets[numComps+1] = bitSize + 3;
    deweyid[numComps] = 3;
    ADVANCE(bitSize, byteIndex, bitIndex, 7);
    extractValue(bitSize, byteIndex, bitIndex, 4, 8, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }
  case 189:   // 1011 1101   10,1 + 1110,1 ...      (3/2,1 + 8/4,4)
  {
    compOffsets[numComps+1] = bitSize + 3;
    deweyid[numComps] = 3;
    ADVANCE(bitSize, byteIndex, bitIndex, 7);
    extractValue(bitSize, byteIndex, bitIndex, 4, 8, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }

  case 190:   // 1011 1110   10,1 + 11110, ...      (3/2,1 + 13/5,8)
  {
    compOffsets[numComps+1] = bitSize + 3;
    deweyid[numComps] = 3;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    extractValue(bitSize, byteIndex, bitIndex, 8, 24, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }

  case 191:   // 1011 1111   10,1 + 11111 ...       (3/2,1)
  {
    deweyid[numComps] = 3;
    ADVANCE(bitSize, byteIndex, bitIndex, 3);
    numComps += 1;
    break;
  }


  case 192:   // 1100 0000   110,00 + 000 ...       (5/3,2)
  {
    deweyid[numComps] = 4;
    ADVANCE(bitSize, byteIndex, bitIndex, 5);
    numComps += 1;
    break;
  }
  case 193:   // 1100 0001   110,00 + 001 +         (5/3,2 + 3/3,0)
  {
    compOffsets[numComps+1] = bitSize + 5;
    deweyid[numComps] = 4;
    deweyid[numComps + 1] = 0;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 194:   // 1100 0010   110,00 + 01 + 0 ...    (5/3,2 + 2/2,0)
  {
    compOffsets[numComps+1] = bitSize + 5;
    deweyid[numComps] = 4;
    deweyid[numComps + 1] = 1;
    ADVANCE(bitSize, byteIndex, bitIndex, 7);
    numComps += 2;
    break;
  }
  case 195:   // 1100 0011   110,00 + 01 + 1 ...    (5/3,2 + 2/2,0)
  {
    compOffsets[numComps+1] = bitSize + 5;
    deweyid[numComps] = 4;
    deweyid[numComps + 1] = 1;
    ADVANCE(bitSize, byteIndex, bitIndex, 7);
    numComps += 2;
    break;
  }

  case 196:   // 1100 0100   110,00 + 10,0 +        (5/3,2 + 3/2,1)
  {
    compOffsets[numComps+1] = bitSize + 5;
    deweyid[numComps] = 4;
    deweyid[numComps + 1] = 2;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 197:   // 1100 0101   110,00 + 10,1 +        (5/3,2 + 3/2,1)
  {
    compOffsets[numComps+1] = bitSize + 5;
    deweyid[numComps] = 4;
    deweyid[numComps + 1] = 3;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 198:   // 1100 0110   110,00 + 110, ...      (5/3,2 + 5/3,2)
  {
    compOffsets[numComps+1] = bitSize + 5;
    deweyid[numComps] = 4;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    extractValue(bitSize, byteIndex, bitIndex, 2, 4, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }
  case 199:   // 1100 0111   110,00 + 111 ...       (5/3,2)
  {
    deweyid[numComps] = 4;
    ADVANCE(bitSize, byteIndex, bitIndex, 5);
    numComps += 1;
    break;
  }

  case 200:   // 1100 1000   110,01 + 000 ...       (5/3,2)
  {
    deweyid[numComps] = 5;
    ADVANCE(bitSize, byteIndex, bitIndex, 5);
    numComps += 1;
    break;
  }
  case 201:   // 1100 1001   110,01 + 001 +         (5/3,2 + 3/3,0)
  {
    compOffsets[numComps+1] = bitSize + 5;
    deweyid[numComps] = 5;
    deweyid[numComps + 1] = 0;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 202:   // 1100 1010   110,01 + 01 + 0 ...    (5/3,2 + 2/2,0)
  {
    compOffsets[numComps+1] = bitSize + 5;
    deweyid[numComps] = 5;
    deweyid[numComps + 1] = 1;
    ADVANCE(bitSize, byteIndex, bitIndex, 7);
    numComps += 2;
    break;
  }
  case 203:   // 1100 1011   110,01 + 01 + 1 ...    (5/3,2 + 2/2,0)
  {
    compOffsets[numComps+1] = bitSize + 5;
    deweyid[numComps] = 5;
    deweyid[numComps + 1] = 1;
    ADVANCE(bitSize, byteIndex, bitIndex, 7);
    numComps += 2;
    break;
  }
  case 204:   // 1100 1100   110,01 + 10,0 +        (5/3,2 + 3/2,1)
  {
    compOffsets[numComps+1] = bitSize + 5;
    deweyid[numComps] = 5;
    deweyid[numComps + 1] = 2;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 205:   // 1100 1101   110,01 + 10,1 +        (5/3,2 + 3/2,1)
  {
    compOffsets[numComps+1] = bitSize + 5;
    deweyid[numComps] = 5;
    deweyid[numComps + 1] = 3;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 206:   // 1100 1110   110,01 + 110, ...      (5/3,2 + 5/3,2)
  {
    compOffsets[numComps+1] = bitSize + 5;
    deweyid[numComps] = 5;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    extractValue(bitSize, byteIndex, bitIndex, 2, 4, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }
  case 207:   // 1100 1111   110,01 + 111 ...       (5/3,2)
  {
    deweyid[numComps] = 5;
    ADVANCE(bitSize, byteIndex, bitIndex, 5);
    numComps += 1;
    break;
  }

  case 208:   // 1101 0000   110,10 + 000 ...       (5/3,2)
  {
    deweyid[numComps] = 6;
    ADVANCE(bitSize, byteIndex, bitIndex, 5);
    numComps += 1;
    break;
  }
  case 209:   // 1101 0001   110,10 + 001 +         (5/3,2 + 3/3,0)
  {
    compOffsets[numComps+1] = bitSize + 5;
    deweyid[numComps] = 6;
    deweyid[numComps + 1] = 0;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 210:   // 1101 0010   110,10 + 01 + 0 ...    (5/3,2 + 2/2,0)
  {
    compOffsets[numComps+1] = bitSize + 5;
    deweyid[numComps] = 6;
    deweyid[numComps + 1] = 1;
    ADVANCE(bitSize, byteIndex, bitIndex, 7);
    numComps += 2;
    break;
  }
  case 211:   // 1101 0011   110,10 + 01 + 1 ...    (5/3,2 + 2/2,0)
  {
    compOffsets[numComps+1] = bitSize + 5;
    deweyid[numComps] = 6;
    deweyid[numComps + 1] = 1;
    ADVANCE(bitSize, byteIndex, bitIndex, 7);
    numComps += 2;
    break;
  }
  case 212:   // 1101 0100   110,10 + 10,0 +        (5/3,2 + 3/2,1)
  {
    compOffsets[numComps+1] = bitSize + 5;
    deweyid[numComps] = 6;
    deweyid[numComps + 1] = 2;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 213:   // 1101 0101   110,10 + 10,1 +        (5/3,2 + 3/2,1)
  {
    compOffsets[numComps+1] = bitSize + 5;
    deweyid[numComps] = 6;
    deweyid[numComps + 1] = 3;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 214:   // 1101 0110   110,10 + 110, ...      (5/3,2 + 5/3,2)
  {
    compOffsets[numComps+1] = bitSize + 5;
    deweyid[numComps] = 6;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    extractValue(bitSize, byteIndex, bitIndex, 2, 4, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }
  case 215:   // 1101 0111   110,10 + 111 ...       (5/3,2)
  {
    deweyid[numComps] = 6;
    ADVANCE(bitSize, byteIndex, bitIndex, 5);
    numComps += 1;
    break;
  }

  case 216:   // 1101 1000   110,11 + 000 ...       (5/3,2)
  {
    deweyid[numComps] = 7;
    ADVANCE(bitSize, byteIndex, bitIndex, 5);
    numComps += 1;
    break;
  }
  case 217:   // 1101 1001   110,11 + 001 +         (5/3,2 + 3/3,0)
  {
    compOffsets[numComps+1] = bitSize + 5;
    deweyid[numComps] = 7;
    deweyid[numComps + 1] = 0;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 218:   // 1101 1010   110,11 + 01 + 0 ...    (5/3,2 + 2/2,0)
  {
    compOffsets[numComps+1] = bitSize + 5;
    deweyid[numComps] = 7;
    deweyid[numComps + 1] = 1;
    ADVANCE(bitSize, byteIndex, bitIndex, 7);
    numComps += 2;
    break;
  }
  case 219:   // 1101 1011   110,11 + 01 + 1 ...    (5/3,2 + 2/2,0)
  {
    compOffsets[numComps+1] = bitSize + 5;
    deweyid[numComps] = 7;
    deweyid[numComps + 1] = 1;
    ADVANCE(bitSize, byteIndex, bitIndex, 7);
    numComps += 2;
    break;
  }
  case 220:   // 1101 1100   110,11 + 10,0 +        (5/3,2 + 3/2,1)
  {
    compOffsets[numComps+1] = bitSize + 5;
    deweyid[numComps] = 7;
    deweyid[numComps + 1] = 2;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 221:   // 1101 1101   110,11 + 10,1 +        (5/3,2 + 3/2,1)
  {
    compOffsets[numComps+1] = bitSize + 5;
    deweyid[numComps] = 7;
    deweyid[numComps + 1] = 3;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 222:   // 1101 1110   110,11 + 110, ...      (5/3,2 + 5/3,2)
  {
    compOffsets[numComps+1] = bitSize + 5;
    deweyid[numComps] = 7;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    extractValue(bitSize, byteIndex, bitIndex, 2, 4, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }
  case 223:   // 1101 1111   110,11 + 111 ...       (5/3,2)
  {
    deweyid[numComps] = 7;
    ADVANCE(bitSize, byteIndex, bitIndex, 5);
    numComps += 1;
    break;
  }
  case 224:   // 1110 0000   1110,0000 +            (8/4,4)
  {
    deweyid[numComps] = 8;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 1;
    break;
  }
  case 225:   // 1110 0001   1110,0001 +            (8/4,4)
  {
    deweyid[numComps] = 9;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 1;
    break;
  }
  case 226:   // 1110 0010   1110,0010 +            (8/4,4)
  {
    deweyid[numComps] = 10;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 1;
    break;
  }
  case 227:   // 1110 0011   1110,0011 +            (8/4,4)
  {
    deweyid[numComps] = 11;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 1;
    break;
  }
  case 228:   // 1110 0100   1110,0100 +            (8/4,4)
  {
    deweyid[numComps] = 12;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 1;
    break;
  }
  case 229:   // 1110 0101   1110,0101 +            (8/4,4)
  {
    deweyid[numComps] = 13;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 1;
    break;
  }
  case 230:   // 1110 0110   1110,0110 +            (8/4,4)
  {
    deweyid[numComps] = 14;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 1;
    break;
  }
  case 231:   // 1110 0111   1110,0111 +            (8/4,4)
  {
    deweyid[numComps] = 15;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 1;
    break;
  }
  case 232:   // 1110 1000   1110,1000 +            (8/4,4)
  {
    deweyid[numComps] = 16;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 1;
    break;
  }
  case 233:   // 1110 1001   1110,1001 +            (8/4,4)
  {
    deweyid[numComps] = 17;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 1;
    break;
  }
  case 234:   // 1110 1010   1110,1010 +            (8/4,4)
  {
    deweyid[numComps] = 18;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 1;
    break;
  }
  case 235:   // 1110 1011   1110,1011 +            (8/4,4)
  {
    deweyid[numComps] = 19;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 1;
    break;
  }
  case 236:   // 1110 1100   1110,1100 +            (8/4,4)
  {
    deweyid[numComps] = 20;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 1;
    break;
  }
  case 237:   // 1110 1101   1110,1101 +            (8/4,4)
  {
    deweyid[numComps] = 21;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 1;
    break;
  }
  case 238:   // 1110 1110   1110,1110 +            (8/4,4)
  {
    deweyid[numComps] = 22;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 1;
    break;
  }
  case 239:   // 1110 1111   1110,1111 +            (8/4,4)
  {
    deweyid[numComps] = 23;
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    numComps += 1;
    break;
  }
  case 240:   // 1111 0000   11110,000...           (13/5,8)
  {
    ADVANCE(bitSize, byteIndex, bitIndex, 5);
    extractValue(bitSize, byteIndex, bitIndex, 8, 24, deweyid[numComps]);
    numComps += 1;
    break;
  }
  case 241:   // 1111 0001   11110,001...           (13/5,8)
  {
    ADVANCE(bitSize, byteIndex, bitIndex, 5);
    extractValue(bitSize, byteIndex, bitIndex, 8, 24, deweyid[numComps]);
    numComps += 1;
    break;
  }
  case 242:   // 1111 0010   11110,010...           (13/5,8)
  {
    ADVANCE(bitSize, byteIndex, bitIndex, 5);
    extractValue(bitSize, byteIndex, bitIndex, 8, 24, deweyid[numComps]);
    numComps += 1;
    break;
  }
  case 243:   // 1111 0011   11110,011...           (13/5,8)
  {
    ADVANCE(bitSize, byteIndex, bitIndex, 5);
    extractValue(bitSize, byteIndex, bitIndex, 8, 24, deweyid[numComps]);
    numComps += 1;
    break;
  }
  case 244:   // 1111 0100   11110,100...           (13/5,8)
  {
    ADVANCE(bitSize, byteIndex, bitIndex, 5);
    extractValue(bitSize, byteIndex, bitIndex, 8, 24, deweyid[numComps]);
    numComps += 1;
    break;
  }
  case 245:   // 1111 0101   11110,101...           (13/5,8)
  {
    ADVANCE(bitSize, byteIndex, bitIndex, 5);
    extractValue(bitSize, byteIndex, bitIndex, 8, 24, deweyid[numComps]);
    numComps += 1;
    break;
  }
  case 246:   // 1111 0110   11110,110...           (13/5,8)
  {
    ADVANCE(bitSize, byteIndex, bitIndex, 5);
    extractValue(bitSize, byteIndex, bitIndex, 8, 24, deweyid[numComps]);
    numComps += 1;
    break;
  }
  case 247:   // 1111 0111   11110,111...           (13/5,8)
  {
    ADVANCE(bitSize, byteIndex, bitIndex, 5);
    extractValue(bitSize, byteIndex, bitIndex, 8, 24, deweyid[numComps]);
    numComps += 1;
    break;
  }
  case 248:   // 1111 1000   111110,00...           (18/6,12)
  {
    ADVANCE(bitSize, byteIndex, bitIndex, 6);
    extractValue(bitSize, byteIndex, bitIndex, 12, 280, deweyid[numComps]);
    numComps += 1;
    break;
  }
  case 249:   // 1111 1001   111110,01...           (18/6,12)
  {
    ADVANCE(bitSize, byteIndex, bitIndex, 6);
    extractValue(bitSize, byteIndex, bitIndex, 12, 280, deweyid[numComps]);
    numComps += 1;
    break;
  }
  case 250:   // 1111 1010   111110,10...           (18/6,12)
  {
    ADVANCE(bitSize, byteIndex, bitIndex, 6);
    extractValue(bitSize, byteIndex, bitIndex, 12, 280, deweyid[numComps]);
    numComps += 1;
    break;
  }
  case 251:   // 1111 1011   111110,11...           (18/6,12)
  {
    ADVANCE(bitSize, byteIndex, bitIndex, 6);
    extractValue(bitSize, byteIndex, bitIndex, 12, 280, deweyid[numComps]);
    numComps += 1;
    break;
  }
  case 252:   // 1111 1100   1111110,0...           (23/7,16)
  {
    ADVANCE(bitSize, byteIndex, bitIndex, 7);
    extractValue(bitSize, byteIndex, bitIndex, 16, 4376, deweyid[numComps]);
    numComps += 1;
    break;
  }
  case 253:   // 1111 1101   1111110,1...           (23/7,16)
  {
    ADVANCE(bitSize, byteIndex, bitIndex, 7);
    extractValue(bitSize, byteIndex, bitIndex, 16, 4376, deweyid[numComps]);
    numComps += 1;
    break;
  }
  case 254:   // 1111 1110   11111110,...           (28/8,20)
  {
    ADVANCE(bitSize, byteIndex, bitIndex, 8);
    extractValue(bitSize, byteIndex, bitIndex, 20, 69912, deweyid[numComps]);
    numComps += 1;
    break;
  }
  case 255:   // 1111 1111   11111111,...           (28/8,20)
    ZORBA_ASSERT (false);
    break;
  default:
  {
    std::cerr << "byte " << std::hex << (unsigned short)byte << " NYI" << std::endl;
    byteIndex = 256;
  }
  }
}


/*******************************************************************************

********************************************************************************/
void OrdPath::extractValue(
    ulong& bitSize,
    ulong& byteIndex,
    ulong& bitIndex,
    ulong  numBits,
    long   baseValue,
    long&  result) const
{
  bitSize += numBits;

  if (numBits < 8 - bitIndex)
  {
    unsigned char byte = theBuffer[byteIndex];
    byte <<= bitIndex;
    byte >>= (8 - numBits);
    bitIndex += numBits;
    result = byte;
    result += baseValue;
    return;
  }

  unsigned char byte = theBuffer[byteIndex]  & theByteMasks[bitIndex][0];
  result = byte;
  numBits -= (8 - bitIndex);
  byteIndex++;

  ulong numBytes = numBits / 8;

  for (ulong i = 0; i < numBytes; i++)
  {
    result <<= 8;
    result |= theBuffer[byteIndex];
    byteIndex++;
  }

  numBits -= numBytes * 8;
  bitIndex = numBits;

  if (numBits > 0)
  {
    result <<= numBits;
    byte = theBuffer[byteIndex]  & theByteMasks[numBits][1];
    byte >>= (8 - numBits);
    result |= byte;
  }

  result += baseValue;
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class OrdPathStack                                                         //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
OrdPathStack::OrdPathStack()
  :
  theNumComps(0),
  theByteIndex(0),
  theBitsAvailable(0)
{
  memset(theBuffer, 0, OrdPath::MAX_BYTE_LEN);
}


/*******************************************************************************

********************************************************************************/
void OrdPathStack::init()
{
  theDeweyId[0] = 1;
  theNumComps = 1;

  theCompLens[0] = 2;

  theBuffer[1] = 0x40;
  theByteIndex = 1;
  theBitsAvailable = 6;
}


/*******************************************************************************

********************************************************************************/
ulong OrdPathStack::getByteLength() const
{
  return theByteIndex + 1;
}


/*******************************************************************************

********************************************************************************/
void OrdPathStack::pushChild()
{
  if (theByteIndex == OrdPath::MAX_BYTE_LEN ||
      (theByteIndex == OrdPath::MAX_BYTE_LEN - 1 && theBitsAvailable < 2))
  {
    ZORBA_ERROR_ALERT_OSS(ZorbaError::XQP0018_NODEID_ERROR,
                          NULL, DONT_CONTINUE_EXECUTION,
                          "A nodeid requires more than " << OrdPath::MAX_BYTE_LEN
                          << " bytes", "");
  }

  theDeweyId[theNumComps] = 1;
  theCompLens[theNumComps] = 2;
  theNumComps++;

  if (theBitsAvailable >= 2)
  {
    theBuffer[theByteIndex] |= (0x40 >> (8 - theBitsAvailable));
    theBitsAvailable -= 2;
  }
  else if (theBitsAvailable == 1)
  {
    theBitsAvailable = 7;
    theByteIndex++;
    theBuffer[theByteIndex] |= 0x80;
  }
  else
  {
    theByteIndex++;
    theBitsAvailable = 6;
    theBuffer[theByteIndex] = 0x40;
  }
}


/*******************************************************************************

********************************************************************************/
void OrdPathStack::popChild()
{
  // Pop the last uncompressed component.
  theNumComps--;
  if (theNumComps == 0)
    return;

  // Increment the last uncompressed component by 2.
  theDeweyId[theNumComps - 1] += 2;

  // Pop the last 2 compressed components
  ulong numBits = theCompLens[theNumComps] + theCompLens[theNumComps-1];
  ulong numBytes = (numBits + theBitsAvailable) / 8;
  theByteIndex -= numBytes;
  theBitsAvailable = (numBits + theBitsAvailable) % 8;

  theBuffer[theByteIndex] &= 0xff << theBitsAvailable;

  if (numBytes > 0)
    memset(&theBuffer[theByteIndex+1], 0, numBytes);

  // Increment the last compressed component by 2.
  compressComp(theNumComps - 1, theDeweyId[theNumComps - 1]);
}


/*******************************************************************************

********************************************************************************/
void OrdPathStack::nextChild()
{
  Assert(theNumComps > 0);

  // Increment the last uncompressed component by 2.
  theDeweyId[theNumComps - 1] += 2;

  // Pop the last compressed component
  ulong numBits = theCompLens[theNumComps-1];
  ulong numBytes = (numBits + theBitsAvailable) / 8;
  theByteIndex -= numBytes;
  theBitsAvailable = (numBits + theBitsAvailable) % 8;

  theBuffer[theByteIndex] &= 0xff << theBitsAvailable;

  if (numBytes > 0)
    memset(&theBuffer[theByteIndex+1], 0, numBytes);

  // Increment the last compressed component by 2.
  compressComp(theNumComps - 1, theDeweyId[theNumComps - 1]);
}


/*******************************************************************************

********************************************************************************/
void OrdPathStack::compressComp(ulong comp, long value)
{
  uint32_t eval;
  ulong bitsNeeded;

  if (value < 0)
  {
    value = -value;

    if (value < OrdPath::DEFAULT_FAN_OUT)
    {
      bitsNeeded = OrdPath::theNegV2LMap[value];
      eval = OrdPath::theNegV2EVMap[value] << 16;
    }
    else if (value < 277)
    {
      theCompLens[comp] = bitsNeeded = 14;

      value = 276 - value;
      eval = ((uint32_t)value) << 24;
      eval >>= 6;
      eval |= 0x04000000;
    }
    else if (value < 4373)
    {
      theCompLens[comp] = bitsNeeded = 19;

      value = 2372 - value;
      eval = ((uint32_t)value) << 20;
      eval >>= 7;
      eval |= 0x02000000;
    }
    else if (value < 69909)
    {
      theCompLens[comp] = bitsNeeded = 24;

      value = 69908 - value;
      eval = ((uint32_t)value) << 16;
      eval >>= 8;
      eval |= 0x01000000;
    }
    else if (value < 1118485)
    {
      theCompLens[comp] = bitsNeeded = 29;

      value = 1118484 - value;
      eval = ((uint32_t)value) << 12;
      eval >>= 9;
      eval |= 0x00080000;
    }
    else
    {
      ZORBA_ERROR_ALERT(ZorbaError::XQP0018_NODEID_ERROR,
                        NULL, DONT_CONTINUE_EXECUTION,
                        "A nodeid component is too large to be encoded");
      return;
    }
  }
  else if (value < OrdPath::DEFAULT_FAN_OUT)
  {
    theCompLens[comp] = bitsNeeded = OrdPath::thePosV2LMap[value];
    eval = OrdPath::thePosV2EVMap[value] << 16;
  }
  else
  {
    if (value < 280)
    {
      theCompLens[comp] = bitsNeeded = 13;

      value -= 24;
      eval = ((uint32_t)value) << 24;
      while (!(eval & 0x8FFFFFFF))
        eval <<= 1;

      eval >>= 5;
      eval |= 0xF0000000;
    }
    else if (value < 4376)
    {
      theCompLens[comp] = bitsNeeded = 18;

      value -= 280;
      eval = ((uint32_t)value) << 20;
      eval >>= 6;
      eval |= 0xF8000000;
    }
    else if (value < 69912)
    {
      theCompLens[comp] = bitsNeeded = 23;

      value -= 4376;
      eval = ((uint32_t)value) << 16;
      eval >>= 7;
      eval |= 0xFC000000;
    }
    else if (value < 1118488)
    {
      theCompLens[comp] = bitsNeeded = 28;

      value -= 69912;
      eval = ((uint32_t)value) << 12;
      eval >>= 8;
      eval |= 0xFE000000;
    }
    else
    {
      ZORBA_ERROR_ALERT(ZorbaError::XQP0018_NODEID_ERROR,
                        NULL, DONT_CONTINUE_EXECUTION,
                        "A nodeid component is too large to be encoded");
      return;
    }
  }

  ulong bytesNeeded = theByteIndex +
                      (bitsNeeded + 15 - theBitsAvailable) / 8;

  if (bytesNeeded > OrdPath::MAX_BYTE_LEN)
  {
    ZORBA_ERROR_ALERT_OSS(ZorbaError::XQP0018_NODEID_ERROR,
                          NULL, DONT_CONTINUE_EXECUTION,
                          "A nodeid requires more than " << OrdPath::MAX_BYTE_LEN
                          << " bytes", "");
    return;
  }

  do
  {
    ulong bitsUsed = (bitsNeeded < theBitsAvailable ?
                      bitsNeeded : theBitsAvailable);

    unsigned char byte = (unsigned char)
                         ((eval & OrdPath::theValueMasks[bitsUsed]) >>
                          (32 - theBitsAvailable));

    theBuffer[theByteIndex] |= byte;
    eval = eval << bitsUsed;
    bitsNeeded -= bitsUsed;
    theBitsAvailable -= bitsUsed;
    if (theBitsAvailable == 0 && bitsNeeded > 0)
    {
      theBitsAvailable = 8;
      theByteIndex ++;
    }
  }
  while (bitsNeeded > 0);
}


/*******************************************************************************

********************************************************************************/
std::string OrdPathStack::show() const
{
  std::stringstream str;

  for (ulong i = 0; i < theNumComps; i++)
  {
    str << theDeweyId[i];
    if (i < theNumComps-1)
      str << ".";
  }
#if 1
  str << " ";

  ulong len = getByteLength();

  for (ulong i = 1; i < len; i++)
  {
    str << std::hex << (unsigned short)theBuffer[i] << '|';
  }
#endif
  return str.str().c_str();
}

} // namespace store
} // namespace zorba

