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

#include "context/static_context_consts.h"


namespace zorba {
namespace StaticContextConsts {

std::ostream& operator<<( std::ostream &o, xquery_version_t v ) {
  switch ( v ) {
    case xquery_version_1_0:
      return o << "1.0";
    case xquery_version_3_0:
      return o << "3.0";
    default:
      return o << "unknown";
  }
}

std::string toString(declaration_property_t prop)
{
  switch (prop)
  {
  case StaticContextConsts::decl_mutable:
    return "mutable";

  case StaticContextConsts::decl_queue:
    return "queue";

  case StaticContextConsts::decl_append_only:
    return "append_only";

  case StaticContextConsts::decl_const:
    return "const";

  case StaticContextConsts::decl_ordered:
    return "ordered";

  case StaticContextConsts::decl_unordered:
    return "unordered";

  case StaticContextConsts::decl_value_equality:
    return "valiue_equality";

  case StaticContextConsts::decl_value_range:
    return "value_range";

  case StaticContextConsts::decl_unique:
    return "unique";

  case StaticContextConsts::decl_non_unique:
    return "non_unique";

  case StaticContextConsts::decl_manual:
    return "manual";

  case StaticContextConsts::decl_automatic:
    return "automatic";

  default:
    return "??";
  }

}

} // namespace StaticContextConsts
} // namespace zorba
/* vim:set et sw=2 ts=2: */
