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

#include <zorba/external_function_data.h>
#include <zorba/item.h>
#include <zorba/item_sequence.h>

#include "zorbaerrors/user_exception.h"

namespace zorba {
  
void
ExternalFunctionData::error()
{
  throw DEFAULT_USER_EXCEPTION();
}


void
ExternalFunctionData::error(const Item& aQName)
{
  throw USER_EXCEPTION( aQName );
}


void
ExternalFunctionData::error(const Item& aQName, const String& aDescription)
{
  throw USER_EXCEPTION( aQName, aDescription );
}


void
ExternalFunctionData::error(
    const Item& aQName,
    const String& aDescription,
    const ItemSequence_t& aErrorObject)
{
  throw USER_EXCEPTION( aQName, aDescription, aErrorObject );
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
