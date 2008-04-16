#include <xercesc/util/XMLUri.hpp>
#include <xercesc/util/XMLURL.hpp>
#include <xercesc/util/XMLString.hpp>

#include "representations.h"

#include "URI.h"

using namespace std;
XERCES_CPP_NAMESPACE_USE

namespace zorba {

class XMLChArray 
{
  XMLCh *buf;
    
public:
  XMLChArray (XMLCh *buf_) : buf (buf_) {}

  XMLChArray (const char* str) : buf (XMLString::transcode (str)) {}

  XMLCh *get () { return buf; }

  ~XMLChArray () { XMLString::release (&buf); }
};


bool URI::is_valid (const xqpStringStore_t& uri, bool has_base_uri) {
  XMLChArray xuri(uri->c_str());
  return XMLUri::isValidURI (has_base_uri, xuri.get ());
}


URI::error_t URI::resolve_relative (
    const xqpStringStore_t&  base,
    const xqpStringStore_t&  rel,
    xqpStringStore_t&        result)
{
  XMLChArray xbase (base->c_str()), xrel (rel->c_str());
  try {
    if (! XMLUri::isValidURI (true, xbase.get ()) ||
        ! XMLUri::isValidURI (true, xrel.get ()))
      return URI::INVALID_URI;

    if (XMLUri::isValidURI (false, xrel.get ())
        || ! XMLUri::isValidURI (false, xbase.get ()))
    {
      result = rel;
    } else {
      XMLUri baseuri (xbase.get ());
      XMLUri resuri (&baseuri, xrel.get ());
      char *raw_result = XMLString::transcode (resuri.getUriText ());
      result = new xqpStringStore(raw_result);
      delete [] raw_result;
    }
  } catch (MalformedURLException &e) {
    return URI::RESOLUTION_ERROR;
  }

  return URI::MAX_ERROR_CODE;
}

#if 0  // old relative URI resolution code -- might be useful for low footprint
xqp_string static_context::make_absolute_uri(xqp_string uri, xqp_string base_uri)
{
	xqp_string		abs_uri;

	abs_uri = base_uri;

  // TODO is a collation comparison really necessary here?
	if(!abs_uri.endsWith("/") && !abs_uri.endsWith("\\"))
    abs_uri += "/";
  while(!uri.empty()) {
    if((uri.indexOf("/") == 0) || (uri.indexOf("\\") == 0)) {
      uri = uri.substr(1);//skip one char
      continue;
    }
    if(uri.indexOf(".") == 0) {
      xqp_string  tempuri;
      tempuri = uri.substr(1);
      if((tempuri.indexOf("/") == 0) || (tempuri.indexOf("\\") == 0)) {
        uri = uri.substr(2);//skip two chars
        continue;
      }
      else if(tempuri.indexOf(".") == 0) {
        if((tempuri.indexOf("/") != 1) && (tempuri.indexOf("\\") != 1)) {
          ZORBA_ERROR_PARAM_OSS( ZorbaError::XQP0020_INVALID_URI, base_uri << " + " << uri, "");
          return "";
        }
        xqp_string    tempabs;
        tempabs = abs_uri.substr(0, abs_uri.length()-1);
        int32_t   last_slash;
        int32_t   last_backslash;
        last_slash = tempabs.lastIndexOf("/");
        last_backslash = tempabs.lastIndexOf("\\");
        if(last_slash < last_backslash)
          last_slash = last_backslash;
        
        if(last_slash < 0) {
          ZORBA_ERROR_PARAM_OSS( ZorbaError::XQP0020_INVALID_URI, base_uri << " + " << uri, "");
          return "";
        }
        abs_uri = abs_uri.substr(0, last_slash+1);

        uri = uri.substr(3);
        continue;
      }
    }

    int32_t   first_slash;
    int32_t   first_backslash;
    first_slash = uri.indexOf("/");
    first_backslash = uri.indexOf("\\");
    if((first_slash < 0) || 
      (first_slash > first_backslash) && (first_backslash >= 0))
      first_slash = first_backslash;
    if(first_slash < 0)
      first_slash = uri.length();
    else
      first_slash++;//jump over slash
    
    abs_uri += uri.substr(0,first_slash);
    uri = uri.substr(first_slash);
  }

	if(!GenericCast::instance()->isCastable(abs_uri, GENV_TYPESYSTEM.ANY_URI_TYPE_ONE)) {
    ZORBA_ERROR_PARAM_OSS( ZorbaError::XQP0020_INVALID_URI,  base_uri << " + " << uri, "");
    return "";
  }

	return abs_uri;
}

#endif
};
