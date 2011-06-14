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
#pragma once
#ifndef ZORBA_STRX_H_
#define ZORBA_STRX_H_

#include "common/common.h"
#ifndef ZORBA_NO_XMLSCHEMA

#include <stdlib.h>
#include <string.h>
#ifdef __GNUC__
  // disable a warning in xerces 
#  pragma GCC diagnostic ignored "-Wparentheses"
#  pragma GCC diagnostic ignored "-Wctor-dtor-privacy"
#endif

#include <xercesc/util/XercesDefs.hpp>
#include <xercesc/util/XMLString.hpp>

#ifdef __GNUC__
#  pragma GCC diagnostic warning "-Wctor-dtor-privacy"
#  pragma GCC diagnostic warning "-Wparentheses"
#endif

#ifdef CYGWIN
#  undef WIN32
#endif


#if defined(XERCES_NEW_IOSTREAMS)
#include <iostream>
#else
#include <iostream.h>
#endif



namespace zorba
{

// ---------------------------------------------------------------------------
//  This is a simple class that lets us do easy (though not terribly efficient)
//  trancoding of XMLCh data to local code page for display.
// ---------------------------------------------------------------------------
class StrX
{
public :
  StrX(const XMLCh* const toTranscode, unsigned int length)
    : theLocalForm(0)
  {
    XERCES_CPP_NAMESPACE::XMLString::transcode(toTranscode, theLocalForm, length);
  }

  StrX(const XMLCh* const toTranscode)
  {
    // Call the private transcoding method
    theLocalForm = XERCES_CPP_NAMESPACE::XMLString::transcode(toTranscode);
  }

  ~StrX()
  {
    XERCES_CPP_NAMESPACE::XMLString::release(&theLocalForm);
  }

  // -----------------------------------------------------------------------
  //  Getter methods
  // -----------------------------------------------------------------------
  const char* localForm() const
  {
    return theLocalForm;
  }
  
  const char *localFormOrDefault (const char *def) 
  {
    return (theLocalForm == NULL ? def : theLocalForm);
  }

private :
  // -----------------------------------------------------------------------
  //  Private data members
  //
  //  fLocalForm
  //      This is the local code page form of the string.
  // -----------------------------------------------------------------------
  char* theLocalForm;
};


inline XERCES_STD_QUALIFIER ostream& operator<<(
    XERCES_STD_QUALIFIER ostream& target, const StrX& toDump)
{
  target << (toDump.localForm()==NULL ? "NULL" : toDump.localForm() );
  return target;
}

inline XERCES_STD_QUALIFIER ostream& operator+(
    XERCES_STD_QUALIFIER ostream& target, const StrX& toDump)
{
  target << (toDump.localForm()==NULL ? "NULL" : toDump.localForm() );
  return target;
}

} // namespace zorba

#endif  // ZORBA_NO_XMLSCHEMA
#endif /*ZORBA_STRX_H_*/

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
