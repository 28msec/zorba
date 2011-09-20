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
#ifndef ZSTRING_H
#define ZSTRING_H

#include "util/atomic_int.h"
#include "util/string/buf_rep.h"
#include "util/string/default_rep.h"
#include "util/string/ptr_rep.h"
#include "util/string/rep_proxy.h"
#include "util/string/rstring.h"

namespace zorba {

typedef rstring_classes::rep<atomic_int> default_rep;
typedef rstring_classes::ptr_rep<atomic_int> ptr_rep;
typedef rstring_classes::buf_rep<default_rep> buf_rep;

typedef rstring< default_rep > zstring;
typedef rstring< ptr_rep > zstring_p;
typedef rstring< buf_rep > zstring_b;

} // namespace zorba

#endif /* ZSTRING_H */
/* vim:set et sw=2 ts=2: */
