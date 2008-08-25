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

namespace zorba {

class URI
{
 public:

  static xqpStringStore_t  decode_file_URI(const xqpStringStore_t& uri);
  static xqpStringStore_t  encode_file_URI(const xqpStringStore_t& uri);
  static xqpStringStore_t encode_file_URI(const std::string& uri) {
    xqpStringStore_t ssuri = new xqpStringStore (uri);
    return encode_file_URI (ssuri);
  }

  // construct a uri
  URI( const xqpString& uri );

  // construct a uri and eventually resolve with the given base uri
  URI( const URI& base_uri, const xqpString& uri );

  // copy constructor
  URI ( const URI& to_copy );

  // default (empty) constructor)
  URI ();

  // destructor
  ~URI();

  bool
  is_absolute() const;

  // get the full uri as text
  const xqpString&
  toString() const;

  const xqpString&
  toASCIIString() const;
  
  // getters and setters for each component
  const xqpString&
  get_scheme() const;

  void
  set_scheme(const xqpString& new_scheme);

  const xqpString&
  get_host() const;

  void
  set_host(const xqpString& new_host);
  
  int
  get_port() const;

  void
  set_port(int new_port);

  const xqpString
  get_user_info() const;

  const xqpString&
  get_encoded_user_info() const;

  void
  set_user_info(const xqpString& new_user_info);

  // decoded
  const xqpString
  get_reg_based_authority() const;

  // encoded
  const xqpString&
  get_encoded_reg_based_authority() const;

  void
  set_reg_based_authority(const xqpString& new_authority);

  // decoded
  const xqpString
  get_path() const;

  // encoded
  const xqpString&
  get_encoded_path() const;

  void
  set_path(const xqpString& new_path);
  
  // decoded
  const xqpString
  get_query() const;

  // encoded
  const xqpString&
  get_encoded_query() const;

  void
  set_query(const xqpString& new_query_string);

  // decoded
  const xqpString
  get_fragment() const;

  // encoded
  const xqpString&
  get_encoded_fragment() const;

  void
  set_fragment(const xqpString& new_fragment);

protected:
  // helper functions
  void
  build_full_text() const;

  void
  build_ascii_full_text() const;

  void
  initialize(const xqpString& uri);

  // simply copy.
  void
  initialize(const URI& toCopy);

  void
  initializeScheme(const xqpString& uri);

  void
  initializeAuthority(const xqpString& uri);

  void
  initializePath(const xqpString& uri);

  bool
  is_conformant_scheme_name(const xqpString& scheme);

  bool
  is_valid_server_based_authority(const xqpString& host, const int port, const xqpString& user_info, bool user_info_found);

  // some small static helpers
  static bool 
  is_well_formed_address(const xqpString& addr);

  static bool
  is_well_formed_ipv6_reference(const xqpString& addr, size_t length);

  static int 
  scanHexSequence (const xqpString& addr, int index, int end, int& counter);

  static bool
  is_well_formed_ipv4_address(const xqpString& addr, size_t length);

  static int
  find_any(const xqpString& str, const std::string& patterns);

  static bool
  is_hex(char c);

  static bool
  is_alpha(char c);

  static bool
  is_digit(char c);

  static bool
  is_alphanum(char c);

  static bool
  is_unreserved_char(char c);

  static bool
  is_path_character(char c);

  static bool
  is_reservered_or_unreserved_char(char c);
  
protected:
  void
  resolve(const URI * base_uri);

  // keep track whether particular components of a uri are defined or undefined
  mutable uint32_t theState;
  enum States {                   
    Scheme            = 1,
    UserInfo          = 2,
    Host              = 4,
    Port              = 8,
    RegBasedAuthority = 16,
    Path              = 32,
    QueryString       = 64,
    Fragment          = 128
  };

  void set_state(uint32_t s) const   { theState |= s; }
  bool is_set(uint32_t s) const      { return theState & s; }
  void unset_state(uint32_t s) const { theState &= ~s; }
 
  // the uri text is composed out of the components below
  // it's mutable because get_uri_text is const
  mutable xqpString theURIText; // encoded
  mutable xqpString theASCIIURIText; // decoded

  // the uri components (RegBasedAuthority, Path, QueryString, Fragment, and UserInfo are always encoded)
  xqpString theScheme;
  xqpString theHost;
  uint32_t  thePort;
  xqpString theUserInfo;
  xqpString theRegBasedAuthority;
  xqpString thePath;
  xqpString theQueryString;
  xqpString theFragment;

}; /* class URI */

inline const xqpString&
URI::get_scheme() const 
{
  return theScheme;
}

inline const xqpString&
URI::get_host() const
{
  return theHost;
}

inline int 
URI::get_port() const
{
  return thePort;
}

inline const xqpString
URI::get_user_info() const
{
  return theUserInfo.decodeFromUri();
}

inline const xqpString&
URI::get_encoded_user_info() const
{
  return theUserInfo;
}

inline const xqpString
URI::get_reg_based_authority() const
{
  return theRegBasedAuthority.decodeFromUri();
}

inline const xqpString&
URI::get_encoded_reg_based_authority() const
{
  return theRegBasedAuthority;
}

inline const xqpString
URI::get_path() const
{
  return thePath.decodeFromUri();
}

inline const xqpString&
URI::get_encoded_path() const
{
  return thePath;
}

inline const xqpString
URI::get_query() const
{
  return theQueryString.decodeFromUri();
}

inline const xqpString&
URI::get_encoded_query() const
{
  return theQueryString;
}

inline const xqpString
URI::get_fragment() const
{
  return theFragment.decodeFromUri();
}

inline const xqpString&
URI::get_encoded_fragment() const
{
  return theFragment;
}

} /* namespace zorba */
/*
 * Local variables:
 * mode: c++
 * End:
 */
