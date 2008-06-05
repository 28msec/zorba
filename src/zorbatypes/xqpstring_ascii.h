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
#ifndef ZORBA_XQPSTRING_ASCII_H
#define ZORBA_XQPSTRING_ASCII_H

#include "common/common.h"

#include <stdlib.h>
#include <iostream>
#include <vector>
#include <map>

#include "zorbatypes/zorbatypes_decl.h"
#include "zorbatypes/rchandle.h"
#include "zorbautils/checked_vector.h"

namespace zorba {

class xqpStringStore : public RCObject
{
  friend class xqpString;

  friend std::ostream& operator<<(std::ostream& os, const xqpStringStore& src);

public:
  typedef ptrdiff_t distance_type;

#ifndef ZORBA_FOR_ONE_THREAD_ONLY
protected:
  SYNC_CODE(mutable RCLock  theRCLock;)
#endif

protected:
  std::string  theString;

public:
  static bool
  is_whitespace(uint32_t cp);

  static uint32_t
  hash(const char* str);

  static bool
  is_unreservedCP(uint32_t cp);

  static bool
  is_ucscharCP(uint32_t cp);

  static bool
  is_iprivateCP(uint32_t cp);
  
  static bool
  is_printableASCII(uint32_t cp);
  
  static bool
  is_Invalid_in_IRI(uint32_t cp);

//  static xqpStringStore_t
//  getXqpString(UnicodeString source);

public:
  xqpStringStore() { }

  xqpStringStore(const char* start, const char* end) : theString(start, end) {}

  xqpStringStore(const char* start, long len) : theString(start, len) {}

  xqpStringStore(const std::string& other) : theString(other) {}

  xqpStringStore(const xqpStringStore &other) 
    :
    RCObject(other),
    theString(other.theString)
  {
  }

  long*
  getSharedRefCounter() const { return NULL; }  

  SYNC_CODE(RCLock* getRCLock() const { return &theRCLock; })


  void clear();

  const std::string& str() const { return theString; }

  const char* c_str() const { return theString.c_str(); }

  bool empty() const { return theString.empty(); }

  std::string::size_type bytes() const { return theString.size(); }

  std::string::size_type numChars() const;

  char byteAt (std::string::size_type i) const { return str () [i]; }

  uint32_t 
  hash(XQPCollator* = 0) const;

  bool
  byteEqual(const xqpStringStore& src) const;
      
  bool
  byteEqual(const char* src, uint32_t srcBytes) const;

  bool
  byteEqual(const char* src) const;


  // Three-way lexicographical comparison of s and a substring of *this
  int byteCompare (std::string::size_type pos, std::string::size_type n, const std::string &s) {
    return theString.compare (pos, n, s);
  }

  bool byteStartsWith (const std::string &s) {
    return byteCompare (0, s.size (), s) == 0;
  }

  // Three-way lexicographical comparison of a substring of s and a substring of *this
  int byteCompare (std::string::size_type pos, std::string::size_type n, const std::string &s, std::string::size_type pos1, std::string::size_type n1) {
    return theString.compare (pos, n, s, pos1, n1);
  }

  bool
  equals(const xqpStringStore* src) const
  {
    return ((this == src) || (compare(src, 0) == 0));
  }

  int
  compare(const xqpStringStore* src, XQPCollator* coll = 0) const;
  
  int32_t
  indexOf(const char* pattern) const;

  int32_t
  indexOf(const xqpStringStore* pattern, XQPCollator* col) const;

  int32_t
  lastIndexOf(const char* pattern) const;

  int32_t
  lastIndexOf(const xqpStringStore* pattern, XQPCollator* coll) const;

  bool
  endsWith(const char* pattern) const;

  bool
  endsWith(const xqpStringStore* pattern, XQPCollator* col) const;

  xqpStringStore_t
  append(const xqpStringStore_t& suffix) const;

  xqpStringStore_t
  append(const std::string& suffix) const;

  xqpStringStore_t
  append(const char* suffix) const;

  void append_in_place(const char c);

  void append_in_place(xqpStringStore *suffix);

  xqpStringStore_t
  substr(std::string::size_type index, std::string::size_type length) const;

  xqpStringStore_t
  uppercase() const;
      
  xqpStringStore_t
  lowercase() const;

  xqpStringStore_t
  normalizeSpace() const;

  xqpStringStore_t
  trimL() const;

  xqpStringStore_t
  trimL(const char* start, uint16_t len) const;

  xqpStringStore_t
  trimR() const;

  xqpStringStore_t
  trimR(const char* start, uint16_t len) const;

  xqpStringStore_t
  trim() const;

  xqpStringStore_t
  trim(const char* start, uint16_t len) const;

  xqpStringStore_t
  formatAsXML() const;

  xqpStringStore_t
  escapeHtmlUri() const;

  xqpStringStore_t
  iriToUri() const;

  xqpStringStore_t
  encodeForUri() const;

  xqpStringStore_t
  normalize(const xqpStringStore* normMode) const;

//  UnicodeString
//  getUnicodeString() const;

  checked_vector<uint32_t>
  getCodepoints() const;

};


  class xqpString
  {
  public:
    xqpStringStore_t theStrStore;

    typedef std::string::size_type  size_type;

    //constructor/destructor
    /**Construct an empty xqpString
     */
    xqpString();

    /**Construct a xqpString as a copy of another xqpString
     * @param src A source UTF-8 encoded string
     */
    xqpString(const xqpString& other) : theStrStore(other.theStrStore) {}

    /**Construct a xqpString as a wrapper of an existing xqpStringStore
     * @param src A source UTF-8 encoded string
     */
    xqpString(xqpStringStore* other) : theStrStore(other) {}

    /**Construct a xqpString given a std::string
     * @param src A source std::string containin ASCII characters
     */
    xqpString(const std::string& src);

    /**Construct a xqpString as a copy of a C string.
     * @param src %Source C string that is encoded as UTF-8
     */
    xqpString(const char* src);

    ~xqpString(){};

    xqpStringStore* 
    getStore() const { return theStrStore.getp(); }

    xqpString&
    operator=(xqpString src)
    {
      theStrStore = src.theStrStore;
      return *this;
    }

    xqpString&
    operator=(const std::string& src);
      
    xqpString&
    operator=(const char* src);
    
    /**@param cp Codepoint
     */
    xqpString&
    operator=(uint32_t cp);
      
    xqpString&
    operator=(char c);
    
    xqpString&
    operator+=(xqpString src);
      
    xqpString&
    operator+=(const char* src);
      
    /** @param cp Codepoint
     */
    xqpString&
    operator+=(uint32_t cp);
      
    xqpString&
    operator+=(char c);

    void append_in_place(const char c);

    bool
    operator==(xqpString src) const
    {
      return (compare(src) == 0);
    }

    bool
    operator==(const char* src) const
    {
      return (compare(src) == 0);
    }

    bool
    operator!=(xqpString src) const
    {
      return (compare(src) != 0);
    }

    bool
    operator!=(const char* src) const
    {
      return (compare(src) != 0);
    }

    bool
    operator<(xqpString src) const
    {
      return compare(src) == -1;
    }

    bool
    operator>(xqpString src) const
    {
      return compare(src) == 1;
    }

    int
    compare(xqpString src, XQPCollator* coll = 0) const
    {
      return theStrStore->compare(src.theStrStore, coll);
    }

    int
    compare(const char* src, XQPCollator* = 0) const;

    /**
     * Returns true if the strings are equal based on a byte-by-byte comparison.
     * It assumes that both strings are already normalized.
     */
    bool
    byteEqual(xqpString src) const
    {
      return theStrStore->byteEqual(*src.getStore());
    }
    
    bool
    byteEqual(const char* src, uint32_t srcLen) const
    {
      return theStrStore->byteEqual(src, srcLen);
    }
    
    uint32_t
    hash(XQPCollator* = 0) const;

    // xqpString::Length
    /**
     * @return the number of unicode characters (without the null termination)
     */
    size_type 
    length() const { return theStrStore->numChars(); }

    /** 
     * @return the number of unicode characters (without the null termination)
     */
    size_type 
    size() const { return theStrStore->numChars(); }

    /**
     * @return the number of bytes (without the null termination)
     */
    size_type 
    bytes() const { return theStrStore->bytes(); }

    /** @return true is the xqpString is empty
     */
    bool
    empty() const { return theStrStore->empty(); }

    // xqpString::Clear
    void 
    clear();

    /**Locate in this the first occurrence in the range [0, length) of the characters in pattern using the "Default collation".
     *  @param pattern The text to search for.
     *  @return The offset into this of the start of pattern, or -1 if not found.
     */
    int32_t
    indexOf(xqpString pattern, XQPCollator* col = 0) const
    {
      return theStrStore->indexOf(pattern.getStore(), col);
    }

    /**Locate in this the last occurrence in the range [0, length) of the characters in pattern using the "Default collation".
     *  @param pattern The text to search for.
     *  @return The offset into this of the start of pattern, or -1 if not found.
     */
    int32_t
    lastIndexOf(xqpString pattern, XQPCollator* coll = 0) const
    {
      return theStrStore->lastIndexOf(pattern.getStore(), coll);
    }

    /**Determine if this ends with the characters in pattern in the range [0, length).
     *  @param pattern The text to search for.
     */
    bool
    endsWith(xqpString pattern, XQPCollator* coll = 0) const
    {
      return theStrStore->endsWith(pattern.getStore(), coll);
    }

    /**Returns a substring of the current string, starting at index, and length characters long.
     */
    xqpString
    substr(size_type index, size_type length) const;

    /**Returns a substring of the currents string starting at index and continues untill the NULL termination.
     *Doesn't use ICU4C
     */
    xqpString
    substr(xqpStringStore::distance_type index) const;

    xqpString
    formatAsXML() const
    {
      return theStrStore->formatAsXML().getp();
    }
      
    const char*
    c_str() const;

    inline operator std::string() const
    {
      return theStrStore->theString;
    }

//    UnicodeString
//    getUnicodeString() const
//    {
//      return theStrStore->getUnicodeString();
//    }

//    std::vector<uint32_t>
//    getCodepoints() const
//    {
//      return theStrStore->getCodepoints();
//    }

    //uppercase/lowercase
    xqpString
    uppercase() const
    {
      return theStrStore->uppercase().getp();
    }

    xqpString
    lowercase() const
    {
      return theStrStore->lowercase().getp();
    }

    //normalization
    xqpString
    normalize(xqpString normMode);

    //escape all characters except for those :
    //Upper and lowercase letters A-Z
    //digits 0-9, HYPHEN-MINUS ("-"), LOW LINE ("_"), FULL STOP ".", and TILDE "~"
    xqpString
    encodeForUri() const
    {
      return theStrStore->encodeForUri().getp();
    }

    //This function converts an xs:string containing an IRI into a URI according to the
    //rules spelled out in Section 3.1 of http://www.ietf.org/rfc/rfc3987.txt
    xqpString
    iriToUri() const
    {
      return theStrStore->iriToUri().getp();
    }

    //This function escapes all characters except printable characters of the US-ASCII
    //coded character set, specifically the octets ranging from 32 to 126 (decimal)
    xqpString
    escapeHtmlUri() const
    {
      return theStrStore->escapeHtmlUri().getp();
    }
    
    //Returns an xqpString modified so that every character in that occurs at some position N
    //in the value of $mapString has been replaced by the character that occurs at position N
    //in the value of $transString.
    //Every character from 'this' that does not occur in the mapString is left unchanged
    xqpString
    translate(xqpString mapString, xqpString transString) const;

    //Returns a new xqpString by stripping leading and trailing whitespace
    //and replacing sequences of one or more than one whitespace character with a single space, #x20.
    xqpString
    normalizeSpace() const
    {
      return theStrStore->normalizeSpace().getp();
    }
    
    //Removes the leading whitespaces (#x20).
    xqpString
    trimL() const
    {
      return theStrStore->trimL().getp();
    }

    //removes leading characters defined by start and len
    xqpString
    trimL(const char* start, uint16_t len) const
    {
      return theStrStore->trimL(start, len).getp();
    }

    //Removes the trailing whitespaces (#x20).
    xqpString
    trimR() const
    {
      return theStrStore->trimR().getp();
    }

    //removes trailing characters defined by start and len
    xqpString
    trimR(const char* start, uint16_t len) const
    {
      return theStrStore->trimR(start, len).getp();
    }

    //Removes the leading and trailing whitespaces (#x20).
    xqpString
    trim() const
    {
      return theStrStore->trim().getp();
    }
    
    //removes leading and trailing characters defined by start and len
    xqpString
    trim(const char* start, uint16_t len) const
    {
      return theStrStore->trim(start, len).getp();
    }
    
      bool
      matches(xqpString pattern, xqpString flags);

      xqpString
      replace(xqpString pattern, xqpString replacement, xqpString flags);

      xqpString
      tokenize(xqpString pattern, xqpString flags, xqpString *remaining);

      // Removes the leading and trailing whitespace (one of the " \t\r\n")
      // TODO: xqpString trim_whitespace() const;

      /**
       * Create and return an xqpString from an UTF-16 encoded string
       */
//      static xqpString
//      fromUTF16(const UChar* src, int32_t len);

    private:

  
      /**  Return a sequence of wchar_t units given a xqpString (UTF-8 encoded)
       */
//      wchar_t * 
//      getWCS(xqpString source) const;

      /**Sets the capacity of the string to at least size
       */
      void
      reserve(size_type size=0);

      /**Create a map with:
       *-the codepoints of the chars from 'mapString' as first dimension
       *-the codepoints of the chars from 'transString' as second dimension or 0xFFFFFFFF
       *if length(mapString) \< length(transString)
       *Only the first occurence of a character from mapString is inserted into the mapArray
       */
      std::map<uint32_t,uint32_t> 
      createMapArray(xqpString mapString, xqpString transString) const;
  };


  // xqpString::stream I/O operators
  std::istream& 
  operator>>(std::istream& is, zorba::xqpString utf8_src);
  
  std::ostream& 
  operator<<(std::ostream& os, const zorba::xqpStringStore& src);

  std::ostream& 
  operator<<(std::ostream& os, const zorba::xqpStringStore_t src);

  std::ostream& 
  operator<<(std::ostream& os, zorba::xqpString utf8_src);

  //xqpString::concatenation operator+()
  inline xqpString
  operator+(xqpString lsrc, xqpString rsrc)
  {
    xqpString tmp (lsrc);
    tmp += rsrc;
    return tmp;
  }

  inline xqpString
  operator+(xqpString& lsrc, const char* rsrc)
  {
    xqpString tmp (lsrc);
    tmp += rsrc;
    return tmp;
  }

  inline xqpString
  operator+(const char* lsrc, xqpString rsrc)
  {
    xqpString tmp (lsrc);
    tmp += rsrc;
    return tmp;
  }


} /* namespace zorba */

#endif
/*
 * Local variables:
 * mode: c++
 * End:
 */
