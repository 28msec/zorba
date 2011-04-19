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

#ifndef ZORBA_STORE_ORDPATH_H
#define ZORBA_STORE_ORDPATH_H

#include <vector>

#include <zorba/config.h>

#include "common/common.h"

#include "zorbautils/fatal.h"

#include "zorbatypes/zstring.h"


namespace zorba { namespace simplestore {

class OrdPathStack;


/*******************************************************************************

********************************************************************************/
// only exported for unit testing
class ZORBA_DLL_PUBLIC OrdPath
{
  friend class OrdPathStack;

public:
  typedef enum
  {
    PRECEDING,
    ANCESTOR,
    SELF,
    DESCENDANT,
    FOLLOWING
  }
  RelativePosition;


  typedef std::vector<int32_t> DeweyID;

public:
  enum {
    MAX_BYTE_LEN = 255,
    MAX_BIT_LEN = MAX_BYTE_LEN * 8
  };

protected:
  static const ulong MAX_EMBEDDED_BYTE_LEN = 8;
  static const ulong MAX_EMBEDDED_BIT_LEN = MAX_EMBEDDED_BYTE_LEN * 8 - 1;

  static const ulong MAX_EMBEDDED_BYTE = MAX_EMBEDDED_BYTE_LEN - 1;

  static const ulong MAX_NUM_COMPS = MAX_BYTE_LEN * 4;

  // decompression
  static const unsigned char theByteMasks[8][2];

  // compression
  static const uint32_t theValueMasks[9];

  static const long DEFAULT_FAN_OUT = 32;

  static const unsigned char thePosV2LMap[DEFAULT_FAN_OUT];
  static const unsigned char theNegV2LMap[DEFAULT_FAN_OUT];
  static const uint16_t      thePosV2EVMap[DEFAULT_FAN_OUT];
  static const uint16_t      theNegV2EVMap[DEFAULT_FAN_OUT];

protected:
  union
  {
    unsigned char    local[MAX_EMBEDDED_BYTE_LEN];
    unsigned char  * remote;
  } theBuffer;

public:
  static void insertBefore(
        const OrdPath& parent,
        const OrdPath& sibling,
        OrdPath&       result);

  static void insertAfter(
        const OrdPath& parent,
        const OrdPath& sibling,
        OrdPath&       result);

  static void insertInto(
        const OrdPath& parent,
        const OrdPath& sib1,
        const OrdPath& sib2,
        OrdPath&       result);

protected:
  static bool pushComp(
        unsigned char* buf,
        ulong          maxBitSize,
        int32_t        value,
        ulong&         bitSize);

  static void bitsNeeded(
        int32_t    value, 
        ulong&     bitsNeeded,
        uint32_t&  eval,
        uint64_t&  eval2);

  static void appendEncodedComp(
        uint32_t       eval,
        ulong          bitsNeeded,
        ulong          byteIndex,
        ulong          bitsAvailable,
        unsigned char* data);

  static void insertBeforeOrAfter(
        bool           before,
        const OrdPath& parent,
        const OrdPath& sibling,
        OrdPath&       result);

  static void decodeByte(
        unsigned char* data,
        ulong&         bitSize,
        ulong&         byteIndex,
        ulong&         bitIndex,
        unsigned char  byte,
        int32_t*       deweyid,
        ulong*         compOffsets,
        ulong&         numComps);

  static void extractValue(
        unsigned char* data,
        ulong&         bitLen,
        ulong&         byteIndex,
        ulong&         bitIndex,
        ulong          numBits,
        int32_t        baseValue,
        int32_t&       result);


public:
  OrdPath() 
  {
    memset(theBuffer.local, 0, MAX_EMBEDDED_BYTE_LEN);
    markLocal();
  }

  OrdPath(const unsigned char* buf, ulong byteLen);

  ~OrdPath() 
  {
    if (!isLocal())
      delete [] getRemoteBuffer();
  }

  bool isValid() const { return getByteLength() != 0; }

  uint32_t hash() const;

  void setAsRoot();

  OrdPath& operator=(const OrdPath& other);
  OrdPath& operator=(const OrdPathStack& ops);

  bool operator==(const OrdPath& other) const;
  int operator<(const OrdPath& other) const;
  int operator>(const OrdPath& other) const;

  RelativePosition getRelativePosition(const OrdPath& other) const;

  void compress(const DeweyID& dewey);

  void appendComp(int32_t value);

  std::string serialize() const;

  zstring show() const;

  bool isRemote() const {  return !isLocal(); }

protected:
  bool isLocal() const {  return theBuffer.local[MAX_EMBEDDED_BYTE] & 0x1; }

  void markLocal() { theBuffer.local[MAX_EMBEDDED_BYTE] |= 0x1; }

  void markRemote() { theBuffer.local[MAX_EMBEDDED_BYTE] &= 0xFE; }

  unsigned char* getRemoteBuffer() const 
  {
    return theBuffer.remote; 
  }

  void setRemoteBuffer(unsigned char* b)
  {
    theBuffer.remote = b; 
  }


  void reset() 
  {
    if (!isLocal())
      delete [] getRemoteBuffer();

    memset(theBuffer.local, 0, MAX_EMBEDDED_BYTE_LEN);
    markLocal();
  }


  void initRemote(ulong byteLen)
  {
    if (!isLocal())
      delete [] getRemoteBuffer();

    memset(theBuffer.local, 0, MAX_EMBEDDED_BYTE_LEN);

    setRemoteBuffer(new unsigned char[byteLen + 1]);
    memset(getRemoteBuffer(), 0, byteLen+1);
    getRemoteBuffer()[0] = (unsigned char)byteLen;
  }


  unsigned char* getDataAndLength(ulong& len) const
  {
    if (isLocal())
    {
      len = getLocalByteLength();
      return getLocalData();
    }
    else
    {
      len = getRemoteByteLength();
      return getRemoteData();
    }
  }


  unsigned char* getData() const
  {
    return (isLocal() ? getLocalData() : getRemoteData()); 
  }


  unsigned char* getLocalData() const
  {
    return const_cast<unsigned char*>(theBuffer.local);
  }


  unsigned char* getRemoteData() const
  {
    assert(!isLocal());
    return &getRemoteBuffer()[1]; 
  }


  ulong getByteLength() const
  {
    return (isLocal() ? getLocalByteLength() : getRemoteByteLength());
  }


  ulong getLocalByteLength() const
  {
    if (theBuffer.local[MAX_EMBEDDED_BYTE] != 1)
      return MAX_EMBEDDED_BYTE_LEN;

    for (long i = MAX_EMBEDDED_BYTE-1; i >= 0; --i)
    {
      if (theBuffer.local[i] != 0)
        return i+1;
    }

    return 0;
  }


  ulong getRemoteByteLength() const
  {
    return getRemoteBuffer()[0];
  }


  ulong getBitLength(ulong& byteLen) const
  {
    return (isLocal() ? getLocalBitLength(byteLen) : getRemoteBitLength(byteLen));
  }

  ulong getLocalBitLength(ulong& byteLen) const;

  ulong getRemoteBitLength(ulong& byteLen) const;

  bool compressLocal(const DeweyID& dewey);

  void compressRemote(const DeweyID& dewey);

  void decompress(
        ulong startOffset,
        int32_t* deweyid,
        ulong* compOffsets,
        ulong& numComps,
        ulong& bitSize) const;
};


/*******************************************************************************
  theNumComps      : The current number of components in the dewey id.

  theDeweyId       : Array containing the current, uncompressed dewey id.
  theCompLens      : Array containing the bit-length of each component.

  theBuffer        : Buffer containing the current, compressed ordpath.
  theByteIndex     : Position of the last byte of the ordpath within theBuffer.
  theBitsAvailable : The number of unsed bits in the last byte of the compressed
                     ordpath. Can range between 0 and 7.
********************************************************************************/
class OrdPathStack
{
  friend class OrdPath;

protected:
  ulong         theNumComps;

  int32_t       theDeweyId[OrdPath::MAX_NUM_COMPS];

  unsigned char theCompLens[OrdPath::MAX_NUM_COMPS];

  unsigned char theBuffer[OrdPath::MAX_BYTE_LEN];
  ulong         theByteIndex;
  ulong         theBitsAvailable;

public:
  OrdPathStack();

  ~OrdPathStack() { }

  void init();

  ulong getNumComps() const { return theNumComps; }
  
  ulong getByteLength() const;

  void pushChild();
  void popChild();
  void nextChild();

  std::string show() const;

private:
  OrdPathStack(const OrdPathStack& other);
  OrdPathStack& operator=(const OrdPathStack& other);

  void compressComp(ulong comp, int32_t value);
};


} // namespace store
} // namespace zorba

#endif /* ZORBA_STORE_ORDPATH_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
