#ifndef ZORBA_XQPSTRING_H
#define ZORBA_XQPSTRING_H

#include "common/common.h"
#include "common/libicu.h"

#include <stdlib.h>
#include <iostream>
#include <vector>
#include <map>

#include "zorbatypes/zorbatypes_decl.h"
#include "util/rchandle.h"

namespace zorba {

  class xqpStringStore : public RCObject, public std::string
  {
#ifndef ZORBA_FOR_ONE_THREAD_ONLY
  protected:
    SYNC_CODE(mutable RCLock  theRCLock;)
#endif

    public:
      xqpStringStore() { }
      xqpStringStore(const xqpStringStore &other) : RCObject(other), std::string(other) {}
      xqpStringStore(const std::string& other) : std::string(other) {}
      xqpStringStore(const char* start, const char* end) : std::string(start, end) {}
      xqpStringStore(const char* start, long len) : std::string(start, len) {}

      long*
      getSharedRefCounter() const { return NULL; }  

      SYNC_CODE(RCLock* getRCLock() const { return &theRCLock; })

      std::string::size_type bytes() const { return size(); }

      /**
       * djb2 Hash function
       */
      uint32_t 
      hash() const;

      static uint32_t
      hash(const char* str);

      bool
      byteEqual(const xqpStringStore& src) const;
      
      bool
      byteEqual(const char* src, uint32_t srcLen) const;
  };

  class xqpString
  {
    public:
      xqpStringStore_t theStrStore;

      typedef std::string::size_type  size_type;
      typedef ptrdiff_t distance_type;

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
      compare(xqpString src, XQPCollator* = 0) const;

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
      hash() const { return theStrStore->hash(); }

      // xqpString::Length
      /** @return the number of unicode characters (without the null termination)
       */
      size_type 
      length() const;

      /** @return the number of unicode characters (without the null termination)
       */
      size_type 
      size() const;

      /**
       * @return the number of bytes (without the null termination)
       */
      size_type 
      bytes() const { return theStrStore->bytes(); }

      /** @return true is the xqpString is empty
       */
      bool
      empty()  const;

      // xqpString::Clear
      void 
      clear();

      // xqpString::Codepoints()
      std::vector<uint32_t> getCodepoints 
      () const;

      // xqpString::Substring()
      /**Locate in this the first occurrence in the range [0, length) of the characters in pattern using the "Default collation".
       *  @param pattern The text to search for.
       *  @return The offset into this of the start of pattern, or -1 if not found.
       */
      int32_t
      indexOf(xqpString pattern, XQPCollator* = 0) const;

      /**Locate in this the last occurrence in the range [0, length) of the characters in pattern using the "Default collation".
       *  @param pattern The text to search for.
       *  @return The offset into this of the start of pattern, or -1 if not found.
       */
      int32_t
      lastIndexOf(xqpString pattern, XQPCollator* = 0) const;

      /**Determine if this ends with the characters in pattern in the range [0, length).
       *  @param pattern The text to search for.
       */
      bool
      endsWith(xqpString pattern, XQPCollator* = 0) const;

      /**Returns a substring of the current string, starting at index, and length characters long.
       */
      xqpString
      substr(size_type index, size_type length) const;

      /**Returns a substring of the currents string starting at index and continues untill the NULL termination.
       *Doesn't use ICU4C
       */
      xqpString
      substr(distance_type index) const;

      xqpString
      formatAsXML(const char* src) const;
      
      const char*
      c_str() const;

      inline  operator std::string() const
      {
        return *theStrStore;
      }

      //uppercase/lowercase
      xqpString
      uppercase();
      
      xqpString
      lowercase();

      //normalization
      xqpString
      normalize(xqpString normMode);

      //escape all characters except for those :
      //Upper and lowercase letters A-Z
      //digits 0-9, HYPHEN-MINUS ("-"), LOW LINE ("_"), FULL STOP ".", and TILDE "~"
      xqpString
      encodeForUri() const;

      //This function converts an xs:string containing an IRI into a URI according to the
      //rules spelled out in Section 3.1 of http://www.ietf.org/rfc/rfc3987.txt
      xqpString
      iriToUri() const;

      //This function escapes all characters except printable characters of the US-ASCII
      //coded character set, specifically the octets ranging from 32 to 126 (decimal)
      xqpString
      escapeHtmlUri() const;

      //Returns an xqpString modified so that every character in that occurs at some position N
      //in the value of $mapString has been replaced by the character that occurs at position N
      //in the value of $transString.
      //Every character from 'this' that does not occur in the mapString is left unchanged
      xqpString
      translate(xqpString mapString, xqpString transString) const;

      //Returns a new xqpString by stripping leading and trailing whitespace
      //and replacing sequences of one or more than one whitespace character with a single space, #x20.
      xqpString
      normalizeSpace() const;

      //Removes the leading whitespaces (#x20).
      xqpString
      trimL() const;

      //Removes the trailing whitespaces (#x20).
      xqpString
      trimR() const;

      //Removes the leading and trailing whitespaces (#x20).
      xqpString
      trim() const;

      //removes leading characters defined by start and len
      xqpString
      trimL(const char* start, uint16_t len) const;

      //removes trailing characters defined by start and len
      xqpString
      trimR(const char* start, uint16_t len) const;

      //removes leading and trailing characters defined by start and len
      xqpString
      trim(const char* start, uint16_t len) const;

      // Removes the leading and trailing whitespace (one of the " \t\r\n")
      // TODO: xqpString trim_whitespace() const;

      /**
       * Return an UnicodeString (UTF-16 encoded) version of the string
       */
      UnicodeString
      getUnicodeString() const;

      /**
       * Create and return an xqpString from an UTF-16 encoded string
       */
      static xqpString
      fromUTF16(const UChar* src, int32_t len);

    private:

      /**  Return an UnicodeString (UTF-16 encoded) given a xqpString (UTF-8 encoded)
       */
      UnicodeString
      getUnicodeString(xqpString source) const;

      /**  Return a xqpString (UTF-8 encoded) given an UnicodeString (UTF-16 encoded)
       */
      xqpString
      getXqpString(UnicodeString source) const;

      /**  Return a sequence of wchar_t units given a xqpString (UTF-8 encoded)
       */
      wchar_t * 
      getWCS(xqpString source) const;

      /**Sets the capacity of the string to at least size
       */
      void
      reserve(size_type size=0);

      /**Returns true is cp reprezents "unreserved" as defined by rfc3986
       */
      bool
      is_unreservedCP(uint32_t cp) const;

      /**Returns true is cp reprezents "ucschar" as defined by rfc3987
       */
      bool
      is_ucscharCP(uint32_t cp) const;

      /**Returns true for the following printable ASCII characters that are
      *invalid in an IRI: "<", ">", " " " (double quote), space, "{", "}", "|", "\", "^", and "`".
      */
      bool
      is_Invalid_in_IRI(uint32_t cp) const;

      /**Returns true is cp reprezents "iprivate" as defined by rfc3987
       */
      bool
      is_iprivateCP(uint32_t cp) const;

      /**Returns true if cp is a printable characters of the US-ASCII coded
       *character set meaning octets ranging from 32 to 126 (decimal).
       */
      bool
      is_printableASCII(uint32_t cp) const;

      /**
       * Returns true if cp is a whitespace (one of the " \t\r\n")
       */
      bool
      is_whitespace(uint32_t cp) const;

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
