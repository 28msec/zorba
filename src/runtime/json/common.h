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

#ifndef ZORBA_RUNTIME_JSON_COMMON_H
#define ZORBA_RUNTIME_JSON_COMMON_H

#include <iostream>
#include <stack>

#include "diagnostics/xquery_exception.h"
#include "store/api/item.h"
#include "store/api/item_factory.h"
#include "util/indent.h"
#include "util/json_parser.h"
#include "util/omanip.h"
#include "zorbatypes/zstring.h"

#define ZORBA_DEBUG_JSON 0

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

typedef std::stack<store::Item*> item_stack_type;

enum parse_state {
  in_array,
  in_object
};

typedef std::stack<int> state_stack_type;

namespace whitespace {
  enum type {
    none,
    some,
    indent
  };
}

#define if_indent(WS,FN) if_do( (WS) == whitespace::indent, FN )

///////////////////////////////////////////////////////////////////////////////

bool get_attribute_value( store::Item_t const &element, char const *att_name,
                          zstring *att_value );

inline void set_data( XQueryException *xe, json::exception const &je ) {
  set_data( *xe, je.get_loc() );
}

typedef std::ostream& (*std_omanip_type)(std::ostream&);

///////////////////////////////////////////////////////////////////////////////

#define IN_STATE(S) ztd::top_stack_equals( state_stack, (S) )

#if ZORBA_DEBUG_JSON

std::ostream& operator<<( std::ostream &o, parse_state s );

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
# define POP_ITEM()     cur_item = ztd::pop_stack( item_stack )
# define PUSH_STATE(S)  state_stack.push( S )
# define POP_STATE()    state_stack.pop()

#endif /* ZORBA_DEBUG_JSON */

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
#endif /* ZORBA_RUNTIME_JSON_COMMON_H */
/* vim:set et sw=2 ts=2: */
