/**
 * @copyright
 * ========================================================================
 *  Copyright FLWOR Foundation
 * ========================================================================
 *
 * @author Sorin Nasoi (sorin.nasoi@ipdevel.ro)
 * @author Nicolae Brinza (nicolae.brinza@ipdevel.ro)
 * @author Dan Muresan (dan.muresan@ipdevel.ro)
 * @file util/utf8/xqpString.h
 *
 */

#ifndef XQP_STRING
#define XQP_STRING

#ifdef WIN32
#include "util/win32/compatib_defs.h"
#endif

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <map>

#include <unicode/utypes.h>
#include <unicode/coll.h>
#include <unicode/ustring.h>
#include <unicode/stsearch.h>
#include <unicode/ucnv.h>
#include <unicode/normlzr.h>

#include "util/rchandle.h"

namespace xqp {

class xqpStringStore;
typedef rchandle<xqpStringStore> xqpStringStore_t;


class xqpStringStore : public rcobject, public std::string
{
public:
  xqpStringStore() { }
  xqpStringStore(const xqpStringStore &other) : rcobject(other), std::string(other) {}
  xqpStringStore(const std::string& other) : std::string(other) {}
  xqpStringStore(const char* start, const char* end) : std::string(start, end) {}
  xqpStringStore(const char* start, long len) : std::string(start, len) {}

  std::string::size_type bytes() const { return size(); }

  /**
   * djb2 Hash function
   */
  uint32_t hash() const;

  static uint32_t hash(const char* str);

  bool byteEqual(const xqpStringStore& src) const;
  bool byteEqual(const char* src, uint32_t srcLen) const;

  bool hashEqual(const xqpStringStore& src) const;
};

  class xqpString
  {
  public:
    rchandle<xqpStringStore> theStrStore;

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
    xqpString(const xqpStringStore_t& other) : theStrStore(other.get_ptr()) {}

    /**Construct a xqpString given a std::string
     * @param src A source std::string containin ASCII characters
     */
    xqpString(const std::string& src);

    /**Construct a xqpString as a copy of a C string.
     * @param src %Source C string that is encoded as UTF-8
     */
    xqpString(const char* src);

    ~xqpString(){};

    xqpStringStore& getStore() const { return *(theStrStore.get_ptr()); }

    //xqpString::operator=()
    xqpString&operator=(xqpString src)
    {
      theStrStore = src.theStrStore;
      return *this;
    }
    xqpString& operator=(const std::string& src);
    xqpString& operator=(const char* src);
    /**@param cp Codepoint
    */
    xqpString& operator=(uint32_t cp);
    xqpString& operator=(char c);

    //xqpString::operator+=()
    xqpString& operator+=(xqpString src);
    xqpString& operator+=(const char* src);
    /** @param cp Codepoint
    */
    xqpString& operator+=(uint32_t cp);
    xqpString& operator+=(char c);

    //xqpString::operator==()
    inline bool operator==(xqpString src) const{
      return (compare(src) == 0);
    }

    inline bool operator==(const char* src) const{
      return (compare(src) == 0);
    }

    //xqpString::operator!=()
    inline bool operator!=(xqpString src) const{
      return (compare(src) != 0);
    }

    inline bool operator!=(const char* src) const{
      return (compare(src) != 0);
    }

    // xqpString::operator<()
    inline bool operator<(xqpString src) const {
      return compare(src) == -1;
    }

    // xqpString::operator>()
    inline bool operator>(xqpString src) const {
      return compare(src) == 1;
    }

    //xqpString::Compare
    int compare(xqpString src) const;

    /** Compare 2 strings based on a specific collation for a locale.
    *  @param loc locale as lowercase two-letter or three-letter ISO-639 code. In ICU4C one can also send something like "de_ch".
    * http://www.loc.gov/standards/iso639-2/ has a list of language codes (de stands for German language)
    * http://www.iso.org/iso/en/prods-services/iso3166ma/index.html a list of countries (ch stands for Switzerland)
    */
    int compare(xqpString src, const char * loc) const;
    int compare(const char* src) const;

    /**
     * Returns true if the strings are equal based on a byte-by-byte comparison.
     * It assumes that both strings are already normalized.
     */
    bool byteEqual(xqpString src) const
    {
      if (theStrStore.get_ptr() == src.theStrStore.get_ptr())
        return true;

      return theStrStore->byteEqual(src.getStore());
    }

    bool byteEqual(const char* src, uint32_t srcLen) const
    {
      return theStrStore->byteEqual(src, srcLen);
    }

    /**
     * Returns true if the hash of the strings are equal and if the strings
     * are byteEqual. It assumes that both strings are already normalized.
     */
    bool hashEqual(xqpString src) const
    {
      if (theStrStore.get_ptr() == src.theStrStore.get_ptr())
        return true;

      return theStrStore->hashEqual(src.getStore());
    }

    uint32_t hash() const { return theStrStore->hash(); }

    // xqpString::Length
    /** @return the number of unicode characters (without the null termination)
    */
    size_type length() const;

    /** @return the number of unicode characters (without the null termination)
    */
    size_type size() const;

    /**
     * @return the number of bytes (without the null termination)
     */
    size_type bytes() const { return theStrStore->bytes(); }

    /** @return true is the xqpString is empty
    */
    bool empty()  const;

    // xqpString::Clear
    void clear();

    // xqpString::Codepoints()
    std::vector<uint32_t> getCodepoints();

    // xqpString::Substring()
    /**Locate in this the first occurrence in the range [0, length) of the characters in pattern using the "Default collation".
    *  @param pattern The text to search for.
    *  @return The offset into this of the start of pattern, or -1 if not found.
    */
    int32_t indexOf(xqpString pattern);

    /**Locate in this the first occurrence in the range [0, length) of the characters in pattern using the a collation created using the provided locale.
    *  @param pattern The text to search for.
    *  @param loc The locale ID for which to open a collator.
    *  @return The offset into this of the start of pattern, or -1 if not found.
    */
    int32_t indexOf(xqpString pattern, const char * loc);

    /**Locate in this the last occurrence in the range [0, length) of the characters in pattern using the "Default collation".
    *  @param pattern The text to search for.
    *  @return The offset into this of the start of pattern, or -1 if not found.
    */
    int32_t lastIndexOf(xqpString pattern);

    /**Locate in this the last occurrence in the range [0, length) of the characters in pattern using the "Default collation".
    *  @param pattern The text to search for.
    *  @param loc The locale ID for which to open a collator.
    *  @return The offset into this of the start of pattern, or -1 if not found.
    */
    int32_t lastIndexOf(xqpString pattern, const char * loc);

    /**Determine if this ends with the characters in pattern in the range [0, length).
    *  @param pattern The text to search for.
    */
    bool endsWith(xqpString pattern);

    /**Determine if this ends with the characters in pattern in the range [0, length).
    *  @param pattern The text to search for.
    *  @param loc The locale ID for which to open a collator.
    */
    bool endsWith(xqpString pattern, const char * loc);

    /**Returns a substring of the current string, starting at index, and length characters long.
    */
    xqpString substr(size_type index, size_type length);

    /**Returns a substring of the currents string starting at index and continues untill the NULL termination.
    *Doesn't use ICU4C
    */
    xqpString substr(distance_type index);
    const char* c_str() const;

    inline  operator std::string() const{
      return *theStrStore;
    }

    //uppercase/lowercase
    xqpString uppercase();
    xqpString lowercase();

    //normalization
    xqpString normalize(xqpString normMode);

    //escape all characters except for those :
    //Upper and lowercase letters A-Z
    //digits 0-9, HYPHEN-MINUS ("-"), LOW LINE ("_"), FULL STOP ".", and TILDE "~"
    xqpString encodeForUri();

    //This function converts an xs:string containing an IRI into a URI according to the
    //rules spelled out in Section 3.1 of http://www.ietf.org/rfc/rfc3987.txt
    xqpString iriToUri();

    //This function escapes all characters except printable characters of the US-ASCII
    //coded character set, specifically the octets ranging from 32 to 126 (decimal)
    xqpString escapeHtmlUri();

    //Returns an xqpString modified so that every character in that occurs at some position N
    //in the value of $mapString has been replaced by the character that occurs at position N
    //in the value of $transString.
    //Every character from 'this' that does not occur in the mapString is left unchanged
    xqpString translate(xqpString mapString, xqpString transString);

    //Returns a new xqpString by stripping leading and trailing whitespace
    //and replacing sequences of one or more than one whitespace character with a single space, #x20.
    xqpString normalizeSpace();

private:

    /**  Return an UnicodeString (UTF-16 encoded) given a xqpString (UTF-8 encoded)
    */
    UnicodeString getUnicodeString(xqpString source) const;
    /**  Return a xqpString (UTF-8 encoded) given an UnicodeString (UTF-16 encoded)
    */
    xqpString getXqpString(UnicodeString source);

    /**  Return a sequence of wchar_t units given a xqpString (UTF-8 encoded)
    */
    wchar_t * getWCS(xqpString source) const;

    /**Sets the capacity of the string to at least size
    */
    void reserve(size_type size=0);

    /**Returns true is cp reprezents "unreserved" as defined by rfc3986
    */
    bool is_unreservedCP(uint32_t cp);

    /**Returns true is cp reprezents "ucschar" as defined by rfc3987
    */
    bool is_ucscharCP(uint32_t cp);

    /**Returns true is cp reprezents "iprivate" as defined by rfc3987
    */
    bool is_iprivateCP(uint32_t cp);

    /**Returns true if cp is a printable characters of the US-ASCII coded
    *character set meaning octets ranging from 32 to 126 (decimal).
    */
    bool is_printableASCII(uint32_t cp);

    /**Returns true if cp is sapce 32 (decimal).
    */
    bool is_space(uint32_t cp);

    /**Create a map with:
    *-the codepoints of the chars from 'mapString' as first dimension
    *-the codepoints of the chars from 'transString' as second dimension or ULONG_MAX
    *if length(mapString) \< length(transString)
    *Only the first occurence of a character from mapString is inserted into the mapArray
     */
    std::map<uint32_t,uint32_t> createMapArray(xqpString mapString, xqpString transString);
  };

  // xqpString::stream I/O operators
  std::istream& operator>>(std::istream& is, xqp::xqpString utf8_src);
  std::ostream& operator<<(std::ostream& os, xqp::xqpString utf8_src);

  //xqpString::concatenation operator+()
  inline xqpString operator+(xqpString lsrc, xqpString rsrc){
    xqpString tmp (lsrc);
    tmp += rsrc;
    return tmp;
  }

  inline xqpString operator+(xqpString& lsrc, const char* rsrc){
    xqpString tmp (lsrc);
    tmp += rsrc;
    return tmp;
  }

  inline xqpString operator+(const char* lsrc, xqpString rsrc){
    xqpString tmp (lsrc);
    tmp += rsrc;
    return tmp;
  }

}/* namespace xqp */

#endif

