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

// Zorba
#include <zorba/empty_sequence.h>
#include <zorba/item_factory.h>
#include <zorba/item_sequence.h>
#include <zorba/iterator.h>
#include <zorba/singleton_item_sequence.h>

// local
#include "ftp_functions.h"
#include "ftp_module.h"

using namespace std;

namespace zorba {
namespace ftp_client {

///////////////////////////////////////////////////////////////////////////////

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
                        DynamicContext const* ) const {
  // TODO
  try {
    Item result;
#if 0
    Item result(
      text_ ?
        module_->getItemFactory()->createStreamableString(
          *stream_ptr, &stream_releaser, true
        )
      :
        module_->getItemFactory()->createStreamableBase64Binary(
          *stream_ptr, &stream_releaser, true
        )
    );
#endif
    return ItemSequence_t( new SingletonItemSequence( result ) );
  }
  catch ( std::exception const &e ) {
    // TODO
  }
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
                        DynamicContext const* ) const {
  // TODO
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
                            DynamicContext const* ) const {
  String const uri( get_string_arg( args, 0 ) );
  Item const options( get_item_arg( args, 1 ) );
  Item result( module_->getItemFactory()->createAnyURI( uri ) );
  return ItemSequence_t( new SingletonItemSequence( result ) );
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
