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

// standard
#include <cstdio>
#include <cstdlib>
#include <sstream>
#ifdef WIN32
#include <windows.h>
#include <direct.h>
#else
#include <unistd.h>
#endif /* WIN32 */

// Zorba
#include <zorba/diagnostic_list.h>
#include <zorba/empty_sequence.h>
#include <zorba/serializer.h>
#include <zorba/singleton_item_sequence.h>
#include <zorba/store_consts.h>
#include <zorba/user_exception.h>
#include <zorba/util/fs_util.h>
#include <zorba/util/transcode_stream.h>
#include <zorba/xquery_functions.h>
#include <zorba/zorba.h>

// local
#include "file_function.h"
#include "file_module.h"

using namespace std;

namespace zorba {
namespace filemodule {

///////////////////////////////////////////////////////////////////////////////

FileFunction::FileFunction( FileModule const *m, char const *local_name ) :
  module_( m ),
  local_name_( local_name )
{
}

String FileFunction::getLocalName() const {
  return local_name_;
}

int FileFunction::raiseFileError( char const *aQName, char const *aMessage,
                                  String const &aPath ) const {
  Item const lQName(
    module_->getItemFactory()->createQName( getURI(), "file", aQName )
  );
  ostringstream lErrorMessage;
  lErrorMessage << '"' << aPath << "\": " << aMessage;
  throw USER_EXCEPTION( lQName, lErrorMessage.str() );
}

String FileFunction::getURI() const {
  return module_->getURI();
}

String FileFunction::getEncodingArg( ExternalFunction::Arguments_t const &args,
                                     unsigned pos ) const {
  String encoding( getStringArg( args, pos ) );
  if ( encoding.empty() )
    encoding = "UTF-8";                 // the default file encoding
  return encoding;
}

String FileFunction::getPathArg( ExternalFunction::Arguments_t const &args,
                                 unsigned pos ) const {
  String const path( getStringArg( args, pos ) );
  if ( path.empty() )
    return path;
  try {
    return fs::normalize_path( path, fs::curdir() );
  }
  catch ( invalid_argument const &e ) {
    throw raiseFileError( "FOFL9999", e.what(), path );
  }
}

String FileFunction::getStringArg( ExternalFunction::Arguments_t const &args,
                                   unsigned pos ) const {
  String s;
  if ( pos < args.size() ) {
    Iterator_t it( args[ pos ]->getIterator() );
    it->open();
    Item item;
    if ( it->next( item ) )
      s = item.getStringValue();
    it->close();
  }
  return s;
}

String FileFunction::pathToUriString(const String& aPath) const {
  if ( fn::starts_with( aPath,"file://" ) ) {
    stringstream msg;
    msg << '"' << aPath << "\": path must not be a URI";
    Item const lQName(
      module_->getItemFactory()->createQName(
        "http://www.w3.org/2005/xqt-errors", "err", "XPTY0004"
      )
    );
    throw USER_EXCEPTION( lQName, msg.str() );
  }
  String const uri( aPath );
  return uri;
}

///////////////////////////////////////////////////////////////////////////////

WriteBinaryFunctionImpl::WriteBinaryFunctionImpl( FileModule const *m,
                                                  char const *local_name,
                                                  bool append ) :
  FileFunction( m, local_name ),
  append_( append )
{
}

ItemSequence_t WriteBinaryFunctionImpl::evaluate(
  ExternalFunction::Arguments_t const &args,
  StaticContext const*,
  DynamicContext const* ) const
{
  String const path( getPathArg( args, 0 ) );

  fs::type const fs_type = fs::get_type( path );
  if ( fs_type && fs_type != fs::file )
    raiseFileError( "FOFL0004", "not a plain file", path );

  ios_base::openmode const mode = ios_base::out | ios_base::binary
    | (append_ ? ios_base::app : ios_base::trunc);

  ofstream ofs( path.c_str(), mode );
  if ( !ofs ) {
    ostringstream oss;
    oss << '"' << path << "\": can not open file for writing";
    raiseFileError( "FOFL9999", oss.str().c_str(), path );
  }

  Iterator_t it( args[1]->getIterator() );
  it->open();
  Item item;
  while ( it->next( item ) ) {
    if ( item.isStreamable() && !item.isEncoded() )
      ofs << item.getStream().rdbuf();
    else {
      Zorba_SerializerOptions options;
      options.ser_method = ZORBA_SERIALIZATION_METHOD_BINARY;
      Serializer_t serializer( Serializer::createSerializer( options ) );
      SingletonItemSequence seq( item );
      serializer->serialize( &seq, ofs );
    }
  }
  it->close();

  return ItemSequence_t( new EmptySequence() );
}

///////////////////////////////////////////////////////////////////////////////

WriteTextFunctionImpl::WriteTextFunctionImpl( FileModule const *m,
                                              char const *local_name,
                                              bool append ) :
  FileFunction( m, local_name ),
  append_( append )
{
}

ItemSequence_t WriteTextFunctionImpl::evaluate(
  ExternalFunction::Arguments_t const &args,
  StaticContext const*,
  DynamicContext const* ) const
{
  String const path( getPathArg( args, 0 ) );
  String const encoding( getStringArg( args, 2 ) );

  fs::type const fs_type = fs::get_type( path );
  if ( fs_type && fs_type != fs::file )
    raiseFileError( "FOFL0004", "not a plain file", path );

  if ( !transcode::is_supported( encoding.c_str() ) )
    raiseFileError( "FOFL9999", "encoding not supported", encoding );

  ios_base::openmode const mode = ios_base::out
    | (append_ ? ios_base::app : ios_base::trunc);

  ofstream ofs( path.c_str(), mode );
  if ( !ofs ) {
    ostringstream oss;
    oss << '"' << path << "\": can not open file for writing";
    raiseFileError( "FOFL9999", oss.str().c_str(), path );
  }

  transcode::auto_attach<ofstream> transcoder;
  if ( transcode::is_necessary( encoding.c_str() ) )
    transcoder.attach( ofs, encoding.c_str() );

  Iterator_t it( args[1]->getIterator() );
  it->open();
  Item item;
  while ( it->next( item ) ) {
    if ( item.isStreamable() ) {
      ofs << item.getStream().rdbuf();
    } else {
      zorba::String const s( item.getStringValue() );
      ofs.write( s.data(), s.size() );
    }
  }
  it->close();

  return ItemSequence_t( new EmptySequence() );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace filemodule
} // namespace zorba
/* vim:set et sw=2 ts=2: */
