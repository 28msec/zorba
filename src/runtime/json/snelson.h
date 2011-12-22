/*
 * Copyright 2006-2011 The FLWOR Foundation.
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

#ifndef ZORBA_RUNTIME_JSON_SNELSON_H
#define ZORBA_RUNTIME_JSON_SNELSON_H

#include <iostream>

#include "store/api/item.h"
#include "util/json_parser.h"

namespace zorba {
namespace snelson {

///////////////////////////////////////////////////////////////////////////////

void parse( json::parser &p, store::Item_t *result );
void serialize( std::ostream&, store::Item_t const &item );

///////////////////////////////////////////////////////////////////////////////

} // namespace snelson
} // namespace zorba
#endif /* ZORBA_RUNTIME_JSON_SNELSON_H */
/* vim:set et sw=2 ts=2: */
