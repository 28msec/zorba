/*
 * Copyright 2006-2008 The FLWOR Foundation.
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
#pragma once
#ifndef ZORBA_DECIMAL_FORMAT_H
#define ZORBA_DECIMAL_FORMAT_H

#include <utility>                      /* for pair */
#include <map>
#include <vector>

#include "common/shared_types.h"
#include "store/api/item.h"
#include "util/unordered_map.h"
#include "zorbaserialization/class_serializer.h"
#include "zorbatypes/zstring.h"

///////////////////////////////////////////////////////////////////////////////

namespace zorba {

class DecimalFormat : public SimpleRCObject {
public:
  typedef zstring name_type;
  typedef zstring value_type;

  typedef std::vector< std::pair<name_type,value_type> > ctor_properties_type;
  typedef std::map<name_type,value_type> properties_type;

public:
  SERIALIZABLE_CLASS(DecimalFormat)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(DecimalFormat, SimpleRCObject)
  void serialize( serialization::Archiver& );

public:
  DecimalFormat( bool is_default, store::Item_t const &qname,
                 ctor_properties_type const &properties, QueryLoc const &loc );

  store::Item const* getName() const { return qname_.getp(); }
  properties_type const& getProperties() const { return properties_; }
  bool isDefault() const { return is_default_; }

private:
  bool            is_default_;
  store::Item_t   qname_;
  properties_type properties_;
};


typedef rchandle<DecimalFormat> DecimalFormat_t;

///////////////////////////////////////////////////////////////////////////////

} /* namespace zorba */
#endif /* ZORBA_DECIMAL_FORMAT_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
