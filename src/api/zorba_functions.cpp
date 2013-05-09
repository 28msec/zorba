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

#include <zorba/zorba_functions.h>
#include <zorba/zorba_string.h>

#include "util/ascii_util.h"

using namespace std;

namespace zorba {
namespace zfn {

///////////////////////////////////////////////////////////////////////////////

void trim( String &s ) {
  ascii::trim_space( s );
}

void trim( String &s, char const *chars ) {
  ascii::trim( s, chars );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zfn
} // namespace zorba
/* vim:set et sw=2 ts=2: */
