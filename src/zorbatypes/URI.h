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
#ifndef ZORBA_ZORBATYPES_URI_H
#define ZORBA_ZORBATYPES_URI_H

#include <zorba/config.h>
#include "representations.h"

namespace zorba 
{

class ZORBA_DLL_PUBLIC URI
{
public:

  static bool is_hex(uint32_t c);

  static bool is_alpha(uint32_t c);

  static bool is_digit(uint32_t c);

  static bool is_alphanum(uint32_t c);

  static bool is_unreserved_char(uint32_t c);

  static bool is_path_character(uint32_t c);

  static bool is_reservered_or_unreserved_char(uint32_t c);

  static void decode_file_URI(
        const xqpStringStore_t& uri,
        xqpStringStore_t& filepath);

  static void encode_file_URI(
        const xqpStringStore_t& filepath,
        xqpStringStore_t& uri);

  static std::string encode_file_URI(const std::string& filepath);

  static bool is_well_formed_address(const xqpStringStore* addr);

  static bool is_well_formed_ipv6_reference(const xqpStringStore* addr, ulong length);

  static bool is_well_formed_ipv4_address(const xqpStringStore* addr, ulong length);

  static long scanHexSequence(
      const xqpStringStore* addr,
      long index,
      long end,
      long& counter);

  static long find_any(const xqpStringStore* str, const std::string& patterns);

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
  mutable uint32_t           theState;

  // the uri text is composed out of the components below it's mutable because
  // get_uri_text is const
  mutable xqpStringStore_t  theURIText;      // encoded
  mutable xqpStringStore_t  theASCIIURIText; // decoded
  mutable xqpStringStore_t  thePathNotation; 

  // The uri components (UserInfo, RegBasedAuthority, Path, QueryString, and
  // Fragment are always encoded)
  xqpStringStore_t          theScheme;
  xqpStringStore_t          theHost;
  uint32_t                  thePort;
  xqpStringStore_t          theUserInfo;
  xqpStringStore_t          theRegBasedAuthority;
  xqpStringStore_t          thePath;
  xqpStringStore_t          theQueryString;
  xqpStringStore_t          theFragment;

  // true if the constructed URI is valid
  bool                      valid;

 public:
  URI(const xqpStringStore* uri, bool validate = true);

  URI(const URI& base_uri, const xqpStringStore* uri, bool validate = true);

  URI (const URI& full_uri, const URI& base_uri);

  URI (const URI& to_copy);

  URI();

  ~URI();

  bool is_absolute() const;

  // get the full uri as text
  const xqpStringStore_t& toString() const;

  const xqpStringStore_t& toASCIIString() const;

  const xqpStringStore_t& toPathNotation() const;

  // getters and setters for each component
  bool is_valid() const;

  const xqpStringStore_t& get_scheme() const;

  void set_scheme(const xqpStringStore* new_scheme);

  const xqpStringStore_t& get_host() const;

  void set_host(const xqpStringStore* new_host);

  int get_port() const;

  void set_port(int new_port);

  void get_user_info(xqpStringStore_t& result) const;

  const xqpStringStore_t& get_encoded_user_info() const;

  void set_user_info(const xqpStringStore* new_user_info);

  void get_reg_based_authority(xqpStringStore_t& result) const;

  const xqpStringStore_t& get_encoded_reg_based_authority() const;

  void set_reg_based_authority(const xqpStringStore* new_authority);

  void get_path(xqpStringStore_t& result) const;

  const xqpStringStore_t& get_encoded_path() const;

  void set_path(const xqpStringStore* new_path);

  void get_query(xqpStringStore_t& result) const;

  const xqpStringStore_t& get_encoded_query() const;

  void set_query(const xqpStringStore* new_query_string);

  void get_fragment(xqpStringStore_t& result) const;

  const xqpStringStore_t& get_encoded_fragment() const;

  void set_fragment(const xqpStringStore* new_fragment);

protected:
  void build_full_text() const;

  void build_ascii_full_text() const;

  void build_path_notation() const;

  void initialize(const URI& toCopy);

  void initialize(const xqpStringStore* uri, bool have_base = false);

  void initializeScheme(const xqpStringStore* uri);

  void initializeAuthority(const xqpStringStore* uri);

  void initializePath(const xqpStringStore* uri);

  bool is_conformant_scheme_name(const xqpStringStore* scheme);

  bool is_valid_server_based_authority(
    const xqpStringStore* host,
    const int port,
    const xqpStringStore* user_info,
    bool user_info_found);

  void resolve(const URI* base_uri);

  void relativize(const URI* base_uri);

  void set_state(uint32_t s) const { theState |= s; }

  bool is_set(uint32_t s) const { return ((theState & s) > 0); }

  void unset_state(uint32_t s) const { theState &= ~s; }
};


inline bool URI::is_valid() const
{
  return valid;
}


inline const xqpStringStore_t& URI::get_scheme() const 
{
  return theScheme;
}


inline const xqpStringStore_t& URI::get_host() const
{
  return theHost;
}


inline int URI::get_port() const
{
  return thePort;
}


inline void URI::get_user_info(xqpStringStore_t& result) const
{
  theUserInfo->decodeFromUri(result);
}


inline const xqpStringStore_t& URI::get_encoded_user_info() const
{
  return theUserInfo;
}


inline void URI::get_reg_based_authority(xqpStringStore_t& result) const
{
  theRegBasedAuthority->decodeFromUri(result);
}


inline const xqpStringStore_t& URI::get_encoded_reg_based_authority() const
{
  return theRegBasedAuthority;
}


inline void URI::get_path(xqpStringStore_t& result) const
{
  return thePath->decodeFromUri(result);
}


inline const xqpStringStore_t& URI::get_encoded_path() const
{
  return thePath;
}


inline void URI::get_query(xqpStringStore_t& result) const
{
  return theQueryString->decodeFromUri(result);
}


inline const xqpStringStore_t& URI::get_encoded_query() const
{
  return theQueryString;
}


inline void URI::get_fragment(xqpStringStore_t& result) const
{
  return theFragment->decodeFromUri(result);
}


inline const xqpStringStore_t& URI::get_encoded_fragment() const
{
  return theFragment;
}


} /* namespace zorba */

/*
 * Local variables:
 * mode: c++
 * End:
 */

#endif
