/*
 * Copyright 2006-2011 The FLWOR Foundation.
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
#include "stdafx.h"

#include <map>
#include <sstream>

#include <zorba/diagnostic_list.h>
#include <zorba/internal/cxx_util.h>

#include "runtime/json/json.h"
#include "store/api/item_factory.h"
#include "system/globalenv.h"
#include "util/ascii_util.h"
#include "util/mem_streambuf.h"
#include "util/stream_util.h"

#include "jsonml_array.h"
#include "snelson.h"

using namespace std;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

typedef map<zstring,zstring> options_type;

static void get_options( store::Item_t const &options_object,
                         options_type *options ) {
  ZORBA_ASSERT( options_object->getKind() == store::Item::OBJECT );
  store::Iterator_t i( options_object->getObjectKeys() );
  i->open();
  store::Item_t opt_key;
  while ( i->next( opt_key ) ) {
    zstring const opt_name( opt_key->getStringValue() );
    store::Item_t const opt_value( options_object->getObjectValue( opt_key ) );
    (*options)[ opt_name ] = opt_value->getStringValue();
  }
  i->close();
}

///////////////////////////////////////////////////////////////////////////////

bool JSONtoXMLInternal::nextImpl( store::Item_t& result,
                                  PlanState &planState ) const {
  store::Item_t item;
  options_type options;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, planState );

  ZORBA_ASSERT( theChildren.size() == 2 );
  consumeNext( item, theChildren[1], planState );
  get_options( item, &options );

  consumeNext( item, theChildren[0], planState );
  result = nullptr;

  { // local scope
  options_type::mapped_type const &format = options[ "json-format" ];
  ZORBA_ASSERT( !format.empty() );
  if ( format == "Snelson" )
    snelson::json_to_xml( item, &result );
  else if ( format == "JsonML-array" )
    jsonml_array::json_to_xml( item, &result );
  else
    ZORBA_ASSERT( false );
  } // local scope

  STACK_PUSH( !!result, state );
  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

bool XMLtoJSONInternal::nextImpl( store::Item_t& result,
                                  PlanState &planState ) const {
  store::Item_t xml_item;
  options_type options;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, planState );

  ZORBA_ASSERT( theChildren.size() == 2 );
  consumeNext( xml_item, theChildren[1], planState );
  get_options( xml_item, &options );

  consumeNext( xml_item, theChildren[0], planState );
  try {
    options_type::mapped_type const &format_opt = options[ "json-format" ];
    ZORBA_ASSERT( !format_opt.empty() );

    switch ( xml_item->getNodeKind() ) {
      case store::StoreConsts::documentNode:
      case store::StoreConsts::elementNode:
        if ( format_opt == "Snelson" )
          snelson::xml_to_json( xml_item, &result );
        else if ( format_opt == "JsonML-array" )
          jsonml_array::xml_to_json( xml_item, &result );
        else
          ZORBA_ASSERT( false );
        break;
      default:
        throw XQUERY_EXCEPTION(
          zerr::ZJSE0001_NOT_DOCUMENT_OR_ELEMENT_NODE,
          ERROR_LOC( loc )
        );
    }
  }
  catch ( ZorbaException &e ) {
    set_source( e, loc );
    throw;
  }

  STACK_PUSH( !!result, state );
  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
