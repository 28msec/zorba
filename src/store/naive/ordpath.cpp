
#include "errors/Error.h"
#include "util/Assert.h"
#include "store/naive/ordpath.h"
#include "store/naive/store_defs.h"


namespace xqp
{

/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class OrdPathStack                                                         //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************
  Masks ussed during compression
********************************************************************************/
const uint32_t OrdPathStack::theValueMasks[9] = 
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
  id components with values between 0 and DEFAULT_FAN_OUT - 1.
********************************************************************************/
const unsigned char OrdPathStack::thePosV2LMap[DEFAULT_FAN_OUT] = 
{
  /* 0 */        4,
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
const unsigned char OrdPathStack::theNegV2LMap[DEFAULT_FAN_OUT] = 
{
  /*   -1,   0 */    4, 4,
  /*   -5,  -2 */    6, 6, 6, 6,               
  /*  -21,  -6 */    9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 
  /* -277, -22 */    14, 14, 14, 14, 14, 14, 14, 14, 14, 14 
};


/*******************************************************************************
  This array maps each component value between 0 and DEFAULT_FAN_OUT - 1 to its
  encoded version.
********************************************************************************/
const uint16_t OrdPathStack::thePosV2EVMap[DEFAULT_FAN_OUT] = 
{
  0x3000,  // 0   = 001,1           -> 0011-0000-0000-0000

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

********************************************************************************/
OrdPathStack::OrdPathStack()
  :
  theTreeId(0),
  theNumComps(0),
  theByteIdx(0),
  theBitsAvailable(0)
{
  memset(theBuffer, 0, MAX_BYTE_LEN);
}


/*******************************************************************************

********************************************************************************/
void OrdPathStack::init(unsigned long treeid)
{
  theTreeId = treeid;

  theDeweyId[0] = 1;
  theNumComps = 1;

  theCompLens[0] = 2;

  theBuffer[1] = 0x40;
  theByteIdx = 1;
  theBitsAvailable = 6;
}


/*******************************************************************************

********************************************************************************/
unsigned long OrdPathStack::getByteLength() const
{
  return (theBitsAvailable == 8 ? theByteIdx : theByteIdx + 1);
}


/*******************************************************************************

********************************************************************************/
void OrdPathStack::pushChild()
{
  theDeweyId[theNumComps] = 1;
  theCompLens[theNumComps] = 2;
  theNumComps++;

  if (theBitsAvailable > 2)
  {
    theBuffer[theByteIdx] |= (0x40 >> (8 - theBitsAvailable));
    theBitsAvailable -= 2;
  }
  else if (theBitsAvailable == 2)
  {
    theBuffer[theByteIdx] |= (0x40 >> 6);
    theBitsAvailable = 8;
    theByteIdx++;
  }
  else // bitsAvailable == 1
  {
    if (theByteIdx == MAX_BYTE_LEN - 1)
    {
      ZORBA_ERROR_ALERT(error_messages::XQP0018_NODEID_OUT_OF_RANGE,
                        error_messages::USER_ERROR,
                        NULL,
                        false);
    }
 
    theBitsAvailable = 7;
    theByteIdx++;
    theBuffer[theByteIdx] |= 0x80;
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
  unsigned long numBits = theCompLens[theNumComps] + theCompLens[theNumComps-1];
  unsigned long numBytes = (numBits + theBitsAvailable - 1 ) / 8;
  theByteIdx -= numBytes;
  memset(&theBuffer[theByteIdx+1], 0, numBytes);
  theBitsAvailable = (numBits + theBitsAvailable) % 8;
  if (theBitsAvailable == 0)
    theBitsAvailable = 8;

  theBuffer[theByteIdx] &= 0xff << theBitsAvailable;

  compressComp(theNumComps - 1, theDeweyId[theNumComps - 1]);
}


/*******************************************************************************

********************************************************************************/
void OrdPathStack::compressComp(unsigned long comp, long value)
{
  uint32_t eval;
  long bitsNeeded;

  if (value < 0)
  {
    value = -value;

    if (value < DEFAULT_FAN_OUT)
    {
      bitsNeeded += theNegV2LMap[value];
    }
    else if (value < 278)
    {
      bitsNeeded += 14;
    }
    else if (value < 4374)
    {
      bitsNeeded += 19;
    }
    else if (value < 69910)
    {
      bitsNeeded += 24;
    }
    else if (value < 1118486)
    {
      bitsNeeded += 29;
    }
    else
    {
      ZORBA_ERROR_ALERT(error_messages::XQP0018_NODEID_OUT_OF_RANGE,
                        error_messages::SYSTEM_ERROR,
                        NULL,
                        false);
    }
  }
  else if (value < DEFAULT_FAN_OUT)
  {
    theCompLens[comp] = bitsNeeded = thePosV2LMap[value];
    eval = thePosV2EVMap[value] << 16;
  }
  else
  {
    if (value < 280)
    {
      theCompLens[comp] = bitsNeeded = 13;

      value -= 24;
      eval = ((uint32_t)value) << 24;
      while (!(eval & 0x8FFFFFFF))
        eval << 1;

      eval >> 5;
      eval |= 0xF0000000;
    }
    else if (value < 4376)
    {
      theCompLens[comp] = bitsNeeded = 18;

      value -= 280;
      eval = ((uint32_t)value) << 20;
      while (!(eval & 0x8FFFFFFF))
        eval << 1;

      eval >> 6;
      eval |= 0xF8000000;
    }
    else if (value < 69912)
    {
      theCompLens[comp] = bitsNeeded = 23;

      value -= 4376;
      eval = ((uint32_t)value) << 16;
      while (!(eval & 0x8FFFFFFF))
        eval << 1;

      eval >> 7;
      eval |= 0xFC000000;
    }
    else if (value < 1118488)
    {
      theCompLens[comp] = bitsNeeded = 28;

      value -= 69912;
      eval = ((uint32_t)value) << 12;
      while (!(eval & 0x8FFFFFFF))
        eval << 1;

      eval >> 8;
      eval |= 0xFE000000;
    }
    else
    {
      ZORBA_ERROR_ALERT(error_messages::XQP0018_NODEID_OUT_OF_RANGE,
                        error_messages::SYSTEM_ERROR,
                        NULL,
                        false);
    }
  }

  do
  {
    long bitsUsed = (bitsNeeded < theBitsAvailable ?
                     bitsNeeded : theBitsAvailable);

    unsigned char byte = (unsigned char) ((eval & theValueMasks[bitsUsed]) >>
                                          (32 - theBitsAvailable));

    theBuffer[theByteIdx] |= byte;
    eval = eval << bitsUsed;
    bitsNeeded -= bitsUsed;
    theBitsAvailable -= bitsUsed;
    long zerone = (theBitsAvailable + 7) / 8;
    theBitsAvailable = theBitsAvailable * zerone + 8 * (1 - zerone);
    theByteIdx += (1 - zerone);
  }
  while (bitsNeeded > 0);
}


/*******************************************************************************

********************************************************************************/
xqp_string OrdPathStack::show() const
{
  std::stringstream str;

  for (unsigned long i = 0; i < theNumComps; i++)
  {
    str << theDeweyId[i];
    if (i < theNumComps-1)
      str << ".";
  }
#if 1
  str << " ";

  unsigned long len = getByteLength();

  for (unsigned long i = 1; i < len; i++)
  {
    str << std::hex << (unsigned short)theBuffer[i];
  }
#endif
  return str.str().c_str();
}


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

********************************************************************************/
OrdPath& OrdPath::operator=(const OrdPathStack& ops)
{
  theTreeId = ops.getTreeId();

  if (theBuffer != NULL)
    delete [] theBuffer;

  unsigned long len = ops.getByteLength();
  theBuffer = new unsigned char[len];
  memcpy(theBuffer, ops.theBuffer, len);
  theBuffer[0] = (unsigned char)len;
  return *this;
}


/*******************************************************************************

********************************************************************************/
unsigned long OrdPath::getByteLength() const
{
  if (theBuffer == NULL)
    return 0;

  return theBuffer[0];
}


/*******************************************************************************

********************************************************************************/
bool OrdPath::operator==(const OrdPath& other) const
{
  unsigned long len = getByteLength();

  if (len != other.getByteLength())
    return false;

  return memcmp(theBuffer, other.theBuffer, len);
}


/*******************************************************************************

********************************************************************************/
int OrdPath::operator<(const OrdPath& other) const
{
  unsigned long len1 = getByteLength();
  unsigned long len2 = other.getByteLength();

  unsigned char* p1 = theBuffer;
  unsigned char* p2 = other.theBuffer;

  if (len1 < len2)
  {
    unsigned char* end = p1 + len1;

    while (p1 != end)
    {
      if (*p1 < *p2)
        return 1;

      p1++;
      p2++;
    }
  }
  else
  {
    unsigned char* end = p2 + len2;

    while (p2 != end)
    {
      if (*p1 < *p2)
        return 1;

      p1++;
      p2++;
    }
  }

  return 0;
}


/*******************************************************************************

********************************************************************************/
void OrdPath::decompress(unsigned long* deweyid, unsigned long& deweylen) const
{
  unsigned long numComps = 0;
  unsigned long byteIndex = 1;
  unsigned long bitIndex = 0;

  unsigned long len = getByteLength() - 1;

  while (byteIndex < len)
  {
    unsigned char byte0 = theBuffer[byteIndex] & theByteMasks[bitIndex][0];
    unsigned char byte1 = theBuffer[byteIndex+1] & theByteMasks[bitIndex][1];
    unsigned char byte = (byte0 << bitIndex) | (byte1 >> (8 - bitIndex));

    decodeByte(deweyid, numComps, byteIndex, bitIndex, byte);
  }

  // Treat the last byte
  unsigned char lastByte = theBuffer[byteIndex];
  Assert(lastByte != 0);
  lastByte <<= bitIndex;
  if (lastByte != 0)
    decodeByte(deweyid, numComps, byteIndex, bitIndex, lastByte);

  deweylen = numComps;
}


/*******************************************************************************

********************************************************************************/
#define ADVANCE(byteIndex, bitIndex, numBits)   \
{                                               \
  (byteIndex) += ((bitIndex) + (numBits)) / 8;  \
  (bitIndex) = ((bitIndex) + (numBits)) % 8;    \
}


/*******************************************************************************

********************************************************************************/
void OrdPath::decodeByte(
    unsigned long* deweyid,
    unsigned long& numComps,
    unsigned long& byteIndex,
    unsigned long& bitIndex,
    unsigned char  byte) const
{
  switch (byte)
  {
  case 0:    // 0000 0000   00000000                (29/9,20)
  {
    Assert(0);
    break;
  }
  case 1:    // 0000 0001   00000001,...            (24/8,16)
  {
    Assert(0);
    break;
  }
  case 2:    // 0000 0010   0000001,0...            (19/7,12)
  {
    Assert(0);
    break;
  }
  case 3:    // 0000 0011   0000001,1...            (19/7,12)
  {
    Assert(0);
    break;
  }
  case 4:    // 0000 0100   000001,00...            (14/6,8)
  {
    Assert(0);
    break;
  }
  case 5:    // 0000 0101   000001,01..             (14/6,8)
  {
    Assert(0);
    break;
  }
  case 6:    // 0000 0110   000001,10...            (14/6,8)
  {
    Assert(0);
    break;
  }
  case 7:    // 0000 0111   000001,11...            (14/6,8)
  {
    Assert(0);
    break;
  }
  case 8:    // 0000 1000   00001,000...            (9/5,4)
  {
    Assert(0);
    break;
  }
  case 9:    // 0000 1001   00001,001...            (9/5,4)
  {
    Assert(0);
    break;
  }
  case 10:   // 0000 1010   00001,010...            (9/5,4)
  {
    Assert(0);
    break;
  }
  case 11:   // 0000 1011   00001,011...            (9/5,4)
  {
    Assert(0);
    break;
  }
  case 12:   // 0000 1100   00001,100...          (9/5,4)
  {
    Assert(0);
    break;
  }
  case 13:   // 0000 1101   00001,101...          (9/5,4)
  {
    Assert(0);
    break;
  }
  case 14:   // 0000 1110   00001,110...          (9/5,4)
  {
    Assert(0);
    break;
  }
  case 15:   // 0000 1111   00001,111...          (9/5,4)
  {
    Assert(0);
    break;
  }


  case 16:   // 0001 0000   0001,00 + 00...       (6/4,2)
  {
    Assert(0);
    break;
  }
  case 17:   // 0001 0001   0001,00 + 01 +        (6/4,2 + 2/2,0)
  {
    Assert(0);
    break;
  }
  case 18:   // 0001 0010   0001,00 + 10, ...     (6/4,2 + 3/2,1)
  {
    Assert(0);
    break;
  }
  case 19:   // 0001 0011   0001,00 + 11...       (6/4,2)
  {
    Assert(0);
    break;
  }
  case 20:   // 0001 0100   0001,01 + 00...       (6/4,2)
  {
    Assert(0);
    break;
  }
  case 21:   // 0001 0101   0001,01 + 01 +        (6/4,2 + 2/2,0)
  {
    Assert(0);
    break;
  }
  case 22:   // 0001 0110   0001,01 + 10, ...     (6/4,2 + 3/2,1)
  {
    Assert(0);
    break;
  }
  case 23:   // 0001 0111   0001,01 + 11...       (6/4,2)
  {
    Assert(0);
    break;
  }
  case 24:   // 0001 1000   0001,10 + 00...       (6/4,2)
  {
    Assert(0);
    break;
  }
  case 25:   // 0001 1001   0001,10 + 01 +        (6/4,2 + 2/2,0)
  {
    Assert(0);
    break;
  }
  case 26:   // 0001 1010   0001,10 + 10, ...     (6/4,2 + 3/2,1)
  {
    Assert(0);
    break;
  }
  case 27:   // 0001 1011   0001,10 + 11 ...      (6/4,2)
  {
    Assert(0);
    break;
  }
  case 28:   // 0001 1100   0001,11 + 00 ...        (6/4,2)
  {
    Assert(0);
    break;
  }
  case 29:   // 0001 1101   0001,11 + 01 +          (6/4,2 + 2/2,0)
  {
    Assert(0);
    break;
  }
  case 30:   // 0001 1110   0001,11 + 10, ...       (6/4,2 + 3/2,1)
  {
    Assert(0);
    break;
  }
  case 31:   // 0001 1111   0001,11 + 11 ...        (6/4,2)
  {
    Assert(0);
    break;
  }
  

  case 32:   // 0010 0000   001,0 + 0000 ...        (4/3,1)
  {
    Assert(0);
    break;
  }
  case 33:   // 0010 0001   001,0 + 0001, ...       (4/3,1 + 6/4,2)
  {
    Assert(0);
    break;
  }
  case 34:   // 0010 0010   001,0 + 001,0 +         (4/3,1 + 4/3,1)
  {
    Assert(0);
    break;
  }
  case 35:   // 0010 0011   001,0 + 001,1 +         (4/3,1 + 4/3,1)
  {
    Assert(0);
    break;
  }
  case 36:   // 0010 0100   001,0 + 01 + 00 ...     (4/3,1 + 2/2,0)
  {
    Assert(0);
    break;
  }
  case 37:   // 0010 0101   001,0 + 01 + 01 +       (4/3,1 + 2/2,0 + 2/2,0)
  {
    Assert(0);
    break;
  }
  case 38:   // 0010 0110   001,0 + 01 + 10, ...    (4/3,1 + 2/2,0 + 3/2,1)
  {
    Assert(0);
    break;
  }
  case 39:   // 0010 0111   001,0 + 01 + 11 ...     (4/3,1 + 2/2,0)
  {
    Assert(0);
    break;
  }
  case 40:   // 0010 1000   001,0 + 10,0 + 0 ...    (4/3,1 + 3/2,1)
  {
    Assert(0);
    break;
  }
  case 41:   // 0010 1001   001,0 + 10,0 + 1 ...    (4/3,1 + 3/2,1)
  {
    Assert(0);
    break;
  }
  case 42:   // 0010 1010   001,0 + 10,1 + 0 ...    (4/3,1 + 3/2,1)
  {
    Assert(0);
    break;
  }
  case 43:   // 0010 1011   001,0 + 10,1 + 1 ...    (4/3,1 + 3/2,1)
  {
    Assert(0);
    break;
  }
  case 44:   // 0010 1100   001,0 + 110,0 ...       (4/3,1 + 5/3,2)
  {
    Assert(0);
    break;
  }
  case 45:   // 0010 1101   001,0 + 110,1 ...       (4/3,1 + 5/3,2)
  {
    Assert(0);
    break;
  }
  case 46:   // 0010 1110   001,0 + 1110, ...       (4/3,1 + 8/4,4)
  {
    Assert(0);
    break;
  }
  case 47:   // 0010 1111   001,0 + 1111 ...        (4/3,1)
  {
    Assert(0);
    break;
  }

  case 48:   // 0011 0000   001,1 + 0000 ...        (4/3,1)
  {
    Assert(0);
    break;
  }
  case 49:   // 0011 0001   001,1 + 0001, ...       (4/3,1 + 6/4,2)
  {
    Assert(0);
    break;
  }
  case 50:   // 0011 0010   001,1 + 001,0 +         (4/3,1 + 4/3,1)
  {
    Assert(0);
    break;
  }
  case 51:   // 0011 0011   001,1 + 001,1 +         (4/3,1 + 4/3,1)
  {
    Assert(0);
    break;
  }
  case 52:   // 0011 0100   001,1 + 01 + 00 ...     (4/3,1 + 2/2,0)
  {
    Assert(0);
    break;
  }
  case 53:   // 0011 0101   001,1 + 01 + 01 +       (4/3,1 + 2/2,0 + 2/2,0)
  {
    Assert(0);
    break;
  }
  case 54:   // 0011 0110   001,1 + 01 + 10, ...    (4/3,1 + 2/2,0 + 3/2,1)
  {
    Assert(0);
    break;
  }
  case 55:   // 0011 0111   001,1 + 01 + 11 ...     (4/3,1 + 2/2,0)
  {
    Assert(0);
    break;
  }
  case 56:   // 0011 1000   001,1 + 10,0 + 0 ...    (4/3,1 + 3/2,1)
  {
    Assert(0);
    break;
  }
  case 57:   // 0011 1001   001,1 + 10,0 + 1 ...    (4/3,1 + 3/2,1)
  {
    Assert(0);
    break;
  }
  case 58:   // 0011 1010   001,1 + 10,1 + 0 ...    (4/3,1 + 3/2,1)
  {
    Assert(0);
    break;
  }
  case 59:   // 0011 1011   001,1 + 10,1 + 1 ...    (4/3,1 + 3/2,1)
  {
    Assert(0);
    break;
  }
  case 60:   // 0011 1100   001,1 + 110,0 ...       (4/3,1 + 5/3,2)
  {
    Assert(0);
    break;
  }
  case 61:   // 0011 1101   001,1 + 110,1 ...       (4/3,1 + 5/3,2)
  {
    Assert(0);
    break;
  }
  case 62:   // 0011 1110   001,1 + 1110, ...       (4/3,1 + 8/4,4)
  {
    Assert(0);
    break;
  }
  case 63:   // 0011 1111   001,1 + 1111 ...        (4/3,1)
  {
    Assert(0);
    break;
  }


  case 64:   // 0100 0000   01 + 000000 ...         (2/2,0)
  {
    deweyid[numComps] = 1;
    numComps++;
    ADVANCE(byteIndex, bitIndex, 2);
    break;
  }
  case 65:   // 0100 0001   01 + 000001, ...        (2/2,0 + 14/6,8)
  {
    Assert(0);
    break;
  }
  case 66:   // 0100 0010   01 + 00001,0 ...        (2/2,0 + 9/5,4)
  {
    Assert(0);
    break;
  }
  case 67:   // 0100 0011   01 + 00001,1 ...      (2/2,0 + 9/5,4)
  {
    Assert(0);
    break;
  }
  case 68:   // 0100 0100   01 + 0001,00 +        (2/2,0 + 6/4,2)
  {
    Assert(0);
    break;
  }
  case 69:   // 0100 0101   01 + 0001,01 +        (2/2,0 + 6/4,2)
  {
    Assert(0);
    break;
  }
  case 70:   // 0100 0110   01 + 0001,10 +        (2/2,0 + 6/4,2)
  {
    Assert(0);
    break;
  }
  case 71:   // 0100 0111   01 + 0001,11 +        (2/2,0 + 6/4,2)
  {
    Assert(0);
    break;
  }
  
  case 72:   // 0100 1000   01 + 001,0 + 00 ...   (2/2,0 + 4/3,1)
  {
    Assert(0);
    break;
  }
  case 73:   // 0100 1001   01 + 001,0 + 01 +     (2/2,0 + 4/3,1 + 2/2,0)
  {
    Assert(0);
    break;
  }
  case 74:   // 0100 1010   01 + 001,0 + 10, ...  (2/2,0 + 4/3,1 + 3/2,1)
  {
    Assert(0);
    break;
  }
  case 75:   // 0100 1011   01 + 001,0 + 11 ...   (2/2,0 + 4/3,1)
  {
    Assert(0);
    break;
  }
  case 76:   // 0100 1100   01 + 001,1 + 00 ...   (2/2,0 + 4/3,1)
  {
    Assert(0);
    break;
  }
  case 77:   // 0100 1101   01 + 001,1 + 01 +     (2/2,0 + 4/3,1 + 2/2,0)
  {
    Assert(0);
    break;
  }
  case 78:   // 0100 1110   01 + 001,1 + 10, ...    (2/2,0 + 4/3,1 + 3/2,1)
  {
    Assert(0);
    break;
  }
  case 79:   // 0100 1111   01 + 001,1 + 11 ...     (2/2,0 + 4/3,1)
  {
    Assert(0);
    break;
  }

  case 80:   // 0101 0000   01 + 01 + 0000 ...      (2/2,0 + 2/2,0)
  {
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 1;
    numComps += 2;
    ADVANCE(byteIndex, bitIndex, 4);
    break;
  }
  case 81:   // 0101 0000   01 + 01 + 0001, ...     (2/2,0 + 2/2,0 + 6/4,2)
  {
    Assert(0);
    break;
  }
  case 82:   // 0101 0010   01 + 01 + 001,0 +       (2/2,0 + 2/2,0 + 4/3,1)
  {
    Assert(0);

    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 1;
    deweyid[numComps + 2] = -1;
    numComps += 3;
    byteIndex++;
    break;
  }
  case 83:   // 0101 0011   01 + 01 + 001,1 +     (2/2,0 + 2/2,0 + 4/3,1)
  {
    Assert(0);

    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 1;
    deweyid[numComps + 2] = 0;
    numComps += 3;
    byteIndex++;
    break;
  }
  case 84:   // 0101 0100   01 + 01 + 01 + 00 ... (2/2,0 + 2/2,0 + 2/2,0)
  {
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 1;
    deweyid[numComps + 2] = 1;
    numComps += 3;
    ADVANCE(byteIndex, bitIndex, 6);
    break;
  }
  case 85:   // 0101 0101   01 + 01 + 01 + 01 + (2/2,0 + 2/2,0 + 2/2,0 + 2/2,0)
  {
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
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 1;
    deweyid[numComps + 2] = 1;
    ADVANCE(byteIndex, bitIndex, 8);
    extractValue(byteIndex, bitIndex, 1, 2, deweyid[numComps + 3]);
    numComps += 3;
    break;
  }
  case 87:   // 0101 0111   01 + 01 + 01 + 11 ... (2/2,0 + 2/2,0 + 2/2,0)
  {
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 1;
    deweyid[numComps + 2] = 1;
    ADVANCE(byteIndex, bitIndex, 6);
    numComps += 3;
    break;
  }
  case 88:   // 0101 1000   01 + 01 + 10,0 + 0 ... (2/2,0 + 2/2,0 + 3/2,1)
  {
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 1;
    deweyid[numComps + 2] = 2;
    ADVANCE(byteIndex, bitIndex, 7);
    numComps += 3;
    break;
  }
  case 89:   // 0101 1001   01 + 01 + 10,0 + 1 ... (2/2,0 + 2/2,0 + 3/2,1)
  {
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 1;
    deweyid[numComps + 2] = 2;
    ADVANCE(byteIndex, bitIndex, 7);
    numComps += 3;
    break;
  }
  case 90:   // 0101 1010   01 + 01 + 10,1 + 0 ... (2/2,0 + 2/2,0 + 3/2,1)
  {
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 1;
    deweyid[numComps + 2] = 3;
    ADVANCE(byteIndex, bitIndex, 7);
    numComps += 3;
    break;
  }
  case 91:   // 0101 1011   01 + 01 + 10,1 + 1 ... (2/2,0 + 2/2,0 + 3/2,1)
  {
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 1;
    deweyid[numComps + 2] = 3;
    ADVANCE(byteIndex, bitIndex, 7);
    numComps += 3;
    break;
  }
  case 92:   // 0101 1100   01 + 01 + 110,0 ... (2/2,0 + 2/2,0 + 5/3,2)
  {
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 1;
    ADVANCE(byteIndex, bitIndex, 7);
    extractValue(byteIndex, bitIndex, 2, 4, deweyid[numComps + 2]);
    numComps += 3;
    break;
  }
  case 93:   // 0101 1101   01 + 01 + 110,1 ...     (2/2,0 + 2/2,0 + 5/3,2)
  {
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 1;
    ADVANCE(byteIndex, bitIndex, 7);
    extractValue(byteIndex, bitIndex, 2, 4, deweyid[numComps + 2]);
    numComps += 3;
    break;
  }
  case 94:   // 0101 1110   01 + 01 + 1110, ...     (2/2,0 + 2/2,0 + 8/4,4)
  {
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 1;
    ADVANCE(byteIndex, bitIndex, 8);
    extractValue(byteIndex, bitIndex, 4, 8, deweyid[numComps + 2]);
    numComps += 3;
    break;
  }
  case 95:   // 0101 1111   01 + 01 + 1111 ...      (2/2,0 + 2/2,0)
  {
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 1;
    ADVANCE(byteIndex, bitIndex, 4);
    numComps += 2;
    break;
  }


  case 96:   // 0110 0000   01 + 10,0 + 000 ...     (2/2,0 + 3/2,1)
  {
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 2;
    ADVANCE(byteIndex, bitIndex, 5);
    numComps += 2;
    break;
  }
  case 97:   // 0110 0001   01 + 10,0 + 001, ...    (2/2,0 + 3/2,1 + 4/3,1)
  {
    Assert(0);
    break;
  }
  case 98:   // 0110 0010   01 + 10,0 + 01 + 0 ...  (2/2,0 + 3/2,1 + 2/2,0)
  {
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 2;
    deweyid[numComps + 2] = 1;
    ADVANCE(byteIndex, bitIndex, 7);
    numComps += 3;
    break;
  }
  case 99:   // 0110 0011   01 + 10,0 + 01 + 1 ...  (2/2,0 + 3/2,1 + 2/2,0)
  {
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 2;
    deweyid[numComps + 2] = 1;
    ADVANCE(byteIndex, bitIndex, 7);
    numComps += 3;
    break;
  }
  case 100:   // 0110 0100   01 + 10,0 + 10,0 +     (2/2,0 + 3/2,1 + 3/2,1)
  {
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 2;
    deweyid[numComps + 2] = 2;
    ADVANCE(byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 101:   // 0110 0101   01 + 10,0 + 10,1 +     (2/2,0 + 3/2,1 + 3/2,1)
  {
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 2;
    deweyid[numComps + 2] = 3;
    ADVANCE(byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 102:   // 0110 0110   01 + 10,0 + 110, ...   (2/2,0 + 3/2,1 + 5/3,2)
  {
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 2;
    ADVANCE(byteIndex, bitIndex, 8);
    extractValue(byteIndex, bitIndex, 2, 4, deweyid[numComps + 2]);
    numComps += 3;
    break;
  }
  case 103:   // 0110 0111   01 + 10,0 + 111 ...    (2/2,0 + 3/2,1)
  {
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 2;
    ADVANCE(byteIndex, bitIndex, 5);
    numComps += 2;
    break;
  }
  case 104:   // 0110 1000   01 + 10,1 + 000 ...    (2/2,0 + 3/2,1)
  {
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 3;
    ADVANCE(byteIndex, bitIndex, 5);
    numComps += 2;
    break;
  }
  case 105:   // 0110 1001   01 + 10,1 + 001 ...    (2/2,0 + 3/2,1 + 4/3,1)
  {
    Assert(0);
    break;
  }
  case 106:   // 0110 1010   01 + 10,1 + 01 + 0 ... (2/2,0 + 3/2,1 + 2/2,0)
  {
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 3;
    deweyid[numComps + 2] = 1;
    ADVANCE(byteIndex, bitIndex, 7);
    numComps += 3;
    break;
  }
  case 107:   // 0110 1011   01 + 10,1 + 01 + 1 ... (2/2,0 + 3/2,1 + 2/2,0)
  {
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 3;
    deweyid[numComps + 2] = 1;
    ADVANCE(byteIndex, bitIndex, 7);
    numComps += 3;
    break;
  }
  case 108:   // 0110 1100   01 + 10,1 + 10,0 ...   (2/2,0 + 3/2,1 + 3/2,1)
  {
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 3;
    deweyid[numComps + 2] = 2;
    ADVANCE(byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 109:   // 0110 1101   01 + 10,1 + 10,1 ...   (2/2,0 + 3/2,1 + 3/2,1)
  {
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 3;
    deweyid[numComps + 2] = 3;
    ADVANCE(byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 110:   // 0110 1110   01 + 10,1 + 110, ...   (2/2,0 + 3/2,1 + 5/3,2)
  {
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 3;
    ADVANCE(byteIndex, bitIndex, 8);
    extractValue(byteIndex, bitIndex, 2, 4, deweyid[numComps + 2]);
    numComps += 3;
    break;
  }
  case 111:   // 0110 1111   01 + 10,1 + 111 ...    (2/2,0 + 3/2,1)
  {
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 3;
    ADVANCE(byteIndex, bitIndex, 5);
    numComps += 2;
    break;
  }


  case 112:   // 0111 0000   01 + 110,00 + 0 ...    (2/2,0 + 5/3,2)
  {
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 4;
    ADVANCE(byteIndex, bitIndex, 7);
    numComps += 2;
    break;
  }
  case 113:   // 0111 0001   01 + 110,00 + 1 ...    (2/2,0 + 5/3,2)
  {
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 4;
    ADVANCE(byteIndex, bitIndex, 7);
    numComps += 2;
    break;
  }
  case 114:   // 0111 0010   01 + 110,01 + 0 ...    (2/2,0 + 5/3,2)
  {
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 5;
    ADVANCE(byteIndex, bitIndex, 7);
    numComps += 2;
    break;
  }
  case 115:   // 0111 0011   01 + 110,01 + 1 ...    (2/2,0 + 5/3,2)
  {
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 5;
    ADVANCE(byteIndex, bitIndex, 7);
    numComps += 2;
    break;
  }
  case 116:   // 0111 0100   01 + 110,10 + 0 ...    (2/2,0 + 5/3,2)
  {
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 6;
    ADVANCE(byteIndex, bitIndex, 7);
    numComps += 2;
    break;
  }
  case 117:   // 0111 0101   01 + 110,10 + 1 ...    (2/2,0 + 5/3,2)
  {
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 6;
    ADVANCE(byteIndex, bitIndex, 7);
    numComps += 2;
    break;
  }
  case 118:   // 0111 0110   01 + 110,11 + 0 ...    (2/2,0 + 5/3,2)
  {
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 7;
    ADVANCE(byteIndex, bitIndex, 7);
    numComps += 2;
    break;
  }
  case 119:   // 0111 0111   01 + 110,11 + 1 ...    (2/2,0 + 5/3,2)
  {
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 7;
    ADVANCE(byteIndex, bitIndex, 7);
    numComps += 2;
    break;
  }


  case 120:   // 0111 1000   01 + 1110,00 ...    (2/2,0 + 8/4,4)
  {
    deweyid[numComps] = 1;
    ADVANCE(byteIndex, bitIndex, 6);
    extractValue(byteIndex, bitIndex, 4, 8, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }
  case 121:   // 0111 1001   01 + 1110,01 ...    (2/2,0 + 8/4,4)
  {
    deweyid[numComps] = 1;
    ADVANCE(byteIndex, bitIndex, 6);
    extractValue(byteIndex, bitIndex, 4, 4, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }
  case 122:   // 0111 1010   01 + 1110,10 ...    (2/2,0 + 8/4,4)
  {
    deweyid[numComps] = 1;
    ADVANCE(byteIndex, bitIndex, 6);
    extractValue(byteIndex, bitIndex, 4, 4, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }
  case 123:   // 0111 1011   01 + 1110,11 ...    (2/2,0 + 8/4,4)
  {
    deweyid[numComps] = 1;
    ADVANCE(byteIndex, bitIndex, 6);
    extractValue(byteIndex, bitIndex, 4, 4, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }


  case 124:   // 0111 1100   01 + 11110,0 ...    (2/2,0 + 13/5,8)
  {
    deweyid[numComps] = 1;
    ADVANCE(byteIndex, bitIndex, 7);
    extractValue(byteIndex, bitIndex, 8, 24, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }
  case 125:   // 0111 1101   01 + 11110,1 ...    (2/2,0 + 13/5,8)
  {
    deweyid[numComps] = 1;
    ADVANCE(byteIndex, bitIndex, 7);
    extractValue(byteIndex, bitIndex, 8, 24, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }


  case 126:   // 0111 1110   01 + 111110, ...    (2/2,0 + 18/6,12)
  {
    deweyid[numComps] = 1;
    ADVANCE(byteIndex, bitIndex, 8);
    extractValue(byteIndex, bitIndex, 12, 280, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }


  case 127:   // 0111 1111   01 + 111111 ...    (2/2,0)
  {
    deweyid[numComps] = 1;
    ADVANCE(byteIndex, bitIndex, 2);
    numComps += 1;
    break;
  }


  case 128:   // 1000 0000   10,0 + 00000 ...      (3/2,1)
  {
    deweyid[numComps] = 2;
    ADVANCE(byteIndex, bitIndex, 3);
    numComps += 1;
    break;
  }
  case 129:   // 1000 0001   10,0 + 00001, ...      (3/2,1 + 9/5,4)
  {
    Assert(0);
    break;
  }
  case 130:   // 1000 0010   10,0 + 0001,0 ...      (3/2,1 + 6/4,2)
  {
    Assert(0);
    break;
  }
  case 131:   // 1000 0011   10,0 + 0001,1 ...      (3/2,1 + 6/4,2)
  {
    Assert(0);
    break;
  }
  case 132:   // 1000 0100   10,0 + 001,0 + 0 ...   (3/2,1 + 4/3,1)
  {
    Assert(0);
    break;
  }
  case 133:   // 1000 0101   10,0 + 001,0 + 1 ...   (3/2,1 + 4/3,1)
  {
    Assert(0);
    break;
  }
  case 134:   // 1000 0110   10,0 + 001,1 + 0 ...   (3/2,1 + 4/3,1)
  {
    Assert(0);
    break;
  }
  case 135:   // 1000 0111   10,0 + 001,1 + 1 ...   (3/2,1 + 4/3,1)
  {
    Assert(0);
    break;
  }

  case 136:   // 1000 1000   10,0 + 01 + 000 ...    (3/2,1 + 2/2,0)
  {
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 1;
    ADVANCE(byteIndex, bitIndex, 5);
    numComps += 2;
    break;
  }
  case 137:   // 1000 1001   10,0 + 01 + 001, ...   (3/2,1 + 2/2,0 + 4/3,1)
  {
    Assert(0);
    break;
  }
  case 138:   // 1000 1010   10,0 + 01 + 01 + 0 ... (3/2,1 + 2/2,0 + 2/2,0)
  {
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 1;
    deweyid[numComps + 1] = 1;
    ADVANCE(byteIndex, bitIndex, 7);
    numComps += 3;
    break;
  }
  case 139:   // 1000 1011   10,0 + 01 + 01 + 1 ... (3/2,1 + 2/2,0 + 2/2,0)
  {
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 1;
    deweyid[numComps + 1] = 1;
    ADVANCE(byteIndex, bitIndex, 7);
    numComps += 3;
    break;
  }
  case 140:   // 1000 1100   10,0 + 01 + 10,0 ... (3/2,1 + 2/2,0 + 3/2,1)
  {
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 1;
    deweyid[numComps + 1] = 2;
    ADVANCE(byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 141:   // 1000 1101   10,0 + 01 + 10,1 ... (3/2,1 + 2/2,0 + 3/2,1)
  {
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 1;
    deweyid[numComps + 1] = 3;
    ADVANCE(byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 142:   // 1000 1110   10,0 + 01 + 110 ...    (3/2,1 + 2/2,0 + 5/3,2)
  {
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 1;
    ADVANCE(byteIndex, bitIndex, 5);
    extractValue(byteIndex, bitIndex, 2, 4, deweyid[numComps + 2]);    
    numComps += 3;
    break;
  }
  case 143:   // 1000 1111   10,0 + 01 + 111 ...    (3/2,1 + 2/2,0)
  {
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 1;
    ADVANCE(byteIndex, bitIndex, 5);
    numComps += 2;
    break;
  }

  case 144:   // 1001 0000   10,0 + 10,0 + 00 ...   (3/2,1 + 3/2,1)
  {
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 2;
    ADVANCE(byteIndex, bitIndex, 6);
    numComps += 2;
    break;
  }
  case 145:   // 1001 0001   10,0 + 10,0 + 01 +     (3/2,1 + 3/2,1 + 2/2,0)
  {
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 2;
    deweyid[numComps + 2] = 1;
    ADVANCE(byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 146:   // 1001 0010   10,0 + 10,0 + 10, ...  (3/2,1 + 3/2,1 + 3/2,1)
  {
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 2;
    ADVANCE(byteIndex, bitIndex, 8);
    extractValue(byteIndex, bitIndex, 1, 2, deweyid[numComps + 2]);
    numComps += 3;
    break;
  }
  case 147:   // 1001 0011   10,0 + 10,0 + 11 ...   (3/2,1 + 3/2,1)
  {
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 2;
    ADVANCE(byteIndex, bitIndex, 6);
    numComps += 2;
    break;
  }
  case 148:   // 1001 0100   10,0 + 10,1 + 00 ...   (3/2,1 + 3/2,1)
  {
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 3;
    ADVANCE(byteIndex, bitIndex, 6);
    numComps += 2;
    break;
  }
  case 149:   // 1001 0101   10,0 + 10,1 + 01 +     (3/2,1 + 3/2,1 + 2/2,0)
  {
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 3;
    deweyid[numComps + 2] = 1;
    ADVANCE(byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 150:   // 1001 0110   10,0 + 10,1 + 10, ...  (3/2,1 + 3/2,1 + 3/2,1)
  {
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 3;
    ADVANCE(byteIndex, bitIndex, 8);
    extractValue(byteIndex, bitIndex, 1, 2, deweyid[numComps + 2]);
    numComps += 3;
    break;
  }
  case 151:   // 1001 0111   10,0 + 10,1 + 11 ...   (3/2,1 + 3/2,1)
  {
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 3;
    ADVANCE(byteIndex, bitIndex, 6);
    numComps += 2;
    break;
  }

  case 152:   // 1001 1000   10,0 + 110,00 +        (3/2,1 + 5/3,2)
  {
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 4;
    ADVANCE(byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 153:   // 1001 1001   10,0 + 110,01 +        (3/2,1 + 5/3,2)
  {
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 5;
    ADVANCE(byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 154:   // 1001 1010   10,0 + 110,10 +        (3/2,1 + 5/3,2)
  {
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 6;
    ADVANCE(byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 155:   // 1001 1011   10,0 + 110,11 +        (3/2,1 + 5/3,2)
  {
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 7;
    ADVANCE(byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }

  case 156:   // 1001 1100   10,0 + 1110, 0 ...     (3/2,1 + 8/4,4)
  {
    deweyid[numComps] = 2;
    ADVANCE(byteIndex, bitIndex, 7);
    extractValue(byteIndex, bitIndex, 4, 8, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }
  case 157:   // 1001 1101   10,0 + 1110, 1 ...     (3/2,1 + 8/4,4)
  {
    deweyid[numComps] = 2;
    ADVANCE(byteIndex, bitIndex, 7);
    extractValue(byteIndex, bitIndex, 4, 8, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }

  case 158:   // 1001 1110   10,0 + 11110, ...      (3/2,1 + 13/5,8)
  {
    deweyid[numComps] = 2;
    ADVANCE(byteIndex, bitIndex, 8);
    extractValue(byteIndex, bitIndex, 8, 24, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }

  case 159:   // 1001 1111   10,0 + 11111 ...       (3/2,1)
  {
    deweyid[numComps] = 2;
    ADVANCE(byteIndex, bitIndex, 3);
    numComps += 1;
    break;
  }

  case 160:   // 1010 0000   10,1 + 00000 ...       (3/2,1)
  {
    deweyid[numComps] = 3;
    ADVANCE(byteIndex, bitIndex, 3);
    numComps += 1;
    break;
  }

  case 161:   // 1010 0001   10,1 + 00001, ...      (3/2,1 + )
  {
    Assert(0);
    break;
  }
  case 162:   // 1010 0010   10,1 + 0001,0 ...      (3/2,1 + )
  {
    Assert(0);
    break;
  }
  case 163:   // 1010 0011   10,1 + 0001,1 ...      (3/2,1 + )
  {
    Assert(0);
    break;
  }
  case 164:   // 1010 0100   10,1 + 001,00 ...      (3/2,1 + )
  {
    Assert(0);
    break;
  }
  case 165:   // 1010 0101   10,1 + 001,01 ...      (3/2,1 + )
  {
    Assert(0);
    break;
  }
  case 166:   // 1010 0110   10,1 + 001,10 ...      (3/2,1 + )
  {
    Assert(0);
    break;
  }
  case 167:   // 1010 0111   10,1 + 001,11 ...      (3/2,1 + )
  {
    Assert(0);
    break;
  }

  case 168:   // 1010 1000   10,1 + 01 + 000 ...    (3/2,1 + 2/2,0)
  {
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 1;
    ADVANCE(byteIndex, bitIndex, 5);
    numComps += 2;
    break;
  }
  case 169:   // 1010 1001   10,1 + 01 + 001, ...   (3/2,1 + 2/2,0)
  {
    Assert(0);
    break;
  }
  case 170:   // 1010 1010   10,1 + 01 + 01 + 0 ... (3/2,1 + 2/2,0 + 2/2,0)
  {
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 1;
    deweyid[numComps + 2] = 1;
    ADVANCE(byteIndex, bitIndex, 7);
    numComps += 3;
    break;
  }
  case 171:   // 1010 1011   10,1 + 01 + 01 + 1 ... (3/2,1 + 2/2,0 + 2/2,0)
  {
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 1;
    deweyid[numComps + 2] = 1;
    ADVANCE(byteIndex, bitIndex, 7);
    numComps += 3;
    break;
  }
  case 172:   // 1010 1100   10,1 + 01 + 10,0 +     (3/2,1 + 2/2,0 + 3/2,1)
  {
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 1;
    deweyid[numComps + 2] = 2;
    ADVANCE(byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 173:   // 1010 1101   10,1 + 01 + 10,1 +     (3/2,1 + 2/2,0 + 3/2,1)
  {
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 1;
    deweyid[numComps + 2] = 3;
    ADVANCE(byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 174:   // 1010 1110   10,1 + 01 + 110, ...   (3/2,1 + 2/2,0 + 5/3,2)
  {
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 1;
    ADVANCE(byteIndex, bitIndex, 8);
    extractValue(byteIndex, bitIndex, 2, 4, deweyid[numComps + 2]);
    numComps += 3;
    break;
  }
  case 175:   // 1010 1111   10,1 + 01 + 111 ...    (3/2,1 + 2/2,0)
  {
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 1;
    ADVANCE(byteIndex, bitIndex, 5);
    numComps += 2;
    break;
  }
  case 176:   // 1011 0000   10,1 + 10,0 + 00 ...   (3/2,1 + 3/2,1)
  {
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 2;
    ADVANCE(byteIndex, bitIndex, 5);
    numComps += 2;
    break;
  }
  case 177:   // 1011 0001   10,1 + 10,0 + 01 +     (3/2,1 + 3/2,1 + 2/2,0)
  {
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 2;
    deweyid[numComps + 2] = 1;
    ADVANCE(byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 178:   // 1011 0010   10,1 + 10,0 + 10, ...  (3/2,1 + 3/2,1 + 3/2,1)
  {
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 2;
    ADVANCE(byteIndex, bitIndex, 8);
    extractValue(byteIndex, bitIndex, 1, 2, deweyid[numComps + 2]);
    numComps += 3;
    break;
  }
  case 179:   // 1011 0011   10,1 + 10,0 + 11 ...   (3/2,1 + 3/2,1)
  {
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 2;
    ADVANCE(byteIndex, bitIndex, 6);
    numComps += 2;
    break;
  }
  case 180:   // 1011 0100   10,1 + 10,1 + 00 ...   (3/2,1 + 3/2,1)
  {
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 3;
    ADVANCE(byteIndex, bitIndex, 6);
    numComps += 2;
    break;
  }
  case 181:   // 1011 0101   10,1 + 10,1 + 01 +     (3/2,1 + 3/2,1 + 2/2,0)
  {
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 3;
    deweyid[numComps + 1] = 1;
    ADVANCE(byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 182:   // 1011 0110   10,1 + 10,1 + 10, ...  (3/2,1 + 3/2,1 + 3/2,1)
  {
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 3;
    ADVANCE(byteIndex, bitIndex, 8);
    extractValue(byteIndex, bitIndex, 1, 2, deweyid[numComps + 2]);
    numComps += 3;
    break;
  }
  case 183:   // 1011 0111   10,1 + 10,1 + 11 ...   (3/2,1 + 3/2,1)
  {
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 3;
    ADVANCE(byteIndex, bitIndex, 6);
    numComps += 2;
    break;
  }

  case 184:   // 1011 1000   10,1 + 110,00 +        (3/2,1 + 5/3,2)
  {
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 4;
    ADVANCE(byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 185:   // 1011 1001   10,1 + 110,01 +        (3/2,1 + 5/3,2)
  {
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 5;
    ADVANCE(byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 186:   // 1011 1010   10,1 + 110,10 +        (3/2,1 + 5/3,2)
  {
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 6;
    ADVANCE(byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 187:   // 1011 1011   10,1 + 110,11 +        (3/2,1 + 5/3,2)
  {
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 7;
    ADVANCE(byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }

  case 188:   // 1011 1100   10,1 + 1110,0 ...      (3/2,1 + 8/4,4)
  {
    deweyid[numComps] = 3;
    ADVANCE(byteIndex, bitIndex, 7);
    extractValue(byteIndex, bitIndex, 4, 8, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }
  case 189:   // 1011 1101   10,1 + 1110,1 ...      (3/2,1 + 8/4,4)
  {
    deweyid[numComps] = 3;
    ADVANCE(byteIndex, bitIndex, 7);
    extractValue(byteIndex, bitIndex, 4, 8, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }

  case 190:   // 1011 1110   10,1 + 11110, ...      (3/2,1 + 13/5,8)
  {
    deweyid[numComps] = 3;
    ADVANCE(byteIndex, bitIndex, 8);
    extractValue(byteIndex, bitIndex, 8, 24, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }

  case 191:   // 1011 1111   10,1 + 11111 ...       (3/2,1)
  {
    deweyid[numComps] = 3;
    ADVANCE(byteIndex, bitIndex, 3);
    numComps += 1;
    break;
  }


  case 192:   // 1100 0000   110,00 + 000 ...       (5/3,2)
  {
    deweyid[numComps] = 4;
    ADVANCE(byteIndex, bitIndex, 5);
    numComps += 1;
    break;
  }
  case 193:   // 1100 0001   110,00 + 001 ...       (5/3,2 + )
  {
    Assert(0);
    break;
  }
  case 194:   // 1100 0010   110,00 + 01 + 0 ...    (5/3,2 + 2/2,0)
  {
    deweyid[numComps] = 4;
    deweyid[numComps + 1] = 1;
    ADVANCE(byteIndex, bitIndex, 7);
    numComps += 2;
    break;
  }
  case 195:   // 1100 0011   110,00 + 01 + 1 ...    (5/3,2 + 2/2,0)
  {
    deweyid[numComps] = 4;
    deweyid[numComps + 1] = 1;
    ADVANCE(byteIndex, bitIndex, 7);
    numComps += 2;
    break;
  }

  case 196:   // 1100 0100   110,00 + 10,0 +        (5/3,2 + 3/2,1)
  {
    deweyid[numComps] = 4;
    deweyid[numComps + 1] = 2;
    ADVANCE(byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 197:   // 1100 0101   110,00 + 10,1 +        (5/3,2 + 3/2,1)
  {
    deweyid[numComps] = 4;
    deweyid[numComps + 1] = 3;
    ADVANCE(byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 198:   // 1100 0110   110,00 + 110, ...      (5/3,2 + 5/3,2)
  {
    deweyid[numComps] = 4;
    ADVANCE(byteIndex, bitIndex, 8);
    extractValue(byteIndex, bitIndex, 2, 4, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }
  case 199:   // 1100 0111   110,00 + 111 ...       (5/3,2)
  {
    deweyid[numComps] = 4;
    ADVANCE(byteIndex, bitIndex, 5);
    numComps += 1;
    break;
  }

  case 200:   // 1100 1000   110,01 + 000 ...       (5/3,2)
  {
    deweyid[numComps] = 5;
    ADVANCE(byteIndex, bitIndex, 5);
    numComps += 1;
    break;
  }
  case 201:   // 1100 1001   110,01 + 001 ...       (5/3,2 + )
  {
    Assert(0);
    break;
  }
  case 202:   // 1100 1010   110,01 + 01 + 0 ...    (5/3,2 + 2/2,0)
  {
    deweyid[numComps] = 5;
    deweyid[numComps + 1] = 1;
    ADVANCE(byteIndex, bitIndex, 7);
    numComps += 2;
    break;
  }
  case 203:   // 1100 1011   110,01 + 01 + 1 ...    (5/3,2 + 2/2,0)
  {
    deweyid[numComps] = 5;
    deweyid[numComps + 1] = 1;
    ADVANCE(byteIndex, bitIndex, 7);
    numComps += 2;
    break;
  }
  case 204:   // 1100 1100   110,01 + 10,0 +        (5/3,2 + 3/2,1)
  {
    deweyid[numComps] = 5;
    deweyid[numComps + 1] = 2;
    ADVANCE(byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 205:   // 1100 1101   110,01 + 10,1 +        (5/3,2 + 3/2,1)
  {
    deweyid[numComps] = 5;
    deweyid[numComps + 1] = 3;
    ADVANCE(byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 206:   // 1100 1110   110,01 + 110, ...      (5/3,2 + 5/3,2)
  {
    deweyid[numComps] = 5;
    ADVANCE(byteIndex, bitIndex, 8);
    extractValue(byteIndex, bitIndex, 2, 4, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }
  case 207:   // 1100 1111   110,01 + 111 ...       (5/3,2)
  {
    deweyid[numComps] = 5;
    ADVANCE(byteIndex, bitIndex, 5);
    numComps += 1;
    break;
  }

  case 208:   // 1101 0000   110,10 + 000 ...       (5/3,2)
  {
    deweyid[numComps] = 6;
    ADVANCE(byteIndex, bitIndex, 5);
    numComps += 1;
    break;
  }
  case 209:   // 1101 0001   110,10 + 001, ...      (5/3,2 + )
  {
    Assert(0);
    break;
  }
  case 210:   // 1101 0010   110,10 + 01 + 0 ...    (5/3,2 + 2/2,0)
  {
    deweyid[numComps] = 6;
    deweyid[numComps + 1] = 1;
    ADVANCE(byteIndex, bitIndex, 7);
    numComps += 2;
    break;
  }
  case 211:   // 1101 0011   110,10 + 01 + 1 ...    (5/3,2 + 2/2,0)
  {
    deweyid[numComps] = 6;
    deweyid[numComps + 1] = 1;
    ADVANCE(byteIndex, bitIndex, 7);
    numComps += 2;
    break;
  }
  case 212:   // 1101 0100   110,10 + 10,0 +        (5/3,2 + 3/2,1)
  {
    deweyid[numComps] = 6;
    deweyid[numComps + 1] = 2;
    ADVANCE(byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 213:   // 1101 0101   110,10 + 10,1 +        (5/3,2 + 3/2,1)
  {
    deweyid[numComps] = 6;
    deweyid[numComps + 1] = 3;
    ADVANCE(byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 214:   // 1101 0110   110,10 + 110, ...      (5/3,2 + 5/3,2)
  {
    deweyid[numComps] = 6;
    ADVANCE(byteIndex, bitIndex, 8);
    extractValue(byteIndex, bitIndex, 2, 4, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }
  case 215:   // 1101 0111   110,10 + 111 ...       (5/3,2)
  {
    deweyid[numComps] = 6;
    ADVANCE(byteIndex, bitIndex, 5);
    numComps += 1;
    break;
  }

  case 216:   // 1101 1000   110,11 + 000 ...       (5/3,2)
  {
    deweyid[numComps] = 7;
    ADVANCE(byteIndex, bitIndex, 5);
    numComps += 1;
    break;
  }
  case 217:   // 1101 1001   110,11 + 001 ...       (5/3,2)
  {
    Assert(0);
    break;
  }
  case 218:   // 1101 1010   110,11 + 01 + 0 ...    (5/3,2 + 2/2,0)
  {
    deweyid[numComps] = 7;
    deweyid[numComps + 1] = 1;
    ADVANCE(byteIndex, bitIndex, 7);
    numComps += 2;
    break;
  }
  case 219:   // 1101 1011   110,11 + 01 + 1 ...    (5/3,2 + 2/2,0)
  {
    deweyid[numComps] = 7;
    deweyid[numComps + 1] = 1;
    ADVANCE(byteIndex, bitIndex, 7);
    numComps += 2;
    break;
  }
  case 220:   // 1101 1100   110,11 + 10,0 +        (5/3,2 + 3/2,1)
  {
    deweyid[numComps] = 7;
    deweyid[numComps + 1] = 2;
    ADVANCE(byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 221:   // 1101 1101   110,11 + 10,1 +        (5/3,2 + 3/2,1)
  {
    deweyid[numComps] = 7;
    deweyid[numComps + 1] = 3;
    ADVANCE(byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 222:   // 1101 1110   110,11 + 110, ...      (5/3,2 + 5/3,2)
  {
    deweyid[numComps] = 7;
    ADVANCE(byteIndex, bitIndex, 8);
    extractValue(byteIndex, bitIndex, 2, 4, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }
  case 223:   // 1101 1111   110,11 + 111 ...       (5/3,2)
  {
    deweyid[numComps] = 7;
    ADVANCE(byteIndex, bitIndex, 5);
    numComps += 1;
    break;
  }
  case 224:   // 1110 0000   1110,0000 +            (8/4,4)
  {
    deweyid[numComps] = 8;
    ADVANCE(byteIndex, bitIndex, 8);
    numComps += 1;
    break;
  }
  case 225:   // 1110 0001   1110,0001 +            (8/4,4)
  {
    deweyid[numComps] = 9;
    ADVANCE(byteIndex, bitIndex, 8);
    numComps += 1;
    break;
  }
  case 226:   // 1110 0010   1110,0010 +            (8/4,4)
  {
    deweyid[numComps] = 10;
    ADVANCE(byteIndex, bitIndex, 8);
    numComps += 1;
    break;
  }
  case 227:   // 1110 0011   1110,0011 +            (8/4,4)
  {
    deweyid[numComps] = 11;
    ADVANCE(byteIndex, bitIndex, 8);
    numComps += 1;
    break;
  }
  case 228:   // 1110 0100   1110,0100 +            (8/4,4)
  {
    deweyid[numComps] = 12;
    ADVANCE(byteIndex, bitIndex, 8);
    numComps += 1;
    break;
  }
  case 229:   // 1110 0101   1110,0101 +            (8/4,4)
  {
    deweyid[numComps] = 13;
    ADVANCE(byteIndex, bitIndex, 8);
    numComps += 1;
    break;
  }
  case 230:   // 1110 0110   1110,0110 +            (8/4,4)
  {
    deweyid[numComps] = 14;
    ADVANCE(byteIndex, bitIndex, 8);
    numComps += 1;
    break;
  }
  case 231:   // 1110 0111   1110,0111 +            (8/4,4)
  {
    deweyid[numComps] = 15;
    ADVANCE(byteIndex, bitIndex, 8);
    numComps += 1;
    break;
  }
  case 232:   // 1110 1000   1110,1000 +            (8/4,4)
  {
    deweyid[numComps] = 16;
    ADVANCE(byteIndex, bitIndex, 8);
    numComps += 1;
    break;
  }
  case 233:   // 1110 1001   1110,1001 +            (8/4,4)
  {
    deweyid[numComps] = 17;
    ADVANCE(byteIndex, bitIndex, 8);
    numComps += 1;
    break;
  }
  case 234:   // 1110 1010   1110,1010 +            (8/4,4)
  {
    deweyid[numComps] = 18;
    ADVANCE(byteIndex, bitIndex, 8);
    numComps += 1;
    break;
  }
  case 235:   // 1110 1011   1110,1011 +            (8/4,4)
  {
    deweyid[numComps] = 19;
    ADVANCE(byteIndex, bitIndex, 8);
    numComps += 1;
    break;
  }
  case 236:   // 1110 1100   1110,1100 +            (8/4,4)
  {
    deweyid[numComps] = 20;
    ADVANCE(byteIndex, bitIndex, 8);
    numComps += 1;
    break;
  }
  case 237:   // 1110 1101   1110,1101 +            (8/4,4)
  {
    deweyid[numComps] = 21;
    ADVANCE(byteIndex, bitIndex, 8);
    numComps += 1;
    break;
  }
  case 238:   // 1110 1110   1110,1110 +            (8/4,4)
  {
    deweyid[numComps] = 22;
    ADVANCE(byteIndex, bitIndex, 8);
    numComps += 1;
    break;
  }
  case 239:   // 1110 1111   1110,1111 +            (8/4,4)
  {
    deweyid[numComps] = 23;
    ADVANCE(byteIndex, bitIndex, 8);
    numComps += 1;
    break;
  }
  case 240:   // 1111 0000   11110,000...           (13/5,8)
  {
    ADVANCE(byteIndex, bitIndex, 5);
    extractValue(byteIndex, bitIndex, 8, 24, deweyid[numComps + 1]);
    numComps += 1;
    break;
  }
  case 241:   // 1111 0001   11110,001...           (13/5,8)
  {
    ADVANCE(byteIndex, bitIndex, 5);
    extractValue(byteIndex, bitIndex, 8, 24, deweyid[numComps + 1]);
    numComps += 1;
    break;
  }
  case 242:   // 1111 0010   11110,010...           (13/5,8)
  {
    ADVANCE(byteIndex, bitIndex, 5);
    extractValue(byteIndex, bitIndex, 8, 24, deweyid[numComps + 1]);
    numComps += 1;
    break;
  }
  case 243:   // 1111 0011   11110,011...           (13/5,8)
  {
    ADVANCE(byteIndex, bitIndex, 5);
    extractValue(byteIndex, bitIndex, 8, 24, deweyid[numComps + 1]);
    numComps += 1;
    break;
  }
  case 244:   // 1111 0100   11110,100...           (13/5,8)
  {
    ADVANCE(byteIndex, bitIndex, 5);
    extractValue(byteIndex, bitIndex, 8, 24, deweyid[numComps + 1]);
    numComps += 1;
    break;
  }
  case 245:   // 1111 0101   11110,101...           (13/5,8)
  {
    ADVANCE(byteIndex, bitIndex, 5);
    extractValue(byteIndex, bitIndex, 8, 24, deweyid[numComps + 1]);
    numComps += 1;
    break;
  }
  case 246:   // 1111 0110   11110,110...           (13/5,8)
  {
    ADVANCE(byteIndex, bitIndex, 5);
    extractValue(byteIndex, bitIndex, 8, 24, deweyid[numComps + 1]);
    numComps += 1;
    break;
  }
  case 247:   // 1111 0111   11110,111...           (13/5,8)
  {
    ADVANCE(byteIndex, bitIndex, 5);
    extractValue(byteIndex, bitIndex, 8, 24, deweyid[numComps + 1]);
    numComps += 1;
    break;
  }
  case 248:   // 1111 1000   111110,00...           (18/6,12)
  {
    ADVANCE(byteIndex, bitIndex, 6);
    extractValue(byteIndex, bitIndex, 8, 280, deweyid[numComps + 1]);
    numComps += 1;
    break;
  }
  case 249:   // 1111 1001   111110,01...           (18/6,12)
  {
    ADVANCE(byteIndex, bitIndex, 6);
    extractValue(byteIndex, bitIndex, 8, 280, deweyid[numComps + 1]);
    numComps += 1;
    break;
  }
  case 250:   // 1111 1010   111110,10...           (18/6,12)
  {
    ADVANCE(byteIndex, bitIndex, 6);
    extractValue(byteIndex, bitIndex, 8, 280, deweyid[numComps + 1]);
    numComps += 1;
    break;
  }
  case 251:   // 1111 1011   111110,11...           (18/6,12)
  {
    ADVANCE(byteIndex, bitIndex, 6);
    extractValue(byteIndex, bitIndex, 8, 280, deweyid[numComps + 1]);
    numComps += 1;
    break;
  }
  case 252:   // 1111 1100   1111110,0...           (23/7,16)
  {
    ADVANCE(byteIndex, bitIndex, 7);
    extractValue(byteIndex, bitIndex, 8, 280, deweyid[numComps + 1]);
    numComps += 1;
    break;
  }
  case 253:   // 1111 1101   1111110,1...           (23/7,16)
  {
    ADVANCE(byteIndex, bitIndex, 7);
    extractValue(byteIndex, bitIndex, 8, 280, deweyid[numComps + 1]);
    numComps += 1;
    break;
  }
  case 254:   // 1111 1110   11111110,...           (28/8,20)
  {
    ADVANCE(byteIndex, bitIndex, 8);
    extractValue(byteIndex, bitIndex, 8, 280, deweyid[numComps + 1]);
    numComps += 1;
    break;
  }
  case 255:   // 1111 1111   11111111,...           (28/8,20)
  {
    ZORBA_ERROR_ALERT(error_messages::XQP0014_SYSTEM_SHOUD_NEVER_BE_REACHED,
                      error_messages::SYSTEM_ERROR,
                      NULL,
                      false);
  }
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
    unsigned long& byteIndex,
    unsigned long& bitIndex,
    unsigned long  numBits,
    unsigned long  baseValue,
    unsigned long& result) const
{
  if (numBits < 8 - bitIndex)
  {
    unsigned char byte = theBuffer[byteIndex];
    byte << bitIndex;
    byte >> (8 - numBits);
    result = byte;
    return;
  }

  unsigned char byte = theBuffer[byteIndex]  & theByteMasks[bitIndex][0];
  result = byte;
  numBits -= (8 - bitIndex);
  byteIndex++;

  unsigned long numBytes = numBits / 8;

  for (ulong i = 0; i < numBytes; i++)
  {
    result << 8;
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
    result += baseValue;
  }
}


/*******************************************************************************

********************************************************************************/
xqp_string OrdPath::show() const
{
  std::stringstream str;

  str << "";

  if (theBuffer == NULL)
    return str.str().c_str();

  unsigned long len = getByteLength();

  for (unsigned long i = 1; i < len; i++)
  {
    str << std::hex << (unsigned short)theBuffer[i];
  }

  str << " ";

  len = 256;
  unsigned long deweyid[256];

  decompress(deweyid, len);

  for (unsigned long i = 0; i < len; i++)
  {
    str << deweyid[i];
    if (i < len-1)
      str << ".";
  }

  return str.str().c_str();
}
}
