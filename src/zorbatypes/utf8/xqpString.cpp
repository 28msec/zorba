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
#include <zorba/config.h>
#ifndef ZORBA_NO_UNICODE
#include <unicode/regex.h>
#endif
#include <memory>
#include "zorbatypes/xqpstring.h"

#ifndef ZORBA_NO_UNICODE
#include "zorbatypes/Unicode_util.h"
#include "zorbatypes/utf8.h"
#include "zorbatypes/numconversions.h"
#include "zorbatypes/collation_manager.h"

#include <cstdio>
#include <stdio.h>

using namespace std;


namespace zorba
{
SERIALIZABLE_CLASS_VERSIONS(xqpStringStore)
END_SERIALIZABLE_CLASS_VERSIONS(xqpStringStore)

SERIALIZABLE_CLASS_VERSIONS(xqpString)
END_SERIALIZABLE_CLASS_VERSIONS(xqpString)

/*******************************************************************************
  Return a xqpStringStore (UTF-8 encoded) given an UnicodeString (UTF-16 encoded)
********************************************************************************/
static xqpStringStore_t getXqpString(UnicodeString source)
{
  UErrorCode status = U_ZERO_ERROR;

  //open a convertor to UTF-8
  UConverter* conv = ucnv_open("utf-8", &status);

  if(U_FAILURE(status))
  {
    assert(false);
    return new xqpStringStore("");
  }

  int32_t targetLen = source.getCapacity()*4 + 1;
  char* target = new char[targetLen];
  int32_t srcLen = source.length();
  UChar *buf = source.getBuffer(srcLen);

  //Convert from UTF-16 to UTF-8
  ucnv_fromUChars(conv, target, targetLen,
                  buf, srcLen,
                  &status);
  source.releaseBuffer (srcLen);

  //close the converter
  ucnv_close(conv);

  if(U_FAILURE(status))
  {
    assert(false);

    delete[] target;
    return new xqpStringStore("");
  }

  xqpStringStore_t result = new xqpStringStore(&target[0], strlen(target));
  delete[] target;
  return result;
}


/*******************************************************************************
  Return an UnicodeString (UTF-16 encoded) version of the string.
********************************************************************************/
UnicodeString
xqpString::getUnicodeString(const char* aSrc, const ulong aLen)
{
  UnicodeString lRet;
  UErrorCode lStatus = U_ZERO_ERROR;
  int32_t lLen = (int32_t)aLen;
  UChar* buffer = lRet.getBuffer(lLen);

  u_strFromUTF8(buffer, lRet.getCapacity(), &lLen, aSrc, lLen, &lStatus);

  if(U_FAILURE(lStatus))
  {
    assert(false);
  }

  lRet.releaseBuffer(U_SUCCESS(lStatus) ? lLen : 0);

  return lRet;
}


/*******************************************************************************

********************************************************************************/
UnicodeString
xqpString::getUnicodeString(const xqpStringStore* aSrc)
{
  return getUnicodeString(aSrc->c_str(), aSrc->bytes());
}


/*******************************************************************************

********************************************************************************/
static uint32_t parse_regex_flags(const char* flag_cstr) 
{
  uint32_t flags = 0;
  for (const char* p = flag_cstr; *p != '\0'; ++p) 
  {
    switch (*p) 
    {
    case 'i': flags |= UREGEX_CASE_INSENSITIVE; break;
    case 's': flags |= UREGEX_DOTALL; break;
    case 'm': flags |= UREGEX_MULTILINE; break;
    case 'x': flags |= UREGEX_COMMENTS; break;
    default:
      throw zorbatypesException(flag_cstr, ZorbatypesError::FORX0001);
      break;
    }
  }
  return flags;
}

xqpStringStore::xqpStringStore(checked_vector<uint32_t> &aCpVector, ulong aStart, ulong aSize)
{
  char lSeq[5];
  checked_vector<uint32_t>::iterator it;

  for(it=aCpVector.begin()+aStart ; it < aCpVector.begin()+aStart+aSize; it++)
  {
    memset(lSeq, 0, sizeof(lSeq));
    UTF8Encode(*it, lSeq);
    theString += lSeq;
  }
  theString += "\0";
}

/*******************************************************************************
  whitespace = " \t\r\n" meaning (#x20) (#x9) (#xD) (#xA)
********************************************************************************/
bool xqpStringStore::is_whitespace(uint32_t cp)
{
  bool res = (cp == 0x20 || cp == 0x9 || cp == 0xD || cp == 0xA) ? true : false;

  return res;
}


/*******************************************************************************
  Returns true if the characters given as 'start' and 'length' contain the
  codepoint 'cp'.
********************************************************************************/
bool xqpStringStore::is_contained(const char* start, uint16_t length, uint32_t cp)
{
  if( length != 0 && start != NULL)
  {
    for(uint16_t i = 0; i < length; ++i)
      if(UTF8Decode(start) == cp)
        return true;
  }
  return false;
}


/*******************************************************************************
  Returns true is cp represents "unreserved" as defined by rfc3986.
********************************************************************************/
bool xqpStringStore::is_unreservedCP(uint32_t cp)
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


/*******************************************************************************
  Returns true is cp reprezents "ucschar" as defined by rfc3987
********************************************************************************/
bool xqpStringStore::is_ucscharCP(uint32_t cp)
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


/*******************************************************************************
  Return true is cp represents "iprivate" as defined by rfc3987
********************************************************************************/
bool xqpStringStore::is_iprivateCP(uint32_t cp)
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


/*******************************************************************************
  Return true if cp is a printable characters of the US-ASCII coded character
  set meaning octets ranging from 32 to 126 (decimal).
********************************************************************************/
bool xqpStringStore::is_printableASCII(uint32_t cp)
{
  bool ret = false;
  if (0x20 <= cp && cp <=0x7E)//32 to 126 (decimal)
  {
    ret = true;
  }
  return ret;
}


/*******************************************************************************
  Return true for the following printable ASCII characters that are invalid in
  an IRI: "<", ">", " " " (double quote), space, "{", "}", "|", "\", "^", and "`".
********************************************************************************/
bool xqpStringStore::is_Invalid_in_IRI(uint32_t cp)
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


/*******************************************************************************

********************************************************************************/
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


xqpStringStore::xqpStringStore(serialization::Archiver& ar)
  :
  RCObject(ar)
{
}


xqpStringStore::~xqpStringStore() 
{
}


void xqpStringStore::serialize(serialization::Archiver& ar)
{
  ar & theString;
}


/*******************************************************************************

********************************************************************************/
ulong xqpStringStore::numChars() const
{
  const char* c = c_str();
  return UTF8Distance(c, c + bytes());
}


/*******************************************************************************

********************************************************************************/
xqpStringStore::char_type xqpStringStore::charAt(ulong charPos) const
{
  const char* c = c_str();

  while (charPos--)
    UTF8Decode(c);

  return UTF8Decode(c);
}


/*******************************************************************************

********************************************************************************/
checked_vector<uint32_t> xqpStringStore::getCodepoints() const
{
  checked_vector<uint32_t> tt;
  uint16_t vLength;

  vLength = numChars() + 1;
  const char* c = c_str();
  while( --vLength > 0 )
  {
    tt.push_back(UTF8Decode(c));
  }
  return tt;
}


/*******************************************************************************
  Returns true if every single character in the string is a whitespace
********************************************************************************/
bool xqpStringStore::is_whitespace() const
{
  const char* mystr = c_str();
  std::string::size_type i = 0;
  std::string::size_type mylen = bytes();

  for (i = 0; i < mylen; i++, mystr++)
    if (*mystr != 0x20 && *mystr != 0x9 && *mystr != 0xD && *mystr != 0xA)
      return false;

  return true;
}


/*******************************************************************************

********************************************************************************/
uint32_t xqpStringStore::hash(const XQPCollator* coll) const
{
  if(!coll)
  {
    return hash(c_str());
  }

  CollationKey collKey;
  UErrorCode status = U_ZERO_ERROR;

  ((Collator*)coll->theCollator)->getCollationKey(xqpString::getUnicodeString(this),
                                                  collKey,
                                                  status);

  if(U_FAILURE(status))
  {
    assert(false);
  }

  return collKey.hashCode();
}


/*******************************************************************************

********************************************************************************/
bool xqpStringStore::operator==(xqpStringStore::char_type ch) const
{
  return (charAt(0) == ch) && (numChars() == 1);
}


/*******************************************************************************

********************************************************************************/
bool xqpStringStore::byteEqual(const char* other, ulong otherBytes) const
{
  if(bytes() == otherBytes && memcmp(c_str(), other, otherBytes) == 0)
    return true;
  else
    return false;
}


/*******************************************************************************

********************************************************************************/
bool xqpStringStore::byteEqual(const xqpStringStore* other) const
{
  if (this == other)
    return true;

  return byteEqual(other->c_str(), other->bytes());
}


/*******************************************************************************
  Determine if "suffix" is a suffix of "this"
********************************************************************************/
bool xqpStringStore::byteEndsWith(const char* suffix, ulong suffixLen) const
{
  //TODO check if this condition is enough
  long pos = byteLastPositionOf(suffix, suffixLen);
  return (pos != -1 && (pos + suffixLen == bytes()));
}


/*******************************************************************************
  Locate the first occurrence of the "substr" substring after the given byte
  position of "this". Return the byte position into "this" of the start of 
  "substr", or -1 if not found.
********************************************************************************/
long xqpStringStore::bytePositionOf(
    const char* substr,
    ulong substrLen,
    ulong bytePos) const
{
  if (empty())
    return -1;

  ulong lRes = theString.find(substr, bytePos, substrLen);
  if (lRes == std::string::npos)
    return -1;
  else
    return lRes;
}


/*******************************************************************************

********************************************************************************/
long xqpStringStore::byteLastPositionOf(const char* substr, ulong substrLen) const
{
  size_t lRes = theString.rfind(substr, theString.size(), substrLen);

  if (lRes == std::string::npos)
    return -1;
  else
    return lRes;
}


/*******************************************************************************
  Create a new xqpStringStore with the char of "this" between bytePos and
  bytePos + lenght - 1
********************************************************************************/
xqpStringStore_t xqpStringStore::byteSubstr(
    ulong bytePos,
    ulong length) const
{
  return new xqpStringStore(theString.substr(bytePos, length));
}


/*******************************************************************************

********************************************************************************/
long xqpStringStore::compare(const xqpStringStore* other, const XQPCollator* coll) const
{
  if (this == other)
    return 0;

  if ( ! coll )
  {
    return theString.compare(other->theString);
  }

  Collator::EComparisonResult result = ::Collator::EQUAL;

  result = ((Collator*)coll->theCollator)->compare(xqpString::getUnicodeString(this),
                                                   xqpString::getUnicodeString(other));

  return result;
}


/*******************************************************************************
  Determine if "suffix" is a suffix of "this"
********************************************************************************/
bool xqpStringStore::endsWith(const xqpStringStore* suffix, XQPCollator* coll) const
{
  //TODO check if this condition is enough
  int lFound = lastPositionOf(suffix, coll);
  return (lFound != -1 && (lFound + suffix->numChars() == numChars()));
}


/*******************************************************************************
  Locate in "this" the first occurrence of the "pattern" substring, using the
  given collation. Return the position into "this" of the start of "substr", or
  -1 if not found.
********************************************************************************/
long xqpStringStore::positionOf(
    const xqpStringStore* substr,
    XQPCollator* coll) const
{
  if (empty())
    return -1;

  if ( ! coll )
  {
    size_t lRes = theString.find(substr->c_str());
    if (lRes == std::string::npos)
      return -1;
    else
      return lRes;
  }

  UErrorCode status = U_ZERO_ERROR;

  StringSearch search(xqpString::getUnicodeString(substr),
                      xqpString::getUnicodeString(this),
                      (RuleBasedCollator*)coll->theCollator, NULL, status);

  if(U_FAILURE(status))
  {
    assert(false);
    return -1;
  }

  for(long pos = search.first(status);
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


/*******************************************************************************

********************************************************************************/
long xqpStringStore::lastPositionOf(
    const xqpStringStore* substr,
    XQPCollator* coll) const
{
  if ( ! coll )
  {
    size_t lRes = theString.rfind(substr->c_str());
    if (lRes == std::string::npos)
      return -1;
    else
      return lRes;
  }

  UErrorCode status = U_ZERO_ERROR;

  StringSearch search(xqpString::getUnicodeString(substr),
                      xqpString::getUnicodeString(this),
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



/*******************************************************************************
  Return true if "this" mathes the given regular-expression pattern.
********************************************************************************/
bool xqpStringStore::matches(
    const char* pattern,
    std::string::size_type patternLength,
    const char* regexFlags) const
{
  UErrorCode status = U_ZERO_ERROR;

  UnicodeString uspattern = xqpString::getUnicodeString(pattern, patternLength);
  UnicodeString us = xqpString::getUnicodeString(this);
  
  RegexMatcher matcher(uspattern, parse_regex_flags(regexFlags), status);

  if (U_FAILURE(status)) 
  {
    throw zorbatypesException(pattern, ZorbatypesError::FORX0002);
    return false;
  }
  
  matcher.reset(us);

  return matcher.find() != 0;
}


/*******************************************************************************
  Returns a substring of the currents string starting at the given char position
  and continuing until the NULL termination.
********************************************************************************/
xqpStringStore_t xqpStringStore::substr(xqpStringStore::distance_type charPos) const
{
  if (charPos >= (int32_t)size())
  {
    charPos = size();
  }
  else if (charPos < 0)
  {
    return new xqpStringStore(theString);
  }

  const char* d = c_str();
  advance(d, charPos, d + size());

  return new xqpStringStore(d);
}


/*******************************************************************************

********************************************************************************/
xqpStringStore_t xqpStringStore::reverse() const
{
  xqpStringStore_t result = new xqpStringStore();
  char_type ch;
  const char* c = c_str();
  unsigned int len = numChars();
  for (unsigned int i=0; i<len; i++)
    UTF8Decode(c);

  for (unsigned int i=0; i<len; i++)
  {
    ch = UTF8DecodePrev(c);
    result->append_in_place(ch);
  }

  return result;
}

/*******************************************************************************

********************************************************************************/
xqpStringStore_t xqpStringStore::uppercase() const
{
  uint32_t i;
  uint32_t len = numChars();
  const char* c = c_str();
  uint32_t cp;
  char seq[5];

  std::auto_ptr<xqpStringStore> newStr(new xqpStringStore(""));

  for(i = 0; i < len; ++i)
  {
    cp = toUpper(UTF8Decode(c));
    memset(seq, 0, sizeof(seq));
    UTF8Encode(cp, seq);
    newStr->theString += seq;
  }
  newStr->theString += "\0";

  return newStr.release();
}


/*******************************************************************************

********************************************************************************/
xqpStringStore_t xqpStringStore::lowercase() const
{
  uint32_t i;
  uint32_t len = numChars();
  const char* c = c_str();
  uint32_t cp;
  char seq[5];

  //create the new xqpStringStore
  std::auto_ptr<xqpStringStore> newStr(new xqpStringStore(""));

  for(i = 0; i < len; ++i)
  {
    cp = toLower(UTF8Decode(c));
    memset(seq, 0, sizeof(seq));
    UTF8Encode(cp, seq);
    newStr->theString += seq;
  }
  newStr->theString += "\0";

  return newStr.release();
}


/*******************************************************************************
  Create a new xqpStringStore obj that is a suffix of "this". The suffix is
  defined by removing from "this" all of its leading chars that belong to a
  given set S of chars. S is defined as the 1st "len" chars in the "start"
  string.
********************************************************************************/
xqpStringStore_t xqpStringStore::trimL(const char* start, ulong len) const
{
  if(empty() || 0 == len)
    return const_cast<xqpStringStore *>(this);

  const char* c = c_str(), *c0 = c;

  uint32_t shortTrimCP[16];
  uint32_t* trimCP = (len <= 16) ? shortTrimCP : new uint32_t[len];

  for(uint16_t i = 0; i < len; i++)
    trimCP[i] = UTF8Decode(start);

  uint32_t StrLen;
  for (StrLen = numChars(); StrLen > 0; --StrLen) 
  {
    const char* oldc = c;
    uint32_t cp = UTF8Decode(c);
    bool found = true;

    for(uint16_t i = 0; i < len; i++) 
    {
      if(trimCP[i] == cp) 
      {
        found = false;
        break;
      }
    }

    if (found) 
    {
      c = oldc;
      break;
    }
  }

  if (trimCP != shortTrimCP)
    delete[] trimCP;

  if (c == c0)
    return const_cast<xqpStringStore *> (this);
  else
    return new xqpStringStore (c);
}


/*******************************************************************************

********************************************************************************/
xqpStringStore_t xqpStringStore::trimR(const char* start, ulong len) const
{
  if (empty() || 0 == len)
    return const_cast<xqpStringStore *>(this);

  uint32_t shortTrimCP [16];
  uint32_t* trimCP = (len <= 16) ? shortTrimCP : new uint32_t[len];

  for(uint16_t i = 0; i < len; i++)
    trimCP[i] = UTF8Decode(start);

  const char* str = c_str(), *end = str, *end0 = end;
  end += bytes();

  uint32_t StrLen = numChars();

  for (; StrLen > 0; --StrLen) 
  {
    const char *old_end = end;
    uint32_t cp = UTF8DecodePrev(end);

    uint16_t i;
    for(i = 0; i < len && trimCP[i] != cp; i++)
      ;

    if (i == len) 
    {
      end = old_end;
      break;
    }
  }

  if (trimCP != shortTrimCP)
    delete[] trimCP;

  if (end0 == end) 
    return const_cast<xqpStringStore *>(this);
  else
    return new xqpStringStore(str, end - str);
}


/*******************************************************************************

********************************************************************************/
xqpStringStore_t xqpStringStore::trim(const char* start, ulong len) const
{
  if(empty() || 0 == len)
    return new xqpStringStore(*this);

  return trimL(start, len)->trimR(start, len);
}


/*******************************************************************************
  Removes leading and trailing whitespace. Whitespace is any of the following:
  ' ', '\n', '\r', '\t'
********************************************************************************/
xqpStringStore_t xqpStringStore::trim() const
{
  if(empty())
    return new xqpStringStore("");

  const char* lSeq = " \n\r\t";
  xqpStringStore_t lTmpStr = trimL(lSeq, 4);
  return lTmpStr->trimR(lSeq, 4);
}


/*******************************************************************************

********************************************************************************/
void xqpStringStore::replace(
    xqpStringStore_t& result,
    const xqpStringStore* pattern,
    const xqpStringStore* replacement,
    const char* regexFlags) const
{
  UErrorCode status = U_ZERO_ERROR;

  UnicodeString uspattern = xqpString::getUnicodeString(pattern);
  UnicodeString us = xqpString::getUnicodeString(this);

  RegexMatcher matcher(uspattern, us, parse_regex_flags(regexFlags), status);

  if (U_FAILURE(status)) 
  {
    throw zorbatypesException(pattern->c_str(), ZorbatypesError::FORX0002);
  }

  if ((replacement->bytePositionOf("$", 1, 0) != -1 &&
       !replacement->matches("\\$[0-9]", 8, "")) ||
      (replacement->bytePositionOf("\\", 2, 0) != -1 &&
       !replacement->matches("\\$[0-9]", 8, "")))
  {
    // Invalid replacement string.
    throw zorbatypesException("", ZorbatypesError::FORX0004);
  }

  UnicodeString utf16result =
  matcher.replaceAll(xqpString::getUnicodeString(replacement), status);

  if (U_FAILURE(status)) 
  {
    result = new xqpStringStore("");
    // TODO: error
  }

  result = getXqpString(utf16result);
}


/*******************************************************************************

********************************************************************************/
xqpStringStore_t xqpStringStore::append(const xqpStringStore* suffix) const
{
  return new xqpStringStore(theString + suffix->str());
}


/*******************************************************************************

********************************************************************************/
xqpStringStore_t xqpStringStore::append(const char* suffix) const
{
  return new xqpStringStore(theString + suffix);
}


/*******************************************************************************
  Returns a new xqpStringStore by stripping leading and trailing whitespace and
  replacing sequences of one or more than one whitespace character with a single
  space, #x20.
********************************************************************************/
xqpStringStore_t xqpStringStore::normalizeSpace() const
{
  xqpStringStore_t newStr = new xqpStringStore;

  uint32_t len = numChars();
  const char* c = c_str();
  uint32_t cp, cpPrev;
  char seq[5];

  cpPrev = 0x20;

  while(len > 0)
  {
    cp = UTF8Decode(c);

    if( !is_whitespace(cp) ||
        (is_whitespace(cp) && !is_whitespace(cpPrev)))
    {
      if (is_whitespace(cp))
        cp = 0x20;

      memset(seq, 0, sizeof(seq));
      UTF8Encode(cp, seq);
      newStr->theString += seq;
    }
    cpPrev = cp;
    --len;
  }
  newStr->theString += "\0";

  return newStr->trimR();
}


/*******************************************************************************

********************************************************************************/
xqpStringStore_t xqpStringStore::normalize(const xqpStringStore* normMode) const
{
  UnicodeString result;
  UErrorCode status = U_ZERO_ERROR;

  if (normMode->empty())
  {
    return const_cast<xqpStringStore*>(this);
  }
  else if(normMode->byteEqual("NFC", 3))
  {
    Normalizer::normalize(xqpString::getUnicodeString(this), UNORM_NFC , 0, result, status);
  }
  else if(normMode->byteEqual("NFKC", 4))
  {
    Normalizer::normalize(xqpString::getUnicodeString(this), UNORM_NFKC , 0, result, status);
  }
  else if(normMode->byteEqual("NFD", 3))
  {
    Normalizer::normalize(xqpString::getUnicodeString(this), UNORM_NFD , 0, result, status);
  }
  else if(normMode->byteEqual("NFKD", 4))
  {
    Normalizer::normalize(xqpString::getUnicodeString(this), UNORM_NFKD , 0, result, status);
  }

  if(U_FAILURE(status))
  {
    assert(false);
  }

  return getXqpString(result);
}


/*******************************************************************************
  TODO: optimize
********************************************************************************/
xqpStringStore_t xqpStringStore::formatAsXML() const
{
  uint32_t i;
  uint32_t len = numChars();
  const char* c = c_str();
  uint32_t cp;
  char seq[5];

  std::auto_ptr<xqpStringStore> newStr(new xqpStringStore(""));

  for (i = 0; i < len; ++i)
  {
    cp = UTF8Decode(c);
    if ( (cp < 128) &&
         (cp != 34) &&   // quot == " == (double) quotation mark
         (cp != 38) &&   // amp == & == ampersand
         (cp != 39) &&   // apos == ' == apostrophe
         (cp != 60) &&   // lt == < == less-than sign
         (cp != 62))     // gt == > == greater-than sign
    {
      memset(seq, 0, sizeof(seq));
      UTF8Encode(cp, seq);
      newStr->theString += seq;
    }
    else
    {
      newStr->theString += '&';
      newStr->theString += '#';
      newStr->theString +=  Integer::parseInt(cp).toString()->c_str();
      newStr->theString += ';';
    }
  }
  newStr->theString += "\0";

  return newStr.release();
}


/*******************************************************************************
  Escape all characters except printable characters of the US-ASCII coded
  character set, specifically the octets ranging from 32 to 126 (decimal)
********************************************************************************/
xqpStringStore_t xqpStringStore::escapeHtmlUri() const
{
  uint32_t i;
  uint32_t len = numChars();
  const char* c = c_str();
  unsigned int cp;
  char seq[5];
  const char* prev = c_str();
  distance_type length;

  std::auto_ptr<xqpStringStore> newStr(new xqpStringStore(""));

  for(i = 0; i < len; ++i)
  {
    prev = c;
    cp = UTF8Decode(c);
    memset(seq, 0, sizeof(seq));
    if(is_printableASCII(cp))
    {
      UTF8Encode(cp, seq);
      newStr->theString += seq;
    }
    else
    {
      // codepoint has to be escaped
      length = sequence_length(prev);
      if(length != 1)
      {
        for(int j = 0; j < length; ++j)
        {
          cp = mask8(*prev);
          sprintf(seq, "%%%X", cp);
          newStr->theString += seq;
          prev++;
        }
      }
    }
  }
  newStr->theString += "\0";

  return newStr.release();
}


/*******************************************************************************
  Converts an xs:string containing an IRI into a URI according to the rules
  spelled out in Section 3.1 of http://www.ietf.org/rfc/rfc3987.txt
********************************************************************************/
xqpStringStore_t xqpStringStore::iriToUri() const
{
  uint32_t i;
  uint32_t len = numChars();
  const char* c = c_str();
  unsigned int cp;
  char seq[5];
  const char* prev = c_str();
  distance_type length;

  std::auto_ptr<xqpStringStore> newStr(new xqpStringStore(""));

  for (i = 0; i < len; ++i)
  {
    prev = c;
    cp = UTF8Decode(c);
    memset(seq, 0, sizeof(seq));

    if(!is_ucscharCP(cp) && !is_iprivateCP(cp) && !is_Invalid_in_IRI(cp))
    {
      UTF8Encode(cp, seq);
      newStr->theString += seq;
    }
    else
    {
      //codepoint has to be escaped
      length = sequence_length(prev);
      for(int j = 0; j < length;++j)
      {
        cp = mask8(*prev);
        sprintf(seq, "%%%X", cp);
        newStr->theString += seq;
        prev++;
        }
    }
  }
  newStr->theString += "\0";

  return newStr.release();
}


/*******************************************************************************
  The follwoing chars are safe for URIs:

  x2D        (-), 
  x2E        (.),
  x30 to x39 (the digits from 0 to 9),
  x41 to x5A (the letters A to Z),
  x5F        (_),
  x61 to x7A (the latters a to z),
  x7E        (~)
********************************************************************************/
const char SAFE[256] =
{
  /*      0 1 2 3  4 5 6 7  8 9 A B  C D E F */
  /* 0 */ 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0,
  /* 1 */ 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0,
  /* 2 */ 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,1,1,0,
  /* 3 */ 1,1,1,1, 1,1,1,1, 1,1,0,0, 0,0,0,0,

  /* 4 */ 0,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1,
  /* 5 */ 1,1,1,1, 1,1,1,1, 1,1,1,0, 0,0,0,1,
  /* 6 */ 0,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1,
  /* 7 */ 1,1,1,1, 1,1,1,1, 1,1,1,0, 0,0,1,0,

  /* 8 */ 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0,
  /* 9 */ 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0,
  /* A */ 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0,
  /* B */ 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0,

  /* C */ 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0,
  /* D */ 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0,
  /* E */ 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0,
  /* F */ 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0
};


/*******************************************************************************

********************************************************************************/
const char HEX2DEC[256] =
{
  /*       0  1  2  3   4  5  6  7   8  9  A  B   C  D  E  F */
  /* 0 */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
  /* 1 */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
  /* 2 */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
  /* 3 */  0, 1, 2, 3,  4, 5, 6, 7,  8, 9,-1,-1, -1,-1,-1,-1,

  /* 4 */ -1,10,11,12, 13,14,15,-1, -1,-1,-1,-1, -1,-1,-1,-1,
  /* 5 */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
  /* 6 */ -1,10,11,12, 13,14,15,-1, -1,-1,-1,-1, -1,-1,-1,-1,
  /* 7 */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,

  /* 8 */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
  /* 9 */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
  /* A */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
  /* B */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,

  /* C */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
  /* D */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
  /* E */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
  /* F */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1
};


/*******************************************************************************
  Escape all characters except for:
  - Upper and lowercase letters A-Z
  - digits 0-9,
  - HYPHEN-MINUS ("-"), LOW LINE ("_"), FULL STOP ".", and TILDE "~"
  - and also the characters defined by 'start' and 'length'
********************************************************************************/
void xqpStringStore::encodeForUri(
    xqpStringStore_t& result,
    const char* start,
    ulong length) const
{
  const char DEC2HEX[16 + 1] = "0123456789ABCDEF";

  const int srcLen = theString.length();
  const unsigned char* srcp = (const unsigned char *)c_str();
  const unsigned char* const srcEndp = srcp + srcLen;

  unsigned char* const buf = new unsigned char[srcLen * 4];
  unsigned char* destp = buf;


  for (; srcp < srcEndp; ++srcp)
  {
    // not encoding a / is a hack until the uri class can correctly encode paths
    if (SAFE[*srcp] || is_contained(start, length, *srcp))
    {
      *destp++ = *srcp;
    }
    else
    {
      // escape this char
      *destp++ = '%';
      *destp++ = DEC2HEX[*srcp >> 4];
      *destp++ = DEC2HEX[*srcp & 0x0F];
    }
  }

  result = new xqpStringStore((char*)buf, (char*)destp);

  delete [] buf;
}


/*******************************************************************************
  Reverse the effect of encodeForUri().
********************************************************************************/
void xqpStringStore::decodeFromUri(xqpStringStore_t& result) const
{
  std::ostringstream os;

  ulong srcLen = theString.length();

  for (ulong i = 0; i < srcLen; ++i) 
  {
    const char* c = c_str() + i;

    if  ((*c == '%') & (i < srcLen - 2)) 
    {
      char dec1, dec2;
      if ( (dec1 = HEX2DEC[(const unsigned char) *(c + 1)]) != -1 &&
           (dec2 = HEX2DEC[(const unsigned char) *(c + 2)]) != -1 ) 
      {
        os <<  (char)((dec1 << 4) + dec2);
        i += 2;
        continue;
      }
    }

    os << (char)*c;
  }

  result = new xqpStringStore(os.str());
}


/*******************************************************************************

********************************************************************************/
void xqpStringStore::clear()
{
  theString.erase();
}


/*******************************************************************************

********************************************************************************/
void xqpStringStore::append_in_place(const char c)
{
  theString += c;
}


/*******************************************************************************

********************************************************************************/
void xqpStringStore::append_in_place(uint32_t cp)
{
  char seq[5] = {0,0,0,0,0};
  UTF8Encode(cp, seq);
  theString += seq;
}


/*******************************************************************************

********************************************************************************/
void xqpStringStore::append_in_place(const xqpStringStore* suffix)
{
  theString += suffix->theString;
}


/*******************************************************************************

********************************************************************************/
void xqpStringStore::append_in_place(const xqpStringStore* suffix, const char* s2)
{
  theString += suffix->theString;
  theString += s2;
}


/*******************************************************************************

********************************************************************************/
void xqpStringStore::append_in_place(const char* str)
{
  theString += str;
}


/*******************************************************************************

********************************************************************************/
void xqpStringStore::append_in_place(const char* str, ulong len)
{
  theString.append(str, len);
}


/*******************************************************************************

********************************************************************************/
xqpStringStore& xqpStringStore::operator+=(const xqpStringStore_t& suffix)
{
  theString += suffix->theString;
  return *this;
}


/*******************************************************************************

********************************************************************************/
xqpStringStore& xqpStringStore::operator+=(const char* suffix)
{
  theString += suffix;
  return *this;
}


/*******************************************************************************

********************************************************************************/
std::ostream& operator<<(std::ostream& os, const xqpStringStore& src)
{
  //TODO is there a need to perform charset conversion to/from the current locale ?!?!
  os << src.theString;
  return os;
}





void xqpString::serialize(serialization::Archiver &ar)
{
  ar & theStrStore;
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

xqpString::xqpString(const wchar_t * src)
{
  UnicodeString tmp;
  UErrorCode ErrorCode = U_ZERO_ERROR;
  UChar* dest = tmp.getBuffer(wcslen(src)+1);
  
  int32_t DestLength;

  //convert from std::wstring to UTF16 encoded string
  u_strFromWCS(dest, wcslen(src) + 1, &DestLength, src, -1, &ErrorCode);
  
  if(U_FAILURE(ErrorCode))
  {
    assert(false);
  }

  int32_t targetLen = u_strlen(dest)*4 + 1;
  char* target = new char[targetLen];

  //convert from UTF16 to UTF8
  u_strToUTF8(target, targetLen, &DestLength, dest, -1, &ErrorCode);
  tmp.releaseBuffer (wcslen(src));

  if(U_FAILURE(ErrorCode))
  {
    assert(false);
    
    theStrStore = new xqpStringStore("");
    delete[] target;
  }

  theStrStore = new xqpStringStore(&target[0], DestLength);
  delete[] target;
}

xqpString::xqpString(const UnicodeString aSrc)
{
  theStrStore = getXqpString(aSrc);
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
  theStrStore->theString.reserve(5);
  char seq[5] = {0,0,0,0,0};
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
  temp->theString += src;
  theStrStore = temp;
  return *this;
}


xqpString& xqpString::operator+=(const char* src)
{
  xqpStringStore_t temp = new xqpStringStore(*theStrStore);
  temp->theString += src;
  theStrStore = temp;
  return *this;
}


xqpString& xqpString::operator+=(uint32_t cp)
{
  theStrStore->theString.reserve(5);
  char seq[5] = {0,0,0,0,0};
  UTF8Encode(cp, seq);
  theStrStore = new xqpStringStore(theStrStore->theString + seq);
  
  return *this;
}


xqpString& xqpString::operator+=(char c)
{
  theStrStore = new xqpStringStore(theStrStore->theString + c);
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

std::ostream& operator<<(std::ostream& os, xqpStringStore_t str)
{
  //TODO is there a need to perform charset conversion to/from the current locale ?!?!
  os << *str;
  return os;
}

  std::ostream& operator<<(std::ostream& os, xqpString utf8_src)
  {
    //TODO is there a need to perform charset conversion to/from the current locale ?!?!
    os << *utf8_src.theStrStore;
    return os;
  }

  int xqpString::compare(const char* src, XQPCollator* coll) const
  {
    //TODO optimize the code here
    xqpString tmp(src);
    return compare(tmp, coll);
  }

  uint32_t xqpString::hash(XQPCollator* coll) const
  {
    return theStrStore->hash(coll);
  }

  void xqpString::reserve(xqpString::size_type size)
  {
    theStrStore->theString.reserve(size);
  }

  //xqpString::Clear
  void xqpString::clear()
  {
    theStrStore->theString.erase();
  }


xqpString xqpString::substr(xqpString::size_type index, xqpString::size_type length) const
{
  char* target;
  int32_t size =  length*4 + 1;
  target = new char[size]; //will hold UTF-8 encoded characters
  UnicodeString str = getUnicodeString(theStrStore);

  int32_t targetsize = str.extract(index, length, target, size, "UTF-8");
  target[targetsize] = 0; /* NULL termination */

  xqpString ret(&target[0]);

  delete [] target;
  return ret;
}


xqpString xqpString::substr(xqpStringStore::distance_type index) const
{
  if(index >= (int32_t)length())
  {
    index = length();
  }
  else if(index < 0)
  {
    xqpString ret(theStrStore->theString);
    return ret;
  }

  const char * d = theStrStore->c_str();
  advance(d, index, d+length());

  xqpString ret(d);

  return ret;
}


const char* xqpString::c_str() const
{
  return theStrStore->c_str();
}


xqpString xqpString::normalize(xqpString normMode)
{
  return theStrStore->normalize(normMode.getStore()).getp();
}


std::map<uint32_t,uint32_t> xqpString::createMapArray(xqpString mapString, xqpString transString) const
{
  uint16_t      mapLen    = mapString.length();
  uint16_t      transLen  = transString.length();
  const char*   mapPtr    = mapString.theStrStore->c_str();
  const char*   transPtr  = transString.theStrStore->c_str();
  uint32_t      tmp0, tmp1;

  std::map<uint32_t,uint32_t> mapArray;
  std::map<uint32_t,uint32_t>::iterator it;

  if(mapLen >0)
  {
    while((mapLen > 0) && (transLen > 0))
    {
      tmp0 = UTF8Decode(mapPtr);
      tmp1 = UTF8Decode(transPtr);
      mapArray.insert(std::pair<uint32_t,uint32_t>(tmp0, tmp1));
      --mapLen;
      --transLen;
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


xqpString xqpString::translate(xqpString mapString, xqpString transString) const
{
  std::map<uint32_t,uint32_t>           myMap;
  std::map<uint32_t,uint32_t>::iterator it;

  //create the map
  myMap = createMapArray(mapString, transString);

  //create the new xqpStringStore
  std::string tmp = "";
  uint32_t len = length();
  const char* c = c_str();
  uint32_t cp, i;
  char seq[5];

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

  xqpString res(tmp.c_str());
  return res;
}



bool
xqpString::matches(const xqpString& pattern, xqpString flags) const
{
  UErrorCode    status = U_ZERO_ERROR;
  UnicodeString uspattern = getUnicodeString (pattern.getStore()),
    us = getUnicodeString (this->getStore());
  
  RegexMatcher matcher (uspattern, parse_regex_flags (flags.c_str ()), status);
  if (U_FAILURE(status)) {
    throw zorbatypesException(pattern.c_str(), ZorbatypesError::FORX0002);
    return false;
  }
  
  matcher.reset (us);
  return matcher.find () != 0;
}


xqpString
xqpString::replace(xqpString pattern, xqpString replacement, xqpString flags)
{
    UErrorCode status = U_ZERO_ERROR;
    UnicodeString uspattern = getUnicodeString (pattern.getStore()),
    us = getUnicodeString (this->getStore());

    RegexMatcher matcher (uspattern, us, parse_regex_flags (flags.c_str ()), status);
    if (U_FAILURE(status)) {
      throw zorbatypesException(pattern.c_str(), ZorbatypesError::FORX0002);
      return "";
    }

    //if((replacement.indexOf("$") != -1 && !replacement.matches("\\$[0-9]",""))||
    //    (replacement.indexOf("\\") != -1 && !replacement.matches("\\$[0-9]","")))
    //{
    //  throw zorbatypesException("", ZorbatypesError::FORX0004);
    //  return "";
    //}

    UnicodeString result = matcher.replaceAll (getUnicodeString(replacement.getStore()), status);
    if (U_FAILURE(status)) {
      return "";
      // TODO: error
    }
    return getXqpString(result).getp();
}


xqpString
xqpString::tokenize(
    xqpString pattern,
    xqpString flags,
    int32_t* start_pos,
    bool* hasmatched) const
{
  int32_t pos = *start_pos;
  UErrorCode status = U_ZERO_ERROR;
  UnicodeString uspattern = getUnicodeString(pattern.getStore());
  UnicodeString us = getUnicodeString(this->getStore());

  RegexMatcher m (uspattern, us, parse_regex_flags (flags.c_str ()), status);
  if (U_FAILURE(status))
  {
    throw zorbatypesException(pattern.c_str(), ZorbatypesError::FORX0002);
    return "";
  }

  if(m.find(*start_pos, status))
  {
    *hasmatched = true;
    int32_t start = m.start (status), end = m.end (status);
    *start_pos = end;
    return substr (pos, start - pos);
  }
  else
  {
    *hasmatched = false;
    *start_pos = length ();
    return substr (pos, length ());
  }
}


wchar_t * xqpString::getWCS(xqpString aSrc,
                           int32_t *aDestLen)
{
  return getWCS(aSrc.c_str(), aSrc.length(), aDestLen);
}

wchar_t * xqpString::getWCS(const char * aSrc,
                            const unsigned int aSrcLen,
                            int32_t *aDestLen)
{
  wchar_t* wDest = NULL;
  int32_t wDestLen = 0;
  int32_t reqLen= 0;

  UnicodeString unicodeStr = getUnicodeString(aSrc, aSrcLen);
  const UChar* srcBuf = unicodeStr.getBuffer();
  int32_t uSrcLen = unicodeStr.length();
  UErrorCode status = U_ZERO_ERROR;

  if(NULL != srcBuf)
  {
    //pre-flight
    u_strToWCS(wDest, wDestLen, &reqLen, srcBuf, uSrcLen, &status);

    if(status == U_BUFFER_OVERFLOW_ERROR)
    {
      status=U_ZERO_ERROR;
      wDest = (wchar_t*) malloc(sizeof(wchar_t) * (reqLen+1));
      wDestLen = reqLen + 1;
      u_strToWCS(wDest, wDestLen, &reqLen, srcBuf, uSrcLen, &status);
    }
  }

  unicodeStr.releaseBuffer ();

  if(U_FAILURE(status))
  {
    assert(false);
  }

  *aDestLen = wDestLen;
  return wDest;
}

void xqpString::append_in_place(const char c)
{
  theStrStore->append_in_place(c);
}

void xqpString::append_in_place(uint32_t cp)
{
  theStrStore->append_in_place(cp);
}

void xqpString::append_in_place(const xqpStringStore *suffix)
{
  theStrStore->append_in_place(suffix);
}

void xqpString::append_in_place(const xqpStringStore *suffix, const char *s2)
{
  theStrStore->append_in_place(suffix, s2);
}

void xqpString::append_in_place(const char *str)
{
  theStrStore->append_in_place(str);
}

void xqpString::append_in_place(const char *str, int len)
{
  theStrStore->append_in_place(str, len);
}



//static concat
xqpString xqpString::concat(const char *s1,
                            const char *s2)
{
//  int l1 = strlen(s1);
//  int l2 = strlen(s2);

  xqpString   result;//(l1+l2+1);
  result.theStrStore->theString.reserve(strlen(s1) + strlen(s2) + 1);
  result.append_in_place(s1);
  result.append_in_place(s2);
  return result;
}

xqpString xqpString::concat(const char *s1,
                        const char *s2,
                        const xqpStringStore_t s3)
{
//  int l1 = strlen(s1);
//  int l2 = strlen(s2);
//  int l3 = s3->bytes();

  xqpString   result;//(l1+l2+l3+1);
  result.theStrStore->theString.reserve(strlen(s1) + strlen(s2) + s3->bytes() + 1);
  result.append_in_place(s1);
  result.append_in_place(s2);
  result.append_in_place(s3.getp());
  return result;
}

xqpString xqpString::concat(const char *s1,
                        const char *s2,
                        const char *s3)
{
//  int l1 = strlen(s1);
//  int l2 = strlen(s2);
//  int l3 = strlen(s3);

  xqpString   result;//(l1+l2+l3+1);
  result.theStrStore->theString.reserve(strlen(s1) + strlen(s2) + strlen(s3) + 1);
  result.append_in_place(s1);
  result.append_in_place(s2);
  result.append_in_place(s3);
  return result;
}

xqpString xqpString::concat(xqpString s1,
                        const char *s2,
                        const xqpString s3)
{
//  int l1 = s1.bytes();
//  int l2 = strlen(s2);
//  int l3 = s3.bytes();

  xqpString   result;//(l1+l2+l3+1);
  result.theStrStore->theString.reserve(s1.bytes() + strlen(s2) + s3.bytes() + 1);
  result.append_in_place(s1.getStore());
  result.append_in_place(s2);
  result.append_in_place(s3.getStore());
  return result;
}

xqpString xqpString::concat(const xqpString s1,
                        const xqpString s3)
{
//  int l1 = s1.bytes();
//  int l2 = strlen(s2);
//  int l3 = s3.bytes();

  xqpString   result;//(l1+l2+l3+1);
  result.theStrStore->theString.reserve(s1.bytes() + s3.bytes() + 1);
  result.append_in_place(s1.getStore());
  result.append_in_place(s3.getStore());
  return result;
}

xqpString xqpString::concat(const std::string &s1,
                        const char *s2,
                        const xqpStringStore_t s3)
{
//  int l1 = s1.length();
//  int l2 = strlen(s2);
//  int l3 = s3->bytes();

  xqpString   result;//(l1+l2+l3+1);
  result.theStrStore->theString.reserve(s1.length() + strlen(s2) + s3->bytes() + 1);
  result.append_in_place(s1.c_str());
  result.append_in_place(s2);
  result.append_in_place(s3.getp());
  return result;
}

xqpString xqpString::concat(const xqpStringStore_t s1,
                        const char *s2,
                        const xqpString s3,
                        const char *s4)
{
//  int l1 = s1->bytes();
//  int l2 = strlen(s2);
//  int l3 = s3.bytes();
//  int l4 = strlen(s4);

  xqpString   result;//(l1+l2+l3+l4+1);
  result.theStrStore->theString.reserve(s1->bytes() + strlen(s2) + s3.bytes() + strlen(s4) + 1);
  result.append_in_place(s1.getp());
  result.append_in_place(s2);
  result.append_in_place(s3.getStore());
  result.append_in_place(s4);
  return result;
}

xqpString xqpString::concat(const char *s1,
                        const std::string &s2,
                        const char *s3,
                        const xqpStringStore_t s4,
                        const char *s5)
{
//  int l1 = strlen(s1);
//  int l2 = s2.length();
//  int l3 = strlen(s3);
//  int l4 = s4->bytes();
//  int l5 = strlen(s5);

  xqpString   result;//(l1+l2+l3+l4+l5+1);
  result.theStrStore->theString.reserve(strlen(s1) + s2.length() + strlen(s3) + s4->bytes() + strlen(s5) + 1);
  result.append_in_place(s1);
  result.append_in_place(s2.c_str());
  result.append_in_place(s3);
  result.append_in_place(s4.getp());
  result.append_in_place(s5);
  return result;
}

}/* namespace zorba */

#endif//#ifndef ZORBA_NO_UNICODE
