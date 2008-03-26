/**
 * @copyright
 * ========================================================================
 *  Copyright FLWOR Foundation
 * ========================================================================
 *
 * @author Sorin Nasoi (sorin.nasoi@ipdevel.ro)
 * @author Nicolae Brinza (nicolae.brinza@ipdevel.ro)
 * @author Dan Muresan (dan.muresan@ipdevel.ro)
 * @file util/utf8/xqpString.cpp
 *
 */

#include "zorbatypes/xqpstring.h"

#include "zorbatypes/Unicode_util.h"
#include "zorbatypes/utf8.h"
#include "zorbatypes/numconversions.h"
#include "zorbatypes/collation_manager.h"

#include <unicode/regex.h>

using namespace std;

namespace zorba
{
  uint32_t xqpStringStore::hash() const
  {
    uint32_t hash = 5381;
    int c;
    const char *str = c_str();
    while ((c = *str++))
    {
      hash = ((hash << 5) + hash) + c; // hash*33 + c
    }
    return hash;
  }

  uint32_t xqpStringStore::hash(const char* str)
  {
    uint32_t hash = 5381;
    int c;
    while ((c = *str++))
    {
      hash = ((hash << 5) + hash) + c; // hash*33 + c
    }
    return hash;
  }

  bool xqpStringStore::byteEqual(const xqpStringStore& src) const
  {
    if (this == &src)
      return true;

    uint32_t len = bytes();

    if(len == src.bytes() && memcmp(c_str(), src.c_str(), len) == 0)
       return true;

    return false;
  }

  bool xqpStringStore::byteEqual(const char* src, uint32_t srclen) const
  {
    if(bytes() == srclen && memcmp(c_str(), src, srclen) == 0)
      return true;

    return false;
  }

  xqpString::xqpString()
  {
    theStrStore = new xqpStringStore("");
  }

  xqpString::xqpString(const std::string& src)
  {
    theStrStore = new xqpStringStore(src);
  }

  xqpString::xqpString(const char* src)
  {
    theStrStore = new xqpStringStore(src);
  }

  xqpString& xqpString::operator=(const std::string& src)
  {
    theStrStore = new xqpStringStore(src);
    return *this;
  }

  xqpString& xqpString::operator=(const char* src)
  {
    theStrStore = new xqpStringStore(src);
    return *this;
  }

  xqpString& xqpString::operator=(uint32_t cp)
  {
    theStrStore->reserve(4);
    char seq[4] = {0,0,0,0};
    UTF8Encode(cp, seq);
    theStrStore = new xqpStringStore(seq);
    return *this;
  }

  xqpString& xqpString::operator=(char c)
  {
    theStrStore = new xqpStringStore(&c);
    return *this;
  }

  //xqpString::operator+=()
  xqpString& xqpString::operator+=(xqpString src)
  {
    xqpStringStore_t temp = new xqpStringStore(*theStrStore);
    *temp += src;
    theStrStore = temp;
    return *this;
  }

  xqpString& xqpString::operator+=(const char* src)
  {
    xqpStringStore_t temp = new xqpStringStore(*theStrStore);
    *temp += src;
    theStrStore = temp;
    return *this;
  }

  xqpString& xqpString::operator+=(uint32_t cp)
  {
    theStrStore->reserve(4);
    char seq[4] = {0,0,0,0};
    UTF8Encode(cp, seq);
    theStrStore = new xqpStringStore(*theStrStore+seq);
    return *this;
  }

  xqpString& xqpString::operator+=(char c)
  {
    theStrStore = new xqpStringStore(*theStrStore+c);
    return *this;
  }

  //xqpString::stream I/O operators
  std::istream& operator>>(std::istream& is, xqpString& utf8_src)
  {
    std::string buffer;
    is >> buffer;
    //TODO is there a need to perform charset conversion to/from the current locale ?!?!
    utf8_src = buffer;
    return is;
  }

  std::ostream& operator<<(std::ostream& os, xqpString utf8_src)
  {
    //TODO is there a need to perform charset conversion to/from the current locale ?!?!
    os << *utf8_src.theStrStore;
    return os;
  }

  //xqpString::compare
  int xqpString::compare(xqpString src, XQPCollator* coll) const
  {
    if ( ! coll )
      return theStrStore->compare(src.theStrStore->c_str());

    Collator::EComparisonResult result = ::Collator::EQUAL;

    //compare the 2 strings
    result = coll->theCollator->compare(getUnicodeString(*theStrStore), getUnicodeString(src));

    return result;
  }

  int xqpString::compare(const char* src, XQPCollator* coll) const
  {
    //TODO optimize the code here
    xqpString tmp(src);
    return compare(tmp, coll);
  }

  //xqpString::Length
  xqpString::size_type xqpString::size() const
  {
    const char* c = theStrStore->c_str();
    return UTF8Distance(c, c + theStrStore->size());
  }

  xqpString::size_type xqpString::length() const
  {
    const char* c = theStrStore->c_str();
    return UTF8Distance(c, c + theStrStore->size());
  }

  bool xqpString::empty() const
  {
    return theStrStore->empty();
  }

  void xqpString::reserve(xqpString::size_type size)
  {
    theStrStore->reserve(size);
  }

  //xqpString::Clear
  void xqpString::clear()
  {
    theStrStore->erase();
  }

  //xpqString::Codepoint
  std::vector<uint32_t> xqpString::getCodepoints() const
  {
    std::vector<uint32_t> tt;
    uint16_t vLength;

    vLength = length() + 1;
    const char* c = theStrStore->c_str();
    while( --vLength > 0 )
    {
      tt.push_back(UTF8Decode(c));
    }
    return tt;
  }

  //xqpString::Substring matching/ string search
  int32_t xqpString::indexOf(xqpString pattern, XQPCollator* coll) const
  {
    if (size() == 0)
      return -1;

    if ( ! coll ) {
      size_t lRes = theStrStore->find(pattern.theStrStore->c_str());
      return (lRes == std::string::npos)?-1:lRes;
    }

    UErrorCode status = U_ZERO_ERROR;

    StringSearch search(getUnicodeString(pattern), getUnicodeString(*theStrStore), 
                        (RuleBasedCollator*)coll->theCollator, NULL, status);

    if(U_FAILURE(status))
    {
      assert(false);
      return -1;
    }

    for(  int16_t pos = search.first(status);
          U_SUCCESS(status) && pos != USEARCH_DONE;
          pos = search.next(status))
    {
      return pos;
    }
    if (U_FAILURE(status))
    {
      assert(false);
      return -1;
    }
    return -1;
  }


  int32_t xqpString::lastIndexOf(xqpString pattern, XQPCollator* coll) const
  {
    if ( ! coll ) {
      size_t lRes = theStrStore->rfind(pattern.theStrStore->c_str());
      return (lRes == std::string::npos)?-1:lRes;
    }

    UErrorCode status = U_ZERO_ERROR;

    StringSearch search(getUnicodeString(pattern), getUnicodeString(*theStrStore), 
                        (RuleBasedCollator *)coll->theCollator, NULL, status);

    if(U_FAILURE(status))
    {
      assert(false);
      return -1;
    }

    int32_t pos = search.last(status);
    if (U_FAILURE(status))
    {
      assert(false);
      return -1;
    }

    if(U_SUCCESS(status) && pos != USEARCH_DONE)
    {
      //TODO check if this condition is enough
      return pos;
    }

    return -1;
  }

  bool xqpString::endsWith(xqpString pattern, XQPCollator* coll) const
  {
    //TODO check if this condition is enough
    return( lastIndexOf(pattern, coll) + pattern.length() == length() );
  }


  xqpString xqpString::substr(xqpString::size_type index, xqpString::size_type length) const
  {
    char* target;
    int32_t size =  length*4 + 1;
    target = new char[size]; //will hold UTF-8 encoded characters
    UnicodeString str = getUnicodeString( *theStrStore );

    int32_t targetsize = str.extract(index, length, target, size, "UTF-8");
    target[targetsize] = 0; /* NULL termination */

    xqpString ret(&target[0]);

    delete [] target;
    return ret;
  }

  xqpString xqpString::substr(distance_type index) const
  {
    if(index >= (int32_t)length())
    {
      index = length();
    }
    else if(index < 0)
    {
      xqpString ret(*theStrStore);
      return ret;
    }

    const char * d = theStrStore->c_str();
    advance(d, index, d+bytes());

    xqpString ret(d);

    return ret;
  }

  xqpString xqpString::formatAsXML(const char* src) const
  {
    uint32_t i;
    uint32_t len = length();
    const char* c = c_str();
    uint32_t cp;
    char seq[4];

    xqpStringStore_t newStr = new xqpStringStore("");

    for(i=0; i<len; ++i)
    {
      cp = UTF8Decode(c);
      if(cp<128)
      {
        memset(seq, 0, sizeof(seq));
        UTF8Encode(cp, seq);
        *newStr += seq;
      }
      else
      {
        *newStr += '&';
        *newStr += '#';
        *newStr +=  Integer::parseInt(cp).toString();
        *newStr += ';';
      }
    }
    *newStr += "\0";

    xqpString ret(*newStr);
    return ret;
  }

  const char* xqpString::c_str() const
  {
    return theStrStore->c_str();
  }
  
  //uppercase/lowercase
  xqpString xqpString::uppercase()
  {
    uint32_t i;
    uint32_t len = length();
    const char* c = c_str();
    uint32_t cp;
    char seq[4];

    xqpStringStore_t newStr = new xqpStringStore("");

    for(i=0; i<len; ++i)
    {
      cp = toUpper(UTF8Decode(c));
      memset(seq, 0, sizeof(seq));
      UTF8Encode(cp, seq);
      *newStr += seq;
    }
    *newStr += "\0";

    theStrStore = new xqpStringStore(*newStr);
    return *this;
  }

  xqpString xqpString::lowercase()
  {
    uint32_t i;
    uint32_t len = length();
    const char* c = c_str();
    uint32_t cp;
    char seq[4];

    xqpStringStore_t newStr = new xqpStringStore("");

    for(i=0; i<len; ++i)
    {
      cp = toLower(UTF8Decode(c));
      memset(seq, 0, sizeof(seq));
      UTF8Encode(cp, seq);
      *newStr += seq;
    }
    *newStr += "\0";

    theStrStore = new xqpStringStore(*newStr);
    return *this;
  }


  //normalize
  xqpString xqpString::normalize(xqpString normMode)
  {
    UnicodeString result;
    UErrorCode status = U_ZERO_ERROR;

    if (normMode.empty ())
      return *this;
    else if(normMode == "NFC")
    {
      Normalizer::normalize(getUnicodeString(*theStrStore), UNORM_NFC , 0, result, status);
    }
    else if(normMode == "NFKC")
    {
      Normalizer::normalize(getUnicodeString(*theStrStore), UNORM_NFKC , 0, result, status);
    }
    else if(normMode == "NFD")
    {
      Normalizer::normalize(getUnicodeString(*theStrStore), UNORM_NFD , 0, result, status);
    }
    else if(normMode == "NFKD")
    {
      Normalizer::normalize(getUnicodeString(*theStrStore), UNORM_NFKD , 0, result, status);
    }

    if(U_FAILURE(status))
    {
      assert(false);
    }
    
    return getXqpString( result ); 
  }

  bool xqpString::is_unreservedCP(uint32_t cp) const
  {
    bool ret = false;
    if((0x30 <= cp && cp <= 0x39)|| //0-9
       (0x41 <= cp && cp <= 0x5A)|| //A-Z
       (0x61 <= cp && cp <= 0x7A)|| //a-z
       cp == 0x2D || //-
       cp == 0x2E || //.
       cp == 0x5F || //_
       cp == 0x7E)   //~
      {  
        ret = true;
      }
      return ret;
  }

  bool xqpString::is_ucscharCP(uint32_t cp) const
  {
    bool ret = false;
    if((0xA0 <= cp && cp <=0xD7FF) ||
      (0xF900 <= cp && cp <=0xFDCF) ||
      (0xFDF0 <= cp && cp <=0xFFEF) ||
      (0x10000 <= cp && cp <=0x1FFFD) ||
      (0x20000 <= cp && cp <=0x2FFFD) ||
      (0x30000 <= cp && cp <=0x3FFFD) ||
      (0x40000 <= cp && cp <=0x4FFFD) ||
      (0x50000 <= cp && cp <=0x5FFFD) ||
      (0x60000 <= cp && cp <=0x6FFFD) ||
      (0x70000 <= cp && cp <=0x7FFFD) ||
      (0x80000 <= cp && cp <=0x8FFFD) ||
      (0x90000 <= cp && cp <=0x9FFFD) ||
      (0xA0000 <= cp && cp <=0xAFFFD) ||
      (0xB0000 <= cp && cp <=0xBFFFD) ||
      (0xC0000 <= cp && cp <=0xCFFFD) ||
      (0xD0000 <= cp && cp <=0xDFFFD) ||
      (0xE0000 <= cp && cp <=0xEFFFD))
    {
      ret = true;
    }
    return ret;
  }

  bool xqpString::is_Invalid_in_IRI(uint32_t cp) const
  {
    bool ret = false;
    if(0x3C == cp || 0x3E == cp || 0x22 == cp ||
       0x7B == cp || 0x7D == cp || 0x7C == cp || 
       0x5C == cp || 0X5E == cp || 0x60 == cp ||
       0x20 == cp)
    {
      ret = true;
    }
    return ret;
  }

  bool xqpString::is_iprivateCP( uint32_t cp ) const
  {
    bool ret = false;
    if((0xE000 <= cp && cp <=0xF8FF) ||
        (0xF0000 <= cp && cp <=0xFFFFD) ||
        (0x100000 <= cp && cp <= 0x10FFFD)
      )
    {
      ret = true;
    }
    return ret;
  }

  bool xqpString::is_printableASCII(uint32_t cp) const
  {
    bool ret = false;
    if(0x20 <= cp && cp <=0x7E)//32 to 126 (decimal)
    {
      ret = true;
    }
    return ret;
  }

  // whitespace = " \t\r\n" meaning (#x20) (#x9) (#xD) (#xA)
  bool xqpString::is_whitespace(uint32_t cp) const
  {
    bool res = (cp == 0x20
        ||
        cp == 0x9
        ||
        cp == 0xD
        ||
        cp == 0xA) ? true : false;

    return res;
  }

  std::map<uint32_t,uint32_t> xqpString::createMapArray(xqpString mapString, xqpString transString) const
  {
    uint16_t mapLen = mapString.theStrStore->length()+1;
    uint16_t transLen = transString.theStrStore->length()+1;
    const char* mapPtr = mapString.theStrStore->c_str();
    const char* transPtr = transString.theStrStore->c_str();
    uint32_t tmp0, tmp1;
    
    std::map<uint32_t,uint32_t> mapArray;
    std::map<uint32_t,uint32_t>::iterator it;
    
    if(mapLen >0)
    {
      while((--mapLen > 0) && (--transLen > 0))
      {
        tmp0 = UTF8Decode(mapPtr);
        tmp1 = UTF8Decode(transPtr);
        mapArray.insert(std::pair<uint32_t,uint32_t>(tmp0, tmp1));
      }
      
      while(mapLen > 0)
      {
        tmp0 = UTF8Decode(mapPtr);
        mapArray.insert(std::pair<uint32_t,uint32_t>(tmp0, 0xFFFFFFFF)); //0xFFFFFFFF = unsigned long_MAX
        --mapLen;
      }
    }
    return mapArray;
  }
  
  xqpString xqpString::encodeForUri() const
  {
    uint32_t i;
    uint32_t len = length();
    const char* c = c_str();
    unsigned int cp;
    char seq[4];
    const char* prev = c_str();
    distance_type length;

    std::string tmp = "";
    
    for(i=0; i<len; ++i)
    {
      prev = c;
      cp = UTF8Decode(c);
      memset(seq, 0, sizeof(seq));
      if(is_unreservedCP(cp))
      {
        UTF8Encode(cp, seq);
        tmp += seq;
      }
      else{//codepoint has to be escaped
        length = sequence_length(prev);
        for(int j=0; j<length;++j)
        {
          cp = mask8(*prev);
          sprintf(seq, "%%%X", cp);
          tmp += seq;
          prev++;
        }
      }
    }
    tmp += "\0";

    xqpString res(tmp);
    return res;
  }

  xqpString xqpString::iriToUri() const
  {
    uint32_t i;
    uint32_t len = length();
    const char* c = c_str();
    unsigned int cp;
    char seq[4];
    const char* prev = c_str();
    distance_type length;

    std::string tmp = "";
    
    for(i=0; i<len; ++i)
    {
      prev = c;
      cp = UTF8Decode(c);
      memset(seq, 0, sizeof(seq));
      if(!is_ucscharCP(cp) && !is_iprivateCP(cp) && !is_Invalid_in_IRI(cp))
      {
        UTF8Encode(cp, seq);
        tmp += seq;
      }
      else{//codepoint has to be escaped
        length = sequence_length(prev);
        for(int j=0; j<length;++j)
        {
          cp = mask8(*prev);
          sprintf(seq, "%%%X", cp);
          tmp += seq;
          prev++;
        }
      }
    }
    tmp += "\0";

    xqpString res(tmp);
    return res;
  }
 
  xqpString xqpString::escapeHtmlUri() const
  {
    uint32_t i;
    uint32_t len = length();
    const char* c = c_str();
    unsigned int cp;
    char seq[4];
    const char* prev = c_str();
    distance_type length;

    std::string tmp = "";
    
    for(i=0; i<len; ++i)
    {
      prev = c;
      cp = UTF8Decode(c);
      memset(seq, 0, sizeof(seq));
      if(is_printableASCII(cp))
      {
        UTF8Encode(cp, seq);
        tmp += seq;
      }
      else{//codepoint has to be escaped
        length = sequence_length(prev);
        if(length != 1)
        {
          for(int j=0; j<length;++j)
          {
            cp = mask8(*prev);
            sprintf(seq, "%%%X", cp);
            tmp += seq;
            prev++;
          }
        }
      }
    }
    tmp += "\0";

    xqpString res(tmp);
    return res;
  }

  xqpString xqpString::translate(xqpString mapString, xqpString transString) const
  {
    std::map<uint32_t,uint32_t> myMap;
    std::map<uint32_t,uint32_t>::iterator it;

    //create the map
    myMap = createMapArray(mapString, transString);

    //create the new xqpStringStore
    std::string tmp = "";
    uint32_t len = length();
    const char* c = c_str();
    uint32_t cp, i;
    char seq[4];

    for(i=0; i<len; ++i)
    {
      cp = UTF8Decode(c);

      it= myMap.find(cp);
      if( it != myMap.end() )
      {
        cp = (*it).second;
      }

      if(cp != 0xFFFFFFFF) //0xFFFFFFFF = unsigned long_MAX
      {
        memset(seq, 0, sizeof(seq));
        UTF8Encode(cp, seq);
        tmp += seq;
      }
    }
    tmp += "\0";

    xqpString res(tmp);
    return res;
  }

  xqpString xqpString::normalizeSpace() const
  {
    //create the new xqpStringStore
    std::string tmp = "";
    uint32_t len = length();
    const char* c = c_str();
    uint32_t cp, cpPrev;
    char seq[4];

    cpPrev = 0x20;
    while(len > 0)
    {
      cp = UTF8Decode(c);
      if( !is_whitespace(cp) ||
           (is_whitespace(cp) && !is_whitespace(cpPrev))
        )
      {
        if(is_whitespace(cp))
          cp = 0x20;
        
        memset(seq, 0, sizeof(seq));
        UTF8Encode(cp, seq);
        tmp += seq;
      }
      cpPrev = cp;
      --len;
    }
    tmp += "\0";

    xqpString res(tmp);
    return res.trimR();
  }

  xqpString xqpString::trimL(const char* start, uint16_t len) const
  {
    if(0 == length() || 0 == len)
      return *this;

    //create the new xqpStringStore
    std::string tmp = "";
    uint32_t StrLen = length();
    const char* c = c_str();
    uint32_t cp;
    char seq[4];
    bool found = false;
    
    bool firstCp = true;
    uint32_t *trimCP;//[len];
		trimCP = new uint32_t[len];
    for(uint16_t i=0; i<len; i++)
      trimCP[i]=UTF8Decode(start);
  
    while(StrLen > 0 && !found)
    {
      cp = UTF8Decode(c);

      for(uint16_t i=0; i<len; i++)
      {
        if(trimCP[i] == cp)
        {
          firstCp = false;
          break;
        }
      }

      if(firstCp)
      {
        memset(seq, 0, sizeof(seq));
        UTF8Encode(cp, seq);
        tmp += seq;
        tmp +=c;
        found = true;
      }
      --StrLen;
      firstCp = true;
    }

		delete[] trimCP;
    xqpString res(tmp);
    return res;
  }
  
  xqpString xqpString::trimL() const
  {
    char seq = ' ';
    return trimL( &seq, 1 );
  }

  xqpString xqpString::trimR(const char* start, uint16_t len) const
  {
    if(0 == length() || 0 == len )
      return *this;
    
    uint32_t StrLen = length();

    bool firstCp = true;
    uint32_t *trimCP;//[len];
		trimCP = new uint32_t[len];
    for(uint16_t i=0; i<len; i++)
      trimCP[i]=UTF8Decode(start);

    //create the new xqpStringStore
    std::string tmp = "";
    uint32_t pos = 0;
    uint32_t cp = 0;
    const char* end = c_str();
    const char* c = c_str();
    char seq[4];

    zorba::advance(end, StrLen, end + bytes());

    while(StrLen > 0)
    {
      cp = UTF8DecodePrev(end);

      for(uint16_t i=0; i<len; i++)
      {
        if(trimCP[i] == cp)
        {
          firstCp = false;
          break;
        }
      }
      
      if( firstCp )
      {
        pos = zorba::UTF8Distance(c, end);
        break;
      }
      --StrLen;
      firstCp = true;
    }
    
    ++pos;

    while(pos > 0)
    {
      cp = UTF8Decode(c);
      
      memset(seq, 0, sizeof(seq));
      UTF8Encode(cp, seq);
      tmp += seq;

      --pos;
    }

		delete[] trimCP;
    xqpString res(tmp);
    return res;
  }
  
  xqpString xqpString::trimR() const
  {
    char seq = ' ';
    return trimR( &seq, 1 );
  }

  xqpString xqpString::trim(const char* start, uint16_t len) const
  {
    if(0 == length() || 0 == len)
      return *this;

    xqpString tmp = trimL(start, len);
    return tmp.trimR(start, len);
  }
  
  xqpString xqpString::trim() const
  {
    if(0 == length())
      return *this;

    char seq = ' ';
    xqpString tmp = trimL(&seq, 1);
    return tmp.trimR(&seq,1);
  }

  uint32_t parse_regex_flags (const char *flag_cstr) {
    uint32_t flags = 0;
    for (const char *p = flag_cstr; *p != '\0'; p++) {
      switch (*p) {
      case 'i': flags |= UREGEX_CASE_INSENSITIVE; break;
      case 's': flags |= UREGEX_DOTALL; break;
      case 'm': flags |= UREGEX_MULTILINE; break;
      case 'x': flags |= UREGEX_COMMENTS; break;
      default: break;  // FORX0001
      }
    }
    return flags;
  }

  bool
  xqpString::matches(xqpString pattern, xqpString flags)
  {
    UErrorCode status = U_ZERO_ERROR;
    RegexMatcher matcher (pattern.getUnicodeString (), parse_regex_flags (flags.c_str ()), status);
    if (U_FAILURE(status)) {
      return false;
      // FORX0002
    }

    UnicodeString ustr = getUnicodeString ();
    matcher.reset (ustr);
    return matcher.find ();
  }

  xqpString
  xqpString::replace(xqpString pattern, xqpString replacement, xqpString flags) {
    UErrorCode status = U_ZERO_ERROR;
    RegexMatcher matcher (pattern.getUnicodeString (), parse_regex_flags (flags.c_str ()), status);
    if (U_FAILURE(status)) {
      return "";
      // FORX0002
    }
    UnicodeString result = matcher.replaceAll (replacement.getUnicodeString (), status);
    if (U_FAILURE(status)) {
      return "";
      // TODO: error
    }
    return getXqpString (result);
  }

  xqpString
  xqpString::tokenize(xqpString pattern, xqpString flags, xqpString *remaining)
  {
    UErrorCode status = U_ZERO_ERROR;
    RegexMatcher m (pattern.getUnicodeString (), parse_regex_flags (flags.c_str ()), status); 
    UnicodeString words[2];
    int numWords = m.split(getUnicodeString (), words, 2, status);
    *remaining = (numWords == 2) ? getXqpString (words [1]) : xqpString ();
    return getXqpString (words [0]);
  }

  UnicodeString xqpString::getUnicodeString() const
  {
    UnicodeString ret;
    UErrorCode status = U_ZERO_ERROR;
    int32_t len = bytes();
    UChar* buffer = ret.getBuffer(len);

    u_strFromUTF8(buffer, ret.getCapacity(), &len, c_str(), len, &status);

    if(U_FAILURE(status))
    {
      assert(false);
    }

    ret.releaseBuffer(U_SUCCESS(status) ? len : 0);

    return ret;
  }

  xqpString xqpString::fromUTF16(const UChar* src, int32_t len)
  {
    char* target;
    int32_t targetLen = len*4 + 1;
    target = new char[targetLen];
    UErrorCode status = U_ZERO_ERROR;

    //open a convertor to UTF-8
    UConverter *conv = ucnv_open("utf-8", &status);

    if(U_FAILURE(status))
    {
      assert(false);

      delete[] target;
      return "";
    }

    //Convert from UTF-16 to UTF-8
    ucnv_fromUChars (conv, target, targetLen, (const UChar*)src, len, &status);
    //close the converter
    ucnv_close(conv);

    if(U_FAILURE(status))
    {
      assert(false);

      delete[] target;
      return "";
    }

    xqpString ret(&target[0]);
    delete[] target;
    return ret;
  }

  // Private methods
  UnicodeString xqpString::getUnicodeString(xqpString source) const
  {
//     UnicodeString res(source.c_str(), -1, US_INV);
//     return res;
    UnicodeString ret;
    UErrorCode status = U_ZERO_ERROR;
    int32_t len = source.bytes();
    UChar* buffer = ret.getBuffer(len);

    u_strFromUTF8(buffer, ret.getCapacity(), &len, source.c_str(), len, &status);

    if(U_FAILURE(status))
    {
      assert(false);
    }

    ret.releaseBuffer(U_SUCCESS(status) ? len : 0);

    return ret;
  }

  xqpString xqpString::getXqpString(UnicodeString source)
  {
    char* target;
    int32_t targetLen = source.getCapacity()*4 + 1;
    target = new char[targetLen];
    UErrorCode status = U_ZERO_ERROR;

    //open a convertor to UTF-8
    UConverter *conv = ucnv_open("utf-8", &status);

    if(U_FAILURE(status))
    {
      assert(false);

      delete[] target;
      return "";
    }

    //Convert from UTF-16 to UTF-8
    ucnv_fromUChars (conv, target, targetLen, source.getBuffer( source.length() ), source.length(), &status);
    //close the converter
    ucnv_close(conv);

    if(U_FAILURE(status))
    {
      assert(false);

      delete[] target;
      return "";
    }

    xqpString ret(&target[0]);
    delete[] target;
    return ret;
}

  wchar_t * xqpString::getWCS(xqpString source) const
  {
    int32_t destCapacity =  source.length()*2 + 1;
    wchar_t* destWCS;
    destWCS = new wchar_t[destCapacity];
    int32_t destLen;

    UnicodeString unicodeStr = getUnicodeString(source);
    int32_t srcLen = unicodeStr.length();
    UChar* srcBuf = unicodeStr.getBuffer(srcLen);
    UErrorCode status = U_ZERO_ERROR;

    wchar_t* ret =  u_strToWCS(destWCS, destCapacity, &destLen, srcBuf, srcLen, &status);

    if(U_FAILURE(status))
    {
      assert(false);
    }

    return ret;
  }
}/* namespace zorba */
