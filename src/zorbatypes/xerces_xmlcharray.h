#ifndef ZORBA_XERCES_XMLCHARRAY_H
#define ZORBA_XERCES_XMLCHARRAY_H

#include <xercesc/util/XMLString.hpp>

#include <zorbatypes/xqpstring.h>

XERCES_CPP_NAMESPACE_USE

namespace zorba {

  class XMLChArray {
    XMLCh *buf;
    
  public:
    XMLChArray (XMLCh *buf_) : buf (buf_) {}
    
    XMLChArray (const char* str) : buf (XMLString::transcode (str)) {}
    XMLChArray (const xqpStringStore* str) : buf (XMLString::transcode (str->c_str ())) {}
    
    XMLCh *get () { return buf; }
    const XMLCh *get () const { return buf; }

    operator XMLCh* () { return get (); }
    operator const XMLCh* () const { return get (); }
    
    ~XMLChArray () { XMLString::release (&buf); }
  };

}

#endif
