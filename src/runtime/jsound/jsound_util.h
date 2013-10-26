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

#include <map>
#include <vector>

#include "store/api/item.h"

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

class JSound {
public:
  class array;
  class atomic;
  class object;

  union value {
    array *array_val;
    atomic *atomic_val;
    object *object_val;
  };

  struct array {
    typedef std::vector<value> type;
    type elements;
  };

  struct atomic {
    // TODO
  };

  struct object {
    typedef std::map<zstring,value> map_type;
    map_type map;
  };

  JSound( store::Item_t const &jsd );

  void validate( store::Item_t const &json, zstring const &type_name,
                 store::Item_t *result ) const;

private:
  void load_about( store::Item_t const& );
  void load_array_type( store::Item_t const& );
  void load_atomic_type( store::Item_t const& );
  void load_baseType( store::Item_t const& );
  void load_constraints( store::Item_t const& );
  void load_content_array( store::Item_t const& );
  void load_content_object( store::Item_t const& );
  void load_enumeration( store::Item_t const& );
  void load_explicitTimezone( store::Item_t const& );
  void load_field_descriptor( store::Item_t const& );
  void load_fractionDigits( store::Item_t const& );
  void load_imports( store::Item_t const& );
  void load_kind( store::Item_t const& );
  void load_length( store::Item_t const& );
  void load_maxExclusive( store::Item_t const& );
  void load_maxInclusive( store::Item_t const& );
  void load_maxLength( store::Item_t const& );
  void load_minExclusive( store::Item_t const& );
  void load_minInclusive( store::Item_t const& );
  void load_minLength( store::Item_t const& );
  void load_name( store::Item_t const& );
  void load_namespace( store::Item_t const& );
  void load_object_type( store::Item_t const& );
  void load_open( store::Item_t const& );
  void load_pattern( store::Item_t const& );
  void load_totalDigits( store::Item_t const& );
  void load_type( store::Item_t const& );
  void load_types( store::Item_t const& );
  void load_union_type( store::Item_t const& );
};

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba

/* vim:set et sw=2 ts=2: */
