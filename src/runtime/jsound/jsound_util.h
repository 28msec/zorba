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

#include "stdafx.h"

#include <vector>

#include "store/api/item.h"
#include "util/hash/hash.h"
#include "util/unordered_map.h"
#include "zorbatypes/zstring.h"

namespace zorba {

class static_context;

namespace jsound {

struct type;

///////////////////////////////////////////////////////////////////////////////

class schema {
public:
  /**
   * Constructs a %schema.
   *
   * @param jsd The JSound (JSON Schema Document) to load and utlimiately
   * annotate or validate against.
   */
  schema( store::Item_t const &jsd );

  /**
   * Destroys a %schema.
   */
  ~schema();

  /**
   * Gets the namespace of the loaded JSound schema.
   *
   * @return Returns said namespace.
   */
  zstring const& get_namespace() const {
    return namespace_;
  }

  /**
   * Validates a JSON object against a type of a JSound schema.
   * If \a result is not null, then it is set to a validated instance
   * of \a json.
   * If \a json is valid, then \a result will be a copy of \a json
   * with the default values, if any, filled in.
   * If \a json is not valid, then \a result will be a copy of \a json
   * except each invalid item will be replaced by an object of the form:
   *  <pre>
   *    {
   *      "$invalid" : true,
   *      "$expected" : type-name,
   *      "$value" : invalid-value,
   *      "$reason" : "reason the item is invalid"
   *    }
   *  </pre>
   *
   * @param json The JSON object to validate.
   * @param type_name The type to validate \a json against.
   * @param cast If \c true, attempt to cast values within \a json to those
   * specified by this schema.
   * @param result A pointer to an item to receive the validated JSON object or
   * null for none.
   * @return Returns \c true only if \a json is valid against this schema.
   */
  bool validate( store::Item_t const &json, char const *type_name, bool cast,
                 store::Item_t *result = nullptr ) const;

  /**
   * Validates a JSON object against a type of a JSound schema.
   * If \a result is not null, then it is set to a validated instance
   * of \a json.
   * If \a json is valid, then \a result will be a copy of \a json
   * with the default values, if any, filled in.
   * If \a json is not valid, then \a result will be a copy of \a json
   * except each invalid item will be replaced by an object of the form:
   *  <pre>
   *    {
   *      "$invalid" : true,
   *      "$expected" : type-name,
   *      "$value" : invalid-value,
   *      "$reason" : "reason the item is invalid"
   *    }
   *  </pre>
   *
   * @tparam StringType The string type for \a type_name.
   * @param json The JSON object to validate.
   * @param type_name The type to validate \a json against.
   * @param cast If \c true, attempt to cast values within \a json to those
   * specified by this schema.
   * @param result A pointer to an item to receive the validated JSON object or
   * null for none.
   * @return Returns \c true only if \a json is valid.
   */
  template<class StringType>
  typename std::enable_if<ZORBA_HAS_C_STR(StringType),bool>::type
  validate( store::Item_t const &json, StringType const &type_name, bool cast,
            store::Item_t *result = nullptr ) const {
    return validate( json, type_name.c_str(), cast, result );
  }

private:
  // map of all imported namespaces -> locations
  typedef std::unordered_map<zstring,zstring> namespace_map;
  namespace_map namespaces_;

  // map of all prefixes -> namespaces
  typedef std::unordered_map<zstring,zstring> prefix_namespace_map;
  prefix_namespace_map prefix_ns_;

  // list of all types
  typedef std::vector<type const*> type_list;
  type_list types_;

  // map of all fully-qualified type names (Q{uri}local) -> types
  typedef std::unordered_map<zstring,type const*> name_type_map;
  name_type_map name_type_;

  // namespace of the loaded schema
  zstring namespace_;

  /**
   * Finds or creates a new type.
   *
   * @param type_item If an xs:string, it's the name of the type to find;
   * if an object, it's an inline type.
   * @return Returns the existing or new type.
   */
  type const* find_or_create_type( store::Item_t const &type_item );

  /**
   * Attempts to find a type.
   *
   * @param type_name The type-name to find.
   * @param not_found_error If \c true and the type is not found,
   * throws an exception; otherwise returns \c null.
   * @return Returns the type for \a type_name or \c null if not found
   * (and \a not_found_error is \c false).
   */
  type const* find_type( zstring const &type_name,
                         bool not_found_error = true ) const;

  /**
   * Fully-qualify a type-name, then attempt to find the type.
   *
   * @param type_name A pointer to the type-name to fully qualify.
   * @param not_found_error If \c true and the type is not found,
   * throws an exception; otherwise returns \c null.
   * @return Returns the type for \a type_name or \c null if not found
   * (and \a not_found_error is \c false).
   */
  type const* fq_find_type( zstring *type_name,
                            bool not_found_error = true ) const;

  /**
   * Fully-qualify a type-name.
   *
   * @param type_name A pointer to the type-name to fully qualify.
   * @param uri A pointer to receive the URI for the namespace, if any.
   */
  void fq_type_name( zstring *type_name, zstring *uri = nullptr ) const;

  /**
   * Import all of another schema's types into this schema.
   *
   * @param ns The namespace URI of the other schema.
   * @param from A pointer to the schema to import from.  It's types are moved,
   * not copied; so when done, it will be empty.
   */
  void import( zstring const &ns, schema *from );

  /**
   * Creates a new type.
   *
   * @param kind_item The item (that must be a string) containing the kind of
   * item to create: "atomic", "array", "object", or "union".
   * @return Returns the new type.
   */
  type* new_type( store::Item_t const &kind_item );

  void load_import( store::Item_t const& );
  void load_imports( store::Item_t const& );
  void load_namespace( store::Item_t const& );
  void load_top_type( store::Item_t const& );
  type const* load_type( store::Item_t const& );
  void load_types( store::Item_t const& );

  friend class array_type;
  friend class atomic_type;
  friend class object_type;
  friend class type;
  friend class union_type;

  // Forbid these since we'd have to copy the entire type* tree and there's no
  // need for this now.
  schema( schema const& );
  schema& operator=( schema const& );
};

///////////////////////////////////////////////////////////////////////////////

} // jsound
} // namespace zorba

/* vim:set et sw=2 ts=2: */
