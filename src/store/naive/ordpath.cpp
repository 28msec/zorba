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
#include <cassert>
#include "errors/error_manager.h"
#include "util/Assert.h"
#include "util/hashfun.h"

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
  Set the value of "this" to 1 (i.e. the id of a root node).
********************************************************************************/
void OrdPath::setAsRoot()
{
  reset();

  theBuffer[0] = 0x40;
}


/*******************************************************************************

********************************************************************************/
OrdPath& OrdPath::operator=(const OrdPath& other)
{
  if (other.isLocal())
  {
    reset();
    memcpy(getLocalData(), other.getLocalData(), MAX_EMBEDDED_BYTE_LEN);
  }
  else
  {
    ulong len = other.getRemoteByteLength();

    ZORBA_ASSERT(len >= MAX_EMBEDDED_BYTE_LEN);

    initRemote(len);
    memcpy(getRemoteData(), other.getRemoteData(), len);

    ZORBA_ASSERT(!isLocal());
  }

  return *this;
}


/*******************************************************************************

********************************************************************************/
OrdPath& OrdPath::operator=(const OrdPathStack& ops)
{
  ulong len = ops.getByteLength();

  if (len > MAX_EMBEDDED_BYTE_LEN || 
      (len == MAX_EMBEDDED_BYTE_LEN && ops.theBitsAvailable == 0))
  {
    initRemote(len);
    memcpy(getRemoteData(), ops.theBuffer, len);

    ZORBA_ASSERT(!isLocal());
    //std::cout << "REMOTE ORDPATH !!! " << show() << std::endl;
  }
  else
  {
    reset();

    for (ulong i = 0; i < len; i++)
      theBuffer[i] = ops.theBuffer[i];

    markLocal();
  }
  return *this;
}


/*******************************************************************************

********************************************************************************/
ulong OrdPath::getLocalBitLength() const
{
  ulong byteLen = getLocalByteLength();

  if (byteLen == 0)
    return 0;

  ulong bitLen = byteLen * 8;

  unsigned char lastByte = getLocalData()[byteLen - 1];
  if (byteLen == MAX_EMBEDDED_BYTE_LEN)
    lastByte &= 0xFE;

  while ((lastByte & 0x1) == 0)
  {
    lastByte >>= 1;
    bitLen--;
  }

  return bitLen;
}


ulong OrdPath::getRemoteBitLength() const
{
  ulong byteLen = getRemoteByteLength();

  if (byteLen == 0)
    return 0;

  ulong bitLen = byteLen * 8;

  unsigned char lastByte = getRemoteData()[byteLen - 1];

  while ((lastByte & 0x1) == 0)
  {
    lastByte >>= 1;
    bitLen--;
  }

  return bitLen;
}


/*******************************************************************************

********************************************************************************/
uint32_t OrdPath::hash() const
{
  return (isLocal() ? 
          hashfun::h32(getLocalData(), getLocalByteLength(), FNV_32_INIT) :
          hashfun::h32(getRemoteData(), getRemoteByteLength(), FNV_32_INIT));
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
  ulong len1;
  ulong len2;
  unsigned char* p1 = getDataAndLength(len1);
  unsigned char* p2 = other.getDataAndLength(len2);

  if (len1 < len2)
  {
    unsigned char* end = p1 + len1;

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
    unsigned char* end = p2 + len2;

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
  ulong len1;
  ulong len2;
  unsigned char* p1 = getDataAndLength(len1);
  unsigned char* p2 = other.getDataAndLength(len2);

  if (len1 <= len2)
  {
    unsigned char* end = p1 + len1;

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
    unsigned char* end = p2 + len2;

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
  Compress a dewey id into an ordpath.
  NOTE: This method is used for debugging only!
********************************************************************************/
void OrdPath::compress(const std::vector<long>& dewey)
{
  if (! compressLocal(dewey))
    compressRemote(dewey);
}


bool OrdPath::compressLocal(const std::vector<long>& dewey)
{
  reset();

  ulong bitLen = 0;

  ulong numComps = dewey.size();
  for (ulong i = 0; i < numComps; i++)
  {
    if (! pushComp(getLocalData(), MAX_EMBEDDED_BIT_LEN, dewey[i], bitLen))
      return false;
  }

  ZORBA_ASSERT(isLocal());

  return true;
}


void OrdPath::compressRemote(const std::vector<long>& dewey)
{
  reset();

  ulong bitLen = 0;

  unsigned char* databuf = new unsigned char[MAX_BYTE_LEN];

  try
  {
    memset(databuf, 0, MAX_BYTE_LEN);

    ulong numComps = dewey.size();
    for (ulong i = 0; i < numComps; i++)
    {
      bool success = pushComp(databuf, MAX_BIT_LEN, dewey[i], bitLen);
      ZORBA_ASSERT(success);
    }

    ulong byteLen = (bitLen + 7) / 8;

    initRemote(byteLen);
    memcpy(getRemoteData(), databuf, byteLen);
  }
  catch (...)
  {
    delete [] databuf;
    throw;
  }

  delete [] databuf;
}


/*******************************************************************************
  Note: This is a static method.
********************************************************************************/
void OrdPath::insertAfter(
    const OrdPath& parent,
    const OrdPath& sibling,
    OrdPath&       result)
{
  insertBeforeOrAfter(false, parent, sibling, result);
}


void OrdPath::insertBefore(
    const OrdPath& parent,
    const OrdPath& sibling,
    OrdPath&       result)
{
  insertBeforeOrAfter(true, parent, sibling, result);
}


void OrdPath::insertBeforeOrAfter(
    bool           before,
    const OrdPath& parent,
    const OrdPath& sibling,
    OrdPath&       result)
{
  ulong numComps = 0;
  long dewey[MAX_NUM_COMPS];
  ulong offsets[MAX_NUM_COMPS];
  ulong bitLen;
  ulong byteLen;
  unsigned char* data;

  ulong parentBitLen = parent.getBitLength();

  // Decompress the last level-component of sibling.
  sibling.decompress(parentBitLen, dewey, offsets, numComps, bitLen);

  long newcomp = dewey[numComps-1] + (before ? - 2 : 2);

  ulong newBits;
  uint32_t dummy;
  bitsNeeded(newcomp, newBits, dummy);

  ulong commonBitLen = offsets[numComps-1];
  ulong commonByteLen = (commonBitLen + 7) / 8;

  bitLen = commonBitLen + newBits;
  byteLen = (bitLen + 7) / 8;

  bool isLocal = (bitLen <= MAX_EMBEDDED_BIT_LEN);

  if (isLocal)
  {
    result.reset();
    data = result.getLocalData();
  }
  else
  {
    result.initRemote(byteLen);
    data = result.getRemoteData();
  }

  memcpy(data, sibling.getData(), commonByteLen);
  if (commonBitLen % 8 != 0)
    data[commonByteLen-1] &= (0xff << (8 - commonBitLen % 8));

  if (isLocal)
    result.markLocal();

  bool success = result.pushComp(data, bitLen, newcomp, commonBitLen);
  ZORBA_ASSERT(success);
  ZORBA_ASSERT((isLocal && result.isLocal()) || (!isLocal && !result.isLocal()));
}


/*******************************************************************************
  Create an ordpath that is at the same level and in between the two given
  ordpaths (sib1 and sib2). For efficiency, the parent ordpath of sib1 and sib2
  is also given.
  
  Note: This is a static method.
********************************************************************************/
void OrdPath::insertInto(
    const OrdPath& parent,
    const OrdPath& sib1,
    const OrdPath& sib2,
    OrdPath&       result)
{
  assert(sib1 < sib2);

  ulong parentBitLen = parent.getBitLength();

  ulong numComps1 = 0;
  ulong bitLen1 = 0;
  long dewey1[MAX_NUM_COMPS];
  ulong offsets1[MAX_NUM_COMPS];

  ulong numComps2 = 0;
  ulong bitLen2 = 0;
  long dewey2[MAX_BYTE_LEN];
  ulong offsets2[MAX_BYTE_LEN];

  // decompress the last level-comp of sib1
  sib1.decompress(parentBitLen, dewey1, offsets1, numComps1, bitLen1);

  // decompress the last level-component of sib2.
  sib2.decompress(parentBitLen, dewey2, offsets2, numComps2, bitLen2);

  // Within the last level-component, find the 1st pair of differing comps.
  ulong compPos = 0;
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
  ulong commonBitLen;
  ulong newBits;
  uint32_t dummy;

  bool copy1 = true;

  // If there is an odd number between comp1 and comp2, use it
  if (diff > 2 || (!odd1 && diff == 2))
  {
    commonBitLen = offsets1[compPos];

    newcomp1 = comp1 + diff / 2;
    if (newcomp1 % 2 == 0)
      newcomp1++;

    bitsNeeded(newcomp1, newBits, dummy);
  }
  // Else if comp1 and comp2 are 2 consecutive odd numbers...
  else if (odd1 && odd2)
  {
    commonBitLen = offsets1[compPos];

    newcomp1 = comp1 + 1;
    newcomp2 = 1;

    bitsNeeded(newcomp1, newBits, dummy);
    newBits += 2;
  }
  // Else if comp1 is odd and comp2 == comp1 + 1, keep comp2 and add
  // dewey2[compPos+1] - (1 or 2)
  else if (odd1)
  {
    commonBitLen = offsets2[compPos+1];

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
    commonBitLen = offsets1[compPos+1];

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

  ulong commonByteLen = (commonBitLen + 7) / 8;
  ulong bitLen = commonBitLen + newBits;
  ulong byteLen = (bitLen + 7) / 8;
  unsigned char* data;

  bool isLocal = (bitLen <= MAX_EMBEDDED_BIT_LEN);

  if (isLocal)
  {
    result.reset();
    data = result.getLocalData();
  }
  else
  {
    result.initRemote(byteLen);
    data = result.getRemoteData();
  }

  memcpy(data, (copy1 ? sib1.getData() : sib2.getData()), commonByteLen);
  if (commonBitLen % 8 != 0)
    data[commonByteLen-1] &= (0xff << (8 - commonBitLen % 8));

  if (isLocal)
    result.markLocal();

  bool success = result.pushComp(data, bitLen, newcomp1, commonBitLen);
  ZORBA_ASSERT(success);
  if (newcomp2 != 0)
  {
    success = result.pushComp(data, bitLen, newcomp2, commonBitLen);
    ZORBA_ASSERT(success);
  }

  ZORBA_ASSERT((isLocal && result.isLocal()) || (!isLocal && !result.isLocal()));
}


/*******************************************************************************
  Append a given component value to a given buffer. The total size of the buffer
  is given in terms of bits (maxBitLen). The number of bits that are already
  occupied within the buffer is also given (bitLen). If the buffer has enough
  free bits remaining to store the new comp, the method returns true, as well as
  the new number of occupied bits (bitLen). Otherwise, the method returns
  false (without updating the buffer any).

  Note: This is a static method.
********************************************************************************/
bool OrdPath::pushComp(
    unsigned char* data,
    ulong maxBitLen,
    long value,
    ulong& bitLen)
{
  assert(maxBitLen >= bitLen);

  uint32_t eval;
  ulong bitsNeeded;

  ulong byteIndex = bitLen / 8;

  ulong bitsAvailable = 8 - bitLen % 8;
  if (bitsAvailable == 0)
    bitsAvailable = 8;

  OrdPath::bitsNeeded(value, bitsNeeded, eval);

  ulong bytesNeeded = byteIndex + (bitsNeeded + 15 - bitsAvailable) / 8;
  if (bytesNeeded > OrdPath::MAX_BYTE_LEN)
  {
    ZORBA_ERROR_PARAM_OSS(ZorbaError::XQP0018_NODEID_ERROR,
                          "A nodeid requires more than " << OrdPath::MAX_BYTE_LEN
                          << " bytes", "");
  }

  if (bitLen + bitsNeeded > maxBitLen)
    return false;

  bitLen += bitsNeeded;

  do
  {
    ulong bitsUsed = (bitsNeeded < bitsAvailable ?
                      bitsNeeded : bitsAvailable);

    unsigned char byte = (unsigned char)
                         ((eval & OrdPath::theValueMasks[bitsUsed]) >>
                          (32 - bitsAvailable));

    data[byteIndex] |= byte;
    eval = eval << bitsUsed;
    bitsNeeded -= bitsUsed;
    bitsAvailable -= bitsUsed;
    ulong zerone = (bitsAvailable + 7) / 8;
    bitsAvailable = bitsAvailable * zerone + 8 * (1 - zerone);
    byteIndex += (1 - zerone);
  }
  while (bitsNeeded > 0);

  return true;
}


/*******************************************************************************
  Append a given component value to "this", expanding, if necessary, theBuffer
  of "this" to accomodate the new comp.
********************************************************************************/
void OrdPath::appendComp(long value)
{
  uint32_t eval;

  ulong bitLen;
  ulong byteIndex;
  ulong bitsAvailable = 0;
  ulong bitsNeeded;
  unsigned char* data;

  bool isLocal = this->isLocal();

  bitLen = (isLocal ? getLocalBitLength() : getRemoteBitLength());

  byteIndex = bitLen / 8;
  bitsAvailable = 8 - bitLen % 8;

  OrdPath::bitsNeeded(value, bitsNeeded, eval);

  ulong bytesNeeded = byteIndex + (bitsNeeded + 15 - bitsAvailable) / 8;
  if (bytesNeeded > OrdPath::MAX_BYTE_LEN)
  {
    ZORBA_ERROR_PARAM_OSS(ZorbaError::XQP0018_NODEID_ERROR,
                          "A nodeid requires more than " << OrdPath::MAX_BYTE_LEN
                           << " bytes", "");
  }

  if (bitLen + bitsNeeded <= MAX_EMBEDDED_BIT_LEN)
  {
    data = getLocalData();
  }
  else if (isLocal || (bytesNeeded > byteIndex + 1))
  {
    unsigned char* newbuf = new unsigned char[bytesNeeded + 1];
    memset(newbuf, 0, bytesNeeded+1);
    newbuf[0] = bytesNeeded;

    if (isLocal)
    {
      markRemote();
      memcpy(&newbuf[1], getLocalData(), byteIndex+1);
      setRemoteBuffer(newbuf);
    }
    else
    {
      memcpy(&newbuf[1], getRemoteData(), byteIndex+1);
      delete [] getRemoteBuffer();
      setRemoteBuffer(newbuf);
    }

    ZORBA_ASSERT(!this->isLocal());

    data = getRemoteData();
  }
  else
  {
    data = getRemoteData();
  }

  do
  {
    ulong bitsUsed = (bitsNeeded < bitsAvailable ?
                      bitsNeeded : bitsAvailable);

    unsigned char byte = (unsigned char)
                         ((eval & OrdPath::theValueMasks[bitsUsed]) >>
                          (32 - bitsAvailable));

    data[byteIndex] |= byte;
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
  Static method
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
      ZORBA_ERROR_DESC(ZorbaError::XQP0018_NODEID_ERROR, 
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
      ZORBA_ERROR_DESC( ZorbaError::XQP0018_NODEID_ERROR,
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

  ulong len;
  unsigned char* buf = getDataAndLength(len);

  if (len == 0)
    return str.str().c_str();

  for (ulong i = 0; i < len; i++)
  {
    str << std::hex << (unsigned short)buf[i] << '|';
  }

  str << " ";

  ulong numComps = 0;
  ulong bitSize = 0;
  long deweyid[MAX_NUM_COMPS];
  ulong offsets[MAX_NUM_COMPS];

  decompress(0, deweyid, offsets, numComps, bitSize);

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
    ulong& bitLen) const
{
  ulong byteIndex = startOffset / 8;
  ulong bitIndex = startOffset % 8;

  ulong len;
  unsigned char* data = getDataAndLength(len);

  bitLen = byteIndex * 8 + bitIndex;

  while (byteIndex < len - 1)
  {
    unsigned char byte0 = data[byteIndex] & theByteMasks[bitIndex][0];
    unsigned char byte1 = data[byteIndex+1] & theByteMasks[bitIndex][1];
    unsigned char byte = (byte0 << bitIndex) | (byte1 >> (8 - bitIndex));

    decodeByte(data, bitLen, byteIndex, bitIndex, byte,
               deweyid, compOffsets, numComps);
  }

  // Treat the last byte
  if (byteIndex == len - 1)
  {
    unsigned char lastByte = data[byteIndex];
    ZORBA_ASSERT(lastByte != 0);
    lastByte <<= bitIndex;
    if (lastByte != 0)
      decodeByte(data, bitLen, byteIndex, bitIndex, lastByte,
                 deweyid, compOffsets, numComps);
  }
}


/*******************************************************************************

********************************************************************************/
#define ADVANCE(bitLen, byteIndex, bitIndex, numBits)  \
{                                                      \
  (bitLen) += (numBits);                               \
  (byteIndex) += ((bitIndex) + (numBits)) / 8;         \
  (bitIndex) = ((bitIndex) + (numBits)) % 8;           \
}


/*******************************************************************************

********************************************************************************/
void OrdPath::decodeByte(
    unsigned char* data,
    ulong&         bitLen,
    ulong&         byteIndex,
    ulong&         bitIndex,
    unsigned char  byte,
    long*          deweyid,
    ulong*         compOffsets,
    ulong&         numComps)
{ 
  compOffsets[numComps] = bitLen;

  switch (byte)
  {
  case 0:    // 0000 0000   00000000 ...            (29/9,20)
  {
    ADVANCE(bitLen, byteIndex, bitIndex, 9);
    extractValue(data, bitLen, byteIndex, bitIndex, 20, -1118484, deweyid[numComps]);
    numComps += 1;    
    break;
  }
  case 1:    // 0000 0001   00000001,...            (24/8,16)
  {
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    extractValue(data, bitLen, byteIndex, bitIndex, 16, -69908, deweyid[numComps]);
    numComps += 1;
    break;
  }
  case 2:    // 0000 0010   0000001,0...            (19/7,12)
  {
    ADVANCE(bitLen, byteIndex, bitIndex, 7);
    extractValue(data, bitLen, byteIndex, bitIndex, 12, -4372, deweyid[numComps]);
    numComps += 1;
    break;
  }
  case 3:    // 0000 0011   0000001,1...            (19/7,12)
  {
    ADVANCE(bitLen, byteIndex, bitIndex, 7);
    extractValue(data, bitLen, byteIndex, bitIndex, 12, -4372, deweyid[numComps]);
    numComps += 1;
    break;
  }
  case 4:    // 0000 0100   000001,00...            (14/6,8)
  {
    ADVANCE(bitLen, byteIndex, bitIndex, 6);
    extractValue(data, bitLen, byteIndex, bitIndex, 8, -276, deweyid[numComps]);
    numComps += 1;
    break;
  }
  case 5:    // 0000 0101   000001,01..             (14/6,8)
  {
    ADVANCE(bitLen, byteIndex, bitIndex, 6);
    extractValue(data, bitLen, byteIndex, bitIndex, 8, -276, deweyid[numComps]);
    numComps += 1;
    break;
  }
  case 6:    // 0000 0110   000001,10...            (14/6,8)
  {
    ADVANCE(bitLen, byteIndex, bitIndex, 6);
    extractValue(data, bitLen, byteIndex, bitIndex, 8, -276, deweyid[numComps]);
    numComps += 1;
    break;
  }
  case 7:    // 0000 0111   000001,11...            (14/6,8)
  {
    ADVANCE(bitLen, byteIndex, bitIndex, 6);
    extractValue(data, bitLen, byteIndex, bitIndex, 8, -276, deweyid[numComps]);
    numComps += 1;
    break;
  }
  case 8:    // 0000 1000   00001,000...            (9/5,4)
  {
    ADVANCE(bitLen, byteIndex, bitIndex, 5);
    extractValue(data, bitLen, byteIndex, bitIndex, 4, -20, deweyid[numComps]);
    numComps += 1;
    break;
  }
  case 9:    // 0000 1001   00001,001...            (9/5,4)
  {
    ADVANCE(bitLen, byteIndex, bitIndex, 5);
    extractValue(data, bitLen, byteIndex, bitIndex, 4, -20, deweyid[numComps]);
    numComps += 1;
    break;
  }
  case 10:   // 0000 1010   00001,010...            (9/5,4)
  {
    ADVANCE(bitLen, byteIndex, bitIndex, 5);
    extractValue(data, bitLen, byteIndex, bitIndex, 4, -20, deweyid[numComps]);
    numComps += 1;
    break;
  }
  case 11:   // 0000 1011   00001,011...            (9/5,4)
  {
    ADVANCE(bitLen, byteIndex, bitIndex, 5);
    extractValue(data, bitLen, byteIndex, bitIndex, 4, -20, deweyid[numComps]);
    numComps += 1;
    break;
  }
  case 12:   // 0000 1100   00001,100...            (9/5,4)
  {
    ADVANCE(bitLen, byteIndex, bitIndex, 5);
    extractValue(data, bitLen, byteIndex, bitIndex, 4, -20, deweyid[numComps]);
    numComps += 1;
    break;
  }
  case 13:   // 0000 1101   00001,101...            (9/5,4)
  {
    ADVANCE(bitLen, byteIndex, bitIndex, 5);
    extractValue(data, bitLen, byteIndex, bitIndex, 4, -20, deweyid[numComps]);
    numComps += 1;
    break;
  }
  case 14:   // 0000 1110   00001,110...            (9/5,4)
  {
    ADVANCE(bitLen, byteIndex, bitIndex, 5);
    extractValue(data, bitLen, byteIndex, bitIndex, 4, -20, deweyid[numComps]);
    numComps += 1;
    break;
  }
  case 15:   // 0000 1111   00001,111...            (9/5,4)
  {
    ADVANCE(bitLen, byteIndex, bitIndex, 5);
    extractValue(data, bitLen, byteIndex, bitIndex, 4, -20, deweyid[numComps]);
    numComps += 1;
    break;
  }


  case 16:   // 0001 0000   0001,00 + 00...       (6/4,2)
  {
    deweyid[numComps] = -4;    
    ADVANCE(bitLen, byteIndex, bitIndex, 6);
    numComps += 1;
    break;
  }
  case 17:   // 0001 0001   0001,00 + 01 +        (6/4,2 + 2/2,0)
  {
    deweyid[numComps] = -4; 
    deweyid[numComps+1] = 1;
    compOffsets[numComps+1] = bitLen + 6;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 18:   // 0001 0010   0001,00 + 10, ...     (6/4,2 + 3/2,1)
  {
    compOffsets[numComps+1] = bitLen + 6;
    deweyid[numComps] = -4; 
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    extractValue(data, bitLen, byteIndex, bitIndex, 1, 2, deweyid[numComps+1]);
    numComps += 2;
    break;
  }
  case 19:   // 0001 0011   0001,00 + 11...       (6/4,2)
  {
    deweyid[numComps] = -4;
    ADVANCE(bitLen, byteIndex, bitIndex, 6);
    numComps += 1;
    break;
  }
  case 20:   // 0001 0100   0001,01 + 00...       (6/4,2)
  {
    deweyid[numComps] = -3; 
    ADVANCE(bitLen, byteIndex, bitIndex, 6);
    numComps += 1;
    break;
  }
  case 21:   // 0001 0101   0001,01 + 01 +        (6/4,2 + 2/2,0)
  {
    compOffsets[numComps+1] = bitLen + 6;
    deweyid[numComps] = -3; 
    deweyid[numComps+1] = 1;    
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 22:   // 0001 0110   0001,01 + 10, ...     (6/4,2 + 3/2,1)
  {
    compOffsets[numComps+1] = bitLen + 6;
    deweyid[numComps] = -3;    
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    extractValue(data, bitLen, byteIndex, bitIndex, 1, 2, deweyid[numComps+1]);
    numComps += 2;
    break;
  }
  case 23:   // 0001 0111   0001,01 + 11...       (6/4,2)
  {
    deweyid[numComps] = -3;    
    ADVANCE(bitLen, byteIndex, bitIndex, 6);
    numComps += 1;
    break;
  }
  case 24:   // 0001 1000   0001,10 + 00...       (6/4,2)
  {
    deweyid[numComps] = -2;    
    ADVANCE(bitLen, byteIndex, bitIndex, 6);
    numComps += 1;
    break;
  }
  case 25:   // 0001 1001   0001,10 + 01 +        (6/4,2 + 2/2,0)
  {
    compOffsets[numComps+1] = bitLen + 6;
    deweyid[numComps] = -2; 
    deweyid[numComps+1] = 1;    
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 26:   // 0001 1010   0001,10 + 10, ...     (6/4,2 + 3/2,1)
  {
    compOffsets[numComps+1] = bitLen + 6;
    deweyid[numComps] = -2;    
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    extractValue(data, bitLen, byteIndex, bitIndex, 1, 2, deweyid[numComps+1]);
    numComps += 2;
    break;
  }
  case 27:   // 0001 1011   0001,10 + 11 ...      (6/4,2)
  {
    deweyid[numComps] = -2;    
    ADVANCE(bitLen, byteIndex, bitIndex, 6);
    numComps += 1;
    break;
  }
  case 28:   // 0001 1100   0001,11 + 00 ...        (6/4,2)
  {
    deweyid[numComps] = -1;    
    ADVANCE(bitLen, byteIndex, bitIndex, 6);
    numComps += 1;
    break;
  }
  case 29:   // 0001 1101   0001,11 + 01 +          (6/4,2 + 2/2,0)
  {
    compOffsets[numComps+1] = bitLen + 6;
    deweyid[numComps] = -1; 
    deweyid[numComps+1] = 1;    
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 30:   // 0001 1110   0001,11 + 10, ...       (6/4,2 + 3/2,1)
  {
    compOffsets[numComps+1] = bitLen + 6;
    deweyid[numComps] = -1;    
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    extractValue(data, bitLen, byteIndex, bitIndex, 1, 2, deweyid[numComps+1]);
    numComps += 2;
    break;
  }
  case 31:   // 0001 1111   0001,11 + 11 ...        (6/4,2)
  {
    deweyid[numComps] = -2;    
    ADVANCE(bitLen, byteIndex, bitIndex, 6);
    numComps += 1;
    break;
  }
  

  case 32:   // 0010 0000   001 + 00000 ...         (3/3,0)
  {
    deweyid[numComps] = 0;    
    ADVANCE(bitLen, byteIndex, bitIndex, 3);
    numComps += 1;
    break;
  }
  case 33:   // 0010 0001   001 + 00001, ...        (3/3,0 + 9/5,4)
  {
    compOffsets[numComps+1] = bitLen + 3;
    deweyid[numComps] = 0;    
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    extractValue(data, bitLen, byteIndex, bitIndex, 4, -20, deweyid[numComps+1]);
    numComps += 2;
    break;
  }
  case 34:   // 0010 0010   001 + 0001,0...         (3/3,0 + 6/4,2)
  {
    compOffsets[numComps+1] = bitLen + 3;
    deweyid[numComps] = 0;    
    ADVANCE(bitLen, byteIndex, bitIndex, 7);
    extractValue(data, bitLen, byteIndex, bitIndex, 2, -4, deweyid[numComps+1]);
    numComps += 2;
    break;
  }
  case 35:   // 0010 0011   001 + 0001,1...         (3/3,0 + 4/3,1)
  {
    compOffsets[numComps+1] = bitLen + 3;
    deweyid[numComps] = 0;
    ADVANCE(bitLen, byteIndex, bitIndex, 7);
    extractValue(data, bitLen, byteIndex, bitIndex, 2, -4, deweyid[numComps+1]);
    numComps += 2;
    break;
  }
  case 36:   // 0010 0100   001+001 + 00...         (3/3,0 + 3/3,0)
  {
    compOffsets[numComps+1] = bitLen + 3;
    deweyid[numComps] = 0;
    deweyid[numComps+1] = 0;
    ADVANCE(bitLen, byteIndex, bitIndex, 6);
    numComps += 2;
    break;
  }
  case 37:   // 0010 0101   001 + 001 + 01...       (3/3,0 + 3/3,0)
  {
    compOffsets[numComps+1] = bitLen + 3;
    deweyid[numComps] = 0;
    deweyid[numComps+1] = 0;
    ADVANCE(bitLen, byteIndex, bitIndex, 6);
    numComps += 2;
    break;
  }
  case 38:   // 0010 0110   001 + 001 + 10...       (3/3,0 + 3/3,0)
  {
    compOffsets[numComps+1] = bitLen + 3;
    deweyid[numComps] = 0;
    deweyid[numComps+1] = 0;
    ADVANCE(bitLen, byteIndex, bitIndex, 6);
    numComps += 2;
    break;
  }
  case 39:   // 0010 0111   001 + 001 + 11 ...     (3/3,0 + 3/3,0)
  {
    compOffsets[numComps+1] = bitLen + 3;
    deweyid[numComps] = 0;
    deweyid[numComps+1] = 0;
    ADVANCE(bitLen, byteIndex, bitIndex, 6);
    numComps += 2;
    break;
  }
  case 40:   // 0010 1000   001 + 01 + 000...       (3/3,0 + 2/2,0)
  {
    compOffsets[numComps+1] = bitLen + 3;
    deweyid[numComps] = 0;
    deweyid[numComps+1] = 1;
    ADVANCE(bitLen, byteIndex, bitIndex, 5);
    numComps += 2;
    break;
  }
  case 41:   // 0010 1001   001 + 01 + 001 +        (3/3,0 + 2/2,0 + 3/3,0)
  {
    compOffsets[numComps+1] = bitLen + 3;
    compOffsets[numComps+2] = bitLen + 5;
    deweyid[numComps] = 0;
    deweyid[numComps+1] = 1;
    deweyid[numComps+2] = 0;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 42:   // 0010 1010   001 + 01 + 01 + 0...    (3/3,0 + 2/2,0 + 2/2,0)
  {
    compOffsets[numComps+1] = bitLen + 3;
    compOffsets[numComps+2] = bitLen + 5;
    deweyid[numComps] = 0;
    deweyid[numComps+1] = 1;
    deweyid[numComps+2] = 1;
    ADVANCE(bitLen, byteIndex, bitIndex, 7);
    numComps += 3;
    break;
  }
  case 43:   // 0010 1011   001 + 01 + 01 + 1 ...   (3/3,0 + 2/2,0 + 2/2,0)
  {
    compOffsets[numComps+1] = bitLen + 3;
    compOffsets[numComps+2] = bitLen + 5;
    deweyid[numComps] = 0;
    deweyid[numComps+1] = 1;
    deweyid[numComps+2] = 1;
    ADVANCE(bitLen, byteIndex, bitIndex, 7);
    numComps += 3;
    break;
  }
  case 44:   // 0010 1100   001 + 01 + 10,0 +       (3/3,0 + 2/2,0, 3/2,1)
  {
    compOffsets[numComps+1] = bitLen + 3;
    compOffsets[numComps+2] = bitLen + 5;
    deweyid[numComps] = 0;
    deweyid[numComps+1] = 1;
    deweyid[numComps+2] = 2;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 45:   // 0010 1101   001 + 01 + 10,1 +       (3/3,0 + 2/2,0, 3/3,1)
  {
    compOffsets[numComps+1] = bitLen + 3;
    compOffsets[numComps+2] = bitLen + 5;
    deweyid[numComps] = 0;
    deweyid[numComps+1] = 1;
    deweyid[numComps+2] = 3;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 46:   // 0010 1110   001 + 01 + 110, ...     (3/3,0 + 2/2,0 + 5/3,2)
  {
    compOffsets[numComps+1] = bitLen + 3;
    compOffsets[numComps+2] = bitLen + 5;
    deweyid[numComps] = 0;
    deweyid[numComps+1] = 1;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    extractValue(data, bitLen, byteIndex, bitIndex, 2, 4, deweyid[numComps + 2]);
    numComps += 3;
    break;
  }
  case 47:   // 0010 1111   001 + 01 + 111 ...      (3/3,0 + 2/2,0)
  {
    compOffsets[numComps+1] = bitLen + 3;
    deweyid[numComps] = 0;
    deweyid[numComps+1] = 1;
    ADVANCE(bitLen, byteIndex, bitIndex, 5);
    numComps += 2;
    break;
  }

  case 48:   // 0011 0000   001 + 10,0 + 00 ...     (3/3,0 + 3/2,1)
  {
    compOffsets[numComps+1] = bitLen + 3;
    deweyid[numComps] = 0;
    deweyid[numComps+1] = 2;
    ADVANCE(bitLen, byteIndex, bitIndex, 6);
    numComps += 2;
    break;
  }
  case 49:   // 0011 0001   001 + 10,0 + 01 +       (3/3,0 + 3/2,1 + 2/2,0)
  {
    compOffsets[numComps+1] = bitLen + 3;
    compOffsets[numComps+2] = bitLen + 6;
    deweyid[numComps] = 0;
    deweyid[numComps+1] = 2;
    deweyid[numComps+2] = 1;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 50:   // 0011 0010   001 + 10,0 + 10, ...    (3/3,0 + 3/2,1 + 3/2,1)
  {
    compOffsets[numComps+1] = bitLen + 3;
    compOffsets[numComps+2] = bitLen + 6;
    deweyid[numComps] = 0;
    deweyid[numComps+1] = 2;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    extractValue(data, bitLen, byteIndex, bitIndex, 1, 2, deweyid[numComps + 2]);
    numComps += 3;
    break;
  }
  case 51:   // 0011 0011   001 + 10,0 + 11...      (3/3,0 + 3/2,1)
  {
    compOffsets[numComps+1] = bitLen + 3;
    deweyid[numComps] = 0;
    deweyid[numComps+1] = 2;
    ADVANCE(bitLen, byteIndex, bitIndex, 6);
    numComps += 2;
    break;
  }
  case 52:   // 0011 0100   001 + 10,1 + 00 ...     (3/3,0 + 3/2,1)
  {
    compOffsets[numComps+1] = bitLen + 3;
    deweyid[numComps] = 0;
    deweyid[numComps+1] = 3;
    ADVANCE(bitLen, byteIndex, bitIndex, 6);
    numComps += 2;
    break;
  }
  case 53:   // 0011 0101   001 + 10,1 + 01 +       (3/3,0 + 3/2,1 + 2/2,0)
  {
    compOffsets[numComps+1] = bitLen + 3;
    compOffsets[numComps+2] = bitLen + 6;
    deweyid[numComps] = 0;
    deweyid[numComps+1] = 3;
    deweyid[numComps+2] = 1;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 54:   // 0011 0110   001 + 10,1 + 10, ...    (3/3,0 + 3/2,1 + 3/2,1)
  {
    compOffsets[numComps+1] = bitLen + 3;
    compOffsets[numComps+2] = bitLen + 6;
    deweyid[numComps] = 0;
    deweyid[numComps+1] = 3;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    extractValue(data, bitLen, byteIndex, bitIndex, 1, 2, deweyid[numComps + 2]);
    numComps += 3;
    break;
  }
  case 55:   // 0011 0111   001 + 10,1 + 11 ...     (3/3,0 + 3/2,1)
  {
    compOffsets[numComps+1] = bitLen + 3;
    deweyid[numComps] = 0;
    deweyid[numComps+1] = 3;
    ADVANCE(bitLen, byteIndex, bitIndex, 6);
    numComps += 2;
    break;
  }
  case 56:   // 0011 1000   001 + 110,00 +          (3/3,0 + 5/3,2)
  {
    compOffsets[numComps+1] = bitLen + 3;
    deweyid[numComps] = 0;
    deweyid[numComps+1] = 4;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 57:   // 0011 1001   001 + 110,01 +          (3/3,0 + 5/3,2)
  {
    compOffsets[numComps+1] = bitLen + 3;
    deweyid[numComps] = 0;
    deweyid[numComps+1] = 5;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 58:   // 0011 1010   001 + 110,10 +          (3/3,0 + 5/3,2)
  {
    compOffsets[numComps+1] = bitLen + 3;
    deweyid[numComps] = 0;
    deweyid[numComps+1] = 6;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 59:   // 0011 1011   001 + 110,11 +          (3/3,0 + 5/3,2)
  {
    compOffsets[numComps+1] = bitLen + 3;
    deweyid[numComps] = 0;
    deweyid[numComps+1] = 7;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 60:   // 0011 1100   001 + 1110,0 ...        (3/3,0 + 8/4,4)
  {
    compOffsets[numComps+1] = bitLen + 3;
    deweyid[numComps] = 0;
    ADVANCE(bitLen, byteIndex, bitIndex, 7);
    extractValue(data, bitLen, byteIndex, bitIndex, 4, 8, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }
  case 61:   // 0011 1101   001 + 1110,1 ...        (3/3,0 + 8/4,4)
  {
    compOffsets[numComps+1] = bitLen + 3;
    deweyid[numComps] = 0;
    ADVANCE(bitLen, byteIndex, bitIndex, 7);
    extractValue(data, bitLen, byteIndex, bitIndex, 4, 8, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }
  case 62:   // 0011 1110   001 + 11110, ...        (3/3,0 + 13/5,8)
  {
    compOffsets[numComps+1] = bitLen + 3;
    deweyid[numComps] = 0;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    extractValue(data, bitLen, byteIndex, bitIndex, 8, 24, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }
  case 63:   // 0011 1111   001 + 11111 ...         (3/3,0)
  {
    deweyid[numComps] = 0;
    ADVANCE(bitLen, byteIndex, bitIndex, 3);
    numComps += 1;
    break;
  }


  case 64:   // 0100 0000   01 + 000000 ...         (2/2,0)
  {
    deweyid[numComps] = 1;
    numComps++;
    ADVANCE(bitLen, byteIndex, bitIndex, 2);
    break;
  }
  case 65:   // 0100 0001   01 + 000001, ...        (2/2,0 + 14/6,8)
  {
    compOffsets[numComps+1] = bitLen + 2;
    deweyid[numComps] = 1;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    extractValue(data, bitLen, byteIndex, bitIndex, 8, -276, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }
  case 66:   // 0100 0010   01 + 00001,0 ...        (2/2,0 + 9/5,4)
  {
    compOffsets[numComps+1] = bitLen + 2;
    deweyid[numComps] = 1;
    ADVANCE(bitLen, byteIndex, bitIndex, 7);
    extractValue(data, bitLen, byteIndex, bitIndex, 4, -20, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }
  case 67:   // 0100 0011   01 + 00001,1 ...      (2/2,0 + 9/5,4)
  {
    compOffsets[numComps+1] = bitLen + 2;
    deweyid[numComps] = 1;
    ADVANCE(bitLen, byteIndex, bitIndex, 7);
    extractValue(data, bitLen, byteIndex, bitIndex, 4, -20, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }
  case 68:   // 0100 0100   01 + 0001,00 +        (2/2,0 + 6/4,2)
  {
    compOffsets[numComps+1] = bitLen + 2;
    deweyid[numComps] = 1;
    deweyid[numComps+1] = -4;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 69:   // 0100 0101   01 + 0001,01 +        (2/2,0 + 6/4,2)
  {
    compOffsets[numComps+1] = bitLen + 2;
    deweyid[numComps] = 1;
    deweyid[numComps+1] = -3;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 70:   // 0100 0110   01 + 0001,10 +          (2/2,0 + 6/4,2)
  {
    compOffsets[numComps+1] = bitLen + 2;
    deweyid[numComps] = 1;
    deweyid[numComps+1] = -2;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 71:   // 0100 0111   01 + 0001,11 +          (2/2,0 + 6/4,2)
  {
    compOffsets[numComps+1] = bitLen + 2;
    deweyid[numComps] = 1;
    deweyid[numComps+1] = -1;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  
  case 72:   // 0100 1000   01 + 001 + 000 ...      (2/2,0 + 3/3,0)
  {
    compOffsets[numComps+1] = bitLen + 2;
    deweyid[numComps] = 1;
    deweyid[numComps+1] = 0;
    ADVANCE(bitLen, byteIndex, bitIndex, 5);
    numComps += 2;
    break;
  }
  case 73:   // 0100 1001   01 + 001 + 001 +        (2/2,0 + 3/3,0 + 3/3,0)
  {
    compOffsets[numComps+1] = bitLen + 2;
    compOffsets[numComps+2] = bitLen + 5;
    deweyid[numComps] = 1;
    deweyid[numComps+1] = 0;
    deweyid[numComps+2] = 0;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 74:   // 0100 1010   01 + 001 + 01 + 0 ...   (2/2,0 + 3/3,0 + 2/2,0)
  {
    compOffsets[numComps+1] = bitLen + 2;
    compOffsets[numComps+2] = bitLen + 5;
    deweyid[numComps] = 1;
    deweyid[numComps+1] = 0;
    deweyid[numComps+2] = 1;
    ADVANCE(bitLen, byteIndex, bitIndex, 7);
    numComps += 3;
    break;
  }
  case 75:   // 0100 1011   01 + 001 + 01 + 1 ...   (2/2,0 + 3/3,0 + 2/2,0)
  {
    compOffsets[numComps+1] = bitLen + 2;
    compOffsets[numComps+2] = bitLen + 5;
    deweyid[numComps] = 1;
    deweyid[numComps+1] = 0;
    deweyid[numComps+2] = 1;
    ADVANCE(bitLen, byteIndex, bitIndex, 7);
    numComps += 3;
    break;
  }
  case 76:   // 0100 1100   01 + 001 + 10,0 +       (2/2,0 + 3/3,0 + 3/2,1)
  {
    compOffsets[numComps+1] = bitLen + 2;
    compOffsets[numComps+2] = bitLen + 5;
    deweyid[numComps] = 1;
    deweyid[numComps+1] = 0;
    deweyid[numComps+2] = 2;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 77:   // 0100 1101   01 + 001 + 10,1 +       (2/2,0 + 3/3,0 + 3/2,1)
  {
    compOffsets[numComps+1] = bitLen + 2;
    compOffsets[numComps+2] = bitLen + 5;
    deweyid[numComps] = 1;
    deweyid[numComps+1] = 0;
    deweyid[numComps+2] = 3;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 78:   // 0100 1110   01 + 001 + 110, ...     (2/2,0 + 3/3,0 + 5/3,2)
  {
    compOffsets[numComps+1] = bitLen + 2;
    compOffsets[numComps+2] = bitLen + 5;
    deweyid[numComps] = 1;
    deweyid[numComps+1] = 0;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    extractValue(data, bitLen, byteIndex, bitIndex, 2, 4, deweyid[numComps + 2]);
    numComps += 3;
    break;
  }
  case 79:   // 0100 1111   01 + 001 + 111 ...      (2/2,0 + 3/3,0)
  {
    compOffsets[numComps+1] = bitLen + 2;
    compOffsets[numComps+2] = bitLen + 5;
    deweyid[numComps] = 1;
    deweyid[numComps+1] = 0;
    ADVANCE(bitLen, byteIndex, bitIndex, 5);
    numComps += 2;
    break;
  }

  case 80:   // 0101 0000   01 + 01 + 0000 ...      (2/2,0 + 2/2,0)
  {
    compOffsets[numComps+1] = bitLen + 2;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 1;
    ADVANCE(bitLen, byteIndex, bitIndex, 4);
    numComps += 2;
    break;
  }
  case 81:   // 0101 0000   01 + 01 + 0001, ...     (2/2,0 + 2/2,0 + 6/4,2)
  {
    compOffsets[numComps+1] = bitLen + 2;
    compOffsets[numComps+2] = bitLen + 4;
    deweyid[numComps] = 1;
    deweyid[numComps+1] = 1;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    extractValue(data, bitLen, byteIndex, bitIndex, 2, -4, deweyid[numComps + 2]);
    numComps += 3;
    break;
  }
  case 82:   // 0101 0010   01 + 01 + 001 + 0...    (2/2,0 + 2/2,0 + 3/3,0)
  {
    compOffsets[numComps+1] = bitLen + 2;
    compOffsets[numComps+2] = bitLen + 4;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 1;
    deweyid[numComps + 2] = 0;
    ADVANCE(bitLen, byteIndex, bitIndex, 7);
    numComps += 3;
    break;
  }
  case 83:   // 0101 0011   01 + 01 + 001 + 1...    (2/2,0 + 2/2,0 + 3/3,0)
  {
    compOffsets[numComps+1] = bitLen + 2;
    compOffsets[numComps+2] = bitLen + 4;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 1;
    deweyid[numComps + 2] = 0;
    ADVANCE(bitLen, byteIndex, bitIndex, 7);
    numComps += 3;
    break;
  }
  case 84:   // 0101 0100   01 + 01 + 01 + 00 ... (2/2,0 + 2/2,0 + 2/2,0)
  {
    compOffsets[numComps+1] = bitLen + 2;
    compOffsets[numComps+2] = bitLen + 4;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 1;
    deweyid[numComps + 2] = 1;
    numComps += 3;
    ADVANCE(bitLen, byteIndex, bitIndex, 6);
    break;
  }
  case 85:   // 0101 0101   01 + 01 + 01 + 01 + (2/2,0 + 2/2,0 + 2/2,0 + 2/2,0)
  {
    compOffsets[numComps+1] = bitLen + 2;
    compOffsets[numComps+2] = bitLen + 4;
    compOffsets[numComps+3] = bitLen + 6;
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
    compOffsets[numComps+1] = bitLen + 2;
    compOffsets[numComps+2] = bitLen + 4;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 1;
    deweyid[numComps + 2] = 1;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    extractValue(data, bitLen, byteIndex, bitIndex, 1, 2, deweyid[numComps + 3]);
    numComps += 3;
    break;
  }
  case 87:   // 0101 0111   01 + 01 + 01 + 11 ... (2/2,0 + 2/2,0 + 2/2,0)
  {
    compOffsets[numComps+1] = bitLen + 2;
    compOffsets[numComps+2] = bitLen + 4;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 1;
    deweyid[numComps + 2] = 1;
    ADVANCE(bitLen, byteIndex, bitIndex, 6);
    numComps += 3;
    break;
  }
  case 88:   // 0101 1000   01 + 01 + 10,0 + 0 ... (2/2,0 + 2/2,0 + 3/2,1)
  {
    compOffsets[numComps+1] = bitLen + 2;
    compOffsets[numComps+2] = bitLen + 4;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 1;
    deweyid[numComps + 2] = 2;
    ADVANCE(bitLen, byteIndex, bitIndex, 7);
    numComps += 3;
    break;
  }
  case 89:   // 0101 1001   01 + 01 + 10,0 + 1 ... (2/2,0 + 2/2,0 + 3/2,1)
  {
    compOffsets[numComps+1] = bitLen + 2;
    compOffsets[numComps+2] = bitLen + 4;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 1;
    deweyid[numComps + 2] = 2;
    ADVANCE(bitLen, byteIndex, bitIndex, 7);
    numComps += 3;
    break;
  }
  case 90:   // 0101 1010   01 + 01 + 10,1 + 0 ... (2/2,0 + 2/2,0 + 3/2,1)
  {
    compOffsets[numComps+1] = bitLen + 2;
    compOffsets[numComps+2] = bitLen + 4;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 1;
    deweyid[numComps + 2] = 3;
    ADVANCE(bitLen, byteIndex, bitIndex, 7);
    numComps += 3;
    break;
  }
  case 91:   // 0101 1011   01 + 01 + 10,1 + 1 ... (2/2,0 + 2/2,0 + 3/2,1)
  {
    compOffsets[numComps+1] = bitLen + 2;
    compOffsets[numComps+2] = bitLen + 4;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 1;
    deweyid[numComps + 2] = 3;
    ADVANCE(bitLen, byteIndex, bitIndex, 7);
    numComps += 3;
    break;
  }
  case 92:   // 0101 1100   01 + 01 + 110,0 ... (2/2,0 + 2/2,0 + 5/3,2)
  {
    compOffsets[numComps+1] = bitLen + 2;
    compOffsets[numComps+2] = bitLen + 4;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 1;
    ADVANCE(bitLen, byteIndex, bitIndex, 7);
    extractValue(data, bitLen, byteIndex, bitIndex, 2, 4, deweyid[numComps + 2]);
    numComps += 3;
    break;
  }
  case 93:   // 0101 1101   01 + 01 + 110,1 ...     (2/2,0 + 2/2,0 + 5/3,2)
  {
    compOffsets[numComps+1] = bitLen + 2;
    compOffsets[numComps+2] = bitLen + 4;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 1;
    ADVANCE(bitLen, byteIndex, bitIndex, 7);
    extractValue(data, bitLen, byteIndex, bitIndex, 2, 4, deweyid[numComps + 2]);
    numComps += 3;
    break;
  }
  case 94:   // 0101 1110   01 + 01 + 1110, ...     (2/2,0 + 2/2,0 + 8/4,4)
  {
    compOffsets[numComps+1] = bitLen + 2;
    compOffsets[numComps+2] = bitLen + 4;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 1;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    extractValue(data, bitLen, byteIndex, bitIndex, 4, 8, deweyid[numComps + 2]);
    numComps += 3;
    break;
  }
  case 95:   // 0101 1111   01 + 01 + 1111 ...      (2/2,0 + 2/2,0)
  {
    compOffsets[numComps+1] = bitLen + 2;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 1;
    ADVANCE(bitLen, byteIndex, bitIndex, 4);
    numComps += 2;
    break;
  }


  case 96:   // 0110 0000   01 + 10,0 + 000 ...     (2/2,0 + 3/2,1)
  {
    compOffsets[numComps+1] = bitLen + 2;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 2;
    ADVANCE(bitLen, byteIndex, bitIndex, 5);
    numComps += 2;
    break;
  }
  case 97:   // 0110 0001   01 + 10,0 + 001 +     (2/2,0 + 3/2,1 + 3/3,0)
  {
    compOffsets[numComps+1] = bitLen + 2;
    compOffsets[numComps+2] = bitLen + 5;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 2;
    deweyid[numComps + 2] = 0;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 98:   // 0110 0010   01 + 10,0 + 01 + 0 ...  (2/2,0 + 3/2,1 + 2/2,0)
  {
    compOffsets[numComps+1] = bitLen + 2;
    compOffsets[numComps+2] = bitLen + 5;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 2;
    deweyid[numComps + 2] = 1;
    ADVANCE(bitLen, byteIndex, bitIndex, 7);
    numComps += 3;
    break;
  }
  case 99:   // 0110 0011   01 + 10,0 + 01 + 1 ...  (2/2,0 + 3/2,1 + 2/2,0)
  {
    compOffsets[numComps+1] = bitLen + 2;
    compOffsets[numComps+2] = bitLen + 5;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 2;
    deweyid[numComps + 2] = 1;
    ADVANCE(bitLen, byteIndex, bitIndex, 7);
    numComps += 3;
    break;
  }
  case 100:   // 0110 0100   01 + 10,0 + 10,0 +     (2/2,0 + 3/2,1 + 3/2,1)
  {
    compOffsets[numComps+1] = bitLen + 2;
    compOffsets[numComps+2] = bitLen + 5;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 2;
    deweyid[numComps + 2] = 2;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 101:   // 0110 0101   01 + 10,0 + 10,1 +     (2/2,0 + 3/2,1 + 3/2,1)
  {
    compOffsets[numComps+1] = bitLen + 2;
    compOffsets[numComps+2] = bitLen + 5;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 2;
    deweyid[numComps + 2] = 3;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 102:   // 0110 0110   01 + 10,0 + 110, ...   (2/2,0 + 3/2,1 + 5/3,2)
  {
    compOffsets[numComps+1] = bitLen + 2;
    compOffsets[numComps+2] = bitLen + 5;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 2;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    extractValue(data, bitLen, byteIndex, bitIndex, 2, 4, deweyid[numComps + 2]);
    numComps += 3;
    break;
  }
  case 103:   // 0110 0111   01 + 10,0 + 111 ...    (2/2,0 + 3/2,1)
  {
    compOffsets[numComps+1] = bitLen + 2;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 2;
    ADVANCE(bitLen, byteIndex, bitIndex, 5);
    numComps += 2;
    break;
  }
  case 104:   // 0110 1000   01 + 10,1 + 000 ...    (2/2,0 + 3/2,1)
  {
    compOffsets[numComps+1] = bitLen + 2;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 3;
    ADVANCE(bitLen, byteIndex, bitIndex, 5);
    numComps += 2;
    break;
  }
  case 105:   // 0110 1001   01 + 10,1 + 001 +      (2/2,0 + 3/2,1 + 3/3,0)
  {
    compOffsets[numComps+1] = bitLen + 2;
    compOffsets[numComps+2] = bitLen + 5;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 3;
    deweyid[numComps + 2] = 0;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 106:   // 0110 1010   01 + 10,1 + 01 + 0 ... (2/2,0 + 3/2,1 + 2/2,0)
  {
    compOffsets[numComps+1] = bitLen + 2;
    compOffsets[numComps+2] = bitLen + 5;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 3;
    deweyid[numComps + 2] = 1;
    ADVANCE(bitLen, byteIndex, bitIndex, 7);
    numComps += 3;
    break;
  }
  case 107:   // 0110 1011   01 + 10,1 + 01 + 1 ... (2/2,0 + 3/2,1 + 2/2,0)
  {
    compOffsets[numComps+1] = bitLen + 2;
    compOffsets[numComps+2] = bitLen + 5;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 3;
    deweyid[numComps + 2] = 1;
    ADVANCE(bitLen, byteIndex, bitIndex, 7);
    numComps += 3;
    break;
  }
  case 108:   // 0110 1100   01 + 10,1 + 10,0 ...   (2/2,0 + 3/2,1 + 3/2,1)
  {
    compOffsets[numComps+1] = bitLen + 2;
    compOffsets[numComps+2] = bitLen + 5;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 3;
    deweyid[numComps + 2] = 2;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 109:   // 0110 1101   01 + 10,1 + 10,1 ...   (2/2,0 + 3/2,1 + 3/2,1)
  {
    compOffsets[numComps+1] = bitLen + 2;
    compOffsets[numComps+2] = bitLen + 5;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 3;
    deweyid[numComps + 2] = 3;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 110:   // 0110 1110   01 + 10,1 + 110, ...   (2/2,0 + 3/2,1 + 5/3,2)
  {
    compOffsets[numComps+1] = bitLen + 2;
    compOffsets[numComps+2] = bitLen + 5;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 3;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    extractValue(data, bitLen, byteIndex, bitIndex, 2, 4, deweyid[numComps + 2]);
    numComps += 3;
    break;
  }
  case 111:   // 0110 1111   01 + 10,1 + 111 ...    (2/2,0 + 3/2,1)
  {
    compOffsets[numComps+1] = bitLen + 2;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 3;
    ADVANCE(bitLen, byteIndex, bitIndex, 5);
    numComps += 2;
    break;
  }


  case 112:   // 0111 0000   01 + 110,00 + 0 ...    (2/2,0 + 5/3,2)
  {
    compOffsets[numComps+1] = bitLen + 2;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 4;
    ADVANCE(bitLen, byteIndex, bitIndex, 7);
    numComps += 2;
    break;
  }
  case 113:   // 0111 0001   01 + 110,00 + 1 ...    (2/2,0 + 5/3,2)
  {
    compOffsets[numComps+1] = bitLen + 2;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 4;
    ADVANCE(bitLen, byteIndex, bitIndex, 7);
    numComps += 2;
    break;
  }
  case 114:   // 0111 0010   01 + 110,01 + 0 ...    (2/2,0 + 5/3,2)
  {
    compOffsets[numComps+1] = bitLen + 2;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 5;
    ADVANCE(bitLen, byteIndex, bitIndex, 7);
    numComps += 2;
    break;
  }
  case 115:   // 0111 0011   01 + 110,01 + 1 ...    (2/2,0 + 5/3,2)
  {
    compOffsets[numComps+1] = bitLen + 2;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 5;
    ADVANCE(bitLen, byteIndex, bitIndex, 7);
    numComps += 2;
    break;
  }
  case 116:   // 0111 0100   01 + 110,10 + 0 ...    (2/2,0 + 5/3,2)
  {
    compOffsets[numComps+1] = bitLen + 2;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 6;
    ADVANCE(bitLen, byteIndex, bitIndex, 7);
    numComps += 2;
    break;
  }
  case 117:   // 0111 0101   01 + 110,10 + 1 ...    (2/2,0 + 5/3,2)
  {
    compOffsets[numComps+1] = bitLen + 2;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 6;
    ADVANCE(bitLen, byteIndex, bitIndex, 7);
    numComps += 2;
    break;
  }
  case 118:   // 0111 0110   01 + 110,11 + 0 ...    (2/2,0 + 5/3,2)
  {
    compOffsets[numComps+1] = bitLen + 2;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 7;
    ADVANCE(bitLen, byteIndex, bitIndex, 7);
    numComps += 2;
    break;
  }
  case 119:   // 0111 0111   01 + 110,11 + 1 ...    (2/2,0 + 5/3,2)
  {
    compOffsets[numComps+1] = bitLen + 2;
    deweyid[numComps] = 1;
    deweyid[numComps + 1] = 7;
    ADVANCE(bitLen, byteIndex, bitIndex, 7);
    numComps += 2;
    break;
  }


  case 120:   // 0111 1000   01 + 1110,00 ...    (2/2,0 + 8/4,4)
  {
    compOffsets[numComps+1] = bitLen + 2;
    deweyid[numComps] = 1;
    ADVANCE(bitLen, byteIndex, bitIndex, 6);
    extractValue(data, bitLen, byteIndex, bitIndex, 4, 8, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }
  case 121:   // 0111 1001   01 + 1110,01 ...    (2/2,0 + 8/4,4)
  {
    compOffsets[numComps+1] = bitLen + 2;
    deweyid[numComps] = 1;
    ADVANCE(bitLen, byteIndex, bitIndex, 6);
    extractValue(data, bitLen, byteIndex, bitIndex, 4, 8, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }
  case 122:   // 0111 1010   01 + 1110,10 ...    (2/2,0 + 8/4,4)
  {
    compOffsets[numComps+1] = bitLen + 2;
    deweyid[numComps] = 1;
    ADVANCE(bitLen, byteIndex, bitIndex, 6);
    extractValue(data, bitLen, byteIndex, bitIndex, 4, 8, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }
  case 123:   // 0111 1011   01 + 1110,11 ...    (2/2,0 + 8/4,4)
  {
    compOffsets[numComps+1] = bitLen + 2;
    deweyid[numComps] = 1;
    ADVANCE(bitLen, byteIndex, bitIndex, 6);
    extractValue(data, bitLen, byteIndex, bitIndex, 4, 8, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }


  case 124:   // 0111 1100   01 + 11110,0 ...    (2/2,0 + 13/5,8)
  {
    compOffsets[numComps+1] = bitLen + 2;
    deweyid[numComps] = 1;
    ADVANCE(bitLen, byteIndex, bitIndex, 7);
    extractValue(data, bitLen, byteIndex, bitIndex, 8, 24, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }
  case 125:   // 0111 1101   01 + 11110,1 ...    (2/2,0 + 13/5,8)
  {
    compOffsets[numComps+1] = bitLen + 2;
    deweyid[numComps] = 1;
    ADVANCE(bitLen, byteIndex, bitIndex, 7);
    extractValue(data, bitLen, byteIndex, bitIndex, 8, 24, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }


  case 126:   // 0111 1110   01 + 111110, ...    (2/2,0 + 18/6,12)
  {
    compOffsets[numComps+1] = bitLen + 2;
    deweyid[numComps] = 1;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    extractValue(data, bitLen, byteIndex, bitIndex, 12, 280, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }


  case 127:   // 0111 1111   01 + 111111 ...    (2/2,0)
  {
    deweyid[numComps] = 1;
    ADVANCE(bitLen, byteIndex, bitIndex, 2);
    numComps += 1;
    break;
  }


  case 128:   // 1000 0000   10,0 + 00000 ...      (3/2,1)
  {
    deweyid[numComps] = 2;
    ADVANCE(bitLen, byteIndex, bitIndex, 3);
    numComps += 1;
    break;
  }
  case 129:   // 1000 0001   10,0 + 00001, ...      (3/2,1 + 9/5,4)
  {
    compOffsets[numComps+1] = bitLen + 3;
    deweyid[numComps] = 2;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    extractValue(data, bitLen, byteIndex, bitIndex, 4, -20, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }
  case 130:   // 1000 0010   10,0 + 0001,0 ...      (3/2,1 + 6/4,2)
  {
    compOffsets[numComps+1] = bitLen + 3;
    deweyid[numComps] = 2;
    ADVANCE(bitLen, byteIndex, bitIndex, 7);
    extractValue(data, bitLen, byteIndex, bitIndex, 2, -4, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }
  case 131:   // 1000 0011   10,0 + 0001,1 ...      (3/2,1 + 6/4,2)
  {
    compOffsets[numComps+1] = bitLen + 3;
    deweyid[numComps] = 2;
    ADVANCE(bitLen, byteIndex, bitIndex, 7);
    extractValue(data, bitLen, byteIndex, bitIndex, 2, -4, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }
  case 132:   // 1000 0100   10,0 + 001 + 00 ...   (3/2,1 + 3/3,0)
  {
    compOffsets[numComps+1] = bitLen + 3;
    deweyid[numComps] = 2;
    deweyid[numComps+1] = 0;
    ADVANCE(bitLen, byteIndex, bitIndex, 6);
    numComps += 2;
    break;
  }
  case 133:   // 1000 0101   10,0 + 001 + 01 ...   (3/2,1 + 3/3,0 + 2/2,0)
  {
    compOffsets[numComps+1] = bitLen + 3;
    compOffsets[numComps+2] = bitLen + 3;
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 0;
    deweyid[numComps + 1] = 1;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 134:   // 1000 0110   10,0 + 001 + 10, ...   (3/2,1 + 3/3,0 + 3/2,1)
  {
    compOffsets[numComps+1] = bitLen + 3;
    compOffsets[numComps+2] = bitLen + 3;
    deweyid[numComps] = 2;
    deweyid[numComps+1] = 0;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    extractValue(data, bitLen, byteIndex, bitIndex, 1, 2, deweyid[numComps + 2]);
    numComps += 3;
    break;
  }
  case 135:   // 1000 0111   10,0 + 001 + 11 ...    (3/2,1 + 3/3,0)
  {
    compOffsets[numComps+1] = bitLen + 3;
    deweyid[numComps] = 2;
    deweyid[numComps+1] = 0;
    ADVANCE(bitLen, byteIndex, bitIndex, 6);
    numComps += 2;
    break;
  }

  case 136:   // 1000 1000   10,0 + 01 + 000 ...    (3/2,1 + 2/2,0)
  {
    compOffsets[numComps+1] = bitLen + 3;
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 1;
    ADVANCE(bitLen, byteIndex, bitIndex, 5);
    numComps += 2;
    break;
  }
  case 137:   // 1000 1001   10,0 + 01 + 001 +      (3/2,1 + 2/2,0 + 3/3,0)
  {
    compOffsets[numComps+1] = bitLen + 3;
    compOffsets[numComps+2] = bitLen + 2;
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 1;
    deweyid[numComps + 1] = 0;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 138:   // 1000 1010   10,0 + 01 + 01 + 0 ... (3/2,1 + 2/2,0 + 2/2,0)
  {
    compOffsets[numComps+1] = bitLen + 3;
    compOffsets[numComps+2] = bitLen + 2;
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 1;
    deweyid[numComps + 1] = 1;
    ADVANCE(bitLen, byteIndex, bitIndex, 7);
    numComps += 3;
    break;
  }
  case 139:   // 1000 1011   10,0 + 01 + 01 + 1 ... (3/2,1 + 2/2,0 + 2/2,0)
  {
    compOffsets[numComps+1] = bitLen + 3;
    compOffsets[numComps+2] = bitLen + 2;
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 1;
    deweyid[numComps + 1] = 1;
    ADVANCE(bitLen, byteIndex, bitIndex, 7);
    numComps += 3;
    break;
  }
  case 140:   // 1000 1100   10,0 + 01 + 10,0 +     (3/2,1 + 2/2,0 + 3/2,1)
  {
    compOffsets[numComps+1] = bitLen + 3;
    compOffsets[numComps+2] = bitLen + 2;
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 1;
    deweyid[numComps + 1] = 2;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 141:   // 1000 1101   10,0 + 01 + 10,1 +     (3/2,1 + 2/2,0 + 3/2,1)
  {
    compOffsets[numComps+1] = bitLen + 3;
    compOffsets[numComps+2] = bitLen + 2;
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 1;
    deweyid[numComps + 1] = 3;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 142:   // 1000 1110   10,0 + 01 + 110 ...    (3/2,1 + 2/2,0 + 5/3,2)
  {
    compOffsets[numComps+1] = bitLen + 3;
    compOffsets[numComps+2] = bitLen + 2;
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 1;
    ADVANCE(bitLen, byteIndex, bitIndex, 5);
    extractValue(data, bitLen, byteIndex, bitIndex, 2, 4, deweyid[numComps + 2]);    
    numComps += 3;
    break;
  }
  case 143:   // 1000 1111   10,0 + 01 + 111 ...    (3/2,1 + 2/2,0)
  {
    compOffsets[numComps+1] = bitLen + 3;
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 1;
    ADVANCE(bitLen, byteIndex, bitIndex, 5);
    numComps += 2;
    break;
  }

  case 144:   // 1001 0000   10,0 + 10,0 + 00 ...   (3/2,1 + 3/2,1)
  {
    compOffsets[numComps+1] = bitLen + 3;
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 2;
    ADVANCE(bitLen, byteIndex, bitIndex, 6);
    numComps += 2;
    break;
  }
  case 145:   // 1001 0001   10,0 + 10,0 + 01 +     (3/2,1 + 3/2,1 + 2/2,0)
  {
    compOffsets[numComps+1] = bitLen + 3;
    compOffsets[numComps+2] = bitLen + 3;
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 2;
    deweyid[numComps + 2] = 1;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 146:   // 1001 0010   10,0 + 10,0 + 10, ...  (3/2,1 + 3/2,1 + 3/2,1)
  {
    compOffsets[numComps+1] = bitLen + 3;
    compOffsets[numComps+2] = bitLen + 3;
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 2;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    extractValue(data, bitLen, byteIndex, bitIndex, 1, 2, deweyid[numComps + 2]);
    numComps += 3;
    break;
  }
  case 147:   // 1001 0011   10,0 + 10,0 + 11 ...   (3/2,1 + 3/2,1)
  {
    compOffsets[numComps+1] = bitLen + 3;
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 2;
    ADVANCE(bitLen, byteIndex, bitIndex, 6);
    numComps += 2;
    break;
  }
  case 148:   // 1001 0100   10,0 + 10,1 + 00 ...   (3/2,1 + 3/2,1)
  {
    compOffsets[numComps+1] = bitLen + 3;
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 3;
    ADVANCE(bitLen, byteIndex, bitIndex, 6);
    numComps += 2;
    break;
  }
  case 149:   // 1001 0101   10,0 + 10,1 + 01 +     (3/2,1 + 3/2,1 + 2/2,0)
  {
    compOffsets[numComps+1] = bitLen + 3;
    compOffsets[numComps+2] = bitLen + 3;
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 3;
    deweyid[numComps + 2] = 1;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 150:   // 1001 0110   10,0 + 10,1 + 10, ...  (3/2,1 + 3/2,1 + 3/2,1)
  {
    compOffsets[numComps+1] = bitLen + 3;
    compOffsets[numComps+2] = bitLen + 3;
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 3;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    extractValue(data, bitLen, byteIndex, bitIndex, 1, 2, deweyid[numComps + 2]);
    numComps += 3;
    break;
  }
  case 151:   // 1001 0111   10,0 + 10,1 + 11 ...   (3/2,1 + 3/2,1)
  {
    compOffsets[numComps+1] = bitLen + 3;
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 3;
    ADVANCE(bitLen, byteIndex, bitIndex, 6);
    numComps += 2;
    break;
  }

  case 152:   // 1001 1000   10,0 + 110,00 +        (3/2,1 + 5/3,2)
  {
    compOffsets[numComps+1] = bitLen + 3;
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 4;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 153:   // 1001 1001   10,0 + 110,01 +        (3/2,1 + 5/3,2)
  {
    compOffsets[numComps+1] = bitLen + 3;
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 5;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 154:   // 1001 1010   10,0 + 110,10 +        (3/2,1 + 5/3,2)
  {
    compOffsets[numComps+1] = bitLen + 3;
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 6;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 155:   // 1001 1011   10,0 + 110,11 +        (3/2,1 + 5/3,2)
  {
    compOffsets[numComps+1] = bitLen + 3;
    deweyid[numComps] = 2;
    deweyid[numComps + 1] = 7;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }

  case 156:   // 1001 1100   10,0 + 1110, 0 ...     (3/2,1 + 8/4,4)
  {
    compOffsets[numComps+1] = bitLen + 3;
    deweyid[numComps] = 2;
    ADVANCE(bitLen, byteIndex, bitIndex, 7);
    extractValue(data, bitLen, byteIndex, bitIndex, 4, 8, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }
  case 157:   // 1001 1101   10,0 + 1110, 1 ...     (3/2,1 + 8/4,4)
  {
    compOffsets[numComps+1] = bitLen + 3;
    deweyid[numComps] = 2;
    ADVANCE(bitLen, byteIndex, bitIndex, 7);
    extractValue(data, bitLen, byteIndex, bitIndex, 4, 8, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }

  case 158:   // 1001 1110   10,0 + 11110, ...      (3/2,1 + 13/5,8)
  {
    compOffsets[numComps+1] = bitLen + 3;
    deweyid[numComps] = 2;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    extractValue(data, bitLen, byteIndex, bitIndex, 8, 24, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }

  case 159:   // 1001 1111   10,0 + 11111 ...       (3/2,1)
  {
    deweyid[numComps] = 2;
    ADVANCE(bitLen, byteIndex, bitIndex, 3);
    numComps += 1;
    break;
  }

  case 160:   // 1010 0000   10,1 + 00000 ...       (3/2,1)
  {
    deweyid[numComps] = 3;
    ADVANCE(bitLen, byteIndex, bitIndex, 3);
    numComps += 1;
    break;
  }

  case 161:   // 1010 0001   10,1 + 00001, ...      (3/2,1 + 9/5,4)
  {
    compOffsets[numComps+1] = bitLen + 3;
    deweyid[numComps] = 3;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    extractValue(data, bitLen, byteIndex, bitIndex, 4, -20, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }
  case 162:   // 1010 0010   10,1 + 0001,0 ...      (3/2,1 + 6/4,2)
  {
    compOffsets[numComps+1] = bitLen + 3;
    deweyid[numComps] = 3;
    ADVANCE(bitLen, byteIndex, bitIndex, 7);
    extractValue(data, bitLen, byteIndex, bitIndex, 2, -4, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }
  case 163:   // 1010 0011   10,1 + 0001,1 ...      (3/2,1 + 6/4,2)
  {
    compOffsets[numComps+1] = bitLen + 3;
    deweyid[numComps] = 3;
    ADVANCE(bitLen, byteIndex, bitIndex, 7);
    extractValue(data, bitLen, byteIndex, bitIndex, 2, -4, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }
  case 164:   // 1010 0100   10,1 + 001 + 00 ...    (3/2,1 + 3/3,0)
  {
    compOffsets[numComps+1] = bitLen + 3;
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 0;
    ADVANCE(bitLen, byteIndex, bitIndex, 5);
    numComps += 2;
    break;
  }
  case 165:   // 1010 0101   10,1 + 001 + 01 +      (3/2,1 + 3/3,0 + 2/2,0)
  {
    compOffsets[numComps+1] = bitLen + 3;
    compOffsets[numComps+2] = bitLen + 3;
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 0;
    deweyid[numComps + 2] = 1;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 166:   // 1010 0110   10,1 + 001 + 10, ...   (3/2,1 + 3/3,0 + 3/2,1)
  {
    compOffsets[numComps+1] = bitLen + 3;
    compOffsets[numComps+2] = bitLen + 3;
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 0;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    extractValue(data, bitLen, byteIndex, bitIndex, 1, 2, deweyid[numComps + 2]);
    numComps += 3;
    break;
  }
  case 167:   // 1010 0111   10,1 + 001 + 11 ...    (3/2,1 + 3/3,0)
  {
    compOffsets[numComps+1] = bitLen + 3;
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 0;
    ADVANCE(bitLen, byteIndex, bitIndex, 5);
    numComps += 2;
    break;
  }

  case 168:   // 1010 1000   10,1 + 01 + 000 ...    (3/2,1 + 2/2,0)
  {
    compOffsets[numComps+1] = bitLen + 3;
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 1;
    ADVANCE(bitLen, byteIndex, bitIndex, 5);
    numComps += 2;
    break;
  }
  case 169:   // 1010 1001   10,1 + 01 + 001 +      (3/2,1 + 2/2,0 + 3/3,0)
  {
    compOffsets[numComps+1] = bitLen + 3;
    compOffsets[numComps+2] = bitLen + 2;
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 1;
    deweyid[numComps + 2] = 0;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 170:   // 1010 1010   10,1 + 01 + 01 + 0 ... (3/2,1 + 2/2,0 + 2/2,0)
  {
    compOffsets[numComps+1] = bitLen + 3;
    compOffsets[numComps+2] = bitLen + 2;
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 1;
    deweyid[numComps + 2] = 1;
    ADVANCE(bitLen, byteIndex, bitIndex, 7);
    numComps += 3;
    break;
  }
  case 171:   // 1010 1011   10,1 + 01 + 01 + 1 ... (3/2,1 + 2/2,0 + 2/2,0)
  {
    compOffsets[numComps+1] = bitLen + 3;
    compOffsets[numComps+2] = bitLen + 2;
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 1;
    deweyid[numComps + 2] = 1;
    ADVANCE(bitLen, byteIndex, bitIndex, 7);
    numComps += 3;
    break;
  }
  case 172:   // 1010 1100   10,1 + 01 + 10,0 +     (3/2,1 + 2/2,0 + 3/2,1)
  {
    compOffsets[numComps+1] = bitLen + 3;
    compOffsets[numComps+2] = bitLen + 2;
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 1;
    deweyid[numComps + 2] = 2;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 173:   // 1010 1101   10,1 + 01 + 10,1 +     (3/2,1 + 2/2,0 + 3/2,1)
  {
    compOffsets[numComps+1] = bitLen + 3;
    compOffsets[numComps+2] = bitLen + 2;
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 1;
    deweyid[numComps + 2] = 3;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 174:   // 1010 1110   10,1 + 01 + 110, ...   (3/2,1 + 2/2,0 + 5/3,2)
  {
    compOffsets[numComps+1] = bitLen + 3;
    compOffsets[numComps+2] = bitLen + 2;
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 1;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    extractValue(data, bitLen, byteIndex, bitIndex, 2, 4, deweyid[numComps + 2]);
    numComps += 3;
    break;
  }
  case 175:   // 1010 1111   10,1 + 01 + 111 ...    (3/2,1 + 2/2,0)
  {
    compOffsets[numComps+1] = bitLen + 3;
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 1;
    ADVANCE(bitLen, byteIndex, bitIndex, 5);
    numComps += 2;
    break;
  }
  case 176:   // 1011 0000   10,1 + 10,0 + 00 ...   (3/2,1 + 3/2,1)
  {
    compOffsets[numComps+1] = bitLen + 3;
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 2;
    ADVANCE(bitLen, byteIndex, bitIndex, 6);
    numComps += 2;
    break;
  }
  case 177:   // 1011 0001   10,1 + 10,0 + 01 +     (3/2,1 + 3/2,1 + 2/2,0)
  {
    compOffsets[numComps+1] = bitLen + 3;
    compOffsets[numComps+2] = bitLen + 3;
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 2;
    deweyid[numComps + 2] = 1;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 178:   // 1011 0010   10,1 + 10,0 + 10, ...  (3/2,1 + 3/2,1 + 3/2,1)
  {
    compOffsets[numComps+1] = bitLen + 3;
    compOffsets[numComps+2] = bitLen + 3;
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 2;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    extractValue(data, bitLen, byteIndex, bitIndex, 1, 2, deweyid[numComps + 2]);
    numComps += 3;
    break;
  }
  case 179:   // 1011 0011   10,1 + 10,0 + 11 ...   (3/2,1 + 3/2,1)
  {
    compOffsets[numComps+1] = bitLen + 3;
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 2;
    ADVANCE(bitLen, byteIndex, bitIndex, 6);
    numComps += 2;
    break;
  }
  case 180:   // 1011 0100   10,1 + 10,1 + 00 ...   (3/2,1 + 3/2,1)
  {
    compOffsets[numComps+1] = bitLen + 3;
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 3;
    ADVANCE(bitLen, byteIndex, bitIndex, 6);
    numComps += 2;
    break;
  }
  case 181:   // 1011 0101   10,1 + 10,1 + 01 +     (3/2,1 + 3/2,1 + 2/2,0)
  {
    compOffsets[numComps+1] = bitLen + 3;
    compOffsets[numComps+2] = bitLen + 3;
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 3;
    deweyid[numComps + 2] = 1;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 3;
    break;
  }
  case 182:   // 1011 0110   10,1 + 10,1 + 10, ...  (3/2,1 + 3/2,1 + 3/2,1)
  {
    compOffsets[numComps+1] = bitLen + 3;
    compOffsets[numComps+2] = bitLen + 3;
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 3;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    extractValue(data, bitLen, byteIndex, bitIndex, 1, 2, deweyid[numComps + 2]);
    numComps += 3;
    break;
  }
  case 183:   // 1011 0111   10,1 + 10,1 + 11 ...   (3/2,1 + 3/2,1)
  {
    compOffsets[numComps+1] = bitLen + 3;
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 3;
    ADVANCE(bitLen, byteIndex, bitIndex, 6);
    numComps += 2;
    break;
  }

  case 184:   // 1011 1000   10,1 + 110,00 +        (3/2,1 + 5/3,2)
  {
    compOffsets[numComps+1] = bitLen + 3;
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 4;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 185:   // 1011 1001   10,1 + 110,01 +        (3/2,1 + 5/3,2)
  {
    compOffsets[numComps+1] = bitLen + 3;
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 5;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 186:   // 1011 1010   10,1 + 110,10 +        (3/2,1 + 5/3,2)
  {
    compOffsets[numComps+1] = bitLen + 3;
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 6;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 187:   // 1011 1011   10,1 + 110,11 +        (3/2,1 + 5/3,2)
  {
    compOffsets[numComps+1] = bitLen + 3;
    deweyid[numComps] = 3;
    deweyid[numComps + 1] = 7;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }

  case 188:   // 1011 1100   10,1 + 1110,0 ...      (3/2,1 + 8/4,4)
  {
    compOffsets[numComps+1] = bitLen + 3;
    deweyid[numComps] = 3;
    ADVANCE(bitLen, byteIndex, bitIndex, 7);
    extractValue(data, bitLen, byteIndex, bitIndex, 4, 8, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }
  case 189:   // 1011 1101   10,1 + 1110,1 ...      (3/2,1 + 8/4,4)
  {
    compOffsets[numComps+1] = bitLen + 3;
    deweyid[numComps] = 3;
    ADVANCE(bitLen, byteIndex, bitIndex, 7);
    extractValue(data, bitLen, byteIndex, bitIndex, 4, 8, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }

  case 190:   // 1011 1110   10,1 + 11110, ...      (3/2,1 + 13/5,8)
  {
    compOffsets[numComps+1] = bitLen + 3;
    deweyid[numComps] = 3;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    extractValue(data, bitLen, byteIndex, bitIndex, 8, 24, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }

  case 191:   // 1011 1111   10,1 + 11111 ...       (3/2,1)
  {
    deweyid[numComps] = 3;
    ADVANCE(bitLen, byteIndex, bitIndex, 3);
    numComps += 1;
    break;
  }


  case 192:   // 1100 0000   110,00 + 000 ...       (5/3,2)
  {
    deweyid[numComps] = 4;
    ADVANCE(bitLen, byteIndex, bitIndex, 5);
    numComps += 1;
    break;
  }
  case 193:   // 1100 0001   110,00 + 001 +         (5/3,2 + 3/3,0)
  {
    compOffsets[numComps+1] = bitLen + 5;
    deweyid[numComps] = 4;
    deweyid[numComps + 1] = 0;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 194:   // 1100 0010   110,00 + 01 + 0 ...    (5/3,2 + 2/2,0)
  {
    compOffsets[numComps+1] = bitLen + 5;
    deweyid[numComps] = 4;
    deweyid[numComps + 1] = 1;
    ADVANCE(bitLen, byteIndex, bitIndex, 7);
    numComps += 2;
    break;
  }
  case 195:   // 1100 0011   110,00 + 01 + 1 ...    (5/3,2 + 2/2,0)
  {
    compOffsets[numComps+1] = bitLen + 5;
    deweyid[numComps] = 4;
    deweyid[numComps + 1] = 1;
    ADVANCE(bitLen, byteIndex, bitIndex, 7);
    numComps += 2;
    break;
  }

  case 196:   // 1100 0100   110,00 + 10,0 +        (5/3,2 + 3/2,1)
  {
    compOffsets[numComps+1] = bitLen + 5;
    deweyid[numComps] = 4;
    deweyid[numComps + 1] = 2;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 197:   // 1100 0101   110,00 + 10,1 +        (5/3,2 + 3/2,1)
  {
    compOffsets[numComps+1] = bitLen + 5;
    deweyid[numComps] = 4;
    deweyid[numComps + 1] = 3;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 198:   // 1100 0110   110,00 + 110, ...      (5/3,2 + 5/3,2)
  {
    compOffsets[numComps+1] = bitLen + 5;
    deweyid[numComps] = 4;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    extractValue(data, bitLen, byteIndex, bitIndex, 2, 4, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }
  case 199:   // 1100 0111   110,00 + 111 ...       (5/3,2)
  {
    deweyid[numComps] = 4;
    ADVANCE(bitLen, byteIndex, bitIndex, 5);
    numComps += 1;
    break;
  }

  case 200:   // 1100 1000   110,01 + 000 ...       (5/3,2)
  {
    deweyid[numComps] = 5;
    ADVANCE(bitLen, byteIndex, bitIndex, 5);
    numComps += 1;
    break;
  }
  case 201:   // 1100 1001   110,01 + 001 +         (5/3,2 + 3/3,0)
  {
    compOffsets[numComps+1] = bitLen + 5;
    deweyid[numComps] = 5;
    deweyid[numComps + 1] = 0;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 202:   // 1100 1010   110,01 + 01 + 0 ...    (5/3,2 + 2/2,0)
  {
    compOffsets[numComps+1] = bitLen + 5;
    deweyid[numComps] = 5;
    deweyid[numComps + 1] = 1;
    ADVANCE(bitLen, byteIndex, bitIndex, 7);
    numComps += 2;
    break;
  }
  case 203:   // 1100 1011   110,01 + 01 + 1 ...    (5/3,2 + 2/2,0)
  {
    compOffsets[numComps+1] = bitLen + 5;
    deweyid[numComps] = 5;
    deweyid[numComps + 1] = 1;
    ADVANCE(bitLen, byteIndex, bitIndex, 7);
    numComps += 2;
    break;
  }
  case 204:   // 1100 1100   110,01 + 10,0 +        (5/3,2 + 3/2,1)
  {
    compOffsets[numComps+1] = bitLen + 5;
    deweyid[numComps] = 5;
    deweyid[numComps + 1] = 2;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 205:   // 1100 1101   110,01 + 10,1 +        (5/3,2 + 3/2,1)
  {
    compOffsets[numComps+1] = bitLen + 5;
    deweyid[numComps] = 5;
    deweyid[numComps + 1] = 3;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 206:   // 1100 1110   110,01 + 110, ...      (5/3,2 + 5/3,2)
  {
    compOffsets[numComps+1] = bitLen + 5;
    deweyid[numComps] = 5;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    extractValue(data, bitLen, byteIndex, bitIndex, 2, 4, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }
  case 207:   // 1100 1111   110,01 + 111 ...       (5/3,2)
  {
    deweyid[numComps] = 5;
    ADVANCE(bitLen, byteIndex, bitIndex, 5);
    numComps += 1;
    break;
  }

  case 208:   // 1101 0000   110,10 + 000 ...       (5/3,2)
  {
    deweyid[numComps] = 6;
    ADVANCE(bitLen, byteIndex, bitIndex, 5);
    numComps += 1;
    break;
  }
  case 209:   // 1101 0001   110,10 + 001 +         (5/3,2 + 3/3,0)
  {
    compOffsets[numComps+1] = bitLen + 5;
    deweyid[numComps] = 6;
    deweyid[numComps + 1] = 0;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 210:   // 1101 0010   110,10 + 01 + 0 ...    (5/3,2 + 2/2,0)
  {
    compOffsets[numComps+1] = bitLen + 5;
    deweyid[numComps] = 6;
    deweyid[numComps + 1] = 1;
    ADVANCE(bitLen, byteIndex, bitIndex, 7);
    numComps += 2;
    break;
  }
  case 211:   // 1101 0011   110,10 + 01 + 1 ...    (5/3,2 + 2/2,0)
  {
    compOffsets[numComps+1] = bitLen + 5;
    deweyid[numComps] = 6;
    deweyid[numComps + 1] = 1;
    ADVANCE(bitLen, byteIndex, bitIndex, 7);
    numComps += 2;
    break;
  }
  case 212:   // 1101 0100   110,10 + 10,0 +        (5/3,2 + 3/2,1)
  {
    compOffsets[numComps+1] = bitLen + 5;
    deweyid[numComps] = 6;
    deweyid[numComps + 1] = 2;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 213:   // 1101 0101   110,10 + 10,1 +        (5/3,2 + 3/2,1)
  {
    compOffsets[numComps+1] = bitLen + 5;
    deweyid[numComps] = 6;
    deweyid[numComps + 1] = 3;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 214:   // 1101 0110   110,10 + 110, ...      (5/3,2 + 5/3,2)
  {
    compOffsets[numComps+1] = bitLen + 5;
    deweyid[numComps] = 6;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    extractValue(data, bitLen, byteIndex, bitIndex, 2, 4, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }
  case 215:   // 1101 0111   110,10 + 111 ...       (5/3,2)
  {
    deweyid[numComps] = 6;
    ADVANCE(bitLen, byteIndex, bitIndex, 5);
    numComps += 1;
    break;
  }

  case 216:   // 1101 1000   110,11 + 000 ...       (5/3,2)
  {
    deweyid[numComps] = 7;
    ADVANCE(bitLen, byteIndex, bitIndex, 5);
    numComps += 1;
    break;
  }
  case 217:   // 1101 1001   110,11 + 001 +         (5/3,2 + 3/3,0)
  {
    compOffsets[numComps+1] = bitLen + 5;
    deweyid[numComps] = 7;
    deweyid[numComps + 1] = 0;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 218:   // 1101 1010   110,11 + 01 + 0 ...    (5/3,2 + 2/2,0)
  {
    compOffsets[numComps+1] = bitLen + 5;
    deweyid[numComps] = 7;
    deweyid[numComps + 1] = 1;
    ADVANCE(bitLen, byteIndex, bitIndex, 7);
    numComps += 2;
    break;
  }
  case 219:   // 1101 1011   110,11 + 01 + 1 ...    (5/3,2 + 2/2,0)
  {
    compOffsets[numComps+1] = bitLen + 5;
    deweyid[numComps] = 7;
    deweyid[numComps + 1] = 1;
    ADVANCE(bitLen, byteIndex, bitIndex, 7);
    numComps += 2;
    break;
  }
  case 220:   // 1101 1100   110,11 + 10,0 +        (5/3,2 + 3/2,1)
  {
    compOffsets[numComps+1] = bitLen + 5;
    deweyid[numComps] = 7;
    deweyid[numComps + 1] = 2;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 221:   // 1101 1101   110,11 + 10,1 +        (5/3,2 + 3/2,1)
  {
    compOffsets[numComps+1] = bitLen + 5;
    deweyid[numComps] = 7;
    deweyid[numComps + 1] = 3;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 2;
    break;
  }
  case 222:   // 1101 1110   110,11 + 110, ...      (5/3,2 + 5/3,2)
  {
    compOffsets[numComps+1] = bitLen + 5;
    deweyid[numComps] = 7;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    extractValue(data, bitLen, byteIndex, bitIndex, 2, 4, deweyid[numComps + 1]);
    numComps += 2;
    break;
  }
  case 223:   // 1101 1111   110,11 + 111 ...       (5/3,2)
  {
    deweyid[numComps] = 7;
    ADVANCE(bitLen, byteIndex, bitIndex, 5);
    numComps += 1;
    break;
  }
  case 224:   // 1110 0000   1110,0000 +            (8/4,4)
  {
    deweyid[numComps] = 8;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 1;
    break;
  }
  case 225:   // 1110 0001   1110,0001 +            (8/4,4)
  {
    deweyid[numComps] = 9;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 1;
    break;
  }
  case 226:   // 1110 0010   1110,0010 +            (8/4,4)
  {
    deweyid[numComps] = 10;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 1;
    break;
  }
  case 227:   // 1110 0011   1110,0011 +            (8/4,4)
  {
    deweyid[numComps] = 11;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 1;
    break;
  }
  case 228:   // 1110 0100   1110,0100 +            (8/4,4)
  {
    deweyid[numComps] = 12;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 1;
    break;
  }
  case 229:   // 1110 0101   1110,0101 +            (8/4,4)
  {
    deweyid[numComps] = 13;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 1;
    break;
  }
  case 230:   // 1110 0110   1110,0110 +            (8/4,4)
  {
    deweyid[numComps] = 14;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 1;
    break;
  }
  case 231:   // 1110 0111   1110,0111 +            (8/4,4)
  {
    deweyid[numComps] = 15;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 1;
    break;
  }
  case 232:   // 1110 1000   1110,1000 +            (8/4,4)
  {
    deweyid[numComps] = 16;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 1;
    break;
  }
  case 233:   // 1110 1001   1110,1001 +            (8/4,4)
  {
    deweyid[numComps] = 17;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 1;
    break;
  }
  case 234:   // 1110 1010   1110,1010 +            (8/4,4)
  {
    deweyid[numComps] = 18;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 1;
    break;
  }
  case 235:   // 1110 1011   1110,1011 +            (8/4,4)
  {
    deweyid[numComps] = 19;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 1;
    break;
  }
  case 236:   // 1110 1100   1110,1100 +            (8/4,4)
  {
    deweyid[numComps] = 20;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 1;
    break;
  }
  case 237:   // 1110 1101   1110,1101 +            (8/4,4)
  {
    deweyid[numComps] = 21;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 1;
    break;
  }
  case 238:   // 1110 1110   1110,1110 +            (8/4,4)
  {
    deweyid[numComps] = 22;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 1;
    break;
  }
  case 239:   // 1110 1111   1110,1111 +            (8/4,4)
  {
    deweyid[numComps] = 23;
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    numComps += 1;
    break;
  }
  case 240:   // 1111 0000   11110,000...           (13/5,8)
  {
    ADVANCE(bitLen, byteIndex, bitIndex, 5);
    extractValue(data, bitLen, byteIndex, bitIndex, 8, 24, deweyid[numComps]);
    numComps += 1;
    break;
  }
  case 241:   // 1111 0001   11110,001...           (13/5,8)
  {
    ADVANCE(bitLen, byteIndex, bitIndex, 5);
    extractValue(data, bitLen, byteIndex, bitIndex, 8, 24, deweyid[numComps]);
    numComps += 1;
    break;
  }
  case 242:   // 1111 0010   11110,010...           (13/5,8)
  {
    ADVANCE(bitLen, byteIndex, bitIndex, 5);
    extractValue(data, bitLen, byteIndex, bitIndex, 8, 24, deweyid[numComps]);
    numComps += 1;
    break;
  }
  case 243:   // 1111 0011   11110,011...           (13/5,8)
  {
    ADVANCE(bitLen, byteIndex, bitIndex, 5);
    extractValue(data, bitLen, byteIndex, bitIndex, 8, 24, deweyid[numComps]);
    numComps += 1;
    break;
  }
  case 244:   // 1111 0100   11110,100...           (13/5,8)
  {
    ADVANCE(bitLen, byteIndex, bitIndex, 5);
    extractValue(data, bitLen, byteIndex, bitIndex, 8, 24, deweyid[numComps]);
    numComps += 1;
    break;
  }
  case 245:   // 1111 0101   11110,101...           (13/5,8)
  {
    ADVANCE(bitLen, byteIndex, bitIndex, 5);
    extractValue(data, bitLen, byteIndex, bitIndex, 8, 24, deweyid[numComps]);
    numComps += 1;
    break;
  }
  case 246:   // 1111 0110   11110,110...           (13/5,8)
  {
    ADVANCE(bitLen, byteIndex, bitIndex, 5);
    extractValue(data, bitLen, byteIndex, bitIndex, 8, 24, deweyid[numComps]);
    numComps += 1;
    break;
  }
  case 247:   // 1111 0111   11110,111...           (13/5,8)
  {
    ADVANCE(bitLen, byteIndex, bitIndex, 5);
    extractValue(data, bitLen, byteIndex, bitIndex, 8, 24, deweyid[numComps]);
    numComps += 1;
    break;
  }
  case 248:   // 1111 1000   111110,00...           (18/6,12)
  {
    ADVANCE(bitLen, byteIndex, bitIndex, 6);
    extractValue(data, bitLen, byteIndex, bitIndex, 12, 280, deweyid[numComps]);
    numComps += 1;
    break;
  }
  case 249:   // 1111 1001   111110,01...           (18/6,12)
  {
    ADVANCE(bitLen, byteIndex, bitIndex, 6);
    extractValue(data, bitLen, byteIndex, bitIndex, 12, 280, deweyid[numComps]);
    numComps += 1;
    break;
  }
  case 250:   // 1111 1010   111110,10...           (18/6,12)
  {
    ADVANCE(bitLen, byteIndex, bitIndex, 6);
    extractValue(data, bitLen, byteIndex, bitIndex, 12, 280, deweyid[numComps]);
    numComps += 1;
    break;
  }
  case 251:   // 1111 1011   111110,11...           (18/6,12)
  {
    ADVANCE(bitLen, byteIndex, bitIndex, 6);
    extractValue(data, bitLen, byteIndex, bitIndex, 12, 280, deweyid[numComps]);
    numComps += 1;
    break;
  }
  case 252:   // 1111 1100   1111110,0...           (23/7,16)
  {
    ADVANCE(bitLen, byteIndex, bitIndex, 7);
    extractValue(data, bitLen, byteIndex, bitIndex, 16, 4376, deweyid[numComps]);
    numComps += 1;
    break;
  }
  case 253:   // 1111 1101   1111110,1...           (23/7,16)
  {
    ADVANCE(bitLen, byteIndex, bitIndex, 7);
    extractValue(data, bitLen, byteIndex, bitIndex, 16, 4376, deweyid[numComps]);
    numComps += 1;
    break;
  }
  case 254:   // 1111 1110   11111110,...           (28/8,20)
  {
    ADVANCE(bitLen, byteIndex, bitIndex, 8);
    extractValue(data, bitLen, byteIndex, bitIndex, 20, 69912, deweyid[numComps]);
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
    unsigned char* data,
    ulong& bitLen,
    ulong& byteIndex,
    ulong& bitIndex,
    ulong  numBits,
    long   baseValue,
    long&  result)
{
  bitLen += numBits;

  if (numBits < 8 - bitIndex)
  {
    unsigned char byte = data[byteIndex];
    byte <<= bitIndex;
    byte >>= (8 - numBits);
    bitIndex += numBits;
    result = byte;
    result += baseValue;
    return;
  }

  unsigned char byte = data[byteIndex]  & theByteMasks[bitIndex][0];
  result = byte;
  numBits -= (8 - bitIndex);
  byteIndex++;

  ulong numBytes = numBits / 8;

  for (ulong i = 0; i < numBytes; i++)
  {
    result <<= 8;
    result |= data[byteIndex];
    byteIndex++;
  }

  numBits -= numBytes * 8;
  bitIndex = numBits;

  if (numBits > 0)
  {
    result <<= numBits;
    byte = data[byteIndex]  & theByteMasks[numBits][1];
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

  theBuffer[0] = 0x40;
  theByteIndex = 0;
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
    ZORBA_ERROR_PARAM_OSS(ZorbaError::XQP0018_NODEID_ERROR,
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
  ZORBA_ASSERT(theNumComps > 0);

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
      ZORBA_ERROR_DESC( ZorbaError::XQP0018_NODEID_ERROR,
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
      ZORBA_ERROR_DESC( ZorbaError::XQP0018_NODEID_ERROR,
                        "A nodeid component is too large to be encoded");
      return;
    }
  }

  ulong bytesNeeded = theByteIndex +
                      (bitsNeeded + 15 - theBitsAvailable) / 8;

  if (bytesNeeded > OrdPath::MAX_BYTE_LEN)
  {
    ZORBA_ERROR_PARAM_OSS( ZorbaError::XQP0018_NODEID_ERROR,
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

  for (ulong i = 0; i < len; i++)
  {
    str << std::hex << (unsigned short)theBuffer[i] << '|';
  }
#endif
  return str.str().c_str();
}

} // namespace store
} // namespace zorba

