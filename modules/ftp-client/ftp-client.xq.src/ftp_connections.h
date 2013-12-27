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

#pragma once
#ifndef ZORBA_FTP_CLIENT_FTP_CONNECTIONS_H
#define ZORBA_FTP_CLIENT_FTP_CONNECTIONS_H

// standard
#include <map>

// Zorba
#include <zorba/external_function_parameter.h>
#include <zorba/zorba_string.h>

// local
#include "curl_streambuf.h"

namespace zorba {
namespace ftp_client {

///////////////////////////////////////////////////////////////////////////////

/**
 * An ftp::connections is-an ExternalFunctionParameter (that's added to a
 * query's dynamic context) for keeping a mapping between keys (representing
 * URIs of FTP servers) and their associated curl::streambufs (the active
 * connections to said servers).
 */
class connections : public ExternalFunctionParameter {
public:
  ~connections();

  /**
   * Deletes a curl::streambuf associatied with the given \a key.
   *
   * @param key The key associated with the curl::streambuf to delete.
   * @return Returns \a true only if \a key was associated with a
   * curl::streambuf and therefore deleted; \c false otherwise.
   */
  bool delete_buf( String const &key );

  /**
   * Gets an existing curl::streambuf associatied with the given \a key.
   *
   * @param key The key to get the associated curl::streambuf for.
   * @return Returns said curl::streambuf or \c nullptr if \a key has no
   * associated curl::streambuf.
   */
  curl::streambuf* get_buf( String const &key ) const;

  /**
   * Creates a new curl::streambuf and associates it with the given \a key.
   *
   * @param key The key to associate the newly created curl::streambuf to.
   * The key must not alraedy be associated with any curl::streambuf.
   * @return Returns the newly created curl::streambuf.
   */
  curl::streambuf* new_buf( String const &key );

  // inherited
  virtual void destroy() throw();

private:
  // map keys -> cURL::streambuf*
  typedef std::map<String,curl::streambuf*> key_buf_map;
  key_buf_map key_buf_;
};

///////////////////////////////////////////////////////////////////////////////

} // namespace ftp_client
} // namespace zorba
#endif /* ZORBA_FTP_CLIENT_FTP_CONNECTIONS_H */
/* vim:set et sw=2 ts=2: */
