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

#include "common/common.h"

namespace zorba { namespace store {
class OrdPathStack;


/*******************************************************************************

********************************************************************************/
class OrdPath
{
  friend class OrdPathStack;

protected:
  static const ulong MAX_BYTE_LEN = 256;
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
  unsigned char  * theBuffer;

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

public:
  OrdPath() : theBuffer(NULL) { }

  ~OrdPath() 
  {
    if (theBuffer != NULL)
    {
      delete [] theBuffer;
      theBuffer = NULL;
    }
  }

  bool isValid() const { return theBuffer != NULL; }

  void setAsRoot();

  OrdPath& operator=(const OrdPath& other);
  OrdPath& operator=(const OrdPathStack& ops);

  ulong getByteLength() const;
  ulong getBitLength() const;

  uint32_t hash() const;

  //bool operator==(const OrdPath& other) const;
  int operator<(const OrdPath& other) const;
  int operator>(const OrdPath& other) const;

  void compress(const std::vector<long>& dewey);

  void appendComp(long value);

  std::string show() const;

protected:
  static void bitsNeeded(
        long      value, 
        ulong&    bitsNeeded,
        uint32_t& eval);

  static void insertBeforeOrAfter(
        bool           before,
        const OrdPath& parent,
        const OrdPath& sibling,
        OrdPath&       result);

  void pushComp(long value, ulong& bitSize);

  void decompress(
        ulong   startOffset,
        long*   deweyid,
        ulong*  compOffsets,
        ulong&  numComps,
        ulong&  bitSize) const;

  void extractValue(
        ulong& bitSize,
        ulong& byteIndex,
        ulong& bitIndex,
        ulong  numBits,
        long   baseValue,
        long&  result) const;

  void decodeByte(
        long*          deweyid,
        ulong*         compOffsets,
        ulong&         numComps,
        ulong&         bitSize,
        ulong&         byteIndex,
        ulong&         bitIndex,
        unsigned char  byte) const;
};


/*******************************************************************************
  theNumComps      : The current number of components in the dewey id.

  theDeweyId       : Array containing the current, uncompressed dewey id.
  theCompLens      : Array containing the bit-length of each component.

  theBuffer        : Buffer containing the current, compressed ordpath.
  theByteIndex     :
  theBitsAvailable : The number of unsed bits in the last byte of the compressed
                     ordpath. Can range between 0 and 7.
********************************************************************************/
class OrdPathStack
{
  friend class OrdPath;

protected:
  ulong         theNumComps;

  long          theDeweyId[OrdPath::MAX_NUM_COMPS];

  unsigned char theCompLens[OrdPath::MAX_NUM_COMPS];

  unsigned char theBuffer[OrdPath::MAX_BYTE_LEN];
  ulong         theByteIndex;
  ulong         theBitsAvailable;

public:
  OrdPathStack();

  ~OrdPathStack() { }

  void init();

  ulong getNumComps() const   { return theNumComps; }
  
  ulong getByteLength() const;

  void pushChild();
  void popChild();
  void nextChild();

  std::string show() const;

private:
  OrdPathStack(const OrdPathStack& other);
  OrdPathStack& operator=(const OrdPathStack& other);

  void compressComp(ulong comp, long value);
};


} // namespace store
} // namespace zorba

#endif
