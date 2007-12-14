
#ifndef XQP_STORE_NODEID
#define XQP_STORE_NODEID

#include <vector>
#include "types/representations.h"

namespace xqp
{
class OrdPathStack;


/*******************************************************************************

********************************************************************************/
class OrdPath
{
  friend class OrdPathStack;

protected:
  static const unsigned long MAX_BYTE_LEN = 256;
  static const unsigned long MAX_NUM_COMPS = MAX_BYTE_LEN * 4;

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
  unsigned long       theTreeId;

  unsigned char     * theBuffer;

public:
  OrdPath() : theTreeId(0), theBuffer(NULL) { }

  void init(unsigned long treeid);

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

  bool isValid() const              { return theTreeId != 0; }

  unsigned long getByteLength() const;

  unsigned long getTreeId() const   { return theTreeId; }
  void setTreeId(unsigned long tid) { theTreeId = tid; }

  bool operator==(const OrdPath& other) const;
  int operator<(const OrdPath& other) const;
  int operator>(const OrdPath& other) const;

  void appendComp(long value);

  void decompress(long* deweyid, unsigned long& deweylen) const;

  xqp_string show() const;

protected:
  void extractValue(
        unsigned long& byteIndex,
        unsigned long& bitIndex,
        unsigned long  numBits,
        long           baseValue,
        long&          result) const;

  void decodeByte(
        long*          deweyid,
        unsigned long& numComps,
        unsigned long& byteIndex,
        unsigned long& bitIndex,
        unsigned char  byte) const;
};


/*******************************************************************************
  theNumComps      : The current number of components in the dewey id.

  theDeweyId       : Array containing the current, uncompressed dewey id.
  theCompLens      : Array containing the bit-length of each component.

********************************************************************************/
class OrdPathStack
{
  friend class OrdPath;

 protected:
  unsigned long       theTreeId;

  unsigned long       theNumComps;

  long                theDeweyId[OrdPath::MAX_NUM_COMPS];

  unsigned char       theCompLens[OrdPath::MAX_NUM_COMPS];

  unsigned char       theBuffer[OrdPath::MAX_BYTE_LEN];
  unsigned long       theByteIndex;
  unsigned long       theBitsAvailable;

public:
  OrdPathStack();

  ~OrdPathStack() { }

  void init(unsigned long treeid);

  bool isValid() const                { return theTreeId != 0; }

  unsigned long getTreeId() const     { return theTreeId; }
  unsigned long getNumComps() const   { return theNumComps; }
  
  unsigned long getByteLength() const;

  void pushChild();
  void popChild();
  void nextChild();

  xqp_string show() const;

private:
  OrdPathStack(const OrdPathStack& other);
  OrdPathStack& operator=(const OrdPathStack& other);

  void compressComp(unsigned long comp, long value);
};


}

#endif
