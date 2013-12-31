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
#include <memory>
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
#include <zorba/store_consts.h>
#include <zorba/user_exception.h>
#include <zorba/util/base64_stream.h>
#include <zorba/util/mem_streambuf.h>
#include <zorba/util/transcode_stream.h>

// local
#include "ftp_connections.h"
#include "ftp_functions.h"
#include "ftp_module.h"
#include "ftpparse.c"

#define IS_ATOMIC_TYPE(ITEM,TYPE) \
  ( (ITEM).isAtomic() && (ITEM).getTypeCode() == store::TYPE )

// Eliminates "control may reach end of non-void function" warning.
#define THROW_EXCEPTION(ERROR_CODE,OBJECT,MESSAGE) \
  while (1) throw_exception( ERROR_CODE, OBJECT, MESSAGE )

/**
 * This is our "external function parameter" name in the dynamic context.
 */
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

inline int get_scheme_len( String const &uri ) {
  if ( uri.compare( 0, 6, "ftp://" ) == 0 )
    return 6;
  return 0;
}

static String host_part( String /* intentionally not const& */ uri ) {
  if ( int const scheme_len = get_scheme_len( uri ) ) {
    uri.erase( 0, scheme_len );
    String::size_type const at_pos = uri.find( '@' );
    if ( at_pos != String::npos )
      uri.erase( 0, at_pos + 1 );       // erase user:password@
    String::size_type const colon_pos = uri.find( ':' );
    if ( colon_pos != String::npos )
      uri.erase( colon_pos );           // erase :port
  }
  return uri;
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

bool function::get_bool_opt( Item const &options, char const *key,
                             bool default_value ) const {
  Item const item( options.getObjectValue( key ) );
  if ( item.isNull() )
    return default_value;
  if ( !IS_ATOMIC_TYPE( item, XS_BOOLEAN ) )
    THROW_EXCEPTION( "INVALID_ARGUMENT", key, "value must be boolean" );
  return item.getBooleanValue();
}

int function::get_integer_opt( Item const &options, char const *key,
                               int default_value ) const {
  Item const item( options.getObjectValue( key ) );
  if ( item.isNull() )
    return default_value;
  if ( !IS_ATOMIC_TYPE( item, XS_INTEGER ) )
    THROW_EXCEPTION( "INVALID_ARGUMENT", key, "value must be integer" );
  return item.getIntValue();
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

String function::get_string_opt( Item const &options, char const *key,
                                 char const *default_value ) const {
  Item const item( options.getObjectValue( key ) );
  if ( item.isNull() )
    return default_value;
  if ( !IS_ATOMIC_TYPE( item, XS_STRING ) )
    THROW_EXCEPTION( "INVALID_ARGUMENT", key, "value must be string" );
  return item.getStringValue();
}

String function::getURI() const {
  return module_->getURI();
}

curl::streambuf* function::require_connection( DynamicContext const *dctx,
                                               String const &conn ) const {
  connections &conns = get_connections( dctx );
  if ( curl::streambuf *const cbuf = conns.get_buf( conn.c_str() ) )
    return cbuf;
  THROW_EXCEPTION( "NOT_CONNECTED", host_part( conn ), "not connnected" );
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
  if ( !encoding.empty() && transcode::is_necessary( encoding.c_str() ) &&
       !transcode::is_supported( encoding.c_str() ) ) {
    THROW_EXCEPTION( "INVALID_ARGUMENT", encoding, "unsupported encoding" );
  }
  String const uri( make_uri( conn, path ) );

  curl::streambuf *const cbuf = require_connection( dctx, conn );
  CURL *const cobj = cbuf->curl();
  curl_easy_setopt( cobj, CURLOPT_TRANSFERTEXT, text_ ? 1 : 0 );
  curl_easy_setopt( cobj, CURLOPT_URL, uri.c_str() );

  istream *const is = new istream( cbuf );
  if ( transcode::is_necessary( encoding.c_str() ) )
    transcode::attach( *is, encoding.c_str() );

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

static size_t curl_read_callback( void *ptr, size_t size, size_t nmemb,
                                  void *data ) {
  size *= nmemb;
  istream *const is = static_cast<istream*>( data );
  is->read( static_cast<char*>( ptr ), static_cast<streamsize>( size ) );
  return is->gcount();
}

struct put_helper {
  put_helper( curl::streambuf *cbuf, istream &is );
  ~put_helper();
private:
  curl::streambuf *const cbuf_;
};

put_helper::put_helper( curl::streambuf *cbuf, istream &is ) : cbuf_( cbuf ) {
  CURL *const cobj = cbuf_->curl();
  ZORBA_CURLM_ASSERT( curl_multi_remove_handle( cbuf_->curlm(), cobj ) );
  ZORBA_CURL_ASSERT( curl_easy_setopt( cobj, CURLOPT_READDATA, &is ) );
  ZORBA_CURL_ASSERT( curl_easy_setopt( cobj, CURLOPT_READFUNCTION, curl_read_callback ) );
  ZORBA_CURL_ASSERT( curl_easy_setopt( cobj, CURLOPT_UPLOAD, 1L ) );
}

put_helper::~put_helper() {
  curl_easy_setopt( cbuf_->curl(), CURLOPT_UPLOAD, 0L );
  curl_multi_add_handle( cbuf_->curlm(), cbuf_->curl() );
}

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
  Item put_item( get_item_arg( args, 1 ) );
  String const path( get_string_arg( args, 2 ) );
  if ( path.empty() )
    THROW_EXCEPTION( "INVALID_ARGUMENT", path, "empty path" );
  String const encoding( text_ ? get_string_arg( args, 2 ) : "" );
  if ( !encoding.empty() && transcode::is_necessary( encoding.c_str() ) &&
       !transcode::is_supported( encoding.c_str() ) ) {
    THROW_EXCEPTION( "INVALID_ARGUMENT", encoding, "unsupported encoding" );
  }
  String const uri( make_uri( conn, path ) );

  curl::streambuf *const cbuf = require_connection( dctx, conn );
  CURL *const cobj = cbuf->curl();
  ZORBA_CURL_ASSERT( curl_easy_setopt( cobj, CURLOPT_TRANSFERTEXT, text_ ? 1 : 0 ) );
  ZORBA_CURL_ASSERT( curl_easy_setopt( cobj, CURLOPT_URL, uri.c_str() ) );

  istream *is;
  mem_streambuf mbuf;
  auto_ptr<istream> raii_is;
  String text;

  if ( put_item.isStreamable() ) {
    is = &put_item.getStream();
  } else {
    if ( text_ ) {
      text = put_item.getStringValue();
      mbuf.set( const_cast<char*>( text.data() ), text.size() );
    } else {
      size_t size;
      char const *const data = put_item.getBase64BinaryValue( size );
      mbuf.set( const_cast<char*>( data ), size );
    }
    is = new istream( &mbuf );
    raii_is.reset( is );
  }

  //
  // Thest raii_* objects must be constructed after raii_is so their destructor
  // is called before that of raii_is (reverse order of construction) so either
  // the base64_streambuf or transcode_streambuf is destroyed before the stream
  // it's attached to is.
  //
  base64::auto_attach<istream> raii_b64;
  transcode::auto_attach<istream> raii_xcode;
  if ( text_ ) {
    if ( !encoding.empty() && transcode::is_necessary( encoding.c_str() ) )
      raii_xcode.attach( *is, encoding.c_str() );
  } else {
    if ( put_item.isEncoded() )
      raii_b64.attach( *is );
  }

  try {
    put_helper putter( cbuf, *is );
    ZORBA_CURL_ASSERT( curl_easy_perform( cobj ) );
    return ItemSequence_t( new EmptySequence() );
  }
  catch ( std::exception const &e ) {
    THROW_EXCEPTION( "FTP_ERROR", path, e.what() );
  }
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
  String const uri( get_string_arg( args, 0 ) );
  String conn( uri );
  //
  // Even though we allow ftp URIs ("ftp://host"), we limit them to refer only
  // to the host and not either a file or subdirectory; hence chop off
  // everything starting at the first '/'.
  //
  int const scheme_len = get_scheme_len( conn );
  String::size_type const slash_pos = conn.find( scheme_len, '/' );
  if ( slash_pos != String::npos )
    conn.erase( slash_pos );

  Item const options( get_item_arg( args, 1 ) );
  String const user( get_string_opt( options, "user", "ftp" ) );
  String const password( get_string_opt( options, "password", "ftp" ) );
  bool const trace( get_bool_opt( options, "trace", false ) );
  int const port( get_integer_opt( options, "port" ) );

  if ( !scheme_len ) {
    if ( user.empty() || password.empty() )
      THROW_EXCEPTION(
        "CREDENTIALS_REQUIRED", uri, "user and password options required"
      );
    conn.insert( (String::size_type)0, 1, '@' );
    conn.insert( 0, password );
    conn.insert( (String::size_type)0, 1, ':' );
    conn.insert( 0, user );
    conn.insert( 0, "ftp://" );
    if ( port ) {
      conn.append( 1, ':' );
      ostringstream oss;
      oss << port;
      conn.append( oss.str() );
    }
  }

  connections &conns = get_connections( dctx );
  curl::streambuf *cbuf = conns.get_buf( conn );
  if ( cbuf )
    THROW_EXCEPTION(
      "ALREADY_CONNECTED", uri, "connection previously established"
    );
  cbuf = conns.new_buf( conn );

  try {
    cbuf->open( conn.c_str() );
    if ( trace )
      curl_easy_setopt( cbuf->curl(), CURLOPT_VERBOSE, 1 );
    Item result( module_->getItemFactory()->createAnyURI( conn ) );
    return ItemSequence_t( new SingletonItemSequence( result ) );
  }
  catch ( std::exception const &e ) {
    THROW_EXCEPTION( "CONNECTION_ERROR", uri, e.what() );
  }
}

///////////////////////////////////////////////////////////////////////////////

#if ZORBA_FTP_CWD_IMPLEMENTED
ItemSequence_t
cwd_function::evaluate( ExternalFunction::Arguments_t const &args,
                        StaticContext const*,
                        DynamicContext const *dctx ) const {
  String const conn( get_string_arg( args, 0 ) );
  String const path( get_string_arg( args, 1 ) );

  curl::streambuf *const cbuf = require_connection( dctx, conn );
  CURL *const cobj = cbuf->curl();

  String req( "CWD " );
  req += path;
  curl_easy_setopt( cobj, CURLOPT_CUSTOMREQUEST, req.c_str() );
  curl_easy_perform( cobj );

  return ItemSequence_t( new EmptySequence() );
}
#endif

///////////////////////////////////////////////////////////////////////////////

disconnect_function::disconnect_function( module const *m ) :
  function( m, "disconnect" )
{
}

ItemSequence_t
disconnect_function::evaluate( ExternalFunction::Arguments_t const &args,
                               StaticContext const*,
                               DynamicContext const *dctx ) const {
  String const conn( get_string_arg( args, 0 ) );
  connections &conns = get_connections( dctx );
  if ( !conns.delete_buf( conn ) )
    THROW_EXCEPTION( "NOT_CONNECTED", host_part( conn ), "not connected" );
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
      } // switch

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
      } // switch

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
  try {
    ZORBA_CURL_ASSERT( curl_easy_setopt( cobj, CURLOPT_URL, uri.c_str() ) );
    return ItemSequence_t(
      new list_iterator( cbuf, module_->getItemFactory() )
    );
  }
  catch ( std::exception const &e ) {
    THROW_EXCEPTION( "FTP_ERROR", path, e.what() );
  }
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
