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
#ifndef ZORBATYPES_ERROR_H
#define ZORBATYPES_ERROR_H

#include <zorba/config.h>
#include <exception>
#include <string>

namespace zorba
{

class  ZorbatypesError
{
public:
  enum ErrorCode
  {
    //
    // XQuery 1.0 and XPath 2.0 Functions and Operators
    //
    FOER0000, //Unidentified error.
    FOAR0001, //Division by zero.  This error is raised whenever an attempt is made to divide by zero.
    FOAR0002, //Numeric operation overflow/underflow.  This error is raised whenever numeric operations result in an overflow or underflow.
    FOCA0001, //Input value too large for decimal.
    FOCA0002, //Invalid lexical value.
    FOCA0003, //Input value too large for integer.
    FOCA0005, //NaN supplied as float/double value.
    FOCA0006, //String to be cast to decimal has too many digits of precision.
    FOCH0001, //Code point not valid.
    FOCH0002, //Unsupported collation.
  
    FOCH0003, //Unsupported normalization form.
    FOCH0004, //Collation does not support collation units.
    FODC0001, //No context document.
    FODC0002, //Error retrieving resource.
    FODC0003, //Function stability not defined.
    FODC0004, //Invalid argument to fn:collection.
    FODC0005, //Invalid argument to fn:doc or fn:doc-available.
    FODT0001, //Overflow/underflow in date/time operation.
    FODT0002, //Overflow/underflow in duration operation.
    FODT0003, //Invalid timezone value.

    FONS0004, //No namespace found for prefix.
    FONS0005, //Base-uri not defined in the static context.
    FORG0001, //Invalid value for cast/constructor.
    FORG0002, //Invalid argument to fn:resolve-uri().
    FORG0003, //fn:zero-or-one called with a sequence containing more than one item.
    FORG0004, //fn:one-or-more called with a sequence containing no items.
    FORG0005, //fn:exactly-one called with a sequence containing zero or more than one item.
    FORG0006, //Invalid argument type.
    FORG0008, //Both arguments to fn:dateTime have a specified timezone.
    FORG0009, //Error in resolving a relative URI against a base URI in fn:resolve-uri.
  
    FORX0001, //Invalid regular expression. flags
    FORX0002, //Invalid regular expression.
    FORX0003, //Regular expression matches zero-length string.
    FORX0004, //Invalid replacement string.
    FOTY0012, //Argument node does not have a typed value.
    FOTY0013, //Argument to fn:data() contains a node that does not have a typed value.
    FOTY0014, //The argument to fn:string() is a function item
    FOTY0015, //An argument to fn:deep-equal() contains a function item
    FOUP0001, // It is a dynamic error if the first operand of fn:put is not a node of a supported kind.
    FOUP0002  // It is a dynamic error if the second operand of fn:put is not a valid
    // lexical representation of the xs:anyURI type.
  };
};


class zorbatypesException : public std::exception {
public:

  zorbatypesException( char const *msg, ZorbatypesError::ErrorCode code ) :
    msg_( msg ), code_( code )
  {
  }

  template<class StringType>
  zorbatypesException( StringType const &msg,
                       ZorbatypesError::ErrorCode code ) :
    msg_( msg.c_str() ), code_( code )
  {
  }

  ~zorbatypesException() throw() {
  }

  char const* what() const throw() {
    return msg_.c_str();
  }

  ZorbatypesError::ErrorCode ErrorCode() const throw() {
    return code_;
  }

private:
  std::string const msg_;
  ZorbatypesError::ErrorCode const code_;
};

} // namespace zorba
#endif
/* vim:set et sw=2 ts=2: */
