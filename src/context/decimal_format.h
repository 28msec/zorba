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

#include <vector>

#include "common/shared_types.h"
#include "zorbatypes/zstring.h"
#include "zorbaserialization/serialization_engine.h"

namespace zorba
{

class DecimalFormat : public SimpleRCObject
{
public:
  typedef std::vector<std::pair<zstring,zstring> > param_vector_type;

protected:
  bool              theIsDefault;
  store::Item_t     theName;
  param_vector_type theParams;

public:
  SERIALIZABLE_CLASS(DecimalFormat)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(DecimalFormat, SimpleRCObject)
  void serialize(::zorba::serialization::Archiver& ar)
  {
    ar & theIsDefault;
    ar & theName;
    ar & theParams;
  }

protected:
  // Returns true if the given property represents characters used in a
  // picture string. These properties are decimal-separator-sign,
  // grouping-separator, percent-sign, per-mille-sign, zero-digit,
  // digit-sign, and pattern-separator-sign.
  static bool isPictureStringProperty(zstring propertyName);

public:
  DecimalFormat(
        bool isDefault,
        const store::Item_t& qname,
        const param_vector_type& params);

  bool isDefault() const { return theIsDefault; }

  const store::Item* getName() const { return theName.getp(); }

  const param_vector_type* getParamVector() const { return &theParams; }

  bool validate(const QueryLoc& loc) const;
};


typedef rchandle<DecimalFormat> DecimalFormat_t;

} /* namespace zorba */
#endif /* ZORBA_DECIMAL_FORMAT_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
