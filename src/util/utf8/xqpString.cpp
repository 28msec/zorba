/**
 * @copyright
 * ========================================================================
 *  Copyright FLWOR Foundation
 * ========================================================================
 *
 * @author Sorin Nasoi (sorin.nasoi@ipdevel.ro)
 * @author Nicolae Brinza (nicolae.brinza@ipdevel.ro)
 * @author Dan Muresan (dan.muresan@ipdevel.ro)
 * @file utf8/xqpString.cpp
 *
 */

#include "util/utf8/xqpString.h"
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
    uint32_t len = bytes();

    if( len == src.bytes() && memcmp(c_str(), src.c_str(), len) == 0)
       return true;

    return false;
  }

  bool xqpStringStore::byteEqual(const char* src, uint32_t srclen) const
  {
    if( bytes() == srclen && memcmp(c_str(), src, srclen) == 0)
      return true;

    return false;
  }

  bool xqpStringStore::hashEqual(const xqpStringStore& src) const
  {
    if(hash() == src.hash() && byteEqual(src))
      return true;

    return false;
  }


  xqpString::xqpString()
  {
    theStrStore = new xqpStringStore("");
  }

  xqpString::xqpString(const std::string& src){
    theStrStore = new xqpStringStore(src);
  }

  xqpString::xqpString(const char* src){
    theStrStore = new xqpStringStore(src);
  }

  xqpString::~xqpString()
  {}

  xqpString& xqpString::operator=(const std::string& src){
    theStrStore = new xqpStringStore(src);
    return *this;
  }

  xqpString& xqpString::operator=(const char* src){
    theStrStore = new xqpStringStore(src);
    return *this;
  }

  xqpString& xqpString::operator=(uint32_t cp){
    theStrStore->reserve(4);
    char seq[4] = {0,0,0,0};
    UTF8Encode(cp, seq);
    theStrStore = new xqpStringStore(seq);
    return *this;
  }

  xqpString& xqpString::operator=(char c){
    theStrStore = new xqpStringStore(&c);
    return *this;
  }

  //xqpString::operator+=()
  xqpString& xqpString::operator+=(const xqpString& src){
    xqpStringStore* temp = new xqpStringStore(*theStrStore);
    *temp += src;
    theStrStore = temp;
    return *this;
  }

  xqpString& xqpString::operator+=(const char* src){
    xqpStringStore* temp = new xqpStringStore(*theStrStore);
    *temp += src;
    theStrStore = temp;
    return *this;
  }

  xqpString& xqpString::operator+=(uint32_t cp){
    theStrStore->reserve(4);
    char seq[4] = {0,0,0,0};
    UTF8Encode(cp, seq);
    theStrStore = new xqpStringStore(*theStrStore+seq);
    return *this;
  }

  xqpString& xqpString::operator+=(char c){
    theStrStore = new xqpStringStore(*theStrStore+c);
    return *this;
  }

  //xqpString::stream I/O operators
  std::istream& operator>>(std::istream& is, xqpString& utf8_src){
    std::string buffer;
    is >> buffer;
    //TODO is there a need to perform charset conversion to/from the current locale ?!?!
    utf8_src = buffer;
    return is;
  }

  std::ostream& operator<<(std::ostream& os, const xqpString& utf8_src){
    //TODO is there a need to perform charset conversion to/from the current locale ?!?!
    os << *utf8_src.theStrStore;
    return os;
  }

  //xqpString::compare
  int xqpString::compare(const xqpString& src) const{
    UErrorCode status = U_ZERO_ERROR;

    //get the collator for the default collation
    Collator *coll = zorba::getZorbaForCurrentThread()->getCollator();

    Collator::EComparisonResult result = ::Collator::EQUAL;

    //compare the 2 strings
    result = coll->compare(getUnicodeString(*theStrStore), getUnicodeString(src));

    return result;
}

  int xqpString::compare(const xqpString& src, const char * loc) const{
    UErrorCode status = U_ZERO_ERROR;

    //create the collator object
    ::Collator *coll = ::Collator::createInstance(Locale(loc), status);

    if(U_FAILURE(status)) {
      ZORBA_ERROR_ALERT(
          error_messages::XQP0014_SYSTEM_SHOUD_NEVER_BE_REACHED,
          error_messages::SYSTEM_ERROR,
          NULL
        );
    }

    //set level 1 comparison for the collator
    coll->setStrength(::Collator::PRIMARY);

    ::Collator::EComparisonResult result = ::Collator::EQUAL;

    //compare the 2 strings
    result = coll->compare(getUnicodeString(*theStrStore), getUnicodeString(src));

    //close the collator
    delete coll;

    return result;
}

  int xqpString::compare(const char* src) const{
    //TODO optimize the code here
    xqpString tmp(src);
    return compare(tmp);
  }

  //xqpString::Length
  xqpString::size_type xqpString::size() const{
    const char* c = theStrStore->c_str();
    return UTF8Distance(c, c + theStrStore->size());
  }

  xqpString::size_type xqpString::length() const{
    const char* c = theStrStore->c_str();
    return UTF8Distance(c, c + theStrStore->size());
  }

  bool xqpString::empty() const{
    return theStrStore->empty();
  }

  void xqpString::reserve(xqpString::size_type size){
    theStrStore->reserve(size);
  }

  //xqpString::Clear
  void xqpString::clear(){
    theStrStore->erase();
  }

  //xpqString::Codepoint
  std::vector<uint32_t> xqpString::getCodepoints(){
    std::vector<uint32_t> tt;
    uint16_t vLength;

    vLength = length() + 1;
    const char* c = theStrStore->c_str();
    while( --vLength > 0 ){
      tt.push_back(UTF8Decode(c));
    }
    return tt;
  }

  //xqpString::Substring matching/ string search
  int32_t xqpString::indexOf(const xqpString& pattern){
    //create the collator object
    UErrorCode status = U_ZERO_ERROR;

    //get the collator for the default collation
    Collator *coll = zorba::getZorbaForCurrentThread()->getCollator();

    StringSearch search(getUnicodeString(pattern), getUnicodeString(*theStrStore), (RuleBasedCollator *)coll, NULL, status);

    if(U_FAILURE(status)) {
      ZORBA_ERROR_ALERT(
          error_messages::XQP0014_SYSTEM_SHOUD_NEVER_BE_REACHED,
          error_messages::SYSTEM_ERROR,
          NULL
        );
      return -1;
    }

    for(int16_t pos = search.first(status);
    U_SUCCESS(status) && pos != USEARCH_DONE;
    pos = search.next(status)) {
      return pos;
    }
    if (U_FAILURE(status)) {
      ZORBA_ERROR_ALERT(
          error_messages::XQP0014_SYSTEM_SHOUD_NEVER_BE_REACHED,
          error_messages::SYSTEM_ERROR,
          NULL
        );
      return -1;
    }
    return -1;
  }

  int32_t xqpString::indexOf(const xqpString& pattern, const char * loc){
    UErrorCode status = U_ZERO_ERROR;

    //A collator will be created in the process, which will be owned by this instance and will be deleted during destruction
    StringSearch search(getUnicodeString(pattern), getUnicodeString(*theStrStore), Locale(loc), NULL, status);

    if(U_FAILURE(status)) {
      ZORBA_ERROR_ALERT(
          error_messages::XQP0014_SYSTEM_SHOUD_NEVER_BE_REACHED,
          error_messages::SYSTEM_ERROR,
          NULL
        );
      return -1;
    }

    for(int16_t pos = search.first(status);
    U_SUCCESS(status) && pos != USEARCH_DONE;
    pos = search.next(status)) {
      return pos;
    }
    if (U_FAILURE(status)) {
      ZORBA_ERROR_ALERT(
          error_messages::XQP0014_SYSTEM_SHOUD_NEVER_BE_REACHED,
          error_messages::SYSTEM_ERROR,
          NULL
        );
      return -1;
    }
    return -1;
  }

  int32_t xqpString::lastIndexOf(const xqpString& pattern){
    //create the collator object
    UErrorCode status = U_ZERO_ERROR;

    //get the collator for the default collation
    Collator *coll = zorba::getZorbaForCurrentThread()->getCollator();

    StringSearch search(getUnicodeString(pattern), getUnicodeString(*theStrStore), (RuleBasedCollator *)coll, NULL, status);

    if(U_FAILURE(status)) {
      ZORBA_ERROR_ALERT(
          error_messages::XQP0014_SYSTEM_SHOUD_NEVER_BE_REACHED,
          error_messages::SYSTEM_ERROR,
          NULL
        );
      return -1;
    }

    int32_t pos = search.last(status);
    if (U_FAILURE(status)) {
      ZORBA_ERROR_ALERT(
          error_messages::XQP0014_SYSTEM_SHOUD_NEVER_BE_REACHED,
          error_messages::SYSTEM_ERROR,
          NULL
        );
      return -1;
    }

    if(U_SUCCESS(status) && pos != USEARCH_DONE){
      //TODO check if this condition is enough
      return pos;
    }

    return -1;
  }

  int32_t xqpString::lastIndexOf(const xqpString& pattern, const char * loc){
    UErrorCode status = U_ZERO_ERROR;

    //A collator will be created in the process, which will be owned by this instance and will be deleted during destruction
    StringSearch search(getUnicodeString(pattern), getUnicodeString(*theStrStore), Locale(loc), NULL, status);

    if(U_FAILURE(status)) {
      ZORBA_ERROR_ALERT(
          error_messages::XQP0014_SYSTEM_SHOUD_NEVER_BE_REACHED,
          error_messages::SYSTEM_ERROR,
          NULL
        );
      return -1;
    }

    int32_t pos = search.last(status);
    if (U_FAILURE(status)) {
      ZORBA_ERROR_ALERT(
          error_messages::XQP0014_SYSTEM_SHOUD_NEVER_BE_REACHED,
          error_messages::SYSTEM_ERROR,
          NULL
        );
      return -1;
    }

    if(U_SUCCESS(status) && pos != USEARCH_DONE){
      //TODO check if this condition is enough
      return pos;
    }

    return -1;
  }

  bool xqpString::endsWith(const xqpString& pattern){
    //TODO check if this condition is enough
    return( lastIndexOf(pattern) + pattern.length() == length() );
  }

  bool xqpString::endsWith(const xqpString& pattern, const char * loc){
    //TODO check if this condition is enough
    return( lastIndexOf(pattern, loc) + pattern.length() == length() );
  }

  xqpString xqpString::substr(xqpString::size_type index, xqpString::size_type length){
    char* target;
    int32_t size =  length*4 + 1;
    target = new char[size]; //will hold UTF-8 encoded characters
    UnicodeString str = getUnicodeString( *theStrStore );

    int32_t targetsize = str.extract(index, length, target, size, "UTF-8");
    target[targetsize] = 0; /* NULL termination */

    xqpString ret(&target[0]);

    delete target;
    return ret;

  }

  xqpString xqpString::substr(distance_type index){
    if(index >= (int32_t)length()){
      index = length();
    }
    else if(index < 0){
      xqpString ret(*theStrStore);
      return ret;
    }

    const char * d = theStrStore->c_str();
    advance(d, index);

    xqpString ret(d);
    return ret;
  }

  const char* xqpString::c_str() const{
    return theStrStore->c_str();
  }


  // Private methods
  UnicodeString xqpString::getUnicodeString(const xqpString& source) const{
    UnicodeString ret;
    UErrorCode status = U_ZERO_ERROR;
    int32_t len = source.bytes();
    UChar* buffer = ret.getBuffer(len);

    u_strFromUTF8(buffer, ret.getCapacity(), &len, source.c_str(), len, &status);

    ret.releaseBuffer(U_SUCCESS(status) ? len : 0);

    if(U_FAILURE(status)) {
      ZORBA_ERROR_ALERT(
            error_messages::XQP0014_SYSTEM_SHOUD_NEVER_BE_REACHED,
            error_messages::SYSTEM_ERROR,
            NULL
          );
    }

    return ret;
  }

  xqpString xqpString::getXqpString(UnicodeString source){
    char* target;
    int32_t targetLen = source.getCapacity()*4 + 1;
    target = new char[targetLen];
    UErrorCode status = U_ZERO_ERROR;

    //open a convertor to UTF-8
    UConverter *conv = ucnv_open("utf-8", &status);

    if(U_FAILURE(status)) {
      ZORBA_ERROR_ALERT(
            error_messages::XQP0014_SYSTEM_SHOUD_NEVER_BE_REACHED,
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

    if(U_FAILURE(status)) {
      ZORBA_ERROR_ALERT(
            error_messages::XQP0014_SYSTEM_SHOUD_NEVER_BE_REACHED,
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

  wchar_t * xqpString::getWCS(const xqpString& source) const{
    int32_t destCapacity =  source.length()*2 + 1;
    wchar_t* destWCS;
    destWCS = new wchar_t[destCapacity];
    int32_t destLen;

    UnicodeString unicodeStr = getUnicodeString(source);
    int32_t srcLen = unicodeStr.length();
    UChar* srcBuf = unicodeStr.getBuffer(srcLen);
    UErrorCode status = U_ZERO_ERROR;

    wchar_t* ret =  u_strToWCS(destWCS, destCapacity, &destLen, srcBuf, srcLen, &status);

    if(U_FAILURE(status)) {
      ZORBA_ERROR_ALERT(
            error_messages::XQP0014_SYSTEM_SHOUD_NEVER_BE_REACHED,
            error_messages::SYSTEM_ERROR,
            NULL
          );
    }

    return ret;
  }
}/* namespace xqp */
