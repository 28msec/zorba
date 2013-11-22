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

#include <zorba/internal/unique_ptr.h>

#include "store/api/item.h"
#include "util/hash/hash.h"
#include "util/unordered_map.h"
#include "util/unordered_set.h"
#include "zorbatypes/zstring.h"

namespace zorba {
namespace jsound {

class type;

///////////////////////////////////////////////////////////////////////////////

class validator {
public:
  /**
   * Constructs a %validator.
   *
   * @param jsd The JSound (JSON Schema Document) to load and utlimiately
   * validate against.
   */
  validator( store::Item_t const &jsd );

  /**
   * Destroys a %validator.
   */
  ~validator();

  /**
   * Gets the namespace of the loaded JSound.
   *
   * @return Returns said namespace.
   */
  zstring const& get_namespace() const {
    return namespace_;
  }

  /**
   * Validates a JSON object against a type of a JSound schema.
   *
   * @param json The JSON object to validate.
   * @param type_name The type to validate \a json against.
   * @param result The validated JSON object.
   * @return Returns \c true only if \a json is valid.
   */
  bool annotate( store::Item_t const &json, char const *type_name,
                 store::Item_t *result ) const;

  /**
   * Validates a JSON object against a type of a JSound schema.
   *
   * @param json The JSON object to validate.
   * @param type_name The type to validate \a json against.
   * @param result The validated JSON object.
   * @return Returns \c true only if \a json is valid.
   */
  bool validate( store::Item_t const &json, char const *type_name ) const;

  /**
   * Validates a JSON object against a type of a JSound schema.
   *
   * @tparam StringType The string type for \a type_name.
   * @param json The JSON object to validate.
   * @param type_name The type to validate \a json against.
   * @param result The validated JSON object.
   * @return Returns \c true only if \a json is valid.
   */
  template<class StringType>
  typename std::enable_if<ZORBA_HAS_C_STR(StringType),bool>::type
  validate( store::Item_t const &json, StringType const &type_name ) const {
    return validate( json, type_name.c_str() );
  }

private:
  // set of all imported namespaces
  typedef std::unordered_set<zstring> namespace_set;
  namespace_set namespaces_;

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

  type const* find_or_create_type( store::Item_t const& );
  type const* find_type( zstring const &type_name,
                         bool not_found_error = true ) const;
  type const* fq_find_type( zstring *type_name,
                            bool not_found_error = true ) const;
  void fq_type_name( zstring *type_name, zstring *uri = nullptr ) const;

  void load_import( store::Item_t const& );
  void load_imports( store::Item_t const& );
  std::unique_ptr<type> load_kind( store::Item_t const& );
  void load_namespace( store::Item_t const& );
  void load_top_type( store::Item_t const& );
  std::unique_ptr<type> load_type( store::Item_t const& );
  void load_types( store::Item_t const& );

  friend class array_type;
  friend class atomic_type;
  friend class object_type;
  friend class type;
  friend class union_type;
};

///////////////////////////////////////////////////////////////////////////////

} // jsound
} // namespace zorba

/* vim:set et sw=2 ts=2: */
