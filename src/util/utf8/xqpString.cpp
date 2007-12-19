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

#include "util/utf8/xqpString.h"
#include "util/utf8/Unicode_util.h"
#include "util/utf8/utf8.h"
#include "util/zorba.h"

using namespace std;

namespace xqp
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

  bool xqpStringStore::hashEqual(const xqpStringStore& src) const
  {
    if (this == &src)
      return true;
    
    if(hash() == src.hash() && byteEqual(src))
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
    xqpStringStore* temp = new xqpStringStore(*theStrStore);
    *temp += src;
    theStrStore = temp;
    return *this;
  }

  xqpString& xqpString::operator+=(const char* src)
  {
    xqpStringStore* temp = new xqpStringStore(*theStrStore);
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
  int xqpString::compare(xqpString src) const
  {
    UErrorCode status = U_ZERO_ERROR;

    //get the collator for the default collation
    Collator *coll = zorba::getZorbaForCurrentThread()->getCollator();

    Collator::EComparisonResult result = ::Collator::EQUAL;

    //compare the 2 strings
    result = coll->compare(getUnicodeString(*theStrStore), getUnicodeString(src));

    return result;
  }

  int xqpString::compare(xqpString src, xqpString collationUri) const
  {
    UErrorCode status = U_ZERO_ERROR;

    //get the collator object fromthe Static context
      ::Collator *coll = zorba::getZorbaForCurrentThread()->getCollator(collationUri);

    ::Collator::EComparisonResult result = ::Collator::EQUAL;

    //compare the 2 strings
    result = coll->compare(getUnicodeString(*theStrStore), getUnicodeString(src));

    return result;
  }

  int xqpString::compare(const char* src) const
  {
    //TODO optimize the code here
    xqpString tmp(src);
    return compare(tmp);
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
  int32_t xqpString::indexOf(xqpString pattern) const
  {
    //create the collator object
    UErrorCode status = U_ZERO_ERROR;

    //get the collator for the default collation
    Collator *coll = zorba::getZorbaForCurrentThread()->getCollator();

    StringSearch search(getUnicodeString(pattern), getUnicodeString(*theStrStore), (RuleBasedCollator *)coll, NULL, status);

    if(U_FAILURE(status))
    {
      ZORBA_ERROR_ALERT(
          error_messages::XQP0014_SYSTEM_SHOULD_NEVER_BE_REACHED,
          error_messages::SYSTEM_ERROR,
          NULL
        );
      return -1;
    }

    for(int16_t pos = search.first(status);
    U_SUCCESS(status) && pos != USEARCH_DONE;
    pos = search.next(status))
    {
      return pos;
    }
    if (U_FAILURE(status))
    {
      ZORBA_ERROR_ALERT(
          error_messages::XQP0014_SYSTEM_SHOULD_NEVER_BE_REACHED,
          error_messages::SYSTEM_ERROR,
          NULL
        );
      return -1;
    }
    return -1;
  }

  int32_t xqpString::indexOf(xqpString pattern, xqpString collationUri) const
  {
    UErrorCode status = U_ZERO_ERROR;

    //get the collator object fromthe Static context
    ::Collator *coll = zorba::getZorbaForCurrentThread()->getCollator(collationUri);

    //user retains the ownership of this collator, it does not get destroyed during this instance's destruction
    StringSearch search(getUnicodeString(pattern), getUnicodeString(*theStrStore), (RuleBasedCollator*)coll, NULL, status);

    if(U_FAILURE(status))
    {
      ZORBA_ERROR_ALERT(
          error_messages::XQP0014_SYSTEM_SHOULD_NEVER_BE_REACHED,
          error_messages::SYSTEM_ERROR,
          NULL
        );
      return -1;
    }

    for(int16_t pos = search.first(status);
    U_SUCCESS(status) && pos != USEARCH_DONE;
    pos = search.next(status))
    {
      return pos;
    }
    if (U_FAILURE(status))
    {
      ZORBA_ERROR_ALERT(
          error_messages::XQP0014_SYSTEM_SHOULD_NEVER_BE_REACHED,
          error_messages::SYSTEM_ERROR,
          NULL
        );
      return -1;
    }
    return -1;
  }

  int32_t xqpString::lastIndexOf(xqpString pattern) const
  {
    //create the collator object
    UErrorCode status = U_ZERO_ERROR;

    //get the collator for the default collation
    Collator *coll = zorba::getZorbaForCurrentThread()->getCollator();

    StringSearch search(getUnicodeString(pattern), getUnicodeString(*theStrStore), (RuleBasedCollator *)coll, NULL, status);

    if(U_FAILURE(status))
    {
      ZORBA_ERROR_ALERT(
          error_messages::XQP0014_SYSTEM_SHOULD_NEVER_BE_REACHED,
          error_messages::SYSTEM_ERROR,
          NULL
        );
      return -1;
    }

    int32_t pos = search.last(status);
    if (U_FAILURE(status))
    {
      ZORBA_ERROR_ALERT(
          error_messages::XQP0014_SYSTEM_SHOULD_NEVER_BE_REACHED,
          error_messages::SYSTEM_ERROR,
          NULL
        );
      return -1;
    }

    if(U_SUCCESS(status) && pos != USEARCH_DONE)
    {
      //TODO check if this condition is enough
      return pos;
    }

    return -1;
  }

  int32_t xqpString::lastIndexOf(xqpString pattern, xqpString collationUri) const
  {
    UErrorCode status = U_ZERO_ERROR;

    //get the collator object fromthe Static context
    ::Collator *coll = zorba::getZorbaForCurrentThread()->getCollator(collationUri);

    //user retains the ownership of this collator, it does not get destroyed during this instance's destruction.
    StringSearch search(getUnicodeString(pattern), getUnicodeString(*theStrStore), (RuleBasedCollator*)coll, NULL, status);

    if(U_FAILURE(status))
    {
      ZORBA_ERROR_ALERT(
          error_messages::XQP0014_SYSTEM_SHOULD_NEVER_BE_REACHED,
          error_messages::SYSTEM_ERROR,
          NULL
        );
      return -1;
    }

    int32_t pos = search.last(status);
    if (U_FAILURE(status))
    {
      ZORBA_ERROR_ALERT(
          error_messages::XQP0014_SYSTEM_SHOULD_NEVER_BE_REACHED,
          error_messages::SYSTEM_ERROR,
          NULL
        );
      return -1;
    }

    if(U_SUCCESS(status) && pos != USEARCH_DONE)
    {
      //TODO check if this condition is enough
      return pos;
    }

    return -1;
  }

  bool xqpString::endsWith(xqpString pattern) const
  {
    //TODO check if this condition is enough
    return( lastIndexOf(pattern) + pattern.length() == length() );
  }

  bool xqpString::endsWith(xqpString pattern, xqpString collationUri) const
  {
    //TODO check if this condition is enough
    return( lastIndexOf(pattern, collationUri) + pattern.length() == length() );
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
    advance(d, index);

    xqpString ret(d);
    return ret;
  }

  const char* xqpString::c_str() const
  {
    return theStrStore->c_str();
  }
  
  //uppercase/lowercase
  xqpString xqpString::uppercase()
  {
    uint32_t i =0;
    uint32_t len = length();
    const char* c = c_str();
    uint32_t cp;
    char seq[4];

    xqpStringStore* newStr = new xqpStringStore("");

    for(i; i<len; ++i)
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
    uint32_t i =0;
    uint32_t len = length();
    const char* c = c_str();
    uint32_t cp;
    char seq[4];

    xqpStringStore* newStr = new xqpStringStore("");

    for(i; i<len; ++i)
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

    if(normMode == "NFC")
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
    else
    {
      ZORBA_ERROR_ALERT(
          error_messages::FOCH0003_Unsupported_normalization_form,
          error_messages::SYSTEM_ERROR,
          NULL
          );
    }

    if(U_FAILURE(status))
    {
      ZORBA_ERROR_ALERT(
          error_messages::XQP0014_SYSTEM_SHOULD_NEVER_BE_REACHED,
          error_messages::SYSTEM_ERROR,
          NULL
          );
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

  bool xqpString::is_space(uint32_t cp) const
  {
    return  (cp == 0x20) ? true: false;
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
        mapArray.insert(std::pair<uint32_t,uint32_t>(tmp0, 0xFFFFFFFF)); //0xFFFFFFFF = ULONG_MAX
        --mapLen;
      }
    }
    return mapArray;
  }
  
  xqpString xqpString::encodeForUri()
  {
    uint32_t i =0;
    uint32_t len = length();
    const char* c = c_str();
    uint32_t cp;
    char seq[4];
    const char* prev = c_str();
    distance_type length;

    std::string tmp = "";
    
    for(i; i<len; ++i)
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

    theStrStore = new xqpStringStore(tmp);
    return *this;
  }

  xqpString xqpString::iriToUri()
  {
    uint32_t i =0;
    uint32_t len = length();
    const char* c = c_str();
    uint32_t cp;
    char seq[4];
    const char* prev = c_str();
    distance_type length;

    std::string tmp = "";
    
    for(i; i<len; ++i)
    {
      prev = c;
      cp = UTF8Decode(c);
      memset(seq, 0, sizeof(seq));
      if(!is_ucscharCP(cp) && !is_iprivateCP(cp))
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

    theStrStore = new xqpStringStore(tmp);
    return *this;
  }
 
  xqpString xqpString::escapeHtmlUri()
  {
    uint32_t i =0;
    uint32_t len = length();
    const char* c = c_str();
    uint32_t cp;
    char seq[4];
    const char* prev = c_str();
    distance_type length;

    std::string tmp = "";
    
    for(i; i<len; ++i)
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

    theStrStore = new xqpStringStore(tmp);
    return *this;
  }

  xqpString xqpString::translate(xqpString mapString, xqpString transString)
  {
    std::map<uint32_t,uint32_t> myMap;
    std::map<uint32_t,uint32_t>::iterator it;
    uint32_t first, second;

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

      if(cp != 0xFFFFFFFF) //0xFFFFFFFF = ULONG_MAX
      {
        memset(seq, 0, sizeof(seq));
        UTF8Encode(cp, seq);
        tmp += seq;
      }
    }
    tmp += "\0";

    theStrStore = new xqpStringStore(tmp);
    return *this;
  }

  xqpString xqpString::normalizeSpace()
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
      if( !is_space(cp) ||
            (is_space(cp) && !is_space(cpPrev) && len!=1)
        )
      {
        memset(seq, 0, sizeof(seq));
        UTF8Encode(cp, seq);
        tmp += seq;
      }
      cpPrev = cp;
      --len;
    }
    tmp += "\0";

    theStrStore = new xqpStringStore(tmp);
    return *this;
  }

  xqpString xqpString::trimL()
  {
    //create the new xqpStringStore
    std::string tmp = "";
    uint32_t len = length();
    const char* c = c_str();
    uint32_t cp;
    char seq[4];
    bool found = false;

    while(len > 0 && !found)
    {
      cp = UTF8Decode(c);
      if(!is_space( cp))
      {
        memset(seq, 0, sizeof(seq));
        UTF8Encode(cp, seq);
        tmp += seq;
        tmp +=c;
        found = true;
      }
      --len;
    }

    theStrStore = new xqpStringStore(tmp);
    return *this;
  }

  xqpString xqpString::trimR()
  {
    //create the new xqpStringStore
    std::string tmp = "";
    uint32_t len = length();
    uint32_t pos, cp;
    const char* end = c_str();
    const char* c = c_str();
    char seq[4];

    xqp::advance(end, len);

    while(len > 0)
    {
      cp = UTF8DecodePrev(end);
      if( !is_space(cp)  )
      {
        pos = xqp::UTF8Distance(c, end);
        break;
      }
      --len;
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

    theStrStore = new xqpStringStore(tmp);
    return *this;
  }

  xqpString xqpString::trim()
  {
    //TODO optimize
    xqpString tmp = trimL();
    return tmp.trimR();
  }
  
  // Private methods
  UnicodeString xqpString::getUnicodeString(xqpString source) const
  {
    UnicodeString ret;
    UErrorCode status = U_ZERO_ERROR;
    int32_t len = source.bytes();
    UChar* buffer = ret.getBuffer(len);

    u_strFromUTF8(buffer, ret.getCapacity(), &len, source.c_str(), len, &status);

    ret.releaseBuffer(U_SUCCESS(status) ? len : 0);

    if(U_FAILURE(status))
    {
      ZORBA_ERROR_ALERT(
            error_messages::XQP0014_SYSTEM_SHOULD_NEVER_BE_REACHED,
            error_messages::SYSTEM_ERROR,
            NULL
          );
    }

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
      ZORBA_ERROR_ALERT(
            error_messages::XQP0014_SYSTEM_SHOULD_NEVER_BE_REACHED,
            error_messages::SYSTEM_ERROR,
            NULL
          );

      delete target;
      return "";
    }

    //Convert from UTF-16 to UTF-8
    ucnv_fromUChars (conv, target, targetLen, source.getBuffer( source.length() ), source.length(), &status);
    //close the converter
    ucnv_close(conv);

    if(U_FAILURE(status))
    {
      ZORBA_ERROR_ALERT(
            error_messages::XQP0014_SYSTEM_SHOULD_NEVER_BE_REACHED,
            error_messages::SYSTEM_ERROR,
            NULL
          );

      delete target;
      return "";
    }

    xqpString ret(&target[0]);
    delete target;
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
      ZORBA_ERROR_ALERT(
            error_messages::XQP0014_SYSTEM_SHOULD_NEVER_BE_REACHED,
            error_messages::SYSTEM_ERROR,
            NULL
          );
    }

    return ret;
  }
}/* namespace xqp */
