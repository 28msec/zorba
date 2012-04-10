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
#include "stdafx.h"

#include <zorba/api_shared_types.h>
#include "context/decimal_format.h"
#include "common/shared_types.h"

#include "store/api/item.h"

namespace zorba {

SERIALIZABLE_CLASS_VERSIONS(DecimalFormat)


DecimalFormat::DecimalFormat(
    bool isDefault,
    const store::Item_t& qname,
    const param_vector_type& params)
  :
  theIsDefault(isDefault),
  theName(qname),
  theParams(params)
{
}

bool DecimalFormat::isPictureStringProperty(zstring propertyName)
{
  if (propertyName == "decimal-separator" ||
      propertyName == "grouping-separator" ||
      propertyName == "percent" ||
      propertyName == "per-mille" ||
      propertyName == "zero-digit" ||
      propertyName == "digit" ||
      propertyName == "pattern-separator")
    return true;
  else
    return false;
}

bool DecimalFormat::validate(const QueryLoc& loc) const
{
  for (unsigned int i = 0; i<theParams.size()-1; i++)
    for (unsigned int j = i+1; j<theParams.size(); j++)
    {
      if (isPictureStringProperty(theParams[i].first)
          &&
          isPictureStringProperty(theParams[j].first)
          &&
          theParams[i].second == theParams[j].second)
        throw XQUERY_EXCEPTION(err::XQST0098, ERROR_PARAMS(theParams[i].first, theParams[j].first), ERROR_LOC(loc));
    }

  return true;
}

}	// namespace zorba
/* vim:set et sw=2 ts=2: */
