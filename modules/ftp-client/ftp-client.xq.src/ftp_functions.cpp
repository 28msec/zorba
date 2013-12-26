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

// standard
#include <istream>
#include <sstream>
#include <string>

// Zorba
#include <zorba/dynamic_context.h>
#include <zorba/empty_sequence.h>
#include <zorba/item_factory.h>
#include <zorba/item_sequence.h>
#include <zorba/iterator.h>
#include <zorba/singleton_item_sequence.h>
#include <zorba/user_exception.h>

// local
#include "ftp_connections.h"
#include "ftp_functions.h"
#include "ftp_module.h"

// Eliminates "control may reach end of non-void function" warning.
#define THROW_EXCEPTION(ERROR_CODE,OBJECT,MESSAGE) \
  while (1) throw_exception( ERROR_CODE, OBJECT, MESSAGE )

#define ZORBA_FTP_CONNECTIONS "http://zorba.io/modules/ftp-client/connections"

using namespace std;

namespace zorba {
namespace ftp_client {

///////////////////////////////////////////////////////////////////////////////

static size_t curl_header_callback( void *ptr, size_t size, size_t nmemb,
                                    void *data ) {
  size *= nmemb;
  streambuf *const that = static_cast<streambuf*>( data );
  char const *const s = static_cast<char const*>( ptr );
  String d( s, size );
  cout << "HEADER:" << d << endl;
  // TODO
  return size;
}

static connections& get_connections( DynamicContext const *dctx ) {
  connections *conns = static_cast<connections*>(
    dctx->getExternalFunctionParameter( ZORBA_FTP_CONNECTIONS )
  );
  if ( !conns ) {
    conns = new connections();
    dctx->addExternalFunctionParameter( ZORBA_FTP_CONNECTIONS, conns );
  }
  return *conns;
}

static int get_integer_option( Item const &options, char const *key ) {
  Item const item( options.getObjectValue( key ) );
  return item.isNull() ? 0 : item.getIntValue();
}

static String get_string_option( Item const &options, char const *key ) {
  Item const item( options.getObjectValue( key ) );
  return item.getStringValue();
}

static void stream_releaser( istream *is ) {
  delete is;
}

///////////////////////////////////////////////////////////////////////////////

function::function( module const *m, char const *local_name ) :
  module_( m ),
  local_name_( local_name )
{
}

Item function::get_item_arg( ExternalFunction::Arguments_t const &args,
                             unsigned pos ) const {
  Item result;
  if ( pos < args.size() ) {
    Iterator_t it( args[ pos ]->getIterator() );
    it->open();
    it->next( result );
    it->close();
  }
  return result;
}

String function::getLocalName() const {
  return local_name_;
}

String function::get_string_arg( ExternalFunction::Arguments_t const &args,
                                 unsigned pos ) const {
  String s;
  Item const item( get_item_arg( args, pos ) );
  if ( !item.isNull() )
    s = item.getStringValue();
  return s;
}

String function::getURI() const {
  return module_->getURI();
}

curl::streambuf* function::require_connection( DynamicContext const *dctx,
                                               String const &uri ) const {
  connections &conns = get_connections( dctx );
  if ( curl::streambuf *const cbuf = conns.get_buf( uri.c_str() ) )
    return cbuf;
  THROW_EXCEPTION( "NOT_CONNECTED", uri, "not connnected" );
}

void function::throw_exception( char const *error_code, char const *object,
                                char const *message ) const {
  ostringstream oss;
  string s;

  if ( object && *object ) {
    oss << '"' << object << "\": " << message;
    s = oss.str();
  } else
    s = message;

  throw USER_EXCEPTION(
    module_->getItemFactory()->createQName( getURI(), error_code ), s
  );
}

///////////////////////////////////////////////////////////////////////////////

get_function::get_function( module const *m, char const *local_name,
                            bool text ) :
  function( m, local_name ),
  text_( text )
{
}

ItemSequence_t
get_function::evaluate( ExternalFunction::Arguments_t const &args,
                        StaticContext const*,
                        DynamicContext const *dctx ) const {
  String uri( get_string_arg( args, 0 ) );
  String const file( get_string_arg( args, 1 ) );
  String const encoding( text_ ? get_string_arg( args, 2 ) : "" );

  curl::streambuf *const cbuf = require_connection( dctx, uri );
  CURL *const cobj = cbuf->curl();
  uri += '/', uri += file;
  curl_easy_setopt( cobj, CURLOPT_TRANSFERTEXT, text_ ? 1 : 0 );
  curl_easy_setopt( cobj, CURLOPT_URL, uri.c_str() );

  istream *const is = new istream( cbuf );
  Item result(
    text_ ?
      module_->getItemFactory()->createStreamableString(
        *is, &stream_releaser, true
      )
    :
      module_->getItemFactory()->createStreamableBase64Binary(
        *is, &stream_releaser, true
      )
  );
  return ItemSequence_t( new SingletonItemSequence( result ) );
}

///////////////////////////////////////////////////////////////////////////////

put_function::put_function( module const *m, char const *local_name,
                            bool text ) :
  function( m, local_name ),
  text_( text )
{
}

ItemSequence_t
put_function::evaluate( ExternalFunction::Arguments_t const &args,
                        StaticContext const*,
                        DynamicContext const *dctx ) const {
  String uri( get_string_arg( args, 0 ) );
  Item text_item( get_item_arg( args, 1 ) );
  String text;
  String const file( get_string_arg( args, 2 ) );

  curl::streambuf *const cbuf = require_connection( dctx, uri );
  CURL *const cobj = cbuf->curl();
  uri += '/', uri += file;
  curl_easy_setopt( cobj, CURLOPT_TRANSFERTEXT, text_ ? 1 : 0 );
  curl_easy_setopt( cobj, CURLOPT_UPLOAD, 1L );
  curl_easy_setopt( cobj, CURLOPT_URL, uri.c_str() );

  istream *is;
  if ( text_item.isStreamable() ) {
    is = &text_item.getStream();
  } else {
    text = text_item.getStringValue();
    // TODO
    curl_easy_setopt( cobj, CURLOPT_INFILESIZE_LARGE, (curl_off_t)text.size() );
  }

  // TODO

  curl_easy_setopt( cobj, CURLOPT_UPLOAD, 0L );
  return ItemSequence_t( new EmptySequence() );
}

///////////////////////////////////////////////////////////////////////////////

connect_function::connect_function( module const *m ) :
  function( m, "connect" )
{
}

ItemSequence_t
connect_function::evaluate( ExternalFunction::Arguments_t const &args,
                            StaticContext const*,
                            DynamicContext const *dctx ) const {
  String uri( get_string_arg( args, 0 ) );
  bool const is_uri = uri.compare( 0, 6, "ftp://" ) == 0;

  Item const options( get_item_arg( args, 1 ) );
  String const user( get_string_option( options, "user" ) );
  String const password( get_string_option( options, "password" ) );
  int const port( get_integer_option( options, "port" ) );

  if ( !uri.empty() && uri[ uri.size() - 1 ] == '/' )
    uri.erase( uri.size() - 1 );

  if ( !is_uri ) {
    if ( user.empty() || password.empty() )
      THROW_EXCEPTION(
        "CREDENTIALS_REQUIRED", uri, "user and password options required"
      );
    uri.insert( (String::size_type)0, 1, '@' );
    uri.insert( 0, password );
    uri.insert( (String::size_type)0, 1, ':' );
    uri.insert( 0, user );
    uri.insert( 0, "ftp://" );
    if ( port ) {
      uri.append( 1, ':' );
      ostringstream oss;
      oss << port;
      uri.append( oss.str() );
    }
  }

  connections &conns = get_connections( dctx );
  curl::streambuf *cbuf = conns.get_buf( uri );
  if ( cbuf )
    THROW_EXCEPTION(
      "ALREADY_CONNECTED", uri, "connection previously established"
    );

  try {
    cbuf = conns.new_buf( uri );
    CURL *const cobj = cbuf->curl();
    curl_easy_setopt( cobj, CURLOPT_HEADERFUNCTION, &curl_header_callback );
    curl_easy_setopt( cobj, CURLOPT_HEADERDATA, this );
    curl_easy_setopt( cobj, CURLOPT_NOPROGRESS, (long)1 );
    curl_easy_setopt( cobj, CURLOPT_VERBOSE, 1 );
    cbuf->open( uri.c_str() );
    Item result( module_->getItemFactory()->createAnyURI( uri ) );
    return ItemSequence_t( new SingletonItemSequence( result ) );
  }
  catch ( curl::exception const &e ) {
    THROW_EXCEPTION( "CONNECTION_ERROR", uri, e.what() );
  }
}

disconnect_function::disconnect_function( module const *m ) :
  function( m, "disconnect" )
{
}

ItemSequence_t
disconnect_function::evaluate( ExternalFunction::Arguments_t const &args,
                               StaticContext const*,
                               DynamicContext const *dctx ) const {
  String const uri( get_string_arg( args, 0 ) );
  connections &conns = get_connections( dctx );
  if ( !conns.delete_buf( uri ) )
    THROW_EXCEPTION( "NOT_CONNECTED", uri, "not connected" );
  return ItemSequence_t( new EmptySequence() );
}

get_binary_function::get_binary_function( module const *m ) :
  get_function( m, "get-binary", false )
{
}

get_text_function::get_text_function( module const *m ) :
  get_function( m, "get-text", true )
{
}

put_binary_function::put_binary_function( module const *m ) :
  put_function( m, "put-binary", false )
{
}

put_text_function::put_text_function( module const *m ) :
  put_function( m, "put-text", true )
{
}

///////////////////////////////////////////////////////////////////////////////

} // namespace ftp_client
} // namespace zorba
/* vim:set et sw=2 ts=2: */
