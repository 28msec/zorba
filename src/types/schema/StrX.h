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
#ifndef ZORBA_STRX_H_
#define ZORBA_STRX_H_

#include "common/common.h"
#ifndef ZORBA_NO_XMLSCHEMA

#include <stdlib.h>
#include <string.h>
#include "xercesIncludes.h"


#if defined(XERCES_NEW_IOSTREAMS)
#include <iostream>
#else
#include <iostream.h>
#endif

XERCES_CPP_NAMESPACE_USE

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
  {
    XMLString::transcode(toTranscode, fLocalForm, length);
  }

  StrX(const XMLCh* const toTranscode)
  {
    // Call the private transcoding method
    fLocalForm = XMLString::transcode(toTranscode);
  }

  ~StrX()
  {
    XMLString::release(&fLocalForm);
  }

  // -----------------------------------------------------------------------
  //  Getter methods
  // -----------------------------------------------------------------------
  const char* localForm() const
  {
    return fLocalForm;
  }
  
  const char *localFormOrDefault (const char *def) 
  {
    return (fLocalForm == NULL ? def : fLocalForm);
  }

private :
  // -----------------------------------------------------------------------
  //  Private data members
  //
  //  fLocalForm
  //      This is the local code page form of the string.
  // -----------------------------------------------------------------------
  char* fLocalForm;
};


inline XERCES_STD_QUALIFIER ostream& operator<<(XERCES_STD_QUALIFIER ostream& target, const StrX& toDump)
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
