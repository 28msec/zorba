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
#include "stdafx.h"

#include "schema_types.h"

#include "diagnostics/xquery_diagnostics.h"
#include "diagnostics/dict.h"
#include "diagnostics/assert.h"

#include <zorba/util/path.h>

#include "URI.h"

#include "util/ascii_util.h"
#include "util/string_util.h"
#include "util/uri_util.h"
#include "util/utf8_util.h"
#include "zorbautils/string_util.h"


using namespace std;

namespace zorba {

  /*
  ---------------------------------------------------------------------------
  URI-reference = [ absoluteURI | relativeURI ] [ "#" fragment ]
  absoluteURI   = scheme ":" ( hier_part | opaque_part )
  relativeURI   = ( net_path | abs_path | rel_path ) [ "?" query ]
  ---------------------------------------------------------------------------
  query         = *uric

  fragment      = *uric
---------------------------------------------------------------------------
  */


/*******************************************************************************

********************************************************************************/
bool URI::is_unreserved_char(uint32_t c)
{
  static std::string lMarkCharacter("-_.!~*'{}");
  return (ascii::is_alnum(c) || (c == ' ') || (c > 127 ) ||
    ((c<128) && lMarkCharacter.find((char)c) != std::string::npos));
}


/*******************************************************************************

********************************************************************************/
bool URI::is_path_character(uint32_t c)
{
  static std::string lPathChracters(";/\\:@&=+$,");
  return ((c<128) && lPathChracters.find((char)c) != std::string::npos);
}


/*******************************************************************************

********************************************************************************/
bool URI::is_reservered_or_unreserved_char(uint32_t c)
{
  static std::string lMarkOrReservedChars("-_.!~*'();/?:@&=+$,[]");
  return (ascii::is_alnum(c) ||
          (c == ' ') ||
          ((c<128) && lMarkOrReservedChars.find((char)c) != std::string::npos));
}


/*******************************************************************************
  Note: The encode_file_URI and decode_file_URI methods are hacks. Doing it
  properly would require boost-filesystem (or equivalent code).

  The decode_file_URI() method takes a file URI and converts it to a filepath
  in the native OS foramt.
********************************************************************************/
void URI::decode_file_URI(const zstring& uri, zstring& filepath)
{
  // TODO: file://localhost/
#ifdef WIN32
  if (uri.compare(0, 8, "file:///") == 0 && 
      ((uri.compare(9, 1, ":") == 0) || (uri.compare(9, 4, "%3A/") == 0))) 
  {
    zstring tmp(uri.c_str() + 8);
    uri::decode(tmp, &filepath);
  }
  else
#endif
    if (uri.compare(0, 8, "file:///") == 0) 
    {
      zstring tmp(uri.c_str() + 7);
      uri::decode(tmp, &filepath);
    }
    else if (uri.compare(0, 17, "file://localhost/") == 0)
    {
      zstring tmp(uri.c_str() + 16);
      uri::decode(tmp, &filepath);
    }
    else
    {
      // should we raise an unknown host exception?
      filepath = uri;
    }

#ifdef WIN32
  ascii::replace_all(filepath, '/', '\\');
#endif
}


/*******************************************************************************
  The encode_file_URI() method takes a filepath and converts it to a file URI.

  Assumes input is absolute path.
********************************************************************************/
void URI::encode_file_URI(const zstring& filepath, zstring& uri)
{
  if (filepath.find("://", 0, 3) != zstring::npos)
  {
    uri = filepath;
    return;
  }

#ifdef WIN32
  uri = "file:///";

  zstring tmp1( filepath );
  ascii::replace_all( tmp1, '\\', '/' );

  zstring tmp2;
  uri::encode(tmp1, &tmp2, false);

  uri.append(tmp2);

#else
  if (filepath[0] == '/')
    uri = "file://";
  else
    uri = "file:///";

  zstring tmp;
  uri::encode(filepath, &tmp, false);

  uri.append(tmp);
#endif
}


/*******************************************************************************
  The encode_file_URI() method takes a filepath and converts it to a file URI.

  Assumes input is absolute path.
********************************************************************************/
std::string URI::encode_file_URI(const std::string& filepath)
{
  zstring uri;
  encode_file_URI(filepath, uri);
  return uri.str();
}


/*******************************************************************************

********************************************************************************/
bool URI::is_well_formed_address(const char* addr, ulong addrLen)
{
  if (addrLen == 0) 
  {
    return false;
  }

  char c = addr[0];

  if (c == '[') 
  {
    return is_well_formed_ipv6_reference(addr, addrLen);
  }

  if ( c == '.' || c == '-' || addr[addrLen-1] == '-') 
  {
    return false;
  }

  zstring_b wrap;
  wrap.wrap_memory(addr, addrLen);

  zstring::size_type lLastPeriodPos = wrap.rfind(".");

  if ( lLastPeriodPos != zstring::npos && lLastPeriodPos + 1 == addrLen ) 
  {
    zstring_b wrap2;
    wrap2.wrap_memory(addr, lLastPeriodPos);
    lLastPeriodPos = wrap2.rfind(".");

    if ( lLastPeriodPos != zstring::npos && ascii::is_digit(addr[lLastPeriodPos + 1]) )
    {
      return false;
    }
  }

  if ( lLastPeriodPos != zstring::npos && ascii::is_digit(addr[lLastPeriodPos + 1]) ) 
  {
    return is_well_formed_ipv4_address(addr, addrLen);
  }
  else 
  {
    if (addrLen > 255)
    {
      return false;
    }

    ulong lLabelCharCount = 0;

    for (ulong i = 0; i < addrLen; ++i) 
    {
      char c1 = addr[i];

      if ( c1 == '.' ) 
      {
        if ( ( i > 0  &&  ! ascii::is_alnum(addr[i-1])) ||
             ( i + 1 < addrLen  && ! ascii::is_alnum(addr[i+1])) ) 
        {
          return false;
        }
        
        lLabelCharCount = 0;
      }
      else if ( ! ascii::is_alnum(c1) && c1 != '-' )
      {
        return false;
      }
      else if ( ++lLabelCharCount > 63 )
      {
        return false;
      }
    }
  }

  return true;
}



/*******************************************************************************

********************************************************************************/
bool URI::is_well_formed_ipv4_address(const char* addr, ulong length)
{
  ulong numDots = 0;
  ulong numDigits = 0;

  for (ulong i = 0; i < length; ++i)
  {
    char c = addr[i];

    if (c == '.') 
    {
      if ( (i == 0) || (i+1 == length) || ! ascii::is_digit(addr[i+1]) )
        return false;
    }
    else if ( ! ascii::is_digit(c) )
    {
      return false;
    }
    else if (++numDigits > 3)
    {
      return false;
    }
    else if (numDigits == 3)
    {
      char lFirst  = addr[i-2];
      char lSecond = addr[i-1];
      char lLast   = addr[i];

      if ( !(lFirst < '2' ||
             (lFirst == '2' && (lSecond < '5' || (lSecond == '5' && lLast <= '5'))))) 
        return false;
    }
  }

  return (numDots == 3);
}


/*******************************************************************************

********************************************************************************/
bool URI::is_well_formed_ipv6_reference(const char* addr, ulong length)
{
  long lIndex = 1;
  long lEnd = length-1;

  // Check if string is a potential match for IPv6reference.
  if (!(length > 2 && addr[0] == '[' && addr[lEnd] == ']')) 
  {
    return false;
  }

  // Counter for the number of 16-bit sections read in the address.
  long lCounter = 0;
  
  lIndex = scanHexSequence(addr, lIndex, lEnd, lCounter);
  if ( lIndex == -1) 
  {
    return false;
  }

  // Address must contain 128-bits of information.
  else if (lIndex == lEnd) 
  {
    return (lCounter == 8);
  }
  
  if (lIndex+1 < lEnd && addr[lIndex] == ':') 
  {
    if (addr[lIndex+1] == ':') 
    {
      // '::' represents at least one 16-bit group of zeros.
      if (++lCounter > 8) 
      {
        return false;
      }

      lIndex += 2;

      // Trailing zeros will fill out the rest of the address.
      if (lIndex == lEnd)
      {
        return true;
      }
    }

    // If the second character wasn't ':', in order to be valid,
    // the remainder of the string must match IPv4Address, 
    // and we must have read exactly 6 16-bit groups.
    else
    { 
      if (lCounter == 6)
      {
        return is_well_formed_ipv4_address(addr + lIndex+1, lEnd - lIndex - 1);
      }
      else
      {
        return false;
      }
    }
  }
  else
  {
    return false;
  }
  
  // 3. Scan hex sequence after '::'.
  int prevCount = lCounter;

  lIndex = scanHexSequence(addr, lIndex, lEnd, lCounter);
  if (lIndex == -1) 
  {
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

  return is_well_formed_ipv4_address(addr + shiftCount, lEnd - shiftCount);
}


/*******************************************************************************
  For use with isWellFormedIPv6Reference only.
********************************************************************************/
long URI::scanHexSequence(
    const char* addr,
    long index,
    long end,
    long& counter) 
{
  char c;
  long lNumDigits = 0;
  long lStart = index;
    
  // Trying to match the following productions:
  // hexseq = hex4 *( ":" hex4)
  // hex4   = 1*4HEXDIG
  for (; index < end; ++index) 
  {
    c = addr[index];

    if ( c == ':' ) 
    {
      // IPv6 addresses are 128-bit, so there can be at most eight sections.
      if (lNumDigits > 0 && ++counter > 8) 
      {
        return -1;
      }

      // This could be '::'.
      if (lNumDigits == 0 || ((index+1 < end) && addr[index+1] == ':'))
      {
        return index;
      }

      lNumDigits = 0;
    }

    // This might be invalid or an IPv4address. If it's potentially an IPv4address,
    // backup to just after the last valid character that matches hexseq.
    else if (!ascii::is_xdigit(c)) 
    {
      if (c == '.' && 
          lNumDigits < 4 && 
          lNumDigits > 0 && 
          counter <= 6)
      {
        long lBack = index - lNumDigits - 1;
        return (lBack >= lStart) ? lBack : lStart;
      }

      return -1;
    }

    // There can be at most 4 hex digits per group.
    else if (++lNumDigits > 4) 
    {
      return -1;
    }
  }

  return (lNumDigits > 0 && ++counter <= 8) ? end : -1;    
}


/*******************************************************************************
  construct a uri
********************************************************************************/
URI::URI(const zstring& uri, bool validate)
  : 
  theState(0),
  thePort(0),
  valid(validate)
{
  initialize(uri);

  //std::cout << "empty rep 2 = " << std::hex << theScheme.empty_rep() << std::endl;
}


/*******************************************************************************
  construct a uri and eventually resolve with the given base uri
********************************************************************************/
URI::URI(const URI& base_uri, const zstring& uri, bool validate)
  :
  theState(0),
  thePort(0),
  valid(validate)
{
  initialize(uri, true);
  resolve(&base_uri);
}


/*******************************************************************************
  constructs a new uri by relativizing the full_uri against the base_uri
********************************************************************************/
URI::URI(const URI& full_uri, const URI& base_uri)
   :
  theState(0),
  thePort(0),
  valid(false)
{
  initialize(full_uri.toString(), false);
  relativize(&base_uri);
}


/*******************************************************************************
  copy constructor
********************************************************************************/
URI::URI(const URI& to_copy)
{
  initialize(to_copy);
}


/*******************************************************************************
  default (empty) constructor)
********************************************************************************/
URI::URI()
  :
  theState(0),
  thePort(0),
  valid(true)
{
}


/*******************************************************************************
  destructor
********************************************************************************/
URI::~URI()
{
}


/*******************************************************************************
  copy a uri
********************************************************************************/
void URI::initialize(const URI& to_copy) 
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
  valid                = to_copy.valid;
}


/*******************************************************************************
  Initialize this uri based on a base-uri (i.e. uri resolving) and a (relative)
  uri given as string
********************************************************************************/
void URI::initialize(const zstring& uri, bool have_base)
{
  invalidate_text();
  thePathNotation.clear();
  theScheme.clear();
  theHost.clear();
  theUserInfo.clear();
  theRegBasedAuthority.clear();
  thePath.clear();
  theQueryString.clear();
  theFragment.clear();

  // first, we need to normalize the spaces in the uri
  // and only work with the normalized version from this point on
  zstring lTrimmedURI;
  ascii::normalize_whitespace(uri, &lTrimmedURI);
  ascii::trim_whitespace(lTrimmedURI);

  zstring::size_type lTrimmedURILength = lTrimmedURI.size();

  // index of the current processing state used in this function
  ulong lIndex = 0;

  zstring::size_type lColonIdx    = lTrimmedURI.find(":");
  zstring::size_type lSlashIdx    = lTrimmedURI.find("/");
  zstring::size_type lQueryIdx    = lTrimmedURI.find("?");
  zstring::size_type lFragmentIdx = lTrimmedURI.find("#");

#ifdef WIN32
  // on WIN32 we might have a drive specification ("C:")
  // and we don't want to consider this as scheme
  char lLetter = lTrimmedURI[0];
  bool lIsDrive = false;
  if (lColonIdx == 1 &&
     ((lLetter >= 65 && 90 >= lLetter) || (lLetter >= 97 && 122 >= lLetter)))
  {
    lIsDrive = true;
  }
#endif

  /**
   * Scheme
   * must be before `/', '?' or '#'.  
   */
  if ((lColonIdx == 0 || lColonIdx == zstring::npos) ||
#ifdef WIN32
      // avoid interpreting the drive as a scheme
      lIsDrive ||
#endif
      (lColonIdx > lSlashIdx && lSlashIdx != zstring::npos) ||
      (lColonIdx > lQueryIdx && lQueryIdx != zstring::npos) ||
      (lColonIdx > lFragmentIdx && lFragmentIdx != zstring::npos)) 
  {
    // A standalone base is a valid URI
    if (valid &&
        (lColonIdx == 0 || (!have_base && lFragmentIdx != zstring::npos)) &&
        lTrimmedURILength > 0)
    {
      throw XQUERY_EXCEPTION(
        err::XQST0046, ERROR_PARAMS( lTrimmedURI, ZED( NoURIScheme ) )
      );
    }
  }
  else
  {
    initializeScheme(lTrimmedURI);

    lIndex = (ulong)theScheme.size() + 1;
  }

  /**
   * Authority
   * two slashes means generic URI syntax, so we get the authority
   */
  if (lTrimmedURI.compare(lIndex, 2, "//") == 0) 
  {
    lIndex += 2;
    if (lIndex >= lTrimmedURILength)
    {
      throw XQUERY_EXCEPTION(
        err::XQST0046, ERROR_PARAMS( lTrimmedURI, ZED( NoURIAuthority ) )
      );
    }
    else
    {
      ulong lStartPos = lIndex;

      // get authority
      // (everything up to path, query, fragment or the end of the URI)
      // RFC3986, 3.2, par. 2
      char c;
      while (lIndex < lTrimmedURILength) 
      {
        c = lTrimmedURI[lIndex];

        if (c == '/' || c == '?' || c == '#')
          break;

        ++lIndex;
      }

      // if we found authority, parse it out, otherwise we set the
      // host to empty string
      if (lIndex > lStartPos) 
      {
        zstring lAuthUri = lTrimmedURI.substr(lStartPos, lIndex - lStartPos);

        // For "file" scheme only allow "localhost" as authority.
        // This makes this implementation the same with the file module.
        // If this functionality is changed, please make the same changes
        // in the file module.
        if (ZSTREQ(theScheme, "file") &&
            !ZSTREQ(lAuthUri, "localhost")) 
        {
          throw XQUERY_EXCEPTION(
            err::XQST0046,
            ERROR_PARAMS( lTrimmedURI, ZED( BadFileURIAuthority_2 ), lAuthUri )
          );
        }

        initializeAuthority(lAuthUri);
      }
      else 
      {
        set_host(zstring());
      }
    }
    // do not allow constructs like: file:D:/myFile or http:myFile
  }
  else if (ZSTREQ(theScheme, "file") ||
           ZSTREQ(theScheme, "http") ||
           ZSTREQ(theScheme, "https")) 
  {
    if (valid)
    {
      throw XQUERY_EXCEPTION(
        err::XQST0046,
        ERROR_PARAMS( lTrimmedURI, ZED( BadURISyntaxForScheme_3 ), theScheme )
      );
     }
  }

  // stop, if we're done here
  if (lIndex > lTrimmedURILength)
    return;

  /**
   * Path
   */
  zstring lPathUri = lTrimmedURI.substr(lIndex, lTrimmedURILength - lIndex);

  initializePath(lPathUri);
}


/*******************************************************************************
   scheme = alpha *( alpha | digit | "+" | "-" | "." )
********************************************************************************/
void URI::initializeScheme(const zstring& uri)
{
  zstring::size_type lSchemeSeparatorIdx = uri.find_first_of(":/?#", 0,4 );
  
  if ( valid && lSchemeSeparatorIdx == zstring::npos ) 
  {
    throw XQUERY_EXCEPTION(
      err::XQST0046, ERROR_PARAMS( uri, ZED( NoURIScheme ) )
    );
  }
  else
  {
    set_scheme(uri.substr(0, lSchemeSeparatorIdx));
  }
}


/*******************************************************************************
  authority     = server | reg_name

  reg_name      = 1*( unreserved | escaped | "$" | "," |
                      ";" | ":" | "@" | "&" | "=" | "+" )

  server        = [ [ userinfo "@" ] hostport ]
  userinfo      = *( unreserved | escaped |
                      ";" | ":" | "&" | "=" | "+" | "$" | "," )

  hostport      = host [ ":" port ]
  host          = hostname | IPv4address
  hostname      = *( domainlabel "." ) toplabel [ "." ]
  domainlabel   = alphanum | alphanum *( alphanum | "-" ) alphanum
  toplabel      = alpha | alpha *( alphanum | "-" ) alphanum
  IPv4address   = 1*digit "." 1*digit "." 1*digit "." 1*digit
  port          = *digit
********************************************************************************/
void URI::initializeAuthority(const zstring& uri)
{
  zstring::size_type lIndex = 0;
  zstring::size_type lStart = 0;
  zstring::size_type lEnd = uri.size();

  zstring lUserInfo;
  bool lUserInfoFound;


  lIndex = uri.find("@");

  if ( lIndex != zstring::npos ) 
  {
    lUserInfo = uri.substr(0, lIndex);
    ++lIndex;
    lStart += lIndex;
    lUserInfoFound = true;
  }
  else
  {
    lUserInfoFound = false;
  }

  //
  // hostport = host [ ":" port ]
  // host is everything up to ':', or up to 
  // and including ']' if followed by ':'.
  //
  zstring lHost;
  zstring_b lTmp; // used for substrings starting at lStart

  lTmp.wrap_memory(uri.c_str() + lStart, lEnd - lStart);

  if ( lStart < lEnd && uri[lStart] == '[' ) 
  {
     lIndex = lTmp.find("]");

    if ( lIndex != zstring::npos ) 
    { 
      lIndex = ((lStart + lIndex + 1)  < lEnd && uri[lStart + lIndex + 1] == ':' ?
                lIndex + 1 : zstring::npos);
    }
  }
  else
  {
    lIndex = lTmp.find(":");
  }

  if ( lIndex != zstring::npos ) 
  {
    lHost = lTmp.substr(0, lIndex);

    ++lIndex; // skip the colon
    lStart += lIndex;
  }
  else
  {
    lHost = lTmp.substr(0, lEnd - lStart);
    lStart = lEnd;
  }

  lTmp.wrap_memory(uri.c_str() + lStart, lEnd - lStart);
  int lPort = -1;

  if ( ( ! lHost.empty() ) && ( lIndex != zstring::npos ) && ( lStart < lEnd ) ) 
  {
    zstring lPortString = lTmp.substr(0, lEnd - lStart);

    if ( !lPortString.empty() )
    {
      lPort = atoi(lPortString.c_str());
    }
  }
  else if ( lStart >= lEnd && lIndex != zstring::npos ) 
  {
    lPort = -2;
  }

  if (is_valid_server_based_authority(lHost,
                                      lPort,
                                      lUserInfo,
                                      lUserInfoFound)) 
  {
    theHost = lHost;
    set_state(Host);

    if (lPort != -1)
    {
      thePort = lPort;
      set_state(Port);
    }

    if (lUserInfoFound)
    {
      set_user_info(lUserInfo);
    }

    return;
  }
  set_reg_based_authority(uri);
}


/*******************************************************************************

********************************************************************************/
bool URI::is_valid_server_based_authority(
    const zstring& host,
    const int port,
    const zstring& user_info,
    bool user_info_found)
{
  if ( !is_well_formed_address(host.c_str(), (ulong)host.size()) )  
  {
    return false;
  }

  if ( (port > 65535) || ( port < 0 && port != -1) ) 
  {
    return false;
  }

  // TODO check user_info
  
  return true;
}



/*******************************************************************************
  hier_part     = ( net_path | abs_path ) [ "?" query ]
  opaque_part   = uric_no_slash *uric

  uric_no_slash = unreserved | escaped | ";" | "?" | ":" | "@" |
                  "&" | "=" | "+" | "$" | ","

  net_path      = "//" authority [ abs_path ]
  abs_path      = "/"  path_segments
  rel_path      = rel_segment [ abs_path ]

  rel_segment   = 1*( unreserved | escaped |
                  ";" | "@" | "&" | "=" | "+" | "$" | "," )

  path          = [ abs_path | opaque_part ]
  path_segments = segment *( "/" segment )
  segment       = *pchar *( ";" param )
  param         = *pchar
  pchar         = unreserved | escaped |
                  ":" | "@" | "&" | "=" | "+" | "$" | ","
********************************************************************************/
void URI::initializePath(const zstring& uri)
{
  checked_vector<uint32_t> lCodepoints;
  utf8::to_codepoints(uri, &lCodepoints);

  ulong lIndex = 0;
  ulong lStart = 0;
  ulong lEnd = (ulong)lCodepoints.size();
  uint32_t lCp = 0;

  if (uri.empty())
  {
    thePath = uri;
    set_state(Path);
    return;
  }

  // path - everything up to query string or fragment
  if ( lStart < lEnd )
  {
    // RFC 2732 only allows '[' and ']' to appear in the opaque part.
    if ( ! is_set(Scheme) || lCodepoints[lStart] == '/')
    {
      // Scan path.
      // abs_path = "/"  path_segments
      // rel_path = rel_segment [ abs_path ]
      while ( lIndex < lEnd )
      {
        lCp = lCodepoints[lIndex];
        if ( lCp == '?' || lCp == '#' )
          break;

        if ( lCp == '%' )
        {
          if ( lIndex + 2 >= lEnd )
          {
            throw XQUERY_EXCEPTION(
              err::XQST0046, ERROR_PARAMS( uri, ZED( BadHexSequence ) )
            );
          }
          unicode::code_point lHex1 = lCodepoints[++lIndex];
          if(!ascii::is_xdigit(lHex1))
            throw XQUERY_EXCEPTION(
              err::XQST0046, ERROR_PARAMS( uri, ZED( BadHexDigit_3 ), lHex1 )
            );
          unicode::code_point lHex2 = lCodepoints[++lIndex];
          if(!ascii::is_xdigit(lHex2))
            throw XQUERY_EXCEPTION(
              err::XQST0046, ERROR_PARAMS( uri, ZED( BadHexDigit_3 ), lHex2 )
            );
        }
        else if (!is_unreserved_char(lCp) && !is_path_character(lCp) && valid)
        {
          throw XQUERY_EXCEPTION(
            err::XQST0046, ERROR_PARAMS( uri, ZED( BadUnicodeChar_3 ), lCp )
          );
        }
        ++lIndex;
      }
    #ifdef WIN32
      if (ZSTREQ(theScheme, "file") &&
          (lCodepoints[lStart] == '/') &&
          (lEnd > (lStart+2)) &&
          ((lCodepoints[lStart+2] == ':') || !uri.compare(lStart+2, 4, "%3A/")))//jump over first '/' of path
        lStart++;
    #endif
    }
    else
    {
      while ( lIndex < lEnd )
      {
        lCp = lCodepoints[lIndex];
        if ( lCp == '?' || lCp == '#' )
          break;

        if ( lCp == '%' )
        {
          // TODO check errors
        }
        else if (!is_reservered_or_unreserved_char(lCp) && valid)
        {
          throw XQUERY_EXCEPTION(
            err::XQST0046, ERROR_PARAMS( uri, ZED( BadUnicodeChar_3 ), lCp )
          );
        }
        ++lIndex;
      }
    }

  } // lStart < lEnd


  thePath.clear();
  utf8::append_codepoints(lCodepoints.begin() + lStart,
                          lCodepoints.begin() + lIndex,
                          &thePath);

  set_state(Path);

  // query - starts with ? and up to fragment or end
  if ( lCp == '?' )
  {
    ++lIndex;
    lStart = lIndex;
    while ( lIndex < lEnd )
    {
      lCp = lCodepoints[lIndex];
      if ( lCp == '#' )
        break;

      // TODO check conformance
      ++lIndex;
    } /* lIndex < lEnd */

    theQueryString.clear();
    utf8::append_codepoints(lCodepoints.begin() + lStart,
                            lCodepoints.begin() + lIndex,
                            &theQueryString);

    set_state(QueryString);
  }

  // fragment - starts with #
  if ( lCp == '#' )
  {
    ++lIndex;
    lStart = lIndex;
    while ( lIndex < lEnd )
    {
      lCp = lCodepoints[lIndex];
      // TODO check conformance

      ++lIndex;
    } /* lIndex < lEnd */

    if ( lIndex > lStart)
    {
      theFragment.clear();
      utf8::append_codepoints(lCodepoints.begin() + lStart,
                              lCodepoints.begin() + lIndex,
                              &theFragment);
      set_state(Fragment);
    }
    else
    {
      // fragment is not set
    }
  }

}


/*******************************************************************************

********************************************************************************/
void URI::set_scheme(const zstring& new_scheme)
{
  if ( new_scheme.empty() ) 
  {
    throw XQUERY_EXCEPTION(
      err::XQST0046, ERROR_PARAMS( "", ZED( NoURIScheme ) )
    );
  }

  if ( ! is_conformant_scheme_name(new_scheme) ) 
  {
    throw XQUERY_EXCEPTION(
      err::XQST0046, ERROR_PARAMS( "", ZED( BadURIScheme_3 ), new_scheme )
    );
  }

  theScheme = new_scheme;
  set_state(Scheme);
}


/*******************************************************************************

********************************************************************************/
void URI::set_host(const zstring& new_host)
{
  theHost = new_host;
  set_state(Host);
}


/*******************************************************************************

********************************************************************************/
void URI::set_port(int new_port)
{
  thePort = new_port;
  set_state(Port);
}


/*******************************************************************************

********************************************************************************/
void URI::set_user_info(const zstring& new_user_info)
{
  uri::encode(new_user_info, &theUserInfo, false);

  set_state(UserInfo);
}


/*******************************************************************************

********************************************************************************/
void URI::set_reg_based_authority(const zstring& new_authority)
{
  if ( new_authority.empty() ) 
  {
    return;
  } 

  // TODO check valid registry based authority

  theRegBasedAuthority = new_authority;
  set_state(RegBasedAuthority);

  unset_state(Host);
}


/*******************************************************************************

********************************************************************************/
void URI::set_path(const zstring& new_path)
{
  if (new_path.empty()) 
  {
    thePath = new_path;
    unset_state(Path);
    theQueryString = new_path;
    unset_state(QueryString);
    theFragment = new_path;
    unset_state(Fragment);
  }
  else
  {
    initializePath(new_path);
  }
}


/*******************************************************************************

********************************************************************************/
void URI::get_user_info(zstring& result) const
{
  uri::decode(theUserInfo, &result);
}


/*******************************************************************************

********************************************************************************/
void URI::get_reg_based_authority(zstring& result) const
{
  uri::decode(theRegBasedAuthority, &result);
}


/*******************************************************************************

********************************************************************************/
void URI::get_path(zstring& result) const
{
  uri::decode(thePath, &result);
}


/*******************************************************************************

********************************************************************************/
void URI::get_query(zstring& result) const
{
  uri::decode(theQueryString, &result);
}


/*******************************************************************************

********************************************************************************/
void URI::get_fragment(zstring& result) const
{
  uri::decode(theFragment, &result);
}


/*******************************************************************************

********************************************************************************/
bool URI::is_absolute() const
{
  return is_set(Scheme) && !theScheme.empty();
}

bool URI::is_absolute_path(zstring &thePath)
{
#ifndef WIN32
  return thePath[0] == '/';
#else
  return (thePath.length() > 2) && 
          ((thePath[1] == ':') || 
           ((thePath[1] == '%') && (thePath[2] == '3') && (thePath[3] == 'A')));
#endif
}

/*******************************************************************************

********************************************************************************/
void URI::resolve(const URI* base_uri)
{
  if (is_absolute()) 
  {
    return;
  }

  if ( base_uri == 0 && toString().empty() ) 
  {
    throw XQUERY_EXCEPTION(
      err::XQST0046, ERROR_PARAMS( "", ZED( ZeroLenURI ) )
    );
  }

  if ( toString().empty() ) 
  {
    // just copy the base uri 
    initialize(*base_uri);
  }

  zstring::size_type lIndex = 0;

  // If the path component is empty and the scheme, authority, and
  // query components are undefined, then it is a reference to the
  // current document and we are done.  Otherwise, the reference URI's
  // query and fragment components are defined as found (or not found)
  // within the URI reference and not inherited from the base URI.
  if ( ((!is_set(Path)) || (thePath.empty())) &&
       (!is_set(Scheme) && (!is_set(Host)) && (!is_set(RegBasedAuthority)) )) 
  {
    set_scheme(base_uri->get_scheme());

    if (base_uri->is_set(UserInfo)) 
    {
      zstring userInfo;
      base_uri->get_user_info(userInfo);
      set_user_info(userInfo);
    }

    if (base_uri->is_set(Host)) 
    {
      set_host(base_uri->get_host());
    }

    if (base_uri->is_set(Port)) 
    {
      set_port(base_uri->get_port());
    }

    if (base_uri->is_set(RegBasedAuthority)) 
    {
      zstring auth;
      base_uri->get_reg_based_authority(auth);
      set_reg_based_authority(auth);
    }

    if (base_uri->is_set(Path)) 
    {
      // I think this is a bug in xerces because it doesn't remove the last segment
      zstring path;
      base_uri->get_path(path);

      zstring::size_type last_slash = path.rfind("/");
      if ( last_slash != zstring::npos )
        thePath = path.substr(0, last_slash+1);
      else 
        thePath = path;

      set_state(Path);
    }

    if ( (! is_set(QueryString)) ) 
    {
        base_uri->get_query(theQueryString);

        set_state(QueryString);
    }

    invalidate_text();

    return;
  }

  // If the scheme component is defined, indicating that the reference
  // starts with a scheme name, then the reference is interpreted as an
  // absolute URI and we are done.  Otherwise, the reference URI's
  // scheme is inherited from the base URI's scheme component.
  if ( is_set(Scheme) ) 
  {
    invalidate_text();
    return;
  }

  set_scheme(base_uri->get_scheme());

  // If the authority component is defined, then the reference is a
  // network-path and we skip to step 7.  Otherwise, the reference
  // URI's authority is inherited from the base URI's authority
  // component, which will also be undefined if the URI scheme does not
  // use an authority component.
  if ( (!is_set(Host)) && (!is_set(RegBasedAuthority)) ) 
  {
    if (base_uri->is_set(UserInfo)) 
    {
      base_uri->get_user_info(theUserInfo); 
      set_state(UserInfo);
    }

    if (base_uri->is_set(Host)) 
    {
      theHost = base_uri->get_host();
      set_state(Host);
    }

    if (base_uri->is_set(Port)) 
    {
      thePort = base_uri->get_port();
      set_state(Port);
    }

    if (base_uri->is_set(RegBasedAuthority)) 
    {
      base_uri->get_reg_based_authority(theRegBasedAuthority);
      set_state(RegBasedAuthority);
    }
  }
  else
  {
    invalidate_text();
    return;
  }


  // If the path component begins with a slash character ("/"), then
  // the reference is an absolute-path and we skip to step 7.
  if ( is_set(Path) && is_absolute_path(thePath) ) 
  {
     invalidate_text();
     return;
  }

  zstring base_path = base_uri->get_encoded_path();
  zstring path;

  if ( base_uri->is_set(Path) ) 
  {
    if(!is_absolute_path(thePath))
    {
      zstring::size_type last_slash = base_path.rfind("/");
      if ( last_slash != zstring::npos )
        path = base_path.substr(0, last_slash+1);
  //  else
  //    path = "/";
    }
  }

  // 6b - append the relative URI path
  path.append(thePath);

  // 6c - remove all "./" where "." is a complete path segment
  ascii::replace_all(path, "/./", 3, "/", 1);

  // 6d If the buffer string ends with "." as a complete path segment,
  //  that "." is removed.
  if (ascii::ends_with(path, "/.", 2)) 
  {
    path = path.substr(0, path.size() - 1);
  }

  // 6e All occurrences of "<segment>/../", where <segment> is a
  // complete path segment not equal to "..", are removed from the
  // buffer string.  Removal of these path segments is performed
  // iteratively, removing the leftmost matching pattern on each
  // iteration, until no matching pattern remains.
  zstring::size_type segIndex;
  zstring::size_type offset = 1;

  zstring_b tmp_path;
  tmp_path.wrap_memory(const_cast<char*>(path.c_str() + 1), path.size() - 1);
  zstring_b tmp1;
  zstring_b tmp2;

  while ((lIndex = tmp_path.find("/../")) != zstring::npos) 
  {
    // Undo offset
    lIndex += offset;
    
    // Find start of <segment> within substring ending at found point.
    tmp1.wrap_memory(path.c_str(), lIndex - 1);

    segIndex = tmp1.rfind("/");

    // Ensure <segment> exists and != ".."
    if (segIndex != zstring::npos &&
        (path[segIndex+1] != '.' ||
         path[segIndex+2] != '.' ||
         segIndex + 3 != lIndex)) 
    { 
      tmp1.wrap_memory(path.c_str(), segIndex);
      tmp2.wrap_memory(path.c_str() + lIndex + 3, path.size() - lIndex - 3);

      zstring tmp;
      tmp.reserve(tmp1.size() + tmp2.size());
      tmp += tmp1;
      tmp += tmp2;
      path.swap(tmp);

      offset = (segIndex == 0 ? 1 : segIndex);
    }
    else
    {
      offset += 4;
    }

    tmp_path.wrap_memory(path.c_str() + offset, path.size() - offset);
  } // while

  // 6f) If the buffer string ends with "<segment>/..", where <segment>
  // is a complete path segment not equal to "..", that
  // "<segment>/.." is removed.
  if (ascii::ends_with(path, "/..", 3))
  {
    // Find start of <segment> within substring ending at found point.
    lIndex = path.size() - 3;
    tmp1.wrap_memory(path.c_str(), lIndex - 1);
    segIndex = tmp1.rfind("/");

    if (segIndex != zstring::npos &&
        (path[segIndex+1] != '.' ||
         path[segIndex+2] != '.' ||
         segIndex + 3 != lIndex))
    {
      path = path.substr(0, segIndex+1);
    }
  }
  
  thePath = path;
  invalidate_text();
}


/*******************************************************************************

********************************************************************************/
void URI::relativize(const URI* base_uri)
{
  if ( base_uri == 0 || base_uri->toString().size() == 0)
    return;

  // if the scheme of the base_uri and the current uri are not identical,
  // we return the current uri
  if ( base_uri->get_scheme().compare(get_scheme()) != 0 ) 
  {
    return;
  }

  // if the authority of the base_uri and the current uri are not identical,
  // we return the current uri
  zstring auth;
  zstring base_auth;
  get_reg_based_authority(auth);
  base_uri->get_reg_based_authority(base_auth);

  if ( base_auth != auth ) 
  {
    return;
  }

  // if the path of the current uri is not a substring of the path of the base_uri,
  // we return the current uri
  zstring path;
  zstring base_path;
  get_path(path);
  base_uri->get_path(base_path);

  if ( path.find(base_path) != 0 ) 
  {
    return;
  }

  // construct a new relative hierarchical URI is constructed with query and
  // fragment components taken from the given URI and with a path component
  // computed by removing this URI's 
  // path from the beginning of the given URI's path.
  zstring lNewPath = path.substr(base_path.size());
  set_path(lNewPath);
  // unset remaining stuff
  theScheme.clear();
  unset_state(Scheme);
  theRegBasedAuthority.clear();
  unset_state(RegBasedAuthority);
  theUserInfo.clear();
  unset_state(UserInfo);
  thePort = 0;
  unset_state(Port);
  theHost.clear();
  unset_state(Host);
}


/*******************************************************************************

********************************************************************************/
bool URI::is_conformant_scheme_name(const zstring& scheme)
{
#if 0
  // start with a-zA-Z
  if ( ! zorba::matches(scheme, "[a-zA-Z]", "" ) )
    return false;
#endif

  for (ulong i = 0; i < scheme.size(); ++i) 
  {
    char c = scheme[i];

    if ( ! ascii::is_alpha(c) && c != '+' && c != '-' && c != '.')
    {
      return false; 
    }
  }
  return true;
}


/*******************************************************************************

********************************************************************************/
const zstring& URI::toString() const
{
  if (theURIText.empty()) 
  {
    build_full_text();
  }
  return theURIText;
}


/*******************************************************************************

********************************************************************************/
const zstring& URI::toPathNotation() const
{
  if (thePathNotation.empty()) 
  {
    build_path_notation();
  }
  return thePathNotation;
}


/*******************************************************************************

********************************************************************************/
const zstring& URI::toASCIIString() const
{
  if (theASCIIURIText.empty()) 
  {
    build_ascii_full_text();
  }
  return theASCIIURIText;
}


/*******************************************************************************

********************************************************************************/
void URI::build_path_notation() const
{
  std::ostringstream lPathNotation;

  std::string lToTokenize;
  if (is_set(Host)) 
  {
    lToTokenize = theHost.str();
  }
  else
  {
    lToTokenize = theRegBasedAuthority.str();
  }

  std::string::size_type lastPos = 
      lToTokenize.find_last_not_of(".", lToTokenize.length());

  std::string::size_type pos = lToTokenize.find_last_of(".", lastPos);

  if (pos == std::string::npos) 
  {
    lPathNotation << lToTokenize;
  }

  while (std::string::npos != pos) 
  {
    lPathNotation << lToTokenize.substr(pos + 1, lastPos - pos) << "/";

    lastPos = pos - 1;
    pos = lToTokenize.find_last_of(".", lastPos);
    if (pos == std::string::npos) 
    {
      lPathNotation << lToTokenize.substr(0, lastPos+1);
    }
  }

  if (is_set(Path)) 
  {
    if(!thePath.empty() && (thePath[0] != '/') && (thePath[0] != '\\'))
      lPathNotation << "/";
    lPathNotation << thePath;
  } 

  thePathNotation = lPathNotation.str();
}


/*******************************************************************************

********************************************************************************/
void URI::build_full_text() const
{
  std::ostringstream lURI;
  
  // Scheme
  if ( is_set(Scheme) )
    lURI << theScheme << ":";

  // Authority
  if ( is_set(Host) || is_set(RegBasedAuthority) ) 
  {
    lURI << "//";
    if ( is_set(Host) ) 
    {
      if ( is_set(UserInfo) )
        lURI << theUserInfo << "@";

      lURI << theHost;

      if ( is_set(Port) )
        lURI << ":" << thePort;
    }
    else
    {
      lURI << theRegBasedAuthority;
    }
  }

  if ( is_set(Path) )
  {
  #ifdef WIN32
    if(ZSTREQ(theScheme, "file") && !thePath.empty() && (thePath[0] != '/'))
        lURI << "/";
  #endif
    lURI << thePath;
  }

  if ( is_set(QueryString) )
    lURI << "?" << theQueryString;

  if ( is_set(Fragment) )
    lURI << "#" << theFragment;

  theURIText = lURI.str();
}


/*******************************************************************************

********************************************************************************/
void URI::build_ascii_full_text() const
{
  std::ostringstream lURI;
  
  // Scheme
  if ( is_set(Scheme) )
    lURI << theScheme << ":";

  // Authority
  if ( is_set(Host) || is_set(RegBasedAuthority) ) 
  {
    lURI << "//";
    
    if ( is_set(Host) ) 
    {
      if ( is_set(UserInfo) )
        lURI << theUserInfo << "@";

      lURI << theHost;

      if ( is_set(Port) )
        lURI << ":" << thePort;
    }
    else 
    {
      lURI << theRegBasedAuthority;
    }
  }

  if ( is_set(Path) )
  {
  #ifdef WIN32
    if(ZSTREQ(theScheme, "file") && !thePath.empty() && (thePath[0] != '/'))
        lURI << "/";
  #endif
    lURI << thePath;
  }

  if ( is_set(QueryString) )
    lURI << "?" << theQueryString;

  if ( is_set(Fragment) )
    lURI << "#" << theFragment;

  theASCIIURIText = lURI.str();
}

};
/* vim:set et sw=2 ts=2: */
