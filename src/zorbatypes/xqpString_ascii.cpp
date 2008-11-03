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
#include "common/common.h"
#ifdef ZORBA_NO_UNICODE

//#include <unicode/regex.h>
#include "zorbatypes/xqpstring_ascii.h"

//#include "zorbatypes/Unicode_util.h"
//#include "zorbatypes/utf8.h"
#include "zorbatypes/numconversions.h"
//#include "zorbatypes/collation_manager.h"
#include "zorbatypesError.h"

#include "regex_ascii.h"

using namespace std;


namespace zorba
{

//UnicodeString getUnicodeString(xqpStringStore *strstore);


/*******************************************************************************
  whitespace = " \t\r\n" meaning (#x20) (#x9) (#xD) (#xA)
********************************************************************************/
bool xqpStringStore::is_whitespace(uint32_t cp)
{
  bool res = (cp == 0x20 || cp == 0x9 || cp == 0xD || cp == 0xA) ? true : false;

  return res;
}

/*******************************************************************************
  Returns true returns true if the characters given as 'start' and 'length'
  contain the codepoint 'cp'.
********************************************************************************/
bool xqpStringStore::is_contained(const char* start, uint16_t length, uint32_t cp)
{
  if( length != 0 && start != NULL) 
  {
    for(uint16_t i = 0; i < length; i++)
    {
      if(start[i] == cp) 
      {
        return true;
      }
    }
  }
  return false;
}

/*******************************************************************************
  Returns true is cp reprezents "unreserved" as defined by rfc3986.
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
  Return true is cp reprezents "iprivate" as defined by rfc3987
********************************************************************************/
bool xqpStringStore::is_iprivateCP( uint32_t cp )
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
  if(0x20 <= cp && cp <=0x7E)//32 to 126 (decimal)
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

/*******************************************************************************

********************************************************************************/
uint32_t xqpStringStore::hash(XQPCollator* coll) const
{
//    if(!coll) {
        return hash(c_str());
//    }

//    CollationKey collKey;
//    UErrorCode status = U_ZERO_ERROR;
    
//    coll->theCollator->getCollationKey(getUnicodeString(this), collKey, status);

//    if(U_FAILURE(status))
//    {
//      assert(false);
//    }
     
//    return collKey.hashCode();
/*
  uint32_t hash = 5381;
  std::string::const_iterator  cit;
  for(cit = theString.begin(); cit != theString.end(); cit++)
  {
    hash = ((hash << 5) + hash) + *cit; // hash*33 + c
  }
  return hash;
*/
}


/*******************************************************************************

********************************************************************************/
void xqpStringStore::clear()
{
  theString.erase();
}


/*******************************************************************************

********************************************************************************/
std::string::size_type xqpStringStore::numChars() const
{
//  const char* c = c_str();
//  return UTF8Distance(c, c + bytes());
  return theString.size();
}


/*******************************************************************************

********************************************************************************/
bool xqpStringStore::byteEqual(const xqpStringStore& src) const
{
  if (this == &src)
    return true;

//  uint32_t len = bytes();
//
//  if(len == src.bytes() && memcmp(c_str(), src.c_str(), len) == 0)
//    return true;

  if(src.theString == theString)
    return true;

  return false;
}


bool xqpStringStore::byteEqual(const char* src, uint32_t srclen) const
{
  //if(bytes() == srclen) && memcmp(c_str(), src, srclen) == 0)
  //  return true;
  //return false;
  
  if(bytes() != srclen)
    return false;
  
  //compare strings from back to front
  const char  *s1 = c_str();
  uint32_t    llen = srclen>>2;
  const long *l2 = ((long*)src) + llen - 1;
  const long *l1 = ((long*)s1) + llen - 1;
  for(;l2>=(const long*)src;l2--, l1--)
  {
    if(*l1 != *l2)
      return false;
  }
  s1 += llen<<2;
  src += llen<<2;
  while(*s1)
  {
    if(*s1 != *src)
      return false;
    s1++;
    src++;
  }

  return true;
}

bool xqpStringStore::byteEqual(const char* src) const
{
  const char  *mystr = c_str();
  int   i = 0;

  do
  {
    if(mystr[i] != src[i])
      return false;
  }while(mystr[i++]);

  return true;
}


int xqpStringStore::compare(const xqpStringStore* src, XQPCollator* coll) const
{
//  if ( ! coll )
    return theString.compare(src->theString);

//  Collator::EComparisonResult result = ::Collator::EQUAL;
//
//  result = coll->theCollator->compare(getUnicodeString(this),
//                                      src->getUnicodeString());
//
//  return result;
}


/*******************************************************************************
  Locate in "this" the first occurrence of the "pattern" substring. Return the
  offset into this of the start of "pattern", or -1 if not found.
********************************************************************************/
int32_t xqpStringStore::indexOf(const char* pattern) const
{
  if (empty())
    return -1;

  size_t lRes = theString.find(pattern);
  return (lRes == std::string::npos) ? -1 : lRes;
}


/*******************************************************************************
  Locate in "this" the first occurrence of the "pattern" substring, using the
  given collation. Return the offset into this of the start of "pattern", or
  -1 if not found.
********************************************************************************/
int32_t xqpStringStore::indexOf(const xqpStringStore* pattern, XQPCollator* coll) const
{
  if (empty())
    return -1;

//  if ( ! coll ) 
  {
    size_t lRes = theString.find(pattern->c_str());
    return (lRes == std::string::npos) ? -1 : lRes;
  }

//  UErrorCode status = U_ZERO_ERROR;
//
//  StringSearch search(pattern->getUnicodeString(),
//                      getUnicodeString(), 
//                      (RuleBasedCollator*)coll->theCollator, NULL, status);
//
//  if(U_FAILURE(status))
//  {
//    assert(false);
//    return -1;
//  }
//
//  for(int16_t pos = search.first(status);
//      U_SUCCESS(status) && pos != USEARCH_DONE;
//      pos = search.next(status))
//  {
//    return pos;
//  }
//
//  if (U_FAILURE(status))
//  {
//    assert(false);
//    return -1;
//  }
//  return -1;
}


/*******************************************************************************

********************************************************************************/
int32_t xqpStringStore::lastIndexOf(const char* pattern) const
{
  size_t lRes = theString.rfind(pattern);
  return (lRes == std::string::npos) ? -1 : lRes;
}


/*******************************************************************************

********************************************************************************/
int32_t xqpStringStore::lastIndexOf(const xqpStringStore* pattern, XQPCollator* coll) const
{
//  if ( ! coll )
  {
    size_t lRes = theString.rfind(pattern->c_str());
    return (lRes == std::string::npos) ? -1 : lRes;
  }

  //UErrorCode status = U_ZERO_ERROR;

  //StringSearch search(pattern->getUnicodeString(),
  //                    getUnicodeString(), 
  //                    (RuleBasedCollator *)coll->theCollator, NULL, status);

  //if(U_FAILURE(status))
  //{
  //  assert(false);
  //  return -1;
  //}

  //int32_t pos = search.last(status);
  //if (U_FAILURE(status))
  //{
  //  assert(false);
  //  return -1;
  //}

  //if(U_SUCCESS(status) && pos != USEARCH_DONE)
  //{
  //  //TODO check if this condition is enough
  //  return pos;
  //}

  //return -1;
}


/*******************************************************************************
  Determine if "pattern" is a suffix of "this"
********************************************************************************/
bool xqpStringStore::endsWith(const char* pattern) const
{
  int pattern_len = strlen(pattern);
  int mylen = bytes();
  if(pattern_len < mylen)
    return false;
  if(!memcmp(c_str()+ mylen - pattern_len, pattern, pattern_len))
    return true;
  return false;
}


/*******************************************************************************
  Determine if "pattern" is a suffix of "this"
********************************************************************************/
bool xqpStringStore::endsWith(const xqpStringStore* pattern, XQPCollator* coll) const
{
  int pattern_len = pattern->bytes();
  int mylen = bytes();
  if(pattern_len < mylen)
    return false;
  if(!memcmp(c_str()+ mylen - pattern_len, pattern->c_str(), pattern_len))
    return true;
  return false;
}


/*******************************************************************************

********************************************************************************/
xqpStringStore_t xqpStringStore::append(const xqpStringStore_t& suffix) const
{
  return new xqpStringStore(theString + suffix->str());
}


xqpStringStore_t xqpStringStore::append(const std::string& suffix) const
{
  return new xqpStringStore(theString + suffix);
}


xqpStringStore_t xqpStringStore::append(const char* suffix) const
{
  return new xqpStringStore(theString + suffix);
}

void xqpStringStore::append_in_place(const char c)
{
  theString += c;
}

void xqpStringStore::append_in_place(const xqpStringStore* suffix)
{
  theString += suffix->theString;
}

void xqpStringStore::append_in_place(const xqpStringStore* suffix, const char *s2)
{
  theString += suffix->theString;
  theString += s2;
}

void xqpStringStore::append_in_place(const char *str)
{
  theString += str;
}

void xqpStringStore::append_in_place(const char *str, int len)
{
  theString.append(str, len);
}

void xqpStringStore::append_in_place(const std::string &str)
{
  theString.append(str);
}

/*******************************************************************************

********************************************************************************/
xqpStringStore_t xqpStringStore::substr(
    std::string::size_type index,
    std::string::size_type length) const
{
  return new xqpStringStore(theString.substr(index, length));
}

/*******************************************************************************

********************************************************************************/
xqpStringStore_t xqpStringStore::uppercase() const
{
  //uint32_t i;
  //uint32_t len = numChars();
  //const char* c = c_str();
  //uint32_t cp;
  //char seq[4];

  //std::auto_ptr<xqpStringStore> newStr(new xqpStringStore(""));

  //for(i = 0; i < len; ++i)
  //{
  //  cp = toUpper(UTF8Decode(c));
  //  memset(seq, 0, sizeof(seq));
  //  UTF8Encode(cp, seq);
  //  newStr->theString += seq;
  //}
  //newStr->theString += "\0";

  //return newStr.release();

  int   sz = theString.size();
  xqpStringStore  *strstore = new xqpStringStore("");
  strstore->theString.reserve(sz+2);

  std::string::const_iterator  cit;
  for(cit = theString.begin(); cit != theString.end(); cit++)
  {
    strstore->theString.append(1, toupper(*cit));
  }
  //strstore->theString.append(1, 0);

  return strstore;
}


/*******************************************************************************

********************************************************************************/
xqpStringStore_t xqpStringStore::lowercase() const
{
  //uint32_t i;
  //uint32_t len = numChars();
  //const char* c = c_str();
  //uint32_t cp;
  //char seq[4];

  ////create the new xqpStringStore
  //std::auto_ptr<xqpStringStore> newStr(new xqpStringStore(""));

  //for(i = 0; i < len; ++i)
  //{
  //  cp = toLower(UTF8Decode(c));
  //  memset(seq, 0, sizeof(seq));
  //  UTF8Encode(cp, seq);
  //  newStr->theString += seq;
  //}
  //newStr->theString += "\0";

  //return newStr.release();
  int   sz = theString.size();
  xqpStringStore  *strstore = new xqpStringStore("");
  strstore->theString.reserve(sz+2);

  std::string::const_iterator  cit;
  for(cit = theString.begin(); cit != theString.end(); cit++)
  {
    strstore->theString.append(1, tolower(*cit));
  }
  //strstore->theString.append(1, 0);

  return strstore;
}


/*******************************************************************************
  Returns a new xqpString by stripping leading and trailing whitespace and
  replacing sequences of one or more than one whitespace character with a
  single space, #x20.
********************************************************************************/
xqpStringStore_t xqpStringStore::normalizeSpace() const
{
  //create the new xqpStringStore
  xqpStringStore *newStr = new xqpStringStore("");

  uint32_t len = numChars();
  newStr->theString.reserve(len+2);

  const unsigned char* c = (unsigned char*)c_str();
  uint32_t cp;
//  char seq[4];
  bool  wsp = false;
  bool  strstarted = false;

  while(c[0])
  {
    cp = c[0];//UTF8Decode(c);
    c++;
    if( is_whitespace(cp))
    {
      //if(strstarted)
        wsp = true;
      continue;
    }
    if(strstarted && wsp)
      newStr->theString += 0x20;
    newStr->theString += cp;
    strstarted = true;
    wsp = false;
  }
  if(!strstarted && wsp)
  {
    c = (unsigned char*)c_str();
    if((c[0] == '\t') && (c[1] == 0))
      newStr->theString = '\t';
    else
      newStr->theString = 0x20;
  }
  //newStr->theString += "\0";

  return newStr;//->trimR();
}


/*******************************************************************************
  Create a new xqpStringStore obj that is a suffix of "this". The suffix is
  defined by removing from "this" all of its leading chars that belong to a
  given set S of chars. S is defined as the 1st "len" chars in the "start"
  string. 
********************************************************************************/
xqpStringStore_t xqpStringStore::trimL(const char* start, uint16_t len) const
{
  if(empty() || 0 == len)
    return new xqpStringStore(*this);

  //create the new xqpStringStore
  std::auto_ptr<xqpStringStore> newStr(new xqpStringStore(""));

  uint32_t StrLen = numChars();
  const char* c = c_str();

//  uint32_t* trimCP;//[len];
//  trimCP = new uint32_t[len];
//  for(uint16_t i = 0; i < len; i++)
//    trimCP[i] = UTF8Decode(start);

  bool found = true; 
//  bool firstCp = true;
  char cp;
  
  while(StrLen && found)
  {
    cp = c[0];//UTF8Decode(c);

    found = false;
    for(uint16_t i = 0; i < len; i++)
    {
      if(start[i] == cp)
      {
        //firstCp = false;
        found = true;
        c++;
        StrLen--;
        break;
      }
    }
  }
  
  newStr->theString.append(c, StrLen);

//  delete[] trimCP;
  return newStr.release();
}
  

/*******************************************************************************

********************************************************************************/
xqpStringStore_t xqpStringStore::trimL() const
{
  char seq = ' ';
  return trimL( &seq, 1 );
}


/*******************************************************************************

********************************************************************************/
xqpStringStore_t xqpStringStore::trimR(const char* start, uint16_t len) const
{
  if(empty() || 0 == len )
    return new xqpStringStore(*this);
    
  //uint32_t StrLen = numChars();

  //uint32_t* trimCP;//[len];
  //trimCP = new uint32_t[len];
  //for(uint16_t i = 0; i < len; i++)
  //  trimCP[i] = UTF8Decode(start);

  ////create the new xqpStringStore
  //std::auto_ptr<xqpStringStore> newStr(new xqpStringStore(""));

  //uint32_t pos = 0;
  //uint32_t cp = 0;
  //const char* end = c_str();
  //const char* c = c_str();
  //char seq[4];

  //zorba::advance(end, StrLen, end + bytes());

  //bool firstCp = true;

  //while(StrLen > 0)
  //{
  //  cp = UTF8DecodePrev(end);

  //  for(uint16_t i=0; i<len; i++)
  //  {
  //    if(trimCP[i] == cp)
  //    {
  //      firstCp = false;
  //      break;
  //    }
  //  }
  //    
  //  if( firstCp )
  //  {
  //    pos = zorba::UTF8Distance(c, end);
  //    break;
  //  }
  //  --StrLen;
  //  firstCp = true;
  //}
  //  
  //++pos;

  //while(pos > 0)
  //{
  //  cp = UTF8Decode(c);
  //    
  //  memset(seq, 0, sizeof(seq));
  //  UTF8Encode(cp, seq);
  //  newStr->theString += seq;
  //  
  //  --pos;
  //}

  //delete[] trimCP;
  //return newStr.release();

  uint32_t StrLen = numChars();
  xqpStringStore *newStr = new xqpStringStore("");

  int   trimsize = 0;
  char  cp;
  bool  found = false;
  std::string::const_reverse_iterator cit;
  for(cit = theString.rbegin(); cit != theString.rend();cit++)
  {
    cp = *cit;
    found = false;
    for(uint16_t i=0; i<len; i++)
    {
      if(start[i] == cp)
      {
        found = true;
        break;
      }
    }
    if(found)
      trimsize++;
    else
      break;
  }

  newStr->theString.append(theString, 0, StrLen-trimsize);

  return newStr;
}
  

/*******************************************************************************

********************************************************************************/
xqpStringStore_t xqpStringStore::trimR() const
{
  char seq = ' ';
  return trimR( &seq, 1 );
}


/*******************************************************************************

********************************************************************************/
xqpStringStore_t xqpStringStore::trim(const char* start, uint16_t len) const
{
  if(empty() || 0 == len)
    return new xqpStringStore(*this);

  //xqpStringStore_t tmp = trimL(start, len);
  //return tmp->trimR(start, len);
  //create the new xqpStringStore

 xqpStringStore   *newStr = new xqpStringStore("");

  const char* c = c_str();
  int   sz = theString.size();
  //char  cp;
  int   off1 = 0;
  int   off2 = sz-1;
  bool  found = true;
  int   i;

  while(c[off1] && found)
  {
    found = false;
    for(i=0;i<len;i++)
    {
      if(start[i] == c[off1])
      {
        found = true;
        off1++;
        break;
      }
    }
  }
  if(off1 < off2)
  {
    found = true;
    while(off2>=0 && found)
    {
      found = false;
      for(i=0;i<len;i++)
      {
        if(start[i] == c[off2])
        {
          found = true;
          off2--;
          break;
        }
      }
    }
  }

  if(off1 <= off2)
    newStr->theString.append(c+off1, off2-off1+1);

  return newStr;
}


/*******************************************************************************
  Removes the leading and trailing whitespaces (#x20).
********************************************************************************/
xqpStringStore_t xqpStringStore::trim() const
{
  if(empty())
    return new xqpStringStore("");
  
  char seq = ' ';
  //xqpStringStore_t tmp = trimL(&seq, 1);
  //return tmp->trimR(&seq,1);
  return trim(&seq, 1);
}


/*******************************************************************************

********************************************************************************/
xqpStringStore_t xqpStringStore::formatAsXML() const
{
  uint32_t i;
  uint32_t len = numChars();
  const unsigned char* c = (unsigned char*)c_str();
  uint32_t cp;
//  char seq[4];

  std::auto_ptr<xqpStringStore> newStr(new xqpStringStore(""));

  for(i = 0; i < len; ++i)
  {
    cp = c[i];//UTF8Decode(c);
    if(cp < 128)
    {
      //memset(seq, 0, sizeof(seq));
      //UTF8Encode(cp, seq);
      //newStr->theString += seq;
      newStr->theString += cp;
    }
    else
    {
      newStr->theString += '&';
      newStr->theString += '#';
      newStr->theString +=  Integer::parseInt(cp).toString();
      newStr->theString += ';';
    }
  }
  //newStr->theString += "\0";

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
  const unsigned char* c = (unsigned char*)c_str();
  unsigned int cp;
//  char seq[4];
  const unsigned char* prev = (unsigned char*)c_str();
  distance_type length;

  std::auto_ptr<xqpStringStore> newStr(new xqpStringStore(""));
    
  for(i = 0; i < len; ++i)
  {
    prev = c+i;
    cp = c[i];//UTF8Decode(c);
    //memset(seq, 0, sizeof(seq));
    if(is_printableASCII(cp))
    {
      //UTF8Encode(cp, seq);
      newStr->theString += cp;//seq;
    }
    else
    {
      //codepoint has to be escaped
      length = 1;//sequence_length(prev);
      //if(length != 1)
      {
        for(int j = 0; j < length;++j)
        {
          char seq[10];
          cp = *prev;//mask8(*prev);
          sprintf(seq, "%%%X", cp);
          newStr->theString += seq;
          prev++;
        }
      }
    }
  }
  //newStr->theString += "\0";

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
  const unsigned char* c = (unsigned char*)c_str();
  unsigned int cp;
//  char seq[4];
  const unsigned char* prev = (unsigned char*)c_str();
  distance_type length;

  std::auto_ptr<xqpStringStore> newStr(new xqpStringStore(""));
    
  for(i = 0; i < len; ++i)
  {
    prev = c+i;
    cp = c[i];//UTF8Decode(c);
    //memset(seq, 0, sizeof(seq));
    if(!is_ucscharCP(cp) && !is_iprivateCP(cp) && !is_Invalid_in_IRI(cp))
    {
      //UTF8Encode(cp, seq);
      newStr->theString += cp;//seq;
    }
    else
    {
      //codepoint has to be escaped
      length = 1;//sequence_length(prev);
      for(int j = 0; j < length;++j)
      {
        cp = *prev;//mask8(*prev);
        char seq[10];
        sprintf(seq, "%%%X", cp);
        newStr->theString += seq;
        prev++;
        }
    }
  }
  //newStr->theString += "\0";

  return newStr.release();
}


/*******************************************************************************

********************************************************************************/
xqpStringStore_t xqpStringStore::encodeForUri(const char* start, uint16_t length) const
{
  uint32_t i, cp;
  uint32_t len = numChars();
  const unsigned char* c = (unsigned char*)c_str();
//  char seq[4];
  const unsigned char* prev = (unsigned char*)c_str();
  distance_type seq_length;
  
  std::auto_ptr<xqpStringStore> newStr(new xqpStringStore(""));
    
  for(i = 0; i < len; ++i)
  {
    prev = c+i;
    cp = c[i];//UTF8Decode(c);
    //memset(seq, 0, sizeof(seq));
    // not encoding a / is a hack until the uri class can correctly encode paths
    if(is_unreservedCP(cp) || is_contained(start, length, cp))
    {
      //UTF8Encode(cp, seq);
      newStr->theString += cp;//seq;
    }
    else
    {
      //codepoint has to be escaped
      seq_length = 1;//sequence_length(prev);
      for(int j = 0; j < seq_length; ++j)
      {
        cp = *prev;//mask8(*prev);
        char seq[10];
        sprintf(seq, "%%%X", cp);
        newStr->theString += seq;
        prev++;
      }
    }
  }
  //newStr->theString += "\0";

  return newStr.release();
}

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
  revert encodeForUri("/",1)
********************************************************************************/
xqpStringStore_t xqpStringStore::decodeFromUri() const
{
  std::ostringstream os;

  for (std::string::size_type i = 0; i < numChars(); ++i) {
    const char* c = c_str() + i;
    if  ((*c == '%') & (i < numChars() -2)) {
      char dec1, dec2;
      if ( (dec1 = HEX2DEC[(const unsigned char) *(c + 1)]) != -1 &&
           (dec2 = HEX2DEC[(const unsigned char) *(c + 2)]) != -1 ) {
        os <<  (char)((dec1 << 4) + dec2);
        i += 2;
        continue;
      }
    }
    os << (char)*c;
  }

  return new xqpStringStore(os.str());
}

/*******************************************************************************

********************************************************************************/
xqpStringStore_t xqpStringStore::normalize(const xqpStringStore* normMode) const
{
  xqpStringStore_t  newstr = new xqpStringStore(this->str());
  return newstr;
  //return normalizeSpace();
}

/*******************************************************************************
  Return an UnicodeString (UTF-16 encoded) version of the string.
********************************************************************************/
//UnicodeString getUnicodeString(xqpStringStore *strstore)
//{
//  UnicodeString ret;
//  UErrorCode status = U_ZERO_ERROR;
//  int32_t len = strstore->bytes();
//  UChar* buffer = ret.getBuffer(len);
//
//  u_strFromUTF8(buffer, ret.getCapacity(), &len, strstore->c_str(), len, &status);
//
//  if(U_FAILURE(status))
//  {
//    assert(false);
//  }
//
//  ret.releaseBuffer(U_SUCCESS(status) ? len : 0);
//
//  return ret;
//}


/*******************************************************************************

********************************************************************************/
checked_vector<uint32_t> xqpStringStore::getCodepoints() const
{
  checked_vector<uint32_t> tt;
  uint16_t vLength;
  
  vLength = numChars() + 1;
  const unsigned char* c = (unsigned char*)c_str();
  while( --vLength > 0 )
  {
    tt.push_back(*c);//UTF8Decode(c));
    c++;
  }
  return tt;
}


std::ostream& operator<<(std::ostream& os, const xqpStringStore& src)
{
  //TODO is there a need to perform charset conversion to/from the current locale ?!?!
  os << src.theString;
  return os;
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

  xqpString::xqpString(long initial_len)
  {
    theStrStore = new xqpStringStore(initial_len);
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
    char seq[2];
    //UTF8Encode(cp, seq);
    seq[0] = cp;
    seq[1] = 0;
    theStrStore = new xqpStringStore(seq);
    return *this;
  }

  xqpString& xqpString::operator=(char c)
  {
    char  seq[2];
    seq[0] = c;
    seq[1] = 0;
    theStrStore = new xqpStringStore(seq);
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
    char seq[2];
    //UTF8Encode(cp, seq);
    seq[0] = cp;
    seq[1] = 0;
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
    //char* target;
    //int32_t size =  length*4 + 1;
    //target = new char[size]; //will hold UTF-8 encoded characters
    //UnicodeString str = theStrStore->getUnicodeString();

    //int32_t targetsize = str.extract(index, length, target, size, "UTF-8");
    //target[targetsize] = 0; /* NULL termination */

    //xqpString ret(&target[0]);

    //delete [] target;
    //return ret;
    return xqpString(theStrStore->theString.substr(index, length));
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

    //const char * d = theStrStore->c_str();
    //advance(d, index, d+length());

    //xqpString ret(d);

    //return ret;
    return xqpString(theStrStore->theString.substr(index));
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
    const unsigned char*   mapPtr    = (unsigned char*)mapString.theStrStore->c_str();
    const unsigned char*   transPtr  = (unsigned char*)transString.theStrStore->c_str();
    uint32_t      tmp0, tmp1;
    
    std::map<uint32_t,uint32_t> mapArray;
    std::map<uint32_t,uint32_t>::iterator it;
    
    if(mapLen >0)
    {
      while((mapLen > 0) && (transLen > 0))
      {
        tmp0 = *mapPtr;//UTF8Decode(mapPtr);
        mapPtr++;
        tmp1 = *transPtr;//UTF8Decode(transPtr);
        transPtr++;
        mapArray.insert(std::pair<uint32_t,uint32_t>(tmp0, tmp1));
        --mapLen;
        --transLen;
      }
      
      while(mapLen > 0)
      {
        tmp0 = *mapPtr;//UTF8Decode(mapPtr);
        mapPtr++;
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
    const unsigned char* c = (unsigned char*)c_str();
    uint32_t cp, i;
//    char seq[4];

    for(i=0; i<len; ++i)
    {
      cp = c[i];//UTF8Decode(c);

      it= myMap.find(cp);
      if( it != myMap.end() )
      {
        cp = (*it).second;
      }

      if(cp != 0xFFFFFFFF) //0xFFFFFFFF = unsigned long_MAX
      {
        //memset(seq, 0, sizeof(seq));
        //UTF8Encode(cp, seq);
        //tmp += seq;
        tmp += cp;
      }
    }
    //tmp += "\0";

    xqpString res(tmp);
    return res;
  }


  uint32_t parse_regex_flags (const char *flag_cstr) {
    uint32_t flags = 0;
    for (const char *p = flag_cstr; *p != '\0'; p++) {
      switch (*p) {
      case 'i': flags |= REGEX_ASCII_CASE_INSENSITIVE; break;
      case 's': flags |= REGEX_ASCII_DOTALL; break;
      case 'm': flags |= REGEX_ASCII_MULTILINE; break;
      case 'x': flags |= REGEX_ASCII_COMMENTS; break;
      default:
        throw zorbatypesException("", ZorbatypesError::FORX0001);
        break;
      }
    }
    return flags;
  }

  bool
    xqpString::matches(const xqpString& pattern, xqpString flags) const  
  {
    regex_ascii::CRegexAscii_parser    regex_parser;
    regex_ascii::CRegexAscii_regex     *regex;
    regex = regex_parser.parse(pattern.c_str());//should be moved out of here for performance
    if(!regex)
      throw zorbatypesException("", ZorbatypesError::FORX0002);

    bool  retval;
    int   match_pos;
    int   matched_len;
    retval = regex->match_anywhere(c_str(), parse_regex_flags(flags.c_str()), &match_pos, &matched_len);
    delete regex;
    return retval;
  }


  xqpString
  xqpString::replace(xqpString pattern, xqpString replacement, xqpString flags)
  {
    regex_ascii::CRegexAscii_parser    regex_parser;
    regex_ascii::CRegexAscii_regex     *regex;
    regex = regex_parser.parse(pattern.c_str());//should be moved out of here for performance
    if(!regex)
      throw zorbatypesException("", ZorbatypesError::FORX0002);

    int   match_pos;
    int   matched_len;
 //+   if(regex->match_anywhere("", parse_regex_flags(flags.c_str()), &match_pos, &matched_len))
 //+   {//Regular expression matches zero-length string.
 //+     throw zorbatypesException("", ZorbatypesError::FORX0003);
 //+   }
    
    xqpString   newstr;
    const char  *start_str = c_str();
    int   subregex_count = regex->get_indexed_regex_count();

    while(regex->match_anywhere(start_str, parse_regex_flags(flags.c_str()), &match_pos, &matched_len))
    {
      if(match_pos)
        newstr.append_in_place(start_str , match_pos);
      const char *temprepl = replacement.c_str();
      const char *submatched_source;
      int   submatched_len;
      int index;
      while(*temprepl)
      {
        //look for dollars
        if(*temprepl == '\\')
        {
          temprepl++;
          if(!*temprepl || (*temprepl != '\\') || (*temprepl != '$'))//Invalid replacement string.
            throw zorbatypesException("", ZorbatypesError::FORX0004);
          newstr.append_in_place(*temprepl);
          temprepl++;
          continue;
        }
        if(*temprepl == '$')
        {
          temprepl++;
          index = 0;
          int   nr_digits = 0;
          while(isdigit(*temprepl))
          {
            if(nr_digits && ((index*10 + (*temprepl)-'0') > subregex_count))
              break;
            index = index*10 + (*temprepl)-'0';
            temprepl++;
            nr_digits++;
          }
          if(!nr_digits)//Invalid replacement string.
            throw zorbatypesException("", ZorbatypesError::FORX0004);
          else if(!index)
          {
            newstr.append_in_place(start_str+match_pos, matched_len);
          }
          else if(regex->get_indexed_match(index, &submatched_source, &submatched_len))
          {
            if(submatched_source && submatched_len)
              newstr.append_in_place(submatched_source, submatched_len);
          }
        }
        else
        {
          newstr.append_in_place(*temprepl);
          temprepl++;
        }
      }
      start_str += match_pos + matched_len;
    }
    newstr.append_in_place(start_str);

    delete regex;
    return newstr;

  }

  xqpString
  xqpString::tokenize(xqpString pattern, 
                      xqpString flags, 
                      /*in-out*/int32_t *match_pos, 
                      /*out*/bool *hasmatched)
  {
    regex_ascii::CRegexAscii_parser    regex_parser;
    regex_ascii::CRegexAscii_regex     *regex;
    regex = regex_parser.parse(pattern.c_str());//should be moved out of here for performance
    if(!regex)
      throw zorbatypesException("", ZorbatypesError::FORX0002);

    int first_pos = *match_pos;
    //int   match_pos;
    int   matched_len = 0;
  //+  if(regex->match_anywhere("", parse_regex_flags(flags.c_str()), &match_pos, &matched_len))
  //+  {//Regular expression matches zero-length string.
  //+    throw zorbatypesException("", ZorbatypesError::FORX0003);
  //+  }
    //bool  ismatch;
    xqpString   leftstr;
    const char  *start_str = c_str();

    *hasmatched = regex->match_from(start_str, parse_regex_flags(flags.c_str()), (int*)match_pos, &matched_len);
    delete regex;
    if(*hasmatched)
    {
      //*remaining = xqpString(start_str + match_pos + matched_len);
      if(*match_pos)
        leftstr = substr(first_pos, *match_pos-first_pos);
      *match_pos += matched_len;
    }
    else
    {
      leftstr = substr (first_pos, length ()-first_pos);
      //*remaining = xqpString();
      *match_pos = length ();
    }

    return leftstr;
  }


  //xqpString xqpString::fromUTF16(const UChar* src, int32_t len)
  //{
  //  char* target;
  //  int32_t targetLen = len*4 + 1;
  //  target = new char[targetLen];
  //  UErrorCode status = U_ZERO_ERROR;

  //  //open a convertor to UTF-8
  //  UConverter *conv = ucnv_open("utf-8", &status);

  //  if(U_FAILURE(status))
  //  {
  //    assert(false);

  //    delete[] target;
  //    return "";
  //  }

  //  //Convert from UTF-16 to UTF-8
  //  ucnv_fromUChars (conv, target, targetLen, (const UChar*)src, len, &status);
  //  //close the converter
  //  ucnv_close(conv);

  //  if(U_FAILURE(status))
  //  {
  //    assert(false);

  //    delete[] target;
  //    return "";
  //  }

  //  xqpString ret(&target[0]);
  //  delete[] target;
  //  return ret;
  //}

  // Private methods
//xqpStringStore_t getXqpString(UnicodeString source)
//{
//  UErrorCode status = U_ZERO_ERROR;
//  
//  //open a convertor to UTF-8
//  UConverter* conv = ucnv_open("utf-8", &status);
//
//  if(U_FAILURE(status))
//  {
//    assert(false);
//    return new xqpStringStore("");
//  }
//
//  int32_t targetLen = source.getCapacity()*4 + 1;
//  char* target = new char[targetLen];
//
//  //Convert from UTF-16 to UTF-8
//  ucnv_fromUChars(conv, target, targetLen,
//                  source.getBuffer(source.length()),
//                  source.length(),
//                  &status);
//
//  //close the converter
//  ucnv_close(conv);
//
//  if(U_FAILURE(status))
//  {
//    assert(false);
//
//    delete[] target;
//    return new xqpStringStore("");
//  }
//
//  xqpStringStore_t result = new xqpStringStore(target, strlen(target));
//  delete[] target;
//  return result;
//}

  //wchar_t * xqpString::getWCS(xqpString source) const
  //{
  //  int32_t destCapacity =  source.length()*2 + 1;
  //  wchar_t* destWCS;
  //  destWCS = new wchar_t[destCapacity];
  //  int32_t destLen;

  //  UnicodeString unicodeStr = source.theStrStore->getUnicodeString();
  //  int32_t srcLen = unicodeStr.length();
  //  UChar* srcBuf = unicodeStr.getBuffer(srcLen);
  //  UErrorCode status = U_ZERO_ERROR;

  //  wchar_t* ret =  u_strToWCS(destWCS, destCapacity, &destLen, srcBuf, srcLen, &status);

  //  if(U_FAILURE(status))
  //  {
  //    assert(false);
  //  }

  //  return ret;
  //}

void xqpString::append_in_place(const char c)
{
  theStrStore->append_in_place(c);
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

void xqpString::append_in_place(const std::string &str)
{
  theStrStore->append_in_place(str);
}

//static concat
xqpString xqpString::concat(const char *s1, 
                            const char *s2)
{
//  int l1 = strlen(s1);
//  int l2 = strlen(s2);

  xqpString   result;//(l1+l2+1);
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
  result.append_in_place(s1);
  result.append_in_place(s2);
  result.append_in_place(s3);
  return result;
}

xqpString xqpString::concat(const xqpString s1, 
                        const char *s2,
                        const xqpString s3)
{
//  int l1 = s1.bytes();
//  int l2 = strlen(s2);
//  int l3 = s3.bytes();

  xqpString   result;//(l1+l2+l3+1);
  result.append_in_place(s1.getStore());
  result.append_in_place(s2);
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
  result.append_in_place(s1);
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
  result.append_in_place(s1);
  result.append_in_place(s2);
  result.append_in_place(s3);
  result.append_in_place(s4.getp());
  result.append_in_place(s5);
  return result;
}



}/* namespace zorba */

#endif//#ifdef ZORBA_NO_UNICODE
