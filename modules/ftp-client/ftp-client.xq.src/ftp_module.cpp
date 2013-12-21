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

// Zorba
#include <zorba/zorba.h>

// local
#include "ftp_functions.h"
#include "ftp_module.h"

namespace zorba {
namespace ftp_client {

///////////////////////////////////////////////////////////////////////////////

module::module() {
  item_factory_ = 0;
}

module::~module() {
  for ( func_map_type::const_iterator i = func_map_.begin();
        i != func_map_.end(); ++i ) {
    delete i->second;
  }
}

void module::destroy() {
  delete this;
}

ExternalFunction* module::getExternalFunction( String const &local_name ) {
  ExternalFunction *&f = func_map_[ local_name ];
  if ( !f ) {
    if ( local_name == "connect" )
      f = new connect_function( this );
    else if ( local_name == "get-binary" )
      f = new get_binary_function( this );
    else if ( local_name == "get-text" )
      f = new get_text_function( this );
    else if ( local_name == "put-binary" )
      f = new put_binary_function( this );
    else if ( local_name == "put-text" )
      f = new put_text_function( this );
  }
  return f;
}

ItemFactory* module::getItemFactory() const {
  if ( !item_factory_ )
    item_factory_ = Zorba::getInstance(0)->getItemFactory();
  return item_factory_;
}

String module::getURI() const {
  static String const uri( "http://zorba.io/modules/ftp-client" );
  return uri;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace ftp_client
} // namespace zorba

#ifdef WIN32
# define DLL_EXPORT __declspec(dllexport)
#else
# define DLL_EXPORT __attribute__ ((visibility("default")))
#endif /* WIN32 */

extern "C" DLL_EXPORT zorba::ExternalModule* createModule() {
  return new zorba::ftp_client::module();
}

/* vim:set et sw=2 ts=2: */
