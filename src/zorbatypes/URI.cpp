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
#include <zorba/util/path.h>

#include "URI.h"

using namespace std;

namespace zorba {


/*******************************************************************************
  is the given char a hex allowed one
********************************************************************************/
bool URI::is_hex(uint32_t c)
{
  return (is_digit(c) || (c >= 'a'&& c <= 'f') || (c >= 'A'&& c <= 'F'));
}


/*******************************************************************************

********************************************************************************/
bool URI::is_alpha(uint32_t c)
{
  if ((( c >= 'a' ) && ( c <= 'z' )) || (( c >= 'A' ) && ( c <= 'Z' )) )
    return true;

  return false;
}


/*******************************************************************************

********************************************************************************/
bool URI::is_digit(uint32_t c)
{
  if (( c >= '0' ) && ( c <= '9' ))
    return true;
 
  return false;
}


/*******************************************************************************

********************************************************************************/
bool URI::is_alphanum(uint32_t c)
{
  return (is_alpha(c) || is_digit(c));
}


/*******************************************************************************

********************************************************************************/
bool URI::is_unreserved_char(uint32_t c)
{
  std::string lMarkCharacter("-_.!~*'{}");
  return (is_alphanum(c) || (c == ' ') || (c > 127 ) ||
    ((c<128) && lMarkCharacter.find((char)c) != std::string::npos));
}


/*******************************************************************************

********************************************************************************/
bool URI::is_path_character(uint32_t c)
{
  std::string lPathChracters(";/:@&=+$,");
  return ((c<128) && lPathChracters.find((char)c) != std::string::npos);
}


/*******************************************************************************

********************************************************************************/
bool URI::is_reservered_or_unreserved_char(uint32_t c)
{
  std::string lMarkOrReservedChars("-_.!~*'();/?:@&=+$,[]");
  return (is_alphanum(c) ||
          (c == ' ') ||
          ((c<128) && lMarkOrReservedChars.find((char)c) != std::string::npos));
}


/*******************************************************************************
  Note: The encode_file_URI and decode_file_URI methods are hacks. Doing it
  properly would require boost-filesystem (or equivalent code).

  The decode_file_URI() method takes a file URI and converts it to a filepath
  in the native OS foramt.
********************************************************************************/
void URI::decode_file_URI(
    const xqpStringStore_t& uri,
    xqpStringStore_t& filepath)
{
  // TODO: file://localhost/
#ifdef WIN32
  if ((uri->byteCompare(0, 8, "file:///") == 0) && 
      ((uri->byteCompare(9, 1, ":") == 0) || (uri->byteCompare(9, 4, "%3A/") == 0))) 
  {
    xqpStringStore_t tmp = new xqpStringStore(uri->c_str() + 8);
    tmp->decodeFromUri(filepath);
  }
  else
#endif
    if (uri->byteCompare(0, 8, "file:///") == 0) 
    {
      xqpStringStore_t tmp = new xqpStringStore(uri->c_str() + 7);
      tmp->decodeFromUri(filepath);
    }
    else if (uri->byteCompare(0, 17, "file://localhost/") == 0)
    {
      xqpStringStore_t tmp = new xqpStringStore(uri->c_str() + 16);
      tmp->decodeFromUri(filepath);
    }
    else
    {
      // should we raise an unknown host exception?
      filepath = uri;
    }
}


/*******************************************************************************
  The encode_file_URI() method takes a filepath and converts it to a file URI.

  Assumes input is absolute path.
********************************************************************************/
void URI::encode_file_URI(
    const xqpStringStore_t& filepath,
    xqpStringStore_t& uri)
{
  if (filepath->bytePositionOf("://") != -1)
  {
    uri = filepath;
    return;
  }

#ifdef WIN32
  uri = new xqpStringStore("file:///");

  xqpStringStore_t tmp1;
  xqpStringStore_t pattern = new xqpStringStore("\\\\");
  xqpStringStore_t replacement = new xqpStringStore("/");
  filepath->replace(tmp1, pattern, replacement, "");

  xqpStringStore_t tmp2;
  tmp1->encodeForUri(tmp2, "/", 1);

  uri->append_in_place(tmp2);

#else
  uri = new xqpStringStore("file:///");

  xqpStringStore_t tmp;
  filepath->encodeForUri(tmp, "/", 1);

  uri->append_in_place(tmp);
#endif
}


/*******************************************************************************
  The encode_file_URI() method takes a filepath and converts it to a file URI.

  Assumes input is absolute path.
********************************************************************************/
std::string URI::encode_file_URI(const std::string& filepath)
{
  xqpStringStore_t filepath2 = new xqpStringStore(filepath);
  xqpStringStore_t uri;

  encode_file_URI(filepath2, uri);

  return uri->str();
}


/*******************************************************************************

********************************************************************************/
bool URI::is_well_formed_address(const xqpStringStore* addr)
{
  if (addr->empty()) 
  {
    return false;
  }

  const std::string& addrStr = addr->str();

  ulong addrLen = addr->bytes();

  if (addr->bytePositionOf("[") == 0) 
  {
    return is_well_formed_ipv6_reference(addr, addrLen);
  }

  char c = addrStr.at(0);

  if ( c == '.' || c == '-' || addrStr.at(addrLen-1) == '-') 
  {
    return false;
  }

  long lLastPeriodPos = addr->byteLastPositionOf(".", 1);

  if ( lLastPeriodPos >= 0 && (ulong)lLastPeriodPos + 1 == addrLen ) 
  {
    xqpStringStore_t lTmp = addr->byteSubstr(0, lLastPeriodPos);
    lLastPeriodPos = lTmp->byteLastPositionOf(".", 1);

    if ( is_digit(addrStr.at(lLastPeriodPos + 1)) )
    {
      return false;
    }
  }

  if ( lLastPeriodPos >= 0 && is_digit(addrStr.at(lLastPeriodPos + 1)) ) 
  {
    return is_well_formed_ipv4_address(addr, addrLen);
  }
  else 
  {
    if (addrLen > 255)
    {
      return false;
    }

    uint32_t lLabelCharCount = 0;

    for (ulong i = 0; i < addrLen; ++i) 
    {
      char c1 = addrStr.at(i);

      if ( c1 == '.' ) 
      {
        if ( ( i > 0  &&  ! is_alphanum(addrStr.at(i-1))) ||
             ( i + 1 < addrLen  && ! is_alphanum(addrStr.at(i+1))) ) 
        {
          return false;
        }
        
        lLabelCharCount = 0;
      }
      else if ( ! is_alphanum(c1) && c1 != '-' )
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
bool URI::is_well_formed_ipv4_address(const xqpStringStore* addr, ulong length)
{
  ulong numDots = 0;
  ulong numDigits = 0;

  const std::string& addrStr = addr->str();

  for (ulong i = 0; i < length; ++i)
  {
    char c = addrStr.at(i);

    if (c == '.') 
    {
      if ( (i == 0) || (i+1 == length) || ! is_digit(addrStr.at(i+1)) )
        return false;
    }
    else if ( ! is_digit(c) )
    {
      return false;
    }
    else if (++numDigits > 3)
    {
      return false;
    }
    else if (numDigits == 3)
    {
      char lFirst  = addrStr.at(i-2);
      char lSecond = addrStr.at(i-1);
      char lLast   = addrStr.at(i);

      if ( !(lFirst < '2' ||
             (lFirst == '2' && (lSecond < '5' || (lSecond == '5' && lLast <= '5'))))) 
        return false;
    }
  }

  return (numDots == 3);
}


/*******************************************************************************

********************************************************************************/
bool URI::is_well_formed_ipv6_reference(const xqpStringStore* addr, ulong length)
{
  long lIndex = 1;
  long lEnd = length-1;

  const std::string& addrStr = addr->str();

  // Check if string is a potential match for IPv6reference.
  if (!(length > 2 && addrStr.at(0) == '[' && addrStr.at(lEnd) == ']')) 
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
  
  if (lIndex+1 < lEnd && addrStr.at(lIndex) == ':') 
  {
    if (addrStr.at(lIndex+1) == ':') 
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
        xqpStringStore_t lTmp = addr->byteSubstr(lIndex+1, lEnd - lIndex -1);
        return is_well_formed_ipv4_address(lTmp.getp(), lEnd - lIndex - 1);
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
  xqpStringStore_t lTmp = addr->byteSubstr(shiftCount, lEnd - shiftCount);

  return is_well_formed_ipv4_address(lTmp.getp(), lEnd - shiftCount);
}


/*******************************************************************************
  For use with isWellFormedIPv6Reference only.
********************************************************************************/
long URI::scanHexSequence(
    const xqpStringStore* addr,
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
    c = addr->str().at(index);

    if ( c == ':' ) 
    {
      // IPv6 addresses are 128-bit, so there can be at most eight sections.
      if (lNumDigits > 0 && ++counter > 8) 
      {
        return -1;
      }

      // This could be '::'.
      if (lNumDigits == 0 || ((index+1 < end) && addr->str().at(index+1) == ':'))
      {
        return index;
      }

      lNumDigits = 0;
    }

    // This might be invalid or an IPv4address. If it's potentially an IPv4address,
    // backup to just after the last valid character that matches hexseq.
    else if (!is_hex(c)) 
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
  Helper: Check whether any of the chars in the second argument is contained in
  the string that is passed as first argument.
********************************************************************************/
long URI::find_any(const xqpStringStore* str, const std::string& patterns) 
{
  ulong lLength = str->bytes();

  for (ulong i = 0; i < lLength; ++i) 
  {
    char s = str->str().at(i);
 
    for (ulong j = 0; j < patterns.length(); ++j) 
    {
      char p = patterns.at(j); 
      if (s == p)
        return i;
    }
  }

  return -1; 
}


/*******************************************************************************
  construct a uri
********************************************************************************/
URI::URI(const xqpStringStore* uri, bool validate)
  : 
  theState(0),
  thePort(0),
  valid(validate)
{
  initialize(uri);
}


/*******************************************************************************
  construct a uri and eventually resolve with the given base uri
********************************************************************************/
URI::URI(const URI& base_uri, const xqpStringStore* uri, bool validate)
  :
  theState(0),
  thePort(0),
  valid(validate)
{
  initialize(uri, true);
  resolve(&base_uri);
}


/*******************************************************************************
  constructs a new uri by relativizing the full_uri agsinst the base_uri
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
  xqpStringStore_t empty = new xqpStringStore("");
  theURIText = empty;
  theASCIIURIText = empty;
  thePathNotation = empty;
  theScheme = empty;
  theHost = empty;
  theUserInfo = empty;
  theRegBasedAuthority = empty;
  thePath = empty;
  theQueryString = empty;
  theFragment = empty;
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
void URI::initialize(const xqpStringStore* uri, bool have_base)
{
  xqpStringStore_t empty = new xqpStringStore("");
  theURIText = empty;
  theASCIIURIText = empty;
  thePathNotation = empty;
  theScheme = empty;
  theHost = empty;
  theUserInfo = empty;
  theRegBasedAuthority = empty;
  thePath = empty;
  theQueryString = empty;
  theFragment = empty;

  // first, we need to normalize the spaces in the uri
  // and only work with the normalized version from this point on
  xqpStringStore_t lTrimmedURI = (uri->normalizeSpace())->trim();
  ulong lTrimmedURILength = lTrimmedURI->bytes();

  // index of the current processing state used in this function
  ulong lIndex = 0;

  long lColonIdx    = lTrimmedURI->bytePositionOf(":");
  long lSlashIdx    = lTrimmedURI->bytePositionOf("/");
  long lQueryIdx    = lTrimmedURI->bytePositionOf("?");
  long lFragmentIdx = lTrimmedURI->bytePositionOf("#");

#ifdef WIN32
  // on WIN32 we might have a drive specification ("C:")
  // and we don't want to consider this as scheme
  char lLetter = lTrimmedURI->c_str()[0];
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
  if ((lColonIdx <= 0) ||
#ifdef WIN32
      // avoid interpreting the drive as a scheme
      lIsDrive ||
#endif
      (lColonIdx > lSlashIdx && lSlashIdx != -1) ||
      (lColonIdx > lQueryIdx && lQueryIdx != -1) ||
      (lColonIdx > lFragmentIdx && lFragmentIdx != -1)) 
  {
    // A standalone base is a valid URI
    if (valid && 
        (lColonIdx == 0 || (!have_base && lFragmentIdx != 0)) &&
        lTrimmedURILength > 0) 
    {
      ZORBA_ERROR_DESC_OSS(XQST0046,
                           "URI \"" << lTrimmedURI << "\" doesn't have an URI scheme");
    }
  }
  else
  {
    initializeScheme(lTrimmedURI);

    lIndex = theScheme->bytes() + 1;
  }

  /**
   * Authority
   * two slashes means generic URI syntax, so we get the authority
   */
  xqpStringStore_t lAuthUri = lTrimmedURI->byteSubstr(lIndex, lTrimmedURILength - lIndex);

  if (lAuthUri->byteSubstr(0, 2)->byteEqual("//", 2)) 
  {
    lIndex += 2;
    if (lIndex >= lTrimmedURILength) 
    {
      ZORBA_ERROR_DESC_OSS(XQST0046,
                           "Authority is misssing in URI \"" << lTrimmedURI << "\" .");
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
        c = lTrimmedURI->str().at(lIndex);

        if (c == '/' || c == '?' || c == '#')
          break;

        ++lIndex;
      }

      // if we found authority, parse it out, otherwise we set the
      // host to empty string
      if (lIndex > lStartPos) 
      {
        lAuthUri = lTrimmedURI->byteSubstr(lStartPos, lIndex - lStartPos);

        // For "file" scheme only allow "localhost" as authority.
        // This makes this implementation the same with the file module.
        // If this functionality is changed, please make the same changes
        // in the file module.
        if (theScheme->byteEqual("file", 4) &&
            !lAuthUri->byteEqual("localhost", 9)) 
        {
          ZORBA_ERROR_DESC_OSS(XQST0046,
                               "Invalid authority value for the \"file\" scheme: \""
                               << lAuthUri->c_str()
                               << "\". The only accepted values are empty string"
                               << " (file:///) and \"localhost\" (file://localhost/).");
        }

        initializeAuthority(lAuthUri);
      }
      else 
      {
        xqpStringStore_t empty = new xqpStringStore("");
        set_host(empty);
      }
    }
    // do not allow constructs like: file:D:/myFile or http:myFile
  }
  else if (theScheme->byteEqual("file", 4) ||
           theScheme->byteEqual("http", 4) ||
           theScheme->byteEqual("https", 5)) 
  {
    if (valid)
    {
       ZORBA_ERROR_DESC_OSS(XQST0046, "Invalid URI syntax for the \""
                            << theScheme << "\" scheme.");
     }
  }

  // stop, if we're done here
  if (lIndex > lTrimmedURILength)
    return;

  /**
   * Path
   */
  xqpStringStore_t lPathUri = lTrimmedURI->byteSubstr(lIndex, lTrimmedURILength - lIndex);

  initializePath(lPathUri);
}


/*******************************************************************************
   scheme = alpha *( alpha | digit | "+" | "-" | "." )
********************************************************************************/
void URI::initializeScheme(const xqpStringStore* uri)
{
  long lSchemeSeparatorIdx = find_any(uri, ":/?#");
  
  if ( valid && lSchemeSeparatorIdx == -1 ) 
  {
    ZORBA_ERROR_DESC_OSS(XQST0046, "URI \"" << uri << "\" doesn't have an URI scheme");
  }
  else
  {
    set_scheme(uri->byteSubstr(0, lSchemeSeparatorIdx).getp());
  }
}


/*******************************************************************************

********************************************************************************/
void URI::initializeAuthority(const xqpStringStore* uri)
{
  long lIndex = 0;
  ulong lStart = 0;
  ulong lEnd = uri->bytes();

  xqpStringStore_t lUserInfo;
  bool lUserInfoFound;


  lIndex = uri->bytePositionOf("@");

  if ( lIndex != -1 ) 
  {
    lUserInfo = uri->byteSubstr(0, lIndex);
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
  xqpStringStore_t lHost;
  xqpStringStore_t lTmp; // used for substrings starting at lStart
  if ( lStart < lEnd && uri->str().at(lStart) == '[' ) 
  {
    lTmp = uri->byteSubstr(lStart, lEnd - lStart);
    lIndex = lTmp->bytePositionOf("]");
    if ( lIndex != -1 ) 
    { 
      lIndex = ( ((lStart + lIndex + 1 ) < lEnd) &&
                 (uri->str().at(lStart + lIndex + 1)) == ':') ? lIndex + 1 : -1;
    }
  }
  else
  {
    lTmp = uri->byteSubstr(lStart, lEnd - lStart);
    lIndex = lTmp->bytePositionOf(":");
  }

  if ( lIndex != -1 ) 
  {
    lHost = lTmp->byteSubstr(0, lIndex);
    ++lIndex; // skip the colon
    lStart += lIndex;
    //if(lStart >= lEnd)
    //{
    //  //port number is missing after ':'
    //  ZORBA_ERROR_DESC_OSS(XQST0046, "Port number is missing after ':'.");
    //}
  }
  else
  {
    lHost = lTmp->byteSubstr(0, lEnd - lStart);
    lStart = lEnd;
  }

  lTmp = uri->byteSubstr(lStart, lEnd - lStart);
  int lPort = -1;

  if ( ( ! lHost->empty() ) && ( lIndex != -1 ) && ( lStart < lEnd ) ) 
  {
    xqpStringStore_t lPortString = lTmp->byteSubstr(0, lEnd - lStart);

    if ( !lPortString->empty() )
    {
      lPort = atoi(lPortString->c_str());
    }
  }
  else if ( lStart >= lEnd && lIndex != -1 ) 
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
    if (lUserInfoFound) {
      set_user_info(lUserInfo);
    }

    return;
  }
  set_reg_based_authority(uri);
}


/*******************************************************************************

********************************************************************************/
bool URI::is_valid_server_based_authority(
    const xqpStringStore* host,
    const int port,
    const xqpStringStore* user_info,
    bool user_info_found)
{
  if ( !is_well_formed_address(host) )  
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

********************************************************************************/
void URI::initializePath(const xqpStringStore* uri)
{
  checked_vector<uint32_t> lCodepoints = uri->getCodepoints();

  ulong lIndex = 0;
  ulong lStart = 0;
  ulong lEnd = lCodepoints.size();
  uint32_t lCp = 0;

  if(uri->empty())
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
            // TODO check hex and throw errors
          }
        }
        else if (!is_unreserved_char(lCp) && !is_path_character(lCp) && valid)
        {
         ZORBA_ERROR_DESC_OSS(XQST0046, "Invalid char with codepoint '" << lCp << "' in URI path " << uri->str());
        }
        ++lIndex;
      }
    #ifdef WIN32
      if (theScheme->byteEqual("file", 4) && (lCodepoints[lStart] == '/'))//jump over first '/' of path
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
         ZORBA_ERROR_DESC_OSS(XQST0046, "Invalid char with codepoint '" << lCp << "' in URI path " << uri->str());
        }
        ++lIndex;
      }
    }

  } // lStart < lEnd

  thePath = new xqpStringStore(lCodepoints, lStart, lIndex - lStart);

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


    theQueryString = new xqpStringStore(lCodepoints, lStart, lIndex - lStart);

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
      theFragment = new xqpStringStore(lCodepoints, lStart, lIndex - lStart);

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
bool URI::is_absolute() const
{
  return is_set(Scheme) && !theScheme->empty();
}



/*******************************************************************************

********************************************************************************/
void URI::resolve(const URI* base_uri)
{
  if (is_absolute()) 
  {
    return;
  }

  if ( base_uri == 0 && toString()->empty() ) 
  {
    ZORBA_ERROR_DESC_OSS(XQST0046, "No base URI given and URILiteral is of zero length");
  }

  if ( toString()->empty() ) 
  {
    // just copy the base uri 
    initialize(*base_uri);
  }

  long lIndex = 0;

  // If the path component is empty and the scheme, authority, and
  // query components are undefined, then it is a reference to the
  // current document and we are done.  Otherwise, the reference URI's
  // query and fragment components are defined as found (or not found)
  // within the URI reference and not inherited from the base URI.
  if ( ((!is_set(Path)) || (thePath->empty())) &&
       (!is_set(Scheme) && (!is_set(Host)) && (!is_set(RegBasedAuthority)) )) 
  {
    set_scheme(base_uri->get_scheme());

    if (base_uri->is_set(UserInfo)) 
    {
      xqpStringStore_t userInfo;
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
      xqpStringStore_t auth;
      base_uri->get_reg_based_authority(auth);
      set_reg_based_authority(auth);
    }

    if (base_uri->is_set(Path)) 
    {
      // I think this is a bug in xerces because it doesn't remove the last segment
      xqpStringStore_t path;
      base_uri->get_path(path);
      long last_slash = path->byteLastPositionOf("/", 1);
      if ( last_slash != -1 )
        thePath = path->byteSubstr(0, last_slash+1);
      else 
        thePath = path;

      set_state(Path);
    }

    if ( (! is_set(QueryString)) ) 
    {
        base_uri->get_query(theQueryString);

        set_state(QueryString);
    }

    theURIText = new xqpStringStore(""); // force rebuild in get_uri_text

    return;
  }

  // If the scheme component is defined, indicating that the reference
  // starts with a scheme name, then the reference is interpreted as an
  // absolute URI and we are done.  Otherwise, the reference URI's
  // scheme is inherited from the base URI's scheme component.
  if ( is_set(Scheme) ) 
  {
    theURIText = new xqpStringStore(""); // force rebuild in get_uri_text
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
    theURIText = new xqpStringStore(""); // force rebuild in toString
    theASCIIURIText = new xqpStringStore("");
    return;
  }


  // If the path component begins with a slash character ("/"), then
  // the reference is an absolute-path and we skip to step 7.
  if ( (is_set(Path)) && (thePath->bytePositionOf("/") == 0) ) 
  {
    theURIText = new xqpStringStore(""); // force rebuild in get_uri_text
    theASCIIURIText = new xqpStringStore("");
    return;
  }

  xqpStringStore_t base_path = base_uri->get_encoded_path();
  xqpStringStore_t path;

  if ( base_uri->is_set(Path) ) 
  {
    long last_slash = base_path->byteLastPositionOf("/", 1);
    if ( last_slash != -1 )
      path = base_path->byteSubstr(0, last_slash+1);
//  else
//    path = "/";

  }

  // 6b - append the relative URI path
  if(path != NULL)
    path->append_in_place(thePath);
  else
    path = thePath;

  // 6c - remove all "./" where "." is a complete path segment
  xqpStringStore_t pattern = new xqpStringStore("/\\./");
  xqpStringStore_t replacement = new xqpStringStore("/");
  path->replace(path, pattern, replacement, "");

  // 6d If the buffer string ends with "." as a complete path segment,
  //  that "." is removed.
  if (path->byteEndsWith("/.", 2)) 
  {
    path = path->byteSubstr(0, path->bytes() - 1);
  }

  // 6e All occurrences of "<segment>/../", where <segment> is a
  // complete path segment not equal to "..", are removed from the
  // buffer string.  Removal of these path segments is performed
  // iteratively, removing the leftmost matching pattern on each
  // iteration, until no matching pattern remains.
  lIndex = -1;
  long segIndex = -1;
  long offset = 1;

  xqpStringStore_t tmp_path = path->byteSubstr(1, path->bytes() - 1 );
  xqpStringStore_t tmp1, tmp2;
  while ((lIndex = tmp_path->bytePositionOf("/../")) != -1) 
  {
    // Undo offset
    lIndex += offset;
    
    // Find start of <segment> within substring ending at found point.
    tmp1 = path->byteSubstr(0, lIndex - 1);
    segIndex = tmp1->byteLastPositionOf("/", 1);

    // Ensure <segment> exists and != ".."
    if (segIndex != -1 &&
        (path->str().at(segIndex+1) != '.' ||
         path->str().at(segIndex+2) != '.' ||
         segIndex + 3 != lIndex)) 
    { 
      tmp1 = path->byteSubstr(0, segIndex);
      tmp2 = path->byteSubstr(lIndex+3, path->bytes() - lIndex - 3);

      path = new xqpStringStore("");
      path->append_in_place(tmp1);
      path->append_in_place(tmp2);

      offset = (segIndex == 0 ? 1 : segIndex);
    }
    else
    {
      offset += 4;
    }

    tmp_path = path->byteSubstr(offset, path->bytes() - offset);
  } // while

  // 6f) If the buffer string ends with "<segment>/..", where <segment>
  // is a complete path segment not equal to "..", that
  // "<segment>/.." is removed.
  if (path->byteEndsWith("/..", 3)) 
  {
    // Find start of <segment> within substring ending at found point.
    lIndex = path->bytes() - 3;
    tmp1 = path->byteSubstr(0, lIndex - 1);
    segIndex = tmp1->byteLastPositionOf("/", 1);

    if (segIndex != -1 &&
        (path->str().at(segIndex+1) != '.' ||
         path->str().at(segIndex+2) != '.' ||
         segIndex + 3 != lIndex))
    {
      path = path->byteSubstr(0, segIndex+1);
    }
  }
  
  thePath = path;
  theURIText = new xqpStringStore(""); // force rebuild in get_uri_text
  theASCIIURIText = new xqpStringStore("");
}


/*******************************************************************************

********************************************************************************/
void URI::relativize(const URI* base_uri)
{
  if ( base_uri == 0 || base_uri->toString()->size() == 0)
    return;

  // if the scheme of the base_uri and the current uri are not identical,
  // we return the current uri
  if ( base_uri->get_scheme()->compare(get_scheme()) != 0 ) 
  {
    return;
  }

  // if the authority of the base_uri and the current uri are not identical,
  // we return the current uri
  xqpStringStore_t auth;
  xqpStringStore_t base_auth;
  get_reg_based_authority(auth);
  base_uri->get_reg_based_authority(base_auth);

  if ( base_auth->compare(auth, NULL) != 0 ) 
  {
    return;
  }

  // if the path of the current uri is not a substring of the path of the base_uri,
  // we return the current uri
  xqpStringStore_t path;
  xqpStringStore_t base_path;
  get_path(path);
  base_uri->get_path(base_path);

  if ( path->positionOf(base_path, NULL) != 0 ) 
  {
    return;
  }

  // construct a new relative hierarchical URI is constructed with query and
  // fragment components taken from the given URI and with a path component
  // computed by removing this URI's 
  // path from the beginning of the given URI's path.
  xqpStringStore_t lNewPath = path->substr(base_path->bytes());
  xqpStringStore_t empty = new xqpStringStore("");
  set_path(lNewPath);
  // unset remaining stuff
  theScheme = empty;
  unset_state(Scheme);
  theRegBasedAuthority = empty;
  unset_state(RegBasedAuthority);
  theUserInfo = empty;
  unset_state(UserInfo);
  thePort = 0;
  unset_state(Port);
  theHost = empty;
  unset_state(Host);
}


/*******************************************************************************

********************************************************************************/
void URI::set_scheme(const xqpStringStore* new_scheme)
{
  if ( new_scheme->empty() ) 
  {
    ZORBA_ERROR_DESC_OSS(XQST0046, "URI scheme is empty");  
  }

  if ( ! is_conformant_scheme_name(new_scheme) ) 
  {
    ZORBA_ERROR_DESC_OSS(XQST0046, "URI contains a scheme \"" 
                         << new_scheme->c_str()
                         << "\" that is not a conformant URI scheme");
  }

  theScheme = new_scheme;
  set_state(Scheme);
}



/*******************************************************************************

********************************************************************************/
bool URI::is_conformant_scheme_name(const xqpStringStore* scheme)
{
  // start with a-zA-Z
  if ( ! scheme->matches("[a-zA-Z]", 8, "" ) )
    return false;
  

  for (ulong i = 0; i < scheme->bytes(); ++i) 
  {
    char c = scheme->str().at(i);

    if ( ! is_alpha(c) && c != '+' && c != '-' && c != '.')
    {
      return false; 
    }
  }
  return true;
}


/*******************************************************************************

********************************************************************************/
void URI::set_user_info(const xqpStringStore* new_user_info)
{
  new_user_info->encodeForUri(theUserInfo, "/", 1);

  set_state(UserInfo);
}



/*******************************************************************************

********************************************************************************/
void URI::set_host(const xqpStringStore* new_host)
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
void URI::set_reg_based_authority(const xqpStringStore* new_authority)
{
  if ( new_authority->empty() ) 
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
void URI::set_path(const xqpStringStore* new_path)
{
  if (new_path->empty()) 
  {
    xqpStringStore_t empty = new xqpStringStore("");
    thePath = empty;
    unset_state(Path);
    theQueryString = empty;
    unset_state(QueryString);
    theFragment = empty;
    unset_state(Fragment);
  }
  else
  {
    initializePath(new_path);
  }
}


/*******************************************************************************

********************************************************************************/
const xqpStringStore_t& URI::toString() const
{
  if (theURIText->empty()) 
  {
    build_full_text();
  }
  return theURIText;
}


/*******************************************************************************

********************************************************************************/
const xqpStringStore_t& URI::toPathNotation() const
{
  if (thePathNotation->empty()) 
  {
    build_path_notation();
  }
  return thePathNotation;
}


/*******************************************************************************

********************************************************************************/
const xqpStringStore_t& URI::toASCIIString() const
{
  if (theASCIIURIText->empty()) 
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
    lToTokenize = theHost->c_str();
  }
  else
  {
    lToTokenize = theRegBasedAuthority->c_str();
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
    lPathNotation << thePath;
  } 

  thePathNotation = new xqpStringStore(lPathNotation.str().c_str());
}


/*******************************************************************************

********************************************************************************/
void URI::build_full_text() const
{
  std::ostringstream lURI;
  
  // Scheme
  if ( is_set(Scheme) )
    lURI << theScheme->c_str() << ":";

  // Authority
  if ( is_set(Host) || is_set(RegBasedAuthority) ) 
  {
    lURI << "//";
    if ( is_set(Host) ) 
    {
      if ( is_set(UserInfo) )
        lURI << theUserInfo->c_str() << "@";

      lURI << theHost;

      if ( is_set(Port) )
        lURI << ":" << thePort;
    }
    else
    {
      lURI << theRegBasedAuthority->c_str();
    }
  }
#ifdef WIN32
    if(theScheme->byteEqual("file", 4))
      lURI << "/";
#endif

  if ( is_set(Path) )
    lURI << thePath->c_str();

  if ( is_set(QueryString) )
    lURI << "?" << theQueryString->c_str();

  if ( is_set(Fragment) )
    lURI << "#" << theFragment->c_str();

  theURIText = new xqpStringStore(lURI.str().c_str());
}


/*******************************************************************************

********************************************************************************/
void URI::build_ascii_full_text() const
{
  std::ostringstream lURI;
  
  // Scheme
  if ( is_set(Scheme) )
    lURI << theScheme->c_str() << ":";

  // Authority
  if ( is_set(Host) || is_set(RegBasedAuthority) ) 
  {
    lURI << "//";
    
    if ( is_set(Host) ) 
    {
      if ( is_set(UserInfo) )
        lURI << theUserInfo->c_str() << "@";

      lURI << theHost->c_str();
#ifdef WIN32
      if(theScheme->byteEqual("file", 4))
        lURI << "/";
#endif

      if ( is_set(Port) )
        lURI << ":" << thePort;
    }
    else 
    {
      lURI << theRegBasedAuthority->c_str();
    }
  }

#ifdef WIN32
  if(theScheme->byteEqual("file", 4))
    lURI << "/";
#endif
  if ( is_set(Path) )
    lURI << thePath->c_str();

  if ( is_set(QueryString) )
    lURI << "?" << theQueryString->c_str();

  if ( is_set(Fragment) )
    lURI << "#" << theFragment->c_str();

  theASCIIURIText = new xqpStringStore(lURI.str().c_str());
}

};
