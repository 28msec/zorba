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

#include "representations.h"

#include "zorbaerrors/error_manager.h"
#include "URI.h"

using namespace std;

namespace zorba {



// encode / decode URI are hacks. Doing it properly would require
// boost-filesystem (or equivalent code).

xqpStringStore_t  URI::decode_file_URI(const xqpStringStore_t& uri)
{
  // TODO: file://localhost/
  if (uri->byteCompare(0, 7, "file://") == 0) {
    xqp_string res(uri->c_str() + 7);
#if defined(UNIX)
    res = xqp_string ("/") + res;
#endif
    return res.decodeFromUri().getStore();
  }
  else
    return uri;
}

// Assumes input is absolute path.
xqpStringStore_t  URI::encode_file_URI(const xqpStringStore_t& uri)
{
  xqpString  result (&*uri);

#if !defined(UNIX)
  result = xqpString ("/") + result;
#endif
  result = xqpString ("file://") + result.encodeForUri();
  return result.getStore();
}

URI::URI( const xqpString& uri )
  : theState(0),
    thePort(0)
{
  initialize(uri); 
}

URI::URI( const URI& base_uri, const xqpString& uri )
  :  theState(0),
     thePort(0)
{
  initialize(uri);
  resolve(&base_uri);
}

URI::URI( const URI& to_copy )
{
  initialize(to_copy);
}

URI::URI()
  : theState(0),
    thePort(0) {}
      


URI::~URI()
{
}

// copy a uri
void
URI::initialize(const URI& to_copy) 
{
  theState             = to_copy.theState;
  theScheme            = to_copy.theScheme;
  theUserInfo          = to_copy.theUserInfo;
  theHost              = to_copy.theHost;
  thePort              = to_copy.thePort;
  theRegBasedAuthority = to_copy.theRegBasedAuthority;
  thePath              = to_copy.thePath;
  theQueryString       = to_copy.theQueryString;
  theFragment          = to_copy.theFragment;
}

bool
URI::is_absolute() const
{
  return is_set(Scheme);
}

// helper

// check whether any of the chars in the second argument is
// contained in the string that is passed as first argument
int
URI::find_any(const xqpString& str, const std::string& patterns) 
{
  for (uint32_t i = 0; i < str.length(); ++i) {
    char s = str.getStore()->str().at(i); 
    for (uint32_t j = 0; j < patterns.length(); ++j) {
      char p = patterns.at(j); 
      if (s == p)
        return i;
    }
  }
  return -1; 
}

// is the given char a hex allowed one
bool
URI::is_hex(char c)
{
  return (is_digit(c) || (c >= 'a'&& c <= 'f') || (c >= 'A'&& c <= 'F'));
}

bool
URI::is_alpha(char c)
{
  if ((( c >= 'a' ) && ( c <= 'z' )) ||
     (( c >= 'A' ) && ( c <= 'Z' )) )
    return true;

  return false;
}

bool
URI::is_digit(char c)
{
  if (( c >= '0' ) && ( c <= '9' ))
    return true;
 
  return false;
}

bool
URI::is_alphanum(char c)
{
  return (is_alpha(c) || is_digit(c));
}


bool
URI::is_unreserved_char(char c)
{
  std::string lMarkCharacter("-_.!~*'{}");
  return (is_alphanum(c) || lMarkCharacter.find(c) != std::string::npos);
}

bool
URI::is_path_character(char c)
{
  std::string lPathChracters(";/:@&=+$,");
  return (lPathChracters.find(c) != std::string::npos);
}

bool
URI::is_reservered_or_unreserved_char(char c)
{
  std::string lMarkOrReservedChars("-_.!~*'();/?:@&=+$,[]");
  return (is_alphanum(c) || lMarkOrReservedChars.find(c) != std::string::npos);
}

// initialize this uri based on a base-uri (i.e. uri resolving) and a (relative) uri given as string
void
URI::initialize(const xqpString& uri)
{
  // first, we need to trim the uri
  // and only work with the trimmed one from this point on
  xqpString lTrimmedURI = uri.trim();
  int    lTrimmedURILength = lTrimmedURI.length();

  // index of the current processing state used in this function
  int lIndex = 0;

  int32_t  lColonIdx    = lTrimmedURI.indexOf(":");
  int32_t  lSlashIdx    = lTrimmedURI.indexOf("/");
  int32_t  lQueryIdx    = lTrimmedURI.indexOf("?");
  int32_t  lFragmentIdx = lTrimmedURI.indexOf("#");


  /**
   * Scheme
   * must be before `/', '?' or '#'.  
   */
  if ((lColonIdx <= 0) ||
      (lColonIdx > lSlashIdx && lSlashIdx != -1) ||
      (lColonIdx > lQueryIdx && lQueryIdx != -1) ||
      (lColonIdx > lFragmentIdx && lFragmentIdx != -1)) {

//   // A standalone base is a valid URI
//  if ( lColonIdx == 0 || (base_uri == 0 && lFragmentIdx != 0) ) {
//    ZORBA_ERROR_DESC_OSS(XQST0046, "URI doesn't have an URI scheme");
//  }

  } else {
    initializeScheme(lTrimmedURI);
    lIndex = theScheme.length() + 1;
  }

  /**
   * Authority
   * two slashes means generic URI syntax, so we get the authority
   */
  xqpString lAuthUri = lTrimmedURI.substr(lIndex, lTrimmedURILength - lIndex);

  if ( ((lIndex + 1) < lTrimmedURILength) &&
       lAuthUri.indexOf("//") == 0) {

    lIndex += 2;

    int lStartPos = lIndex;

    // get authority - everything up to path, query or fragment
    char c;
    while ( lIndex < lTrimmedURILength ) {
      c = lTrimmedURI.getStore()->str().at(lIndex);
      if ( c == '/' || c == '?' || c == '#' ) {
        break;
      }
      ++lIndex;
    }
  
    // if we found authority, parse it out, otherwise we set the
    // host to empty string
    if (lIndex > lStartPos) {
      lAuthUri = lTrimmedURI.substr(lStartPos, lIndex - lStartPos);
      initializeAuthority(lAuthUri);
    } else {
      set_host("");
    }
  }


  // stop, if we're done here
  if (lIndex > lTrimmedURILength)
    return;

  /**
   * Path
   */
  xqpString lPathUri = lTrimmedURI.substr(lIndex, lTrimmedURILength - lIndex);

  initializePath(lPathUri);
}

void
URI::resolve(const URI * base_uri)
{
  if (is_absolute()) {
    return;
  }

  if ( base_uri == 0 && toString().empty() ) {
    ZORBA_ERROR_DESC_OSS(XQST0046, "No base URI given and URILiteral is of zero length");
  }

  if ( toString().empty() ) {
    // just copy the base uri 
    initialize(*base_uri);
  }

  int lIndex = 0;

  // If the path component is empty and the scheme, authority, and
  // query components are undefined, then it is a reference to the
  // current document and we are done.  Otherwise, the reference URI's
  // query and fragment components are defined as found (or not found)
  // within the URI reference and not inherited from the base URI.
  if ( ((!is_set(Path)) || (thePath.empty())) &&
       (!is_set(Scheme) && (!is_set(Host)) && (!is_set(RegBasedAuthority)) )) {

    set_scheme(base_uri->get_scheme());
    if (base_uri->is_set(UserInfo)) {
      set_user_info(base_uri->get_user_info());
    }
    if (base_uri->is_set(Host)) {
      set_host(base_uri->get_host());
    }
    if (base_uri->is_set(Port)) {
      set_port(base_uri->get_port());
    }
    if (base_uri->is_set(RegBasedAuthority)) {
      set_reg_based_authority(base_uri->get_reg_based_authority());
    }
    if (base_uri->is_set(Path)) {
      // I think this is a bug in xerces because it doesn't remove the last segment
      int last_slash = base_uri->get_path().lastIndexOf("/");
      if ( last_slash != -1 )
        thePath = base_uri->get_path().substr(0, last_slash+1);
      else 
        thePath = base_uri->get_path();
      set_state(Path);
    }
    if ( (! is_set(QueryString)) ) {
        theQueryString = base_uri->get_query();
        set_state(QueryString);
    }
    theURIText = ""; // force rebuild in get_uri_text
    return;
  }

  // If the scheme component is defined, indicating that the reference
  // starts with a scheme name, then the reference is interpreted as an
  // absolute URI and we are done.  Otherwise, the reference URI's
  // scheme is inherited from the base URI's scheme component.
  if ( is_set(Scheme) ) {
    theURIText = ""; // force rebuild in get_uri_text
    return;
  }

  set_scheme(base_uri->get_scheme());

  // If the authority component is defined, then the reference is a
  // network-path and we skip to step 7.  Otherwise, the reference
  // URI's authority is inherited from the base URI's authority
  // component, which will also be undefined if the URI scheme does not
  // use an authority component.
  if ( (!is_set(Host)) && (!is_set(RegBasedAuthority)) ) {
    if (base_uri->is_set(UserInfo)) {
      theUserInfo = base_uri->get_user_info(); 
      set_state(UserInfo);
    }
    if (base_uri->is_set(Host)) {
      theHost = base_uri->get_host();
      set_state(Host);
    }
    if (base_uri->is_set(Port)) {
      thePort = base_uri->get_port();
      set_state(Port);
    }
    if (base_uri->is_set(RegBasedAuthority)) {
      theRegBasedAuthority = base_uri->get_reg_based_authority();
      set_state(RegBasedAuthority);
    }
  } else {
    theURIText = ""; // force rebuild in toString
    theASCIIURIText = "";
    return;
  }


  // If the path component begins with a slash character ("/"), then
  // the reference is an absolute-path and we skip to step 7.
  if ( (is_set(Path)) && (thePath.indexOf("/") == 0) ) {
    theURIText = ""; // force rebuild in get_uri_text
    theASCIIURIText = "";
    return;
  }


  xqpString base_path = base_uri->get_path();

  xqpString path;
  if ( base_uri->is_set(Path) ) {
    int last_slash = base_path.lastIndexOf("/");
    if ( last_slash != -1 )
      path = base_path.substr(0, last_slash+1);
    else
      path = "/";

  }

  // 6b - append the relative URI path
  path += thePath;

  // 6c - remove all "./" where "." is a complete path segment
  path = path.replace("/\\./", "/", "");

  // 6d If the buffer string ends with "." as a complete path segment,
  //  that "." is removed.
  if (path.endsWith("/.")) {
    path = path.substr(0, path.length() - 1);
  }

  // 6e All occurrences of "<segment>/../", where <segment> is a
  // complete path segment not equal to "..", are removed from the
  // buffer string.  Removal of these path segments is performed
  // iteratively, removing the leftmost matching pattern on each
  // iteration, until no matching pattern remains.
  lIndex = -1;
  int segIndex = -1;
  int offset = 1;

  xqpString tmp_path = path.substr(1, path.length() - 1 );
  xqpString tmp1, tmp2;
  while ((lIndex = tmp_path.indexOf("/../")) != -1) { // XMLString::patternMatch(&(path[offset]), SLASH_DOTDOT_SLASH)) != -1)

    // Undo offset
    lIndex += offset;
    
    // Find start of <segment> within substring ending at found point.
    tmp1 = path.substr(0, lIndex - 1);
    segIndex = tmp1.lastIndexOf("/");


    // Ensure <segment> exists and != ".."
    if (segIndex != -1                &&
        (path.getStore()->str().at(segIndex+1) != '.' ||
         path.getStore()->str().at(segIndex+2) != '.' ||
         segIndex + 3 != lIndex)) {
      

      tmp1 = path.substr(0, segIndex);
      tmp2 = path.substr(lIndex+3, path.length() - lIndex - 3);

      path = "";
      path += tmp1;
      path += tmp2;

      offset = (segIndex == 0 ? 1 : segIndex);
    } else {
      offset += 4;
    }
    tmp_path = path.substr(offset, tmp_path.length() - offset);
  } // while

  // 6f) If the buffer string ends with "<segment>/..", where <segment>
  // is a complete path segment not equal to "..", that
  // "<segment>/.." is removed.
  if (path.endsWith("/..")) {

    // Find start of <segment> within substring ending at found point.
    lIndex = path.length() - 3;
    tmp1 = path.substr(0, lIndex - 1);
    segIndex = tmp1.lastIndexOf("/");

    if (segIndex != -1                &&
        (path.getStore()->str().at(segIndex+1) != '.' ||
         path.getStore()->str().at(segIndex+2) != '.' ||
         segIndex + 3 != lIndex))
    {
      path = path.substr(0, segIndex+1);
    }
  }
  
  thePath = path;
  theURIText = ""; // force rebuild in get_uri_text
  theASCIIURIText = "";
}

// scheme = alpha *( alpha | digit | "+" | "-" | "." )
void
URI::initializeScheme(const xqpString& uri)
{
  int lSchemeSeparatorIdx = find_any(uri, ":/?#");  
  if (lSchemeSeparatorIdx == -1 ) {
    ZORBA_ERROR_DESC_OSS(XQST0046, "URI doesn't have an URI scheme");
  } else {
    set_scheme(uri.substr(0, lSchemeSeparatorIdx));
  }
}

void
URI::initializeAuthority(const xqpString& uri)
{
  int lIndex = 0;
  int lStart = 0;
  const int lEnd = uri.length();

  xqpString lUserInfo;
  bool      lUserInfoFound;


  lIndex = uri.indexOf("@");

  if ( lIndex != -1 ) {
    lUserInfo = uri.substr(0, lIndex);
    ++lIndex;
    lStart += lIndex;
    lUserInfoFound = true;
  } else {
    lUserInfoFound = false;
  }

  //
  // hostport = host [ ":" port ]
  // host is everything up to ':', or up to 
  // and including ']' if followed by ':'.
  //
  xqpString lHost;
  xqpString lTmp; // used for substrings starting at lStart
  if ( lStart < lEnd && uri.getStore()->str().at(lStart) == '[' ) {
    lTmp = uri.substr(lStart, uri.length() - lStart);
    lIndex = lTmp.indexOf("]");
    if ( lIndex != -1 ) { 
      lIndex = ( ( (lStart + lIndex + 1 ) < lEnd )
                && (uri.getStore()->str().at(lStart + lIndex + 1)) == ':') ? lIndex + 1 : -1;
    }
  } else {
    lTmp = uri.substr(lStart, uri.length() - lStart);
    lIndex = lTmp.indexOf(":");
  }

  if ( lIndex != -1 ) {
    lHost = lTmp.substr(0, lIndex);
    ++lIndex; // skip the colon
    lStart += lIndex;
  } else {
    lHost = lTmp.substr(0, lEnd - lStart);
    lStart = lEnd;
  }

  lTmp = uri.substr(lStart, uri.length() - lStart);
  xqpString lPortString;
  int lPort = -1;

  if ( ( ! lHost.empty() ) && ( lIndex != -1 ) && ( lStart < lEnd ) ) {
    lPortString = lTmp.substr(0, lEnd - lStart);

    if ( !lPortString.empty() ) {
      lPort = atoi(lPortString.c_str());
    } 
  } else if ( lStart >= lEnd && lIndex != -1 ) {
    lPort = -2;
  }

  if ( is_valid_server_based_authority(lHost, lPort, lUserInfo, lUserInfoFound) ) {
    theHost = lHost;
    set_state(Host);
    if (lPort != -1) {
      thePort = lPort;
      set_state(Port);
    }
    if (lUserInfoFound) {
      set_user_info(lUserInfo);
    }

    return;
  }
  set_reg_based_authority(uri);
}

bool
URI::is_valid_server_based_authority(const xqpString& host, const int port, const xqpString& user_info, bool user_info_found)
{
  if ( !is_well_formed_address(host) )  {
    return false;
   }

  if ( (port > 65535) || ( port < 0 && port != -1) ) {
    return false;
  }

  // TODO check user_info
  
  return true;
}

bool
URI::is_well_formed_ipv4_address(const xqpString& addr, size_t length)
{
  int lNumDots = 0;
  int lNumDigits = 0;

  for (size_t i = 0; i < length; ++i) {
    char c = addr.getStore()->str().at(i);
    if (c == '.') {
      if ( (i == 0) || (i+1 == length) || ! is_digit(addr.getStore()->str().at(i+1)) )
        return false;
    } else if ( ! is_digit(c) ) {
      return false;
    } else if ( ++lNumDigits > 3) {
      return false;
    } else if ( lNumDigits == 3) {
      char lFirst  = addr.getStore()->str().at(i-2);
      char lSecond = addr.getStore()->str().at(i-1);
      char lLast   = addr.getStore()->str().at(i);
      if ( !(lFirst < '2' || ( lFirst == '2' && ( lSecond < '5' || (lSecond == '5' && lLast <= '5'))))) 
        return false;
    }
  }
  return ( lNumDots == 3 );
}

bool
URI::is_well_formed_ipv6_reference(const xqpString& addr, size_t length)
{
  int lIndex = 1;
  int lEnd = length-1;

  // Check if string is a potential match for IPv6reference.
  if (!(length > 2 && addr.getStore()->str().at(0) == '[' && addr.getStore()->str().at(lEnd) == ']')) {
      return false;
  }

  // Counter for the number of 16-bit sections read in the address.
  int lCounter = 0;
  
  lIndex = scanHexSequence(addr, lIndex, lEnd, lCounter);
  if ( lIndex == -1) {
      return false;
  }
 // Address must contain 128-bits of information.
  else if (lIndex == lEnd) {
     return (lCounter == 8);
  }
    
  if (lIndex+1 < lEnd && addr.getStore()->str().at(lIndex) == ':') {
      if (addr.getStore()->str().at(lIndex+1) == ':') {
          // '::' represents at least one 16-bit group of zeros.
          if (++lCounter > 8) {
              return false;
          }
          lIndex += 2;
          // Trailing zeros will fill out the rest of the address.
          if (lIndex == lEnd) {
              return true;
          }
      }
      // If the second character wasn't ':', in order to be valid,
      // the remainder of the string must match IPv4Address, 
      // and we must have read exactly 6 16-bit groups.
      else { 
          if (lCounter == 6) {
              xqpString lTmp = addr.substr(lIndex+1, lEnd - lIndex -1);
              return is_well_formed_ipv4_address(lTmp, lEnd - lIndex - 1);
          } else
              return false;
      }
  } else {
     return false;
  }
    
  // 3. Scan hex sequence after '::'.
  int prevCount = lCounter;
  lIndex = scanHexSequence(addr, lIndex, lEnd, lCounter);
  if (lIndex == -1) {
      return false;
  }
  // If this is the end of the address then
  // we've got 128-bits of information.
  else if (lIndex == lEnd) 
  {
      return true;
  }

  // The address ends in an IPv4 address, or it is invalid. 
  // scanHexSequence has already made sure that we have the right number of bits. 
  int shiftCount = (lCounter > prevCount) ? lIndex+1 : lIndex;
  xqpString lTmp = addr.substr(shiftCount, lEnd - shiftCount);
  return is_well_formed_ipv4_address(lTmp, lEnd - shiftCount);


}

bool 
URI::is_well_formed_address(const xqpString& addr)
{
  if (addr.empty()) {
    return false;
  }

  size_t lStringLen = addr.length();

  if (addr.indexOf("[") == 0) {
    return is_well_formed_ipv6_reference(addr, lStringLen);
  }

  char c = addr.getStore()->str().at(0);
  if ( c == '.' || c == '-' || addr.getStore()->str().at(lStringLen-1) == '-') {
    return false;
  }

  size_t lLastPeriodPos = addr.lastIndexOf(".");
  if ( lLastPeriodPos + 1 == lStringLen ) {
    xqpString lTmp = addr.substr(0, lLastPeriodPos);
    lLastPeriodPos = lTmp.lastIndexOf(".");

    if ( is_digit(addr.getStore()->str().at(lLastPeriodPos + 1)) ) {
      return false;
    }
  }

  if ( is_digit(addr.getStore()->str().at(lLastPeriodPos + 1)) ) {
    return is_well_formed_ipv4_address(addr, lStringLen);
  } else {
    if (lStringLen > 255) {
      return false;
    }

    uint32_t lLabelCharCount = 0;

    for (size_t i = 0; i < lStringLen; ++i) {
      char c1 = addr.getStore()->str().at(i);
      if ( c1 == '.' ) {

        if ( (( i > 0 ) && ( ! is_alphanum(addr.getStore()->str().at(i-1)))) ||
             (( i + 1 < lStringLen ) && ( ! is_alphanum(addr.getStore()->str().at(i+1)))) ) {
          return false;
        }
        
        lLabelCharCount = 0;

      } else if ( ! is_alphanum(c1) && c1 != '-' ) {
        return false;
      } else if ( ++lLabelCharCount > 63 ) {
        return false;
      }
    }
  }
  return true;
}

void
URI::initializePath(const xqpString& uri)
{
  int lIndex = 0;
  int lStart = 0;
  int lEnd = uri.length();
  char c = 0;

  // path - everything up to query string or fragment
  if ( lStart < lEnd ) {

    // RFC 2732 only allows '[' and ']' to appear in the opaque part.
    if ( ! is_set(Scheme) || uri.getStore()->str().at(lStart) == '/') {
      // Scan path.
      // abs_path = "/"  path_segments
      // rel_path = rel_segment [ abs_path ]
      while ( lIndex < lEnd ) {
        c = uri.getStore()->str().at(lIndex);
        if ( c == '?' || c == '#' ) {
          break;
        }

        if ( c == '%' ) {
          if ( lIndex + 2 >= lEnd ) { // TODO check hex and throw errors
            
          }
        } else if (!is_unreserved_char(c) && !is_path_character(c)) 
        {
          ZORBA_ERROR_DESC_OSS(XQST0046, "Invalid char in URI: '" << c << "': " << uri);
        }
        ++lIndex;
      }
    } else {

      while ( lIndex < lEnd ) {
        c = uri.getStore()->str().at(lIndex);
        if ( c == '?' || c == '#' ) {
          break;
        }

        if ( c == '%' ) {
          // TODO check errors
        } else if (!is_reservered_or_unreserved_char(c)) {
          ZORBA_ERROR_DESC_OSS(XQST0046, "Invalid char in URI '" << c << "'");
        }
        ++lIndex;
      }
    }

  } // lStart < lEnd

  thePath = uri.substr(lStart, lIndex - lStart);
  set_state(Path);

  // query - starts with ? and up to fragment or end
  if ( c == '?' ) {
    ++lIndex;
    lStart = lIndex;
    while ( lIndex < lEnd ) {
      c = uri.getStore()->str().at(lIndex);
      if ( c == '#' ) {
        break;
      }

      // TODO check conformance
      ++lIndex;
    } /* lIndex < lEnd */

    theQueryString = uri.substr(lStart, lIndex - lStart);
    set_state(QueryString);
  }

  // fragment - starts with #
  if ( c == '#' ) {
    ++lIndex;
    lStart = lIndex;
    while ( lIndex < lEnd ) {
      c = uri.getStore()->str().at(lIndex);

      // TODO check conformance

      ++lIndex;
    } /* lIndex < lEnd */

    if ( lIndex > lStart) {
      theFragment = uri.substr(lStart, lIndex - lStart);
      set_state(Fragment);
    } else {
      // fragment is not set
    }
  }
}

void
URI::set_scheme(const xqpString& new_scheme)
{
  if ( new_scheme.empty() ) {
    ZORBA_ERROR_DESC_OSS(XQST0046, "URI scheme is empty");
    
  }

  if ( ! is_conformant_scheme_name(new_scheme) ) {
    ZORBA_ERROR_DESC_OSS(XQST0046, "URI contain's a scheme that is not a conformant URI scheme");
  }

  theScheme = new_scheme; //.lowercase();
  set_state(Scheme);
}


bool
URI::is_conformant_scheme_name(const xqpString& scheme)
{
  // start with a-zA-Z
  if ( ! scheme.matches("[a-zA-Z]", "" ) )
    return false;
  

  for (uint32_t i = 0; i < scheme.length(); ++i) {
    char c = scheme.getStore()->str().at(i);

    if ( ! is_alpha(c) && xqpString("+-.").indexOf(&c) == -1 ) {
      return false; 
    }
  }
  return true;
}

void
URI::set_user_info(const xqpString& new_user_info)
{
  theUserInfo = new_user_info.encodeForUri();
  set_state(UserInfo);
}


void
URI::set_host(const xqpString& new_host)
{
  theHost = new_host;
  set_state(Host);
}

void
URI::set_port(int new_port)
{
  thePort = new_port;
  set_state(Port);
}

void
URI::set_reg_based_authority(const xqpString& new_authority)
{
  if ( new_authority.empty() ) {
    return;
  } 

  // TODO check valid registry based authority

  theRegBasedAuthority = new_authority;
  set_state(RegBasedAuthority);

  unset_state(Host);
}

void
URI::set_path(const xqpString& new_path)
{
  if (new_path.empty()) {
    thePath = "";
    unset_state(Path);
    theQueryString = "";
    unset_state(QueryString);
    theFragment = "";
    unset_state(Fragment);
  } else {
    initializePath(new_path);
  }
}

const xqpString&
URI::toString() const
{
  if (theURIText.length() == 0) {
    build_full_text();
  }
  return theURIText;
}

const xqpString&
URI::toASCIIString() const
{
  if (theASCIIURIText.length() == 0) {
    build_ascii_full_text();
  }
  return theASCIIURIText;
}

void
URI::build_full_text() const
{
  std::ostringstream lURI;
  
  // Scheme
  if ( is_set(Scheme) )
    lURI << theScheme << ":";

  // Authority
  if ( is_set(Host) || is_set(RegBasedAuthority) ) {
    lURI << "//";
    
    if ( is_set(Host) ) {
      if ( is_set(UserInfo) )
        lURI << theUserInfo << "@";

      lURI << theHost;

      if ( is_set(Port) )
        lURI << ":" << thePort;
    } else {
      lURI << theRegBasedAuthority;
    }
  }

  if ( is_set(Path) )
    lURI << thePath;

  if ( is_set(QueryString) )
    lURI << "?" << theQueryString;

  if ( is_set(Fragment) )
    lURI << "#" << theFragment;

  theURIText = lURI.str();
}

void
URI::build_ascii_full_text() const
{
  std::ostringstream lURI;
  
  // Scheme
  if ( is_set(Scheme) )
    lURI << theScheme << ":";

  // Authority
  if ( is_set(Host) || is_set(RegBasedAuthority) ) {
    lURI << "//";
    
    if ( is_set(Host) ) {
      if ( is_set(UserInfo) )
        lURI << theUserInfo << "@";

      lURI << theHost;

      if ( is_set(Port) )
        lURI << ":" << thePort;
    } else {
      lURI << theRegBasedAuthority;
    }
  }

  if ( is_set(Path) )
    lURI << thePath;

  if ( is_set(QueryString) )
    lURI << "?" << theQueryString;

  if ( is_set(Fragment) )
    lURI << "#" << theFragment;

  theURIText = lURI.str();
}

//
//  For use with isWellFormedIPv6Reference only.
//
int 
URI::scanHexSequence (const xqpString& addr, int index, int end, int& counter) {
  char c;
  int lNumDigits = 0;
  int lStart = index;
    
  // Trying to match the following productions:
  // hexseq = hex4 *( ":" hex4)
  // hex4   = 1*4HEXDIG
  for (; index < end; ++index) {
      c = addr.getStore()->str().at(index);
      if ( c == ':' ) {
          // IPv6 addresses are 128-bit, so there can be at most eight sections.
          if (lNumDigits > 0 && ++counter > 8) {
              return -1;
          }
          // This could be '::'.
          if (lNumDigits == 0 || ((index+1 < end) && addr.getStore()->str().at(index+1) == ':')) {
              return index;
          }
          lNumDigits = 0;
      }
      // This might be invalid or an IPv4address. If it's potentially an IPv4address,
      // backup to just after the last valid character that matches hexseq.
      else if (!is_hex(c)) {
          if ( c == '.' && 
               lNumDigits < 4 && 
               lNumDigits > 0 && 
               counter <= 6) {
              int lBack = index - lNumDigits - 1;
              return (lBack >= lStart) ? lBack : lStart;
          }
          return -1;
      }
      // There can be at most 4 hex digits per group.
      else if (++lNumDigits > 4) {
          return -1;
      }
  }
  return (lNumDigits > 0 && ++counter <= 8) ? end : -1;    
}

};
