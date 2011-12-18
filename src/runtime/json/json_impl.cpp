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

#include <zorba/diagnostic_list.h>

#include "runtime/json/json.h"
#include "store/api/item_factory.h"
#include "system/globalenv.h"
#include "types/root_typemanager.h"
#include "util/ascii_util.h"
#include "util/cxx_util.h"
#include "util/json_parser.h"
#include "util/stl_util.h"

#define JSON_NS "http://www.zorba-xquery.com/modules/converters/json"

#define DEBUG_JSON 0

using namespace std;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

enum state {
  in_array,
  in_object
};

typedef stack<store::Item*> item_stack_type;
typedef stack<int> state_stack_type;

#if DEBUG_JSON

ostream& operator<<( ostream &o, state s ) {
  static char const *const string_of[] = {
    "in_array",
    "in_object"
  };
  return o << string_of[ s ];
}

# define PUSH_ITEM(I)                                                     \
    do {                                                                  \
      cout << __LINE__ << ":PUSH_ITEM( " << (I)->show() << " )" << endl;  \
      item_stack.push( (I).getp() );                                      \
    } while (0)

# define POP_ITEM()                               \
    do {                                          \
      cout << __LINE__ << ":POP_ITEM()" << endl;  \
      cur_item = ztd::pop_stack( item_stack );    \
    } while (0)

# define PUSH_STATE(S) \
    do {                                                          \
      cout << __LINE__ << ":PUSH_STATE( " << (S) << " )" << endl; \
      state_stack.push( S );                                      \
    } while (0)

# define POP_STATE()                              \
    do {                                          \
      cout << __LINE__ << ":POP_STATE()" << endl; \
      state_stack.pop();                          \
    } while (0)                                   \

#else

# define PUSH_ITEM(I)   item_stack.push( (I).getp() )
# define POP_ITEM()     cur_item = ztd::pop_stack( item_stack );
# define PUSH_STATE(S)  state_stack.push( S )
# define POP_STATE()    state_stack.pop();

#endif /* DEBUG_JSON */

static void add_type_attribute( store::Item *parent, char const *value ) {
  store::Item_t junk_item, att_name, type_name, value_item;
  GENV_ITEMFACTORY->createQName( att_name, "", "", "type" );
  type_name = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
  zstring value_string( value );
  GENV_ITEMFACTORY->createString( value_item, value_string );
  GENV_ITEMFACTORY->createAttributeNode(
    junk_item, parent, att_name, type_name, value_item
  );
}

#define ADD_TYPE_ATTRIBUTE(T)             \
  do {                                    \
    if ( needs_type_attribute ) {         \
      add_type_attribute( cur_item, T );  \
      needs_type_attribute = false;       \
    }                                     \
  } while (0)

static void add_item_element( item_stack_type &item_stack,
                              state_stack_type &state_stack,
                              store::Item_t &cur_item,
                              char const *type ) {
  if ( !state_stack.empty() && state_stack.top() == in_array ) {
    store::Item_t element_name, type_name;
    zstring base_uri;
    store::NsBindings ns_bindings;
    GENV_ITEMFACTORY->createQName( element_name, JSON_NS, "", "item" );
    type_name = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
    GENV_ITEMFACTORY->createElementNode(
      cur_item, item_stack.top(),
      element_name, type_name, false, false, ns_bindings, base_uri
    );
    add_type_attribute( cur_item.getp(), type );
  }
}

#define ADD_ITEM_ELEMENT(T) \
  add_item_element( item_stack, state_stack, cur_item, T );

bool JSONParseInternal::nextImpl( store::Item_t& result,
                                  PlanState &planState ) const {
  store::Item_t cur_item;
  istringstream iss;
  string json_string;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, planState );

  if ( consumeNext( cur_item, theChildren[0], planState ) ) {
    istream *is;
    if ( cur_item->isStreamable() ) {
      is = &cur_item->getStream();
    } else {
      zstring json_zstring;
      cur_item->getStringValue2( json_zstring );
      // This string copying is inefficient, but I can't see another way.
      json_string = json_zstring.str();
      iss.str( json_string );
      is = &iss;
    }

    try {
      state_stack_type state_stack;

      store::Item_t junk_item, value_item;
      store::Item_t att_name, element_name, type_name;

      zstring base_uri;
      item_stack_type item_stack;
      bool needs_type_attribute = false;
      bool next_string_is_key = false;
      store::NsBindings ns_bindings;
      zstring value;

      json::parser p( *is );
      p.set_loc(
        loc.getFilename().c_str(), loc.getLineBegin(), loc.getColumnBegin()
      );
      json::token t;

      while ( p.next( &t ) ) {
        if ( !result ) {
          GENV_ITEMFACTORY->createQName( element_name, JSON_NS, "", "json" );
          type_name = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
          GENV_ITEMFACTORY->createElementNode(
            cur_item, nullptr,
            element_name, type_name, false, false, ns_bindings, base_uri
          );
          result = cur_item;
          needs_type_attribute = true;
        }

        switch ( t.get_type() ) {

          case '[':
            PUSH_ITEM( cur_item );
            ADD_TYPE_ATTRIBUTE( "array" );
            ADD_ITEM_ELEMENT( "array" );
            PUSH_STATE( in_array );
            break;

          case '{':
            PUSH_ITEM( cur_item );
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
            GENV_ITEMFACTORY->createTextNode( junk_item, cur_item, value );
            break;

          case json::token::string:
            ADD_TYPE_ATTRIBUTE( "string" );
            value = t.get_value();
  #if 0
            ascii::replace_all( value, "\"", 1, "\\\"", 2 );
            ascii::replace_all( value, "\\", 1, "\\\\", 2 );
            ascii::replace_all( value, "\b", 1, "\\b", 2 );
            ascii::replace_all( value, "\f", 1, "\\f", 2 );
            ascii::replace_all( value, "\n", 1, "\\n", 2 );
            ascii::replace_all( value, "\r", 1, "\\r", 2 );
            ascii::replace_all( value, "\t", 1, "\\t", 2 );
  #endif

            if ( next_string_is_key ) {
              // <pair name="..." ...>
              GENV_ITEMFACTORY->createQName(
                element_name, JSON_NS, "", "pair"
              );
              type_name = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
              GENV_ITEMFACTORY->createElementNode(
                cur_item, item_stack.top(),
                element_name, type_name, false, false, ns_bindings, base_uri
              );

              GENV_ITEMFACTORY->createQName( att_name, "", "", "name" );
              type_name = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
              GENV_ITEMFACTORY->createString( value_item, value );
              GENV_ITEMFACTORY->createAttributeNode(
                junk_item, cur_item, att_name, type_name, value_item
              );

              needs_type_attribute = true;
              next_string_is_key = false;
            } else {
              ADD_ITEM_ELEMENT( "string" );
              GENV_ITEMFACTORY->createTextNode( junk_item, cur_item, value );
            }
            break;

          case 'F':
          case 'T':
            ADD_TYPE_ATTRIBUTE( "boolean" );
            ADD_ITEM_ELEMENT( "boolean" );
            value = t.get_type() == 'F' ? "false" : "true";
            GENV_ITEMFACTORY->createTextNode( junk_item, cur_item, value );
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
    }
    catch ( json::illegal_character const &e ) {
      throw XQUERY_EXCEPTION(
        zerr::ZJPE0001_ILLEGAL_CHARACTER,
        ERROR_PARAMS( e.get_char() ),
        ERROR_LOC( e.get_loc() )
      );
    }
    catch ( json::illegal_codepoint const &e ) {
      throw XQUERY_EXCEPTION(
        zerr::ZJPE0002_ILLEGAL_CODEPOINT,
        ERROR_PARAMS( e.get_codepoint() ),
        ERROR_LOC( e.get_loc() )
      );
    }
    catch ( json::illegal_escape const &e ) {
      throw XQUERY_EXCEPTION(
        zerr::ZJPE0003_ILLEGAL_ESCAPE,
        ERROR_PARAMS( e.get_escape() ),
        ERROR_LOC( e.get_loc() )
      );
    }
    catch ( json::illegal_literal const &e ) {
      throw XQUERY_EXCEPTION(
        zerr::ZJPE0004_ILLEGAL_LITERAL,
        ERROR_LOC( e.get_loc() )
      );
    }
    catch ( json::illegal_number const &e ) {
      throw XQUERY_EXCEPTION(
        zerr::ZJPE0005_ILLEGAL_NUMBER,
        ERROR_LOC( e.get_loc() )
      );
    }
    catch ( json::unexpected_token const &e ) {
      throw XQUERY_EXCEPTION(
        zerr::ZJPE0006_UNEXPECTED_TOKEN,
        ERROR_PARAMS( e.get_token() ),
        ERROR_LOC( e.get_loc() )
      );
    }
    catch ( json::unterminated_string const &e ) {
      throw XQUERY_EXCEPTION(
        zerr::ZJPE0007_UNTERMINATED_STRING,
        ERROR_LOC( e.get_loc() )
      );
    }

#if DEBUG_JSON
    cout << "----- RESULT -----\n" << result->show() << endl;
#endif /* DEBUG_JSON */

    STACK_PUSH( !!result, state );
  } // if ( consumeNext( ...
  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

static void find_attribute( store::Item_t const &element,
                            char const *wanted_att_name,
                            zstring *att_value ) {
  store::Iterator_t i( element->getAttributes() );
  bool found = false;
  i->open();
  store::Item_t att_item;
  while ( i->next( att_item ) ) {
    store::Item const *const att_name = att_item->getNodeName();
    if ( att_name->getStringValue() == wanted_att_name ) {
      att_item->getStringValue2( *att_value );
      found = true;
      break;
    }
  }
  i->close();
  if ( !found )
    throw XQUERY_EXCEPTION(
      zerr::ZJSE0002_ELEMENT_MISSING_ATTRIBUTE,
      ERROR_PARAMS( element->getNodeName()->getStringValue(), wanted_att_name )
    );
}

static json::type get_json_type( store::Item_t const &element,
                                 bool allow_all_types = true ) {
  zstring att_value;
  find_attribute( element, "type", &att_value );
  if ( att_value == "array" )
    return json::array;
  if ( att_value == "object" )
    return json::object;
  if ( allow_all_types ) {
    if ( att_value == "boolean" )
      return json::boolean;
    if ( att_value == "null" )
      return json::null;
    if ( att_value == "number" )
      return json::number;
    if ( att_value == "string" )
      return json::string;
  }
  throw XQUERY_EXCEPTION(
    zerr::ZJSE0003_BAD_ATTRIBUTE_VALUE,
    ERROR_PARAMS( att_value, "type" )
  );
}

inline bool is_element( store::Item_t const &item ) {
  return  item->isNode() &&
          item->getNodeKind() == store::StoreConsts::elementNode;
}

static void serialize_children( store::Item_t const &parent,
                                json::type parent_type, ostream &o );

static void serialize_json_element( store::Item_t const &element, ostream &o ) {
  zstring const element_name( element->getNodeName()->getStringValue() );
  if ( element_name != "json" )
    throw XQUERY_EXCEPTION(
      zerr::ZJSE0004_BAD_ELEMENT,
      ERROR_PARAMS( element_name, "json" )
    );

  json::type const t = get_json_type( element, false );

  o << "<json type=\"" << json::type_string_of[ t ]
    << "\" xmlns=\"" JSON_NS "\">";
  serialize_children( element, t, o );
  o << "</json>";
}

static void serialize_item_element( store::Item_t const &element, ostream &o ) {
  zstring const element_name( element->getNodeName()->getStringValue() );
  if ( element_name != "item" )
    throw XQUERY_EXCEPTION(
      zerr::ZJSE0005_BAD_CHILD_ELEMENT,
      ERROR_PARAMS( element_name, "array", "item" )
    );

  json::type const t = get_json_type( element );

  o << "<item type=\"" << json::type_string_of[ t ] << "\">";
  serialize_children( element, t, o );
  o << "</item>";
}

static void serialize_pair_element( store::Item_t const &element, ostream &o ) {
  zstring const element_name( element->getNodeName()->getStringValue() );
  if ( element_name != "pair" )
    throw XQUERY_EXCEPTION(
      zerr::ZJSE0005_BAD_CHILD_ELEMENT,
      ERROR_PARAMS( element_name, "object", "pair" )
    );

  zstring name_att_value;
  find_attribute( element, "name", &name_att_value );
  json::type const t = get_json_type( element );

  o << "<pair name=\"" << name_att_value
    << "\" type=\"" << json::type_string_of[ t ] << "\">";
  serialize_children( element, t, o );
  o << "</pair>";
}

static void serialize_children( store::Item_t const &parent,
                                json::type parent_type, ostream &o ) {
  store::Iterator_t i = parent->getChildren();
  i->open();
  store::Item_t child;
  while ( i->next( child ) ) {
    switch ( child->getNodeKind() ) {

      case store::StoreConsts::elementNode:
        switch ( parent_type ) {
          case json::none:
            serialize_json_element( child, o );
          case json::array:
            serialize_item_element( child, o );
            break;
          case json::object:
            serialize_pair_element( child, o );
            break;
          default:
            throw XQUERY_EXCEPTION(
              zerr::ZJSE0006_NO_ELEMENT_CHILD,
              ERROR_PARAMS( json::type_string_of[ parent_type ] )
            );
        }
        break;

      case store::StoreConsts::textNode:
        switch ( parent_type ) {
          case json::boolean:
          case json::number:
          case json::string:
            // TODO: should the string be parsed for validity?
            o << child->getStringValue();
            break;
          default:
            throw XQUERY_EXCEPTION(
              zerr::ZJSE0007_NO_TEXT_CHILD,
              ERROR_PARAMS( json::type_string_of[ parent_type ] )
            );
        }
        break;

      default:
        // do nothing
        break;
    } // switch
  } // while
  i->close();
}

bool JSONSerializeInternal::nextImpl( store::Item_t& result,
                                      PlanState &planState ) const {
  store::Item_t cur_item;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, planState );

  if ( consumeNext( cur_item, theChildren[0], planState ) ) {
    try {
      ostringstream oss;
      switch ( cur_item->getNodeKind() ) {
        case store::StoreConsts::documentNode:
          serialize_children( cur_item, json::none, oss );
        case store::StoreConsts::elementNode:
          serialize_json_element( cur_item, oss );
          break;
        default:
          throw XQUERY_EXCEPTION(
            zerr::ZJSE0001_NOT_DOCUMENT_OR_ELEMENT_NODE,
            ERROR_LOC( loc )
          );
      }
      string const temp( oss.str() );
      zstring temp2( temp );
      GENV_ITEMFACTORY->createString( result, temp2 );
    }
    catch ( ZorbaException &e ) {
      set_source( e, loc );
      throw;
    }
    STACK_PUSH( true, state );
  } // if ( consumeNext( ...
  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

} /* namespace zorba */
/* vim:set et sw=2 ts=2: */
