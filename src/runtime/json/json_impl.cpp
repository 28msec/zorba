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

#include <sstream>

#include "runtime/json/json.h"
#include "store/api/item_factory.h"
#include "system/globalenv.h"
#include "types/root_typemanager.h"
#include "util/ascii_util.h"
#include "util/cxx_util.h"
#include "util/json_parser.h"

using namespace std;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

bool JSONParseInternal::nextImpl( store::Item_t& result,
                                  PlanState &planState ) const {
  store::Item_t cur_item;
  zstring json_string;
  istringstream iss;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, planState );

  if ( consumeNext( cur_item, theChildren[0].getp(), planState ) ) {
    istream *is;
    if ( cur_item->isStreamable() ) {
      is = &cur_item->getStream();
    } else {
      cur_item->getStringValue2( json_string );
      iss.str( json_string.str() ); // Does this copy this string?
      is = &iss;
    }

    { // local scope
    enum state {
      in_array,
      in_object
    };
    stack<int> state_stack;

    store::Item_t junk_item, root_item, value_item;
    store::Item_t type_name;

    stack<store::Item_t> item_stack;

    store::Item_t item_elt_name;
    GENV_ITEMFACTORY->createQName( item_elt_name, "", "", "item" );

    store::Item_t json_elt_name;
    GENV_ITEMFACTORY->createQName( json_elt_name, "", "", "json" );

    store::Item_t pair_elt_name;
    GENV_ITEMFACTORY->createQName( pair_elt_name, "", "", "pair" );

    store::Item_t type_att_name;
    GENV_ITEMFACTORY->createQName( type_att_name, "", "", "type" );

    zstring base_uri;
    bool next_string_is_key = false;
    store::NsBindings ns_bindings;
    zstring value;

    json::parser p( *is );
    json::token t;
    while ( p.next( &t ) ) {
      switch ( t.get_type() ) {

        case '[':                       // <json type="array">
          type_name = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
          GENV_ITEMFACTORY->createElementNode(
            cur_item,
            item_stack.empty() ? nullptr : item_stack.top().getp(),
            json_elt_name, type_name, false, false, ns_bindings, base_uri
          );

          value = "array";
          GENV_ITEMFACTORY->createString( value_item, value );

          type_name = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
          GENV_ITEMFACTORY->createAttributeNode(
            junk_item, cur_item, type_att_name, type_name, value_item
          );
          item_stack.push( cur_item );
          if ( !root_item )
            root_item = cur_item;
          state_stack.push( in_array );
          break;

        case '{':                       // <json type="object">
          // TODO
          state_stack.push( in_object );
          next_string_is_key = true;
          break;

        case ']':                       // </json>
        case '}':
          item_stack.pop();
          state_stack.pop();
          break;

        case ',':
          next_string_is_key = (state_stack.top() == in_object);
          break;

        case json::token::number:
          value = t.get_value();
          GENV_ITEMFACTORY->createTextNode(
            junk_item, item_stack.top().getp(), value
          );
          break;

        case json::token::string:
          value = t.get_value();
          ascii::replace_all( value, "\"", 1, "\\\"", 2 );

          if ( next_string_is_key ) {
            // TODO
          } else {
            GENV_ITEMFACTORY->createTextNode(
              junk_item, item_stack.top().getp(), value
            );
          }
          next_string_is_key = false;
          break;

        case 'F':
          value = "false";
          GENV_ITEMFACTORY->createTextNode(
            junk_item, item_stack.top().getp(), value
          );
          break;

        case 'T':
          value = "true";
          GENV_ITEMFACTORY->createTextNode(
            junk_item, item_stack.top().getp(), value
          );
          break;

        case ':':
        case json::token::json_null:
        case json::token::none:
          break;
      } // switch
    } // while
    } // local scope

    STACK_PUSH( true, state );
  } // if ( consumeNext( ...
  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

bool JSONSerializeInternal::nextImpl( store::Item_t& result,
                                      PlanState &planState ) const {
  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, planState );

  STACK_PUSH( false, state );

  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

} /* namespace zorba */
/* vim:set et sw=2 ts=2: */
