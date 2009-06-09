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
#ifndef ZORBA_XERCES_XMLCHARRAY_H
#define ZORBA_XERCES_XMLCHARRAY_H

#ifndef ZORBA_NO_XMLSCHEMA

#include <xercesc/util/XMLString.hpp>
//daniel: this is to make cygwin work; xerces defines WIN32 in case of cygwin, which is wrong
#ifdef CYGWIN
#undef WIN32
#endif

#include <zorba/config.h>
#include <zorbatypes/xqpstring.h>


XERCES_CPP_NAMESPACE_USE

namespace zorba {

class XMLChArray 
{
  XMLCh *buf;
    
 public:
  XMLChArray (XMLCh *buf_) : buf(buf_) {}
    
  XMLChArray (const char* str) : buf(XMLString::transcode(str)) {}

  XMLChArray (const xqpStringStore* str) : buf(XMLString::transcode(str->c_str())) {}
    
  XMLCh *get () { return buf; }
  const XMLCh *get () const { return buf; }

  operator XMLCh* () { return get (); }
  operator const XMLCh* () const { return get (); }

  friend std::ostream& operator<<(std::ostream& out, const XMLChArray& xmlChArray)
  {
      out << XMLString::transcode(xmlChArray.get ());
      return out;
  }

 
  ~XMLChArray () { XMLString::release (&buf); }
};

}

#endif // ifndef ZORBA_NO_XMLSCHEMA
#endif // ifndef ZORBA_XERCES_XMLCHARRAY_H
