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

#include <iostream>
#include <map>
#include <vector>

#include <zorba/internal/unique_ptr.h>

#include "store/api/item.h"
#include "util/unordered_map.h"

namespace zorba {
namespace jsound {

class validator;

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
std::ostream& operator<<( std::ostream&, kind );

namespace timezone {
  enum type {
    prohibited,
    optional,
    required
  };
}

class type {
public:
  zstring about_;
  zstring baseType_;
  enumeration enumeration_;
  kind const kind_;
  zstring name_;

  type( kind );
  virtual ~type();

protected:
  void load_about( store::Item_t const& );
  virtual void load_baseType( store::Item_t const&, validator const& );
  void load_constraints( store::Item_t const& );
  void load_enumeration( store::Item_t const& );
  virtual void load_type( store::Item_t const&, validator const& ) = 0;
  void load_name( store::Item_t const&, validator const& );

  friend class validator;
};

class min_max_type : public type {
public:
  int minLength_;
  int maxLength_;

protected:
  void load_maxLength( store::Item_t const& );
  void load_minLength( store::Item_t const& );

  min_max_type( kind );

  friend class validator;
};

class atomic_type : public min_max_type {
public:
  // string, anyURI, base64Binary, hexBinary
  int length_;

  // date, dateTime, time, gYear, gYearMOnth, gMonth, gMondyDay, gDay,
  // duration, decimal, double, float
  store::Item_t maxExclusive_;
  store::Item_t maxInclusive_;
  store::Item_t minExclusive_;
  store::Item_t minInclusive_;

  // decimal
  int totalDigits_;
  int fractionDigits_;

  // date, dateTime, time
  timezone::type explicitTimezone_;

  // all types
  zstring pattern_;

  atomic_type();

protected:
  virtual void load_baseType( store::Item_t const&, validator const& );
  virtual void load_type( store::Item_t const&, validator const& );

private:
  void load_explicitTimezone( store::Item_t const& );
  void load_fractionDigits( store::Item_t const& );
  void load_length( store::Item_t const& );
  void load_maxInclusive( store::Item_t const& );
  void load_minInclusive( store::Item_t const& );
  void load_maxExclusive( store::Item_t const& );
  void load_minExclusive( store::Item_t const& );
  void load_pattern( store::Item_t const& );
  void load_totalDigits( store::Item_t const& );
};

class array_type : public min_max_type {
public:
  typedef type* value_type;
  typedef std::vector<value_type> content_type;
  content_type content_;

  array_type();
  ~array_type();

private:
  void load_content( store::Item_t const& );
  virtual void load_type( store::Item_t const&, validator const& );

  friend class validator;
};

class object_type : public type {
public:
  class field_descriptor {
  public:
    type const *type_;
    bool optional_;
    store::Item_t default_;

    field_descriptor();
    // default copy constructor is OK
    // defalut assignment operator is OK
    // default destructor is OK

  private:
    void load_default( store::Item_t const& );
    void load_optional( store::Item_t const& );
    void load_type( store::Item_t const& );
    friend class object_type;
  };

  typedef zstring key_type;
  typedef field_descriptor value_type;
  typedef std::map<key_type,value_type> content_type;

  content_type content_;
  bool open_;

  object_type();

private:
  void load_content( store::Item_t const&, validator const& );
  void load_field_descriptor( store::Item_t const&, field_descriptor* );
  void load_open( store::Item_t const& );
  virtual void load_type( store::Item_t const&, validator const& );

  friend class validator;
};

class union_type : public type {
public:
  // TODO
  union_type();

private:
  virtual void load_type( store::Item_t const&, validator const& );
};

///////////////////////////////////////////////////////////////////////////////

class validator {
public:
  validator( store::Item_t const &jsd );
  ~validator();

  zstring const& get_namespace() const {
    return namespace_;
  }

  void validate( store::Item_t const &json, zstring const &type_name,
                 store::Item_t *result ) const;

private:
  // set of all imported namespaces
  typedef std::set<zstring> namespace_set;
  namespace_set namespaces_;

  // map of all prefixes -> namespaces
  typedef std::map<zstring,zstring> prefix_namespace_map;
  prefix_namespace_map prefix_ns_;

  // map of all type names (Q{uri}local) -> types
  typedef std::map<zstring,type*> typename_map;
  typename_map types_;

  zstring namespace_;

  type const* find_type( zstring const &type_name, bool not_found_error = true ) const;
  void fq_type_name( zstring *type_name, zstring *uri = nullptr ) const;

  void load_import( store::Item_t const& );
  void load_imports( store::Item_t const& );
  std::unique_ptr<type> load_kind( store::Item_t const& );
  void load_namespace( store::Item_t const& );
  void load_type_top( store::Item_t const& );
  void load_types( store::Item_t const& );

  friend class type;
  friend class atomic_type;
  friend class object_type;
  friend class array_type;
};

///////////////////////////////////////////////////////////////////////////////

} // jsound
} // namespace zorba

/* vim:set et sw=2 ts=2: */
