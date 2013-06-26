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

#ifndef ZORBA_JSON_LOADER_H
#define ZORBA_JSON_LOADER_H

// standard
#include <istream>
#include <new>
#include <utility>                          /* for pair */
#include <vector>

// Zorba
#include "store/api/item.h"
#include "util/json_parser.h"
#include "zorbatypes/zstring.h"

namespace zorba {
namespace json {

///////////////////////////////////////////////////////////////////////////////

class loader {
public:
  typedef parser::line_type line_type;
  typedef parser::column_type column_type;

  /**
   * Constructs a %loader.
   *
   * @param is The istream to read from.
   * @param allow_multiple If \c true, allow multiple top-level JSON items to
   * be returned.
   * @param strip_top_level_array If \c true, strips the top-level array, if
   * any.
   */
  loader( std::istream &is, 
          bool allow_multiple = false,
          bool strip_top_level_array = false,
          const store::Item* aDataguide = NULL);

  /**
   * Destroys this %loader.
   */
  ~loader();

  /**
   * Resets this %loader to its initial state.
   */
  void clear();

  /**
   * Gets the next Item, if any.
   *
   * @param result A pointer to the Item to receive the Item.
   * @return Returns \c true only if an Item was gotten.
   */
  bool next( store::Item_t *result );

  /**
   * Sets the file location.
   *
   * @param file The source file name.
   * @param line The source line number.
   * @param col  The source column number.
   */
  void set_loc( char const *file, line_type line, column_type col ) {
    parser_.set_loc( file, line, col );
  }

private:
  typedef std::vector<store::Item_t> json_array_type;

  struct json_object_type {
    std::vector<store::Item_t> keys_;
    std::vector<store::Item_t> values_;
  };

  struct stack_element {
    enum type {
      no_type,
      array_type,
      object_type,
      key_type
    };
    type const type_;
    union {
      json_array_type *array_;
      json_object_type *object_;
      store::Item *key_;
    };

    stack_element( type = no_type );
    void destroy();
  };

  typedef std::stack<stack_element> stack_type;
  stack_type stack_;

  void add_value( store::Item_t const& );
  void clear_stack();

  stack_element& push( stack_element::type t ) {
    //
    // We push in this convoluted manner since we can't use C++11 rvalue
    // references.
    //
    stack_.push( stack_element() );
    return *new( &stack_.top() ) stack_element( t );
  }

  parser parser_;
  bool const strip_top_level_array_;
  bool stripped_top_level_array_;
  const store::Item* dataguide;
};

///////////////////////////////////////////////////////////////////////////////

} // namespace json
} // namespace zorba

#endif /* ZORBA_JSON_LOADER_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
