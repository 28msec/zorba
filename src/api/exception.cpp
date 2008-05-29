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
#ifndef ZORBA_EXCEPTION_H
#define ZORBA_EXCEPTION_H

#include <ostream>
#include <zorba/exception.h>
#include <zorba/error.h>
#include <zorba/zorbastring.h>
#include "zorbaerrors/errors.h"

namespace zorba {

ZorbaException::ZorbaException(
    const XQUERY_ERROR& aErrorCode,
    const String& aDescription,
    const String& aFileName,
    unsigned int aFileLineNumber)
  :
  theErrorCode(aErrorCode),
  theDescription(aDescription),
  theFileName(aFileName),
  theFileLineNumber(aFileLineNumber) 
{
}


ZorbaException::~ZorbaException() throw() 
{
}


XQUERY_ERROR
ZorbaException::getErrorCode() const { return theErrorCode; }


String
ZorbaException::getDescription() const { return theDescription; }


String
ZorbaException::getFileName() const { return theFileName; }


unsigned int
ZorbaException::getFileLineNumber() const { return theFileLineNumber; }


std::string
ZorbaException::getErrorCodeAsString(const XQUERY_ERROR& code)
{
  return error::ZorbaError::toString(code);
}


QueryException::QueryException(
    const XQUERY_ERROR& aErrorCode,
    const String& aDescription,
    const String& afilename,
    unsigned int afilelinenumber,
    const String& queryuri,
    unsigned int linebegin,
    unsigned int columnbegin)
  :
  ZorbaException(aErrorCode, aDescription, afilename, afilelinenumber),
  theLineBegin(linebegin),
  theColumnBegin(columnbegin),
  theQueryURI(queryuri)
{
}


QueryException::~QueryException() throw() 
{
}


unsigned int
QueryException::getLineBegin() const 
{
  return theLineBegin;
}


unsigned int
QueryException::getColumnBegin() const
{
  return theColumnBegin; 
}


DynamicException::DynamicException(
    const XQUERY_ERROR& aErrorCode,
    const String& aDescription,
    const String& afilename,
    unsigned int afilelinenumber,
    const String& queryuri,
    unsigned int linebegin,
    unsigned int columnbegin)
  : QueryException(aErrorCode, aDescription, afilename, afilelinenumber, queryuri, linebegin, columnbegin)
{
}


DynamicException::~DynamicException() throw()
{
}


StaticException::StaticException(
    const XQUERY_ERROR& aErrorCode,
    const String& aDescription,
    const String& afilename,
    unsigned int afilelinenumber,
    const String& queryuri,
    unsigned int linebegin,
    unsigned int columnbegin)
  :
  QueryException(aErrorCode, aDescription, afilename, afilelinenumber, queryuri, linebegin, columnbegin)
{
}


StaticException::~StaticException() throw() 
{
}


TypeException::TypeException(
    const XQUERY_ERROR& aErrorCode, 
    const String& aDescription,
    const String& afilename, 
    unsigned int afilelinenumber, 
    const String& queryuri,
    unsigned int linebegin,
    unsigned int columnbegin)
    : QueryException(aErrorCode, aDescription, afilename, afilelinenumber, queryuri, linebegin, columnbegin) {}

TypeException::~TypeException() throw() 
{
}


SerializationException::SerializationException(
    const XQUERY_ERROR& aErrorCode,
    const String& aDescription,
    const String& afilename,
    unsigned int afilelinenumber,
    const String& queryuri,
    unsigned int linebegin,
    unsigned int columnbegin)
  :
  QueryException(aErrorCode, aDescription, afilename, afilelinenumber, queryuri, linebegin, columnbegin)
{
}


SerializationException::~SerializationException() throw() 
{
}


SystemException::SystemException(
    const XQUERY_ERROR& aErrorCode, 
    const String& aDescription,
    const String& aFilename,
    unsigned int afilelinenumber)
  :
  ZorbaException(aErrorCode, aDescription, aFilename, afilelinenumber)
{
}


SystemException::~SystemException() throw() 
{
}


std::ostream& operator<< (std::ostream& os, const ZorbaException& aException)
{
  return os << "[" << ZorbaException::getErrorCodeAsString(aException.getErrorCode()) << "] "
            << aException.getDescription();
}


std::ostream& operator<< (std::ostream& os, const QueryException& aException)
{
#ifndef NDEBUG
  return os << "Generated from " << aException.getFileName()
            << ":"  << aException.getFileLineNumber() 
            << " Error on line " << aException.getLineBegin() 
            << " column " << aException.getColumnBegin() + 1
            << ": " 
            << (ZorbaException)aException;
#else
  return os << " Error on line " << aException.getLineBegin() 
            << " column " << aException.getColumnBegin() + 1
            << ": " 
            << (ZorbaException)aException;
#endif
}


std::ostream& operator<< (std::ostream& os, const DynamicException& aException)
{
  return os << (QueryException)aException;
}


std::ostream& operator<< (std::ostream& os, const StaticException& aException)
{
  return os << (QueryException)aException;
}


std::ostream& operator<< (std::ostream& os, const TypeException& aException)
{
  return os << (QueryException)aException;
}


std::ostream& operator<< (std::ostream& os, const SerializationException& aException)
{
  return os << (QueryException)aException;
}


std::ostream& operator<< (std::ostream& os, const SystemException& aException)
{
  return  os << (ZorbaException)aException;
}


} /* namespace zorba */

#endif
