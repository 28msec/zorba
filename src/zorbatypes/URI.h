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
#ifndef ZORBA_ZORBATYPES_URI_H
#define ZORBA_ZORBATYPES_URI_H

#include <iostream>

#include <zorba/config.h>
#include "schema_types.h"

namespace zorba 
{

class ZORBA_DLL_PUBLIC URI
{
public:

  static bool is_unreserved_char(uint32_t c);

  static bool is_path_character(uint32_t c);

  static bool is_reservered_or_unreserved_char(uint32_t c);

  static void decode_file_URI(const zstring& uri, zstring& filepath);

  static void encode_file_URI(const zstring& filepath, zstring& uri);

  static std::string encode_file_URI(const std::string& filepath);

  static bool is_well_formed_address(const char* addr, ulong length);

  static bool is_well_formed_ipv6_reference(const char* addr, ulong length);

  static bool is_well_formed_ipv4_address(const char* addr, ulong length);

  static long scanHexSequence(const char* addr, long idx, long end, long& counter);

protected:
  enum States 
  {
    Scheme            = 1,
    UserInfo          = 2,
    Host              = 4,
    Port              = 8,
    RegBasedAuthority = 16,
    Path              = 32,
    QueryString       = 64,
    Fragment          = 128
  };

  // keep track whether particular components of a uri are defined or undefined
  mutable uint32_t theState;

  // the uri text is composed out of the components below it's mutable because
  // get_uri_text is const
  mutable zstring  theURIText;      // encoded
  mutable zstring  theASCIIURIText; // decoded
  mutable zstring  thePathNotation; 

  // The uri components (UserInfo, RegBasedAuthority, Path, QueryString, and
  // Fragment are always encoded)
  zstring          theScheme;
  zstring          theHost;
  uint32_t         thePort;
  zstring          theUserInfo;
  zstring          theRegBasedAuthority;
  zstring          thePath;
  zstring          theQueryString;
  zstring          theFragment;

  // true if the constructed URI is valid
  bool             valid;

public:
  URI(const zstring& uri, bool validate = true);

  URI(const URI& base_uri, const zstring& uri, bool validate = true);

  URI (const URI& full_uri, const URI& base_uri);

  URI (const URI& to_copy);

  URI();

  ~URI();

  bool is_absolute() const;

  // get the full uri as text
  const zstring& toString() const;

  const zstring& toASCIIString() const;

  const zstring& toPathNotation() const;

  // getters and setters for each component
  bool is_valid() const;

  const zstring& get_scheme() const;

  void set_scheme(const zstring& new_scheme);

  const zstring& get_host() const;

  void set_host(const zstring& new_host);

  int get_port() const;

  void set_port(int new_port);

  void get_user_info(zstring& result) const;

  const zstring& get_encoded_user_info() const;

  void set_user_info(const zstring& new_user_info);

  void get_reg_based_authority(zstring& result) const;

  const zstring& get_encoded_reg_based_authority() const;

  void set_reg_based_authority(const zstring& new_authority);

  void get_path(zstring& result) const;

  const zstring& get_encoded_path() const;

  void set_path(const zstring& new_path);

  void get_query(zstring& result) const;

  const zstring& get_encoded_query() const;

  void set_query(const zstring& new_query_string);

  void get_fragment(zstring& result) const;

  const zstring& get_encoded_fragment() const;

  void set_fragment(const zstring& new_fragment);

  void clear_fragment();

protected:
  void build_full_text() const;

  void build_ascii_full_text() const;

  void build_path_notation() const;

  void initialize(const URI& toCopy);

  void initialize(const zstring& uri, bool have_base = false);

  void initializeScheme(const zstring& uri);

  void initializeAuthority(const zstring& uri);

  void initializePath(const zstring& uri);

  bool is_conformant_scheme_name(const zstring& scheme);

  bool is_valid_server_based_authority(
    const zstring& host,
    const int port,
    const zstring& user_info,
    bool user_info_found);

  void resolve(const URI* base_uri);

  void relativize(const URI* base_uri);

  void set_state(uint32_t s) const { theState |= s; }

  bool is_set(uint32_t s) const { return ((theState & s) > 0); }

  void unset_state(uint32_t s) const { theState &= ~s; }

  void invalidate_text() const;
  
  bool is_absolute_path(zstring &thePath);
};


inline bool URI::is_valid() const
{
  return valid;
}


inline const zstring& URI::get_scheme() const 
{
  return theScheme;
}


inline const zstring& URI::get_host() const
{
  return theHost;
}


inline int URI::get_port() const
{
  return thePort;
}


inline const zstring& URI::get_encoded_user_info() const
{
  return theUserInfo;
}


inline const zstring& URI::get_encoded_reg_based_authority() const
{
  return theRegBasedAuthority;
}


inline const zstring& URI::get_encoded_path() const
{
  return thePath;
}


inline const zstring& URI::get_encoded_query() const
{
  return theQueryString;
}


inline const zstring& URI::get_encoded_fragment() const
{
  return theFragment;
}

inline void URI::set_fragment(const zstring &new_fragment)
{
  theFragment = new_fragment;
  invalidate_text();
}

inline void URI::clear_fragment()
{
  theFragment.clear();
  unset_state(Fragment);
  invalidate_text();
}

inline void URI::invalidate_text() const
{
  theASCIIURIText.clear();
  theURIText.clear();
}

inline std::ostream& operator<<( std::ostream &o, URI const &uri ) {
  return o << uri.toString();
}

} // namespace zorba
#endif /* ZORBA_ZORBATYPES_URI_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
