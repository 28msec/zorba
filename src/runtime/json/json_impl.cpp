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

#define JSON_NS "http://www.zorba-xquery.com/modules/converters/json"

#define DEBUG_JSON 1

using namespace std;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

enum state {
  in_array,
  in_object,
  needs_type_attribute
};

typedef stack<store::Item_t> item_stack_type;
typedef stack<int> state_stack_type;

#if DEBUG_JSON

ostream& operator<<( ostream &o, state s ) {
  static char const *const string_of[] = {
    "in_array",
    "in_object",
    "needs_type_attribute"
  };
  return o << string_of[ s ];
}

# define PUSH_ITEM(I)                                                     \
    if (0) ; else {                                                       \
      cout << __LINE__ << ":PUSH_ITEM( " << (I)->show() << " )" << endl;  \
      item_stack.push( I );                                               \
    }

# define POP_ITEM() \
    cout << __LINE__ << ":POP_ITEM()" << endl

# define PUSH_STATE(S) \
    if (0) ; else {                                               \
      cout << __LINE__ << ":PUSH_STATE( " << (S) << " )" << endl; \
      state_stack.push( S );                                      \
    }

# define POP_STATE() \
    cout << __LINE__ << ":POP_STATE()" << endl

#else

# define PUSH_ITEM(I)   item_stack.push( I )
# define POP_ITEM()     item_stack.pop()
# define PUSH_STATE(S)  state_stack.push( S )
# define POP_STATE()    state_stack.pop()

#endif /* DEBUG_JSON */

static void add_type_attribute( store::Item *i, state_stack_type &state_stack,
                                char const *value ) {
  if ( !state_stack.empty() && state_stack.top() == needs_type_attribute ) {
    store::Item_t junk_item, att_name, type_name, value_item;
    GENV_ITEMFACTORY->createQName( att_name, "", "", "type" );
    type_name = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
    zstring value_string( value );
    GENV_ITEMFACTORY->createString( value_item, value_string );
    GENV_ITEMFACTORY->createAttributeNode(
      junk_item, i, att_name, type_name, value_item
    );
    POP_STATE();
  }
}

#define ADD_TYPE_ATTRIBUTE(T) \
  add_type_attribute( item_stack.top().getp(), state_stack, T )

static void add_item_element( item_stack_type &item_stack,
                              state_stack_type &state_stack,
                              char const *type ) {
  if ( !state_stack.empty() && state_stack.top() == in_array ) {
    store::Item_t new_item, element_name, type_name;
    zstring base_uri;
    store::NsBindings ns_bindings;
    GENV_ITEMFACTORY->createQName( element_name, JSON_NS, "", "item" );
    type_name = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
    GENV_ITEMFACTORY->createElementNode(
      new_item, item_stack.top().getp(),
      element_name, type_name, false, false, ns_bindings, base_uri
    );
    PUSH_ITEM( new_item );
    PUSH_STATE( needs_type_attribute );
    ADD_TYPE_ATTRIBUTE( type );
  }
}

#define ADD_ITEM_ELEMENT(T) \
  add_item_element( item_stack, state_stack, T );

bool JSONParseInternal::nextImpl( store::Item_t& result,
                                  PlanState &planState ) const {
  store::Item_t cur_item, result_item;
  istringstream iss;
  zstring json_zstring;
  string json_string;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, planState );

  if ( consumeNext( cur_item, theChildren[0].getp(), planState ) ) {
    istream *is;
    if ( cur_item->isStreamable() ) {
      is = &cur_item->getStream();
    } else {
      cur_item->getStringValue2( json_zstring );
      json_string = json_zstring.str();
      iss.str( json_string );
      is = &iss;
    }

    { // local scope
    state_stack_type state_stack;

    store::Item_t junk_item, value_item;
    store::Item_t att_name, element_name, type_name;

    zstring base_uri;
    stack<store::Item_t> item_stack;
    bool next_string_is_key = false;
    store::NsBindings ns_bindings;
    zstring value;

    json::parser p( *is );
    json::token t;
    while ( p.next( &t ) ) {
      if ( !result_item ) {
        GENV_ITEMFACTORY->createQName( element_name, JSON_NS, "", "json" );
        type_name = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
        GENV_ITEMFACTORY->createElementNode(
          result_item, nullptr,
          element_name, type_name, false, false, ns_bindings, base_uri
        );
        PUSH_ITEM( result_item );
        PUSH_STATE( needs_type_attribute );
      }

      switch ( t.get_type() ) {

        case '[':
          ADD_TYPE_ATTRIBUTE( "array" );
          ADD_ITEM_ELEMENT( "array" );
          PUSH_STATE( in_array );
          break;

        case '{':
          ADD_TYPE_ATTRIBUTE( "object" );
          ADD_ITEM_ELEMENT( "object" );
          PUSH_STATE( in_object );
          next_string_is_key = true;
          break;

        case ']':
        case '}':
          POP_ITEM();
          POP_STATE();
          break;

        case ',':
          next_string_is_key = (state_stack.top() == in_object);
          break;

        case json::token::number:
          ADD_TYPE_ATTRIBUTE( "number" );
          ADD_ITEM_ELEMENT( "number" );
          value = t.get_value();
          GENV_ITEMFACTORY->createTextNode(
            junk_item, item_stack.top().getp(), value
          );
          break;

        case json::token::string:
          ADD_TYPE_ATTRIBUTE( "string" );
          value = t.get_value();
          ascii::replace_all( value, "\"", 1, "\\\"", 2 );

          if ( next_string_is_key ) {
            // <pair name="..." ...>
            GENV_ITEMFACTORY->createQName( element_name, JSON_NS, "", "pair" );
            type_name = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
            GENV_ITEMFACTORY->createElementNode(
              cur_item, item_stack.top().getp(),
              element_name, type_name, false, false, ns_bindings, base_uri
            );

            GENV_ITEMFACTORY->createQName( att_name, "", "", "name" );
            type_name = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
            GENV_ITEMFACTORY->createString( value_item, value );
            GENV_ITEMFACTORY->createAttributeNode(
              junk_item, cur_item, att_name, type_name, value_item
            );
            PUSH_ITEM( cur_item );
            PUSH_STATE( needs_type_attribute );
          } else {
            ADD_ITEM_ELEMENT( "string" );
            GENV_ITEMFACTORY->createTextNode(
              junk_item, item_stack.top().getp(), value
            );
          }
          next_string_is_key = false;
          break;

        case 'F':
          ADD_TYPE_ATTRIBUTE( "boolean" );
          ADD_ITEM_ELEMENT( "boolean" );
          value = "false";
          GENV_ITEMFACTORY->createTextNode(
            junk_item, item_stack.top().getp(), value
          );
          break;

        case 'T':
          ADD_TYPE_ATTRIBUTE( "boolean" );
          ADD_ITEM_ELEMENT( "boolean" );
          value = "true";
          GENV_ITEMFACTORY->createTextNode(
            junk_item, item_stack.top().getp(), value
          );
          break;

        case json::token::json_null:
          ADD_TYPE_ATTRIBUTE( "null" );
          ADD_ITEM_ELEMENT( "null" );
          break;

        case ':':
        case json::token::none:
          break;

        default:
          assert( false );
      } // switch
    } // while
    } // local scope

#if DEBUG_JSON
    cout << "----- RESULT -----\n" << result_item->show() << endl;
#endif /* DEBUG_JSON */

    STACK_PUSH( result_item, state );
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
