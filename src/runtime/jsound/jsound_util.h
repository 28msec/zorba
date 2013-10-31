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

#include <zorba/internal/unique_ptr.h>

#include "store/api/item.h"
#include "util/unordered_map.h"

namespace zorba {
namespace jsound {

///////////////////////////////////////////////////////////////////////////////

struct enumeration {
  typedef store::Item_t value_type;
  typedef std::vector<value_type> content_type;
  content_type values_;
};

enum kind {
  k_none,
  k_array,
  k_atomic,
  k_object,
  k_union
};

namespace timezone {
  enum type {
    prohibited,
    optional,
    required
  };
}

struct type {
  enumeration enumeration_;
  kind kind_;
  zstring name_;

  virtual ~type();
};

struct min_max_type : type {
  int minLength_;
  int maxLength_;

  min_max_type();
};

struct atomic_type : min_max_type {
  // string, anyURI, base64Binary, hexBinary
  int length_;

  // date, dateTime, time, gYear, gYearMOnth, gMonth, gMondyDay, gDay,
  // duration, decimal, double, float
  // TODO

  // decimal
  int totalDigits_;
  int fractionDigits_;

  // date, dateTime, time
  timezone::type explicitTimezone_;

  // all types
  zstring pattern_;

  atomic_type();
};

struct array_type : min_max_type {
  typedef type* value_type;
  typedef std::vector<value_type> content_type;
  content_type content_;

  array_type();
  ~array_type();
};

struct object_type : type {
  typedef zstring key_type;
  typedef type* value_type;
  typedef std::map<key_type,value_type> content_type;
  content_type content_;

  ~object_type();
};

struct union_type : type {
  // TODO
};

class validator {
public:
  validator( store::Item_t const &jsd );
  ~validator();

  zstring const& get_about() const {
    return about_;
  }

  zstring const& get_namespace() const {
    return namespace_;
  }

  void validate( store::Item_t const &json, zstring const &type_name,
                 store::Item_t *result ) const;

private:
  typedef std::map<zstring,type*> typename_map;
  typename_map types_;

  zstring about_;
  zstring namespace_;

  void load_about( store::Item_t const& );
  void load_array_type( store::Item_t const&, array_type* );
  void load_atomic_type( store::Item_t const&, atomic_type* );
  void load_baseType( store::Item_t const& );
  void load_constraints( store::Item_t const& );
  void load_content_array( store::Item_t const& );
  void load_content_object( store::Item_t const& );
  void load_enumeration( store::Item_t const& );
  void load_explicitTimezone( store::Item_t const&, atomic_type* );
  void load_field_descriptor( store::Item_t const& );
  void load_fractionDigits( store::Item_t const&, atomic_type* );
  void load_imports( store::Item_t const& );
  std::unique_ptr<type> load_kind( store::Item_t const& );
  void load_length( store::Item_t const&, atomic_type* );
  void load_maxExclusive( store::Item_t const&, atomic_type* );
  void load_maxInclusive( store::Item_t const&, atomic_type* );
  void load_maxLength( store::Item_t const&, min_max_type* );
  void load_minExclusive( store::Item_t const&, atomic_type* );
  void load_minInclusive( store::Item_t const&, atomic_type* );
  void load_minLength( store::Item_t const&, min_max_type* );
  void load_name( store::Item_t const& );
  void load_namespace( store::Item_t const& );
  void load_object_type( store::Item_t const&, object_type* );
  void load_open( store::Item_t const& );
  void load_pattern( store::Item_t const& );
  void load_totalDigits( store::Item_t const& );
  std::unique_ptr<type> load_type( store::Item_t const& );
  void load_types( store::Item_t const& );
  void load_union_type( store::Item_t const&, union_type* );
};

///////////////////////////////////////////////////////////////////////////////

} // jsound
} // namespace zorba

/* vim:set et sw=2 ts=2: */
