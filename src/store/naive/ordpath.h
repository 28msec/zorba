
#ifndef ZORBA_STORE_ORDPATH_H
#define ZORBA_STORE_ORDPATH_H

#include <vector>

#include <zorba/common/common.h>

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
        const OrdPath& p,
        OrdPath&       result);

  static void insertAfter(
        const OrdPath& p,
        OrdPath&       result);

  static void insertInto(
        const OrdPath& p1,
        const OrdPath& p2,
        OrdPath&       result);

public:
  OrdPath() : theBuffer(NULL) { }

  void init();

  OrdPath& operator=(const OrdPath& other);
  OrdPath& operator=(const OrdPathStack& ops);

  ~OrdPath() 
  {
    if (theBuffer != NULL)
    {
      delete [] theBuffer;
      theBuffer = NULL;
    }
  }

  ulong getByteLength() const;

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
        const OrdPath& p1,
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
