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
#include <ctime>
#include <istream>
#include <sstream>
#include <string>
#include <utility>                      /* for pair */
#include <vector>

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
#include "ftpparse.c"

// Eliminates "control may reach end of non-void function" warning.
#define THROW_EXCEPTION(ERROR_CODE,OBJECT,MESSAGE) \
  while (1) throw_exception( ERROR_CODE, OBJECT, MESSAGE )

#define ZORBA_FTP_CONNECTIONS "http://zorba.io/modules/ftp-client/connections"

using namespace std;

namespace zorba {
namespace ftp_client {

///////////////////////////////////////////////////////////////////////////////

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

static String make_uri( String const &uri,
                        String path, // intentionally not const&
                        bool path_is_dir = false ) {
  if ( path.empty() )
    path = '/';
  else {
    if ( path_is_dir && path[ path.size() - 1 ] != '/' )
      path += '/';
    if ( path[0] != '/' )
      path.insert( (String::size_type)0, 1, '/' );
  }
  String result( uri );
  result += path;
  return result;
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
  String const conn( get_string_arg( args, 0 ) );
  String const path( get_string_arg( args, 1 ) );
  if ( path.empty() )
    THROW_EXCEPTION( "INVALID_ARGUMENT", path, "empty path" );
  String const encoding( text_ ? get_string_arg( args, 2 ) : "" );
  String const uri( make_uri( conn, path ) );

  curl::streambuf *const cbuf = require_connection( dctx, conn );
  CURL *const cobj = cbuf->curl();
  curl_easy_setopt( cobj, CURLOPT_TRANSFERTEXT, text_ ? 1 : 0 );
  curl_easy_setopt( cobj, CURLOPT_URL, uri.c_str() );

  istream *const is = new istream( cbuf );
  ItemFactory *const f = module_->getItemFactory();
  Item result(
    text_ ?
      f->createStreamableString( *is, &stream_releaser )
    :
      f->createStreamableBase64Binary( *is, &stream_releaser, false )
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
  String const conn( get_string_arg( args, 0 ) );
  Item text_item( get_item_arg( args, 1 ) );
  String const path( get_string_arg( args, 2 ) );
  if ( path.empty() )
    THROW_EXCEPTION( "INVALID_ARGUMENT", path, "empty path" );
  String const uri( make_uri( conn, path ) );

  curl::streambuf *const cbuf = require_connection( dctx, conn );
  CURL *const cobj = cbuf->curl();
  curl_easy_setopt( cobj, CURLOPT_TRANSFERTEXT, text_ ? 1 : 0 );
  curl_easy_setopt( cobj, CURLOPT_UPLOAD, 1L );
  curl_easy_setopt( cobj, CURLOPT_URL, uri.c_str() );

  istream *is;
  String text;
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
  //
  // Even though we allow ftp URIs ("ftp://host"), we limit them to refer only
  // to the host and not either a file or subdirectory; hence chop off
  // eveyrthing past the first '/'.
  //
  String::size_type const slash_pos = uri.find( is_uri ? 6 : 0, '/' );
  if ( slash_pos != String::npos )
    uri.erase( slash_pos );

  Item const options( get_item_arg( args, 1 ) );
  String const user( get_string_option( options, "user" ) );
  String const password( get_string_option( options, "password" ) );
  int const port( get_integer_option( options, "port" ) );

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
  cbuf = conns.new_buf( uri );

  try {
    cbuf->open( uri.c_str() );
    Item result( module_->getItemFactory()->createAnyURI( uri ) );
    return ItemSequence_t( new SingletonItemSequence( result ) );
  }
  catch ( curl::exception const &e ) {
    THROW_EXCEPTION( "CONNECTION_ERROR", uri, e.what() );
  }
}

///////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////

get_binary_function::get_binary_function( module const *m ) :
  get_function( m, "get-binary", false )
{
}

///////////////////////////////////////////////////////////////////////////////

get_text_function::get_text_function( module const *m ) :
  get_function( m, "get-text", true )
{
}

///////////////////////////////////////////////////////////////////////////////

class list_iterator : public ItemSequence, public Iterator {
public:
  list_iterator( curl::streambuf*, ItemFactory* );

  // inherited from ItemSequence
  Iterator_t getIterator();

  // inherited from Iterator
  void close();
  bool isOpen() const;
  bool next( Item& );
  void open();

private:
  ItemFactory *const factory_;
  istream is_;
  bool open_;
};

list_iterator::list_iterator( curl::streambuf *cbuf, ItemFactory *factory ) :
  factory_( factory ),
  is_( cbuf ),
  open_( false )
{
}

void list_iterator::close() {
  open_ = false;
}

Iterator_t list_iterator::getIterator() {
  return this;
}

bool list_iterator::isOpen() const {
  return open_;
}

bool list_iterator::next( Item &result ) {
  static Item const mtime_key( factory_->createString( "mtime" ) );
  static Item const name_key( factory_->createString( "name" ) );
  static Item const size_key( factory_->createString( "size" ) );

  string line;
  while ( getline( is_, line ) ) {
    if ( line.empty() )
      continue;
    if ( line[ line.size() - 1 ] == '\r' )
      line.erase( line.size() - 1 );
    struct ftpparse ftp_file;
    if ( ftpparse( &ftp_file, line.data(), line.size() ) ) {
      vector<pair<Item,Item> > kv;

      String name( ftp_file.name, ftp_file.namelen );
      Item const name_value( factory_->createString( name ) );
      kv.push_back( make_pair( name_key, name_value ) );

      switch ( ftp_file.sizetype ) {
        case FTPPARSE_SIZE_ASCII:
        case FTPPARSE_SIZE_BINARY: {
          Item const size_value( factory_->createLong( ftp_file.size ) );
          kv.push_back( make_pair( size_key, size_value ) );
          break;
        }
        case FTPPARSE_SIZE_UNKNOWN:
          // do nothing
          break;
      }

      struct tm tm;
      gmtime_r( &ftp_file.mtime, &tm );
      int const year = tm.tm_year + 1900;
      switch ( ftp_file.mtimetype ) {
        case FTPPARSE_MTIME_REMOTEDAY:
          tm.tm_hour = tm.tm_min = 0;
          // no break;
        case FTPPARSE_MTIME_REMOTEMINUTE:
          tm.tm_sec = 0;
          tm.tm_gmtoff = 0;
          // no break;
        case FTPPARSE_MTIME_LOCAL: {
          Item const mtime_value (
            factory_->createDateTime(
              year, tm.tm_mon, tm.tm_mday,
              tm.tm_hour, tm.tm_min, tm.tm_sec, (int)tm.tm_gmtoff
            )
          );
          kv.push_back( make_pair( mtime_key, mtime_value ) );
          // no break;
        }
        case FTPPARSE_MTIME_UNKNOWN:
          // do nothing
          break;
      }

      result = factory_->createJSONObject( kv );
      return true;
    } // if
  } // while
  return false;
}

void list_iterator::open() {
  open_ = true;
}

list_function::list_function( module const *m ) :
  function( m, "list" )
{
}

ItemSequence_t
list_function::evaluate( ExternalFunction::Arguments_t const &args,
                         StaticContext const*,
                         DynamicContext const *dctx ) const {
  String const conn( get_string_arg( args, 0 ) );
  String const path( get_string_arg( args, 1 ) );
  String const uri( make_uri( conn, path, true ) );

  curl::streambuf *const cbuf = require_connection( dctx, conn );
  CURL *const cobj = cbuf->curl();
  curl_easy_setopt( cobj, CURLOPT_URL, uri.c_str() );
  return ItemSequence_t( new list_iterator( cbuf, module_->getItemFactory() ) );
}

///////////////////////////////////////////////////////////////////////////////

put_binary_function::put_binary_function( module const *m ) :
  put_function( m, "put-binary", false )
{
}

///////////////////////////////////////////////////////////////////////////////

put_text_function::put_text_function( module const *m ) :
  put_function( m, "put-text", true )
{
}

///////////////////////////////////////////////////////////////////////////////

} // namespace ftp_client
} // namespace zorba
/* vim:set et sw=2 ts=2: */
