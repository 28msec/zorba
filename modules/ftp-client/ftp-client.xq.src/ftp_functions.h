/*
 * Copyright 2006-2013 The FLWOR Foundation.
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

#ifndef ZORBA_FTP_CLIENT_MODULE_FUNCTIONS_H
#define ZORBA_FTP_CLIENT_MODULE_FUNCTIONS_H

// Zorba
#include <zorba/function.h>
#include <zorba/item.h>
#include <zorba/util/curl_streambuf.h>
#include <zorba/zorba_string.h>

namespace zorba {
namespace ftp_client {

class module;

///////////////////////////////////////////////////////////////////////////////

class function : public ContextualExternalFunction {
public:
  // inherited
  virtual String getLocalName() const;
  virtual String getURI() const;

protected:
  function( module const *m, char const *local_name );

  bool get_bool_opt( Item const&, char const*, bool = false ) const;
  int get_integer_opt( Item const&, char const*, int = 0 ) const;
  Item get_item_arg( ExternalFunction::Arguments_t const&, unsigned ) const;
  String get_string_arg( ExternalFunction::Arguments_t const&, unsigned ) const;
  String get_string_opt( Item const&, char const*, char const* = "" ) const;

  curl::streambuf* require_connection( DynamicContext const*,
                                       String const& ) const;

  void throw_exception( char const*, char const*, char const*, int = 0 ) const;

  void throw_exception( char const *error_code, String const &s,
                        char const *message, int ftp_code = 0 ) const {
    throw_exception( error_code, s.c_str(), message, ftp_code );
  }

  void throw_exception( char const *error_code, String const &s,
                        String const &message, int ftp_code = 0 ) const {
    throw_exception( error_code, s.c_str(), message.c_str(), ftp_code );
  }

  module const *const module_;
  char const *const local_name_;        // points to C string literal
};

class get_function : public function {
public:
  // inherited
  ItemSequence_t evaluate( ExternalFunction::Arguments_t const&,
                           StaticContext const*, DynamicContext const* ) const;

protected:
  get_function( module const*, char const *local_name, bool text );

  bool const text_;
};

class put_function : public function {
public:
  // inherited
  ItemSequence_t evaluate( ExternalFunction::Arguments_t const&,
                           StaticContext const*, DynamicContext const* ) const;

protected:
  put_function( module const*, char const *local_name, bool text );

  bool const text_;
};

///////////////////////////////////////////////////////////////////////////////

struct connect_function : function {
  connect_function( module const* );
  ItemSequence_t evaluate( ExternalFunction::Arguments_t const&,
                           StaticContext const*, DynamicContext const* ) const;
};

struct disconnect_function : function {
  disconnect_function( module const* );
  ItemSequence_t evaluate( ExternalFunction::Arguments_t const&,
                           StaticContext const*, DynamicContext const* ) const;
};

struct delete_function : function {
  delete_function( module const* );
  ItemSequence_t evaluate( ExternalFunction::Arguments_t const&,
                           StaticContext const*, DynamicContext const* ) const;
};

struct get_binary_function : get_function {
  get_binary_function( module const* );
};

struct get_text_function : get_function {
  get_text_function( module const* );
};

struct list_function : function {
  list_function( module const* );
  ItemSequence_t evaluate( ExternalFunction::Arguments_t const&,
                           StaticContext const*, DynamicContext const* ) const;
};

struct mkdir_function : function {
  mkdir_function( module const* );
  ItemSequence_t evaluate( ExternalFunction::Arguments_t const&,
                           StaticContext const*, DynamicContext const* ) const;
};

struct put_binary_function : put_function {
  put_binary_function( module const* );
};

struct put_text_function : put_function {
  put_text_function( module const* );
};

struct rename_function : function {
  rename_function( module const* );
  ItemSequence_t evaluate( ExternalFunction::Arguments_t const&,
                           StaticContext const*, DynamicContext const* ) const;
};

struct rmdir_function : function {
  rmdir_function( module const* );
  ItemSequence_t evaluate( ExternalFunction::Arguments_t const&,
                           StaticContext const*, DynamicContext const* ) const;
};

///////////////////////////////////////////////////////////////////////////////

} // namespace ftp_client
} // namespace zorba
#endif /* ZORBA_FTP_CLIENT_MODULE_FUNCTIONS_H */
/* vim:set et sw=2 ts=2: */
