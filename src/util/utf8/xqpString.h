/**
 * @copyright
 * ========================================================================
 *  Copyright FLWOR Foundation
 * ========================================================================
 *
 * @author Sorin Nasoi (sorin.nasoi@ipdevel.ro)
 * @author Nicolae Brinza (nicolae.brinza@ipdevel.ro)
 * @author Dan Muresan (dan.muresan@ipdevel.ro)
 * @file utf8/xqpString.h
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

#include <unicode/utypes.h>
#include <unicode/coll.h>
#include <unicode/ustring.h>
#include <unicode/stsearch.h>
#include <unicode/ucnv.h>

#include "util/rchandle.h"

using namespace std;
namespace xqp {

  class xqpString_t : public rcobject, public string  {
  public:
    xqpString_t (const xqpString_t &other) : rcobject (other), string (other) {}
    xqpString_t (const std::string& other) : string(other) {}
  };

  class xqpString
  {
  public:
    typedef rchandle<xqpString_t> xqpString_h;
    typedef std::string::size_type  size_type;
    typedef ptrdiff_t distance_type;
    xqpString_h utf8String;
    //constructor/destructor
    /**Construct an empty xqpString
    */
    xqpString();

    /**Construct a xqpString as a copy of another xqpString
    * @param src A source UTF-8 encoded string
    */
    xqpString (const xqpString &other)
    :
    utf8String (other.utf8String) {}

    /**Construct a xqpString given a std::string
    * @param src A source std::string containin ASCII characters
    */
    xqpString(const std::string& src);

    /**Construct a xqpString as a copy of a C string.
    * @param src %Source C string that is encoded as UTF-8
    */
    xqpString(const char* src);

    ~xqpString();

    //xqpString::operator=()
    xqpString&operator=(const xqpString& src) { utf8String = src.utf8String; return *this;}
    xqpString& operator=(const std::string& src);
    xqpString& operator=(const char* src);
    /**@param cp Codepoint
    */
    xqpString& operator=(uint32_t cp);
    xqpString& operator=(char c);

    //xqpString::operator+=()
    xqpString& operator+=(const xqpString& src);
    xqpString& operator+=(const char* src);
    /** @param cp Codepoint
    */
    xqpString& operator+=(uint32_t cp);
    xqpString& operator+=(char c);

    //xqpString::operator==()
    inline bool operator==(const xqpString& src) const{
      return (compare(src) == 0);
    }

    inline bool operator==(const char* src) const{
      return (compare(src) == 0);
    }

    //xqpString::operator!=()
    inline bool operator!=(const xqpString& src) const{
      return (compare(src) != 0);
    }

    inline bool operator!=(const char* src) const{
      return (compare(src) != 0);
    }

    // xqpString::operator<()
    inline bool operator<(const xqpString& src) const {
      return compare(src) == -1;
    }

    // xqpString::operator>()
    inline bool operator>(const xqpString& src) const {
      return compare(src) == 1;
    }

    //xqpString::Compare
    int compare(const xqpString& src) const;

    /** Compare 2 strings based on a specific collation for a locale.
    *  @param loc locale as lowercase two-letter or three-letter ISO-639 code. In ICU4C one can also send something like "de_ch".
    * http://www.loc.gov/standards/iso639-2/ has a list of language codes (de stands for German language)
    * http://www.iso.org/iso/en/prods-services/iso3166ma/index.html a list of countries (ch stands for Switzerland)
    */
    int compare(const xqpString& src, const char * loc) const;
    int compare(const char* src) const;

    // xqpString::Length
    /** @return the number of unicode characters (without the null termination)
    */
    size_type length() const;

    /** @return the number of unicode characters (without the null termination)
    */
    size_type size() const;

    /** @return the number of bytes (without the null termination)
    */
    size_type bytes() const;

    /** @return true is the xqpString is empty
    */
    bool empty()  const;

    /**Sets the capacity of the string to at least size
    */
    void reserve(size_type size=0);

    // xqpString::Clear
    void clear();

    // xqpString::Codepoints()
    std::vector<uint32_t> getCodepoints();

    // xqpString::Substring()
    /**Locate in this the first occurrence in the range [0, length) of the characters in pattern using the "Default collation".
    *  @param pattern The text to search for.
    *  @return The offset into this of the start of pattern, or -1 if not found.
    */
    int32_t indexOf(const xqpString& pattern);

    /**Locate in this the first occurrence in the range [0, length) of the characters in pattern using the a collation created using the provided locale.
    *  @param pattern The text to search for.
    *  @param loc The locale ID for which to open a collator.
    *  @return The offset into this of the start of pattern, or -1 if not found.
    */
    int32_t indexOf(const xqpString& pattern, const char * loc);

    /**Locate in this the last occurrence in the range [0, length) of the characters in pattern using the "Default collation".
    *  @param pattern The text to search for.
    *  @return The offset into this of the start of pattern, or -1 if not found.
    */
    int32_t lastIndexOf(const xqpString& pattern);

    /**Locate in this the last occurrence in the range [0, length) of the characters in pattern using the "Default collation".
    *  @param pattern The text to search for.
    *  @param loc The locale ID for which to open a collator.
    *  @return The offset into this of the start of pattern, or -1 if not found.
    */
    int32_t lastIndexOf(const xqpString& pattern, const char * loc);

    /**Determine if this ends with the characters in pattern in the range [0, length).
    *  @param pattern The text to search for.
    */
    bool endsWith(const xqpString& pattern);

    /**Determine if this ends with the characters in pattern in the range [0, length).
    *  @param pattern The text to search for.
    *  @param loc The locale ID for which to open a collator.
    */
    bool endsWith(const xqpString& pattern, const char * loc);

    /**Returns a substring of the current string, starting at index, and length characters long.
    */
    xqpString substr(size_type index, size_type length);

    /**Returns a substring of the currents string starting at index and continues untill the NULL termination.
    *Doesn't use ICU4C
    */
    xqpString substr(distance_type index);
    const char* c_str() const;

    inline  operator std::string() const{
      return *utf8String;
    }
private:

    /**  Return an UnicodeString (UTF-16 encoded) given a xqpString (UTF-8 encoded)
    */
    UnicodeString getUnicodeString(const xqpString& source) const;
    /**  Return a xqpString (UTF-8 encoded) given an UnicodeString (UTF-16 encoded)
    */
    xqpString getXqpString(UnicodeString source);

    /**  Return a sequence of wchar_t units given a xqpString (UTF-8 encoded)
    */
    wchar_t * getWCS(const xqpString& source) const;

  };

  // xqpString::stream I/O operators
  std::istream& operator>>(std::istream& is, xqp::xqpString& utf8_src);
  std::ostream& operator<<(std::ostream& os, const xqp::xqpString& utf8_src);

  //xqpString::concatenation operator+()
  inline xqpString operator+(const xqpString& lsrc, const xqpString& rsrc){
    xqpString tmp (lsrc);
    tmp += rsrc;
    return tmp;
  }

  inline xqpString operator+(const xqpString& lsrc, const char* rsrc){
    xqpString tmp (lsrc);
    tmp += rsrc;
    return tmp;
  }

  inline xqpString operator+(const char* lsrc, const xqpString& rsrc){
    xqpString tmp (lsrc);
    tmp += rsrc;
    return tmp;
  }
}/* namespace xqp */

#endif

