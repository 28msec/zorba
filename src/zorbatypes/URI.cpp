#include <xercesc/util/XMLUri.hpp>
#include <xercesc/util/XMLURL.hpp>
#include <xercesc/util/XMLString.hpp>

#include "representations.h"

#include "URI.h"

using namespace std;
XERCES_CPP_NAMESPACE_USE

namespace zorba {

  class XMLChArray {
    XMLCh *buf;
    
  public:
    XMLChArray (XMLCh *buf_) : buf (buf_) {}
    XMLChArray (xqp_string str)
      : buf (XMLString::transcode (str.c_str ()))
    {}
    XMLCh *get () { return buf; }
    ~XMLChArray () { XMLString::release (&buf); }
  };

  bool URI::is_valid (xqp_string uri) {
    XMLChArray xuri (uri);
    return XMLUri::isValidURI (true, xuri.get ());
  }

  URI::error_t URI::resolve_relative (xqp_string base, xqp_string rel, xqp_string &result) {
    XMLChArray xbase (base), xrel (rel);
    try {
      if (! XMLUri::isValidURI (true, xbase.get ()) || ! XMLUri::isValidURI (true, xrel.get ()))
        return URI::INVALID_URI;
      if (XMLUri::isValidURI (false, xrel.get ())
          || ! XMLUri::isValidURI (false, xbase.get ()))
      {
        result = rel;
      } else {
        XMLUri baseuri (xbase.get ());
        XMLUri resuri (&baseuri, xrel.get ());
        char *raw_result = XMLString::transcode (resuri.getUriText ());
        result = xqp_string (raw_result);
        delete [] raw_result;
      }
    } catch (MalformedURLException &e) {
      return URI::RESOLUTION_ERROR;
    }

    return URI::MAX_ERROR_CODE;
  }
};
